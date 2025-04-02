 /*
 **	      _      ____   _      ___    _          ___       ___
 **	     | |    | |_   \ \_/  / / \  | |\ |     / / \  __   ) )
 **	     |_|__  |_|__  /_/ \  \_\_/  |_| \|     \_\_/ (_() _)_)
 **
 **
 **                  Lexon — natural language programming
 **
 **     Copyright (C) 2016-24 Henning Diedrich. Licensed to you under
 **	AGPL3 subject to the conditions described in the file LICENSE.
 **
 **	Also see https://www.lexon.org/license-0.3.html
 **
 **
 **
 **	lexon.l — tokenizer, parser and tree builder.
 **
 **	A Lexon compiler is built from this code in two cycles: first a compiler
 **	compiler compiler is built, using Flex, then gcc. This lexccc is used to
 **	create from an LGF grammar file a number of inputs to Flex, Bison and
 **	gcc to build the Lexon compiler from, which processes controlled natural
 **	language obeying the grammar. See grammar/english.lgf.
 **
 **	This code has three parts, it is Flex input in its entirety. The first
 **	part has declarations. Then follow the regex patterns for the scanner
 **	generation. The last part are the C functions that handle LGF, LXF and
 **	Lexon parsing. The parts are separated by %% as Flex requires.
 */
%{

/* part I: declarations --------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdarg.h>
#include <libgen.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>

#ifndef PATH_MAX
#define PATH_MAX 1000
#endif

#define program_vers "0.3 beta 4"
#define grammar_vers "[no grammar]"
#ifndef CYCLE_2
#define program_name "Lexon grammar compiler"
#define slug program_name " " program_vers
#else
#define program_name "Lexon compiler"
#define slug program_name " " program_vers ", grammar " grammar_vers
#endif
const char *program_version = program_vers;
char *grammar_version = grammar_vers;

#define D mtrac_concat(&lexcoms->value, yytext); D0
#define D0 \
	if(strchr(context, '\n')) { mtrac_free(context); context = mtrac_strdup(yytext); } \
	else { mtrac_concat(&context, yytext); } \
	if(opt_debug_regex) fprintf(stderr, "matched in mode <%d> line %d  '%s'\n", YY_START, __LINE__, xcr(yytext))
#define DX(result_) \
	if(opt_debug_mainscan) { \
		fprintf(stderr, " mode <%d> line %d: '%s' ⟶ - %s\n", YY_START, __LINE__, xcr(yytext), #result_); \
	}
#define S source(yytext)
#define new(type, var) \
	_mtrac_malloc(sizeof(type), #var, __FILE__, __LINE__); \
	if(!var) { fprintf(stderr, "out of memory %s %d", __FILE__, __LINE__); exit(137); } \
	memset(var, 0, sizeof(type));
#define news(var, size) \
	_mtrac_malloc(size, #var, __FILE__, __LINE__); \
	if(!var) { fprintf(stderr, "out of memory %s %d", __FILE__, __LINE__); exit(137); } \
	memset(var, 0, size);

#ifndef CYCLE_2
typedef int bool;
#endif
#define false 0
#define true 1
#define null (void *)0

/* prettier and safer wraps */
#define concat(var_, ...) _concat(#var_, __FILE__, __LINE__, 0, 0, var_, __VA_ARGS__, null)
#define precat(...) _precat(__VA_ARGS__, null)
#define padcat(down_, right_, var_, ...) _concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)
#define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, false, null, null, #orig_, __FILE__, __LINE__)
#define replace_whole_words(orig_, rep_, with_, quote_, unquote_) _replace(orig_, rep_, with_, true, null, true, quote_, unquote_, #orig_, __FILE__, __LINE__)
#define replace_first(orig_, rep_, with_) _replace(orig_, rep_, with_, false, null, false, null, null, #orig_, __FILE__, __LINE__)
#define replace_first_from(orig_, rep_, with_, from_) _replace(orig_, rep_, with_, false, from_, false, null, null, #orig_, __FILE__, __LINE__)

/* prepending Flex' debug output with 'scanner: ' -- this is Flex' own and the above D macro's */
#define fprintf(out_, ...) repchr(yytext, '\n', '$'), fprintf(out_, "scanner: " __VA_ARGS__), repchr(yytext, '$', '\n')


void clean_exit();
char *walk();
void parsargs(int argc, char **argv);
void syntax(char *message, char *violation);
void yacc_printf(FILE *stream, char *format, ...);
char *coredup(char *src);
void process(char *ltrim, char *skip1, char *mtrim, char *skip2, char *ctrim, char *pif, char *rtrim);
void process2(char *pif, char *rtrim, char *open, char *close);
void include(char *pif);
int include_done();
void dump_include_stack(char *path);
void dump_include_trace(char *path);
void delete_include_trace();
char **_concat(char *varname, char *file, int line, int down, int right, char **buf, ...);
char **_concatnum(char **buf, char *prefix, int number, char *postfix);
void _precat(char **buf, ...);
char *catdup(char *string, char *append, int(*func)(int));
int _replace(char **orig, const char *rep, const char *with, int all, char *from,
	bool whole, char *quote, char *unquote, char *origname, char *file, int line);
int repchr(char *hay, char s, char r) { char *c = hay; while(*c) { if(*c==s) *c = r; c++; } return 0; }
char *filedup(const char *path, const char *dflt);
char *str_escape(const char *src, const char *varname);
const char *str(int line);
const char *literal_symbol(char *token);
char *UP(const char *token);
char *up(char *token);
char *LOW(const char *token);
char *SNAKE(const char *token);
char *lowdup(const char *token);
char *snakedup(const char *token);
char *dash_spaced(const char *token);
char *snake_spaced(const char *token);
char *camel_spaced(const char *token);
void lineno();
void rump(char **dest, char *filename);
char *cutbuf(char *src, char *cut);
void precompile();
char *trim(char *s);
char *contract(char *s);
char *unspace(char *s);
char *quote_trimmed(const char *token);
char **pad(char **s, int to);
char *xcr(char *);
int chrcnt(char *hay, char needle);
void margin();
void freeline();
void geninfo();
void dump_name_list();
void help();
void setlaw(char *);
void emulaws();
void dump_laws();

char name_homedir[PATH_MAX];
char *file_clearname = null;
char *file_namepart = null;
char *file_pathpart = null;
char *file_location = null;
FILE *file_fileptr = null;

/* The currently selected jurisdiction (can be none). */
char *law_name = null;
char *law_abbr = null;
char *law_ext = null;

/* precompilation line counting: it is somewhat involved and abused during pre-compilation
   as it can result into pulling two lines into one to join names with whitespace between their
   constituent words, before tokenizing */
int line = 1;
int metaline = 1;
int _lastline = 0;
char *_lastfile = null;
bool lhd = false; // 'line has definition'
bool plhd = false; // 'previous line has ..'
bool pretty = false;

/* line number and file name given in errors during MAIN parse pass, which are prefixed to each line,
   put there during precompilation. This, for proper tracking of included files. */
char *prec_file = null;
int prec_line = 0;
char *context = null;

/* temp string buffer */
char *_xcr = null;

/* the code buffers: parsing (except lgf/lxf) is done in-memory after precompilation */
char *buf;
char *buf2;
char *t;
char *src; // used by lgf
char *keywords;
char *funclist; // not used yet

/* imbued files */
#ifndef CYCLE_2
const char *own = "not set";
const char *owngrm = "not set";
const char *manual = "not set";
#else
const char *own;
const char *owngrm;
const char *manual;
#endif

int nonce = 0;

/* list of symbols (names) */
typedef struct node {
	struct node *prev;
	int serial;
	char *find;
	int find_len;
	char *tag;
	char *repl;
} node;
node *symbols = null;

int name_count = 0;

/* The command line options for the compiler */
char *opt_source = null;
char *opt_output = null;
bool opt_verbose = false;
bool opt_quiet = false;
bool opt_echo = false;
bool opt_precompile = false;
bool opt_pre_echo = false;
bool opt_names = false;
bool opt_jurisdictions = false;
bool opt_included_files = false;
char *opt_include_path = "./";  // (**)
bool opt_geninfo = false;
bool opt_manual = false;
bool opt_instructions = false;
bool opt_grammar = false;
bool opt_bnf = false;
char *opt_yacc = null;
bool opt_keywords = false;
char *opt_bootstrap = null;
char *opt_source_base = null;
char *opt_header = null;
char *opt_langprefix = "core";  // (**)
char *opt_template = null;
char *opt_samples = null;
int opt_max_examples = 0;
bool opt_bare = false;
bool opt_comment = false;
bool opt_lexon_comments = false;
bool opt_feedback = false;
bool opt_harden = false;
char *opt_log = null;
char *opt_persistence = null;
char *opt_bundle = null;
char *opt_email = null;
char *opt_signatures = null;
int opt_chaining = 0;
bool opt_extended = false;
bool opt_wipe = false;
bool opt_ignore_circular_includes = false;
bool opt_ignore_repeat_includes = false;
bool opt_memory = false;
bool opt_debug = false;
bool opt_debug_regex = false;
bool opt_debug_scanner = false;
bool opt_debug_mainscan = false;
bool opt_debug_actions = false;
bool opt_debug_tokens = false;
bool opt_debug_parser = false;
bool opt_debug_generator = false;
bool opt_debug_examples = false;
bool opt_debug_lists = false;
bool opt_debug_dev = false;
bool opt_debug_production = false;
bool _concat_trace = false;
bool opt_debug_time = false;
bool opt_help = false;
bool opt_debug_allow_double_names = false;
bool do_main_pass = true;

//# bool opt_run_spheres = false; // #spheres
bool opt_produce_tree = false; // #tree
bool opt_produce_core = false; // #core
bool opt_produce_javascript = false; // #javascript
bool opt_produce_solidity = false; // #solidity
bool opt_produce_sophia = false; // #sophia

bool opt_produce_flat = false;
bool opt_produce_terse = false;
char *opt_color = null;
char *opt_highlight = null;
char *opt_symbols = null;
char *opt_values = null;
char *opt_subvalues = null;

char *opt_summarized = null;

/* This mechanism preserves the parse cursor in a file
   and other context when another file is included. */
#define MAX_INCLUDE_DEPTH 20
struct _include_stack {
	YY_BUFFER_STATE buffer;
	char *clearname;
	char *namepart;
	char *pathpart;
	char *location;
	FILE *fileptr;
	int line;
};

struct _include_stack include_stack[MAX_INCLUDE_DEPTH];
int include_stack_ptr = 0;

/* This list keeps track of what file was included. */
int include_count = 0;
typedef struct _include_trace {
	char *from_namepart;
	char *from_clearname;
	int from_line;
	char *include_namepart;
	char *include_clearname;
	struct _include_trace *next;
} include_trace;
include_trace *include_trace_start = null;
include_trace *include_trace_last = null;

/* A list of allowable jurisdictions, their abbreviations, extensions, relationship */
typedef struct _law {
	char *abbr;
	char *name;
	char *under;
	char *ext;
	struct _law *prev;
} law;
law *laws_last = null;

/* grammar definitions for XBNF processing */
typedef enum {active, passive, none} mode;
typedef enum {personal, factual, neutral} kind;
typedef enum {unspaced=false, spaced=true, not_applicable} adjacency;
typedef enum {no_pipe=false, with_pipe=true} piped;
typedef enum {sort=false, keep=true} ordering;

struct word {
	char *string;
	bool option_start;
	bool option_end;
	adjacency adjacency;
	struct word *next;
};

struct alternate {
	struct word *words;
	struct alternate *next;
};

struct alternation {
	char *string;
	struct alternate *alternates;
	struct alternation *next;
};

typedef struct _stringlist {
	char *string;
	bool seal;
	struct _stringlist *next;
} stringlist;

struct rule {
	mode mode;
	kind kind;
	struct word *words;
	struct word *keywords;
	stringlist *tokens;
	struct rule *next;
};

struct definition {
	char *name;
	bool important;
	struct rule *rules; // the LGF rules, which can result into multiple BNF rules each
	struct alternation *alternations;
	struct rule *subrules; // the resulting BNF rules, i.e. lines in the Yacc grammar
	stringlist *tokens;
	stringlist *types;
	char *source;
	int line;
	stringlist *results;
	bool simple; // no options and alternates
	struct definition *next;
};

typedef struct _map {
	char *key;
	char *value;
	struct _map *next;
} map;


struct definition *grammar = null;
struct definition **definition = &grammar;
struct rule **rule = null;
struct word **keyword = null;
struct word **word = null;
struct alternation **alternation = null;
struct alternate **alternate = null;

map *lexcoms = null; // list of lexon text chunks as comments
stringlist *tokens = null;
stringlist *ignores = null;
stringlist *predef = null;
stringlist *xpredef = null;
char *embed;

void start_definition(char *scan);
void start_rule(mode, kind);
void continue_rule();
void add_keyword(char *scan);
void _add_word(char *scan, bool option_start, bool option_end, adjacency space);
void add_word(char *string);
bool _add_token(stringlist **tokens, const char *string, stringlist *only,
	stringlist *ignores, ordering keep_order, char *var, char *file, int line);
void new_lexcom(const char *name, const char *value);
const char *get_lexcom(const char *name);
bool in_list(stringlist *tokens, const char *string);
int count_in_list(stringlist *token, const char *string);
void delete_stringlist(stringlist *list);
void delete_node_list(node *list);
void delete_map(map *map);
void start_option(adjacency);
void end_option(adjacency);
void start_alternation(char *scan);
void start_alternate();
void end_rule();
void add_embed(char *s);
void produce_grammar(struct definition *definition);
void produce_examples(stringlist **result, int depth, struct word *word,
	struct definition *grammar, char *contract_name, char *clause_name,
	char *last_defined, bool *separated, int *names, int *texts, char *check,
	int *count, int fuse);
char *foobar(int);
char *blind(int n);
void write_examples(stringlist *example, int count);
void produce_extension(struct definition *definition);
void produce_tokens(stringlist *result, stringlist *tokens);
void produce_rule(stringlist *result, struct definition *definition,
	struct rule *rule, struct word *word, struct word *pickup,
	adjacency space, char *prefix, bool extension);
stringlist *new_result(stringlist *result, char *string, piped add_pipe);
stringlist *new_result_dup(stringlist *result, char *string, piped add_pipe);
stringlist *listcat(stringlist *head, stringlist *tail);
bool pin_list(stringlist *list, stringlist *needle);
void delete_definitions(struct definition *definitions);
void delete_laws();
const char *yacc_stub();
const char *walk_stub();
void prepfile(char *outfile, char *header, char *bootstrap, char *grammar_file, char *lex);
void source(char *s);

/* #tree and #core code production */
char *opening_bracket = "(";
char *closing_bracket = ")";
bool bracket_just_closed = false;

/* alternate memory management */
void *(*system_malloc)(size_t) = &malloc;
void (*system_free)(void *) = &free;
#define MEMORY_CHECKS
#ifdef MEMORY_CHECKS
#define mtrac_malloc(size_) _mtrac_malloc(size_, "[unknown]", __FILE__, __LINE__)
#define mtrac_strdup(string_) _mtrac_strdup(string_, "[unknown]", __FILE__, __LINE__)
#define mtrac_strdup_gross(string_) mtrac_gross(_mtrac_strdup(string_, "[unknown]", __FILE__, __LINE__))
#define mtrac_concat(...) _mtrac_concat(__FILE__, __LINE__, 0, 0, __VA_ARGS__, null)
#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)
#else
#define mtrac_malloc(size_) malloc(size_)
#define mtrac_strdup(string_) strdup(string_)
#define mtrac_strdup_gross(string_) strdup(string_)
#define mtrac_concat(var_, ...) _concat(0, 0, var_, __VA_ARGS__, null)
#define mtrac_free(var_) free(var_)
#endif

#define add_token(tokens_, string_, only_, ignores_, keep_order_) \
	_add_token(tokens_, string_, only_, ignores_, keep_order_, #tokens_, __FILE__, __LINE__)
void *_mtrac_malloc(size_t size, char *name, char *file, int line);
void *_mtrac_strdup(const char *string, char *name, char *file, int line);
char *_mtrac_dupcat(const char *string, ...);
void _mtrac_free(void *p, char *name, char *file, int line);
char **_mtrac_concat(char *file, int line, int down, int right, char **buf, ...);
void mtrac_stats();
void mtrac_dump();
int mtrac_check();
size_t mtrac_limit = 1000000000; // ◊ make optional
bool mtrac_really_free = true;
bool mtrac_verbose = false;
bool mtrac_blank_pointers = false;
char *mtrac_printable = "*stringlist,*word,*alternation,*definition";
void *mtrac_gross(void *rec);
void mtrac_free_gross();

/* stub tokens for 1st cycle (lexccc compiler compiler). They are replaced by
   the yacc-generated header for the 2nd (full lexon compiler). */

#ifndef YY_YY_LEXC_TAB_H_INCLUDED
# define YY_YY_LEXC_TAB_H_INCLUDED

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

#ifndef YYTOKENTYPE
#define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,
    YYerror = 256,
    YYUNDEF = 257,
    Colon = 258,
    Comma = 259,
    Dash = 260,
    Percent = 261,
    Period = 262,
    Quote = 263,
    Semicolon = 264,
    Separator = 265,
    DESCRIPTION = 266,
    HEX = 267,
    NAME = 268,
    SCALAR = 269
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
	char *Name;
	char *Description;
	char *Scalar;
	char *Hex;
};
typedef union YYSTYPE YYSTYPE;

# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1

YYSTYPE yylval;

#endif

int yyparse (void);

#endif /* !YY_YY_LEXC_TAB_H_INCLUDED  */
%}


/* part II: scanner ------------------------------------------------------ */


/* speed-up: */
%option never-interactive

%option case-insensitive

 /* parse character patterns */
quote	 ["]
digit    [0-9]
scalar   [-]?[0-9]+
hex      0?[xX][0-9a-fA-F]+
letter   [A-Za-z]
wordpart ['-]
word	 [A-Za-z']([A-Za-z'-]*[A-Za-z'])?
token	 [A-Za-z0-9'_]([A-Za-z0-9'_-]*[A-Za-z0-9'_])?
spaced   [A-Za-z0-9'_][ ](([A-Za-z0-9'_-][ ])*[A-Za-z0-9'_])?
term	 [A-Za-z]([A-Za-z0-9/' -]*[A-Za-z0-9'])?
termpart [A-Za-z]([A-Za-z0-9/'-]*[A-Za-z0-9'])?
path     [A-Za-z./\\_-]([A-Za-z0-9./:\\' _-]*[A-Za-z0-9'_-])?
lawext   [A-Za-z .'()/-]+
interpunctuation [,;.:!?()/\\'-]+
percents [%]
brackets [\[\]]
space	 [ \t]
white	 [ \t\n]
category (is[ \t]+)?((an?|the)[ \t]+)?(person|amount|time|binary|text|data)
contract (is[ \t]+)?this[ \t]+[^\"“”\n]+
defined  (be|is)[: \t]+

/* two compiler passes (PRE, MAIN), multiple sub scan states */
%x BOFTRIM
%x PRE
%x NAME_PROCESSING
%x QUOTED_TEXT
%s MAIN

%x TRIM
%x LAW
%x INCLUDE
%x LINENO
%x NAME_
%x DESCRIPTION_
%x EXPLANATION_
%x NAMEQUOTE
%x TEXTQUOTE
%x LONGQUOTE

/* grammar parsing */
%x LGF

/* extension parsing */
%x LXF
%x EMBED


%%

 if(YY_START==INITIAL) BEGIN ((opt_bnf || opt_yacc || opt_keywords || opt_template || opt_bootstrap || opt_samples ? LGF : BOFTRIM));

 /* precompilation marks variable names with « »; to this end normalizes whitespace to allow
    for the liberal use of tabs and newlines even within variable names.
    At the ocassion, double newline (which semantically equal '.') is also normalized. */

<PRE>{
GRAMMAR{space}*:?{space}*					{ D; BEGIN(LXF); }
LGF{space}*:?{space}*						{ D; BEGIN(LGF); }
({space}*\n){2}							{ D; lineno(); concat(&buf, "\n\n"); line+=2; plhd=lhd=false; BEGIN(TRIM); }
{space}*\.{space}*\n						{ D; lineno(); concat(&buf, ".\n"); line++; plhd=lhd; lhd=false; BEGIN(TRIM); }
{space}*,{space}*\n						{ D; lineno(); concat(&buf, ",\n"); line++; plhd=lhd=false; }
{space}*;{space}*\n						{ D; lineno(); concat(&buf, ";\n"); line++; plhd=lhd=false; }
{space}*:{space}*\n						{ D; lineno(); concat(&buf, ":\n"); line++; plhd=lhd=false; BEGIN(TRIM); }
^{space}*\n  /* under, after include */				{ D;           concat(&buf, "\n"); line++; plhd=lhd; lhd=false; }
{space}*\n							{ D;           concat(&buf, " "); _lastline=++line; }
^{space}*LEX(:|{space})+					{ D; if(_lastline==line) _lastline--;
								     freeline(); lineno(); concat(&buf, trim(yytext), ": "); BEGIN(NAMEQUOTE); }
^{space}*OPERATING{space}+AGREEMENT{space}*(OF)*(:|{space})+	{ D; if(_lastline==line) _lastline--;
								     freeline(); lineno(); concat(&buf, trim(yytext), ": "); BEGIN(NAMEQUOTE); }
^{space}*(TERMS)?{space}+PER{space}+{letter}({letter}|{digit}|{space})*:	{ D0; if(_lastline==line) _lastline--; freeline(); lineno(); new_lexcom(yytext, yytext);
									 process(" \t", "TERMS", " \t", "PER", " \t", yytext, ": \t"); // ◊ separate TERMS PER
									 concat(&buf, yytext);
									 concat(&buf, ":"); } // ◊ why is the : lost in the scan? (and needs re-adding here)
^{space}*CLAUSE(:|{space})+{letter}({letter}|{digit}|{space})*	{ D0; if(_lastline==line) _lastline--; freeline(); lineno(); new_lexcom(yytext, yytext);
									 concat(&funclist, ":", yytext, ":"); process(" \t", "CLAUSE", ": \t", "", "", yytext, ". \t");
									 concat(&buf, yytext); }
^{space}*INCLUDE{space}*:?{space}*				{ D; freeline(); BEGIN(INCLUDE); }
^{space}*LAW{space}*:?{space}*					{ D; lineno(); concat(&buf, yytext); BEGIN(LAW); }
 /* ---> 2ND CYCLE LGF GENERATED TYPE NAMES HERE ---> */
 /* <--- TO HERE <--- */
^{space}*PREAMBLE{space}*(:|\.)*{space}*			{ D; lineno(); concat(&buf, trim(yytext), ": ‹"); BEGIN(LONGQUOTE); }
^{space}*{word}{space}*:{space}*				{ D; lineno(); concat(&buf, trim(yytext), ": "); BEGIN(TEXTQUOTE); }
^{space}*{word}{space}*						{ D; lineno(); concat(&buf, trim(yytext), " "); }
^{space}*(A|AN|THE)?{space}*(\"|“|”){space}*			{ D; lineno(); concat(&buf, yytext); BEGIN(NAME_PROCESSING); }
\.{space}*(A|AN|THE)?{space}*(\"|“|”){space}*			{ D;           concat(&buf, yytext); BEGIN(NAME_PROCESSING); }
[^.\n]{space}*(\"|“|”)						{ D;           concat(&buf, yytext); BEGIN(QUOTED_TEXT); }
{space}+                                   			{ D;           concat(&buf, " "); }
^(\"|“|”) /* these 2 lines emulate ^[^"“”]: */			{ D; lineno(); concat(&buf, yytext); }
^.	 							{ D0; yyless(0); if(plhd && pretty) freeline(); }
.								{ D; lineno(); concat(&buf, yytext); }
<<EOF>>		        					{ D0; new_lexcom("_pre_", "");
									if(include_done()) {
										// yy_set_bol(true); // ◊ added for no effect
										BEGIN(PRE);
									} else {
										precompile();
										if(do_main_pass) {
											BEGIN(MAIN);
											yy_delete_buffer(YY_CURRENT_BUFFER);
											YY_CURRENT_BUFFER_LVALUE = NULL;
											yy_scan_string(buf);
										} else
											return 0;
									} 
								} // (*)
}

<NAME_PROCESSING>{
{term}/(\"|“|”){space}*({category}|{contract}|{defined}) { D; process("", "", "", "", "", yytext, " \t"); concat(&buf, yytext); lhd=true; BEGIN(PRE); } // should be {term}/{space}* but that triggers a Flex (buggy) warning
[^"“”]+/(\"|“|”)	/* description string */		{ D; concat(&buf, "‹", yytext, "›"); BEGIN(PRE); }
.                                                               { D0; yyless(0); BEGIN(PRE); }
}

<QUOTED_TEXT>{
[^"“”]+/(\"|“|”)						{ D; concat(&buf, "‹", yytext, "›"); BEGIN(PRE); }
.                                                               { D0; yyless(0); BEGIN(PRE); } // ◊ error msg for empty text ""
}

<BOFTRIM>{
^{space}+                                                       { D; }
\n                                                              { D; line++; }
.                                                               { D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }
<<EOF>>                                                         { D; syntax("empty file (or only whitespace)", yytext); }
}

<TRIM>{
^{space}+							{ D; }
\n								{ D; if(!pretty) concat(&buf, "\n"); line++; }
^.								{ D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }
.								{ D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }
<<EOF>>				  				{ D0; new_lexcom("_pre_", "");
									if(include_done()) {
										// yy_set_bol(true); // ◊ added for no effect 
										BEGIN(PRE);
									} else {
										precompile();
										if(do_main_pass) {
											BEGIN(MAIN);
											yy_delete_buffer(YY_CURRENT_BUFFER);
											YY_CURRENT_BUFFER_LVALUE = NULL;
											yy_scan_string(buf);
										} else
											return 0;
									} 
								} // (*)

}

<NAMEQUOTE>{
{letter}({letter}|{digit}|{space})*				{ D; process2(yytext, ". \t", "«", "»"); concat(&buf, yytext); BEGIN(PRE); }
.								{ D; syntax("unexpected character in name", yytext); }
\n								{ D; syntax("unexpected end of line instead of name", ""); }
<<EOF>>								{ D; syntax("unexpected end of file instead of name", yytext); }
}

<TEXTQUOTE>{
{space}+                                                        { D; }
\.                                                              { D; }
[^ \t.\n].+							{ D; concat(&buf, "‹", yytext, "›."); }
{space}*\n		/* used to be \.*{space}*\n */		{ D; concat(&buf, "\n"); line++; plhd=lhd; lhd=false; BEGIN(TRIM); }
}

<LONGQUOTE>{
.*                                                              { D; concat(&buf, yytext); }
\n+/(TERM|GENERAL)						{ D; concat(&buf, "›."); concat(&buf, yytext); line+=strlen(yytext); plhd=lhd; lhd=false; BEGIN(TRIM); }
\n+/(A|AN|THE)?{space}*{quote}                                                     { D; concat(&buf, "›."); concat(&buf, yytext); line+=strlen(yytext); plhd=lhd; lhd=false; BEGIN(TRIM); }
\n                                                              { D; concat(&buf, "\n"); line++; plhd=lhd; lhd=false; }
({space}*\n){3}                                                 { D; concat(&buf, "›.\n\n\n"); line+=3; plhd=lhd; lhd=false; BEGIN(TRIM); }
}

<INCLUDE>{path}/\n						{ D; input(); include(yytext); yy_set_bol(true); BEGIN(PRE); }
<INCLUDE>.							{ D; syntax("unexpected character in include filename and path", yytext); }
<INCLUDE>\n							{ D; syntax("unexpected end of line instead of include filename and path", ""); }
<INCLUDE><<EOF>>						{ D; syntax("unexpected end of file instead of include filename and path", yytext); }

<LAW>{lawext}/\n						{ D; input(); concat(&buf, yytext); setlaw(yytext); BEGIN(PRE); }
<LAW>.								{ D; syntax("unexpected character in jurisdiction tag", yytext); }
<LAW>\n								{ D; syntax("unexpected end of line instead of jurisdiction tag", ""); }
<LAW><<EOF>>							{ D; syntax("unexpected end of file in jurisdiction tag", yytext); }


 /* MAIN */

<MAIN>{
^({letter}|{digit}|[ .])+[ ][ ]/{digit} 			{ D; mtrac_free(prec_file); prec_file = trim(mtrac_strdup(yytext));
									if(opt_debug_mainscan) printf("file %s ", yytext); BEGIN(LINENO); }
:								{ D; DX(Colon); return Colon; }
,								{ D; DX(Comma); return Comma; }
;								{ D; DX(Semicolon); return Semicolon; }
–								{ D; DX(Dash); return Dash; }
[%]								{ D; DX(Percent); return Percent; }
(\"|“|”)							{ D; DX(Quote); return Quote; }
({space}*\n){2}({space}*\n)*					{ D; DX(Separator); return Separator; }
\.({space}*\n)*							{ D; DX(Separator); return Separator; }
{white}+							{ D; }
«								{ D; BEGIN(NAME_); }
\"?{space}*‹							{ D; BEGIN(DESCRIPTION_); }
{scalar}                                                        { D; DX(SCALAR); yylval.Scalar=mtrac_strdup_gross(yytext); return SCALAR; }
 /* //# {hex}								{ D; DX(HEX); yylval.Hex=mtrac_strdup_gross(yytext); return HEX; } */
 /* --> 2ND CYCLE LGF GENERATED KEYWORDS HERE --> */
{term}                                                          { D; printf(" %s", yytext); }
 /* <-- TO HERE <-- */
.								{ D; syntax("unexpected character", yytext); }
}

<LINENO>{
{digit}+/:							{ D; prec_line = atoi(yytext); if(opt_debug_mainscan) printf("line %s: ", yytext); }
:								{ D; BEGIN(MAIN); }
.								{ D; syntax("unexpected character in line number (after precompilation, use -P to check)",
									yytext); }
<<EOF>>								{ D; syntax("unexpected end of file in line number (after precompilation, use -P to check)",
									yytext); }
}

<NAME_>{
[^»]+								{ D; DX(NAME); yylval.Name=mtrac_strdup_gross(yytext); return NAME; }
»								{ D; BEGIN(MAIN); }
<<EOF>>								{ D; syntax("unexpected end of file - precompiler name quote error", yytext); }
}

<DESCRIPTION_>{
[^›]+								{ D; DX(DESCRIPTION); yylval.Description=mtrac_strdup_gross(yytext); return DESCRIPTION; }
›{space}*\"?{space}*\.?({space}*\n)*				{ D; DX(Separator); BEGIN(MAIN); return Separator; }
›{space}*\"?{space}*/[,;]					{ D;                BEGIN(MAIN); }
<<EOF>>								{ D; syntax("unexpected end of file - precompiler description quote error", yytext); }
}

 /* The LXF patterns are sloppy. whitespace and colons are trimmed off later */

<LXF>{
^{space}*COMMENT{space}*:?.*/\n                                 { D; }
^{space}*\/\/.*/\n						{ D; }
^{space}*#.*/\n							{ D; }
^{space}*javascript{space}*:?.*/\n				{ D; BEGIN(EMBED); }
^{space}*solidity{space}*:?.*/\n				{ D; BEGIN(EMBED); }
^{space}*sophia{space}*:?.*/\n					{ D; BEGIN(EMBED); }
^{space}*{word}{space}*:?{space}*/\n				{ D; start_definition(yytext); }
^{space}*{word}{space}*:{space}*				{ D; start_alternation(yytext); start_alternate(); }
^{space}*Someone						{ D; start_rule(active, personal); }
^{space}*Somebody						{ D; start_rule(passive, personal); }
^{space}*Something						{ D; start_rule(passive, factual); }
^{space}*A{space}+Fact						{ D; start_rule(passive, factual); }
\]{space}+\[							{ D; end_option(spaced); start_option(spaced); }
{space}+\[							{ D; start_option(spaced); }
\[								{ D; start_option(unspaced); }
\]{space}*/\n							{ D; end_option(spaced); }
\]{space}+							{ D; end_option(spaced); }
\]								{ D; end_option(unspaced); }
somebody							{ D; add_keyword(yytext); }
party								{ D; add_keyword(yytext); }
{word}								{ D; add_word(yytext); }
,								{ D; start_alternate(); }
\.{space}*\n							{ D; line++; /* end_rule(); */ }
{space}+							{ D; }
\n								{ D; line++; }
.								{ D; syntax("unexpected character", yytext); }
<EMBED><<EOF>>							{ D; produce_extension(grammar); exit(0); yyterminate(); return 0; }
}

<EMBED>.+							{ D; add_embed(yytext); }
<EMBED>\n							{ D; lineno(); add_embed(yytext); }


 /* Lexon Grammar Form: precompiling LGF to BNF */

<LGF>{
^.*Version{space}*.*/\n		/* grammar version */		{ D; S; mtrac_free(grammar_version);
									grammar_version = trim(mtrac_strdup(strstr(yytext, "Version") + 7)); }
^{space}*\/\/.*/\n		/* comment */			{ D; }
^{space}*#.*/\n			/* comment */			{ D; }
^[^ \t\n][^:\n]+{space}*/\n	/* comment */			{ D; }
{space}*or{space}*  /* spaces make it longest pattern */	{ D; S; start_rule(none, neutral); }
^{space}*{token}{space}*:?{space}*				{ D; start_definition(yytext); start_rule(none, neutral); S; }
^{space}*{spaced}{space}*:?{space}*				{ D; start_definition(yytext); start_rule(none, neutral); S; }
{token}{space}*/\/						{ D; S; add_word(yytext); start_alternation(yytext); }
{quote}{token}{quote}{space}*/\/				{ D; S; add_word(yytext); start_alternation(yytext); }
\/{space}*{token}						{ D; S; start_alternate(); add_word(yytext); }
\/{space}*{quote}{word}{quote}					{ D; S; start_alternate(); add_word(yytext); }
{token}								{ D; S; continue_rule(); add_word(yytext); }
{quote}{word}{quote}						{ D; S; continue_rule(); add_word(yytext); }
{quote}:{quote}							{ D; S; continue_rule(); add_word("colon"); }
{quote},{quote}							{ D; S; continue_rule(); add_word("comma"); }
{quote}[%]{quote}						{ D; S; continue_rule(); add_word("percent"); }
{quote}{interpunctuation}{quote}				{ D; S; continue_rule(); add_word(yytext); }
\]{space}+\[							{ D; S; end_option(spaced); start_option(spaced); }
{space}+\[							{ D; S; start_option(spaced); }
\[								{ D; S; start_option(unspaced); }
\]{space}*/\n							{ D; S; end_option(spaced); }
\]{space}+							{ D; S; end_option(spaced); }
\]								{ D; S; end_option(unspaced); }
{space}+							{ D; S; }
\n								{ D; S; line++; }
.								{ D; syntax("unexpected character", yytext); }
<<EOF>>								{ D; produce_grammar(grammar); yyterminate(); }
}

%%


/* part III: code --------------------------------------------------------- */


#undef fprintf

#ifndef WHITEBOX
int main(int argc, char **argv) {

	clock_t start = clock();

	/* print name and version: separated out from other command line handling (parsargs() below) */
	int i = argc;
	while(i-->0) if(strstr(argv[i], "-V") || strstr(argv[i], "--vers")) { printf("\n%s\n\n", slug); break; }

	/* debug: separated out from other command line handling (parsargs() below) to show args parsing, too */
	i = argc;
	while(i-->0) if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "--debug")) { opt_debug = true; break; }

	/* setting defaults for stdin. Source file may be set in parseargs() immediately below */
	file_clearname = mtrac_strdup("stdin");
	file_namepart = mtrac_strdup("stdin");
	file_pathpart = mtrac_strdup("-");
	file_location = mtrac_strdup("-");
	file_fileptr = null;

	/* (**) dynamic allocation of command line arg defaults, so they can be blindly freed */
	opt_include_path = mtrac_strdup(opt_include_path);
	opt_langprefix = mtrac_strdup(opt_langprefix);

	/* process command line settings */
	parsargs(argc, argv);

	/* initialize buffers so they can be blindly freed */
	prec_file = mtrac_strdup("");
	context = mtrac_strdup("");
	keywords = mtrac_strdup("");
	funclist = mtrac_strdup("");
	buf = mtrac_strdup("");
	buf2 = mtrac_strdup("");
	src = mtrac_strdup("");

	/* ditto for grammar version string */
	grammar_version = mtrac_strdup(grammar_version);

	/* known, special tokens for LGF */
	add_token(&predef, "Separator", null, null, keep);
	add_token(&predef, "Comma", null, null, keep);
	add_token(&predef, "Colon", null, null, keep);
	add_token(&predef, "Semicolon", null, null, keep);
	add_token(&predef, "Dash", null, null, keep);
	add_token(&predef, "Percent", null, null, keep);
	add_token(&predef, "Quote", null, null, keep);
	add_token(&predef, "Name", null, null, keep);
	add_token(&predef, "Description", null, null, keep);
	add_token(&predef, "Scalar", null, null, keep);
	//# add_token(&predef, "Hex", null, null, keep);

	/* ignore when building BNF from LGF */
	add_token(&ignores, "Separator", null, null, keep);
	add_token(&ignores, "Comma", null, null, keep);
	add_token(&ignores, "Colon", null, null, keep);
	add_token(&ignores, "Semicolon", null, null, keep);
	add_token(&ignores, "Dash", null, null, keep);
	add_token(&ignores, "Percent", null, null, keep);
	add_token(&ignores, "Quote", null, null, keep);

	/* known, special tokens for LXF */
	add_token(&xpredef, "Separator", null, null, keep);
	add_token(&xpredef, "Comma", null, null, keep);
	add_token(&xpredef, "Colon", null, null, keep);
	add_token(&xpredef, "Semicolon", null, null, keep);
	add_token(&xpredef, "Dash", null, null, keep);
	add_token(&xpredef, "Percent", null, null, keep);
	add_token(&xpredef, "Name", null, null, keep);
	add_token(&xpredef, "Description", null, null, keep);
	add_token(&xpredef, "Scalar", null, null, keep);
	//# add_token(&xpredef, "Hex", null, null, keep);
	add_token(&xpredef, "Party", null, null, keep);
	add_token(&xpredef, "Somebody", null, null, keep);
	add_token(&xpredef, "Someone", null, null, keep);
	add_token(&xpredef, "Something", null, null, keep);
	add_token(&xpredef, "Thing", null, null, keep);

	/* initialize comments map */
	new_lexcom("start", "");

	/* emulate reading a law file */
	emulaws();

	/* main parse actions */
	yy_flex_debug = opt_debug_scanner;
	if(opt_jurisdictions) {
		if(opt_verbose || opt_debug) printf("• jurisdictions\n");
		dump_laws();
		exit(0);
	} else if(opt_grammar) {
		if(opt_verbose || opt_debug) printf("• grammar\n");
		printf("%s\n", owngrm);
		exit(0);
	} else if(opt_manual) {
		if(opt_verbose || opt_debug) printf("• manual\n");
		printf("%s\n", manual);
		exit(0);
	} else if(opt_geninfo || opt_keywords || opt_samples || opt_bootstrap || opt_yacc || opt_bnf || opt_template) {
		if(opt_verbose || opt_debug) printf("• scanning\n");
		do_main_pass = false;
		while(yylex()); /* 1st cycle ccc uses only the scanner, not a parser */
		if(opt_geninfo){
			if(opt_verbose || opt_debug) printf("• generator info\n");
			geninfo();
		} else if(opt_keywords) {
			if(opt_verbose || opt_debug) printf("• keywords\n");
			printf("%s\n", keywords);
		}
	} else {
#ifndef CYCLE_2
		fprintf(stderr, "this program is only a 1st cycle generator that cannot compile lexon code.\n");
		exit(3);
#else
		yydebug = opt_debug_parser;
		if(opt_verbose || opt_debug) printf("• parsing\n");
		yyparse(); /* calls yylex() */
		if(opt_verbose || opt_debug) printf("• walking\n");
		char *prod = walk();

		/* print to screen */
		if(!opt_quiet && !opt_output) {
			if(opt_verbose || opt_debug)
				printf("\nproduct:\n--------\n%s\n", prod); else printf("%s", prod);
		}

		/* write to file */
		if(opt_output) {
			if(opt_verbose || opt_debug) printf("• writing\n");
			/* backup previous output */
			if(access(opt_output, F_OK) != -1) {
				char *bak = mtrac_malloc(strlen(opt_output) + 1 + 1 + 6 + 4);
				sprintf(bak, "%s-%ld.bak", opt_output, time(NULL) % 100000);
				if(rename(opt_output, bak)) {
					fprintf(stderr, "cant create backup for existing %s. ", opt_output);
					perror(bak); exit(1);
				}
				mtrac_free(bak);
			}
			/* write */
			FILE *out;
			if(!(out = fopen(opt_output, "w"))) { perror(opt_output); exit(1); }
			if(fputs(prod, out) == EOF) {
				fprintf(stderr, "failed to write output ");
				perror(opt_output); exit(1);
			}
			fclose(out);
		}

		mtrac_free(prod);
#endif
	}

	/* TODO MOVE */
	/* clean up * /
	yy_delete_buffer(YY_CURRENT_BUFFER); // ? --> sic bec (*)

	/ * list precompilation, json for gui, or known laws to screen * /
	if(!opt_precompile && !opt_geninfo && !opt_names && !opt_jurisdictions && !opt_included_files)
		puts(buf2);
	*/

	/* time measure */
	if(opt_verbose || opt_debug || opt_debug_time) {
		clock_t end = clock() ;
		double elapsed_time = (end-start) * 1000 / (double)CLOCKS_PER_SEC ;
		printf("• time: %f ms\n", elapsed_time);
	}

	clean_exit(); // exits exit(0);

	return 0;
}
#endif

/* dynamic memory clean up / check */
void clean_exit() {

	if(_xcr) mtrac_free(_xcr);

	mtrac_free(funclist);
	mtrac_free(buf);
	mtrac_free(buf2);
	mtrac_free(src);
	mtrac_free(prec_file);
	mtrac_free(context);
	mtrac_free(keywords);
	yylex_destroy(); // Flex scan buffer and stack

	delete_stringlist(predef);
	delete_stringlist(ignores);
	delete_stringlist(xpredef);

	delete_laws();
	delete_definitions(grammar);
	delete_stringlist(tokens);

	delete_map(lexcoms);

	if(opt_output) mtrac_free(opt_output);
	mtrac_free(grammar_version);
	if(opt_yacc) mtrac_free(opt_yacc);
	if(opt_header) mtrac_free(opt_header);
	if(opt_bootstrap) mtrac_free(opt_bootstrap);
	mtrac_free(opt_include_path);
	mtrac_free(opt_langprefix);
	if(opt_log) mtrac_free(opt_log);
	if(opt_signatures) mtrac_free(opt_signatures);
	if(opt_persistence) mtrac_free(opt_persistence);
	if(opt_bundle) mtrac_free(opt_bundle);
	if(opt_email) mtrac_free(opt_email);
	if(opt_template) mtrac_free(opt_template);
 	if(opt_source_base) mtrac_free(opt_source_base);
 	if(opt_samples) mtrac_free(opt_samples);
 	if(opt_summarized) mtrac_free(opt_summarized);
	if(opt_color) mtrac_free(opt_color);
	if(opt_highlight) mtrac_free(opt_highlight);
	if(opt_symbols) mtrac_free(opt_symbols);
	if(opt_values) mtrac_free(opt_values);
	if(opt_subvalues) mtrac_free(opt_subvalues);

	if(law_name) mtrac_free(law_name);
	if(law_abbr) mtrac_free(law_abbr);
	if(law_ext) mtrac_free(law_ext);

	mtrac_free(file_clearname);
	mtrac_free(file_namepart);
	mtrac_free(file_pathpart);
	mtrac_free(file_location);
	fclose(file_fileptr);

	delete_include_trace();

	delete_node_list(symbols);
	mtrac_free_gross();

	mtrac_check();

	if(opt_verbose || opt_debug) printf("• done\n\n");

	exit(0);
}

void parsargs(int argc, char **argv) {
    static struct option long_options[] = {
	{"help",                     no_argument,       null, 'h'},
	{"version",                  no_argument,       null, 'V'},
	{"manual",                   no_argument,       null, 'm'},
	{"instructions",             no_argument,       null, 'u'},
	{"output",                   required_argument, null, 'o'},
	{"run",                      no_argument,       null, 'r'},
	{"echo-source",              no_argument,       null, 'j'},
	{"precompile-only",          no_argument,       null, 'P'},
	{"echo-precompile",          no_argument,       null, 'W'},
	{"names",                    no_argument,       null, 'N'},
	{"jurisdictions",            no_argument,       null, 'J'},
	{"include-path",             required_argument, null, 'i'},
	{"included-files",           no_argument,       null, 'I'},
	{"ui-info",                  optional_argument, null, 'U'},
	{"grammar",                  no_argument,       null, 'G'},
	{"bnf",                      no_argument,       null, 'B'},
	{"parser",                   optional_argument, null, 'Y'},
	{"template",                 optional_argument, null, 'T'},
	{"language-prefix",          optional_argument, null, 'L'},
	{"keywords",                 no_argument,       null, 'K'},
	{"scanner",                  optional_argument, null, 'S'},
	{"source-file",              required_argument, null, 'F'},
	{"header",                   required_argument, null, 'H'},
	{"examples",                 optional_argument, null, 'E'},
	{"max-examples",             optional_argument, null, 'n'},
	{"check",                    no_argument,       null, 'k'},
	{"bare",                     no_argument,       null, 'b'},
	{"comment",                  no_argument,       null, 'y'},
	{"quote-source",             no_argument,       null, 'q'},
	{"feedback",                 no_argument,       null, 'f'},
	{"action-lists",             no_argument,       null, 'a'},
	{"harden",                   no_argument,       null, 'z'},
	{"log",                      optional_argument, null, 'l'},
	{"signatures",               no_argument,       null, 's'},
	{"chaining",                 optional_argument, null, 'c'},
	{"persistence",              optional_argument, null, 'p'},
	{"bundle",                   optional_argument, null, 't'},
	{"email",                    optional_argument, null, 'e'},
	{"all-auxiliaries",          no_argument,       null, 'x'},
	{"wipe",                     no_argument,       null, 'w'},
	{"ignore-circular-includes", no_argument,       null, 'C'},
	{"ignore-repeat-includes",   no_argument,       null, 'R'},
	{"verbose",                  no_argument,       null, 'v'},
	{"no-result",                no_argument,       null, 'Q'},
	{"debug",                    no_argument,       null, 'd'},
	{"debug-modules",            optional_argument, null, 'D'},
	{"memory-check",             no_argument,       null, 'M'},
	/* target languages */
	{"tree",                     no_argument,       null, '0'}, // #tree
	{"core",                     no_argument,       null, '1'}, // #core
	{"javascript",               no_argument,       null, '2'}, // #javascript
	{"solidity",                 no_argument,       null, '3'}, // #solidity
	{"sophia",                   no_argument,       null, '4'}, // #sophia
//#	{"spheres",                  no_argument,       null, '5'}, // #spheres
	{"color",                    optional_argument, null, 1000},
	{"symbols",                  optional_argument, null, 1001},
	{"leaves",                   optional_argument, null, 1002},
	{"subleaves",                optional_argument, null, 1003},
	{"highlight",                optional_argument, null, 1004},
	{"flat",                     no_argument,       null, 1005},
	{"terse",                    no_argument,       null, 1006},
	{null,                       0,                 null,  0 }
    };
    int c;
    int option_index = 0;
    opt_summarized = mtrac_strdup("");
    while ((c = getopt_long(argc, argv,
    		"hVmuo:rjPWNJi:IUGBY::T::L::KS::F:H:E::n::kbyqfazl::sc::p::t::e::xwCRvQdD::M01234",
		long_options, &option_index)) != -1) {
	if(c == '?') { fprintf(stderr, "parameter error"); exit(1); }

	struct option *o = long_options;
	while(o && o->val != c) o++;
	assert(o && o->name);
	mtrac_concat(&opt_summarized, *opt_summarized?" ":"", "--", o->name, " ", optarg ? optarg : "");

	int this_option_optind = optind ? optind : 1;
	switch (c) {
	case 'h':
	    if(opt_debug) printf ("print help and quit: on\n");
	    opt_help = true;
	    help(); // exits
	    break;
	case 'V':
	    exit(0); //handled earlier, in main. case to prevent arg error msg
	case 'm':
	    if(opt_debug) printf ("manual listing: on\n");
	    opt_manual = true;
	    break;
	case 'u':
	    if(opt_debug) printf ("generate usage instructions: on\n");
	    opt_instructions = true;
	    break;
	case 'v':
	    if(opt_debug) printf ("verbose output: on\n");
	    opt_verbose = true;
	    break;
	case 'o':
	    if(opt_verbose || opt_debug) printf ("output file: %s\n", optarg);
	    if(!optarg) {
	    	fprintf(stderr, "output file name missing after -o or --output\n");
		exit(1);
	    }
	    assert(!opt_output);
	    opt_output = mtrac_strdup(optarg);
	    break;
	case 'Q':
	    if(opt_debug) printf ("quiet result output: on\n");
	    opt_quiet = true;
	    break;
	case 'j':
	    if(opt_debug) printf ("echo source file: on\n");
	    opt_echo = true;
	    break;
	 case 'P':
	    if(opt_debug) printf ("precompilation output: on\n");
	    opt_precompile = true;
	    break;
	 case 'W':
	    if(opt_debug) printf ("echo precompilation and continue: on\n");
	    opt_pre_echo = true;
	    break;
	case 'N':
	    if(opt_debug) printf ("names list output: on\n");
	    opt_names = true;
	    break;
	case 'J':
	    if(opt_debug) printf ("jurisdictions list output: on\n");
	    opt_jurisdictions = true;
	    break;
	case 'I':
	    if(opt_debug) printf ("included file trace: on\n");
	    opt_included_files = true;
	    break;
	case 'U':
	    if(opt_debug) printf ("ui generator info json output: on\n");
	    opt_geninfo = true;
	    break;
	case 'G':
	    if(opt_debug) printf ("LGF grammar listing: on\n");
	    opt_grammar = true;
	    break;
	case 'B':
	    if(opt_debug) printf ("BNF grammar production output: on\n");
	    opt_bnf = true;
	    break;
	case 'Y':
	    if(opt_verbose || opt_debug) printf ("yacc file including BNF grammar production: %s\n", optarg ? optarg : "on (to stdout)");
	    opt_yacc = mtrac_strdup(optarg ? optarg : "");
	    break;
	case 'T':
	    if(opt_verbose || opt_debug) printf ("write walk function template top: %s\n", optarg ? optarg : "on (to stdout)");
	    opt_template = mtrac_strdup(optarg ? optarg : "");
	    break;
	case 'L':
	    if(opt_verbose || opt_debug) printf ("walk function language prefix: %s\n", optarg ? optarg : opt_langprefix);
	    if(optarg) {
		mtrac_free(opt_langprefix);
		opt_langprefix = mtrac_strdup(optarg);
	    }
	    break;
	case 'K':
	    if(opt_debug) printf ("lexer tokens / keyword output: on\n");
	    opt_keywords = true;
	    break;
	case 'S':
	    opt_bootstrap = mtrac_strdup(optarg ? optarg : "");
	    if(opt_verbose || opt_debug) printf ("write scanner file to: %s\n", optarg ? opt_bootstrap : "screen");
	    break;
	case 'F':
       	    if(opt_verbose || opt_debug) printf ("build scanner based on source file: %s\n", optarg ? optarg : "missing");
	    if(!optarg) {
	    	fprintf(stderr, "source file name missing after -F or --source-file parameter\n");
		exit(1);
	    }
	    opt_source_base = mtrac_strdup(optarg);
	    break;
	case 'H':
       	    if(opt_verbose || opt_debug) printf ("header to include in lexer file: %s\n", optarg ? optarg : "missing");
	    if(!optarg) {
	    	fprintf(stderr, "header file name missing after -H or --header parameter\n");
		exit(1);
	    }
	    opt_header = mtrac_strdup(optarg);
	    break;
	case 'E':
	    opt_samples = mtrac_strdup(optarg ? optarg : "");
	    if(opt_verbose || opt_debug) printf ("sample Lexon code production from LGF to: %s\n", optarg ? opt_samples : "screen");
	    break;
	case 'n':
	    opt_max_examples = optarg ? atoi(optarg) : 10;
	    if(opt_verbose || opt_debug) printf ("maximal number of examples to be produced: %d\n", opt_max_examples);
	    break;
	case 'k':
	    if(opt_debug) printf ("check completeness of LGF grammar: on\n");
	    opt_samples = mtrac_strdup("");
	    opt_quiet = true;
	    break;
	case 'y':
	    if(opt_debug) printf ("comments in grammar production: on\n");
	    opt_comment = true;
	    opt_lexon_comments = true;
	    break;
	case 'b':
	    if(opt_debug) printf ("generated source is barebones happy path for demonstration: on\n");
	    opt_bare = true;
	    opt_comment = false;
	    opt_lexon_comments = false;
	    opt_instructions = false;
	    opt_feedback = false;
	    opt_harden = false;
	    if(opt_log) mtrac_free(opt_log), opt_log = null;
	    if(opt_signatures) mtrac_free(opt_signatures), opt_signatures = null;
	    opt_chaining = 0;
	    if(opt_persistence) mtrac_free(opt_persistence), opt_persistence = null;
	    if(opt_bundle) mtrac_free(opt_bundle), opt_bundle = null;
	    if(opt_email) mtrac_free(opt_email), opt_email = null;
	    break;
	case 'x':
	    if(opt_debug) printf ("generated source has all auxiliary features: on\n");
	    opt_bare = false;
	    opt_comment = true;
	    opt_lexon_comments = true;
	    opt_instructions = true;
	    opt_feedback = true;
	    opt_harden = true;
	    if(!opt_log) opt_log = mtrac_strdup("log");
	    if(!opt_signatures) opt_signatures = mtrac_strdup("*.key");
	    if(!opt_chaining) opt_chaining = 12;
	    if(!opt_persistence) opt_persistence = mtrac_strdup("state");
	    if(!opt_bundle) opt_bundle = mtrac_strdup("contract.tgz");
	    if(!opt_email) opt_email = mtrac_strdup("config");
	    break;
	case 'f':
	    if(opt_debug) printf ("generated source answers actions with feedback output: on\n");
	    opt_feedback = true;
	    break;
	case 'z':
	    if(opt_debug) printf ("generated source checks for wrong input and missing state: on\n");
	    opt_harden = true;
	    break;
	case 'l':
	    if(opt_log) mtrac_free(opt_log);
	    opt_log = mtrac_strdup(optarg ? optarg : "log");
       	    if(opt_verbose || opt_debug) printf ("generated source writes log of state change to: %s\n", opt_log);
	    break;
	case 's':
	    if(opt_signatures) mtrac_free(opt_signatures);
	    opt_signatures = mtrac_strdup(optarg ? optarg : "*.key");
	    if(opt_debug) printf ("log signatures for state changes, signature file: %s\n", opt_signatures);
	    // effects --log
	    if(!opt_log) opt_log = mtrac_strdup("log");
	    break;
	case 'c':
	    opt_chaining = optarg ? atoi(optarg) : 12;
	    if(opt_debug) printf ("log entries are hash-chained, hash length: %d (64 = full)\n", opt_chaining);
	    // effects --log
	    if(!opt_log) opt_log = mtrac_strdup("log");
	    break;
	case 'p':
	    if(opt_persistence) mtrac_free(opt_persistence);
	    opt_persistence = mtrac_strdup(optarg ? optarg : "state");
       	    if(opt_verbose || opt_debug) printf ("generated source writes state to: %s\n", opt_persistence);
	    break;
	case 't':
	    if(opt_bundle) mtrac_free(opt_bundle);
	    opt_bundle = mtrac_strdup(optarg ? optarg : "contract.tgz");
       	    if(opt_verbose || opt_debug) printf ("generated source bundles code, state and log to: %s\n", opt_bundle);
	    break;
	case 'e':
	    if(opt_email) mtrac_free(opt_email);
	    opt_email = mtrac_strdup(optarg ? optarg : "config");
       	    if(opt_verbose || opt_debug) printf ("generated source uses email configuration in: %s\n", opt_persistence);
	    break;
	case 'w':
	    if(opt_debug) printf ("wipe older files of same pattern: on\n");
	    opt_wipe = true;
	    break;
	case 'i':
	    if(opt_verbose || opt_debug) printf ("include path: %s\n", optarg);
	    if(!optarg) {
	    	fprintf(stderr, "path missing after -I or --include-path parameter\n");
		exit(1);
	    }
	    mtrac_free(opt_include_path);
	    opt_include_path = mtrac_strdup(optarg);
	    break;
	case 'C':
	    if(opt_debug) printf ("ignore circular includes: on\n");
	    opt_ignore_circular_includes = true;
	    break;
	case 'R':
	    if(opt_debug) printf ("ignore repeat includes: on\n");
	    opt_ignore_repeat_includes = true;
	    break;
	case 'd':
	    printf ("debug output: on\n");
	    opt_debug = true;
	    break;
	case 'D':
	    if(opt_verbose) printf ("specific modules debug output: %s\n", optarg?optarg:"all on");
     	    opt_debug_regex = !optarg || strstr(optarg, "regex");
	    opt_debug_scanner = !optarg || strstr(optarg, "scanner");
	    opt_debug_mainscan = !optarg || strstr(optarg, "mainscan");
	    opt_debug_actions = !optarg || strstr(optarg, "actions");
	    opt_debug_tokens = !optarg || strstr(optarg, "tokens");
	    opt_debug_parser = !optarg || strstr(optarg, "parser");
	    opt_debug_lists = !optarg || strstr(optarg, "lists");
	    opt_debug_generator = !optarg || strstr(optarg, "generator");
	    opt_debug_examples = !optarg || strstr(optarg, "examples");
	    opt_debug_production = !optarg || strstr(optarg, "production");
	    opt_debug_time = !optarg || strstr(optarg, "time");
	    opt_debug_dev = !optarg || strstr(optarg, "dev");
	    opt_debug_allow_double_names = !optarg || strstr(optarg, "allow_double_names");
	    bool fail = optarg && !opt_debug_regex && !opt_debug_scanner && !opt_debug_mainscan && !opt_debug_actions && !opt_debug_tokens && !opt_debug_parser
		&& !opt_debug_generator && !opt_debug_examples && !opt_debug_lists && !opt_debug_production && !opt_debug_time && !opt_debug_dev && !opt_debug_allow_double_names;
	    if(opt_verbose || fail || (optarg && !strcmp(optarg, "h"))) {
		    printf ("module debug regex     : %s   scanned regex pattern results of the scanner (Flex) tokenizing input\n",
		    	opt_debug_regex     ?"yes":"no ");
		    printf ("module debug scanner   : %s   scanner (Flex) live process trace during input scan (LGF, LXF, LEX)\n",
		    	opt_debug_scanner   ?"yes":"no ");
		    printf ("module debug mainscan  : %s   token production of scan pass of precompiled code (LEX files only)\n",
		    	opt_debug_mainscan  ?"yes":"no ");
		    printf ("module debug actions   : %s   rule actions processing new nodes during build up of AST (LEX only)\n",
		    	opt_debug_actions   ?"yes":"no ");
		    printf ("module debug tokens    : %s   recognized tokens resulting from parser grammar rule match\n",
		    	opt_debug_tokens    ?"yes":"no ");
		    printf ("module debug parser    : %s   parser (Bison) live shift/reduce and stack trace (LEX files only)\n",
		    	opt_debug_parser    ?"yes":"no ");
		    printf ("module debug generator : %s   cycle 1 rule prosessing during parser generation (LGF and LXF only)\n",
		    	opt_debug_generator ?"yes":"no ");
		    printf ("module debug examples  : %s   production of examples based on LGF\n",
		    	opt_debug_examples  ?"yes":"no ");
		    printf ("module debug lists     : %s   low level list management (LGF, LXF, LEX)\n",
		    	opt_debug_lists     ?"yes":"no ");
		    printf ("module debug production: %s   print target output module line numbers into the produced code\n",
		    	opt_debug_production?"yes":"no ");
		    printf ("module debug time      : %s   display total runtime at regulat program exit\n",
		    	opt_debug_time      ?"yes":"no ");
		    printf ("module debug dev       : %s   varying hot spots (use opt_debug_dev during development)\n",
		    	opt_debug_dev       ?"yes":"no ");
		    printf ("allow double names     : %s   for grammar test parsing of generated code\n",
		    	opt_debug_allow_double_names?"yes":"no ");
	    }
       	    if(fail) {
		if(strcmp(optarg, "h")) fprintf(stderr, "no module selected by string '%s'. ", optarg);
		fprintf(stderr, "Use one or more of the names above (e.g. -Dregex,tokens)\n");
		exit(1);
	    }
    	    break;
	case 'M':
	    #ifndef MEMORY_CHECKS
	    fprintf("memory checks not supported by this build\n"), exit(12);
	    #endif
	    if(opt_debug) printf ("memory check activated: on\n");
	    opt_memory = true;
	    break;
	case '0':
	    if(opt_debug) printf ("abstract syntax tree ouput: on\n");
	    opt_produce_tree = true;
	    break;
	case '1':
	    if(opt_debug) printf ("core language ouput: on\n");
	    opt_produce_core = true;
	    break;
	case '2':
	    if(opt_debug) printf ("javascript language ouput: on\n");
	    opt_produce_javascript = true;
	    break;
	case '3':
	    if(opt_debug) printf ("solidity language ouput: on\n");
	    opt_produce_solidity = true;
	    break;
	case '4':
	    if(opt_debug) printf ("sophia language ouput: on\n");
	    opt_produce_sophia = true;
	    break;
//#	case '5':
//#	    if(opt_debug) printf ("run spheres: on\n");
//#	    opt_run_spheres = true;
//#	    break;
	/* color */
	case 1000:
       	    if(opt_verbose || opt_debug) printf ("color: %s\n", optarg ? optarg : "on (bold)");
	    if(opt_color) mtrac_free(opt_color);
	    opt_color = mtrac_strdup(""); concat(&opt_color, "\033[", optarg ? optarg : "1", "m");
	    replace(&opt_color, ",", ";");
	    optarg = null;
	    // fall through to symbols, values, subvalues, tokens
	/* symbols highlighting */
	case 1001:
       	    if(opt_verbose || opt_debug) printf ("symbol highlighting: %s\n", optarg ? optarg : "on (bold)");
	    if(opt_symbols) mtrac_free(opt_symbols);
	    opt_symbols = mtrac_strdup(""); concat(&opt_symbols, "\033[", optarg ? optarg : "36", "m");
	    replace(&opt_symbols, ",", ";");
	    if(c!=1000) break;
	/* values highlighting */
	case 1002:
	    if(opt_values) mtrac_free(opt_values);
	    opt_values = mtrac_strdup(optarg ? optarg : "type,combinator,illocutor");
	    if(!opt_color) opt_color = mtrac_strdup("\033[1m");
       	    if(opt_verbose || opt_debug) printf ("values highlighting: %s\n", opt_values);
	    if(c!=1000) break;
	/* subvalues highlighting */
	case 1003:
	    if(opt_subvalues) mtrac_free(opt_subvalues);
	    opt_subvalues = mtrac_strdup(optarg ? optarg : "predicate");
	    if(!opt_color) opt_color = mtrac_strdup("\033[1m");
       	    if(opt_verbose || opt_debug) printf ("sub value highlighting: %s\n", opt_subvalues);
	    if(c!=1000) break;
	/* highlight tokens */
	case 1004:
	    if(opt_highlight) mtrac_free(opt_highlight);
	    opt_highlight = mtrac_strdup(optarg ? optarg : "clause,subject,object,if");
	    if(!opt_color) opt_color = mtrac_strdup("\033[1m");
       	    if(opt_verbose || opt_debug) printf ("token highlighting: %s\n", opt_highlight);
	    break;
	/* flattened tree */
	case 1005:
	    if(opt_debug) printf ("packed binary lists: on\n");
	    opt_produce_flat = true;
	    break;
	/* terse tree */
	case 1006:
	    if(opt_debug) printf ("terse tree: on\n");
	    opt_produce_terse = true;
	    break;
	case ':':
	    fprintf (stderr, "command line parameter error, missing argument\n");
	    exit(1);
	default:
	    fprintf (stderr, "command line parameter error (0%o)\n", c); // ◊ allow ignoring
	    exit(1);
	}
    }

    /* source file is given as command line parameter */
    if (optind < argc) {
    	opt_source = argv[optind];
	if(opt_verbose || opt_debug) fprintf(stderr, "• source file: %s\n", opt_source);

	/* the following replaces defaults of all file_* globals */
	mtrac_free(file_clearname); file_clearname = null;
	mtrac_free(file_namepart); file_namepart = null;
	mtrac_free(file_pathpart); file_pathpart = null;
	mtrac_free(file_location); file_location = null;

	/* build pretty clear name, extraxt path and file name */
	rump(&file_clearname, opt_source);
	char *tmp = mtrac_strdup(opt_source);
	file_namepart = mtrac_strdup(basename(tmp));
	mtrac_free(tmp);
	tmp = mtrac_strdup(opt_source);
	file_pathpart = mtrac_strdup(dirname(tmp));
	mtrac_free(tmp);

	/* for switching back to the directory that the program was started in */
	if(getcwd(name_homedir, sizeof(name_homedir)) == NULL) {
		perror("could not get home directory");
		exit(15);
	}

	/* change working directory - to allow for relative includes */
	if(opt_verbose || opt_debug) fprintf(stderr, "• change to source file's folder: %s\n", file_pathpart);
	if(chdir(file_pathpart) != 0) {
		fprintf(stderr, "Failed to change into the directory '%s' of the source file '%s'. Code: %s\n", file_pathpart, file_namepart, yytext);
		perror(file_pathpart);
		exit(16);
	}

	/* record absolute path of source directory. Also for later switch back from includes. */
	file_location = mtrac_malloc(PATH_MAX);
	if(getcwd(file_location, PATH_MAX) == NULL) {
		perror("could not read source file directory name");
		exit(17);
	}

	/* open the source file, from its home directory */
	assert(file_fileptr == null);
	if(!(file_fileptr = fopen(file_namepart, "r"))) {
		fprintf(stderr, "Failed to open source file '%s' expected in directory '%s'. Code: %s\n", file_namepart, file_pathpart, yytext);
		perror(file_namepart);
		exit(19);
	}

	/* echo source file */
	if(opt_echo) {
		FILE *fp = file_fileptr;
		fseek(fp, 0L, SEEK_END);
		int size = ftell(fp);
		rewind(fp);
		char *src = news(src, size + 1);
		if(fread(src, 1, size, fp) != size) { perror(file_namepart); exit(20); }
		rewind(fp);
		printf("\nsource:\n-------\n%s\n", src);
		mtrac_free(src);
	}

	yyin = file_fileptr; //.. necessary?
	line = 1;
    }
}

void help() {
	puts("\n\t" slug "\n\n\
	Lexon is a compiler that translates controlled natural language into program languages.\n\
	It can also be used to create or extend itself by processing Lexon Grammar Form (LGF).\n\
	\n\
	usage: lexon [options] [<source file>]\n\
	\n\
	-V --version                    print version slug and exit\n\
	-h --help                       print this text and exit\n\
	-m --manual                     print the readme text and exit\n\
	-o --output <file name>         write result of source translation to <file name> (default: stdout)\n\
	-j --echo-source                list the source text that will be processed\n\
	-Q --no-result                  no output of resulting code to screen, even absent <out file>\n\
\n\
	Producing Lexon Code\n\
	-2 --javascript                 produce javascript output\n\
	-3 --solidity                   produce solidity output\n\
	-4 --sophia                     produce sophia output\n\
	-v --verbose                    trace detailed compilation steps to find code errors\n\
	-N --names                      list found names - ie. symbols - and exit\n\
	-W --echo-precompile            show sanitized source code first, with included files\n\
	-P --precompile                 show sanitized source code, with included files, then exit\n\
	-J --jurisdictions              list known jurisdictions and exit\n\
	-b --bare                       generated code is barebones happy path demonstration\n\
	-y --comment                    generated code has explanatory comments\n\
	-u --instructions               generated code leads in with user instructions\n\
	-z --harden                     generated code checks for unset arguments and variables\n\
	-f --feedback                   javascript: generated code confirms calls on-screen\n\
	-l --log [<file>]               javascript: generated code logs state changes to <file> (default: log)\n\
	-s --signatures [<pem file>]    javascript: generated code signs log using <pem file> (default: key.pem)\n\
	-c --chaining [<hash length>]   javascript: generated code hash-chains log-entries (default length 12)\n\
	-p --persistence [<file>]       javascript: generated code stores state in <file> (default: state)\n\
	-t --bundle [<file>]            javascript: generated code can tar code, log and state (default: contract.tgz)\n\
	-x --all-auxiliaries            generated code features all applicable extras (-y -u -z -f -l -s -c -p -t)\n\
	-i --include-path <path>        set a default path to look for include files\n\
 	-I --included-files             print cascade of included and sub-included files and exit\n\
	-R --ignore-repeat-includes     ignore include files that are given repeatedly\n\
	-C --ignore-circular-includes   ignore include files that effectively call themselves\n\
\n\
	Inspecting Lexon Code\n\
	-G --grammar                    list the implemented grammar (LGF), and exit\n\
	-1 --core                       produce lexon core code output\n\
	-0 --tree                       produce abstract syntax tree output\n\
	   --flat                       produce a tree with flattened binary lists\n\
	   --color [<sgr,sgr..>]        ansi sgr codes for highlighting (default: 1), adds following four\n\
	   --symbols [<sgr,sgr..>]      highlight the symbols in tree, core, or output code (default: 36)\n\
	   --highlight [<word,word..>]  highlight specific nodes (default: clause,subject,object,if)\n\
	   --leaves [<word,word..>]     highlight specific node leaves (default: type,combinator,illocutor)\n\
	   --subleaves [<word,word..>]  highlight specific node sub leaves (default: predicate)\n\
\n" /*
	Interfacing\n\
 	-U --ui-info                    print json object of insights about the source code, and exit\n\
\n\ */ "\
	Developing Lexon Grammars\n\
	-S --scanner [<out file>]       produce scanner code from an LGF grammar\n\
	-F --source base [<file name>]  source file to be included into scanner code (-S)\n\
	-H --header [<file name>]       prepend #include \"<file name>\" to scanner code (-S)\n\
	-Y --parser [<out file>]        produce parser code, incl. BNF, from an LGF grammar\n\
	-K --keywords                   list the keywords produced from an LGF grammar, and exit\n\
	-B --bnf                        produce BNF from an LGF grammar (subset of -Y), and exit\n\
	-y --comment                    include comments in grammar output (-S, -Y)\n\
	-k --check                      check consistency and completeness of LGF grammar (equals -QE)\n\
	-E --examples [<path stub>]     produce examples from <path stub>-nn.lex for an LGF grammar\n\
	-n --max-examples [<cap>]       produce ca. <cap> number of examples (default: 1000)\n\
	-w --wipe                       delete pre-existing example files <path stub>-*.lex for -E\n\
\n\
	Developing Lexon Targets\n\
	-T --template [<out file>]      produce skeleton AST walk functions for an LGF grammar\n\
	-L --language-prefix [<prefix>] prepend <prefix> to the functions of -T (default: 'core')\n\
\n\
	Debugging Lexon\n\
	-d --debug                      detailed trace of processing steps to debug lexon itself\n\
	-D --debug-modules [<modules>]  detailed trace of specific modules. Use -Dh to list modules\n\
	-M --memory-check               run-time check and post-mortem of memory allocation and errors\n\
	$ make check                    run test source files from tests/\n\
	$ make recheck                  run tests from tests/ again but skip those that worked\n\
	$ make update                   run tests again but interactively inspect & update expectations\n\
\n\
	Examples\n\
	lexon sample.lex\n\
	lexon --javascript sample.lex\n\
	lexon -vQ sample.lex\n\
	lexon -P sample.lex\n\
	lexon --flat --color --tree sample.lex\n\
	lexon -B english.lgf\n\
	lexon -Yparser.y -Hparser.h -Sscanner.l -Flexon.l -Lcore english.lgf\n\
\n\
	Version\n\
	" slug "\n\n");
	exit(0);
}

void syntax(char *message, char *violation) {

	if(violation){
		fprintf(stderr, "%s%s<<<\n\n", src, violation);
		fprintf(stderr, "Lexon: syntax error at line %d: %s. Can't process '%s'", line, message, violation);
		if(strlen(violation) == 1) fprintf(stderr, " (ascii %x %u)",
			 *(unsigned char *)violation, *(unsigned char *)violation);
		fprintf(stderr, ".\n");
	} else {
		// fprintf(stderr, "%s<<<\n\n", src); // ◊ make more error context optional
		fprintf(stderr, "Lexon: syntax error at line %d: %s.\n", line, message);
	}
	fprintf(stderr, ">> %s\n", context); // ◊ make more error context optional
	exit(1); // |1| because tests atm want expected fails to return 1. Fits as weakest, controlled error exit.
}

void yacc_printf(FILE *stream, char *format, ...) {
	static bool had = true;
	va_list args;
	va_start(args, format);
	if(had) fprintf(stream, "parser : ");
	vfprintf(stream, format, args);
	va_end(args);
	had = !!strchr(format, '\n');
}

void precompile() {

	if(opt_verbose || opt_debug) fprintf(stderr, "• precompilation\n"); // not quite, the start of PRE is the real start of precompilation

	/* protect pre-existing « » ◊ cover */
	replace(&buf, "«", "\\«");
	replace(&buf, "»", "\\»");

	/* unicode chars are not processed correctly by Flex, it takes the bytes
	   apert, specifically the negative calls notquote can't work */

	/* list presorted for length, descending two steps: replace by tag [n] first */
	node *cur = symbols;
	char tag[40]; // safeguard ◊
	int i = 0;
	while(cur) {
		snprintf(tag, 40, "«[%d]»", ++i);
		replace_whole_words(&buf, cur->find, tag, "‹", "›");
		cur->tag = mtrac_strdup(tag);
		cur = cur->prev;
	}
	cur = symbols;
	while(cur) {
		replace(&buf, cur->tag, cur->repl);
		mtrac_free(cur->tag);
		cur = cur->prev;
	}

	margin();

	if(opt_names || opt_debug)
		dump_name_list();

	if(opt_precompile || opt_pre_echo || opt_debug)
		printf("\nprecompilation:\n---------------\n%s\n", buf);

	if(opt_precompile)
		 clean_exit();

	if(opt_debug)
		 fprintf(stderr, "  precompilation done\n");
}

// write file name and line number into buffer
void lineno() {
	if(_lastline != line || _lastfile != file_namepart) { // sic
		concat(&buf, file_clearname, " ", str(line), ":   ");
		_lastfile = file_namepart;
		_lastline = line;
	}
}

void geninfo() {
	char* buf = mtrac_strdup("{ \"names\" = [\n");
	// use .serial to go by original order of appearance
	int i;
	for(i = 1; i <= name_count; i++) {
		node *cur = symbols;
		assert(i<=name_count);
		while(cur->serial != i)
			cur = cur->prev;
		concat(&buf, i>1?",\n":"", "\t\"", cur->find, "\"");
	}
	concat(&buf, "\n]}");
	puts(buf);
	mtrac_free(buf);
}

void dump_name_list() {
	int i;
	for(i = 1; i <= name_count; i++) {
		node *cur = symbols;
		assert(i<=name_count);
		while(cur->serial != i)
			cur = cur->prev;
		printf("%d\t%s\n", cur->serial, cur->find);
	}
}

int yywrap(void) {
	return 1;
}

char *coredup(char *src) {
	char *s = mtrac_strdup(src+1);
	*(s+strlen(s)-1) = 0;
	return s;
}

char *cutbuf(char *src, char *cut) {
	char *b = src+strlen(cut);
	while(*b==' '||*b=='\t') b++;
	b = mtrac_strdup(b);
	char *e = b + strlen(b) -1;
	while(*e=='.'||*e==' '||*e=='\t') *e-- = 0;
	return b;
}

char _str[40];
const char *str(int line) {
	sprintf(_str, "%d", line);
	return _str;
}

char _lit[1001];
const char *literal_symbol(char *token) {
	strncpy(_lit, token, 1000);
	char *c = _lit;
	while(*c) {
		while(*c == '"') { char *p=c; do *p = *(p+1); while(*++p); }
		if(*c) *c = toupper(*c);
		c++;
	}
	if(!strcmp(_lit, "FILE")) strcat(_lit, "_");
	return _lit;
}

char _up[1001];
char *UP(const char *token) {
	strncpy(_up, token, 1000);
	_up[1000] = 0;
	char *c = _up;
	bool sep = true;
	while(*c) { if(sep) *c = toupper(*c); else *c = tolower(*c); sep = *c == '_'; c++; }
	return _up;
}

char *up(char *s) {
	char *c = s;
	bool sep = true;
	while(*c) { if(sep) *c = toupper(*c); sep = *c == '_'; c++; }
	return s;
}

char _low[1001];
char *LOW(const char *token) {
	strncpy(_low, token, 1000);
	char *c = _low -1;
	while(*++c) *c = tolower(*c);
	return _low;
}

char *lowdup(const char *s) {
	char *buf = mtrac_strdup(s);
	char *c = buf -1;
	while(*++c) *c = tolower(*c);
	return buf;
}

char _snake[1001];
char *SNAKE(const char *token) {
	strncpy(_snake, token, 1000);
	char *c = _snake -1;
	while(*++c) if(*c == ' ' || *c == '-') *c = '_'; else *c = tolower(*c);
	return _snake;
}

char *snakedup(const char *s) {
	char *dup = mtrac_strdup(s);
	char *c = dup -1;
	while(*++c) if(*c == ' ' || *c == '-') *c = '_'; else *c = tolower(*c);
	return dup;
}

char _dsp[1001];
char *dash_spaced(const char *token) {
	assert(token);
	strncpy(_dsp, token, 1000);
	char *p = _dsp -1;
	while(*++p) if(*p == ' ' || *p == '_') *p = '-';
	return _dsp;
}

char _ssp[1001];
char *snake_spaced(const char *token) {
	//assert(token); ◊
	if(!token) token = "[undefined]";
	strncpy(_ssp, token, 1000);
	char *p = _ssp -1;
	while(*++p) if(*p == ' ' || *p == '-') *p = '_';
	return _ssp;
}

char _csp[1001];
char *camel_spaced(const char *token) {
	assert(token);
	strncpy(_csp, token, 1000);
	char *p = _csp -1;
	bool gap = false;
	while(*++p) { if(gap) *p = toupper(*p); gap = *p == ' ' || *p == '-' || *p == '_'; }
	contract(_csp);
	return _csp;
}

void rump(char **buf, char *filename) {
	char *copy = mtrac_strdup(filename); // as per namepart doc
	if(*buf) mtrac_free(*buf);
	*buf = mtrac_strdup(basename(copy)); // don't free file bec (**)
	mtrac_free(copy);
	replace(buf, ".lex", "");
	replace(buf, "-", " ");
}

static bool in(char *hay, char *needle) { // ◊ unify w/target.c
        char *tagged = mtrac_strdup("");
        mtrac_concat(&tagged, ":", needle, ":");
        bool in = !!strstr(hay, tagged);
        mtrac_free(tagged);
        return in;
}

void include(char *scanned) {
	int i;
	char *tmp;

	/* The parsed term may be a full path, a base name or a pretty-written name */
	char *clearname, *namepart, *pathpart, *location, *fullpath;
	FILE *fileptr;

	/* pretty representation */
 	clearname = null;
	rump(&clearname, scanned);

	/* fully qualified path, poss. prefix command line parameter */
	fullpath = mtrac_strdup(scanned);
	replace(&fullpath, " ", "-");
	if(!strstr(fullpath, ".lex")) concat(&fullpath, ".lex"); // ..
	if(!strchr(fullpath, '/')) precat(&fullpath, opt_include_path);

	/* resulting directory path */
	tmp = mtrac_strdup(fullpath);
	pathpart = mtrac_strdup(dirname(tmp));
	mtrac_free(tmp);

	/* resulting file namepart */
	tmp = mtrac_strdup(fullpath);
	namepart = mtrac_strdup(basename(tmp));
	mtrac_free(tmp);

	/* trace */
	if(opt_included_files || opt_verbose || opt_debug) {
		printf("%s %d ⟼   %s\n", file_clearname, line, clearname);
		printf("Code file %s/%s on line %d includes file %s/%s from directory %s.\nThe default include path is (-I) %s.\n",
			file_pathpart, file_namepart, line, pathpart, namepart, file_location, opt_include_path);
	}

	/* prevent includes from nesting too deeply */
	if(include_stack_ptr >= MAX_INCLUDE_DEPTH) {
		fprintf(stderr, "fatal: includes nested too deeply (limit: %d)\n", MAX_INCLUDE_DEPTH);
		dump_include_stack(clearname);
		exit(1); // see |1|: atm required by tests: planned fail error code 1
	}

	/* Includes should not be circular, i.e. not file1 -> file2 -> file1 */
	if(!opt_ignore_circular_includes)
		for(i = 0; i < include_stack_ptr; i++)
			if(!strcmp(include_stack[i].namepart, namepart)) {
				fprintf(stderr, "fatal: circular include\n");
				dump_include_stack(clearname);
				exit(1); // see |1|
			}

	/* includes should also not be included twice, i.e. not file1 -> file2, file2 */
	if(!opt_ignore_repeat_includes) {
		include_trace *t = include_trace_start;
		if(t && !strcmp(t->from_namepart, namepart)) {
			fprintf(stderr, "fatal: include of main file\n");
			dump_include_trace(clearname);
			exit(1); // see |1|
		}
		while(t) {
			if(!strcmp(t->include_namepart, namepart)) {
				fprintf(stderr, "fatal: repeat include\n");
				dump_include_trace(clearname);
				exit(1); // see |1|
			}
			t = t->next;
		}
	}

	/* switch to directory of the file to be included */
	if(chdir(pathpart) != 0) {
		fprintf(stderr, "Failed to change into the directory '%s' of the include file '%s'. Code %s\n", pathpart, namepart, yytext);
		perror(pathpart);
		exit(26);
	}

	/* record absolute path of directory */
	location = getcwd(null, 0);
	if(location == NULL) { //..
		perror("could not read include file directory name");
		exit(27);
	}
	location = mtrac_strdup(getcwd(null, 0));

	/* open the include file, from its home directory */
	if(!(fileptr = fopen(namepart, "r"))) {
		fprintf(stderr, "Failed to open include file '%s' expected in directory '%s'.\n", namepart, pathpart);
		fprintf(stderr, "Included from file '%s/%s', line %d, as '%s'.\n", file_pathpart, file_namepart, line, yytext);
		fprintf(stderr, "The include file path prefix set via command line is: '%s'.\n", opt_include_path);
		fprintf(stderr, "Code: %s\n", yytext);
		perror(namepart);
		exit(1);
	}

	/* keep track of include files ever used */
	include_trace *trace = mtrac_malloc(sizeof(include_trace));
	trace->from_namepart = mtrac_strdup(file_namepart);          // never free'd
	trace->from_clearname = mtrac_strdup(file_clearname);        // ditto
	trace->from_line = line;
	trace->include_namepart = mtrac_strdup(namepart);            // ditto
	trace->include_clearname = mtrac_strdup(clearname);          // ditto
	include_count++;
	trace->next = null;
	if(!include_trace_start) include_trace_start = trace;
	if(include_trace_last) include_trace_last->next = trace;
	include_trace_last = trace;

	/* keep track of include files nesting depth */
	include_stack[include_stack_ptr].buffer = YY_CURRENT_BUFFER; // gift
	include_stack[include_stack_ptr].clearname = file_clearname; // gift
	include_stack[include_stack_ptr].namepart = file_namepart;   // gift
	include_stack[include_stack_ptr].pathpart = file_pathpart;   // gift
	include_stack[include_stack_ptr].location = file_location;   // gift
	include_stack[include_stack_ptr].fileptr = file_fileptr;     // gift
	include_stack[include_stack_ptr].line = line;
	include_stack_ptr++;

	/* For clarity only, these mtrac_mallocs are all in the responsibility of the include_stack now: */
	file_clearname = null;
	file_namepart = null;
	file_pathpart = null;
	file_location = null;
	file_fileptr = null;

	/* now the switch-over starts, regarding Lex and the file_* variables. */
	file_clearname = clearname;
	file_namepart = namepart;
	file_pathpart = pathpart;
	file_location = location;
	file_fileptr = fileptr;
	line = 1;

	/* Finally, make it Lex' scan source.
	   Note that the FILE pointer in the call to yy_create_buffer is only used as the value of yyin seen by YY_INPUT */
	yy_switch_to_buffer(yy_create_buffer(file_fileptr, YY_BUF_SIZE));

	/* set scan mode to normal pre-processing to start the file scan */
	BEGIN(PRE);

	/* 4 mtrac_mallocs and 2 file buffers have been gifted to the include_stack,
	  they, yyin and the new YY_CURRENT_BUFFER are freed when twice popped at (****) */
	mtrac_free(fullpath);
}

int include_done() {
	if (--include_stack_ptr < 0)
		return 0;

	if(opt_debug) fprintf (stderr, "include complete: %s\n", file_namepart);

	/* note (****) this deletes the CURRENT values and starts to use those from stack */
	mtrac_free(file_clearname);
	mtrac_free(file_pathpart);
	mtrac_free(file_namepart);
	mtrac_free(file_location);
	fclose(file_fileptr); //.. is this duplicating yy_delete_buffer's action?
	yy_delete_buffer(YY_CURRENT_BUFFER);

	/* switch over */
	file_clearname = include_stack[include_stack_ptr].clearname;
	file_pathpart = include_stack[include_stack_ptr].pathpart;
	file_namepart = include_stack[include_stack_ptr].namepart;
	file_location = include_stack[include_stack_ptr].location;
	file_fileptr = include_stack[include_stack_ptr].fileptr;
	line = include_stack[include_stack_ptr].line;
	line++; // the \n was consumed with the path but progress only now.

	// ◊ is a call to chdir(file_location) missing ?

	yy_switch_to_buffer(include_stack[include_stack_ptr].buffer);

	return 1;
}

void dump_include_stack(char *include_clearname) {
	int i;
	for(i = 0; i < include_stack_ptr; i++)
		fprintf(stderr, "%s line %d ⟶  \n", include_stack[i].clearname, include_stack[i].line);
	printf("%s again - fails\n", include_clearname);
}

void dump_include_trace(char *include_clearname) {
	include_trace *t = include_trace_start;
	while(t) {
		fprintf(stderr, "%s line %d ⟼   %s\n", t->from_clearname, t->from_line, t->include_clearname);
		t = t->next;
	}
	fprintf(stderr, "%s line %d ⟼   %s again - fails\n", file_clearname, line, include_clearname);
}

void delete_include_trace() {
	include_trace *it0, *it = include_trace_start;
	while((it0 = it)) {
		mtrac_free(it->from_namepart);
		mtrac_free(it->from_clearname);
		mtrac_free(it->include_namepart);
		mtrac_free(it->include_clearname);
		mtrac_free(it);
		it = it0->next;
		if(it0 == include_trace_last) { assert(!it); }
	}
}

/* add a symbol (name) to the symbols list, scanned directly from the code buffer */
void process(char *ltrim, char *skip1, char *mtrim, char *skip2, char *ctrim, char *pif, char *rtrim) {
	pif += strspn(pif, ltrim);
	if(tolower(*pif) == tolower(*skip1)) pif += strlen(skip1);
	pif += strspn(pif, mtrim);
	if(tolower(*pif) == tolower(*skip2)) pif += strlen(skip2);
	pif += strspn(pif, ctrim);
	pif = mtrac_strdup(pif);
	char *e = pif + strlen(pif);
	while(strchr(rtrim, *--e)) ; *++e = 0;

	int l = strlen(pif);
	char *c = mtrac_malloc(l+1+strlen("«")+strlen("»"));
	strcpy(c, "«");
	strcpy(c+strlen("«"), pif);
	strcpy(c+l+strlen("«"), "»");
	if(opt_debug) printf("found name %s\n", c);

	node *ins = symbols;
	node *next = null;
	while(ins && ins->find_len > l) {
		next = ins; ins = ins->prev;
	}
	node *n = mtrac_malloc(sizeof(node));
	n->serial = ++name_count;
	n->find = pif;
	n->find_len = strlen(pif);
	n->repl = c;
	n->prev = ins;
	if(next) { assert(next->prev==ins); next->prev = n; }
	else symbols = n;
}

/* add a symbol (name) to the symbols list, scanned directly from the code buffer */
void process2(char *pif, char *rtrim, char *open, char *close) {
	pif = mtrac_strdup(pif);
	char *e = pif + strlen(pif);
	while(strchr(rtrim, *--e)) ; *++e = 0;

	int l = strlen(pif);
	char *c = mtrac_malloc(l+1+strlen(open)+strlen(close));
	strcpy(c, open);
	strcpy(c+strlen(open), pif);
	strcpy(c+l+strlen(open), close);
	if(opt_debug) printf("found name %s\n", c);

	node *ins = symbols;
	node *next = null;
	while(ins && ins->find_len > l) {
		next = ins; ins = ins->prev;
	}
	node *n = mtrac_malloc(sizeof(node));
	n->serial = ++name_count;
	n->find = pif;
	n->find_len = strlen(pif);
	n->repl = c;
	n->prev = ins;
	if(next) { assert(next->prev==ins); next->prev = n; }
	else symbols = n;
}

// frees input and replaces with result.
unsigned int grid = 0; // optics: bitpattern of vertical tree branch lines, across rows\n\n";
unsigned int last_indent = 0; // for auto spacing between sub branches: extra line whenever indentation doesn't grow vs last line.
void gridrow(char *t, int right) { unsigned int mask = (1<<right); while(right > 0) { strcat(t, (mask&grid)?"⎸   ":"    "); right--; mask>>=1; } }
char **_concat(char *varname, char *file, int line, int down, int right, char **buf, ...) {
	if(right < 0) right = 0;
	int org_down  = down ;
	int org_right = right;
	va_list ap;
	va_start(ap, buf);
	char *add = va_arg(ap, char *);
	while(add) {
		char *t = _mtrac_malloc(strlen(*buf) + down + (down+1) * 10 * right + 1 + strlen(add) + 1, varname, file, line);
		if(!t) { fprintf(stderr, "out of memory %s %d", __FILE__, __LINE__); exit(137); } // doubles mtrac_malloc catch.
		strcpy(t, *buf);
		while(down > 0) { strcat(t, "\n"); down--; if(grid||!down) gridrow(t, right); }
		if(grid && right && right <= last_indent) { strcat(t, "⎸ \n"); gridrow(t, right); }
		right = 0;
		strcat(t, add);
		mtrac_free(*buf);
		*buf = t;
		add = va_arg(ap, char *);
	}
	va_end(ap);
	if(org_right && org_down) last_indent = org_right;

	/* module debug mode: insert line# tags after each snippet */
	if(_concat_trace)
		_concatnum(buf, " ", line, " ");

	return buf;
}

char **_concatnum(char **buf, char *prefix, int number, char *postfix) {

	char *t = _mtrac_malloc(strlen(*buf) + (prefix?strlen(prefix):0) + (postfix?strlen(postfix):0) + 1000, "t", __FILE__, __LINE__);
	if(!t) { fprintf(stderr, "out of memory %s %d", __FILE__, __LINE__); exit(137); } // doubles mtrac_malloc catch.
	strcpy(t, *buf);
	sprintf(t + strlen(*buf), "%s%d%s", prefix, number, postfix);
	mtrac_free(*buf);
	*buf = t;

	return buf;
}



// frees input and replaces with result.
void _precat(char **buf, ...) {
	va_list ap;
	va_start(ap, buf);
	char *add = va_arg(ap, char *);
	while(add) {
		char *t = mtrac_malloc(strlen(*buf) + strlen(add) + 1);
		strcpy(t, add);
		strcat(t, *buf);
		mtrac_free(*buf);
		*buf = t;
		add = va_arg(ap, char *);
	}
	va_end(ap);
}

char *catdup(char *string, char *append, int(*func)(int))  {
	char *buf = mtrac_malloc(strlen(string) + strlen(append) + 1);
	strcpy(buf, string);
	strcat(buf, append);
	char *c = buf -1; while(*++c) *c = (*func)(*c);
	return buf;
}

// Frees input and replaces with result. Result must later be freed.
// courtesy J Mucchiello https://stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c#
int _replace(char **orig, const char *rep, const char *with, int all, char *from,
	bool whole, char *quote, char *unquote, char *origname, char *file, int line) {
	char *result;
	char *start;
	char *ins; // next insert point
	char *tmp;
	int len_orig;
	int len_rep;
	int len_with;
	int len_front; // distance between rep and end of last rep
	int counter; // number of replacements
	int count; // number of replacements

	assert(!(!orig || !*orig || !rep));
	if (!orig || !*orig || !rep)
		return -1;

	start = ins = from ? from : *orig;
	len_orig = strlen(*orig);
	len_rep = strlen(rep);
	if (len_rep == 0 || len_orig == 0 || !*start || !with)
		return 0;
	len_with = strlen(with);

	/* count the number of replacements. Wastes space if 'whole' fails. */
	for (count = 0; (tmp = strstr(ins, rep)); ) {
		ins = tmp + len_rep;
		count++;
		if(!all) break;
	}

	if(!count)
		return 0;

	size_t msz = len_orig + (len_with - len_rep) * count + 1;
	if(whole && len_orig + 1 > msz) msz = len_orig + 1; // wasteful but avoids prechecking whole-wordiness when 'count' is made

	tmp = result = _mtrac_malloc(msz, origname, file, line);

	if (!result) {
		fprintf(stderr, "internal error in string replace for %s %s %d", origname, file, line);
		exit(30);
	}

	if(from && from != *orig) {
		tmp = strncpy(tmp, *orig, from - *orig) + (from - *orig);
	}

	// first time through the loop, all the variable are set correctly
	// from here on,
	//    tmp points to the end of the result string
	//    ins points to the next occurrence of rep in orig
	//    start points to the remainder of orig after "end of rep"
	counter = count;
	bool inquote = false;
	while (counter--) {
		ins = strstr(start, rep);
		if(quote && unquote) {
			char *but, *tub = start;
			do {
				but = strstr(tub, quote);
				tub = but ? strstr(but, unquote) : null;
			} while(tub && tub < ins) ;
			inquote = but && tub && but < ins && tub > ins;
		}
		// printf("> > > %s 	%d %p %p %p\n", with, inquote, but, ins, tub); ◊ make option
		len_front = ins - start;
		tmp = strncpy(tmp, start, len_front) + len_front;
		const char *border = " \t\r\n\".,;:?!()[]{}&%$#@~+/\\“”";
		const char *border_special = " \t\r\n\".,;:?!()[]{}&%$#@~+/\\“”";
		if(!inquote && (!whole || ((ins == *orig || strchr(border, *(ins-1))) && (!*(ins+len_rep) || strchr(border, *(ins+len_rep))))))
			tmp = strcpy(tmp, with) + len_with;
		else
			tmp = strcpy(tmp, rep) + len_rep;
		start += len_front + len_rep; // move to next "end of rep" (sic rep: start is on the OLD memory)
	}
	strcpy(tmp, start);

	mtrac_free(*orig);
	*orig = result;
	return count;
}

/* takes away whitespace and colon. Shuffles within buffer, doesn't reallocate */
char *trim(char *s) {
	assert(s);
	if(*s) {
		char *p = s + strlen(s) -1;
		while(*p == ' ' || *p == '\t' || *p == '\n' || *p == ':') p--;
		*(p+1) = 0;
		p = s;
		while(*p == ' ' || *p == '\t' || *p == '\n' || *p == ':') p++;
		if(p != s)
			memmove(s, p, strlen(p)+1);
	}

	//char *c = s-1;
	//while(*++c) *c = tolower(*c);
	return s;
}

char *contract(char *s) {
	assert(s);
	char *q = s, *p = s - 1;
	while(*++p) if(*p != ' ' && *p != '-' && *p != '_') *q++ = *p;
	*q = 0;
	return s;
}

/* takes out spaces between letters. Spaced letters are allowed for emphasis in LGF definition names. */
char *unspace(char *s) {
	assert(s);
	char *q = s, *p = s - 1;
	while(*++p) if(*p != ' ') *q++ = *p;
	*q = 0;
	return s;
}

/* takes away whitespace, colon and quote. Uses static buffer, doesn't touch input */
char _qtr[1001];
char *quote_trimmed(const char *token) {
	assert(token);
	strncpy(_qtr, token, 1000);
	char *p, *s = _qtr;
	if(*s) {
		p = s + strlen(s) -1;
		while(*p == ' ' || *p == '\t' || *p == '\n' || *p == ':' || *p == '\"'
			 || (p[0] == "”"[0] && p[1] == "”"[1]) || (p[0] == "”"[0] && p[1] == "”"[1])) p--;
		*(p+1) = 0;
		p = s;
		while(*p == ' ' || *p == '\t' || *p == '\n' || *p == ':' || *p == '\"'
			 || (p[0] == "”"[0] && p[1] == "”"[1]) || (p[0] == "”"[0] && p[1] == "”"[1])) p++;
	}

	return p;
}

char **pad(char **s, int to) {
	assert(s);
	int l = strlen(*s);
	int d = to - l;
	if(d < 1) return s;
	//*s = realloc(*s, to + 1);
	char *ss = (char *)mtrac_malloc(to + 1);
	strcpy(ss, *s);
	mtrac_free(*s);
	*s = ss;
	memset(ss+l, ' ', d);
	ss[to] = 0;
	return s;
}

char *xcr(char *s) {
	if(_xcr) mtrac_free(_xcr);
	_xcr = mtrac_strdup(s);
	char *c = _xcr - 1;
	while(*++c) if(*c == '\n') *c = '@';
	return _xcr;
}

int chrcnt(char *hay, char needle) {
	int cnt = 0;
	while(*hay) if(*hay++ == needle) cnt++;
	return cnt;
}

// get all colons after line numbers into same column
void margin() {
	if(opt_debug) fprintf(stderr, "adding margins\n");
	char *p0, *p = buf;
	size_t max = 0;
	while(*p) {
		size_t margin = strcspn(p, ":\n");
		if(*(p+margin)=='\n') margin = 0;
		else if(margin > 0 && !strchr("0123456789", *(p+margin-1))) margin = 0;
		if(margin > max) max = margin;
		if(!(p = strchr(p,'\n'))) break;
		p++;
	}
	max++;
	char space[max+1];
	memset(&space, ' ', max);
	*(space + max) = 0;
	p = p0 = buf;
	while(*p) {
		size_t margin = strcspn(p, ":\n");
		if(margin && *(p + margin) == ':' && margin < max) {
			p += margin;
			///while(*--p != ' ')
			///	if(p < p0) {
			///		/* would break the line counter: a line did not, as all should, start '.* .*:' */
			///		fprintf(stderr, "margin scan buffer:\n%s\n\n", buf);
			///		fprintf(stderr, "parser error at: '%.*s' ...\n", 25, p0); // ◊ make canonical error message
			///		exit(31);
			///	}
			while(*--p != ' ' && p > p0) ;
			if(p > p0) {
				size_t pos = p - buf;
				replace_first_from(&buf, " ", space + margin -1, p);
				p = buf + pos;
			}
		}
		if(!(p = strchr(p,'\n'))) break;
		p0 = ++p;
	}
}

void freeline() {
	if(strlen(buf) > 1 && strcmp(buf + strlen(buf) -2, "\n\n"))
		concat(&buf, "\n");
	if(strcmp(buf + strlen(buf) -2, "\n\n"))
		concat(&buf, "\n");
}

void emulaws() {
	law *l = mtrac_malloc(sizeof(law));
	l->abbr = "BER";
	l->name = "Berlin";
	l->under = "GER";
	l->ext = "ber";
	l->prev = null;
	laws_last = l;

	l = mtrac_malloc(sizeof(law));
	l->abbr = "NY";
	l->name = "New York";
	l->under = "USA";
	l->ext = "ny";
	l->prev = laws_last;
	laws_last = l;
}

void delete_laws() {
	while(laws_last) {
		law *l = laws_last->prev;
		mtrac_free(laws_last);
		laws_last = l;
	}
}

void dump_laws() {
	printf("Known jurisdictions:\n");
	law *l = laws_last;
	while(l) {
		printf("%s (%s) under %s, file extension: .%s.\n", l->name, l->abbr, l->under, l->ext);
		l = l->prev;
	}
}

void setlaw(char *scan) {
	if(opt_debug) printf("jurisdiction given as %s\n", scan);
	law_abbr = mtrac_strdup(scan);
	law_name = mtrac_strdup(scan);
	law_ext = mtrac_strdup(scan);
	char *c = law_ext -1; while(*++c) *c = tolower(*c);
	precat(&law_ext, ".");
	concat(&law_ext, ".");
	if(opt_verbose || opt_debug) printf("Jurisdiction set to %s\n", scan);
}

 /* LGF/LXF grammar processing */

void start_definition(char *scan) {
	assert(definition);
	//..//assert(!rule);
	//..//assert(!alternation);
	//..//assert(!alternate);
	//..//assert(!word);

	if(*definition) definition = &(*definition)->next;
	*definition = mtrac_malloc(sizeof(struct definition));
	(*definition)->name = up(trim(mtrac_strdup(scan)));
	(*definition)->important = !!strchr((*definition)->name, ' ');
	(*definition)->name = unspace((*definition)->name);
	(*definition)->rules = null;
	(*definition)->alternations = null;
	(*definition)->subrules = null;
	(*definition)->tokens = null;
	(*definition)->types = null;
	(*definition)->source = mtrac_strdup(""); // S macro follows after call of this func
	(*definition)->line = line;
	(*definition)->results = null;
	(*definition)->simple = true;
	(*definition)->next = null;

	rule = &(*definition)->rules;
	alternation = &(*definition)->alternations;
	alternate = null;
	word = null;
}

void start_rule(mode mode, kind kind) {
	assert(definition);
	assert(rule);

	if(opt_debug_generator) fprintf(stderr, "gentor.: start rule/subrule - %d %d\n", mode, kind);
	if(*rule) rule = &(*rule)->next;
	*rule = mtrac_malloc(sizeof(struct rule));
	(*rule)->mode = mode;
	(*rule)->kind = kind;
	(*rule)->words = null;
	(*rule)->keywords = null;
	(*rule)->tokens = null;
	(*rule)->next = null;

	word = &(*rule)->words;
	keyword = &(*rule)->keywords;
}

void add_keyword(char *scan) {
	assert(keyword);
	assert(!!scan);

	if(opt_debug_generator) fprintf(stderr, "gentor.: add keyword - %s \n", scan);
	if(*keyword) keyword = &(*keyword)->next;
	*keyword = mtrac_malloc(sizeof(struct word));
	(*keyword)->string = scan ? trim(mtrac_strdup(scan)) : null;
	(*keyword)->next = null;

	add_word(scan);
}

void _add_word(char *scan, bool option_start, bool option_end, adjacency space) {
	assert(word);
	assert(!!scan + option_start + option_end == 1);

	if(opt_debug_generator) fprintf(stderr, "gentor.: add word - %s \n", scan);
	if(*word) word = &(*word)->next;
	*word = mtrac_malloc(sizeof(struct word));
	(*word)->string = scan ? trim(mtrac_strdup(scan)) : null;
	(*word)->option_start = option_start;
	(*word)->option_end = option_end;
	(*word)->adjacency = space;
	(*word)->next = null;
}

void add_word(char *string) {
	assert(string && *string);
	_add_word(string, false, false, not_applicable);
}

bool _add_token(stringlist **tokens, const char *string, stringlist *only, stringlist *ignores, ordering keep_order, char *var, char *file, int line) {
	assert(string && *string);
	if(opt_debug_lists) fprintf(stderr, "lists  : maybe add token '%s'\n", string);

	/* check list of strings to be ignored (i.e. not added) */
	if(only) {
		do if(!strcmp(only->string, string)) goto pass; while((only = only->next));
		return false;
	}
	pass:

	/* check list of strings to be ignored (i.e. not added) */
	while(ignores) {
		if(!strcmp(ignores->string, string)) return false;
		ignores = ignores->next;
	}

	/* search if it is already listed, and for its right place */
	stringlist *next = *tokens, **prev = tokens;
	int order = 1;
	while(next && (keep_order || (order = strcmp(string, next->string)) > 0)) {
		if(opt_debug_lists) fprintf(stderr, "lists  : next: '%s'\n", next->string);
		prev = &next->next; next = next->next;
	}
	/* if not in the token list, add the new token */
	bool added = false;
	if(order != 0) {
		if(opt_debug_lists) fprintf(stderr, "lists  : now adding '%s' (next: %p, current prev: %p)\n", string, next, *prev);
		stringlist *n = _mtrac_malloc(sizeof(stringlist), var, file, line);
		n->string = _mtrac_strdup(string, var, file, line); // many lists and their strings are note free'd
		n->next = next;
		*prev = n;
		added = true;
	}

	stringlist *t = *tokens;
	while(t) {
		if(opt_debug_lists) fprintf(stderr, "lists  : %p ⟶  '%s'\n", t, t->string);
		t = t->next;
	}
	/* note that there is no need to point into the list. Flex uses the string itself */
	return added;
}

bool in_list(stringlist *token, const char *string) {
	while(token) {
		if(!strcmp(token->string, string)) return true;
		token = token->next;
	}
	return false;
}

int count_in_list(stringlist *token, const char *string) {
	int cnt = 0;
	while(token) {
		if(!strcmp(token->string, string)) cnt++;
		token = token->next;
	}
	return cnt;
}

void delete_stringlist(stringlist *list) {

	stringlist *t;
	while(list) { if(list->string) mtrac_free(list->string); t = list; list = list->next; mtrac_free(t); }
}

void delete_map(map *_map) {

	map *m;
	while(_map) { // printf("deleting %s -> %s\n", _map->key, _map->value);
		 if(_map->key) mtrac_free(_map->key); if(_map->value) mtrac_free(_map->value); m = _map; _map = _map->next; mtrac_free(m); }
}

void delete_node_list(node *list) {

	node *n;
	while(list) {
		if(list->find) mtrac_free(list->find);
		if(list->repl) mtrac_free(list->repl);
		n = list; list = list->prev; mtrac_free(n);
	}
	list = null;
}

/* switch forward the map entry of the current clause to collect its literal text for comments */
void new_lexcom(const char *name, const char *value) {

	// cut leading 'clause: '
	assert(name);
	while(*name == ' ') name++;
	if(!strncmp(LOW(name), "clause", 6)) {
		name += 6;
		while(*name == ' ') name++;
		while(*name == ':') name++;
		while(*name == ' ') name++;
	} else if(!strncmp(LOW(name), "terms", 5)) {
		name += 5;
		while(*name == ' ') name++;
		if(!strncmp(LOW(name), "per", 3)) name += 3;
		while(*name == ' ') name++;
	}
	if(strchr(name, ':'))
		*strchr(name, ':') = 0;

	map *m = lexcoms;
	// prevent double use of clause or covenant name (◊ sort elsewhere)
	if(!opt_debug_allow_double_names) {
		while(m) {
			if(!strcmp(LOW(snake_spaced(name)), m->key)) {
				// except, allow multiple _pre_ entries
				// ◊ _pre_ entries, if any, are never used.
				if(strcmp(name, "_pre_")) {
					fprintf(stderr, "clause or covenant name used twice: %s", name);
					exit(1);
				}
			}
			m = m->next;
		}
	}

	// trim previous (sic) entry's value
	m = lexcoms;
	if(m && m->value && *m->value) {
		char *e = m->value + strlen(m->value) -1;
		while(e > m->value && (*e == ' ' || *e == '\t' || *e == '\n')) e--;
		if(e > m->value) *(e+1) = 0;
	}

	// add map entry
	m = _mtrac_malloc(sizeof(map), "lexcom node", __FILE__, __LINE__);
	m->key = mtrac_strdup(LOW(snake_spaced(name)));
	m->value = mtrac_strdup(value);
	m->next = lexcoms;
	lexcoms = m;
}

const char *get_lexcom(const char *name) {

	map *m = lexcoms;
	while(m) {
		if(!strcmp(LOW(snake_spaced(name)), m->key))
			return m->value;
		m = m->next;
	}
	return "";
}

void start_option(adjacency space) {
	_add_word(null, true, false, space);
}

void end_option(adjacency space) {
	_add_word(null, false, true, space);
}

void start_alternation(char *scan) {
	assert(scan && *scan);

	if(opt_debug_generator) fprintf(stderr, "gentor.: start alternation - '%s'\n", scan);
	if(*alternation) alternation = &(*alternation)->next;
	*alternation = mtrac_malloc(sizeof(struct alternation));
	(*alternation)->string = trim(mtrac_strdup(scan));
	if(opt_debug_generator) fprintf(stderr, "gentor.: alternation string - '%s'\n", (*alternation)->string);
	(*alternation)->alternates = null;
	(*alternation)->next = null;

	alternate = &(*alternation)->alternates;
}

void start_alternate() {
	assert(alternate);

	if(opt_debug_generator) fprintf(stderr, "gentor.: start atlernate ..\n");
	if(*alternate) alternate = &(*alternate)->next;
	*alternate = mtrac_malloc(sizeof(struct alternate));
	(*alternate)->words = null;
	(*alternate)->next = null;

	word = &(*alternate)->words;
}

void continue_rule() {
	word = &(*rule)->words;
	while(*word && (*word)->next) word = &(*word)->next;
}

void end_rule() {
}

void add_embed(char *s) {
	if(!embed) embed = mtrac_strdup(s);
	else concat(&embed, s);
}

/* build the resulting BNF, as string, from the LGF tree */
void produce_grammar(struct definition *definition) {

	if(!definition) return;
	assert(definition->rules);
	assert(!definition->results);

	/* head of main yacc feed file */
	char *requires =
		"#define CYCLE_2 true\n\n"
		"#include <stdio.h>\n"
		"#include <string.h>\n\n"
		"int yylex(void);\n"
		"void yyerror(const char *);\n\n"
		"void *mtrac_gross(void *);\n\n"
		"#define NEW(type, literal) \\\n"
		"	if(opt_debug_tokens) fprintf(stderr, \"tokens : creating node for \" #type \"'%s'\\n\", literal); \\\n"
		"	type *type = mtrac_malloc(sizeof(struct type)); \\\n"
		"	mtrac_gross(type); \\\n"
		"	memset(type, 0, sizeof(struct type)); \\\n"
		"	type->Literal = literal;\n"
		"#define mtrac_malloc(size_) _mtrac_malloc(size_, \"[unknown]\", __FILE__, __LINE__)\n"
		"#define mtrac_strdup(string_) _mtrac_strdup(string_, \"[unknown]\", __FILE__, __LINE__)\n"
		"#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)\n"
		"void *_mtrac_malloc(size_t size, char *name, char *file, int line);\n"
		"void *_mtrac_strdup(const char *string, char *name, char *file, int line);\n"
		"char *_mtrac_dupcat(const char *string, ...);\n"
		"void _mtrac_free(void *p, char *name, char *file, int line);\n"
		"#define YYFPRINTF yacc_printf\n"
		"typedef int bool;\n"
		"#define false 0\n"
		"#define true 1\n"
		"#define null (void *)0\n\n"
		"typedef char Literal;\n"
		"typedef char Name;\n"
		"typedef char Description;\n"
		"typedef char Scalar;\n\n"
		"typedef char Hex;\n\n"
		"#define padcat(down_, right_, var_, ...) \\\n"
		"	_concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)\n"
		"char **_concat(char *, char*, int, int, int, char **buf, ...);\n"
		"void yacc_printf(FILE *stream, char *format, ...);\n\n"
		"extern bool opt_produce_tree;\n"
		"extern bool opt_produce_flat;\n"
		"extern bool opt_produce_terse;\n"
		"extern bool opt_debug;\n"
		"extern bool opt_verbose;\n"
		"extern bool opt_debug_actions;\n\n"
		"extern bool opt_debug_tokens;\n\n"
		"extern char *opening_bracket;\n\n"
		"extern char *closing_bracket;\n\n"
		"extern bool bracket_just_closed; // optics: helps with line breaks in produced core code\n\n"
		"extern unsigned int grid; // optics: bitpattern of vertical tree branch lines, across rows\n\n";

	char *lex = mtrac_strdup(" /* Keywords (generated from LGF) */\n");
	char *prol = mtrac_strdup("/* - */");
	char *req = mtrac_strdup("%code requires {\n\n"); concat(&req, requires);
	char *enu = mtrac_strdup("typedef enum types {\n");
	char *uni = mtrac_strdup("typedef union node {\n"); // \tname *name;\n\tdescription *description;\n");
	char *stru = mtrac_strdup("/* AST nodes = semantic value types (in actions, the respective types of '$$') */\n\n");
	char *decl = mtrac_strdup("/* Mapping C types to tokens */\n\n"
				"%define api.value.type union\n\n"
				"%define parse.error detailed\n"
				"%define lr.type ielr\n"
				//"%define parse.lac full\n"
				"%glr-parser\n"
				//"%expect-rr 1\n"
				"%define parse.trace\n\n");
	char *bnf = mtrac_strdup("");
	char *fdecl = mtrac_strdup("\n/* action handler (stub) functions */\n\n");
	char *funcs = mtrac_strdup("\n/* action handler (stub) functions */\n\n");
	char *tdecl = mtrac_strdup("\n/* AST walk (stub) functions */\n\n");
	char *templ = mtrac_strdup("\n/* AST walk (stub) functions */\n\n");
	stringlist *results = new_result_dup(null, "", no_pipe);

	if(opt_verbose || opt_debug) printf("• constructing rules\n");

	/* rules */
	char *last = null;
	while(definition) {
		char *prefix = mtrac_strdup(""); // catdup(definition->name, "_", tolower);

		/* traverse all words, options and synonyms to create a list of result strings */
		assert(definition->rules);
		definition->simple = !definition->rules->next;

		/* echo lgf source into output */
		if(opt_comment) {
			char *c = mtrac_strdup("/* ");
			concat(&c, /* str(definition->line), ": ", */ trim(definition->source), " */");
			replace(&c, "\n", "\n\t * ");
			concat(&c, "\n");
			new_result(results, c, no_pipe);
		}

		char *tag = mtrac_strdup("");
		//concat(&tag, definition->name, rule->mode == active ? "_predicate" : "_predicament");
		concat(&tag, definition->name);
		add_token(&tokens, tag, null, predef, sort); // (x)
		concat(&tag, ":\t");
		new_result(results, tag, no_pipe);

		struct rule *rule = definition->rules;
		bool frst = true;
		do {
			produce_rule(new_result_dup(results, "\t  ", frst ? no_pipe : with_pipe),
				definition, rule, rule->words, null, unspaced, prefix, false);
			frst = false;
		} while((rule = rule->next));
		new_result_dup(results, "\t;\n\n", no_pipe);

		/* enums, type and structure declarations */
		concat(&enu, "\t", definition->name, ",\n");
		concat(&uni, "\t", definition->name , " ", definition->name, ";\n");
		stringlist *token = definition->tokens;
		stringlist *types = definition->types;
		concat(&stru, "typedef struct ", definition->name, " {\n");
		while(token) {
			if(!strcmp(token->string, "Literal")
			|| !strcmp(token->string, "Name")
			|| !strcmp(token->string, "Description")
			|| !strcmp(token->string, "Scalar")
			|| !strcmp(token->string, "Hex"))
				concat(&stru, "\t", types->string, " *", token->string, ";\n");
			else {
				concat(&stru, "\tstruct ", types->string, " *", token->string, ";\n");
			}
			token = token->next;
			types = types->next;
		}
		concat(&stru, "\tLiteral *Literal;\n} ", definition->name, ";\n\n");

		/* action handler (parse) functions and their declarations */
		concat(&fdecl, definition->name, " *process_", LOW(definition->name), "(", definition->name, " *", definition->name, ");\n");
		concat(&funcs, definition->name, " *process_", LOW(definition->name), "(", definition->name, " *", definition->name, ") {\n"
			"\tif(opt_debug_actions) printf(\"actions: parsing ", definition->name);
		if(in_list(definition->tokens, "Name")) concat(&funcs, " %s\\n\", ", definition->name, "->Name);\n");
		else if(in_list(definition->tokens, "Description")) concat(&funcs, " %s\\n\", ", definition->name, "->Description);\n");
		else if(in_list(definition->tokens, "Scalar")) concat(&funcs, " %s\\n\", ", definition->name, "->Scalar);\n");
		else if(in_list(definition->tokens, "Hex")) concat(&funcs, " %s\\n\", ", definition->name, "->Hex);\n");
		else concat(&funcs, " '%s'\\n\", ", definition->name, "->Literal);\n");

		// List struct elements in commented-out rows
		token = definition->tokens;
		while(token) {
			concat(&funcs, "\t// ", definition->name, "->", token->string, "\n");
			token = token->next;
		}
		concat(&funcs, "\treturn ", definition->name,";\n}\n\n");

		/* AST walk (code production) template functions and their declarations. Obviously, the following
		   is code that produces code that produces code.  */
		concat(&tdecl, "/*T*/\tbool ", opt_langprefix, "_", LOW(definition->name),
			"(char **production, ", definition->name, " *", definition->name,
			", int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);\n");
		concat(&templ, "/*T*/\tbool ", opt_langprefix, "_", LOW(definition->name),
			"(char **production, ", definition->name, " *", definition->name,
			", int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\n");
		concat(&templ, "/*T*/\t\tif(!", definition->name, ") return false;\n");

		/* debug output */
		concat(&templ, "/*T*/\t\tif(opt_debug) printf(\"producing ", definition->name);
		if(in_list(definition->tokens, "Name")) concat(&templ, " %s\\n\", ", definition->name, "->Name);\n");
		else if(in_list(definition->tokens, "Description")) concat(&templ, " %s\\n\", ", definition->name, "->Description);\n");
		else if(in_list(definition->tokens, "Scalar")) concat(&templ, " %s\\n\", ", definition->name, "->Scalar);\n");
		else if(in_list(definition->tokens, "Hex")) concat(&templ, " %s\\n\", ", definition->name, "->Hex);\n");
		else concat(&templ, "\\n\");\n\n"); //*** literal!

		/* arbitrary coloring of tokens */
		concat(&templ, "/*T*/\t\tchar *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, \"",
			LOW(dash_spaced(definition->name)), "\")) ? opt_color : \"\";\n" );
		concat(&templ, "/*T*/\t\tchar *off = *color ? \"\\033[0m\" : \"\";\n" );

		/* actual command production */
		bool has_leaf = !!definition->tokens;
		bool recursive = in_list(definition->tokens, definition->name) && !definition->tokens->next->next;
		char *match = _mtrac_dupcat("", ",", definition->name, ",", null);
		char *no_break_list = ",Type,Symbol,Combination,Combinand,Combinor,Combinator,";
		bool no_break = !!strstr(no_break_list, match);
		bool skip = !!strstr(",Type_Term,Punctuation,", match); // core lang
		char *drop_list = ""; // ":Punctuation:"; // tree 
		char *cut_list = ""; // "::Article:"; // flat tree
		char *skid_list = ""; // ":Catena:Type_Term:Body:Provisions:"; // flat tree
		char *hide_list = ""; //":Definition:Symbol:"; // flat tree
		mtrac_free(match);

		char *production_name = mtrac_strdup(LOW(dash_spaced(definition->name)));

		/* tree production (same as core case 'has_leaf') */
		concat(&templ, "/*T*/\t\tbool sameline;\n");
		if(recursive) {
			concat(&templ, "/*T*/\t\tbool has_more_recursion = !!", definition->name, "->", definition->name, ";\n");
			concat(&templ, "/*T*/\t\tbool skipped = (!opt_produce_tree || opt_produce_flat) "
				"&& !!", definition->name, "->", definition->name, ";\n");
		} else {
			concat(&templ, "/*T*/\t\tbool has_more_recursion = false;\n");
			concat(&templ, "/*T*/\t\tbool skipped = false;\n");
		}
		concat(&templ, "/*T*/\t\tbool terse = opt_produce_terse && (skipped || (1 == 0");
		token = definition->tokens;
		while(token) {
			if(!in(cut_list, token->string) && !in(skid_list, token->string))
				concat(&templ, " + (!!", definition->name, "->", token->string, "?1:0)");
			token = token->next;
		}
		concat(&templ, "));\n");

		/* tree: produce actual node name, for tree display */
		bool hide = in(hide_list, definition->name);
		concat(&templ, "/*T*/\t\tif(opt_produce_tree) {\n");
		if(in(skid_list, definition->name))
			concat(&templ, "/*T*/\t\t\tif(!opt_produce_flat");
		else
			concat(&templ, "/*T*/\t\t\tif(!(opt_produce_flat && has_more_recursion)");
		concat(&templ, " && !terse)\n");
		concat(&templ, "/*T*/\t\t\t\t", "padcat(", definition==grammar?"0":"1", ", indent, production, \"", definition!=grammar?"↳  ":"   ", "\""); // ↳
		if(!hide) concat(&templ, ", color, \"", production_name, "\", off, \" \"");
		concat(&templ, ");\n");

		/* core: skips some, unpacks the binary nesting and uses less lines */
		concat(&templ, "/*T*/\t\t} else {\n");
		if(!skip) {
			if(recursive)
				/* list conversion: those definitions that have a leaf that is of their own type are not printed
				   when that leaf is not null this produces lists instead of nested binary nodes. Note the produced
				   if lives two runtimes later. It leaves it to the next nested instance to produce (or to also
				   pass until the last of these) */
				concat(&templ, "/*T*/\t\t\tif(!has_more_recursion && !terse) {\n");
			if(no_break) {
				concat(&templ, "/*T*/", recursive?"\t":"",
					"\t\t\tpadcat(bracket_just_closed?1:0, bracket_just_closed?indent:0,"
					" production, opening_bracket, \" \", color, \"", production_name, "\", off, \" \");\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tsameline = !bracket_just_closed;\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tbracket_just_closed = false;\n");
			} else if(has_leaf) {
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tpadcat(", definition==grammar?"0":"1", ", indent,"
					" production, opening_bracket, \" \", color, \"", production_name,"\", off, \" \");\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tsameline = false;\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tbracket_just_closed = false;\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tsameline = false;\n");
			} else {
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tpadcat(bracket_just_closed?1:0, bracket_just_closed?indent:0,"
					" production, color, \"", production_name, "\", off, \" \");\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tsameline = !bracket_just_closed;\n");
				concat(&templ, "/*T*/", recursive?"\t":"", "\t\t\tbracket_just_closed=false;\n");
			}
			if(recursive) {
				concat(&templ, "/*T*/\t\t\t} else\n");
				concat(&templ, "/*T*/\t\t\t\tsameline = true;\n");
			}
		}
		mtrac_free(production_name);

		// /* for leafless tokens print literal: the actual word that triggered the token */
		// if(!definition->tokens) concat(&templ, ", \"«\", ", definition->name, "->Literal", ", \"»\" "); ◊ clean up / make option

		concat(&templ, "/*T*/\t\t}\n");

		/* *** calls to constituting leaves *** */

		/* sorting recursion to top: */
		token = definition->tokens;
		types = definition->types;
		stringlist *prevto = null;
		stringlist *prevty = null;
		while(token) {
			if(!strcmp(definition->name, token->string)) {
				/* bring recursion top */
				if(prevto) {
					prevto->next = token->next;
					prevty->next = types->next;
					token->next = definition->tokens;
					types->next = definition->types;
					definition->tokens = token;
					definition->types = types;
				}
				break;
			}
			prevto = token;
			prevty = types;
			token = token->next;
			types = types->next;
		}

		/* producing calls */
		token = definition->tokens;
		types = definition->types;
		const char *stop = ",Article,This_Contract,Be,Catena,Illocutor,Preposition,";
		concat(&templ, "/*T*/\t\tbool sibbling_follows;\n");
		if(recursive)
			concat(&templ, "/*T*/\t\tif(!opt_produce_flat) grid <<= 1;\n");
		else
			concat(&templ, "/*T*/\t\tgrid <<= !terse ? 1 : 0;\n");
		concat(&templ, "/*T*/\t\tint irx = !terse ? 1 : 0;\n");

		/* individual leaf calls, including the recursing 'namesake' */
		while(token) {
			bool stopped = !!strstr(stop, token->string);
			bool namesake = !strcmp(definition->name, token->string);

			if(stopped) {
				if(!strstr("article,this", LOW(types->string)))
					concat(&templ, "/*T*/\t\tif(true) {\n");
				else
					concat(&templ, "/*T*/\t\tif(opt_produce_tree) {\n");
			}
			if(!recursive)
				concat(&templ, "/*T*/\t\t", stopped?"\t":"", "if(!terse) grid &= 4294967294;\n");
			if(token->next) {
				concat(&templ, "/*T*/\t\t", stopped?"\t":"", "sibbling_follows = !!(");
				stringlist *succ = token->next;
				stringlist *start = succ;
				bool any = false;
				while(succ) {
					if(!in(drop_list, succ->string)) {
						if(!in(cut_list, succ->string) && !in(skid_list, succ->string))
							concat(&templ, succ!=start?" || ":"", definition->name, "->", succ->string);
						else
							concat(&templ, succ!=start?" || ":"", "!opt_produce_flat && ", definition->name, "->", succ->string);
						any = true;
					}
					succ = succ->next;
				}
				if(!any)
					concat(&templ, "false");
				concat(&templ, ");\n");
				if(!recursive || !namesake)
					concat(&templ, "/*T*/\t\t", stopped?"\t":"",
						"if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows;"
						" if(line) grid |=1; }\n");
				else
					concat(&templ, "/*T*/\t\t", stopped?"\t":"",
						"if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows;"
						" if(line) grid |= 1; }\n");
			}
			else
				concat(&templ, "/*T*/\t\t", stopped?"\t":"", "sibbling_follows = false;\n");


			if(recursive && namesake) {
				concat(&templ, "/*T*/\t\tirx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;\n");
			} else {
				// concat(&templ, "/*T*/\t\tirx = ", strstr(no_break_list, token->string) ? "0" : "1", ";\n");
				concat(&templ, "/*T*/\t\tirx = !terse ? 1 : 0;\n");
				concat(&templ, "/*T*/\t\tif(opt_produce_tree && opt_produce_flat) grid |= sibbling;\n");
			}

			concat(&templ, "/*T*/\t\t", stopped?"\t":"", "if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;\n");


			/* *** actual call to the leaf *** */
			if(!in(drop_list, token->string)) {
				char *type = lowdup(types->string);
				char *name = lowdup(definition->name);
				bool cut = in(cut_list, token->string);
				char *tabs = "\t\t";
				if(cut) {
					concat(&templ, "/*T*/\t\tif(!opt_produce_flat) {");
					tabs = "\t\t\t";
				}
				concat(&templ, "/*T*/", tabs, stopped?"\t":"", opt_langprefix, "_", type,
					"(production, ",
					definition->name, "->", token->string,
					", indent+irx, ",
					namesake?"false, ":"true, ",
					recursive?"sibbling_follows && skipped":"false", namesake?"|| sibbling":"",
					", subhighlight || opt_values && !!strstr(opt_values, \"", name, "\")",
					", opt_subvalues && !!strstr(opt_subvalues, \"", name, "\")", ");\n",
					"/*T*/", tabs, stopped?"\t":"", "subhighlight = false;\n");
				if(cut) {
					concat(&templ, "/*T*/\t\t}");
				}
				mtrac_free(type);
				mtrac_free(name);
			}

			/* delayed grid shift for skipped recursives */
			if(recursive && namesake) {
				concat(&templ, "/*T*/\t\tif(opt_produce_flat) grid <<= !terse ? 1 : 0;\n");
			}

			if(stopped)
				concat(&templ, "/*T*/\t\t}\n");

			token = token->next;
			types = types->next;
		}

		concat(&templ, "/*T*/\t\tgrid >>= !terse ? 1 : 0;\n");

		/* closing bracket of the production of this node */
		if((no_break || has_leaf) && !skip) {
			/* list conversion: those definitions that have a leaf that is of their own type are not
			   printed when that leaf is not null this produces lists instead of nested binary nodes.
			   Note the produced if lives two runtimes later. */
			if(recursive)
				concat(&templ, "/*T*/\t\tif(topcall) {\n");
			concat(&templ, "/*T*/", recursive?"\t":"", "\t\tpadcat(0, 0, production, opt_produce_tree?\"\":closing_bracket, \"",
				definition==grammar?"\\n":" ", "\");\n");
			concat(&templ, "/*T*/", recursive?"\t":"", "\t\tbracket_just_closed=true;\n");
			if(recursive)
				concat(&templ, "\t\t}\n");
		}

		/* return and end of function body */
		concat(&templ, "\n/*T*/\t\treturn true;\n/*T*/\t}\n/*T*/\n");

		mtrac_free(prefix);

		definition = definition->next;
		if(definition) new_result_dup(results, "", no_pipe);
	}
	concat(&enu, "};\n\n");
	concat(&uni, "};\n\n");

	/* the Yacc %tokens tags: predefined tokens, plus .. */
	stringlist *token = predef;
//	concat(&decl, "\t%type <Literal *> Literal\n");
	while(token) {
		if(in_list(ignores, token->string))
			concat(&decl, "\t%token ", UP(token->string), "\n");
		else { // name, description
			concat(&decl, "\t%token <", UP(token->string), " *> ", literal_symbol(token->string), "\n");
			concat(&decl, "\t%nterm <", UP(token->string), " *> ", UP(token->string), "\n"); // UP buffer ok here
		}
		token = token->next;
	}
	/* .. from tokens as produced at (x) and (xx) */
	token = tokens;
	while(token) {
		if(strchr(token->string, '"'))
			concat(&decl, "\t%token ", literal_symbol(token->string), "\n");
		else
			concat(&decl, "\t%nterm <", UP(token->string), " *> ", UP(token->string), "\n"); // UP buffer ok here
		token = token->next;
	}

	/* keywords: the Lexer parse patterns and token values of all found literals (case insensitivity presumed) */
	token = tokens;
	while(token) {
		if(strchr(token->string, '"'))
			concat(&lex, token->string, strlen(token->string)<10?"\t":"",
				"\t\t\t\t\t\t\t{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ", literal_symbol(token->string), "; }\n");
		token = token->next;
	}
	concat(&lex, "{termpart} /* no space to not erron. make it longest match */"
		" { D; syntax(\"unexpected word (after precompilation, use -P to check)\", yytext); }\n");

	/* the BNF (-G) rule result strings, which are built up logically in parallel, are now joined sequentially */
	stringlist *result = results;
	while(result) {
		if(result->string) concat(&bnf, "\t", result->string, "\n");
		result = result->next;
	}
	/* add standard predefined rules for names, descriptions and scalars */
	concat(&bnf, "\tName: NAME\t\t\t\t\t\t{ $$=$NAME; }\n\t    ;\n\n");
	concat(&bnf, "\tDescription: DESCRIPTION\t\t\t\t\t\t{ $$=$DESCRIPTION; }\n\t    ;\n\n");
	concat(&bnf, "\tScalar: SCALAR\t\t\t\t\t\t{ $$=$SCALAR; }\n\t    ;\n\n");
	//# concat(&bnf, "\tHex: HEX\t\t\t\t\t\t{ $$=$HEX; }\n\t    ;\n\n");

	/* note, much of what was produced above can remain unused below if not asked for by command line options, e.g. -G, -Y etc */

	if(opt_verbose || opt_debug) printf("• output\n");

	/* create examples - this can get many - AND check for missing definitions. An error stops the rest below */
	if(opt_samples) {
		stringlist *examples = new_result_dup(null, "", false);
		struct word *word = new(struct word, word);
		word->string = mtrac_strdup(grammar->name);
		char contract_name[1000]; *contract_name = 0;
		char clause_name[1000]; *clause_name = 0;
		char last_defined[1000]; *last_defined = 0;
		bool separated = true;
		int names = 0;
		int texts = 0;
		int count = 1; // sic
		if(opt_verbose) fprintf(stderr, "• building examples\n");
		produce_examples(&examples, 0, word, grammar, contract_name, clause_name, last_defined, &separated, &names, &texts, "", &count, 5);
		if(strlen(opt_samples) || !opt_quiet) write_examples(examples, count);
		delete_stringlist(examples);
		mtrac_free(word->string);
		mtrac_free(word);
		word = null;
	}

	/* keyword tokens (sorted case-insensitively) */
	if(opt_keywords) {
		stringlist *keys = null;
		token = tokens;
		while(token) {
			if(strchr(token->string, '"')) {
				add_token(&keys, literal_symbol(token->string), null, null, sort);
			}
			token = token->next; }
		token = keys;
		while(token) { mtrac_concat(&keywords, token->string, "\n"); token = token->next; }
		delete_stringlist(keys);
	}

	if(opt_bootstrap)
		prepfile(opt_bootstrap, opt_header, opt_source_base, opt_source, lex);

	/* print (-B) only the BNF grammar (subset of -Y) */
	if(opt_bnf && !opt_quiet) {
		printf("%s", bnf);
	}

	/* print or write (to -Y<file>) the BNF grammar and ancillary functions */
	if(opt_yacc) {
		if(opt_verbose || opt_debug) {
			if(!strlen(opt_yacc))
				printf("\n2nd cycle parser file:\n"
					"----------------------\n"
					"- node structures\n"
					"- rules, actions\n"
					"- node processing functions\n\n");
			else
				printf("  writing 2nd cycle parser source to file %s\n", opt_yacc);
		}
		char *include = mtrac_strdup("");
		//if(opt_header) concat(&include, "#include \"", opt_header, "\"\n");
		char *root = mtrac_strdup("");
		concat(&root, "static ", UP(grammar->name), " *root;");
		concat(&req, include, /* enu, "\n", */ stru, "\n", root, "\n", /* uni, "\n", */ fdecl, "}");
		FILE *out = stdout;
		if(strlen(opt_yacc)) {
			chdir(name_homedir); // assume path to open as relative to dir at program start
			if(!(out = fopen(opt_yacc, "w"))) { perror(opt_yacc); exit(1); }
		}
		if(strlen(opt_yacc) || !opt_quiet)
			fprintf(out, "%%{\n\n/* Prologue */\n\n%s\n%%}\n\n"
				"/* Requires */\n\n%s\n\n"
				"/* Declarations */\n\n%s\n\n%%%%\n\n"
				"/* Grammar */\n\n%s\n\n%%%%\n\n"
				"/* Epilogue */\n\n%s\n\n%s",
				prol, req, decl, bnf, yacc_stub(), funcs);
		if(strlen(opt_yacc)) {
			fclose(out);
			chdir(file_location); // back to source file's absolute location
		}
		mtrac_free(include);
		mtrac_free(root);
	}

	/* print or write (to -T<file>) the AST tree walk functions */
	if(opt_template) {
		if(opt_verbose || opt_debug) {
			if(!strlen(opt_template))
				printf("\nAST walk functions:\n"
					"-------------------\n"
					"- %s prefix\n\n", opt_langprefix);
			else
				printf("  writing %s_* AST walk functions to file %s\n", opt_langprefix, opt_template);
		}

		replace(&stru, "\n", "\n/*T*/\t");
		char *stub = mtrac_strdup(walk_stub());
		replace(&stub, "<prefix>", opt_langprefix);
		replace(&stub, "<low-roottype>", LOW(grammar->name));
		replace(&stub, "<roottype>", grammar->name);

		FILE *out = stdout;
		if(strlen(opt_template)) {
			chdir(name_homedir); // assume path to open as relative to dir at program start
			if(strcmp(opt_template, "core.c") && access(opt_template, F_OK ) != -1 ) {
				fprintf(stderr, "walk function file '%s' exists. Please move or delete and try again."
					" (Only 'core.c' is not protected this way.)\n", opt_template); exit(1);
			}
			if(!(out = fopen(opt_template, "w"))) { perror(opt_template); exit(1); }
		}
		if(strlen(opt_template) || !opt_quiet) {
			fprintf(out, "/*T*/\t/* %s code production / AST walk */\n\n", opt_langprefix);
			fprintf(out, "%s", requires);
			fprintf(out, "%s%s%s\n\n%s", stru, stub, tdecl, templ);
		}
		if(strlen(opt_template)) {
			fclose(out);
			chdir(file_location); // back to source file's absolute location
		}
		mtrac_free(stub);
	}

	// .. free
	delete_stringlist(results);
	mtrac_free(lex);
	mtrac_free(prol);
	mtrac_free(req);
	mtrac_free(enu);
	mtrac_free(uni);
	mtrac_free(stru);
	mtrac_free(decl);
	mtrac_free(bnf);
	mtrac_free(fdecl);
	mtrac_free(funcs);
	mtrac_free(tdecl);
	mtrac_free(templ);
	rule = null;
	alternation = null;
	alternate = null;
	word = null;
}

void produce_examples(stringlist **accu, int depth, struct word *word, struct definition *grammar, char *contract_name,
	char *clause_name, char *last_defined,  bool *separated, int *names, int *texts, char *check, int *count, int fuse) {

	assert(accu);
	stringlist *branch = *accu;
	assert(branch);
	assert(!branch->next);

	bool opn_q = false; // opening quotes have been/are being set.

	if(!word && opt_debug_examples)
		fprintf(stderr,
			"\n----------------------------------------\n"
			"Reached one end node building example #%d -- now: \n\n%s\n"
			"----------------------------------------\n\n",
			*count, branch->string);
	if(!word) return;

	char *name = word->string;
	if(opt_debug_examples) fprintf(stderr, "example: %*s%*s ⟶   %s\n", 20-fuse, "", 20-fuse, "", name);

//	if(!fuse) { concat(&branch->string, " [error: recursion stopped for ", name, "] "); return; }

	/* handle terminals, i.e. literal strings and interpunctuation */
	char **add = null;
	bool separator_now = false;
	int blen = strlen(branch->string);
	bool space = !blen || (branch->string)[blen-1] == '\"';
	bool linestart = !blen || (branch->string)[blen-1] == '\n';
	if(!strcmp(name, "Clause")) { strcpy(clause_name, foobar(++*names)); }
	if(!strncmp(name, "Lex", 4)) { strcpy(contract_name, foobar(++*names)); }
	if(!strcmp(name, "Name")) {
		add = concat(&branch->string, space ? "" : " ", *clause_name?clause_name:*last_defined?last_defined:contract_name);
		*clause_name=0;
		*separated = false;
	}
	else if(!strcmp(name, "Description")) { add = concat(&branch->string, space ? "" : " ", blind(++*texts)); *separated = false; }
	else if(!strcmp(name, "Scalar")) { add = concat(&branch->string, space ? "" : " ", "123"); *separated = false; }
// 	else if(!strcmp(name, "Hex")) { add = concat(&branch->string, space ? "" : " ", "0xf00ba5"); *separated = false; }
	else if(!strcmp(name, "Colon")) { add = concat(&branch->string, ":"); separator_now = true; }
	else if(!strcmp(name, "Comma")) { add = concat(&branch->string, ","); }
	else if(!strcmp(name, "This")) { concat(&branch->string, linestart?"This ":" this ", contract_name); return; }
	else if(!strcmp(name, "Separator") || !strcmp(name, "separator")) { add = concat(&branch->string, ".\n"); separator_now = true; }
	else if(!strcmp(name, "Quote"))  {
		opn_q = !(chrcnt(branch->string, '\"') % 2);
		add = concat(&branch->string, !opn_q || linestart ? "" : " ", "\"");
		if(opn_q) strcpy(last_defined, foobar(++*names));
	}
	else if(strchr(name, '"')) add = concat(&branch->string, linestart?"":" ", *separated ? UP(quote_trimmed(name)) : quote_trimmed(name)) ;

	/* simple case: recurse to next word and end this branch upon return */
	if(add) {
		*separated = separator_now;
		if(opt_debug_examples) {
			if(word->next) fprintf(stderr, "example %d: (add) node %s follows to %s\n", *count, word->string, word->next->string);
			else fprintf(stderr, "example %d: (add) node %s has no next\n", *count, word->string);
		}
		produce_examples(accu, depth+1, word->next, grammar, contract_name, clause_name, last_defined, separated, names, texts, check, count, fuse);
		return;
	}

	/* end recursion if non-terminal (non-printing) token was met 3 times before (some, like 'provisions' must be allowed multiple times) */
/*
	if(strstr(check, name))
		if(strstr(strstr(check, name)+1, name))
			if(strstr(strstr(strstr(check, name)+1, name)+1, name)) { concat(&branch->string, " [stopped]"); return; }
*/
	/* find the definition of 'name', which is a rule token's name */
	struct definition *definition = grammar;
	while(definition) { if(!strcmp(name, definition->name)) break; definition = definition->next; }
	if(!definition) { fprintf(stderr, "error in %s: token '%s' undefined\n", opt_source ? opt_source : "stdin stream", name); exit(35); }

	/* prepend empty line for 'important' tokens (spaced lettering in LGF) */
	if(definition->important && strcmp(definition->name, "Statements"))  concat(&branch->string, "\n");

	/* fork into the set of resulting BNF rules ('subrules') of this definition. (One LGF rule often results into multiple BNF ('sub'-)rules.) */
	char *checkdup = mtrac_strdup(check);
	concat(&checkdup, name, ",");
	fuse--;
	assert(!branch->next); // bec. it, too, is used in the recursion to add new branches to.

	/* pick a random starting point */
	struct rule *subrule = definition->subrules;
	assert(subrule);
	int n = 1; while((subrule = subrule->next)) n++;
	//int i = (nonce += 17) % n;
	int i = rand() % n;
/*
	if(depth > 50) {
		mtrac_free(branch->string);
		branch->string = mtrac_strdup("overlong");
		return;
	}

*/	/* if at limit of wanted example count, choose one branch down only, at random */
	if(fuse <= 0 || (opt_max_examples && *count >= opt_max_examples)) {
		printf("Count: %d\n", *count);
		if(opt_debug_examples) fprintf(stderr, "  max cut off: picking alternate #%d of %d ", i, n);

		subrule = definition->subrules;
		while(i--) subrule = subrule->next;
		if(opt_debug_examples) fprintf(stderr, " (%s --> %s)\n", definition->name, subrule->words->string);

		bool sep = *separated;
		produce_examples(accu, depth +1, subrule->words, grammar, contract_name, clause_name, last_defined, &sep, names, texts, checkdup, count, fuse);
		produce_examples(accu, depth +1, word->next, grammar, contract_name, clause_name, last_defined, &sep, names, texts, checkdup, count, fuse);

	/* but normally, traverse all alternates. From a random starting point however, revolving. */
	} else {
		*accu = null; /* temp loses connct to branch */

		subrule = definition->subrules;
		while(i--) subrule = subrule->next;
		i = n;
		while(i--) {
			if(i) {
				(*count)++; // ie. does count one less than loops: the existing branch.
				printf("Count: %d\n", *count);
				if(opt_verbose) fprintf(stderr, "\b\b\b\b\b\b\b\b\b\b\b  %d", *count);
			}
			stringlist *fork = i ? new_result_dup(null, branch->string, no_pipe) : branch;
			bool sep = *separated;
			produce_examples(&fork, depth +1, subrule->words, grammar, contract_name, clause_name,
				last_defined, &sep, names, texts, checkdup, count, fuse);
			stringlist *subfork = fork; // fork now may have subforks added.
			while(subfork) {
				stringlist *next = subfork->next;
				subfork->next = null;
				produce_examples(&subfork, depth +1, word->next, grammar, contract_name, clause_name,
					last_defined, &sep, names, texts, checkdup, count, fuse);
				/* subfork may now also have subforks. Add all to resulting fork list */
				*accu = listcat(*accu, subfork);
				subfork = next;
			}
			subrule = subrule->next ? subrule->next : definition->subrules; // from top
		}
	}
	assert(pin_list(*accu, branch));
	mtrac_free(checkdup);

	return;
}

char foobars[2000];
char *bars[12] = {"Foo", "Bar", "Baz", "Qux", "Corge", "Grault", "Garply", "Waldo", "Fred", "Plugh", "Xyzzy", "Thud"};
char *foobar(int n) {
	char *p = foobars;
	if(n > 12 && n % 2) n = (n % 12) + 1;
	else if(n > 144 && n % 3) n = (n % 144) + 1;
	while(n) {
		if(p!=foobars) p += strlen(strcpy(p, " "));
		p += strlen(strcpy(p, bars[n % 12]));
		n /= 12;
	}
	return foobars;
}


char *blindtext = ".Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor."
	" Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus."
	" Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim."
	" Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a,"
	" venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus"
	" elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae,"
	" eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla"
	" ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur"
	" ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus,"
	" sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus"
	" pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero"
	" venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo."
	" Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna.";
char *blind(int n) {
	char *q, *p = foobars;
	strcpy(p, blindtext);
	int s = n % 11;
	int l = n % 7 + 1;
	while(s) if(*++p=='.') s--;
	q = ++p;
	while(l) if(*++q==' ') l--;
	*q = 0;
	return p;
}


/* write examples to file or screen */
void write_examples(stringlist *example, int count) {
	int width = 6; // log10(count)+1; ◊ can require lib
	int i = 1;

	/* to screen */
	if(!strlen(opt_samples) && !opt_quiet) {
		printf("\nexamples:\n---------\n\n");
		while(example) {
			printf("--- example #%0*d ---\n\n%s\n\n", width, i++, example->string);
			example = example->next;

	/* to individual files (and if --echo, to screen) */
	}} else if (strlen(opt_samples)) {
		int size = 1 + width + snprintf(null, 0, "%s%0*d.lex", opt_samples, width, 0);
		char *filename = news(filename, size);
		chdir(name_homedir); // assume path to open as relative to dir at program start
		if(opt_wipe) {
			if(opt_verbose || opt_debug)
				printf("  deleting files %s%0*d.lex - %s%0*d.lex\n", opt_samples, width, 1, opt_samples, width, count);
			snprintf(filename, size, "rm %s*.lex", opt_samples);
			printf("clean up %s\n", filename);
			system(filename);
		}
		if(opt_verbose || opt_debug)
			printf("  writing example files %s%0*d.lex - %s%0*d.lex\n", opt_samples, width, 1, opt_samples, width, count);
		while(example) {
			snprintf(filename, size, "%s%0*d.lex", opt_samples, width, i);
			if(opt_echo) printf("#%0*d --- %s\n\n%s\n\n", width, i, filename, example->string);
			i++;
			FILE *fp = fopen(filename, "wb");
			if(!fp) { fprintf(stderr, "could not open file for writing. "); perror(filename); exit(1); }
			fwrite(example->string, 1, strlen(example->string), fp);
			fclose(fp);
			example = example->next;
		}
		mtrac_free(filename);
		chdir(file_location); // back to source file's absolute location
	}
}



/* build the resulting BNF, as string, from the LXF tree */
void produce_extension(struct definition *definition) {

	if(!definition) return;
	assert(definition->rules);
	assert(!definition->results);

	char *bnf = mtrac_strdup("");
	stringlist *results = new_result_dup(null, "", no_pipe);

	/* rules */
	char *last = null;
	while(definition) {
		char *prefix = mtrac_strdup(""); // catdup(definition->name, "_", tolower);

		/* traverse all words, options and synonyms to create a list of result strings */
		assert(definition->rules);
		struct rule *rule = definition->rules;
		mode last = none;
		struct rule *last_rule = null;
		do {
			if(rule->mode != last || last_rule != rule) {
				char *tag = mtrac_strdup("");
				concat(&tag, definition->name, rule->mode == active ? "_Predicate" : "_Predicament");
				add_token(&tokens, tag, null, null, sort); // (x)
				concat(&tag, ":\t");
				new_result(results, tag, no_pipe);
				last = rule->mode;
				last_rule = rule;
			}
			produce_rule(new_result_dup(results, "\t  ", no_pipe), definition, rule, rule->words, null, unspaced, prefix, true);
			if(rule->next) new_result_dup(results, "", no_pipe);
		} while((rule = rule->next));
		mtrac_free(prefix);
		definition = definition->next;
	}

	/* prepend tokens, which were produced in produce_rule at (xx) and above at (x) */
	stringlist *token = tokens;
	while(token) {
		concat(&bnf, "\t%token ", token->string, "\n");
		token = token->next;
	}

	/* the result strings, which are built up logically in parallel, are now joined sequentially */
	stringlist *result = results;
	while(result) {
		if(result->string) concat(&bnf, "\t", result->string, "\n");
		result = result->next;
	}

	printf("%s", bnf);

	// .. free
	delete_stringlist(results);
	rule = null;
	alternation = null;
	alternate = null;
	word = null;
}

void produce_tokens(stringlist *results, stringlist *token) {

	while(token) {
		char *t = mtrac_strdup("%token ");
		concat(&t, token->string);
		new_result(results, t, no_pipe);
		token = token->next;
	}
}

/* recursively add the next word of a rule, fork the production for both optionals and synonyms */
void produce_rule(stringlist *result, struct definition *definition, struct rule *rule, struct word *word,
	struct word *pickup, adjacency space, char *prefix, bool extension) {
	assert(definition);
	assert(rule);
	assert(result);
	assert(result->string);
	assert(!result->seal);

	if(!word) {
		if(pickup)
			if(opt_debug_generator)
				fprintf(stderr, "gentor.: rule production pickup with '%s' after: %s ..\n", pickup->string, result->string);
		word = pickup;
		pickup = null;
	}

	if(!word) {
		/* Now we are done, glue unspaced literals ("lex"":") ... */
		replace(&result->string, "\"\"", "");

		/* (xx) .. and check what words we produced (non-spaced options create new words)
		   and also, record this specific new line as 'subrule', i.e. Yacc BNF rule.
		   what also happens is that quoted literals are replaced by their symbols */
		struct rule **subrule = &definition->subrules;
		while(*subrule) subrule = &(*subrule)->next;
		*subrule = new(struct rule, *subrule);
		struct word **subword = &(*subrule)->words;

		char *t0 = mtrac_strdup(result->string);
		char *t = strtok(t0, " \t");
		char *self_reference = "[error]";
		stringlist *action_tokens = null; // note, one lgf rule struct routinely results into multiple bnf yacc rules
		stringlist *action_numbers = null; // to build $n when needed
		int i = 0;
		while(t) {
			if(*t != '|') {
				i++;
				if(strchr(t, '"'))
					/* replace quoted literals with their upper case symbols */
					replace(&result->string, t, literal_symbol(t));
				else {
					int number = count_in_list(action_tokens, UP(t)) + 1;
					char *field = mtrac_strdup(UP(t));
					if(number > 1) {
						if(!definition->simple)
							fprintf(stderr, "Lexon: name '%s' cannot appear twice in '%s' in file %s.\n"
								"Only simple LGF rules can repeat names. "
								"Simple rules cannot have options ([..]) nor alternatives (.. or ..) .\n",
								UP(t), trim(result->string), file_clearname),
							exit(1);
						mtrac_concat(&field, str(number));
					}
					if(add_token(&action_tokens, UP(t), extension?xpredef:null, extension?null:ignores, keep))
						add_token(&action_numbers, str(i), null, null, keep);
					if(!in_list(definition->tokens, field)) {
						add_token(&definition->tokens, field, null, ignores, keep);
						add_token(&definition->types, UP(t), null, ignores, keep);
					}
					mtrac_free(field);
				}
				add_token(&tokens, t, null, predef, sort);

				/* build subrule */
				assert(!*subword);
				*subword = new(struct word, *subword);
				(*subword)->string = mtrac_strdup(t);
				subword = &(*subword)->next;
				assert(!*subword);
			}
			t = strtok(null, " ");
		}
		mtrac_free(t0);

		/* Now we are done with all words and have picked up all optionals, add the action
		   (unless we want pure BNF output). */
		if(!opt_bnf) {
			pad(&result->string, 50);

			char *fields = mtrac_strdup("");

			stringlist *token = action_tokens;
			stringlist *number = action_numbers;
			stringlist *appearances = null;
			while(token) {
				/* all for grammar (LGF), only some predefined ones for extensions (LXF) */
				/* use $<n> instead of name when equalling definition name */
				add_token(&appearances, token->string, null, null, keep);
				int count = count_in_list(appearances, token->string);
				int appears = count_in_list(action_tokens, token->string);
				char *field = mtrac_strdup(token->string);
				if(appears > 1 && count > 1) mtrac_concat(&field, str(count));
				const char *reference = (!strcmp(token->string, definition->name) || appears > 1) ? number->string : token->string;
				concat(&fields, definition->name, "->"); // separate in 3 calls when using UP buffer
				concat(&fields, field, "=$");
				concat(&fields, reference, "; ");
				mtrac_free(field);
				token = token->next;
				number = number->next;
			}

			concat(&result->string, " { NEW(", definition->name, ", *((Literal **)&yylval)); ",
				fields, definition==grammar?"root":"$$", "=process_", LOW(definition->name), "(", UP(definition->name), "); }" );

			delete_stringlist(appearances);
			mtrac_free(fields);
		}
		delete_stringlist(action_tokens);
		delete_stringlist(action_numbers);

		if(opt_debug_generator) fprintf(stderr, "gentor.: rule production result: %s\n", UP(result->string));
		result->seal = true;
		return;
	}

	assert(!!word->string + word->option_start + word->option_end == 1);

	if(word->string) {
		if(opt_debug_generator) fprintf(stderr, "gentor.: produce word: %s\n", word->string);
		size_t len = strlen(result->string);

		/* Finally, the happy path, add a word. Allow the synonym forks (+) before adding to result->string */
		if(space == spaced) concat(&result->string, " ", UP(word->string)); // (+++)
		else concat(&result->string, UP(word->string));
		produce_rule(result, definition, rule, word->next, pickup,
			word->next && (word->next->option_end || word->next->option_start) ? 0 : spaced, prefix, extension);

		/* fork the string building for every matching synonym. This (++++) helps to order results */
		if(definition->alternations && !pickup) {
			struct alternation *alternation = definition->alternations;
			do {
				assert(alternation->string);
				assert(alternation->alternates);
				if(opt_debug_generator)
					fprintf(stderr, "gentor.: produce alternation - compare: '%s' vs '%s'\n", word->string, alternation->string);
				if(!strcmp(word->string, alternation->string)) {
					struct alternate *alternate = alternation->alternates;
					char *rump = mtrac_strdup(result->string); *(rump + len) = 0; // (++++)
					do {
						if(opt_debug_generator)
							fprintf(stderr, "produce alternation - fork for alt: %s (..)\n", alternate->words->string);
						produce_rule(new_result_dup(result, rump, with_pipe), // (+)
							definition, rule, alternate->words, word->next, space, prefix, extension);
					} while((alternate = alternate->next));
					mtrac_free(rump);
				}
			} while((alternation = alternation->next));
		}
	}

	/* fork the result string, skipping (a) past the (b) into a (nested) options */
	if(word->option_start) {
		definition->simple = false;
		if(opt_debug_generator) fprintf(stderr, "gentor.: production of option - start\n");
		struct word *w = word;
		int nested = 0;
		while((nested += w->option_start - w->option_end) && (w = w->next))
			if(opt_debug_generator) fprintf(stderr, "gentor.: production skips '%s'\n", word->string ? word->string : "bracket");
		char *trunk = mtrac_strdup(result->string); // note, used after result has grown
		produce_rule(result, definition, rule, w, pickup, w->adjacency || word->adjacency, prefix, extension); // (a) skip
		produce_rule(new_result(result, trunk, with_pipe), definition, rule,
			word->next, pickup, word->adjacency || space, prefix, extension); // (b) do the option
	}

	if(word->option_end) {
		if(opt_debug_generator) fprintf(stderr, "gentor.: production of option - end\n");
		produce_rule(result, definition, rule, word->next, pickup, word->adjacency || space, prefix, extension);
	}
}

/* create a new result struct, dup the string and append it to the end of the result's list */
stringlist *new_result_dup(stringlist *result, char *string, piped add_pipe) {
	return new_result(result, mtrac_strdup(string ? string : ""), add_pipe);
}

stringlist *new_result(stringlist *result, char *string, piped add_pipe) {
	stringlist *fork = mtrac_malloc(sizeof(stringlist));
	fork->string = string;
	fork->seal = false;
	fork->next = null;

	if(add_pipe && strlen(string) > 1) string[1] = '|';

	if(result) { while(result->next) result = result->next; result->next = fork; }
	return fork;
}

stringlist *listcat(stringlist *head, stringlist *tail) {

	if(!head) return tail;
	stringlist *i = head;
	while(i->next) i = i->next; i->next = tail;
	return head;
}

bool pin_list(stringlist *list, stringlist *needle) {

	while(list) if(list == needle) return true; else list = list->next;
	return false;
}

void delete_definitions(struct definition *definition) {
	while(definition) {
		mtrac_free(definition->name);
		mtrac_free(definition->source);
		struct rule *r, *rule = definition->rules;
		while(rule) {
			struct word *w, *word = rule->words;
			while(word) { if(word->string) mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }
			struct word *k, *keyword = rule->keywords;
			while(keyword) { mtrac_free(keyword->string); k = keyword; keyword = keyword->next; mtrac_free(k); }
			stringlist *t, *token = rule->tokens;
			while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }
			r = rule; rule = rule->next; mtrac_free(r);
		}
		struct alternation *a, *alternation = definition->alternations;
		while(alternation) {
			mtrac_free(alternation->string);
			struct alternate *aa, *alternate = alternation->alternates;
			while(alternate) {
				struct word *w, *word = alternate->words;
				while(word) { mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }
				aa = alternate; alternate = alternate->next; mtrac_free(aa);
			}
			a = alternation; alternation = alternation->next; mtrac_free(a);
		}
		struct rule *s, *subrule = definition->subrules;
		while(subrule) {
			struct word *w, *word = subrule->words;
			while(word) { mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }
			struct word *k, *keyword = subrule->keywords;
			while(keyword) { mtrac_free(keyword->string); k = keyword; keyword = keyword->next; mtrac_free(k); }
			stringlist *t, *token = subrule->tokens;
			while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }
			s = subrule; subrule = subrule->next; mtrac_free(s);
		}
		stringlist *t, *token = definition->tokens;
		while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }
		stringlist *types = definition->types;
		while(types) { mtrac_free(types->string); t = types; types = types->next; mtrac_free(t); }
		stringlist *rr, *result = definition->results;
		while(result) { mtrac_free(result->string); rr = result; result = result->next; mtrac_free(rr); }
		struct definition *d = definition;
		definition = definition->next;
		mtrac_free(d);
	}
}

void source(char *s) {
	concat(&src, s);
	if(*definition) concat(&(*definition)->source, s);
}

const char *yacc_stub() {
	return
		"bool core_document(char **production, Document *root, int indent, bool topcall, bool sibbling,\n"
		"	bool highlight, bool subhighlight); // #core #tree\n"
//#		"bool sph_document(char **production, Document *root, int indent); // #spheres\n" // :spheres
		"bool js_document(char **production, Document *root, int indent); // #javascript\n" // :javascript
		"bool sol_document(char **production, Document *root, int indent); // #solidity\n" // :solidity
		"bool sophia_document(char **production, Document *root, int indent); // #sophia\n" // :sophia
//#		"extern bool opt_run_spheres;\n"
		"extern bool opt_produce_tree;\n"
		"extern bool opt_produce_core;\n"
		"extern bool opt_produce_javascript;\n"
		"extern bool opt_produce_solidity;\n"
		"extern bool opt_produce_sophia;\n"
		"char *walk() {\n"
		"	char *production = mtrac_strdup(\"\");\n"
		"	if(opt_verbose || opt_debug) fprintf(stderr, \"• starting walk\\n\");\n"
//#		"	if(opt_run_spheres) {\n"
//#		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• run\\n\");\n"
//#		"		sph_document(&production, root, 0); // #spheres\n" // :spheres
//#		"	} else\n"
		"	if(opt_produce_javascript) {\n"
		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• produce javascript\\n\");\n"
		"		js_document(&production, root, 0); // #javascript\n" // :javascript
		"	} else if(opt_produce_solidity) {\n"
		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• produce solidity\\n\");\n"
		"		sol_document(&production, root, 0); // #solidity\n" // :solidity
		"	} else if(opt_produce_sophia) {\n"
		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• produce sophia\\n\");\n"
		"		sophia_document(&production, root, 0); // #sophia\n" // :sophia
		"	} else if(opt_produce_tree) {\n"
		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• produce abstract syntax tree\\n\");\n"
		"		core_document(&production, root, 0, true, false, false, false); // #tree #core\n"
		"	} else { /* default */\n"
		"		if(opt_verbose || opt_debug) fprintf(stderr, \"• produce core listing\\n\");\n"
		"		core_document(&production, root, 0, true, false, false, false); // #core\n"
		"	}\n"
		"	padcat(0,0,&production, \"\\\n\");\n"
		"	return production;\n\n"
		"}\n\n"
		"extern int prec_line;\n"
		"extern char *context;\n"
		"extern char *prec_file;\n"
		"extern char *yytext;\n"
		"void yyerror(const char *s) {\n"
		"	fprintf(stderr, \"Lexon: %s -- check %s, line %d: %s\\n>> %s\\n\", s, prec_file, prec_line, yytext, context);\n"
		"	exit(1);\n"
		"}";
}

const char *walk_stub() {
	return
		"/*T*/	static struct <roottype> *root;\n"
		"/*T*/	bool <prefix>_<low-roottype>(char **production, <roottype> *root, int indent, bool topcall,"
			" bool sibbling, bool highlight, bool subhighlight);\n"
		"/*T*/\n"
		"/*T*/  #define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, null, #orig_, __FILE__, __LINE__)\n"
		"/*T*/  char *_replace(char **orig, const char *rep, const char *with, int all, char *from, int *times,"
			" char *origname, char *file, int line);\n"
		"/*T*/  char *quote_trimmed(const char *token);\n"
		"/*T*/  char *dash_spaced(const char *token);\n"
		"/*T*/  char *snake_spaced(const char *token);\n"
		"/*T*/  char *LOW(const char *token);\n"
		"/*T*/  char *UP(const char *token);\n"
		"/*T*/  extern char *opt_color;\n"
		"/*T*/  extern char *opt_highlight;\n"
		"/*T*/  extern char *opt_symbols;\n"
		"/*T*/  extern char *opt_values;\n"
		"/*T*/  extern char *opt_subvalues;\n"
		"/*T*/\n"
		"/*T*/	bool <prefix>_walk(char **production) {\n"
		"/*T*/		if(!root) return false;\n"
		"/*T*/		return <prefix>_<low-roottype>(production, root, 0, true, false, false, false);\n"
		"/*T*/	}\n\n"
		"/*T*/	bool <prefix>_name(char **production, Name *Name, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\n"
		"/*T*/		if(!Name) return false;\n"
		"/*T*/		padcat(0, 0, production, \"«\", opt_symbols?opt_symbols:\"\", LOW(dash_spaced(quote_trimmed(Name))),"
			" opt_symbols?\"\\033[0m\":\"\", \"» \");\n" 
		"/*T*/		return true;\n"
		"/*T*/	}\n\n"
		"/*T*/	bool <prefix>_description(char **production, Description *Description, int indent, bool topcall,"
			" bool sibbling, bool highlight, bool subhighlight) {\n"
		"/*T*/		if(!Description) return false;\n"
		"/*T*/		padcat(0, 0, production, \"\\\"\", Description, \"\\\"\");\n"
		"/*T*/		return true;\n"
		"/*T*/	}\n\n"
		"/*T*/	bool <prefix>_scalar(char **production, Scalar *Scalar, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\n"
		"/*T*/		if(!Scalar) return false;\n"
		"/*T*/		padcat(0, 0, production, Scalar, \" \");\n"
		"/*T*/		return true;\n"
		"/*T*/	}\n\n"
		"/*T*/	bool <prefix>_hex(char **production, Hex *Hex, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\n"
		"/*T*/		if(!Hex) return false;\n"
		"/*T*/		padcat(0, 0, production, Hex, \" \");\n"
		"/*T*/		return true;\n"
		"/*T*/	}\n\n";
}

/* writing 2nd cycle lexer file */
void prepfile(char *outfile, char *header, char *template, char *grammar_path, char *lex) {
#ifndef CYCLE_2
	if(!template) template = "lexon.l";
#endif
	if(!header) header = "parser.h";
	char *include = news(include, strlen(header) + 100); sprintf(include, "%%{\n#include \"%s\" // set by -H\n%%}\n\n", header);
	if(opt_debug || opt_verbose) {
		if(!strlen(outfile))
			fprintf(stderr, "\n2nd cycle scanner source\n------------------------\n%s%s. It includes %s (use -H to change).\n\n",
				template ? "from template " : "from interned source", template ? template : "", header);
		else
			fprintf(stderr, "  creating 2nd cycle scanner file %s %s%s. It will include %s (use -H to change).\n",
				outfile, template ? "from template " : "from interned source", template ? template : "", header);
	}

	/* go to directory from which the invocation started (we are presently, possibly in the source file's dir) */
	chdir(name_homedir);

	/* read template lexer (this here) file */
	char *src = filedup(template, own);
	replace(&src, "[no grammar]", grammar_version);
	char *src_imbue = str_escape(src, "own");

	/* read grammer file */
	char *grm = filedup(opt_source, owngrm);
	char *grm_imbue = str_escape(grm, "owngrm");

	/* read manual file */
	char *man = filedup("MANUAL", manual);
	char *man_imbue = str_escape(man, "manual");

	char *pre_midend = strstr(src, "/* --" "->"); // never fe" "ed on yourself
	if(!pre_midend) { fprintf(stderr, "could not find type name insertion start mark '/* --" "->' in file %s\n", template); exit(38); }
	char *pre_midstart = strstr(src, "<-" "-- */");
	if(!pre_midstart) { fprintf(stderr, "could not find type name insertion end mark '<-" "-- */' in file %s\n", template); exit(39); }
	*pre_midend = 0;
	pre_midstart += 8;
	char *midend = strstr(pre_midstart, "/* -" "->"); // never fe" "ed on yourself
	if(!midend) { fprintf(stderr, "could not find keyword insertion start mark '/* -" "->' in file %s\n", template); exit(40); }
	char *midstart = strstr(pre_midstart, "<-" "- */");
	if(!midstart) { fprintf(stderr, "could not find keyword insertion end mark '<-" "- */' in file %s\n", template); exit(41); }
	*midend = 0;
	midstart += 7;

	/* write to file, or to screen */
	FILE *fp = strlen(outfile) ? fopen(outfile, "w") : stdout;
	if(!fp) { perror(strlen(outfile)?outfile:"stdout"); exit(1); }
	int check = fwrite(include, strlen(include), 1, fp);
	check += fwrite(src, strlen(src), 1, fp);
	check += fwrite(pre_midstart, strlen(pre_midstart), 1, fp);
	check += fwrite(lex, strlen(lex), 1, fp);
	check += fwrite(midstart, strlen(midstart), 1, fp);
	check += fwrite(src_imbue, strlen(src_imbue), 1, fp);
	check += fwrite(grm_imbue, strlen(grm_imbue), 1, fp);
	check += fwrite(man_imbue, strlen(man_imbue), 1, fp);
	if(check != 8) { fprintf(stderr, "error writing "); perror(strlen(outfile)?outfile:"stdout"); exit(1); }
	fclose(fp);

	/* back to source file's absolute location */
	chdir(file_location);

	mtrac_free(include);
	mtrac_free(src);
	mtrac_free(src_imbue);
	mtrac_free(grm);
	mtrac_free(grm_imbue);
	mtrac_free(man);
	mtrac_free(man_imbue);
}

/* expects to be in the right folder to use the path as is */
char *filedup(const char *path, const char *dflt) {

	FILE *fp;
	char *src;
#ifdef CYCLE_2
	if(!path)
		src = mtrac_strdup(dflt); // midend pokes 0 in
	else
#endif
	{
		fp = fopen(path, "r");
		if(!fp) { perror(path); exit(1); }
		fseek(fp, 0L, SEEK_END);
		int size = ftell(fp);
		rewind(fp);
		src = mtrac_malloc(size + 1);
		if(fread(src, 1, size, fp) != size) { perror(path); exit(1); }
		src[size] = 0;
		fclose(fp);
	}

	return src;
}

char *str_escape(const char *src, const char *varname) {

	char *esc = mtrac_strdup(src);
	replace(&esc, "\\", "\\\\");
	replace(&esc, "\"", "\\\"");
	replace(&esc, "\n", "\\n\"\n\t\"");

	char *imbue = mtrac_strdup("");
	concat(&imbue,"\n\nconst char *", varname, " =\n\n\t\"", esc, "\";");

	mtrac_free(esc);

	return imbue;
}

/* tracking dynamic memory management */

typedef struct mtrac {
	unsigned long magic;
	int index;
	char *name;
	char *file;
	int line;
	size_t size;
	bool free;
	char *free_name;
	char *free_file;
	int free_line;
	int free_action;
	struct mtrac *next;
	struct mtrac *previous;
	unsigned long __attribute__((aligned(8))) magic2;
} mtrac;

const unsigned long mtrac_magic = 0xCCCCCCCCCCCCCCCC;
mtrac *mtrac_first = null;
mtrac *mtrac_last = null;
int mtrac_action = 0;
int mtrac_count = 0;
size_t mtrac_total = 0;
int  mtrac_max_count = 0;
size_t mtrac_max_total = 0;
size_t mtrac_allocated = 0;
int mtrac_allocations = 0;
size_t mtrac_freed = 0;
int mtrac_frees = 0;

/* wholesale handling of freeing, for AST nodes */
typedef struct element {
	void *payload;
	struct element *previous;
} element;
element *mtrac_gross_list = null; // actually the tail

void *_mtrac_malloc(size_t size, char *name, char *file, int line) {

	mtrac_action++;
	if(mtrac_verbose) printf("allocate %lu bytes for <%s> in file %s at line %d: ", size, name, file, line);
	void *p = (*system_malloc)(sizeof(mtrac) + size + sizeof(unsigned long));
	if(mtrac_verbose) printf("%p\n", !mtrac_blank_pointers ? p : (void *)0xb00);
	mtrac *m = p;
	if(mtrac_limit < mtrac_total + size) {
		fprintf(stderr, "\nmemory: violating memory limit (%lu < %luk + %lu) for %s %s %d.\n",
			mtrac_limit, mtrac_total, size, name, file, line);
		exit(46);
	}
	if(!p) {
		fprintf(stderr, "\nmemory: out of memory (%luk + %lu) for %s %s %d.\n",
			mtrac_total, size, name, file, line);
		exit(137);
	}
	m->magic = mtrac_magic;
	m->index = mtrac_action;
	m->name = name;
	m->file = file;
	m->line = line;
	m->size = size;
	m->free = false;
	m->free_name = null;
	m->free_file = null;
	m->free_line = 0;
	m->free_action = 0;
	m->next = null;
	if(!mtrac_first) mtrac_first = m;
	m->previous = mtrac_last;
	if(mtrac_last) mtrac_last->next = m;
	mtrac_last = m;
	m->magic2 = mtrac_magic;
	*(unsigned long *)(p + sizeof(mtrac) + size) = mtrac_magic;

	mtrac_total += size;
	mtrac_allocated += size;
	mtrac_allocations++;
	mtrac_count++;
	if(mtrac_total > mtrac_max_total) mtrac_max_total = mtrac_total;
	if(mtrac_count > mtrac_max_count) mtrac_max_count = mtrac_count;

	return p + sizeof(mtrac);
}

void *_mtrac_strdup(const char *string, char *name, char *file, int line) {
	if(!string) string = "";
	char *s = _mtrac_malloc(strlen(string) + 1, name, file, line);
	strcpy(s, string);
	return s;
}

// frees input and replaces with result.
char *_mtrac_dupcat(const char *sep, ...) {
	va_list ap;
	va_start(ap, sep);
	char *add = va_arg(ap, char *);
	char *buf = null;
	int lsep = strlen(sep);
	int lbuf = 1;
	while(add) {
		lbuf += lsep + strlen(add);
		char *t = mtrac_malloc(lbuf);
		if(!t) { fprintf(stderr, "out of memory %s %d", __FILE__, __LINE__); exit(137); }
		if(buf) strcpy(t, buf); else *t = 0;
		strcat(t, add);
		if(buf) mtrac_free(buf);
		buf = t;
		add = va_arg(ap, char *);
	}
	va_end(ap);
	return buf ? buf : mtrac_strdup("");
}

void _mtrac_free(void *q, char *name, char *file, int line) {

	mtrac_action++;
	if(mtrac_verbose) printf("free <%s> [%p] in file %s at line %d\n", name, !mtrac_blank_pointers ? q : (void *)0xb00, file, line);

	if(!q) {
		fprintf(stderr, "\nmemory: (action %d) null pointer handed to free as '%s' at file %s at line %d.\n",
		mtrac_action, name, file, line);
		exit(48);
	}
	void *p = q - sizeof(mtrac);
	mtrac *m = p;
	if(m->magic != mtrac_magic) {
		fprintf(stderr, "\nmemory: (action %d) wild %s pointer handed to free at file %s at line %d.\n",
		mtrac_action, name, file, line);
		exit(49);
	}
	if(m->magic2 != mtrac_magic) {
		fprintf(stderr, "\nmemory: (action %d) damaged head of %s pointer handed to free at file %s at line %d.\n",
		mtrac_action, name, file, line);
		exit(50);
	}
	unsigned long *al = (unsigned long *)(p + sizeof(mtrac) + m->size); assert(((void *)al) - p == m->size + sizeof(mtrac)); // alignment
	if(*(unsigned long *)(p + sizeof(mtrac) + m->size) != mtrac_magic)
		{ fprintf(stderr, "\nmemory: (action %d) damaged end of pointer (#%d) handed to free as '%s' at file %s at line %d. "
			"Allocated %lu bytes as '%s' in %s at line %d. Damaged magic: %lx, expected %lx\n",
			mtrac_action, m->index, name, file, line, m->size, m->name, m->file, m->line, *(unsigned long *)(p + m->size), mtrac_magic); exit(51); }
	if(m->free) {
		fprintf(stderr, "\nmemory: (action %d) previously freed %s pointer (#%d) handed to free at file %s at line %d. "
			"Allocated %lu bytes as '%s' in %s at line %d. Freed as '%s' in %s at line %d as memory action #%d.\n",
			mtrac_action, name, m->index, file, line, m->size, m->name, m->file, m->line, m->free_name, m->free_file,
			m->free_line, m->free_action);
		exit(52);
	}
	if(mtrac_count < 1) {
		fprintf(stderr, "\nmemory: (action %d) allocation undercount (more frees than allocations) freeing %s at file %s at line %d. "
			"Allocated %lu bytes as '%s' in %s at line %d.\n", mtrac_action, name, file, line, m->size, m->name, m->file, m->line);
		exit(53);
	}

	assert(m->next || m == mtrac_last);
	assert(m->previous || m == mtrac_first);

	/* ok: free */
	mtrac_total -= m->size;
	mtrac_freed += m->size;
	mtrac_frees++;
	mtrac_count--;

	/* take out of list of remaining active allocations */
	if(m->previous) m->previous->next = m->next;
	if(m->next) m->next->previous = m->previous;
	if(m == mtrac_first) mtrac_first = m->next;
	if(m == mtrac_last) mtrac_last = m->previous;

	m->free_action = mtrac_action;
	m->free_name = name;
	m->free_file = file;
	m->free_line = line;
	if(mtrac_really_free) (*system_free)(p);
}

void mtrac_stats() {

	mtrac_action++;
	printf("\n	Dynamic Allocation Summary\n\t--------------------------\n");
	printf("	total allocation: %12d count %12lu bytes\n", mtrac_allocations, mtrac_allocated);
	printf("	total freed     : %12d count %12lu bytes\n", mtrac_frees, mtrac_freed);
	printf("	total remain    : %12d count %12lu bytes\n", mtrac_count, mtrac_total);
	printf("	max allocation  : %12d count %12lu bytes\n", mtrac_max_count, mtrac_max_total);
	printf("	total actions   : %12d count\n", mtrac_action);
	printf("	set limit       :                    %12lu bytes\n\n", mtrac_limit);
}

void mtrac_dump() {

	mtrac_action++;
	printf("\n	Remaining Dynamic Allocations\n\t-----------------------------\n");
	mtrac *m = mtrac_first;
	if(!m) printf("	none.\n");
	while(m) {
		void *p = m;
		void *q = p + sizeof(mtrac);
		if(m->magic != mtrac_magic) { fprintf(stderr, "\nmemory: (action %d) wild pointer traversed.\n", mtrac_action); exit(54); }
		if(m->magic2 != mtrac_magic) { fprintf(stderr, "\nmemory: (action %d) damaged head of pointer traversed.\n", mtrac_action); exit(55); }
		unsigned long *al = (unsigned long *)(p + sizeof(mtrac) + m->size); assert(((void *)al) - p == m->size + sizeof(mtrac)); // alignment
		if(*(unsigned long *)(p + sizeof(mtrac) + m->size) != mtrac_magic) {
			fprintf(stderr, "\nmemory: (action %d) damaged end of pointer (#%d) traversed. "
				"Allocated %lu bytes as '%s' in %s at line %d. Damaged magic: %lx, expected %lx\n",
				mtrac_action, m->index, m->size, m->name, m->file, m->line, *(unsigned long *)(p + m->size), mtrac_magic);
			exit(56);
		}
		printf("	Allocation #%3d: <%s> %12lu bytes, file %s, line %d	%s\n",
				m->index, m->name, m->size, m->file, m->line,
				strstr(mtrac_printable, m->name) ? (char *)q : "");
		m = m->next;
	}
	printf("\n");
}

int mtrac_check() {
	mtrac_action++;
	if(mtrac_count || mtrac_total) {
		fprintf(stderr, "\nmemory: %d unfreed dynamic memory allocations of %lu bytes total remain.\n", mtrac_count, mtrac_total);
		mtrac_stats();
		mtrac_dump();
		if(mtrac_count || mtrac_total)
			exit(57);
	} else {
		if(mtrac_verbose || opt_memory || opt_verbose || opt_debug)
			printf("• memory is clean\n");
	}
	return true;
}

// frees input and replaces with result.
char **_mtrac_concat(char *file, int line, int down, int right, char **buf, ...) {
	va_list ap;
	va_start(ap, buf);
	char *add = va_arg(ap, char *);
	while(add) {
		char *t = mtrac_malloc(strlen(*buf) + down + 4 * right + strlen(add) + 1);
		if(!t) { fprintf(stderr, "out of memory %s %d", file, line); exit(137); }
		strcpy(t, *buf);
		while(down > 0) { strcat(t, "\n"); down--; }
		while(right > 0) { strcat(t, "    "); right--; }
		strcat(t, add);
		mtrac_free(*buf);
		*buf = t;
		add = va_arg(ap, char *);
	}
	va_end(ap);
	return buf;
}

 /* add to the gross list of memory allocations to be eventually freed */
void *mtrac_gross(void *rec) {
	element *e = mtrac_malloc(sizeof (element));
	e->payload = rec;
	e->previous = mtrac_gross_list;
	mtrac_gross_list = e;
	return rec;
}

 /* freeing the gross list of memory allocations */
void mtrac_free_gross() {
	element *p, *e = mtrac_gross_list;
	while(e) {
		p = e->previous;
		mtrac_free(e->payload);
		mtrac_free(e);
		e = p;
	}
}

 /* Thanks to Tom Niemann, whose Lex & Yacc tutorial I kept coming back to for
    every restart :-D  https://www.epaperpress.com/lexandyacc/index.html */
