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
  **    Lexon code production / AST walk target module
  */

  /*    javascript.c - Javascript backend       */

#define backend_version "javascript 0.3.99a U"
#define target_version "node 14.1+"

#define CYCLE_2 true

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define EOL ";"

#define LEXCOM0 "/*"
#define LEXCOM1 " | "
#define LEXCOM2 " */"

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
char **_mtrac_concat(char *file, int line, int down, int right, char **buf,
		     ...);
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
char **_concat(char *, char *, int, int, int, char **buf, ...);
char **_concatnum(char **buf, char *prefix, int number, char *postfix);
void yacc_printf(FILE * stream, char *format, ...);

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
#define C (2 + (opt_comment?0:1))

/* extern calls from lexon.l */
const char *str(int line);
extern struct Document *root;

bool js_document(char **production, struct Document *root, int indent);

#define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, false, #orig_, __FILE__, __LINE__)
extern char *_replace(char **orig, const char *rep, const char *with, int all,
		      char *from, bool whole, char *origname, char *file,
		      int line);
extern const char *str(int line);
static char *quote_trimmed(const char *token);
static char *dash_spaced(const char *token);
extern char *snake_spaced(const char *token);
extern char *camel_spaced(const char *token);
extern char *SNAKE(const char *token);
extern char *snakedup(const char *token);
extern char *UP(const char *token);

static char *safedup(const char *token);
static const char *type(const char *varname, bool option_type, bool forpara,
			int);
static const char *nullmap(const char *lex_type, bool defined_default);
static const char *defaultmap(const char *lex_type);
static const char *lextype(const char *varname);
static const char *typemap(const char *lextype, bool option_type, bool forpara,
			   int);
static const char *nullvalue(const char *name, bool defined_default);

static char *methods = null;
static char *globals = null;	       // element members of main
static char *declarations = null;
static char *initializations = null;
static char *main_interface = null;
static char *command_init = null;
static bool beyond_assignment = false;
static char *fixed = null;	       // list of variables that have been set
static char *args = null;	       // list of variables that come in as paremeters
static char *functions = null;
static char *safedup(const char *name) {
	assert(name);
	char *_safe = mtrac_malloc(strlen(name) + 3);

	strcpy(_safe, " ");
	strcat(_safe, name);
	strcat(_safe, " ");

	if (!strstr(" main notify terminate terminated default "	// Lexon ◊
		    " abstract arguments await boolean break byte case catch"
		    " char class const continue debugger default delete do"
		    " double else enum eval export extends false final"
		    " finally float for function goto if implements import"
		    " in instanceof int interface let long native new"
		    " null package private protected public return short static"
		    " super switch synchronized this throw throws transient true"
		    " try typeof var void volatile while with yield ", _safe)) {

		strcpy(_safe, name);

	} else {
		strcpy(_safe, name);
		strcat(_safe, "_");

	}

	return _safe;
}

typedef struct list {
	void *item;
	struct list *next;
} list;

static void list_add(list **l, void *item) {
	list *n = mtrac_malloc(sizeof (list));

	n->item = item;
	n->next = *l;
	*l = n;
}

static list *shallow_clone(list *l) {
	list *clone = null;

	while (l) {
		list_add(&clone, l->item);
		l = l->next;
	}
	return clone;
}

static int drop_item(list **l, list *drop) {
	int count = 0;
	list *cur = *l, *prev = null;

	while (cur) {
		if (cur->item == drop->item) {
			if (prev) prev->next = cur->next;
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

	while ((m = l)) l = l->next, mtrac_free(m);
}

static void delete_list_and_items(list *l) {
	list *m;

	while ((m = l)) l = l->next, mtrac_free(m->item), mtrac_free(m);
}

/* this is an optimization to not have all functions require a caller.
   This is almost an optical nuance but really about not confusing
   users with compilation artifacts. */

static int bind_index = 100;
typedef struct bind {
	int index;
	char *tag;
	char *lexname;
	char *name;
	char *parameters;
	char *arguments;
	char *parameta;		       // for instructions, wrapped in < >
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

static bool traverse_for_caller(bind * bind, int fuse);
static void produce_access_conditions(int down, int indent, char **production,
				      list * subjects);

static void inject_transfer(char **production, int indent);
static void inject_notify(char **production, char **emits, int indent);
static void inject_termination(char **production, char *prompt, int indent);

/* create or find a binding for a function name */
static bind *register_bind(char *name, char *lexname) {

	assert(name && strlen(name));
	bind *bind = binds;

	while (bind && strcmp(name, bind->name)) bind = bind->next;
	if (!bind) {
		bind = mtrac_malloc(sizeof (struct bind));	// sic
		bind->index = bind_index++;
		bind->tag = mtrac_strdup("");
		mtrac_concat(&bind->tag, "%", str(bind->index), "%");
		bind->lexname = mtrac_strdup(lexname);
		bind->name = mtrac_strdup(name);
		bind->parameters = mtrac_strdup("");
		bind->arguments = mtrac_strdup("");
		bind->parameta = mtrac_strdup("");
		bind->uses_caller = false;
		bind->uses_permission = false;
		bind->changes_state = false;
		bind->calls = null;
		bind->next = null;
		if (!binds) binds = bind;
		if (last_bind) last_bind->next = bind;
		last_bind = bind;
	}
	return bind;
}

/* register a call and receive the point to be set to the coming next one */
static call **register_call(call **prevnext, char *to, char *lexname) {
	call *call = mtrac_malloc(sizeof (call));

	call->bind = register_bind(to, lexname);
	call->next = null;
	*prevnext = call;
	return &call->next;
}

static void replace_bind_tags(char **production, char **instructions, bind *b) {

	while (b) {
		char *head = mtrac_strdup("");
		char *ihead = mtrac_strdup("");

		mtrac_concat(&head, b->name);
		mtrac_concat(&ihead, b->name);

		if (traverse_for_caller(b, 10)) {
			mtrac_concat(&head, "(caller",
				     strlen(b->parameters) ? ", " : "",
				     b->parameters, ")");
			if (!strlen(b->parameta))	/* sic: instructions have the subject (caller) in parameta */
				mtrac_concat(&ihead, "(<caller>)");
			else
				mtrac_concat(&ihead, "(", b->parameta, ")");

		} else {
			mtrac_concat(&head, "(", b->parameters, ")");
			mtrac_concat(&ihead, "(", b->parameta, ")");
		}

		/* now replace the tags standing in for the function declaration head and all calls to the function in the production string */
		replace(production, b->tag, head);
		replace(instructions, b->tag, ihead);	// private functions will just not have a tag to match

		mtrac_free(head);
		mtrac_free(ihead);
		b = b->next;
	}
}

static bool traverse_for_caller(bind *bind, int fuse) {
	if (bind->uses_caller) return true;
	if (!fuse) return false;
	call *c = bind->calls;

	while (c) {
		if (traverse_for_caller(c->bind, fuse - 1)) return true;
		c = c->next;
	}
	return false;
}

static void delete_bind_tree(bind *b) {
	while (b) {
		call *cc, *c = b->calls;

		while (c) {
			cc = c->next;
			mtrac_free(c);
			c = cc;
		}
		mtrac_free(b->lexname);
		mtrac_free(b->name);
		mtrac_free(b->tag);
		if (b->parameters) mtrac_free(b->parameters);
		if (b->arguments) mtrac_free(b->arguments);
		if (b->parameta) mtrac_free(b->parameta);
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

typedef struct Document {
	struct Head *Head;
	struct Terms *Terms;
	struct Covenants *Covenants;
} Document;

typedef struct Head {
	struct Lex *Lex;
	struct Preamble *Preamble;
	struct Comment *Comment;
	struct Authors *Authors;
	struct Lexon *Lexon;
} Head;

typedef struct Lex {
	Name *Name;
} Lex;

typedef struct Lexon {
	Description *Description;
} Lexon;

typedef struct Authors {
	Description *Description;
} Authors;

typedef struct Comment {
	Description *Description;
} Comment;

typedef struct Preamble {
	Description *Description;
} Preamble;

typedef struct Terms {
	struct Provisions *Provisions;
} Terms;

typedef struct Covenants {
	struct Covenant *Covenant;
	struct Covenants *Covenants;
} Covenants;

typedef struct Covenant {
	Name *Name;
	struct Provisions *Provisions;
} Covenant;

typedef struct Provisions {
	struct Definitions *Definitions;
	struct Clauses *Clauses;
	struct Statements *Statements;
} Provisions;

typedef struct Definitions {
	struct Definition *Definition;
	struct Definitions *Definitions;
} Definitions;

typedef struct Definition {
	Name *Name;
	struct Type_Term *Type_Term;
	struct Article *Article;
	struct This_Contract *This_Contract;
	Literal *Literal;
} Definition;

typedef struct Type_Term {
	struct Type *Type;
	struct Article *Article;
	Literal *Literal;
} Type_Term;

typedef struct Type {
	struct Person *Person;
	struct Amount *Amount;
	struct Time *Time;
	struct Binary *Binary;
	struct Text *Text;
	struct Data *Data;
	Literal *Literal;
} Type;

typedef struct Person {
	Literal *Literal;
} Person;

typedef struct Amount {
	Literal *Literal;
} Amount;

typedef struct Time {
	Literal *Literal;
} Time;

typedef struct Binary {
	Literal *Literal;
} Binary;

typedef struct Text {
	Literal *Literal;
} Text;

typedef struct Data {
	Literal *Literal;
} Data;

typedef struct This_Contract {
	struct This *This;
	Name *Name;
	Literal *Literal;
} This_Contract;

typedef struct All_Contracts {
	Literal *Literal;
} All_Contracts;

typedef struct This {
	Literal *Literal;
} This;

typedef struct Clauses {
	struct Clause *Clause;
	struct Clauses *Clauses;
} Clauses;

typedef struct Clause {
	Name *Name;
	struct Body *Body;
} Clause;

typedef struct Body {
	struct Statements *Statements;
	struct Function *Function;
} Body;

typedef struct Function {
	Name *Name;
	struct Illocutor *Illocutor;
	struct Expression *Expression;
	struct Article *Article;
} Function;

typedef struct Statements {
	struct Statement *Statement;
	struct Statements *Statements;
} Statements;

typedef struct Statement {
	struct Action *Action;
	struct Flagging *Flagging;
} Statement;

typedef struct Actions {
	struct Action *Action;
	struct Actions *Actions;
} Actions;

typedef struct Action {
	struct Subject *Subject;
	struct Predicates *Predicates;
	struct Permission *Permission;
	struct Condition *Condition;
} Action;

typedef struct Subject {
	struct Symbols *Symbols;
} Subject;

typedef struct Symbols {
	struct Symbol *Symbol;
	struct Symbols *Symbols;
	struct Catena *Catena;
} Symbols;

typedef struct Symbol {
	Name *Name;
	struct New *New;
	struct Article *Article;
	struct Type *Type;
} Symbol;

typedef struct Catena {
} Catena;

typedef struct Object {
	struct Symbol *Symbol;
	struct Reflexive *Reflexive;
} Object;

typedef struct Reflexive {
	Literal *Literal;
} Reflexive;

typedef struct Contract {
	struct This_Contract *This_Contract;
	struct All_Contracts *All_Contracts;
} Contract;

typedef struct Predicates {
	struct Predicates *Predicates;
	struct Predicate *Predicate;
} Predicates;

typedef struct Predicate {
	struct Certification *Certification;
	struct Declaration *Declaration;
	struct Filing *Filing;
	struct Registration *Registration;
	struct Grantment *Grantment;
	struct Appointment *Appointment;
	struct Acceptance *Acceptance;
	struct Fixture *Fixture;
	struct Setting *Setting;
	struct Payment *Payment;
	struct Sending *Sending;
	struct Notification *Notification;
	struct Termination *Termination;
} Predicate;

typedef struct Permission {
} Permission;

typedef struct Certification {
	struct Certify *Certify;
	struct Symbol *Symbol;
	struct Expression *Expression;
	struct Contract *Contract;
} Certification;

typedef struct Certify {
} Certify;

typedef struct Declaration {
	struct Declare *Declare;
	struct Symbol *Symbol;
	struct Expression *Expression;
	struct Contract *Contract;
} Declaration;

typedef struct Declare {
} Declare;

typedef struct Filing {
	struct File *File;
	struct Symbol *Symbol;
	struct Expression *Expression;
	struct Contract *Contract;
} Filing;

typedef struct File {
} File;

typedef struct Registration {
	struct Register *Register;
	struct Symbol *Symbol;
	struct Expression *Expression;
	struct Contract *Contract;
} Registration;

typedef struct Register {
} Register;

typedef struct Grantment {
	struct Grant *Grant;
	struct Symbol *Symbol;
} Grantment;

typedef struct Grant {
} Grant;

typedef struct Appointment {
	struct Appoint *Appoint;
	struct Symbol *Symbol;
	struct Expression *Expression;
} Appointment;

typedef struct Appoint {
} Appoint;

typedef struct Acceptance {
	struct Accept *Accept;
	struct Symbol *Symbol;
	struct Expression *Expression;
	Literal *Literal;
} Acceptance;

typedef struct Accept {
} Accept;

typedef struct Fixture {
	struct Fix *Fix;
	struct Symbol *Symbol;
	struct Expression *Expression;
	struct Contract *Contract;
} Fixture;

typedef struct Fix {
} Fix;

typedef struct Setting {
	struct Illocutor *Illocutor;
	struct Symbol *Symbol;
} Setting;

typedef struct Illocutor {
	struct Be *Be;
} Illocutor;

typedef struct Be {
} Be;

typedef struct Payment {
	struct Pay *Pay;
	struct Expression *Expression;
	struct Preposition *Preposition;
	struct Object *Object;
	struct From_Escrow *From_Escrow;
	struct Escrow *Escrow;
	Literal *Literal;
} Payment;

typedef struct Pay {
	Literal *Literal;
} Pay;

typedef struct Preposition {
	Literal *Literal;
} Preposition;

typedef struct Escrow {
	Literal *Literal;
} Escrow;

typedef struct From_Escrow {
	Literal *Literal;
} From_Escrow;

typedef struct Sending {
	struct Send *Send;
	struct Expression *Expression;
	struct Preposition *Preposition;
	struct Object *Object;
	Literal *Literal;
} Sending;

typedef struct Send {
} Send;

typedef struct Notification {
	struct Notify *Notify;
	struct Object *Object;
	struct Preposition *Preposition;
	struct Expression *Expression;
} Notification;

typedef struct Notify {
} Notify;

typedef struct Termination {
	struct Terminate *Terminate;
	struct This_Contract *This_Contract;
	struct All_Contracts *All_Contracts;
} Termination;

typedef struct Terminate {
} Terminate;

typedef struct Flagging {
	struct Illocutor *Illocutor;
	struct Symbol *Symbol;
	struct This_Contract *This_Contract;
} Flagging;

typedef struct Condition {
	struct If *If;
	struct Expression *Expression;
} Condition;

typedef struct If {
} If;

typedef struct Expression {
	struct Combination *Combination;
	Literal *Literal;
} Expression;

typedef struct Scalar_Comparison {
	struct Scalar_Expression *Scalar_Expression;
	struct Comparison_Operator *Comparison_Operator;
	struct Scalar_Expression *Scalar_Expression2;
} Scalar_Comparison;

typedef struct Hex_Expression {
	struct Symbol *Symbol;
	Hex *Hex;
	// struct Point_In_Time *Point_In_Time;
} Hex_Expression;

typedef struct Comparison_Operator {
	struct Equal *Equal;
	struct Greater *Greater;
	struct Less *Less;
	struct Later *Later;
	Literal *Literal;
} Comparison_Operator;

typedef struct Equal {
	Literal *Literal;
} Equal;

typedef struct Greater {
	Literal *Literal;
} Greater;

typedef struct Less {
	Literal *Literal;
} Less;

typedef struct Later {
	Literal *Literal;
} Later;

typedef struct Scalar_Expression {
	struct Symbol *Symbol;
	Scalar *Scalar;
	struct Point_In_Time *Point_In_Time;
} Scalar_Expression;

typedef struct Combination {
	struct Combinor *Combinor;
	struct Combination *Combination;
	struct Combinator *Combinator;
} Combination;

typedef struct Combinor {
	struct Combinand *Combinand;
	struct Combinator *Combinator;
	struct Combinor *Combinor;
} Combinor;

typedef struct Combinand {
	struct Symbol *Symbol;
	struct Expiration *Expiration;
	struct Timeliness *Timeliness;
	struct Reflexive *Reflexive;
	Description *Description;
	struct Article *Article;
	struct Scalar_Comparison *Scalar_Comparison;
	struct Negation *Negation;
	struct Existence *Existence;
	struct Point_In_Time *Point_In_Time;
} Combinand;

typedef struct Combinator {
	struct Or_ *Or_;
	struct And *And;
	struct Neither *Neither;
	struct Nor *Nor;
} Combinator;

typedef struct Or_ {
} Or_;

typedef struct And {
} And;

typedef struct Neither {
} Neither;

typedef struct Nor {
} Nor;

typedef struct Existence {
	struct Symbol *Symbol;
	struct Contract *Contract;
	struct Equal *Equal;
	struct Be *Be;
	struct Being *Being;
	struct True *True;
} Existence;

typedef struct Negation {
	struct Negator *Negator;
	struct Symbol *Symbol;
	struct Contract *Contract;
} Negation;

typedef struct Negator {
	struct Be *Be;
} Negator;

typedef struct Being {
} Being;

typedef struct True {
} True;

typedef struct Article {
} Article;

typedef struct New {
	Literal *Literal;
} New;

typedef struct Point_In_Time {
	struct Current_Time *Current_Time;
	struct Relative_Time *Relative_Time;
} Point_In_Time;

typedef struct Current_Time {
} Current_Time;

typedef struct Relative_Time {
	struct Duration *Duration;
	struct Symbol *Symbol;
} Relative_Time;

typedef struct Duration {
	struct Scalar_Expression *Scalar_Expression;
	struct Time_Unit *Time_Unit;
} Duration;

typedef struct Time_Unit {
	struct Years *Years;
	struct Months *Months;
	struct Weeks *Weeks;
	struct Days *Days;
	struct Hours *Hours;
	struct Minutes *Minutes;
	struct Seconds *Seconds;
	struct Milliseconds *Milliseconds;
} Time_Unit;
typedef struct Years {
} Years;

typedef struct Months {
} Months;

typedef struct Weeks {
} Weeks;

typedef struct Days {
} Days;

typedef struct Hours {
} Hours;

typedef struct Minutes {
} Minutes;

typedef struct Seconds {
} Seconds;

typedef struct Milliseconds {
} Milliseconds;

typedef struct Expiration {
} Expiration;

typedef struct Timeliness {
	Literal *Literal;
} Timeliness;

static void insert_parameter_and_set_member(char **production,
					    char **instructions,
					    Symbol * symbol, bool payment,
					    size_t paratag, int indent,
					    int line);

bool js_walk(char **production);
bool js_name(char **production, Name * Name, bool assign, int indent);
bool js_description(char **production, Description * Description, int indent);
bool js_scalar(char **production, Scalar * Scalar, int indent);
bool js_hex(char **production, Hex * Hex, int indent);

static const char *lexsymtype(Symbol * symbol);

/* AST walk (stub) functions */

bool js_document(char **production, Document * Document, int indent);
bool js_head(char **production, Head * Head, int indent);
bool js_lex(char **production, Lex * Lex, int indent);
bool js_lexon(char **production, Lexon * Lexon, int indent);
bool js_authors(char **production, Authors * Authors, int indent);
bool js_comment(char **production, Comment * Comment, int indent);
bool js_preamble(char **production, Preamble * Preamble, int indent);
bool js_terms(char **production, Terms * Terms, int indent);
bool js_covenants(char **production, Covenants * Covenants, int indent);
bool js_covenant(char **production, Covenant * Covenant, int indent);
bool js_provisions(char **production, Provisions * Provisions, int indent);
bool js_definitions(char **production, Definitions * Definitions, int indent);
bool js_definition(char **production, Definition * Definition, int indent);
bool js_clauses(char **production, Clauses * Clauses, int indent);
bool js_clause(char **production, Clause * Clause, int indent);
bool js_body(char **production, Body * Body, int indent);
bool js_function(char **production, Function * Function, int indent);
bool js_statements(char **production, Statements * Statements, int indent);
bool js_statement(char **production, Statement * Statement, int indent);
bool js_actions(char **production, Actions * Actions, int indent);
bool js_action(char **production, Action * Action, int indent);
bool js_subject(char **production, Subject * Subject, int indent);
bool js_symbols(char **production, Symbols * Symbols, int indent);
bool js_symbol(char **production, Symbol * Symbol, bool assign, int indent);
bool js_noun(char **production, Symbol * Symbol, int indent);
bool js_catena(char **production, Catena * Catena, int indent);
bool js_object(char **production, Object * Object, int indent);
bool js_reflexive(char **production, Reflexive * Reflexive, int indent);
bool js_predicates(char **production, Predicates * Predicates, int indent);
bool js_predicate(char **production, Predicate * Predicate, int indent);
bool js_certification(char **production, Certification * Certification,
		      int indent);
bool js_declaration(char **production, Declaration * Declaration, int indent);
bool js_filing(char **production, Filing * Filing, int indent);
bool js_registration(char **production, Registration * Registration,
		     int indent);
bool js_grantment(char **production, Grantment * Grantment, int indent);
bool js_appointment(char **production, Appointment * Appointment, int indent);
bool js_acceptance(char **production, Acceptance * Acceptance, int indent);
bool js_fixture(char **production, Fixture * Fixture, int indent);
bool js_setting(char **production, Setting * Setting, int indent);
bool js_payment(char **production, Payment * Payment, int indent);
bool js_pay(char **production, Pay * Pay, int indent);
bool js_escrow(char **production, Escrow * Escrow, int indent);
bool js_from_escrow(char **production, From_Escrow * From_Escrow, int indent);
bool js_sending(char **production, Sending * Sending, int indent);
bool js_send(char **production, Send * Send, int indent);
bool js_notification(char **production, Notification * Notification,
		     int indent);
bool js_notify(char **production, Notify * Notify, int indent);
bool js_termination(char **production, Termination * Termination, int indent);
bool js_terminate(char **production, Terminate * Terminate, int indent);
bool js_flagging(char **production, Flagging * Flagging, int indent);
bool js_condition(char **production, Condition * Condition, int indent);
bool js_if(char **production, If * If, int indent);
bool js_expression(char **production, Expression * Expression, int indent);
bool js_scalar_comparison(char **production,
			  Scalar_Comparison * Scalar_Comparison, int indent);
bool js_comparison_operator(char **production,
			    Comparison_Operator * Comparison_Operator,
			    int indent);
bool js_equal(char **production, Equal * Equal, int indent);
bool js_greater(char **production, Greater * Greater, int indent);
bool js_less(char **production, Less * Less, int indent);
bool js_later(char **production, Later * Later, int indent);
bool js_scalar_expression(char **production,
			  Scalar_Expression * Scalar_Expression, int indent);
bool js_combination(char **production, Combination * Combination, int indent);
bool js_combinor(char **production, Combinor * Combinor, int indent);
bool js_combinand(char **production, Combinand * Combinand, int indent);
bool js_combinator(char **production, Combinator * Combinator, int indent);
bool js_or_(char **production, Or_ * Or_, int indent);
bool js_and(char **production, And * And, int indent);
bool js_neither(char **production, Neither * Neither, int indent);
bool js_nor(char **production, Nor * Nor, int indent);
bool js_existence(char **production, Existence * Existence, int indent);
bool js_negation(char **production, Negation * Negation, int indent);
bool js_negator(char **production, Negator * Negator, int indent);
bool js_being(char **production, Being * Being, int indent);
bool js_true(char **production, True * True, int indent);
bool js_article(char **production, Article * Article, int indent);
bool js_point_in_time(char **production, Point_In_Time * Point_In_Time,
		      int indent);
bool js_current_time(char **production, Current_Time * Current_Time,
		     int indent);
bool js_relative_time(char **production, Relative_Time * Relative_Time,
		      int indent);
bool js_duration(char **production, Duration * Duration, int indent);
bool js_time_unit(char **production, Time_Unit * Time_Unit, int indent);
bool js_years(char **production, Years * Years, int indent);
bool js_months(char **production, Months * Months, int indent);
bool js_weeks(char **production, Weeks * Weeks, int indent);
bool js_days(char **production, Days * Days, int indent);
bool js_hours(char **production, Hours * Hours, int indent);
bool js_minutes(char **production, Minutes * Minutes, int indent);
bool js_seconds(char **production, Seconds * Seconds, int indent);
bool js_milliseconds(char **production, Milliseconds * Milliseconds,
		     int indent);
bool js_expiration(char **production, Expiration * Expiration, int indent);
bool js_timeliness(char **production, Timeliness * Timeliness, int indent);

static bool is_payment(Predicates *predicates) {
	while (predicates) {
		if (predicates->Predicate->Payment)
			return true;
		predicates = predicates->Predicates;
	}
	return false;
}

/* AST walk functions ----------------------------------------------------- */

static char *requires = "";
static char *module = null;
static bind *current_function = null;
static bool single_sentence_clause = true;
static bool multi_sentence_clause = false;
static bool no_literal = false;
static char *msg_sender = null;
static char *msg_value = null;
static bool is_payable = false;
static bool payment_expression = false;
static char *inference = null;

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

static char *instructions =
	"\n\n   INSTRUCTIONS FOR USE:\n\n"
	"   Execute this program using node. Replace the <parameters> with literal values.\n\n"
	"   Running this program as-is requires beginners programmer knowledge. This phase is\n"
	"   yet not covered by lexon's mission to make code readable and useful for non-coders.\n"
	"   In the future, an interface will be generated to complete this last mile. However,\n"
	"   embedding this code into a self-explanatory user interface is a straight forward\n"
	"   task for a full-stack programmer.\n\n"
	"   Note that the instructions below reflect your lexon code as well as the parameters\n"
	"   used during compilation of the code: different functions and parameters will result\n"
	"   from different input. Some functions are 'built-in' but only appear when needed as\n"
	"   per compiled-in features – a list of which is available with lexon -h. The functions\n"
	"   are not given in a specific order of execution but as listed in the lexon source.\n\n"
	"%00%"
	"   Parameters below are marked with double angle brackets << >> for the respective\n"
	"   required caller. If the role is defined earlier, it can only be performed by this\n"
	"   person. (But remember that this entire setup is trustful: anyone can manipulate\n"
	"   anything about this contract. Though they cannot sign it or change the signed log.)\n"
	"   If the role is not defined earlier, the call makes the role be assigned to the\n"
	"   person named for the call. Some functions can be called without naming a caller.\n"
	"   Some clauses of the original lexon source will not appear below. Namely, those\n"
	"   that have no permission phrase, wherefore they are regarded as internal.\n\n"
	"   The main contract system is initialized by loading the module and instantiating:\n\n"
	"   $ node\n" "   > contract = require(\"./%4%\");\n"
	"   > %contract% = new contract(%6%);\n\n"
	"   Remember to reset node's module cache each time you edit and recompile your code:\n\n"
	"   > delete require.cache[require.resolve('./%4%')];\n\n"
	"   These are the state progress functions that allow to interact with the contract:\n";
static bool enforce_same_subject = false;
static list *active_subjects = null;
static list *covenant_subjects = null;
static bool no_action_in_group_yet = true;
static bool uses_main = true;
static bool uses_termination = false;
static bool uses_transfer = false;
static bool uses_notification = false;

static bool has_subclasses = false;
static void optional_caller(char **production) {
	if (opt_log)
		concat(production, !current_function
		       && active_subjects ? SNAKE(active_subjects->
						  item) : "caller", ", ");
}

bool js_walk(char **production) {
	if (!root) return false;
	return js_document(production, root, 0);
}

static Name *class = null;
static bool main_constructor_body = true;
static bool main_contract = true;
static bool covenant_constructor_body = false;
static bool terms_body = true;
static bool recital_of_terms = false;
bool js_name(char **production, Name *Name, bool assign, int indent) {
	if (!Name) return false;

	/* put '_' to names that are target language keywords */
	char *safe = safedup(SNAKE(Name));
	bool global = in(globals, Name) && class;

	if (!in(functions, Name)) {
		padcat(0, 0, production,
		       global &&!main_constructor_body ? "main." : "this.",
		       safe);
	} else {
		bind *bind = register_bind(safe, Name);
		padcat(0, 0, production,
		       global &&!main_constructor_body ? "main." : "this.",
		       bind->tag);
	}
	if (assign) padcat(0, 0, &fixed, ":", safe, ":");
	mtrac_free(safe);
	return true;
}

bool js_description(char **production, Description *Description, int indent) {
	if (!Description) return false;
	padcat(0, 0, production, "\"", Description, "\"");
	return true;
}

bool js_scalar(char **production, Scalar *Scalar, int indent) {
	if (!Scalar) return false;
	padcat(0, 0, production, Scalar);
	return true;
}

bool js_hex(char **production, Hex *Hex, int indent) {
	if (!Hex) return false;
	padcat(0, 0, production, Hex);
	return true;
}
bool js_document(char **production, Document *Document, int indent) {
	if (!Document) return false;
	if (opt_debug) printf("producing Document\n");

	/* switch line# trace of every concat to code output buffer */
	_concat_trace = opt_debug_production;

	/* source code head */
	if (!opt_bare) padcat(0, indent, production,
			      "/** Lexon-generated Javascript ");
	if (!opt_bare) padcat(1, indent, production, " **");

	assert(!parameters);
	assert(!arguments);
	assert(!args);
	methods = mtrac_strdup("");
	globals = mtrac_strdup("");
	declarations = mtrac_strdup("");
	initializations = mtrac_strdup("");
	fixed = mtrac_strdup("");
	class_lists = mtrac_strdup("");
	restorers = mtrac_strdup("");
	adders = mtrac_strdup("");
	parameters = mtrac_strdup("");
	arguments = mtrac_strdup("");
	args = mtrac_strdup("");
	parameta = mtrac_strdup("");
	emits = mtrac_strdup("");
	functions = mtrac_strdup("");
	requires = mtrac_strdup(requires);

	/* instructions are being built up in parallel, eventually prepent.
	 * They will be built up for naught and discarded if opt_instructions is not set. */
	instructions = mtrac_strdup(instructions);

	char *file = mtrac_strdup(opt_source ? opt_source : "contract");

	replace(&file, ".lex", "");
	concat(&file, ".jsx");
	replace(&instructions, "%4%", file);

	/* create a name for the instance variable */
	char *optcpy = mtrac_strdup(opt_source ? opt_source : "instance");
	char *rump = optcpy;

	if (strrchr(rump, '/')
	    && *(strrchr(rump, '/') + 1)) rump = strrchr(rump, '/') + 1;
	while (*rump) {
		while (*rump && strchr("/.-0123456789", *rump)) rump++;
		if (*rump
		    && strcspn(rump,
			       "/.-0123456789") > 1) *(rump + strcspn(rump,
								      "/.-0123456789"))
			  = 0;
		else if (*rump && strcspn(rump, "/.-0123456789") == 1
			 && strlen(rump) > 2) {
			rump += 2;
			continue;
		}
		break;
	}
	char *instance_var_name = mtrac_strdup(rump ? rump : "instance");

	mtrac_free(optcpy);

	/* obtain the names of the clauses */
	Clauses *clauses =
		!Document->Terms ? null : (!Document->Terms->
					   Provisions ? null : Document->Terms->
					   Provisions->Clauses);
	while (clauses) {
		char *name = !clauses->Clause ? null : clauses->Clause->Name;

		if (name) mtrac_concat(&functions, ":", name, ":");
		clauses = clauses->Clauses;
	}

	js_head(production, Document->Head, indent);

	/* includes - depending on what is needed */
	if (opt_log || opt_signatures || opt_persistence
	    || opt_email) padcat(2, indent, production,
				 "var fs = require('fs');");
	if (opt_log
	    && (opt_chaining
		|| opt_signatures)) padcat(1, indent, production,
					   "var crypto = require('crypto');");
	if (opt_persistence) padcat(1, indent, production,
				    "var serialize = require('serialize-javascript');");
	if (opt_log
	    && opt_signatures) padcat(1, indent, production,
				      "var prompt = require('prompt-sync')();");
	if (opt_bundle) padcat(1, indent, production,
			       "var tar = require('tar');");
	if (opt_email) padcat(1, indent, production,
			      "var nodemailer = require('nodemailer');");
	if (opt_log
	    && opt_signatures) padcat(1, indent, production,
				      "var last_caller;");
	if (opt_log
	    && opt_signatures) padcat(1, indent, production,
				      "var last_passphrase;");
	/* comments */
	if (opt_comment) {
		padcat(2, indent, production, "/**");
		padcat(1, indent, production, " **");
		padcat(1, indent, production, " **\tMain ", module,
		       " contract system");
		padcat(1, indent, production, " **");
		padcat(1, indent, production, " **/");
	}

	if (opt_comment || opt_lexon_comments)
		padcat(1, 0, production, "");

	/* lexon text head as extended code comment */
	if (opt_lexon_comments) {
		char *c = mtrac_strdup(get_lexcom("start"));

		replace(&c, "\n", "\n" LEXCOM1 "\t");
		replace(&c, "\n" LEXCOM1 "\t\n", "\n" LEXCOM1 "\n");
		padcat(1, 0, production, LEXCOM0 "\n" LEXCOM1 "\t", c,
		       "\n" LEXCOM2);
		mtrac_free(c);
	}

	/* main contract's constructor */
	paratag = strlen(*production);
	if (!opt_bare) padcat(2, indent, production, "");
	padcat(0, indent, production, "module.exports = class ", camel_spaced(module), " {%21%");	// %21%: member initialization by parameters
	padcat(1, indent + 1, production, "constructor(%1%) {");	// sic not C. %1%: constructor parameters
	padcat(1, 0, production, "%20%");	// %20%: closure 'main = this'

	main_constructor_body = true;
	main_contract = true;
	assert(active_subjects == null);
	js_terms(production, Document->Terms, indent + 2);	// sets caller, uses methods variable for production string
	main_constructor_body = false; // off for non-JS? ◊
	main_contract = false;
	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = null;

	replace(production, "%1%", parameters);
	/* covenants
	 * js: like all non-covenant clauses, the entire covenant class definition including all their clauses,
	 * are hidden in the scope of the main, top level constructor */
	js_covenants(production, Document->Covenants, indent + 2);
	/* note this must follow after the class definitions, to be able to use the main_constructor_bodys in `restorers` */
	if (opt_persistence) {
		if (opt_comment) padcat(2, indent + 2, production,
					"/* restore object from file - must be below class definition */");
		padcat(C, indent + 2, production, "if(typeof ", caller,
		       " === 'undefined') {");
		padcat(1, indent + 3, production,
		       "console.log(\"> restore from file '", opt_persistence,
		       "'\");");
		padcat(1, indent + 3, production,
		       "let data = fs.readFileSync('", opt_persistence,
		       "', ()=>{});");
		padcat(1, indent + 3, production,
		       "let live = eval('(' + data + ')');");
		padcat(1, indent + 3, production, "Object.assign(this, live);");
		if (restorers
		    && strlen(restorers)) padcat(1, indent + 3, production,
						 restorers);
		padcat(1, indent + 2, production, "}");
	}

	/* end of constructor */
	padcat(1, indent + 1, production, "}");

	/* aux functions to add a new sub object instance (covenants) */
	if (strlen(adders)) padcat(0, 0, production, adders);
	/* js: now add the general terms methods beneath the constructor */
	padcat(1, 0, production, methods);

	/* AUXILIARY FUNCTIONS (main contract) */

	char *auxfuncs = mtrac_strdup("");

	/* access shorthand */
	/* safe transfer */
	if (uses_transfer) inject_transfer(&auxfuncs, indent + 1);

	/* notifications */
	if (uses_notification) inject_notify(&auxfuncs, &emits, indent + 1);
	/* termination */
	if (uses_termination) inject_termination(&auxfuncs, "contract system",
						 indent + 1);

	/* contract history from log */
	if (opt_log) {

		padcat(2, 0, &instructions,
		       "   state changes of the contract can be listed, e.g. actions performed by\n"
		       "   a party to it, or agents who are assigned privileges. In case hash chains\n"
		       "   or signatures are used, they are visible in this log. The log is stored in\n"
		       "   in the file '", opt_log, "'.");
		padcat(2, 0, &instructions, "   > %contract%.history()");

		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in convenience function to view state change log. */");
		padcat(C, indent + 1, &auxfuncs, "history() {");
		padcat(1, indent + 2, &auxfuncs,
		       "fs.readFile(this.logname, (e,d)=>{console.log(d.toString())});");
		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* persistence */
	if (opt_persistence) {

		padcat(2, 0, &instructions,
		       "   The complete contract state can be saved to disk and re-loaded at a\n"
		       "   later point in time. This serves to continue work after stopping and\n"
		       "   restarting node; or to send the entire contract system and its current\n"
		       "   state - which can include hashes and signatures - to another party,\n"
		       "   who may perform the next steps.");
		padcat(2, 0, &instructions, "   > %contract%.persist()");
		padcat(1, 0, &instructions, "   > %contract%.load()");
		padcat(1, 0, &requires,
		       "   $ npm install serialize-javascript");

		/* contract state saving to file */
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in serialization and storage of entire contract system state. */");
		padcat(C, indent + 1, &auxfuncs, "persist() {");
		padcat(1, indent + 2, &auxfuncs,
		       "console.log('> persisting');");
		padcat(1, indent + 2, &auxfuncs,
		       "var data = serialize(this, {space: 4});");
		padcat(1, indent + 2, &auxfuncs, "fs.writeFileSync('",
		       opt_persistence, "', data, ()=>{});");
		padcat(1, indent + 1, &auxfuncs, "}");

		/* contract state loading from file */
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* re-instate entire contract system from serialized file store */");
		padcat(C, indent + 1, &auxfuncs, "static load() {");
		padcat(1, indent + 2, &auxfuncs, "return new ",
		       camel_spaced(module), "();");
		padcat(1, indent + 1, &auxfuncs, "}");

	}

	/* bundle */
	if (opt_bundle) {

		padcat(2, 0, &instructions,
		       "   The contract code, state and log can be bundled into one file to exchange\n"
		       "   or archive it:");
		padcat(2, 0, &instructions, "   > %contract%.bundle()");
		padcat(1, 0, &instructions, "   > %contract%.unbundle()");
		padcat(1, 0, &requires, "   $ npm install tar");

		/* contract bundling */
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in tar-balling of code, log and state. */");
		padcat(C, indent + 1, &auxfuncs, "bundle() {");
		padcat(1, indent + 2, &auxfuncs,
		       "console.log('> bundling into ", opt_bundle, "');");
		padcat(1, indent + 2, &auxfuncs,
		       "tar.create({gzip:true, file:'", opt_bundle, "'}, " "['",
		       opt_source, "', '", file, "', '", opt_persistence,
		       "', '", opt_log, "', 'INSTRUCTIONS.TXT']);");
		padcat(1, indent + 1, &auxfuncs, "}");

		/* contract unbundling */
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in untar-balling of code, log and state. */");
		padcat(C, indent + 1, &auxfuncs, "static unbundle() {");
		padcat(1, indent + 2, &auxfuncs, "console.log('> unbundling ",
		       opt_bundle, "');");
		padcat(1, indent + 2, &auxfuncs, "tar.extract('", opt_bundle,
		       "');");
		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* email */
	if (opt_email) {

		padcat(2, 0, &instructions,
		       "   The contract code, state and log can be sent to a counterparty. This\n"
		       "   requires configuring an email account in the file '",
		       opt_email, "'.");
		padcat(2, 0, &instructions, "   > %contract%.send()");
		padcat(1, 0, &requires, "   $ npm install nodemailer");

		/* contract bundling */
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in email sending of code, log and state. */");
		padcat(C, indent + 1, &auxfuncs, "send() {");
		padcat(2, indent + 2, &auxfuncs, "this.persist();");
		padcat(1, indent + 2, &auxfuncs, "this.bundle();");
		padcat(2, indent + 2, &auxfuncs,
		       "console.log('> sending via email');");
		padcat(1, indent + 2, &auxfuncs,
		       "var receiver = prompt('enter receiver address: ');");
		padcat(2, indent + 2, &auxfuncs,
		       "var config = fs.readFileSync('", opt_email,
		       "', ()=>{});");
		padcat(1, indent + 2, &auxfuncs,
		       "var email = eval('(' + config + ')').email;");
		padcat(1, indent + 2, &auxfuncs, "console.log(email);");

		padcat(2, indent + 2, &auxfuncs,
		       "var transporter = nodemailer.createTransport({");
		padcat(1, indent + 3, &auxfuncs, "service: email.service,");
		padcat(1, indent + 3, &auxfuncs,
		       "auth: { user: email.user, pass: email.pass }});");

		padcat(2, indent + 2, &auxfuncs, "var mailOptions = {");
		padcat(1, indent + 3, &auxfuncs, "from: email.from,");
		padcat(1, indent + 3, &auxfuncs, "to: receiver,");
		padcat(1, indent + 3, &auxfuncs, "subject: email.subject,");
		padcat(1, indent + 3, &auxfuncs, "text: email.text,");
		padcat(1, indent + 3, &auxfuncs, "attachments: { path: './",
		       opt_bundle, "', contentType: 'application/gzip' }};");

		padcat(2, indent + 2, &auxfuncs,
		       "transporter.sendMail(mailOptions, function(error, info){");
		padcat(1, indent + 3, &auxfuncs, "if (error) {");
		padcat(1, indent + 4, &auxfuncs, "console.log(error);");
		padcat(1, indent + 3, &auxfuncs, "} else {");
		padcat(1, indent + 4, &auxfuncs,
		       "console.log('> email sent: ' + info.response); }});");

		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* log() - log function, with optionally hash chain and signatures */
	if (opt_log /* // ◊ || opt_feedback */ ) {
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in logging of state changes. */");
		padcat(C, indent + 1, &auxfuncs, "log(caller, msg) {");
	}

	// ◊ should be unnecesary. log() is not used but console.log is produced everywhere if !opt_log
	if (opt_feedback)
		/* to console */
		padcat(1, indent + 2, &auxfuncs, "console.log(msg);");

	if (opt_log) {
		padcat(1, indent + 2, &auxfuncs,
		       "let stamp = (new Date()).toLocaleString('en-US');");

		/* sign log entry */
		if (opt_signatures) {
			padcat(1, 0, &requires, "   $ npm install prompt-sync");

			padcat(1, indent + 2, &auxfuncs,
			       "var entry = `⌽  ${stamp} ✦ ${caller} ${msg}`;");
			padcat(1, indent + 2, &auxfuncs,
			       "var passphrase = this.sync_passphrase(caller);");
			padcat(1, indent + 2, &auxfuncs,
			       "var pem = fs.readFileSync(caller + '.key');");
			padcat(1, indent + 2, &auxfuncs,
			       "var key = pem.toString('ascii');");
			padcat(1, indent + 2, &auxfuncs,
			       "var sign = crypto.createSign('RSA-SHA256');");
			padcat(1, indent + 2, &auxfuncs, "sign.update(entry);");
			padcat(1, indent + 2, &auxfuncs,
			       "var sig = sign.sign({ key: key, passphrase: passphrase }, 'hex');");
			padcat(1, indent + 2, &auxfuncs,
			       "fs.appendFileSync(this.logname, `${entry} ❈ ${sig}\\n`);");
		} else {
			padcat(1, indent + 2, &auxfuncs,
			       "fs.appendFileSync(this.logname, `${stamp} ${caller} ${msg}\\n`);");
		}

		/* hash goes into beginning of next line */
		if (opt_chaining) {
			padcat(1, indent + 2, &auxfuncs,
			       "let pay = fs.readFileSync(this.logname);");
			padcat(1, indent + 2, &auxfuncs,
			       "let hash = crypto.createHash('sha256').update(pay);");
			padcat(1, indent + 2, &auxfuncs,
			       "fs.appendFileSync(this.logname, '⧉ ' + hash.digest('hex').substr(0, ",
			       str(opt_chaining), ") + \" \");");
		}
	}
	if (opt_log || opt_feedback)
		padcat(1, indent + 1, &auxfuncs, "}");

	/* passphrase input and cache */
	if (opt_log && opt_signatures) {
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in password query for private key file, with cache. */");
		padcat(C, indent + 1, &auxfuncs, "sync_passphrase(caller) {");
		padcat(1, indent + 2, &auxfuncs,
		       "if(!caller) process.exit('no caller information');");
		padcat(1, indent + 2, &auxfuncs,
		       "if(caller == last_caller) return last_passphrase;");
		padcat(1, indent + 2, &auxfuncs, "last_caller = caller;");
		padcat(1, indent + 2, &auxfuncs,
		       "return last_passphrase = prompt('enter pass phrase for ' + caller + ': ', {echo: ''});");
		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* service to create demo keys */
	if (opt_log && opt_signatures) {

		padcat(2, 0, &instructions,
		       "   Keys for signing log entries are expected on-file, by default named after\n"
		       "   the actor, with the extension .key. For demo purposes, key files can be\n"
		       "   created using this utility function:");
		padcat(2, 0, &instructions,
		       "   > %contract%.create_key(name, passphrase)");

		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in convenience function to create keys for users. */");
		padcat(C, indent + 1, &auxfuncs,
		       "static create_key(name, passphrase) {");
		padcat(1, indent + 2, &auxfuncs,
		       "const { publicKey, privateKey } =");
		padcat(1, indent + 3, &auxfuncs,
		       "crypto.generateKeyPairSync('rsa',");
		padcat(1, indent + 4, &auxfuncs, "{ modulusLength: 2048,");
		padcat(1, indent + 5, &auxfuncs,
		       "publicKeyEncoding: { type: 'spki', format: 'pem' },");
		padcat(1, indent + 5, &auxfuncs,
		       "privateKeyEncoding: { type: 'pkcs8', format: 'pem', cipher: 'aes-256-cbc', passphrase: passphrase }});");

		padcat(2, indent + 2, &auxfuncs,
		       "fs.writeFileSync(name+'.key', privateKey);");
		padcat(1, indent + 2, &auxfuncs,
		       "fs.writeFileSync(name+'.pub', publicKey);");
		padcat(1, indent + 2, &auxfuncs, "return true;");
		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* aux functions insert - js: in place. soli+sop: higher up. */
	padcat(0, 0, production, auxfuncs);

	mtrac_free(auxfuncs);

	/* js: end of main class */
	padcat(1, indent, production, "}");

	/* end of file */
	if (!opt_bare) padcat(2, indent, production, "/* end */\n");

	_concat_trace = false;

	/* sort out names, privacy mark (javascript: '#') and parameters */
	replace_bind_tags(production, &instructions, binds);

	/* if needed, create 'main' variable to provide 'this' for closures */
	char *closure_this = mtrac_strdup("");

	if (strstr(*production, "main.")) padcat(1, indent + 2, &closure_this,
						 "let main = this;");
	replace(production, "%20%", closure_this);
	mtrac_free(closure_this);

	char *scope_comment = mtrac_strdup("");

	if (opt_comment && has_subclasses) {
		padcat(2, indent + 1, &scope_comment,
		       "/* This classes constructor's is the only scope where the covenant classes exist. ");
		padcat(1, indent + 1, &scope_comment,
		       "   This can hide them in larger contexts but requires constructor indirections. */");
	} else {
		padcat(1, 0, &scope_comment, "");
	}
	replace(production, "%21%", scope_comment);
	mtrac_free(scope_comment);
	/* prepend instructions to the top - or just discard if not switched on */
	replace(&instructions, "%6%", parameta);
	replace(&instructions, "%00%",
		strlen(requires) ?
		"   These node modules have to be installed once:\n%000%\n\n" :
		"");
	replace(&instructions, "%000%", requires);
	replace(&instructions, "%contract%", instance_var_name);
	concat(&instructions, "\n");
	replace(production, "%0%", opt_instructions ? instructions : "");
	/* memory clean up */
	delete_bind_tree(binds);
	mtrac_free(parameters), parameters = null;
	mtrac_free(arguments), arguments = null;
	mtrac_free(args), args = null;
	mtrac_free(parameta), parameta = null;
	mtrac_free(emits), emits = null;
	if (caller) mtrac_free(caller), caller = null;
	mtrac_free(methods);
	mtrac_free(globals);
	mtrac_free(declarations);
	mtrac_free(initializations);

	mtrac_free(fixed);
	mtrac_free(class_lists);
	mtrac_free(restorers);
	mtrac_free(adders);
	mtrac_free(functions);
	mtrac_free(instructions);
	mtrac_free(requires);
	mtrac_free(file);
	mtrac_free(instance_var_name);

	return true;
}

	/* transfer of tokens */
void inject_transfer(char **production, int indent) {

	if (opt_comment) padcat(2, indent, production,
				"/* built-in transfer message */");

	padcat(C, indent, production, "transfer(", (opt_log) ? "caller, " : "",
	       "from, to, amount) {");
	if (opt_log) padcat(1, indent + 1, production,
			    (!class ? "this" : "main"),
			    ".log(caller, `➠ system message: transfer ${amount} from ${from} to ${to}.`);");
	else padcat(1, indent + 1, production,
		    "console.log(`➠ system message: transfer ${amount} from ${from} to ${to}.`);");
	/* track escrow balance */
	padcat(1, indent + 1, production, "if(from == 'escrow') ",
	       class ? "main." : "this.", "_escrow -= amount;");
	padcat(1, indent + 1, production, "if(to == 'escrow') ",
	       class ? "main." : "this.", "_escrow += amount;");
	padcat(1, indent, production, "}");
}

	/* sending / emitting of a message */
void inject_notify(char **production, char **emits, int indent) {

	if (opt_comment) padcat(2, indent, production,
				"/* built-in send message */");
	padcat(C, indent, production, "notify(", (opt_log) ? "caller, " : "",
	       "from, to, message) {");
	if (opt_log)
		padcat(1, indent + 1, production, (!class ? "this" : "main"),
		       ".log(caller, `➠ system message: send message «${message}» from ${from} to ${to}.`);");
	else
		padcat(1, indent + 1, production,
		       "console.log(`➠ system message: send message «${message}» from ${from} to ${to}.`);");
	padcat(1, indent, production, "}");

}

	/* terminate() - contract termination */
void inject_termination(char **production, char *prompt, int indent) {

	if (opt_comment) padcat(3, indent, production,
				"/* built-in termination of the ", prompt,
				" */");
	padcat(C, indent, production, "termination(",
	       (opt_log || opt_feedback) ? "caller" : "", ") {");
	padcat(1, indent + 1, production, "this.terminated = true;");
	if (opt_log
	    || opt_feedback) padcat(1, indent + 2, production,
				    (!class ? "this" : "main"),
				    ".log(caller, '■ ", prompt,
				    " terminated');");
	padcat(1, indent, production, "}");
	padcat(2, indent, production, "check_termination() {");
	padcat(1, indent + 1, production, "if(!this.terminated) return false;");
	if (opt_log
	    || opt_feedback) padcat(1, indent + 2, production,
				    "console.log('✕ ", prompt,
				    " previously terminated');");
	padcat(1, indent + 1, production, "return true;");
	padcat(1, indent, production, "}");

}
bool js_head(char **production, Head *Head, int indent) {
	if (!Head) return false;
	if (opt_debug) printf("producing Head\n");
	// padcat(2, indent, production, "/*");

	js_lex(production, Head->Lex, indent);
	js_preamble(production, Head->Preamble, indent);
	js_comment(production, Head->Comment, indent);
	js_authors(production, Head->Authors, indent);
	if (!opt_bare) {
		padcat(1, 0, production, " **	file:        ", opt_source);
		padcat(1, 0, production, " **");
		js_lexon(production, Head->Lexon, indent);
		padcat(1, 0, production, " **	compiler:    lexon ",
		       program_version);
		padcat(1, 0, production, " **");
		padcat(1, 0, production, " **	grammar:     ",
		       grammar_version);
		padcat(1, 0, production, " **");
		padcat(1, 0, production, " **	backend:     ",
		       backend_version);
		padcat(1, 0, production, " **");
		padcat(1, 0, production, " **	target:      ", target_version);
		padcat(1, 0, production, " **");
		padcat(1, 0, production, " **	options:     ", opt_summarized);
		padcat(1, 0, production, " **");
		padcat(1, 0, production, "%0% */");
	}

	return true;
}

bool js_lex(char **production, Lex *Lex, int indent) {
	if (!Lex) return false;
	if (opt_debug) printf("producing Lex %s\n", Lex->Name);
	if (!opt_bare) {
		padcat(1, 0, production, " **	code:        ", Lex->Name);
		padcat(1, 0, production, " **");
	}
	module = Lex->Name;
	return true;
}

bool js_lexon(char **production, Lexon *Lexon, int indent) {
	if (!Lexon) return false;
	if (opt_debug) printf("producing Lexon %s\n", Lexon->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	code tagged: ",
		       Lexon->Description);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool js_authors(char **production, Authors *Authors, int indent) {
	if (!Authors) return false;
	if (opt_debug) printf("producing Authors %s\n", Authors->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	authors:     ",
		       Authors->Description);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool js_comment(char **production, Comment *Comment, int indent) {
	if (!Comment) return false;
	if (opt_debug) printf("producing comment %s\n", Comment->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	comment:     ");
		js_description(production, Comment->Description, indent + 1);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool js_preamble(char **production, Preamble *Preamble, int indent) {
	if (!Preamble) return false;
	if (opt_debug) printf("producing Preamble %s\n", Preamble->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	preamble:    ",
		       Preamble->Description);
		padcat(1, 0, production, " **");
	}
	return true;
}

	/* the general terms, definition and clauses */
bool js_terms(char **production, Terms *Terms, int indent) {
	if (!Terms) return false;
	if (opt_debug) printf("producing Terms\n");
	js_provisions(production, Terms->Provisions, indent);
	return true;
}

bool js_covenants(char **production, Covenants *Covenants, int indent) {
	if (!Covenants) return false;
	if (opt_debug) printf("producing contracts\n");
	js_covenant(production, Covenants->Covenant, indent);
	js_covenants(production, Covenants->Covenants, indent);
	return true;
}

bool js_covenant(char **production, Covenant *Covenant, int indent) {
	if (!Covenant) return false;
	if (opt_debug) printf("producing Covenant %s\n", Covenant->Name);

	paratag = strlen(*production);
	class = mtrac_strdup(UP(camel_spaced(Covenant->Name)));
	instance = snakedup(Covenant->Name);
	has_subclasses = true;
	char *functions_shelve = mtrac_strdup(functions);
	char *fixed_shelve = mtrac_strdup(fixed);
	bool main_uses_termination = uses_termination;
	char *emits = mtrac_strdup("");
	bool transfer_shelve = uses_transfer;

	uses_transfer = false;
	bool notification_shelve = uses_notification;

	uses_notification = false;
	bool termination_shelve = uses_termination;

	uses_termination = false;

	/* obtain the names of the clauses */
	Clauses *clauses =
		!Covenant->Provisions ? null : Covenant->Provisions->Clauses;
	while (clauses) {
		char *name = !clauses->Clause ? null : clauses->Clause->Name;

		if (name) mtrac_concat(&functions, ":", name, ":");
		clauses = clauses->Clauses;
	}

	char *list = mtrac_strdup("");

	mtrac_concat(&list, "_", instance, "_list");
	char *count = mtrac_strdup("");

	mtrac_concat(&count, "_", instance, "_count");

	if (opt_comment) padcat(2, indent, production,
				"/* aggregation of covenants for folds and serialization */");
	padcat(C, indent, production, "this.", list, " = {};");
	padcat(1, indent, production, "this.", count, " = 0;");
	if (opt_comment) padcat(2, indent, production, "/**");
	if (opt_comment) padcat(1, indent, production, " **");
	if (opt_comment) padcat(1, indent, production, " **\t", class,
				" covenant class");
	if (opt_comment) padcat(1, indent, production, " **");
	if (opt_comment) padcat(1, indent, production, " **/");

	if (opt_comment || opt_lexon_comments)
		padcat(1, 0, production, "");

	/* lexon text of covenant definitions and terms as extended code comment */
	if (opt_lexon_comments) {
		char *c = mtrac_strdup(get_lexcom(instance));

		replace(&c, "\n", "\n\t" LEXCOM1 "\t");
		replace(&c, "\n\t" LEXCOM1 "\t\n", "\n\t" LEXCOM1 "\n");
		padcat(1, 2, production, LEXCOM0 "\n\t" LEXCOM1 "\t", c,
		       "\n\t" LEXCOM2);

		mtrac_free(c);
	}

	/* covenant constructor */
	if (opt_comment) padcat(2, indent, production,
				"/* this closure exports the covenant's constructor to the scope of the main */");
	padcat(C, indent, production, "this.", class, " = (%2%) => {%15%");	// %15%: access permissions
	assert(active_subjects == null);
	padcat(1, indent + 2, production, "return new ", class,
	       "(this%2,%%2%);%16%");
	padcat(1, indent, production, "};");

	padcat(2, indent, production, "class ", class, " {");
	padcat(2, indent + 1, production, "constructor(%2%) {");
	char *declarations_stack = declarations;
	char *initializations_stack = initializations;
	char *parameters_stack = parameters;
	char *arguments_stack = arguments;
	char *args_stack = args;
	char *parameta_stack = parameta;

	declarations = mtrac_strdup("");
	initializations = mtrac_strdup("");

	parameters = mtrac_strdup("caller");
	arguments = mtrac_strdup("caller");
	args = mtrac_strdup("");
	parameta = mtrac_strdup("");   // sic, for JS too
	bool is_payable_stack = is_payable;

	is_payable = false;
	padcat(2, 0, &instructions,
	       "   The following are actions that can be performed per ", class,
	       ".");
	padcat(2, 0, &instructions, "   > ", instance, " = %contract%.add_", instance, "(%2%)");	// ◊ check syntax

	if (opt_comment) padcat(1, indent + 1, &restorers, "/* restore ", class,
				" objects */");
	padcat(1, indent + 1, &restorers, "for (let id in this.", list, ") {");
	padcat(1, indent + 2, &restorers, "let live = this.", list, "[id];");
	padcat(1, indent + 2, &restorers, "let instance = new ", class, "();");
	padcat(1, indent + 2, &restorers, "Object.assign(instance, live);");
	padcat(1, indent + 2, &restorers, "this.", list, "[id] = instance;");
	padcat(1, indent + 1, &restorers, "}");

	enforce_same_subject = true;
	covenant_constructor_body = true;
	js_provisions(production, Covenant->Provisions, indent + 2);

	covenant_constructor_body = false;
	enforce_same_subject = false;

	/* AUXILIARY FUNCTIONS (covenant) */

	/* access shorthand */
	/* safe transfers */
	if (uses_transfer) inject_transfer(production, indent + 1);

	/* notifications */
	if (uses_notification) inject_notify(production, &emits, indent + 1);	// ~ emits is a local char *
	/* termination of covenant */
	if (uses_termination) inject_termination(production, "covenant",
						 indent + 1);
	/* end of covenant class definition */
	padcat(1, indent, production, "}");

	/* wrapper for the covenant constructor: user api to the hidden classes constructor (must appear after main's (top level) constructor */
	if (opt_comment) padcat(2, 1, &adders, "/* create new instance of ",
				Covenant->Name,
				" covenant, and register it with main */");
	padcat(C, 1, &adders, "add_", SNAKE(Covenant->Name), "(%2%) {");
	if (main_uses_termination) padcat(1, 2, &adders, "if (this.check_termination()) return undefined;");	// this == main
	padcat(1, 2, &adders, "return this.", list, "[this.", count,
	       " += 1] = this.", class, "(%2b%);");
	padcat(1, 1, &adders, "}");
	/* inject catch of non-permissioned caller into constructor wrapper */

	char *perm = mtrac_strdup("");

	assert(covenant_subjects);
	produce_access_conditions(1, indent + 1, &perm, covenant_subjects);
	replace(production, "%15%", perm);

	replace(production, "%16%", strlen(perm) ? "\n            }" : "");

	mtrac_free(perm);

	/* inject parameter lists */
	replace(production, "%2%", parameters);
	replace(production, "%2,%", *parameters ? ", " : "");
	replace(&adders, "%2%", parameters);
	replace(&adders, "%2,%", *parameters ? ", " : "");
	replace(&adders, "%2b%", arguments);
	replace(&adders, "%2b,%", *arguments ? ", " : "");
	replace(&instructions, "%2%", parameta);
	replace(production, "%2,%", *parameta ? ", " : "");

	/* cleanup & stack ('shelve') popping */
	if (covenant_subjects) delete_list(covenant_subjects);
	covenant_subjects = null;
	assert(!!!active_subjects);
	active_subjects = null;
	mtrac_free(parameters);
	mtrac_free(arguments);
	mtrac_free(args);
	mtrac_free(parameta);
	mtrac_free(declarations);
	mtrac_free(initializations);
	parameters = parameters_stack;
	arguments = arguments_stack;
	args = args_stack;
	parameta = parameta_stack;
	declarations = declarations_stack;
	initializations = initializations_stack;
	is_payable = is_payable_stack;

	mtrac_free(functions), functions = functions_shelve;
	mtrac_free(fixed), fixed = fixed_shelve;

	uses_transfer = transfer_shelve;
	uses_notification = notification_shelve;
	mtrac_free(emits);
	uses_termination = termination_shelve;
	mtrac_free(class), class = null;
	mtrac_free(instance), instance = null;
	mtrac_free(list), list = null;
	mtrac_free(count), count = null;
	paratag = -1;

	return true;
}

static Definitions *global_definitions = null;
static Definitions *covenant_definitions = null;
bool js_provisions(char **production, Provisions *Provisions, int indent) {
	if (!Provisions) return false;
	if (opt_debug) printf("producing Provisions\n");

	/* definitions */
	if (opt_persistence
	    && opt_comment) padcat(2, indent, production,
				   "/* object members: skip for restoring serialized object */");
	if (opt_persistence) padcat(1 + (opt_comment ? 0 : 1), indent++, production, "if(typeof ", main_constructor_body ? "%7%" : "caller", " !== 'undefined') {");	// (*)

	if (main_constructor_body) padcat(1, indent, production,
					  "this._escrow = 0;");
	if (!global_definitions) global_definitions = Provisions->Definitions;
	else covenant_definitions = Provisions->Definitions;	// (sic)
	js_definitions(production, Provisions->Definitions, indent);

	/* placeholder for this.terminated */
	padcat(0, 0, production, main_constructor_body ? "%22%" : "%23%");

	if (opt_log
	    && !class) padcat(1, indent, production, (!class ? "this" : "main"),
			      ".logname = '", opt_log, "';");

	/* statements */
	if (opt_log && !class) {
		if (opt_comment) padcat(2, indent, production,
					"/* start log - overwrites previous by same name */");
		padcat(C, indent, production,
		       "fs.writeFileSync(this.logname, \"Lexon log \" + (new Date).toLocaleString('en-US') + \"\\n\", ()=>{});");
	}

	recital_of_terms = main_constructor_body;
	no_action_in_group_yet = true;
	enforce_same_subject = true;
	single_sentence_clause = Provisions->Statements
		&& !Provisions->Statements->Statements;
	multi_sentence_clause = Provisions->Statements
		&& Provisions->Statements->Statements;

	js_statements(production, Provisions->Statements, indent);
	recital_of_terms = false;
	enforce_same_subject = false;

	/* end of constructor code */
	if (opt_persistence) padcat(1, --indent, production, "}");
	if (!main_constructor_body) padcat(1, --indent, production, "}");	// end of constructor

	/* insert caller argumnet and 'payable' modifier */
	replace(production, "%7%", caller ? caller : "caller");	// ! caller is not yet set at (*) above.
	/* clauses */
	js_clauses(instance ? production : &methods, Provisions->Clauses,
		   indent - (instance ? 0 : 1));

	/* add element this.terminated, if needed */
	char *terminated = mtrac_strdup("");

	if (uses_termination) padcat(1, indent + (main_constructor_body ? 0 : 2), &terminated, "this.terminated = false;");	// [3] ◊ unify
	replace(production, main_constructor_body ? "%22%" : "%23%",
		terminated);
	mtrac_free(terminated);

	char *termination_test = mtrac_strdup("");

	if (uses_termination) padcat(1,
				     indent + (main_constructor_body ? 0 : 1),
				     &termination_test,
				     "if(this.check_termination()) return undefined;");
	replace(instance ? production : &methods,
		main_constructor_body ? "%24%" : "%25%", termination_test);
	mtrac_free(termination_test);

	return true;
}

bool js_definitions(char **production, Definitions *Definitions, int indent) {
	if (!Definitions) return false;
	js_definitions(production, Definitions->Definitions, indent);
	js_definition(production, Definitions->Definition, indent);
	return true;
}

bool js_definition(char **production, Definition *Definition, int indent) {
	if (!Definition) return false;
	if (opt_debug) printf("producing Definition %s\n", Definition->Name);

	/* ignore alias for this contract */
	if (Definition->This_Contract)
		return true;

	assert(globals);
	if (Definition->Name) {
		if (!class) mtrac_concat(&globals, ":", Definition->Name, ":");
		else if (in(globals, Definition->Name))
			error("do not re-use the same name in multiple definitions", Definition->Name);
	}
	padcat(1, indent, production, "");
	js_name(production, Definition->Name, false, indent);
	padcat(0, 0, production, " = null;");

	return true;
}

const char *typemap(const char *lex_type, bool option_type, bool forpara,
		    int line) {
	if (!lex_type) return "undefined";	// assert ◊

	printf("Unknown type at %d\n", line);	// ◊ make proper error call / fatal error / compiler error
	exit(1);
	return "[ ERROR: UNKNOWN TYPE ]";	// ◊ assert
}

const char *nullmap(const char *lex_type, bool defined_default) {
	if (!lex_type) return "undefined";
	// defined_default means, don't use None as null but a proper value.

	if (!strcmp(lex_type, "number")) return "0";
	if (!strcmp(lex_type, "amount")) return "0";
	if (!strcmp(lex_type, "time")) return "0";
	if (!strcmp(lex_type, "text")) return "\"\"";
	if (!strcmp(lex_type, "data")) return "\"\"";
	if (!strcmp(lex_type, "binary")) return "false";
	return "[ ERROR: UNKNOWN CATEGORY ]";	// ◊ assert
}

const char *lexsymtype(Symbol *symbol) {
	char *pretty_varname;

	if (symbol->Name) pretty_varname = snakedup(symbol->Name);
	else if (symbol->Type) pretty_varname = snakedup(symbol->Type->Literal);
	assert(pretty_varname);
	const char *lt = lextype(pretty_varname);

	mtrac_free(pretty_varname);
	if (!strcmp(lt, "[ ERROR: UNKNOWN CATEGORY ]")) return null;	// assert ◊
	return lt;
}

const char *lextype(const char *name) {
	Definitions *d = global_definitions;
	bool covenants = false;	       // loop goes global first, then local covenant definitions

	if (!strcmp(name, "person") || !strcmp(name, "Person"))
		return "person";
	if (!strcmp(name, "amount") || !strcmp(name, "Amount"))
		return "amount";
	while (d && d->Definition) {
		if (!strcmp(name, SNAKE(d->Definition->Name))) {
			return d->Definition->Type_Term->Type->Literal;
		}
		d = d->Definitions;
		if (!d
		    && !covenants) covenants = true, d = covenant_definitions;
	}
	return "[ ERROR: UNKNOWN CATEGORY ]";	// assert ◊
}

const char *type(const char *name, bool option_type, bool forpara, int line) {
	Definitions *d = global_definitions;
	bool covenants = false;	       // loop goes global first, then local covenant definitions

	if (!strcmp(name, "person") || !strcmp(name, "Person"))
		return typemap("person", option_type, forpara, __LINE__);
	if (!strcmp(name, "amount") || !strcmp(name, "Amount"))
		return typemap("amount", option_type, forpara, __LINE__);
	while (d && d->Definition) {
		if (!strcmp(name, SNAKE(d->Definition->Name))) {
			return typemap(d->Definition->Type_Term->Type->Literal,
				       option_type, forpara, __LINE__);
		}
		d = d->Definitions;
		if (!d
		    && !covenants) covenants = true, d = covenant_definitions;
	}
	printf("Unknown type for %s\n", name);	// ◊ make proper error call / fatal error / compiler error
	exit(1);
}

const char *nullvalue(const char *name, bool defined_default) {
	assert(global_definitions);
	char *snakename = snakedup(name);
	Definitions *d = global_definitions;

	while (d) {
		if (!strcmp(snakename, SNAKE(d->Definition->Name))) {
			mtrac_free(snakename);
			return nullmap(d->Definition->Type_Term->Type->Literal,
				       defined_default);
		}
		d = d->Definitions;
	}
	d = covenant_definitions;
	while (d) {
		if (!strcmp(snakename, SNAKE(d->Definition->Name))) {
			mtrac_free(snakename);
			return nullmap(d->Definition->Type_Term->Type->Literal,
				       defined_default);
		}
		d = d->Definitions;
	}
	mtrac_free(snakename);
	return "[ ERROR: UNKNOWN NAME ]";	// assert ◊
}

bool js_this_contract(char **production, This_Contract *This_Contract,
		      int indent) {
	if (!This_Contract) return false;
	padcat(0, 0, production, "this.");

	return true;
}

bool js_all_contracts(char **production, All_Contracts *All_Contracts,
		      int indent) {
	if (!All_Contracts) return false;
	padcat(0, 0, production, "main.");	// ◊ cover

	return true;
}

bool js_clauses(char **production, Clauses *Clauses, int indent) {
	if (!Clauses) return false;

	js_clauses(production, Clauses->Clauses, indent);
	js_clause(production, Clauses->Clause, indent);

	return true;
}

bool js_clause(char **production, Clause *Clause, int indent) {
	if (!Clause) return false;
	if (opt_debug) printf("producing Clause %s\n", Clause->Name);

	mtrac_free(args);
	args = mtrac_strdup("");
	list *active_subjects_stack = active_subjects;

	active_subjects = null;
	bool is_payable_stack = is_payable;

	/* track which function calls which other functions */
	char *low = SNAKE(Clause->Name);
	char *safe = safedup(low);
	bind *bind = register_bind(safe, Clause->Name);

	mtrac_free(safe);
	current_function = bind;

	paratag = strlen(*production);
	if (opt_comment) padcat(3, indent, production, "/* ", Clause->Name,
				" clause */");

	/* lexon clause text as extended code comment */
	if (opt_lexon_comments) {
		char *clause = snakedup(Clause->Name);
		char *c = mtrac_strdup(get_lexcom(clause));

		mtrac_free(clause);
		assert(c);
		if (main_constructor_body) {
			replace(&c, "\n", "\n    " LEXCOM1 " ");
			padcat(2, 0, production,
			       "    " LEXCOM0 "\n    " LEXCOM1 " ", c,
			       "\n    " LEXCOM2);
		} else {
			replace(&c, "\n", "\n            " LEXCOM1 " ");
			padcat(2, 2, production,
			       "    " LEXCOM0 "\n            " LEXCOM1 " ", c,
			       "\n            " LEXCOM2);
		}
		mtrac_free(c);
	}

	padcat(C, indent, production, bind->tag, " ");

	padcat(1, 0, &instructions, "   > ", instance ? instance : "%contract%",
	       ".", bind->tag);
	assert(functions);
	if (Clause->Name) mtrac_concat(&functions, ":", Clause->Name, ":");

	js_body(production, Clause->Body, indent);
	paratag = -1;
	current_function = null;       // not used in recitals

	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = active_subjects_stack;
	is_payable = is_payable_stack;
	return true;
}

	/* Early catch if no subject of a multi-sentence clause could access.
	 * It's not really a courtesy only, for multi-sentence clauses
	 * where one sentence has NO subject. This summary access control
	 * protects the subject-less sentences. They are only reachable when
	 * any of the other sentences that has a subject is. */
char *courtesy;
char *courtesy_track;

bool js_body(char **production, Body *Body, int indent) {
	if (!Body) return false;
	if (opt_debug) printf("producing Body\n");
	padcat(0, 0, production, " {");
	/* check for termination */
	if (Body->Statements) padcat(0, 0, production,
				     main_constructor_body ? "%24%" : "%25%");

	no_action_in_group_yet = true;
	single_sentence_clause = Body->Statements
		&& !Body->Statements->Statements;
	multi_sentence_clause = Body->Statements
		&& Body->Statements->Statements;

	if (multi_sentence_clause) {
		courtesy = mtrac_strdup("if(!(");

		courtesy_track = mtrac_strdup("");
		padcat(1, indent + 1, production, "%36%");	// 36: courtesy multi-sentence access warning
	}

	js_statements(production, Body->Statements, indent + 1);

	if (multi_sentence_clause) {
		padcat(0, indent, &courtesy, ")) return 'not permitted';");

		replace(production, "%36%", courtesy);
		mtrac_free(courtesy);
		mtrac_free(courtesy_track);
	}

	js_function(production, Body->Function, indent + 1);

	if (opt_feedback && !Body->Function)
		padcat(1, indent + 1, production, "return 'done.';");

	padcat(1, indent, production, "}");
	return true;
}

bool js_function(char **production, Function *Function, int indent) {
	if (!Function) return false;
	if (opt_debug) printf("producing Function %s\n", Function->Name);
	padcat(1, indent, production, "return ");

	js_expression(production, Function->Expression, indent + 1);
	padcat(0, 0, production, EOL);

	/* add return type to function signature */

	return true;
}

static char *subjnonmatch = null;
static char *subjlatebind = null;
bool js_statements(char **production, Statements *Statements, int indent) {
	if (!Statements) return false;
	if (opt_debug) printf("producing Statements\n");

	js_statements(production, Statements->Statements, indent);
	js_statement(production, Statements->Statement, indent);

	return true;
}

bool js_statement(char **production, Statement *Statement, int indent) {
	if (!Statement) return false;
	if (opt_debug) printf("producing Statement\n");
	js_action(production, Statement->Action, indent);
	js_flagging(production, Statement->Flagging, indent);
	return true;
}

static Name *subject = null;
static bool ever = false;
bool js_action(char **production, Action *Action, int indent) {
	if (!Action) return false;
	if (opt_debug) printf("producing Action\n");
	action = Action;

	/* single subject only .. */
	subject = Action->Subject->Symbols->Symbol->Name;
	if (!ever && recital_of_terms) {
		bool payment = is_payment(Action->Predicates);

		/* this takes care of the subject person 1) becoming a parameter and 2) an object member that 3) gets the parameter assigned */
		insert_parameter_and_set_member(production, null,
						Action->Subject->Symbols->
						Symbol, payment, paratag,
						indent, __LINE__);
		/* the function we are in, if it had no caller set yet, the subject will be used as the caller, LITERALLY. */
		if (!caller) caller = snakedup(Action->Subject->Symbols->Symbol->Name);	// ...
	}

	/* for main_constructor_bodys, enforce that if there are multiple sentences, they all use the same subjects */
	if (!Action->Subject->Symbols->Symbols && !Action->Subject->Symbols->Symbol->Name) ;	// "this contract"
	else if (!no_action_in_group_yet && enforce_same_subject) {
		bool good = true;
		Symbols *symbols = Action->Subject->Symbols;

		while (symbols && symbols->Symbol) {
			assert(symbols->Symbol->Name);
			list *c = active_subjects;

			while (c) {
				if (strcmp
				    ((char *)c->item, symbols->Symbol->Name))
					good = false;
				c = c->next;
			}
			symbols = symbols->Symbols;	// i.e., next
		}
		if (!good) error("in terms, the active subjects of all sentences must match", (char *)active_subjects->item);	// ◊ cover
	}
	/* if not first sentence OR not in constructor: just collect the ones of this sentence */
	else {
		assert(!active_subjects);
		Symbols *symbols = Action->Subject->Symbols;

		while (symbols && symbols->Symbol) {
			if (symbols->Symbol->
			    Name
			    /* && !in_list(active_subjects, symbol->Symbol->Name) */
			    ) {
				list_add(&active_subjects,
					 symbols->Symbol->Name);
			}
			symbols = symbols->Symbols;	// i.e., next
		}
		if (!covenant_subjects && covenant_constructor_body)
			covenant_subjects = active_subjects;
	}
	no_action_in_group_yet = false;
	ever = true;

	assert(!subjnonmatch);
	assert(!subjlatebind);
	subjnonmatch = mtrac_strdup("");
	subjlatebind = mtrac_strdup("");
	padcat(0, 0, production, "%11%%12%");

	js_subject(production, Action->Subject, indent);

	/* pre-insert the non-match comparisons and late bindings */

	replace(production, "%11%", subjnonmatch);	// can be ""
	replace(production, "%12%", subjlatebind);	// can be ""
	mtrac_free(subjnonmatch), subjnonmatch = null;
	mtrac_free(subjlatebind), subjlatebind = null;

	/* check binding of the subject */
	bool single_subject = !Action->Subject->Symbols->Symbols;

	if (current_function) {
		current_function->uses_permission = !!Action->Permission;

		if (single_sentence_clause && single_subject) {
			padcat(1, indent, production, "if(caller != ");

			if (current_function) current_function->uses_caller =
					true;
			js_symbol(production, Action->Subject->Symbols->Symbol,
				  false, 0);

			padcat(0, 0, production, ") return 'not permitted';");

			// multi-subject and/or multi-sentence
		} else {
			if (single_sentence_clause) {
				padcat(1, indent, production, "if(!(");

			} else
				padcat(1, indent, production, "if(");
			Symbols *Symbols = Action->Subject->Symbols;
			int i = 0;

			while (Symbols && Symbols->Symbol) {
				char *symbol = mtrac_strdup("");

				js_symbol(&symbol, Symbols->Symbol, false, 0);
				if (i++) padcat(0, 0, production, " || ");
				padcat(0, 0, production, "caller == ", symbol);
				if (current_function) current_function->
						uses_caller = true;

				/* aggregated, potentially shortened access condition for revert message */
				if (multi_sentence_clause) {
					char *search = mtrac_strdup("");

					padcat(0, 0, &search, ":", symbol, ":");
					if (!strstr(courtesy_track, search)) {
						if (strlen(courtesy_track))
								padcat(0, 0,
								       &courtesy,
								       " || ");
						padcat(0, 0, &courtesy_track,
						       search);
						padcat(0, 0, &courtesy,
						       "caller == ", symbol);
						if (current_function)
								current_function->
								uses_caller =
								true;
					}
					mtrac_free(search);
				}
				mtrac_free(symbol);
				Symbols = Symbols->Symbols;
			}
			// either close the require phrase or open the block which's else is the revert with 'not permitted' at [2]
			if (single_sentence_clause) {
				padcat(0, 0, production,
				       ")) return 'not permitted';");

				// multi sentence
			} else {
				padcat(0, 0, production, ") {");

				indent++;
			}
		}
	}

	js_condition(production, Action->Condition, indent);
	if (Action->Condition) indent++;

	js_predicates(production, Action->Predicates, indent);

	if (Action->Condition) padcat(1, --indent, production, "}");

	/* for multiple sentences, add the closing bracket */
	if (current_function && !single_sentence_clause) {
		padcat(1, --indent, production, "}");
	}

	action = null;
	if (active_subjects
	    && active_subjects !=
	    covenant_subjects) delete_list(active_subjects);
	active_subjects = null;
	return true;
}

bool js_subject(char **production, Subject *Subject, int indent) {
	if (!Subject) return false;
	if (opt_debug) printf("producing Subject\n");

	char **para =
		current_function ? &current_function->parameta : &parameta;

	Symbols *s = Subject->Symbols; // a subject may consist of multiple nouns
	bool first = true;
	bool any = false;

	/* for every noun that is part of the subject */
	while (s && s->Symbol) {
		/* if it has a literal name - and thus is not the keyword 'escrow'
		 * (which's literal may be in Literal but Name after parsing) */
		if (s->Symbol->Name) {
			// ◊ into symbol coming in here
			char *varname = snakedup(s->Symbol->Name);
			char *lexname = s->Symbol->Name;
			char *scope = (!in(globals, s->Symbol->Name) && class) ? "this." : "main.";	// ◊ unite with usual 'main_constructor_body?' ?
			char *postscope = "";

			padcat(0, 0, para, first ? "<<" : " or ", varname);	//X unite with S+S?

			/* binding of unbound person variable to caller parameter */
			if (!main_constructor_body) {
				char *safe = safedup(varname);

				/* precondition that caller and all of the subjects cannot be the same */
				if (first) padcat(2, indent, &subjnonmatch,
						  "if(caller != ", scope, safe,
						  postscope);
				else padcat(0, 0, &subjnonmatch,
					    " && caller != ", scope, safe,
					    postscope);
				/* produce bind code. Person in question must still be null, i.e., unbound */
				if (!in(fixed, varname)) {
					// ◊ add error when postscope is set == assignment not in the right class
					padcat(1, indent + 1, &subjlatebind,
					       !any ? "" : "else ", "if(",
					       scope, safe, " == null) ", scope,
					       safe, " = caller;");
					any = true;
					padcat(0, 0, &fixed, ":", safe, ":");	// right? ◊
				}
				mtrac_free(safe);
			}
			mtrac_free(varname);
		}
		s = s->Symbols;
		first = false;
	}
	if (strlen(*para)) padcat(0, 0, para, ">>");	// ◊ .. sometimes produces >>>>
	if (any)
		padcat(0, 0, &subjnonmatch, ") {"), padcat(1, indent,
							   &subjlatebind,
							   "}\n");
	else
		/* reset all when all in subjlatebind are actually constructor arguments, of the main or sub contract
		 * This is known only after the loop has been traversed and 'any' is still false.  */
		mtrac_free(subjnonmatch), subjnonmatch = mtrac_strdup("");

	return true;
}

bool js_symbols(char **production, Symbols *Symbols, int indent) {
	if (!Symbols) return false;
	js_symbol(production, Symbols->Symbol, false, indent);
	js_catena(production, Symbols->Catena, indent);
	js_symbols(production, Symbols->Symbols, indent);
	return true;
}

bool js_symbol(char **production, Symbol *Symbol, bool assign, int indent) {
	if (!Symbol) return false;

	/* produce the name literal. Note that js_name adds 'this.'
	 * or 'main.', which makes for a global scope, while the cases
	 * that a type name is itself used as variable name, it is use
	 * unprefixed, for a local scope. */
	if (Symbol->Name)
		js_name(production, Symbol->Name, assign, indent);
	else {
		assert(Symbol->Type);
		char *safe = safedup(SNAKE(Symbol->Type->Literal));

		padcat(0, 0, production, safe);
		if (assign) padcat(0, 0, &fixed, ":", safe, ":");
		mtrac_free(safe);
	}
	return true;
}

bool js_noun(char **production, Symbol *Symbol, int indent) {
	if (!Symbol) return false;
	if (Symbol->Name)
		padcat(0, 0, production, Symbol->Name);
	else {
		assert(Symbol->Type);
		padcat(0, 0, production, Symbol->Type->Literal);
	}
	return true;
}

bool js_catena(char **production, Catena *Catena, int indent) {
	if (!Catena) return false;
	return true;
}

bool js_object(char **production, Object *Object, int indent) {
	if (!Object) return false;
	if (opt_debug) printf("producing Object\n");
	if (Object->Symbol) {

		js_symbol(production, Object->Symbol, false, indent + 1);

	} else if (Object->Reflexive) {

		js_reflexive(production, Object->Reflexive, indent + 1);
	}
	// else: escrow == do nothing
	return true;
}

bool js_reflexive(char **production, Reflexive *Reflexive, int indent) {
	if (!Reflexive) return false;
	if (opt_debug) printf("producing Reflexive\n");

	assert(action);
	assert(action->Subject);
	assert(action->Subject->Symbols);
	if (!action->Subject->Symbols->Symbol)
		error("missing subject for reflexive pronoun ",
		      Reflexive->Literal);
	if (action->Subject->Symbols->Symbols) {
		char *msg = mtrac_strdup("");

		concat(&msg, action->Subject->Symbols->Symbol->Name, ", ",
		       action->Subject->Symbols->Symbols->Symbol->Name, " / ",
		       Reflexive->Literal, ")");
		error("don't use multiple subjects with a reflexive pronoun",
		      msg);
		mtrac_free(msg);
	}
	js_symbol(production, action->Subject->Symbols->Symbol, false,
		  indent + 1);

	return true;
}

bool js_predicates(char **production, Predicates *Predicates, int indent) {
	if (!Predicates) return false;
	if (opt_debug) printf("producing Predicates\n");
	js_predicates(production, Predicates->Predicates, indent);
	js_predicate(production, Predicates->Predicate, indent);
	return true;
}

bool js_predicate(char **production, Predicate *Predicate, int indent) {
	if (!Predicate) return false;
	if (opt_debug) printf("producing Predicate\n");

	if (current_function) current_function->changes_state = true;

	js_certification(production, Predicate->Certification, indent);
	js_declaration(production, Predicate->Declaration, indent);
	js_filing(production, Predicate->Filing, indent);
	js_registration(production, Predicate->Registration, indent);
	js_grantment(production, Predicate->Grantment, indent);
	js_appointment(production, Predicate->Appointment, indent);
	js_acceptance(production, Predicate->Acceptance, indent);
	js_fixture(production, Predicate->Fixture, indent);
	js_setting(production, Predicate->Setting, indent);
	js_payment(production, Predicate->Payment, indent);
	js_sending(production, Predicate->Sending, indent);
	js_notification(production, Predicate->Notification, indent);
	js_termination(production, Predicate->Termination, indent);

	return true;
}

	/* assign a symbol an expression */
static void assign(char **production, int indent, Symbol *symbol,
		   Expression *expression) {

	padcat(1, indent, production, "");

	js_symbol(production, symbol, true, indent);	// true --> assign flag
	padcat(0, 0, production, " = ");

	if (expression)
		js_expression(production, expression, indent + 1);
	else
		padcat(0, 0, production, "true");

	padcat(0, 0, production, EOL);
}

	/* Support functions for predicates */

	/* Logging */
static void log_entry(char **production, char *name, char *action, int indent) {
	if (opt_log || opt_feedback) {
		padcat(1, indent, production, (!class ? "this" : "main"),
		       ".log(", recital_of_terms ? caller : "caller",
		       ", \"✓ ", name, " ", action, "\");");
		if (current_function) current_function->uses_caller |= class
				|| !strcmp(caller, "caller");
	}
}

	/* Lock-in a place for pre-assignment of variables in case its needed */
static void preassign_mark(char **production, int indent) {
	assert(!strstr(*production, "%preassign%"));
	padcat(0, 0, production, "%preassign%");
	preass_indent = indent;
}

	/* Delete the place-holder */
static void delete_preassign_mark(char **production) {
	replace(production, "%preassign%", "");
}

	/* Predicates */

bool js_certification(char **production, Certification *Certification,
		      int indent) {
	if (!Certification) return false;
	if (opt_debug) printf("producing Certification\n");

	preassign_mark(production, indent);

	if (Certification->Contract) { // 'certify contract as ..'
		assign(production, indent, Certification->Symbol, null);
	} else if (Certification->Expression) {
		assign(production, indent, Certification->Symbol,
		       Certification->Expression);
	} else {		       // nothing -> create a parameter
		insert_parameter_and_set_member(production, &instructions,
						Certification->Symbol, false,
						paratag, indent, __LINE__);
		// ◊ cf. evaluation.lex commissioned() / statement.lex certify()
	}

	log_entry(production, Certification->Symbol->Name, "certified", indent);

	delete_preassign_mark(production);

	return true;
}

bool js_declaration(char **production, Declaration *Declaration, int indent) {
	if (!Declaration) return false;
	if (opt_debug) printf("producing Declaration\n");

	assign(production, indent, Declaration->Symbol,
	       Declaration->Expression);

	log_entry(production, Declaration->Symbol->Name, "declared", indent);

	return true;
}

	/* e.g. The Secured Party may file the Continuation Statement. (only example currently) */
bool js_filing(char **production, Filing *Filing, int indent) {
	if (!Filing) return false;
	if (opt_debug) printf("producing Filing\n");

	if (Filing->Expression)
		assign(production, indent, Filing->Symbol, Filing->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Filing->Symbol, false, paratag,
						indent, __LINE__);

	log_entry(production, Filing->Symbol->Name, "filed", indent);

	return true;
}

	/* e.g., The Licensee may register a Comment Text. (only example) */
bool js_registration(char **production, Registration *Registration, int indent) {
	if (!Registration) return false;
	if (opt_debug) printf("producing registration\n");

	if (Registration->Expression)
		assign(production, indent, Registration->Symbol,
		       Registration->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Registration->Symbol, false,
						paratag, indent, __LINE__);

	log_entry(production, Registration->Symbol->Name, "registered", indent);

	return true;
}

bool js_grantment(char **production, Grantment *Grantment, int indent) {
	if (!Grantment) return false;
	if (opt_debug) printf("producing Grantment\n");

	assign(production, indent, Grantment->Symbol, null);	// sets true

	log_entry(production, Grantment->Symbol->Name, "granted", indent);

	return true;
}

bool js_appointment(char **production, Appointment *Appointment, int indent) {
	if (!Appointment) return false;
	if (opt_debug) printf("producing Appointment\n");

	insert_parameter_and_set_member(production, &instructions,
					Appointment->Symbol, false, paratag,
					indent, __LINE__);

	log_entry(production, Appointment->Symbol->Name, "appointed", indent);

	return true;
}

bool js_acceptance(char **production, Acceptance *Acceptance, int indent) {
	if (!Acceptance) return false;
	if (opt_debug) printf("producing Acceptance\n");

	insert_parameter_and_set_member(production, &instructions,
					Acceptance->Symbol, false, paratag,
					indent, __LINE__);

	log_entry(production, Acceptance->Symbol->Name, "accepted", indent);

	return true;
}

	/* The Licensor or the Arbiter may fix the Notice Time as the respective current time.
	 * The Licensor [..] fixes the Description of Goods. */
bool js_fixture(char **production, Fixture *Fixture, int indent) {
	if (!Fixture) return false;
	if (opt_debug) printf("producing Fixture\n");

	if (Fixture->Expression)
		assign(production, indent, Fixture->Symbol,
		       Fixture->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Fixture->Symbol, false, paratag,
						indent, __LINE__);

	log_entry(production, Fixture->Symbol->Name, "fixed", indent);

	return true;
}

bool js_setting(char **production, Setting *Setting, int indent) {
	if (!Setting) return false;
	if (opt_debug) printf("producing Setting\n");

	assign(production, indent, Setting->Symbol, null);	// null -> set true

	log_entry(production, Setting->Symbol->Name, "state set", indent);

	return true;
}

bool js_payment(char **production, Payment *Payment, int indent) {
	if (!Payment) return false;
	if (opt_debug) printf("producing Payment\n");

	preassign_mark(production, indent);

	bool explicit_from_escrow = Payment->Escrow || Payment->From_Escrow;
	bool explicit_to_escrow = !Payment->Object->Symbol
		&& !Payment->Object->Reflexive;
	assert(!(explicit_from_escrow && explicit_to_escrow));
	// ◊◊ printf("Flags: %d, %d, %d\n", explicit_from_escrow, explicit_to_escrow, !!Payment->Expression);

	/* function head */
	js_pay(production, Payment->Pay, indent);

	/* sender */
	if (Payment->Escrow)
		js_escrow(production, Payment->Escrow, 0);
	else if (Payment->From_Escrow)
		js_from_escrow(production, Payment->From_Escrow, 0);
	else
		js_name(production, (Name *) subject, false, 0);

	padcat(0, 0, production, ", ");
	/* receiver */
	if (!explicit_to_escrow) {
		payment_expression = true;
		js_object(production, Payment->Object, 0);
		payment_expression = false;
	} else
		padcat(0, 0, production, "'escrow'");

	padcat(0, 0, production, ", ");

	/* amount */
	if (Payment->Expression) {
		payment_expression = true;
		js_expression(production, Payment->Expression, 0);
		payment_expression = false;
	} else {
		padcat(0, 0, production,
		       main_constructor_body ? "this._escrow" : "main._escrow");
	}

	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);
	return true;
}

bool js_pay(char **production, Pay *Pay, int indent) {
	if (!Pay) return false;
	if (opt_debug) printf("producing Pay\n");
	uses_transfer = true;

	padcat(1, indent, production, (class ? "main" : "this"), ".transfer(");
	optional_caller(production);

	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool js_escrow(char **production, Escrow *Escrow, int indent) {
	if (!Escrow) return false;
	if (opt_debug) printf("producing Escrow\n");
	padcat(0, 0, production, "'escrow'");

	return true;
}

bool js_from_escrow(char **production, From_Escrow *From_Escrow, int indent) {
	if (!From_Escrow) return false;
	if (opt_debug) printf("producing From_Escrow\n");
	padcat(0, 0, production, "'escrow'");

	return true;
}

bool js_sending(char **production, Sending *Sending, int indent) {
	if (!Sending) return false;
	if (opt_debug) printf("producing Sending\n");

	preassign_mark(production, indent);
	// ◊ change mech to allow for multiple pre-assignments
	// ◊ get out of possible access block for multi-sentence clauses

	js_send(production, Sending->Send, indent);

	/* sender */
	js_name(production, (Name *) subject, false, 0);
	padcat(0, 0, production, ", ");

	/* receiver */
	assert(Sending->Object->Symbol || Sending->Object->Reflexive);
	js_object(production, Sending->Object, 0);
	padcat(0, 0, production, ", ");

	/* message */

	js_expression(production, Sending->Expression, 0);

	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);

	return true;
}

bool js_send(char **production, Send *Send, int indent) {
	if (!Send) return false;
	if (opt_debug) printf("producing Send\n");

	uses_notification = true;

	padcat(1, indent, production, (class ? "main." : "this."), "notify(");
	optional_caller(production);

	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool js_notification(char **production, Notification *Notification, int indent) {	// document it ◊
	if (!Notification) return false;
	if (opt_debug) printf("producing Notification\n");
	beyond_assignment = true;      // ◊ make comprehensive

	preassign_mark(production, indent);

	js_notify(production, Notification->Notify, indent);

	// sender
	js_name(production, (Name *) subject, false, 0);
	padcat(0, 0, production, ", ");

	// receiver
	assert(Notification->Object->Symbol || Notification->Object->Reflexive);
	js_object(production, Notification->Object, 0);
	padcat(0, 0, production, ", ");

	// message
	if (Notification->Expression) {

		js_expression(production, Notification->Expression, 0);

	} else {
		padcat(0, 0, production, "\"NOTIFICATION\"");
	}
	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);

	return true;
}

bool js_notify(char **production, Notify *Notify, int indent) {
	if (!Notify) return false;
	if (opt_debug) printf("producing Notify\n");
	uses_notification = true;

	padcat(1, indent, production, (class ? "main." : "this."), "notify(");
	optional_caller(production);

	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;

	return true;
}

bool js_termination(char **production, Termination *Termination, int indent) {
	if (!Termination) return false;
	if (opt_debug) printf("producing Termination\n");
	padcat(1, indent, production, "");
	js_this_contract(production, Termination->This_Contract, indent + 1);
	js_all_contracts(production, Termination->All_Contracts, indent + 1);
	js_terminate(production, Termination->Terminate, indent + 1);
	return true;
}

bool js_terminate(char **production, Terminate *Terminate, int indent) {
	if (!Terminate) return false;
	if (opt_debug) printf("producing Terminate\n");

	uses_termination = true;
	padcat(0, 0, production, "termination(",
	       (opt_log || opt_feedback) ? "caller" : "", ");");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;

	return true;
}

bool js_flagging(char **production, Flagging *Flagging, int indent) {
	if (!Flagging) return false;
	if (opt_debug) printf("producing Flagging\n");

	assign(production, indent, Flagging->Symbol, null);	// null -> set true

	return true;
}

bool js_condition(char **production, Condition *Condition, int indent) {
	if (!Condition) return false;
	if (opt_debug) printf("producing Condition\n");

	js_if(production, Condition->If, indent);

	js_expression(production, Condition->Expression, indent + 1);

	padcat(0, 0, production, ") {");
	return true;
}

bool js_if(char **production, If *If, int indent) {
	if (!If) return false;
	if (opt_debug) printf("producing If\n");
	padcat(1, indent, production, "if(");
	return true;
}

bool js_expression(char **production, Expression *Expression, int indent) {
	if (!Expression) return false;
	if (opt_debug) printf("producing Expression\n");
	js_combination(production, Expression->Combination, indent + 1);
	return true;
}

bool js_scalar_comparison(char **production,
			  Scalar_Comparison *Scalar_Comparison, int indent) {
	if (!Scalar_Comparison) return false;
	if (opt_debug) printf("producing Scalar_Comparison\n");

	padcat(0, 0, production, "(");
	js_scalar_expression(production, Scalar_Comparison->Scalar_Expression,
			     indent + 1);

	js_comparison_operator(production,
			       Scalar_Comparison->Comparison_Operator,
			       indent + 1);

	char *inference_stack = inference;

	js_scalar_expression(production, Scalar_Comparison->Scalar_Expression2,
			     indent + 1);
	inference = inference_stack;

	padcat(0, 0, production, ")");

	return true;
}

bool js_comparison_operator(char **production,
			    Comparison_Operator *Comparison_Operator,
			    int indent) {
	if (!Comparison_Operator) return false;
	if (opt_debug) printf("producing Comparison_Operator\n");
	js_equal(production, Comparison_Operator->Equal, indent + 1);
	js_later(production, Comparison_Operator->Later, indent + 1);
	return true;
}

bool js_equal(char **production, Equal *Equal, int indent) {
	if (!Equal) return false;
	padcat(0, 0, production, " == ");
	inference = "bool";
	return true;
}

bool js_greater(char **production, Greater *Greater, int indent) {
	if (!Greater) return false;
	if (opt_debug) printf("producing Greater\n");
	padcat(0, 0, production, " > ");
	inference = "bool";
	return true;
}

bool js_less(char **production, Less *Less, int indent) {
	if (!Less) return false;
	if (opt_debug) printf("producing Less\n");
	padcat(0, 0, production, " < ");
	inference = "bool";
	return true;
}

bool js_later(char **production, Later *Later, int indent) {
	if (!Later) return false;
	if (opt_debug) printf("producing Later\n");
	padcat(0, 0, production, " <= ");

	inference = "bool";
	return true;
}

bool js_scalar_expression(char **production,
			  Scalar_Expression *Scalar_Expression, int indent) {
	if (!Scalar_Expression) return false;
	if (opt_debug) printf("producing Scalar_Expression %s\n",
			      Scalar_Expression->Scalar);
	js_symbol(production, Scalar_Expression->Symbol, false, indent + 1);
	js_scalar(production, Scalar_Expression->Scalar, indent + 1);
	js_point_in_time(production, Scalar_Expression->Point_In_Time,
			 indent + 1);
	bool is_escrow_literal = !Scalar_Expression->Symbol
		&& !Scalar_Expression->Scalar
		&& !Scalar_Expression->Point_In_Time;
	if (is_escrow_literal) {
		padcat(0, 0, production,
		       main_constructor_body ? "this._escrow" : "main._escrow");
	}

	inference = "uint";
	return true;
}

bool js_hex_expression(char **production, Hex_Expression *Hex_Expression,
		       int indent) {
	if (!Hex_Expression) return false;
	if (opt_debug) printf("producing Hex_Expression %s\n",
			      Hex_Expression->Hex);
	js_symbol(production, Hex_Expression->Symbol, false, indent + 1);
	js_hex(production, Hex_Expression->Hex, indent + 1);
	// js_point_in_time(production, Hex_Expression->Point_In_Time, indent+1);
	inference = "uint";
	return true;
}

bool js_combination(char **production, Combination *Combination, int indent) {
	if (!Combination) return false;
	if (opt_debug) printf("producing Combination\n");
	if (Combination->Combinator) padcat(0, 0, production, "(");
	js_combinor(production, Combination->Combinor, 0);
	js_combinator(production, Combination->Combinator, indent);
	js_combination(production, Combination->Combination, 0);
	char *inference_stack = inference;

	if (Combination->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;
	return true;
}

bool js_combinor(char **production, Combinor *Combinor, int indent) {
	if (!Combinor) return false;
	if (opt_debug) printf("producing Combinor\n");
	if (Combinor->Combinator) padcat(0, 0, production, "(");

	js_combinand(production, Combinor->Combinand, 0);
	js_combinator(production, Combinor->Combinator, 0);
	js_combinor(production, Combinor->Combinor, 0);

	char *inference_stack = inference;

	if (Combinor->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;

	return true;
}

bool js_combinand(char **production, Combinand *Combinand, int indent) {
	if (!Combinand) return false;

	if (Combinand->Symbol) {
		char *funcname = Combinand->Symbol->Name;

		if (!funcname) funcname = Combinand->Symbol->Type->Literal;
		assert(funcname);
		char *varname = snakedup(funcname);

		if (!in(fixed, varname) && !in(functions, funcname)) {	// ◊ insufficient concept, depending on order
			/* produce amounts/texts etc variables: take care that they
			 * 1) become parameters, and 2) object elements with that parameter assigned
			 * e.g., The Secured Party may pay a Reminder Fee into escrow. */
			// ◊ into symbol coming in here
			insert_parameter_and_set_member(production,
							&instructions,
							Combinand->Symbol,
							payment_expression,
							paratag, indent + 4,
							__LINE__);
		}

		/* produce the literal (name or type name for variables that are named verbatim a type) */
		if (!no_literal) {

			js_symbol(production, Combinand->Symbol, false,
				  indent + 1);

		}
		mtrac_free(varname);
	}
	js_expiration(production, Combinand->Expiration, indent + 1);
	js_timeliness(production, Combinand->Timeliness, indent + 1);
	js_description(production, Combinand->Description, indent + 1);
	js_scalar_comparison(production, Combinand->Scalar_Comparison,
			     indent + 1);
	js_negation(production, Combinand->Negation, indent + 1);
	js_existence(production, Combinand->Existence, indent + 1);
	js_point_in_time(production, Combinand->Point_In_Time, indent + 1);

	return true;
}

bool js_combinator(char **production, Combinator *Combinator, int indent) {
	if (!Combinator) return false;
	if (opt_debug) printf("producing Combinator\n");
	js_or_(production, Combinator->Or_, indent);
	js_and(production, Combinator->And, indent);
	js_neither(production, Combinator->Neither, indent);
	js_nor(production, Combinator->Nor, indent);

	return true;
}

bool js_or_(char **production, Or_ *Or_, int indent) {
	if (!Or_) return false;
	if (opt_debug) printf("producing Or_\n");
	padcat(indent ? 1 : 0, indent, production, " || ");
	inference = "bool";
	return true;
}

bool js_and(char **production, And *And, int indent) {
	if (!And) return false;
	if (opt_debug) printf("producing And\n");
	padcat(indent ? 1 : 0, indent, production, " && ");
	inference = "bool";
	return true;
}

bool js_neither(char **production, Neither *Neither, int indent) {
	if (!Neither) return false;
	if (opt_debug) printf("producing Neither\n");
	padcat(1, indent, production, "( neither ");
	padcat(0, 0, production, ") ");
	inference = "bool";
	return true;
}

bool js_nor(char **production, Nor *Nor, int indent) {
	if (!Nor) return false;
	if (opt_debug) printf("producing Nor\n");
	padcat(1, indent, production, "( nor ");
	inference = "bool";
	return true;
}

bool js_existence(char **production, Existence *Existence, int indent) {
	////// check and test for rule 'symbol be fixed'
	if (!Existence) return false;
	if (opt_debug) printf("producing Existence\n");
	// padcat(0, 0, production, "(");
	padcat(0, 0, production, "");

	assert(Existence->Symbol->Name);	// should never need Existance->Symbol->Type->Literal
	js_symbol(production, Existence->Symbol, false, indent + 1);
	inference = "bool";
	return true;
}

bool js_negation(char **production, Negation *Negation, int indent) {
	if (!Negation) return false;
	if (opt_debug) printf("producing Negation\n");
	js_negator(production, Negation->Negator, indent + 1);
	js_symbol(production, Negation->Symbol, false, indent + 1);
	assert(Negation->Symbol->Name);	// should never need Negation->Symbol->Type->Literal (?)
	inference = "bool";
	return true;
}

bool js_negator(char **production, Negator *Negator, int indent) {
	if (!Negator) return false;
	if (opt_debug) printf("producing Negator\n");
	padcat(0, 0, production, "!");
	inference = "bool";
	return true;
}

bool js_being(char **production, Being *Being, int indent) {
	if (!Being) return false;
	if (opt_debug) printf("producing Being\n");
	inference = "bool";
	return true;
}

bool js_true(char **production, True *True, int indent) {
	if (!True) return false;
	if (opt_debug) printf("producing True\n");
	return true;
}

bool js_article(char **production, Article *Article, int indent) {
	if (!Article) return false;
	return true;
}

bool js_point_in_time(char **production, Point_In_Time *Point_In_Time,
		      int indent) {
	if (!Point_In_Time) return false;
	if (opt_debug) printf("producing Point In Time\n");
	js_current_time(production, Point_In_Time->Current_Time, indent + 1);
	js_relative_time(production, Point_In_Time->Relative_Time, indent + 1);

	inference = "uint";
	return true;
}

bool js_current_time(char **production, Current_Time *Current_Time, int indent) {
	if (!Current_Time) return false;
	if (opt_debug) printf("producing Current_Time\n");
	padcat(0, 0, production, "Date.now()");
	inference = "uint";
	return true;
}

bool js_relative_time(char **production, Relative_Time *Relative_Time,
		      int indent) {
	if (!Relative_Time) return false;
	if (opt_debug) printf("producing Relative_Time\n");
	if (Relative_Time->Symbol) {
		padcat(0, 0, production, "(");

		js_symbol(production, Relative_Time->Symbol, false, indent + 1);

		padcat(0, 0, production, " + ");
	} else {
		padcat(0, 0, production, "(Date.now() - ");
	}
	js_duration(production, Relative_Time->Duration, indent + 1);
	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool js_duration(char **production, Duration *Duration, int indent) {
	if (!Duration) return false;
	if (opt_debug) printf("producing Duration\n");
	padcat(0, 0, production, "(");

	js_scalar_expression(production, Duration->Scalar_Expression,
			     indent + 1);
	padcat(0, 0, production, " * ");
	js_time_unit(production, Duration->Time_Unit, indent + 1);

	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool js_time_unit(char **production, Time_Unit *Time_Unit, int indent) {
	if (!Time_Unit) return false;
	if (opt_debug) printf("producing Time_Unit\n");
	js_years(production, Time_Unit->Years, indent + 1);
	js_months(production, Time_Unit->Months, indent + 1);
	js_weeks(production, Time_Unit->Weeks, indent + 1);
	js_days(production, Time_Unit->Days, indent + 1);
	js_hours(production, Time_Unit->Hours, indent + 1);
	js_minutes(production, Time_Unit->Minutes, indent + 1);
	js_seconds(production, Time_Unit->Seconds, indent + 1);
	js_milliseconds(production, Time_Unit->Milliseconds, indent + 1);
	inference = "uint";
	return true;
}

bool js_years(char **production, Years *Years, int indent) {
	if (!Years) return false;
	if (opt_debug) printf("producing Years\n");
	padcat(0, 0, production, "31536000000");
	inference = "uint";
	return true;
}

bool js_months(char **production, Months *Months, int indent) {
	if (!Months) return false;
	if (opt_debug) printf("producing Months\n");
	padcat(0, 0, production, "2592000000");
	inference = "uint";
	return true;
}

bool js_weeks(char **production, Weeks *Weeks, int indent) {
	if (!Weeks) return false;
	if (opt_debug) printf("producing Weeks\n");
	padcat(0, 0, production, "604800000");
	inference = "uint";
	return true;
}

bool js_days(char **production, Days *Days, int indent) {
	if (!Days) return false;
	if (opt_debug) printf("producing Days\n");
	padcat(0, 0, production, "86400000");
	inference = "uint";
	return true;
}

bool js_hours(char **production, Hours *Hours, int indent) {
	if (!Hours) return false;
	if (opt_debug) printf("producing Hours\n");
	padcat(0, 0, production, "3600000");
	inference = "uint";
	return true;
}

bool js_minutes(char **production, Minutes *Minutes, int indent) {
	if (!Minutes) return false;
	if (opt_debug) printf("producing Minutes\n");
	padcat(0, 0, production, "60000");
	inference = "uint";
	return true;
}

bool js_seconds(char **production, Seconds *Seconds, int indent) {
	if (!Seconds) return false;
	if (opt_debug) printf("producing Seconds\n");
	padcat(0, 0, production, "1000");
	inference = "uint";
	return true;
}

bool js_milliseconds(char **production, Milliseconds *Milliseconds, int indent) {
	if (!Milliseconds) return false;
	if (opt_debug) printf("producing Milliseconds\n");
	padcat(0, 0, production, "1");
	inference = "uint";
	return true;
}

bool js_expiration(char **production, Expiration *Expiration, int indent) {
	if (!Expiration) return false;
	if (opt_debug) printf("producing Expiration\n");

	/* 'has passed' means that the moment has happened that the millisecond was counted as passed -> <= */
	padcat(0, 0, production, " <= Date.now()");
	inference = "bool";
	return true;
}

bool js_timeliness(char **production, Timeliness *Timeliness, int indent) {
	if (!Timeliness) return false;
	if (opt_debug) printf("producing Timeliness\n");

	/* 'has not passed' means that the moment has not happened that the millisecond was counted as passed -> > */
	padcat(0, 0, production, " > Date.now()");
	inference = "bool";
	return true;
}

	/* Assign a parameter value to a class member, and create the declaration for the class member.
	 * Optimized to unite the declaration of the member (and assigning it null) with setting its value
	 * to the parameter immediately already in the declaration, instead of first setting it to null.
	 * Uses text replacement in the production string, which might be based in part on 'this.' not being
	 * used outside the constructor (but 'main.'), to work. */
void insert_parameter_and_set_member(char **production, char **instructions,
				     Symbol *symbol, bool payment,
				     size_t paratag, int indent, int line) {

	/* callstack inspection: write calling line number into production. */
	if (_concat_trace)
		_concatnum(production, " ", line, "> ");

	char *pretty_varname;

	if (symbol->Name) pretty_varname = snakedup(symbol->Name);
	else if (symbol->Type) pretty_varname = snakedup(symbol->Type->Literal);
	else assert(false);

	char *symbol_name;

	if (symbol->Name) symbol_name = symbol->Name;
	else if (symbol->Type) symbol_name = symbol->Type->Literal;
	else assert(false);
	// ◊ double check that it is only alphanumeric, no " and \ etc

	if (opt_debug) printf("producing parameter %s\n", pretty_varname);

	// protect keywords
	char *varname = safedup(pretty_varname);

	// protect parameters with leading underscore (sol),
	// or not because this. or main or state. will be prefixed (js, sop).
	char *parameter_varname = mtrac_strdup("");

	concat(&parameter_varname, pretty_varname);	// same because member gets 'this.' or 'main.' prefixed

	// prepend type (sol, sop)
	char *typed_varname = mtrac_strdup("");

	concat(&typed_varname, varname);	// no type added for js
	char *pretty_typed_varname = mtrac_strdup("");

	concat(&pretty_typed_varname, pretty_varname);	// not type added for js
	char *typed_parameter_varname = mtrac_strdup("");

	concat(&typed_parameter_varname, parameter_varname);	// not type added for js

	/* binding to msg.sender and msg.value */

	// printf("payment %d -- msg_value %s -- pretty varname %s -- lextype %s\n", payment, msg_value, pretty_varname, lextype(pretty_varname)); ◊ make option
	/* 1: Add to the parameters and arguments list. In the produced code as well as (parameta) the instructions */

	char *search = mtrac_strdup("");

	concat(&search, ":", parameter_varname, ":");
	if (!strstr(args, search)) {
		concat(&args, search);
		if (!current_function) {
			/* outside a function (recital/constructor) */
			padcat(0, 0, &parameters, *parameters ? ", " : "",
			       typed_parameter_varname);
			padcat(0, 0, &arguments, *arguments ? ", " : "",
			       parameter_varname);
			if (instructions) padcat(0, 0, &parameta,
						 *parameta ? ", " : "", "<",
						 pretty_typed_varname, ">");
		} else {
			/* inside a function (clause) */
			padcat(0, 0, &current_function->parameters,
			       *current_function->parameters ? ", " : "",
			       typed_parameter_varname);
			// arguments don't happen in this case
			if (instructions)
				padcat(0, 0, &current_function->parameta,
				       *current_function->parameta ? ", " : "",
				       "<", pretty_typed_varname, ">");
		}
	}
	mtrac_free(search);
	/* 2: Set the member to the parameter.  It's a member only if it's not a variable named for a type
	 * (then found at Symbol->Type->Literal) */
	if (symbol->Name) {
		// ◊ into symbol coming in here
		/* js: prep: we will (at [1]) look for, eg 'x = null;' in the previously produced */
		char *nulling = mtrac_strdup("");

		mtrac_concat(&nulling, "this.", varname, " = null;");

		/* js: prep: .. to replace it (at [1]) with 'x = xpara;' */
		char *setting = mtrac_strdup("");

		mtrac_concat(&setting, "this.", varname, " = ", varname, EOL);
		bool preassign = !!strstr(*production, "%preassign%");

		/* 2a: optimized setting right in the declaration list (replacing '= null') */
		// printf("\n\nOPT\n\n%d: %s\n\n%s\n\n", paratag, nulling, paratag>=0?*production+paratag:""); ◊ make option
		if (paratag >= 0 && strstr(*production + paratag, nulling)) {	// ◊ test for (conflicting) covenant symbols
			replace_first_from(production, nulling, setting, *production + paratag);	// [1]
		} else
			/* 2b: set member immediately before the use of the value:
			 * within functions (instead within the constructor) when a parameter's value is to be used,
			 * and a member set to this value on the fly. The setting is inserted before the start of the
			 * statement that the expression is nested in that uses the symbol in question. */

		if (strstr(*production, "%preassign%")) {

			char *line = mtrac_strdup("");

			padcat(1, preass_indent, &line, setting);
			replace(production, "%preassign%", line);	// insert before current statement
			mtrac_free(line);
		}

		/* 2c: but if we could not find either, just create a member and assign the given parameter,
		 * js: production will currently be at declaration height, so we effectively append to the member declaration list */
		else {
			padcat(1, indent, production, setting);
		}

		mtrac_free(nulling);

		mtrac_free(setting);

	}

	/* 3: track that this symbol has been set */
	padcat(0, 0, &fixed, ":", varname, ":");

	mtrac_free(varname);
	mtrac_free(pretty_varname);
	mtrac_free(typed_varname);
	mtrac_free(parameter_varname);
	mtrac_free(typed_parameter_varname);
	mtrac_free(pretty_typed_varname);
}

void produce_access_conditions(int down, int indent, char **production,
			       list *subjects) {

	if (!subjects) return;

	padcat(down, indent, production, "if(");
	list *s = subjects;
	int i = 0;

	while (s) {
		if (i++) padcat(0, 0, production, " || ");
		padcat(0, 0, production, "caller == ");
		js_name(production, (char *)s->item, false, 0);
		if (current_function) current_function->uses_caller = true;
		s = s->next;
	}
	padcat(0, 0, production, ") {");
}

void error(char *msg, char *cargo) {
	printf("Lexon semantic error: %s %s%s%s.\n", msg, cargo ? "(" : "",
	       cargo ? cargo : "", cargo ? ")" : "");
	if (current_function) printf("In clause %s.\n", current_function->lexname);	// ◊ add file and line
	exit(1);
}

/* end of file */
