 /*
 **
 **           _      ____   _      ___    _          ___       ___
 **          | |    | |_   \ \_/  / / \  | |\ |     / / \  __   ) )
 **          |_|__  |_|__  /_/ \  \_\_/  |_| \|     \_\_/ (_() _)_)
 **
 **
 **                  Lexon — natural language programming
 **
 **     Copyright (C) 2016-24 Henning Diedrich. Licensed to you under
 **     AGPL3 subject to the conditions described in the file LICENSE.
 **
 **     Also see https://www.lexon.org/license-0.3.html
 **
 **
 **	Lexon code production / AST walk target module
 */
 ##	target.c
 ##
 ##	This file is used to create javascript.c, solidity.c and sophia.c.
 ##	It is a blend of all three and not intended to compile as-is.
 ##
 ##	This streamlines grammar extension work that comprises identical
 ##	boilerplate across the targets, and common additional logic.
 ##	It is an intermediary device to find the commonalities between targets
 ##	en-route to a higher-level abstraction of shared basics.
 ##
 ##	Lines are marked for how they are split up by the Makefile:
 ##
 ##	/*JS */		Javascript only
 ##	/*Sol*/		Solidity only
 ##	/*Sop*/		Sophia only
 ##	/*J+S*/		Javascript and Solidity
 ##	/*S+S*/		Solidity and Sophia
 ##	/*T*/		generated boilerplate
 ##
 ##	All other lines, and the *T* boilerplate, are shared by all targets.
 ##
 ##	The tags are processed during build by one-liners in the Makefile
 ##	to create javascript.c, solidity.c and sophia.c.
 ##
 ##	To work with this source, to help telling apart the targets, add this
 ##	syntax highlighting in ~/.vimrc:
 ##
 ##     :syntax on
 ##
 ##	autocmd ColorScheme *
 ##	        \ syn match lexfrontT   "\/\*T.*"   contains=cFunction |
 ##	        \ syn match lexfrontJS  "\/\*JS .*" contains=cString |
 ##	        \ syn match lexfrontSol "\/\*Sol.*" contains=cString |
 ##	        \ syn match lexfrontSop "\/\*Sop.*" contains=cString |
 ##	        \ syn match lexfrontJaS "\/\*J+S.*" contains=cString |
 ##	        \ syn match lexfrontSaS "\/\*S+S.*" contains=cString |
 ##	        \ hi lexfrontT   ctermfg=110 guifg=#84a0c6 |
 ##	        \ hi lexfrontJS  ctermfg=76  guifg=#5fd700 |
 ##	        \ hi lexfrontSol ctermfg=51  guifg=#00ffff |
 ##	        \ hi lexfrontSaS ctermfg=21  guifg=#0000ff |
 ##	        \ hi lexfrontJaS ctermfg=28  guifg=#008700 |
 ##	        \ hi lexfrontJxS ctermfg=94  guifg=#875f00 |
 ##	        \ hi lexfrontSop ctermfg=127 guifg=#af00afv
 ##
 ##	This colors every tagged line in its own hue, making the scheme
 ##	more transparent and workable.

/*JS */   /*	javascript.c - Javascript backend	*/
/*JS */
/*JS */ #define backend_version "javascript 0.3.93 U"
/*JS */ #define target_version "node 14.1+"

/*Sol*/   /*	solidity.c - Solidity backend	*/
/*Sol*/
/*Sol*/ #define backend_version "solidity 0.3.93 U"
/*Sol*/ #define target_version "solidity 0.8+"

/*Sop*/   /*	sophia.c - Sophia backend	*/
/*Sop*/
/*Sop*/ #define backend_version "sophia 0.3.93 U"
/*Sop*/ #define target_version "sophia 6+"

#define CYCLE_2 true

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/*JS */ #define EOL ";"
/*Sol*/ #define EOL ";"
/*Sop*/ #define EOL ""

int yylex(void);
void yyerror(const char *);
static void error(char *msg, char *cargo);

#define NEW(type) \
	if(opt_debug_tokens) fprintf(stderr, "tokens : creating node for " #type "\n"); \
	type *type = mtrac_malloc(sizeof(struct type)); \
	memset(type, 0, sizeof(struct type));
#define mtrac_malloc(size_) _mtrac_malloc(size_, "[unknown]", __FILE__, __LINE__)
#define mtrac_strdup(string_) _mtrac_strdup(string_, "[unknown]", __FILE__, __LINE__)
#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)
#define mtrac_concat(...) _mtrac_concat(__FILE__, __LINE__, 0, 0, __VA_ARGS__, null)
#define replace_first_from(orig_, rep_, with_, from_) \
	_replace(orig_, rep_, with_, false, from_, false, #orig_, __FILE__, __LINE__)
void *_mtrac_malloc(size_t size, char *name, char *file, int line);
void *_mtrac_strdup(const char *string, char *name, char *file, int line);
void _mtrac_free(void *p, char *name, char *file, int line);
char **_mtrac_concat(char *file, int line, int down, int right, char **buf, ...);
#define YYFPRINTF yacc_printf

typedef int bool;
#define false 0
#define true 1
#define null (void *)0

extern const char *program_version;
extern const char *grammar_version;

typedef char Literal;
typedef char Name;
typedef char Description;
typedef char Scalar;
typedef char Hex;

#define concat(var_, ...) _concat(#var_, __FILE__, __LINE__, 0, 0, var_, __VA_ARGS__, null)
#define padcat(down_, right_, var_, ...) _concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)
char **_concat(char *, char*, int, int, int, char **buf, ...);
char **_concatnum(char **buf, char *prefix, int number, char *postfix);
void yacc_printf(FILE *stream, char *format, ...);

extern char *opt_source;
extern bool opt_debug;
extern bool opt_verbose;
extern bool opt_bare;
extern bool opt_instructions;
extern bool opt_comment;
extern bool opt_lexon_comments;
extern bool opt_feedback;
extern bool opt_harden;
extern char *opt_log;
extern int opt_chaining;
extern int opt_signatures;
extern char *opt_persistence;
extern char *opt_bundle;
extern char *opt_email;
extern bool opt_debug_actions;
extern bool opt_debug_tokens;
extern bool opt_debug_production;
extern bool _concat_trace;
extern char *opt_summarized;

extern const char *get_lexcom(const char *);

/* optical convenience */
#define C (1 + (opt_comment?0:1))

/* extern calls from lexon.l */
const char *str(int line);
extern struct Document *root;

bool xxx_document(char **production, struct Document *root, int indent);

#define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, false, #orig_, __FILE__, __LINE__)
extern char *_replace(char **orig, const char *rep, const char *with, int all, char *from, bool whole, char *origname, char *file, int line);
extern const char *str(int line);
static char *quote_trimmed(const char *token);
static char *dash_spaced(const char *token);
extern char *snake_spaced(const char *token);
extern char *camel_spaced(const char *token);
extern char *LOW(const char *token);
extern char *UP(const char *token);

static char *SAFE(const char *token);
static const char *type(const char *varname, bool option_type, bool forpara);
static const char *nullmap(const char *lex_type, bool defined_default);
static const char *defaultmap(const char *lex_type);
static const char *lextype(const char *varname);
static const char *typemap(const char *lextype, bool option_type, bool forpara);
static const char *nullvalue(const char *name, bool defined_default);

static char *methods = null;
static char *globals = null;
static char *declarations = null;
static char *initializations = null;
static char *fixed = null; // list of variables that have been set in this function
static char *declared = null; // list of variables that come in as paremeters
static char *functions = null;
static bool miller = false;

static char _safe[1003];
static char *SAFE(const char *name) { ////// INCOMPLETE LIST: INCLUDE ALL LANGUAGE KEYWORDS
	assert(name);
	assert(strlen(name) < 1000);
	strcpy(_safe, " ");
	strcat(_safe, name);
	strcat(_safe, " ");
/*JS */	if(!strstr(" send terminate terminated default ", _safe))
/*Sol*/	if(!strstr(" Message permit send terminate terminated default contract constructor function transfer call check_termination ", _safe))
/*Sop*/	if(!strstr(" Message permit send terminate terminated default contract constructor function transfer call check_termination" // Lexon
/*Sop*/		   " contract include let switch type record datatype if elif else function stateful payable true false mod public" // Sophia 7.1
/*Sop*/		   " entrypoint private indexed namespace interface main using as for hiding", _safe)) // Sophia 7.1
		return (char *)name;
/*S+S*/	strcpy(_safe, "_");
/*S+S*/	strcat(_safe, name); // haystack limits lenght of possible needles
/*JS */	strcpy(_safe, name); //X difference to S+S warranted? //////
/*JS */	strcat(_safe, "_");
	return _safe;
}

typedef struct list {
	void *item;
	struct list *next;
} list;

static void list_add(list **l, void *item) {
	list *n = mtrac_malloc(sizeof(list));
	n->item = item;
	n->next = *l;
	*l = n;
}

static list *shallow_clone(list *l) {
	list *clone = null;
	while(l) {
		list_add(&clone, l->item);
		l = l->next;
	}
	return clone;
}

static int drop_item(list **l, list *drop) {
	int count = 0;
	list *cur = *l, *prev = null;
	while(cur) {
		if(cur->item == drop->item) {
			if(prev) prev->next = cur->next;
			else *l = cur->next;
			list *next = cur->next;
			mtrac_free(cur);
			cur = next;
			// prev remains
			count++;
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
	return count;
}

static void delete_list(list *l) {
	list *m;
	while((m = l)) l = l->next, mtrac_free(m);
}

static void delete_list_and_items(list *l) {
	list *m;
	while((m = l)) l = l->next, mtrac_free(m->item), mtrac_free(m);
}

/* this is an optimization to not have all functions require a caller.
   This is almost an optical nuance but really about not confusing
   users with compilation artifacts. */

static int bind_index = 100;
typedef struct bind {
	int index;
	char *tag;
	char *name;
	char *parameters;
	char *arguments;
	char *parameta; // for instructions, wrapped in < >
	bool uses_caller;
	bool uses_permission;
	bool changes_state;
	struct call *calls;
	struct bind *next;
} bind;
static bind *binds = null;
static bind *last_bind = null;

typedef struct call {
	struct bind *bind;
	struct call *next;
} call;

static bool traverse_for_caller(bind *bind, int fuse);
static void produce_access_conditions(int down, int indent, char **production, list *subjects);

/* create or find a binding for a function name */
static bind *register_bind(char *name) {

	assert(name && strlen(name));
	bind *bind = binds;
	while(bind && strcmp(name, bind->name)) bind = bind->next;
	if(!bind) {
		bind = mtrac_malloc(sizeof(struct bind)); // sic
		bind->index = bind_index++;
		bind->tag = mtrac_strdup("");
		mtrac_concat(&bind->tag, "%", str(bind->index), "%");
		bind->name = mtrac_strdup(name);
		bind->parameters = mtrac_strdup("");
		bind->arguments = mtrac_strdup("");
		bind->parameta = mtrac_strdup("");
		bind->uses_caller = false;
		bind->uses_permission = false;
		bind->changes_state = false;
		bind->calls = null;
		bind->next = null;
		if(!binds) binds = bind;
		if(last_bind) last_bind->next = bind;
		last_bind = bind;
	}
	return bind;
}

/* register a call and receive the point to be set to the coming next one */
static call **register_call(call **prevnext, char *to) {
	call *call = mtrac_malloc(sizeof(call));
	call->bind = register_bind(to);
	call->next = null;
	*prevnext = call;
	return &call->next;
}

static void replace_bind_tags(char **production, char **instructions, bind *b) {

	while(b) {
		char *head = mtrac_strdup("");
		char *ihead = mtrac_strdup("");

//		if(!b->uses_permission && b->changes_state) ///// replace by logic 'has subject'
//			mtrac_concat(&head, "#");

		mtrac_concat(&head, b->name);
		mtrac_concat(&ihead, b->name);

/*JS */		if(traverse_for_caller(b, 10)) {
/*JS */			mtrac_concat(&head, "(caller", strlen(b->parameters)?", ":"", b->parameters, ")");
/*JS */			if(!strlen(b->parameta)) /* sic: instructions have the subject (caller) in parameta */
/*JS */				mtrac_concat(&ihead, "(<caller>)");
/*JS */			else
/*JS */				mtrac_concat(&ihead, "(", b->parameta, ")");
/*JS */
/*JS */		} else {
			mtrac_concat(&head, "(", b->parameters, ")");
			mtrac_concat(&ihead, "(", b->parameta, ")");
/*JS */		}

		/* now replace the tags standing in for the function declaration head and all calls to the function in the production string */
		replace(production, b->tag, head);
		replace(instructions, b->tag, ihead); // private functions will just not have a tag to match

		mtrac_free(head);
		mtrac_free(ihead);
		b = b->next;
	}
}

static bool traverse_for_caller(bind *bind, int fuse) {
	if(bind->uses_caller) return true;
	if(!fuse) return false;
	call *c = bind->calls;
	while(c) {
		if(traverse_for_caller(c->bind, fuse-1)) return true;
		c = c->next;
	}
	return false;
}

static void delete_bind_tree(bind *b) {
	while(b) {
		call *cc, *c = b->calls;
		while(c) { cc = c->next; mtrac_free(c); c = cc; }
		mtrac_free(b->name);
		mtrac_free(b->tag);
		if(b->parameters) mtrac_free(b->parameters);
		if(b->arguments) mtrac_free(b->arguments);
		if(b->parameta) mtrac_free(b->parameta);
		bind *bb = b->next;
		mtrac_free(b);
		b = bb;
	}
}

static bool in(char *hay, char *needle) {
	char *tagged = mtrac_strdup("");
	mtrac_concat(&tagged, ":", needle, ":");
	bool in = !!strstr(hay, tagged);
	mtrac_free(tagged);
	return in;
}


/* AST nodes = semantic value types (in actions, the respective types of '$$') */
/*T*/
/*T*/	typedef struct Document {
/*T*/		struct Head *Head;
/*T*/		struct Terms *Terms;
/*T*/		struct Covenants *Covenants;
/*T*/	} Document;
/*T*/
/*T*/	typedef struct Head {
/*T*/		struct Lex *Lex;
/*T*/		struct Preamble *Preamble;
/*T*/		struct Comment *Comment;
/*T*/		struct Authors *Authors;
/*T*/		struct Lexon *Lexon;
/*T*/	} Head;
/*T*/
/*T*/	typedef struct Lex {
/*T*/		Name *Name;
/*T*/	} Lex;
/*T*/
/*T*/	typedef struct Lexon {
/*T*/		Description *Description;
/*T*/	} Lexon;
/*T*/
/*T*/	typedef struct Authors {
/*T*/		Description *Description;
/*T*/	} Authors;
/*T*/
/*T*/	typedef struct Comment {
/*T*/		Description *Description;
/*T*/	} Comment;
/*T*/
/*T*/	typedef struct Preamble {
/*T*/		Description *Description;
/*T*/	} Preamble;
/*T*/
/*T*/	typedef struct Terms {
/*T*/		struct Provisions *Provisions;
/*T*/	} Terms;
/*T*/
/*T*/	typedef struct Covenants {
/*T*/		struct Covenant *Covenant;
/*T*/		struct Covenants *Covenants;
/*T*/	} Covenants;
/*T*/
/*T*/	typedef struct Covenant {
/*T*/		Name *Name;
/*T*/		struct Provisions *Provisions;
/*T*/	} Covenant;
/*T*/
/*T*/	typedef struct Provisions {
/*T*/		struct Definitions *Definitions;
/*T*/		struct Clauses *Clauses;
/*T*/		struct Statements *Statements;
/*T*/	} Provisions;
/*T*/
/*T*/	typedef struct Definitions {
/*T*/		struct Definition *Definition;
/*T*/		struct Definitions *Definitions;
/*T*/	} Definitions;
/*T*/
/*T*/	typedef struct Definition {
/*T*/		Name *Name;
/*T*/		struct Placeholder *Placeholder;
/*T*/		struct Article *Article;
/*T*/		struct This_Contract *This_Contract;
/*T*/	} Definition;
/*T*/
/*T*/	typedef struct Placeholder {
/*T*/		struct Type *Type;
/*T*/		struct Article *Article;
/*T*/	} Placeholder;
/*T*/
/*T*/	typedef struct Type {
/*T*/	        struct Person *Person;
/*T*/	        struct Amount *Amount;
/*T*/	        struct Time *Time;
/*T*/	        struct Binary *Binary;
/*T*/	        struct Text *Text;
/*T*/	        struct Data *Data;
		Literal *Literal;
/*T*/	} Type;
/*T*/
/*T*/	typedef struct Person {
/*T*/	} Person;
/*T*/
/*T*/	typedef struct Amount {
/*T*/	} Amount;
/*T*/
/*T*/	typedef struct Time {
/*T*/	} Time;
/*T*/
/*T*/	typedef struct Binary {
/*T*/	} Binary;
/*T*/
/*T*/	typedef struct Text {
/*T*/	} Text;
/*T*/
/*T*/	typedef struct Data {
/*T*/	} Data;
/*T*/
/*T*/	typedef struct This_Contract {
/*T*/		struct This *This;
/*T*/		Name *Name;
/*T*/	} This_Contract;
/*T*/
/*T*/	typedef struct All_Contracts {
/*T*/	} All_Contracts;
/*T*/
/*T*/	typedef struct This {
/*T*/	} This;
/*T*/
/*T*/	typedef struct Clauses {
/*T*/		struct Clause *Clause;
/*T*/		struct Clauses *Clauses;
/*T*/	} Clauses;
/*T*/
/*T*/	typedef struct Clause {
/*T*/		Name *Name;
/*T*/		struct Body *Body;
/*T*/	} Clause;
/*T*/
/*T*/	typedef struct Body {
/*T*/		struct Statements *Statements;
/*T*/		struct Function *Function;
/*T*/	} Body;
/*T*/
/*T*/	typedef struct Function {
/*T*/		Name *Name;
/*T*/		struct Illocutor *Illocutor;
/*T*/		struct Expression *Expression;
/*T*/		struct Article *Article;
/*T*/	} Function;
/*T*/
/*T*/	typedef struct Statements {
/*T*/		struct Statement *Statement;
/*T*/		struct Statements *Statements;
/*T*/	} Statements;
/*T*/
/*T*/	typedef struct Statement {
/*T*/		struct Action *Action;
/*T*/		struct Flagging *Flagging;
/*T*/	} Statement;
/*T*/
/*T*/	typedef struct Actions {
/*T*/		struct Action *Action;
/*T*/		struct Actions *Actions;
/*T*/	} Actions;
/*T*/
/*T*/	typedef struct Action {
/*T*/		struct Subject *Subject;
/*T*/		struct Predicates *Predicates;
/*T*/		struct Permission *Permission;
/*T*/		struct Condition *Condition;
/*T*/	} Action;
/*T*/
/*T*/	typedef struct Subject {
/*T*/		struct Symbols *Symbols;
/*T*/	} Subject;
/*T*/
/*T*/	typedef struct Symbols {
/*T*/		struct Symbol *Symbol;
/*T*/		struct Symbols *Symbols;
/*T*/		struct Catena *Catena;
/*T*/	} Symbols;
/*T*/
/*T*/	typedef struct Symbol {
/*T*/		Name *Name;
/*T*/		struct Article *Article;
/*T*/		struct Type *Type;
/*T*/	} Symbol;
/*T*/
/*T*/	typedef struct Catena {
/*T*/	} Catena;
/*T*/
/*T*/	typedef struct Object {
/*T*/		struct Symbol *Symbol;
/*T*/		struct Reflexive *Reflexive;
/*T*/	} Object;
/*T*/
/*T*/	typedef struct Reflexive {
/*T*/	} Reflexive;
/*T*/
/*T*/	typedef struct Contract {
/*T*/		struct This_Contract *This_Contract;
/*T*/		struct All_Contracts *All_Contracts;
/*T*/	} Contract;
/*T*/
/*T*/	typedef struct Predicates {
/*T*/		struct Predicates *Predicates;
/*T*/		struct Predicate *Predicate;
/*T*/	} Predicates;
/*T*/
/*T*/	typedef struct Predicate {
/*T*/		struct Certification *Certification;
/*T*/		struct Declaration *Declaration;
/*T*/		struct Filing *Filing;
/*T*/		struct Registration *Registration;
/*T*/		struct Grantment *Grantment;
/*T*/		struct Appointment *Appointment;
/*T*/		struct Fixture *Fixture;
/*T*/		struct Setting *Setting;
/*T*/		struct Payment *Payment;
/*T*/		struct Sending *Sending;
/*T*/		struct Notification *Notification;
/*T*/		struct Termination *Termination;
/*T*/	} Predicate;
/*T*/
/*T*/	typedef struct Permission {
/*T*/	} Permission;
/*T*/
/*T*/	typedef struct Certification {
/*T*/		struct Certify *Certify;
/*T*/		struct Symbol *Symbol;
/*T*/		struct Expression *Expression;
/*T*/		struct Contract *Contract;
/*T*/	} Certification;
/*T*/
/*T*/	typedef struct Certify {
/*T*/	} Certify;
/*T*/
/*T*/	typedef struct Declaration {
/*T*/	        struct Declare *Declare;
/*T*/	        struct Symbol *Symbol;
/*T*/		struct Expression *Expression;
/*T*/		struct Contract *Contract;
/*T*/	} Declaration;
/*T*/
/*T*/	typedef struct Declare {
/*T*/	} Declare;
/*T*/
/*T*/	typedef struct Filing {
/*T*/	        struct File *File;
/*T*/	        struct Symbol *Symbol;
/*T*/		struct Expression *Expression;
/*T*/		struct Contract *Contract;
/*T*/	} Filing;
/*T*/
/*T*/	typedef struct File {
/*T*/	} File;
/*T*/
/*T*/	typedef struct Registration {
/*T*/		struct Register *Register;
/*T*/		struct Symbol *Symbol;
/*T*/		struct Expression *Expression;
/*T*/		struct Contract *Contract;
/*T*/	} Registration;
/*T*/
/*T*/	typedef struct Register {
/*T*/	} Register;
/*T*/
/*T*/	typedef struct Grantment {
/*T*/		struct Grant *Grant;
/*T*/		struct Symbol *Symbol;
/*T*/	} Grantment;
/*T*/
/*T*/	typedef struct Grant {
/*T*/	} Grant;
/*T*/
/*T*/	typedef struct Appointment {
/*T*/		struct Appoint *Appoint;
/*T*/		struct Symbol *Symbol;
/*T*/	} Appointment;
/*T*/
/*T*/	typedef struct Appoint {
/*T*/	} Appoint;
/*T*/
/*T*/	typedef struct Fixture {
/*T*/		struct Fix *Fix;
/*T*/		struct Symbol *Symbol;
/*T*/		struct Expression *Expression;
/*T*/		struct Contract *Contract;
/*T*/	} Fixture;
/*T*/
/*T*/	typedef struct Fix {
/*T*/	} Fix;
/*T*/
/*T*/	typedef struct Setting {
/*T*/		struct Illocutor *Illocutor;
/*T*/		struct Symbol *Symbol;
/*T*/	} Setting;
/*T*/
/*T*/	typedef struct Illocutor {
/*T*/		struct Be *Be;
/*T*/	} Illocutor;
/*T*/
/*T*/	typedef struct Be {
/*T*/	} Be;
/*T*/
/*T*/	typedef struct Payment {
/*T*/		struct Pay *Pay;
/*T*/		struct Expression *Expression;
/*T*/		struct Preposition *Preposition;
/*T*/		struct Object *Object;
/*T*/		struct From_Escrow *From_Escrow;
/*T*/		struct Escrow *Escrow;
/*T*/	} Payment;
/*T*/
/*T*/	typedef struct Pay {
/*T*/	} Pay;
/*T*/
/*T*/	typedef struct Preposition {
/*T*/	} Preposition;
/*T*/
/*T*/	typedef struct Escrow {
/*T*/	} Escrow;
/*T*/
/*T*/	typedef struct From_Escrow {
/*T*/	} From_Escrow;
/*T*/
/*T*/	typedef struct Sending {
/*T*/		struct Send *Send;
/*T*/		struct Expression *Expression;
/*T*/		struct Preposition *Preposition;
/*T*/		struct Object *Object;
/*T*/	} Sending;
/*T*/
/*T*/	typedef struct Send {
/*T*/	} Send;
/*T*/
/*T*/	typedef struct Notification {
/*T*/		struct Notify *Notify;
/*T*/		struct Object *Object;
/*T*/		struct Preposition *Preposition;
/*T*/		struct Expression *Expression;
/*T*/	} Notification;
/*T*/
/*T*/	typedef struct Notify {
/*T*/	} Notify;
/*T*/
/*T*/	typedef struct Termination {
/*T*/		struct Terminate *Terminate;
/*T*/		struct This_Contract *This_Contract;
/*T*/		struct All_Contracts *All_Contracts;
/*T*/	} Termination;
/*T*/
/*T*/	typedef struct Terminate {
/*T*/	} Terminate;
/*T*/
/*T*/	typedef struct Flagging {
/*T*/		struct Illocutor *Illocutor;
/*T*/		struct Symbol *Symbol;
/*T*/		struct This_Contract *This_Contract;
/*T*/	} Flagging;
/*T*/
/*T*/	typedef struct Condition {
/*T*/		struct If *If;
/*T*/		struct Expression *Expression;
/*T*/	} Condition;
/*T*/
/*T*/	typedef struct If {
/*T*/	} If;
/*T*/
/*T*/	typedef struct Expression {
/*T*/		struct Combination *Combination;
/*T*/	} Expression;
/*T*/
/*T*/	typedef struct Scalar_Comparison {
/*T*/		struct Scalar_Expression *Scalar_Expression;
/*T*/		struct Comparison_Operator *Comparison_Operator;
/*T*/		struct Scalar_Expression *Scalar_Expression2;
/*T*/	} Scalar_Comparison;
/*T*/
/*T*/	typedef struct Hex_Expression {
/*T*/		struct Symbol *Symbol;
/*T*/		Hex *Hex;
		// struct Point_In_Time *Point_In_Time;
/*T*/	} Hex_Expression;
/*T*/
/*T*/	typedef struct Comparison_Operator {
/*T*/		struct Equal *Equal;
/*T*/		struct Later *Later;
/*T*/	} Comparison_Operator;
/*T*/
/*T*/	typedef struct Equal {
/*T*/	} Equal;
/*T*/
/*T*/	typedef struct Later {
/*T*/	} Later;
/*T*/
/*T*/	typedef struct Scalar_Expression {
/*T*/		struct Symbol *Symbol;
/*T*/		Scalar *Scalar;
		struct Point_In_Time *Point_In_Time;
/*T*/	} Scalar_Expression;
/*T*/
/*T*/	typedef struct Combination {
/*T*/		struct Combinor *Combinor;
/*T*/		struct Combination *Combination;
/*T*/		struct Combinator *Combinator;
/*T*/	} Combination;
/*T*/
/*T*/	typedef struct Combinor {
/*T*/		struct Combinand *Combinand;
/*T*/		struct Combinator *Combinator;
/*T*/		struct Combinor *Combinor;
/*T*/	} Combinor;
/*T*/
/*T*/	typedef struct Combinand {
/*T*/		struct Symbol *Symbol;
/*T*/		struct Expiration *Expiration;
/*T*/		struct Scalar_Comparison *Scalar_Comparison;
/*T*/		struct Negation *Negation;
/*T*/		struct Existence *Existence;
/*T*/		struct Point_In_Time *Point_In_Time;
/*T*/	} Combinand;
/*T*/
/*T*/	typedef struct Combinator {
/*T*/		struct Or_ *Or_;
/*T*/		struct And *And;
/*T*/		struct Neither *Neither;
/*T*/		struct Nor *Nor;
/*T*/	} Combinator;
/*T*/
/*T*/	typedef struct Or_ {
/*T*/	} Or_;
/*T*/
/*T*/	typedef struct And {
/*T*/	} And;
/*T*/
/*T*/	typedef struct Neither {
/*T*/	} Neither;
/*T*/
/*T*/	typedef struct Nor {
/*T*/	} Nor;
/*T*/
/*T*/	typedef struct Existence {
/*T*/		struct Symbol *Symbol;
/*T*/		struct Contract *Contract;
/*T*/		struct Equal *Equal;
/*T*/		struct Be *Be;
/*T*/		struct Being *Being;
/*T*/		struct True *True;
/*T*/	} Existence;
/*T*/
/*T*/	typedef struct Negation {
/*T*/		struct Negator *Negator;
/*T*/		struct Symbol *Symbol;
/*T*/		struct Contract *Contract;
/*T*/	} Negation;
/*T*/
/*T*/	typedef struct Negator {
/*T*/		struct Be *Be;
/*T*/	} Negator;
/*T*/
/*T*/	typedef struct Being {
/*T*/	} Being;
/*T*/
/*T*/	typedef struct True {
/*T*/	} True;
/*T*/
/*T*/	typedef struct Article {
/*T*/	} Article;
/*T*/
/*T*/	typedef struct Point_In_Time {
/*T*/		struct Current_Time *Current_Time;
/*T*/		struct Relative_Time *Relative_Time;
/*T*/	} Point_In_Time;
/*T*/
/*T*/	typedef struct Current_Time {
/*T*/	} Current_Time;
/*T*/
/*T*/	typedef struct Relative_Time {
/*T*/		struct Duration *Duration;
/*T*/		struct Symbol *Symbol;
/*T*/	} Relative_Time;
/*T*/
/*T*/	typedef struct Duration {
/*T*/		struct Scalar_Expression *Scalar_Expression;
/*T*/		struct Time_Unit *Time_Unit;
/*T*/	} Duration;
/*T*/
/*T*/	typedef struct Time_Unit {
/*T*/		struct Years *Years;
/*T*/		struct Months *Months;
/*T*/		struct Weeks *Weeks;
/*T*/		struct Days *Days;
/*T*/		struct Hours *Hours;
/*T*/		struct Minutes *Minutes;
/*T*/		struct Seconds *Seconds;
/*T*/		struct Milliseconds *Milliseconds;
/*T*/	} Time_Unit;
/*T*/
/*T*/
/*T*/	typedef struct Years {
/*T*/	} Years;
/*T*/
/*T*/	typedef struct Months {
/*T*/	} Months;
/*T*/
/*T*/	typedef struct Weeks {
/*T*/	} Weeks;
/*T*/
/*T*/	typedef struct Days {
/*T*/	} Days;
/*T*/
/*T*/	typedef struct Hours {
/*T*/	} Hours;
/*T*/
/*T*/	typedef struct Minutes {
/*T*/	} Minutes;
/*T*/
/*T*/	typedef struct Seconds {
/*T*/	} Seconds;
/*T*/
/*T*/	typedef struct Milliseconds {
/*T*/	} Milliseconds;
/*T*/
/*T*/	typedef struct Expiration {
/*T*/	} Expiration;
/*T*/
	static void insert_parameter_and_set_member(char **production, char **instructions, Symbol *symbol, bool payment, size_t paratag, int indent, int line);

/*T*/	bool xxx_walk(char **production) {
/*T*/		if(!root) return false;
/*T*/		return xxx_document(production, root, 0);
/*T*/	}

	static Name *class = null;
	static bool main_constructor_body = true;
	static bool covenant_constructor_body = false;
	static bool recital_of_terms = false;
/*T*/	bool xxx_name(char **production, Name *Name, int indent) {
/*T*/		if(!Name) return false;

		/* put '_' to names that are target language keywords */ ///// incomplete list
		char *safe = SAFE(LOW(snake_spaced(Name))); ///// don't store LOW buffer
		if(!in(functions, Name)) {
/*JS */			padcat(0, 0, production, in(globals, Name) && !main_constructor_body?"main.":"this.", safe);
/*Sol*/			padcat(0, 0, production, safe);
/*Sop*/			padcat(0, 0, production, in(globals, Name) && !miller?"state.":"", safe);
		} else {
			bind *bind = register_bind(safe);
/*JS */			padcat(0, 0, production, in(globals, Name) && !main_constructor_body?"main.":"this.", bind->tag);
/*Sol*/			padcat(0, 0, production, bind->tag);
/*Sop*/			padcat(0, 0, production, in(globals, Name) && !miller?"state.":"", bind->tag);
		}
/*T*/		return true;
/*T*/	}

/*T*/	bool xxx_description(char **production, Description *Description, int indent) {
/*T*/		if(!Description) return false;
/*T*/		padcat(0, 0, production, "\"", Description, "\"");
/*T*/		return true;
/*T*/	}

/*T*/	bool xxx_scalar(char **production, Scalar *Scalar, int indent) {
/*T*/		if(!Scalar) return false;
/*T*/		padcat(0, 0, production, Scalar);
/*T*/		return true;
/*T*/	}

/*T*/	bool xxx_hex(char **production, Hex *Hex, int indent) {
/*T*/		if(!Hex) return false;
/*T*/		padcat(0, 0, production, Hex);
/*T*/		return true;
/*T*/	}

static const char *lexsymtype(Symbol *symbol);

/* AST walk (stub) functions */

/*T*/	bool xxx_document(char **production, Document *Document, int indent);
/*T*/	bool xxx_head(char **production, Head *Head, int indent);
/*T*/	bool xxx_lex(char **production, Lex *Lex, int indent);
/*T*/	bool xxx_lexon(char **production, Lexon *Lexon, int indent);
/*T*/	bool xxx_authors(char **production, Authors *Authors, int indent);
/*T*/	bool xxx_comment(char **production, Comment *Comment, int indent);
/*T*/	bool xxx_preamble(char **production, Preamble *Preamble, int indent);
/*T*/	bool xxx_terms(char **production, Terms *Terms, int indent);
/*T*/	bool xxx_covenants(char **production, Covenants *Covenants, int indent);
/*T*/	bool xxx_covenant(char **production, Covenant *Covenant, int indent);
/*T*/	bool xxx_provisions(char **production, Provisions *Provisions, int indent);
/*T*/	bool xxx_definitions(char **production, Definitions *Definitions, int indent);
/*T*/	bool xxx_definition(char **production, Definition *Definition, int indent);
/*T*/	bool xxx_placeholder(char **production, Placeholder *Placeholder, int indent);
/*T*/	bool xxx_type(char **production, Type *Type, int indent);
/*T*/	bool xxx_person(char **production, Person *Person, int indent);
/*T*/	bool xxx_amount(char **production, Amount *Amount, int indent);
/*T*/	bool xxx_time(char **production, Time *Time, int indent);
/*T*/	bool xxx_binary(char **production, Binary *Binary, int indent);
/*T*/	bool xxx_text(char **production, Text *Text, int indent);
/*T*/	bool xxx_data(char **production, Data *Data, int indent);
/*T*/	bool xxx_this(char **production, This *This, int indent);
/*T*/	bool xxx_clauses(char **production, Clauses *Clauses, int indent);
/*T*/	bool xxx_clause(char **production, Clause *Clause, int indent);
/*T*/	bool xxx_body(char **production, Body *Body, int indent);
/*T*/	bool xxx_function(char **production, Function *Function, int indent);
/*T*/	bool xxx_statements(char **production, Statements *Statements, int indent);
/*T*/	bool xxx_statement(char **production, Statement *Statement, int indent);
/*T*/	bool xxx_actions(char **production, Actions *Actions, int indent);
/*T*/	bool xxx_action(char **production, Action *Action, int indent);
/*T*/	bool xxx_subject(char **production, Subject *Subject, int indent);
/*T*/	bool xxx_symbols(char **production, Symbols *Symbols, int indent);
/*T*/	bool xxx_symbol(char **production, Symbol *Symbol, int indent);
	bool xxx_noun(char **production, Symbol *Symbol, int indent);
/*T*/	bool xxx_catena(char **production, Catena *Catena, int indent);
/*T*/	bool xxx_object(char **production, Object *Object, int indent);
/*T*/	bool xxx_reflexive(char **production, Reflexive *Reflexive, int indent);
/*T*/	bool xxx_contract(char **production, Contract *Contract, int indent);
/*T*/	bool xxx_predicates(char **production, Predicates *Predicates, int indent);
/*T*/	bool xxx_predicate(char **production, Predicate *Predicate, int indent);
/*T*/	bool xxx_permission(char **production, Permission *Permission, int indent);
/*T*/	bool xxx_certification(char **production, Certification *Certification, int indent);
/*T*/	bool xxx_certify(char **production, Certify *Certify, int indent);
/*T*/	bool xxx_declaration(char **production, Declaration *Declaration, int indent);
/*T*/	bool xxx_declare(char **production, Declare *Declare, int indent);
/*T*/	bool xxx_filing(char **production, Filing *Filing, int indent);
/*T*/	bool xxx_file(char **production, File *File, int indent);
/*T*/	bool xxx_registration(char **production, Registration *Registration, int indent);
/*T*/	bool xxx_register(char **production, Register *Register, int indent);
/*T*/	bool xxx_grantment(char **production, Grantment *Grantment, int indent);
/*T*/	bool xxx_grant(char **production, Grant *Grant, int indent);
/*T*/	bool xxx_appointment(char **production, Appointment *Appointment, int indent);
/*T*/	bool xxx_appoint(char **production, Appoint *Appoint, int indent);
/*T*/	bool xxx_fixture(char **production, Fixture *Fixture, int indent);
/*T*/	bool xxx_fix(char **production, Fix *Fix, int indent);
/*T*/	bool xxx_setting(char **production, Setting *Setting, int indent);
/*T*/	bool xxx_illocutor(char **production, Illocutor *Illocutor, int indent);
/*T*/	bool xxx_be(char **production, Be *Be, int indent);
/*T*/	bool xxx_payment(char **production, Payment *Payment, int indent);
/*T*/	bool xxx_pay(char **production, Pay *Pay, int indent);
/*T*/	bool xxx_preposition(char **production, Preposition *Preposition, int indent);
/*T*/	bool xxx_escrow(char **production, Escrow *Escrow, int indent);
/*T*/	bool xxx_from_escrow(char **production, From_Escrow *From_Escrow, int indent);
/*T*/	bool xxx_sending(char **production, Sending *Sending, int indent);
/*T*/	bool xxx_send(char **production, Send *Send, int indent);
/*T*/	bool xxx_notification(char **production, Notification *Notification, int indent);
/*T*/	bool xxx_notify(char **production, Notify *Notify, int indent);
/*T*/	bool xxx_termination(char **production, Termination *Termination, int indent);
/*T*/	bool xxx_terminate(char **production, Terminate *Terminate, int indent);
/*T*/	bool xxx_flagging(char **production, Flagging *Flagging, int indent);
/*T*/	bool xxx_condition(char **production, Condition *Condition, int indent);
/*T*/	bool xxx_if(char **production, If *If, int indent);
/*T*/	bool xxx_expression(char **production, Expression *Expression, int indent);
/*T*/	bool xxx_scalar_comparison(char **production, Scalar_Comparison *Scalar_Comparison, int indent);
/*T*/	bool xxx_comparison_operator(char **production, Comparison_Operator *Comparison_Operator, int indent);
/*T*/	bool xxx_equal(char **production, Equal *Equal, int indent);
/*T*/	bool xxx_later(char **production, Later *Later, int indent);
/*T*/	bool xxx_scalar_expression(char **production, Scalar_Expression *Scalar_Expression, int indent);
/*T*/	bool xxx_combination(char **production, Combination *Combination, int indent);
/*T*/	bool xxx_combinor(char **production, Combinor *Combinor, int indent);
/*T*/	bool xxx_combinand(char **production, Combinand *Combinand, int indent);
/*T*/	bool xxx_combinator(char **production, Combinator *Combinator, int indent);
/*T*/	bool xxx_or_(char **production, Or_ *Or_, int indent);
/*T*/	bool xxx_and(char **production, And *And, int indent);
/*T*/	bool xxx_neither(char **production, Neither *Neither, int indent);
/*T*/	bool xxx_nor(char **production, Nor *Nor, int indent);
/*T*/	bool xxx_existence(char **production, Existence *Existence, int indent);
/*T*/	bool xxx_negation(char **production, Negation *Negation, int indent);
/*T*/	bool xxx_negator(char **production, Negator *Negator, int indent);
/*T*/	bool xxx_being(char **production, Being *Being, int indent);
/*T*/	bool xxx_true(char **production, True *True, int indent);
/*T*/	bool xxx_article(char **production, Article *Article, int indent);
/*T*/	bool xxx_point_in_time(char **production, Point_In_Time *Point_In_Time, int indent);
/*T*/	bool xxx_current_time(char **production, Current_Time *Current_Time, int indent);
/*T*/	bool xxx_relative_time(char **production, Relative_Time *Relative_Time, int indent);
/*T*/	bool xxx_duration(char **production, Duration *Duration, int indent);
/*T*/	bool xxx_time_unit(char **production, Time_Unit *Time_Unit, int indent);
/*T*/	bool xxx_years(char **production, Years *Years, int indent);
/*T*/	bool xxx_months(char **production, Months *Months, int indent);
/*T*/	bool xxx_weeks(char **production, Weeks *Weeks, int indent);
/*T*/	bool xxx_days(char **production, Days *Days, int indent);
/*T*/	bool xxx_hours(char **production, Hours *Hours, int indent);
/*T*/	bool xxx_minutes(char **production, Minutes *Minutes, int indent);
/*T*/	bool xxx_seconds(char **production, Seconds *Seconds, int indent);
/*T*/	bool xxx_milliseconds(char **production, Milliseconds *Milliseconds, int indent);
/*T*/	bool xxx_expiration(char **production, Expiration *Expiration, int indent);

static bool is_payment(Predicates *predicates) {
	while(predicates) {
		if(predicates->Predicate->Payment)
			return true;
		predicates = predicates->Predicates;
	}
	return false;
}

/* AST walk functions ----------------------------------------------------- */

/*J+S*/	static char *requires = "";
	static char *module = null;
	static bind *current_function = null;
	static bool single_sentence_clause = true;
	static bool no_literal = false;
	static char *msg_sender = null;
	static char *msg_value = null;
	static bool is_payable = false;
	static char *inference = null;
/*S+S*/	static bool is_stateful = false;
	static char *parameters = null;
	static char *arguments = null;
	static char *parameta = null;
	static char *emits = null;
	static char *caller = null;
	static size_t paratag = -1;
	static int preass_indent = 0;
	static Action *action = null;
	static char *first_amount = null;
	static char *class_lists = null;
	static char *instance = null;
	static char *adders = null;
	static char *restorers = null;

/*JS */	static char *instructions =
/*JS */		"\n\n   INSTRUCTIONS FOR USE:\n\n"
/*JS */		"   Execute this program using node. Replace the <parameters> with literal values.\n\n"
/*JS */		"   Running this program as-is requires beginners programmer knowledge. This phase is\n"
/*JS */		"   yet not covered by lexon's mission to make code readable and useful for non-coders.\n"
/*JS */		"   In the future, an interface will be generated to complete this last mile. However,\n"
/*JS */		"   embedding this code into a self-explanatory user interface is a straight forward\n"
/*JS */		"   task for a full-stack programmer.\n\n"
/*JS */		"   Note that the instructions below reflect your lexon code as well as the parameters\n"
/*JS */		"   used during compilation of the code: different functions and parameters will result\n"
/*JS */		"   from different input. Some functions are 'built-in' but only appear when needed as\n"
/*JS */		"   per compiled-in features – a list of which is available with lexon -h. The functions\n"
/*JS */		"   are not given in a specific order of execution but as listed in the lexon source.\n\n"
/*JS */		"%00%"
/*JS */		"   Parameters below are marked with double angle brackets << >> for the respective\n"
/*JS */		"   required caller. If the role is defined earlier, it can only be performed by this\n"
/*JS */		"   person. (But remember that this entire setup is trustful: anyone can manipulate\n"
/*JS */		"   anything about this contract. Though they cannot sign it or change the signed log.)\n"
/*JS */		"   If the role is not defined earlier, the call makes the role be assigned to the\n"
/*JS */		"   person named for the call. Some functions can be called without naming a caller.\n"
/*JS */		"   Some clauses of the original lexon source will not appear below. Namely, those\n"
/*JS */		"   that have no permission phrase, wherefore they are regarded as internal.\n\n"
/*JS */		"   The main contract system is initialized by loading the module and instantiating:\n\n"
/*JS */		"   $ node\n"
/*JS */		"   > contract = require(\"./%4%\");\n"
/*JS */		"   > %contract% = new contract(%6%);\n\n"
/*JS */		"   Remember to reset node's module cache each time you edit and recompile your code:\n\n"
/*JS */		"   > delete require.cache[require.resolve('./%4%')];\n\n"
/*JS */		"   These are the state progress functions that allow to interact with the contract:\n"
/*JS */		;

/*Sol*/	static char *instructions =
/*Sol*/		"\n\n   INSTRUCTIONS FOR USE:\n\n"
/*Sol*/		"   Deploy this smart contract to the Ethereum blockchain or Goerli testchain.  Replace\n"
/*Sol*/		"   the <parameters> with literal values to interact with the contract via terminal.\n\n"
/*Sol*/		"   Note that the instructions below reflect your lexon code, as well as the parameters\n"
/*Sol*/		"   used during compilation of the code: different functions and parameters will result\n"
/*Sol*/		"   from different input.  Some functions are 'built-in' but only appear when needed as\n"
/*Sol*/		"   per compiler options used during compilation  –  a list of which, is available with\n"
/*Sol*/		"   lexon -h.  The functions are given in the order of appearance, in the lexon source.\n\n"
/*Sol*/		"   The required caller is noted in double angle brackets << >>.  Some functions can be\n"
/*Sol*/		"   called by anyone.  Note that roles are being defined by using an address for it for\n"
/*Sol*/		"   the first time. This will require for the same address to be used for the same role\n"
/*Sol*/		"   after this point. Else, the call will revert.\n\n"
/*Sol*/		"   Some clauses of the original lexon source text do not appear in the comments below.\n"
/*Sol*/		"   Namely, those without permission phrase, wherefore they are regarded as internal.\n\n"
/*Sol*/		"   These are the constructor parameters for deployment:\n\n"
/*Sol*/		"   %6%\n\n"
/*Sol*/		"   These are the state progress functions that allow to interact with the contract:\n"
/*Sol*/		;

/*Sop*/	static char *instructions =
/*Sop*/		"\n\n   INSTRUCTIONS FOR USE:\n\n"
/*Sop*/		"   Deploy this smart contract to the Aeternity blockchain or testchain. An easy way to\n"
/*Sop*/		"   get started is to copy-paste this code into  https://studio.aepps.com.  Replace the\n"
/*Sop*/		"   <parameters> with literal values to interact with the contract via terminal.\n\n"
/*Sop*/		"   LIKE ALL SMART CONTRACTS THIS CODE MUST BE AUDITED BEFORE USING IT IN PRODUCTION.\n\n"
/*Sop*/		"   Note  that the instructions below  reflect your Lexon code,  as well as the options\n"
/*Sop*/		"   used during compilation of the code: different clauses and options will result from\n"
/*Sop*/		"   different input code.  Some functions are 'built-in' but only appear when needed as\n"
/*Sop*/		"   per compiler options used  during compilation – a list of options is available with\n"
/*Sop*/		"   lexon -h.  The functions are given in the order of appearance, in the Lexon source.\n\n"
/*Sop*/		"   The required caller is noted in double angle brackets << >>.  Some functions can be\n"
/*Sop*/		"   called by anyone.  Note that roles are being defined by using an account for it for\n"
/*Sop*/		"   the first time. This will require for the same account to be used for the same role\n"
/*Sop*/		"   after this point. Else, the call will revert, i.e. cancelled and not go through.\n\n"
/*Sop*/		"   Some clauses of the original Lexon source text do not appear in the comments below.\n"
/*Sop*/		"   Namely, those without permission phrase, wherefore they are regarded as internal.\n\n"
/*Sop*/		"   These are the constructor parameters for deployment. If you are using Aestudio, the\n"
/*Sop*/		"   fields under the deploy button are where your values for them go before deploying.\n\n"
/*Sop*/		"   %6%\n\n"
/*Sop*/		"   These are the state progress functions that allow to interact with the contract:\n"
/*Sop*/		;

	static bool enforce_same_subject = false;
	static list *active_subjects = null;
	static bool no_action_in_group_yet = true;
	static bool uses_termination = false;
	static bool uses_pay = false;
	static bool uses_send = false;
/*S+S*/	static bool uses_permit = false;
	static bool has_subclasses = false;

/*T*/	bool xxx_document(char **production, Document *Document, int indent) {
/*T*/		if(!Document) return false;
/*T*/		if(opt_debug) printf("producing Document\n");

		/* switch line# trace of every concat to code output buffer */
		_concat_trace = opt_debug_production;

		/* source code head */
/*JS */		if(!opt_bare) padcat(0, indent, production, "/* Lexon-generated Javascript ");
/*Sol*/		padcat(0, indent, production, "// SPDX-License-Identifier: UNLICENSED\n");
/*Sol*/		padcat(0, indent, production, "pragma solidity ^0.8.17;\n\n");
/*Sol*/		if(!opt_bare) padcat(0, indent, production, "/* Lexon-generated Solidity code\n");
/*Sop*/		if(!opt_bare) padcat(0, indent, production, "/* Lexon-generated Sophia code");

		assert(!parameters);
		assert(!arguments);
		methods = mtrac_strdup("");
		globals = mtrac_strdup("");
		declarations = mtrac_strdup("");
		initializations = mtrac_strdup("");
		fixed = mtrac_strdup("");
		declared = mtrac_strdup("");
		class_lists = mtrac_strdup("");
		restorers = mtrac_strdup("");
		adders = mtrac_strdup("");
		parameters = mtrac_strdup("");
		arguments = mtrac_strdup("");
		parameta = mtrac_strdup("");
		emits = mtrac_strdup("");
		functions = mtrac_strdup("");
/*J+S*/		requires = mtrac_strdup(requires);

		/* instructions are being built up in parallel, eventually prepent.
		   They will be built up for naught and discarded if opt_instructions is not set. */
		instructions = mtrac_strdup(instructions);



		char *file = mtrac_strdup(opt_source ? opt_source : "contract");
		replace(&file, ".lex", "");
/*JS */		concat(&file, ".jsx");
/*Sol*/		concat(&file, ".solx");
/*Sop*/		concat(&file, ".aesx");
		replace(&instructions, "%4%", file);

		/* create a name for the instance variable */
		char *optcpy = mtrac_strdup(opt_source ? opt_source : "instance");
		char *rump = optcpy;
		if(strrchr(rump, '/') && *(strrchr(rump,'/') +1)) rump = strrchr(rump,'/') +1;
		while(*rump) {
			while(*rump && strchr("/.-0123456789", *rump)) rump++;
			if(*rump && strcspn(rump, "/.-0123456789") > 1) *(rump + strcspn(rump, "/.-0123456789")) = 0;
			else if(*rump && strcspn(rump, "/.-0123456789") == 1 && strlen(rump) > 2) { rump += 2; continue; }
			break;
		}
		char *instance_var_name = mtrac_strdup(rump?rump:"instance");
		mtrac_free(optcpy);

		/* obtain the names of the clauses */
		Clauses *clauses = !Document->Terms ? null : (!Document->Terms->Provisions ? null : Document->Terms->Provisions->Clauses);
		while(clauses) {
			char *name = !clauses->Clause ? null : clauses->Clause->Name;
			if(name) mtrac_concat(&functions, ":", name, ":");
			clauses = clauses->Clauses;
		}

/*T*/		xxx_head(production, Document->Head, indent);

/*JS */		/* includes - depending on what is needed */
/*JS */		if(opt_log || opt_signatures || opt_persistence || opt_email) padcat(2, indent, production, "var fs = require('fs');");
/*JS */		if(opt_log && (opt_chaining || opt_signatures)) padcat(1, indent, production, "var crypto = require('crypto');");
/*JS */		if(opt_persistence) padcat(1, indent, production, "var serialize = require('serialize-javascript');");
/*JS */		if(opt_log && opt_signatures) padcat(1, indent, production, "var prompt = require('prompt-sync')();");
/*JS */		if(opt_bundle) padcat(1, indent, production, "var tar = require('tar');");
/*JS */		if(opt_email) padcat(1, indent, production, "var nodemailer = require('nodemailer');");
/*JS */		if(opt_log && opt_signatures) padcat(1, indent, production, "var last_caller;");
/*JS */		if(opt_log && opt_signatures) padcat(1, indent, production, "var last_passphrase;");

/*Sop*/		/* source code head (Sop) */
/*Sop*/		padcat(2, 0, production, "@compiler >=6");
/*Sop*/		if(opt_harden) padcat(2, 0, production, "include \"Option.aes\"");

		/* comments */
		if(opt_comment) {
			padcat(2, indent, production, "/**");
			padcat(1, indent, production, " **");
			padcat(1, indent, production, " ** Main ", module, " contract system");
			padcat(1, indent, production, " **");
			padcat(1, indent, production, " **/");
		}

		if(opt_comment || opt_lexon_comments) {
			padcat(1, 0, production, "");
		}

		if(opt_lexon_comments) {
			char *c = mtrac_strdup(get_lexcom("start"));
			replace(&c, "\n", "\n *\t");
			replace(&c, "\n *\t\n", "\n *\n");
			padcat(1, 0, production, "/** ", c, "\n**/");
			mtrac_free(c);
		}

		paratag = strlen(*production);
		if(!opt_bare) padcat(2, indent, production, "");
/*JS */		padcat(0, indent, production, "module.exports = class ", camel_spaced(module), " {%21%"); // %21%: member initialization by parameters
/*JS */		padcat(1, indent+1, production, "constructor(%1%) {"); // sic not C
/*JS */		padcat(1, 0, production, "%20%"); // %20%: closure 'main = this'
/*Sol*/		padcat(0, indent, production, "contract ", camel_spaced(module), " {\n%27%\n"); // %27%: member declaration
/*Sol*/		padcat(1, indent+1, production, "%29%constructor(%1%) %28%{"); // %29%: emits, %1%: constructor parameters, sol %28%: payable
/*Sop*/		padcat(2, indent, production, "main contract ", camel_spaced(module), " =");
/*Sop*/		padcat(2, indent+1, production, "record state = {");
/*Sop*/		padcat(0, indent  , production, "%27%"); // %27%: member declaration
/*Sop*/		padcat(1, indent+2, production, "}\n");
/*Sop*/		padcat(1, indent+1, production, "%29%entrypoint init(%1%) = {%32%"); // %29%: emits, %1%: constructor parameters, %32%: initializations
/*Sop*/		padcat(1, indent+2, production, "}\n");

		main_constructor_body = true;
		enforce_same_subject = true;
		assert(active_subjects == null);
/*T*/		xxx_terms(production, Document->Terms, indent+2); // sets caller, uses methods variable for production string
		main_constructor_body = false;
		enforce_same_subject = false;

		/* inject catch of non-permissioned caller in constructor wrapper ///// what happened to this case
		char *perm = mtrac_strdup("");
		char *close = mtrac_strdup("");
		produce_access_conditions(1, indent, &perm, active_subjects);
		if(strlen(perm)) padcat(1, indent, &close, "}");
		replace(production, "%15%", perm);
		replace(production, "%16%", close);
		mtrac_free(perm);
		mtrac_free(close);
*/		delete_list(active_subjects);
		active_subjects = null;

/*S+S*/		/* sol, sop: end of main constructor */
/*Sol*/		padcat(1, indent+1, production, "}%34%"); // %34% adders
/*S+S*/		replace(production, "%1%", parameters); ////// can this line go?

/*S+S*/		padcat(0,0, production, "%31%"); // %31%: auxiliary functions

/*S+S*/		/* sol,sop: add the general terms methods beneath the constructor */
/*S+S*/		padcat(1, 0, production, methods);

/*S+S*/		/* sol, sop: end of main class (sop: by indent) */
/*Sol*/		padcat(1, indent, production, "}");

/*JS */		/* covenants
/*JS */		   js: like all non-covenant clauses, the entire covenant class definition including all their clauses,
/*JS */		   are hidden in the scope of the main, top level constructor */
/*JS */		xxx_covenants(production, Document->Covenants, indent+2);
/*S+S*//*T*/	xxx_covenants(production, Document->Covenants, indent);

/*JS */		/* note this must follow after the class definitions, to be able to use the main_constructor_bodys in `restorers` */
/*JS */		if(opt_persistence) {
/*JS */			if(opt_comment) padcat(2, indent+2, production, "/* restore object from file - must be below class definition */");
/*JS */			padcat(C, indent+2, production, "if(typeof ", caller, " === 'undefined') {");
/*JS */ 		padcat(1, indent+3, production, "console.log(\"> restore from file '", opt_persistence, "'\");");
/*JS */ 		padcat(1, indent+3, production, "var data = fs.readFileSync('", opt_persistence, "', ()=>{});");
/*JS */ 		padcat(1, indent+3, production, "var live = eval('(' + data + ')');");
/*JS */ 		padcat(1, indent+3, production, "Object.assign(this, live);");
/*JS */ 		if(restorers && strlen(restorers)) padcat(1, indent+3, production, restorers);
/*JS */ 		padcat(1, indent+2, production, "}");
/*JS */		}

/*JS */		/* end of constructor */
/*JS */		padcat(1, indent+1, production, "}");

		/* aux functions to add a new sub object instance (covenants) */
/*JS */		if(strlen(adders)) padcat(0, 0, production, adders);
/*S+S*/		replace(production, "%34%", adders);

/*JS */		/* js: now add the general terms methods beneath the constructor */
/*JS */		padcat(1, 0, production, methods);

		/* AUXILIARY FUNCTIONS */
		char *auxfuncs = mtrac_strdup("");

/*JS */		/* contract history from log */
/*JS */		if(opt_log) {
/*JS */
/*JS */			padcat(2, 0, &instructions, "   state changes of the contract can be listed, e.g. actions performed by\n"
/*JS */						    "   a party to it, or agents who are assigned privileges. In case hash chains\n"
/*JS */						    "   or signatures are used, they are visible in this log. The log is stored in\n"
/*JS */						    "   in the file '", opt_log, "'.");
/*JS */			padcat(2, 0, &instructions, "   > %contract%.history()");
/*JS */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs,
/*JS */				"/* built-in convenience function to view state change log. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "history() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "fs.readFile(this.logname, (e,d)=>{console.log(d.toString())});");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */		}

/*JS */		/* persistence */
/*JS */		if(opt_persistence) {
/*JS */
/*JS */			padcat(2, 0, &instructions, "   The complete contract state can be saved to disk and re-loaded at a\n"
/*JS */						    "   later point in time. This serves to continue work after stopping and\n"
/*JS */						    "   restarting node; or to send the entire contract system and its current\n"
/*JS */						    "   state - which can include hashes and signatures - to another party,\n"
/*JS */						    "   who may perform the next steps.");
/*JS */			padcat(2, 0, &instructions, "   > %contract%.persist()");
/*JS */			padcat(1, 0, &instructions, "   > %contract%.load()");
/*JS */			padcat(1, 0, &requires,     "   $ npm install serialize-javascript");
/*JS */
/*JS */			/* contract state saving to file */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs,
/*JS */				"/* built-in serialization and storage of entire contract system state. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "persist() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "console.log('> persisting');");
/*JS */			padcat(1, indent+2, &auxfuncs, "var data = serialize(this, {space: 4});");
/*JS */			padcat(1, indent+2, &auxfuncs, "fs.writeFileSync('", opt_persistence, "', data, ()=>{});");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */
/*JS */			/* contract state loading from file */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs,
/*JS */				"/* re-instate entire contract system from serialized file store */");
/*JS */			padcat(C, indent+1, &auxfuncs, "static load() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "return new ", camel_spaced(module), "();");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */
/*JS */		}

/*JS */		/* bundle */
/*JS */		if(opt_bundle) {
/*JS */
/*JS */			padcat(2, 0, &instructions, "   The contract code, state and log can be bundled into one file to exchange\n"
/*JS */						    "   or archive it:");
/*JS */			padcat(2, 0, &instructions, "   > %contract%.bundle()");
/*JS */			padcat(1, 0, &instructions, "   > %contract%.unbundle()");
/*JS */			padcat(1, 0, &requires,     "   $ npm install tar");
/*JS */
/*JS */			/* contract bundling */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in tar-balling of code, log and state. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "bundle() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "console.log('> bundling into ", opt_bundle, "');");
/*JS */			padcat(1, indent+2, &auxfuncs, "tar.create({gzip:true, file:'", opt_bundle, "'}, "
/*JS */					"['", opt_source, "', '", file, "', '", opt_persistence, "', '", opt_log, "', 'INSTRUCTIONS.TXT']);");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */
/*JS */			/* contract unbundling */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in untar-balling of code, log and state. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "static unbundle() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "console.log('> unbundling ", opt_bundle, "');");
/*JS */			padcat(1, indent+2, &auxfuncs, "tar.extract('", opt_bundle, "');");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */		}

/*JS */		/* email */
/*JS */		if(opt_email) {
/*JS */
/*JS */			padcat(2, 0, &instructions, "   The contract code, state and log can be sent to a counterparty. This\n"
/*JS */						    "   requires configuring an email account in the file '", opt_email, "'.");
/*JS */			padcat(2, 0, &instructions, "   > %contract%.send()");
/*JS */			padcat(1, 0, &requires,     "   $ npm install nodemailer");
/*JS */
/*JS */			/* contract bundling */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in email sending of code, log and state. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "send() {");
/*JS */			padcat(2, indent+2, &auxfuncs, "this.persist();");
/*JS */			padcat(1, indent+2, &auxfuncs, "this.bundle();");
/*JS */			padcat(2, indent+2, &auxfuncs, "console.log('> sending via email');");
/*JS */			padcat(1, indent+2, &auxfuncs, "var receiver = prompt('enter receiver address: ');");
/*JS */			padcat(2, indent+2, &auxfuncs, "var config = fs.readFileSync('", opt_email, "', ()=>{});");
/*JS */ 			padcat(1, indent+2, &auxfuncs, "var email = eval('(' + config + ')').email;");
/*JS */ 			padcat(1, indent+2, &auxfuncs, "console.log(email);");
/*JS */
/*JS */ 			padcat(2, indent+2, &auxfuncs, "var transporter = nodemailer.createTransport({");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "service: email.service,");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "auth: { user: email.user, pass: email.pass }});");
/*JS */
/*JS */ 			padcat(2, indent+2, &auxfuncs, "var mailOptions = {");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "from: email.from,");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "to: receiver,");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "subject: email.subject,");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "text: email.text,");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "attachments: { path: './", opt_bundle, "', contentType: 'application/gzip' }};");
/*JS */
/*JS */ 			padcat(2, indent+2, &auxfuncs, "transporter.sendMail(mailOptions, function(error, info){");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "if (error) {");
/*JS */ 			padcat(1, indent+4, &auxfuncs, "console.log(error);");
/*JS */ 			padcat(1, indent+3, &auxfuncs, "} else {");
/*JS */ 			padcat(1, indent+4, &auxfuncs, "console.log('> email sent: ' + info.response); }});");
/*JS */
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */		}

		/* #terminate() - contract termination */
		if(uses_termination) {
			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in termination of the entire contract system */");
/*JS */			padcat(C, indent+1, &auxfuncs, /* "#" */ "termination(", (opt_log || opt_feedback)?"caller":"", ") {");
/*JS */			padcat(1, indent+2, &auxfuncs, "this.terminated = true;"); // [3]
/*JS */			if(opt_log || opt_feedback) padcat(1, indent+2, &auxfuncs, (!class?"this":"main"), ".log(caller, '■ contract system terminated');");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*Sol*/			padcat(C, indent+1, &auxfuncs, "function termination() internal {");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "terminated = true;");
/*Sol*/			padcat(1, indent+1, &auxfuncs, "}");
/*Sop*/			padcat(C, indent+1, &auxfuncs, "stateful function termination() =", EOL);
/*Sop*/			padcat(1, indent+2, &auxfuncs, "put(state{terminated = true})", EOL);

/*JS */			padcat(2, indent+1, &auxfuncs, "already_terminated() {");
/*JS */			padcat(1, indent+2, &auxfuncs, "if(!this.terminated) return false;");
/*JS */			if(opt_log || opt_feedback) padcat(1, indent+2, &auxfuncs, "console.log('✕ contract system previously terminated');");
/*JS */			padcat(1, indent+2, &auxfuncs, "return true;");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*Sol*/			padcat(2, indent+1, &auxfuncs, "function check_termination() internal view {");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "require(!terminated, \"contract system terminated before\");");
/*Sol*/			padcat(1, indent+1, &auxfuncs, "}");
/*Sop*/			padcat(2, indent+1, &auxfuncs, "function check_termination() =");
/*Sop*/			padcat(1, indent+2, &auxfuncs, "require(!state.terminated, \"contract system terminated before\")");
		}

/*JS */		/* log() - log function, with optionally hash chain and signatures */
/*JS */		if(opt_log /* /////// || opt_feedback */) {
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in logging of state changes. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "log(caller, msg) {");
/*JS */		}

/*JS */		/////// should be unnecesary. log() is not used but console.log is produced everywhere if !opt_log
/*JS */		if(opt_feedback)
/*JS */			/* to console */
/*JS */			padcat(1, indent+2, &auxfuncs, "console.log(msg);");

/*JS */		if(opt_log) {
/*JS */			padcat(1, indent+2, &auxfuncs, "let stamp = (new Date()).toLocaleString('en-US');");
/*JS */
/*JS */			/* sign log entry */
/*JS */			if(opt_signatures) {
/*JS */				padcat(1, 0, &requires,         "   $ npm install prompt-sync");
/*JS */
/*JS */				padcat(1, indent+2, &auxfuncs, "var entry = `⌽  ${stamp} ✦ ${caller} ${msg}`;");
/*JS */				padcat(1, indent+2, &auxfuncs, "var passphrase = this.sync_passphrase(caller);");
/*JS */				padcat(1, indent+2, &auxfuncs, "var pem = fs.readFileSync(caller + '.key');");
/*JS */				padcat(1, indent+2, &auxfuncs, "var key = pem.toString('ascii');");
/*JS */				padcat(1, indent+2, &auxfuncs, "var sign = crypto.createSign('RSA-SHA256');");
/*JS */				padcat(1, indent+2, &auxfuncs, "sign.update(entry);");
/*JS */				padcat(1, indent+2, &auxfuncs, "var sig = sign.sign({ key: key, passphrase: passphrase }, 'hex');");
/*JS */				padcat(1, indent+2, &auxfuncs, "fs.appendFileSync(this.logname, `${entry} ❈ ${sig}\\n`);");
/*JS */			} else {
/*JS */				padcat(1, indent+2, &auxfuncs, "fs.appendFileSync(this.logname, `${stamp} ${caller} ${msg}\\n`);");
/*JS */			}
/*JS */
/*JS */			/* hash goes into beginning of next line */
/*JS */			if(opt_chaining) {
/*JS */				padcat(1, indent+2, &auxfuncs, "let pay = fs.readFileSync(this.logname);");
/*JS */				padcat(1, indent+2, &auxfuncs, "let hash = crypto.createHash('sha256').update(pay);");
/*JS */				padcat(1, indent+2, &auxfuncs, "fs.appendFileSync(this.logname, '⧉ ' + hash.digest('hex').substr(0, ", str(opt_chaining), ") + \" \");");
/*JS */			}
/*JS */		}
/*JS */		if(opt_log || opt_feedback)
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */
/*JS */		/* passphrase input and cache */
/*JS */		if(opt_log && opt_signatures) {
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in password query for private key file, with cache. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "sync_passphrase(caller) {");
/*JS */			padcat(1, indent+2, &auxfuncs, "if(!caller) process.exit('no caller information');");
/*JS */			padcat(1, indent+2, &auxfuncs, "if(caller == last_caller) return last_passphrase;");
/*JS */			padcat(1, indent+2, &auxfuncs, "last_caller = caller;");
/*JS */			padcat(1, indent+2, &auxfuncs, "return last_passphrase = prompt('enter pass phrase for ' + caller + ': ', {echo: ''});");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */		}
/*JS */
/*JS */		/* service to create demo keys */
/*JS */		if(opt_log && opt_signatures) {
/*JS */
/*JS */			padcat(2, 0, &instructions, "   Keys for signing log entries are expected on-file, by default named after\n"
/*JS */						    "   the actor, with the extension .key. For demo purposes, key files can be\n"
/*JS */						    "   created using this utility function:");
/*JS */			padcat(2, 0, &instructions, "   > %contract%.create_key(name, passphrase)");
/*JS */
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in convenience function to create keys for users. */");
/*JS */			padcat(C, indent+1, &auxfuncs, "static create_key(name, passphrase) {");
/*JS */			padcat(1, indent+2, &auxfuncs, "const { publicKey, privateKey } =");
/*JS */			padcat(1, indent+3, &auxfuncs, "crypto.generateKeyPairSync('rsa',");
/*JS */			padcat(1, indent+4, &auxfuncs, "{ modulusLength: 2048,");
/*JS */			padcat(1, indent+5, &auxfuncs, "publicKeyEncoding: { type: 'spki', format: 'pem' },");
/*JS */			padcat(1, indent+5, &auxfuncs, "privateKeyEncoding: { type: 'pkcs8', format: 'pem', cipher: 'aes-256-cbc', passphrase: passphrase }});");
/*JS */
/*JS */			padcat(2, indent+2, &auxfuncs, "fs.writeFileSync(name+'.key', privateKey);");
/*JS */			padcat(1, indent+2, &auxfuncs, "fs.writeFileSync(name+'.pub', publicKey);");
/*JS */			padcat(1, indent+2, &auxfuncs, "return true;");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*JS */		}

		/* pay() */
		if(uses_pay) {
/*JS */			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in pay message */");
/*S+S*/			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* safe transfer */");
/*JS */			padcat(C, indent+1, &auxfuncs, "_pay(", (opt_log)?"caller, ":"", "from, to, amount) {"); ////// harmonize to 'transfer'
/*Sol*/			padcat(C, indent+1, &auxfuncs, "function transfer(address _to, uint _amount) internal {");
/*Sop*/			padcat(C, indent+1, &auxfuncs, "stateful function transfer(to : address, amount : int) =");
/*JS */			if(opt_log) padcat(1, indent+2, &auxfuncs, (!class?"this":"main"), ".log(caller, `➠ system message: pay ${amount} from ${from} to ${to}.`);");
/*JS */			else padcat(1, indent+2, &auxfuncs, "console.log(`➠ system message: pay ${amount} from ${from} to ${to}.`);");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "(bool _success, ) = _to.call{value:_amount}(\"\");");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "require(_success, \"transfer failed on receiver side\");");
/*Sop*/			padcat(1, indent+2, &auxfuncs, "Chain.spend(to, amount)");

/*JS */			/* track escrow balance */
/*JS */			padcat(1, indent+2, &auxfuncs, "if(from == 'escrow') main._escrow -= amount;");
/*JS */			padcat(1, indent+2, &auxfuncs, "if(to == 'escrow') main._escrow += amount;");
/*J+S*/			padcat(1, indent+1, &auxfuncs, "}");
		}

		/* send() - sending / emitting of a message */
		if(uses_send) {
			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in send message */");
/*JS */			padcat(C, indent+1, &auxfuncs, "_send(", (opt_log)?"caller, ":"", "from, to, message) {");
/*JS */			if(opt_log) padcat(1, indent+2, &auxfuncs, (!class?"this":"main"),
/*JS */				".log(caller, `➠ system message: send message «${message}» from ${from} to ${to}.`);");
/*JS */			else padcat(1, indent+2, &auxfuncs, "console.log(`➠ system message: send message «${message}» from ${from} to ${to}.`);");
/*JS */			padcat(1, indent+1, &auxfuncs, "}");
/*Sol*/			padcat(C, indent+1, &auxfuncs, "function send(address _to, string storage _message) internal {");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "emit Message(msg.sender, _to, _message);");
/*Sol*/			padcat(1, indent+1, &auxfuncs, "}");
/*Sol*/			padcat(0, indent+1, &emits, "event Message(");
/*Sol*/			padcat(1, indent+2, &emits, "address indexed _from,");
/*Sol*/			padcat(1, indent+2, &emits, "address indexed _to,");
/*Sol*/			padcat(1, indent+2, &emits, "string _message);");
/*Sol*/			padcat(2, indent+1, &emits, "");
/*Sop*/			padcat(C, indent+1, &auxfuncs, "function send(to : address, message : string) =");
/*Sop*/			padcat(1, indent+2, &auxfuncs, "Chain.event(Message(Call.caller, to, message))", EOL);
/*Sop*/			padcat(0, indent+1, &emits, "datatype event = Message(indexed address, indexed address, string)\n");
/*Sop*/			padcat(1, indent+1, &emits, "");
		}

/*S+S*/		/* place message structure definitions (emits) */
/*S+S*/		replace(production, "%29%", emits); ///// correct for S+S?

/*S+S*/		/* sol+sop: permit - optimized require() */
/*S+S*/		if(uses_permit) {
/*S+S*/			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in caller assertion */");
/*Sol*/			padcat(C, indent+1, &auxfuncs, "function permit(address _authorized) internal view {");
/*Sol*/			padcat(1, indent+2, &auxfuncs, "require(msg.sender == _authorized, \"not permitted\");");
/*Sol*/			padcat(1, indent+1, &auxfuncs, "}");
/*Sop*/			if(opt_harden) {
/*Sop*/				padcat(C, indent+1, &auxfuncs, "function permit(authorized : §§§address§, name : string) =");
/*Sop*/				padcat(1, indent+2, &auxfuncs, "require(Call.caller == force(authorized, name), StringInternal.concat(\"no access for \", name))");
/*Sop*/			} else {
/*Sop*/				padcat(C, indent+1, &auxfuncs, "function permit(authorized : address) =");
/*Sop*/				padcat(1, indent+2, &auxfuncs, "require(Call.caller == authorized, \"access\")");
/*Sop*/			}
/*S+S*/		}

/*Sop*/		if(opt_harden) {
/*Sop*/			if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in option type force function */");
/*Sop*/			padcat(C, indent+1, &auxfuncs, "function force(o : option('a), name : string) : 'a =");
/*Sop*/			padcat(1, indent+2, &auxfuncs, "switch(o)");
/*Sop*/			padcat(1, indent+3, &auxfuncs, "None => abort(StringInternal.concat(name, \" not fixed\"))");
/*Sop*/			padcat(1, indent+3, &auxfuncs, "Some(a) => a");
/*Sop*/		}

		/* aux functions insert - js: in place. soli+sop: higher up. */
/*JS */		padcat(0, 0, production, auxfuncs);
/*S+S*/		replace(production, "%31%", auxfuncs);
		mtrac_free(auxfuncs);

/*JS */		/* js: end of main class */
/*JS */		padcat(1, indent, production, "}");

		replace(production, "%1%", parameters);

		/* end of file */
		if(!opt_bare) padcat(2, indent, production, "/* end */\n");

		_concat_trace = false;

		/* sort out names, privacy mark (javascript: '#') and parameters */
		replace_bind_tags(production, &instructions, binds);

/*JS */		/* if needed, create 'main' variable to provide 'this' for closures */
/*JS */		char *closure_this = mtrac_strdup("");
/*JS */		if(strstr(*production, "main.")) padcat(1, indent+2, &closure_this, "let main = this;");
/*JS */		replace(production, "%20%", closure_this);
/*JS */		mtrac_free(closure_this);
/*JS */
/*JS */		char *scope_comment = mtrac_strdup("");
/*JS */		if(opt_comment && has_subclasses) {
/*JS */			padcat(2, indent+1, &scope_comment, "/* This classes constructor's is the only scope where the covenant classes exist. ");
/*JS */			padcat(1, indent+1, &scope_comment, "   This can hide them in larger contexts but requires constructor indirections. */");
/*JS */		} else {
/*JS */			padcat(1, 0, &scope_comment, "");
/*JS */		}
/*JS */		replace(production, "%21%", scope_comment);
/*JS */		mtrac_free(scope_comment);

/*S+S*/		/* take care of termination flag (js @ [3]) */
/*S+S*/		if(uses_termination) { 
/*Sol*/			padcat(1, 1, &declarations, "bool terminated = false;");
/*Sop*/			if(strlen(declarations)) padcat(0, 0, &declarations, ",");
/*Sop*/			padcat(1, 3, &declarations, "terminated : bool");
/*Sop*/			if(strlen(initializations)) padcat(0, 0, &initializations, ",");
/*Sop*/			padcat(1, 3, &initializations, "terminated = false");
/*S+S*/		}

/*S+S*/		/* sol+sop: insert declaration of member variables into constructor (sol)/contract (sop) head */
/*S+S*/		replace(production, "%27%", declarations);

/*Sop*/		/* sop: insert initializations of member variables into constructor (sop) head */
/*Sop*/		replace(production, "%32%", initializations);

		/* prepend instructions to the top - or just discard if not switched on */
		replace(&instructions, "%6%", parameta);
/*JS */		replace(&instructions, "%00%", strlen(requires) ? "   These node modules have to be installed once:\n%000%\n\n" : "");
/*JS */		replace(&instructions, "%000%", requires);
		replace(&instructions, "%contract%", instance_var_name);
		replace(production, "%0%", opt_instructions ? instructions : "");

/*Sop*/		/* add option casts */
/*Sop*/		replace(production, "§§§", opt_harden ? "option(" : "");
/*Sop*/		replace(production, "§§", opt_harden ? "Some(" : "");
/*Sop*/		replace(production, "§", opt_harden ? ")" : "");
/*Sop*/		replace(production, "±±", opt_harden ? "force(" : "");
/*Sop*/		replace(production, "±", opt_harden ? ")" : "");

		/* memory clean up */
		delete_bind_tree(binds);
		mtrac_free(parameters), parameters = null;
		mtrac_free(arguments), arguments = null;
		mtrac_free(parameta), parameta = null;
		mtrac_free(emits), emits = null;
		if(caller) mtrac_free(caller), caller = null;
		mtrac_free(methods);
		mtrac_free(globals);
		mtrac_free(declarations);
		mtrac_free(initializations);
		mtrac_free(fixed);
		mtrac_free(declared);
		mtrac_free(class_lists);
		mtrac_free(restorers);
		mtrac_free(adders);
		mtrac_free(functions);
		mtrac_free(instructions);
/*J+S*/		mtrac_free(requires);
		mtrac_free(file);
		mtrac_free(instance_var_name);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_head(char **production, Head *Head, int indent) {
/*T*/		if(!Head) return false;
/*T*/		if(opt_debug) printf("producing Head\n");
		// padcat(2, indent, production, "/*");

/*T*/		xxx_lex(production, Head->Lex, indent);
/*T*/		xxx_preamble(production, Head->Preamble, indent);
/*T*/		xxx_comment(production, Head->Comment, indent);
/*T*/		xxx_authors(production, Head->Authors, indent);
		if(!opt_bare) {
			padcat(2, indent, production, "   file:        ", opt_source);
/*T*/			xxx_lexon(production, Head->Lexon, indent);
			padcat(2, indent, production, "   compiler:    lexon ", program_version);
			padcat(2, indent, production, "   grammar:     ", grammar_version);
			padcat(2, indent, production, "   backend:     ", backend_version);
			padcat(2, indent, production, "   target:      ", target_version);
/*Sop*/			padcat(2, indent, production, "   options:     ", opt_summarized);
/*J+S*/			padcat(2, indent, production, "   parameters:  ", opt_summarized); /////// unify
			padcat(1, indent, production, "%0%\n*/");
		}

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_lex(char **production, Lex *Lex, int indent) {
/*T*/		if(!Lex) return false;
/*T*/		if(opt_debug) printf("producing Lex %s\n", Lex->Name);
		if(!opt_bare) padcat(2, indent, production, "   code:        ", Lex->Name);
		module = Lex->Name;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_lexon(char **production, Lexon *Lexon, int indent) {
/*T*/		if(!Lexon) return false;
/*T*/		if(opt_debug) printf("producing Lexon %s\n", Lexon->Description);
		if(!opt_bare) {
			padcat(2, indent, production, "   code tagged: ", Lexon->Description);
		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_authors(char **production, Authors *Authors, int indent) {
/*T*/		if(!Authors) return false;
/*T*/		if(opt_debug) printf("producing Authors %s\n", Authors->Description);
		if(!opt_bare) {
			padcat(2, indent, production, "   authors:     ", Authors->Description);
			padcat(0, 0, production, "");
		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_comment(char **production, Comment *Comment, int indent) {
/*T*/		if(!Comment) return false;
/*T*/		if(opt_debug) printf("producing comment %s\n", Comment->Description);
		if(!opt_bare) {
			padcat(2, indent, production, "   comment:     ");
/*T*/			xxx_description(production, Comment->Description, indent+1);
			padcat(0, 0, production, "");
		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_preamble(char **production, Preamble *Preamble, int indent) {
/*T*/		if(!Preamble) return false;
/*T*/		if(opt_debug) printf("producing Preamble %s\n", Preamble->Description);
		if(!opt_bare) {
			padcat(2, indent, production, "   preamble:    ", Preamble->Description);
		}
/*T*/		return true;
/*T*/	}
/*T*/
	/* the general terms */
/*T*/	bool xxx_terms(char **production, Terms *Terms, int indent) {
/*T*/		if(!Terms) return false;
/*T*/		if(opt_debug) printf("producing Terms\n");
/*T*/		xxx_provisions(production, Terms->Provisions, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_covenants(char **production, Covenants *Covenants, int indent) {
/*T*/		if(!Covenants) return false;
/*T*/		if(opt_debug) printf("producing contracts\n");
/*T*/		xxx_covenant(production, Covenants->Covenant, indent);
/*T*/		xxx_covenants(production, Covenants->Covenants, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_covenant(char **production, Covenant *Covenant, int indent) {
/*T*/		if(!Covenant) return false;
/*T*/		if(opt_debug) printf("producing Covenant %s\n", Covenant->Name);

		paratag = strlen(*production);
		class = mtrac_strdup(UP(camel_spaced(Covenant->Name)));
		instance = mtrac_strdup(LOW(snake_spaced(Covenant->Name)));
		has_subclasses = true;
		char *functions_shelve = mtrac_strdup(functions);
		char *fixed_shelve = mtrac_strdup(fixed);
		char *declared_shelve = mtrac_strdup(declared);
		bool termination_shelve = uses_termination;
		uses_termination = false;

		/* obtain the names of the clauses */
		Clauses *clauses = !Covenant->Provisions ? null : Covenant->Provisions->Clauses;
		while(clauses) {
			char *name = !clauses->Clause ? null : clauses->Clause->Name;
			if(name) mtrac_concat(&functions, ":", name, ":");
			clauses = clauses->Clauses;
		}

		char *list = mtrac_strdup("");
		mtrac_concat(&list, "_", instance, "_list");
		char *count = mtrac_strdup("");
		mtrac_concat(&count, "_", instance, "_count");

/*JS */		if(opt_comment) padcat(2, indent, production, "/* aggregation of covenants for folds and serialization */");
/*JS */		padcat(C, indent, production, "this.", list, " = {};");
/*JS */		padcat(1, indent, production, "this.", count, " = 0;");

/*Sol*/		if(opt_comment) padcat(2, 1, &adders, "/* aggregation of covenants for folds and serialization */");
/*Sol*/		padcat(C, 1, &adders, "mapping(uint => contract) public ", list, ";");
/*Sol*/		padcat(1, 1, &adders, "uint ", count, " = 0;");

/*Sop*/		if(opt_comment) padcat(2, indent, production, "/* aggregation of covenants for folds and serialization */");
/*Sop*/		padcat(C, indent, production, "this.", list, " = {};");
/*Sop*/		padcat(1, indent, production, "this.", count, " = 0;");

		if(opt_comment) padcat(2, indent, production, "/**");
		if(opt_comment) padcat(1, indent, production, " ** ", class, " covenant class");
		if(opt_comment) padcat(1, indent, production, " **/");

		/*
		if(opt_lexon_comments) {
			char *c = mtrac_strdup(get_lexcom("start"));
			replace(&c, "\n", "\n *\t");
			padcat(1, 0, production, "/ ** ", c, "\n** /");
			mtrac_free(c);
		}
		*/

/*JS */		if(opt_comment) padcat(2, indent, production, "/* this closure exports the covenant's constructor to the scope of the main */");
/*JS */		padcat(C, indent  , production, "this.", class, " = (%2%) => {%15%"); // %15%: access permissions
/*JS */		assert(active_subjects == null);
/*JS */		padcat(1, indent+2, production, "return new ", class, "(%2%);%16%");
/*JS */		padcat(1, indent  , production, "};");

/*JS */		padcat(2, indent  , production, "class ", class, " {");
/*JS */		padcat(2, indent+1, production, "constructor(%2%) {");
/*Sol*/		padcat(2, indent  , production, "contract ", class, " {");
/*Sol*/         padcat(1, indent+1, production, "constructor(%2%) {"); // %2%: constructor parameters, ////// payable
/*Sop*/		padcat(2, indent  , production, "contract ", class, " =");
/*Sop*/		padcat(2, indent+1, production, "record state = {");
/*Sop*/		padcat(0, indent  , production, "%27C%"); // %27C%: covenant member declaration
/*Sop*/		padcat(1, indent+2, production, "}\n");
/*Sop*/		padcat(1, indent+1, production, "%29%entrypoint init(%2%) = {%32C%"); // %29%: emits, %1%: constructor parameters, %32C%: covenant initializations
/*Sop*/		padcat(1, indent+2, production, "}\n");


		char *declarations_stack = declarations;
		char *initializations_stack = initializations;
		char *parameters_stack = parameters;
		char *arguments_stack = arguments;
		char *parameta_stack = parameta;
		declarations = mtrac_strdup("");
		initializations = mtrac_strdup("");
/*JS */		parameters = mtrac_strdup("caller");
/*JS */		arguments = mtrac_strdup("caller");
/*S+S*/		parameters = mtrac_strdup("");
/*S+S*/		arguments = mtrac_strdup("");
		parameta = mtrac_strdup(""); // sic, for JS too
		bool is_payable_stack = is_payable;
/*S+S*/		bool is_stateful_stack = is_stateful;
		is_payable = false;
/*S+S*/		is_stateful = false;

		padcat(2, 0, &instructions, "   The following are actions that can be performed per ", class, ".");
		padcat(2, 0, &instructions, "   > ", instance, " = %contract%.add_", instance, "(%2%)");

/*JS */		if(opt_comment) padcat(1, indent+1, &restorers, "/* restore ", class, " objects */");
/*JS */		padcat(1, indent+1, &restorers, "for (let id in this.", list, ") {");
/*JS */		padcat(1, indent+2, &restorers, "var live = this.", list, "[id];");
/*JS */		padcat(1, indent+2, &restorers, "var instance = new ", class, "();");
/*JS */		padcat(1, indent+2, &restorers, "Object.assign(instance, live);");
/*JS */		padcat(1, indent+2, &restorers, "this.", list, "[id] = instance;");
/*JS */		padcat(1, indent+1, &restorers, "}");

		enforce_same_subject = true;
		covenant_constructor_body = true;
/*T*/		xxx_provisions(production, Covenant->Provisions, indent+2);
		covenant_constructor_body = false;
		enforce_same_subject = false;

		if(uses_termination) {
			if(opt_comment) padcat(2, indent+1, production, "/* built-in termination of this covenant */");
/*JS */			padcat(C, indent+1, production, /* "#" */ "termination(", (opt_log || opt_feedback)?"caller":"", ") {");
/*JS */			padcat(1, indent+2, production, "this.terminated = true;");
/*Sol*/			padcat(C, indent+1, production, "function termination() internal {");
/*Sol*/			padcat(1, indent+2, production, "terminated = true;");
/*Sop*/			padcat(C, indent+1, production, "stateful function termination() =");
/*Sop*/			padcat(1, indent+2, production, "put(state{terminated = true})");
/*JS */			if(opt_log || opt_feedback) padcat(1, indent+2, production, "main.log(caller, '■ covenant terminated');");
/*J+S*/			padcat(1, indent+1, production, "}");

/*JS */			padcat(2, indent+1, production, "already_terminated() {");
/*JS */			padcat(1, indent+2, production, "if(!this.terminated) return false;");
/*JS */			padcat(1, indent+2, production, "console.log('✕ covenant previously terminated');");
/*Sol*/			padcat(2, indent+1, production, "function already_terminated() internal view returns(bool) {");
/*Sol*/			padcat(1, indent+2, production, "if(!terminated) return false;");
/*J+S*/			padcat(1, indent+2, production, "return true;");
/*J+S*/			padcat(1, indent+1, production, "}");
/*Sop*/			padcat(2, indent+1, production, "function already_terminated() =");
/*Sop*/			padcat(1, indent+3, production, "state.terminated");
		}

		/* end of covenant class definition */
/*J+S*/		padcat(1, indent, production, "}");

		/* user api to the hidden classes constructor (must appear after main's (top level) constructor */
		if(opt_comment) padcat(2, 1, &adders, "/* create new instance of ", Covenant->Name, " covenant, and register it with main */");
/*JS */		padcat(C, 1, &adders, "add_", LOW(snake_spaced(Covenant->Name)), "(%2%) {");
/*JS */		if(uses_termination) padcat(1, 2, &adders, "if (this.already_terminated()) return undefined;"); // this == main
/*JS */		padcat(1, 2, &adders, "return this.", list, "[this.", count, " += 1] = this.", class, "(%2b%);");
/*S+S*/		padcat(C, 1, &adders, "function add_", LOW(snake_spaced(Covenant->Name)), "(%2%) returns(", Covenant->Name, ") {");
/*S+S*/		if(uses_termination) padcat(1, 2, &adders, "check_termination()" EOL);
/*S+S*/		padcat(1, 2, &adders, "return ", list, "[", count, " += 1] = new ", class, "(%2b%);");
		padcat(1, 1, &adders, "}");

		/* inject catch of non-permissioned caller in constructor wrapper */
		char *perm = mtrac_strdup("");
		char *close = mtrac_strdup("");
		assert(active_subjects);
		produce_access_conditions(1, indent+1, &perm, active_subjects);
		if(strlen(perm)) padcat(1, indent+1, &close, "}");
		replace(production, "%15%", perm);
		replace(production, "%16%", close);
		mtrac_free(perm);
		mtrac_free(close);

		/* inject parameter lists */
		replace(production, "%2%", parameters);
		replace(&adders   , "%2%", parameters);
		replace(&adders   , "%2b%", arguments);
		replace(&instructions, "%2%", parameta);

		/* function modifier */
		// needed here?
/*Sol*/		replace(production, "%33%", !is_stateful ? " view" : "");
/*Sop*/		replace(production, "%33%", is_stateful ? "stateful " : "");

/*S+S*/		/* sol+sop: insert declaration of member variables into constructor (sol)/contract (sop) head */
/*S+S*/		replace(production, "%27C%", declarations);

/*Sop*/		/* sop: insert initializations of member variables into constructor (sop) head */
/*Sop*/		replace(production, "%32C%", initializations);

		/* cleanup & stack ('shelve') popping */
		delete_list(active_subjects); active_subjects = null;
		mtrac_free(parameters);
		mtrac_free(arguments);
		mtrac_free(parameta);
		mtrac_free(declarations);
		mtrac_free(initializations);
		parameters = parameters_stack;
		arguments = arguments_stack;
		parameta = parameta_stack;
		declarations = declarations_stack;
		initializations = initializations_stack;
		is_payable = is_payable_stack;
/*S+S*/		is_stateful = is_stateful_stack;
		mtrac_free(functions), functions = functions_shelve;
		mtrac_free(fixed), fixed = fixed_shelve;
		mtrac_free(declared), declared = declared_shelve;
		uses_termination = termination_shelve;
		mtrac_free(class), class = null;
		mtrac_free(instance), instance = null;
		mtrac_free(list), list = null;
		mtrac_free(count), count = null;
		paratag = -1;

/*T*/		return true;
/*T*/	}
/*T*/
	static Definitions *global_definitions = null;
	static Definitions *covenant_definitions = null;
/*T*/	bool xxx_provisions(char **production, Provisions *Provisions, int indent) {
/*T*/		if(!Provisions) return false;
/*T*/		if(opt_debug) printf("producing Provisions\n");

		/* definitions */
/*JS */		if(opt_persistence && opt_comment) padcat(2, indent, production, "/* object members: skip for restoring serialized object */");
/*JS */		if(opt_persistence) padcat(1 + (opt_comment?0:1), indent++, production, "if(typeof ", main_constructor_body?"%7%":"caller", " !== 'undefined') {"); // (*)

		if(current_function) current_function->uses_caller |= !main_constructor_body; // for clarity. Really main_constructor_body -> !current_function

/*JS */		if(main_constructor_body) padcat(1, indent, production, "this._escrow = 0;");
		if(!global_definitions) global_definitions = Provisions->Definitions;
		else covenant_definitions = Provisions->Definitions; // (sic)
/*T*/		xxx_definitions(production, Provisions->Definitions, indent);

/*JS */		/* placeholder for this.terminated */
/*JS */		padcat(0, 0, production, main_constructor_body ? "%22%" : "%23%");

/*JS */		if(opt_log && !class) padcat(1, indent, production, (!class?"this":"main"), ".logname = '", opt_log, "';");

		/* statements */
/*JS */		if(opt_log && !class) {
/*JS */			if(opt_comment) padcat(2, indent, production, "/* start log - overwrites previous by same name */");
/*JS */			 padcat(C, indent, production,
/*JS */				"fs.writeFileSync(this.logname, \"Lexon log \" + (new Date).toLocaleString('en-US') + \"\\n\", ()=>{});");
/*JS */		}
		recital_of_terms = main_constructor_body;
		no_action_in_group_yet = true;
		single_sentence_clause = Provisions->Statements && !Provisions->Statements->Statements; // untested ////
/*S+S*/		msg_sender = null;
/*S+S*/		msg_value = null;
/*S+S*/		is_payable = false;
/*S+S*/		is_stateful = false;
/*T*/		xxx_statements(production, Provisions->Statements, indent);
/*S+S*/		if(msg_sender) mtrac_free(msg_sender);
/*S+S*/		if(msg_value) mtrac_free(msg_value);
		recital_of_terms = false;

		/* end of constructor body */
/*JS */		if(opt_persistence) padcat(1, --indent, production, "}");
/*J+S*/		if(!main_constructor_body) padcat(1, --indent, production, "}"); // end of constructor
		/* the above line does anyting only during main_constructor_body==true,
		   which implies current_function==null => irrelevant for uses_caller */ ///// < ???
/*Sop*/		main_constructor_body = false;
/*Sop*/		covenant_constructor_body = false;

		/* insert caller argumnet and 'payable' modifier */
/*JS */		replace(production, "%7%", caller?caller:"caller"); // ! caller is not yet set at (*) above.
/*Sol*/		replace(production, "%28%", is_payable?"payable ":"");

		/* clauses */
/*T*/		xxx_clauses(instance ? production : &methods, Provisions->Clauses, indent - (instance ? 0 : 1));

/*JS */		/* add element this.terminated, if needed */
/*JS */		char *terminated = mtrac_strdup("");
/*JS */		if(uses_termination) padcat(1, indent+(main_constructor_body?1:2),  &terminated, "this.terminated = false;");
/*JS */		replace(production, main_constructor_body ? "%22%" : "%23%", terminated);
/*JS */		mtrac_free(terminated);

		char *termination_test = mtrac_strdup("");
/*JS */		if(uses_termination) padcat(1, indent + (main_constructor_body?0:1), &termination_test, "if(this.already_terminated()) return undefined;");
/*Sol*/		if(uses_termination) padcat(1, indent + (main_constructor_body?0:1), &termination_test, "check_termination()" EOL);
/*Sop*/		if(uses_termination) padcat(1, indent + 1, &termination_test, "check_termination()" EOL);
		replace(instance ? production : &methods, main_constructor_body ? "%24%" : "%25%", termination_test);
		mtrac_free(termination_test);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_definitions(char **production, Definitions *Definitions, int indent) {
/*T*/		if(!Definitions) return false;
/*T*/		xxx_definitions(production, Definitions->Definitions, indent);
/*T*/		xxx_definition(production, Definitions->Definition, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_definition(char **production, Definition *Definition, int indent) {
/*T*/		if(!Definition) return false;
/*T*/		if(opt_debug) printf("producing Definition %s\n", Definition->Name);

		/* ignore alias for this contract */
		if(Definition->This_Contract)
			return true;

		assert(globals);
		if(Definition->Name) {
			if(!class) mtrac_concat(&globals, ":", Definition->Name, ":");
			else if(in(globals, Definition->Name))
				error("do not re-use the same name in multiple definitions", Definition->Name);
		}
/*JS */		padcat(1, indent, production, "");
/*JS *//*T*/	xxx_name(production, Definition->Name, indent);
/*JS */		padcat(0, 0, production, " = null;");
/*S+S*/		char *lowsnake_safe_name = mtrac_strdup(SAFE(LOW(snake_spaced(Definition->Name))));
/*S+S*/		char *lowsnake_literal = mtrac_strdup(LOW(snake_spaced(Definition->Placeholder->Type->Literal)));
/*Sol*/		padcat(1, indent-1, &declarations, typemap(lowsnake_literal, opt_harden, false), " ", lowsnake_safe_name, EOL);
/*Sop*/		if(strlen(declarations)) padcat(0, 0, &declarations, ",");
/*Sop*/		padcat(1, indent+1, &declarations, lowsnake_safe_name, " : ");
/*Sop*/		//- int len = strlen(lowsnake_safe_name);
/*Sop*/		//- padcat(1, indent+1, &declarations, lowsnake_safe_name, len < 4 ? "\t":"", len < 12 ? "\t":"", len < 20 ? "\t":" ", ": ");
/*Sop*/		padcat(0, 0, &declarations, typemap(LOW(snake_spaced(Definition->Placeholder->Type->Literal)), opt_harden, false), EOL);
/*Sop*/		if(strlen(initializations)) padcat(0, 0, &initializations, ",");
/*Sop*/		padcat(1, indent+1, &initializations, lowsnake_safe_name, " = ");
/*Sop*/		padcat(0, 0, &initializations, nullmap(LOW(snake_spaced(Definition->Placeholder->Type->Literal)), !opt_harden), EOL);
/*S+S*/		mtrac_free(lowsnake_safe_name);
/*S+S*/		mtrac_free(lowsnake_literal);
		padcat(0, 0, &declared, ":", LOW(snake_spaced(Definition->Name)), ":"); // declared: write #1
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_placeholder(char **production, Placeholder *Placeholder, int indent) {
/*T*/		if(!Placeholder) return false;
/*T*/		xxx_type(production, Placeholder->Type, indent+1);
/*T*/		return true;
/*T*/	}
/*T*/
	const char *typemap(const char *lex_type, bool option_type, bool forpara) {
		if(!lex_type) return "undefined";
/*Sol*/		if(!strcmp(lex_type,"person")) return "address payable";
/*Sol*/		if(!strcmp(lex_type,"number")) return "uint";
/*Sol*/		if(!strcmp(lex_type,"amount")) return "uint";
/*Sol*/		if(!strcmp(lex_type,"time")) return "uint";
/*Sol*/		if(!strcmp(lex_type,"text")) return forpara ? "string memory" : "string";
/*Sol*/		if(!strcmp(lex_type,"data")) return forpara ? "string memory" : "string";
/*Sol*/		if(!strcmp(lex_type,"binary")) return "bool";
/*Sop*/		if(option_type) {
/*Sop*/			if(!strcmp(lex_type,"person")) return "option(address)";
/*Sop*/			if(!strcmp(lex_type,"number")) return "option(int)";
/*Sop*/			if(!strcmp(lex_type,"amount")) return "option(int)";
/*Sop*/			if(!strcmp(lex_type,"time")) return "option(int)";
/*Sop*/			if(!strcmp(lex_type,"text")) return "option(string)";
/*Sop*/			if(!strcmp(lex_type,"data")) return "option(string)";
/*Sop*/			if(!strcmp(lex_type,"binary")) return "option(bool)";
/*Sop*/		} else {
/*Sop*/			if(!strcmp(lex_type,"person")) return "address";
/*Sop*/			if(!strcmp(lex_type,"number")) return "int";
/*Sop*/			if(!strcmp(lex_type,"amount")) return "int";
/*Sop*/			if(!strcmp(lex_type,"time")) return "int";
/*Sop*/			if(!strcmp(lex_type,"text")) return "string";
/*Sop*/			if(!strcmp(lex_type,"data")) return "string";
/*Sop*/			if(!strcmp(lex_type,"binary")) return "bool";
/*Sop*/		}
		return "[ ERROR: UNKNOWN TYPE ]";
	}

	const char *nullmap(const char *lex_type, bool defined_default) {
		if(!lex_type) return "undefined";
		// defined_default means, don't use None as null but a proper value.
/*Sop*/		if(!defined_default) return "None";
/*Sol*/		if(!strcmp(lex_type,"person")) return "address(0)";
/*Sop*/		if(!strcmp(lex_type,"person")) return "ak_11111111111111111111111111111111273Yts";
		if(!strcmp(lex_type,"number")) return "0";
		if(!strcmp(lex_type,"amount")) return "0";
		if(!strcmp(lex_type,"time")) return "0";
		if(!strcmp(lex_type,"text")) return "\"\"";
		if(!strcmp(lex_type,"data")) return "\"\"";
		if(!strcmp(lex_type,"binary")) return "false";
		return "[ ERROR: UNKNOWN CATEGORY ]";
	}

	const char *lexsymtype(Symbol *symbol) {
                char *pretty_varname;
                if(symbol->Name) pretty_varname = LOW(snake_spaced(symbol->Name)); ///// don't store LOW buffer
                else if(symbol->Type) pretty_varname = LOW(snake_spaced(symbol->Type->Literal)); ///// don't store LOW buffer
                assert(pretty_varname);
		const char *lt = lextype(pretty_varname);
		if(!strcmp(lt, "[ ERROR: UNKNOWN CATEGORY ]")) return null;
		return lt;
	}

	const char *lextype(const char *name) {
		Definitions *d = global_definitions;
		bool covenants = false; // loop goes global first, then local covenant definitions
		if(!strcmp(name, "person") || !strcmp(name, "Person"))
                        return "person";
                if(!strcmp(name, "amount") || !strcmp(name, "Amount"))
                        return "amount";
                char *_name = mtrac_strdup(name); // to get out of LOW buffer, if nec. /// optimize ///// does not work when it kills LOW for caller
		while(d && d->Definition) {
			if(!strcmp(_name, LOW(snake_spaced(d->Definition->Name)))) {
				mtrac_free(_name);
				return d->Definition->Placeholder->Type->Literal;
			}
			d = d->Definitions;
			if(!d && !covenants) covenants = true, d = covenant_definitions;
		}
		mtrac_free(_name);
		return "[ ERROR: UNKNOWN CATEGORY ]";
	}

	const char *type(const char *name, bool option_type, bool forpara) {
		Definitions *d = global_definitions;
		bool covenants = false; // loop goes global first, then local covenant definitions
		char *_name = mtrac_strdup(name); // to get out of LOW buffer, if nec. /// optimize
		while(d && d->Definition) {
			if(!strcmp(_name, LOW(snake_spaced(d->Definition->Name)))) {
				mtrac_free(_name);
				return typemap(d->Definition->Placeholder->Type->Literal, option_type, forpara);
			}
			d = d->Definitions;
			if(!d && !covenants) covenants = true, d = covenant_definitions;
		}
		mtrac_free(_name);
		return "[ ERROR: UNKNOWN TYPE ]";
	}

	const char *nullvalue(const char *name, bool defined_default) {
		assert(global_definitions);
		char *_name = mtrac_strdup(name); // to get out of LOW buffer, if nec. /// optimize
		Definitions *d = global_definitions;
		while(d) {
			if(!strcmp(_name, LOW(snake_spaced(d->Definition->Name)))) {
				mtrac_free(_name);
				return nullmap(d->Definition->Placeholder->Type->Literal, defined_default);
			}
			d = d->Definitions;
		}
		d = covenant_definitions;
		while(d) {
			if(!strcmp(_name, LOW(snake_spaced(d->Definition->Name)))) {
				mtrac_free(_name);
				return nullmap(d->Definition->Placeholder->Type->Literal, defined_default);
			}
			d = d->Definitions;
		}
		mtrac_free(_name);
		return "[ ERROR: UNKNOWN NAME ]";
	}

/*T*/	bool xxx_type(char **production, Type *Type, int indent) {
/*T*/	        if(!Type) return false;
/*T*/	        if(opt_debug) printf("producing Type\n");

/*T*/	        xxx_person(production, Type->Person, indent+1);
/*T*/	        xxx_amount(production, Type->Amount, indent+1);
/*T*/	        xxx_time(production, Type->Time, indent+1);
/*T*/	        xxx_binary(production, Type->Binary, indent+1);
/*T*/	        xxx_text(production, Type->Text, indent+1);
/*T*/	        xxx_data(production, Type->Data, indent+1);
/*T*/
                padcat(0, 0, production, ") ");

/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_person(char **production, Person *Person, int indent) {
/*T*/	        if(!Person) return false;
/*T*/	        if(opt_debug) printf("producing Person\n");
/*Sol*/		padcat(0,0, production, "address payable");
/*Sop*/		padcat(0,0, production, "address");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_amount(char **production, Amount *Amount, int indent) {
/*T*/	        if(!Amount) return false;
/*T*/	        if(opt_debug) printf("producing Amount\n");
/*Sol*/		padcat(0,0, production, "uint");
/*Sop*/		padcat(0,0, production, "int");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_time(char **production, Time *Time, int indent) {
/*T*/	        if(!Time) return false;
/*T*/	        if(opt_debug) printf("producing Time\n");
/*Sol*/		padcat(0,0, production, "uint");
/*Sop*/		padcat(0,0, production, "int");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_binary(char **production, Binary *Binary, int indent) {
/*T*/	        if(!Binary) return false;
/*T*/	        if(opt_debug) printf("producing Binary\n");
/*S+S*/		padcat(0,0, production, "bool");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_text(char **production, Text *Text, int indent) {
/*T*/	        if(!Text) return false;
/*T*/	        if(opt_debug) printf("producing Text\n");
/*S+S*/		padcat(0,0, production, "string");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_data(char **production, Data *Data, int indent) {
/*T*/	        if(!Data) return false;
/*T*/	        if(opt_debug) printf("producing Data\n");
/*S+S*/		padcat(0,0, production, "string");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_this_contract(char **production, This_Contract *This_Contract, int indent) {
/*T*/		if(!This_Contract) return false;
/*JS */		padcat(0, 0, production, "this.");
/*S+S*/		// padcat(0, 0, production, "address(this)."); ? //////
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_all_contracts(char **production, All_Contracts *All_Contracts, int indent) {
/*T*/		if(!All_Contracts) return false;
		padcat(0, 0, production, "main."); // JS/Sol/Sop? //////
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_this(char **production, This *This, int indent) {
/*T*/		if(!This) return false;
/*T*/		if(opt_debug) printf("producing This\n");
		padcat(1, indent, production, "( this ");
		padcat(0, 0, production, ") ");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_clauses(char **production, Clauses *Clauses, int indent) {
/*T*/		if(!Clauses) return false;

/*T*/		xxx_clauses(production, Clauses->Clauses, indent);
/*T*/		xxx_clause(production, Clauses->Clause, indent);
/*T*/
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_clause(char **production, Clause *Clause, int indent) {
/*T*/		if(!Clause) return false;
/*T*/		if(opt_debug) printf("producing Clause %s\n", Clause->Name);

		list *active_subjects_stack = active_subjects;
		active_subjects = null;
		bool is_payable_stack = is_payable;
/*S+S*/		bool is_stateful_stack = is_stateful;

		/* track which function calls which other functions */
		bind *bind = register_bind(SAFE(LOW(snake_spaced(Clause->Name)))); ///// don't call with LOW buffer
		padcat(0, 0, &declared, ":", LOW(snake_spaced(Clause->Name)), ":"); // declared: write #2
		current_function = bind;

		paratag = strlen(*production);
		if(opt_comment) padcat(2, indent, production, "/* ", Clause->Name, " clause */");

            	if(opt_lexon_comments) {
                        char *c = mtrac_strdup(get_lexcom(LOW(snake_spaced(Clause->Name)))); ///// don't call with LOW buffer
			assert(c);
                        replace(&c, "\n", "\n     *  ");
			padcat(2, 0, production, "    /*\n     *  ", c, "\n     */");
                        mtrac_free(c);
                }

/*JS */		padcat(C, indent, production, bind->tag, " ");
/*Sol*/		padcat(C, indent, production, "function ", bind->tag, " public%30%%33%%35%"); // %30%: payable, %33%: view %35%: inference
/*Sop*/		padcat(C, indent, production, "%33%%30%entrypoint ", bind->tag); // %30%: payable, %33%: stateful

/*JS */		padcat(1, 0, &instructions, "   > ", instance ? instance : "%contract%", ".", bind->tag);
/*S+S*/		padcat(1, 0, &instructions, "   • %26%", bind->tag); // %26% caller

		assert(functions);
		if(Clause->Name) mtrac_concat(&functions, ":", Clause->Name, ":");

/*T*/		xxx_body(production, Clause->Body, indent);

/*Sol*/		replace(production, "%30%", is_payable ? " payable" : "");
/*Sol*/		replace(production, "%35%", ""); // take out if not used
/*Sol*/		replace(production, "%33%", !is_stateful ? " view" : "");
/*Sop*/		replace(production, "%30%", is_payable ? "payable " : "");
/*Sop*/		replace(production, "%33%", is_stateful ? "stateful " : "");

		paratag = -1;
		current_function = null; // not used in recitals

		delete_list(active_subjects);
		active_subjects = active_subjects_stack;
		is_payable = is_payable_stack;
/*S+S*/		is_stateful = is_stateful_stack;

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_body(char **production, Body *Body, int indent) {
/*T*/		if(!Body) return false;
/*T*/		if(opt_debug) printf("producing Body\n");
/*J+S*/		padcat(0, 0, production, " {");
/*Sop*/		padcat(0, 0, production, " =");

		/* check for termination */
		if(Body->Statements) padcat(0, 0, production, main_constructor_body ? "%24%" : "%25%");

		no_action_in_group_yet = true;
		single_sentence_clause = Body->Statements && !Body->Statements->Statements; // untested ////
/*S+S*/		msg_sender = null;
/*S+S*/		msg_value = null;
/*S+S*/		is_payable = false;
/*S+S*/		is_stateful = false;
/*T*/		xxx_statements(production, Body->Statements, indent+1);
/*S+S*/		if(msg_sender) mtrac_free(msg_sender);
/*S+S*/		if(msg_value) mtrac_free(msg_value);

/*T*/		xxx_function(production, Body->Function, indent+1);
/*JS */		if(opt_feedback && !Body->Function)
/*JS */			padcat(1, indent+1, production, "return 'done.';"); // this.", LOW(snake_spaced(class)), EOL);

/*J+S*/		padcat(1, indent, production, "}");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_function(char **production, Function *Function, int indent) {
/*T*/		if(!Function) return false;
/*T*/		if(opt_debug) printf("producing Function %s\n", Function->Name);
/*J+S*/		padcat(1, indent, production, "return ");
/*Sop*/		padcat(1, indent, production, "");
/*T*/		xxx_expression(production, Function->Expression, indent+1);
		padcat(0, 0, production, EOL);

		/* add return type to function signature */
/*Sol*/		char *returns = mtrac_strdup(""); if(inference) padcat(0,0,&returns, " returns(", inference, ")");
/*Sol*/		replace(production, "%35%", returns ? returns : "");
/*Sol*/		inference = null;
/*Sol*/		mtrac_free(returns);

/*T*/		return true;
/*T*/	}
/*T*/
	static char *subjnonmatch = null;
	static char *subjlatebind = null;
/*T*/	bool xxx_statements(char **production, Statements *Statements, int indent) {
/*T*/		if(!Statements) return false;
/*T*/		if(opt_debug) printf("producing Statements\n");

		xxx_statements(production, Statements->Statements, indent);
		xxx_statement(production, Statements->Statement, indent);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_statement(char **production, Statement *Statement, int indent) {
/*T*/		if(!Statement) return false;
/*T*/		if(opt_debug) printf("producing Statement\n");
/*T*/		xxx_action(production, Statement->Action, indent);
/*T*/		xxx_flagging(production, Statement->Flagging, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_actions(char **production, Actions *Actions, int indent) {
/*T*/		if(!Actions) return false;

		xxx_actions(production, Actions->Actions, indent);
		xxx_action(production, Actions->Action, indent);

/*T*/		return true;
/*T*/	}
/*T*/
	static Name *subject = null;
	static bool ever = false;
/*T*/	bool xxx_action(char **production, Action *Action, int indent) {
/*T*/		if(!Action) return false;
/*T*/		if(opt_debug) printf("producing Action\n");
		action = Action;

		/* single subject only .. */
		subject = Action->Subject->Symbols->Symbol->Name;
		if(!ever && recital_of_terms) {
			bool payment = is_payment(Action->Predicates);
			/* this takes care of the subject person 1) becoming a parameter and 2) an object member that 3) gets the parameter assigned */
			insert_parameter_and_set_member(production, null, Action->Subject->Symbols->Symbol, payment, paratag, indent, __LINE__); // call #1
			/* the function we are in, if it had no caller set yet, the subject will be used as the caller, LITERALLY. */
			if(!caller) caller = mtrac_strdup(LOW(snake_spaced(Action->Subject->Symbols->Symbol->Name))); // ...
		}

		/* for main_constructor_bodys, enforce that if there are multiple sentences, they all use the same subjects */
		if(! Action->Subject->Symbols->Symbols && ! Action->Subject->Symbols->Symbol->Name)
			; // "this contract"
		else if(!no_action_in_group_yet && enforce_same_subject) {
			list *checks = shallow_clone(active_subjects);
			Symbols *symbols = Action->Subject->Symbols;
			while(symbols && symbols->Symbol) {
				if(symbols->Symbol->Name) {
					printf("testing %s\n", symbols->Symbol->Name);
					list *c = checks;
					while(c) {
						printf("    vs %s\n", (char *)c->item);
						if(!strcmp((char *)c->item, symbols->Symbol->Name)) {
							drop_item(&checks, c);
							break;
						}
						c = c->next;
					}
					if(c) error("In terms, the active subjects of all sentences must match", symbols->Symbol->Name);
				}
				symbols = symbols->Symbols; // i.e. next
			}
			if(checks) error("In terms, the active subjects of all sentences must match", (char *)checks->item); //..
			delete_list(checks);
		}
		/* if not first sentence OR not in constructor: just collect the ones of this sentence */
		else {
			assert(!active_subjects);
			if(active_subjects) delete_list(active_subjects);
			Symbols *symbols = Action->Subject->Symbols;
			while(symbols && symbols->Symbol) {
				if(symbols->Symbol->Name /* && !in_list(active_subjects, symbol->Symbol->Name) */) {
					list_add(&active_subjects, symbols->Symbol->Name);
					assert(active_subjects);
				}
				symbols = symbols->Symbols; // i.e. next
			}
		}
		no_action_in_group_yet = false;
		ever = true;

		assert(!subjnonmatch);
		assert(!subjlatebind);
		subjnonmatch = mtrac_strdup("");
		subjlatebind = mtrac_strdup("");
		padcat(0, 0, production, "%11%%12%");

		xxx_subject(production, Action->Subject, indent);

		/* pre-insert the non-match comparisons and late bindings */

		replace(production, "%11%", subjnonmatch); // can be ""
		replace(production, "%12%", subjlatebind); // can be ""
		mtrac_free(subjnonmatch), subjnonmatch = null;
		mtrac_free(subjlatebind), subjlatebind = null;

		/* check binding of the subject */
		if(current_function) {
			current_function->uses_permission = !!Action->Permission;
/*S+S*/			bool single_subject = !Action->Subject->Symbols->Symbols;
/*S+S*/			// optimized
/*S+S*/			if(single_sentence_clause && single_subject) {
/*S+S*/				padcat(1, indent, production, "permit(");
/*S+S*/				xxx_symbol(production, Action->Subject->Symbols->Symbol, 0);
/*Sop*/				if(opt_harden) {
/*Sop*/					padcat(0,0, production, ", \"");
/*Sop*/					xxx_noun(production, Action->Subject->Symbols->Symbol, 0);
/*Sop*/					padcat(0,0, production, "\"");
/*Sop*/				}
/*S+S*/				padcat(0,0, production, ")" EOL);
/*S+S*/				uses_permit = true;
/*S+S*/			// not optimized
/*S+S*/			} else {
/*JS */				padcat(1, indent, production, "if(");
/*S+S*/				if(single_sentence_clause)
/*S+S*/					padcat(1, indent, production, "require(");
/*S+S*/				else
/*S+S*/					padcat(1, indent, production, "if(");
				Symbols *Symbols = Action->Subject->Symbols;
				int i = 0;
				while(Symbols && Symbols->Symbol) {
					if(i++) padcat(0, 0, production, " || ");
/*JS */					padcat(0, 0, production, "caller == ");
/*Sol*/					padcat(0, 0, production, "msg.sender == ");
/*Sop*/					padcat(0, 0, production, "§§Call.caller§ == ");
					xxx_symbol(production, Symbols->Symbol, 0);
					if(current_function) current_function->uses_caller = true;
					Symbols = Symbols->Symbols;
				}
				// either close the require phrase or open the block which's else is the revert with 'not permitted' at [2]
/*S+S*/				if(single_sentence_clause)
/*JS */					//// visual optimization: padcat(0, 0, production, ") return \"not permitted.\";");
/*S+S*/					padcat(0, 0, production, ", \"not permitted\")" EOL);
/*S+S*/				else {
/*J+S*/					padcat(0, 0, production, ") {");
					indent++;
/*S+S*/				}
/*S+S*/			}
		}

/*T*/		xxx_condition(production, Action->Condition, indent);
		if(Action->Condition) indent++;

/*T*/		xxx_predicates(production, Action->Predicates, indent);

/*J+S*/		if(Action->Condition) padcat(1, --indent, production, "}");

		/* for multiple sentences, add the closing, reverting else */
/*S+S*/		if(current_function && !single_sentence_clause) {
/*JS */		if(current_function) {
/*J+S*/			padcat(1, indent - 1, production, "} else {");
/*Sop*/			padcat(1, indent - 1, production, "else");
/*JS */			padcat(1, indent, production, "return 'not permitted.';"); // [2] ////// delete the dot (must refresh tests)
/*Sol*/			padcat(1, indent, production, "revert(\"not permitted\");"); // [2]
/*Sop*/			padcat(1, indent, production, "abort(\"not permitted\")", EOL); // [2]
/*J+S*/			padcat(1, --indent, production, "}");
		}

		action = null;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_subject(char **production, Subject *Subject, int indent) {
/*T*/		if(!Subject) return false;
/*T*/		if(opt_debug) printf("producing Subject\n");

/*JS */		char **para = current_function ? &current_function->parameta : &parameta;
/*S+S*/		char *_para = mtrac_strdup("");
/*S+S*/		char **para = &_para;

		Symbols *s = Subject->Symbols; // a subject may consist of multiple nouns
		bool first = true;
		bool any = false;

		/* for every noun that is part of the subject */
		while(s && s->Symbol) {
			/* if it has a literal name - and thus is not the keyword 'escrow'
			 (which's literal may be in Literal but Name after parsing) */
			if(s->Symbol->Name) {

				char *varname = LOW(snake_spaced(s->Symbol->Name)); ///// don't store LOW buffer
				char *lexname = s->Symbol->Name;
				char *scope = (!in(globals, s->Symbol->Name) && class) ? "this." : "main."; ////// unite with usual 'main_constructor_body?' ?

/*S+S*/				padcat(0,0,para, first ? "<<" : " or ", lexname);
/*JS */				padcat(0,0,para, first ? "<<" : " or ", varname); //X unite with S+S?

				/* binding of unbound person variable to caller parameter */
				if(!main_constructor_body) {
					/* precondition that caller and all of the subjects cannot be the same */
					if(first) padcat(2, indent, &subjnonmatch, "if(caller != ", scope, SAFE(varname));
					else padcat(0, 0, &subjnonmatch, " && caller != ", scope, SAFE(varname));
					/* produce bind code. Person in question must still be null, i.e., unbound */
					if(!in(fixed, varname)) {
						padcat(1, indent+1, &subjlatebind, !any ? "" : "else ", "if(", scope,
							SAFE(varname), " == null) ", scope, SAFE(varname), " = caller;");
						any = true;
					}
				}
			}
			s = s->Symbols;
			first = false;
		}
		if(strlen(*para)) padcat(0, 0, para, ">>"); // .. sometimes produces >>>>
/*S+S*/		if(strlen(*para)) concat(para, " ⟶  ");
/*S+S*/		replace(&instructions, "%26%", *para);
/*S+S*/		mtrac_free(_para);

		if(any)
			padcat(0, 0, &subjnonmatch, ") {"), padcat(1, indent, &subjlatebind, "}\n");
		else
			/* reset all when all in subjlatebind are actually constructor arguments, of the main or sub contract
			   This is known only after the loop has been traversed and 'any' is still false.  */
			mtrac_free(subjnonmatch), subjnonmatch = mtrac_strdup("");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_symbols(char **production, Symbols *Symbols, int indent) {
/*T*/		if(!Symbols) return false;
/*T*/		xxx_symbol(production, Symbols->Symbol, indent);
/*T*/		xxx_catena(production, Symbols->Catena, indent);
/*T*/		xxx_symbols(production, Symbols->Symbols, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_symbol(char **production, Symbol *Symbol, int indent) {
/*T*/		if(!Symbol) return false;

		/* produce the name literal. Note that xxx_name adds 'this.' or 'main.', which makes for a global scope,
		   while the cases that a type name is itself used as variable name, it is use unprefixed, for a local scope. */
/*T*/		if(Symbol->Name) xxx_name(production, Symbol->Name, indent);
		else if(Symbol->Type) {
/*S+S*/			padcat(0,0, production, Symbol->Type->Literal); //X change to JS SAFE etc? v
/*JS */			padcat(0,0, production, SAFE(LOW(snake_spaced(Symbol->Type->Literal))));
		} else { padcat(0,0, production, "[ UNDEFINED ]"); } ///// or assert
		return true;
/*T*/	}

	bool xxx_noun(char **production, Symbol *Symbol, int indent) {
		if(!Symbol) return false;
		if(Symbol->Name) padcat(0,0, production, Symbol->Name);
		else if(Symbol->Type) padcat(0,0, production, Symbol->Type->Literal);
		else padcat(0,0, production, "[ UNKNOWN ]");
		return true;
	}

/*T*/	bool xxx_catena(char **production, Catena *Catena, int indent) {
/*T*/		if(!Catena) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_object(char **production, Object *Object, int indent) {
/*T*/		if(!Object) return false;
/*T*/		if(opt_debug) printf("producing Object\n");
		if(Object->Symbol) {
/*Sop*/			if(opt_harden) padcat(0,0, production, "force(");
			xxx_symbol(production, Object->Symbol, indent+1);
/*Sop*/			if(opt_harden) {
/*Sop*/				padcat(0,0, production, ", \"");
/*Sop*/				xxx_noun(production, Object->Symbol, indent+1);
/*Sop*/				padcat(0,0, production, "\")");
/*Sop*/			}
		} else if(Object->Reflexive)
			xxx_reflexive(production, Object->Reflexive, indent+1);
		// else: escrow == do nothing
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_reflexive(char **production, Reflexive *Reflexive, int indent) {
/*T*/		if(!Reflexive) return false;
/*T*/		if(opt_debug) printf("producing Reflexive\n");

		assert(action);
		assert(action->Subject);
		assert(action->Subject->Symbols);
		if(!action->Subject->Symbols->Symbol)
			error("missing subject for reflexive pronoun", "..."); ///// add literal from parse run
		if(action->Subject->Symbols->Symbols)
			error("don't use multiple subjects with a reflexive pronoun", action->Subject->Symbols->Symbol->Name);
		xxx_symbol(production, action->Subject->Symbols->Symbol, indent+1);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_contract(char **production, Contract *Contract, int indent) {
/*T*/		if(!Contract) return false;
/*T*/		if(opt_debug) printf("producing Contract\n");
		padcat(1, indent, production, "( contract ");

/*T*/		xxx_this_contract(production, Contract->This_Contract, indent+1);
/*T*/		xxx_all_contracts(production, Contract->All_Contracts, indent+1);
/*T*/
		padcat(0, 0, production, ") ");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_predicates(char **production, Predicates *Predicates, int indent) {
/*T*/		if(!Predicates) return false;
/*T*/		if(opt_debug) printf("producing Predicates\n");
/*T*/		xxx_predicates(production, Predicates->Predicates, indent);
/*T*/		xxx_predicate(production, Predicates->Predicate, indent);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_predicate(char **production, Predicate *Predicate, int indent) {
/*T*/		if(!Predicate) return false;
/*T*/		if(opt_debug) printf("producing Predicate\n");

		if(current_function) current_function->changes_state = true;

/*T*/		xxx_certification(production, Predicate->Certification, indent);
/*T*/	        xxx_declaration(production, Predicate->Declaration, indent);
/*T*/	        xxx_filing(production, Predicate->Filing, indent);
/*T*/		xxx_registration(production, Predicate->Registration, indent);
/*T*/		xxx_grantment(production, Predicate->Grantment, indent);
/*T*/		xxx_appointment(production, Predicate->Appointment, indent);
/*T*/		xxx_fixture(production, Predicate->Fixture, indent);
/*T*/		xxx_setting(production, Predicate->Setting, indent);
/*T*/		xxx_payment(production, Predicate->Payment, indent);
/*T*/	        xxx_sending(production, Predicate->Sending, indent);
/*T*/	        xxx_notification(production, Predicate->Notification, indent);
/*T*/		xxx_termination(production, Predicate->Termination, indent);
/*T*/
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_permission(char **production, Permission *Permission, int indent) {
/*T*/		if(!Permission) return false;
/*T*/		if(opt_debug) printf("producing Permission\n");
/*T*/		return true;
/*T*/	}
/*T*/

static void assign(char **production, int indent, Symbol *symbol, Expression *expression) {
		padcat(1, indent, production, "");
/*Sop*/		padcat(0, 0, production, "put(state{");
		miller = true;
		xxx_symbol(production, symbol, indent);
		miller = false;
/*S+S*/		is_stateful = true; // note the tag is useless for sol, assign() is yet only used by Sop
                padcat(0, 0, production, " = ");
		if(expression)
			xxx_expression(production, expression, indent+1);
		else
			padcat(0, 0, production, "true");
/*S+S*/		padcat(0, 0, production, "})"); // note this is hypothetical, assign() is not used yet by Sol (only Sop)
                padcat(0, 0, production, EOL);
}

/*T*/	bool xxx_certification(char **production, Certification *Certification, int indent) {
/*T*/		if(!Certification) return false;
/*T*/		if(opt_debug) printf("producing Certification\n");

/*JS */		assert(!strstr(*production, "%preassign%")); //X is all of the following dated and should be rolled into Sop/assign ?
/*JS */		padcat(0, 0, production, "%preassign%");
/*JS */		preass_indent = indent;
/*JS */		padcat(1, indent, production, "");
/*JS */		js_symbol(production, Certification->Symbol, indent);
/*JS */		padcat(0, 0, production, " = ");
/*JS */		if(Certification->Expression)
/*JS */			js_expression(production, Certification->Expression, indent+1);
/*JS */		else // contract or nothing
/*JS */			padcat(0, 0, production, "true");
/*JS */		padcat(0, 0, production, ";");
/*JS */
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Certification->Symbol->Name, " certified\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*JS */		replace(production, "%preassign%", "");

/*Sol*/		if(Certification->Expression) {
/*Sol*/			padcat(1, indent, production, "");
/*Sol*/			sol_symbol(production, Certification->Symbol, indent);
/*Sol*/			padcat(0, 0, production, " = ");
/*Sol*/			sol_expression(production, Certification->Expression, indent+1);
/*Sol*/			padcat(0, 0, production, ";");
/*Sol*/		} else { // contract or nothing
/*Sol*/			insert_parameter_and_set_member(production, &instructions, Certification->Symbol, false, paratag, indent, __LINE__); // call #2
/*Sol*/			///// padcat(1, indent, production, "");
/*Sol*/			///// sol_symbol(production, Certification->Symbol, indent);
/*Sol*/			///// padcat(0, 0, production, "= true;");
			///// cf. evaluation.lex commissioned() / statement.lex certify()
/*Sol*/			is_stateful = true;
/*Sol*/		}

/*Sop*/		if(Certification->Contract) {
/*Sop*/			assign(production, indent, Certification->Symbol, null);
/*Sop*/		} else if(Certification->Expression) {
/*Sop*/			assign(production, indent, Certification->Symbol, Certification->Expression);
/*Sop*/		} else { // contract or nothing
/*Sop*/			insert_parameter_and_set_member(production, &instructions, Certification->Symbol, false, paratag, indent, __LINE__); // call #2a
/*Sop*/			// padcat(0, 0, production, "true"); //< 4oct
/*Sop*/		}

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_certify(char **production, Certify *Certify, int indent) {
/*T*/		if(!Certify) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_declaration(char **production, Declaration *Declaration, int indent) {
/*T*/	        if(!Declaration) return false;
/*T*/	        if(opt_debug) printf("producing Declaration\n");

		assert(!strstr(*production, "%preassign%")); //X new after javascript.c was finished
		padcat(0, 0, production, "%preassign%");
		preass_indent = indent;
/*Sop*/		assign(production, indent, Declaration->Symbol, Declaration->Expression); //X new after javascript.c was finished

/*J+S*/		padcat(1, indent, production, ""); //X sollte das Folgende komplett, wie oben mit assign() behandelt werden?
/*J+S*/		xxx_symbol(production, Declaration->Symbol, indent);
/*J+S*/		padcat(0, 0, production, " = ");
/*Sol*/		is_stateful = true;
/*J+S*/		if(Declaration->Expression)
/*J+S*/			xxx_expression(production, Declaration->Expression, indent+1);
/*J+S*/		else
/*J+S*/			padcat(0, 0, production, "true");
/*J+S*/		padcat(0, 0, production, ";");
/*J+S*/
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Declaration->Symbol->Name, " declared\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
		replace(production, "%preassign%", "");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_declare(char **production, Declare *Declare, int indent) {
/*T*/	        if(!Declare) return false;
/*T*/	        if(opt_debug) printf("producing Declare\n");
                padcat(1, indent, production, "( declare ");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_filing(char **production, Filing *Filing, int indent) {
/*T*/	        if(!Filing) return false;
/*T*/	        if(opt_debug) printf("producing Filing\n");

		if(Filing->Symbol) {
			/* e.g. The Secured Party may file the Continuation Statement. (only example currently) */
			insert_parameter_and_set_member(production, &instructions, Filing->Symbol, false, paratag, indent, __LINE__); // call #3
		} else {
			padcat(1, indent, production, "");
			xxx_symbol(production, Filing->Symbol, indent); ///// can't have any effect?
			padcat(0, 0, production, " = ");
			if(Filing->Expression)
				xxx_expression(production, Filing->Expression, indent+1);
			else
				padcat(0, 0, production, "true");
			padcat(0, 0, production, EOL);
		}
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Filing->Symbol->Name, " filed\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_file(char **production, File *File, int indent) {
/*T*/	        if(!File) return false;
/*T*/	        if(opt_debug) printf("producing File\n");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_registration(char **production, Registration *Registration, int indent) {
/*T*/		if(!Registration) return false;
/*T*/		if(opt_debug) printf("producing registration\n");

		if(Registration->Symbol) {
			/* e.g., The Licensee may register a Comment Text. (only example) */
			insert_parameter_and_set_member(production, &instructions, Registration->Symbol, false, paratag, indent, __LINE__); // call #4
		} else {
			padcat(1, indent, production, "");
			xxx_symbol(production, Registration->Symbol, indent); ////// can't have any effect?
			padcat(0, 0, production, " = ");
			if(Registration->Expression)
				xxx_expression(production, Registration->Expression, indent+1);
			else
				padcat(0, 0, production, "true");
			padcat(0, 0, production, EOL);
		}
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Registration->Symbol->Name, " registered\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_register(char **production, Register *Register, int indent) {
/*T*/		if(!Register) return false;
/*T*/		if(opt_debug) printf("producing Register\n");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_grantment(char **production, Grantment *Grantment, int indent) {
/*T*/		if(!Grantment) return false;
/*T*/		if(opt_debug) printf("producing Grantment\n");
/*Sop*/		assign(production, indent, Grantment->Symbol, null); // sets true
/*J+S*/		padcat(1, indent, production, "");
/*J+S*/		xxx_symbol(production, Grantment->Symbol, indent+1);
/*Sol*/		is_stateful = true;
/*J+S*/		padcat(0, 0, production, " = true;"); // 'grant' instead of 'true'
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Grantment->Symbol->Name, " granted\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_grant(char **production, Grant *Grant, int indent) {
/*T*/		if(!Grant) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_appointment(char **production, Appointment *Appointment, int indent) {
/*T*/		if(!Appointment) return false;
/*T*/		if(opt_debug) printf("producing Appointment\n");

		/* produce person code: take care that they 1) become parameters, and 2) object elements with 3) that parameter assigned to */
		insert_parameter_and_set_member(production, &instructions, Appointment->Symbol, false, paratag, indent, __LINE__); // call #5
/*JS */		if(opt_log || opt_feedback) {
/*JS */			if(opt_feedback)
/*JS */				padcat(1, indent, production, (!class?"this":"main"), ".log(", recital_of_terms?caller:"caller",
/*JS */					", \"✓ ", Appointment->Symbol->Name, " appointed\");");
/*JS */			if(current_function)
/*JS */				current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_appoint(char **production, Appoint *Appoint, int indent) {
/*T*/		if(!Appoint) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_fixture(char **production, Fixture *Fixture, int indent) {
/*T*/		if(!Fixture) return false;
/*T*/		if(opt_debug) printf("producing Fixture\n");

		if(Fixture->Expression) {
			/* An object member is declared and defined on the fly by an expression and NOT by parameter:
			   e.g., The Licensor or the Arbiter may fix the Notice Time as the respective current time. */
			///// will not work in constructor?
/*Sop*/			assign(production, indent, Fixture->Symbol, Fixture->Expression);
/*J+S*/			padcat(1, indent, production, "");
/*J+S*//*T*/		xxx_symbol(production, Fixture->Symbol, indent+1);
/*J+S*/			padcat(0, 0, production, " = ");
/*J+S*//*T*/		xxx_expression(production, Fixture->Expression, indent);
/*J+S*/			padcat(0, 0, production, ";"); // 'fix' instead of ';'
		} else {
			/* produce amounts/texts etc variables: take care that they 1) become parameters 2) object elements with that parameter assigned
			   e.g., The Licensor [..] fixes the Description of Goods. */
			insert_parameter_and_set_member(production, &instructions, Fixture->Symbol, false, paratag, indent, __LINE__); // call #6
/*Sol*/			is_stateful = true;
		}
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Fixture->Symbol->Name, " fixed\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*T*/		return true;
/*T*/	}

/*T*/
/*T*/	bool xxx_fix(char **production, Fix *Fix, int indent) {
/*T*/		if(!Fix) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_setting(char **production, Setting *Setting, int indent) {
/*T*/		if(!Setting) return false;
/*T*/		if(opt_debug) printf("producing Setting\n");
		padcat(1, indent, production, "");
/*T*/		xxx_symbol(production, Setting->Symbol, indent+1);
		padcat(0, 0, production, " = true;"); // set");
/*JS */		if(opt_log || opt_feedback) {
/*JS */			padcat(1, indent, production, (!class?"this":"main"),
/*JS */				".log(", recital_of_terms?caller:"caller", ", \"✓ ", Setting->Symbol->Name, " state set\");");
/*JS */			if(current_function) current_function->uses_caller |= class || !strcmp(caller, "caller");
/*JS */		}
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_illocutor(char **production, Illocutor *Illocutor, int indent) {
/*T*/		if(!Illocutor) return false;
/*T*/		if(opt_debug) printf("producing Illocutor\n");
		padcat(1, indent, production, "( illocutor ");

/*T*/		xxx_be(production, Illocutor->Be, indent+1);
/*T*/
		padcat(0, 0, production, ") ");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_be(char **production, Be *Be, int indent) {
/*T*/		if(!Be) return false;
/*T*/		if(opt_debug) printf("producing Be\n");
		padcat(1, indent, production, "( be ");
		padcat(0, 0, production, ") ");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_payment(char **production, Payment *Payment, int indent) {
/*T*/		if(!Payment) return false;
/*T*/		if(opt_debug) printf("producing Payment\n");

		assert(!strstr(*production, "%preassign%"));
		padcat(0, 0, production, "%preassign%");
		preass_indent = indent;

		bool explicit_from_escrow = Payment->Escrow || Payment->From_Escrow;
		bool explicit_to_escrow = !Payment->Object->Symbol && !Payment->Object->Reflexive;
		assert(!(explicit_from_escrow && explicit_to_escrow));

/*S+S*/		// msg.value is paid in implicitly, no code to produce ..
/*S+S*/		if(explicit_to_escrow) {
/*S+S*/			// .. but handle the amount variable (declaration)
/*S+S*/			// e.g. it must consume the msg_value slot if 'Amount'
/*S+S*/			/// this won't hold expressions for payment amounts, so assert
/*S+S*/			if(Payment->Expression) {
/*S+S*/				assert(Payment->Expression->Combination);
/*S+S*/				assert(!Payment->Expression->Combination->Combination);
/*S+S*/				assert(Payment->Expression->Combination->Combinor);
/*S+S*/				assert(!Payment->Expression->Combination->Combinor->Combinor);
/*S+S*/				assert(Payment->Expression->Combination->Combinor->Combinand);
/*S+S*/				assert(Payment->Expression->Combination->Combinor->Combinand->Symbol);
/*S+S*/				no_literal = true;
/*S+S*/				xxx_expression(production, Payment->Expression, 0);
/*S+S*/				no_literal = false;
/*S+S*/			}
/*S+S*/			replace(production, "%preassign%", "");
/*S+S*/			return true;
/*S+S*/		}

		/* function head */
		xxx_pay(production, Payment->Pay, indent);

		/* sender */
/*JS */		if(Payment->Escrow)
/*JS */			xxx_escrow(production, Payment->Escrow, 0);
/*JS */		else if(Payment->From_Escrow)
/*JS */			xxx_from_escrow(production, Payment->From_Escrow, 0);
/*JS */		else
/*JS */			xxx_name(production, (Name *)subject, 0);
/*JS */
/*JS */		padcat(0, 0, production, ", ");


		/* receiver */
		if(!explicit_to_escrow)
			xxx_object(production, Payment->Object, 0);
		else
			padcat(0, 0, production, "'escrow'");

		padcat(0, 0, production, ", ");

		/* amount */
		if(Payment->Expression)
/*T*/			xxx_expression(production, Payment->Expression, 0);
		else
/*JS */			padcat(0, 0, production, main_constructor_body?"this._escrow":"main._escrow");
/*Sol*/			padcat(0, 0, production, "address(this).balance");
/*Sop*/			padcat(0, 0, production, "Contract.balance");

		padcat(0, 0, production, ")", EOL);

		replace(production, "%preassign%", "");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_pay(char **production, Pay *Pay, int indent) {
/*T*/		if(!Pay) return false;
/*T*/		if(opt_debug) printf("producing Pay\n");
		uses_pay = true;
/*S+S*/		is_stateful = true;
/*JS */		padcat(1, indent, production, (class?"main":"this"), "._pay(", (opt_log)?"caller, ":"");
/*S+S*/		padcat(1, indent, production, "transfer(");
		if(current_function) current_function->uses_caller |= opt_log || opt_feedback;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_preposition(char **production, Preposition *Preposition, int indent) {
/*T*/		if(!Preposition) return false;
/*T*/		if(opt_debug) printf("producing Preposition\n");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_escrow(char **production, Escrow *Escrow, int indent) {
/*T*/	        if(!Escrow) return false;
/*T*/	        if(opt_debug) printf("producing Escrow\n");
/*JS */		padcat(0, 0, production, "'escrow'");
/*S+S*/		padcat(0, 0, production, "address(this)");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_from_escrow(char **production, From_Escrow *From_Escrow, int indent) {
/*T*/		if(!From_Escrow) return false;
/*T*/		if(opt_debug) printf("producing From_Escrow\n");
/*JS */		padcat(0, 0, production, "'escrow'");
/*S+S*/		padcat(0, 0, production, "address(this)");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_sending(char **production, Sending *Sending, int indent) {
/*T*/	        if(!Sending) return false;
/*T*/	        if(opt_debug) printf("producing Sending\n");

		xxx_send(production, Sending->Send, indent);

/*JS */		// sender
/*JS */		xxx_name(production, (Name *)subject, 0);
/*JS */		padcat(0, 0, production, ", ");

		// receiver
		assert(Sending->Object->Symbol || Sending->Object->Reflexive);
		xxx_object(production, Sending->Object, 0);

		padcat(0, 0, production, ", ");

		// message
/*T*/		xxx_expression(production, Sending->Expression, 0);
		padcat(0, 0, production, ")", EOL);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_send(char **production, Send *Send, int indent) {
/*T*/	        if(!Send) return false;
/*T*/	        if(opt_debug) printf("producing Send\n");
		uses_send = true;
/*JS */		padcat(1, indent, production, (class?"main":"this"), "_send(", (opt_log)?"caller, ":"");
/*S+S*/		padcat(1, indent, production, "send(");
		if(current_function) current_function->uses_caller |= opt_log || opt_feedback;
/*T*/		return true;
/*T*/	}

/*T*/	bool xxx_notification(char **production, Notification *Notification, int indent) {
/*T*/	        if(!Notification) return false;
/*T*/	        if(opt_debug) printf("producing Notification\n");
                padcat(1, indent, production, "( notification ");

/*T*/	        xxx_notify(production, Notification->Notify, indent+1);
/*T*/	        xxx_object(production, Notification->Object, indent+1);
/*T*/	        xxx_preposition(production, Notification->Preposition, indent+1);
/*T*/	        xxx_expression(production, Notification->Expression, indent+1);
/*T*/
                padcat(0, 0, production, ") ");

/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_notify(char **production, Notify *Notify, int indent) {
/*T*/	        if(!Notify) return false;
/*T*/	        if(opt_debug) printf("producing Notify\n");
                padcat(1, indent, production, "( notify ");
		///////
/*T*/
                padcat(0, 0, production, ") ");

/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_termination(char **production, Termination *Termination, int indent) {
/*T*/		if(!Termination) return false;
/*T*/		if(opt_debug) printf("producing Termination\n");
		padcat(1, indent, production, "");
/*T*/		xxx_this_contract(production, Termination->This_Contract, indent+1);
/*T*/		xxx_all_contracts(production, Termination->All_Contracts, indent+1);
/*T*/		xxx_terminate(production, Termination->Terminate, indent+1);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_terminate(char **production, Terminate *Terminate, int indent) {
/*T*/		if(!Terminate) return false;
/*T*/		if(opt_debug) printf("producing Terminate\n");
		uses_termination = true;
/*JS */		padcat(0, 0, production, /* "#" */ "termination(", (opt_log || opt_feedback)?"caller":"", ");");
/*S+S*/		padcat(0, 0, production, "termination()", EOL);
/*S+S*/		is_stateful = true;
		if(current_function) current_function->uses_caller |= opt_log || opt_feedback;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_flagging(char **production, Flagging *Flagging, int indent) {
/*T*/		if(!Flagging) return false;
/*T*/		if(opt_debug) printf("producing Flagging\n");
		padcat(1, indent, production, "");
/*T*/		xxx_symbol(production, Flagging->Symbol, indent+1);
		padcat(0, 0, production, " = true;"); ////////
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_condition(char **production, Condition *Condition, int indent) {
/*T*/		if(!Condition) return false;
/*T*/		if(opt_debug) printf("producing Condition\n");

/*T*/		xxx_if(production, Condition->If, indent);
/*T*/		xxx_expression(production, Condition->Expression, indent+1);
/*J+S*/		padcat(0, 0, production, ") {");
/*Sop*/		padcat(0, 0, production, ")");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_if(char **production, If *If, int indent) {
/*T*/		if(!If) return false;
/*T*/		if(opt_debug) printf("producing If\n");
		padcat(1, indent, production, "if(");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_expression(char **production, Expression *Expression, int indent) {
/*T*/		if(!Expression) return false;
/*T*/		if(opt_debug) printf("producing Expression\n");
		// padcat(0, 0, production, "«");
/*T*/		xxx_combination(production, Expression->Combination, indent+1);
		 //padcat(0, 0, production, "»");
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_scalar_comparison(char **production, Scalar_Comparison *Scalar_Comparison, int indent) {
/*T*/		if(!Scalar_Comparison) return false;
/*T*/		if(opt_debug) printf("producing Scalar_Comparison\n");

		// obsolete bool self = Scalar_Comparison->Scalar_Expression ///// clean up
		//	&& Scalar_Comparison->Scalar_Expression->Symbol
		//	&& Scalar_Comparison->Scalar_Expression->Symbol->This_Contract
		//	&& Scalar_Comparison->Comparison_Operator;

		// dito if(!self) { ///// clean up
		padcat(0, 0, production, "(");
/*T*/		xxx_scalar_expression(production, Scalar_Comparison->Scalar_Expression, indent+1);
/*T*/		xxx_comparison_operator(production, Scalar_Comparison->Comparison_Operator, indent+1);
		// }
		char *inference_stack = inference;
/*T*/		xxx_scalar_expression(production, Scalar_Comparison->Scalar_Expression2, indent+1);
		inference = inference_stack;
/*T*/
		// dito if(!self) ///// clean up
		padcat(0, 0, production, ")");

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_comparison_operator(char **production, Comparison_Operator *Comparison_Operator, int indent) {
/*T*/		if(!Comparison_Operator) return false;
/*T*/		if(opt_debug) printf("producing Comparison_Operator\n");
/*T*/		xxx_equal(production, Comparison_Operator->Equal, indent+1);
/*T*/		xxx_later(production, Comparison_Operator->Later, indent+1);
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_equal(char **production, Equal *Equal, int indent) {
/*T*/		if(!Equal) return false;
/*T*/		if(opt_debug) printf("producing Equal\n");
		padcat(0, 0, production, " == ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_later(char **production, Later *Later, int indent) {
/*T*/		if(!Later) return false;
/*T*/		if(opt_debug) printf("producing Later\n");
/*J+S*/		padcat(0, 0, production, " <= ");
/*Sop*/		padcat(0, 0, production, " =< ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_scalar_expression(char **production, Scalar_Expression *Scalar_Expression, int indent) {
/*T*/		if(!Scalar_Expression) return false;
/*T*/		if(opt_debug) printf("producing Scalar_Expression %s\n", Scalar_Expression->Scalar);
/*T*/		xxx_symbol(production, Scalar_Expression->Symbol, indent+1);
/*T*/		xxx_scalar(production, Scalar_Expression->Scalar, indent+1);
/*T*/		xxx_point_in_time(production, Scalar_Expression->Point_In_Time, indent+1);
		inference = "uint";
/*T*/		return true;
/*T*/	}

/*T*/	bool xxx_hex_expression(char **production, Hex_Expression *Hex_Expression, int indent) {
/*T*/		if(!Hex_Expression) return false;
/*T*/		if(opt_debug) printf("producing Hex_Expression %s\n", Hex_Expression->Hex);
/*T*/		xxx_symbol(production, Hex_Expression->Symbol, indent+1);
/*T*/		xxx_hex(production, Hex_Expression->Hex, indent+1);
/*T*/		// xxx_point_in_time(production, Hex_Expression->Point_In_Time, indent+1);
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/

/*T*/
/*T*/	bool xxx_combination(char **production, Combination *Combination, int indent) {
/*T*/		if(!Combination) return false;
/*T*/		if(opt_debug) printf("producing Combination\n");
		if(Combination->Combinator) padcat(0, 0, production, "(");
/*T*/		xxx_combinor(production, Combination->Combinor, 0);
/*T*/		xxx_combinator(production, Combination->Combinator, indent);
/*T*/		xxx_combination(production, Combination->Combination, 0);
		char *inference_stack = inference;
		if(Combination->Combinator) padcat(0, 0, production, ")");
		inference = inference_stack;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_combinor(char **production, Combinor *Combinor, int indent) {
/*T*/		if(!Combinor) return false;
/*T*/		if(opt_debug) printf("producing Combinor\n");
		if(Combinor->Combinator) padcat(0, 0, production, "(");

/*T*/		xxx_combinand(production, Combinor->Combinand, 0);
/*T*/		xxx_combinator(production, Combinor->Combinator, 0);
/*T*/		xxx_combinor(production, Combinor->Combinor, 0);
/*T*/
		char *inference_stack = inference;
		if(Combinor->Combinator) padcat(0, 0, production, ")");
		inference = inference_stack;

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_combinand(char **production, Combinand *Combinand, int indent) {
/*T*/		if(!Combinand) return false;
/*T*/		if(opt_debug) printf("producing Combinand\n");

		if(Combinand->Symbol) {
			char *funcname = Combinand->Symbol->Name;
			if(!funcname) funcname = Combinand->Symbol->Type->Literal;
			assert(funcname);
			char *varname = LOW(snake_spaced(funcname)); ///// don't store LOW buffer
			if(!in(fixed, varname) && !in(functions, funcname)) {
				/* produce amounts/texts etc variables: take care that they
				   1) become parameters, and 2) object elements with that parameter assigned
				   e.g., The Secured Party may pay a Reminder Fee into escrow. */
				insert_parameter_and_set_member(production, &instructions, Combinand->Symbol, false, paratag, indent+1, __LINE__); ////// call #7
			}
			/* produce the literal (name or type name for variables that are named verbatim a type) */
			if(!no_literal) {
/*Sop*/				if(opt_harden) padcat(0, 0, production, "force(");
				xxx_symbol(production, Combinand->Symbol, indent+1);
/*Sop*/				if(opt_harden) padcat(0, 0, production, ", \"");
/*Sop*/				if(opt_harden) xxx_noun(production, Combinand->Symbol, indent+1);
/*Sop*/				if(opt_harden) padcat(0, 0, production, "\")", EOL);
			}
		}
/*T*/		xxx_expiration(production, Combinand->Expiration, indent+1);
/*T*/		xxx_scalar_comparison(production, Combinand->Scalar_Comparison, indent+1);
/*T*/		xxx_negation(production, Combinand->Negation, indent+1);
/*T*/		xxx_existence(production, Combinand->Existence, indent+1);
/*T*/		xxx_point_in_time(production, Combinand->Point_In_Time, indent+1);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_combinator(char **production, Combinator *Combinator, int indent) {
/*T*/		if(!Combinator) return false;
/*T*/		if(opt_debug) printf("producing Combinator\n");
/*T*/		xxx_or_(production, Combinator->Or_, indent);
/*T*/		xxx_and(production, Combinator->And, indent);
/*T*/		xxx_neither(production, Combinator->Neither, indent);
/*T*/		xxx_nor(production, Combinator->Nor, indent);

/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_or_(char **production, Or_ *Or_, int indent) {
/*T*/		if(!Or_) return false;
/*T*/		if(opt_debug) printf("producing Or_\n");
  		padcat(indent?1:0, indent, production, " || ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_and(char **production, And *And, int indent) {
/*T*/		if(!And) return false;
/*T*/		if(opt_debug) printf("producing And\n");
  		padcat(indent?1:0, indent, production, " && ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_neither(char **production, Neither *Neither, int indent) {
/*T*/		if(!Neither) return false;
/*T*/		if(opt_debug) printf("producing Neither\n");
		padcat(1, indent, production, "( neither ");
		padcat(0, 0, production, ") ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_nor(char **production, Nor *Nor, int indent) {
/*T*/		if(!Nor) return false;
/*T*/		if(opt_debug) printf("producing Nor\n");
		padcat(1, indent, production, "( nor ");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_existence(char **production, Existence *Existence, int indent) {
		////// check and test for rule 'symbol be fixed'
/*T*/		if(!Existence) return false;
/*T*/		if(opt_debug) printf("producing Existence\n");
/*J+S*/		// padcat(0, 0, production, "(");
/*J+S*/		padcat(0, 0, production, "");
/*Sop*/		padcat(0, 0, production, "");
		assert(Existence->Symbol->Name); // should never need Existance->Symbol->Type->Literal
/*T*/		xxx_symbol(production, Existence->Symbol, indent+1);
/*S+S*/		const char *lst = lexsymtype(Existence->Symbol);
/*S+S*/		if(!lst || !strcmp(lst, "binary")) {
/*Sop*/			if(opt_harden)
/*Sop*/				padcat(0, 0, production, " == §§true§");
/*Sop*/			// else: nothing instead of " == true" and that both for !opt_harden and the outer if also for Sol
/*S+S*/		} else {
/*S+S*/			padcat(0, 0, production, " != ", nullvalue(LOW(snake_spaced(Existence->Symbol->Name)), !opt_harden)); ///// don't call with LOW buffer
/*S+S*/		}
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_negation(char **production, Negation *Negation, int indent) {
/*T*/		if(!Negation) return false;
/*T*/		if(opt_debug) printf("producing Negation\n");
/*JS */		xxx_negator(production, Negation->Negator, indent+1);
/*JS */		xxx_symbol(production, Negation->Symbol, indent+1);
		assert(Negation->Symbol->Name); // should never need Negation->Symbol->Type->Literal (?)
/*Sop*/		padcat(0, 0, production, "");
/*S+S*/		const char *lst = lexsymtype(Negation->Symbol);
/*S+S*/		if(!lst || !strcmp(lst, "binary")) {
/*Sop*/			if(!opt_harden) {
/*S+S*/				padcat(0, 0, production, "!");
/*S+S*/				xxx_symbol(production, Negation->Symbol, indent+1);
/*Sop*/			} else {
/*Sop*/				xxx_symbol(production, Negation->Symbol, indent+1);
/*Sop*/				padcat(0, 0, production, " == §§false§");
/*Sop*/			}
/*S+S*/		} else {
/*S+S*/			xxx_symbol(production, Negation->Symbol, indent+1);
/*S+S*/			padcat(0, 0, production, " == ", nullvalue(LOW(snake_spaced(Negation->Symbol->Name)), !opt_harden)); ///// don't call with LOW buffer
/*S+S*/		}
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_negator(char **production, Negator *Negator, int indent) {
/*T*/		if(!Negator) return false;
/*T*/		if(opt_debug) printf("producing Negator\n");
		padcat(0, 0, production, "!");
		inference = "bool";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_being(char **production, Being *Being, int indent) {
/*T*/	        if(!Being) return false;
/*T*/	        if(opt_debug) printf("producing Being\n");
		inference = "bool";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_true(char **production, True *True, int indent) {
/*T*/	        if(!True) return false;
/*T*/	        if(opt_debug) printf("producing True\n");
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_article(char **production, Article *Article, int indent) {
/*T*/		if(!Article) return false;
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_point_in_time(char **production, Point_In_Time *Point_In_Time, int indent) {
/*T*/		if(!Point_In_Time) return false;
/*T*/		if(opt_debug) printf("producing Point In Time\n");
/*T*/		xxx_current_time(production, Point_In_Time->Current_Time, indent+1);
/*T*/		xxx_relative_time(production, Point_In_Time->Relative_Time, indent+1);
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_current_time(char **production, Current_Time *Current_Time, int indent) {
/*T*/		if(!Current_Time) return false;
/*T*/		if(opt_debug) printf("producing Current_Time\n");
/*JS */		padcat(0, 0, production, "Date.now()");
/*Sol*/		padcat(0, 0, production, "block.timestamp");
/*Sop*/		padcat(0, 0, production, "Chain.timestamp");
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_relative_time(char **production, Relative_Time *Relative_Time, int indent) {
/*T*/		if(!Relative_Time) return false;
/*T*/		if(opt_debug) printf("producing Relative_Time\n");
		if(Relative_Time->Symbol) {
			padcat(0, 0, production, opt_harden?"Some":"", "(");
/*T*/	        	xxx_symbol(production, Relative_Time->Symbol, indent+1);
			padcat(0, 0, production, " + ");
		} else {
/*JS */			padcat(0, 0, production, "(Date.now() - ");
/*Sol*/			padcat(0, 0, production, "(block.timestamp - ");
/*Sop*/			padcat(0, 0, production, "(Chain.timestamp - ");
		}
/*T*/		xxx_duration(production, Relative_Time->Duration, indent+1);
		padcat(0, 0, production, ")");
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_duration(char **production, Duration *Duration, int indent) {
/*T*/		if(!Duration) return false;
/*T*/		if(opt_debug) printf("producing Duration\n");
		padcat(0, 0, production, "(");

/*T*/		xxx_scalar_expression(production, Duration->Scalar_Expression, indent+1);
		padcat(0, 0, production, " * ");
/*T*/		xxx_time_unit(production, Duration->Time_Unit, indent+1);
/*T*/
		padcat(0, 0, production, ")");
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_time_unit(char **production, Time_Unit *Time_Unit, int indent) {
/*T*/		if(!Time_Unit) return false;
/*T*/		if(opt_debug) printf("producing Time_Unit\n");
/*T*/	        xxx_years(production, Time_Unit->Years, indent+1);
/*T*/	        xxx_months(production, Time_Unit->Months, indent+1);
/*T*/	        xxx_weeks(production, Time_Unit->Weeks, indent+1);
/*T*/	        xxx_days(production, Time_Unit->Days, indent+1);
/*T*/	        xxx_hours(production, Time_Unit->Hours, indent+1);
/*T*/	        xxx_minutes(production, Time_Unit->Minutes, indent+1);
/*T*/	        xxx_seconds(production, Time_Unit->Seconds, indent+1);
/*T*/	        xxx_milliseconds(production, Time_Unit->Milliseconds, indent+1);
		inference = "uint";
/*T*/		return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_years(char **production, Years *Years, int indent) {
/*T*/	        if(!Years) return false;
/*T*/	        if(opt_debug) printf("producing Years\n");
/*JS */		padcat(0, 0, production, "31536000000");
/*Sol*/		padcat(0, 0, production, "31536000");
/*Sop*/		padcat(0, 0, production, "31536000000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_months(char **production, Months *Months, int indent) {
/*T*/	        if(!Months) return false;
/*T*/	        if(opt_debug) printf("producing Months\n");
/*JS */		padcat(0, 0, production, "2592000000");
/*Sol*/		padcat(0, 0, production, "2592000");
/*Sop*/		padcat(0, 0, production, "2592000000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_weeks(char **production, Weeks *Weeks, int indent) {
/*T*/	        if(!Weeks) return false;
/*T*/	        if(opt_debug) printf("producing Weeks\n");
/*JS */		padcat(0, 0, production, "604800000");
/*Sol*/		padcat(0, 0, production, "604800");
/*Sop*/		padcat(0, 0, production, "604800000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_days(char **production, Days *Days, int indent) {
/*T*/	        if(!Days) return false;
/*T*/	        if(opt_debug) printf("producing Days\n");
/*JS */		padcat(0, 0, production, "86400000");
/*Sol*/		padcat(0, 0, production, "86400");
/*Sop*/		padcat(0, 0, production, "86400000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_hours(char **production, Hours *Hours, int indent) {
/*T*/	        if(!Hours) return false;
/*T*/	        if(opt_debug) printf("producing Hours\n");
/*JS */		padcat(0, 0, production, "3600000");
/*Sol*/		padcat(0, 0, production, "3600");
/*Sop*/		padcat(0, 0, production, "3600000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_minutes(char **production, Minutes *Minutes, int indent) {
/*T*/	        if(!Minutes) return false;
/*T*/	        if(opt_debug) printf("producing Minutes\n");
/*JS */		padcat(0, 0, production, "60000");
/*Sol*/		padcat(0, 0, production, "60");
/*Sop*/		padcat(0, 0, production, "60000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_seconds(char **production, Seconds *Seconds, int indent) {
/*T*/	        if(!Seconds) return false;
/*T*/	        if(opt_debug) printf("producing Seconds\n");
/*JS */		padcat(0, 0, production, "1000");
/*Sol*/		padcat(0, 0, production, "1");
/*Sop*/		padcat(0, 0, production, "1000");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_milliseconds(char **production, Milliseconds *Milliseconds, int indent) {
/*T*/	        if(!Milliseconds) return false;
/*T*/	        if(opt_debug) printf("producing Milliseconds\n");
/*JS */		padcat(0, 0, production, "1");
/*Sol*/		padcat(0, 0, production, "0");
/*Sop*/		padcat(0, 0, production, "1");
		inference = "uint";
/*T*/	        return true;
/*T*/	}
/*T*/
/*T*/	bool xxx_expiration(char **production, Expiration *Expiration, int indent) {
/*T*/	        if(!Expiration) return false;
/*T*/	        if(opt_debug) printf("producing Expiration\n");

		/// note: 'has passed' means that the moment has happened that the millisecond was counted as passed -> <=
/*JS */		padcat(0, 0, production, " <= Date.now()");
/*Sol*/        	padcat(0, 0, production, " <= block.timestamp");
/*Sop*/		padcat(0, 0, production, " =< Chain.timestamp");
		inference = "bool";
/*T*/	        return true;
/*T*/	}
/*T*/

	/* Assign a parameter value to a class member, and create the declaration for the class member.
	   Optimized to unite the declaration of the member (and assigning it null) with setting its value
	   to the parameter immediately already in the declaration, instead of first setting it to null.
	   Uses text replacement in the production string, which might be based in part on 'this.' not being
	   used outside the constructor (but 'main.'), to work. */
	void insert_parameter_and_set_member(char **production, char **instructions, Symbol *symbol,
		bool payment, size_t paratag, int indent, int line) {

		/* callstack inspection: write calling line number into production. */
		if(_concat_trace)
			_concatnum(production, " ", line, "> ");

                char *pretty_varname;
		if(symbol->Name) pretty_varname = mtrac_strdup(LOW(snake_spaced(symbol->Name)));
		else if(symbol->Type) pretty_varname = mtrac_strdup(LOW(snake_spaced(symbol->Type->Literal)));
		else assert(false);

                char *symbol_name;
		if(symbol->Name) symbol_name = symbol->Name;
		else if(symbol->Type) symbol_name = symbol->Type->Literal;
		else assert(false);
		/// todo: double check that it is only alphanumeric, no " and \ etc

		if(opt_debug) printf("producing parameter %s\n", pretty_varname);

		// protect keywords
                char *varname = mtrac_strdup("");
		concat(&varname, SAFE(pretty_varname));

		// protect parameters with leading underscore (sol),
		// or not because this. or main or state. will be prefixed (js, sop).
                char *parameter_varname = mtrac_strdup("");
/*JS */		concat(&parameter_varname, pretty_varname); // same because member gets 'this.' or 'main.' prefixed
/*Sol*/		concat(&parameter_varname, "_", varname); // with SAFE() above can lead to double underscore
/*Sop*/		concat(&parameter_varname, pretty_varname); // same because member gets 'state.' prefixed

		// prepend type (sol, sop)
                char *typed_varname = mtrac_strdup("");
/*JS */		concat(&typed_varname, varname); // no type added for js
/*S+S*/		concat(&typed_varname, type(pretty_varname, opt_harden, false), " ", varname);

                char *pretty_typed_varname = mtrac_strdup("");
/*JS */		concat(&pretty_typed_varname, pretty_varname); // not type added for js
/*S+S*/		concat(&pretty_typed_varname, pretty_varname, " : ", type(pretty_varname, opt_harden, false));

                char *typed_parameter_varname = mtrac_strdup("");
/*JS */		concat(&typed_parameter_varname, parameter_varname); // not type added for js
/*Sol*/		concat(&typed_parameter_varname, type(pretty_varname, false, true), " ", parameter_varname);
/*Sop*/		concat(&typed_parameter_varname, parameter_varname, " : ", type(pretty_varname, false, true));

		/* binding to msg.sender and msg.value */
/*S+S*/		bool use_sender = !active_subjects && !msg_sender && !strcmp("person", lextype(pretty_varname));
/*S+S*/		if(use_sender) msg_sender = mtrac_strdup(pretty_varname);
		///////// printf("msgval %s %d ", msg_value, payment);
/*S+S*/		bool use_value = !msg_value && !strcmp("amount", lextype(pretty_varname)); ///// unclear, wip?: && payment;
/*S+S*/		if(use_value) msg_value = mtrac_strdup(pretty_varname);
/*S+S*/		is_payable |= !!use_value;
/*S+S*/		is_stateful = true;
/*S+S*/		///////// printf("%s: %d (%s)\n", pretty_varname, use_value, lextype(pretty_varname));

		/* 1: Add to the parameters and arguments list. In the produced code as well as (parameta) the instructions */
/*S+S*/		if(!use_sender && !use_value) {
			if(!current_function) {
				/* outside a function (constructor?/////) */
				padcat(0, 0, &parameters, *parameters?", ":"", typed_parameter_varname); ////// js was SAFE(varname)
				padcat(0, 0, &arguments, *arguments?", ":"", parameter_varname);
				if(instructions) padcat(0, 0, &parameta, *parameta?", ":"", "<", pretty_typed_varname, ">"); ///// js was varname
				//////// padcat(0, 0, &declared, ":", parameter_varname, ":"); // declared: write #4  ///// js was varname
				//////// note: changed to include underscore in some case
			} else {
				/* inside a function (clause) */
				padcat(0, 0, &current_function->parameters, *current_function->parameters?", ":"", typed_parameter_varname); ///// js was SAFE(varname)
				// arguments don't happen in this case
				if(instructions)
					padcat(0, 0, &current_function->parameta,
						*current_function->parameta?", ":"", "<", pretty_typed_varname, ">"); ///// js was varname
			}
/*S+S*/		}

		/* 2: Set the member to the parameter.  It's a member only if it's not a variable named for a type
		   (then found at Symbol->Type->Literal) */
		if(symbol->Name) {
			/* js: prep: we will (at [1]) look for, eg 'x = null;' in the previously produced */
/*JS */			char *nulling = mtrac_strdup("");
/*JS */			mtrac_concat(&nulling, "this.", varname, " = null;");
/*Sop*/			char *nulling = mtrac_strdup("");
/*Sop*/			mtrac_concat(&nulling, varname, " = ", nullmap(lextype(pretty_varname), !opt_harden));

			/* js: prep: .. to replace it (at [1]) with 'x = xpara;' */
			char *setting = mtrac_strdup("");
			char *initializing = mtrac_strdup("");
/*JS */			mtrac_concat(&setting, "this.", varname, " = ", varname, EOL);
			bool preassign = !!strstr(*production, "%preassign%");
/*S+S*/			int linebreak = preassign ? 1 : 0;
/*Sol*/			int setting_indent = preassign ? preass_indent : indent;
/*Sop*/			int setting_indent = preassign ? preass_indent : indent + 1;
/*S+S*/			if(use_sender) {
/*Sol*/				padcat(linebreak, setting_indent, &setting, varname, " = payable(msg.sender);");
/*Sop*/				padcat(linebreak, setting_indent, &setting, "put(state{", varname, " = §§Call.caller§})");
/*Sop*/				padcat(linebreak, setting_indent, &initializing, varname, " = §§Call.caller§");
/*S+S*/			} else if(use_value) {
/*Sol*/				padcat(1, 1, &declarations, "bool ", varname, "__set = false;");
/*S+S*/				if(!main_constructor_body && !covenant_constructor_body) {
/*Sol*/					padcat(linebreak, setting_indent, &setting, "if(", varname, "__set) {");
/*Sol*/					padcat(1, setting_indent+1, &setting, "require(msg.value == ", varname, ", \"wrong amount\");");
/*Sol*/					padcat(1, setting_indent, &setting, "} else {");
/*Sol*/					padcat(1, setting_indent+1, &setting, varname, " = msg.value;");
/*Sop*/					if(opt_harden) { ////// ? v v needed?
/*Sop*/						padcat(1, setting_indent, &setting, "put(state{", varname, " = option.default(0, state.", varname, ") + Call.value})");
/*Sop*/						//padcat(1, setting_indent+2, &setting, "Some(_) => abort(\"", symbol_name, " already paid\")");
/*Sop*/					} else {
/*Sop*/						if(opt_harden) {
/*Sop*/							padcat(1, setting_indent, &setting, "put(state{", varname, " = §§force(state.", varname, ", \"");
/*Sop*/							xxx_noun(&setting, symbol, 0);
/*Sop*/							padcat(0,0, &setting, "\") + Call.value§})");
/*Sop*/						} else {
/*Sop*/							padcat(1, setting_indent, &setting, "put(state{", varname, " = state.", varname, " + Call.value})");
/*Sop*/						}
/*Sop*/					}
/*Sop*/					padcat(1, setting_indent+1, &initializing, varname, " = §§Call.value§,");
/*Sol*/					padcat(1, setting_indent+1, &setting, varname, "__set = true;");
/*Sol*/					padcat(1, setting_indent, &setting, "}");
/*S+S*/				} else {
/*Sol*/					padcat(1, setting_indent, &setting, varname, " = msg.value;");
/*Sol*/					padcat(1, setting_indent, &setting, varname, "__set = true;");
/*Sop*/					padcat(1, setting_indent, &setting, varname, " ///= Call.value"); /////// needed?
/*Sop*/					padcat(0, 0, &initializing, varname, " = §§Call.value§", EOL);
/*S+S*/				}
/*S+S*/			} else {
/*Sol*/				padcat(linebreak, setting_indent, &setting, varname, " = ", parameter_varname, EOL);
/*Sop*/				padcat(linebreak, setting_indent, &setting, "put(state{", varname, " = §§", parameter_varname, "§})", EOL);
/*Sop*/				padcat(linebreak, setting_indent, &initializing, varname, " = §§", parameter_varname, "§", EOL);
/*S+S*/			}

/*JS */			/* 2a: optimized setting right in the declaration list (replacing '= null') */
/*JS */			//x// printf("\n\nOPT\n\n%d: %s\n\n%s\n\n", paratag, nulling, paratag>=0?*production+paratag:"");
/*JS */			if(paratag >= 0 && strstr(*production + paratag, nulling)) { ///// test for (conflicting) covenant symbols
/*JS */				replace_first_from(production, nulling, setting, *production + paratag); // [1]
/*JS */			} else

/*Sop*/			/* 2a: optimized setting right in the declaration list (replacing '= null') */
/*Sop*/			//x// printf("\n\nOPT\n\n%d: %s\n\n%s\n\n", paratag, nulling, paratag>=0?*production+paratag:"");
/*Sop*/			if((main_constructor_body || covenant_constructor_body) && strstr(initializations, nulling)) { ///// test for (conflicting) covenant symbols
/*Sop*/				replace_first_from(&initializations, nulling, initializing, initializations); // [1]
			/* 2b: set member immediately before the use of the value:
			   within functions (instead within the constructor) when a parameter's value is to be used,
			   and a member set to this value on the fly. The setting is inserted before the start of the
			   statement that the expression is nested in that uses the symbol in question. */
/*Sop*/			} else
				if(strstr(*production, "%preassign%")) {
/*S+S*/					replace(production, "%preassign%", setting); // insert before current statement
/*JS */					char *line = mtrac_strdup("");
/*JS */					padcat(1, preass_indent, &line, setting);
/*JS */					replace(production, "%preassign%", line); // insert before current statement
/*JS */					mtrac_free(line);
			}

			/* 2c: but if we could not find either, just create a member and assign the given parameter,
			   js: production will currently be at declaration height, so we effectively append to the member declaration list */
			else {
				padcat(1, indent, production, setting);
			}

/*JS */			mtrac_free(nulling);
/*Sop*/			mtrac_free(nulling);
			mtrac_free(setting);
			mtrac_free(initializing);
		}

		/* 3: track that this symbol has been set */
		padcat(0, 0, &fixed, ":", varname, ":"); /////// note: changed to include underscore in some cases

		mtrac_free(varname);
		mtrac_free(pretty_varname);
		mtrac_free(typed_varname);
		mtrac_free(parameter_varname);
		mtrac_free(typed_parameter_varname);
		mtrac_free(pretty_typed_varname);
        }

	void produce_access_conditions(int down, int indent, char **production, list *subjects) {

		if(!subjects) return;

		padcat(down, indent, production, "if(");
		list *s = subjects;
		int i = 0;
		while(s) {
			if(i++) padcat(0, 0, production, " || ");
			padcat(0, 0, production, "caller == ");
			xxx_name(production, (char *)s->item, 0);
			//.// if(current_function) current_function->uses_caller = true;
			s = s->next;
		}
		padcat(0, 0, production, ") {");
	}

	void error(char *msg, char *cargo) {
		printf("Lexon semantic error: %s %s%s%s\n", msg, cargo?"(":"", cargo?cargo:"", cargo?")":"");
		if(current_function) printf("In clause %s --\n", current_function->name);
		exit(1);
	}

/* end of file */
