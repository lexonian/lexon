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
  /*    solidity.c - Solidity backend   */

#define backend_version "solidity 0.3.97a U"
#define target_version "solidity 0.8+"
#define CYCLE_2 true

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define EOL ";"
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

bool sol_document(char **production, struct Document *root, int indent);

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
static char *globals = null;
static char *declarations = null;
static char *initializations = null;
static char *fixed = null;	       // list of variables that have been set
static char *declared = null;	       // list of variables that come in as paremeters
static char *functions = null;
static bool miller = false;

static char *safedup(const char *name) {
	assert(name);
	char *_safe = mtrac_malloc(strlen(name) + 3);

	strcpy(_safe, " ");
	strcat(_safe, name);
	strcat(_safe, " ");

	if (!strstr(" Message permit send terminate terminated transfer call check_termination "	// Lexon ◊
		    " after alias apply auto byte case copyof default define final"
		    " implements in inline let macro match mutable null of partial"
		    " promise reference relocatable sealed sizeof static supports switch typedef typeof"
		    " var abstract address anonymous as assembly bool break bytes calldata"
		    " catch constant constructor continue contract delete do else emit enum"
		    " error event external fallback false fixed fixed x bytes1 bytes2"
		    " bytes3 bytes4 bytes5 bytes6 bytes7 bytes8 bytes9 bytes10 bytes11 bytes12"
		    " bytes13 bytes14 bytes15 bytes16 bytes17 bytes18 bytes19 bytes20 bytes21 bytes22"
		    " bytes23 bytes24 bytes25 bytes26 bytes27 bytes28 bytes29 bytes30 bytes31 bytes32"
		    " for from function global hex if immutable import indexed interface"
		    " internal is library mapping memory modifier new wei gwei ether"
		    " seconds minutes hours days weeks years override payable pragma private"
		    " public pure receive return returns revert int int8 int16 int24"
		    " int32 int40 int48 int56 int64 int72 int80 int88 int96 int104"
		    " int112 int120 int128 int136 int144 int152 int160 int168 int176 int184"
		    " int192 int200 int208 int216 int224 int232 int240 int248 int256 storage"
		    " string struct transient true try type ufixed ufixed x unchecked"
		    " unicode uint uint8 uint16 uint24 uint32 uint40 uint48 uint56 uint64"
		    " uint72 uint80 uint88 uint96 uint104 uint112 uint120 uint128 uint136 uint144"
		    " uint152 uint160 uint168 uint176 uint184 uint192 uint200 uint208 uint216 uint224"
		    " uint232 uint240 uint248 uint256 using view virtual while ",
		    _safe)) {
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

/* create or find a binding for a function name */
static bind *register_bind(char *name) {

	assert(name && strlen(name));
	bind *bind = binds;

	while (bind && strcmp(name, bind->name)) bind = bind->next;
	if (!bind) {
		bind = mtrac_malloc(sizeof (struct bind));	// sic
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
		if (!binds) binds = bind;
		if (last_bind) last_bind->next = bind;
		last_bind = bind;
	}
	return bind;
}

/* register a call and receive the point to be set to the coming next one */
static call **register_call(call **prevnext, char *to) {
	call *call = mtrac_malloc(sizeof (call));

	call->bind = register_bind(to);
	call->next = null;
	*prevnext = call;
	return &call->next;
}

static void replace_bind_tags(char **production, char **instructions, bind *b) {

	while (b) {
		char *head = mtrac_strdup("");
		char *ihead = mtrac_strdup("");

//              if(!b->uses_permission && b->changes_state) ///// replace by logic 'has subject'
//                      mtrac_concat(&head, "#");

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
} Payment;

typedef struct Pay {
} Pay;

typedef struct Preposition {
} Preposition;

typedef struct Escrow {
} Escrow;

typedef struct From_Escrow {
} From_Escrow;

typedef struct Sending {
	struct Send *Send;
	struct Expression *Expression;
	struct Preposition *Preposition;
	struct Object *Object;
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
	struct Later *Later;
} Comparison_Operator;

typedef struct Equal {
} Equal;

typedef struct Later {
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
	struct Reflexive *Reflexive;
	Description *Description;
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

static void insert_parameter_and_set_member(char **production,
					    char **instructions,
					    Symbol * symbol, bool payment,
					    size_t paratag, int indent,
					    int line);

bool sol_walk(char **production) {
	if (!root) return false;
	return sol_document(production, root, 0);
}

static Name *class = null;
static bool main_constructor_body = true;
static bool main_contract = true;
static bool covenant_constructor_body = false;
static bool terms_body = true;
static bool recital_of_terms = false;
bool sol_name(char **production, Name *Name, bool assign, int indent) {
	if (!Name) return false;

	/* put '_' to names that are target language keywords */
	char *safe = safedup(SNAKE(Name));

	if (!in(functions, Name)) {

		padcat(0, 0, production, safe);

	} else {
		bind *bind = register_bind(safe);

		padcat(0, 0, production, bind->tag);

	}
	if (assign) padcat(0, 0, &fixed, ":", safe, ":");
	mtrac_free(safe);
	return true;
}

bool sol_description(char **production, Description *Description, int indent) {
	if (!Description) return false;
	padcat(0, 0, production, "\"", Description, "\"");
	return true;
}

bool sol_scalar(char **production, Scalar *Scalar, int indent) {
	if (!Scalar) return false;
	padcat(0, 0, production, Scalar);
	return true;
}

bool sol_hex(char **production, Hex *Hex, int indent) {
	if (!Hex) return false;
	padcat(0, 0, production, Hex);
	return true;
}

static const char *lexsymtype(Symbol * symbol);

/* AST walk (stub) functions */

bool sol_document(char **production, Document * Document, int indent);
bool sol_head(char **production, Head * Head, int indent);
bool sol_lex(char **production, Lex * Lex, int indent);
bool sol_lexon(char **production, Lexon * Lexon, int indent);
bool sol_authors(char **production, Authors * Authors, int indent);
bool sol_comment(char **production, Comment * Comment, int indent);
bool sol_preamble(char **production, Preamble * Preamble, int indent);
bool sol_terms(char **production, Terms * Terms, int indent);
bool sol_covenants(char **production, Covenants * Covenants, int indent);
bool sol_covenant(char **production, Covenant * Covenant, int indent);
bool sol_provisions(char **production, Provisions * Provisions, int indent);
bool sol_definitions(char **production, Definitions * Definitions, int indent);
bool sol_definition(char **production, Definition * Definition, int indent);
bool sol_clauses(char **production, Clauses * Clauses, int indent);
bool sol_clause(char **production, Clause * Clause, int indent);
bool sol_body(char **production, Body * Body, int indent);
bool sol_function(char **production, Function * Function, int indent);
bool sol_statements(char **production, Statements * Statements, int indent);
bool sol_statement(char **production, Statement * Statement, int indent);
bool sol_actions(char **production, Actions * Actions, int indent);
bool sol_action(char **production, Action * Action, int indent);
bool sol_subject(char **production, Subject * Subject, int indent);
bool sol_symbols(char **production, Symbols * Symbols, int indent);
bool sol_symbol(char **production, Symbol * Symbol, bool assign, int indent);
bool sol_noun(char **production, Symbol * Symbol, int indent);
bool sol_catena(char **production, Catena * Catena, int indent);
bool sol_object(char **production, Object * Object, int indent);
bool sol_reflexive(char **production, Reflexive * Reflexive, int indent);
bool sol_predicates(char **production, Predicates * Predicates, int indent);
bool sol_predicate(char **production, Predicate * Predicate, int indent);
bool sol_permission(char **production, Permission * Permission, int indent);
bool sol_certification(char **production, Certification * Certification,
		       int indent);
bool sol_certify(char **production, Certify * Certify, int indent);
bool sol_declaration(char **production, Declaration * Declaration, int indent);
bool sol_declare(char **production, Declare * Declare, int indent);
bool sol_filing(char **production, Filing * Filing, int indent);
bool sol_file(char **production, File * File, int indent);
bool sol_registration(char **production, Registration * Registration,
		      int indent);
bool sol_register(char **production, Register * Register, int indent);
bool sol_grantment(char **production, Grantment * Grantment, int indent);
bool sol_grant(char **production, Grant * Grant, int indent);
bool sol_appointment(char **production, Appointment * Appointment, int indent);
bool sol_appoint(char **production, Appoint * Appoint, int indent);
bool sol_fixture(char **production, Fixture * Fixture, int indent);
bool sol_fix(char **production, Fix * Fix, int indent);
bool sol_setting(char **production, Setting * Setting, int indent);
bool sol_illocutor(char **production, Illocutor * Illocutor, int indent);
bool sol_payment(char **production, Payment * Payment, int indent);
bool sol_pay(char **production, Pay * Pay, int indent);
bool sol_preposition(char **production, Preposition * Preposition, int indent);
bool sol_escrow(char **production, Escrow * Escrow, int indent);
bool sol_from_escrow(char **production, From_Escrow * From_Escrow, int indent);
bool sol_sending(char **production, Sending * Sending, int indent);
bool sol_send(char **production, Send * Send, int indent);
bool sol_notification(char **production, Notification * Notification,
		      int indent);
bool sol_notify(char **production, Notify * Notify, int indent);
bool sol_termination(char **production, Termination * Termination, int indent);
bool sol_terminate(char **production, Terminate * Terminate, int indent);
bool sol_flagging(char **production, Flagging * Flagging, int indent);
bool sol_condition(char **production, Condition * Condition, int indent);
bool sol_if(char **production, If * If, int indent);
bool sol_expression(char **production, Expression * Expression, int indent);
bool sol_scalar_comparison(char **production,
			   Scalar_Comparison * Scalar_Comparison, int indent);
bool sol_comparison_operator(char **production,
			     Comparison_Operator * Comparison_Operator,
			     int indent);
bool sol_equal(char **production, Equal * Equal, int indent);
bool sol_later(char **production, Later * Later, int indent);
bool sol_scalar_expression(char **production,
			   Scalar_Expression * Scalar_Expression, int indent);
bool sol_combination(char **production, Combination * Combination, int indent);
bool sol_combinor(char **production, Combinor * Combinor, int indent);
bool sol_combinand(char **production, Combinand * Combinand, int indent);
bool sol_combinator(char **production, Combinator * Combinator, int indent);
bool sol_or_(char **production, Or_ * Or_, int indent);
bool sol_and(char **production, And * And, int indent);
bool sol_neither(char **production, Neither * Neither, int indent);
bool sol_nor(char **production, Nor * Nor, int indent);
bool sol_existence(char **production, Existence * Existence, int indent);
bool sol_negation(char **production, Negation * Negation, int indent);
bool sol_negator(char **production, Negator * Negator, int indent);
bool sol_being(char **production, Being * Being, int indent);
bool sol_true(char **production, True * True, int indent);
bool sol_article(char **production, Article * Article, int indent);
bool sol_point_in_time(char **production, Point_In_Time * Point_In_Time,
		       int indent);
bool sol_current_time(char **production, Current_Time * Current_Time,
		      int indent);
bool sol_relative_time(char **production, Relative_Time * Relative_Time,
		       int indent);
bool sol_duration(char **production, Duration * Duration, int indent);
bool sol_time_unit(char **production, Time_Unit * Time_Unit, int indent);
bool sol_years(char **production, Years * Years, int indent);
bool sol_months(char **production, Months * Months, int indent);
bool sol_weeks(char **production, Weeks * Weeks, int indent);
bool sol_days(char **production, Days * Days, int indent);
bool sol_hours(char **production, Hours * Hours, int indent);
bool sol_minutes(char **production, Minutes * Minutes, int indent);
bool sol_seconds(char **production, Seconds * Seconds, int indent);
bool sol_milliseconds(char **production, Milliseconds * Milliseconds,
		      int indent);
bool sol_expiration(char **production, Expiration * Expiration, int indent);

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
	"   Deploy this smart contract to the Ethereum blockchain or Goerli testchain.  Replace\n"
	"   the <parameters> with literal values to interact with the contract via terminal.\n\n"
	"   Note that the instructions below reflect your lexon code, as well as the parameters\n"
	"   used during compilation of the code: different functions and parameters will result\n"
	"   from different input.  Some functions are 'built-in' but only appear when needed as\n"
	"   per compiler options used during compilation  –  a list of which, is available with\n"
	"   lexon -h.  The functions are given in the order of appearance, in the lexon source.\n\n"
	"   The required caller is noted in double angle brackets << >>.  Some functions can be\n"
	"   called by anyone.  Note that roles are being defined by using an address for it for\n"
	"   the first time. This will require for the same address to be used for the same role\n"
	"   after this point. Else, the call will revert.\n\n"
	"   Some clauses of the original lexon source text do not appear in the comments below.\n"
	"   Namely, those without permission phrase, wherefore they are regarded as internal.\n\n"
	"   These are the constructor parameters for deployment:\n\n"
	"   %6%\n\n"
	"   These are the state progress functions that allow to interact with the contract:\n";
static bool enforce_same_subject = false;
static list *active_subjects = null;
static list *covenant_subjects = null;
static bool no_action_in_group_yet = true;
static bool uses_termination = false;
static bool uses_pay = false;
static bool uses_send = false;
static bool uses_permit = false;
static bool has_subclasses = false;

bool sol_document(char **production, Document *Document, int indent) {
	if (!Document) return false;
	if (opt_debug) printf("producing Document\n");

	/* switch line# trace of every concat to code output buffer */
	_concat_trace = opt_debug_production;

	/* source code head */

	padcat(0, indent, production,
	       "// SPDX-License-Identifier: UNLICENSED\n");
	padcat(0, indent, production, "pragma solidity ^0.8.17;\n\n");
	if (!opt_bare) padcat(0, indent, production,
			      "/* Lexon-generated Solidity code\n");
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
	requires = mtrac_strdup(requires);

	/* instructions are being built up in parallel, eventually prepent.
	 * They will be built up for naught and discarded if opt_instructions is not set. */
	instructions = mtrac_strdup(instructions);

	char *file = mtrac_strdup(opt_source ? opt_source : "contract");

	replace(&file, ".lex", "");

	concat(&file, ".solx");

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

	sol_head(production, Document->Head, indent);

	/* comments */
	if (opt_comment) {
		padcat(2, indent, production, "/**");
		padcat(1, indent, production, " **");
		padcat(1, indent, production, " ** Main ", module,
		       " contract system");
		padcat(1, indent, production, " **");
		padcat(1, indent, production, " **/");
	}

	if (opt_comment || opt_lexon_comments) {
		padcat(1, 0, production, "");
	}

	if (opt_lexon_comments) {
		char *c = mtrac_strdup(get_lexcom("start"));

		replace(&c, "\n", "\n *\t");
		replace(&c, "\n *\t\n", "\n *\n");
		padcat(1, 0, production, "/** ", c, "\n**/");
		mtrac_free(c);
	}

	paratag = strlen(*production);
	if (!opt_bare) padcat(2, indent, production, "");

	padcat(0, indent, production, "contract ", camel_spaced(module), " {\n%27%\n");	// %27%: member declaration
	padcat(1, indent + 1, production, "%29%constructor(%1%) %28%{");	// %29%: emits, %1%: constructor parameters, sol %28%: payable

	main_constructor_body = true;
	main_contract = true;
	assert(active_subjects == null);
	sol_terms(production, Document->Terms, indent + 2);	// sets caller, uses methods variable for production string
	main_constructor_body = false; // off for non-JS? ◊ //////
	main_contract = false;
	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = null;

	/* sol, sop: end of main constructor */
	padcat(1, indent + 1, production, "}%34%");	// %34% adders
	replace(production, "%1%", parameters);

	padcat(0, 0, production, "%31%");	// %31%: auxiliary functions

	/* sol,sop: add the general terms methods beneath the constructor */
	padcat(0, 0, production, methods);

	/* sol, sop: end of main class (sop: by indent) */
	padcat(1, indent, production, "}");

	sol_covenants(production, Document->Covenants, indent);
	/* aux functions to add a new sub object instance (covenants) */

	replace(production, "%34%", adders);
	/* AUXILIARY FUNCTIONS */
	char *auxfuncs = mtrac_strdup("");

	/* #terminate() - contract termination */
	if (uses_termination) {
		if (opt_comment) padcat(3, indent + 1, &auxfuncs,
					"/* built-in termination of the entire contract system */");
		padcat(C, indent + 1, &auxfuncs,
		       "function termination() internal {");
		padcat(1, indent + 2, &auxfuncs, "terminated = true;");
		padcat(1, indent + 1, &auxfuncs, "}");
		padcat(2, indent + 1, &auxfuncs,
		       "function check_termination() internal view {");
		padcat(1, indent + 2, &auxfuncs,
		       "require(!terminated, \"contract system terminated before\");");
		padcat(1, indent + 1, &auxfuncs, "}");
	}
	/* pay() */
	if (uses_pay) {

		// ◊◊◊ if(opt_comment) padcat(2, indent+1, &auxfuncs, "/* built-in safe transfer */");
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* safe transfer */");

		padcat(C, indent + 1, &auxfuncs,
		       "function transfer(address _to, uint _amount) internal {");

		padcat(1, indent + 2, &auxfuncs,
		       "(bool _success, ) = _to.call{value:_amount}(\"\");");
		padcat(1, indent + 2, &auxfuncs,
		       "require(_success, \"transfer failed on receiver side\");");

		padcat(1, indent + 1, &auxfuncs, "}");
	}

	/* send() - sending / emitting of a message */
	if (uses_send) {
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in send message */");

		padcat(C, indent + 1, &auxfuncs,
		       "function send(address _to, string storage _message) internal {");
		padcat(1, indent + 2, &auxfuncs,
		       "emit Message(msg.sender, _to, _message);");
		padcat(1, indent + 1, &auxfuncs, "}");
		padcat(0, indent + 1, &emits, "event Message(");
		padcat(1, indent + 2, &emits, "address indexed _from,");
		padcat(1, indent + 2, &emits, "address indexed _to,");
		padcat(1, indent + 2, &emits, "string _message);");
		padcat(2, indent + 1, &emits, "");
	}

	/* place message structure definitions (emits) */
	replace(production, "%29%", emits);	///// correct for S+S?

	/* sol+sop: permit - optimized require() */
	if (uses_permit) {
		if (opt_comment) padcat(2, indent + 1, &auxfuncs,
					"/* built-in caller assertion */");
		padcat(C, indent + 1, &auxfuncs,
		       "function permit(address _authorized) internal view {");
		padcat(1, indent + 2, &auxfuncs,
		       "require(msg.sender == _authorized, \"not permitted\");");
		padcat(1, indent + 1, &auxfuncs, "}");

	}

	/* aux functions insert - js: in place. soli+sop: higher up. */

	replace(production, "%31%", auxfuncs);
	mtrac_free(auxfuncs);
	/* end of file */
	if (!opt_bare) padcat(2, indent, production, "/* end */\n");

	_concat_trace = false;

	/* sort out names, privacy mark (javascript: '#') and parameters */
	replace_bind_tags(production, &instructions, binds);

	/* take care of termination flag (js @ [3]) */
	if (uses_termination) {
		padcat(1, 1, &declarations, "bool terminated = false;");
	}

	/* sol+sop: insert declaration of member variables into constructor (sol)/contract (sop) head */
	replace(production, "%27%", declarations);
	/* prepend instructions to the top - or just discard if not switched on */
	replace(&instructions, "%6%", parameta);
	replace(&instructions, "%contract%", instance_var_name);
	replace(production, "%0%", opt_instructions ? instructions : "");
	/* memory clean up */
	delete_bind_tree(binds);
	mtrac_free(parameters), parameters = null;
	mtrac_free(arguments), arguments = null;
	mtrac_free(parameta), parameta = null;
	mtrac_free(emits), emits = null;
	if (caller) mtrac_free(caller), caller = null;
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
	mtrac_free(requires);
	mtrac_free(file);
	mtrac_free(instance_var_name);

	return true;
}

bool sol_head(char **production, Head *Head, int indent) {
	if (!Head) return false;
	if (opt_debug) printf("producing Head\n");
	// padcat(2, indent, production, "/*");

	sol_lex(production, Head->Lex, indent);
	sol_preamble(production, Head->Preamble, indent);
	sol_comment(production, Head->Comment, indent);
	sol_authors(production, Head->Authors, indent);
	if (!opt_bare) {
		padcat(2, indent, production, "   file:        ", opt_source);
		sol_lexon(production, Head->Lexon, indent);
		padcat(2, indent, production, "   compiler:    lexon ",
		       program_version);
		padcat(2, indent, production, "   grammar:     ",
		       grammar_version);
		padcat(2, indent, production, "   backend:     ",
		       backend_version);
		padcat(2, indent, production, "   target:      ",
		       target_version);

		padcat(2, indent, production, "   parameters:  ", opt_summarized);	/////// unify
		padcat(1, indent, production, "%0%\n*/");
	}

	return true;
}

bool sol_lex(char **production, Lex *Lex, int indent) {
	if (!Lex) return false;
	if (opt_debug) printf("producing Lex %s\n", Lex->Name);
	if (!opt_bare) padcat(2, indent, production, "   code:        ",
			      Lex->Name);
	module = Lex->Name;
	return true;
}

bool sol_lexon(char **production, Lexon *Lexon, int indent) {
	if (!Lexon) return false;
	if (opt_debug) printf("producing Lexon %s\n", Lexon->Description);
	if (!opt_bare) {
		padcat(2, indent, production, "   code tagged: ",
		       Lexon->Description);
	}
	return true;
}

bool sol_authors(char **production, Authors *Authors, int indent) {
	if (!Authors) return false;
	if (opt_debug) printf("producing Authors %s\n", Authors->Description);
	if (!opt_bare) {
		padcat(2, indent, production, "   authors:     ",
		       Authors->Description);
		padcat(0, 0, production, "");
	}
	return true;
}

bool sol_comment(char **production, Comment *Comment, int indent) {
	if (!Comment) return false;
	if (opt_debug) printf("producing comment %s\n", Comment->Description);
	if (!opt_bare) {
		padcat(2, indent, production, "   comment:     ");
		sol_description(production, Comment->Description, indent + 1);
		padcat(0, 0, production, "");
	}
	return true;
}

bool sol_preamble(char **production, Preamble *Preamble, int indent) {
	if (!Preamble) return false;
	if (opt_debug) printf("producing Preamble %s\n", Preamble->Description);
	if (!opt_bare) {
		padcat(2, indent, production, "   preamble:    ",
		       Preamble->Description);
	}
	return true;
}

	/* the general terms, definition and clauses */
bool sol_terms(char **production, Terms *Terms, int indent) {
	if (!Terms) return false;
	if (opt_debug) printf("producing Terms\n");
	sol_provisions(production, Terms->Provisions, indent);
	return true;
}

bool sol_covenants(char **production, Covenants *Covenants, int indent) {
	if (!Covenants) return false;
	if (opt_debug) printf("producing contracts\n");
	sol_covenant(production, Covenants->Covenant, indent);
	sol_covenants(production, Covenants->Covenants, indent);
	return true;
}

bool sol_covenant(char **production, Covenant *Covenant, int indent) {
	if (!Covenant) return false;
	if (opt_debug) printf("producing Covenant %s\n", Covenant->Name);

	paratag = strlen(*production);
	class = mtrac_strdup(UP(camel_spaced(Covenant->Name)));
	instance = snakedup(Covenant->Name);
	has_subclasses = true;
	char *functions_shelve = mtrac_strdup(functions);
	char *fixed_shelve = mtrac_strdup(fixed);
	char *declared_shelve = mtrac_strdup(declared);
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

	if (opt_comment) padcat(2, 1, &adders,
				"/* aggregation of covenants for folds and serialization */");
	padcat(C, 1, &adders, "mapping(uint => contract) public ", list, ";");
	padcat(1, 1, &adders, "uint ", count, " = 0;");

	if (opt_comment) padcat(2, indent, production, "/**");
	if (opt_comment) padcat(1, indent, production, " ** ", class,
				" covenant class");
	if (opt_comment) padcat(1, indent, production, " **/");

	/* ///// clean up
	 * if(opt_lexon_comments) {
	 * char *c = mtrac_strdup(get_lexcom("start"));
	 * replace(&c, "\n", "\n *\t");
	 * padcat(1, 0, production, "/ ** ", c, "\n** /");
	 * mtrac_free(c);
	 * }
	 */

	padcat(2, indent, production, "contract ", class, " {");
	padcat(1, indent + 1, production, "constructor(%2%) {");	// %2%: constructor parameters, ////// payable
	char *declarations_stack = declarations;
	char *initializations_stack = initializations;
	char *parameters_stack = parameters;
	char *arguments_stack = arguments;
	char *parameta_stack = parameta;

	declarations = mtrac_strdup("");
	initializations = mtrac_strdup("");
	parameters = mtrac_strdup("");
	arguments = mtrac_strdup("");
	parameta = mtrac_strdup("");   // sic, for JS too
	bool is_payable_stack = is_payable;
	bool is_stateful_stack = is_stateful;

	is_payable = false;
	is_stateful = false;

	padcat(2, 0, &instructions,
	       "   The following are actions that can be performed per ", class,
	       ".");
	padcat(2, 0, &instructions, "   > ", instance, " = %contract%.add_",
	       instance, "(%2%)");

	enforce_same_subject = true;
	covenant_constructor_body = true;
	sol_provisions(production, Covenant->Provisions, indent + 2);

	covenant_constructor_body = false;
	enforce_same_subject = false;

	if (uses_termination) {
		if (opt_comment) padcat(3, indent + 1, production,
					"/* built-in termination of this covenant */");
		padcat(C, indent + 1, production,
		       "function termination() internal {");
		padcat(1, indent + 2, production, "terminated = true;");

		padcat(1, indent + 1, production, "}");
		padcat(2, indent + 1, production,
		       "function already_terminated() internal view returns(bool) {");
		padcat(1, indent + 2, production,
		       "if(!terminated) return false;");
		padcat(1, indent + 2, production, "return true;");
		padcat(1, indent + 1, production, "}");
	}

	/* end of covenant class definition */
	padcat(1, indent, production, "}");

	/* wrapper for the covenant constructor: user api to the hidden classes constructor (must appear after main's (top level) constructor */
	if (opt_comment) padcat(2, 1, &adders, "/* create new instance of ",
				Covenant->Name,
				" covenant, and register it with main */");

	padcat(C, 1, &adders, "function add_", SNAKE(Covenant->Name),
	       "(%2%) returns(", Covenant->Name, ") {");
	if (uses_termination) padcat(1, 2, &adders, "check_termination()" EOL);
	padcat(1, 2, &adders, "return ", list, "[", count, " += 1] = new ",
	       class, "(%2b%);");
	padcat(1, 1, &adders, "}");
	/* inject parameter lists */
	replace(production, "%2%", parameters);
	replace(&adders, "%2%", parameters);
	replace(&adders, "%2b%", arguments);
	replace(&instructions, "%2%", parameta);

	/* function modifier */
	// needed here? ◊
	replace(production, "%33%", !is_stateful ? " view" : "");
	/* sol+sop: insert declaration of member variables into constructor (sol)/contract (sop) head */
	replace(production, "%27C%", declarations);
	/* cleanup & stack ('shelve') popping */
	if (covenant_subjects) delete_list(covenant_subjects);
	covenant_subjects = null;
	assert(!!!active_subjects);
	active_subjects = null;
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
	is_stateful = is_stateful_stack;
	mtrac_free(functions), functions = functions_shelve;
	mtrac_free(fixed), fixed = fixed_shelve;
	mtrac_free(declared), declared = declared_shelve;
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
bool sol_provisions(char **production, Provisions *Provisions, int indent) {
	if (!Provisions) return false;
	if (opt_debug) printf("producing Provisions\n");

	/* definitions */
	if (!global_definitions) global_definitions = Provisions->Definitions;
	else covenant_definitions = Provisions->Definitions;	// (sic)
	sol_definitions(production, Provisions->Definitions, indent);
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
	sol_statements(production, Provisions->Statements, indent);
	if (msg_sender) mtrac_free(msg_sender);
	if (msg_value) mtrac_free(msg_value);
	recital_of_terms = false;
	enforce_same_subject = false;

	/* end of constructor code */

	if (!main_constructor_body) padcat(1, --indent, production, "}");	// end of constructor

	/* insert caller argumnet and 'payable' modifier */

	replace(production, "%28%", is_payable ? "payable " : "");

	/* clauses */
	sol_clauses(instance ? production : &methods, Provisions->Clauses,
		    indent - (instance ? 0 : 1));

	char *termination_test = mtrac_strdup("");

	if (uses_termination) padcat(1,
				     indent + (main_constructor_body ? 0 : 1),
				     &termination_test,
				     "check_termination()" EOL);

	replace(instance ? production : &methods,
		main_constructor_body ? "%24%" : "%25%", termination_test);
	mtrac_free(termination_test);

	return true;
}

bool sol_definitions(char **production, Definitions *Definitions, int indent) {
	if (!Definitions) return false;
	sol_definitions(production, Definitions->Definitions, indent);
	sol_definition(production, Definitions->Definition, indent);
	return true;
}

bool sol_definition(char **production, Definition *Definition, int indent) {
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
	padcat(1, indent - 1, &declarations,
	       typemap(lowsnake_literal, opt_harden, false, __LINE__), " ",
	       lowsnake_safe_name, EOL);
	mtrac_free(lowsnake_safe_name);
	mtrac_free(lowsnake_literal);
	padcat(0, 0, &declared, ":", SNAKE(Definition->Name), ":");	// declared: write #1
	return true;
}

const char *typemap(const char *lex_type, bool option_type, bool forpara,
		    int line) {
	if (!lex_type) return "undefined";	// assert ◊
	if (!strcmp(lex_type, "person")) return "address payable";
	if (!strcmp(lex_type, "number")) return "uint";
	if (!strcmp(lex_type, "amount")) return "uint";
	if (!strcmp(lex_type, "amount")) return "uint";
	if (!strcmp(lex_type, "time")) return "uint";
	if (!strcmp(lex_type, "text")) return forpara ? "string memory" :
			"string";
	if (!strcmp(lex_type, "data")) return forpara ? "string memory" :
			"string";
	if (!strcmp(lex_type, "binary")) return "bool";

	printf("Unknown type at %d\n", line);
	exit(1);
	return "[ ERROR: UNKNOWN TYPE ]";
}

const char *nullmap(const char *lex_type, bool defined_default) {
	if (!lex_type) return "undefined";
	// defined_default means, don't use None as null but a proper value.

	if (!strcmp(lex_type, "person")) return "address(0)";

	if (!strcmp(lex_type, "number")) return "0";
	if (!strcmp(lex_type, "amount")) return "0";
	if (!strcmp(lex_type, "time")) return "0";
	if (!strcmp(lex_type, "text")) return "\"\"";
	if (!strcmp(lex_type, "data")) return "\"\"";
	if (!strcmp(lex_type, "binary")) return "false";
	return "[ ERROR: UNKNOWN CATEGORY ]";
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
	printf("Unknown type for %s\n", name);
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

bool sol_this_contract(char **production, This_Contract *This_Contract, int indent) {	// unclear concept ◊
	if (!This_Contract) return false;

	// intentionally empty
	return true;
}

bool sol_all_contracts(char **production, All_Contracts *All_Contracts, int indent) {	// unclear concept ◊
	if (!All_Contracts) return false;
	// intentionally empty

	return true;
}

bool sol_clauses(char **production, Clauses *Clauses, int indent) {
	if (!Clauses) return false;

	sol_clauses(production, Clauses->Clauses, indent);
	sol_clause(production, Clauses->Clause, indent);

	return true;
}

bool sol_clause(char **production, Clause *Clause, int indent) {
	if (!Clause) return false;
	if (opt_debug) printf("producing Clause %s\n", Clause->Name);

	list *active_subjects_stack = active_subjects;

	active_subjects = null;
	bool is_payable_stack = is_payable;
	bool is_stateful_stack = is_stateful;

	/* track which function calls which other functions */
	char *low = SNAKE(Clause->Name);
	char *safe = safedup(low);
	bind *bind = register_bind(safe);

	mtrac_free(safe);
	padcat(0, 0, &declared, ":", low, ":");	// declared: write #2
	current_function = bind;

	paratag = strlen(*production);
	if (opt_comment) padcat(3, indent, production, "/* ", Clause->Name,
				" clause */");

	if (opt_lexon_comments) {
		char *clause = snakedup(Clause->Name);
		char *c = mtrac_strdup(get_lexcom(clause));

		mtrac_free(clause);
		assert(c);
		if (main_constructor_body) {
			replace(&c, "\n", "\n     *  ");
			padcat(2, 0, production, "    /*\n     *  ", c,
			       "\n     */");
		} else {
			replace(&c, "\n", "\n     *  ");
			padcat(2, 0, production, "    /*\n     *  ", c,
			       "\n     */");
		}
		mtrac_free(c);
	}
	padcat(C, indent, production, "function ", bind->tag, " public%30%%33%%35%");	// %30%: payable, %33%: view %35%: inference

	padcat(1, 0, &instructions, "   • %26%", bind->tag);	// %26% caller

	assert(functions);
	if (Clause->Name) mtrac_concat(&functions, ":", Clause->Name, ":");

	sol_body(production, Clause->Body, indent);

	replace(production, "%30%", is_payable ? " payable" : "");
	replace(production, "%35%", "");	// take out if not used
	replace(production, "%33%", !is_stateful ? " view" : "");

	paratag = -1;
	current_function = null;       // not used in recitals

	assert(!active_subjects || active_subjects != covenant_subjects);
	if (active_subjects) delete_list(active_subjects);
	active_subjects = active_subjects_stack;
	is_payable = is_payable_stack;
	is_stateful = is_stateful_stack;

	return true;
}

char *courtesy;			       // courtesy warning if no subject of a multi-sentence clause could access.
char *courtesy_track;
bool sol_body(char **production, Body *Body, int indent) {
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

/*ΩΩΩ*/ courtesy = mtrac_strdup("");

		courtesy_track = mtrac_strdup("");

	}

	msg_sender = null;
	msg_value = null;
	is_payable = false;
	is_stateful = false;
	sol_statements(production, Body->Statements, indent + 1);
	if (msg_sender) mtrac_free(msg_sender);
	if (msg_value) mtrac_free(msg_value);

	if (multi_sentence_clause) {
		mtrac_free(courtesy);
		mtrac_free(courtesy_track);
	}

	sol_function(production, Body->Function, indent + 1);

	padcat(1, indent, production, "}");
	return true;
}

bool sol_function(char **production, Function *Function, int indent) {
	if (!Function) return false;
	if (opt_debug) printf("producing Function %s\n", Function->Name);
	padcat(1, indent, production, "return ");

	sol_expression(production, Function->Expression, indent + 1);
	padcat(0, 0, production, EOL);

	/* add return type to function signature */
	char *returns = mtrac_strdup("");

	if (inference) padcat(0, 0, &returns, " returns(", inference, ")");
	replace(production, "%35%", returns ? returns : "");
	inference = null;
	mtrac_free(returns);

	return true;
}

static char *subjnonmatch = null;
static char *subjlatebind = null;
bool sol_statements(char **production, Statements *Statements, int indent) {
	if (!Statements) return false;
	if (opt_debug) printf("producing Statements\n");

	sol_statements(production, Statements->Statements, indent);
	sol_statement(production, Statements->Statement, indent);

	return true;
}

bool sol_statement(char **production, Statement *Statement, int indent) {
	if (!Statement) return false;
	if (opt_debug) printf("producing Statement\n");
	sol_action(production, Statement->Action, indent);
	sol_flagging(production, Statement->Flagging, indent);
	return true;
}

static Name *subject = null;
static bool ever = false;
bool sol_action(char **production, Action *Action, int indent) {
	if (!Action) return false;
	if (opt_debug) printf("producing Action\n");
	action = Action;

	/* single subject only .. */
	subject = Action->Subject->Symbols->Symbol->Name;
	if (!ever && recital_of_terms) {
		bool payment = is_payment(Action->Predicates);

		/* this takes care of the subject person 1) becoming a parameter and 2) an object member that 3) gets the parameter assigned */
		insert_parameter_and_set_member(production, null, Action->Subject->Symbols->Symbol, payment, paratag, indent, __LINE__);	// call #1
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
			printf("testing %s\n", symbols->Symbol->Name);	// ◊◊
			list *c = active_subjects;

			while (c) {
				printf("    vs %s\n", (char *)c->item);	// ◊◊
				if (strcmp
				    ((char *)c->item, symbols->Symbol->Name))
					good = false;
				c = c->next;
			}
			symbols = symbols->Symbols;	// i.e., next
		}
		if (!good) error("In terms, the active subjects of all sentences must match", (char *)active_subjects->item);	//..
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

	sol_subject(production, Action->Subject, indent);

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
			padcat(1, indent, production, "permit(");
			if (current_function) current_function->uses_caller =
					true;
			sol_symbol(production, Action->Subject->Symbols->Symbol,
				   false, 0);

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

				sol_symbol(&symbol, Symbols->Symbol, false, 0);
				if (i++) padcat(0, 0, production, " || ");

				padcat(0, 0, production, "msg.sender == ",
				       symbol);

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
						       "msg.sender == ",
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
				padcat(0, 0, production, ") {");

				indent++;
			}
		}
	}

	sol_condition(production, Action->Condition, indent);
	if (Action->Condition) indent++;

	sol_predicates(production, Action->Predicates, indent);

	if (Action->Condition) padcat(1, --indent, production, "}");

	// ◊◊◊ /* for multiple sentences, add the closing, reverting else */
	if (current_function && !single_sentence_clause) {
		// ◊◊◊ padcat(1, --indent, production, "}");
	}

	if (current_function && !single_sentence_clause) {	// ◊◊◊
		padcat(1, --indent, production, "} else {");	// ◊◊◊
		padcat(1, indent + 1, production, "revert(\"not permitted\");");	// ◊◊◊
		padcat(1, indent--, production, "}");	// ◊◊◊
	}			       // ◊◊◊

	action = null;
	if (active_subjects
	    && active_subjects !=
	    covenant_subjects) delete_list(active_subjects);
	active_subjects = null;
	return true;
}

bool sol_subject(char **production, Subject *Subject, int indent) {
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

			char *varname = snakedup(s->Symbol->Name);
			char *lexname = s->Symbol->Name;
			char *scope = (!in(globals, s->Symbol->Name) && class) ? "this." : "main.";	////// unite with usual 'main_constructor_body?' ?

			padcat(0, 0, para, first ? "<<" : " or ", lexname);
			/* binding of unbound person variable to caller parameter */
			if (!main_constructor_body) {
				char *safe = safedup(varname);

				/* precondition that caller and all of the subjects cannot be the same */
				if (first) padcat(2, indent, &subjnonmatch,
						  "if(caller != ", scope, safe);
				else padcat(0, 0, &subjnonmatch,
					    " && caller != ", scope, safe);
				/* produce bind code. Person in question must still be null, i.e., unbound */
				if (!in(fixed, varname)) {
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
	if (strlen(*para)) padcat(0, 0, para, ">>");	// .. sometimes produces >>>>
	if (strlen(*para)) concat(para, " ⟶  ");
	replace(&instructions, "%26%", *para);
	mtrac_free(_para);

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

bool sol_symbols(char **production, Symbols *Symbols, int indent) {
	if (!Symbols) return false;
	sol_symbol(production, Symbols->Symbol, false, indent);
	sol_catena(production, Symbols->Catena, indent);
	sol_symbols(production, Symbols->Symbols, indent);
	return true;
}

bool sol_symbol(char **production, Symbol *Symbol, bool assign, int indent) {
	if (!Symbol) return false;

	/* produce the name literal. Note that sol_name adds 'this.'
	 * or 'main.', which makes for a global scope, while the cases
	 * that a type name is itself used as variable name, it is use
	 * unprefixed, for a local scope. */
	if (Symbol->Name)
		sol_name(production, Symbol->Name, assign, indent);
	else {
		assert(Symbol->Type);
		char *safe = safedup(SNAKE(Symbol->Type->Literal));

		padcat(0, 0, production, safe);
		if (assign) padcat(0, 0, &fixed, ":", safe, ":");
		mtrac_free(safe);
	}
	return true;
}

bool sol_noun(char **production, Symbol *Symbol, int indent) {
	if (!Symbol) return false;
	if (Symbol->Name)
		padcat(0, 0, production, Symbol->Name);
	else {
		assert(Symbol->Type);
		padcat(0, 0, production, Symbol->Type->Literal);
	}
	return true;
}

bool sol_catena(char **production, Catena *Catena, int indent) {
	if (!Catena) return false;
	return true;
}

bool sol_object(char **production, Object *Object, int indent) {
	if (!Object) return false;
	if (opt_debug) printf("producing Object\n");
	if (Object->Symbol) {

		sol_symbol(production, Object->Symbol, false, indent + 1);

	} else if (Object->Reflexive)
		sol_reflexive(production, Object->Reflexive, indent + 1);
	// else: escrow == do nothing
	return true;
}

bool sol_reflexive(char **production, Reflexive *Reflexive, int indent) {
	if (!Reflexive) return false;
	if (opt_debug) printf("producing Reflexive\n");

	assert(action);
	assert(action->Subject);
	assert(action->Subject->Symbols);
	if (!action->Subject->Symbols->Symbol)
		error("missing subject for reflexive pronoun", "...");	///// add literal from parse run
	if (action->Subject->Symbols->Symbols)
		error("don't use multiple subjects with a reflexive pronoun",
		      action->Subject->Symbols->Symbol->Name);
	sol_symbol(production, action->Subject->Symbols->Symbol, false,
		   indent + 1);

	return true;
}

bool sol_predicates(char **production, Predicates *Predicates, int indent) {
	if (!Predicates) return false;
	if (opt_debug) printf("producing Predicates\n");
	sol_predicates(production, Predicates->Predicates, indent);
	sol_predicate(production, Predicates->Predicate, indent);
	return true;
}

bool sol_predicate(char **production, Predicate *Predicate, int indent) {
	if (!Predicate) return false;
	if (opt_debug) printf("producing Predicate\n");

	if (current_function) current_function->changes_state = true;

	sol_certification(production, Predicate->Certification, indent);
	sol_declaration(production, Predicate->Declaration, indent);
	sol_filing(production, Predicate->Filing, indent);
	sol_registration(production, Predicate->Registration, indent);
	sol_grantment(production, Predicate->Grantment, indent);
	sol_appointment(production, Predicate->Appointment, indent);
	sol_fixture(production, Predicate->Fixture, indent);
	sol_setting(production, Predicate->Setting, indent);
	sol_payment(production, Predicate->Payment, indent);
	sol_sending(production, Predicate->Sending, indent);
	sol_notification(production, Predicate->Notification, indent);
	sol_termination(production, Predicate->Termination, indent);

	return true;
}

bool sol_permission(char **production, Permission *Permission, int indent) {
	if (!Permission) return false;
	if (opt_debug) printf("producing Permission\n");
	return true;
}

	/* assign a symbol an expression */
static void assign(char **production, int indent, Symbol *symbol,
		   Expression *expression) {
	padcat(1, indent, production, "");

	miller = true;
	sol_symbol(production, symbol, true, indent);	// true --> assign flag
	miller = false;
	is_stateful = true;	       // clean up where set outside assign ◊
	padcat(0, 0, production, " = ");
	if (expression)
		sol_expression(production, expression, indent + 1);
	else
		padcat(0, 0, production, "true");

	padcat(0, 0, production, EOL);
}

bool sol_certification(char **production, Certification *Certification,
		       int indent) {
	if (!Certification) return false;
	if (opt_debug) printf("producing Certification\n");

	if (Certification->Contract) { // 'certify contract as ..'
		assign(production, indent, Certification->Symbol, null);
	} else if (Certification->Expression) {
		assign(production, indent, Certification->Symbol,
		       Certification->Expression);
	} else {		       // nothing -> create a parameter
		insert_parameter_and_set_member(production, &instructions, Certification->Symbol, false, paratag, indent, __LINE__);	// call #2a
		// cf. evaluation.lex commissioned() / statement.lex certify() ◊
	}
	return true;
}

bool sol_certify(char **production, Certify *Certify, int indent) {
	if (!Certify) return false;
	return true;
}

bool sol_declaration(char **production, Declaration *Declaration, int indent) {
	if (!Declaration) return false;
	if (opt_debug) printf("producing Declaration\n");

	assert(!strstr(*production, "%preassign%"));	//X new after javascript.c was finished
	padcat(0, 0, production, "%preassign%");
	preass_indent = indent;
	assign(production, indent, Declaration->Symbol, Declaration->Expression);	//X new after javascript.c was finished //////

	replace(production, "%preassign%", "");

	return true;
}

bool sol_declare(char **production, Declare *Declare, int indent) {
	if (!Declare) return false;
	if (opt_debug) printf("producing Declare\n");
	padcat(1, indent, production, "( declare ");
	return true;
}

	/* e.g. The Secured Party may file the Continuation Statement. (only example currently) */
bool sol_filing(char **production, Filing *Filing, int indent) {
	if (!Filing) return false;
	if (opt_debug) printf("producing Filing\n");

	if (Filing->Expression)
		assign(production, indent, Filing->Symbol, Filing->Expression);
	else
		insert_parameter_and_set_member(production, &instructions, Filing->Symbol, false, paratag, indent, __LINE__);	// call #3

	return true;
}

bool sol_file(char **production, File *File, int indent) {
	if (!File) return false;
	if (opt_debug) printf("producing File\n");
	return true;
}

	/* e.g., The Licensee may register a Comment Text. (only example) */
bool sol_registration(char **production, Registration *Registration, int indent) {
	if (!Registration) return false;
	if (opt_debug) printf("producing registration\n");

	if (Registration->Expression)
		assign(production, indent, Registration->Symbol,
		       Registration->Expression);
	else
		insert_parameter_and_set_member(production, &instructions, Registration->Symbol, false, paratag, indent, __LINE__);	// call #4

	return true;
}

bool sol_register(char **production, Register *Register, int indent) {
	if (!Register) return false;
	if (opt_debug) printf("producing Register\n");
	return true;
}

bool sol_grantment(char **production, Grantment *Grantment, int indent) {
	if (!Grantment) return false;
	if (opt_debug) printf("producing Grantment\n");

	assign(production, indent, Grantment->Symbol, null);	// sets true

	return true;
}

bool sol_grant(char **production, Grant *Grant, int indent) {
	if (!Grant) return false;
	return true;
}

bool sol_appointment(char **production, Appointment *Appointment, int indent) {
	if (!Appointment) return false;
	if (opt_debug) printf("producing Appointment\n");

	/* produce person code: take care that they 1) become parameters, and 2) object elements with 3) that parameter assigned to */
	insert_parameter_and_set_member(production, &instructions, Appointment->Symbol, false, paratag, indent, __LINE__);	// call #5
	return true;
}

bool sol_appoint(char **production, Appoint *Appoint, int indent) {
	if (!Appoint) return false;
	return true;
}

	/* The Licensor or the Arbiter may fix the Notice Time as the respective current time.
	 * The Licensor [..] fixes the Description of Goods. */
bool sol_fixture(char **production, Fixture *Fixture, int indent) {
	if (!Fixture) return false;
	if (opt_debug) printf("producing Fixture\n");

	if (Fixture->Expression)
		assign(production, indent, Fixture->Symbol,
		       Fixture->Expression);
	else
		insert_parameter_and_set_member(production, &instructions, Fixture->Symbol, false, paratag, indent, __LINE__);	// call #6

	return true;
}
bool sol_fix(char **production, Fix *Fix, int indent) {
	if (!Fix) return false;
	return true;
}

bool sol_setting(char **production, Setting *Setting, int indent) {	// dysfunctional ◊
	if (!Setting) return false;
	if (opt_debug) printf("producing Setting\n");
	padcat(1, indent, production, "");
	sol_symbol(production, Setting->Symbol, false, indent + 1);
	padcat(0, 0, production, " = true;");	// set");

	return true;
}

bool sol_illocutor(char **production, Illocutor *Illocutor, int indent) {
	if (!Illocutor) return false;
	if (opt_debug) printf("producing Illocutor\n");

	padcat(0, 0, production, " = ");

	return true;
}

bool sol_payment(char **production, Payment *Payment, int indent) {
	if (!Payment) return false;
	if (opt_debug) printf("producing Payment\n");

	assert(!strstr(*production, "%preassign%"));
	padcat(0, 0, production, "%preassign%");
	preass_indent = indent;

	bool explicit_from_escrow = Payment->Escrow || Payment->From_Escrow;
	bool explicit_to_escrow = !Payment->Object->Symbol
		&& !Payment->Object->Reflexive;
	assert(!(explicit_from_escrow && explicit_to_escrow));

	// msg.value is paid in implicitly, no code to produce ..
	if (explicit_to_escrow) {
		// .. but handle the amount variable (declaration)
		// e.g. it must consume the msg_value slot if 'Amount'
		/// this won't hold expressions for payment amounts, so assert
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
			sol_expression(production, Payment->Expression, 0);
			payment_expression = false;
			no_literal = false;
		}
		replace(production, "%preassign%", "");
		return true;
	}

	/* function head */
	sol_pay(production, Payment->Pay, indent);

	/* sender */
	/* receiver */
	if (!explicit_to_escrow)
		sol_object(production, Payment->Object, 0);
	else
		padcat(0, 0, production, "'escrow'");

	padcat(0, 0, production, ", ");

	/* amount */
	if (Payment->Expression)
		sol_expression(production, Payment->Expression, 0);
	else
		padcat(0, 0, production, "address(this).balance");
	padcat(0, 0, production, ")", EOL);

	replace(production, "%preassign%", "");
	return true;
}

bool sol_pay(char **production, Pay *Pay, int indent) {
	if (!Pay) return false;
	if (opt_debug) printf("producing Pay\n");
	uses_pay = true;
	is_stateful = true;

	padcat(1, indent, production, "transfer(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool sol_preposition(char **production, Preposition *Preposition, int indent) {
	if (!Preposition) return false;
	if (opt_debug) printf("producing Preposition\n");
	return true;
}

bool sol_escrow(char **production, Escrow *Escrow, int indent) {
	if (!Escrow) return false;
	if (opt_debug) printf("producing Escrow\n");

	padcat(0, 0, production, "address(this)");
	return true;
}

bool sol_from_escrow(char **production, From_Escrow *From_Escrow, int indent) {
	if (!From_Escrow) return false;
	if (opt_debug) printf("producing From_Escrow\n");

	padcat(0, 0, production, "address(this)");
	return true;
}

bool sol_sending(char **production, Sending *Sending, int indent) {
	if (!Sending) return false;
	if (opt_debug) printf("producing Sending\n");

	sol_send(production, Sending->Send, indent);

	// receiver
	assert(Sending->Object->Symbol || Sending->Object->Reflexive);
	sol_object(production, Sending->Object, 0);
	padcat(0, 0, production, ", ");

	// message
	sol_expression(production, Sending->Expression, 0);
	padcat(0, 0, production, ")", EOL);
	return true;
}

bool sol_send(char **production, Send *Send, int indent) {
	if (!Send) return false;
	if (opt_debug) printf("producing Send\n");
	uses_send = true;

	padcat(1, indent, production, "send(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool sol_notification(char **production, Notification *Notification, int indent) {	// document it ◊
	if (!Notification) return false;
	if (opt_debug) printf("producing Notification\n");

	sol_notify(production, Notification->Notify, indent);

	// receiver
	assert(Notification->Object->Symbol || Notification->Object->Reflexive);
	sol_object(production, Notification->Object, 0);
	padcat(0, 0, production, ", ");

	// message
	if (Notification->Expression)
		sol_expression(production, Notification->Expression, 0);
	else
		padcat(0, 0, production, "\"NOTIFICATION\"", EOL);
	padcat(0, 0, production, ")", EOL);

	return true;
}

bool sol_notify(char **production, Notify *Notify, int indent) {
	if (!Notify) return false;
	if (opt_debug) printf("producing Notify\n");

	uses_send = true;

	padcat(1, indent, production, "send(");
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;

	return true;
}

bool sol_termination(char **production, Termination *Termination, int indent) {
	if (!Termination) return false;
	if (opt_debug) printf("producing Termination\n");
	padcat(1, indent, production, "");
	sol_this_contract(production, Termination->This_Contract, indent + 1);
	sol_all_contracts(production, Termination->All_Contracts, indent + 1);
	sol_terminate(production, Termination->Terminate, indent + 1);
	return true;
}

bool sol_terminate(char **production, Terminate *Terminate, int indent) {
	if (!Terminate) return false;
	if (opt_debug) printf("producing Terminate\n");
	uses_termination = true;

	padcat(0, 0, production, "termination()", EOL);
	is_stateful = true;
	if (current_function) current_function->uses_caller |= opt_log
			|| opt_feedback;
	return true;
}

bool sol_flagging(char **production, Flagging *Flagging, int indent) {
	if (!Flagging) return false;
	if (opt_debug) printf("producing Flagging\n");
	padcat(1, indent, production, "");
	sol_symbol(production, Flagging->Symbol, true, indent + 1);
	padcat(0, 0, production, " = true;");	////////
	return true;
}

bool sol_condition(char **production, Condition *Condition, int indent) {
	if (!Condition) return false;
	if (opt_debug) printf("producing Condition\n");

	sol_if(production, Condition->If, indent);
	sol_expression(production, Condition->Expression, indent + 1);
	padcat(0, 0, production, ") {");
	return true;
}

bool sol_if(char **production, If *If, int indent) {
	if (!If) return false;
	if (opt_debug) printf("producing If\n");
	padcat(1, indent, production, "if(");
	return true;
}

bool sol_expression(char **production, Expression *Expression, int indent) {
	if (!Expression) return false;
	if (opt_debug) printf("producing Expression\n");
	// padcat(0, 0, production, "«");
	sol_combination(production, Expression->Combination, indent + 1);
	//padcat(0, 0, production, "»");
	return true;
}

bool sol_scalar_comparison(char **production,
			   Scalar_Comparison *Scalar_Comparison, int indent) {
	if (!Scalar_Comparison) return false;
	if (opt_debug) printf("producing Scalar_Comparison\n");

	// obsolete bool self = Scalar_Comparison->Scalar_Expression ///// clean up
	//      && Scalar_Comparison->Scalar_Expression->Symbol
	//      && Scalar_Comparison->Scalar_Expression->Symbol->This_Contract
	//      && Scalar_Comparison->Comparison_Operator;

	// dito if(!self) { ///// clean up
	padcat(0, 0, production, "(");
	sol_scalar_expression(production, Scalar_Comparison->Scalar_Expression,
			      indent + 1);
	sol_comparison_operator(production,
				Scalar_Comparison->Comparison_Operator,
				indent + 1);
	// }
	char *inference_stack = inference;

	sol_scalar_expression(production, Scalar_Comparison->Scalar_Expression2,
			      indent + 1);
	inference = inference_stack;

	// dito if(!self) ///// clean up
	padcat(0, 0, production, ")");

	return true;
}

bool sol_comparison_operator(char **production,
			     Comparison_Operator *Comparison_Operator,
			     int indent) {
	if (!Comparison_Operator) return false;
	if (opt_debug) printf("producing Comparison_Operator\n");
	sol_equal(production, Comparison_Operator->Equal, indent + 1);
	sol_later(production, Comparison_Operator->Later, indent + 1);
	return true;
}

bool sol_equal(char **production, Equal *Equal, int indent) {
	if (!Equal) return false;
	if (opt_debug) printf("producing Equal\n");
	padcat(0, 0, production, " == ");
	inference = "bool";
	return true;
}

bool sol_later(char **production, Later *Later, int indent) {
	if (!Later) return false;
	if (opt_debug) printf("producing Later\n");
	padcat(0, 0, production, " <= ");

	inference = "bool";
	return true;
}

bool sol_scalar_expression(char **production,
			   Scalar_Expression *Scalar_Expression, int indent) {
	if (!Scalar_Expression) return false;
	if (opt_debug) printf("producing Scalar_Expression %s\n",
			      Scalar_Expression->Scalar);
	sol_symbol(production, Scalar_Expression->Symbol, false, indent + 1);
	sol_scalar(production, Scalar_Expression->Scalar, indent + 1);
	sol_point_in_time(production, Scalar_Expression->Point_In_Time,
			  indent + 1);
	inference = "uint";
	return true;
}

bool sol_hex_expression(char **production, Hex_Expression *Hex_Expression,
			int indent) {
	if (!Hex_Expression) return false;
	if (opt_debug) printf("producing Hex_Expression %s\n",
			      Hex_Expression->Hex);
	sol_symbol(production, Hex_Expression->Symbol, false, indent + 1);
	sol_hex(production, Hex_Expression->Hex, indent + 1);
	// sol_point_in_time(production, Hex_Expression->Point_In_Time, indent+1);
	inference = "uint";
	return true;
}

bool sol_combination(char **production, Combination *Combination, int indent) {
	if (!Combination) return false;
	if (opt_debug) printf("producing Combination\n");
	if (Combination->Combinator) padcat(0, 0, production, "(");
	sol_combinor(production, Combination->Combinor, 0);
	sol_combinator(production, Combination->Combinator, indent);
	sol_combination(production, Combination->Combination, 0);
	char *inference_stack = inference;

	if (Combination->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;
	return true;
}

bool sol_combinor(char **production, Combinor *Combinor, int indent) {
	if (!Combinor) return false;
	if (opt_debug) printf("producing Combinor\n");
	if (Combinor->Combinator) padcat(0, 0, production, "(");

	sol_combinand(production, Combinor->Combinand, 0);
	sol_combinator(production, Combinor->Combinator, 0);
	sol_combinor(production, Combinor->Combinor, 0);

	char *inference_stack = inference;

	if (Combinor->Combinator) padcat(0, 0, production, ")");
	inference = inference_stack;

	return true;
}

bool sol_combinand(char **production, Combinand *Combinand, int indent) {
	if (!Combinand) return false;
	if (opt_debug) printf("producing Combinand\n");

	if (Combinand->Symbol) {
		char *funcname = Combinand->Symbol->Name;

		if (!funcname) funcname = Combinand->Symbol->Type->Literal;
		assert(funcname);
		char *varname = snakedup(funcname);

		if (!in(fixed, varname) && !in(functions, funcname)) {	// incomplete, depends on order ◊
			/* produce amounts/texts etc variables: take care that they
			 * 1) become parameters, and 2) object elements with that parameter assigned
			 * e.g., The Secured Party may pay a Reminder Fee into escrow. */
			insert_parameter_and_set_member(production, &instructions, Combinand->Symbol, payment_expression, paratag, indent + 4, __LINE__);	////// call #7
		}
		/* produce the literal (name or type name for variables that are named verbatim a type) */

		if (!no_literal) {

			sol_symbol(production, Combinand->Symbol, false,
				   indent + 1);

		}
		mtrac_free(varname);
	}
	sol_expiration(production, Combinand->Expiration, indent + 1);
	sol_description(production, Combinand->Description, indent + 1);
	sol_scalar_comparison(production, Combinand->Scalar_Comparison,
			      indent + 1);
	sol_negation(production, Combinand->Negation, indent + 1);
	sol_existence(production, Combinand->Existence, indent + 1);
	sol_point_in_time(production, Combinand->Point_In_Time, indent + 1);

	return true;
}

bool sol_combinator(char **production, Combinator *Combinator, int indent) {
	if (!Combinator) return false;
	if (opt_debug) printf("producing Combinator\n");
	sol_or_(production, Combinator->Or_, indent);
	sol_and(production, Combinator->And, indent);
	sol_neither(production, Combinator->Neither, indent);
	sol_nor(production, Combinator->Nor, indent);

	return true;
}

bool sol_or_(char **production, Or_ *Or_, int indent) {
	if (!Or_) return false;
	if (opt_debug) printf("producing Or_\n");
	padcat(indent ? 1 : 0, indent, production, " || ");
	inference = "bool";
	return true;
}

bool sol_and(char **production, And *And, int indent) {
	if (!And) return false;
	if (opt_debug) printf("producing And\n");
	padcat(indent ? 1 : 0, indent, production, " && ");
	inference = "bool";
	return true;
}

bool sol_neither(char **production, Neither *Neither, int indent) {
	if (!Neither) return false;
	if (opt_debug) printf("producing Neither\n");
	padcat(1, indent, production, "( neither ");
	padcat(0, 0, production, ") ");
	inference = "bool";
	return true;
}

bool sol_nor(char **production, Nor *Nor, int indent) {
	if (!Nor) return false;
	if (opt_debug) printf("producing Nor\n");
	padcat(1, indent, production, "( nor ");
	inference = "bool";
	return true;
}

bool sol_existence(char **production, Existence *Existence, int indent) {
	////// check and test for rule 'symbol be fixed'
	if (!Existence) return false;
	if (opt_debug) printf("producing Existence\n");
	// padcat(0, 0, production, "(");
	padcat(0, 0, production, "");

	assert(Existence->Symbol->Name);	// should never need Existance->Symbol->Type->Literal
	sol_symbol(production, Existence->Symbol, false, indent + 1);
	const char *lst = lexsymtype(Existence->Symbol);

	if (!lst || !strcmp(lst, "binary")) {

	} else {
		padcat(0, 0, production, " != ",
		       nullvalue(Existence->Symbol->Name, !opt_harden));
	}
	inference = "bool";
	return true;
}

bool sol_negation(char **production, Negation *Negation, int indent) {
	if (!Negation) return false;
	if (opt_debug) printf("producing Negation\n");
	assert(Negation->Symbol->Name);	// should never need Negation->Symbol->Type->Literal (?)

	const char *lst = lexsymtype(Negation->Symbol);

	if (!lst || !strcmp(lst, "binary")) {

		padcat(0, 0, production, "!");
		sol_symbol(production, Negation->Symbol, false, indent + 1);
	} else {
		sol_symbol(production, Negation->Symbol, false, indent + 1);
		padcat(0, 0, production, " == ",
		       nullvalue(Negation->Symbol->Name, !opt_harden));
	}
	inference = "bool";
	return true;
}

bool sol_negator(char **production, Negator *Negator, int indent) {
	if (!Negator) return false;
	if (opt_debug) printf("producing Negator\n");
	padcat(0, 0, production, "!");
	inference = "bool";
	return true;
}

bool sol_being(char **production, Being *Being, int indent) {
	if (!Being) return false;
	if (opt_debug) printf("producing Being\n");
	inference = "bool";
	return true;
}

bool sol_true(char **production, True *True, int indent) {
	if (!True) return false;
	if (opt_debug) printf("producing True\n");
	return true;
}

bool sol_article(char **production, Article *Article, int indent) {
	if (!Article) return false;
	return true;
}

bool sol_point_in_time(char **production, Point_In_Time *Point_In_Time,
		       int indent) {
	if (!Point_In_Time) return false;
	if (opt_debug) printf("producing Point In Time\n");
	sol_current_time(production, Point_In_Time->Current_Time, indent + 1);
	sol_relative_time(production, Point_In_Time->Relative_Time, indent + 1);
	inference = "uint";
	return true;
}

bool sol_current_time(char **production, Current_Time *Current_Time, int indent) {
	if (!Current_Time) return false;
	if (opt_debug) printf("producing Current_Time\n");

	padcat(0, 0, production, "block.timestamp");

	inference = "uint";
	return true;
}

bool sol_relative_time(char **production, Relative_Time *Relative_Time,
		       int indent) {
	if (!Relative_Time) return false;
	if (opt_debug) printf("producing Relative_Time\n");
	if (Relative_Time->Symbol) {
		padcat(0, 0, production, opt_harden ? "Some" : "", "(");
		sol_symbol(production, Relative_Time->Symbol, false,
			   indent + 1);
		padcat(0, 0, production, " + ");
	} else {

		padcat(0, 0, production, "(block.timestamp - ");

	}
	sol_duration(production, Relative_Time->Duration, indent + 1);
	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool sol_duration(char **production, Duration *Duration, int indent) {
	if (!Duration) return false;
	if (opt_debug) printf("producing Duration\n");
	padcat(0, 0, production, "(");

	sol_scalar_expression(production, Duration->Scalar_Expression,
			      indent + 1);
	padcat(0, 0, production, " * ");
	sol_time_unit(production, Duration->Time_Unit, indent + 1);

	padcat(0, 0, production, ")");
	inference = "uint";
	return true;
}

bool sol_time_unit(char **production, Time_Unit *Time_Unit, int indent) {
	if (!Time_Unit) return false;
	if (opt_debug) printf("producing Time_Unit\n");
	sol_years(production, Time_Unit->Years, indent + 1);
	sol_months(production, Time_Unit->Months, indent + 1);
	sol_weeks(production, Time_Unit->Weeks, indent + 1);
	sol_days(production, Time_Unit->Days, indent + 1);
	sol_hours(production, Time_Unit->Hours, indent + 1);
	sol_minutes(production, Time_Unit->Minutes, indent + 1);
	sol_seconds(production, Time_Unit->Seconds, indent + 1);
	sol_milliseconds(production, Time_Unit->Milliseconds, indent + 1);
	inference = "uint";
	return true;
}

bool sol_years(char **production, Years *Years, int indent) {
	if (!Years) return false;
	if (opt_debug) printf("producing Years\n");

	padcat(0, 0, production, "31536000");

	inference = "uint";
	return true;
}

bool sol_months(char **production, Months *Months, int indent) {
	if (!Months) return false;
	if (opt_debug) printf("producing Months\n");

	padcat(0, 0, production, "2592000");

	inference = "uint";
	return true;
}

bool sol_weeks(char **production, Weeks *Weeks, int indent) {
	if (!Weeks) return false;
	if (opt_debug) printf("producing Weeks\n");

	padcat(0, 0, production, "604800");

	inference = "uint";
	return true;
}

bool sol_days(char **production, Days *Days, int indent) {
	if (!Days) return false;
	if (opt_debug) printf("producing Days\n");

	padcat(0, 0, production, "86400");

	inference = "uint";
	return true;
}

bool sol_hours(char **production, Hours *Hours, int indent) {
	if (!Hours) return false;
	if (opt_debug) printf("producing Hours\n");

	padcat(0, 0, production, "3600");

	inference = "uint";
	return true;
}

bool sol_minutes(char **production, Minutes *Minutes, int indent) {
	if (!Minutes) return false;
	if (opt_debug) printf("producing Minutes\n");

	padcat(0, 0, production, "60");

	inference = "uint";
	return true;
}

bool sol_seconds(char **production, Seconds *Seconds, int indent) {
	if (!Seconds) return false;
	if (opt_debug) printf("producing Seconds\n");

	padcat(0, 0, production, "1");

	inference = "uint";
	return true;
}

bool sol_milliseconds(char **production, Milliseconds *Milliseconds, int indent) {
	if (!Milliseconds) return false;
	if (opt_debug) printf("producing Milliseconds\n");

	padcat(0, 0, production, "0");

	inference = "uint";
	return true;
}

bool sol_expiration(char **production, Expiration *Expiration, int indent) {
	if (!Expiration) return false;
	if (opt_debug) printf("producing Expiration\n");

	/// note: 'has passed' means that the moment has happened that the millisecond was counted as passed -> <=

	padcat(0, 0, production, " <= block.timestamp");

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
	/// todo: double check that it is only alphanumeric, no " and \ etc

	if (opt_debug) printf("producing parameter %s\n", pretty_varname);

	// protect keywords
	char *varname = safedup(pretty_varname);

	// protect parameters with leading underscore (sol),
	// or not because this. or main or state. will be prefixed (js, sop).
	char *parameter_varname = mtrac_strdup("");

	concat(&parameter_varname, "_", varname);	// with safedup() above can lead to double underscore
	// prepend type (sol, sop)
	char *typed_varname = mtrac_strdup("");

	concat(&typed_varname,
	       type(pretty_varname, opt_harden, false, __LINE__), " ", varname);

	char *pretty_typed_varname = mtrac_strdup("");

	concat(&pretty_typed_varname, pretty_varname, " : ",
	       type(pretty_varname, opt_harden, false, __LINE__));

	char *typed_parameter_varname = mtrac_strdup("");

	concat(&typed_parameter_varname,
	       type(pretty_varname, false, true, __LINE__), " ",
	       parameter_varname);
	/* binding to msg.sender and msg.value */
	bool use_sender = !active_subjects && !msg_sender
		&& !strcmp("person", lextype(pretty_varname));
	if (use_sender) msg_sender = mtrac_strdup(pretty_varname);
	bool use_value = payment && !msg_value
		&& !strcmp("amount", lextype(pretty_varname));
	// trace printf("payment %d -- msg_value %s -- pretty varname %s -- lextype %s\n", payment, msg_value, pretty_varname, lextype(pretty_varname));
	if (use_value) msg_value = mtrac_strdup(pretty_varname);
	is_payable |= !!use_value;
	is_stateful = true;

	/* 1: Add to the parameters and arguments list. In the produced code as well as (parameta) the instructions */
	if (!use_sender && !use_value) {
		if (!current_function) {
			/* outside a function (constructor?/////) */
			padcat(0, 0, &parameters, *parameters ? ", " : "",
			       typed_parameter_varname);
			padcat(0, 0, &arguments, *arguments ? ", " : "",
			       parameter_varname);
			if (instructions) padcat(0, 0, &parameta,
						 *parameta ? ", " : "", "<",
						 pretty_typed_varname, ">");
			//////// padcat(0, 0, &declared, ":", parameter_varname, ":"); // declared: write #4  ///// js was varname
			//////// note: changed to include underscore in some case
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

	/* 2: Set the member to the parameter.  It's a member only if it's not a variable named for a type
	 * (then found at Symbol->Type->Literal) */
	if (symbol->Name) {
		/* js: prep: we will (at [1]) look for, eg 'x = null;' in the previously produced */

		/* js: prep: .. to replace it (at [1]) with 'x = xpara;' */
		char *setting = mtrac_strdup("");
		char *initializing = mtrac_strdup("");

		bool preassign = !!strstr(*production, "%preassign%");
		int linebreak = preassign ? 1 : 0;
		int setting_indent = preassign ? preass_indent : indent;

		if (use_sender) {
			padcat(linebreak, setting_indent, &setting, varname,
			       " = payable(msg.sender);");
		} else if (use_value) {
			padcat(1, 1, &declarations, "bool ", varname,
			       "__set = false;");
			if (!main_constructor_body
			    && !covenant_constructor_body) {
				padcat(linebreak, setting_indent, &setting,
				       "if(", varname, "__set) {");
				padcat(1, setting_indent + 1, &setting,
				       "require(msg.value == ", varname,
				       ", \"wrong amount\");");
				padcat(1, setting_indent, &setting, "} else {");
				padcat(1, setting_indent + 1, &setting, varname,
				       " = msg.value;");

				padcat(1, setting_indent + 1, &setting, varname,
				       "__set = true;");
				padcat(1, setting_indent, &setting, "}");
			} else {
				padcat(1, setting_indent, &setting, varname,
				       " = msg.value;");
				padcat(1, setting_indent, &setting, varname,
				       "__set = true;");
			}
		} else {
			padcat(linebreak, setting_indent, &setting, varname,
			       " = ", parameter_varname, EOL);
		}
		/* 2b: set member immediately before the use of the value:
		 * within functions (instead within the constructor) when a parameter's value is to be used,
		 * and a member set to this value on the fly. The setting is inserted before the start of the
		 * statement that the expression is nested in that uses the symbol in question. */

		if (strstr(*production, "%preassign%")) {
			replace(production, "%preassign%", setting);	// insert before current statement
		}

		/* 2c: but if we could not find either, just create a member and assign the given parameter,
		 * js: production will currently be at declaration height, so we effectively append to the member declaration list */
		else {
			padcat(1, indent, production, setting);
		}

		mtrac_free(setting);
		mtrac_free(initializing);
	}

	/* 3: track that this symbol has been set */
	padcat(0, 0, &fixed, ":", varname, ":");	/////// note: changed to include underscore in some cases

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
		sol_name(production, (char *)s->item, false, 0);
		//.// if(current_function) current_function->uses_caller = true; ◊
		s = s->next;
	}
	padcat(0, 0, production, ") {");
}

void error(char *msg, char *cargo) {
	printf("Lexon semantic error: %s %s%s%s\n", msg, cargo ? "(" : "",
	       cargo ? cargo : "", cargo ? ")" : "");
	if (current_function) printf("In clause %s --\n",
				     current_function->name);
	exit(1);
}

/* end of file */
