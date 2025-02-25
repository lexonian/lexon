%{
#include "parser.h" // set by -H
%}

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

#define program_vers "0.3 beta 1"
#define grammar_vers "0.2.20 / subset 0.3.9 beta 1 - English / Reyes"
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
void process(char *ltrim, char *skip, char *mtrim, char *pif, char *rtrim);
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
#endif

YYSTYPE yylval;

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

/* two compiler passes (PRE, MAIN), multiple sub scan states */
%x BOFTRIM
%x PRE
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
									 process(" \t", "TERMS PER", " \t", yytext, ": \t"); // make TERMS optional for process ◊
									 concat(&buf, yytext); 
									 concat(&buf, ":"); } // why is the : lost in the scan? (and needs re-adding here)  ◊
^{space}*CLAUSE(:|{space})+{letter}({letter}|{digit}|{space})*	{ D0; if(_lastline==line) _lastline--; freeline(); lineno(); new_lexcom(yytext, yytext);
									 concat(&funclist, ":", yytext, ":"); process(" \t", "CLAUSE", ": \t", yytext, ". \t");
									 concat(&buf, yytext); }
^{space}*INCLUDE{space}*:?{space}*				{ D; freeline(); BEGIN(INCLUDE); }
^{space}*LAW{space}*:?{space}*					{ D; lineno(); concat(&buf, yytext); BEGIN(LAW); }
 ^{space}*{word}{space}*:{space}*				{ D; lineno(); concat(&buf, trim(yytext), ": "); BEGIN(TEXTQUOTE); }
^{space}*PREAMBLE{space}*(:|\.)*{space}*			{ D; lineno(); concat(&buf, trim(yytext), " ‹"); BEGIN(LONGQUOTE); }
^{space}*{word}{space}*						{ D; lineno(); concat(&buf, trim(yytext), " "); }
(\"|“|”){term}(\"|“|”)						{ D; lineno(); process("\"“”", "", "", yytext, "\"“”"); concat(&buf, yytext); lhd=true; }
{space}+                                   			{ D; concat(&buf, " "); }
^(\"|“|”) /* these 2 lines emulate ^[^"“”]: */			{ D; lineno(); concat(&buf, yytext); }
^.	 							{ D0; yyless(0); if(plhd && pretty) freeline(); }
.								{ D; lineno(); concat(&buf, yytext); }
<<EOF>>		        					{ D0; new_lexcom("_pre_", "");
									if(include_done()) BEGIN(PRE);
									else {
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
									if(include_done())
										BEGIN(PRE);
									else {
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

<NAMEQUOTE>{							// ◊ refactor: only used by LEX tag
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
\n                                                              { D; concat(&buf, "\n"); line++; plhd=lhd; lhd=false; }
({space}*\n){3}                                                 { D; concat(&buf, "›.\n\n\n"); line+=3; plhd=lhd; lhd=false; BEGIN(TRIM); }
}

<INCLUDE>{path}/\n						{ D; input(); include(yytext); BEGIN(PRE); }
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
‹								{ D; BEGIN(DESCRIPTION_); }
{scalar}                                                        { D; DX(SCALAR); yylval.Scalar=mtrac_strdup_gross(yytext); return SCALAR; }
 /* //# {hex}								{ D; DX(HEX); yylval.Hex=mtrac_strdup_gross(yytext); return HEX; } */
  /* Keywords (generated from LGF) */
"AUTHOR"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AUTHOR; }
"AUTHORS"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AUTHORS; }
"CLAUSE"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CLAUSE; }
"COMMENT"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return COMMENT; }
"COMMENTS"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return COMMENTS; }
"GENERAL"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return GENERAL; }
"LEX"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return LEX; }
"LEXON"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return LEXON; }
"PER"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PER; }
"PREAMBLE"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PREAMBLE; }
"TERMS"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TERMS; }
"a"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return A; }
"accept"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ACCEPT; }
"accepts"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ACCEPTS; }
"after"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AFTER; }
"afterwards"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AFTERWARDS; }
"all"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ALL; }
"also"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ALSO; }
"amount"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AMOUNT; }
"an"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AN; }
"and"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AND; }
"announced"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ANNOUNCED; }
"appoint"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return APPOINT; }
"appoints"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return APPOINTS; }
"as"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AS; }
"at"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return AT; }
"be"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return BE; }
"been"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return BEEN; }
"being"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return BEING; }
"binary"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return BINARY; }
"certified"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CERTIFIED; }
"certifies"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CERTIFIES; }
"certify"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CERTIFY; }
"coming"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return COMING; }
"contract"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CONTRACT; }
"contracts"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CONTRACTS; }
"current"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return CURRENT; }
"data"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DATA; }
"day"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DAY; }
"days"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DAYS; }
"declare"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DECLARE; }
"declared"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DECLARED; }
"declares"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DECLARES; }
"defined"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return DEFINED; }
"equal"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return EQUAL; }
"equaling"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return EQUALING; }
"escrow"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ESCROW; }
"file"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FILE_; }
"filed"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FILED; }
"files"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FILES; }
"fix"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FIX; }
"fixed"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FIXED; }
"fixes"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FIXES; }
"for"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FOR; }
"from"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return FROM; }
"given"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return GIVEN; }
"grant"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return GRANT; }
"grants"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return GRANTS; }
"greater"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return GREATER; }
"has"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return HAS; }
"herself"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return HERSELF; }
"himself"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return HIMSELF; }
"hour"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return HOUR; }
"hours"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return HOURS; }
"if"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return IF; }
"in"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return IN; }
"incoming"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return INCOMING; }
"into"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return INTO; }
"is"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return IS; }
"itself"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ITSELF; }
"least"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return LEAST; }
"less"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return LESS; }
"lies"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return LIES; }
"may"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MAY; }
"millisecond"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MILLISECOND; }
"milliseconds"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MILLISECONDS; }
"minute"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MINUTE; }
"minutes"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MINUTES; }
"month"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MONTH; }
"months"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MONTHS; }
"myself"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return MYSELF; }
"neither"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NEITHER; }
"new"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NEW; }
"next"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NEXT; }
"no"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NO; }
"nor"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NOR; }
"not"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NOT; }
"notifies"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NOTIFIES; }
"notify"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NOTIFY; }
"now"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return NOW; }
"of"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return OF; }
"off"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return OFF; }
"on"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ON; }
"oneself"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return ONESELF; }
"or"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return OR; }
"ourselves"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return OURSELVES; }
"passed"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PASSED; }
"past"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PAST; }
"pay"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PAY; }
"pays"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PAYS; }
"person"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PERSON; }
"provided"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return PROVIDED; }
"register"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return REGISTER; }
"registers"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return REGISTERS; }
"remainder"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return REMAINDER; }
"repay"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return REPAY; }
"repays"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return REPAYS; }
"respective"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return RESPECTIVE; }
"return"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return RETURN; }
"returns"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return RETURNS; }
"second"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SECOND; }
"seconds"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SECONDS; }
"send"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SEND; }
"sends"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SENDS; }
"signed"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SIGNED; }
"smaller"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SMALLER; }
"so"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return SO; }
"terminate"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TERMINATE; }
"terminates"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TERMINATES; }
"text"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TEXT; }
"than"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THAN; }
"that"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THAT; }
"the"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THE; }
"themself"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THEMSELF; }
"themselves"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THEMSELVES; }
"then"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THEN; }
"there"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THERE; }
"therefor"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THEREFOR; }
"therefore"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THEREFORE; }
"these"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THESE; }
"this"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return THIS; }
"time"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TIME; }
"to"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TO; }
"true"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return TRUE; }
"was"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return WAS; }
"week"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return WEEK; }
"weeks"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return WEEKS; }
"with"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return WITH; }
"year"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YEAR; }
"years"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YEARS; }
"yes"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YES; }
"yet"								{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YET; }
"yourself"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YOURSELF; }
"yourselves"							{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return YOURSELVES; }
{termpart} /* no space to not erron. make it longest match */ { D; syntax("unexpected word (after precompilation, use -P to check)", yytext); }
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
›{space}*\.?({space}*\n)*					{ D; DX(Separator); BEGIN(MAIN); return Separator; }
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
	} else if(opt_grammar) {
		if(opt_verbose || opt_debug) printf("• grammar\n");
		printf("%s\n", owngrm);
	} else if(opt_manual) {
		if(opt_verbose || opt_debug) printf("• manual\n");
		printf("%s\n", manual);
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
    		"hVmuo:rjPWNJi:IUGBY::T::L::KS::F:H:E::n::kbyqfazl::sc::p::t::e::xwCRvQdD::M0123",
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
	char *c = _up;
	bool sep = true;
	while(*c) { if(sep) *c = toupper(*c); sep = *c == '_'; c++; }
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
void process(char *ltrim, char *skip, char *mtrim, char *pif, char *rtrim) {
	pif += strspn(pif, ltrim);
	pif += strlen(skip);
	pif += strspn(pif, mtrim);
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
			while(*--p != ' ')
				if(p < p0) {
					/* would break the line counter: a line did not, as all should, start '.* .*:' */
					fprintf(stderr, "margin scan buffer:\n%s\n\n", buf);
					fprintf(stderr, "parser error at: '%.*s' ...\n", 25, p0);
					exit(31);
				}
			size_t pos = p - buf;
			replace_first_from(&buf, " ", space + margin -1, p);
			p = buf + pos;
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
	char *fdecl = mtrac_strdup("/* action handler (stub) functions */\n");
	char *funcs = mtrac_strdup("/* action handler (stub) functions */\n\n");
	char *tdecl = mtrac_strdup("/* AST walk (stub) functions */\n\n");
	char *templ = mtrac_strdup("/* AST walk (stub) functions */\n\n");
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
		char *no_break_list = ",Type,Symbol,Combination,Combinand,Combinor,Combinator";
		bool no_break = !!strstr(no_break_list, match);
		bool skip = !!strstr(",Type_Term,Body", match);
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
		while(token) { concat(&templ, " + (!!", definition->name, "->", token->string, "?1:0)"); token = token->next; }
		concat(&templ, "));\n");

		/* tree: produce actual node name, for tree display */
		concat(&templ, "/*T*/\t\tif(opt_produce_tree) {\n");
		concat(&templ, "/*T*/\t\t\tif(!(opt_produce_flat && has_more_recursion) && !terse)\n");
		concat(&templ, "/*T*/\t\t\t\t", "padcat(", definition==grammar?"0":"1", ", indent, production, \"",
			definition!=grammar?"↳  ":"   ", "\", color, \"", production_name, "\", off, \" \");\n"); // ↳

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
				if(!succ)
					concat(&templ, "false");
				while(succ) {
					concat(&templ, succ!=start?" || ":"", definition->name, "->", succ->string);
					succ = succ->next;
				}
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
			char *type = lowdup(types->string);
			char *name = lowdup(definition->name);
			concat(&templ, "/*T*/\t\t", stopped?"\t":"", opt_langprefix, "_", type,
				"(production, ",
				definition->name, "->", token->string,
				", indent+irx, ",
				namesake?"false, ":"true, ",
				recursive?"sibbling_follows && skipped":"false", namesake?"|| sibbling":"",
				", subhighlight || opt_values && !!strstr(opt_values, \"", name, "\")",
				", opt_subvalues && !!strstr(opt_subvalues, \"", name, "\")", ");\n",
				"/*T*/\t\t", stopped?"\t":"", "subhighlight = false;\n");
			mtrac_free(type);
			mtrac_free(name);

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
		char *root = mtrac_strdup(""); concat(&root, UP(grammar->name), " *root;");
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
		"/*T*/	extern struct <roottype> *root;\n"
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
	replace(&src, "0.2.20 / subset 0.3.9 beta 1 - English / Reyes", grammar_version);
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


const char *own =

	" /*\n"
	" **	      _      ____   _      ___    _          ___       ___\n"
	" **	     | |    | |_   \\ \\_/  / / \\  | |\\ |     / / \\  __   ) )\n"
	" **	     |_|__  |_|__  /_/ \\  \\_\\_/  |_| \\|     \\_\\_/ (_() _)_)\n"
	" **\n"
	" **\n"
	" **                  Lexon — natural language programming\n"
	" **\n"
	" **     Copyright (C) 2016-24 Henning Diedrich. Licensed to you under\n"
	" **	AGPL3 subject to the conditions described in the file LICENSE.\n"
	" **\n"
	" **	Also see https://www.lexon.org/license-0.3.html\n"
	" **\n"
	" **\n"
	" **\n"
	" **	lexon.l — tokenizer, parser and tree builder.\n"
	" **\n"
	" **	A Lexon compiler is built from this code in two cycles: first a compiler\n"
	" **	compiler compiler is built, using Flex, then gcc. This lexccc is used to\n"
	" **	create from an LGF grammar file a number of inputs to Flex, Bison and\n"
	" **	gcc to build the Lexon compiler from, which processes controlled natural\n"
	" **	language obeying the grammar. See grammar/english.lgf.\n"
	" **\n"
	" **	This code has three parts, it is Flex input in its entirety. The first\n"
	" **	part has declarations. Then follow the regex patterns for the scanner\n"
	" **	generation. The last part are the C functions that handle LGF, LXF and\n"
	" **	Lexon parsing. The parts are separated by %% as Flex requires.\n"
	" */\n"
	"%{\n"
	"\n"
	"/* part I: declarations --------------------------------------------------- */\n"
	"\n"
	"#include <stdlib.h>\n"
	"#include <stdio.h>\n"
	"#include <assert.h>\n"
	"#include <getopt.h>\n"
	"#include <stdarg.h>\n"
	"#include <libgen.h>\n"
	"#include <time.h>\n"
	"#include <ctype.h>\n"
	"#include <unistd.h>\n"
	"#include <limits.h>\n"
	"#include <math.h>\n"
	"\n"
	"#ifndef PATH_MAX\n"
	"#define PATH_MAX 1000\n"
	"#endif\n"
	"\n"
	"#define program_vers \"0.3 beta 1\"\n"
	"#define grammar_vers \"0.2.20 / subset 0.3.9 beta 1 - English / Reyes\"\n"
	"#ifndef CYCLE_2\n"
	"#define program_name \"Lexon grammar compiler\"\n"
	"#define slug program_name \" \" program_vers\n"
	"#else\n"
	"#define program_name \"Lexon compiler\"\n"
	"#define slug program_name \" \" program_vers \", grammar \" grammar_vers\n"
	"#endif\n"
	"const char *program_version = program_vers;\n"
	"char *grammar_version = grammar_vers;\n"
	"\n"
	"#define D mtrac_concat(&lexcoms->value, yytext); D0\n"
	"#define D0 \\\n"
	"	if(strchr(context, '\\n')) { mtrac_free(context); context = mtrac_strdup(yytext); } \\\n"
	"	else { mtrac_concat(&context, yytext); } \\\n"
	"	if(opt_debug_regex) fprintf(stderr, \"matched in mode <%d> line %d  '%s'\\n\", YY_START, __LINE__, xcr(yytext))\n"
	"#define DX(result_) \\\n"
	"	if(opt_debug_mainscan) { \\\n"
	"		fprintf(stderr, \" mode <%d> line %d: '%s' ⟶ - %s\\n\", YY_START, __LINE__, xcr(yytext), #result_); \\\n"
	"	}\n"
	"#define S source(yytext)\n"
	"#define new(type, var) \\\n"
	"	_mtrac_malloc(sizeof(type), #var, __FILE__, __LINE__); \\\n"
	"	if(!var) { fprintf(stderr, \"out of memory %s %d\", __FILE__, __LINE__); exit(137); } \\\n"
	"	memset(var, 0, sizeof(type));\n"
	"#define news(var, size) \\\n"
	"	_mtrac_malloc(size, #var, __FILE__, __LINE__); \\\n"
	"	if(!var) { fprintf(stderr, \"out of memory %s %d\", __FILE__, __LINE__); exit(137); } \\\n"
	"	memset(var, 0, size);\n"
	"\n"
	"#ifndef CYCLE_2\n"
	"typedef int bool;\n"
	"#endif\n"
	"#define false 0\n"
	"#define true 1\n"
	"#define null (void *)0\n"
	"\n"
	"/* prettier and safer wraps */\n"
	"#define concat(var_, ...) _concat(#var_, __FILE__, __LINE__, 0, 0, var_, __VA_ARGS__, null)\n"
	"#define precat(...) _precat(__VA_ARGS__, null)\n"
	"#define padcat(down_, right_, var_, ...) _concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)\n"
	"#define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, false, null, null, #orig_, __FILE__, __LINE__)\n"
	"#define replace_whole_words(orig_, rep_, with_, quote_, unquote_) _replace(orig_, rep_, with_, true, null, true, quote_, unquote_, #orig_, __FILE__, __LINE__)\n"
	"#define replace_first(orig_, rep_, with_) _replace(orig_, rep_, with_, false, null, false, null, null, #orig_, __FILE__, __LINE__)\n"
	"#define replace_first_from(orig_, rep_, with_, from_) _replace(orig_, rep_, with_, false, from_, false, null, null, #orig_, __FILE__, __LINE__)\n"
	"\n"
	"/* prepending Flex' debug output with 'scanner: ' -- this is Flex' own and the above D macro's */\n"
	"#define fprintf(out_, ...) repchr(yytext, '\\n', '$'), fprintf(out_, \"scanner: \" __VA_ARGS__), repchr(yytext, '$', '\\n')\n"
	"\n"
	"\n"
	"void clean_exit();\n"
	"char *walk();\n"
	"void parsargs(int argc, char **argv);\n"
	"void syntax(char *message, char *violation);\n"
	"void yacc_printf(FILE *stream, char *format, ...);\n"
	"char *coredup(char *src);\n"
	"void process(char *ltrim, char *skip, char *mtrim, char *pif, char *rtrim);\n"
	"void process2(char *pif, char *rtrim, char *open, char *close);\n"
	"void include(char *pif);\n"
	"int include_done();\n"
	"void dump_include_stack(char *path);\n"
	"void dump_include_trace(char *path);\n"
	"void delete_include_trace();\n"
	"char **_concat(char *varname, char *file, int line, int down, int right, char **buf, ...);\n"
	"char **_concatnum(char **buf, char *prefix, int number, char *postfix);\n"
	"void _precat(char **buf, ...);\n"
	"char *catdup(char *string, char *append, int(*func)(int));\n"
	"int _replace(char **orig, const char *rep, const char *with, int all, char *from,\n"
	"	bool whole, char *quote, char *unquote, char *origname, char *file, int line);\n"
	"int repchr(char *hay, char s, char r) { char *c = hay; while(*c) { if(*c==s) *c = r; c++; } return 0; }\n"
	"char *filedup(const char *path, const char *dflt);\n"
	"char *str_escape(const char *src, const char *varname);\n"
	"const char *str(int line);\n"
	"const char *literal_symbol(char *token);\n"
	"char *UP(const char *token);\n"
	"char *up(char *token);\n"
	"char *LOW(const char *token);\n"
	"char *SNAKE(const char *token);\n"
	"char *lowdup(const char *token);\n"
	"char *snakedup(const char *token);\n"
	"char *dash_spaced(const char *token);\n"
	"char *snake_spaced(const char *token);\n"
	"char *camel_spaced(const char *token);\n"
	"void lineno();\n"
	"void rump(char **dest, char *filename);\n"
	"char *cutbuf(char *src, char *cut);\n"
	"void precompile();\n"
	"char *trim(char *s);\n"
	"char *contract(char *s);\n"
	"char *unspace(char *s);\n"
	"char *quote_trimmed(const char *token);\n"
	"char **pad(char **s, int to);\n"
	"char *xcr(char *);\n"
	"int chrcnt(char *hay, char needle);\n"
	"void margin();\n"
	"void freeline();\n"
	"void geninfo();\n"
	"void dump_name_list();\n"
	"void help();\n"
	"void setlaw(char *);\n"
	"void emulaws();\n"
	"void dump_laws();\n"
	"\n"
	"char name_homedir[PATH_MAX];\n"
	"char *file_clearname = null;\n"
	"char *file_namepart = null;\n"
	"char *file_pathpart = null;\n"
	"char *file_location = null;\n"
	"FILE *file_fileptr = null;\n"
	"\n"
	"/* The currently selected jurisdiction (can be none). */\n"
	"char *law_name = null;\n"
	"char *law_abbr = null;\n"
	"char *law_ext = null;\n"
	"\n"
	"/* precompilation line counting: it is somewhat involved and abused during pre-compilation\n"
	"   as it can result into pulling two lines into one to join names with whitespace between their\n"
	"   constituent words, before tokenizing */\n"
	"int line = 1;\n"
	"int metaline = 1;\n"
	"int _lastline = 0;\n"
	"char *_lastfile = null;\n"
	"bool lhd = false; // 'line has definition'\n"
	"bool plhd = false; // 'previous line has ..'\n"
	"bool pretty = false;\n"
	"\n"
	"/* line number and file name given in errors during MAIN parse pass, which are prefixed to each line,\n"
	"   put there during precompilation. This, for proper tracking of included files. */\n"
	"char *prec_file = null;\n"
	"int prec_line = 0;\n"
	"char *context = null;\n"
	"\n"
	"/* temp string buffer */\n"
	"char *_xcr = null;\n"
	"\n"
	"/* the code buffers: parsing (except lgf/lxf) is done in-memory after precompilation */\n"
	"char *buf;\n"
	"char *buf2;\n"
	"char *t;\n"
	"char *src; // used by lgf\n"
	"char *keywords;\n"
	"char *funclist; // not used yet\n"
	"\n"
	"/* imbued files */\n"
	"#ifndef CYCLE_2\n"
	"const char *own = \"not set\";\n"
	"const char *owngrm = \"not set\";\n"
	"const char *manual = \"not set\";\n"
	"#else\n"
	"const char *own;\n"
	"const char *owngrm;\n"
	"const char *manual;\n"
	"#endif\n"
	"\n"
	"int nonce = 0;\n"
	"\n"
	"/* list of symbols (names) */\n"
	"typedef struct node {\n"
	"	struct node *prev;\n"
	"	int serial;\n"
	"	char *find;\n"
	"	int find_len;\n"
	"	char *tag;\n"
	"	char *repl;\n"
	"} node;\n"
	"node *symbols = null;\n"
	"\n"
	"int name_count = 0;\n"
	"\n"
	"/* The command line options for the compiler */\n"
	"char *opt_source = null;\n"
	"char *opt_output = null;\n"
	"bool opt_verbose = false;\n"
	"bool opt_quiet = false;\n"
	"bool opt_echo = false;\n"
	"bool opt_precompile = false;\n"
	"bool opt_pre_echo = false;\n"
	"bool opt_names = false;\n"
	"bool opt_jurisdictions = false;\n"
	"bool opt_included_files = false;\n"
	"char *opt_include_path = \"./\";  // (**)\n"
	"bool opt_geninfo = false;\n"
	"bool opt_manual = false;\n"
	"bool opt_instructions = false;\n"
	"bool opt_grammar = false;\n"
	"bool opt_bnf = false;\n"
	"char *opt_yacc = null;\n"
	"bool opt_keywords = false;\n"
	"char *opt_bootstrap = null;\n"
	"char *opt_source_base = null;\n"
	"char *opt_header = null;\n"
	"char *opt_langprefix = \"core\";  // (**)\n"
	"char *opt_template = null;\n"
	"char *opt_samples = null;\n"
	"int opt_max_examples = 0;\n"
	"bool opt_bare = false;\n"
	"bool opt_comment = false;\n"
	"bool opt_lexon_comments = false;\n"
	"bool opt_feedback = false;\n"
	"bool opt_harden = false;\n"
	"char *opt_log = null;\n"
	"char *opt_persistence = null;\n"
	"char *opt_bundle = null;\n"
	"char *opt_email = null;\n"
	"char *opt_signatures = null;\n"
	"int opt_chaining = 0;\n"
	"bool opt_extended = false;\n"
	"bool opt_wipe = false;\n"
	"bool opt_ignore_circular_includes = false;\n"
	"bool opt_ignore_repeat_includes = false;\n"
	"bool opt_memory = false;\n"
	"bool opt_debug = false;\n"
	"bool opt_debug_regex = false;\n"
	"bool opt_debug_scanner = false;\n"
	"bool opt_debug_mainscan = false;\n"
	"bool opt_debug_actions = false;\n"
	"bool opt_debug_tokens = false;\n"
	"bool opt_debug_parser = false;\n"
	"bool opt_debug_generator = false;\n"
	"bool opt_debug_examples = false;\n"
	"bool opt_debug_lists = false;\n"
	"bool opt_debug_dev = false;\n"
	"bool opt_debug_production = false;\n"
	"bool _concat_trace = false;\n"
	"bool opt_debug_time = false;\n"
	"bool opt_help = false;\n"
	"bool opt_debug_allow_double_names = false;\n"
	"bool do_main_pass = true;\n"
	"\n"
	"//# bool opt_run_spheres = false; // #spheres\n"
	"bool opt_produce_tree = false; // #tree\n"
	"bool opt_produce_core = false; // #core\n"
	"bool opt_produce_javascript = false; // #javascript\n"
	"bool opt_produce_solidity = false; // #solidity\n"
	"bool opt_produce_sophia = false; // #sophia\n"
	"\n"
	"bool opt_produce_flat = false;\n"
	"bool opt_produce_terse = false;\n"
	"char *opt_color = null;\n"
	"char *opt_highlight = null;\n"
	"char *opt_symbols = null;\n"
	"char *opt_values = null;\n"
	"char *opt_subvalues = null;\n"
	"\n"
	"char *opt_summarized = null;\n"
	"\n"
	"/* This mechanism preserves the parse cursor in a file\n"
	"   and other context when another file is included. */\n"
	"#define MAX_INCLUDE_DEPTH 20\n"
	"struct _include_stack {\n"
	"	YY_BUFFER_STATE buffer;\n"
	"	char *clearname;\n"
	"	char *namepart;\n"
	"	char *pathpart;\n"
	"	char *location;\n"
	"	FILE *fileptr;\n"
	"	int line;\n"
	"};\n"
	"\n"
	"struct _include_stack include_stack[MAX_INCLUDE_DEPTH];\n"
	"int include_stack_ptr = 0;\n"
	"\n"
	"/* This list keeps track of what file was included. */\n"
	"int include_count = 0;\n"
	"typedef struct _include_trace {\n"
	"	char *from_namepart;\n"
	"	char *from_clearname;\n"
	"	int from_line;\n"
	"	char *include_namepart;\n"
	"	char *include_clearname;\n"
	"	struct _include_trace *next;\n"
	"} include_trace;\n"
	"include_trace *include_trace_start = null;\n"
	"include_trace *include_trace_last = null;\n"
	"\n"
	"/* A list of allowable jurisdictions, their abbreviations, extensions, relationship */\n"
	"typedef struct _law {\n"
	"	char *abbr;\n"
	"	char *name;\n"
	"	char *under;\n"
	"	char *ext;\n"
	"	struct _law *prev;\n"
	"} law;\n"
	"law *laws_last = null;\n"
	"\n"
	"/* grammar definitions for XBNF processing */\n"
	"typedef enum {active, passive, none} mode;\n"
	"typedef enum {personal, factual, neutral} kind;\n"
	"typedef enum {unspaced=false, spaced=true, not_applicable} adjacency;\n"
	"typedef enum {no_pipe=false, with_pipe=true} piped;\n"
	"typedef enum {sort=false, keep=true} ordering;\n"
	"\n"
	"struct word {\n"
	"	char *string;\n"
	"	bool option_start;\n"
	"	bool option_end;\n"
	"	adjacency adjacency;\n"
	"	struct word *next;\n"
	"};\n"
	"\n"
	"struct alternate {\n"
	"	struct word *words;\n"
	"	struct alternate *next;\n"
	"};\n"
	"\n"
	"struct alternation {\n"
	"	char *string;\n"
	"	struct alternate *alternates;\n"
	"	struct alternation *next;\n"
	"};\n"
	"\n"
	"typedef struct _stringlist {\n"
	"	char *string;\n"
	"	bool seal;\n"
	"	struct _stringlist *next;\n"
	"} stringlist;\n"
	"\n"
	"struct rule {\n"
	"	mode mode;\n"
	"	kind kind;\n"
	"	struct word *words;\n"
	"	struct word *keywords;\n"
	"	stringlist *tokens;\n"
	"	struct rule *next;\n"
	"};\n"
	"\n"
	"struct definition {\n"
	"	char *name;\n"
	"	bool important;\n"
	"	struct rule *rules; // the LGF rules, which can result into multiple BNF rules each\n"
	"	struct alternation *alternations;\n"
	"	struct rule *subrules; // the resulting BNF rules, i.e. lines in the Yacc grammar\n"
	"	stringlist *tokens;\n"
	"	stringlist *types;\n"
	"	char *source;\n"
	"	int line;\n"
	"	stringlist *results;\n"
	"	bool simple; // no options and alternates\n"
	"	struct definition *next;\n"
	"};\n"
	"\n"
	"typedef struct _map {\n"
	"	char *key;\n"
	"	char *value;\n"
	"	struct _map *next;\n"
	"} map;\n"
	"\n"
	"\n"
	"struct definition *grammar = null;\n"
	"struct definition **definition = &grammar;\n"
	"struct rule **rule = null;\n"
	"struct word **keyword = null;\n"
	"struct word **word = null;\n"
	"struct alternation **alternation = null;\n"
	"struct alternate **alternate = null;\n"
	"\n"
	"map *lexcoms = null; // list of lexon text chunks as comments\n"
	"stringlist *tokens = null;\n"
	"stringlist *ignores = null;\n"
	"stringlist *predef = null;\n"
	"stringlist *xpredef = null;\n"
	"char *embed;\n"
	"\n"
	"void start_definition(char *scan);\n"
	"void start_rule(mode, kind);\n"
	"void continue_rule();\n"
	"void add_keyword(char *scan);\n"
	"void _add_word(char *scan, bool option_start, bool option_end, adjacency space);\n"
	"void add_word(char *string);\n"
	"bool _add_token(stringlist **tokens, const char *string, stringlist *only,\n"
	"	stringlist *ignores, ordering keep_order, char *var, char *file, int line);\n"
	"void new_lexcom(const char *name, const char *value);\n"
	"const char *get_lexcom(const char *name);\n"
	"bool in_list(stringlist *tokens, const char *string);\n"
	"int count_in_list(stringlist *token, const char *string);\n"
	"void delete_stringlist(stringlist *list);\n"
	"void delete_node_list(node *list);\n"
	"void delete_map(map *map);\n"
	"void start_option(adjacency);\n"
	"void end_option(adjacency);\n"
	"void start_alternation(char *scan);\n"
	"void start_alternate();\n"
	"void end_rule();\n"
	"void add_embed(char *s);\n"
	"void produce_grammar(struct definition *definition);\n"
	"void produce_examples(stringlist **result, int depth, struct word *word,\n"
	"	struct definition *grammar, char *contract_name, char *clause_name,\n"
	"	char *last_defined, bool *separated, int *names, int *texts, char *check,\n"
	"	int *count, int fuse);\n"
	"char *foobar(int);\n"
	"char *blind(int n);\n"
	"void write_examples(stringlist *example, int count);\n"
	"void produce_extension(struct definition *definition);\n"
	"void produce_tokens(stringlist *result, stringlist *tokens);\n"
	"void produce_rule(stringlist *result, struct definition *definition,\n"
	"	struct rule *rule, struct word *word, struct word *pickup,\n"
	"	adjacency space, char *prefix, bool extension);\n"
	"stringlist *new_result(stringlist *result, char *string, piped add_pipe);\n"
	"stringlist *new_result_dup(stringlist *result, char *string, piped add_pipe);\n"
	"stringlist *listcat(stringlist *head, stringlist *tail);\n"
	"bool pin_list(stringlist *list, stringlist *needle);\n"
	"void delete_definitions(struct definition *definitions);\n"
	"void delete_laws();\n"
	"const char *yacc_stub();\n"
	"const char *walk_stub();\n"
	"void prepfile(char *outfile, char *header, char *bootstrap, char *grammar_file, char *lex);\n"
	"void source(char *s);\n"
	"\n"
	"/* #tree and #core code production */\n"
	"char *opening_bracket = \"(\";\n"
	"char *closing_bracket = \")\";\n"
	"bool bracket_just_closed = false;\n"
	"\n"
	"/* alternate memory management */\n"
	"void *(*system_malloc)(size_t) = &malloc;\n"
	"void (*system_free)(void *) = &free;\n"
	"#define MEMORY_CHECKS\n"
	"#ifdef MEMORY_CHECKS\n"
	"#define mtrac_malloc(size_) _mtrac_malloc(size_, \"[unknown]\", __FILE__, __LINE__)\n"
	"#define mtrac_strdup(string_) _mtrac_strdup(string_, \"[unknown]\", __FILE__, __LINE__)\n"
	"#define mtrac_strdup_gross(string_) mtrac_gross(_mtrac_strdup(string_, \"[unknown]\", __FILE__, __LINE__))\n"
	"#define mtrac_concat(...) _mtrac_concat(__FILE__, __LINE__, 0, 0, __VA_ARGS__, null)\n"
	"#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)\n"
	"#else\n"
	"#define mtrac_malloc(size_) malloc(size_)\n"
	"#define mtrac_strdup(string_) strdup(string_)\n"
	"#define mtrac_strdup_gross(string_) strdup(string_)\n"
	"#define mtrac_concat(var_, ...) _concat(0, 0, var_, __VA_ARGS__, null)\n"
	"#define mtrac_free(var_) free(var_)\n"
	"#endif\n"
	"\n"
	"#define add_token(tokens_, string_, only_, ignores_, keep_order_) \\\n"
	"	_add_token(tokens_, string_, only_, ignores_, keep_order_, #tokens_, __FILE__, __LINE__)\n"
	"void *_mtrac_malloc(size_t size, char *name, char *file, int line);\n"
	"void *_mtrac_strdup(const char *string, char *name, char *file, int line);\n"
	"char *_mtrac_dupcat(const char *string, ...);\n"
	"void _mtrac_free(void *p, char *name, char *file, int line);\n"
	"char **_mtrac_concat(char *file, int line, int down, int right, char **buf, ...);\n"
	"void mtrac_stats();\n"
	"void mtrac_dump();\n"
	"int mtrac_check();\n"
	"size_t mtrac_limit = 1000000000; // ◊ make optional\n"
	"bool mtrac_really_free = true;\n"
	"bool mtrac_verbose = false;\n"
	"bool mtrac_blank_pointers = false;\n"
	"char *mtrac_printable = \"*stringlist,*word,*alternation,*definition\";\n"
	"void *mtrac_gross(void *rec);\n"
	"void mtrac_free_gross();\n"
	"\n"
	"/* stub tokens for 1st cycle (lexccc compiler compiler). They are replaced by\n"
	"   the yacc-generated header for the 2nd (full lexon compiler). */\n"
	"\n"
	"#ifndef YY_YY_LEXC_TAB_H_INCLUDED\n"
	"# define YY_YY_LEXC_TAB_H_INCLUDED\n"
	"\n"
	"/* Debug traces.  */\n"
	"#ifndef YYDEBUG\n"
	"# define YYDEBUG 0\n"
	"#endif\n"
	"#if YYDEBUG\n"
	"extern int yydebug;\n"
	"#endif\n"
	"\n"
	"#ifndef YYTOKENTYPE\n"
	"#define YYTOKENTYPE\n"
	"  enum yytokentype\n"
	"  {\n"
	"    YYEMPTY = -2,\n"
	"    YYEOF = 0,\n"
	"    YYerror = 256,\n"
	"    YYUNDEF = 257,\n"
	"    Colon = 258,\n"
	"    Comma = 259,\n"
	"    Dash = 260,\n"
	"    Percent = 261,\n"
	"    Period = 262,\n"
	"    Quote = 263,\n"
	"    Semicolon = 264,\n"
	"    Separator = 265,\n"
	"    DESCRIPTION = 266,\n"
	"    HEX = 267,\n"
	"    NAME = 268,\n"
	"    SCALAR = 269\n"
	"  };\n"
	"  typedef enum yytokentype yytoken_kind_t;\n"
	"#endif\n"
	"\n"
	"/* Value type.  */\n"
	"#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED\n"
	"union YYSTYPE\n"
	"{\n"
	"	char *Name;\n"
	"	char *Description;\n"
	"	char *Scalar;\n"
	"	char *Hex;\n"
	"};\n"
	"typedef union YYSTYPE YYSTYPE;\n"
	"# define YYSTYPE_IS_TRIVIAL 1\n"
	"# define YYSTYPE_IS_DECLARED 1\n"
	"#endif\n"
	"\n"
	"YYSTYPE yylval;\n"
	"\n"
	"int yyparse (void);\n"
	"\n"
	"#endif /* !YY_YY_LEXC_TAB_H_INCLUDED  */\n"
	"%}\n"
	"\n"
	"\n"
	"/* part II: scanner ------------------------------------------------------ */\n"
	"\n"
	"\n"
	"/* speed-up: */\n"
	"%option never-interactive\n"
	"\n"
	"%option case-insensitive\n"
	"\n"
	" /* parse character patterns */\n"
	"quote	 [\"]\n"
	"digit    [0-9]\n"
	"scalar   [-]?[0-9]+\n"
	"hex      0?[xX][0-9a-fA-F]+\n"
	"letter   [A-Za-z]\n"
	"wordpart ['-]\n"
	"word	 [A-Za-z']([A-Za-z'-]*[A-Za-z'])?\n"
	"token	 [A-Za-z0-9'_]([A-Za-z0-9'_-]*[A-Za-z0-9'_])?\n"
	"spaced   [A-Za-z0-9'_][ ](([A-Za-z0-9'_-][ ])*[A-Za-z0-9'_])?\n"
	"term	 [A-Za-z]([A-Za-z0-9/' -]*[A-Za-z0-9'])?\n"
	"termpart [A-Za-z]([A-Za-z0-9/'-]*[A-Za-z0-9'])?\n"
	"path     [A-Za-z./\\\\_-]([A-Za-z0-9./:\\\\' _-]*[A-Za-z0-9'_-])?\n"
	"lawext   [A-Za-z .'()/-]+\n"
	"interpunctuation [,;.:!?()/\\\\'-]+\n"
	"percents [%]\n"
	"brackets [\\[\\]]\n"
	"space	 [ \\t]\n"
	"white	 [ \\t\\n]\n"
	"\n"
	"/* two compiler passes (PRE, MAIN), multiple sub scan states */\n"
	"%x BOFTRIM\n"
	"%x PRE\n"
	"%s MAIN\n"
	"\n"
	"%x TRIM\n"
	"%x LAW\n"
	"%x INCLUDE\n"
	"%x LINENO\n"
	"%x NAME_\n"
	"%x DESCRIPTION_\n"
	"%x EXPLANATION_\n"
	"%x NAMEQUOTE\n"
	"%x TEXTQUOTE\n"
	"%x LONGQUOTE\n"
	"\n"
	"/* grammar parsing */\n"
	"%x LGF\n"
	"\n"
	"/* extension parsing */\n"
	"%x LXF\n"
	"%x EMBED\n"
	"\n"
	"\n"
	"%%\n"
	"\n"
	" if(YY_START==INITIAL) BEGIN ((opt_bnf || opt_yacc || opt_keywords || opt_template || opt_bootstrap || opt_samples ? LGF : BOFTRIM));\n"
	"\n"
	" /* precompilation marks variable names with « »; to this end normalizes whitespace to allow\n"
	"    for the liberal use of tabs and newlines even within variable names.\n"
	"    At the ocassion, double newline (which semantically equal '.') is also normalized. */\n"
	"\n"
	"<PRE>{\n"
	"GRAMMAR{space}*:?{space}*					{ D; BEGIN(LXF); }\n"
	"LGF{space}*:?{space}*						{ D; BEGIN(LGF); }\n"
	"({space}*\\n){2}							{ D; lineno(); concat(&buf, \"\\n\\n\"); line+=2; plhd=lhd=false; BEGIN(TRIM); }\n"
	"{space}*\\.{space}*\\n						{ D; lineno(); concat(&buf, \".\\n\"); line++; plhd=lhd; lhd=false; BEGIN(TRIM); }\n"
	"{space}*,{space}*\\n						{ D; lineno(); concat(&buf, \",\\n\"); line++; plhd=lhd=false; }\n"
	"{space}*;{space}*\\n						{ D; lineno(); concat(&buf, \";\\n\"); line++; plhd=lhd=false; }\n"
	"{space}*:{space}*\\n						{ D; lineno(); concat(&buf, \":\\n\"); line++; plhd=lhd=false; BEGIN(TRIM); }\n"
	"^{space}*\\n  /* under, after include */				{ D;           concat(&buf, \"\\n\"); line++; plhd=lhd; lhd=false; }\n"
	"{space}*\\n							{ D;           concat(&buf, \" \"); _lastline=++line; }\n"
	"^{space}*LEX(:|{space})+					{ D; if(_lastline==line) _lastline--;\n"
	"								     freeline(); lineno(); concat(&buf, trim(yytext), \": \"); BEGIN(NAMEQUOTE); }\n"
	"^{space}*OPERATING{space}+AGREEMENT{space}*(OF)*(:|{space})+	{ D; if(_lastline==line) _lastline--;\n"
	"								     freeline(); lineno(); concat(&buf, trim(yytext), \": \"); BEGIN(NAMEQUOTE); }\n"
	"^{space}*(TERMS)?{space}+PER{space}+{letter}({letter}|{digit}|{space})*:	{ D0; if(_lastline==line) _lastline--; freeline(); lineno(); new_lexcom(yytext, yytext);\n"
	"									 process(\" \\t\", \"TERMS PER\", \" \\t\", yytext, \": \\t\"); // make TERMS optional for process ◊\n"
	"									 concat(&buf, yytext); \n"
	"									 concat(&buf, \":\"); } // why is the : lost in the scan? (and needs re-adding here)  ◊\n"
	"^{space}*CLAUSE(:|{space})+{letter}({letter}|{digit}|{space})*	{ D0; if(_lastline==line) _lastline--; freeline(); lineno(); new_lexcom(yytext, yytext);\n"
	"									 concat(&funclist, \":\", yytext, \":\"); process(\" \\t\", \"CLAUSE\", \": \\t\", yytext, \". \\t\");\n"
	"									 concat(&buf, yytext); }\n"
	"^{space}*INCLUDE{space}*:?{space}*				{ D; freeline(); BEGIN(INCLUDE); }\n"
	"^{space}*LAW{space}*:?{space}*					{ D; lineno(); concat(&buf, yytext); BEGIN(LAW); }\n"
	" /* ---> 2ND CYCLE LGF GENERATED TYPE NAMES HERE ---> */\n"
	" /* <--- TO HERE <--- */\n"
	"^{space}*{word}{space}*:{space}*				{ D; lineno(); concat(&buf, trim(yytext), \": \"); BEGIN(TEXTQUOTE); }\n"
	"^{space}*PREAMBLE{space}*(:|\\.)*{space}*			{ D; lineno(); concat(&buf, trim(yytext), \" ‹\"); BEGIN(LONGQUOTE); }\n"
	"^{space}*{word}{space}*						{ D; lineno(); concat(&buf, trim(yytext), \" \"); }\n"
	"(\\\"|“|”){term}(\\\"|“|”)						{ D; lineno(); process(\"\\\"“”\", \"\", \"\", yytext, \"\\\"“”\"); concat(&buf, yytext); lhd=true; }\n"
	"{space}+                                   			{ D; concat(&buf, \" \"); }\n"
	"^(\\\"|“|”) /* these 2 lines emulate ^[^\"“”]: */			{ D; lineno(); concat(&buf, yytext); }\n"
	"^.	 							{ D0; yyless(0); if(plhd && pretty) freeline(); }\n"
	".								{ D; lineno(); concat(&buf, yytext); }\n"
	"<<EOF>>		        					{ D0; new_lexcom(\"_pre_\", \"\");\n"
	"									if(include_done()) BEGIN(PRE);\n"
	"									else {\n"
	"										precompile();\n"
	"										if(do_main_pass) {\n"
	"											BEGIN(MAIN);\n"
	"											yy_delete_buffer(YY_CURRENT_BUFFER);\n"
	"											YY_CURRENT_BUFFER_LVALUE = NULL;\n"
	"											yy_scan_string(buf);\n"
	"										} else\n"
	"											return 0;\n"
	"									} \n"
	"								} // (*)\n"
	"}\n"
	"\n"
	"<BOFTRIM>{\n"
	"^{space}+                                                       { D; }\n"
	"\\n                                                              { D; line++; }\n"
	".                                                               { D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }\n"
	"<<EOF>>                                                         { D; syntax(\"empty file (or only whitespace)\", yytext); }\n"
	"}\n"
	"\n"
	"<TRIM>{\n"
	"^{space}+							{ D; }\n"
	"\\n								{ D; if(!pretty) concat(&buf, \"\\n\"); line++; }\n"
	"^.								{ D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }\n"
	".								{ D0; yyless(0); BEGIN(PRE); yy_set_bol(true); }\n"
	"<<EOF>>				  				{ D0; new_lexcom(\"_pre_\", \"\");\n"
	"									if(include_done())\n"
	"										BEGIN(PRE);\n"
	"									else {\n"
	"										precompile();\n"
	"										if(do_main_pass) {\n"
	"											BEGIN(MAIN);\n"
	"											yy_delete_buffer(YY_CURRENT_BUFFER);\n"
	"											YY_CURRENT_BUFFER_LVALUE = NULL;\n"
	"											yy_scan_string(buf);\n"
	"										} else\n"
	"											return 0;\n"
	"									} \n"
	"								} // (*)\n"
	"\n"
	"}\n"
	"\n"
	"<NAMEQUOTE>{							// ◊ refactor: only used by LEX tag\n"
	"{letter}({letter}|{digit}|{space})*				{ D; process2(yytext, \". \\t\", \"«\", \"»\"); concat(&buf, yytext); BEGIN(PRE); }\n"
	".								{ D; syntax(\"unexpected character in name\", yytext); }\n"
	"\\n								{ D; syntax(\"unexpected end of line instead of name\", \"\"); }\n"
	"<<EOF>>								{ D; syntax(\"unexpected end of file instead of name\", yytext); }\n"
	"}\n"
	"\n"
	"<TEXTQUOTE>{\n"
	"{space}+                                                        { D; }\n"
	"\\.                                                              { D; }\n"
	"[^ \\t.\\n].+							{ D; concat(&buf, \"‹\", yytext, \"›.\"); }\n"
	"{space}*\\n		/* used to be \\.*{space}*\\n */		{ D; concat(&buf, \"\\n\"); line++; plhd=lhd; lhd=false; BEGIN(TRIM); }\n"
	"}\n"
	"\n"
	"<LONGQUOTE>{\n"
	".*                                                              { D; concat(&buf, yytext); }\n"
	"\\n                                                              { D; concat(&buf, \"\\n\"); line++; plhd=lhd; lhd=false; }\n"
	"({space}*\\n){3}                                                 { D; concat(&buf, \"›.\\n\\n\\n\"); line+=3; plhd=lhd; lhd=false; BEGIN(TRIM); }\n"
	"}\n"
	"\n"
	"<INCLUDE>{path}/\\n						{ D; input(); include(yytext); BEGIN(PRE); }\n"
	"<INCLUDE>.							{ D; syntax(\"unexpected character in include filename and path\", yytext); }\n"
	"<INCLUDE>\\n							{ D; syntax(\"unexpected end of line instead of include filename and path\", \"\"); }\n"
	"<INCLUDE><<EOF>>						{ D; syntax(\"unexpected end of file instead of include filename and path\", yytext); }\n"
	"\n"
	"<LAW>{lawext}/\\n						{ D; input(); concat(&buf, yytext); setlaw(yytext); BEGIN(PRE); }\n"
	"<LAW>.								{ D; syntax(\"unexpected character in jurisdiction tag\", yytext); }\n"
	"<LAW>\\n								{ D; syntax(\"unexpected end of line instead of jurisdiction tag\", \"\"); }\n"
	"<LAW><<EOF>>							{ D; syntax(\"unexpected end of file in jurisdiction tag\", yytext); }\n"
	"\n"
	"\n"
	" /* MAIN */\n"
	"\n"
	"<MAIN>{\n"
	"^({letter}|{digit}|[ .])+[ ][ ]/{digit} 			{ D; mtrac_free(prec_file); prec_file = trim(mtrac_strdup(yytext));\n"
	"									if(opt_debug_mainscan) printf(\"file %s \", yytext); BEGIN(LINENO); }\n"
	":								{ D; DX(Colon); return Colon; }\n"
	",								{ D; DX(Comma); return Comma; }\n"
	";								{ D; DX(Semicolon); return Semicolon; }\n"
	"–								{ D; DX(Dash); return Dash; }\n"
	"[%]								{ D; DX(Percent); return Percent; }\n"
	"(\\\"|“|”)							{ D; DX(Quote); return Quote; }\n"
	"({space}*\\n){2}({space}*\\n)*					{ D; DX(Separator); return Separator; }\n"
	"\\.({space}*\\n)*							{ D; DX(Separator); return Separator; }\n"
	"{white}+							{ D; }\n"
	"«								{ D; BEGIN(NAME_); }\n"
	"‹								{ D; BEGIN(DESCRIPTION_); }\n"
	"{scalar}                                                        { D; DX(SCALAR); yylval.Scalar=mtrac_strdup_gross(yytext); return SCALAR; }\n"
	" /* //# {hex}								{ D; DX(HEX); yylval.Hex=mtrac_strdup_gross(yytext); return HEX; } */\n"
	" /* --> 2ND CYCLE LGF GENERATED KEYWORDS HERE --> */\n"
	"{term}                                                          { D; printf(\" %s\", yytext); }\n"
	" /* <-- TO HERE <-- */\n"
	".								{ D; syntax(\"unexpected character\", yytext); }\n"
	"}\n"
	"\n"
	"<LINENO>{\n"
	"{digit}+/:							{ D; prec_line = atoi(yytext); if(opt_debug_mainscan) printf(\"line %s: \", yytext); }\n"
	":								{ D; BEGIN(MAIN); }\n"
	".								{ D; syntax(\"unexpected character in line number (after precompilation, use -P to check)\",\n"
	"									yytext); }\n"
	"<<EOF>>								{ D; syntax(\"unexpected end of file in line number (after precompilation, use -P to check)\",\n"
	"									yytext); }\n"
	"}\n"
	"\n"
	"<NAME_>{\n"
	"[^»]+								{ D; DX(NAME); yylval.Name=mtrac_strdup_gross(yytext); return NAME; }\n"
	"»								{ D; BEGIN(MAIN); }\n"
	"<<EOF>>								{ D; syntax(\"unexpected end of file - precompiler name quote error\", yytext); }\n"
	"}\n"
	"\n"
	"<DESCRIPTION_>{\n"
	"[^›]+								{ D; DX(DESCRIPTION); yylval.Description=mtrac_strdup_gross(yytext); return DESCRIPTION; }\n"
	"›{space}*\\.?({space}*\\n)*					{ D; DX(Separator); BEGIN(MAIN); return Separator; }\n"
	"<<EOF>>								{ D; syntax(\"unexpected end of file - precompiler description quote error\", yytext); }\n"
	"}\n"
	"\n"
	" /* The LXF patterns are sloppy. whitespace and colons are trimmed off later */\n"
	"\n"
	"<LXF>{\n"
	"^{space}*COMMENT{space}*:?.*/\\n                                 { D; }\n"
	"^{space}*\\/\\/.*/\\n						{ D; }\n"
	"^{space}*#.*/\\n							{ D; }\n"
	"^{space}*javascript{space}*:?.*/\\n				{ D; BEGIN(EMBED); }\n"
	"^{space}*solidity{space}*:?.*/\\n				{ D; BEGIN(EMBED); }\n"
	"^{space}*sophia{space}*:?.*/\\n					{ D; BEGIN(EMBED); }\n"
	"^{space}*{word}{space}*:?{space}*/\\n				{ D; start_definition(yytext); }\n"
	"^{space}*{word}{space}*:{space}*				{ D; start_alternation(yytext); start_alternate(); }\n"
	"^{space}*Someone						{ D; start_rule(active, personal); }\n"
	"^{space}*Somebody						{ D; start_rule(passive, personal); }\n"
	"^{space}*Something						{ D; start_rule(passive, factual); }\n"
	"^{space}*A{space}+Fact						{ D; start_rule(passive, factual); }\n"
	"\\]{space}+\\[							{ D; end_option(spaced); start_option(spaced); }\n"
	"{space}+\\[							{ D; start_option(spaced); }\n"
	"\\[								{ D; start_option(unspaced); }\n"
	"\\]{space}*/\\n							{ D; end_option(spaced); }\n"
	"\\]{space}+							{ D; end_option(spaced); }\n"
	"\\]								{ D; end_option(unspaced); }\n"
	"somebody							{ D; add_keyword(yytext); }\n"
	"party								{ D; add_keyword(yytext); }\n"
	"{word}								{ D; add_word(yytext); }\n"
	",								{ D; start_alternate(); }\n"
	"\\.{space}*\\n							{ D; line++; /* end_rule(); */ }\n"
	"{space}+							{ D; }\n"
	"\\n								{ D; line++; }\n"
	".								{ D; syntax(\"unexpected character\", yytext); }\n"
	"<EMBED><<EOF>>							{ D; produce_extension(grammar); exit(0); yyterminate(); return 0; }\n"
	"}\n"
	"\n"
	"<EMBED>.+							{ D; add_embed(yytext); }\n"
	"<EMBED>\\n							{ D; lineno(); add_embed(yytext); }\n"
	"\n"
	"\n"
	" /* Lexon Grammar Form: precompiling LGF to BNF */\n"
	"\n"
	"<LGF>{\n"
	"^.*Version{space}*.*/\\n		/* grammar version */		{ D; S; mtrac_free(grammar_version);\n"
	"									grammar_version = trim(mtrac_strdup(strstr(yytext, \"Version\") + 7)); }\n"
	"^{space}*\\/\\/.*/\\n		/* comment */			{ D; }\n"
	"^{space}*#.*/\\n			/* comment */			{ D; }\n"
	"^[^ \\t\\n][^:\\n]+{space}*/\\n	/* comment */			{ D; }\n"
	"{space}*or{space}*  /* spaces make it longest pattern */	{ D; S; start_rule(none, neutral); }\n"
	"^{space}*{token}{space}*:?{space}*				{ D; start_definition(yytext); start_rule(none, neutral); S; }\n"
	"^{space}*{spaced}{space}*:?{space}*				{ D; start_definition(yytext); start_rule(none, neutral); S; }\n"
	"{token}{space}*/\\/						{ D; S; add_word(yytext); start_alternation(yytext); }\n"
	"{quote}{token}{quote}{space}*/\\/				{ D; S; add_word(yytext); start_alternation(yytext); }\n"
	"\\/{space}*{token}						{ D; S; start_alternate(); add_word(yytext); }\n"
	"\\/{space}*{quote}{word}{quote}					{ D; S; start_alternate(); add_word(yytext); }\n"
	"{token}								{ D; S; continue_rule(); add_word(yytext); }\n"
	"{quote}{word}{quote}						{ D; S; continue_rule(); add_word(yytext); }\n"
	"{quote}:{quote}							{ D; S; continue_rule(); add_word(\"colon\"); }\n"
	"{quote},{quote}							{ D; S; continue_rule(); add_word(\"comma\"); }\n"
	"{quote}[%]{quote}						{ D; S; continue_rule(); add_word(\"percent\"); }\n"
	"{quote}{interpunctuation}{quote}				{ D; S; continue_rule(); add_word(yytext); }\n"
	"\\]{space}+\\[							{ D; S; end_option(spaced); start_option(spaced); }\n"
	"{space}+\\[							{ D; S; start_option(spaced); }\n"
	"\\[								{ D; S; start_option(unspaced); }\n"
	"\\]{space}*/\\n							{ D; S; end_option(spaced); }\n"
	"\\]{space}+							{ D; S; end_option(spaced); }\n"
	"\\]								{ D; S; end_option(unspaced); }\n"
	"{space}+							{ D; S; }\n"
	"\\n								{ D; S; line++; }\n"
	".								{ D; syntax(\"unexpected character\", yytext); }\n"
	"<<EOF>>								{ D; produce_grammar(grammar); yyterminate(); }\n"
	"}\n"
	"\n"
	"%%\n"
	"\n"
	"\n"
	"/* part III: code --------------------------------------------------------- */\n"
	"\n"
	"\n"
	"#undef fprintf\n"
	"\n"
	"#ifndef WHITEBOX\n"
	"int main(int argc, char **argv) {\n"
	"\n"
	"	clock_t start = clock();\n"
	"\n"
	"	/* print name and version: separated out from other command line handling (parsargs() below) */\n"
	"	int i = argc;\n"
	"	while(i-->0) if(strstr(argv[i], \"-V\") || strstr(argv[i], \"--vers\")) { printf(\"\\n%s\\n\\n\", slug); break; }\n"
	"\n"
	"	/* debug: separated out from other command line handling (parsargs() below) to show args parsing, too */\n"
	"	i = argc;\n"
	"	while(i-->0) if(!strcmp(argv[i], \"-d\") || !strcmp(argv[i], \"--debug\")) { opt_debug = true; break; }\n"
	"\n"
	"	/* setting defaults for stdin. Source file may be set in parseargs() immediately below */\n"
	"	file_clearname = mtrac_strdup(\"stdin\");\n"
	"	file_namepart = mtrac_strdup(\"stdin\");\n"
	"	file_pathpart = mtrac_strdup(\"-\");\n"
	"	file_location = mtrac_strdup(\"-\");\n"
	"	file_fileptr = null;\n"
	"\n"
	"	/* (**) dynamic allocation of command line arg defaults, so they can be blindly freed */\n"
	"	opt_include_path = mtrac_strdup(opt_include_path);\n"
	"	opt_langprefix = mtrac_strdup(opt_langprefix);\n"
	"\n"
	"	/* process command line settings */\n"
	"	parsargs(argc, argv);\n"
	"\n"
	"	/* initialize buffers so they can be blindly freed */\n"
	"	prec_file = mtrac_strdup(\"\");\n"
	"	context = mtrac_strdup(\"\");\n"
	"	keywords = mtrac_strdup(\"\");\n"
	"	funclist = mtrac_strdup(\"\");\n"
	"	buf = mtrac_strdup(\"\");\n"
	"	buf2 = mtrac_strdup(\"\");\n"
	"	src = mtrac_strdup(\"\");\n"
	"\n"
	"	/* ditto for grammar version string */\n"
	"	grammar_version = mtrac_strdup(grammar_version);\n"
	"\n"
	"	/* known, special tokens for LGF */\n"
	"	add_token(&predef, \"Separator\", null, null, keep);\n"
	"	add_token(&predef, \"Comma\", null, null, keep);\n"
	"	add_token(&predef, \"Colon\", null, null, keep);\n"
	"	add_token(&predef, \"Semicolon\", null, null, keep);\n"
	"	add_token(&predef, \"Dash\", null, null, keep);\n"
	"	add_token(&predef, \"Percent\", null, null, keep);\n"
	"	add_token(&predef, \"Quote\", null, null, keep);\n"
	"	add_token(&predef, \"Name\", null, null, keep);\n"
	"	add_token(&predef, \"Description\", null, null, keep);\n"
	"	add_token(&predef, \"Scalar\", null, null, keep);\n"
	"	//# add_token(&predef, \"Hex\", null, null, keep);\n"
	"\n"
	"	/* ignore when building BNF from LGF */\n"
	"	add_token(&ignores, \"Separator\", null, null, keep);\n"
	"	add_token(&ignores, \"Comma\", null, null, keep);\n"
	"	add_token(&ignores, \"Colon\", null, null, keep);\n"
	"	add_token(&ignores, \"Semicolon\", null, null, keep);\n"
	"	add_token(&ignores, \"Dash\", null, null, keep);\n"
	"	add_token(&ignores, \"Percent\", null, null, keep);\n"
	"	add_token(&ignores, \"Quote\", null, null, keep);\n"
	"\n"
	"	/* known, special tokens for LXF */\n"
	"	add_token(&xpredef, \"Separator\", null, null, keep);\n"
	"	add_token(&xpredef, \"Comma\", null, null, keep);\n"
	"	add_token(&xpredef, \"Colon\", null, null, keep);\n"
	"	add_token(&xpredef, \"Semicolon\", null, null, keep);\n"
	"	add_token(&xpredef, \"Dash\", null, null, keep);\n"
	"	add_token(&xpredef, \"Percent\", null, null, keep);\n"
	"	add_token(&xpredef, \"Name\", null, null, keep);\n"
	"	add_token(&xpredef, \"Description\", null, null, keep);\n"
	"	add_token(&xpredef, \"Scalar\", null, null, keep);\n"
	"	//# add_token(&xpredef, \"Hex\", null, null, keep);\n"
	"	add_token(&xpredef, \"Party\", null, null, keep);\n"
	"	add_token(&xpredef, \"Somebody\", null, null, keep);\n"
	"	add_token(&xpredef, \"Someone\", null, null, keep);\n"
	"	add_token(&xpredef, \"Something\", null, null, keep);\n"
	"	add_token(&xpredef, \"Thing\", null, null, keep);\n"
	"\n"
	"	/* initialize comments map */\n"
	"	new_lexcom(\"start\", \"\");\n"
	"\n"
	"	/* emulate reading a law file */\n"
	"	emulaws();\n"
	"\n"
	"	/* main parse actions */\n"
	"	yy_flex_debug = opt_debug_scanner;\n"
	"	if(opt_jurisdictions) {\n"
	"		if(opt_verbose || opt_debug) printf(\"• jurisdictions\\n\");\n"
	"		dump_laws();\n"
	"	} else if(opt_grammar) {\n"
	"		if(opt_verbose || opt_debug) printf(\"• grammar\\n\");\n"
	"		printf(\"%s\\n\", owngrm);\n"
	"	} else if(opt_manual) {\n"
	"		if(opt_verbose || opt_debug) printf(\"• manual\\n\");\n"
	"		printf(\"%s\\n\", manual);\n"
	"	} else if(opt_geninfo || opt_keywords || opt_samples || opt_bootstrap || opt_yacc || opt_bnf || opt_template) {\n"
	"		if(opt_verbose || opt_debug) printf(\"• scanning\\n\");\n"
	"		do_main_pass = false;\n"
	"		while(yylex()); /* 1st cycle ccc uses only the scanner, not a parser */\n"
	"		if(opt_geninfo){\n"
	"			if(opt_verbose || opt_debug) printf(\"• generator info\\n\");\n"
	"			geninfo();\n"
	"		} else if(opt_keywords) {\n"
	"			if(opt_verbose || opt_debug) printf(\"• keywords\\n\");\n"
	"			printf(\"%s\\n\", keywords);\n"
	"		}\n"
	"	} else {\n"
	"#ifndef CYCLE_2\n"
	"		fprintf(stderr, \"this program is only a 1st cycle generator that cannot compile lexon code.\\n\");\n"
	"		exit(3);\n"
	"#else\n"
	"		yydebug = opt_debug_parser;\n"
	"		if(opt_verbose || opt_debug) printf(\"• parsing\\n\");\n"
	"		yyparse(); /* calls yylex() */\n"
	"		if(opt_verbose || opt_debug) printf(\"• walking\\n\");\n"
	"		char *prod = walk();\n"
	"\n"
	"		/* print to screen */\n"
	"		if(!opt_quiet && !opt_output) {\n"
	"			if(opt_verbose || opt_debug)\n"
	"				printf(\"\\nproduct:\\n--------\\n%s\\n\", prod); else printf(\"%s\", prod);\n"
	"		}\n"
	"\n"
	"		/* write to file */\n"
	"		if(opt_output) {\n"
	"			if(opt_verbose || opt_debug) printf(\"• writing\\n\");\n"
	"			/* backup previous output */\n"
	"			if(access(opt_output, F_OK) != -1) {\n"
	"				char *bak = mtrac_malloc(strlen(opt_output) + 1 + 1 + 6 + 4);\n"
	"				sprintf(bak, \"%s-%ld.bak\", opt_output, time(NULL) % 100000);\n"
	"				if(rename(opt_output, bak)) {\n"
	"					fprintf(stderr, \"cant create backup for existing %s. \", opt_output);\n"
	"					perror(bak); exit(1);\n"
	"				}\n"
	"				mtrac_free(bak);\n"
	"			}\n"
	"			/* write */\n"
	"			FILE *out;\n"
	"			if(!(out = fopen(opt_output, \"w\"))) { perror(opt_output); exit(1); }\n"
	"			if(fputs(prod, out) == EOF) {\n"
	"				fprintf(stderr, \"failed to write output \");\n"
	"				perror(opt_output); exit(1);\n"
	"			}\n"
	"			fclose(out);\n"
	"		}\n"
	"\n"
	"		mtrac_free(prod);\n"
	"#endif\n"
	"	}\n"
	"\n"
	"	/* TODO MOVE */\n"
	"	/* clean up * /\n"
	"	yy_delete_buffer(YY_CURRENT_BUFFER); // ? --> sic bec (*)\n"
	"\n"
	"	/ * list precompilation, json for gui, or known laws to screen * /\n"
	"	if(!opt_precompile && !opt_geninfo && !opt_names && !opt_jurisdictions && !opt_included_files)\n"
	"		puts(buf2);\n"
	"	*/\n"
	"\n"
	"	/* time measure */\n"
	"	if(opt_verbose || opt_debug || opt_debug_time) {\n"
	"		clock_t end = clock() ;\n"
	"		double elapsed_time = (end-start) * 1000 / (double)CLOCKS_PER_SEC ;\n"
	"		printf(\"• time: %f ms\\n\", elapsed_time);\n"
	"	}\n"
	"\n"
	"	clean_exit(); // exits exit(0);\n"
	"\n"
	"	return 0;\n"
	"}\n"
	"#endif\n"
	"\n"
	"/* dynamic memory clean up / check */\n"
	"void clean_exit() {\n"
	"\n"
	"	if(_xcr) mtrac_free(_xcr);\n"
	"\n"
	"	mtrac_free(funclist);\n"
	"	mtrac_free(buf);\n"
	"	mtrac_free(buf2);\n"
	"	mtrac_free(src);\n"
	"	mtrac_free(prec_file);\n"
	"	mtrac_free(context);\n"
	"	mtrac_free(keywords);\n"
	"	yylex_destroy(); // Flex scan buffer and stack\n"
	"\n"
	"	delete_stringlist(predef);\n"
	"	delete_stringlist(ignores);\n"
	"	delete_stringlist(xpredef);\n"
	"\n"
	"	delete_laws();\n"
	"	delete_definitions(grammar);\n"
	"	delete_stringlist(tokens);\n"
	"\n"
	"	delete_map(lexcoms);\n"
	"\n"
	"	if(opt_output) mtrac_free(opt_output);\n"
	"	mtrac_free(grammar_version);\n"
	"	if(opt_yacc) mtrac_free(opt_yacc);\n"
	"	if(opt_header) mtrac_free(opt_header);\n"
	"	if(opt_bootstrap) mtrac_free(opt_bootstrap);\n"
	"	mtrac_free(opt_include_path);\n"
	"	mtrac_free(opt_langprefix);\n"
	"	if(opt_log) mtrac_free(opt_log);\n"
	"	if(opt_signatures) mtrac_free(opt_signatures);\n"
	"	if(opt_persistence) mtrac_free(opt_persistence);\n"
	"	if(opt_bundle) mtrac_free(opt_bundle);\n"
	"	if(opt_email) mtrac_free(opt_email);\n"
	"	if(opt_template) mtrac_free(opt_template);\n"
	" 	if(opt_source_base) mtrac_free(opt_source_base);\n"
	" 	if(opt_samples) mtrac_free(opt_samples);\n"
	" 	if(opt_summarized) mtrac_free(opt_summarized);\n"
	"	if(opt_color) mtrac_free(opt_color);\n"
	"	if(opt_highlight) mtrac_free(opt_highlight);\n"
	"	if(opt_symbols) mtrac_free(opt_symbols);\n"
	"	if(opt_values) mtrac_free(opt_values);\n"
	"	if(opt_subvalues) mtrac_free(opt_subvalues);\n"
	"\n"
	"	if(law_name) mtrac_free(law_name);\n"
	"	if(law_abbr) mtrac_free(law_abbr);\n"
	"	if(law_ext) mtrac_free(law_ext);\n"
	"\n"
	"	mtrac_free(file_clearname);\n"
	"	mtrac_free(file_namepart);\n"
	"	mtrac_free(file_pathpart);\n"
	"	mtrac_free(file_location);\n"
	"	fclose(file_fileptr);\n"
	"\n"
	"	delete_include_trace();\n"
	"\n"
	"	delete_node_list(symbols);\n"
	"	mtrac_free_gross();\n"
	"\n"
	"	mtrac_check();\n"
	"\n"
	"	if(opt_verbose || opt_debug) printf(\"• done\\n\\n\");\n"
	"\n"
	"	exit(0);\n"
	"}\n"
	"\n"
	"void parsargs(int argc, char **argv) {\n"
	"    static struct option long_options[] = {\n"
	"	{\"help\",                     no_argument,       null, 'h'},\n"
	"	{\"version\",                  no_argument,       null, 'V'},\n"
	"	{\"manual\",                   no_argument,       null, 'm'},\n"
	"	{\"instructions\",             no_argument,       null, 'u'},\n"
	"	{\"output\",                   required_argument, null, 'o'},\n"
	"	{\"run\",                      no_argument,       null, 'r'},\n"
	"	{\"echo-source\",              no_argument,       null, 'j'},\n"
	"	{\"precompile-only\",          no_argument,       null, 'P'},\n"
	"	{\"echo-precompile\",          no_argument,       null, 'W'},\n"
	"	{\"names\",                    no_argument,       null, 'N'},\n"
	"	{\"jurisdictions\",            no_argument,       null, 'J'},\n"
	"	{\"include-path\",             required_argument, null, 'i'},\n"
	"	{\"included-files\",           no_argument,       null, 'I'},\n"
	"	{\"ui-info\",                  optional_argument, null, 'U'},\n"
	"	{\"grammar\",                  no_argument,       null, 'G'},\n"
	"	{\"bnf\",                      no_argument,       null, 'B'},\n"
	"	{\"parser\",                   optional_argument, null, 'Y'},\n"
	"	{\"template\",                 optional_argument, null, 'T'},\n"
	"	{\"language-prefix\",          optional_argument, null, 'L'},\n"
	"	{\"keywords\",                 no_argument,       null, 'K'},\n"
	"	{\"scanner\",                  optional_argument, null, 'S'},\n"
	"	{\"source-file\",              required_argument, null, 'F'},\n"
	"	{\"header\",                   required_argument, null, 'H'},\n"
	"	{\"examples\",                 optional_argument, null, 'E'},\n"
	"	{\"max-examples\",             optional_argument, null, 'n'},\n"
	"	{\"check\",                    no_argument,       null, 'k'},\n"
	"	{\"bare\",                     no_argument,       null, 'b'},\n"
	"	{\"comment\",                  no_argument,       null, 'y'},\n"
	"	{\"quote-source\",             no_argument,       null, 'q'},\n"
	"	{\"feedback\",                 no_argument,       null, 'f'},\n"
	"	{\"action-lists\",             no_argument,       null, 'a'},\n"
	"	{\"harden\",                   no_argument,       null, 'z'},\n"
	"	{\"log\",                      optional_argument, null, 'l'},\n"
	"	{\"signatures\",               no_argument,       null, 's'},\n"
	"	{\"chaining\",                 optional_argument, null, 'c'},\n"
	"	{\"persistence\",              optional_argument, null, 'p'},\n"
	"	{\"bundle\",                   optional_argument, null, 't'},\n"
	"	{\"email\",                    optional_argument, null, 'e'},\n"
	"	{\"all-auxiliaries\",          no_argument,       null, 'x'},\n"
	"	{\"wipe\",                     no_argument,       null, 'w'},\n"
	"	{\"ignore-circular-includes\", no_argument,       null, 'C'},\n"
	"	{\"ignore-repeat-includes\",   no_argument,       null, 'R'},\n"
	"	{\"verbose\",                  no_argument,       null, 'v'},\n"
	"	{\"no-result\",                no_argument,       null, 'Q'},\n"
	"	{\"debug\",                    no_argument,       null, 'd'},\n"
	"	{\"debug-modules\",            optional_argument, null, 'D'},\n"
	"	{\"memory-check\",             no_argument,       null, 'M'},\n"
	"	/* target languages */\n"
	"	{\"tree\",                     no_argument,       null, '0'}, // #tree\n"
	"	{\"core\",                     no_argument,       null, '1'}, // #core\n"
	"	{\"javascript\",               no_argument,       null, '2'}, // #javascript\n"
	"	{\"solidity\",                 no_argument,       null, '3'}, // #solidity\n"
	"	{\"sophia\",                   no_argument,       null, '4'}, // #sophia\n"
	"//#	{\"spheres\",                  no_argument,       null, '5'}, // #spheres\n"
	"	{\"color\",                    optional_argument, null, 1000},\n"
	"	{\"symbols\",                  optional_argument, null, 1001},\n"
	"	{\"leaves\",                   optional_argument, null, 1002},\n"
	"	{\"subleaves\",                optional_argument, null, 1003},\n"
	"	{\"highlight\",                optional_argument, null, 1004},\n"
	"	{\"flat\",                     no_argument,       null, 1005},\n"
	"	{\"terse\",                    no_argument,       null, 1006},\n"
	"	{null,                       0,                 null,  0 }\n"
	"    };\n"
	"    int c;\n"
	"    int option_index = 0;\n"
	"    opt_summarized = mtrac_strdup(\"\");\n"
	"    while ((c = getopt_long(argc, argv,\n"
	"    		\"hVmuo:rjPWNJi:IUGBY::T::L::KS::F:H:E::n::kbyqfazl::sc::p::t::e::xwCRvQdD::M0123\",\n"
	"		long_options, &option_index)) != -1) {\n"
	"	if(c == '?') { fprintf(stderr, \"parameter error\"); exit(1); }\n"
	"\n"
	"	struct option *o = long_options;\n"
	"	while(o && o->val != c) o++;\n"
	"	assert(o && o->name);\n"
	"	mtrac_concat(&opt_summarized, *opt_summarized?\" \":\"\", \"--\", o->name, \" \", optarg ? optarg : \"\");\n"
	"\n"
	"	int this_option_optind = optind ? optind : 1;\n"
	"	switch (c) {\n"
	"	case 'h':\n"
	"	    if(opt_debug) printf (\"print help and quit: on\\n\");\n"
	"	    opt_help = true;\n"
	"	    help(); // exits\n"
	"	    break;\n"
	"	case 'V':\n"
	"	    exit(0); //handled earlier, in main. case to prevent arg error msg\n"
	"	case 'm':\n"
	"	    if(opt_debug) printf (\"manual listing: on\\n\");\n"
	"	    opt_manual = true;\n"
	"	    break;\n"
	"	case 'u':\n"
	"	    if(opt_debug) printf (\"generate usage instructions: on\\n\");\n"
	"	    opt_instructions = true;\n"
	"	    break;\n"
	"	case 'v':\n"
	"	    if(opt_debug) printf (\"verbose output: on\\n\");\n"
	"	    opt_verbose = true;\n"
	"	    break;\n"
	"	case 'o':\n"
	"	    if(opt_verbose || opt_debug) printf (\"output file: %s\\n\", optarg);\n"
	"	    if(!optarg) {\n"
	"	    	fprintf(stderr, \"output file name missing after -o or --output\\n\");\n"
	"		exit(1);\n"
	"	    }\n"
	"	    assert(!opt_output);\n"
	"	    opt_output = mtrac_strdup(optarg);\n"
	"	    break;\n"
	"	case 'Q':\n"
	"	    if(opt_debug) printf (\"quiet result output: on\\n\");\n"
	"	    opt_quiet = true;\n"
	"	    break;\n"
	"	case 'j':\n"
	"	    if(opt_debug) printf (\"echo source file: on\\n\");\n"
	"	    opt_echo = true;\n"
	"	    break;\n"
	"	 case 'P':\n"
	"	    if(opt_debug) printf (\"precompilation output: on\\n\");\n"
	"	    opt_precompile = true;\n"
	"	    break;\n"
	"	 case 'W':\n"
	"	    if(opt_debug) printf (\"echo precompilation and continue: on\\n\");\n"
	"	    opt_pre_echo = true;\n"
	"	    break;\n"
	"	case 'N':\n"
	"	    if(opt_debug) printf (\"names list output: on\\n\");\n"
	"	    opt_names = true;\n"
	"	    break;\n"
	"	case 'J':\n"
	"	    if(opt_debug) printf (\"jurisdictions list output: on\\n\");\n"
	"	    opt_jurisdictions = true;\n"
	"	    break;\n"
	"	case 'I':\n"
	"	    if(opt_debug) printf (\"included file trace: on\\n\");\n"
	"	    opt_included_files = true;\n"
	"	    break;\n"
	"	case 'U':\n"
	"	    if(opt_debug) printf (\"ui generator info json output: on\\n\");\n"
	"	    opt_geninfo = true;\n"
	"	    break;\n"
	"	case 'G':\n"
	"	    if(opt_debug) printf (\"LGF grammar listing: on\\n\");\n"
	"	    opt_grammar = true;\n"
	"	    break;\n"
	"	case 'B':\n"
	"	    if(opt_debug) printf (\"BNF grammar production output: on\\n\");\n"
	"	    opt_bnf = true;\n"
	"	    break;\n"
	"	case 'Y':\n"
	"	    if(opt_verbose || opt_debug) printf (\"yacc file including BNF grammar production: %s\\n\", optarg ? optarg : \"on (to stdout)\");\n"
	"	    opt_yacc = mtrac_strdup(optarg ? optarg : \"\");\n"
	"	    break;\n"
	"	case 'T':\n"
	"	    if(opt_verbose || opt_debug) printf (\"write walk function template top: %s\\n\", optarg ? optarg : \"on (to stdout)\");\n"
	"	    opt_template = mtrac_strdup(optarg ? optarg : \"\");\n"
	"	    break;\n"
	"	case 'L':\n"
	"	    if(opt_verbose || opt_debug) printf (\"walk function language prefix: %s\\n\", optarg ? optarg : opt_langprefix);\n"
	"	    if(optarg) {\n"
	"		mtrac_free(opt_langprefix);\n"
	"		opt_langprefix = mtrac_strdup(optarg);\n"
	"	    }\n"
	"	    break;\n"
	"	case 'K':\n"
	"	    if(opt_debug) printf (\"lexer tokens / keyword output: on\\n\");\n"
	"	    opt_keywords = true;\n"
	"	    break;\n"
	"	case 'S':\n"
	"	    opt_bootstrap = mtrac_strdup(optarg ? optarg : \"\");\n"
	"	    if(opt_verbose || opt_debug) printf (\"write scanner file to: %s\\n\", optarg ? opt_bootstrap : \"screen\");\n"
	"	    break;\n"
	"	case 'F':\n"
	"       	    if(opt_verbose || opt_debug) printf (\"build scanner based on source file: %s\\n\", optarg ? optarg : \"missing\");\n"
	"	    if(!optarg) {\n"
	"	    	fprintf(stderr, \"source file name missing after -F or --source-file parameter\\n\");\n"
	"		exit(1);\n"
	"	    }\n"
	"	    opt_source_base = mtrac_strdup(optarg);\n"
	"	    break;\n"
	"	case 'H':\n"
	"       	    if(opt_verbose || opt_debug) printf (\"header to include in lexer file: %s\\n\", optarg ? optarg : \"missing\");\n"
	"	    if(!optarg) {\n"
	"	    	fprintf(stderr, \"header file name missing after -H or --header parameter\\n\");\n"
	"		exit(1);\n"
	"	    }\n"
	"	    opt_header = mtrac_strdup(optarg);\n"
	"	    break;\n"
	"	case 'E':\n"
	"	    opt_samples = mtrac_strdup(optarg ? optarg : \"\");\n"
	"	    if(opt_verbose || opt_debug) printf (\"sample Lexon code production from LGF to: %s\\n\", optarg ? opt_samples : \"screen\");\n"
	"	    break;\n"
	"	case 'n':\n"
	"	    opt_max_examples = optarg ? atoi(optarg) : 10;\n"
	"	    if(opt_verbose || opt_debug) printf (\"maximal number of examples to be produced: %d\\n\", opt_max_examples);\n"
	"	    break;\n"
	"	case 'k':\n"
	"	    if(opt_debug) printf (\"check completeness of LGF grammar: on\\n\");\n"
	"	    opt_samples = mtrac_strdup(\"\");\n"
	"	    opt_quiet = true;\n"
	"	    break;\n"
	"	case 'y':\n"
	"	    if(opt_debug) printf (\"comments in grammar production: on\\n\");\n"
	"	    opt_comment = true;\n"
	"	    opt_lexon_comments = true;\n"
	"	    break;\n"
	"	case 'b':\n"
	"	    if(opt_debug) printf (\"generated source is barebones happy path for demonstration: on\\n\");\n"
	"	    opt_bare = true;\n"
	"	    opt_comment = false;\n"
	"	    opt_lexon_comments = false;\n"
	"	    opt_instructions = false;\n"
	"	    opt_feedback = false;\n"
	"	    opt_harden = false;\n"
	"	    if(opt_log) mtrac_free(opt_log), opt_log = null;\n"
	"	    if(opt_signatures) mtrac_free(opt_signatures), opt_signatures = null;\n"
	"	    opt_chaining = 0;\n"
	"	    if(opt_persistence) mtrac_free(opt_persistence), opt_persistence = null;\n"
	"	    if(opt_bundle) mtrac_free(opt_bundle), opt_bundle = null;\n"
	"	    if(opt_email) mtrac_free(opt_email), opt_email = null;\n"
	"	    break;\n"
	"	case 'x':\n"
	"	    if(opt_debug) printf (\"generated source has all auxiliary features: on\\n\");\n"
	"	    opt_bare = false;\n"
	"	    opt_comment = true;\n"
	"	    opt_lexon_comments = true;\n"
	"	    opt_instructions = true;\n"
	"	    opt_feedback = true;\n"
	"	    opt_harden = true;\n"
	"	    if(!opt_log) opt_log = mtrac_strdup(\"log\");\n"
	"	    if(!opt_signatures) opt_signatures = mtrac_strdup(\"*.key\");\n"
	"	    if(!opt_chaining) opt_chaining = 12;\n"
	"	    if(!opt_persistence) opt_persistence = mtrac_strdup(\"state\");\n"
	"	    if(!opt_bundle) opt_bundle = mtrac_strdup(\"contract.tgz\");\n"
	"	    if(!opt_email) opt_email = mtrac_strdup(\"config\");\n"
	"	    break;\n"
	"	case 'f':\n"
	"	    if(opt_debug) printf (\"generated source answers actions with feedback output: on\\n\");\n"
	"	    opt_feedback = true;\n"
	"	    break;\n"
	"	case 'z':\n"
	"	    if(opt_debug) printf (\"generated source checks for wrong input and missing state: on\\n\");\n"
	"	    opt_harden = true;\n"
	"	    break;\n"
	"	case 'l':\n"
	"	    if(opt_log) mtrac_free(opt_log);\n"
	"	    opt_log = mtrac_strdup(optarg ? optarg : \"log\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"generated source writes log of state change to: %s\\n\", opt_log);\n"
	"	    break;\n"
	"	case 's':\n"
	"	    if(opt_signatures) mtrac_free(opt_signatures);\n"
	"	    opt_signatures = mtrac_strdup(optarg ? optarg : \"*.key\");\n"
	"	    if(opt_debug) printf (\"log signatures for state changes, signature file: %s\\n\", opt_signatures);\n"
	"	    // effects --log\n"
	"	    if(!opt_log) opt_log = mtrac_strdup(\"log\");\n"
	"	    break;\n"
	"	case 'c':\n"
	"	    opt_chaining = optarg ? atoi(optarg) : 12;\n"
	"	    if(opt_debug) printf (\"log entries are hash-chained, hash length: %d (64 = full)\\n\", opt_chaining);\n"
	"	    // effects --log\n"
	"	    if(!opt_log) opt_log = mtrac_strdup(\"log\");\n"
	"	    break;\n"
	"	case 'p':\n"
	"	    if(opt_persistence) mtrac_free(opt_persistence);\n"
	"	    opt_persistence = mtrac_strdup(optarg ? optarg : \"state\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"generated source writes state to: %s\\n\", opt_persistence);\n"
	"	    break;\n"
	"	case 't':\n"
	"	    if(opt_bundle) mtrac_free(opt_bundle);\n"
	"	    opt_bundle = mtrac_strdup(optarg ? optarg : \"contract.tgz\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"generated source bundles code, state and log to: %s\\n\", opt_bundle);\n"
	"	    break;\n"
	"	case 'e':\n"
	"	    if(opt_email) mtrac_free(opt_email);\n"
	"	    opt_email = mtrac_strdup(optarg ? optarg : \"config\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"generated source uses email configuration in: %s\\n\", opt_persistence);\n"
	"	    break;\n"
	"	case 'w':\n"
	"	    if(opt_debug) printf (\"wipe older files of same pattern: on\\n\");\n"
	"	    opt_wipe = true;\n"
	"	    break;\n"
	"	case 'i':\n"
	"	    if(opt_verbose || opt_debug) printf (\"include path: %s\\n\", optarg);\n"
	"	    if(!optarg) {\n"
	"	    	fprintf(stderr, \"path missing after -I or --include-path parameter\\n\");\n"
	"		exit(1);\n"
	"	    }\n"
	"	    mtrac_free(opt_include_path);\n"
	"	    opt_include_path = mtrac_strdup(optarg);\n"
	"	    break;\n"
	"	case 'C':\n"
	"	    if(opt_debug) printf (\"ignore circular includes: on\\n\");\n"
	"	    opt_ignore_circular_includes = true;\n"
	"	    break;\n"
	"	case 'R':\n"
	"	    if(opt_debug) printf (\"ignore repeat includes: on\\n\");\n"
	"	    opt_ignore_repeat_includes = true;\n"
	"	    break;\n"
	"	case 'd':\n"
	"	    printf (\"debug output: on\\n\");\n"
	"	    opt_debug = true;\n"
	"	    break;\n"
	"	case 'D':\n"
	"	    if(opt_verbose) printf (\"specific modules debug output: %s\\n\", optarg?optarg:\"all on\");\n"
	"     	    opt_debug_regex = !optarg || strstr(optarg, \"regex\");\n"
	"	    opt_debug_scanner = !optarg || strstr(optarg, \"scanner\");\n"
	"	    opt_debug_mainscan = !optarg || strstr(optarg, \"mainscan\");\n"
	"	    opt_debug_actions = !optarg || strstr(optarg, \"actions\");\n"
	"	    opt_debug_tokens = !optarg || strstr(optarg, \"tokens\");\n"
	"	    opt_debug_parser = !optarg || strstr(optarg, \"parser\");\n"
	"	    opt_debug_lists = !optarg || strstr(optarg, \"lists\");\n"
	"	    opt_debug_generator = !optarg || strstr(optarg, \"generator\");\n"
	"	    opt_debug_examples = !optarg || strstr(optarg, \"examples\");\n"
	"	    opt_debug_production = !optarg || strstr(optarg, \"production\");\n"
	"	    opt_debug_time = !optarg || strstr(optarg, \"time\");\n"
	"	    opt_debug_dev = !optarg || strstr(optarg, \"dev\");\n"
	"	    opt_debug_allow_double_names = !optarg || strstr(optarg, \"allow_double_names\");\n"
	"	    bool fail = optarg && !opt_debug_regex && !opt_debug_scanner && !opt_debug_mainscan && !opt_debug_actions && !opt_debug_tokens && !opt_debug_parser\n"
	"		&& !opt_debug_generator && !opt_debug_examples && !opt_debug_lists && !opt_debug_production && !opt_debug_time && !opt_debug_dev && !opt_debug_allow_double_names;\n"
	"	    if(opt_verbose || fail || (optarg && !strcmp(optarg, \"h\"))) {\n"
	"		    printf (\"module debug regex     : %s   scanned regex pattern results of the scanner (Flex) tokenizing input\\n\",\n"
	"		    	opt_debug_regex     ?\"yes\":\"no \");\n"
	"		    printf (\"module debug scanner   : %s   scanner (Flex) live process trace during input scan (LGF, LXF, LEX)\\n\",\n"
	"		    	opt_debug_scanner   ?\"yes\":\"no \");\n"
	"		    printf (\"module debug mainscan  : %s   token production of scan pass of precompiled code (LEX files only)\\n\",\n"
	"		    	opt_debug_mainscan  ?\"yes\":\"no \");\n"
	"		    printf (\"module debug actions   : %s   rule actions processing new nodes during build up of AST (LEX only)\\n\",\n"
	"		    	opt_debug_actions   ?\"yes\":\"no \");\n"
	"		    printf (\"module debug tokens    : %s   recognized tokens resulting from parser grammar rule match\\n\",\n"
	"		    	opt_debug_tokens    ?\"yes\":\"no \");\n"
	"		    printf (\"module debug parser    : %s   parser (Bison) live shift/reduce and stack trace (LEX files only)\\n\",\n"
	"		    	opt_debug_parser    ?\"yes\":\"no \");\n"
	"		    printf (\"module debug generator : %s   cycle 1 rule prosessing during parser generation (LGF and LXF only)\\n\",\n"
	"		    	opt_debug_generator ?\"yes\":\"no \");\n"
	"		    printf (\"module debug examples  : %s   production of examples based on LGF\\n\",\n"
	"		    	opt_debug_examples  ?\"yes\":\"no \");\n"
	"		    printf (\"module debug lists     : %s   low level list management (LGF, LXF, LEX)\\n\",\n"
	"		    	opt_debug_lists     ?\"yes\":\"no \");\n"
	"		    printf (\"module debug production: %s   print target output module line numbers into the produced code\\n\",\n"
	"		    	opt_debug_production?\"yes\":\"no \");\n"
	"		    printf (\"module debug time      : %s   display total runtime at regulat program exit\\n\",\n"
	"		    	opt_debug_time      ?\"yes\":\"no \");\n"
	"		    printf (\"module debug dev       : %s   varying hot spots (use opt_debug_dev during development)\\n\",\n"
	"		    	opt_debug_dev       ?\"yes\":\"no \");\n"
	"		    printf (\"allow double names     : %s   for grammar test parsing of generated code\\n\",\n"
	"		    	opt_debug_allow_double_names?\"yes\":\"no \");\n"
	"	    }\n"
	"       	    if(fail) {\n"
	"		if(strcmp(optarg, \"h\")) fprintf(stderr, \"no module selected by string '%s'. \", optarg);\n"
	"		fprintf(stderr, \"Use one or more of the names above (e.g. -Dregex,tokens)\\n\");\n"
	"		exit(1);\n"
	"	    }\n"
	"    	    break;\n"
	"	case 'M':\n"
	"	    #ifndef MEMORY_CHECKS\n"
	"	    fprintf(\"memory checks not supported by this build\\n\"), exit(12);\n"
	"	    #endif\n"
	"	    if(opt_debug) printf (\"memory check activated: on\\n\");\n"
	"	    opt_memory = true;\n"
	"	    break;\n"
	"	case '0':\n"
	"	    if(opt_debug) printf (\"abstract syntax tree ouput: on\\n\");\n"
	"	    opt_produce_tree = true;\n"
	"	    break;\n"
	"	case '1':\n"
	"	    if(opt_debug) printf (\"core language ouput: on\\n\");\n"
	"	    opt_produce_core = true;\n"
	"	    break;\n"
	"	case '2':\n"
	"	    if(opt_debug) printf (\"javascript language ouput: on\\n\");\n"
	"	    opt_produce_javascript = true;\n"
	"	    break;\n"
	"	case '3':\n"
	"	    if(opt_debug) printf (\"solidity language ouput: on\\n\");\n"
	"	    opt_produce_solidity = true;\n"
	"	    break;\n"
	"	case '4':\n"
	"	    if(opt_debug) printf (\"sophia language ouput: on\\n\");\n"
	"	    opt_produce_sophia = true;\n"
	"	    break;\n"
	"//#	case '5':\n"
	"//#	    if(opt_debug) printf (\"run spheres: on\\n\");\n"
	"//#	    opt_run_spheres = true;\n"
	"//#	    break;\n"
	"	/* color */\n"
	"	case 1000:\n"
	"       	    if(opt_verbose || opt_debug) printf (\"color: %s\\n\", optarg ? optarg : \"on (bold)\");\n"
	"	    if(opt_color) mtrac_free(opt_color);\n"
	"	    opt_color = mtrac_strdup(\"\"); concat(&opt_color, \"\\033[\", optarg ? optarg : \"1\", \"m\");\n"
	"	    replace(&opt_color, \",\", \";\");\n"
	"	    optarg = null;\n"
	"	    // fall through to symbols, values, subvalues, tokens\n"
	"	/* symbols highlighting */\n"
	"	case 1001:\n"
	"       	    if(opt_verbose || opt_debug) printf (\"symbol highlighting: %s\\n\", optarg ? optarg : \"on (bold)\");\n"
	"	    if(opt_symbols) mtrac_free(opt_symbols);\n"
	"	    opt_symbols = mtrac_strdup(\"\"); concat(&opt_symbols, \"\\033[\", optarg ? optarg : \"36\", \"m\");\n"
	"	    replace(&opt_symbols, \",\", \";\");\n"
	"	    if(c!=1000) break;\n"
	"	/* values highlighting */\n"
	"	case 1002:\n"
	"	    if(opt_values) mtrac_free(opt_values);\n"
	"	    opt_values = mtrac_strdup(optarg ? optarg : \"type,combinator,illocutor\");\n"
	"	    if(!opt_color) opt_color = mtrac_strdup(\"\\033[1m\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"values highlighting: %s\\n\", opt_values);\n"
	"	    if(c!=1000) break;\n"
	"	/* subvalues highlighting */\n"
	"	case 1003:\n"
	"	    if(opt_subvalues) mtrac_free(opt_subvalues);\n"
	"	    opt_subvalues = mtrac_strdup(optarg ? optarg : \"predicate\");\n"
	"	    if(!opt_color) opt_color = mtrac_strdup(\"\\033[1m\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"sub value highlighting: %s\\n\", opt_subvalues);\n"
	"	    if(c!=1000) break;\n"
	"	/* highlight tokens */\n"
	"	case 1004:\n"
	"	    if(opt_highlight) mtrac_free(opt_highlight);\n"
	"	    opt_highlight = mtrac_strdup(optarg ? optarg : \"clause,subject,object,if\");\n"
	"	    if(!opt_color) opt_color = mtrac_strdup(\"\\033[1m\");\n"
	"       	    if(opt_verbose || opt_debug) printf (\"token highlighting: %s\\n\", opt_highlight);\n"
	"	    break;\n"
	"	/* flattened tree */\n"
	"	case 1005:\n"
	"	    if(opt_debug) printf (\"packed binary lists: on\\n\");\n"
	"	    opt_produce_flat = true;\n"
	"	    break;\n"
	"	/* terse tree */\n"
	"	case 1006:\n"
	"	    if(opt_debug) printf (\"terse tree: on\\n\");\n"
	"	    opt_produce_terse = true;\n"
	"	    break;\n"
	"	case ':':\n"
	"	    fprintf (stderr, \"command line parameter error, missing argument\\n\");\n"
	"	    exit(1);\n"
	"	default:\n"
	"	    fprintf (stderr, \"command line parameter error (0%o)\\n\", c); // ◊ allow ignoring\n"
	"	    exit(1);\n"
	"	}\n"
	"    }\n"
	"\n"
	"    /* source file is given as command line parameter */\n"
	"    if (optind < argc) {\n"
	"    	opt_source = argv[optind];\n"
	"	if(opt_verbose || opt_debug) fprintf(stderr, \"• source file: %s\\n\", opt_source);\n"
	"\n"
	"	/* the following replaces defaults of all file_* globals */\n"
	"	mtrac_free(file_clearname); file_clearname = null;\n"
	"	mtrac_free(file_namepart); file_namepart = null;\n"
	"	mtrac_free(file_pathpart); file_pathpart = null;\n"
	"	mtrac_free(file_location); file_location = null;\n"
	"\n"
	"	/* build pretty clear name, extraxt path and file name */\n"
	"	rump(&file_clearname, opt_source);\n"
	"	char *tmp = mtrac_strdup(opt_source);\n"
	"	file_namepart = mtrac_strdup(basename(tmp));\n"
	"	mtrac_free(tmp);\n"
	"	tmp = mtrac_strdup(opt_source);\n"
	"	file_pathpart = mtrac_strdup(dirname(tmp));\n"
	"	mtrac_free(tmp);\n"
	"\n"
	"	/* for switching back to the directory that the program was started in */\n"
	"	if(getcwd(name_homedir, sizeof(name_homedir)) == NULL) {\n"
	"		perror(\"could not get home directory\");\n"
	"		exit(15);\n"
	"	}\n"
	"\n"
	"	/* change working directory - to allow for relative includes */\n"
	"	if(opt_verbose || opt_debug) fprintf(stderr, \"• change to source file's folder: %s\\n\", file_pathpart);\n"
	"	if(chdir(file_pathpart) != 0) {\n"
	"		fprintf(stderr, \"Failed to change into the directory '%s' of the source file '%s'. Code: %s\\n\", file_pathpart, file_namepart, yytext);\n"
	"		perror(file_pathpart);\n"
	"		exit(16);\n"
	"	}\n"
	"\n"
	"	/* record absolute path of source directory. Also for later switch back from includes. */\n"
	"	file_location = mtrac_malloc(PATH_MAX);\n"
	"	if(getcwd(file_location, PATH_MAX) == NULL) {\n"
	"		perror(\"could not read source file directory name\");\n"
	"		exit(17);\n"
	"	}\n"
	"\n"
	"	/* open the source file, from its home directory */\n"
	"	assert(file_fileptr == null);\n"
	"	if(!(file_fileptr = fopen(file_namepart, \"r\"))) {\n"
	"		fprintf(stderr, \"Failed to open source file '%s' expected in directory '%s'. Code: %s\\n\", file_namepart, file_pathpart, yytext);\n"
	"		perror(file_namepart);\n"
	"		exit(19);\n"
	"	}\n"
	"\n"
	"	/* echo source file */\n"
	"	if(opt_echo) {\n"
	"		FILE *fp = file_fileptr;\n"
	"		fseek(fp, 0L, SEEK_END);\n"
	"		int size = ftell(fp);\n"
	"		rewind(fp);\n"
	"		char *src = news(src, size + 1);\n"
	"		if(fread(src, 1, size, fp) != size) { perror(file_namepart); exit(20); }\n"
	"		rewind(fp);\n"
	"		printf(\"\\nsource:\\n-------\\n%s\\n\", src);\n"
	"		mtrac_free(src);\n"
	"	}\n"
	"\n"
	"	yyin = file_fileptr; //.. necessary?\n"
	"	line = 1;\n"
	"    }\n"
	"}\n"
	"\n"
	"void help() {\n"
	"	puts(\"\\n\\t\" slug \"\\n\\n\\\n"
	"	Lexon is a compiler that translates controlled natural language into program languages.\\n\\\n"
	"	It can also be used to create or extend itself by processing Lexon Grammar Form (LGF).\\n\\\n"
	"	\\n\\\n"
	"	usage: lexon [options] [<source file>]\\n\\\n"
	"	\\n\\\n"
	"	-V --version                    print version slug and exit\\n\\\n"
	"	-h --help                       print this text and exit\\n\\\n"
	"	-m --manual                     print the readme text and exit\\n\\\n"
	"	-o --output <file name>         write result of source translation to <file name> (default: stdout)\\n\\\n"
	"	-j --echo-source                list the source text that will be processed\\n\\\n"
	"	-Q --no-result                  no output of resulting code to screen, even absent <out file>\\n\\\n"
	"\\n\\\n"
	"	Producing Lexon Code\\n\\\n"
	"	-2 --javascript                 produce javascript output\\n\\\n"
	"	-3 --solidity                   produce solidity output\\n\\\n"
	"	-4 --sophia                     produce sophia output\\n\\\n"
	"	-v --verbose                    trace detailed compilation steps to find code errors\\n\\\n"
	"	-N --names                      list found names - ie. symbols - and exit\\n\\\n"
	"	-W --echo-precompile            show sanitized source code first, with included files\\n\\\n"
	"	-P --precompile                 show sanitized source code, with included files, then exit\\n\\\n"
	"	-J --jurisdictions              list known jurisdictions and exit\\n\\\n"
	"	-b --bare                       generated code is barebones happy path demonstration\\n\\\n"
	"	-y --comment                    generated code has explanatory comments\\n\\\n"
	"	-u --instructions               generated code leads in with user instructions\\n\\\n"
	"	-z --harden                     generated code checks for unset arguments and variables\\n\\\n"
	"	-f --feedback                   javascript: generated code confirms calls on-screen\\n\\\n"
	"	-l --log [<file>]               javascript: generated code logs state changes to <file> (default: log)\\n\\\n"
	"	-s --signatures [<pem file>]    javascript: generated code signs log using <pem file> (default: key.pem)\\n\\\n"
	"	-c --chaining [<hash length>]   javascript: generated code hash-chains log-entries (default length 12)\\n\\\n"
	"	-p --persistence [<file>]       javascript: generated code stores state in <file> (default: state)\\n\\\n"
	"	-t --bundle [<file>]            javascript: generated code can tar code, log and state (default: contract.tgz)\\n\\\n"
	"	-x --all-auxiliaries            generated code features all applicable extras (-y -u -z -f -l -s -c -p -t)\\n\\\n"
	"	-i --include-path <path>        set a default path to look for include files\\n\\\n"
	" 	-I --included-files             print cascade of included and sub-included files and exit\\n\\\n"
	"	-R --ignore-repeat-includes     ignore include files that are given repeatedly\\n\\\n"
	"	-C --ignore-circular-includes   ignore include files that effectively call themselves\\n\\\n"
	"\\n\\\n"
	"	Inspecting Lexon Code\\n\\\n"
	"	-G --grammar                    list the implemented grammar (LGF), and exit\\n\\\n"
	"	-1 --core                       produce lexon core code output\\n\\\n"
	"	-0 --tree                       produce abstract syntax tree output\\n\\\n"
	"	   --flat                       produce a tree with flattened binary lists\\n\\\n"
	"	   --color [<sgr,sgr..>]        ansi sgr codes for highlighting (default: 1), adds following four\\n\\\n"
	"	   --symbols [<sgr,sgr..>]      highlight the symbols in tree, core, or output code (default: 36)\\n\\\n"
	"	   --highlight [<word,word..>]  highlight specific nodes (default: clause,subject,object,if)\\n\\\n"
	"	   --leaves [<word,word..>]     highlight specific node leaves (default: type,combinator,illocutor)\\n\\\n"
	"	   --subleaves [<word,word..>]  highlight specific node sub leaves (default: predicate)\\n\\\n"
	"\\n\" /*\n"
	"	Interfacing\\n\\\n"
	" 	-U --ui-info                    print json object of insights about the source code, and exit\\n\\\n"
	"\\n\\ */ \"\\\n"
	"	Developing Lexon Grammars\\n\\\n"
	"	-S --scanner [<out file>]       produce scanner code from an LGF grammar\\n\\\n"
	"	-F --source base [<file name>]  source file to be included into scanner code (-S)\\n\\\n"
	"	-H --header [<file name>]       prepend #include \\\"<file name>\\\" to scanner code (-S)\\n\\\n"
	"	-Y --parser [<out file>]        produce parser code, incl. BNF, from an LGF grammar\\n\\\n"
	"	-K --keywords                   list the keywords produced from an LGF grammar, and exit\\n\\\n"
	"	-B --bnf                        produce BNF from an LGF grammar (subset of -Y), and exit\\n\\\n"
	"	-y --comment                    include comments in grammar output (-S, -Y)\\n\\\n"
	"	-k --check                      check consistency and completeness of LGF grammar (equals -QE)\\n\\\n"
	"	-E --examples [<path stub>]     produce examples from <path stub>-nn.lex for an LGF grammar\\n\\\n"
	"	-n --max-examples [<cap>]       produce ca. <cap> number of examples (default: 1000)\\n\\\n"
	"	-w --wipe                       delete pre-existing example files <path stub>-*.lex for -E\\n\\\n"
	"\\n\\\n"
	"	Developing Lexon Targets\\n\\\n"
	"	-T --template [<out file>]      produce skeleton AST walk functions for an LGF grammar\\n\\\n"
	"	-L --language-prefix [<prefix>] prepend <prefix> to the functions of -T (default: 'core')\\n\\\n"
	"\\n\\\n"
	"	Debugging Lexon\\n\\\n"
	"	-d --debug                      detailed trace of processing steps to debug lexon itself\\n\\\n"
	"	-D --debug-modules [<modules>]  detailed trace of specific modules. Use -Dh to list modules\\n\\\n"
	"	-M --memory-check               run-time check and post-mortem of memory allocation and errors\\n\\\n"
	"	$ make check                    run test source files from tests/\\n\\\n"
	"	$ make recheck                  run tests from tests/ again but skip those that worked\\n\\\n"
	"	$ make update                   run tests again but interactively inspect & update expectations\\n\\\n"
	"\\n\\\n"
	"	Examples\\n\\\n"
	"	lexon sample.lex\\n\\\n"
	"	lexon --javascript sample.lex\\n\\\n"
	"	lexon -vQ sample.lex\\n\\\n"
	"	lexon -P sample.lex\\n\\\n"
	"	lexon --flat --color --tree sample.lex\\n\\\n"
	"	lexon -B english.lgf\\n\\\n"
	"	lexon -Yparser.y -Hparser.h -Sscanner.l -Flexon.l -Lcore english.lgf\\n\\\n"
	"\\n\\\n"
	"	Version\\n\\\n"
	"	\" slug \"\\n\\n\");\n"
	"	exit(0);\n"
	"}\n"
	"\n"
	"void syntax(char *message, char *violation) {\n"
	"\n"
	"	if(violation){\n"
	"		fprintf(stderr, \"%s%s<<<\\n\\n\", src, violation);\n"
	"		fprintf(stderr, \"Lexon: syntax error at line %d: %s. Can't process '%s'\", line, message, violation);\n"
	"		if(strlen(violation) == 1) fprintf(stderr, \" (ascii %x %u)\",\n"
	"			 *(unsigned char *)violation, *(unsigned char *)violation);\n"
	"		fprintf(stderr, \".\\n\");\n"
	"	} else {\n"
	"		// fprintf(stderr, \"%s<<<\\n\\n\", src); // ◊ make more error context optional\n"
	"		fprintf(stderr, \"Lexon: syntax error at line %d: %s.\\n\", line, message);\n"
	"	}\n"
	"	fprintf(stderr, \">> %s\\n\", context); // ◊ make more error context optional\n"
	"	exit(1); // |1| because tests atm want expected fails to return 1. Fits as weakest, controlled error exit.\n"
	"}\n"
	"\n"
	"void yacc_printf(FILE *stream, char *format, ...) {\n"
	"	static bool had = true;\n"
	"	va_list args;\n"
	"	va_start(args, format);\n"
	"	if(had) fprintf(stream, \"parser : \");\n"
	"	vfprintf(stream, format, args);\n"
	"	va_end(args);\n"
	"	had = !!strchr(format, '\\n');\n"
	"}\n"
	"\n"
	"void precompile() {\n"
	"\n"
	"	if(opt_verbose || opt_debug) fprintf(stderr, \"• precompilation\\n\"); // not quite, the start of PRE is the real start of precompilation\n"
	"\n"
	"	/* protect pre-existing « » ◊ cover */\n"
	"	replace(&buf, \"«\", \"\\\\«\");\n"
	"	replace(&buf, \"»\", \"\\\\»\");\n"
	"\n"
	"	/* unicode chars are not processed correctly by Flex, it takes the bytes\n"
	"	   apert, specifically the negative calls notquote can't work */\n"
	"\n"
	"	/* list presorted for length, descending two steps: replace by tag [n] first */\n"
	"	node *cur = symbols;\n"
	"	char tag[40]; // safeguard ◊\n"
	"	int i = 0;\n"
	"	while(cur) {\n"
	"		snprintf(tag, 40, \"«[%d]»\", ++i);\n"
	"		replace_whole_words(&buf, cur->find, tag, \"‹\", \"›\");\n"
	"		cur->tag = mtrac_strdup(tag);\n"
	"		cur = cur->prev;\n"
	"	}\n"
	"	cur = symbols;\n"
	"	while(cur) {\n"
	"		replace(&buf, cur->tag, cur->repl);\n"
	"		mtrac_free(cur->tag);\n"
	"		cur = cur->prev;\n"
	"	}\n"
	"\n"
	"	margin();\n"
	"\n"
	"	if(opt_names || opt_debug)\n"
	"		dump_name_list();\n"
	"\n"
	"	if(opt_precompile || opt_pre_echo || opt_debug)\n"
	"		printf(\"\\nprecompilation:\\n---------------\\n%s\\n\", buf);\n"
	"\n"
	"	if(opt_precompile)\n"
	"		 clean_exit();\n"
	"\n"
	"	if(opt_debug)\n"
	"		 fprintf(stderr, \"  precompilation done\\n\");\n"
	"}\n"
	"\n"
	"// write file name and line number into buffer\n"
	"void lineno() {\n"
	"	if(_lastline != line || _lastfile != file_namepart) { // sic\n"
	"		concat(&buf, file_clearname, \" \", str(line), \":   \");\n"
	"		_lastfile = file_namepart;\n"
	"		_lastline = line;\n"
	"	}\n"
	"}\n"
	"\n"
	"void geninfo() {\n"
	"	char* buf = mtrac_strdup(\"{ \\\"names\\\" = [\\n\");\n"
	"	// use .serial to go by original order of appearance\n"
	"	int i;\n"
	"	for(i = 1; i <= name_count; i++) {\n"
	"		node *cur = symbols;\n"
	"		assert(i<=name_count);\n"
	"		while(cur->serial != i)\n"
	"			cur = cur->prev;\n"
	"		concat(&buf, i>1?\",\\n\":\"\", \"\\t\\\"\", cur->find, \"\\\"\");\n"
	"	}\n"
	"	concat(&buf, \"\\n]}\");\n"
	"	puts(buf);\n"
	"	mtrac_free(buf);\n"
	"}\n"
	"\n"
	"void dump_name_list() {\n"
	"	int i;\n"
	"	for(i = 1; i <= name_count; i++) {\n"
	"		node *cur = symbols;\n"
	"		assert(i<=name_count);\n"
	"		while(cur->serial != i)\n"
	"			cur = cur->prev;\n"
	"		printf(\"%d\\t%s\\n\", cur->serial, cur->find);\n"
	"	}\n"
	"}\n"
	"\n"
	"int yywrap(void) {\n"
	"	return 1;\n"
	"}\n"
	"\n"
	"char *coredup(char *src) {\n"
	"	char *s = mtrac_strdup(src+1);\n"
	"	*(s+strlen(s)-1) = 0;\n"
	"	return s;\n"
	"}\n"
	"\n"
	"char *cutbuf(char *src, char *cut) {\n"
	"	char *b = src+strlen(cut);\n"
	"	while(*b==' '||*b=='\\t') b++;\n"
	"	b = mtrac_strdup(b);\n"
	"	char *e = b + strlen(b) -1;\n"
	"	while(*e=='.'||*e==' '||*e=='\\t') *e-- = 0;\n"
	"	return b;\n"
	"}\n"
	"\n"
	"char _str[40];\n"
	"const char *str(int line) {\n"
	"	sprintf(_str, \"%d\", line);\n"
	"	return _str;\n"
	"}\n"
	"\n"
	"char _lit[1001];\n"
	"const char *literal_symbol(char *token) {\n"
	"	strncpy(_lit, token, 1000);\n"
	"	char *c = _lit;\n"
	"	while(*c) {\n"
	"		while(*c == '\"') { char *p=c; do *p = *(p+1); while(*++p); }\n"
	"		if(*c) *c = toupper(*c);\n"
	"		c++;\n"
	"	}\n"
	"	if(!strcmp(_lit, \"FILE\")) strcat(_lit, \"_\");\n"
	"	return _lit;\n"
	"}\n"
	"\n"
	"char _up[1001];\n"
	"char *UP(const char *token) {\n"
	"	strncpy(_up, token, 1000);\n"
	"	char *c = _up;\n"
	"	bool sep = true;\n"
	"	while(*c) { if(sep) *c = toupper(*c); sep = *c == '_'; c++; }\n"
	"	return _up;\n"
	"}\n"
	"\n"
	"char *up(char *s) {\n"
	"	char *c = s;\n"
	"	bool sep = true;\n"
	"	while(*c) { if(sep) *c = toupper(*c); sep = *c == '_'; c++; }\n"
	"	return s;\n"
	"}\n"
	"\n"
	"char _low[1001];\n"
	"char *LOW(const char *token) {\n"
	"	strncpy(_low, token, 1000);\n"
	"	char *c = _low -1;\n"
	"	while(*++c) *c = tolower(*c);\n"
	"	return _low;\n"
	"}\n"
	"\n"
	"char *lowdup(const char *s) {\n"
	"	char *buf = mtrac_strdup(s);\n"
	"	char *c = buf -1;\n"
	"	while(*++c) *c = tolower(*c);\n"
	"	return buf;\n"
	"}\n"
	"\n"
	"char _snake[1001];\n"
	"char *SNAKE(const char *token) {\n"
	"	strncpy(_snake, token, 1000);\n"
	"	char *c = _snake -1;\n"
	"	while(*++c) if(*c == ' ' || *c == '-') *c = '_'; else *c = tolower(*c);\n"
	"	return _snake;\n"
	"}\n"
	"\n"
	"char *snakedup(const char *s) {\n"
	"	char *dup = mtrac_strdup(s);\n"
	"	char *c = dup -1;\n"
	"	while(*++c) if(*c == ' ' || *c == '-') *c = '_'; else *c = tolower(*c);\n"
	"	return dup;\n"
	"}\n"
	"\n"
	"char _dsp[1001];\n"
	"char *dash_spaced(const char *token) {\n"
	"	assert(token);\n"
	"	strncpy(_dsp, token, 1000);\n"
	"	char *p = _dsp -1;\n"
	"	while(*++p) if(*p == ' ' || *p == '_') *p = '-';\n"
	"	return _dsp;\n"
	"}\n"
	"\n"
	"char _ssp[1001];\n"
	"char *snake_spaced(const char *token) {\n"
	"	//assert(token); ◊\n"
	"	if(!token) token = \"[undefined]\";\n"
	"	strncpy(_ssp, token, 1000);\n"
	"	char *p = _ssp -1;\n"
	"	while(*++p) if(*p == ' ' || *p == '-') *p = '_';\n"
	"	return _ssp;\n"
	"}\n"
	"\n"
	"char _csp[1001];\n"
	"char *camel_spaced(const char *token) {\n"
	"	assert(token);\n"
	"	strncpy(_csp, token, 1000);\n"
	"	char *p = _csp -1;\n"
	"	bool gap = false;\n"
	"	while(*++p) { if(gap) *p = toupper(*p); gap = *p == ' ' || *p == '-' || *p == '_'; }\n"
	"	contract(_csp);\n"
	"	return _csp;\n"
	"}\n"
	"\n"
	"void rump(char **buf, char *filename) {\n"
	"	char *copy = mtrac_strdup(filename); // as per namepart doc\n"
	"	if(*buf) mtrac_free(*buf);\n"
	"	*buf = mtrac_strdup(basename(copy)); // don't free file bec (**)\n"
	"	mtrac_free(copy);\n"
	"	replace(buf, \".lex\", \"\");\n"
	"	replace(buf, \"-\", \" \");\n"
	"}\n"
	"\n"
	"void include(char *scanned) {\n"
	"	int i;\n"
	"	char *tmp;\n"
	"\n"
	"	/* The parsed term may be a full path, a base name or a pretty-written name */\n"
	"	char *clearname, *namepart, *pathpart, *location, *fullpath;\n"
	"	FILE *fileptr;\n"
	"\n"
	"	/* pretty representation */\n"
	" 	clearname = null;\n"
	"	rump(&clearname, scanned);\n"
	"\n"
	"	/* fully qualified path, poss. prefix command line parameter */\n"
	"	fullpath = mtrac_strdup(scanned);\n"
	"	replace(&fullpath, \" \", \"-\");\n"
	"	if(!strstr(fullpath, \".lex\")) concat(&fullpath, \".lex\"); // ..\n"
	"	if(!strchr(fullpath, '/')) precat(&fullpath, opt_include_path);\n"
	"\n"
	"	/* resulting directory path */\n"
	"	tmp = mtrac_strdup(fullpath);\n"
	"	pathpart = mtrac_strdup(dirname(tmp));\n"
	"	mtrac_free(tmp);\n"
	"\n"
	"	/* resulting file namepart */\n"
	"	tmp = mtrac_strdup(fullpath);\n"
	"	namepart = mtrac_strdup(basename(tmp));\n"
	"	mtrac_free(tmp);\n"
	"\n"
	"	/* trace */\n"
	"	if(opt_included_files || opt_verbose || opt_debug) {\n"
	"		printf(\"%s %d ⟼   %s\\n\", file_clearname, line, clearname);\n"
	"		printf(\"Code file %s/%s on line %d includes file %s/%s from directory %s.\\nThe default include path is (-I) %s.\\n\",\n"
	"			file_pathpart, file_namepart, line, pathpart, namepart, file_location, opt_include_path);\n"
	"	}\n"
	"\n"
	"	/* prevent includes from nesting too deeply */\n"
	"	if(include_stack_ptr >= MAX_INCLUDE_DEPTH) {\n"
	"		fprintf(stderr, \"fatal: includes nested too deeply (limit: %d)\\n\", MAX_INCLUDE_DEPTH);\n"
	"		dump_include_stack(clearname);\n"
	"		exit(1); // see |1|: atm required by tests: planned fail error code 1\n"
	"	}\n"
	"\n"
	"	/* Includes should not be circular, i.e. not file1 -> file2 -> file1 */\n"
	"	if(!opt_ignore_circular_includes)\n"
	"		for(i = 0; i < include_stack_ptr; i++)\n"
	"			if(!strcmp(include_stack[i].namepart, namepart)) {\n"
	"				fprintf(stderr, \"fatal: circular include\\n\");\n"
	"				dump_include_stack(clearname);\n"
	"				exit(1); // see |1|\n"
	"			}\n"
	"\n"
	"	/* includes should also not be included twice, i.e. not file1 -> file2, file2 */\n"
	"	if(!opt_ignore_repeat_includes) {\n"
	"		include_trace *t = include_trace_start;\n"
	"		if(t && !strcmp(t->from_namepart, namepart)) {\n"
	"			fprintf(stderr, \"fatal: include of main file\\n\");\n"
	"			dump_include_trace(clearname);\n"
	"			exit(1); // see |1|\n"
	"		}\n"
	"		while(t) {\n"
	"			if(!strcmp(t->include_namepart, namepart)) {\n"
	"				fprintf(stderr, \"fatal: repeat include\\n\");\n"
	"				dump_include_trace(clearname);\n"
	"				exit(1); // see |1|\n"
	"			}\n"
	"			t = t->next;\n"
	"		}\n"
	"	}\n"
	"\n"
	"	/* switch to directory of the file to be included */\n"
	"	if(chdir(pathpart) != 0) {\n"
	"		fprintf(stderr, \"Failed to change into the directory '%s' of the include file '%s'. Code %s\\n\", pathpart, namepart, yytext);\n"
	"		perror(pathpart);\n"
	"		exit(26);\n"
	"	}\n"
	"\n"
	"	/* record absolute path of directory */\n"
	"	location = getcwd(null, 0);\n"
	"	if(location == NULL) { //..\n"
	"		perror(\"could not read include file directory name\");\n"
	"		exit(27);\n"
	"	}\n"
	"	location = mtrac_strdup(getcwd(null, 0));\n"
	"\n"
	"	/* open the include file, from its home directory */\n"
	"	if(!(fileptr = fopen(namepart, \"r\"))) {\n"
	"		fprintf(stderr, \"Failed to open include file '%s' expected in directory '%s'.\\n\", namepart, pathpart);\n"
	"		fprintf(stderr, \"Included from file '%s/%s', line %d, as '%s'.\\n\", file_pathpart, file_namepart, line, yytext);\n"
	"		fprintf(stderr, \"The include file path prefix set via command line is: '%s'.\\n\", opt_include_path);\n"
	"		fprintf(stderr, \"Code: %s\\n\", yytext);\n"
	"		perror(namepart);\n"
	"		exit(1);\n"
	"	}\n"
	"\n"
	"	/* keep track of include files ever used */\n"
	"	include_trace *trace = mtrac_malloc(sizeof(include_trace));\n"
	"	trace->from_namepart = mtrac_strdup(file_namepart);          // never free'd\n"
	"	trace->from_clearname = mtrac_strdup(file_clearname);        // ditto\n"
	"	trace->from_line = line;\n"
	"	trace->include_namepart = mtrac_strdup(namepart);            // ditto\n"
	"	trace->include_clearname = mtrac_strdup(clearname);          // ditto\n"
	"	include_count++;\n"
	"	trace->next = null;\n"
	"	if(!include_trace_start) include_trace_start = trace;\n"
	"	if(include_trace_last) include_trace_last->next = trace;\n"
	"	include_trace_last = trace;\n"
	"\n"
	"	/* keep track of include files nesting depth */\n"
	"	include_stack[include_stack_ptr].buffer = YY_CURRENT_BUFFER; // gift\n"
	"	include_stack[include_stack_ptr].clearname = file_clearname; // gift\n"
	"	include_stack[include_stack_ptr].namepart = file_namepart;   // gift\n"
	"	include_stack[include_stack_ptr].pathpart = file_pathpart;   // gift\n"
	"	include_stack[include_stack_ptr].location = file_location;   // gift\n"
	"	include_stack[include_stack_ptr].fileptr = file_fileptr;     // gift\n"
	"	include_stack[include_stack_ptr].line = line;\n"
	"	include_stack_ptr++;\n"
	"\n"
	"	/* For clarity only, these mtrac_mallocs are all in the responsibility of the include_stack now: */\n"
	"	file_clearname = null;\n"
	"	file_namepart = null;\n"
	"	file_pathpart = null;\n"
	"	file_location = null;\n"
	"	file_fileptr = null;\n"
	"\n"
	"	/* now the switch-over starts, regarding Lex and the file_* variables. */\n"
	"	file_clearname = clearname;\n"
	"	file_namepart = namepart;\n"
	"	file_pathpart = pathpart;\n"
	"	file_location = location;\n"
	"	file_fileptr = fileptr;\n"
	"	line = 1;\n"
	"\n"
	"	/* Finally, make it Lex' scan source.\n"
	"	   Note that the FILE pointer in the call to yy_create_buffer is only used as the value of yyin seen by YY_INPUT */\n"
	"	yy_switch_to_buffer(yy_create_buffer(file_fileptr, YY_BUF_SIZE));\n"
	"\n"
	"	/* set scan mode to normal pre-processing to start the file scan */\n"
	"	BEGIN(PRE);\n"
	"\n"
	"	/* 4 mtrac_mallocs and 2 file buffers have been gifted to the include_stack,\n"
	"	  they, yyin and the new YY_CURRENT_BUFFER are freed when twice popped at (****) */\n"
	"	mtrac_free(fullpath);\n"
	"}\n"
	"\n"
	"int include_done() {\n"
	"	if (--include_stack_ptr < 0)\n"
	"		return 0;\n"
	"\n"
	"	if(opt_debug) fprintf (stderr, \"include complete: %s\\n\", file_namepart);\n"
	"\n"
	"	/* note (****) this deletes the CURRENT values and starts to use those from stack */\n"
	"	mtrac_free(file_clearname);\n"
	"	mtrac_free(file_pathpart);\n"
	"	mtrac_free(file_namepart);\n"
	"	mtrac_free(file_location);\n"
	"	fclose(file_fileptr); //.. is this duplicating yy_delete_buffer's action?\n"
	"	yy_delete_buffer(YY_CURRENT_BUFFER);\n"
	"\n"
	"	/* switch over */\n"
	"	file_clearname = include_stack[include_stack_ptr].clearname;\n"
	"	file_pathpart = include_stack[include_stack_ptr].pathpart;\n"
	"	file_namepart = include_stack[include_stack_ptr].namepart;\n"
	"	file_location = include_stack[include_stack_ptr].location;\n"
	"	file_fileptr = include_stack[include_stack_ptr].fileptr;\n"
	"	line = include_stack[include_stack_ptr].line;\n"
	"	line++; // the \\n was consumed with the path but progress only now.\n"
	"\n"
	"	// ◊ is a call to chdir(file_location) missing ?\n"
	"\n"
	"	yy_switch_to_buffer(include_stack[include_stack_ptr].buffer);\n"
	"\n"
	"	return 1;\n"
	"}\n"
	"\n"
	"void dump_include_stack(char *include_clearname) {\n"
	"	int i;\n"
	"	for(i = 0; i < include_stack_ptr; i++)\n"
	"		fprintf(stderr, \"%s line %d ⟶  \\n\", include_stack[i].clearname, include_stack[i].line);\n"
	"	printf(\"%s again - fails\\n\", include_clearname);\n"
	"}\n"
	"\n"
	"void dump_include_trace(char *include_clearname) {\n"
	"	include_trace *t = include_trace_start;\n"
	"	while(t) {\n"
	"		fprintf(stderr, \"%s line %d ⟼   %s\\n\", t->from_clearname, t->from_line, t->include_clearname);\n"
	"		t = t->next;\n"
	"	}\n"
	"	fprintf(stderr, \"%s line %d ⟼   %s again - fails\\n\", file_clearname, line, include_clearname);\n"
	"}\n"
	"\n"
	"void delete_include_trace() {\n"
	"	include_trace *it0, *it = include_trace_start;\n"
	"	while((it0 = it)) {\n"
	"		mtrac_free(it->from_namepart);\n"
	"		mtrac_free(it->from_clearname);\n"
	"		mtrac_free(it->include_namepart);\n"
	"		mtrac_free(it->include_clearname);\n"
	"		mtrac_free(it);\n"
	"		it = it0->next;\n"
	"		if(it0 == include_trace_last) { assert(!it); }\n"
	"	}\n"
	"}\n"
	"\n"
	"/* add a symbol (name) to the symbols list, scanned directly from the code buffer */\n"
	"void process(char *ltrim, char *skip, char *mtrim, char *pif, char *rtrim) {\n"
	"	pif += strspn(pif, ltrim);\n"
	"	pif += strlen(skip);\n"
	"	pif += strspn(pif, mtrim);\n"
	"	pif = mtrac_strdup(pif);\n"
	"	char *e = pif + strlen(pif);\n"
	"	while(strchr(rtrim, *--e)) ; *++e = 0;\n"
	"\n"
	"	int l = strlen(pif);\n"
	"	char *c = mtrac_malloc(l+1+strlen(\"«\")+strlen(\"»\"));\n"
	"	strcpy(c, \"«\");\n"
	"	strcpy(c+strlen(\"«\"), pif);\n"
	"	strcpy(c+l+strlen(\"«\"), \"»\");\n"
	"	if(opt_debug) printf(\"found name %s\\n\", c);\n"
	"\n"
	"	node *ins = symbols;\n"
	"	node *next = null;\n"
	"	while(ins && ins->find_len > l) {\n"
	"		next = ins; ins = ins->prev;\n"
	"	}\n"
	"	node *n = mtrac_malloc(sizeof(node));\n"
	"	n->serial = ++name_count;\n"
	"	n->find = pif;\n"
	"	n->find_len = strlen(pif);\n"
	"	n->repl = c;\n"
	"	n->prev = ins;\n"
	"	if(next) { assert(next->prev==ins); next->prev = n; }\n"
	"	else symbols = n;\n"
	"}\n"
	"\n"
	"/* add a symbol (name) to the symbols list, scanned directly from the code buffer */\n"
	"void process2(char *pif, char *rtrim, char *open, char *close) {\n"
	"	pif = mtrac_strdup(pif);\n"
	"	char *e = pif + strlen(pif);\n"
	"	while(strchr(rtrim, *--e)) ; *++e = 0;\n"
	"\n"
	"	int l = strlen(pif);\n"
	"	char *c = mtrac_malloc(l+1+strlen(open)+strlen(close));\n"
	"	strcpy(c, open);\n"
	"	strcpy(c+strlen(open), pif);\n"
	"	strcpy(c+l+strlen(open), close);\n"
	"	if(opt_debug) printf(\"found name %s\\n\", c);\n"
	"\n"
	"	node *ins = symbols;\n"
	"	node *next = null;\n"
	"	while(ins && ins->find_len > l) {\n"
	"		next = ins; ins = ins->prev;\n"
	"	}\n"
	"	node *n = mtrac_malloc(sizeof(node));\n"
	"	n->serial = ++name_count;\n"
	"	n->find = pif;\n"
	"	n->find_len = strlen(pif);\n"
	"	n->repl = c;\n"
	"	n->prev = ins;\n"
	"	if(next) { assert(next->prev==ins); next->prev = n; }\n"
	"	else symbols = n;\n"
	"}\n"
	"\n"
	"// frees input and replaces with result.\n"
	"unsigned int grid = 0; // optics: bitpattern of vertical tree branch lines, across rows\\n\\n\";\n"
	"unsigned int last_indent = 0; // for auto spacing between sub branches: extra line whenever indentation doesn't grow vs last line.\n"
	"void gridrow(char *t, int right) { unsigned int mask = (1<<right); while(right > 0) { strcat(t, (mask&grid)?\"⎸   \":\"    \"); right--; mask>>=1; } }\n"
	"char **_concat(char *varname, char *file, int line, int down, int right, char **buf, ...) {\n"
	"	if(right < 0) right = 0;\n"
	"	int org_down  = down ;\n"
	"	int org_right = right;\n"
	"	va_list ap;\n"
	"	va_start(ap, buf);\n"
	"	char *add = va_arg(ap, char *);\n"
	"	while(add) {\n"
	"		char *t = _mtrac_malloc(strlen(*buf) + down + (down+1) * 10 * right + 1 + strlen(add) + 1, varname, file, line);\n"
	"		if(!t) { fprintf(stderr, \"out of memory %s %d\", __FILE__, __LINE__); exit(137); } // doubles mtrac_malloc catch.\n"
	"		strcpy(t, *buf);\n"
	"		while(down > 0) { strcat(t, \"\\n\"); down--; if(grid||!down) gridrow(t, right); }\n"
	"		if(grid && right && right <= last_indent) { strcat(t, \"⎸ \\n\"); gridrow(t, right); }\n"
	"		right = 0;\n"
	"		strcat(t, add);\n"
	"		mtrac_free(*buf);\n"
	"		*buf = t;\n"
	"		add = va_arg(ap, char *);\n"
	"	}\n"
	"	va_end(ap);\n"
	"	if(org_right && org_down) last_indent = org_right;\n"
	"\n"
	"	/* module debug mode: insert line# tags after each snippet */\n"
	"	if(_concat_trace)\n"
	"		_concatnum(buf, \" \", line, \" \");\n"
	"\n"
	"	return buf;\n"
	"}\n"
	"\n"
	"char **_concatnum(char **buf, char *prefix, int number, char *postfix) {\n"
	"\n"
	"	char *t = _mtrac_malloc(strlen(*buf) + (prefix?strlen(prefix):0) + (postfix?strlen(postfix):0) + 1000, \"t\", __FILE__, __LINE__);\n"
	"	if(!t) { fprintf(stderr, \"out of memory %s %d\", __FILE__, __LINE__); exit(137); } // doubles mtrac_malloc catch.\n"
	"	strcpy(t, *buf);\n"
	"	sprintf(t + strlen(*buf), \"%s%d%s\", prefix, number, postfix);\n"
	"	mtrac_free(*buf);\n"
	"	*buf = t;\n"
	"\n"
	"	return buf;\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"// frees input and replaces with result.\n"
	"void _precat(char **buf, ...) {\n"
	"	va_list ap;\n"
	"	va_start(ap, buf);\n"
	"	char *add = va_arg(ap, char *);\n"
	"	while(add) {\n"
	"		char *t = mtrac_malloc(strlen(*buf) + strlen(add) + 1);\n"
	"		strcpy(t, add);\n"
	"		strcat(t, *buf);\n"
	"		mtrac_free(*buf);\n"
	"		*buf = t;\n"
	"		add = va_arg(ap, char *);\n"
	"	}\n"
	"	va_end(ap);\n"
	"}\n"
	"\n"
	"char *catdup(char *string, char *append, int(*func)(int))  {\n"
	"	char *buf = mtrac_malloc(strlen(string) + strlen(append) + 1);\n"
	"	strcpy(buf, string);\n"
	"	strcat(buf, append);\n"
	"	char *c = buf -1; while(*++c) *c = (*func)(*c);\n"
	"	return buf;\n"
	"}\n"
	"\n"
	"// Frees input and replaces with result. Result must later be freed.\n"
	"// courtesy J Mucchiello https://stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c#\n"
	"int _replace(char **orig, const char *rep, const char *with, int all, char *from,\n"
	"	bool whole, char *quote, char *unquote, char *origname, char *file, int line) {\n"
	"	char *result;\n"
	"	char *start;\n"
	"	char *ins; // next insert point\n"
	"	char *tmp;\n"
	"	int len_orig;\n"
	"	int len_rep;\n"
	"	int len_with;\n"
	"	int len_front; // distance between rep and end of last rep\n"
	"	int counter; // number of replacements\n"
	"	int count; // number of replacements\n"
	"\n"
	"	assert(!(!orig || !*orig || !rep));\n"
	"	if (!orig || !*orig || !rep)\n"
	"		return -1;\n"
	"\n"
	"	start = ins = from ? from : *orig;\n"
	"	len_orig = strlen(*orig);\n"
	"	len_rep = strlen(rep);\n"
	"	if (len_rep == 0 || len_orig == 0 || !*start || !with)\n"
	"		return 0;\n"
	"	len_with = strlen(with);\n"
	"\n"
	"	/* count the number of replacements. Wastes space if 'whole' fails. */\n"
	"	for (count = 0; (tmp = strstr(ins, rep)); ) {\n"
	"		ins = tmp + len_rep;\n"
	"		count++;\n"
	"		if(!all) break;\n"
	"	}\n"
	"\n"
	"	if(!count)\n"
	"		return 0;\n"
	"\n"
	"	size_t msz = len_orig + (len_with - len_rep) * count + 1;\n"
	"	if(whole && len_orig + 1 > msz) msz = len_orig + 1; // wasteful but avoids prechecking whole-wordiness when 'count' is made\n"
	"\n"
	"	tmp = result = _mtrac_malloc(msz, origname, file, line);\n"
	"\n"
	"	if (!result) {\n"
	"		fprintf(stderr, \"internal error in string replace for %s %s %d\", origname, file, line);\n"
	"		exit(30);\n"
	"	}\n"
	"\n"
	"	if(from && from != *orig) {\n"
	"		tmp = strncpy(tmp, *orig, from - *orig) + (from - *orig);\n"
	"	}\n"
	"\n"
	"	// first time through the loop, all the variable are set correctly\n"
	"	// from here on,\n"
	"	//    tmp points to the end of the result string\n"
	"	//    ins points to the next occurrence of rep in orig\n"
	"	//    start points to the remainder of orig after \"end of rep\"\n"
	"	counter = count;\n"
	"	bool inquote = false;\n"
	"	while (counter--) {\n"
	"		ins = strstr(start, rep);\n"
	"		if(quote && unquote) {\n"
	"			char *but, *tub = start;\n"
	"			do {\n"
	"				but = strstr(tub, quote);\n"
	"				tub = but ? strstr(but, unquote) : null;\n"
	"			} while(tub && tub < ins) ;\n"
	"			inquote = but && tub && but < ins && tub > ins;\n"
	"		}\n"
	"		// printf(\"> > > %s 	%d %p %p %p\\n\", with, inquote, but, ins, tub); ◊ make option\n"
	"		len_front = ins - start;\n"
	"		tmp = strncpy(tmp, start, len_front) + len_front;\n"
	"		const char *border = \" \\t\\r\\n\\\".,;:?!()[]{}&%$#@~+/\\\\“”\";\n"
	"		const char *border_special = \" \\t\\r\\n\\\".,;:?!()[]{}&%$#@~+/\\\\“”\";\n"
	"		if(!inquote && (!whole || ((ins == *orig || strchr(border, *(ins-1))) && (!*(ins+len_rep) || strchr(border, *(ins+len_rep))))))\n"
	"			tmp = strcpy(tmp, with) + len_with;\n"
	"		else\n"
	"			tmp = strcpy(tmp, rep) + len_rep;\n"
	"		start += len_front + len_rep; // move to next \"end of rep\" (sic rep: start is on the OLD memory)\n"
	"	}\n"
	"	strcpy(tmp, start);\n"
	"\n"
	"	mtrac_free(*orig);\n"
	"	*orig = result;\n"
	"	return count;\n"
	"}\n"
	"\n"
	"/* takes away whitespace and colon. Shuffles within buffer, doesn't reallocate */\n"
	"char *trim(char *s) {\n"
	"	assert(s);\n"
	"	if(*s) {\n"
	"		char *p = s + strlen(s) -1;\n"
	"		while(*p == ' ' || *p == '\\t' || *p == '\\n' || *p == ':') p--;\n"
	"		*(p+1) = 0;\n"
	"		p = s;\n"
	"		while(*p == ' ' || *p == '\\t' || *p == '\\n' || *p == ':') p++;\n"
	"		if(p != s)\n"
	"			memmove(s, p, strlen(p)+1);\n"
	"	}\n"
	"\n"
	"	//char *c = s-1;\n"
	"	//while(*++c) *c = tolower(*c);\n"
	"	return s;\n"
	"}\n"
	"\n"
	"char *contract(char *s) {\n"
	"	assert(s);\n"
	"	char *q = s, *p = s - 1;\n"
	"	while(*++p) if(*p != ' ' && *p != '-' && *p != '_') *q++ = *p;\n"
	"	*q = 0;\n"
	"	return s;\n"
	"}\n"
	"\n"
	"/* takes out spaces between letters. Spaced letters are allowed for emphasis in LGF definition names. */\n"
	"char *unspace(char *s) {\n"
	"	assert(s);\n"
	"	char *q = s, *p = s - 1;\n"
	"	while(*++p) if(*p != ' ') *q++ = *p;\n"
	"	*q = 0;\n"
	"	return s;\n"
	"}\n"
	"\n"
	"/* takes away whitespace, colon and quote. Uses static buffer, doesn't touch input */\n"
	"char _qtr[1001];\n"
	"char *quote_trimmed(const char *token) {\n"
	"	assert(token);\n"
	"	strncpy(_qtr, token, 1000);\n"
	"	char *p, *s = _qtr;\n"
	"	if(*s) {\n"
	"		p = s + strlen(s) -1;\n"
	"		while(*p == ' ' || *p == '\\t' || *p == '\\n' || *p == ':' || *p == '\\\"'\n"
	"			 || (p[0] == \"”\"[0] && p[1] == \"”\"[1]) || (p[0] == \"”\"[0] && p[1] == \"”\"[1])) p--;\n"
	"		*(p+1) = 0;\n"
	"		p = s;\n"
	"		while(*p == ' ' || *p == '\\t' || *p == '\\n' || *p == ':' || *p == '\\\"'\n"
	"			 || (p[0] == \"”\"[0] && p[1] == \"”\"[1]) || (p[0] == \"”\"[0] && p[1] == \"”\"[1])) p++;\n"
	"	}\n"
	"\n"
	"	return p;\n"
	"}\n"
	"\n"
	"char **pad(char **s, int to) {\n"
	"	assert(s);\n"
	"	int l = strlen(*s);\n"
	"	int d = to - l;\n"
	"	if(d < 1) return s;\n"
	"	//*s = realloc(*s, to + 1);\n"
	"	char *ss = (char *)mtrac_malloc(to + 1);\n"
	"	strcpy(ss, *s);\n"
	"	mtrac_free(*s);\n"
	"	*s = ss;\n"
	"	memset(ss+l, ' ', d);\n"
	"	ss[to] = 0;\n"
	"	return s;\n"
	"}\n"
	"\n"
	"char *xcr(char *s) {\n"
	"	if(_xcr) mtrac_free(_xcr);\n"
	"	_xcr = mtrac_strdup(s);\n"
	"	char *c = _xcr - 1;\n"
	"	while(*++c) if(*c == '\\n') *c = '@';\n"
	"	return _xcr;\n"
	"}\n"
	"\n"
	"int chrcnt(char *hay, char needle) {\n"
	"	int cnt = 0;\n"
	"	while(*hay) if(*hay++ == needle) cnt++;\n"
	"	return cnt;\n"
	"}\n"
	"\n"
	"// get all colons after line numbers into same column\n"
	"void margin() {\n"
	"	if(opt_debug) fprintf(stderr, \"adding margins\\n\");\n"
	"	char *p0, *p = buf;\n"
	"	size_t max = 0;\n"
	"	while(*p) {\n"
	"		size_t margin = strcspn(p, \":\\n\");\n"
	"		if(*(p+margin)=='\\n') margin = 0;\n"
	"		else if(margin > 0 && !strchr(\"0123456789\", *(p+margin-1))) margin = 0;\n"
	"		if(margin > max) max = margin;\n"
	"		if(!(p = strchr(p,'\\n'))) break;\n"
	"		p++;\n"
	"	}\n"
	"	max++;\n"
	"	char space[max+1];\n"
	"	memset(&space, ' ', max);\n"
	"	*(space + max) = 0;\n"
	"	p = p0 = buf;\n"
	"	while(*p) {\n"
	"		size_t margin = strcspn(p, \":\\n\");\n"
	"		if(margin && *(p + margin) == ':' && margin < max) {\n"
	"			p += margin;\n"
	"			while(*--p != ' ')\n"
	"				if(p < p0) {\n"
	"					/* would break the line counter: a line did not, as all should, start '.* .*:' */\n"
	"					fprintf(stderr, \"margin scan buffer:\\n%s\\n\\n\", buf);\n"
	"					fprintf(stderr, \"parser error at: '%.*s' ...\\n\", 25, p0);\n"
	"					exit(31);\n"
	"				}\n"
	"			size_t pos = p - buf;\n"
	"			replace_first_from(&buf, \" \", space + margin -1, p);\n"
	"			p = buf + pos;\n"
	"		}\n"
	"		if(!(p = strchr(p,'\\n'))) break;\n"
	"		p0 = ++p;\n"
	"	}\n"
	"}\n"
	"\n"
	"void freeline() {\n"
	"	if(strlen(buf) > 1 && strcmp(buf + strlen(buf) -2, \"\\n\\n\"))\n"
	"		concat(&buf, \"\\n\");\n"
	"	if(strcmp(buf + strlen(buf) -2, \"\\n\\n\"))\n"
	"		concat(&buf, \"\\n\");\n"
	"}\n"
	"\n"
	"void emulaws() {\n"
	"	law *l = mtrac_malloc(sizeof(law));\n"
	"	l->abbr = \"BER\";\n"
	"	l->name = \"Berlin\";\n"
	"	l->under = \"GER\";\n"
	"	l->ext = \"ber\";\n"
	"	l->prev = null;\n"
	"	laws_last = l;\n"
	"\n"
	"	l = mtrac_malloc(sizeof(law));\n"
	"	l->abbr = \"NY\";\n"
	"	l->name = \"New York\";\n"
	"	l->under = \"USA\";\n"
	"	l->ext = \"ny\";\n"
	"	l->prev = laws_last;\n"
	"	laws_last = l;\n"
	"}\n"
	"\n"
	"void delete_laws() {\n"
	"	while(laws_last) {\n"
	"		law *l = laws_last->prev;\n"
	"		mtrac_free(laws_last);\n"
	"		laws_last = l;\n"
	"	}\n"
	"}\n"
	"\n"
	"void dump_laws() {\n"
	"	printf(\"Known jurisdictions:\\n\");\n"
	"	law *l = laws_last;\n"
	"	while(l) {\n"
	"		printf(\"%s (%s) under %s, file extension: .%s.\\n\", l->name, l->abbr, l->under, l->ext);\n"
	"		l = l->prev;\n"
	"	}\n"
	"}\n"
	"\n"
	"void setlaw(char *scan) {\n"
	"	if(opt_debug) printf(\"jurisdiction given as %s\\n\", scan);\n"
	"	law_abbr = mtrac_strdup(scan);\n"
	"	law_name = mtrac_strdup(scan);\n"
	"	law_ext = mtrac_strdup(scan);\n"
	"	char *c = law_ext -1; while(*++c) *c = tolower(*c);\n"
	"	precat(&law_ext, \".\");\n"
	"	concat(&law_ext, \".\");\n"
	"	if(opt_verbose || opt_debug) printf(\"Jurisdiction set to %s\\n\", scan);\n"
	"}\n"
	"\n"
	" /* LGF/LXF grammar processing */\n"
	"\n"
	"void start_definition(char *scan) {\n"
	"	assert(definition);\n"
	"	//..//assert(!rule);\n"
	"	//..//assert(!alternation);\n"
	"	//..//assert(!alternate);\n"
	"	//..//assert(!word);\n"
	"\n"
	"	if(*definition) definition = &(*definition)->next;\n"
	"	*definition = mtrac_malloc(sizeof(struct definition));\n"
	"	(*definition)->name = up(trim(mtrac_strdup(scan)));\n"
	"	(*definition)->important = !!strchr((*definition)->name, ' ');\n"
	"	(*definition)->name = unspace((*definition)->name);\n"
	"	(*definition)->rules = null;\n"
	"	(*definition)->alternations = null;\n"
	"	(*definition)->subrules = null;\n"
	"	(*definition)->tokens = null;\n"
	"	(*definition)->types = null;\n"
	"	(*definition)->source = mtrac_strdup(\"\"); // S macro follows after call of this func\n"
	"	(*definition)->line = line;\n"
	"	(*definition)->results = null;\n"
	"	(*definition)->simple = true;\n"
	"	(*definition)->next = null;\n"
	"\n"
	"	rule = &(*definition)->rules;\n"
	"	alternation = &(*definition)->alternations;\n"
	"	alternate = null;\n"
	"	word = null;\n"
	"}\n"
	"\n"
	"void start_rule(mode mode, kind kind) {\n"
	"	assert(definition);\n"
	"	assert(rule);\n"
	"\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: start rule/subrule - %d %d\\n\", mode, kind);\n"
	"	if(*rule) rule = &(*rule)->next;\n"
	"	*rule = mtrac_malloc(sizeof(struct rule));\n"
	"	(*rule)->mode = mode;\n"
	"	(*rule)->kind = kind;\n"
	"	(*rule)->words = null;\n"
	"	(*rule)->keywords = null;\n"
	"	(*rule)->tokens = null;\n"
	"	(*rule)->next = null;\n"
	"\n"
	"	word = &(*rule)->words;\n"
	"	keyword = &(*rule)->keywords;\n"
	"}\n"
	"\n"
	"void add_keyword(char *scan) {\n"
	"	assert(keyword);\n"
	"	assert(!!scan);\n"
	"\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: add keyword - %s \\n\", scan);\n"
	"	if(*keyword) keyword = &(*keyword)->next;\n"
	"	*keyword = mtrac_malloc(sizeof(struct word));\n"
	"	(*keyword)->string = scan ? trim(mtrac_strdup(scan)) : null;\n"
	"	(*keyword)->next = null;\n"
	"\n"
	"	add_word(scan);\n"
	"}\n"
	"\n"
	"void _add_word(char *scan, bool option_start, bool option_end, adjacency space) {\n"
	"	assert(word);\n"
	"	assert(!!scan + option_start + option_end == 1);\n"
	"\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: add word - %s \\n\", scan);\n"
	"	if(*word) word = &(*word)->next;\n"
	"	*word = mtrac_malloc(sizeof(struct word));\n"
	"	(*word)->string = scan ? trim(mtrac_strdup(scan)) : null;\n"
	"	(*word)->option_start = option_start;\n"
	"	(*word)->option_end = option_end;\n"
	"	(*word)->adjacency = space;\n"
	"	(*word)->next = null;\n"
	"}\n"
	"\n"
	"void add_word(char *string) {\n"
	"	assert(string && *string);\n"
	"	_add_word(string, false, false, not_applicable);\n"
	"}\n"
	"\n"
	"bool _add_token(stringlist **tokens, const char *string, stringlist *only, stringlist *ignores, ordering keep_order, char *var, char *file, int line) {\n"
	"	assert(string && *string);\n"
	"	if(opt_debug_lists) fprintf(stderr, \"lists  : maybe add token '%s'\\n\", string);\n"
	"\n"
	"	/* check list of strings to be ignored (i.e. not added) */\n"
	"	if(only) {\n"
	"		do if(!strcmp(only->string, string)) goto pass; while((only = only->next));\n"
	"		return false;\n"
	"	}\n"
	"	pass:\n"
	"\n"
	"	/* check list of strings to be ignored (i.e. not added) */\n"
	"	while(ignores) {\n"
	"		if(!strcmp(ignores->string, string)) return false;\n"
	"		ignores = ignores->next;\n"
	"	}\n"
	"\n"
	"	/* search if it is already listed, and for its right place */\n"
	"	stringlist *next = *tokens, **prev = tokens;\n"
	"	int order = 1;\n"
	"	while(next && (keep_order || (order = strcmp(string, next->string)) > 0)) {\n"
	"		if(opt_debug_lists) fprintf(stderr, \"lists  : next: '%s'\\n\", next->string);\n"
	"		prev = &next->next; next = next->next;\n"
	"	}\n"
	"	/* if not in the token list, add the new token */\n"
	"	bool added = false;\n"
	"	if(order != 0) {\n"
	"		if(opt_debug_lists) fprintf(stderr, \"lists  : now adding '%s' (next: %p, current prev: %p)\\n\", string, next, *prev);\n"
	"		stringlist *n = _mtrac_malloc(sizeof(stringlist), var, file, line);\n"
	"		n->string = _mtrac_strdup(string, var, file, line); // many lists and their strings are note free'd\n"
	"		n->next = next;\n"
	"		*prev = n;\n"
	"		added = true;\n"
	"	}\n"
	"\n"
	"	stringlist *t = *tokens;\n"
	"	while(t) {\n"
	"		if(opt_debug_lists) fprintf(stderr, \"lists  : %p ⟶  '%s'\\n\", t, t->string);\n"
	"		t = t->next;\n"
	"	}\n"
	"	/* note that there is no need to point into the list. Flex uses the string itself */\n"
	"	return added;\n"
	"}\n"
	"\n"
	"bool in_list(stringlist *token, const char *string) {\n"
	"	while(token) {\n"
	"		if(!strcmp(token->string, string)) return true;\n"
	"		token = token->next;\n"
	"	}\n"
	"	return false;\n"
	"}\n"
	"\n"
	"int count_in_list(stringlist *token, const char *string) {\n"
	"	int cnt = 0;\n"
	"	while(token) {\n"
	"		if(!strcmp(token->string, string)) cnt++;\n"
	"		token = token->next;\n"
	"	}\n"
	"	return cnt;\n"
	"}\n"
	"\n"
	"void delete_stringlist(stringlist *list) {\n"
	"\n"
	"	stringlist *t;\n"
	"	while(list) { if(list->string) mtrac_free(list->string); t = list; list = list->next; mtrac_free(t); }\n"
	"}\n"
	"\n"
	"void delete_map(map *_map) {\n"
	"\n"
	"	map *m;\n"
	"	while(_map) { // printf(\"deleting %s -> %s\\n\", _map->key, _map->value);\n"
	"		 if(_map->key) mtrac_free(_map->key); if(_map->value) mtrac_free(_map->value); m = _map; _map = _map->next; mtrac_free(m); }\n"
	"}\n"
	"\n"
	"void delete_node_list(node *list) {\n"
	"\n"
	"	node *n;\n"
	"	while(list) {\n"
	"		if(list->find) mtrac_free(list->find);\n"
	"		if(list->repl) mtrac_free(list->repl);\n"
	"		n = list; list = list->prev; mtrac_free(n);\n"
	"	}\n"
	"	list = null;\n"
	"}\n"
	"\n"
	"/* switch forward the map entry of the current clause to collect its literal text for comments */\n"
	"void new_lexcom(const char *name, const char *value) {\n"
	"\n"
	"	// cut leading 'clause: '\n"
	"	assert(name);\n"
	"	while(*name == ' ') name++;\n"
	"	if(!strncmp(LOW(name), \"clause\", 6)) {\n"
	"		name += 6;\n"
	"		while(*name == ' ') name++;\n"
	"		while(*name == ':') name++;\n"
	"		while(*name == ' ') name++;\n"
	"	} else if(!strncmp(LOW(name), \"terms\", 5)) {\n"
	"		name += 5;\n"
	"		while(*name == ' ') name++;\n"
	"		if(!strncmp(LOW(name), \"per\", 3)) name += 3;\n"
	"		while(*name == ' ') name++;\n"
	"	}\n"
	"	if(strchr(name, ':'))\n"
	"		*strchr(name, ':') = 0;\n"
	"\n"
	"	map *m = lexcoms;\n"
	"	// prevent double use of clause or covenant name (◊ sort elsewhere)\n"
	"	if(!opt_debug_allow_double_names) {\n"
	"		while(m) {\n"
	"			if(!strcmp(LOW(snake_spaced(name)), m->key)) {\n"
	"				// except, allow multiple _pre_ entries\n"
	"				// ◊ _pre_ entries, if any, are never used.\n"
	"				if(strcmp(name, \"_pre_\")) {\n"
	"					fprintf(stderr, \"clause or covenant name used twice: %s\", name);\n"
	"					exit(1);\n"
	"				}\n"
	"			}\n"
	"			m = m->next;\n"
	"		}\n"
	"	}\n"
	"\n"
	"	// trim previous (sic) entry's value\n"
	"	m = lexcoms;\n"
	"	if(m && m->value && *m->value) {\n"
	"		char *e = m->value + strlen(m->value) -1;\n"
	"		while(e > m->value && (*e == ' ' || *e == '\\t' || *e == '\\n')) e--;\n"
	"		if(e > m->value) *(e+1) = 0;\n"
	"	}\n"
	"\n"
	"	// add map entry\n"
	"	m = _mtrac_malloc(sizeof(map), \"lexcom node\", __FILE__, __LINE__);\n"
	"	m->key = mtrac_strdup(LOW(snake_spaced(name)));\n"
	"	m->value = mtrac_strdup(value);\n"
	"	m->next = lexcoms;\n"
	"	lexcoms = m;\n"
	"}\n"
	"\n"
	"const char *get_lexcom(const char *name) {\n"
	"\n"
	"	map *m = lexcoms;\n"
	"	while(m) {\n"
	"		if(!strcmp(LOW(snake_spaced(name)), m->key))\n"
	"			return m->value;\n"
	"		m = m->next;\n"
	"	}\n"
	"	return \"\";\n"
	"}\n"
	"\n"
	"void start_option(adjacency space) {\n"
	"	_add_word(null, true, false, space);\n"
	"}\n"
	"\n"
	"void end_option(adjacency space) {\n"
	"	_add_word(null, false, true, space);\n"
	"}\n"
	"\n"
	"void start_alternation(char *scan) {\n"
	"	assert(scan && *scan);\n"
	"\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: start alternation - '%s'\\n\", scan);\n"
	"	if(*alternation) alternation = &(*alternation)->next;\n"
	"	*alternation = mtrac_malloc(sizeof(struct alternation));\n"
	"	(*alternation)->string = trim(mtrac_strdup(scan));\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: alternation string - '%s'\\n\", (*alternation)->string);\n"
	"	(*alternation)->alternates = null;\n"
	"	(*alternation)->next = null;\n"
	"\n"
	"	alternate = &(*alternation)->alternates;\n"
	"}\n"
	"\n"
	"void start_alternate() {\n"
	"	assert(alternate);\n"
	"\n"
	"	if(opt_debug_generator) fprintf(stderr, \"gentor.: start atlernate ..\\n\");\n"
	"	if(*alternate) alternate = &(*alternate)->next;\n"
	"	*alternate = mtrac_malloc(sizeof(struct alternate));\n"
	"	(*alternate)->words = null;\n"
	"	(*alternate)->next = null;\n"
	"\n"
	"	word = &(*alternate)->words;\n"
	"}\n"
	"\n"
	"void continue_rule() {\n"
	"	word = &(*rule)->words;\n"
	"	while(*word && (*word)->next) word = &(*word)->next;\n"
	"}\n"
	"\n"
	"void end_rule() {\n"
	"}\n"
	"\n"
	"void add_embed(char *s) {\n"
	"	if(!embed) embed = mtrac_strdup(s);\n"
	"	else concat(&embed, s);\n"
	"}\n"
	"\n"
	"/* build the resulting BNF, as string, from the LGF tree */\n"
	"void produce_grammar(struct definition *definition) {\n"
	"\n"
	"	if(!definition) return;\n"
	"	assert(definition->rules);\n"
	"	assert(!definition->results);\n"
	"\n"
	"	/* head of main yacc feed file */\n"
	"	char *requires =\n"
	"		\"#define CYCLE_2 true\\n\\n\"\n"
	"		\"#include <stdio.h>\\n\"\n"
	"		\"#include <string.h>\\n\\n\"\n"
	"		\"int yylex(void);\\n\"\n"
	"		\"void yyerror(const char *);\\n\\n\"\n"
	"		\"void *mtrac_gross(void *);\\n\\n\"\n"
	"		\"#define NEW(type, literal) \\\\\\n\"\n"
	"		\"	if(opt_debug_tokens) fprintf(stderr, \\\"tokens : creating node for \\\" #type \\\"'%s'\\\\n\\\", literal); \\\\\\n\"\n"
	"		\"	type *type = mtrac_malloc(sizeof(struct type)); \\\\\\n\"\n"
	"		\"	mtrac_gross(type); \\\\\\n\"\n"
	"		\"	memset(type, 0, sizeof(struct type)); \\\\\\n\"\n"
	"		\"	type->Literal = literal;\\n\"\n"
	"		\"#define mtrac_malloc(size_) _mtrac_malloc(size_, \\\"[unknown]\\\", __FILE__, __LINE__)\\n\"\n"
	"		\"#define mtrac_strdup(string_) _mtrac_strdup(string_, \\\"[unknown]\\\", __FILE__, __LINE__)\\n\"\n"
	"		\"#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)\\n\"\n"
	"		\"void *_mtrac_malloc(size_t size, char *name, char *file, int line);\\n\"\n"
	"		\"void *_mtrac_strdup(const char *string, char *name, char *file, int line);\\n\"\n"
	"		\"char *_mtrac_dupcat(const char *string, ...);\\n\"\n"
	"		\"void _mtrac_free(void *p, char *name, char *file, int line);\\n\"\n"
	"		\"#define YYFPRINTF yacc_printf\\n\"\n"
	"		\"typedef int bool;\\n\"\n"
	"		\"#define false 0\\n\"\n"
	"		\"#define true 1\\n\"\n"
	"		\"#define null (void *)0\\n\\n\"\n"
	"		\"typedef char Literal;\\n\"\n"
	"		\"typedef char Name;\\n\"\n"
	"		\"typedef char Description;\\n\"\n"
	"		\"typedef char Scalar;\\n\\n\"\n"
	"		\"typedef char Hex;\\n\\n\"\n"
	"		\"#define padcat(down_, right_, var_, ...) \\\\\\n\"\n"
	"		\"	_concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)\\n\"\n"
	"		\"char **_concat(char *, char*, int, int, int, char **buf, ...);\\n\"\n"
	"		\"void yacc_printf(FILE *stream, char *format, ...);\\n\\n\"\n"
	"		\"extern bool opt_produce_tree;\\n\"\n"
	"		\"extern bool opt_produce_flat;\\n\"\n"
	"		\"extern bool opt_produce_terse;\\n\"\n"
	"		\"extern bool opt_debug;\\n\"\n"
	"		\"extern bool opt_verbose;\\n\"\n"
	"		\"extern bool opt_debug_actions;\\n\\n\"\n"
	"		\"extern bool opt_debug_tokens;\\n\\n\"\n"
	"		\"extern char *opening_bracket;\\n\\n\"\n"
	"		\"extern char *closing_bracket;\\n\\n\"\n"
	"		\"extern bool bracket_just_closed; // optics: helps with line breaks in produced core code\\n\\n\"\n"
	"		\"extern unsigned int grid; // optics: bitpattern of vertical tree branch lines, across rows\\n\\n\";\n"
	"\n"
	"	char *lex = mtrac_strdup(\" /* Keywords (generated from LGF) */\\n\");\n"
	"	char *prol = mtrac_strdup(\"/* - */\");\n"
	"	char *req = mtrac_strdup(\"%code requires {\\n\\n\"); concat(&req, requires);\n"
	"	char *enu = mtrac_strdup(\"typedef enum types {\\n\");\n"
	"	char *uni = mtrac_strdup(\"typedef union node {\\n\"); // \\tname *name;\\n\\tdescription *description;\\n\");\n"
	"	char *stru = mtrac_strdup(\"/* AST nodes = semantic value types (in actions, the respective types of '$$') */\\n\\n\");\n"
	"	char *decl = mtrac_strdup(\"/* Mapping C types to tokens */\\n\\n\"\n"
	"				\"%define api.value.type union\\n\\n\"\n"
	"				\"%define parse.error detailed\\n\"\n"
	"				\"%define lr.type ielr\\n\"\n"
	"				//\"%define parse.lac full\\n\"\n"
	"				\"%glr-parser\\n\"\n"
	"				//\"%expect-rr 1\\n\"\n"
	"				\"%define parse.trace\\n\\n\");\n"
	"	char *bnf = mtrac_strdup(\"\");\n"
	"	char *fdecl = mtrac_strdup(\"/* action handler (stub) functions */\\n\");\n"
	"	char *funcs = mtrac_strdup(\"/* action handler (stub) functions */\\n\\n\");\n"
	"	char *tdecl = mtrac_strdup(\"/* AST walk (stub) functions */\\n\\n\");\n"
	"	char *templ = mtrac_strdup(\"/* AST walk (stub) functions */\\n\\n\");\n"
	"	stringlist *results = new_result_dup(null, \"\", no_pipe);\n"
	"\n"
	"	if(opt_verbose || opt_debug) printf(\"• constructing rules\\n\");\n"
	"\n"
	"	/* rules */\n"
	"	char *last = null;\n"
	"	while(definition) {\n"
	"		char *prefix = mtrac_strdup(\"\"); // catdup(definition->name, \"_\", tolower);\n"
	"\n"
	"		/* traverse all words, options and synonyms to create a list of result strings */\n"
	"		assert(definition->rules);\n"
	"		definition->simple = !definition->rules->next;\n"
	"\n"
	"		/* echo lgf source into output */\n"
	"		if(opt_comment) {\n"
	"			char *c = mtrac_strdup(\"/* \");\n"
	"			concat(&c, /* str(definition->line), \": \", */ trim(definition->source), \" */\");\n"
	"			replace(&c, \"\\n\", \"\\n\\t * \");\n"
	"			concat(&c, \"\\n\");\n"
	"			new_result(results, c, no_pipe);\n"
	"		}\n"
	"\n"
	"		char *tag = mtrac_strdup(\"\");\n"
	"		//concat(&tag, definition->name, rule->mode == active ? \"_predicate\" : \"_predicament\");\n"
	"		concat(&tag, definition->name);\n"
	"		add_token(&tokens, tag, null, predef, sort); // (x)\n"
	"		concat(&tag, \":\\t\");\n"
	"		new_result(results, tag, no_pipe);\n"
	"\n"
	"		struct rule *rule = definition->rules;\n"
	"		bool frst = true;\n"
	"		do {\n"
	"			produce_rule(new_result_dup(results, \"\\t  \", frst ? no_pipe : with_pipe),\n"
	"				definition, rule, rule->words, null, unspaced, prefix, false);\n"
	"			frst = false;\n"
	"		} while((rule = rule->next));\n"
	"		new_result_dup(results, \"\\t;\\n\\n\", no_pipe);\n"
	"\n"
	"		/* enums, type and structure declarations */\n"
	"		concat(&enu, \"\\t\", definition->name, \",\\n\");\n"
	"		concat(&uni, \"\\t\", definition->name , \" \", definition->name, \";\\n\");\n"
	"		stringlist *token = definition->tokens;\n"
	"		stringlist *types = definition->types;\n"
	"		concat(&stru, \"typedef struct \", definition->name, \" {\\n\");\n"
	"		while(token) {\n"
	"			if(!strcmp(token->string, \"Literal\")\n"
	"			|| !strcmp(token->string, \"Name\")\n"
	"			|| !strcmp(token->string, \"Description\")\n"
	"			|| !strcmp(token->string, \"Scalar\")\n"
	"			|| !strcmp(token->string, \"Hex\"))\n"
	"				concat(&stru, \"\\t\", types->string, \" *\", token->string, \";\\n\");\n"
	"			else {\n"
	"				concat(&stru, \"\\tstruct \", types->string, \" *\", token->string, \";\\n\");\n"
	"			}\n"
	"			token = token->next;\n"
	"			types = types->next;\n"
	"		}\n"
	"		concat(&stru, \"\\tLiteral *Literal;\\n} \", definition->name, \";\\n\\n\");\n"
	"\n"
	"		/* action handler (parse) functions and their declarations */\n"
	"		concat(&fdecl, definition->name, \" *process_\", LOW(definition->name), \"(\", definition->name, \" *\", definition->name, \");\\n\");\n"
	"		concat(&funcs, definition->name, \" *process_\", LOW(definition->name), \"(\", definition->name, \" *\", definition->name, \") {\\n\"\n"
	"			\"\\tif(opt_debug_actions) printf(\\\"actions: parsing \", definition->name);\n"
	"		if(in_list(definition->tokens, \"Name\")) concat(&funcs, \" %s\\\\n\\\", \", definition->name, \"->Name);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Description\")) concat(&funcs, \" %s\\\\n\\\", \", definition->name, \"->Description);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Scalar\")) concat(&funcs, \" %s\\\\n\\\", \", definition->name, \"->Scalar);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Hex\")) concat(&funcs, \" %s\\\\n\\\", \", definition->name, \"->Hex);\\n\");\n"
	"		else concat(&funcs, \" '%s'\\\\n\\\", \", definition->name, \"->Literal);\\n\");\n"
	"\n"
	"		// List struct elements in commented-out rows\n"
	"		token = definition->tokens;\n"
	"		while(token) {\n"
	"			concat(&funcs, \"\\t// \", definition->name, \"->\", token->string, \"\\n\");\n"
	"			token = token->next;\n"
	"		}\n"
	"		concat(&funcs, \"\\treturn \", definition->name,\";\\n}\\n\\n\");\n"
	"\n"
	"		/* AST walk (code production) template functions and their declarations. Obviously, the following\n"
	"		   is code that produces code that produces code.  */\n"
	"		concat(&tdecl, \"/*T*/\\tbool \", opt_langprefix, \"_\", LOW(definition->name),\n"
	"			\"(char **production, \", definition->name, \" *\", definition->name,\n"
	"			\", int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);\\n\");\n"
	"		concat(&templ, \"/*T*/\\tbool \", opt_langprefix, \"_\", LOW(definition->name),\n"
	"			\"(char **production, \", definition->name, \" *\", definition->name,\n"
	"			\", int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\\n\");\n"
	"		concat(&templ, \"/*T*/\\t\\tif(!\", definition->name, \") return false;\\n\");\n"
	"\n"
	"		/* debug output */\n"
	"		concat(&templ, \"/*T*/\\t\\tif(opt_debug) printf(\\\"producing \", definition->name);\n"
	"		if(in_list(definition->tokens, \"Name\")) concat(&templ, \" %s\\\\n\\\", \", definition->name, \"->Name);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Description\")) concat(&templ, \" %s\\\\n\\\", \", definition->name, \"->Description);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Scalar\")) concat(&templ, \" %s\\\\n\\\", \", definition->name, \"->Scalar);\\n\");\n"
	"		else if(in_list(definition->tokens, \"Hex\")) concat(&templ, \" %s\\\\n\\\", \", definition->name, \"->Hex);\\n\");\n"
	"		else concat(&templ, \"\\\\n\\\");\\n\\n\"); //*** literal!\n"
	"\n"
	"		/* arbitrary coloring of tokens */\n"
	"		concat(&templ, \"/*T*/\\t\\tchar *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, \\\"\",\n"
	"			LOW(dash_spaced(definition->name)), \"\\\")) ? opt_color : \\\"\\\";\\n\" );\n"
	"		concat(&templ, \"/*T*/\\t\\tchar *off = *color ? \\\"\\\\033[0m\\\" : \\\"\\\";\\n\" );\n"
	"\n"
	"		/* actual command production */\n"
	"		bool has_leaf = !!definition->tokens;\n"
	"		bool recursive = in_list(definition->tokens, definition->name) && !definition->tokens->next->next;\n"
	"		char *match = _mtrac_dupcat(\"\", \",\", definition->name, \",\", null);\n"
	"		char *no_break_list = \",Type,Symbol,Combination,Combinand,Combinor,Combinator\";\n"
	"		bool no_break = !!strstr(no_break_list, match);\n"
	"		bool skip = !!strstr(\",Type_Term,Body\", match);\n"
	"		mtrac_free(match);\n"
	"\n"
	"		char *production_name = mtrac_strdup(LOW(dash_spaced(definition->name)));\n"
	"\n"
	"		/* tree production (same as core case 'has_leaf') */\n"
	"		concat(&templ, \"/*T*/\\t\\tbool sameline;\\n\");\n"
	"		if(recursive) {\n"
	"			concat(&templ, \"/*T*/\\t\\tbool has_more_recursion = !!\", definition->name, \"->\", definition->name, \";\\n\");\n"
	"			concat(&templ, \"/*T*/\\t\\tbool skipped = (!opt_produce_tree || opt_produce_flat) \"\n"
	"				\"&& !!\", definition->name, \"->\", definition->name, \";\\n\");\n"
	"		} else {\n"
	"			concat(&templ, \"/*T*/\\t\\tbool has_more_recursion = false;\\n\");\n"
	"			concat(&templ, \"/*T*/\\t\\tbool skipped = false;\\n\");\n"
	"		}\n"
	"		concat(&templ, \"/*T*/\\t\\tbool terse = opt_produce_terse && (skipped || (1 == 0\");\n"
	"		token = definition->tokens;\n"
	"		while(token) { concat(&templ, \" + (!!\", definition->name, \"->\", token->string, \"?1:0)\"); token = token->next; }\n"
	"		concat(&templ, \"));\\n\");\n"
	"\n"
	"		/* tree: produce actual node name, for tree display */\n"
	"		concat(&templ, \"/*T*/\\t\\tif(opt_produce_tree) {\\n\");\n"
	"		concat(&templ, \"/*T*/\\t\\t\\tif(!(opt_produce_flat && has_more_recursion) && !terse)\\n\");\n"
	"		concat(&templ, \"/*T*/\\t\\t\\t\\t\", \"padcat(\", definition==grammar?\"0\":\"1\", \", indent, production, \\\"\",\n"
	"			definition!=grammar?\"↳  \":\"   \", \"\\\", color, \\\"\", production_name, \"\\\", off, \\\" \\\");\\n\"); // ↳\n"
	"\n"
	"		/* core: skips some, unpacks the binary nesting and uses less lines */\n"
	"		concat(&templ, \"/*T*/\\t\\t} else {\\n\");\n"
	"		if(!skip) {\n"
	"			if(recursive)\n"
	"				/* list conversion: those definitions that have a leaf that is of their own type are not printed\n"
	"				   when that leaf is not null this produces lists instead of nested binary nodes. Note the produced\n"
	"				   if lives two runtimes later. It leaves it to the next nested instance to produce (or to also\n"
	"				   pass until the last of these) */\n"
	"				concat(&templ, \"/*T*/\\t\\t\\tif(!has_more_recursion && !terse) {\\n\");\n"
	"			if(no_break) {\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\",\n"
	"					\"\\t\\t\\tpadcat(bracket_just_closed?1:0, bracket_just_closed?indent:0,\"\n"
	"					\" production, opening_bracket, \\\" \\\", color, \\\"\", production_name, \"\\\", off, \\\" \\\");\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tsameline = !bracket_just_closed;\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tbracket_just_closed = false;\\n\");\n"
	"			} else if(has_leaf) {\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tpadcat(\", definition==grammar?\"0\":\"1\", \", indent,\"\n"
	"					\" production, opening_bracket, \\\" \\\", color, \\\"\", production_name,\"\\\", off, \\\" \\\");\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tsameline = false;\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tbracket_just_closed = false;\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tsameline = false;\\n\");\n"
	"			} else {\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tpadcat(bracket_just_closed?1:0, bracket_just_closed?indent:0,\"\n"
	"					\" production, color, \\\"\", production_name, \"\\\", off, \\\" \\\");\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tsameline = !bracket_just_closed;\\n\");\n"
	"				concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\t\\tbracket_just_closed=false;\\n\");\n"
	"			}\n"
	"			if(recursive) {\n"
	"				concat(&templ, \"/*T*/\\t\\t\\t} else\\n\");\n"
	"				concat(&templ, \"/*T*/\\t\\t\\t\\tsameline = true;\\n\");\n"
	"			}\n"
	"		}\n"
	"		mtrac_free(production_name);\n"
	"\n"
	"		// /* for leafless tokens print literal: the actual word that triggered the token */\n"
	"		// if(!definition->tokens) concat(&templ, \", \\\"«\\\", \", definition->name, \"->Literal\", \", \\\"»\\\" \"); ◊ clean up / make option\n"
	"\n"
	"		concat(&templ, \"/*T*/\\t\\t}\\n\");\n"
	"\n"
	"		/* *** calls to constituting leaves *** */\n"
	"\n"
	"		/* sorting recursion to top: */\n"
	"		token = definition->tokens;\n"
	"		types = definition->types;\n"
	"		stringlist *prevto = null;\n"
	"		stringlist *prevty = null;\n"
	"		while(token) {\n"
	"			if(!strcmp(definition->name, token->string)) {\n"
	"				/* bring recursion top */\n"
	"				if(prevto) {\n"
	"					prevto->next = token->next;\n"
	"					prevty->next = types->next;\n"
	"					token->next = definition->tokens;\n"
	"					types->next = definition->types;\n"
	"					definition->tokens = token;\n"
	"					definition->types = types;\n"
	"				}\n"
	"				break;\n"
	"			}\n"
	"			prevto = token;\n"
	"			prevty = types;\n"
	"			token = token->next;\n"
	"			types = types->next;\n"
	"		}\n"
	"\n"
	"		/* producing calls */\n"
	"		token = definition->tokens;\n"
	"		types = definition->types;\n"
	"		const char *stop = \",Article,This_Contract,Be,Catena,Illocutor,Preposition,\";\n"
	"		concat(&templ, \"/*T*/\\t\\tbool sibbling_follows;\\n\");\n"
	"		if(recursive)\n"
	"			concat(&templ, \"/*T*/\\t\\tif(!opt_produce_flat) grid <<= 1;\\n\");\n"
	"		else\n"
	"			concat(&templ, \"/*T*/\\t\\tgrid <<= !terse ? 1 : 0;\\n\");\n"
	"		concat(&templ, \"/*T*/\\t\\tint irx = !terse ? 1 : 0;\\n\");\n"
	"\n"
	"		/* individual leaf calls, including the recursing 'namesake' */\n"
	"		while(token) {\n"
	"			bool stopped = !!strstr(stop, token->string);\n"
	"			bool namesake = !strcmp(definition->name, token->string);\n"
	"\n"
	"			if(stopped) {\n"
	"				if(!strstr(\"article,this\", LOW(types->string)))\n"
	"					concat(&templ, \"/*T*/\\t\\tif(true) {\\n\");\n"
	"				else\n"
	"					concat(&templ, \"/*T*/\\t\\tif(opt_produce_tree) {\\n\");\n"
	"			}\n"
	"			if(!recursive)\n"
	"				concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\", \"if(!terse) grid &= 4294967294;\\n\");\n"
	"			if(token->next) {\n"
	"				concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\", \"sibbling_follows = !!(\");\n"
	"				stringlist *succ = token->next;\n"
	"				stringlist *start = succ;\n"
	"				if(!succ)\n"
	"					concat(&templ, \"false\");\n"
	"				while(succ) {\n"
	"					concat(&templ, succ!=start?\" || \":\"\", definition->name, \"->\", succ->string);\n"
	"					succ = succ->next;\n"
	"				}\n"
	"				concat(&templ, \");\\n\");\n"
	"				if(!recursive || !namesake)\n"
	"					concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\",\n"
	"						\"if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows;\"\n"
	"						\" if(line) grid |=1; }\\n\");\n"
	"				else\n"
	"					concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\",\n"
	"						\"if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows;\"\n"
	"						\" if(line) grid |= 1; }\\n\");\n"
	"			}\n"
	"			else\n"
	"				concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\", \"sibbling_follows = false;\\n\");\n"
	"\n"
	"\n"
	"			if(recursive && namesake) {\n"
	"				concat(&templ, \"/*T*/\\t\\tirx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;\\n\");\n"
	"			} else {\n"
	"				// concat(&templ, \"/*T*/\\t\\tirx = \", strstr(no_break_list, token->string) ? \"0\" : \"1\", \";\\n\");\n"
	"				concat(&templ, \"/*T*/\\t\\tirx = !terse ? 1 : 0;\\n\");\n"
	"				concat(&templ, \"/*T*/\\t\\tif(opt_produce_tree && opt_produce_flat) grid |= sibbling;\\n\");\n"
	"			}\n"
	"\n"
	"			concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\", \"if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;\\n\");\n"
	"\n"
	"\n"
	"			/* *** actual call to the leaf *** */\n"
	"			char *type = lowdup(types->string);\n"
	"			char *name = lowdup(definition->name);\n"
	"			concat(&templ, \"/*T*/\\t\\t\", stopped?\"\\t\":\"\", opt_langprefix, \"_\", type,\n"
	"				\"(production, \",\n"
	"				definition->name, \"->\", token->string,\n"
	"				\", indent+irx, \",\n"
	"				namesake?\"false, \":\"true, \",\n"
	"				recursive?\"sibbling_follows && skipped\":\"false\", namesake?\"|| sibbling\":\"\",\n"
	"				\", subhighlight || opt_values && !!strstr(opt_values, \\\"\", name, \"\\\")\",\n"
	"				\", opt_subvalues && !!strstr(opt_subvalues, \\\"\", name, \"\\\")\", \");\\n\",\n"
	"				\"/*T*/\\t\\t\", stopped?\"\\t\":\"\", \"subhighlight = false;\\n\");\n"
	"			mtrac_free(type);\n"
	"			mtrac_free(name);\n"
	"\n"
	"			/* delayed grid shift for skipped recursives */\n"
	"			if(recursive && namesake) {\n"
	"				concat(&templ, \"/*T*/\\t\\tif(opt_produce_flat) grid <<= !terse ? 1 : 0;\\n\");\n"
	"			}\n"
	"\n"
	"			if(stopped)\n"
	"				concat(&templ, \"/*T*/\\t\\t}\\n\");\n"
	"\n"
	"			token = token->next;\n"
	"			types = types->next;\n"
	"		}\n"
	"\n"
	"		concat(&templ, \"/*T*/\\t\\tgrid >>= !terse ? 1 : 0;\\n\");\n"
	"\n"
	"		/* closing bracket of the production of this node */\n"
	"		if((no_break || has_leaf) && !skip) {\n"
	"			/* list conversion: those definitions that have a leaf that is of their own type are not\n"
	"			   printed when that leaf is not null this produces lists instead of nested binary nodes.\n"
	"			   Note the produced if lives two runtimes later. */\n"
	"			if(recursive)\n"
	"				concat(&templ, \"/*T*/\\t\\tif(topcall) {\\n\");\n"
	"			concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\tpadcat(0, 0, production, opt_produce_tree?\\\"\\\":closing_bracket, \\\"\",\n"
	"				definition==grammar?\"\\\\n\":\" \", \"\\\");\\n\");\n"
	"			concat(&templ, \"/*T*/\", recursive?\"\\t\":\"\", \"\\t\\tbracket_just_closed=true;\\n\");\n"
	"			if(recursive)\n"
	"				concat(&templ, \"\\t\\t}\\n\");\n"
	"		}\n"
	"\n"
	"		/* return and end of function body */\n"
	"		concat(&templ, \"\\n/*T*/\\t\\treturn true;\\n/*T*/\\t}\\n/*T*/\\n\");\n"
	"\n"
	"		mtrac_free(prefix);\n"
	"\n"
	"		definition = definition->next;\n"
	"		if(definition) new_result_dup(results, \"\", no_pipe);\n"
	"	}\n"
	"	concat(&enu, \"};\\n\\n\");\n"
	"	concat(&uni, \"};\\n\\n\");\n"
	"\n"
	"	/* the Yacc %tokens tags: predefined tokens, plus .. */\n"
	"	stringlist *token = predef;\n"
	"//	concat(&decl, \"\\t%type <Literal *> Literal\\n\");\n"
	"	while(token) {\n"
	"		if(in_list(ignores, token->string))\n"
	"			concat(&decl, \"\\t%token \", UP(token->string), \"\\n\");\n"
	"		else { // name, description\n"
	"			concat(&decl, \"\\t%token <\", UP(token->string), \" *> \", literal_symbol(token->string), \"\\n\");\n"
	"			concat(&decl, \"\\t%nterm <\", UP(token->string), \" *> \", UP(token->string), \"\\n\"); // UP buffer ok here\n"
	"		}\n"
	"		token = token->next;\n"
	"	}\n"
	"	/* .. from tokens as produced at (x) and (xx) */\n"
	"	token = tokens;\n"
	"	while(token) {\n"
	"		if(strchr(token->string, '\"'))\n"
	"			concat(&decl, \"\\t%token \", literal_symbol(token->string), \"\\n\");\n"
	"		else\n"
	"			concat(&decl, \"\\t%nterm <\", UP(token->string), \" *> \", UP(token->string), \"\\n\"); // UP buffer ok here\n"
	"		token = token->next;\n"
	"	}\n"
	"\n"
	"	/* keywords: the Lexer parse patterns and token values of all found literals (case insensitivity presumed) */\n"
	"	token = tokens;\n"
	"	while(token) {\n"
	"		if(strchr(token->string, '\"'))\n"
	"			concat(&lex, token->string, strlen(token->string)<10?\"\\t\":\"\",\n"
	"				\"\\t\\t\\t\\t\\t\\t\\t{ D; *((char **)&yylval) = mtrac_strdup_gross(yytext); return \", literal_symbol(token->string), \"; }\\n\");\n"
	"		token = token->next;\n"
	"	}\n"
	"	concat(&lex, \"{termpart} /* no space to not erron. make it longest match */\"\n"
	"		\" { D; syntax(\\\"unexpected word (after precompilation, use -P to check)\\\", yytext); }\\n\");\n"
	"\n"
	"	/* the BNF (-G) rule result strings, which are built up logically in parallel, are now joined sequentially */\n"
	"	stringlist *result = results;\n"
	"	while(result) {\n"
	"		if(result->string) concat(&bnf, \"\\t\", result->string, \"\\n\");\n"
	"		result = result->next;\n"
	"	}\n"
	"	/* add standard predefined rules for names, descriptions and scalars */\n"
	"	concat(&bnf, \"\\tName: NAME\\t\\t\\t\\t\\t\\t{ $$=$NAME; }\\n\\t    ;\\n\\n\");\n"
	"	concat(&bnf, \"\\tDescription: DESCRIPTION\\t\\t\\t\\t\\t\\t{ $$=$DESCRIPTION; }\\n\\t    ;\\n\\n\");\n"
	"	concat(&bnf, \"\\tScalar: SCALAR\\t\\t\\t\\t\\t\\t{ $$=$SCALAR; }\\n\\t    ;\\n\\n\");\n"
	"	//# concat(&bnf, \"\\tHex: HEX\\t\\t\\t\\t\\t\\t{ $$=$HEX; }\\n\\t    ;\\n\\n\");\n"
	"\n"
	"	/* note, much of what was produced above can remain unused below if not asked for by command line options, e.g. -G, -Y etc */\n"
	"\n"
	"	if(opt_verbose || opt_debug) printf(\"• output\\n\");\n"
	"\n"
	"	/* create examples - this can get many - AND check for missing definitions. An error stops the rest below */\n"
	"	if(opt_samples) {\n"
	"		stringlist *examples = new_result_dup(null, \"\", false);\n"
	"		struct word *word = new(struct word, word);\n"
	"		word->string = mtrac_strdup(grammar->name);\n"
	"		char contract_name[1000]; *contract_name = 0;\n"
	"		char clause_name[1000]; *clause_name = 0;\n"
	"		char last_defined[1000]; *last_defined = 0;\n"
	"		bool separated = true;\n"
	"		int names = 0;\n"
	"		int texts = 0;\n"
	"		int count = 1; // sic\n"
	"		if(opt_verbose) fprintf(stderr, \"• building examples\\n\");\n"
	"		produce_examples(&examples, 0, word, grammar, contract_name, clause_name, last_defined, &separated, &names, &texts, \"\", &count, 5);\n"
	"		if(strlen(opt_samples) || !opt_quiet) write_examples(examples, count);\n"
	"		delete_stringlist(examples);\n"
	"		mtrac_free(word->string);\n"
	"		mtrac_free(word);\n"
	"		word = null;\n"
	"	}\n"
	"\n"
	"	/* keyword tokens (sorted case-insensitively) */\n"
	"	if(opt_keywords) {\n"
	"		stringlist *keys = null;\n"
	"		token = tokens;\n"
	"		while(token) {\n"
	"			if(strchr(token->string, '\"')) {\n"
	"				add_token(&keys, literal_symbol(token->string), null, null, sort);\n"
	"			}\n"
	"			token = token->next; }\n"
	"		token = keys;\n"
	"		while(token) { mtrac_concat(&keywords, token->string, \"\\n\"); token = token->next; }\n"
	"		delete_stringlist(keys);\n"
	"	}\n"
	"\n"
	"	if(opt_bootstrap)\n"
	"		prepfile(opt_bootstrap, opt_header, opt_source_base, opt_source, lex);\n"
	"\n"
	"	/* print (-B) only the BNF grammar (subset of -Y) */\n"
	"	if(opt_bnf && !opt_quiet) {\n"
	"		printf(\"%s\", bnf);\n"
	"	}\n"
	"\n"
	"	/* print or write (to -Y<file>) the BNF grammar and ancillary functions */\n"
	"	if(opt_yacc) {\n"
	"		if(opt_verbose || opt_debug) {\n"
	"			if(!strlen(opt_yacc))\n"
	"				printf(\"\\n2nd cycle parser file:\\n\"\n"
	"					\"----------------------\\n\"\n"
	"					\"- node structures\\n\"\n"
	"					\"- rules, actions\\n\"\n"
	"					\"- node processing functions\\n\\n\");\n"
	"			else\n"
	"				printf(\"  writing 2nd cycle parser source to file %s\\n\", opt_yacc);\n"
	"		}\n"
	"		char *include = mtrac_strdup(\"\");\n"
	"		//if(opt_header) concat(&include, \"#include \\\"\", opt_header, \"\\\"\\n\");\n"
	"		char *root = mtrac_strdup(\"\"); concat(&root, UP(grammar->name), \" *root;\");\n"
	"		concat(&req, include, /* enu, \"\\n\", */ stru, \"\\n\", root, \"\\n\", /* uni, \"\\n\", */ fdecl, \"}\");\n"
	"		FILE *out = stdout;\n"
	"		if(strlen(opt_yacc)) {\n"
	"			chdir(name_homedir); // assume path to open as relative to dir at program start\n"
	"			if(!(out = fopen(opt_yacc, \"w\"))) { perror(opt_yacc); exit(1); }\n"
	"		}\n"
	"		if(strlen(opt_yacc) || !opt_quiet)\n"
	"			fprintf(out, \"%%{\\n\\n/* Prologue */\\n\\n%s\\n%%}\\n\\n\"\n"
	"				\"/* Requires */\\n\\n%s\\n\\n\"\n"
	"				\"/* Declarations */\\n\\n%s\\n\\n%%%%\\n\\n\"\n"
	"				\"/* Grammar */\\n\\n%s\\n\\n%%%%\\n\\n\"\n"
	"				\"/* Epilogue */\\n\\n%s\\n\\n%s\",\n"
	"				prol, req, decl, bnf, yacc_stub(), funcs);\n"
	"		if(strlen(opt_yacc)) {\n"
	"			fclose(out);\n"
	"			chdir(file_location); // back to source file's absolute location\n"
	"		}\n"
	"		mtrac_free(include);\n"
	"		mtrac_free(root);\n"
	"	}\n"
	"\n"
	"	/* print or write (to -T<file>) the AST tree walk functions */\n"
	"	if(opt_template) {\n"
	"		if(opt_verbose || opt_debug) {\n"
	"			if(!strlen(opt_template))\n"
	"				printf(\"\\nAST walk functions:\\n\"\n"
	"					\"-------------------\\n\"\n"
	"					\"- %s prefix\\n\\n\", opt_langprefix);\n"
	"			else\n"
	"				printf(\"  writing %s_* AST walk functions to file %s\\n\", opt_langprefix, opt_template);\n"
	"		}\n"
	"\n"
	"		replace(&stru, \"\\n\", \"\\n/*T*/\\t\");\n"
	"		char *stub = mtrac_strdup(walk_stub());\n"
	"		replace(&stub, \"<prefix>\", opt_langprefix);\n"
	"		replace(&stub, \"<low-roottype>\", LOW(grammar->name));\n"
	"		replace(&stub, \"<roottype>\", grammar->name);\n"
	"\n"
	"		FILE *out = stdout;\n"
	"		if(strlen(opt_template)) {\n"
	"			chdir(name_homedir); // assume path to open as relative to dir at program start\n"
	"			if(strcmp(opt_template, \"core.c\") && access(opt_template, F_OK ) != -1 ) {\n"
	"				fprintf(stderr, \"walk function file '%s' exists. Please move or delete and try again.\"\n"
	"					\" (Only 'core.c' is not protected this way.)\\n\", opt_template); exit(1);\n"
	"			}\n"
	"			if(!(out = fopen(opt_template, \"w\"))) { perror(opt_template); exit(1); }\n"
	"		}\n"
	"		if(strlen(opt_template) || !opt_quiet) {\n"
	"			fprintf(out, \"/*T*/\\t/* %s code production / AST walk */\\n\\n\", opt_langprefix);\n"
	"			fprintf(out, \"%s\", requires);\n"
	"			fprintf(out, \"%s%s%s\\n\\n%s\", stru, stub, tdecl, templ);\n"
	"		}\n"
	"		if(strlen(opt_template)) {\n"
	"			fclose(out);\n"
	"			chdir(file_location); // back to source file's absolute location\n"
	"		}\n"
	"		mtrac_free(stub);\n"
	"	}\n"
	"\n"
	"	// .. free\n"
	"	delete_stringlist(results);\n"
	"	mtrac_free(lex);\n"
	"	mtrac_free(prol);\n"
	"	mtrac_free(req);\n"
	"	mtrac_free(enu);\n"
	"	mtrac_free(uni);\n"
	"	mtrac_free(stru);\n"
	"	mtrac_free(decl);\n"
	"	mtrac_free(bnf);\n"
	"	mtrac_free(fdecl);\n"
	"	mtrac_free(funcs);\n"
	"	mtrac_free(tdecl);\n"
	"	mtrac_free(templ);\n"
	"	rule = null;\n"
	"	alternation = null;\n"
	"	alternate = null;\n"
	"	word = null;\n"
	"}\n"
	"\n"
	"void produce_examples(stringlist **accu, int depth, struct word *word, struct definition *grammar, char *contract_name,\n"
	"	char *clause_name, char *last_defined,  bool *separated, int *names, int *texts, char *check, int *count, int fuse) {\n"
	"\n"
	"	assert(accu);\n"
	"	stringlist *branch = *accu;\n"
	"	assert(branch);\n"
	"	assert(!branch->next);\n"
	"\n"
	"	bool opn_q = false; // opening quotes have been/are being set.\n"
	"\n"
	"	if(!word && opt_debug_examples)\n"
	"		fprintf(stderr,\n"
	"			\"\\n----------------------------------------\\n\"\n"
	"			\"Reached one end node building example #%d -- now: \\n\\n%s\\n\"\n"
	"			\"----------------------------------------\\n\\n\",\n"
	"			*count, branch->string);\n"
	"	if(!word) return;\n"
	"\n"
	"	char *name = word->string;\n"
	"	if(opt_debug_examples) fprintf(stderr, \"example: %*s%*s ⟶   %s\\n\", 20-fuse, \"\", 20-fuse, \"\", name);\n"
	"\n"
	"//	if(!fuse) { concat(&branch->string, \" [error: recursion stopped for \", name, \"] \"); return; }\n"
	"\n"
	"	/* handle terminals, i.e. literal strings and interpunctuation */\n"
	"	char **add = null;\n"
	"	bool separator_now = false;\n"
	"	int blen = strlen(branch->string);\n"
	"	bool space = !blen || (branch->string)[blen-1] == '\\\"';\n"
	"	bool linestart = !blen || (branch->string)[blen-1] == '\\n';\n"
	"	if(!strcmp(name, \"Clause\")) { strcpy(clause_name, foobar(++*names)); }\n"
	"	if(!strncmp(name, \"Lex\", 4)) { strcpy(contract_name, foobar(++*names)); }\n"
	"	if(!strcmp(name, \"Name\")) {\n"
	"		add = concat(&branch->string, space ? \"\" : \" \", *clause_name?clause_name:*last_defined?last_defined:contract_name);\n"
	"		*clause_name=0;\n"
	"		*separated = false;\n"
	"	}\n"
	"	else if(!strcmp(name, \"Description\")) { add = concat(&branch->string, space ? \"\" : \" \", blind(++*texts)); *separated = false; }\n"
	"	else if(!strcmp(name, \"Scalar\")) { add = concat(&branch->string, space ? \"\" : \" \", \"123\"); *separated = false; }\n"
	"// 	else if(!strcmp(name, \"Hex\")) { add = concat(&branch->string, space ? \"\" : \" \", \"0xf00ba5\"); *separated = false; }\n"
	"	else if(!strcmp(name, \"Colon\")) { add = concat(&branch->string, \":\"); separator_now = true; }\n"
	"	else if(!strcmp(name, \"Comma\")) { add = concat(&branch->string, \",\"); }\n"
	"	else if(!strcmp(name, \"This\")) { concat(&branch->string, linestart?\"This \":\" this \", contract_name); return; }\n"
	"	else if(!strcmp(name, \"Separator\") || !strcmp(name, \"separator\")) { add = concat(&branch->string, \".\\n\"); separator_now = true; }\n"
	"	else if(!strcmp(name, \"Quote\"))  {\n"
	"		opn_q = !(chrcnt(branch->string, '\\\"') % 2);\n"
	"		add = concat(&branch->string, !opn_q || linestart ? \"\" : \" \", \"\\\"\");\n"
	"		if(opn_q) strcpy(last_defined, foobar(++*names));\n"
	"	}\n"
	"	else if(strchr(name, '\"')) add = concat(&branch->string, linestart?\"\":\" \", *separated ? UP(quote_trimmed(name)) : quote_trimmed(name)) ;\n"
	"\n"
	"	/* simple case: recurse to next word and end this branch upon return */\n"
	"	if(add) {\n"
	"		*separated = separator_now;\n"
	"		if(opt_debug_examples) {\n"
	"			if(word->next) fprintf(stderr, \"example %d: (add) node %s follows to %s\\n\", *count, word->string, word->next->string);\n"
	"			else fprintf(stderr, \"example %d: (add) node %s has no next\\n\", *count, word->string);\n"
	"		}\n"
	"		produce_examples(accu, depth+1, word->next, grammar, contract_name, clause_name, last_defined, separated, names, texts, check, count, fuse);\n"
	"		return;\n"
	"	}\n"
	"\n"
	"	/* end recursion if non-terminal (non-printing) token was met 3 times before (some, like 'provisions' must be allowed multiple times) */\n"
	"/*\n"
	"	if(strstr(check, name))\n"
	"		if(strstr(strstr(check, name)+1, name))\n"
	"			if(strstr(strstr(strstr(check, name)+1, name)+1, name)) { concat(&branch->string, \" [stopped]\"); return; }\n"
	"*/\n"
	"	/* find the definition of 'name', which is a rule token's name */\n"
	"	struct definition *definition = grammar;\n"
	"	while(definition) { if(!strcmp(name, definition->name)) break; definition = definition->next; }\n"
	"	if(!definition) { fprintf(stderr, \"error in %s: token '%s' undefined\\n\", opt_source ? opt_source : \"stdin stream\", name); exit(35); }\n"
	"\n"
	"	/* prepend empty line for 'important' tokens (spaced lettering in LGF) */\n"
	"	if(definition->important && strcmp(definition->name, \"Statements\"))  concat(&branch->string, \"\\n\");\n"
	"\n"
	"	/* fork into the set of resulting BNF rules ('subrules') of this definition. (One LGF rule often results into multiple BNF ('sub'-)rules.) */\n"
	"	char *checkdup = mtrac_strdup(check);\n"
	"	concat(&checkdup, name, \",\");\n"
	"	fuse--;\n"
	"	assert(!branch->next); // bec. it, too, is used in the recursion to add new branches to.\n"
	"\n"
	"	/* pick a random starting point */\n"
	"	struct rule *subrule = definition->subrules;\n"
	"	assert(subrule);\n"
	"	int n = 1; while((subrule = subrule->next)) n++;\n"
	"	//int i = (nonce += 17) % n;\n"
	"	int i = rand() % n;\n"
	"/*\n"
	"	if(depth > 50) {\n"
	"		mtrac_free(branch->string);\n"
	"		branch->string = mtrac_strdup(\"overlong\");\n"
	"		return;\n"
	"	}\n"
	"\n"
	"*/	/* if at limit of wanted example count, choose one branch down only, at random */\n"
	"	if(fuse <= 0 || (opt_max_examples && *count >= opt_max_examples)) {\n"
	"		printf(\"Count: %d\\n\", *count);\n"
	"		if(opt_debug_examples) fprintf(stderr, \"  max cut off: picking alternate #%d of %d \", i, n);\n"
	"\n"
	"		subrule = definition->subrules;\n"
	"		while(i--) subrule = subrule->next;\n"
	"		if(opt_debug_examples) fprintf(stderr, \" (%s --> %s)\\n\", definition->name, subrule->words->string);\n"
	"\n"
	"		bool sep = *separated;\n"
	"		produce_examples(accu, depth +1, subrule->words, grammar, contract_name, clause_name, last_defined, &sep, names, texts, checkdup, count, fuse);\n"
	"		produce_examples(accu, depth +1, word->next, grammar, contract_name, clause_name, last_defined, &sep, names, texts, checkdup, count, fuse);\n"
	"\n"
	"	/* but normally, traverse all alternates. From a random starting point however, revolving. */\n"
	"	} else {\n"
	"		*accu = null; /* temp loses connct to branch */\n"
	"\n"
	"		subrule = definition->subrules;\n"
	"		while(i--) subrule = subrule->next;\n"
	"		i = n;\n"
	"		while(i--) {\n"
	"			if(i) {\n"
	"				(*count)++; // ie. does count one less than loops: the existing branch.\n"
	"				printf(\"Count: %d\\n\", *count);\n"
	"				if(opt_verbose) fprintf(stderr, \"\\b\\b\\b\\b\\b\\b\\b\\b\\b\\b\\b  %d\", *count);\n"
	"			}\n"
	"			stringlist *fork = i ? new_result_dup(null, branch->string, no_pipe) : branch;\n"
	"			bool sep = *separated;\n"
	"			produce_examples(&fork, depth +1, subrule->words, grammar, contract_name, clause_name,\n"
	"				last_defined, &sep, names, texts, checkdup, count, fuse);\n"
	"			stringlist *subfork = fork; // fork now may have subforks added.\n"
	"			while(subfork) {\n"
	"				stringlist *next = subfork->next;\n"
	"				subfork->next = null;\n"
	"				produce_examples(&subfork, depth +1, word->next, grammar, contract_name, clause_name,\n"
	"					last_defined, &sep, names, texts, checkdup, count, fuse);\n"
	"				/* subfork may now also have subforks. Add all to resulting fork list */\n"
	"				*accu = listcat(*accu, subfork);\n"
	"				subfork = next;\n"
	"			}\n"
	"			subrule = subrule->next ? subrule->next : definition->subrules; // from top\n"
	"		}\n"
	"	}\n"
	"	assert(pin_list(*accu, branch));\n"
	"	mtrac_free(checkdup);\n"
	"\n"
	"	return;\n"
	"}\n"
	"\n"
	"char foobars[2000];\n"
	"char *bars[12] = {\"Foo\", \"Bar\", \"Baz\", \"Qux\", \"Corge\", \"Grault\", \"Garply\", \"Waldo\", \"Fred\", \"Plugh\", \"Xyzzy\", \"Thud\"};\n"
	"char *foobar(int n) {\n"
	"	char *p = foobars;\n"
	"	if(n > 12 && n % 2) n = (n % 12) + 1;\n"
	"	else if(n > 144 && n % 3) n = (n % 144) + 1;\n"
	"	while(n) {\n"
	"		if(p!=foobars) p += strlen(strcpy(p, \" \"));\n"
	"		p += strlen(strcpy(p, bars[n % 12]));\n"
	"		n /= 12;\n"
	"	}\n"
	"	return foobars;\n"
	"}\n"
	"\n"
	"\n"
	"char *blindtext = \".Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor.\"\n"
	"	\" Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.\"\n"
	"	\" Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim.\"\n"
	"	\" Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a,\"\n"
	"	\" venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus\"\n"
	"	\" elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae,\"\n"
	"	\" eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla\"\n"
	"	\" ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur\"\n"
	"	\" ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus,\"\n"
	"	\" sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus\"\n"
	"	\" pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero\"\n"
	"	\" venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo.\"\n"
	"	\" Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna.\";\n"
	"char *blind(int n) {\n"
	"	char *q, *p = foobars;\n"
	"	strcpy(p, blindtext);\n"
	"	int s = n % 11;\n"
	"	int l = n % 7 + 1;\n"
	"	while(s) if(*++p=='.') s--;\n"
	"	q = ++p;\n"
	"	while(l) if(*++q==' ') l--;\n"
	"	*q = 0;\n"
	"	return p;\n"
	"}\n"
	"\n"
	"\n"
	"/* write examples to file or screen */\n"
	"void write_examples(stringlist *example, int count) {\n"
	"	int width = 6; // log10(count)+1; ◊ can require lib\n"
	"	int i = 1;\n"
	"\n"
	"	/* to screen */\n"
	"	if(!strlen(opt_samples) && !opt_quiet) {\n"
	"		printf(\"\\nexamples:\\n---------\\n\\n\");\n"
	"		while(example) {\n"
	"			printf(\"--- example #%0*d ---\\n\\n%s\\n\\n\", width, i++, example->string);\n"
	"			example = example->next;\n"
	"\n"
	"	/* to individual files (and if --echo, to screen) */\n"
	"	}} else if (strlen(opt_samples)) {\n"
	"		int size = 1 + width + snprintf(null, 0, \"%s%0*d.lex\", opt_samples, width, 0);\n"
	"		char *filename = news(filename, size);\n"
	"		chdir(name_homedir); // assume path to open as relative to dir at program start\n"
	"		if(opt_wipe) {\n"
	"			if(opt_verbose || opt_debug)\n"
	"				printf(\"  deleting files %s%0*d.lex - %s%0*d.lex\\n\", opt_samples, width, 1, opt_samples, width, count);\n"
	"			snprintf(filename, size, \"rm %s*.lex\", opt_samples);\n"
	"			printf(\"clean up %s\\n\", filename);\n"
	"			system(filename);\n"
	"		}\n"
	"		if(opt_verbose || opt_debug)\n"
	"			printf(\"  writing example files %s%0*d.lex - %s%0*d.lex\\n\", opt_samples, width, 1, opt_samples, width, count);\n"
	"		while(example) {\n"
	"			snprintf(filename, size, \"%s%0*d.lex\", opt_samples, width, i);\n"
	"			if(opt_echo) printf(\"#%0*d --- %s\\n\\n%s\\n\\n\", width, i, filename, example->string);\n"
	"			i++;\n"
	"			FILE *fp = fopen(filename, \"wb\");\n"
	"			if(!fp) { fprintf(stderr, \"could not open file for writing. \"); perror(filename); exit(1); }\n"
	"			fwrite(example->string, 1, strlen(example->string), fp);\n"
	"			fclose(fp);\n"
	"			example = example->next;\n"
	"		}\n"
	"		mtrac_free(filename);\n"
	"		chdir(file_location); // back to source file's absolute location\n"
	"	}\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"/* build the resulting BNF, as string, from the LXF tree */\n"
	"void produce_extension(struct definition *definition) {\n"
	"\n"
	"	if(!definition) return;\n"
	"	assert(definition->rules);\n"
	"	assert(!definition->results);\n"
	"\n"
	"	char *bnf = mtrac_strdup(\"\");\n"
	"	stringlist *results = new_result_dup(null, \"\", no_pipe);\n"
	"\n"
	"	/* rules */\n"
	"	char *last = null;\n"
	"	while(definition) {\n"
	"		char *prefix = mtrac_strdup(\"\"); // catdup(definition->name, \"_\", tolower);\n"
	"\n"
	"		/* traverse all words, options and synonyms to create a list of result strings */\n"
	"		assert(definition->rules);\n"
	"		struct rule *rule = definition->rules;\n"
	"		mode last = none;\n"
	"		struct rule *last_rule = null;\n"
	"		do {\n"
	"			if(rule->mode != last || last_rule != rule) {\n"
	"				char *tag = mtrac_strdup(\"\");\n"
	"				concat(&tag, definition->name, rule->mode == active ? \"_Predicate\" : \"_Predicament\");\n"
	"				add_token(&tokens, tag, null, null, sort); // (x)\n"
	"				concat(&tag, \":\\t\");\n"
	"				new_result(results, tag, no_pipe);\n"
	"				last = rule->mode;\n"
	"				last_rule = rule;\n"
	"			}\n"
	"			produce_rule(new_result_dup(results, \"\\t  \", no_pipe), definition, rule, rule->words, null, unspaced, prefix, true);\n"
	"			if(rule->next) new_result_dup(results, \"\", no_pipe);\n"
	"		} while((rule = rule->next));\n"
	"		mtrac_free(prefix);\n"
	"		definition = definition->next;\n"
	"	}\n"
	"\n"
	"	/* prepend tokens, which were produced in produce_rule at (xx) and above at (x) */\n"
	"	stringlist *token = tokens;\n"
	"	while(token) {\n"
	"		concat(&bnf, \"\\t%token \", token->string, \"\\n\");\n"
	"		token = token->next;\n"
	"	}\n"
	"\n"
	"	/* the result strings, which are built up logically in parallel, are now joined sequentially */\n"
	"	stringlist *result = results;\n"
	"	while(result) {\n"
	"		if(result->string) concat(&bnf, \"\\t\", result->string, \"\\n\");\n"
	"		result = result->next;\n"
	"	}\n"
	"\n"
	"	printf(\"%s\", bnf);\n"
	"\n"
	"	// .. free\n"
	"	delete_stringlist(results);\n"
	"	rule = null;\n"
	"	alternation = null;\n"
	"	alternate = null;\n"
	"	word = null;\n"
	"}\n"
	"\n"
	"void produce_tokens(stringlist *results, stringlist *token) {\n"
	"\n"
	"	while(token) {\n"
	"		char *t = mtrac_strdup(\"%token \");\n"
	"		concat(&t, token->string);\n"
	"		new_result(results, t, no_pipe);\n"
	"		token = token->next;\n"
	"	}\n"
	"}\n"
	"\n"
	"/* recursively add the next word of a rule, fork the production for both optionals and synonyms */\n"
	"void produce_rule(stringlist *result, struct definition *definition, struct rule *rule, struct word *word,\n"
	"	struct word *pickup, adjacency space, char *prefix, bool extension) {\n"
	"	assert(definition);\n"
	"	assert(rule);\n"
	"	assert(result);\n"
	"	assert(result->string);\n"
	"	assert(!result->seal);\n"
	"\n"
	"	if(!word) {\n"
	"		if(pickup)\n"
	"			if(opt_debug_generator)\n"
	"				fprintf(stderr, \"gentor.: rule production pickup with '%s' after: %s ..\\n\", pickup->string, result->string);\n"
	"		word = pickup;\n"
	"		pickup = null;\n"
	"	}\n"
	"\n"
	"	if(!word) {\n"
	"		/* Now we are done, glue unspaced literals (\"lex\"\":\") ... */\n"
	"		replace(&result->string, \"\\\"\\\"\", \"\");\n"
	"\n"
	"		/* (xx) .. and check what words we produced (non-spaced options create new words)\n"
	"		   and also, record this specific new line as 'subrule', i.e. Yacc BNF rule.\n"
	"		   what also happens is that quoted literals are replaced by their symbols */\n"
	"		struct rule **subrule = &definition->subrules;\n"
	"		while(*subrule) subrule = &(*subrule)->next;\n"
	"		*subrule = new(struct rule, *subrule);\n"
	"		struct word **subword = &(*subrule)->words;\n"
	"\n"
	"		char *t0 = mtrac_strdup(result->string);\n"
	"		char *t = strtok(t0, \" \\t\");\n"
	"		char *self_reference = \"[error]\";\n"
	"		stringlist *action_tokens = null; // note, one lgf rule struct routinely results into multiple bnf yacc rules\n"
	"		stringlist *action_numbers = null; // to build $n when needed\n"
	"		int i = 0;\n"
	"		while(t) {\n"
	"			if(*t != '|') {\n"
	"				i++;\n"
	"				if(strchr(t, '\"'))\n"
	"					/* replace quoted literals with their upper case symbols */\n"
	"					replace(&result->string, t, literal_symbol(t));\n"
	"				else {\n"
	"					int number = count_in_list(action_tokens, UP(t)) + 1;\n"
	"					char *field = mtrac_strdup(UP(t));\n"
	"					if(number > 1) {\n"
	"						if(!definition->simple)\n"
	"							fprintf(stderr, \"Lexon: name '%s' cannot appear twice in '%s' in file %s.\\n\"\n"
	"								\"Only simple LGF rules can repeat names. \"\n"
	"								\"Simple rules cannot have options ([..]) nor alternatives (.. or ..) .\\n\",\n"
	"								UP(t), trim(result->string), file_clearname),\n"
	"							exit(1);\n"
	"						mtrac_concat(&field, str(number));\n"
	"					}\n"
	"					if(add_token(&action_tokens, UP(t), extension?xpredef:null, extension?null:ignores, keep))\n"
	"						add_token(&action_numbers, str(i), null, null, keep);\n"
	"					if(!in_list(definition->tokens, field)) {\n"
	"						add_token(&definition->tokens, field, null, ignores, keep);\n"
	"						add_token(&definition->types, UP(t), null, ignores, keep);\n"
	"					}\n"
	"					mtrac_free(field);\n"
	"				}\n"
	"				add_token(&tokens, t, null, predef, sort);\n"
	"\n"
	"				/* build subrule */\n"
	"				assert(!*subword);\n"
	"				*subword = new(struct word, *subword);\n"
	"				(*subword)->string = mtrac_strdup(t);\n"
	"				subword = &(*subword)->next;\n"
	"				assert(!*subword);\n"
	"			}\n"
	"			t = strtok(null, \" \");\n"
	"		}\n"
	"		mtrac_free(t0);\n"
	"\n"
	"		/* Now we are done with all words and have picked up all optionals, add the action\n"
	"		   (unless we want pure BNF output). */\n"
	"		if(!opt_bnf) {\n"
	"			pad(&result->string, 50);\n"
	"\n"
	"			char *fields = mtrac_strdup(\"\");\n"
	"\n"
	"			stringlist *token = action_tokens;\n"
	"			stringlist *number = action_numbers;\n"
	"			stringlist *appearances = null;\n"
	"			while(token) {\n"
	"				/* all for grammar (LGF), only some predefined ones for extensions (LXF) */\n"
	"				/* use $<n> instead of name when equalling definition name */\n"
	"				add_token(&appearances, token->string, null, null, keep);\n"
	"				int count = count_in_list(appearances, token->string);\n"
	"				int appears = count_in_list(action_tokens, token->string);\n"
	"				char *field = mtrac_strdup(token->string);\n"
	"				if(appears > 1 && count > 1) mtrac_concat(&field, str(count));\n"
	"				const char *reference = (!strcmp(token->string, definition->name) || appears > 1) ? number->string : token->string;\n"
	"				concat(&fields, definition->name, \"->\"); // separate in 3 calls when using UP buffer\n"
	"				concat(&fields, field, \"=$\");\n"
	"				concat(&fields, reference, \"; \");\n"
	"				mtrac_free(field);\n"
	"				token = token->next;\n"
	"				number = number->next;\n"
	"			}\n"
	"\n"
	"			concat(&result->string, \" { NEW(\", definition->name, \", *((Literal **)&yylval)); \",\n"
	"				fields, definition==grammar?\"root\":\"$$\", \"=process_\", LOW(definition->name), \"(\", UP(definition->name), \"); }\" );\n"
	"\n"
	"			delete_stringlist(appearances);\n"
	"			mtrac_free(fields);\n"
	"		}\n"
	"		delete_stringlist(action_tokens);\n"
	"		delete_stringlist(action_numbers);\n"
	"\n"
	"		if(opt_debug_generator) fprintf(stderr, \"gentor.: rule production result: %s\\n\", UP(result->string));\n"
	"		result->seal = true;\n"
	"		return;\n"
	"	}\n"
	"\n"
	"	assert(!!word->string + word->option_start + word->option_end == 1);\n"
	"\n"
	"	if(word->string) {\n"
	"		if(opt_debug_generator) fprintf(stderr, \"gentor.: produce word: %s\\n\", word->string);\n"
	"		size_t len = strlen(result->string);\n"
	"\n"
	"		/* Finally, the happy path, add a word. Allow the synonym forks (+) before adding to result->string */\n"
	"		if(space == spaced) concat(&result->string, \" \", UP(word->string)); // (+++)\n"
	"		else concat(&result->string, UP(word->string));\n"
	"		produce_rule(result, definition, rule, word->next, pickup,\n"
	"			word->next && (word->next->option_end || word->next->option_start) ? 0 : spaced, prefix, extension);\n"
	"\n"
	"		/* fork the string building for every matching synonym. This (++++) helps to order results */\n"
	"		if(definition->alternations && !pickup) {\n"
	"			struct alternation *alternation = definition->alternations;\n"
	"			do {\n"
	"				assert(alternation->string);\n"
	"				assert(alternation->alternates);\n"
	"				if(opt_debug_generator)\n"
	"					fprintf(stderr, \"gentor.: produce alternation - compare: '%s' vs '%s'\\n\", word->string, alternation->string);\n"
	"				if(!strcmp(word->string, alternation->string)) {\n"
	"					struct alternate *alternate = alternation->alternates;\n"
	"					char *rump = mtrac_strdup(result->string); *(rump + len) = 0; // (++++)\n"
	"					do {\n"
	"						if(opt_debug_generator)\n"
	"							fprintf(stderr, \"produce alternation - fork for alt: %s (..)\\n\", alternate->words->string);\n"
	"						produce_rule(new_result_dup(result, rump, with_pipe), // (+)\n"
	"							definition, rule, alternate->words, word->next, space, prefix, extension);\n"
	"					} while((alternate = alternate->next));\n"
	"					mtrac_free(rump);\n"
	"				}\n"
	"			} while((alternation = alternation->next));\n"
	"		}\n"
	"	}\n"
	"\n"
	"	/* fork the result string, skipping (a) past the (b) into a (nested) options */\n"
	"	if(word->option_start) {\n"
	"		definition->simple = false;\n"
	"		if(opt_debug_generator) fprintf(stderr, \"gentor.: production of option - start\\n\");\n"
	"		struct word *w = word;\n"
	"		int nested = 0;\n"
	"		while((nested += w->option_start - w->option_end) && (w = w->next))\n"
	"			if(opt_debug_generator) fprintf(stderr, \"gentor.: production skips '%s'\\n\", word->string ? word->string : \"bracket\");\n"
	"		char *trunk = mtrac_strdup(result->string); // note, used after result has grown\n"
	"		produce_rule(result, definition, rule, w, pickup, w->adjacency || word->adjacency, prefix, extension); // (a) skip\n"
	"		produce_rule(new_result(result, trunk, with_pipe), definition, rule,\n"
	"			word->next, pickup, word->adjacency || space, prefix, extension); // (b) do the option\n"
	"	}\n"
	"\n"
	"	if(word->option_end) {\n"
	"		if(opt_debug_generator) fprintf(stderr, \"gentor.: production of option - end\\n\");\n"
	"		produce_rule(result, definition, rule, word->next, pickup, word->adjacency || space, prefix, extension);\n"
	"	}\n"
	"}\n"
	"\n"
	"/* create a new result struct, dup the string and append it to the end of the result's list */\n"
	"stringlist *new_result_dup(stringlist *result, char *string, piped add_pipe) {\n"
	"	return new_result(result, mtrac_strdup(string ? string : \"\"), add_pipe);\n"
	"}\n"
	"\n"
	"stringlist *new_result(stringlist *result, char *string, piped add_pipe) {\n"
	"	stringlist *fork = mtrac_malloc(sizeof(stringlist));\n"
	"	fork->string = string;\n"
	"	fork->seal = false;\n"
	"	fork->next = null;\n"
	"\n"
	"	if(add_pipe && strlen(string) > 1) string[1] = '|';\n"
	"\n"
	"	if(result) { while(result->next) result = result->next; result->next = fork; }\n"
	"	return fork;\n"
	"}\n"
	"\n"
	"stringlist *listcat(stringlist *head, stringlist *tail) {\n"
	"\n"
	"	if(!head) return tail;\n"
	"	stringlist *i = head;\n"
	"	while(i->next) i = i->next; i->next = tail;\n"
	"	return head;\n"
	"}\n"
	"\n"
	"bool pin_list(stringlist *list, stringlist *needle) {\n"
	"\n"
	"	while(list) if(list == needle) return true; else list = list->next;\n"
	"	return false;\n"
	"}\n"
	"\n"
	"void delete_definitions(struct definition *definition) {\n"
	"	while(definition) {\n"
	"		mtrac_free(definition->name);\n"
	"		mtrac_free(definition->source);\n"
	"		struct rule *r, *rule = definition->rules;\n"
	"		while(rule) {\n"
	"			struct word *w, *word = rule->words;\n"
	"			while(word) { if(word->string) mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }\n"
	"			struct word *k, *keyword = rule->keywords;\n"
	"			while(keyword) { mtrac_free(keyword->string); k = keyword; keyword = keyword->next; mtrac_free(k); }\n"
	"			stringlist *t, *token = rule->tokens;\n"
	"			while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }\n"
	"			r = rule; rule = rule->next; mtrac_free(r);\n"
	"		}\n"
	"		struct alternation *a, *alternation = definition->alternations;\n"
	"		while(alternation) {\n"
	"			mtrac_free(alternation->string);\n"
	"			struct alternate *aa, *alternate = alternation->alternates;\n"
	"			while(alternate) {\n"
	"				struct word *w, *word = alternate->words;\n"
	"				while(word) { mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }\n"
	"				aa = alternate; alternate = alternate->next; mtrac_free(aa);\n"
	"			}\n"
	"			a = alternation; alternation = alternation->next; mtrac_free(a);\n"
	"		}\n"
	"		struct rule *s, *subrule = definition->subrules;\n"
	"		while(subrule) {\n"
	"			struct word *w, *word = subrule->words;\n"
	"			while(word) { mtrac_free(word->string); w = word; word = word->next; mtrac_free(w); }\n"
	"			struct word *k, *keyword = subrule->keywords;\n"
	"			while(keyword) { mtrac_free(keyword->string); k = keyword; keyword = keyword->next; mtrac_free(k); }\n"
	"			stringlist *t, *token = subrule->tokens;\n"
	"			while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }\n"
	"			s = subrule; subrule = subrule->next; mtrac_free(s);\n"
	"		}\n"
	"		stringlist *t, *token = definition->tokens;\n"
	"		while(token) { mtrac_free(token->string); t = token; token = token->next; mtrac_free(t); }\n"
	"		stringlist *types = definition->types;\n"
	"		while(types) { mtrac_free(types->string); t = types; types = types->next; mtrac_free(t); }\n"
	"		stringlist *rr, *result = definition->results;\n"
	"		while(result) { mtrac_free(result->string); rr = result; result = result->next; mtrac_free(rr); }\n"
	"		struct definition *d = definition;\n"
	"		definition = definition->next;\n"
	"		mtrac_free(d);\n"
	"	}\n"
	"}\n"
	"\n"
	"void source(char *s) {\n"
	"	concat(&src, s);\n"
	"	if(*definition) concat(&(*definition)->source, s);\n"
	"}\n"
	"\n"
	"const char *yacc_stub() {\n"
	"	return\n"
	"		\"bool core_document(char **production, Document *root, int indent, bool topcall, bool sibbling,\\n\"\n"
	"		\"	bool highlight, bool subhighlight); // #core #tree\\n\"\n"
	"//#		\"bool sph_document(char **production, Document *root, int indent); // #spheres\\n\" // :spheres\n"
	"		\"bool js_document(char **production, Document *root, int indent); // #javascript\\n\" // :javascript\n"
	"		\"bool sol_document(char **production, Document *root, int indent); // #solidity\\n\" // :solidity\n"
	"		\"bool sophia_document(char **production, Document *root, int indent); // #sophia\\n\" // :sophia\n"
	"//#		\"extern bool opt_run_spheres;\\n\"\n"
	"		\"extern bool opt_produce_tree;\\n\"\n"
	"		\"extern bool opt_produce_core;\\n\"\n"
	"		\"extern bool opt_produce_javascript;\\n\"\n"
	"		\"extern bool opt_produce_solidity;\\n\"\n"
	"		\"extern bool opt_produce_sophia;\\n\"\n"
	"		\"char *walk() {\\n\"\n"
	"		\"	char *production = mtrac_strdup(\\\"\\\");\\n\"\n"
	"		\"	if(opt_verbose || opt_debug) fprintf(stderr, \\\"• starting walk\\\\n\\\");\\n\"\n"
	"//#		\"	if(opt_run_spheres) {\\n\"\n"
	"//#		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• run\\\\n\\\");\\n\"\n"
	"//#		\"		sph_document(&production, root, 0); // #spheres\\n\" // :spheres\n"
	"//#		\"	} else\\n\"\n"
	"		\"	if(opt_produce_javascript) {\\n\"\n"
	"		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• produce javascript\\\\n\\\");\\n\"\n"
	"		\"		js_document(&production, root, 0); // #javascript\\n\" // :javascript\n"
	"		\"	} else if(opt_produce_solidity) {\\n\"\n"
	"		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• produce solidity\\\\n\\\");\\n\"\n"
	"		\"		sol_document(&production, root, 0); // #solidity\\n\" // :solidity\n"
	"		\"	} else if(opt_produce_sophia) {\\n\"\n"
	"		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• produce sophia\\\\n\\\");\\n\"\n"
	"		\"		sophia_document(&production, root, 0); // #sophia\\n\" // :sophia\n"
	"		\"	} else if(opt_produce_tree) {\\n\"\n"
	"		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• produce abstract syntax tree\\\\n\\\");\\n\"\n"
	"		\"		core_document(&production, root, 0, true, false, false, false); // #tree #core\\n\"\n"
	"		\"	} else { /* default */\\n\"\n"
	"		\"		if(opt_verbose || opt_debug) fprintf(stderr, \\\"• produce core listing\\\\n\\\");\\n\"\n"
	"		\"		core_document(&production, root, 0, true, false, false, false); // #core\\n\"\n"
	"		\"	}\\n\"\n"
	"		\"	padcat(0,0,&production, \\\"\\\\\\n\\\");\\n\"\n"
	"		\"	return production;\\n\\n\"\n"
	"		\"}\\n\\n\"\n"
	"		\"extern int prec_line;\\n\"\n"
	"		\"extern char *context;\\n\"\n"
	"		\"extern char *prec_file;\\n\"\n"
	"		\"extern char *yytext;\\n\"\n"
	"		\"void yyerror(const char *s) {\\n\"\n"
	"		\"	fprintf(stderr, \\\"Lexon: %s -- check %s, line %d: %s\\\\n>> %s\\\\n\\\", s, prec_file, prec_line, yytext, context);\\n\"\n"
	"		\"	exit(1);\\n\"\n"
	"		\"}\";\n"
	"}\n"
	"\n"
	"const char *walk_stub() {\n"
	"	return\n"
	"		\"/*T*/	extern struct <roottype> *root;\\n\"\n"
	"		\"/*T*/	bool <prefix>_<low-roottype>(char **production, <roottype> *root, int indent, bool topcall,\"\n"
	"			\" bool sibbling, bool highlight, bool subhighlight);\\n\"\n"
	"		\"/*T*/\\n\"\n"
	"		\"/*T*/  #define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, null, #orig_, __FILE__, __LINE__)\\n\"\n"
	"		\"/*T*/  char *_replace(char **orig, const char *rep, const char *with, int all, char *from, int *times,\"\n"
	"			\" char *origname, char *file, int line);\\n\"\n"
	"		\"/*T*/  char *quote_trimmed(const char *token);\\n\"\n"
	"		\"/*T*/  char *dash_spaced(const char *token);\\n\"\n"
	"		\"/*T*/  char *snake_spaced(const char *token);\\n\"\n"
	"		\"/*T*/  char *LOW(const char *token);\\n\"\n"
	"		\"/*T*/  char *UP(const char *token);\\n\"\n"
	"		\"/*T*/  extern char *opt_color;\\n\"\n"
	"		\"/*T*/  extern char *opt_highlight;\\n\"\n"
	"		\"/*T*/  extern char *opt_symbols;\\n\"\n"
	"		\"/*T*/  extern char *opt_values;\\n\"\n"
	"		\"/*T*/  extern char *opt_subvalues;\\n\"\n"
	"		\"/*T*/\\n\"\n"
	"		\"/*T*/	bool <prefix>_walk(char **production) {\\n\"\n"
	"		\"/*T*/		if(!root) return false;\\n\"\n"
	"		\"/*T*/		return <prefix>_<low-roottype>(production, root, 0, true, false, false, false);\\n\"\n"
	"		\"/*T*/	}\\n\\n\"\n"
	"		\"/*T*/	bool <prefix>_name(char **production, Name *Name, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\\n\"\n"
	"		\"/*T*/		if(!Name) return false;\\n\"\n"
	"		\"/*T*/		padcat(0, 0, production, \\\"«\\\", opt_symbols?opt_symbols:\\\"\\\", LOW(dash_spaced(quote_trimmed(Name))),\"\n"
	"			\" opt_symbols?\\\"\\\\033[0m\\\":\\\"\\\", \\\"» \\\");\\n\" \n"
	"		\"/*T*/		return true;\\n\"\n"
	"		\"/*T*/	}\\n\\n\"\n"
	"		\"/*T*/	bool <prefix>_description(char **production, Description *Description, int indent, bool topcall,\"\n"
	"			\" bool sibbling, bool highlight, bool subhighlight) {\\n\"\n"
	"		\"/*T*/		if(!Description) return false;\\n\"\n"
	"		\"/*T*/		padcat(0, 0, production, \\\"\\\\\\\"\\\", Description, \\\"\\\\\\\"\\\");\\n\"\n"
	"		\"/*T*/		return true;\\n\"\n"
	"		\"/*T*/	}\\n\\n\"\n"
	"		\"/*T*/	bool <prefix>_scalar(char **production, Scalar *Scalar, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\\n\"\n"
	"		\"/*T*/		if(!Scalar) return false;\\n\"\n"
	"		\"/*T*/		padcat(0, 0, production, Scalar, \\\" \\\");\\n\"\n"
	"		\"/*T*/		return true;\\n\"\n"
	"		\"/*T*/	}\\n\\n\"\n"
	"		\"/*T*/	bool <prefix>_hex(char **production, Hex *Hex, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {\\n\"\n"
	"		\"/*T*/		if(!Hex) return false;\\n\"\n"
	"		\"/*T*/		padcat(0, 0, production, Hex, \\\" \\\");\\n\"\n"
	"		\"/*T*/		return true;\\n\"\n"
	"		\"/*T*/	}\\n\\n\";\n"
	"}\n"
	"\n"
	"/* writing 2nd cycle lexer file */\n"
	"void prepfile(char *outfile, char *header, char *template, char *grammar_path, char *lex) {\n"
	"#ifndef CYCLE_2\n"
	"	if(!template) template = \"lexon.l\";\n"
	"#endif\n"
	"	if(!header) header = \"parser.h\";\n"
	"	char *include = news(include, strlen(header) + 100); sprintf(include, \"%%{\\n#include \\\"%s\\\" // set by -H\\n%%}\\n\\n\", header);\n"
	"	if(opt_debug || opt_verbose) {\n"
	"		if(!strlen(outfile))\n"
	"			fprintf(stderr, \"\\n2nd cycle scanner source\\n------------------------\\n%s%s. It includes %s (use -H to change).\\n\\n\",\n"
	"				template ? \"from template \" : \"from interned source\", template ? template : \"\", header);\n"
	"		else\n"
	"			fprintf(stderr, \"  creating 2nd cycle scanner file %s %s%s. It will include %s (use -H to change).\\n\",\n"
	"				outfile, template ? \"from template \" : \"from interned source\", template ? template : \"\", header);\n"
	"	}\n"
	"\n"
	"	/* go to directory from which the invocation started (we are presently, possibly in the source file's dir) */\n"
	"	chdir(name_homedir);\n"
	"\n"
	"	/* read template lexer (this here) file */\n"
	"	char *src = filedup(template, own);\n"
	"	replace(&src, \"0.2.20 / subset 0.3.9 beta 1 - English / Reyes\", grammar_version);\n"
	"	char *src_imbue = str_escape(src, \"own\");\n"
	"\n"
	"	/* read grammer file */\n"
	"	char *grm = filedup(opt_source, owngrm);\n"
	"	char *grm_imbue = str_escape(grm, \"owngrm\");\n"
	"\n"
	"	/* read manual file */\n"
	"	char *man = filedup(\"MANUAL\", manual);\n"
	"	char *man_imbue = str_escape(man, \"manual\");\n"
	"\n"
	"	char *pre_midend = strstr(src, \"/* --\" \"->\"); // never fe\" \"ed on yourself\n"
	"	if(!pre_midend) { fprintf(stderr, \"could not find type name insertion start mark '/* --\" \"->' in file %s\\n\", template); exit(38); }\n"
	"	char *pre_midstart = strstr(src, \"<-\" \"-- */\");\n"
	"	if(!pre_midstart) { fprintf(stderr, \"could not find type name insertion end mark '<-\" \"-- */' in file %s\\n\", template); exit(39); }\n"
	"	*pre_midend = 0;\n"
	"	pre_midstart += 8;\n"
	"	char *midend = strstr(pre_midstart, \"/* -\" \"->\"); // never fe\" \"ed on yourself\n"
	"	if(!midend) { fprintf(stderr, \"could not find keyword insertion start mark '/* -\" \"->' in file %s\\n\", template); exit(40); }\n"
	"	char *midstart = strstr(pre_midstart, \"<-\" \"- */\");\n"
	"	if(!midstart) { fprintf(stderr, \"could not find keyword insertion end mark '<-\" \"- */' in file %s\\n\", template); exit(41); }\n"
	"	*midend = 0;\n"
	"	midstart += 7;\n"
	"\n"
	"	/* write to file, or to screen */\n"
	"	FILE *fp = strlen(outfile) ? fopen(outfile, \"w\") : stdout;\n"
	"	if(!fp) { perror(strlen(outfile)?outfile:\"stdout\"); exit(1); }\n"
	"	int check = fwrite(include, strlen(include), 1, fp);\n"
	"	check += fwrite(src, strlen(src), 1, fp);\n"
	"	check += fwrite(pre_midstart, strlen(pre_midstart), 1, fp);\n"
	"	check += fwrite(lex, strlen(lex), 1, fp);\n"
	"	check += fwrite(midstart, strlen(midstart), 1, fp);\n"
	"	check += fwrite(src_imbue, strlen(src_imbue), 1, fp);\n"
	"	check += fwrite(grm_imbue, strlen(grm_imbue), 1, fp);\n"
	"	check += fwrite(man_imbue, strlen(man_imbue), 1, fp);\n"
	"	if(check != 8) { fprintf(stderr, \"error writing \"); perror(strlen(outfile)?outfile:\"stdout\"); exit(1); }\n"
	"	fclose(fp);\n"
	"\n"
	"	/* back to source file's absolute location */\n"
	"	chdir(file_location);\n"
	"\n"
	"	mtrac_free(include);\n"
	"	mtrac_free(src);\n"
	"	mtrac_free(src_imbue);\n"
	"	mtrac_free(grm);\n"
	"	mtrac_free(grm_imbue);\n"
	"	mtrac_free(man);\n"
	"	mtrac_free(man_imbue);\n"
	"}\n"
	"\n"
	"/* expects to be in the right folder to use the path as is */\n"
	"char *filedup(const char *path, const char *dflt) {\n"
	"\n"
	"	FILE *fp;\n"
	"	char *src;\n"
	"#ifdef CYCLE_2\n"
	"	if(!path)\n"
	"		src = mtrac_strdup(dflt); // midend pokes 0 in\n"
	"	else\n"
	"#endif\n"
	"	{\n"
	"		fp = fopen(path, \"r\");\n"
	"		if(!fp) { perror(path); exit(1); }\n"
	"		fseek(fp, 0L, SEEK_END);\n"
	"		int size = ftell(fp);\n"
	"		rewind(fp);\n"
	"		src = mtrac_malloc(size + 1);\n"
	"		if(fread(src, 1, size, fp) != size) { perror(path); exit(1); }\n"
	"		src[size] = 0;\n"
	"		fclose(fp);\n"
	"	}\n"
	"\n"
	"	return src;\n"
	"}\n"
	"\n"
	"char *str_escape(const char *src, const char *varname) {\n"
	"\n"
	"	char *esc = mtrac_strdup(src);\n"
	"	replace(&esc, \"\\\\\", \"\\\\\\\\\");\n"
	"	replace(&esc, \"\\\"\", \"\\\\\\\"\");\n"
	"	replace(&esc, \"\\n\", \"\\\\n\\\"\\n\\t\\\"\");\n"
	"\n"
	"	char *imbue = mtrac_strdup(\"\");\n"
	"	concat(&imbue,\"\\n\\nconst char *\", varname, \" =\\n\\n\\t\\\"\", esc, \"\\\";\");\n"
	"\n"
	"	mtrac_free(esc);\n"
	"\n"
	"	return imbue;\n"
	"}\n"
	"\n"
	"/* tracking dynamic memory management */\n"
	"\n"
	"typedef struct mtrac {\n"
	"	unsigned long magic;\n"
	"	int index;\n"
	"	char *name;\n"
	"	char *file;\n"
	"	int line;\n"
	"	size_t size;\n"
	"	bool free;\n"
	"	char *free_name;\n"
	"	char *free_file;\n"
	"	int free_line;\n"
	"	int free_action;\n"
	"	struct mtrac *next;\n"
	"	struct mtrac *previous;\n"
	"	unsigned long __attribute__((aligned(8))) magic2;\n"
	"} mtrac;\n"
	"\n"
	"const unsigned long mtrac_magic = 0xCCCCCCCCCCCCCCCC;\n"
	"mtrac *mtrac_first = null;\n"
	"mtrac *mtrac_last = null;\n"
	"int mtrac_action = 0;\n"
	"int mtrac_count = 0;\n"
	"size_t mtrac_total = 0;\n"
	"int  mtrac_max_count = 0;\n"
	"size_t mtrac_max_total = 0;\n"
	"size_t mtrac_allocated = 0;\n"
	"int mtrac_allocations = 0;\n"
	"size_t mtrac_freed = 0;\n"
	"int mtrac_frees = 0;\n"
	"\n"
	"/* wholesale handling of freeing, for AST nodes */\n"
	"typedef struct element {\n"
	"	void *payload;\n"
	"	struct element *previous;\n"
	"} element;\n"
	"element *mtrac_gross_list = null; // actually the tail\n"
	"\n"
	"void *_mtrac_malloc(size_t size, char *name, char *file, int line) {\n"
	"\n"
	"	mtrac_action++;\n"
	"	if(mtrac_verbose) printf(\"allocate %lu bytes for <%s> in file %s at line %d: \", size, name, file, line);\n"
	"	void *p = (*system_malloc)(sizeof(mtrac) + size + sizeof(unsigned long));\n"
	"	if(mtrac_verbose) printf(\"%p\\n\", !mtrac_blank_pointers ? p : (void *)0xb00);\n"
	"	mtrac *m = p;\n"
	"	if(mtrac_limit < mtrac_total + size) {\n"
	"		fprintf(stderr, \"\\nmemory: violating memory limit (%lu < %luk + %lu) for %s %s %d.\\n\",\n"
	"			mtrac_limit, mtrac_total, size, name, file, line);\n"
	"		exit(46);\n"
	"	}\n"
	"	if(!p) {\n"
	"		fprintf(stderr, \"\\nmemory: out of memory (%luk + %lu) for %s %s %d.\\n\",\n"
	"			mtrac_total, size, name, file, line);\n"
	"		exit(137);\n"
	"	}\n"
	"	m->magic = mtrac_magic;\n"
	"	m->index = mtrac_action;\n"
	"	m->name = name;\n"
	"	m->file = file;\n"
	"	m->line = line;\n"
	"	m->size = size;\n"
	"	m->free = false;\n"
	"	m->free_name = null;\n"
	"	m->free_file = null;\n"
	"	m->free_line = 0;\n"
	"	m->free_action = 0;\n"
	"	m->next = null;\n"
	"	if(!mtrac_first) mtrac_first = m;\n"
	"	m->previous = mtrac_last;\n"
	"	if(mtrac_last) mtrac_last->next = m;\n"
	"	mtrac_last = m;\n"
	"	m->magic2 = mtrac_magic;\n"
	"	*(unsigned long *)(p + sizeof(mtrac) + size) = mtrac_magic;\n"
	"\n"
	"	mtrac_total += size;\n"
	"	mtrac_allocated += size;\n"
	"	mtrac_allocations++;\n"
	"	mtrac_count++;\n"
	"	if(mtrac_total > mtrac_max_total) mtrac_max_total = mtrac_total;\n"
	"	if(mtrac_count > mtrac_max_count) mtrac_max_count = mtrac_count;\n"
	"\n"
	"	return p + sizeof(mtrac);\n"
	"}\n"
	"\n"
	"void *_mtrac_strdup(const char *string, char *name, char *file, int line) {\n"
	"	if(!string) string = \"\";\n"
	"	char *s = _mtrac_malloc(strlen(string) + 1, name, file, line);\n"
	"	strcpy(s, string);\n"
	"	return s;\n"
	"}\n"
	"\n"
	"// frees input and replaces with result.\n"
	"char *_mtrac_dupcat(const char *sep, ...) {\n"
	"	va_list ap;\n"
	"	va_start(ap, sep);\n"
	"	char *add = va_arg(ap, char *);\n"
	"	char *buf = null;\n"
	"	int lsep = strlen(sep);\n"
	"	int lbuf = 1;\n"
	"	while(add) {\n"
	"		lbuf += lsep + strlen(add);\n"
	"		char *t = mtrac_malloc(lbuf);\n"
	"		if(!t) { fprintf(stderr, \"out of memory %s %d\", __FILE__, __LINE__); exit(137); }\n"
	"		if(buf) strcpy(t, buf); else *t = 0;\n"
	"		strcat(t, add);\n"
	"		if(buf) mtrac_free(buf);\n"
	"		buf = t;\n"
	"		add = va_arg(ap, char *);\n"
	"	}\n"
	"	va_end(ap);\n"
	"	return buf ? buf : mtrac_strdup(\"\");\n"
	"}\n"
	"\n"
	"void _mtrac_free(void *q, char *name, char *file, int line) {\n"
	"\n"
	"	mtrac_action++;\n"
	"	if(mtrac_verbose) printf(\"free <%s> [%p] in file %s at line %d\\n\", name, !mtrac_blank_pointers ? q : (void *)0xb00, file, line);\n"
	"\n"
	"	if(!q) {\n"
	"		fprintf(stderr, \"\\nmemory: (action %d) null pointer handed to free as '%s' at file %s at line %d.\\n\",\n"
	"		mtrac_action, name, file, line);\n"
	"		exit(48);\n"
	"	}\n"
	"	void *p = q - sizeof(mtrac);\n"
	"	mtrac *m = p;\n"
	"	if(m->magic != mtrac_magic) {\n"
	"		fprintf(stderr, \"\\nmemory: (action %d) wild %s pointer handed to free at file %s at line %d.\\n\",\n"
	"		mtrac_action, name, file, line);\n"
	"		exit(49);\n"
	"	}\n"
	"	if(m->magic2 != mtrac_magic) {\n"
	"		fprintf(stderr, \"\\nmemory: (action %d) damaged head of %s pointer handed to free at file %s at line %d.\\n\",\n"
	"		mtrac_action, name, file, line);\n"
	"		exit(50);\n"
	"	}\n"
	"	unsigned long *al = (unsigned long *)(p + sizeof(mtrac) + m->size); assert(((void *)al) - p == m->size + sizeof(mtrac)); // alignment\n"
	"	if(*(unsigned long *)(p + sizeof(mtrac) + m->size) != mtrac_magic)\n"
	"		{ fprintf(stderr, \"\\nmemory: (action %d) damaged end of pointer (#%d) handed to free as '%s' at file %s at line %d. \"\n"
	"			\"Allocated %lu bytes as '%s' in %s at line %d. Damaged magic: %lx, expected %lx\\n\",\n"
	"			mtrac_action, m->index, name, file, line, m->size, m->name, m->file, m->line, *(unsigned long *)(p + m->size), mtrac_magic); exit(51); }\n"
	"	if(m->free) {\n"
	"		fprintf(stderr, \"\\nmemory: (action %d) previously freed %s pointer (#%d) handed to free at file %s at line %d. \"\n"
	"			\"Allocated %lu bytes as '%s' in %s at line %d. Freed as '%s' in %s at line %d as memory action #%d.\\n\",\n"
	"			mtrac_action, name, m->index, file, line, m->size, m->name, m->file, m->line, m->free_name, m->free_file,\n"
	"			m->free_line, m->free_action);\n"
	"		exit(52);\n"
	"	}\n"
	"	if(mtrac_count < 1) {\n"
	"		fprintf(stderr, \"\\nmemory: (action %d) allocation undercount (more frees than allocations) freeing %s at file %s at line %d. \"\n"
	"			\"Allocated %lu bytes as '%s' in %s at line %d.\\n\", mtrac_action, name, file, line, m->size, m->name, m->file, m->line);\n"
	"		exit(53);\n"
	"	}\n"
	"\n"
	"	assert(m->next || m == mtrac_last);\n"
	"	assert(m->previous || m == mtrac_first);\n"
	"\n"
	"	/* ok: free */\n"
	"	mtrac_total -= m->size;\n"
	"	mtrac_freed += m->size;\n"
	"	mtrac_frees++;\n"
	"	mtrac_count--;\n"
	"\n"
	"	/* take out of list of remaining active allocations */\n"
	"	if(m->previous) m->previous->next = m->next;\n"
	"	if(m->next) m->next->previous = m->previous;\n"
	"	if(m == mtrac_first) mtrac_first = m->next;\n"
	"	if(m == mtrac_last) mtrac_last = m->previous;\n"
	"\n"
	"	m->free_action = mtrac_action;\n"
	"	m->free_name = name;\n"
	"	m->free_file = file;\n"
	"	m->free_line = line;\n"
	"	if(mtrac_really_free) (*system_free)(p);\n"
	"}\n"
	"\n"
	"void mtrac_stats() {\n"
	"\n"
	"	mtrac_action++;\n"
	"	printf(\"\\n	Dynamic Allocation Summary\\n\\t--------------------------\\n\");\n"
	"	printf(\"	total allocation: %12d count %12lu bytes\\n\", mtrac_allocations, mtrac_allocated);\n"
	"	printf(\"	total freed     : %12d count %12lu bytes\\n\", mtrac_frees, mtrac_freed);\n"
	"	printf(\"	total remain    : %12d count %12lu bytes\\n\", mtrac_count, mtrac_total);\n"
	"	printf(\"	max allocation  : %12d count %12lu bytes\\n\", mtrac_max_count, mtrac_max_total);\n"
	"	printf(\"	total actions   : %12d count\\n\", mtrac_action);\n"
	"	printf(\"	set limit       :                    %12lu bytes\\n\\n\", mtrac_limit);\n"
	"}\n"
	"\n"
	"void mtrac_dump() {\n"
	"\n"
	"	mtrac_action++;\n"
	"	printf(\"\\n	Remaining Dynamic Allocations\\n\\t-----------------------------\\n\");\n"
	"	mtrac *m = mtrac_first;\n"
	"	if(!m) printf(\"	none.\\n\");\n"
	"	while(m) {\n"
	"		void *p = m;\n"
	"		void *q = p + sizeof(mtrac);\n"
	"		if(m->magic != mtrac_magic) { fprintf(stderr, \"\\nmemory: (action %d) wild pointer traversed.\\n\", mtrac_action); exit(54); }\n"
	"		if(m->magic2 != mtrac_magic) { fprintf(stderr, \"\\nmemory: (action %d) damaged head of pointer traversed.\\n\", mtrac_action); exit(55); }\n"
	"		unsigned long *al = (unsigned long *)(p + sizeof(mtrac) + m->size); assert(((void *)al) - p == m->size + sizeof(mtrac)); // alignment\n"
	"		if(*(unsigned long *)(p + sizeof(mtrac) + m->size) != mtrac_magic) {\n"
	"			fprintf(stderr, \"\\nmemory: (action %d) damaged end of pointer (#%d) traversed. \"\n"
	"				\"Allocated %lu bytes as '%s' in %s at line %d. Damaged magic: %lx, expected %lx\\n\",\n"
	"				mtrac_action, m->index, m->size, m->name, m->file, m->line, *(unsigned long *)(p + m->size), mtrac_magic);\n"
	"			exit(56);\n"
	"		}\n"
	"		printf(\"	Allocation #%3d: <%s> %12lu bytes, file %s, line %d	%s\\n\",\n"
	"				m->index, m->name, m->size, m->file, m->line,\n"
	"				strstr(mtrac_printable, m->name) ? (char *)q : \"\");\n"
	"		m = m->next;\n"
	"	}\n"
	"	printf(\"\\n\");\n"
	"}\n"
	"\n"
	"int mtrac_check() {\n"
	"	mtrac_action++;\n"
	"	if(mtrac_count || mtrac_total) {\n"
	"		fprintf(stderr, \"\\nmemory: %d unfreed dynamic memory allocations of %lu bytes total remain.\\n\", mtrac_count, mtrac_total);\n"
	"		mtrac_stats();\n"
	"		mtrac_dump();\n"
	"		if(mtrac_count || mtrac_total)\n"
	"			exit(57);\n"
	"	} else {\n"
	"		if(mtrac_verbose || opt_memory || opt_verbose || opt_debug)\n"
	"			printf(\"• memory is clean\\n\");\n"
	"	}\n"
	"	return true;\n"
	"}\n"
	"\n"
	"// frees input and replaces with result.\n"
	"char **_mtrac_concat(char *file, int line, int down, int right, char **buf, ...) {\n"
	"	va_list ap;\n"
	"	va_start(ap, buf);\n"
	"	char *add = va_arg(ap, char *);\n"
	"	while(add) {\n"
	"		char *t = mtrac_malloc(strlen(*buf) + down + 4 * right + strlen(add) + 1);\n"
	"		if(!t) { fprintf(stderr, \"out of memory %s %d\", file, line); exit(137); }\n"
	"		strcpy(t, *buf);\n"
	"		while(down > 0) { strcat(t, \"\\n\"); down--; }\n"
	"		while(right > 0) { strcat(t, \"    \"); right--; }\n"
	"		strcat(t, add);\n"
	"		mtrac_free(*buf);\n"
	"		*buf = t;\n"
	"		add = va_arg(ap, char *);\n"
	"	}\n"
	"	va_end(ap);\n"
	"	return buf;\n"
	"}\n"
	"\n"
	" /* add to the gross list of memory allocations to be eventually freed */\n"
	"void *mtrac_gross(void *rec) {\n"
	"	element *e = mtrac_malloc(sizeof (element));\n"
	"	e->payload = rec;\n"
	"	e->previous = mtrac_gross_list;\n"
	"	mtrac_gross_list = e;\n"
	"	return rec;\n"
	"}\n"
	"\n"
	" /* freeing the gross list of memory allocations */\n"
	"void mtrac_free_gross() {\n"
	"	element *p, *e = mtrac_gross_list;\n"
	"	while(e) {\n"
	"		p = e->previous;\n"
	"		mtrac_free(e->payload);\n"
	"		mtrac_free(e);\n"
	"		e = p;\n"
	"	}\n"
	"}\n"
	"\n"
	" /* Thanks to Tom Niemann, whose Lex & Yacc tutorial I kept coming back to for\n"
	"    every restart :-D  https://www.epaperpress.com/lexandyacc/index.html */\n"
	"";

const char *owngrm =

	"##\n"
	"##	 _      ____   _      ___    _          ___       ___\n"
	"##	| |    | |_   \\ \\_/  / / \\  | |\\ |     / / \\  __  _) )\n"
	"##	|_|__  |_|__  /_/ \\  \\_\\_/  |_| \\|     \\_\\_/ (_() _)_)\n"
	"##\n"
	"##\n"
	"##	Lexon — natural language programming\n"
	"##\n"
	"##	Copyright (C) 2016-24 Henning Diedrich. Licensed to you under\n"
	"##	AGPL3 subject to the conditions described in the file LICENSE.\n"
	"##\n"
	"##	Also see https://www.lexon.org/license-0.3.html\n"
	"##\n"
	"##\n"
	"##\n"
	"##	english.lgf — Lexon controlled English grammar\n"
	"##\n"
	"##	Version 0.2.20 / subset 0.3.9 beta 1 - English / Reyes\n"
	"##\n"
	"##	This document is in Lexon Grammar Form, a variation of BNF.\n"
	"##	Square brackets indicate optionality, 'or' separates variants.\n"
	"##	Literals in quotes are case-insensitive.\n"
	"##\n"
	"\n"
	"\n"
	"## Document Head\n"
	"\n"
	"   document:	head terms [covenants]\n"
	"\n"
	"   head:	lex [lexon] [authors] [comment] [preamble]\n"
	"\n"
	"   lex: 	\"LEX\" \":\" name separator\n"
	"   lexon: 	\"LEXON\" \":\" description separator\n"
	"   authors: 	\"AUTHOR\"[\"S\"] \":\" description separator\n"
	"   comment: 	\"COMMENT\"[\"S\"] \":\" description separator\n"
	"   preamble: 	\"PREAMBLE\" \":\" description separator\n"
	"\n"
	"\n"
	"## Sections\n"
	"\n"
	"   t e r m s: 	[\"GENERAL\"] [\"TERMS\" \":\"] [separator] provisions\n"
	"\n"
	"   covenants: 	[covenants] covenant\n"
	"\n"
	"   c o v e n a n t: [\"TERMS\"] \"PER\" name \":\" [separator] provisions\n"
	"\n"
	"\n"
	"## Provisions\n"
	"\n"
	"   p r o v i s i o n s: definitions [statements] [clauses]\n"
	"\n"
	"\n"
	"## Definitions\n"
	"\n"
	"   definitions: [definitions] definition\n"
	"\n"
	"   definition: 	[article] quote name quote \"is\" type_term separator\n"
	"		or [article] quote name quote \"is\" this_contract separator\n"
	"\n"
	"   type_term:	[article] type\n"
	"\n"
	"## Types\n"
	"\n"
	"   type: 	person or amount or time or binary or text or data\n"
	"\n"
	"   person:	\"person\"\n"
	"   amount:	\"amount\"\n"
	"   time:	\"time\"\n"
	"   binary:	\"binary\"\n"
	"   text:	\"text\"\n"
	"   data:	\"data\"\n"
	"\n"
	"   this_contract: this \"contract\"\n"
	"		or this name\n"
	"\n"
	"   all_contracts: \"all\" \"contracts\"\n"
	"\n"
	"   this: 	\"this\" or \"these\"\n"
	"\n"
	"\n"
	"## Clauses\n"
	"\n"
	"   clauses: 	[clauses] clause\n"
	"\n"
	"   c l a u s e : \"CLAUSE\" \":\" name separator body\n"
	"\n"
	"   body: 	statements or function\n"
	"\n"
	"\n"
	"## FUNCTION\n"
	"\n"
	"   function: 	[article] quote name quote illocutor [\":\"] expression separator\n"
	"\n"
	"\n"
	"\n"
	"# IV. SENTENCE LEVEL\n"
	"\n"
	"## STATEMENT\n"
	"\n"
	"   s t a t e m e n t s : [statements] statement\n"
	"\n"
	"   statement:	action or flagging\n"
	"\n"
	"\n"
	"## ACTION\n"
	"\n"
	"   action:	subject [permission [comma] [condition [comma] [\":\"]]] predicates separator\n"
	"\n"
	"\n"
	"\n"
	"# V. PHRASE LEVEL\n"
	"\n"
	"## SUBJECT\n"
	"\n"
	"   subject:	symbols\n"
	"\n"
	"\n"
	"## SYMBOLS\n"
	"\n"
	"   symbols:	[symbols catena] symbol\n"
	"\n"
	"   symbol:	[article] [new] name\n"
	"		or [article] [new] type\n"
	"\n"
	"   catena:	\"or\" or comma\n"
	"\n"
	"\n"
	"## OBJECT\n"
	"\n"
	"   object:	symbol or reflexive or [\"the\"] \"escrow\"\n"
	"\n"
	"   reflexive:	\"myself\" or \"yourself\" or \"herself\" or \"himself\" or \"oneself\" or \"itself\" or \"themself\" or \"ourselves\" or \"yourselves\" or \"themselves\"\n"
	"\n"
	"\n"
	"## SELF-REFERENCE\n"
	"\n"
	"   contract:    this_contract\n"
	"		or all_contracts\n"
	"\n"
	"\n"
	"## PREDICATE\n"
	"\n"
	"   predicates:	predicates comma [\"and\" [\"also\"]] [\"if\" \"so\"] [\"afterwards\"] predicate\n"
	"		or predicates comma \"and\" \"with\" \"this\" predicate\n"
	"		or predicate\n"
	"\n"
	"\n"
	"   predicate:	certification\n"
	"		or declaration\n"
	"		or filing\n"
	"		or registration\n"
	"		or grantment\n"
	"		or appointment\n"
	"		or acceptance\n"
	"		or fixture\n"
	"		or setting\n"
	"		or payment\n"
	"		or sending\n"
	"		or notification\n"
	"		or termination\n"
	"\n"
	"   permission:	\"may\"\n"
	"\n"
	"\n"
	"## CERTIFICATION PREDICATE\n"
	"\n"
	"   certification: certify symbol [[\"as\"] expression]\n"
	"		or certify contract [\"as\"] symbol\n"
	"\n"
	"   certify:	\"certify\" or \"certifies\"\n"
	"\n"
	"\n"
	"## DECLARAION PREDICATE\n"
	"\n"
	"   declaration: declare symbol [[\"to\" \"be\"] expression]\n"
	"		or declare contract [\"as\"] symbol\n"
	"\n"
	"   declare:	\"declare\" or \"declares\"\n"
	"\n"
	"\n"
	"## FILING PREDICATE\n"
	"\n"
	"  filing:	file [\"for\"] symbol [[\"to\" \"be\"] expression]\n"
	"		or file [\"for\"] contract [\"to\" \"be\"] symbol\n"
	"\n"
	"  file:		\"file\" or \"files\"\n"
	"\n"
	"\n"
	"## REGISTRATION PREDICATE\n"
	"\n"
	"   registration: register symbol [[\"as\"] expression]\n"
	"		or register contract [\"as\"] symbol\n"
	"\n"
	"   register:	\"register\" or \"registers\"\n"
	"\n"
	"\n"
	"## GRANT PREDICATE\n"
	"\n"
	"   grantment:	grant symbol\n"
	"\n"
	"   grant:	\"grant\" or \"grants\"\n"
	"\n"
	"\n"
	"## APPOINTMENT PREDICATE\n"
	"\n"
	"   appointment:	appoint symbol [[\"as\"] expression]\n"
	"\n"
	"   appoint:	\"appoint\" or \"appoints\"\n"
	"\n"
	"\n"
	"## ACCEPTANCE PREDICATE\n"
	"\n"
	"   acceptance:	accept symbol [[\"as\"] expression]\n"
	"\n"
	"   accept:	\"accept\" or \"accepts\"\n"
	"\n"
	"\n"
	"## FIXTURE PREDICATE\n"
	"\n"
	"   fixture:	fix symbol [\"as\" expression]\n"
	"		or fix contract \"as\" symbol\n"
	"\n"
	"   fix:		\"fix\" or \"fixes\"\n"
	"\n"
	"   fixed:	\"fixed\"\n"
	"\n"
	"\n"
	"## FIXTURE PREDICATE / PASSIVE\n"
	"\n"
	"   setting:	illocutor [\"then\"] [\"therefor\"[\"e\"]] symbol\n"
	"\n"
	"   illocutor: 	be [\"defined\"] [\"as\"]\n"
	"\n"
	"   be:		\"be\" or \"is\"\n"
	"\n"
	"\n"
	"## PAYMENT PREDICATE\n"
	"\n"
	"   payment: 	pay [from_escrow] expression preposition object\n"
	"		or pay expression from_escrow preposition object\n"
	"		or pay escrow preposition object\n"
	"\n"
	"   pay:		\"pay\" or \"pays\" or \"return\" or \"returns\" or \"repay\" or \"repays\"\n"
	"\n"
	"   preposition:	\"to\" or \"into\" or \"of\"\n"
	"\n"
	"   escrow:	[\"the\"] [\"remainder\" \"of\" \"the\"] \"escrow\"\n"
	"\n"
	"   from_escrow:	\"from\" [\"the\"] [\"remainder\" \"of\" \"the\"] \"escrow\"\n"
	"\n"
	"\n"
	"## SENDING PREDICATE\n"
	"\n"
	"   sending:	send expression preposition object\n"
	"\n"
	"   send:	\"send\" or \"sends\"\n"
	"\n"
	"\n"
	"## NOTIFICATION PREDICATE\n"
	"\n"
	"   notification: notify object [preposition expression]\n"
	"\n"
	"   notify:	\"notify\" or \"notifies\"\n"
	"\n"
	"\n"
	"## TERMINATION PREDICATE\n"
	"\n"
	"   termination:	terminate this_contract\n"
	"		or terminate all_contracts\n"
	"\n"
	"   terminate:	\"terminate\" or \"terminates\"\n"
	"\n"
	"\n"
	"## FLAGGING\n"
	"\n"
	"   flagging:	[this_contract] illocutor [\"then\"] [\"therefore\"] symbol separator\n"
	"\n"
	"\n"
	"\n"
	"# VI. EXPRESSION LEVEL\n"
	"\n"
	"## CONDITIONS\n"
	"\n"
	"   condition:	if expression [[comma] \"then\"]\n"
	"\n"
	"   if:		\"if\" or \"given\" \"that\" or \"provided\"\n"
	"\n"
	"\n"
	"## EXPRESSION\n"
	"\n"
	"   expression: 	combination\n"
	"\n"
	"\n"
	"## COMPARISON\n"
	"\n"
	"   scalar_comparison:	scalar_expression comparison_operator scalar_expression\n"
	"\n"
	"   comparison_operator:	equal\n"
	"   			or greater\n"
	"			or less\n"
	"			or later\n"
	"\n"
	"   equal:		\"equal\" [\"to\"]\n"
	"			or \"equaling\"\n"
	"			or \"is\" [\"equal\" [\"to\"]]\n"
	"			or \"being\" [\"equal\" [\"to\"]]\n"
	"\n"
	"   greater:		[\"is\"] \"greater\" [\"than\"]\n"
	"   			\"being\" \"greater\" [\"than\"]\n"
	"\n"
	"   less:		[\"is\"] \"less\" [\"than\"]\n"
	"   			\"being\" \"less\" [\"than\"]\n"
	"   			[\"is\"] \"smaller\" [\"than\"]\n"
	"   			\"being\" \"smaller\" [\"than\"]\n"
	"\n"
	"   later:		\"is\" \"at\" [\"the\"] \"least\"\n"
	"			or \"lies\" \"at\" [\"the\"] \"least\"\n"
	"\n"
	"   scalar_expression:	symbol or scalar or point_in_time or [\"the\"] \"escrow\"\n"
	"\n"
	"\n"
	"## LOGIC EXPRESSIONS\n"
	"\n"
	"   combination: combinor [comma [combinator] combination]\n"
	"\n"
	"   combinor:	combinand [combinator combinor]\n"
	"\n"
	"   combinand:	symbol [expiration]\n"
	"   		or symbol timeliness\n"
	"		or reflexive\n"
	"   		or [article] description\n"
	"		or scalar_comparison\n"
	"		or negation\n"
	"		or existence\n"
	"		or point_in_time\n"
	"		or expiration\n"
	"\n"
	"   combinator:	or_\n"
	"		or and\n"
	"		or neither\n"
	"		or nor\n"
	"\n"
	"   or_:		\"or\"\n"
	"\n"
	"   and:		\"and\"\n"
	"\n"
	"   neither:	\"neither\"\n"
	"\n"
	"   nor:		\"nor\"\n"
	"\n"
	"   existence:	symbol equal fixed\n"
	"		or \"there\" be symbol\n"
	"		or contract be symbol\n"
	"		or symbol being true\n"
	"\n"
	"   negation:	negator symbol\n"
	"		or symbol negator fixed\n"
	"		or \"there\" negator symbol\n"
	"		or contract negator symbol\n"
	"\n"
	"   negator:	[be] \"not\"\n"
	"		or [be] \"no\"\n"
	"\n"
	"   being:	\"is\"\n"
	"		or \"has\" \"been\"\n"
	"		or \"was\"\n"
	"\n"
	"   true:	\"true\"\n"
	"		or \"yes\"\n"
	"		or \"certified\"\n"
	"		or \"declared\"\n"
	"		or \"announced\"\n"
	"		or \"filed\" [\"for\"]\n"
	"		or \"signed\" \"off\" [\"on\"]\n"
	"\n"
	"## FILLERS\n"
	"\n"
	"   article:	\"a\" or \"an\" or \"the\"\n"
	"\n"
	"   new:		\"new\" or \"next\" or \"coming\" or \"incoming\"\n"
	"\n"
	"\n"
	"## TIME\n"
	"\n"
	"   point_in_time: current_time\n"
	"		or relative_time\n"
	"\n"
	"   current_time: \"the\" [\"respective\"] [\"then\"] \"current\" \"time\"\n"
	"		or \"now\"\n"
	"\n"
	"   relative_time: duration [\"in\" \"the\"] \"past\" [symbol]\n"
	"		or duration \"after\" symbol\n"
	"\n"
	"   duration:	scalar_expression time_unit\n"
	"\n"
	"   time_unit:	years or months or weeks or days or hours or minutes or seconds or milliseconds\n"
	"\n"
	"   years:	\"year\"[\"s\"]\n"
	"   months:	\"month\"[\"s\"]\n"
	"   weeks:	\"week\"[\"s\"]\n"
	"   days:	\"day\"[\"s\"]\n"
	"   hours:	\"hour\"[\"s\"]\n"
	"   minutes:	\"minute\"[\"s\"]\n"
	"   seconds:	\"second\"[\"s\"]\n"
	"   milliseconds: \"millisecond\"[\"s\"]\n"
	"\n"
	"   expiration:	\"has\" \"passed\" or [\"is\"] \"past\"\n"
	"   timeliness:  [\"has\"] \"not\" [\"yet\"] \"passed\" or [\"is\"] \"not\" [\"yet\"] \"past\" [\"yet\"]\n"
	"";

const char *manual =

	"﻿      _      ____   _      ___    _          ___       ___\n"
	"     | |    | |_   \\ \\_/  / / \\  | |\\ |     / / \\  __   ) )\n"
	"     |_|__  |_|__  /_/ \\  \\_\\_/  |_| \\|     \\_\\_/ (_() _)_)\n"
	"\n"
	"\n"
	"            Lexon — natural language programming\n"
	"\n"
	"                        LEXON\n"
	"                       WRITER'S\n"
	"                        MANUAL\n"
	"                         0.3\n"
	"\n"
	"        This excerpt from the manual describes the\n"
	"        workflow to create and use Lexon digital\n"
	"        contracts on the Ethereum blockchain. It\n"
	"        covers writing, compiling and deploying of\n"
	"        Lexon texts.\n"
	"\n"
	"        You don't need any of this to READ Lexon.\n"
	"\n"
	"        There is further material, background,\n"
	"        papers, books, and online references at\n"
	"        https://www.lexon.org. The Lexon book\n"
	"        offers all relevant angles in a concise for-\n"
	"        mat. The Lexon BIBLE adds details & trivia.\n"
	"        Characteristica Universalis is a high-level,\n"
	"        philosophical book covering 350+ years of\n"
	"        research into language and logic, up to\n"
	"        AI. \n"
	"\n"
	"        This manual includes excerpts from these\n"
	"        sources but focuses on the practical and\n"
	"        technical aspects of writing Lexon texts.\n"
	"        Get the full PDF version online at\n"
	"        https://lexon.org/manual.html\n"
	"\n"
	"\n"
	"\n"
	"DISCLAIMERS\n"
	"\n"
	"The information provided in this document is strictly for educational purposes.\n"
	"There are no warranties, express or implied. Any use of this information is at\n"
	"your own risk. The author does not assume and hereby disclaims any liability to\n"
	"any party for any loss, damage, or disruption.\n"
	"\n"
	"Lexon is not an all-purpose human language. An unambiguous language is\n"
	"desirable for programming and lawmaking, less so for other purposes of human\n"
	"communication.1\n"
	"\n"
	"Lexon compiler output must be audited before using it in production. There is\n"
	"no warranty for fitness for any purpose, nor any other warranty for the\n"
	"compiler output. See  the  License  text  at https://lexon.org/license.html.\n"
	"\n"
	"\n"
	"\n"
	"LICENSE\n"
	"\n"
	"There is no claim to the output products of the Lexon compiler. Any text you\n"
	"write in Lexon and anything you create using the Lexon compiler is yours or\n"
	"determined by arrangements you made.\n"
	"\n"
	"This document is licensed under the GNU Public License (GPL) version 3. The\n"
	"license text can be found at https://www.gnu.org/licenses/gpl-3.0.txt.\n"
	"Basically, you can quote, share or modify this document but must give credit\n"
	"and allow the same.\n"
	"\n"
	"Papers quoted are copyrighted as provided in the papers.\n"
	"\n"
	"Lexon is licensed to you under AGPL 3.0 under the tems provided below.\n"
	"\n"
	"\n"
	"\n"
	"VERSION\n"
	"\n"
	"Excerpt of text version 1.0.1 / 0.5.5.1 of this manual, for Lexon 0.3 on Ethereum.\n"
	"\n"
	"\n"
	"\n"
	"INTRODUCTION\n"
	"\n"
	"Lexon is a plain-text programming language. This means that it reads like natural English and digital contracts written in Lexon that run on the blockchain can be read and understood by anyone, without requiring any knowledge of programming.\n"
	"\n"
	"Lexon's digital contracts inherit their unstoppable power from smart contracts. That they are also readable by anyone - not just programmers - is their interface to the real world. They connect to the legal system, for far-reaching consequences: a digital contract cannot be broken and is a legal agreement.\n"
	"\n"
	"To work its magic, Lexon perfects an AI language processing approach that had been researched for decades.2 Its contribution is 'Zen-like,' reducing transformation steps to stay closer to how human thought works: its internal data model retains human-readability. This makes Lexon transparent as well as precise and provides unparalleled agency.\n"
	"\n"
	"The example contract below is a minimal escrow that is an agreement between a payer and a receiver. The notary decides whether a payment in escrow should be paid out to the receiver or sent back to the payer. This could be the reaction to a corresponding deal being aborted, goods not arriving or being returned for any reason. The contract looks only at the payment side, with the notary in the role of the oracle, i.e., the connection from the blockchain to the real world.\n"
	"\n"
	"As is, the contract could serve many different use cases. There could be many variations, including a scenario that works without oracles.\n"
	"\n"
	"\n"
	"\n"
	"A Lexon digital contract example:\n"
	"\n"
	"        LEX Escrow.\n"
	"\n"
	"        \"Payer\" is a person.\n"
	"        \"Receiver\" is a person.\n"
	"        \"Notary\" is a person.\n"
	"        \"Fee\" is an amount.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Receiver, appoints the Notary, and fixes the Fee.\n"
	"\n"
	"        CLAUSE: Pay Out.\n"
	"        The Notary may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Receiver.\n"
	"\n"
	"        CLAUSE: Pay Back.\n"
	"        The Notary may pay from escrow the Fee to themselves, and afterwards return the \n"
	"        remainder of the escrow to the Payer.\n"
	"\n"
	"\n"
	"\n"
	"In the following chapters, we will discuss this example's grammar, and compile this digital contract using the online Lexon compiler.\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"QUICK START\n"
	"\n"
	"\n"
	"As a crypto developer, all you need to get started may be this:\n"
	"\n"
	"LEXON WRITING AND COMPILATION\n"
	"\n"
	"There is no training required to read and understand a Lexon text.\n"
	"\n"
	"To write your first own digital contract, take an example and modify it at https://lexon.org/compiler.\n"
	"\n"
	"The online compiler screen has an example button that rotates through a number of texts.\n"
	"\n"
	"Click compile, copy and paste the resulting Solidity code to Remix to deploy, or deploy it manually as described below for the Escrow example.\n"
	"\n"
	"To understand the vocabulary and grammar, dive into the interactive vocabulary at https://lexon.org/vocabulary. Clicking around this page is an excellent way to get a feel for Lexon.\n"
	"\n"
	"At the time of writing, the word reference in this manual is the same as the one at the online vocabulary.\n"
	"\n"
	"\n"
	"\n"
	"CONCEPTS\n"
	"\n"
	"The four most important concepts to understand to WRITE Lexon texts:\n"
	"\n"
	"LEXON\n"
	"\n"
	"Lexon unites developments in computational law, cryptography, computer sciences, AI3 and linguistics to achieve long-sought milestones in each field: digital contract analysis, legally enforceable smart contracts, self-documenting code, deterministic language processing, and an executable human language. The resulting accessibility and agency open new ways even to think about some of the more intractable-looking challenges of our times and solve them. It is perfect for trustless private law, i.e., legally valid agreements implemented on the blockchain that can't be broken.\n"
	"\n"
	"LEXON COMPILER\n"
	"\n"
	"The Lexon compiler4, 5 accepts text adhering to Lexon's grammar and transposes this natural-language code to the Ethereum language Solidity. It is a web3 application interacting with the Ethereum blockchain to help creating new web3 applications that run on Ethereum.\n"
	"\n"
	"DIGITAL CONTRACTS\n"
	"\n"
	"Blockchain smart contracts written in Lexon are called digital contracts. While lawmakers will need time to understand their new options, Lexon shines as a language for private law, i.e., contracting. Digital contracts are legally enforceable agreements.\n"
	"\n"
	"SOLIDITY \n"
	"\n"
	"Solidity is the language that smart contracts are programmed in for the Ethereum blockchain. It is a purpose-built, 3rd generation language, designed to be as safe as possible. Lexon users, however, do not need to learn Solidity to be able to create smart contracts.\n"
	" \n"
	"\n"
	"\n"
	"\n"
	"********************************************************************************\n"
	"VOCABULARY\n"
	"********************************************************************************\n"
	"\n"
	"\n"
	"The point of Lexon is that one does NOT have to learn it to READ it.\n"
	"\n"
	"But even learning to write Lexon is best done by looking at examples rather than memorizing words. This is no different than how a human language, or a programming language, or even legalese is usually picked up. The allowed use of a word, its context, are what matters. \n"
	"\n"
	"The Lexon 0.3 word list starts on pg. 23 and is online at http://lexon.org/vocabulary. The webpage is a learning tool to help grasp the bigger picture, not neccessarily to memorize individual words. To this end, one thousand links are at your disposal for fast navigation between words, examples and references. You will find that clicking around reveals the deeper structure of Lexon, beyond words.\n"
	"\n"
	"As the Lexon grammar is a so-called controlled grammar, only some ways of using a word are permitted, fewer than in normal English. This is why it is better learned by doing than done by learning. In fact, it can be particularly hard to 'unlearn' what you know is correct in normal language. But you will – and that is a unique quality of Lexon for a programming language – get a feel for what works.\n"
	"\n"
	"The following is the list of the known words in Lexon 0.3 (13) that between themselves stand up the Lexon grammar. Because you can define words and phrases when writing Lexon, the vocabulary and grammar complexity of Lexon are unlimited from the point of view of natural language. This is discussed below.\n"
	"\n"
	"Note that these words can be redefined as names but in that case cannot serve their original function anywhere in the contract. The exception are category names (types; marked with an asterisk (*) above). They cannot be redefined but can be used as generic names (see, e.g., amount). All words can be used as part of names without losing their original, stand-alone function.\n"
	"\n"
	"In the individual, per-word entries on the following pages, the first information about each word is, in what linguistic capacity it is used in Lexon. This angle can help because English words frequently cover two ore more different grammatical roles. The second line is technical, based on computer science designations for the function that a word is used in in Lexon. It will more often than not be a helpful pointer for non-programmers, too. In many cases, a description follows that describes the use of the word and occasionally presents additional context. Note that the description often seems to explain the obvious, because you know how English works. However, it can help to spell it out to learn to write Lexon. After that, one or more examples show the word in the context of an examples sentence. \n"
	"\n"
	"Note that at http://lexon.org/vocabulary this sentence can be inspected in the context of a complete digital contract by clicking the link immediately below the example sentence. The link leads to a contract that contains the examples sentence, and highlights it.\n"
	"\n"
	"\n"
	"\n"
	"Breadth and Capacity\n"
	"\n"
	"Lexon's vocabulary is unlimited because a) any noun or compound term can be defined and used in a Lexon text, b) any phrase can be used as clause name and then used as part of a sentence elsewhere in the text, and c) the Lexon compiler is extensible and keywords can and are added while the grammar grows more powerful.\n"
	"\n"
	"a) Definitions:\n"
	"\n"
	"see Payer, Payee, etc. in the Escrow example (pg. 6).\n"
	"\n"
	"b) Clauses:\n"
	"\n"
	"cf. Noticed, Factually Breached, etc. in the Evaluation License example, see\n"
	"\n"
	"https://lexon.org/vocabulary.html#LicenseEvaluation \n"
	"\n"
	"c) Keywords:\n"
	"\n"
	"cf. vocabulary 0.3 from pg. 23 vs. 0.2 in the 2020 (DRAFT 3) Lexon Bible, and the forthcoming Lexon Extension Form.\n"
	"\n"
	"The latter—Keywords—is a slow and incremental process. A special, faster process has been prepared for verbs of foundational importance – like move for robotics – that can sustain an entire domain.14 The two former bullet points—Definitions and Clauses—are instant and happen when a writer authors a Lexon text.\n"
	"\n"
	"Each Lexon digital contract therefore has its own vocabulary, extending the dictionary on the fly while drafting, as integral and organic part of the writing process. This is in keeping with the way that paper contracts are written: terms are being defined for clarity, laying the ground for an agreement's text. That's exactly how Lexon's vocabulary grows while penning a digital contract.\n"
	"\n"
	"However, as it comes, before any definitions are added, Lexon 0.3 understands 91 keywords plus variations, of which roughly half are processed in an interesting way. Many have only one specific function as marker, like CLAUSE, or make the list solely by virtue of being part of a fix multi-word term, with no independent function, like OFF in SIGN OFF.\n"
	"\n"
	"To put the word count into perspective, a modern 3rd generation programming language like Rust has about 50 reserved keywords, which are mostly used in the rigid, less interesting way. Beginner's English is said to consist of about 300 words, the Basic English world language project15 has about 850. These latter counts include many nouns; Lexon's vocabulary contains almost no nouns because these are as a rule defined by the writer of a Lexon text and the Lexon compiler understands them from their function as implied by the rest of the text.16 This is a fundamental aspect of Lexon's approach and the reason why the Lexon compiler needs to 'understand' relatively few words out of the box. The nouns and phrases that a user adds are inevitably what gives a text depth. The way that definitions work, the compiler learns the role of the new words on the go and recognizes them in the text from that point on. Clause names, however, can be the most interesting because they are the way to insert any complexity of grammar, which can make Lexon texts look rich and elegant. This is a consequential design choice that serves to include language constructs outside of the limit up to which the controlled grammar has to be observed – offering instead of a hard stop, freedom to be fully creative within the safety of a well defined reference frame. Lexon 'understands' such phrases (the clause names) en block, the clause itself defines their meaning. The (multi-word) name of a clause's internal grammatical composition is not analysed. The way that the processing of clause names is isolated from the rest of the text makes it possible to mix these monolithic elements with the bulk of the text that the Lexon compiler processes word-for-word, i.e., 'more truely understands'. This combination is a pragmatic way to empower writers to add complexity without having to think about any controlled grammar rules, but importantly also: to freely add vocabulary. The new words are baked into the specific grammatical way that they are presented (in the clause name). They need not be explained further. This mode of extension makes perfect sense for Lexon.\n"
	"\n"
	"Third generation programming languages generally allow to add variable names and add types. But they can never reach beyond their fix grammar. Lexon, in contrast, accepts any grammatical extension through the freedom it offers in naming clauses. There is not even a requirement to avoid the initial 91 words that Lexon knows when creating compound new compositions.\n"
	"\n"
	"But the list of initial words cannot be redefined. It is therefore on the one hand desirable that it includes few nouns. The reason that Lexon, on the other hand, has a larger basic vocabulary than, e.g., Rust is that Lexon's grammar is designed to enable multiple ways of expressing the same, to make writing more intuitive, and to allow for more fluid, natural-appearing texts. This does not mean that Lexon's grammar is ambigious, i.e., that the same sentence could have multiple meanings. It only means that the same meaning can be expressed by differently worded sentences.17\n"
	"\n"
	"\n"
	"\n"
	"WORD LIST\n"
	"\n"
	"The entries are based on the grammar version 0.2.20 / subset 0.3.8 alpha 79 - English / Reyes.\n"
	"For an interactive version of this word list, tied into examples, visit http://lexon.org/vocabulary.\n"
	"Don’t try to learn these by heart, this section is to get an idea and to turn to in doubt.\n"
	"\n"
	"---------------------------------------\n"
	"A, AN\n"
	"---------------------------------------\n"
	"indefinite article\n"
	"no op\n"
	"---------------------------------------\n"
	"Articles can be left out with no change in meaning. They are optional to increase readability.\n"
	"\n"
	"They can be omitted, because the name they precede must always be unambigous on its own. This is familiar practice with paper contracts.\n"
	"\n"
	"Same goes for the, this, these.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"AFTER\n"
	"---------------------------------------\n"
	"timewise prepostion\n"
	"time operator\n"
	"---------------------------------------\n"
	"After is used to calculate a point in time, relative to a given one.\n"
	"\n"
	"        \"Termination Period\" is defined as 365 days after the Termination Statement Time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"For more on how to use time, see hours and days.\n"
	"---------------------------------------\n"
	"AFTERWARDS\n"
	"---------------------------------------\n"
	"adverb\n"
	"causal concatenation\n"
	"---------------------------------------\n"
	"Keyword that introduces temporal order, which is not a default in Lexon.\n"
	"\n"
	"Separate sentences are performed independently of each other, declaratively, rather than one after the other. Afterwards serves to bind statements into one sentence and to establish that the phrase following it is performed only after all side effects of the phrase before it have been established.\n"
	"\n"
	"To illustrate by example, in the Lexon sentence given below, the remainder is what remains after the Fee mentioned before afterwards has been deducted.\n"
	"\n"
	"Cf. THEREFORE.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards return the remainder of the escrow to the Payer.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"ALL\n"
	"---------------------------------------\n"
	"adjective\n"
	"quantifier\n"
	"---------------------------------------\n"
	"Only with CONTRACTS.\n"
	"\n"
	"All contracts means all digital contracts in a contract system. This includes the main contract as well as the covenants, or subcontracts.\n"
	"\n"
	"---------------------------------------\n"
	"ALSO\n"
	"---------------------------------------\n"
	"adverb\n"
	"no op\n"
	"---------------------------------------\n"
	"Only appears with AND.\n"
	"\n"
	"And also is synonymous to AND.\n"
	"\n"
	"---------------------------------------\n"
	"AMOUNT\n"
	"---------------------------------------\n"
	"noun\n"
	"type\n"
	"---------------------------------------\n"
	"Defines that a name stands for an amount. In the example, Digital Asset Collateral is marked as being used as the handle for a specific number in the document.\n"
	"\n"
	"        \"Digital Asset Collateral\" is an amount.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Amount can also be used as a name itself, without being first defined. It can only stand for an amount – i.e., for a number and not a text or a time – and Amount must be spelled with a capital 'A' in this case.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"AND\n"
	"---------------------------------------\n"
	"conjunction\n"
	"logical and procedural operator\n"
	"---------------------------------------\n"
	"Concatenates actions ...\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"... as well as logical expressions.\n"
	"A phrase that contains and is true if the part left and the part right of the and are true. There can also be multiple parts, each separated by and. All of them need to be true for the entire expression to be true.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"For precedence and the interplay between and and or, see or.\n"
	"\n"
	"---------------------------------------\n"
	"ANNOUNCED\n"
	"---------------------------------------\n"
	"adjective\n"
	"truth value\n"
	"---------------------------------------\n"
	"Functions like FIXED.\n"
	"\n"
	"---------------------------------------\n"
	"APPOINT, APPOINTS\n"
	"---------------------------------------\n"
	"verb\n"
	"parameter assignment operator\n"
	"---------------------------------------\n"
	"Expresses that the subject of the sentence will determine what the specified object's names will mean concretely. In the example, who the Payee and the Arbiter are.\n"
	"\n"
	"Functions like fix, see additional notes regarding the subject there.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"Functional synonym to certify, declare, file, fix, grant, and register.\n"
	"\n"
	"---------------------------------------\n"
	"AS\n"
	"---------------------------------------\n"
	"conjunction\n"
	"value assignment operator part\n"
	"---------------------------------------\n"
	"Assigns the value of the expression to its right to the name on its left.\n"
	"\n"
	"        The Secured Party may file a Termination Statement, and certify the Termination Statement Time as the then current time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"As can also make a name true that was defined as a binary. In this example, License serves as an object that means the entire contract system, which ultimately is a redundant scope. The relevant mutation is that Commissioned becomes a fact, i.e., true.\n"
	"\n"
	"        The Licensor may certify this License as Commissioned.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"AT\n"
	"---------------------------------------\n"
	"preposition\n"
	"quantifier\n"
	"---------------------------------------\n"
	"Only in conjunction with LEAST.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"AUTHOR, AUTHORS\n"
	"---------------------------------------\n"
	"noun\n"
	"keyword\n"
	"---------------------------------------\n"
	"The information after the AUTHOR(s) keyword is expected to be the name(s) of the creator(s) of the Lexon text. They are meta data, not parsed, and not used in the document itself.\n"
	"\n"
	"As a convention, author and authors are usually spelled in uppercase.\n"
	"\n"
	"        AUTHORS: FLORIAN IDELBERGER, HENNING DIEDRICH\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"BE\n"
	"---------------------------------------\n"
	"verb\n"
	"assignment\n"
	"---------------------------------------\n"
	"Used with a meaning like shall.\n"
	"\n"
	"Functions like IS and can be used synonymously. The linguistic difference is irrelevant for the machine.\n"
	"\n"
	"        \"Noticed\" be defined as a Notice Time being fixed.\n"
	"\n"
	"---------------------------------------\n"
	"BEEN\n"
	"---------------------------------------\n"
	"verb\n"
	"comparison operator\n"
	"---------------------------------------\n"
	"Appears only in conjunction with HAS.\n"
	"\n"
	"Has been functions like BEING.\n"
	"\n"
	"        The Arbiter may, if the Notice Time has been fixed, return the Fee to the Seller.\n"
	"\n"
	"---------------------------------------\n"
	"BEING\n"
	"---------------------------------------\n"
	"present participle\n"
	"comparison operator\n"
	"---------------------------------------\n"
	"Compares the expression to its left with the expression on its right and results in everything together being TRUE or FALSE.\n"
	"\n"
	"In the example, being tests Notice Time for whether it had been fixed before. Noticed will be true exactly when Notice Time is known, and false if, no value has been given for Notice Time before at any point during the lifetime of the contract.\n"
	"\n"
	"        \"Noticed\" is defined as a Notice Time being fixed.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"BINARY\n"
	"---------------------------------------\n"
	"adjective\n"
	"type\n"
	"---------------------------------------\n"
	"Defines a name as standing for a binary value, e.g., YES or NO, or TRUE or FALSE.\n"
	"\n"
	"Note that an undefined binary name is considered to have the value FALSE. Declaring a name sets it to TRUE. Likewise, testing whether a binary name is declared, checks whether it is TRUE.\n"
	"\n"
	"        \"Default\" is a binary.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"CERTIFIED\n"
	"---------------------------------------\n"
	"adjective\n"
	"«defined»\n"
	"---------------------------------------\n"
	"Expresses that a name has a value assigned, i.e., is not unbound or undefined.\n"
	"\n"
	"In the example, being tests Notice Time for whether it had been certified before. Noticed will be true exactly when a Notice Time is known, and false if no value has been given for Notice Time before, at any point during the lifetime of the contract.\n"
	"\n"
	"Functions like FIXED.\n"
	"\n"
	"        \"Noticed\" is defined as a Notice Time being certified.\n"
	"\n"
	"---------------------------------------\n"
	"CERTIFIES, CERTIFY\n"
	"---------------------------------------\n"
	"verb\n"
	"assignment operator\n"
	"---------------------------------------\n"
	"Expresses that the subject of the sentence will determine what the specified object's names will mean concretely. In the example, who the Payee and the Arbiter are.\n"
	"\n"
	"Functions like fix, see additional notes regarding the subject and invocation there.\n"
	"\n"
	"        The Filing Office may certify the File Number.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Functional synonym to appoint, declare, file, fix, grant, and register.\n"
	"\n"
	"---------------------------------------\n"
	"CLAUSE\n"
	"---------------------------------------\n"
	"noun\n"
	"function keyword\n"
	"---------------------------------------\n"
	"Signals the start of a clause. A colon must follow, and the name of the clause. Then, the statements that constitute the clause.\n"
	"\n"
	"Almost every digital contract has one or more clauses. Only in rare, simplistic cases does a contract have only a recital.\n"
	"\n"
	"Either a clause's name is used to instigate actions that change the state of the contract:\n"
	"\n"
	"        CLAUSE: Pay Back.\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards return the remainder of the escrow to the Payer.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"Or, a clause name can itself be a value, if the clause uses defined.\n"
	"The concrete meaning of the name of such clause is dynamic. That is, the concrete meaning of the clause name is not assigned once and for all at any point in time. Instead, whenever the clause name is used elsewhere in any context, the expression right-hand of defined is re-evaluated for its now current result, which is then the meaning, or value, of that clause name.\n"
	"\n"
	"        Clause: Termination Period.\n"
	"        \"Termination Period\" is defined as 365 days after the Termination Statement Time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"The clause name can be used as an expression in the context of other clauses, i.e the name can be used like a value.\n"
	"The example below uses the name Termination Period that is defined in the example above.\n"
	"\n"
	"        The Filing Office may, if the Termination Period has passed, terminate this contract.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"COMMENT, COMMENTS\n"
	"---------------------------------------\n"
	"noun\n"
	"comment keyword\n"
	"---------------------------------------\n"
	"Start of comments that are not translated by the compiler.\n"
	"\n"
	"Functions like PREAMBLE but can be used multiple times in different places.\n"
	"\n"
	"Lexon is self-documenting, which greatly diminishes the role of comments. They should be used sparingly or not at all. They can help to explain a more convoluted set of conditions, as can be found in contracts that need to spell out things in detail, including all relevant fringe cases.\n"
	"\n"
	"Care should be taken to clarify that a comment is not part of the legally binding text; but is written to provide motivation or explain complex aspects with a broad brush, to make the contract easier to understand for a human reader. Such clarification may be added as part of the comment itself.\n"
	"\n"
	"As a convention, COMMENT is usually spelled in uppercase.\n"
	"\n"
	"        COMMENT: A license can be for any tangible or intangible good.\n"
	"\n"
	"Cf. PREAMBLE.\n"
	"\n"
	"---------------------------------------\n"
	"CONTRACT, CONTRACTS\n"
	"---------------------------------------\n"
	"noun\n"
	"self reference\n"
	"---------------------------------------\n"
	"Contract as well as all contracts stand for the contract (system) itself, including all covenants (subcontracts)\n"
	"\n"
	"Contract can either be used to define a proper name for the digital contract:\n"
	"\n"
	"        \"Financing Statement\" is this contract.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Or, Contract as well as all contracts can be used as object to terminate.\n"
	"\n"
	"        The Filing Office may, if the Termination Period has passed, terminate this contract.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"CURRENT\n"
	"---------------------------------------\n"
	"adjective\n"
	"time value\n"
	"---------------------------------------\n"
	"Only appears with time.\n"
	"\n"
	"        The Filing Office may fix the Initial Statement Date as the current time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"DATA\n"
	"---------------------------------------\n"
	"noun\n"
	"type\n"
	"---------------------------------------\n"
	"Defines a name as standing for a piece of data.\n"
	"\n"
	"Data can be a text, a number, a hash, a blockchain address, or an id of any type.\n"
	"\n"
	"        \"File Number\" is data.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"DAY, DAYS\n"
	"---------------------------------------\n"
	"noun\n"
	"time unit\n"
	"---------------------------------------\n"
	"Used to describe a duration.\n"
	"\n"
	"A duration can be used to calculate a point in time relative to another point in time. For example, relative to now or in the past, or – as in the example below - relative to a name that means a specific time.\n"
	"\n"
	"        \"Termination Period\" is defined as 365 days after the Termination Statement Time.\n"
	"\n"
	"        (see examples/Cf. hours.)\n"
	"\n"
	"---------------------------------------\n"
	"DECLARE, DECLARES\n"
	"---------------------------------------\n"
	"verb\n"
	"truth assignment operator\n"
	"---------------------------------------\n"
	"Used to state that something has happened, or is true.\n"
	"\n"
	"Technically, declare assigns the truth value, true, to a name. That name must have been defined (see is) as a binary.\n"
	"\n"
	"In the example this means that Default is now true. Note that before that, it was false.\n"
	"\n"
	"Cf. binary.\n"
	"\n"
	"        The Secured Party may declare Default.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"DECLARED\n"
	"---------------------------------------\n"
	"adjective\n"
	"«true»\n"
	"---------------------------------------\n"
	"Synonym to true.\n"
	"\n"
	"In the example, the fact that Default has been declared is the same as saying that it is true that Default happened.\n"
	"\n"
	"        The Filing Office may, if Default is declared, pay the Digital Asset Collateral to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"DEFINED\n"
	"---------------------------------------\n"
	"adjective\n"
	"assignment operator\n"
	"---------------------------------------\n"
	"Always used with IS, or BE and AS, to describe the meaning of the name to its left by means of the expression on its right.\n"
	"\n"
	"The meaning is dynamic. That is, the concrete meaning is not assigned once and for all at any point in time. But instead, whenever the name that is being defined is used elsewhere in any context, the expression right-hand of defined is re-evaluated for its now current result, which is in that moment the meaning of that name.\n"
	"\n"
	"        CLAUSE: Termination Period\n"
	"        \"Termination Period\" is defined as 365 days after the Termination Statement Time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"This type of sentence is the essence of a particular type of CLAUSE whose name can be used like an expression, i.e., the name of such clause can be used like a value in the text of another clause.\n"
	"The example below uses the name Termination Period that is defined in the example above.\n"
	"\n"
	"        The Filing Office may, if the Termination Period has passed, terminate this contract.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"EQUAL\n"
	"---------------------------------------\n"
	"comparison operator\n"
	"equivalence of values\n"
	"---------------------------------------\n"
	"Forms an expression that is true if the values left and right of equal are the same.\n"
	"\n"
	"Near synonym of equaling.\n"
	"\n"
	"        \"Parity\" is defined as the Count of X being equal to the Count of Y.\n"
	"\n"
	"---------------------------------------\n"
	"EQUALING\n"
	"---------------------------------------\n"
	"comparison operator\n"
	"equivalence of values\n"
	"---------------------------------------\n"
	"Forms an expression that is true if the values left and right of equaling are the same.\n"
	"\n"
	"Near synonym of equal.\n"
	"\n"
	"        \"Parity\" is defined as the Left Side equaling the Right Side.\n"
	"\n"
	"---------------------------------------\n"
	"ESCROW\n"
	"---------------------------------------\n"
	"noun\n"
	"system variable\n"
	"---------------------------------------\n"
	"The internal escrow of a digital contract.\n"
	"\n"
	"It is mostly used as object to the predicate pay.\n"
	"\n"
	"Using it with remainder results into a number: the amount left in the escrow at that point in time.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Payee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"FILED\n"
	"---------------------------------------\n"
	"adjective\n"
	"«defined»\n"
	"---------------------------------------\n"
	"Asking whether a name is filed constitutes an expression that is true in case the name had a value assigned to it previously. The expression is false if the name had not been defined before during the lifetime of the contract.\n"
	"\n"
	"        ... the Continuation Statement is filed ...\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"To clarify, it does not matter if there is text somewhere in the contract that gives a name a concrete meaning. What matters is whether for a specific, live contract between concrete parties and with a concrete state, it so happened that it is clear what a specific name stands for, or, that what the name stands for exists.\n"
	"If you take this example ...\n"
	"\n"
	"        The Filing Office may, if the Continuation Statement is filed, fix the Continuation Statement Date.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"... the phrase the Continuation Statement is filed is true, if what is described in the clause shown below ever happened. Concretely, if the Secured Party has filed the Continuation Statement.\n"
	"\n"
	"        Clause: File Continuation.\n"
	"        The Secured Party may file the Continuation Statement.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Note that in this example contract, the Continuation Statement is defined as a binary. That means that it does not have any specific content beyond existing or not. The filing of it 'is' the statement that continuation is desired.\n"
	"\n"
	"---------------------------------------\n"
	"FILE, FILES\n"
	"---------------------------------------\n"
	"verb\n"
	"parameter assignment operator\n"
	"---------------------------------------\n"
	"Synonym to fix.\n"
	"\n"
	"        The Secured Party may file the Continuation Statement.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"FIX, FIXES\n"
	"---------------------------------------\n"
	"verb\n"
	"parameter assignment operator\n"
	"---------------------------------------\n"
	"Indicates that the subject of the sentence will be who determines the meaning of the named objects.\n"
	"\n"
	"Note that this cuts both ways. The subject might itself be determined by the act of fixing the objects: if it had not been settled yet who the name of the subject refers to, then whoever performs the fixing is from that point on named like the subject of this sentence. The name sticks for the remaining lifetime of the contract. Accordingly, in the example below, if the role of the Filer had not been determined, the person who is fixing the Filing Office etc. becomes the Filer. The way to prevent this automatism is to use may.\n"
	"\n"
	"The values that are assigned to the objects of the sentence are given by the subject when that person acts to invoke this clause.\n"
	"\n"
	"        The Filer fixes the Filing Office, fixes the Debtor, fixes the Secured Party, and fixes the Collateral.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Functional synonym to appoint, certify, declare, file, grant, and register.\n"
	"\n"
	"---------------------------------------\n"
	"FIXED\n"
	"---------------------------------------\n"
	"adjective\n"
	"«defined»\n"
	"---------------------------------------\n"
	"Expresses that a name has a value assigned, i.e., is not unbound or undefined. In the example, being tests Notice Time for whether it had been fixed before. Noticed will be true exactly when a Notice Time is known, and false if no value has been given for Notice Time before, at any point during the lifetime of the contract.\n"
	"\n"
	"Functions like CERTIFIED.\n"
	"\n"
	"        \"Noticed\" is defined as a Notice Time being fixed.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"FOR\n"
	"---------------------------------------\n"
	"preposition\n"
	"no op\n"
	"---------------------------------------\n"
	"Only in conjunction with FILE or FILED.\n"
	"\n"
	"The terms FILE FOR or FILED FOR function like FILE or FILED without FOR.\n"
	"\n"
	"---------------------------------------\n"
	"FROM\n"
	"---------------------------------------\n"
	"preposition\n"
	"transfer origin marker\n"
	"---------------------------------------\n"
	"\n"
	"Only in conjunction with ESCROW.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards return the remainder of the escrow to the Payer.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"GENERAL\n"
	"---------------------------------------\n"
	"adjective\n"
	"no op\n"
	"---------------------------------------\n"
	"Optional specification to TERMS.\n"
	"\n"
	"---------------------------------------\n"
	"GIVEN\n"
	"---------------------------------------\n"
	"preposition\n"
	"conditional keyword\n"
	"---------------------------------------\n"
	"Following statements are executed only if the immediately following condition is true.\n"
	"\n"
	"Appears only together with THAT.\n"
	"\n"
	"GIVEN THAT is a synonym to IF.\n"
	"\n"
	"        The Filing Office may, given that the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"---------------------------------------\n"
	"GRANT, GRANTS\n"
	"---------------------------------------\n"
	"verb\n"
	"truth assignment operator\n"
	"---------------------------------------\n"
	"Synonym to fix.\n"
	"\n"
	"        The Licensee may grant the Permission to Comment.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"HAS\n"
	"---------------------------------------\n"
	"auxiliary verb\n"
	"part\n"
	"---------------------------------------\n"
	"Only in conjunction with BEEN or PASSED.\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"HERSELF, HIMSELF\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"Functions like THEMSELF.\n"
	"\n"
	"HOUR, HOURS\n"
	"\n"
	"time unit\n"
	"\n"
	"time constant of 3600 seconds\n"
	"\n"
	"Used to describe a duration.\n"
	"\n"
	"A duration can be used to calculate a point in time relative to another point in time. For example, relative to now or in the past.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"Cf. days.\n"
	"\n"
	"---------------------------------------\n"
	"IF\n"
	"---------------------------------------\n"
	"conjunction\n"
	"assertion\n"
	"---------------------------------------\n"
	"Following statements are executed only of the immediately following condition is true.\n"
	"\n"
	"The condition starts after if and ends with a comma, which can be followed by an optional then.\n"
	"\n"
	"The statements follow after that.\n"
	"\n"
	"In this example ...\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"... the condition is:\n"
	"\n"
	"        the Continuation Window Start has passed\n"
	"\n"
	"... the statements are:\n"
	"\n"
	"        send the Notification Statement to the Secured Party\n"
	"\n"
	"---------------------------------------\n"
	"IN\n"
	"---------------------------------------\n"
	"preposition\n"
	"no op\n"
	"---------------------------------------\n"
	"Only in conjunction with PAST.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"INTO\n"
	"---------------------------------------\n"
	"preposition\n"
	"operator part\n"
	"---------------------------------------\n"
	"Used with NOTIFY, SEND and PAY.\n"
	"\n"
	"        The Secured Party may pay a Reminder Fee into escrow.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"IS\n"
	"---------------------------------------\n"
	"verb\n"
	"assignment and equality operator\n"
	"---------------------------------------\n"
	"Can be used to define of what category a name is; to assign a value to a name; to compare a name to a value; or to check that something is the case.\n"
	"\n"
	"        \"Payer\" is a person.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"\n"
	"        The Filing Office may, if Default is declared, pay the Digital Asset Collateral to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Note that in the following example, License means the (sub)contract itself and is checks the state of the License, diverting into the clause Factually Breached to find out if the License is breached.\n"
	"\n"
	"        The Arbiter may, if this License is Factually Breached:\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"ITSELF\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"Functions like THEMSELF.\n"
	"\n"
	"---------------------------------------\n"
	"LEAST\n"
	"---------------------------------------\n"
	"adjective\n"
	"time operator part\n"
	"---------------------------------------\n"
	"Only in conjunction with AT.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"LEX\n"
	"---------------------------------------\n"
	"noun\n"
	"keyword\n"
	"---------------------------------------\n"
	"Keyword for the start of a digital contract.\n"
	"\n"
	"LEX must be the first word of a digital contract. The words after LEX are the name of the entire digital contract (system) described thereafter.\n"
	"\n"
	"As a convention, LEX is usually spelled in uppercase.\n"
	"\n"
	"        LEX Escrow.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"LEXON\n"
	"---------------------------------------\n"
	"noun\n"
	"keyword\n"
	"---------------------------------------\n"
	"The numbers following LEXON are the version number of the Lexon compiler that the digital contract was written for. This is a concept that helps while Lexon is evolving. As a rule, newer compilers can compile older version Lexon texts but there will sometimes be 'breaking changes' where this backward compatibility is not provided and older texts have to be adapted to the changes of a new grammar.\n"
	"\n"
	"Note that compatibility is not a dimension of what the texts mean in human language, which remains the same throughout Lexon versions, because English does not change. Instead, this is about older versions of the compiler understanding less than newer ones, i.e., the grammar getting less restricted.\n"
	"\n"
	"As a convention, LEXON is usually spelled in uppercase.\n"
	"\n"
	"        LEXON: 0.2.12\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"LIES\n"
	"---------------------------------------\n"
	"verb\n"
	"time comparison operator\n"
	"---------------------------------------\n"
	"Only in conjunction with AT LEAST.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"MAY\n"
	"---------------------------------------\n"
	"auxilliary verb\n"
	"permission marker\n"
	"---------------------------------------\n"
	"The subject to MAY is/are the only party or parties to the contract that are auhtorized to initiate the action described. The subject must be bound, i.e., the name before MAY must have been defined before, it cannot be defined in the may statement. Note that statements without may might likewise restrict authority to the named subject. And it is possible that the subject is unbound in cases without MAY, i.e., the role not defined at that point.\n"
	"\n"
	"        The Filing Office may certify the File Number.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"MILLISECOND, MILLISECONDS\n"
	"---------------------------------------\n"
	"noun\n"
	"time constant of 1/1000 seconds.\n"
	"---------------------------------------\n"
	"Functions like DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"MINUTE, MINUTES\n"
	"---------------------------------------\n"
	"noun\n"
	"time constant of 60 seconds\n"
	"---------------------------------------\n"
	"Functions like DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"MONTH, MONTHS\n"
	"---------------------------------------\n"
	"noun\n"
	"Time constant of 2592000 seconds, i.e., 30 DAYS\n"
	"---------------------------------------\n"
	"Functions like DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"MYSELF\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"Functions like THEMSELF.\n"
	"\n"
	"---------------------------------------\n"
	"NO\n"
	"---------------------------------------\n"
	"adverb\n"
	"logic operator\n"
	"---------------------------------------\n"
	"Logical inversion. In conjunction with there is, also used to test whether a name has been assign any concrete meaning yet. See fixed.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"NOT\n"
	"---------------------------------------\n"
	"adverb\n"
	"logic operator\n"
	"---------------------------------------\n"
	"Logical inversion.\n"
	"\n"
	"Used to form the opposite of a logical expression. Can be positioned before a name, or before fixed. The resulting expression means the opposite of what the part after not meant. It can be part of a bigger logical expression, as shown below. Not, as is grammatically correct, binds the next noun or verb only. The requirements for sentence structure make sure that no ambiguity can arise for the human reader.\n"
	"\n"
	"If a more complex expression must be inverted, it has to be written as a clause. This simple device to avoid ambiguity without requiring literal bracketing is borrowed from proven best practice in Functional Programming.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"NOW\n"
	"---------------------------------------\n"
	"noun\n"
	"time value\n"
	"---------------------------------------\n"
	"Synonym to CURRENT TIME.\n"
	"\n"
	"        The Filing Office may fix the Initial Statement Date as now.\n"
	"\n"
	"---------------------------------------\n"
	"OF\n"
	"---------------------------------------\n"
	"preposition\n"
	"no op\n"
	"---------------------------------------\n"
	"Only with REMAINDER.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Payee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"OFF\n"
	"---------------------------------------\n"
	"adverb\n"
	"operator part\n"
	"---------------------------------------\n"
	"Only with SIGNED.\n"
	"\n"
	"---------------------------------------\n"
	"ON\n"
	"---------------------------------------\n"
	"preposition\n"
	"operator part\n"
	"---------------------------------------\n"
	"Only with SIGNED.\n"
	"\n"
	"---------------------------------------\n"
	"ONESELF\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"Functions like THEMSELF.\n"
	"\n"
	"---------------------------------------\n"
	"OR\n"
	"---------------------------------------\n"
	"conjunction\n"
	"logic operator\n"
	"---------------------------------------\n"
	"Used to build logical expressions. A phrase that contains or is true if the part left or the part right of the or are true.\n"
	"\n"
	"Colons, commas and semicolons are relevant to separate sub-phrases. Programmers note that there is no precedence of and over or in Lexon as this is not a part of natural language. Commas and semicolons offer two levels of nesting. Beyong this, precedence is created by encapsulating logical expressions into separate clauses.\n"
	"\n"
	"In the example ...\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"... all of the following counts as the left-side of the or, because there is a comma before the or and no comma to the left of it:\n"
	"\n"
	"        this License is Commissioned and the Comment Text is not fixed\n"
	"\n"
	"... and all of the following is the right side of the or, because there is a comma before the or and no comma to the right of it:\n"
	"\n"
	"        this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"---------------------------------------\n"
	"OURSELVES\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"Functions like THEMSELF.\n"
	"\n"
	"---------------------------------------\n"
	"PASSED\n"
	"---------------------------------------\n"
	"adjective\n"
	"time comparison operator\n"
	"---------------------------------------\n"
	"Compares a point in time to the current time.\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"For more on how to use time, see hours and days.\n"
	"\n"
	"---------------------------------------\n"
	"PAST\n"
	"---------------------------------------\n"
	"noun or adjective\n"
	"negative time sign\n"
	"---------------------------------------\n"
	"Past indicates that a measure of time is to be subtracted from the current time, or it functions like HAS PASSED.\n"
	"\n"
	"In the example, in the past functions as a negative sign to the literal 24 hours, relative to now.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"For more on how to use time, see hours and days.\n"
	"\n"
	"---------------------------------------\n"
	"PAY, PAYS\n"
	"---------------------------------------\n"
	"verb\n"
	"transfer operator\n"
	"---------------------------------------\n"
	"A transfer over the amount given immediately following pay, from the subject of the sentence, to the object marked with to or into.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"PER\n"
	"---------------------------------------\n"
	"preposition\n"
	"keyword\n"
	"---------------------------------------\n"
	"PER marks the beginning of the TERMS of a covenant or sub-contract.\n"
	"\n"
	"Digital contracts are often really contract systems that control the creation of individual contracts each with different counter parties. These sub contracts are called covenants in the context of digital contracts. Their terms are separated from the general terms of the digital contracts – which govern everything else, specifically how the covenants come into existence – by the keyword PER, followed by the name the of the covenant, and optionally preceded by the keyword TERMS.\n"
	"\n"
	"As a convention, PER is usually spelled in uppercase.\n"
	"\n"
	"        TERMS PER License:\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"PERSON\n"
	"---------------------------------------\n"
	"noun\n"
	"type\n"
	"---------------------------------------\n"
	"Defines a name to stand for a person.\n"
	"\n"
	"        \"Payer\" is a person.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"PREAMBLE\n"
	"---------------------------------------\n"
	"noun\n"
	"keyword\n"
	"---------------------------------------\n"
	"Start of a comment from both legal and processing point of view. Words after PREAMBLE are explanations with minimal legal weight and are not translated to 3rd generation language code by the compiler. Accordingly, in the example below, no word behind the colon is interpreted. This is not a special case: it is similar to how Lexon does not account for the common meaning of nouns in human language that a writer defines. This meaning is helpful to understand the contract, but not part of it, like the preamble text. Likewise, it is a common pitfall to read the preamble in a paper contract as part of the legal agreement; it is not. Its value lies in paraphrasing the more technical prose of the agreement in more accessible but blurier terms and to provide context.\n"
	"\n"
	"As a convention, PREAMBLE is usually spelled in uppercase.\n"
	"\n"
	"        PREAMBLE: This is a licensing contract for a software evaluation.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"PROVIDED\n"
	"---------------------------------------\n"
	"adjective\n"
	"conditional keyword\n"
	"---------------------------------------\n"
	"Synonym to IF.\n"
	"\n"
	"        The Filing Office may, provided the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"---------------------------------------\n"
	"REGISTER, REGISTERS\n"
	"---------------------------------------\n"
	"verb\n"
	"parameter assignment operator\n"
	"---------------------------------------\n"
	"Synonym to fix.\n"
	"\n"
	"        The Licensee may register a Comment Text.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"REMAINDER\n"
	"---------------------------------------\n"
	"noun\n"
	"no op\n"
	"---------------------------------------\n"
	"Optional part to internal variable ESCROW.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Payee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"RESPECTIVE\n"
	"---------------------------------------\n"
	"adjective\n"
	"optional part of built-in time value\n"
	"---------------------------------------\n"
	"Only in conjunction with CURRENT TIME.\n"
	"\n"
	"        The Secured Party may certify the Termination Statement Time as the respective current time.\n"
	"\n"
	"---------------------------------------\n"
	"RETURN, RETURNS\n"
	"---------------------------------------\n"
	"verb\n"
	"transfer operator\n"
	"---------------------------------------\n"
	"Synonym to PAY.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards return the remainder of the escrow to the Payer.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"SECOND, SECONDS\n"
	"---------------------------------------\n"
	"noun\n"
	"time constant of 1 second\n"
	"---------------------------------------\n"
	"Functions like DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"SEND, SENDS\n"
	"---------------------------------------\n"
	"verb\n"
	"transfer and messaging operator\n"
	"---------------------------------------\n"
	"Send a message. On the blockchain, this can be an entry on the receipt log.\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"SIGNED\n"
	"---------------------------------------\n"
	"adjective\n"
	"logical true\n"
	"---------------------------------------\n"
	"Only in the combination SIGNED OFF, with optional following ON.\n"
	"\n"
	"In other words, signed, signed off, and signed off on all mean the same.\n"
	"\n"
	"        The Agent may, once the Receipt is signed off, return the Collateral to the Counterparty.\n"
	"\n"
	"---------------------------------------\n"
	"SO\n"
	"---------------------------------------\n"
	"adjective\n"
	"causal concatenator part\n"
	"---------------------------------------\n"
	"Only in conjunction with IF.\n"
	"\n"
	"IF SO is a synonym for AFTERWARDS. See remarks on sentence order there.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and if so return the remainder of the escrow to the Payer.\n"
	"\n"
	"---------------------------------------\n"
	"TERMINATE, TERMINATES\n"
	"---------------------------------------\n"
	"verb\n"
	"destruction operator\n"
	"---------------------------------------\n"
	"The consequence of termination is that a contract's state cannot be changed anymore. Both main contracts and covenants (subcontracts) can be terminated. It is good practice to end a contract after its purpose is fulfilled so that it cannot be partially restarted for unintended consequences.\n"
	"\n"
	"        The Filing Office may, if the Termination Period has passed, terminate this contract.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"TERMS\n"
	"---------------------------------------\n"
	"noun\n"
	"optional keyword\n"
	"---------------------------------------\n"
	"Optional marker of the beginning of general or per-subcontract terms. The TERMS keyword serves to increase clarity but can be left out as the document order suffices for the compiler to understand what part of a document to expect next: terms are neccessarily all statements following the LEX keyword and digital contract (system) name. For yet more clarity, TERMS can be preceded by the optional keyword GENERAL.\n"
	"\n"
	"For covenants (sub contracts), their terms must be marked at least by the keyword PER, followed by the covenant's name. TERMS may precede PER but is optional.\n"
	"\n"
	"As a convention, TERMS is usually spelled in uppercase.\n"
	"\n"
	"        TERMS:\n"
	"        ...\n"
	"        TERMS PER License:\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"TEXT\n"
	"---------------------------------------\n"
	"noun\n"
	"type\n"
	"---------------------------------------\n"
	"Defines that a name is standing for a text.\n"
	"\n"
	"        \"Notification Statement\" is a text.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"THAT\n"
	"---------------------------------------\n"
	"conjunction\n"
	"conditional keyword\n"
	"---------------------------------------\n"
	"Following statements are executed only of the immediately following condition is true.\n"
	"\n"
	"Appears only together with GIVEN.\n"
	"\n"
	"GIVEN THAT is a synonym to IF.\n"
	"\n"
	"        The Filing Office may, given that the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"---------------------------------------\n"
	"THE\n"
	"---------------------------------------\n"
	"article\n"
	"no op\n"
	"---------------------------------------\n"
	"Articles are optional to increase readability, because the name they precede must always be unambigous on its own.\n"
	"\n"
	"        The Payer pays an Amount into escrow, appoints the Payee, appoints the Arbiter, and fixes the Fee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"Cf. A.\n"
	"---------------------------------------\n"
	"THEMSELF, THEMSELVES\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"In this example, themselves means the Arbiter.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Payee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"---------------------------------------\n"
	"THEN\n"
	"---------------------------------------\n"
	"adverb, adjective\n"
	"conditional keyword, causal conccatenator\n"
	"---------------------------------------\n"
	"In conjunction with CURRENT TIME:\n"
	"\n"
	"        The Secured Party may file a Termination Statement, and certify the Termination Statement Time as the then current time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Also functions like THEREFOR:\n"
	"\n"
	"        This License is then Paid.\n"
	"\n"
	"---------------------------------------\n"
	"THERE\n"
	"---------------------------------------\n"
	"adverb\n"
	"existence test\n"
	"---------------------------------------\n"
	"Used to reason about the existence of something, ore more precisely, about whether a name has a defined meaning or not.\n"
	"\n"
	"Appears only in THERE IS or THERE IS NOT, or with variations of IS, like BE.\n"
	"\n"
	"Cf. fixed.\n"
	"\n"
	"        \"Factually Breached\" is defined as: this License is Commissioned and the Comment Text is not fixed, or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"THEREFOR, THEREFORE\n"
	"---------------------------------------\n"
	"adverb\n"
	"causal concatenator\n"
	"---------------------------------------\n"
	"THEREFORE binds a sentence to the preceding ones, so that it is performed only if all preceding sentences were performed, i.e., did not disqualify for access or conditional reasons.\n"
	"\n"
	"Without THEREFORE, a sentence by itself is always materialized when a clause is triggered.\n"
	"\n"
	"Cf. afterwards.\n"
	"\n"
	"        The Licensee pays the Licensing Fee to the Licensor, and pays the Breach Fee into escrow. This License is therefore Paid.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"THESE\n"
	"---------------------------------------\n"
	"adjective\n"
	"no op\n"
	"---------------------------------------\n"
	"These can be required to get the natural language grammar right but does not change meaning by its presence or absence because the name that it precedes must always be unambiguous by itself.\n"
	"\n"
	"        The Licensor may certify these Agreements as Commissioned.\n"
	"\n"
	"---------------------------------------\n"
	"THIS\n"
	"---------------------------------------\n"
	"adjective\n"
	"no op\n"
	"---------------------------------------\n"
	"THIS can be required to get the natural language grammar right but does not change meaning by its presence or absence because the name that it precedes must always be unambiguous by itself.\n"
	"\n"
	"        The Licensor may certify this License as Commissioned.\n"
	"\n"
	"        (see examples/evaluation.lex)\n"
	"\n"
	"---------------------------------------\n"
	"TIME\n"
	"---------------------------------------\n"
	"noun\n"
	"type\n"
	"---------------------------------------\n"
	"Either defines a name as standing for a time value.\n"
	"\n"
	"        \"Initial Statement Date\" is a time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Or, specifies the current point in time.\n"
	"\n"
	"        The Filing Office may fix the Initial Statement Date as the current time.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"TO\n"
	"---------------------------------------\n"
	"preposition\n"
	"transfer operator part\n"
	"---------------------------------------\n"
	"Appears in conjunction with PAY, SEND, be or equal.\n"
	"\n"
	"        The Arbiter may pay from escrow the Fee to themselves, and afterwards pay the remainder of the escrow to the Payee.\n"
	"\n"
	"        (see examples/escrow.lex)\n"
	"\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"---------------------------------------\n"
	"TRUE\n"
	"---------------------------------------\n"
	"adjective\n"
	"logical true\n"
	"---------------------------------------\n"
	"A value that a name or an expression can have, meaning that something is the case.\n"
	"\n"
	"Synonymous with YES.\n"
	"\n"
	"In the following example, the expression the Continuation Window has passed can be TRUE or FALSE.\n"
	"\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        (see examples/statement.lex)\n"
	"\n"
	"Cf. FIXED.\n"
	"\n"
	"---------------------------------------\n"
	"WAS\n"
	"---------------------------------------\n"
	"verb\n"
	"logic equivalence operator\n"
	"---------------------------------------\n"
	"Functions like IS.\n"
	"\n"
	"---------------------------------------\n"
	"WEEK, WEEKS\n"
	"---------------------------------------\n"
	"noun\n"
	"time factor constant\n"
	"---------------------------------------\n"
	"Time constant of 604,800 seconds, i.e., 7 DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"WITH\n"
	"---------------------------------------\n"
	"conjunction\n"
	"causal concatenator\n"
	"---------------------------------------\n"
	"Only appears as AND WITH THIS.\n"
	"\n"
	"---------------------------------------\n"
	"YEAR, YEARS\n"
	"---------------------------------------\n"
	"noun\n"
	"time factor constant\n"
	"---------------------------------------\n"
	"Time constant of 31,536,000 seconds, i.e., 365 DAYS.\n"
	"\n"
	"---------------------------------------\n"
	"YES\n"
	"---------------------------------------\n"
	"noun\n"
	"logical true\n"
	"---------------------------------------\n"
	"A value that a name or an expression can have, meaning that something is the case.\n"
	"\n"
	"---------------------------------------\n"
	"YOURSELF, YOURSELVES\n"
	"---------------------------------------\n"
	"reflexive pronoun\n"
	"automatic reference\n"
	"---------------------------------------\n"
	"Refers to the subject of the sentence.\n"
	"\n"
	"\n"
	"\n"
	"********************************************************************************\n"
	"EXAMPLES\n"
	"********************************************************************************\n"
	"\n"
	"\n"
	"LEXON FOR LAW\n"
	"\n"
	"Lexon allows for law to be executed as a program. Asst. prof. Carla L. Reyes of SMU pioneers the use of Lexon to write statute – shown below – in her seminal 2021 paper Creating Cryptolaw for the Uniform Commercial Code.18 She created the following Lexon code as a proposal to the commission that is tasked with the reform of the U.S. trade law, which she advised on blockchain topics. This code could become model law, be adapted by states to be executed on the computers of their local agencies and protect billions of dollars of collateral.\n"
	"\n"
	"    The salient point is that the law itself, without further changes is the program that the respective office runs to implement the law. The productivity gains of Lexon could not be illustrated better.\n"
	"    \n"
	"The motivation for this proposal is a concrete shortfall of the existing statute. Asst. prof. Reyes writes (emphasis added):\n"
	"\n"
	"    “Under certain conditions, security interests not only bind the creditor and debtor, but also third-party creditors seeking to lend against the same collateral. To receive this extraordinary benefit, creditors must put the world on notice, usually by filing a financing statement with the state in which the debtor is located. Unfortunately, the Uniform Commercial Code (U.C.C.) Article 9 filing system fails to provide actual notice to interested parties and introduces risk of heavy financial losses. To solve this problem, this Article introduces a smart-contract-based U.C.C.-1 form built using Lexon, an innovative new programming language that enables the development of smart contracts in English. The proposed “Lexon U.C.C. Financing Statement” does much more than merely replicate the financing statement in digital form; it also performs several U.C.C. rules so that, for the first time, the filing system works as intended. In demonstrating that such a system remains compatible with existing law, the Lexon U.C.C. Financing Statement also reveals important lessons about the interaction of technology and commercial law.” ibid. 15\n"
	"\n"
	"\n"
	"        LEX UCC Financing Statement.\n"
	"\n"
	"        LEXON: 0.2.12\n"
	"\n"
	"        \"Financing Statement\" is this contract. \n"
	"        \"File Number\" is data.\n"
	"        \"Initial Statement Date\" is a time.\n"
	"        \"Filer\" is a person. \n"
	"        \"Debtor\" is a person.\n"
	"        \"Secured Party\" is a person.\n"
	"        \"Filing Office\" is a person.\n"
	"        \"Collateral\" is data.\n"
	"        \"Digital Asset Collateral\" is an amount.\n"
	"        \"Reminder Fee\" is an amount.\n"
	"        \"Continuation Window Start\" is a time.\n"
	"        \"Continuation Statement Date\" is a time.\n"
	"        \"Continuation Statement Filing Number\" is data.\n"
	"        \"Lapse Date\" is a time.\n"
	"        \"Default\" is a binary.\n"
	"        \"Continuation Statement\" is a binary.\n"
	"        \"Termination Statement\" is a binary.\n"
	"        \"Termination Statement Time\" is a time.\n"
	"        \"Notification Statement\" is a text. \n"
	"\n"
	"        The Filer fixes the Filing Office, fixes the Debtor, fixes the Secured Party, and fixes the Collateral.\n"
	"\n"
	"        Clause: Certify.\n"
	"        The Filing Office may certify the File Number.\n"
	"\n"
	"        Clause: Set File Date.\n"
	"        The Filing Office may fix the Initial Statement Date as the current time. \n"
	"\n"
	"        Clause: Set Lapse.\n"
	"        The Filing Office may fix the Lapse Date.\n"
	"\n"
	"        Clause: Set Continuation Start.\n"
	"        The Filing Office may fix the Continuation Window Start.\n"
	"\n"
	"        Clause: Pay Fee.\n"
	"        The Secured Party may pay a Reminder Fee into escrow. \n"
	"\n"
	"        Clause: Notice.\n"
	"        The Filing Office may fix the Notification Statement.\n"
	"\n"
	"        Clause: Notify.\n"
	"        The Filing Office may, if the Continuation Window Start has passed, send the Notification Statement to the Secured Party.\n"
	"\n"
	"        Clause: Pay Escrow In.\n"
	"        The Debtor may pay the Digital Asset Collateral into escrow.\n"
	"\n"
	"        Clause: Fail to Pay.\n"
	"        The Secured Party may declare Default.\n"
	"\n"
	"        Clause: Take Possession.\n"
	"        The Filing Office may, if Default is declared, pay the Digital Asset Collateral to the Secured Party.\n"
	"\n"
	"        Clause: File Continuation.\n"
	"        The Secured Party may file the Continuation Statement.\n"
	"\n"
	"        Clause: Set Continuation Lapse.\n"
	"        The Filing Office may, if the Continuation Statement is filed, fix the Continuation Statement Date.\n"
	"\n"
	"        Clause: File Termination.\n"
	"        The Secured Party may file a Termination Statement, and certify the Termination Statement Time as the then current time.\n"
	"\n"
	"        Clause: Release Escrow.\n"
	"        The Filing Office may, if the Termination Statement is filed, return the Digital Asset Collateral to the Debtor.\n"
	"\n"
	"        Clause: Release Reminder Fee.\n"
	"        The Filing Office may, if the Termination Statement is filed, return the Reminder Fee to the Secured Party.\n"
	"\n"
	"        Clause: Termination Period.\n"
	"        \"Termination Period\" is defined as 365 days after the Termination Statement Time.\n"
	"\n"
	"        Clause: Terminate and Clear.\n"
	"        The Filing Office may, if the Termination Period has passed, terminate this contract.\n"
	"        Source 3 – Lexon code example: U.C.C. Filing Statement\n"
	"\n"
	"\n"
	"\n"
	"EVALUATION LICENSE SYSTEM.\n"
	"\n"
	"This digital contract was created by F. Idelberger, Phd candidate at the European University Institute in Florence. It appears in Merging traditional contracts (or law) and (smart) e-contracts – a novel approach, comparing this text to smart contracts written in other languages.\n"
	"Idelberger’s paper about the contract is available at\n"
	"https://lawgorithm.com.br/wp-content/uploads/2020/09/MLR2020-Florian-Idelberger.pdf. \n"
	"\n"
	"        LEX: Evaluation License System.\n"
	"\n"
	"        LEXON: 0.2.1\n"
	"\n"
	"        AUTHORS: FLORIAN IDELBERGER, HENNING DIEDRICH\n"
	"\n"
	"        PREAMBLE: This is a licensing contract for a software evaluation.\n"
	"\n"
	"        TERMS:\n"
	"\n"
	"        \"Licensor\" is a person.\n"
	"        \"Arbiter\" is a person.\n"
	"        \"Licensing Fee\" is an amount.\n"
	"        \"Breach Fee\" is an amount.\n"
	"\n"
	"        The Licensor appoints the Arbiter,\n"
	"        fixes the Licensing Fee,\n"
	"        and fixes the Breach Fee.\n"
	"\n"
	"        TERMS PER License:\n"
	"\n"
	"        \"Description of Goods\" is a text.\n"
	"        \"Licensee\" is a person.\n"
	"        \"Paid\" is a binary.\n"
	"        \"Commissioned\" is a binary.\n"
	"        \"Comment Text\" is a text.\n"
	"        \"Published\" is a binary.\n"
	"        \"Permission to Comment\" is a binary.\n"
	"        \"Notice Time\" is a time.\n"
	"        \"License\" is this contract.\n"
	"\n"
	"        The Licensor appoints the Licensee, and fixes the Description of Goods.\n"
	"\n"
	"        CLAUSE: Pay.\n"
	"        The Licensee pays the Licensing Fee to the Licensor,\n"
	"        and pays the Breach Fee into escrow.\n"
	"        This License is therefore Paid.\n"
	"\n"
	"        CLAUSE: Commission.\n"
	"        The Licensor may certify this License as Commissioned.\n"
	"\n"
	"        CLAUSE: Comment.\n"
	"        The Licensee may register a Comment Text.\n"
	"\n"
	"        CLAUSE: Publication.\n"
	"        The Licensee may certify this License as Published.\n"
	"\n"
	"        CLAUSE: Grant Permission to Comment.\n"
	"        The Licensee may grant the Permission to Comment.\n"
	"\n"
	"        CLAUSE: Declare Breach.\n"
	"        The Arbiter may, if this License is Factually Breached:\n"
	"        pay the Breach Fee to the Licensor,\n"
	"        and afterwards terminate this License.\n"
	"\n"
	"        CLAUSE: Factually Breached.\n"
	"        \"Factually Breached\" is defined as:\n"
	"        this License is Commissioned and the Comment Text is not fixed,\n"
	"        or this License is Published and there is no Permission to Comment and the Notice Time lies at least 24 hours in the past.\n"
	"\n"
	"        CLAUSE: Notice.\n"
	"        The Licensor or the Arbiter may fix the Notice Time as the respective current time.\n"
	"\n"
	"        CLAUSE: Noticed.\n"
	"        \"Noticed\" is defined as a Notice Time being fixed.\n"
	"\n"
	"\n"
	"\n"
	"INTERNAL MODEL\n"
	"\n"
	"The following is a part of the abstract syntax tree (AST), the internal model the compiler creates when processing the grammar and text discussed in chapter Grammar, pg. 54. It reflects natural language grammar rather than programming logic. Such a tree can be created from any Lexon text using the tree options.\n"
	"\n"
	"    \n"
	"            ↳  statements \n"
	"                ↳  statement \n"
	"                    ↳  action \n"
	"                        ↳  subject \n"
	"                        ⎸   ↳  symbols \n"
	"                        ⎸       ↳  symbol «payer» \n"
	"                        ⎸           ↳  article    \n"
	"                        ↳  predicates \n"
	"                            ↳  predicate \n"
	"                            ⎸   ↳  payment \n"
	"                            ⎸       ↳  pay \n"
	"                            ⎸       ⎸ \n"
	"                            ⎸       ↳  expression \n"
	"                            ⎸       ⎸   ↳  combination \n"
	"                            ⎸       ⎸       ↳  combinor \n"
	"                            ⎸       ⎸           ↳  combinand \n"
	"                            ⎸       ⎸               ↳  symbol «amount» \n"
	"                            ⎸       ⎸                   ↳  article      \n"
	"                            ⎸       ⎸ \n"
	"                            ⎸       ↳  preposition \n"
	"                            ⎸       ⎸ \n"
	"                            ⎸       ↳  object     \n"
	"                            ⎸ \n"
	"                            ↳  predicate \n"
	"                            ⎸   ↳  appointment \n"
	"                            ⎸       ↳  appoint \n"
	"                            ⎸       ⎸ \n"
	"                            ⎸       ↳  symbol «payee» \n"
	"                            ⎸           ↳  article    \n"
	"                            ⎸ \n"
	"                            ↳  predicate \n"
	"                            ⎸   ↳  appointment \n"
	"                            ⎸       ↳  appoint \n"
	"                            ⎸       ⎸ \n"
	"                            ⎸       ↳  symbol «arbiter» \n"
	"                            ⎸           ↳  article    \n"
	"                            ↳  predicate \n"
	"                                ↳  fixture \n"
	"                                    ↳  fix \n"
	"                                    ↳  symbol «fee» \n"
	"                                        ↳  article\n"
	"\n"
	"To create such a tree for your own Lexon text, check out the --tree option.\n"
	"\n"
	"There are fine-grained options for highlighting specific elements of the tree: color, highlight etc.\n"
	"    \n"
	"© 2025 Henning Diedrich\n"
	"\n"
	"\n"
	"LICENSE\n"
	"\n"
	"        Copyright (C) 2016-25 Henning Diedrich, licensed under AGPL3 in\n"
	"        jurisidictions that allow for the following warranty exclusion.\n"
	"\n"
	"        hd@lexon.org\n"
	"\n"
	"        You can redistribute this program and/or modify it under the terms of\n"
	"        the GNU Affero General Public License as published by the Free Software\n"
	"        Foundation, either version 3 of the License (given below), or (at your\n"
	"        option) any later version, if the following exclusion of warranties\n"
	"        can be fully effective in the jurisdiction that would apply:\n"
	"\n"
	"        This program is distributed WITHOUT ANY WARRANTY; without even the\n"
	"        implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
	"        See the GNU Affero General Public License (below) for more details.\n"
	"\n"
	"        If the jurisdiction that would apply does not allow for this exclusion\n"
	"        of warranties to be effective, the program is not licensed to you. This\n"
	"        condition might be relaxed with future versions of the software.\n"
	"\n"
	"\n"
	"\n"
	"                         GNU AFFERO GENERAL PUBLIC LICENSE\n"
	"                            Version 3, 19 November 2007\n"
	"\n"
	"         Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>\n"
	"         Everyone is permitted to copy and distribute verbatim copies\n"
	"         of this license document, but changing it is not allowed.\n"
	"\n"
	"                                    Preamble\n"
	"\n"
	"          The GNU Affero General Public License is a free, copyleft license for\n"
	"        software and other kinds of works, specifically designed to ensure\n"
	"        cooperation with the community in the case of network server software.\n"
	"\n"
	"          The licenses for most software and other practical works are designed\n"
	"        to take away your freedom to share and change the works.  By contrast,\n"
	"        our General Public Licenses are intended to guarantee your freedom to\n"
	"        share and change all versions of a program--to make sure it remains free\n"
	"        software for all its users.\n"
	"\n"
	"          When we speak of free software, we are referring to freedom, not\n"
	"        price.  Our General Public Licenses are designed to make sure that you\n"
	"        have the freedom to distribute copies of free software (and charge for\n"
	"        them if you wish), that you receive source code or can get it if you\n"
	"        want it, that you can change the software or use pieces of it in new\n"
	"        free programs, and that you know you can do these things.\n"
	"\n"
	"          Developers that use our General Public Licenses protect your rights\n"
	"        with two steps: (1) assert copyright on the software, and (2) offer\n"
	"        you this License which gives you legal permission to copy, distribute\n"
	"        and/or modify the software.\n"
	"\n"
	"          A secondary benefit of defending all users' freedom is that\n"
	"        improvements made in alternate versions of the program, if they\n"
	"        receive widespread use, become available for other developers to\n"
	"        incorporate.  Many developers of free software are heartened and\n"
	"        encouraged by the resulting cooperation.  However, in the case of\n"
	"        software used on network servers, this result may fail to come about.\n"
	"        The GNU General Public License permits making a modified version and\n"
	"        letting the public access it on a server without ever releasing its\n"
	"        source code to the public.\n"
	"\n"
	"          The GNU Affero General Public License is designed specifically to\n"
	"        ensure that, in such cases, the modified source code becomes available\n"
	"        to the community.  It requires the operator of a network server to\n"
	"        provide the source code of the modified version running there to the\n"
	"        users of that server.  Therefore, public use of a modified version, on\n"
	"        a publicly accessible server, gives the public access to the source\n"
	"        code of the modified version.\n"
	"\n"
	"          An older license, called the Affero General Public License and\n"
	"        published by Affero, was designed to accomplish similar goals.  This is\n"
	"        a different license, not a version of the Affero GPL, but Affero has\n"
	"        released a new version of the Affero GPL which permits relicensing under\n"
	"        this license.\n"
	"\n"
	"          The precise terms and conditions for copying, distribution and\n"
	"        modification follow.\n"
	"\n"
	"                               TERMS AND CONDITIONS\n"
	"\n"
	"          0. Definitions.\n"
	"\n"
	"          \"This License\" refers to version 3 of the GNU Affero General Public License.\n"
	"\n"
	"          \"Copyright\" also means copyright-like laws that apply to other kinds of\n"
	"        works, such as semiconductor masks.\n"
	"\n"
	"          \"The Program\" refers to any copyrightable work licensed under this\n"
	"        License.  Each licensee is addressed as \"you\".  \"Licensees\" and\n"
	"        \"recipients\" may be individuals or organizations.\n"
	"\n"
	"          To \"modify\" a work means to copy from or adapt all or part of the work\n"
	"        in a fashion requiring copyright permission, other than the making of an\n"
	"        exact copy.  The resulting work is called a \"modified version\" of the\n"
	"        earlier work or a work \"based on\" the earlier work.\n"
	"\n"
	"          A \"covered work\" means either the unmodified Program or a work based\n"
	"        on the Program.\n"
	"\n"
	"          To \"propagate\" a work means to do anything with it that, without\n"
	"        permission, would make you directly or secondarily liable for\n"
	"        infringement under applicable copyright law, except executing it on a\n"
	"        computer or modifying a private copy.  Propagation includes copying,\n"
	"        distribution (with or without modification), making available to the\n"
	"        public, and in some countries other activities as well.\n"
	"\n"
	"          To \"convey\" a work means any kind of propagation that enables other\n"
	"        parties to make or receive copies.  Mere interaction with a user through\n"
	"        a computer network, with no transfer of a copy, is not conveying.\n"
	"\n"
	"          An interactive user interface displays \"Appropriate Legal Notices\"\n"
	"        to the extent that it includes a convenient and prominently visible\n"
	"        feature that (1) displays an appropriate copyright notice, and (2)\n"
	"        tells the user that there is no warranty for the work (except to the\n"
	"        extent that warranties are provided), that licensees may convey the\n"
	"        work under this License, and how to view a copy of this License.  If\n"
	"        the interface presents a list of user commands or options, such as a\n"
	"        menu, a prominent item in the list meets this criterion.\n"
	"\n"
	"          1. Source Code.\n"
	"\n"
	"          The \"source code\" for a work means the preferred form of the work\n"
	"        for making modifications to it.  \"Object code\" means any non-source\n"
	"        form of a work.\n"
	"\n"
	"          A \"Standard Interface\" means an interface that either is an official\n"
	"        standard defined by a recognized standards body, or, in the case of\n"
	"        interfaces specified for a particular programming language, one that\n"
	"        is widely used among developers working in that language.\n"
	"\n"
	"          The \"System Libraries\" of an executable work include anything, other\n"
	"        than the work as a whole, that (a) is included in the normal form of\n"
	"        packaging a Major Component, but which is not part of that Major\n"
	"        Component, and (b) serves only to enable use of the work with that\n"
	"        Major Component, or to implement a Standard Interface for which an\n"
	"        implementation is available to the public in source code form.  A\n"
	"        \"Major Component\", in this context, means a major essential component\n"
	"        (kernel, window system, and so on) of the specific operating system\n"
	"        (if any) on which the executable work runs, or a compiler used to\n"
	"        produce the work, or an object code interpreter used to run it.\n"
	"\n"
	"          The \"Corresponding Source\" for a work in object code form means all\n"
	"        the source code needed to generate, install, and (for an executable\n"
	"        work) run the object code and to modify the work, including scripts to\n"
	"        control those activities.  However, it does not include the work's\n"
	"        System Libraries, or general-purpose tools or generally available free\n"
	"        programs which are used unmodified in performing those activities but\n"
	"        which are not part of the work.  For example, Corresponding Source\n"
	"        includes interface definition files associated with source files for\n"
	"        the work, and the source code for shared libraries and dynamically\n"
	"        linked subprograms that the work is specifically designed to require,\n"
	"        such as by intimate data communication or control flow between those\n"
	"        subprograms and other parts of the work.\n"
	"\n"
	"          The Corresponding Source need not include anything that users\n"
	"        can regenerate automatically from other parts of the Corresponding\n"
	"        Source.\n"
	"\n"
	"          The Corresponding Source for a work in source code form is that\n"
	"        same work.\n"
	"\n"
	"          2. Basic Permissions.\n"
	"\n"
	"          All rights granted under this License are granted for the term of\n"
	"        copyright on the Program, and are irrevocable provided the stated\n"
	"        conditions are met.  This License explicitly affirms your unlimited\n"
	"        permission to run the unmodified Program.  The output from running a\n"
	"        covered work is covered by this License only if the output, given its\n"
	"        content, constitutes a covered work.  This License acknowledges your\n"
	"        rights of fair use or other equivalent, as provided by copyright law.\n"
	"\n"
	"          You may make, run and propagate covered works that you do not\n"
	"        convey, without conditions so long as your license otherwise remains\n"
	"        in force.  You may convey covered works to others for the sole purpose\n"
	"        of having them make modifications exclusively for you, or provide you\n"
	"        with facilities for running those works, provided that you comply with\n"
	"        the terms of this License in conveying all material for which you do\n"
	"        not control copyright.  Those thus making or running the covered works\n"
	"        for you must do so exclusively on your behalf, under your direction\n"
	"        and control, on terms that prohibit them from making any copies of\n"
	"        your copyrighted material outside their relationship with you.\n"
	"\n"
	"          Conveying under any other circumstances is permitted solely under\n"
	"        the conditions stated below.  Sublicensing is not allowed; section 10\n"
	"        makes it unnecessary.\n"
	"\n"
	"          3. Protecting Users' Legal Rights From Anti-Circumvention Law.\n"
	"\n"
	"          No covered work shall be deemed part of an effective technological\n"
	"        measure under any applicable law fulfilling obligations under article\n"
	"        11 of the WIPO copyright treaty adopted on 20 December 1996, or\n"
	"        similar laws prohibiting or restricting circumvention of such\n"
	"        measures.\n"
	"\n"
	"          When you convey a covered work, you waive any legal power to forbid\n"
	"        circumvention of technological measures to the extent such circumvention\n"
	"        is effected by exercising rights under this License with respect to\n"
	"        the covered work, and you disclaim any intention to limit operation or\n"
	"        modification of the work as a means of enforcing, against the work's\n"
	"        users, your or third parties' legal rights to forbid circumvention of\n"
	"        technological measures.\n"
	"\n"
	"          4. Conveying Verbatim Copies.\n"
	"\n"
	"          You may convey verbatim copies of the Program's source code as you\n"
	"        receive it, in any medium, provided that you conspicuously and\n"
	"        appropriately publish on each copy an appropriate copyright notice;\n"
	"        keep intact all notices stating that this License and any\n"
	"        non-permissive terms added in accord with section 7 apply to the code;\n"
	"        keep intact all notices of the absence of any warranty; and give all\n"
	"        recipients a copy of this License along with the Program.\n"
	"\n"
	"          You may charge any price or no price for each copy that you convey,\n"
	"        and you may offer support or warranty protection for a fee.\n"
	"\n"
	"          5. Conveying Modified Source Versions.\n"
	"\n"
	"          You may convey a work based on the Program, or the modifications to\n"
	"        produce it from the Program, in the form of source code under the\n"
	"        terms of section 4, provided that you also meet all of these conditions:\n"
	"\n"
	"            a) The work must carry prominent notices stating that you modified\n"
	"            it, and giving a relevant date.\n"
	"\n"
	"            b) The work must carry prominent notices stating that it is\n"
	"            released under this License and any conditions added under section\n"
	"            7.  This requirement modifies the requirement in section 4 to\n"
	"            \"keep intact all notices\".\n"
	"\n"
	"            c) You must license the entire work, as a whole, under this\n"
	"            License to anyone who comes into possession of a copy.  This\n"
	"            License will therefore apply, along with any applicable section 7\n"
	"            additional terms, to the whole of the work, and all its parts,\n"
	"            regardless of how they are packaged.  This License gives no\n"
	"            permission to license the work in any other way, but it does not\n"
	"            invalidate such permission if you have separately received it.\n"
	"\n"
	"            d) If the work has interactive user interfaces, each must display\n"
	"            Appropriate Legal Notices; however, if the Program has interactive\n"
	"            interfaces that do not display Appropriate Legal Notices, your\n"
	"            work need not make them do so.\n"
	"\n"
	"          A compilation of a covered work with other separate and independent\n"
	"        works, which are not by their nature extensions of the covered work,\n"
	"        and which are not combined with it such as to form a larger program,\n"
	"        in or on a volume of a storage or distribution medium, is called an\n"
	"        \"aggregate\" if the compilation and its resulting copyright are not\n"
	"        used to limit the access or legal rights of the compilation's users\n"
	"        beyond what the individual works permit.  Inclusion of a covered work\n"
	"        in an aggregate does not cause this License to apply to the other\n"
	"        parts of the aggregate.\n"
	"\n"
	"          6. Conveying Non-Source Forms.\n"
	"\n"
	"          You may convey a covered work in object code form under the terms\n"
	"        of sections 4 and 5, provided that you also convey the\n"
	"        machine-readable Corresponding Source under the terms of this License,\n"
	"        in one of these ways:\n"
	"\n"
	"            a) Convey the object code in, or embodied in, a physical product\n"
	"            (including a physical distribution medium), accompanied by the\n"
	"            Corresponding Source fixed on a durable physical medium\n"
	"            customarily used for software interchange.\n"
	"\n"
	"            b) Convey the object code in, or embodied in, a physical product\n"
	"            (including a physical distribution medium), accompanied by a\n"
	"            written offer, valid for at least three years and valid for as\n"
	"            long as you offer spare parts or customer support for that product\n"
	"            model, to give anyone who possesses the object code either (1) a\n"
	"            copy of the Corresponding Source for all the software in the\n"
	"            product that is covered by this License, on a durable physical\n"
	"            medium customarily used for software interchange, for a price no\n"
	"            more than your reasonable cost of physically performing this\n"
	"            conveying of source, or (2) access to copy the\n"
	"            Corresponding Source from a network server at no charge.\n"
	"\n"
	"            c) Convey individual copies of the object code with a copy of the\n"
	"            written offer to provide the Corresponding Source.  This\n"
	"            alternative is allowed only occasionally and noncommercially, and\n"
	"            only if you received the object code with such an offer, in accord\n"
	"            with subsection 6b.\n"
	"\n"
	"            d) Convey the object code by offering access from a designated\n"
	"            place (gratis or for a charge), and offer equivalent access to the\n"
	"            Corresponding Source in the same way through the same place at no\n"
	"            further charge.  You need not require recipients to copy the\n"
	"            Corresponding Source along with the object code.  If the place to\n"
	"            copy the object code is a network server, the Corresponding Source\n"
	"            may be on a different server (operated by you or a third party)\n"
	"            that supports equivalent copying facilities, provided you maintain\n"
	"            clear directions next to the object code saying where to find the\n"
	"            Corresponding Source.  Regardless of what server hosts the\n"
	"            Corresponding Source, you remain obligated to ensure that it is\n"
	"            available for as long as needed to satisfy these requirements.\n"
	"\n"
	"            e) Convey the object code using peer-to-peer transmission, provided\n"
	"            you inform other peers where the object code and Corresponding\n"
	"            Source of the work are being offered to the general public at no\n"
	"            charge under subsection 6d.\n"
	"\n"
	"          A separable portion of the object code, whose source code is excluded\n"
	"        from the Corresponding Source as a System Library, need not be\n"
	"        included in conveying the object code work.\n"
	"\n"
	"          A \"User Product\" is either (1) a \"consumer product\", which means any\n"
	"        tangible personal property which is normally used for personal, family,\n"
	"        or household purposes, or (2) anything designed or sold for incorporation\n"
	"        into a dwelling.  In determining whether a product is a consumer product,\n"
	"        doubtful cases shall be resolved in favor of coverage.  For a particular\n"
	"        product received by a particular user, \"normally used\" refers to a\n"
	"        typical or common use of that class of product, regardless of the status\n"
	"        of the particular user or of the way in which the particular user\n"
	"        actually uses, or expects or is expected to use, the product.  A product\n"
	"        is a consumer product regardless of whether the product has substantial\n"
	"        commercial, industrial or non-consumer uses, unless such uses represent\n"
	"        the only significant mode of use of the product.\n"
	"\n"
	"          \"Installation Information\" for a User Product means any methods,\n"
	"        procedures, authorization keys, or other information required to install\n"
	"        and execute modified versions of a covered work in that User Product from\n"
	"        a modified version of its Corresponding Source.  The information must\n"
	"        suffice to ensure that the continued functioning of the modified object\n"
	"        code is in no case prevented or interfered with solely because\n"
	"        modification has been made.\n"
	"\n"
	"          If you convey an object code work under this section in, or with, or\n"
	"        specifically for use in, a User Product, and the conveying occurs as\n"
	"        part of a transaction in which the right of possession and use of the\n"
	"        User Product is transferred to the recipient in perpetuity or for a\n"
	"        fixed term (regardless of how the transaction is characterized), the\n"
	"        Corresponding Source conveyed under this section must be accompanied\n"
	"        by the Installation Information.  But this requirement does not apply\n"
	"        if neither you nor any third party retains the ability to install\n"
	"        modified object code on the User Product (for example, the work has\n"
	"        been installed in ROM).\n"
	"\n"
	"          The requirement to provide Installation Information does not include a\n"
	"        requirement to continue to provide support service, warranty, or updates\n"
	"        for a work that has been modified or installed by the recipient, or for\n"
	"        the User Product in which it has been modified or installed.  Access to a\n"
	"        network may be denied when the modification itself materially and\n"
	"        adversely affects the operation of the network or violates the rules and\n"
	"        protocols for communication across the network.\n"
	"\n"
	"          Corresponding Source conveyed, and Installation Information provided,\n"
	"        in accord with this section must be in a format that is publicly\n"
	"        documented (and with an implementation available to the public in\n"
	"        source code form), and must require no special password or key for\n"
	"        unpacking, reading or copying.\n"
	"\n"
	"          7. Additional Terms.\n"
	"\n"
	"          \"Additional permissions\" are terms that supplement the terms of this\n"
	"        License by making exceptions from one or more of its conditions.\n"
	"        Additional permissions that are applicable to the entire Program shall\n"
	"        be treated as though they were included in this License, to the extent\n"
	"        that they are valid under applicable law.  If additional permissions\n"
	"        apply only to part of the Program, that part may be used separately\n"
	"        under those permissions, but the entire Program remains governed by\n"
	"        this License without regard to the additional permissions.\n"
	"\n"
	"          When you convey a copy of a covered work, you may at your option\n"
	"        remove any additional permissions from that copy, or from any part of\n"
	"        it.  (Additional permissions may be written to require their own\n"
	"        removal in certain cases when you modify the work.)  You may place\n"
	"        additional permissions on material, added by you to a covered work,\n"
	"        for which you have or can give appropriate copyright permission.\n"
	"\n"
	"          Notwithstanding any other provision of this License, for material you\n"
	"        add to a covered work, you may (if authorized by the copyright holders of\n"
	"        that material) supplement the terms of this License with terms:\n"
	"\n"
	"            a) Disclaiming warranty or limiting liability differently from the\n"
	"            terms of sections 15 and 16 of this License; or\n"
	"\n"
	"            b) Requiring preservation of specified reasonable legal notices or\n"
	"            author attributions in that material or in the Appropriate Legal\n"
	"            Notices displayed by works containing it; or\n"
	"\n"
	"            c) Prohibiting misrepresentation of the origin of that material, or\n"
	"            requiring that modified versions of such material be marked in\n"
	"            reasonable ways as different from the original version; or\n"
	"\n"
	"            d) Limiting the use for publicity purposes of names of licensors or\n"
	"            authors of the material; or\n"
	"\n"
	"            e) Declining to grant rights under trademark law for use of some\n"
	"            trade names, trademarks, or service marks; or\n"
	"\n"
	"            f) Requiring indemnification of licensors and authors of that\n"
	"            material by anyone who conveys the material (or modified versions of\n"
	"            it) with contractual assumptions of liability to the recipient, for\n"
	"            any liability that these contractual assumptions directly impose on\n"
	"            those licensors and authors.\n"
	"\n"
	"          All other non-permissive additional terms are considered \"further\n"
	"        restrictions\" within the meaning of section 10.  If the Program as you\n"
	"        received it, or any part of it, contains a notice stating that it is\n"
	"        governed by this License along with a term that is a further\n"
	"        restriction, you may remove that term.  If a license document contains\n"
	"        a further restriction but permits relicensing or conveying under this\n"
	"        License, you may add to a covered work material governed by the terms\n"
	"        of that license document, provided that the further restriction does\n"
	"        not survive such relicensing or conveying.\n"
	"\n"
	"          If you add terms to a covered work in accord with this section, you\n"
	"        must place, in the relevant source files, a statement of the\n"
	"        additional terms that apply to those files, or a notice indicating\n"
	"        where to find the applicable terms.\n"
	"\n"
	"          Additional terms, permissive or non-permissive, may be stated in the\n"
	"        form of a separately written license, or stated as exceptions;\n"
	"        the above requirements apply either way.\n"
	"\n"
	"          8. Termination.\n"
	"\n"
	"          You may not propagate or modify a covered work except as expressly\n"
	"        provided under this License.  Any attempt otherwise to propagate or\n"
	"        modify it is void, and will automatically terminate your rights under\n"
	"        this License (including any patent licenses granted under the third\n"
	"        paragraph of section 11).\n"
	"\n"
	"          However, if you cease all violation of this License, then your\n"
	"        license from a particular copyright holder is reinstated (a)\n"
	"        provisionally, unless and until the copyright holder explicitly and\n"
	"        finally terminates your license, and (b) permanently, if the copyright\n"
	"        holder fails to notify you of the violation by some reasonable means\n"
	"        prior to 60 days after the cessation.\n"
	"\n"
	"          Moreover, your license from a particular copyright holder is\n"
	"        reinstated permanently if the copyright holder notifies you of the\n"
	"        violation by some reasonable means, this is the first time you have\n"
	"        received notice of violation of this License (for any work) from that\n"
	"        copyright holder, and you cure the violation prior to 30 days after\n"
	"        your receipt of the notice.\n"
	"\n"
	"          Termination of your rights under this section does not terminate the\n"
	"        licenses of parties who have received copies or rights from you under\n"
	"        this License.  If your rights have been terminated and not permanently\n"
	"        reinstated, you do not qualify to receive new licenses for the same\n"
	"        material under section 10.\n"
	"\n"
	"          9. Acceptance Not Required for Having Copies.\n"
	"\n"
	"          You are not required to accept this License in order to receive or\n"
	"        run a copy of the Program.  Ancillary propagation of a covered work\n"
	"        occurring solely as a consequence of using peer-to-peer transmission\n"
	"        to receive a copy likewise does not require acceptance.  However,\n"
	"        nothing other than this License grants you permission to propagate or\n"
	"        modify any covered work.  These actions infringe copyright if you do\n"
	"        not accept this License.  Therefore, by modifying or propagating a\n"
	"        covered work, you indicate your acceptance of this License to do so.\n"
	"\n"
	"          10. Automatic Licensing of Downstream Recipients.\n"
	"\n"
	"          Each time you convey a covered work, the recipient automatically\n"
	"        receives a license from the original licensors, to run, modify and\n"
	"        propagate that work, subject to this License.  You are not responsible\n"
	"        for enforcing compliance by third parties with this License.\n"
	"\n"
	"          An \"entity transaction\" is a transaction transferring control of an\n"
	"        organization, or substantially all assets of one, or subdividing an\n"
	"        organization, or merging organizations.  If propagation of a covered\n"
	"        work results from an entity transaction, each party to that\n"
	"        transaction who receives a copy of the work also receives whatever\n"
	"        licenses to the work the party's predecessor in interest had or could\n"
	"        give under the previous paragraph, plus a right to possession of the\n"
	"        Corresponding Source of the work from the predecessor in interest, if\n"
	"        the predecessor has it or can get it with reasonable efforts.\n"
	"\n"
	"          You may not impose any further restrictions on the exercise of the\n"
	"        rights granted or affirmed under this License.  For example, you may\n"
	"        not impose a license fee, royalty, or other charge for exercise of\n"
	"        rights granted under this License, and you may not initiate litigation\n"
	"        (including a cross-claim or counterclaim in a lawsuit) alleging that\n"
	"        any patent claim is infringed by making, using, selling, offering for\n"
	"        sale, or importing the Program or any portion of it.\n"
	"\n"
	"          11. Patents.\n"
	"\n"
	"          A \"contributor\" is a copyright holder who authorizes use under this\n"
	"        License of the Program or a work on which the Program is based.  The\n"
	"        work thus licensed is called the contributor's \"contributor version\".\n"
	"\n"
	"          A contributor's \"essential patent claims\" are all patent claims\n"
	"        owned or controlled by the contributor, whether already acquired or\n"
	"        hereafter acquired, that would be infringed by some manner, permitted\n"
	"        by this License, of making, using, or selling its contributor version,\n"
	"        but do not include claims that would be infringed only as a\n"
	"        consequence of further modification of the contributor version.  For\n"
	"        purposes of this definition, \"control\" includes the right to grant\n"
	"        patent sublicenses in a manner consistent with the requirements of\n"
	"        this License.\n"
	"\n"
	"          Each contributor grants you a non-exclusive, worldwide, royalty-free\n"
	"        patent license under the contributor's essential patent claims, to\n"
	"        make, use, sell, offer for sale, import and otherwise run, modify and\n"
	"        propagate the contents of its contributor version.\n"
	"\n"
	"          In the following three paragraphs, a \"patent license\" is any express\n"
	"        agreement or commitment, however denominated, not to enforce a patent\n"
	"        (such as an express permission to practice a patent or covenant not to\n"
	"        sue for patent infringement).  To \"grant\" such a patent license to a\n"
	"        party means to make such an agreement or commitment not to enforce a\n"
	"        patent against the party.\n"
	"\n"
	"          If you convey a covered work, knowingly relying on a patent license,\n"
	"        and the Corresponding Source of the work is not available for anyone\n"
	"        to copy, free of charge and under the terms of this License, through a\n"
	"        publicly available network server or other readily accessible means,\n"
	"        then you must either (1) cause the Corresponding Source to be so\n"
	"        available, or (2) arrange to deprive yourself of the benefit of the\n"
	"        patent license for this particular work, or (3) arrange, in a manner\n"
	"        consistent with the requirements of this License, to extend the patent\n"
	"        license to downstream recipients.  \"Knowingly relying\" means you have\n"
	"        actual knowledge that, but for the patent license, your conveying the\n"
	"        covered work in a country, or your recipient's use of the covered work\n"
	"        in a country, would infringe one or more identifiable patents in that\n"
	"        country that you have reason to believe are valid.\n"
	"\n"
	"          If, pursuant to or in connection with a single transaction or\n"
	"        arrangement, you convey, or propagate by procuring conveyance of, a\n"
	"        covered work, and grant a patent license to some of the parties\n"
	"        receiving the covered work authorizing them to use, propagate, modify\n"
	"        or convey a specific copy of the covered work, then the patent license\n"
	"        you grant is automatically extended to all recipients of the covered\n"
	"        work and works based on it.\n"
	"\n"
	"          A patent license is \"discriminatory\" if it does not include within\n"
	"        the scope of its coverage, prohibits the exercise of, or is\n"
	"        conditioned on the non-exercise of one or more of the rights that are\n"
	"        specifically granted under this License.  You may not convey a covered\n"
	"        work if you are a party to an arrangement with a third party that is\n"
	"        in the business of distributing software, under which you make payment\n"
	"        to the third party based on the extent of your activity of conveying\n"
	"        the work, and under which the third party grants, to any of the\n"
	"        parties who would receive the covered work from you, a discriminatory\n"
	"        patent license (a) in connection with copies of the covered work\n"
	"        conveyed by you (or copies made from those copies), or (b) primarily\n"
	"        for and in connection with specific products or compilations that\n"
	"        contain the covered work, unless you entered into that arrangement,\n"
	"        or that patent license was granted, prior to 28 March 2007.\n"
	"\n"
	"          Nothing in this License shall be construed as excluding or limiting\n"
	"        any implied license or other defenses to infringement that may\n"
	"        otherwise be available to you under applicable patent law.\n"
	"\n"
	"          12. No Surrender of Others' Freedom.\n"
	"\n"
	"          If conditions are imposed on you (whether by court order, agreement or\n"
	"        otherwise) that contradict the conditions of this License, they do not\n"
	"        excuse you from the conditions of this License.  If you cannot convey a\n"
	"        covered work so as to satisfy simultaneously your obligations under this\n"
	"        License and any other pertinent obligations, then as a consequence you may\n"
	"        not convey it at all.  For example, if you agree to terms that obligate you\n"
	"        to collect a royalty for further conveying from those to whom you convey\n"
	"        the Program, the only way you could satisfy both those terms and this\n"
	"        License would be to refrain entirely from conveying the Program.\n"
	"\n"
	"          13. Remote Network Interaction; Use with the GNU General Public License.\n"
	"\n"
	"          Notwithstanding any other provision of this License, if you modify the\n"
	"        Program, your modified version must prominently offer all users\n"
	"        interacting with it remotely through a computer network (if your version\n"
	"        supports such interaction) an opportunity to receive the Corresponding\n"
	"        Source of your version by providing access to the Corresponding Source\n"
	"        from a network server at no charge, through some standard or customary\n"
	"        means of facilitating copying of software.  This Corresponding Source\n"
	"        shall include the Corresponding Source for any work covered by version 3\n"
	"        of the GNU General Public License that is incorporated pursuant to the\n"
	"        following paragraph.\n"
	"\n"
	"          Notwithstanding any other provision of this License, you have\n"
	"        permission to link or combine any covered work with a work licensed\n"
	"        under version 3 of the GNU General Public License into a single\n"
	"        combined work, and to convey the resulting work.  The terms of this\n"
	"        License will continue to apply to the part which is the covered work,\n"
	"        but the work with which it is combined will remain governed by version\n"
	"        3 of the GNU General Public License.\n"
	"\n"
	"          14. Revised Versions of this License.\n"
	"\n"
	"          The Free Software Foundation may publish revised and/or new versions of\n"
	"        the GNU Affero General Public License from time to time.  Such new versions\n"
	"        will be similar in spirit to the present version, but may differ in detail to\n"
	"        address new problems or concerns.\n"
	"\n"
	"          Each version is given a distinguishing version number.  If the\n"
	"        Program specifies that a certain numbered version of the GNU Affero General\n"
	"        Public License \"or any later version\" applies to it, you have the\n"
	"        option of following the terms and conditions either of that numbered\n"
	"        version or of any later version published by the Free Software\n"
	"        Foundation.  If the Program does not specify a version number of the\n"
	"        GNU Affero General Public License, you may choose any version ever published\n"
	"        by the Free Software Foundation.\n"
	"\n"
	"          If the Program specifies that a proxy can decide which future\n"
	"        versions of the GNU Affero General Public License can be used, that proxy's\n"
	"        public statement of acceptance of a version permanently authorizes you\n"
	"        to choose that version for the Program.\n"
	"\n"
	"          Later license versions may give you additional or different\n"
	"        permissions.  However, no additional obligations are imposed on any\n"
	"        author or copyright holder as a result of your choosing to follow a\n"
	"        later version.\n"
	"\n"
	"          15. Disclaimer of Warranty.\n"
	"\n"
	"          THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY\n"
	"        APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT\n"
	"        HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY\n"
	"        OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,\n"
	"        THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n"
	"        PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\n"
	"        IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n"
	"        ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n"
	"\n"
	"          16. Limitation of Liability.\n"
	"\n"
	"          IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\n"
	"        WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS\n"
	"        THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY\n"
	"        GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE\n"
	"        USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF\n"
	"        DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD\n"
	"        PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),\n"
	"        EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF\n"
	"        SUCH DAMAGES.\n"
	"\n"
	"          17. Interpretation of Sections 15 and 16.\n"
	"\n"
	"          If the disclaimer of warranty and limitation of liability provided\n"
	"        above cannot be given local legal effect according to their terms,\n"
	"        reviewing courts shall apply local law that most closely approximates\n"
	"        an absolute waiver of all civil liability in connection with the\n"
	"        Program, unless a warranty or assumption of liability accompanies a\n"
	"        copy of the Program in return for a fee.\n"
	"\n"
	"                             END OF TERMS AND CONDITIONS\n"
	"\n"
	"                    How to Apply These Terms to Your New Programs\n"
	"\n"
	"          If you develop a new program, and you want it to be of the greatest\n"
	"        possible use to the public, the best way to achieve this is to make it\n"
	"        free software which everyone can redistribute and change under these terms.\n"
	"\n"
	"          To do so, attach the following notices to the program.  It is safest\n"
	"        to attach them to the start of each source file to most effectively\n"
	"        state the exclusion of warranty; and each file should have at least\n"
	"        the \"copyright\" line and a pointer to where the full notice is found.\n"
	"\n"
	"            <one line to give the program's name and a brief idea of what it does.>\n"
	"            Copyright (C) <year>  <name of author>\n"
	"\n"
	"            This program is free software: you can redistribute it and/or modify\n"
	"            it under the terms of the GNU Affero General Public License as published by\n"
	"            the Free Software Foundation, either version 3 of the License, or\n"
	"            (at your option) any later version.\n"
	"\n"
	"            This program is distributed in the hope that it will be useful,\n"
	"            but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"            GNU Affero General Public License for more details.\n"
	"\n"
	"            You should have received a copy of the GNU Affero General Public License\n"
	"            along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"
	"\n"
	"        Also add information on how to contact you by electronic and paper mail.\n"
	"\n"
	"          If your software can interact with users remotely through a computer\n"
	"        network, you should also make sure that it provides a way for users to\n"
	"        get its source.  For example, if your program is a web application, its\n"
	"        interface could display a \"Source\" link that leads users to an archive\n"
	"        of the code.  There are many ways you could offer source, and different\n"
	"        solutions will be better for different programs; see section 13 for the\n"
	"        specific requirements.\n"
	"\n"
	"          You should also get your employer (if you work as a programmer) or school,\n"
	"        if any, to sign a \"copyright disclaimer\" for the program, if necessary.\n"
	"        For more information on this, and how to apply and follow the GNU AGPL, see\n"
	"        <https://www.gnu.org/licenses/>.\n"
	"\n"
	"\n"
	"\n"
	"";