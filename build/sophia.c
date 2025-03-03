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

  /*    sophia.c - Sophia backend       */

#define backend_version "sophia 0.3.102 beta 2"
#define target_version "sophia 8+"

#define CYCLE_2 true

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define EOL ""

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

bool sophia_document(char **production, struct Document *root, int indent);

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
static bool miller = false;

static char *safedup(const char *name) {
	assert(name);
	char *_safe = mtrac_malloc(strlen(name) + 3);

	strcpy(_safe, " ");
	strcat(_safe, name);
	strcat(_safe, " ");
	if (!strstr(" main Message permit notify terminate terminated default contract"	// Lexon ◊
		    " constructor function transfer call check_termination" " contract include let switch type record datatype if elif"	// Sophia 7.1
		    " else function stateful payable true false mod public"
		    " entrypoint private indexed namespace interface main using"
		    " as for hiding", _safe)) {

		strcpy(_safe, name);

	} else {

		strcpy(_safe, "_");
		strcat(_safe, name);
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
static void inject_permit(char **production, int indent);
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

		mtrac_concat(&head, "(", b->parameters, ")");
		mtrac_concat(&ihead, "(", b->parameta, ")");
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

bool sophia_walk(char **production);
bool sophia_name(char **production, Name * Name, bool assign, int indent);
bool sophia_description(char **production, Description * Description,
			int indent);
bool sophia_scalar(char **production, Scalar * Scalar, int indent);
bool sophia_hex(char **production, Hex * Hex, int indent);

static const char *lexsymtype(Symbol * symbol);

/* AST walk (stub) functions */

bool sophia_document(char **production, Document * Document, int indent);
bool sophia_head(char **production, Head * Head, int indent);
bool sophia_lex(char **production, Lex * Lex, int indent);
bool sophia_lexon(char **production, Lexon * Lexon, int indent);
bool sophia_authors(char **production, Authors * Authors, int indent);
bool sophia_comment(char **production, Comment * Comment, int indent);
bool sophia_preamble(char **production, Preamble * Preamble, int indent);
bool sophia_terms(char **production, Terms * Terms, int indent);
bool sophia_covenants(char **production, Covenants * Covenants, int indent);
bool sophia_covenant(char **production, Covenant * Covenant, int indent);
bool sophia_provisions(char **production, Provisions * Provisions, int indent);
bool sophia_definitions(char **production, Definitions * Definitions,
			int indent);
bool sophia_definition(char **production, Definition * Definition, int indent);
bool sophia_clauses(char **production, Clauses * Clauses, int indent);
bool sophia_clause(char **production, Clause * Clause, int indent);
bool sophia_body(char **production, Body * Body, int indent);
bool sophia_function(char **production, Function * Function, int indent);
bool sophia_statements(char **production, Statements * Statements, int indent);
bool sophia_statement(char **production, Statement * Statement, int indent);
bool sophia_actions(char **production, Actions * Actions, int indent);
bool sophia_action(char **production, Action * Action, int indent);
bool sophia_subject(char **production, Subject * Subject, int indent);
bool sophia_symbols(char **production, Symbols * Symbols, int indent);
bool sophia_symbol(char **production, Symbol * Symbol, bool assign, int indent);
bool sophia_noun(char **production, Symbol * Symbol, int indent);
bool sophia_catena(char **production, Catena * Catena, int indent);
bool sophia_object(char **production, Object * Object, int indent);
bool sophia_reflexive(char **production, Reflexive * Reflexive, int indent);
bool sophia_predicates(char **production, Predicates * Predicates, int indent);
bool sophia_predicate(char **production, Predicate * Predicate, int indent);
bool sophia_certification(char **production, Certification * Certification,
			  int indent);
bool sophia_declaration(char **production, Declaration * Declaration,
			int indent);
bool sophia_filing(char **production, Filing * Filing, int indent);
bool sophia_registration(char **production, Registration * Registration,
			 int indent);
bool sophia_grantment(char **production, Grantment * Grantment, int indent);
bool sophia_appointment(char **production, Appointment * Appointment,
			int indent);
bool sophia_acceptance(char **production, Acceptance * Acceptance, int indent);
bool sophia_fixture(char **production, Fixture * Fixture, int indent);
bool sophia_setting(char **production, Setting * Setting, int indent);
bool sophia_payment(char **production, Payment * Payment, int indent);
bool sophia_pay(char **production, Pay * Pay, int indent);
bool sophia_escrow(char **production, Escrow * Escrow, int indent);
bool sophia_from_escrow(char **production, From_Escrow * From_Escrow,
			int indent);
bool sophia_sending(char **production, Sending * Sending, int indent);
bool sophia_send(char **production, Send * Send, int indent);
bool sophia_notification(char **production, Notification * Notification,
			 int indent);
bool sophia_notify(char **production, Notify * Notify, int indent);
bool sophia_termination(char **production, Termination * Termination,
			int indent);
bool sophia_terminate(char **production, Terminate * Terminate, int indent);
bool sophia_flagging(char **production, Flagging * Flagging, int indent);
bool sophia_condition(char **production, Condition * Condition, int indent);
bool sophia_if(char **production, If * If, int indent);
bool sophia_expression(char **production, Expression * Expression, int indent);
bool sophia_scalar_comparison(char **production,
			      Scalar_Comparison * Scalar_Comparison,
			      int indent);
bool sophia_comparison_operator(char **production,
				Comparison_Operator * Comparison_Operator,
				int indent);
bool sophia_equal(char **production, Equal * Equal, int indent);
bool sophia_greater(char **production, Greater * Greater, int indent);
bool sophia_less(char **production, Less * Less, int indent);
bool sophia_later(char **production, Later * Later, int indent);
bool sophia_scalar_expression(char **production,
			      Scalar_Expression * Scalar_Expression,
			      int indent);
bool sophia_combination(char **production, Combination * Combination,
			int indent);
bool sophia_combinor(char **production, Combinor * Combinor, int indent);
bool sophia_combinand(char **production, Combinand * Combinand, int indent);
bool sophia_combinator(char **production, Combinator * Combinator, int indent);
bool sophia_or_(char **production, Or_ * Or_, int indent);
bool sophia_and(char **production, And * And, int indent);
bool sophia_neither(char **production, Neither * Neither, int indent);
bool sophia_nor(char **production, Nor * Nor, int indent);
bool sophia_existence(char **production, Existence * Existence, int indent);
bool sophia_negation(char **production, Negation * Negation, int indent);
bool sophia_negator(char **production, Negator * Negator, int indent);
bool sophia_being(char **production, Being * Being, int indent);
bool sophia_true(char **production, True * True, int indent);
bool sophia_article(char **production, Article * Article, int indent);
bool sophia_point_in_time(char **production, Point_In_Time * Point_In_Time,
			  int indent);
bool sophia_current_time(char **production, Current_Time * Current_Time,
			 int indent);
bool sophia_relative_time(char **production, Relative_Time * Relative_Time,
			  int indent);
bool sophia_duration(char **production, Duration * Duration, int indent);
bool sophia_time_unit(char **production, Time_Unit * Time_Unit, int indent);
bool sophia_years(char **production, Years * Years, int indent);
bool sophia_months(char **production, Months * Months, int indent);
bool sophia_weeks(char **production, Weeks * Weeks, int indent);
bool sophia_days(char **production, Days * Days, int indent);
bool sophia_hours(char **production, Hours * Hours, int indent);
bool sophia_minutes(char **production, Minutes * Minutes, int indent);
bool sophia_seconds(char **production, Seconds * Seconds, int indent);
bool sophia_milliseconds(char **production, Milliseconds * Milliseconds,
			 int indent);
bool sophia_expiration(char **production, Expiration * Expiration, int indent);
bool sophia_timeliness(char **production, Timeliness * Timeliness, int indent);

static bool is_payment(Predicates *predicates) {
	while (predicates) {
		if (predicates->Predicate->Payment)
			return true;
		predicates = predicates->Predicates;
	}
	return false;
}

/* AST walk functions ----------------------------------------------------- */
static char *module = null;
static bind *current_function = null;
static bool single_sentence_clause = true;
static bool multi_sentence_clause = false;
static bool no_literal = false;
static char *msg_sender = null;
static char *msg_value = null;
static bool is_payable = false;
static bool payment_expression = false;
static bool conditional_expression = false;
static bool require_option = false;
static bool require_mandat = false;
static bool require_force = false;
static char *inference = null;
static bool is_stateful = false;
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
	"   Deploy this smart contract to the Aeternity blockchain or testchain. An easy way to\n"
	"   get started is to copy-paste this code into  https://studio.aepps.com.  Replace the\n"
	"   <parameters> with literal values to interact with the contract via terminal.\n\n"
	"   LIKE ALL SMART CONTRACTS THIS CODE MUST BE AUDITED BEFORE USING IT IN PRODUCTION.\n\n"
	"   Note  that the instructions below  reflect your Lexon code,  as well as the options\n"
	"   used during compilation of the code: different clauses and options will result from\n"
	"   different input code.  Some functions are 'built-in' but only appear when needed as\n"
	"   per compiler options used  during compilation – a list of options is available with\n"
	"   lexon -h.  The functions are given in the order of appearance, in the Lexon source.\n\n"
	"   The required caller is noted in double angle brackets << >>.  Some functions can be\n"
	"   called by anyone.  Note that roles are being defined by using an account for it for\n"
	"   the first time. This will require for the same account to be used for the same role\n"
	"   after this point. Else, the call will revert, i.e. cancelled and not go through.\n\n"
	"   Some clauses of the original Lexon source text do not appear in the comments below.\n"
	"   Namely, those without permission phrase, wherefore they are regarded as internal.\n\n"
	"   These are the constructor parameters for deployment. If you are using Aestudio, the\n"
	"   fields under the deploy button are where your values for them go before deploying.\n\n"
	"   %6%\n\n"
	"   These are the state progress functions that allow to interact with the contract:\n";

static bool enforce_same_subject = false;
static list *active_subjects = null;
static list *covenant_subjects = null;
static bool no_action_in_group_yet = true;
static bool uses_termination = false;
static bool uses_transfer = false;
static bool uses_notification = false;
static bool uses_permit = false;
static bool has_subclasses = false;
static bool uses_option = false;       // Sophia Option header inclusion for Option class
static Name *class = null;
static bool main_constructor_body = true;
static bool main_contract = true;
static bool covenant_constructor_body = false;
static bool terms_body = true;
static bool recital_of_terms = false;
bool sophia_walk(char **production) {
	if (!root) return false;
	return sophia_document(production, root, 0);
}

bool sophia_name(char **production, Name *Name, bool assign, int indent) {
	if (!Name) return false;

	/* put '_' to names that are target language keywords */
	char *safe = safedup(SNAKE(Name));
	bool global = in(globals, Name) && class;

	if (opt_harden && require_force) {
		padcat(0, 0, production, "Option.force_msg(");
		uses_option = true;
	}

	if (!in(functions, Name)) {
		padcat(0, 0, production, !miller ? "state." : "",
		       global &&!miller ? "global." : "", safe);
	} else {
		bind *bind = register_bind(safe, Name);
		padcat(0, 0, production, global &&!miller ? "state." : "",
		       bind->tag);
	}
	if (opt_harden
	    && require_force) padcat(0, 0, production, ", \"", Name,
				     " not set\")");

	if (assign) padcat(0, 0, &fixed, ":", safe, ":");
	mtrac_free(safe);
	return true;
}

bool sophia_description(char **production, Description *Description, int indent) {
	if (!Description) return false;
	padcat(0, 0, production, "\"", Description, "\"");
	return true;
}

bool sophia_scalar(char **production, Scalar *Scalar, int indent) {
	if (!Scalar) return false;
	padcat(0, 0, production, Scalar);
	return true;
}

bool sophia_hex(char **production, Hex *Hex, int indent) {
	if (!Hex) return false;
	padcat(0, 0, production, Hex);
	return true;
}
bool sophia_document(char **production, Document *Document, int indent) {
	if (!Document) return false;
	if (opt_debug) printf("producing Document\n");

	/* switch line# trace of every concat to code output buffer */
	_concat_trace = opt_debug_production;

	/* source code head */
	if (!opt_bare) padcat(0, indent, production,
			      "/** Lexon-generated Sophia code");
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
	/* instructions are being built up in parallel, eventually prepent.
	 * They will be built up for naught and discarded if opt_instructions is not set. */
	instructions = mtrac_strdup(instructions);

	char *file = mtrac_strdup(opt_source ? opt_source : "contract");

	replace(&file, ".lex", "");
	concat(&file, ".aesx");
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

	sophia_head(production, Document->Head, indent);

	/* source code head (Sop) */
	padcat(2, 0, production, "@compiler >=8");
	if (opt_harden) padcat(0, 0, production, "%43%");	// %43%: include "Option.aes"

	/* if covenants exist, the main state declaration is forward-extracted
	 * into its own namespace to be shared via a class interface 'Main'.
	 * The interface is required possibly because of an aesophia bug.
	 * Using the main contracts' type in places results in an 'unbound' error. */
	padcat(0, 0, production, "%37%");	// %37%: state namespace if covenants need access to it
	main_interface = mtrac_strdup( // not used when no covenants exist
					     "\n\nnamespace MainState =\n" "    record main_state = {%27%\n"	// %27%: declarations (if covenants exist)
					     "        }\n\n"
					     "using MainState\n\n"
					     "contract interface Main =\n"
					     "    entrypoint get_state: () => main_state\n");

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

	padcat(1, indent, production, "%28%main contract ", camel_spaced(module), "%38% =");	// %28%: payable, %38%: Main interface inheritance
	padcat(1, 0, production, "%39%");	// %39%: main_state type def, may contain %27%: declarations -- or state type def (if covenants)
	padcat(1, indent + 1, production, "%29%entrypoint init(%1%) = {%32%");	// %29%: emits, %1%: paras, %32%: initializations
	padcat(1, indent + 2, production, "}%40%%41%");	// %40%: state getter

	main_constructor_body = true;
	main_contract = true;
	assert(active_subjects == null);
	sophia_terms(production, Document->Terms, indent + 2);	// sets caller, uses methods variable for production string
	main_contract = false;
	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = null;

	/* sol, sop: end of main constructor */

	padcat(1, indent + 2, production, "%42%");	// end of init2
	padcat(1, indent + 1, production, "%34%");	// %34%: adders
	replace(production, "%1%", parameters);

	/* sop: command-dedicated, second constructor */
	if (beyond_assignment) {
		replace(production, "%41%",
			"\n    /* required additional constructor for statements beyond assignments */ \n    entrypoint init2() : state =");
		replace(production, "%42%", "state");
	} else {
		replace(production, "%41%", "");
		replace(production, "%42%", "");
	}

	padcat(0, 0, production, "%31%");	// %31%: auxiliary functions

	/* sol,sop: add the general terms methods beneath the constructor */
	padcat(0, 0, production, methods);

	/* sol, sop: end of main class (sop: by indent) */

	sophia_covenants(production, Document->Covenants, indent);

	/* aux functions to add a new sub object instance (covenants) */

	replace(production, "%34%", adders);
	/* AUXILIARY FUNCTIONS (main contract) */

	char *auxfuncs = mtrac_strdup("");

	/* access shorthand */
	if (uses_permit) inject_permit(&auxfuncs, indent + 1);

	/* safe transfer */
	if (uses_transfer) inject_transfer(&auxfuncs, indent + 1);

	/* notifications */
	if (uses_notification) inject_notify(&auxfuncs, &emits, indent + 1);

	/* place message structure definitions (emits) */
	replace(production, "%29%", emits);

	/* termination */
	if (uses_termination) inject_termination(&auxfuncs, "contract system",
						 indent + 1);
	/* aux functions insert - js: in place. soli+sop: higher up. */

	replace(production, "%31%", auxfuncs);
	mtrac_free(auxfuncs);
	/* end of file */
	if (!opt_bare) padcat(2, indent, production, "/* end */\n");

	_concat_trace = false;

	/* sort out names, privacy mark (javascript: '#') and parameters */
	replace_bind_tags(production, &instructions, binds);

	/* take care of termination flag [3] */
	if (uses_termination) {

		if (strlen(declarations)) padcat(0, 0, &declarations, ",");
		padcat(1, 3, &declarations, "terminated : bool");
		if (strlen(initializations)) padcat(0, 0, &initializations,
						    ",");
		padcat(1, 3, &initializations, "terminated = false");
	}
	/* insert declaration of member variables into constructor or interface declaration */
	if (!has_subclasses) {
		replace(production, "%37%", "");	// no namespace and Main interface
		replace(production, "%38%", "");
		replace(production, "%39%",
			"    record state = {\n        %27%\n        }");
		replace(production, "%27%", declarations);
		replace(production, "%40%", "");
	} else {
		replace(production, "%27%", "");
		replace(&main_interface, "%27%", declarations);
		replace(production, "%37%", main_interface);
		replace(production, "%38%", " : Main");
		replace(production, "%39%",
			"\n\n    type state = main_state\n");
		replace(production, "%40%",
			"\n\n    entrypoint get_state() : state =\n        state\n");
	}

	/* sop: insert initializations of member variables into constructor head */
	replace(production, "%32%", initializations);

	/* prepend instructions to the top - or just discard if not switched on */
	replace(&instructions, "%6%", parameta);
	replace(&instructions, "%contract%", instance_var_name);
	concat(&instructions, "\n");
	replace(production, "%0%", opt_instructions ? instructions : "");

	/* add option casts */
	replace(production, ":§§:", opt_harden ? "Some(" : "");
	replace(production, ":§:", opt_harden ? ")" : "");

	/* include Sophia Options declaration */
	if (opt_harden && uses_option)
		replace(production, "%43%", "\n\ninclude \"Option.aes\"");
	else
		replace(production, "%43%", "");
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
	mtrac_free(main_interface);
	mtrac_free(fixed);
	mtrac_free(class_lists);
	mtrac_free(restorers);
	mtrac_free(adders);
	mtrac_free(functions);
	mtrac_free(instructions);

	mtrac_free(file);
	mtrac_free(instance_var_name);

	return true;
}

	/* sol+sop: permit - optimized require() */
void inject_permit(char **production, int indent) {

	if (opt_comment) padcat(2, indent, production,
				"/* built-in caller assertion */");

	if (opt_harden) {
		padcat(C, indent, production,
		       "function permit(option_authorized : option(address), name : string) =");
		padcat(1, indent + 1, production, "switch(option_authorized)");
		padcat(1, indent + 2, production,
		       "None => abort(StringInternal.concat(name, \" not set\"))");
		padcat(1, indent + 2, production,
		       "Some(authorized) => if(Call.caller != authorized)");
		padcat(1, indent + 3, production,
		       "abort(StringInternal.concat(name, \" only\"))");
	} else {
		padcat(C, indent, production,
		       "function permit(authorized : address) =");
		padcat(1, indent + 1, production,
		       "require(Call.caller == authorized, \"access\")");
	}
}

	/* transfer of tokens */
void inject_transfer(char **production, int indent) {
	if (opt_comment) padcat(2, indent, production,
				"/* built-in safe transfer */");
	padcat(C, indent, production,
	       "stateful function transfer(to : address, amount : int) =");
	padcat(1, indent + 1, production, "Chain.spend(to, amount)");

}

	/* sending / emitting of a message */
void inject_notify(char **production, char **emits, int indent) {

	if (opt_comment) padcat(2, indent, production,
				"/* built-in send message */");

	padcat(C, indent, production,
	       "function notify(to : address, message : string) =");
	padcat(1, indent + 1, production,
	       "Chain.event(Message(Call.caller, to, message))", EOL);
	padcat(0, indent, emits,
	       "datatype event = Message(indexed address, indexed address, string)\n");
	padcat(1, indent, emits, "");

}

	/* terminate() - contract termination */
void inject_termination(char **production, char *prompt, int indent) {

	if (opt_comment) padcat(3, indent, production,
				"/* built-in termination of the ", prompt,
				" */");

	padcat(C, indent, production, "stateful function termination() =", EOL);
	padcat(1, indent + 1, production, "put(state{terminated = true})", EOL);

	padcat(3, indent, production, "function check_termination() =");
	padcat(1, indent + 1, production, "require(!state.terminated, \"",
	       prompt, " terminated before\")");
}

bool sophia_head(char **production, Head *Head, int indent) {
	if (!Head) return false;
	if (opt_debug) printf("producing Head\n");
	// padcat(2, indent, production, "/*");

	sophia_lex(production, Head->Lex, indent);
	sophia_preamble(production, Head->Preamble, indent);
	sophia_comment(production, Head->Comment, indent);
	sophia_authors(production, Head->Authors, indent);
	if (!opt_bare) {
		padcat(1, 0, production, " **	file:        ", opt_source);
		padcat(1, 0, production, " **");
		sophia_lexon(production, Head->Lexon, indent);
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

bool sophia_lex(char **production, Lex *Lex, int indent) {
	if (!Lex) return false;
	if (opt_debug) printf("producing Lex %s\n", Lex->Name);
	if (!opt_bare) {
		padcat(1, 0, production, " **	code:        ", Lex->Name);
		padcat(1, 0, production, " **");
	}
	module = Lex->Name;
	return true;
}

bool sophia_lexon(char **production, Lexon *Lexon, int indent) {
	if (!Lexon) return false;
	if (opt_debug) printf("producing Lexon %s\n", Lexon->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	code tagged: ",
		       Lexon->Description);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool sophia_authors(char **production, Authors *Authors, int indent) {
	if (!Authors) return false;
	if (opt_debug) printf("producing Authors %s\n", Authors->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	authors:     ",
		       Authors->Description);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool sophia_comment(char **production, Comment *Comment, int indent) {
	if (!Comment) return false;
	if (opt_debug) printf("producing comment %s\n", Comment->Description);
	if (!opt_bare) {
		padcat(1, 0, production, " **	comment:     ");
		sophia_description(production, Comment->Description,
				   indent + 1);
		padcat(1, 0, production, " **");
	}
	return true;
}

bool sophia_preamble(char **production, Preamble *Preamble, int indent) {
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
bool sophia_terms(char **production, Terms *Terms, int indent) {
	if (!Terms) return false;
	if (opt_debug) printf("producing Terms\n");
	sophia_provisions(production, Terms->Provisions, indent);
	return true;
}

bool sophia_covenants(char **production, Covenants *Covenants, int indent) {
	if (!Covenants) return false;
	if (opt_debug) printf("producing contracts\n");
	sophia_covenant(production, Covenants->Covenant, indent);
	sophia_covenants(production, Covenants->Covenants, indent);
	return true;
}

bool sophia_covenant(char **production, Covenant *Covenant, int indent) {
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
	bool main_uses_permit = uses_permit;

	uses_permit = false;
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

	padcat(0, 0, &declarations, *declarations ? "," : "");
	padcat(1, 3, &declarations, list, " : list(address),");
	padcat(1, 3, &declarations, count, " : int");
	padcat(0, 0, &initializations, *initializations ? "," : "");
	padcat(1, 3, &initializations, list, " = [],");
	padcat(1, 3, &initializations, count, " = 0");

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

		replace(&c, "\n", "\n" LEXCOM1 "\t");
		replace(&c, "\n" LEXCOM1 "\t\n", "\n" LEXCOM1 "\n");
		padcat(1, 0, production, LEXCOM0 "\n" LEXCOM1 "\t", c,
		       "\n" LEXCOM2);
		mtrac_free(c);
	}

	/* covenant constructor */
	padcat(2, indent, production, "%28%contract ", class, " =");	// %28%: payable
	padcat(2, indent + 1, production, "record state = {");
	padcat(1, indent + 3, production, "global : main_state,");
	padcat(0, 0, production, "%27C%");	// %27C%: covenant member declaration
	padcat(1, indent + 2, production, "}\n");
	padcat(1, indent + 1, production, "%29C%entrypoint init(global : Main%2,%%2%) = {%32C%,");	// %29C%: emits, %1%: paras, %32C%: initializations
	padcat(1, indent + 3, production, "global = global.get_state()");
	padcat(1, indent + 2, production, "}");

	char *declarations_stack = declarations;
	char *initializations_stack = initializations;
	char *parameters_stack = parameters;
	char *arguments_stack = arguments;
	char *args_stack = args;
	char *parameta_stack = parameta;

	declarations = mtrac_strdup("");
	initializations = mtrac_strdup("");

	parameters = mtrac_strdup("");
	arguments = mtrac_strdup("");
	args = mtrac_strdup("");
	parameta = mtrac_strdup("");   // sic, for JS too
	bool is_payable_stack = is_payable;
	bool is_stateful_stack = is_stateful;

	is_payable = false;
	is_stateful = false;

	padcat(2, 0, &instructions,
	       "   The following are actions that can be performed per ", class,
	       ".");
	padcat(2, 0, &instructions, "   > ", instance, " = %contract%.add_", instance, "(%2%)");	// ◊ check syntax

	enforce_same_subject = true;
	covenant_constructor_body = true;

	sophia_provisions(production, Covenant->Provisions, indent + 1);
	covenant_constructor_body = false;
	enforce_same_subject = false;

	/* AUXILIARY FUNCTIONS (covenant) */

	/* access shorthand */
	if (uses_permit) inject_permit(production, indent + 1);

	/* safe transfers */
	if (uses_transfer) inject_transfer(production, indent + 1);

	/* notifications */
	if (uses_notification) inject_notify(production, &emits, indent + 1);	// ~ emits is a local char *

	/* place message structure definitions (emits) */
	replace(production, "%29C%", emits);

	/* termination of covenant */
	if (uses_termination) inject_termination(production, "covenant",
						 indent + 1);

	/* take care of the covenant's termination flag [3] */
	if (uses_termination) {

		if (strlen(declarations)) padcat(0, 0, &declarations, ",");
		padcat(1, 3, &declarations, "terminated : bool");
		if (strlen(initializations)) padcat(0, 0, &initializations,
						    ",");
		padcat(1, 3, &initializations, "terminated = false");
	}

	/* end of covenant class definition */
	/* wrapper for the covenant constructor: user api to the hidden classes constructor (must appear after main's (top level) constructor */
	if (opt_comment) padcat(2, 1, &adders, "/* create new instance of ",
				Covenant->Name,
				" covenant, and register it with main */");

	padcat(C - 1, 1, &adders, "stateful entrypoint add_",
	       SNAKE(Covenant->Name), "(%2%) : address =");
	if (main_uses_termination) padcat(1, 2, &adders, "check_termination()");
	padcat(1, 2, &adders,
	       "let covenant = Chain.create(Address.to_contract(Contract.address) : ",
	       camel_spaced(module), "%2b,%%2b%) : ", class);
	padcat(1, 2, &adders, "put(state{ ", count, " = state.", count,
	       " + 1})");
	padcat(1, 2, &adders, "put(state{ ", list,
	       " = covenant.address :: state.", list, " })");
	padcat(1, 2, &adders, "covenant.address");

	char *perm = mtrac_strdup("");

	assert(covenant_subjects);
	produce_access_conditions(1, indent + 1, &perm, covenant_subjects);

	main_uses_permit = main_uses_permit || *perm;
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

	/* sol+sop: insert declaration of member variables into constructor (sol)/contract (sop) head */
	replace(production, "%27C%", declarations);

	/* sop: insert initializations of member variables into constructor (sop) head */
	replace(production, "%32C%", initializations);

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
	is_stateful = is_stateful_stack;
	mtrac_free(functions), functions = functions_shelve;
	mtrac_free(fixed), fixed = fixed_shelve;
	uses_permit = main_uses_permit;
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
bool sophia_provisions(char **production, Provisions *Provisions, int indent) {
	if (!Provisions) return false;
	if (opt_debug) printf("producing Provisions\n");

	/* definitions */
	if (!global_definitions) global_definitions = Provisions->Definitions;
	else covenant_definitions = Provisions->Definitions;	// (sic)
	sophia_definitions(production, Provisions->Definitions, indent);
	/* statements */
	recital_of_terms = main_constructor_body;
	no_action_in_group_yet = true;
	enforce_same_subject = true;
	single_sentence_clause = Provisions->Statements
		&& !Provisions->Statements->Statements;
	multi_sentence_clause = Provisions->Statements
		&& Provisions->Statements->Statements;

	msg_sender = null;
	msg_value = null;
	is_payable = false;
	is_stateful = false;
	sophia_statements(production, Provisions->Statements, indent);
	if (msg_sender) mtrac_free(msg_sender);
	if (msg_value) mtrac_free(msg_value);
	recital_of_terms = false;
	enforce_same_subject = false;

	/* end of constructor code */
	main_constructor_body = false;
	covenant_constructor_body = false;

	/* insert caller argumnet and 'payable' modifier */

	replace(production, "%28%", is_payable ? "payable " : "");

	/* clauses */
	sophia_clauses(instance ? production : &methods, Provisions->Clauses,
		       indent - (instance ? 0 : 1));

	char *termination_test = mtrac_strdup("");

	if (uses_termination) padcat(1, indent + (main_contract ? 0 : 1),
				     &termination_test,
				     "check_termination()" EOL);
	replace(instance ? production : &methods,
		main_constructor_body ? "%24%" : "%25%", termination_test);
	mtrac_free(termination_test);

	return true;
}

bool sophia_definitions(char **production, Definitions *Definitions, int indent) {
	if (!Definitions) return false;
	sophia_definitions(production, Definitions->Definitions, indent);
	sophia_definition(production, Definitions->Definition, indent);
	return true;
}

bool sophia_definition(char **production, Definition *Definition, int indent) {
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

	char *lowsnake_safe_name = safedup(SNAKE(Definition->Name));
	char *lowsnake_literal =
		safedup(SNAKE(Definition->Type_Term->Type->Literal));

	if (strlen(declarations)) padcat(0, 0, &declarations, ",");
	padcat(1, 3, &declarations, lowsnake_safe_name, " : ");
	padcat(0, 0, &declarations,
	       typemap(SNAKE(Definition->Type_Term->Type->Literal), opt_harden,
		       false, __LINE__), EOL);
	if (strlen(initializations)) padcat(0, 0, &initializations, ",");
	padcat(1, 3, &initializations, lowsnake_safe_name, " = ");
	padcat(0, 0, &initializations,
	       nullmap(SNAKE(Definition->Type_Term->Type->Literal),
		       !opt_harden), EOL);
	mtrac_free(lowsnake_safe_name);
	mtrac_free(lowsnake_literal);
	return true;
}

const char *typemap(const char *lex_type, bool option_type, bool forpara,
		    int line) {
	if (!lex_type) return "undefined";	// assert ◊
	if (option_type) {
		if (!strcmp(lex_type, "person")) return "option(address)";
		if (!strcmp(lex_type, "number")) return "option(int)";
		if (!strcmp(lex_type, "amount")) return "option(int)";
		if (!strcmp(lex_type, "time")) return "option(int)";
		if (!strcmp(lex_type, "text")) return "option(string)";
		if (!strcmp(lex_type, "data")) return "option(string)";
		if (!strcmp(lex_type, "binary")) return "option(bool)";
	} else {
		if (!strcmp(lex_type, "person")) return "address";
		if (!strcmp(lex_type, "number")) return "int";
		if (!strcmp(lex_type, "amount")) return "int";
		if (!strcmp(lex_type, "time")) return "int";
		if (!strcmp(lex_type, "text")) return "string";
		if (!strcmp(lex_type, "data")) return "string";
		if (!strcmp(lex_type, "binary")) return "bool";
	}
	printf("Unknown type at %d\n", line);	// ◊ make proper error call / fatal error / compiler error
	exit(1);
	return "[ ERROR: UNKNOWN TYPE ]";	// ◊ assert
}

const char *nullmap(const char *lex_type, bool defined_default) {
	if (!lex_type) return "undefined";
	// defined_default means, don't use None as null but a proper value.
	if (!defined_default) return "None";

	if (!strcmp(lex_type, "person")) return
			"ak_11111111111111111111111111111111273Yts";
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

bool sophia_this_contract(char **production, This_Contract *This_Contract,
			  int indent) {
	if (!This_Contract) return false;

	// intentionally empty
	return true;
}

bool sophia_all_contracts(char **production, All_Contracts *All_Contracts,
			  int indent) {
	if (!All_Contracts) return false;

	// intentionally empty — ◊ cover
	return true;
}

bool sophia_clauses(char **production, Clauses *Clauses, int indent) {
	if (!Clauses) return false;

	sophia_clauses(production, Clauses->Clauses, indent);
	sophia_clause(production, Clauses->Clause, indent);

	return true;
}

bool sophia_clause(char **production, Clause *Clause, int indent) {
	if (!Clause) return false;
	if (opt_debug) printf("producing Clause %s\n", Clause->Name);

	mtrac_free(args);
	args = mtrac_strdup("");
	list *active_subjects_stack = active_subjects;

	active_subjects = null;
	bool is_payable_stack = is_payable;
	bool is_stateful_stack = is_stateful;

	/* track which function calls which other functions */
	char *low = SNAKE(Clause->Name);
	char *safe = safedup(low);
	bind *bind = register_bind(safe, Clause->Name);

	mtrac_free(safe);
	current_function = bind;

	paratag = strlen(*production);
	if (opt_comment) padcat(3, indent, production, "/* ", Clause->Name,
				" clause */");

	/* clause comments from lexon clause text */
	if (opt_lexon_comments) {
		char *clause = snakedup(Clause->Name);
		char *c = mtrac_strdup(get_lexcom(clause));

		mtrac_free(clause);
		assert(c);
		if (!main_constructor_body && !class) {
			replace(&c, "\n", "\n    " LEXCOM1 " ");
			padcat(2, 0, production,
			       "    " LEXCOM0 "\n    " LEXCOM1 " ", c,
			       "\n    " LEXCOM2);
		} else {
			replace(&c, "\n", "\n    " LEXCOM1 " ");
			padcat(2, 0, production,
			       "    " LEXCOM0 "\n    " LEXCOM1 " ", c,
			       "\n    " LEXCOM2);
		}
		mtrac_free(c);
	}

	padcat(C, indent, production, "%33%%30%entrypoint ", bind->tag);	// %30%: payable, %33%: stateful
	padcat(1, 0, &instructions, "   • %26%", bind->tag);	// %26% caller

	assert(functions);
	if (Clause->Name) mtrac_concat(&functions, ":", Clause->Name, ":");

	sophia_body(production, Clause->Body, indent);
	replace(production, "%30%", is_payable ? "payable " : "");
	replace(production, "%33%", is_stateful ? "stateful " : "");
	replace(&instructions, "%26%", "anyone ⟶   ");	// in case no subject

	paratag = -1;
	current_function = null;       // not used in recitals

	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = active_subjects_stack;
	is_payable = is_payable_stack;
	is_stateful = is_stateful_stack;

	return true;
}

	/* Early catch if no subject of a multi-sentence clause could access.
	 * It's not really a courtesy only, for multi-sentence clauses
	 * where one sentence has NO subject. This summary access control
	 * protects the subject-less sentences. They are only reachable when
	 * any of the other sentences that has a subject is. */
char *courtesy;
char *courtesy_track;

bool sophia_body(char **production, Body *Body, int indent) {
	if (!Body) return false;
	if (opt_debug) printf("producing Body\n");

	padcat(0, 0, production, " =");

	/* check for termination */
	if (Body->Statements) padcat(0, 0, production,
				     main_constructor_body ? "%24%" : "%25%");

	no_action_in_group_yet = true;
	single_sentence_clause = Body->Statements
		&& !Body->Statements->Statements;
	multi_sentence_clause = Body->Statements
		&& Body->Statements->Statements;

	if (multi_sentence_clause) {

		courtesy = mtrac_strdup("require(");
		courtesy_track = mtrac_strdup("");
		padcat(1, indent + 1, production, "%36%");	// 36: courtesy multi-sentence access warning
	}

	msg_sender = null;
	msg_value = null;
	is_payable = false;
	is_stateful = false;
	sophia_statements(production, Body->Statements, indent + 1);
	if (msg_sender) mtrac_free(msg_sender);
	if (msg_value) mtrac_free(msg_value);

	if (multi_sentence_clause) {

		padcat(0, indent, &courtesy, ", \"not permitted\")" EOL);
		replace(production, "%36%", courtesy);
		mtrac_free(courtesy);
		mtrac_free(courtesy_track);
	}

	sophia_function(production, Body->Function, indent + 1);

	return true;
}

bool sophia_function(char **production, Function *Function, int indent) {
	if (!Function) return false;
	if (opt_debug) printf("producing Function %s\n", Function->Name);

	padcat(1, indent, production, "");
	sophia_expression(production, Function->Expression, indent + 1);
	padcat(0, 0, production, EOL);

	/* add return type to function signature */

	return true;
}

static char *subjlatebind = null;
bool sophia_statements(char **production, Statements *Statements, int indent) {
	if (!Statements) return false;
	if (opt_debug) printf("producing Statements\n");

	sophia_statements(production, Statements->Statements, indent);
	sophia_statement(production, Statements->Statement, indent);

	return true;
}

bool sophia_statement(char **production, Statement *Statement, int indent) {
	if (!Statement) return false;
	if (opt_debug) printf("producing Statement\n");
	sophia_action(production, Statement->Action, indent);
	sophia_flagging(production, Statement->Flagging, indent);
	return true;
}

static Name *subject = null;
static bool ever = false;
bool sophia_action(char **production, Action *Action, int indent) {
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

	assert(!subjlatebind);
	subjlatebind = mtrac_strdup("");
	padcat(0, 0, production, "%12%");

	sophia_subject(production, Action->Subject, indent);

	/* pre-insert the non-match comparisons and late bindings */

	replace(production, "%12%", subjlatebind);	// can be ""
	mtrac_free(subjlatebind), subjlatebind = null;

	/* check binding of the subject */
	bool single_subject = !Action->Subject->Symbols->Symbols;

	if (current_function) {
		current_function->uses_permission = !!Action->Permission;

		if (single_sentence_clause && single_subject) {

			padcat(1, indent, production, "permit(");
			if (current_function) current_function->uses_caller =
					true;
			sophia_symbol(production,
				      Action->Subject->Symbols->Symbol, false,
				      0);
			if (opt_harden) {
				padcat(0, 0, production, ", \"");
				sophia_noun(production,
					    Action->Subject->Symbols->Symbol,
					    0);
				padcat(0, 0, production, "\"");
			}

			padcat(0, 0, production, ")" EOL);
			uses_permit = true;

			// multi-subject and/or multi-sentence
		} else {
			if (single_sentence_clause) {

				padcat(1, indent, production, "require(");
			} else
				padcat(1, indent, production, "if(");
			Symbols *Symbols = Action->Subject->Symbols;
			int i = 0;

			while (Symbols && Symbols->Symbol) {
				char *symbol = mtrac_strdup("");

				sophia_symbol(&symbol, Symbols->Symbol, false,
					      0);
				if (i++) padcat(0, 0, production, " || ");
				padcat(0, 0, production,
				       ":§§:Call.caller:§: == ", symbol);
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
						       ":§§:Call.caller:§: == ",
						       symbol);
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
				       ", \"not permitted\")" EOL);
				// multi sentence
			} else {

				padcat(0, 0, production, ")");
				indent++;
			}
		}
	}

	sophia_condition(production, Action->Condition, indent);
	if (Action->Condition) indent++;

	sophia_predicates(production, Action->Predicates, indent);

	/* for multiple sentences, add the closing bracket */
	action = null;
	if (active_subjects
	    && active_subjects !=
	    covenant_subjects) delete_list(active_subjects);
	active_subjects = null;
	return true;
}

bool sophia_subject(char **production, Subject *Subject, int indent) {
	if (!Subject) return false;
	if (opt_debug) printf("producing Subject\n");
	char *_para = mtrac_strdup("");
	char **para = &_para;

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
			char *scope = (in(globals, s->Symbol->Name)
				       && class) ? "state.global." : "state.";

			padcat(0, 0, para, first ? "<<" : " or ", varname);
			first = false;

			/* binding of unbound person variable to caller parameter */
			if (!any && !main_constructor_body) {
				char *safe = safedup(varname);

				/* produce bind code. Person in question must still be null, i.e., unbound */
				if (!in(fixed, varname)) {
					// ◊ catch attempt to set global (main) value
					padcat(1, indent, &subjlatebind, "if(",
					       scope, safe, " == ",
					       nullvalue(lexname, !opt_harden),
					       ") put(state{", safe,
					       " = :§§:Call.caller:§:})");
					padcat(0, 0, &fixed, ":", safe, ":");
					any = true;
				}
				mtrac_free(safe);
			}
			mtrac_free(varname);
		}
		s = s->Symbols;
		first = false;
	}

	if (strlen(*para)) padcat(0, 0, para, ">>");	// ◊ .. sometimes produces >>>>
	if (strlen(*para)) concat(para, " ⟶   ");
	replace(&instructions, "%26%", *para);
	mtrac_free(_para);

	return true;
}

bool sophia_symbols(char **production, Symbols *Symbols, int indent) {
	if (!Symbols) return false;
	sophia_symbol(production, Symbols->Symbol, false, indent);
	sophia_catena(production, Symbols->Catena, indent);
	sophia_symbols(production, Symbols->Symbols, indent);
	return true;
}

bool sophia_symbol(char **production, Symbol *Symbol, bool assign, int indent) {
	if (!Symbol) return false;

	/* produce the name literal. Note that sophia_name adds 'this.'
	 * or 'main.', which makes for a global scope, while the cases
	 * that a type name is itself used as variable name, it is use
	 * unprefixed, for a local scope. */
	if (Symbol->Name)
		sophia_name(production, Symbol->Name, assign, indent);
	else {
		assert(Symbol->Type);
		char *safe = safedup(SNAKE(Symbol->Type->Literal));

		padcat(0, 0, production, safe);
		if (assign) padcat(0, 0, &fixed, ":", safe, ":");
		mtrac_free(safe);
	}
	return true;
}

bool sophia_noun(char **production, Symbol *Symbol, int indent) {
	if (!Symbol) return false;
	if (Symbol->Name)
		padcat(0, 0, production, Symbol->Name);
	else {
		assert(Symbol->Type);
		padcat(0, 0, production, Symbol->Type->Literal);
	}
	return true;
}

bool sophia_catena(char **production, Catena *Catena, int indent) {
	if (!Catena) return false;
	return true;
}

bool sophia_object(char **production, Object *Object, int indent) {
	if (!Object) return false;
	if (opt_debug) printf("producing Object\n");
	if (Object->Symbol) {
		if (opt_harden) {
			padcat(0, 0, production, "Option.force_msg(");
			uses_option = true;
		}
		sophia_symbol(production, Object->Symbol, false, indent + 1);
		if (opt_harden) {
			padcat(0, 0, production, ", \"");
			sophia_noun(production, Object->Symbol, indent + 1);
			padcat(0, 0, production, "\")");
		}
	} else if (Object->Reflexive) {
		if (opt_harden) {
			padcat(0, 0, production, "Option.force_msg(");
			uses_option = true;
		}
		sophia_reflexive(production, Object->Reflexive, indent + 1);
		if (opt_harden) {
			padcat(0, 0, production, ", \"reflexive pronoun\")");
			// ◊ put in the actual pronoun sophia_noun(..);
		}
	}
	// else: escrow == do nothing
	return true;
}

bool sophia_reflexive(char **production, Reflexive *Reflexive, int indent) {
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
	sophia_symbol(production, action->Subject->Symbols->Symbol, false,
		      indent + 1);

	return true;
}

bool sophia_predicates(char **production, Predicates *Predicates, int indent) {
	if (!Predicates) return false;
	if (opt_debug) printf("producing Predicates\n");
	sophia_predicates(production, Predicates->Predicates, indent);
	sophia_predicate(production, Predicates->Predicate, indent);
	return true;
}

bool sophia_predicate(char **production, Predicate *Predicate, int indent) {
	if (!Predicate) return false;
	if (opt_debug) printf("producing Predicate\n");

	if (current_function) current_function->changes_state = true;

	sophia_certification(production, Predicate->Certification, indent);
	sophia_declaration(production, Predicate->Declaration, indent);
	sophia_filing(production, Predicate->Filing, indent);
	sophia_registration(production, Predicate->Registration, indent);
	sophia_grantment(production, Predicate->Grantment, indent);
	sophia_appointment(production, Predicate->Appointment, indent);
	sophia_acceptance(production, Predicate->Acceptance, indent);
	sophia_fixture(production, Predicate->Fixture, indent);
	sophia_setting(production, Predicate->Setting, indent);
	sophia_payment(production, Predicate->Payment, indent);
	sophia_sending(production, Predicate->Sending, indent);
	sophia_notification(production, Predicate->Notification, indent);
	sophia_termination(production, Predicate->Termination, indent);

	return true;
}

	/* assign a symbol an expression */
static void assign(char **production, int indent, Symbol *symbol,
		   Expression *expression) {

	padcat(1, indent, production, "");
	padcat(0, 0, production, "put(state{");

	miller = true;
	sophia_symbol(production, symbol, true, indent);	// true --> assign flag
	miller = false;

	padcat(0, 0, production, " = ");

	if (expression)
		sophia_expression(production, expression, indent + 1);
	else
		padcat(0, 0, production, ":§§:true:§:");

	padcat(0, 0, production, "})");
	padcat(0, 0, production, EOL);

	is_stateful = true;
}

	/* Support functions for predicates */
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

bool sophia_certification(char **production, Certification *Certification,
			  int indent) {
	if (!Certification) return false;
	if (opt_debug) printf("producing Certification\n");

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

	return true;
}

bool sophia_declaration(char **production, Declaration *Declaration, int indent) {
	if (!Declaration) return false;
	if (opt_debug) printf("producing Declaration\n");

	assign(production, indent, Declaration->Symbol,
	       Declaration->Expression);

	return true;
}

	/* e.g. The Secured Party may file the Continuation Statement. (only example currently) */
bool sophia_filing(char **production, Filing *Filing, int indent) {
	if (!Filing) return false;
	if (opt_debug) printf("producing Filing\n");

	if (Filing->Expression)
		assign(production, indent, Filing->Symbol, Filing->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Filing->Symbol, false, paratag,
						indent, __LINE__);

	return true;
}

	/* e.g., The Licensee may register a Comment Text. (only example) */
bool sophia_registration(char **production, Registration *Registration,
			 int indent) {
	if (!Registration) return false;
	if (opt_debug) printf("producing registration\n");

	if (Registration->Expression)
		assign(production, indent, Registration->Symbol,
		       Registration->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Registration->Symbol, false,
						paratag, indent, __LINE__);

	return true;
}

bool sophia_grantment(char **production, Grantment *Grantment, int indent) {
	if (!Grantment) return false;
	if (opt_debug) printf("producing Grantment\n");

	assign(production, indent, Grantment->Symbol, null);	// sets true

	return true;
}

bool sophia_appointment(char **production, Appointment *Appointment, int indent) {
	if (!Appointment) return false;
	if (opt_debug) printf("producing Appointment\n");

	insert_parameter_and_set_member(production, &instructions,
					Appointment->Symbol, false, paratag,
					indent, __LINE__);

	return true;
}

bool sophia_acceptance(char **production, Acceptance *Acceptance, int indent) {
	if (!Acceptance) return false;
	if (opt_debug) printf("producing Acceptance\n");

	insert_parameter_and_set_member(production, &instructions,
					Acceptance->Symbol, false, paratag,
					indent, __LINE__);

	return true;
}

	/* The Licensor or the Arbiter may fix the Notice Time as the respective current time.
	 * The Licensor [..] fixes the Description of Goods. */
bool sophia_fixture(char **production, Fixture *Fixture, int indent) {
	if (!Fixture) return false;
	if (opt_debug) printf("producing Fixture\n");

	if (Fixture->Expression)
		assign(production, indent, Fixture->Symbol,
		       Fixture->Expression);
	else
		insert_parameter_and_set_member(production, &instructions,
						Fixture->Symbol, false, paratag,
						indent, __LINE__);

	return true;
}

bool sophia_setting(char **production, Setting *Setting, int indent) {
	if (!Setting) return false;
	if (opt_debug) printf("producing Setting\n");

	assign(production, indent, Setting->Symbol, null);	// null -> set true

	return true;
}

bool sophia_payment(char **production, Payment *Payment, int indent) {
	if (!Payment) return false;
	if (opt_debug) printf("producing Payment\n");

	preassign_mark(production, indent);

	bool explicit_from_escrow = Payment->Escrow || Payment->From_Escrow;
	bool explicit_to_escrow = !Payment->Object->Symbol
		&& !Payment->Object->Reflexive;
	assert(!(explicit_from_escrow && explicit_to_escrow));
	// ◊◊ printf("Flags: %d, %d, %d\n", explicit_from_escrow, explicit_to_escrow, !!Payment->Expression);

	// msg.value is paid in implicitly, no code to produce ..
	if (explicit_to_escrow) {
		// .. but handle the amount variable (declaration)
		// e.g. it must consume the msg_value slot if 'Amount'.
		// This won't hold expressions for payment amounts, so assert
		if (Payment->Expression) {
			assert(Payment->Expression->Combination);
			assert(!Payment->Expression->Combination->Combination);
			assert(Payment->Expression->Combination->Combinor);
			assert(!Payment->Expression->Combination->Combinor->
			       Combinor);
			assert(Payment->Expression->Combination->Combinor->
			       Combinand);
			assert(Payment->Expression->Combination->Combinor->
			       Combinand->Symbol);
			no_literal = true;
			payment_expression = true;
			sophia_expression(production, Payment->Expression, 0);
			payment_expression = false;
			no_literal = false;
		}
		delete_preassign_mark(production);
		return true;
	}

	/* function head */
	sophia_pay(production, Payment->Pay, indent);

	/* sender */

	/* receiver */
	if (!explicit_to_escrow) {
		payment_expression = true;
		sophia_object(production, Payment->Object, 0);
		payment_expression = false;
	} else
		padcat(0, 0, production, "'escrow'");

	padcat(0, 0, production, ", ");

	/* amount */
	if (Payment->Expression) {
		payment_expression = true;
		sophia_expression(production, Payment->Expression, 0);
		payment_expression = false;
	} else {
		padcat(0, 0, production, "Contract.balance");
	}

	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);
	return true;
}

bool sophia_pay(char **production, Pay *Pay, int indent) {
	if (!Pay) return false;
	if (opt_debug) printf("producing Pay\n");
	uses_transfer = true;
	is_stateful = true;
	padcat(1, indent, production, "transfer(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool sophia_escrow(char **production, Escrow *Escrow, int indent) {
	if (!Escrow) return false;
	if (opt_debug) printf("producing Escrow\n");

	padcat(0, 0, production, "address(this)");
	return true;
}

bool sophia_from_escrow(char **production, From_Escrow *From_Escrow, int indent) {
	if (!From_Escrow) return false;
	if (opt_debug) printf("producing From_Escrow\n");

	padcat(0, 0, production, "address(this)");
	return true;
}

bool sophia_sending(char **production, Sending *Sending, int indent) {
	if (!Sending) return false;
	if (opt_debug) printf("producing Sending\n");

	is_stateful = true;

	preassign_mark(production, indent);
	// ◊ change mech to allow for multiple pre-assignments
	// ◊ get out of possible access block for multi-sentence clauses

	sophia_send(production, Sending->Send, indent);

	/* receiver */
	assert(Sending->Object->Symbol || Sending->Object->Reflexive);
	sophia_object(production, Sending->Object, 0);
	padcat(0, 0, production, ", ");

	/* message */
	require_mandat = true;
	sophia_expression(production, Sending->Expression, 0);
	require_mandat = false;
	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);

	return true;
}

bool sophia_send(char **production, Send *Send, int indent) {
	if (!Send) return false;
	if (opt_debug) printf("producing Send\n");

	uses_notification = true;
	is_stateful = true;
	padcat(1, indent, production, "notify(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool sophia_notification(char **production, Notification *Notification, int indent) {	// document it ◊
	if (!Notification) return false;
	if (opt_debug) printf("producing Notification\n");
	beyond_assignment = true;      // ◊ make comprehensive

	preassign_mark(production, indent);

	sophia_notify(production, Notification->Notify, indent);

	// receiver
	assert(Notification->Object->Symbol || Notification->Object->Reflexive);
	sophia_object(production, Notification->Object, 0);
	padcat(0, 0, production, ", ");

	// message
	if (Notification->Expression) {
		require_mandat = true;
		sophia_expression(production, Notification->Expression, 0);
		require_mandat = false;
	} else {
		padcat(0, 0, production, "\"NOTIFICATION\"");
	}
	padcat(0, 0, production, ")", EOL);

	delete_preassign_mark(production);

	return true;
}

bool sophia_notify(char **production, Notify *Notify, int indent) {
	if (!Notify) return false;
	if (opt_debug) printf("producing Notify\n");
	uses_notification = true;
	is_stateful = true;
	padcat(1, indent, production, "notify(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;

	return true;
}

bool sophia_termination(char **production, Termination *Termination, int indent) {
	if (!Termination) return false;
	if (opt_debug) printf("producing Termination\n");
	padcat(1, indent, production, "");
	sophia_this_contract(production, Termination->This_Contract,
			     indent + 1);
	sophia_all_contracts(production, Termination->All_Contracts,
			     indent + 1);
	sophia_terminate(production, Termination->Terminate, indent + 1);
	return true;
}

bool sophia_terminate(char **production, Terminate *Terminate, int indent) {
	if (!Terminate) return false;
	if (opt_debug) printf("producing Terminate\n");

	uses_termination = true;

	padcat(0, 0, production, "termination()", EOL);
	is_stateful = true;
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;

	return true;
}

bool sophia_flagging(char **production, Flagging *Flagging, int indent) {
	if (!Flagging) return false;
	if (opt_debug) printf("producing Flagging\n");

	assign(production, indent, Flagging->Symbol, null);	// null -> set true

	return true;
}

bool sophia_condition(char **production, Condition *Condition, int indent) {
	if (!Condition) return false;
	if (opt_debug) printf("producing Condition\n");

	sophia_if(production, Condition->If, indent);

	conditional_expression = true;
	require_mandat = true;
	sophia_expression(production, Condition->Expression, indent + 1);
	conditional_expression = false;
	require_mandat = false;
	padcat(0, 0, production, ")");

	return true;
}

bool sophia_if(char **production, If *If, int indent) {
	if (!If) return false;
	if (opt_debug) printf("producing If\n");
	padcat(1, indent, production, "if(");
	return true;
}

bool sophia_expression(char **production, Expression *Expression, int indent) {
	if (!Expression) return false;
	if (opt_debug) printf("producing Expression\n");

	if (!no_literal && !require_mandat && !conditional_expression
	    && !payment_expression) padcat(0, 0, production, ":§§:");
	sophia_combination(production, Expression->Combination, indent + 1);
	if (!no_literal && !require_mandat && !conditional_expression
	    && !payment_expression) padcat(0, 0, production, ":§:");

	return true;
}

bool sophia_scalar_comparison(char **production,
			      Scalar_Comparison *Scalar_Comparison,
			      int indent) {
	if (!Scalar_Comparison) return false;
	if (opt_debug) printf("producing Scalar_Comparison\n");

	padcat(0, 0, production, "(");
	require_force = true;
	require_mandat = true;
	sophia_scalar_expression(production,
				 Scalar_Comparison->Scalar_Expression,
				 indent + 1);
	require_force = false;
	require_mandat = false;

	sophia_comparison_operator(production,
				   Scalar_Comparison->Comparison_Operator,
				   indent + 1);

	char *inference_stack = inference;

	require_force = true;
	require_mandat = true;
	sophia_scalar_expression(production,
				 Scalar_Comparison->Scalar_Expression2,
				 indent + 1);
	require_mandat = false;
	require_force = false;
	inference = inference_stack;

	padcat(0, 0, production, ")");

	return true;
}

bool sophia_comparison_operator(char **production,
				Comparison_Operator *Comparison_Operator,
				int indent) {
	if (!Comparison_Operator) return false;
	if (opt_debug) printf("producing Comparison_Operator\n");
	sophia_equal(production, Comparison_Operator->Equal, indent + 1);
	sophia_later(production, Comparison_Operator->Later, indent + 1);
	return true;
}

bool sophia_equal(char **production, Equal *Equal, int indent) {
	if (!Equal) return false;
	padcat(0, 0, production, " == ");
	inference = "bool";
	return true;
}

bool sophia_greater(char **production, Greater *Greater, int indent) {
	if (!Greater) return false;
	if (opt_debug) printf("producing Greater\n");
	padcat(0, 0, production, " > ");
	inference = "bool";
	return true;
}

bool sophia_less(char **production, Less *Less, int indent) {
	if (!Less) return false;
	if (opt_debug) printf("producing Less\n");
	padcat(0, 0, production, " < ");
	inference = "bool";
	return true;
}

bool sophia_later(char **production, Later *Later, int indent) {
	if (!Later) return false;
	if (opt_debug) printf("producing Later\n");

	padcat(0, 0, production, " =< ");
	inference = "bool";
	return true;
}

bool sophia_scalar_expression(char **production,
			      Scalar_Expression *Scalar_Expression,
			      int indent) {
	if (!Scalar_Expression) return false;
	if (opt_debug) printf("producing Scalar_Expression %s\n",
			      Scalar_Expression->Scalar);
	sophia_symbol(production, Scalar_Expression->Symbol, false, indent + 1);
	sophia_scalar(production, Scalar_Expression->Scalar, indent + 1);
	sophia_point_in_time(production, Scalar_Expression->Point_In_Time,
			     indent + 1);
	bool is_escrow_literal = !Scalar_Expression->Symbol
		&& !Scalar_Expression->Scalar
		&& !Scalar_Expression->Point_In_Time;
	if (is_escrow_literal) {
		padcat(0, 0, production, "Contract.balance");
	}

	inference = "uint";
	return true;
}

bool sophia_hex_expression(char **production, Hex_Expression *Hex_Expression,
			   int indent) {
	if (!Hex_Expression) return false;
	if (opt_debug) printf("producing Hex_Expression %s\n",
			      Hex_Expression->Hex);
	sophia_symbol(production, Hex_Expression->Symbol, false, indent + 1);
	sophia_hex(production, Hex_Expression->Hex, indent + 1);
	// sophia_point_in_time(production, Hex_Expression->Point_In_Time, indent+1);
	inference = "uint";
	return true;
}

bool sophia_combination(char **production, Combination *Combination, int indent) {
	if (!Combination) return false;
	if (opt_debug) printf("producing Combination\n");
	if (Combination->Combinator) padcat(0, 0, production, "(");
	sophia_combinor(production, Combination->Combinor, 0);
	sophia_combinator(production, Combination->Combinator, indent);
	sophia_combination(production, Combination->Combination, 0);
	char *inference_stack = inference;

	if (Combination->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;
	return true;
}

bool sophia_combinor(char **production, Combinor *Combinor, int indent) {
	if (!Combinor) return false;
	if (opt_debug) printf("producing Combinor\n");
	if (Combinor->Combinator) padcat(0, 0, production, "(");

	sophia_combinand(production, Combinor->Combinand, 0);
	sophia_combinator(production, Combinor->Combinator, 0);
	sophia_combinor(production, Combinor->Combinor, 0);

	char *inference_stack = inference;

	if (Combinor->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;

	return true;
}

bool sophia_combinand(char **production, Combinand *Combinand, int indent) {
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
			if (opt_harden) {
				padcat(0, 0, production, "Option.force_msg(");
				uses_option = true;
			}
			sophia_symbol(production, Combinand->Symbol, false,
				      indent + 1);
			if (opt_harden) padcat(0, 0, production, ", \"");
			if (opt_harden) sophia_noun(production,
						    Combinand->Symbol,
						    indent + 1);
			if (opt_harden) padcat(0, 0, production, "\")", EOL);
		}
		mtrac_free(varname);
	}
	sophia_expiration(production, Combinand->Expiration, indent + 1);
	sophia_timeliness(production, Combinand->Timeliness, indent + 1);
	sophia_description(production, Combinand->Description, indent + 1);
	sophia_scalar_comparison(production, Combinand->Scalar_Comparison,
				 indent + 1);
	sophia_negation(production, Combinand->Negation, indent + 1);
	sophia_existence(production, Combinand->Existence, indent + 1);
	sophia_point_in_time(production, Combinand->Point_In_Time, indent + 1);

	return true;
}

bool sophia_combinator(char **production, Combinator *Combinator, int indent) {
	if (!Combinator) return false;
	if (opt_debug) printf("producing Combinator\n");
	sophia_or_(production, Combinator->Or_, indent);
	sophia_and(production, Combinator->And, indent);
	sophia_neither(production, Combinator->Neither, indent);
	sophia_nor(production, Combinator->Nor, indent);

	return true;
}

bool sophia_or_(char **production, Or_ *Or_, int indent) {
	if (!Or_) return false;
	if (opt_debug) printf("producing Or_\n");
	padcat(indent ? 1 : 0, indent, production, " || ");
	inference = "bool";
	return true;
}

bool sophia_and(char **production, And *And, int indent) {
	if (!And) return false;
	if (opt_debug) printf("producing And\n");
	padcat(indent ? 1 : 0, indent, production, " && ");
	inference = "bool";
	return true;
}

bool sophia_neither(char **production, Neither *Neither, int indent) {
	if (!Neither) return false;
	if (opt_debug) printf("producing Neither\n");
	padcat(1, indent, production, "( neither ");
	padcat(0, 0, production, ") ");
	inference = "bool";
	return true;
}

bool sophia_nor(char **production, Nor *Nor, int indent) {
	if (!Nor) return false;
	if (opt_debug) printf("producing Nor\n");
	padcat(1, indent, production, "( nor ");
	inference = "bool";
	return true;
}

bool sophia_existence(char **production, Existence *Existence, int indent) {
	////// check and test for rule 'symbol be fixed'
	if (!Existence) return false;
	if (opt_debug) printf("producing Existence\n");
	padcat(0, 0, production, "");
	assert(Existence->Symbol->Name);	// should never need Existance->Symbol->Type->Literal
	sophia_symbol(production, Existence->Symbol, false, indent + 1);
	const char *lst = lexsymtype(Existence->Symbol);

	if (!lst || !strcmp(lst, "binary")) {
		if (opt_harden)
			padcat(0, 0, production, " == :§§:true:§:");
		// else: nothing instead of " == true" and that both for !opt_harden and the outer if also for Sol
	} else {
		padcat(0, 0, production, " != ",
		       nullvalue(Existence->Symbol->Name, !opt_harden));
	}
	inference = "bool";
	return true;
}

bool sophia_negation(char **production, Negation *Negation, int indent) {
	if (!Negation) return false;
	if (opt_debug) printf("producing Negation\n");
	assert(Negation->Symbol->Name);	// should never need Negation->Symbol->Type->Literal (?)
	padcat(0, 0, production, "");
	const char *lst = lexsymtype(Negation->Symbol);

	if (!lst || !strcmp(lst, "binary")) {
		if (!opt_harden) {
			padcat(0, 0, production, "!");
			sophia_symbol(production, Negation->Symbol, false,
				      indent + 1);
		} else {
			sophia_symbol(production, Negation->Symbol, false,
				      indent + 1);
			padcat(0, 0, production, " == :§§:false:§:");
		}
	} else {
		sophia_symbol(production, Negation->Symbol, false, indent + 1);
		padcat(0, 0, production, " == ",
		       nullvalue(Negation->Symbol->Name, !opt_harden));
	}
	inference = "bool";
	return true;
}

bool sophia_negator(char **production, Negator *Negator, int indent) {
	if (!Negator) return false;
	if (opt_debug) printf("producing Negator\n");
	padcat(0, 0, production, "!");
	inference = "bool";
	return true;
}

bool sophia_being(char **production, Being *Being, int indent) {
	if (!Being) return false;
	if (opt_debug) printf("producing Being\n");
	inference = "bool";
	return true;
}

bool sophia_true(char **production, True *True, int indent) {
	if (!True) return false;
	if (opt_debug) printf("producing True\n");
	return true;
}

bool sophia_article(char **production, Article *Article, int indent) {
	if (!Article) return false;
	return true;
}

bool sophia_point_in_time(char **production, Point_In_Time *Point_In_Time,
			  int indent) {
	if (!Point_In_Time) return false;
	if (opt_debug) printf("producing Point In Time\n");
	bool wrap = false;

	if (require_option) {
		concat(production, ":§§:");
		wrap = true;
		require_option = false;
	}
	sophia_current_time(production, Point_In_Time->Current_Time,
			    indent + 1);
	sophia_relative_time(production, Point_In_Time->Relative_Time,
			     indent + 1);
	if (wrap) concat(production, ":§:");
	inference = "uint";
	return true;
}

bool sophia_current_time(char **production, Current_Time *Current_Time,
			 int indent) {
	if (!Current_Time) return false;
	if (opt_debug) printf("producing Current_Time\n");
	padcat(0, 0, production, "Chain.timestamp");
	inference = "uint";
	return true;
}

bool sophia_relative_time(char **production, Relative_Time *Relative_Time,
			  int indent) {
	if (!Relative_Time) return false;
	if (opt_debug) printf("producing Relative_Time\n");
	if (Relative_Time->Symbol) {
		padcat(0, 0, production, "(");
		if (opt_harden) {
			padcat(0, 0, production, "Option.force_msg(");
			uses_option = true;
		}
		sophia_symbol(production, Relative_Time->Symbol, false,
			      indent + 1);
		if (opt_harden) padcat(0, 0, production, ", \"",
				       Relative_Time->Symbol->Name,
				       " not set\")");
		padcat(0, 0, production, " + ");
	} else {
		padcat(0, 0, production, "(Chain.timestamp - ");
	}
	sophia_duration(production, Relative_Time->Duration, indent + 1);
	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool sophia_duration(char **production, Duration *Duration, int indent) {
	if (!Duration) return false;
	if (opt_debug) printf("producing Duration\n");
	padcat(0, 0, production, "(");

	sophia_scalar_expression(production, Duration->Scalar_Expression,
				 indent + 1);
	padcat(0, 0, production, " * ");
	sophia_time_unit(production, Duration->Time_Unit, indent + 1);

	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool sophia_time_unit(char **production, Time_Unit *Time_Unit, int indent) {
	if (!Time_Unit) return false;
	if (opt_debug) printf("producing Time_Unit\n");
	sophia_years(production, Time_Unit->Years, indent + 1);
	sophia_months(production, Time_Unit->Months, indent + 1);
	sophia_weeks(production, Time_Unit->Weeks, indent + 1);
	sophia_days(production, Time_Unit->Days, indent + 1);
	sophia_hours(production, Time_Unit->Hours, indent + 1);
	sophia_minutes(production, Time_Unit->Minutes, indent + 1);
	sophia_seconds(production, Time_Unit->Seconds, indent + 1);
	sophia_milliseconds(production, Time_Unit->Milliseconds, indent + 1);
	inference = "uint";
	return true;
}

bool sophia_years(char **production, Years *Years, int indent) {
	if (!Years) return false;
	if (opt_debug) printf("producing Years\n");
	padcat(0, 0, production, "31536000000");
	inference = "uint";
	return true;
}

bool sophia_months(char **production, Months *Months, int indent) {
	if (!Months) return false;
	if (opt_debug) printf("producing Months\n");
	padcat(0, 0, production, "2592000000");
	inference = "uint";
	return true;
}

bool sophia_weeks(char **production, Weeks *Weeks, int indent) {
	if (!Weeks) return false;
	if (opt_debug) printf("producing Weeks\n");
	padcat(0, 0, production, "604800000");
	inference = "uint";
	return true;
}

bool sophia_days(char **production, Days *Days, int indent) {
	if (!Days) return false;
	if (opt_debug) printf("producing Days\n");
	padcat(0, 0, production, "86400000");
	inference = "uint";
	return true;
}

bool sophia_hours(char **production, Hours *Hours, int indent) {
	if (!Hours) return false;
	if (opt_debug) printf("producing Hours\n");
	padcat(0, 0, production, "3600000");
	inference = "uint";
	return true;
}

bool sophia_minutes(char **production, Minutes *Minutes, int indent) {
	if (!Minutes) return false;
	if (opt_debug) printf("producing Minutes\n");
	padcat(0, 0, production, "60000");
	inference = "uint";
	return true;
}

bool sophia_seconds(char **production, Seconds *Seconds, int indent) {
	if (!Seconds) return false;
	if (opt_debug) printf("producing Seconds\n");
	padcat(0, 0, production, "1000");
	inference = "uint";
	return true;
}

bool sophia_milliseconds(char **production, Milliseconds *Milliseconds,
			 int indent) {
	if (!Milliseconds) return false;
	if (opt_debug) printf("producing Milliseconds\n");
	padcat(0, 0, production, "1");
	inference = "uint";
	return true;
}

bool sophia_expiration(char **production, Expiration *Expiration, int indent) {
	if (!Expiration) return false;
	if (opt_debug) printf("producing Expiration\n");

	/* 'has passed' means that the moment has happened that the millisecond was counted as passed -> <= */
	padcat(0, 0, production, " =< Chain.timestamp");
	inference = "bool";
	return true;
}

bool sophia_timeliness(char **production, Timeliness *Timeliness, int indent) {
	if (!Timeliness) return false;
	if (opt_debug) printf("producing Timeliness\n");

	/* 'has not passed' means that the moment has not happened that the millisecond was counted as passed -> > */
	padcat(0, 0, production, " > Chain.timestamp");
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

	concat(&parameter_varname, pretty_varname);	// same because member gets 'state.' prefixed

	// prepend type (sol, sop)
	char *typed_varname = mtrac_strdup("");

	concat(&typed_varname,
	       type(pretty_varname, opt_harden, false, __LINE__), " ", varname);

	char *pretty_typed_varname = mtrac_strdup("");

	concat(&pretty_typed_varname, pretty_varname, " : ",
	       type(pretty_varname, opt_harden, false, __LINE__));

	char *typed_parameter_varname = mtrac_strdup("");

	concat(&typed_parameter_varname, parameter_varname, " : ",
	       type(pretty_varname, false, true, __LINE__));

	/* binding to msg.sender and msg.value */
	bool use_sender = !active_subjects && !msg_sender
		&& !strcmp("person", lextype(pretty_varname));
	if (use_sender) msg_sender = mtrac_strdup(pretty_varname);
	bool use_value = payment && !msg_value
		&& !strcmp("amount", lextype(pretty_varname));
	// printf("payment %d -- msg_value %s -- pretty varname %s -- lextype %s\n", payment, msg_value, pretty_varname, lextype(pretty_varname)); ◊ make option
	if (use_value) msg_value = mtrac_strdup(pretty_varname);
	is_payable |= !!use_value;
	is_stateful = true;

	/* 1: Add to the parameters and arguments list. In the produced code as well as (parameta) the instructions */
	if (!use_sender && !use_value) {
		char *search = mtrac_strdup("");

		concat(&search, ":", parameter_varname, ":");
		if (!strstr(args, search)) {
			concat(&args, search);
			if (!current_function) {
				/* outside a function (recital/constructor) */
				padcat(0, 0, &parameters,
				       *parameters ? ", " : "",
				       typed_parameter_varname);
				padcat(0, 0, &arguments, *arguments ? ", " : "",
				       parameter_varname);
				if (instructions) padcat(0, 0, &parameta,
							 *parameta ? ", " : "",
							 "<",
							 pretty_typed_varname,
							 ">");
			} else {
				/* inside a function (clause) */
				padcat(0, 0, &current_function->parameters,
				       *current_function->
				       parameters ? ", " : "",
				       typed_parameter_varname);
				// arguments don't happen in this case
				if (instructions)
					padcat(0, 0,
					       &current_function->parameta,
					       *current_function->
					       parameta ? ", " : "", "<",
					       pretty_typed_varname, ">");
			}
		}
		mtrac_free(search);
	}

	/* 2: Set the member to the parameter.  It's a member only if it's not a variable named for a type
	 * (then found at Symbol->Type->Literal) */
	if (symbol->Name) {
		// ◊ into symbol coming in here
		/* js: prep: we will (at [1]) look for, eg 'x = null;' in the previously produced */
		char *nulling = mtrac_strdup("");

		mtrac_concat(&nulling, varname, " = ",
			     nullmap(lextype(pretty_varname), !opt_harden));

		/* js: prep: .. to replace it (at [1]) with 'x = xpara;' */
		char *setting = mtrac_strdup("");
		char *initializing = mtrac_strdup("");

		bool preassign = !!strstr(*production, "%preassign%");
		int linebreak = preassign ? 1 : 0;

		int setting_indent = preassign ? preass_indent : indent + 1;

		if (use_sender) {

			padcat(linebreak, setting_indent, &setting,
			       "put(state{", varname,
			       " = :§§:Call.caller:§:})");
			padcat(linebreak, setting_indent, &initializing,
			       varname, " = :§§:Call.caller:§:");
		} else if (use_value) {

			if (!main_constructor_body
			    && !covenant_constructor_body) {
				if (opt_harden) {
					padcat(1, setting_indent, &setting,
					       "put(state{", varname,
					       " = Some(Option.default(0, state.",
					       varname, ") + Call.value)})");
					uses_option = true;
				} else {
					padcat(1, setting_indent, &setting,
					       "put(state{", varname,
					       " = state.", varname,
					       " + Call.value})");
				}
				padcat(1, setting_indent + 1, &initializing,
				       varname, " = :§§:Call.value:§:,");
			} else {
				padcat(0, 0, &initializing, varname,
				       " = :§§:Call.value:§:");
			}
		} else {

			padcat(linebreak, setting_indent, &setting,
			       "put(state{", varname, " = :§§:",
			       parameter_varname, ":§:})", EOL);
			padcat(linebreak, setting_indent, &initializing,
			       varname, " = :§§:", parameter_varname, ":§:",
			       EOL);
		}

		/* 2a: optimized setting right in the declaration list (replacing '= null') */
		// printf("\n\nOPT\n\n%d: %s\n\n%s\n\n", paratag, nulling, paratag>=0?*production+paratag:""); ◊ make option
		if ((main_constructor_body || covenant_constructor_body) && strstr(initializations, nulling)) {	// ◊ test for (conflicting) covenant symbols
			replace_first_from(&initializations, nulling, initializing, initializations);	// [1]

			/* 2b: set member immediately before the use of the value:
			 * within functions (instead within the constructor) when a parameter's value is to be used,
			 * and a member set to this value on the fly. The setting is inserted before the start of the
			 * statement that the expression is nested in that uses the symbol in question. */
		} else if (strstr(*production, "%preassign%")) {
			replace(production, "%preassign%", setting);	// insert before current statement
		}

		/* 2c: but if we could not find either, just create a member and assign the given parameter,
		 * js: production will currently be at declaration height, so we effectively append to the member declaration list */
		else {
			padcat(1, indent, production, setting);
		}
		mtrac_free(nulling);
		mtrac_free(setting);
		mtrac_free(initializing);
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
}

void error(char *msg, char *cargo) {
	printf("Lexon semantic error: %s %s%s%s.\n", msg, cargo ? "(" : "",
	       cargo ? cargo : "", cargo ? ")" : "");
	if (current_function) printf("In clause %s.\n", current_function->lexname);	// ◊ add file and line
	exit(1);
}

/* end of file */
