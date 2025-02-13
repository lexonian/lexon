	/* core code production / AST walk */

#define CYCLE_2 true

#include <stdio.h>
#include <string.h>

int yylex(void);
void yyerror(const char *);

void *mtrac_gross(void *);

#define NEW(type, literal) \
	if(opt_debug_tokens) fprintf(stderr, "tokens : creating node for " #type "'%s'\n", literal); \
	type *type = mtrac_malloc(sizeof(struct type)); \
	mtrac_gross(type); \
	memset(type, 0, sizeof(struct type)); \
	type->Literal = literal;
#define mtrac_malloc(size_) _mtrac_malloc(size_, "[unknown]", __FILE__, __LINE__)
#define mtrac_strdup(string_) _mtrac_strdup(string_, "[unknown]", __FILE__, __LINE__)
#define mtrac_free(var_) _mtrac_free(var_, #var_, __FILE__, __LINE__)
void *_mtrac_malloc(size_t size, char *name, char *file, int line);
void *_mtrac_strdup(const char *string, char *name, char *file, int line);
char *_mtrac_dupcat(const char *string, ...);
void _mtrac_free(void *p, char *name, char *file, int line);
#define YYFPRINTF yacc_printf
typedef int bool;
#define false 0
#define true 1
#define null (void *)0

typedef char Literal;
typedef char Name;
typedef char Description;
typedef char Scalar;

typedef char Hex;

#define padcat(down_, right_, var_, ...) \
	_concat(#var_, __FILE__, __LINE__, down_, right_, var_, __VA_ARGS__, null)
char **_concat(char *, char*, int, int, int, char **buf, ...);
void yacc_printf(FILE *stream, char *format, ...);

extern bool opt_produce_tree;
extern bool opt_produce_flat;
extern bool opt_produce_terse;
extern bool opt_debug;
extern bool opt_verbose;
extern bool opt_debug_actions;

extern bool opt_debug_tokens;

extern char *opening_bracket;

extern char *closing_bracket;

extern bool bracket_just_closed; // optics: helps with line breaks in produced core code

extern unsigned int grid; // optics: bitpattern of vertical tree branch lines, across rows

/* AST nodes = semantic value types (in actions, the respective types of '$$') */
	
	typedef struct Document {
		struct Head *Head;
		struct Terms *Terms;
		struct Covenants *Covenants;
		Literal *Literal;
	} Document;
	
	typedef struct Head {
		struct Lex *Lex;
		struct Preamble *Preamble;
		struct Comment *Comment;
		struct Authors *Authors;
		struct Lexon *Lexon;
		Literal *Literal;
	} Head;
	
	typedef struct Lex {
		Name *Name;
		Literal *Literal;
	} Lex;
	
	typedef struct Lexon {
		Description *Description;
		Literal *Literal;
	} Lexon;
	
	typedef struct Authors {
		Description *Description;
		Literal *Literal;
	} Authors;
	
	typedef struct Comment {
		Description *Description;
		Literal *Literal;
	} Comment;
	
	typedef struct Preamble {
		Description *Description;
		Literal *Literal;
	} Preamble;
	
	typedef struct Terms {
		struct Provisions *Provisions;
		Literal *Literal;
	} Terms;
	
	typedef struct Covenants {
		struct Covenant *Covenant;
		struct Covenants *Covenants;
		Literal *Literal;
	} Covenants;
	
	typedef struct Covenant {
		Name *Name;
		struct Provisions *Provisions;
		Literal *Literal;
	} Covenant;
	
	typedef struct Provisions {
		struct Definitions *Definitions;
		struct Clauses *Clauses;
		struct Statements *Statements;
		Literal *Literal;
	} Provisions;
	
	typedef struct Definitions {
		struct Definition *Definition;
		struct Definitions *Definitions;
		Literal *Literal;
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
		Literal *Literal;
	} Clauses;
	
	typedef struct Clause {
		Name *Name;
		struct Body *Body;
		Literal *Literal;
	} Clause;
	
	typedef struct Body {
		struct Statements *Statements;
		struct Function *Function;
		Literal *Literal;
	} Body;
	
	typedef struct Function {
		Name *Name;
		struct Illocutor *Illocutor;
		struct Expression *Expression;
		struct Article *Article;
		Literal *Literal;
	} Function;
	
	typedef struct Statements {
		struct Statement *Statement;
		struct Statements *Statements;
		Literal *Literal;
	} Statements;
	
	typedef struct Statement {
		struct Action *Action;
		struct Flagging *Flagging;
		Literal *Literal;
	} Statement;
	
	typedef struct Action {
		struct Subject *Subject;
		struct Predicates *Predicates;
		struct Permission *Permission;
		struct Condition *Condition;
		Literal *Literal;
	} Action;
	
	typedef struct Subject {
		struct Symbols *Symbols;
		Literal *Literal;
	} Subject;
	
	typedef struct Symbols {
		struct Symbol *Symbol;
		struct Symbols *Symbols;
		struct Catena *Catena;
		Literal *Literal;
	} Symbols;
	
	typedef struct Symbol {
		Name *Name;
		struct Article *Article;
		struct Type *Type;
		Literal *Literal;
	} Symbol;
	
	typedef struct Catena {
		Literal *Literal;
	} Catena;
	
	typedef struct Object {
		struct Symbol *Symbol;
		struct Reflexive *Reflexive;
		Literal *Literal;
	} Object;
	
	typedef struct Reflexive {
		Literal *Literal;
	} Reflexive;
	
	typedef struct Contract {
		struct This_Contract *This_Contract;
		struct All_Contracts *All_Contracts;
		Literal *Literal;
	} Contract;
	
	typedef struct Predicates {
		struct Predicates *Predicates;
		struct Predicate *Predicate;
		Literal *Literal;
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
		Literal *Literal;
	} Predicate;
	
	typedef struct Permission {
		Literal *Literal;
	} Permission;
	
	typedef struct Certification {
		struct Certify *Certify;
		struct Symbol *Symbol;
		struct Expression *Expression;
		struct Contract *Contract;
		Literal *Literal;
	} Certification;
	
	typedef struct Certify {
		Literal *Literal;
	} Certify;
	
	typedef struct Declaration {
		struct Declare *Declare;
		struct Symbol *Symbol;
		struct Expression *Expression;
		struct Contract *Contract;
		Literal *Literal;
	} Declaration;
	
	typedef struct Declare {
		Literal *Literal;
	} Declare;
	
	typedef struct Filing {
		struct File *File;
		struct Symbol *Symbol;
		struct Expression *Expression;
		struct Contract *Contract;
		Literal *Literal;
	} Filing;
	
	typedef struct File {
		Literal *Literal;
	} File;
	
	typedef struct Registration {
		struct Register *Register;
		struct Symbol *Symbol;
		struct Expression *Expression;
		struct Contract *Contract;
		Literal *Literal;
	} Registration;
	
	typedef struct Register {
		Literal *Literal;
	} Register;
	
	typedef struct Grantment {
		struct Grant *Grant;
		struct Symbol *Symbol;
		Literal *Literal;
	} Grantment;
	
	typedef struct Grant {
		Literal *Literal;
	} Grant;
	
	typedef struct Appointment {
		struct Appoint *Appoint;
		struct Symbol *Symbol;
		struct Expression *Expression;
		Literal *Literal;
	} Appointment;
	
	typedef struct Appoint {
		Literal *Literal;
	} Appoint;
	
	typedef struct Fixture {
		struct Fix *Fix;
		struct Symbol *Symbol;
		struct Expression *Expression;
		struct Contract *Contract;
		Literal *Literal;
	} Fixture;
	
	typedef struct Fix {
		Literal *Literal;
	} Fix;
	
	typedef struct Fixed {
		Literal *Literal;
	} Fixed;
	
	typedef struct Setting {
		struct Illocutor *Illocutor;
		struct Symbol *Symbol;
		Literal *Literal;
	} Setting;
	
	typedef struct Illocutor {
		struct Be *Be;
		Literal *Literal;
	} Illocutor;
	
	typedef struct Be {
		Literal *Literal;
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
		Literal *Literal;
	} Send;
	
	typedef struct Notification {
		struct Notify *Notify;
		struct Object *Object;
		struct Preposition *Preposition;
		struct Expression *Expression;
		Literal *Literal;
	} Notification;
	
	typedef struct Notify {
		Literal *Literal;
	} Notify;
	
	typedef struct Termination {
		struct Terminate *Terminate;
		struct This_Contract *This_Contract;
		struct All_Contracts *All_Contracts;
		Literal *Literal;
	} Termination;
	
	typedef struct Terminate {
		Literal *Literal;
	} Terminate;
	
	typedef struct Flagging {
		struct Illocutor *Illocutor;
		struct Symbol *Symbol;
		struct This_Contract *This_Contract;
		Literal *Literal;
	} Flagging;
	
	typedef struct Condition {
		struct If *If;
		struct Expression *Expression;
		Literal *Literal;
	} Condition;
	
	typedef struct If {
		Literal *Literal;
	} If;
	
	typedef struct Expression {
		struct Combination *Combination;
		Literal *Literal;
	} Expression;
	
	typedef struct Scalar_Comparison {
		struct Scalar_Expression *Scalar_Expression;
		struct Comparison_Operator *Comparison_Operator;
		struct Scalar_Expression *Scalar_Expression2;
		Literal *Literal;
	} Scalar_Comparison;
	
	typedef struct Comparison_Operator {
		struct Equal *Equal;
		struct Later *Later;
		Literal *Literal;
	} Comparison_Operator;
	
	typedef struct Equal {
		Literal *Literal;
	} Equal;
	
	typedef struct Later {
		Literal *Literal;
	} Later;
	
	typedef struct Scalar_Expression {
		struct Symbol *Symbol;
		Scalar *Scalar;
		struct Point_In_Time *Point_In_Time;
		Literal *Literal;
	} Scalar_Expression;
	
	typedef struct Combination {
		struct Combinor *Combinor;
		struct Combination *Combination;
		struct Combinator *Combinator;
		Literal *Literal;
	} Combination;
	
	typedef struct Combinor {
		struct Combinand *Combinand;
		struct Combinator *Combinator;
		struct Combinor *Combinor;
		Literal *Literal;
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
		Literal *Literal;
	} Combinand;
	
	typedef struct Combinator {
		struct Or_ *Or_;
		struct And *And;
		struct Neither *Neither;
		struct Nor *Nor;
		Literal *Literal;
	} Combinator;
	
	typedef struct Or_ {
		Literal *Literal;
	} Or_;
	
	typedef struct And {
		Literal *Literal;
	} And;
	
	typedef struct Neither {
		Literal *Literal;
	} Neither;
	
	typedef struct Nor {
		Literal *Literal;
	} Nor;
	
	typedef struct Existence {
		struct Symbol *Symbol;
		struct Equal *Equal;
		struct Fixed *Fixed;
		struct Be *Be;
		struct Contract *Contract;
		struct Being *Being;
		struct True *True;
		Literal *Literal;
	} Existence;
	
	typedef struct Negation {
		struct Negator *Negator;
		struct Symbol *Symbol;
		struct Fixed *Fixed;
		struct Contract *Contract;
		Literal *Literal;
	} Negation;
	
	typedef struct Negator {
		struct Be *Be;
		Literal *Literal;
	} Negator;
	
	typedef struct Being {
		Literal *Literal;
	} Being;
	
	typedef struct True {
		Literal *Literal;
	} True;
	
	typedef struct Article {
		Literal *Literal;
	} Article;
	
	typedef struct Point_In_Time {
		struct Current_Time *Current_Time;
		struct Relative_Time *Relative_Time;
		Literal *Literal;
	} Point_In_Time;
	
	typedef struct Current_Time {
		Literal *Literal;
	} Current_Time;
	
	typedef struct Relative_Time {
		struct Duration *Duration;
		struct Symbol *Symbol;
		Literal *Literal;
	} Relative_Time;
	
	typedef struct Duration {
		struct Scalar_Expression *Scalar_Expression;
		struct Time_Unit *Time_Unit;
		Literal *Literal;
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
		Literal *Literal;
	} Time_Unit;
	
	typedef struct Years {
		Literal *Literal;
	} Years;
	
	typedef struct Months {
		Literal *Literal;
	} Months;
	
	typedef struct Weeks {
		Literal *Literal;
	} Weeks;
	
	typedef struct Days {
		Literal *Literal;
	} Days;
	
	typedef struct Hours {
		Literal *Literal;
	} Hours;
	
	typedef struct Minutes {
		Literal *Literal;
	} Minutes;
	
	typedef struct Seconds {
		Literal *Literal;
	} Seconds;
	
	typedef struct Milliseconds {
		Literal *Literal;
	} Milliseconds;
	
	typedef struct Expiration {
		Literal *Literal;
	} Expiration;
	
	/*T*/	extern struct Document *root;
	bool core_document(char **production, Document *root, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);

  #define replace(orig_, rep_, with_) _replace(orig_, rep_, with_, true, null, null, #orig_, __FILE__, __LINE__)
  char *_replace(char **orig, const char *rep, const char *with, int all, char *from, int *times, char *origname, char *file, int line);
  char *quote_trimmed(const char *token);
  char *dash_spaced(const char *token);
  char *snake_spaced(const char *token);
  char *LOW(const char *token);
  char *UP(const char *token);
  extern char *opt_color;
  extern char *opt_highlight;
  extern char *opt_symbols;
  extern char *opt_values;
  extern char *opt_subvalues;

	bool core_walk(char **production) {
		if(!root) return false;
		return core_document(production, root, 0, true, false, false, false);
	}

	bool core_name(char **production, Name *Name, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Name) return false;
		///// padcat(0, 0, production, "\"", Name, "\"");
		padcat(0, 0, production, "«", opt_symbols?opt_symbols:"", LOW(dash_spaced(quote_trimmed(Name))), opt_symbols?"\033[0m":"", "» ");
		return true;
	}

	bool core_description(char **production, Description *Description, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Description) return false;
		padcat(0, 0, production, "\"", Description, "\"");
		return true;
	}

	bool core_scalar(char **production, Scalar *Scalar, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Scalar) return false;
		///// padcat(0, 0, production, "\"", Scalar, "\"");
		padcat(0, 0, production, Scalar, " ");
		return true;
	}

	bool core_hex(char **production, Hex *Hex, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Hex) return false;
		///// padcat(0, 0, production, "\"", Hex, "\"");
		padcat(0, 0, production, Hex, " ");
		return true;
	}

/* AST walk (stub) functions */

	bool core_document(char **production, Document *Document, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_head(char **production, Head *Head, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_lex(char **production, Lex *Lex, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_lexon(char **production, Lexon *Lexon, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_authors(char **production, Authors *Authors, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_comment(char **production, Comment *Comment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_preamble(char **production, Preamble *Preamble, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_terms(char **production, Terms *Terms, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_covenants(char **production, Covenants *Covenants, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_covenant(char **production, Covenant *Covenant, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_provisions(char **production, Provisions *Provisions, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_definitions(char **production, Definitions *Definitions, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_definition(char **production, Definition *Definition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_type_term(char **production, Type_Term *Type_Term, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_type(char **production, Type *Type, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_person(char **production, Person *Person, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_amount(char **production, Amount *Amount, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_time(char **production, Time *Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_binary(char **production, Binary *Binary, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_text(char **production, Text *Text, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_data(char **production, Data *Data, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_this_contract(char **production, This_Contract *This_Contract, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_all_contracts(char **production, All_Contracts *All_Contracts, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_this(char **production, This *This, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_clauses(char **production, Clauses *Clauses, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_clause(char **production, Clause *Clause, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_body(char **production, Body *Body, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_function(char **production, Function *Function, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_statements(char **production, Statements *Statements, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_statement(char **production, Statement *Statement, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_action(char **production, Action *Action, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_subject(char **production, Subject *Subject, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_symbols(char **production, Symbols *Symbols, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_symbol(char **production, Symbol *Symbol, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_catena(char **production, Catena *Catena, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_object(char **production, Object *Object, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_reflexive(char **production, Reflexive *Reflexive, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_contract(char **production, Contract *Contract, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_predicates(char **production, Predicates *Predicates, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_predicate(char **production, Predicate *Predicate, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_permission(char **production, Permission *Permission, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_certification(char **production, Certification *Certification, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_certify(char **production, Certify *Certify, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_declaration(char **production, Declaration *Declaration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_declare(char **production, Declare *Declare, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_filing(char **production, Filing *Filing, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_file(char **production, File *File, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_registration(char **production, Registration *Registration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_register(char **production, Register *Register, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_grantment(char **production, Grantment *Grantment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_grant(char **production, Grant *Grant, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_appointment(char **production, Appointment *Appointment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_appoint(char **production, Appoint *Appoint, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_fixture(char **production, Fixture *Fixture, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_fix(char **production, Fix *Fix, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_fixed(char **production, Fixed *Fixed, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_setting(char **production, Setting *Setting, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_illocutor(char **production, Illocutor *Illocutor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_be(char **production, Be *Be, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_payment(char **production, Payment *Payment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_pay(char **production, Pay *Pay, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_preposition(char **production, Preposition *Preposition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_escrow(char **production, Escrow *Escrow, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_from_escrow(char **production, From_Escrow *From_Escrow, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_sending(char **production, Sending *Sending, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_send(char **production, Send *Send, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_notification(char **production, Notification *Notification, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_notify(char **production, Notify *Notify, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_termination(char **production, Termination *Termination, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_terminate(char **production, Terminate *Terminate, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_flagging(char **production, Flagging *Flagging, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_condition(char **production, Condition *Condition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_if(char **production, If *If, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_expression(char **production, Expression *Expression, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_scalar_comparison(char **production, Scalar_Comparison *Scalar_Comparison, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_comparison_operator(char **production, Comparison_Operator *Comparison_Operator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_equal(char **production, Equal *Equal, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_later(char **production, Later *Later, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_scalar_expression(char **production, Scalar_Expression *Scalar_Expression, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_combination(char **production, Combination *Combination, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_combinor(char **production, Combinor *Combinor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_combinand(char **production, Combinand *Combinand, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_combinator(char **production, Combinator *Combinator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_or_(char **production, Or_ *Or_, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_and(char **production, And *And, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_neither(char **production, Neither *Neither, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_nor(char **production, Nor *Nor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_existence(char **production, Existence *Existence, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_negation(char **production, Negation *Negation, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_negator(char **production, Negator *Negator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_being(char **production, Being *Being, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_true(char **production, True *True, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_article(char **production, Article *Article, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_point_in_time(char **production, Point_In_Time *Point_In_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_current_time(char **production, Current_Time *Current_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_relative_time(char **production, Relative_Time *Relative_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_duration(char **production, Duration *Duration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_time_unit(char **production, Time_Unit *Time_Unit, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_years(char **production, Years *Years, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_months(char **production, Months *Months, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_weeks(char **production, Weeks *Weeks, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_days(char **production, Days *Days, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_hours(char **production, Hours *Hours, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_minutes(char **production, Minutes *Minutes, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_seconds(char **production, Seconds *Seconds, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_milliseconds(char **production, Milliseconds *Milliseconds, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
	bool core_expiration(char **production, Expiration *Expiration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight);
/* AST walk (stub) functions */

	bool core_document(char **production, Document *Document, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Document) return false;
		if(opt_debug) printf("producing Document\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "document")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Document->Head?1:0) + (!!Document->Terms?1:0) + (!!Document->Covenants?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(0, indent, production, "   ", color, "document", off, " ");
		} else {
			padcat(0, indent, production, opening_bracket, " ", color, "document", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Document->Terms || Document->Covenants);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_head(production, Document->Head, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "document"), opt_subvalues && !!strstr(opt_subvalues, "document"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Document->Covenants);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_terms(production, Document->Terms, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "document"), opt_subvalues && !!strstr(opt_subvalues, "document"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_covenants(production, Document->Covenants, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "document"), opt_subvalues && !!strstr(opt_subvalues, "document"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, "\n");
		bracket_just_closed=true;

		return true;
	}

	bool core_head(char **production, Head *Head, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Head) return false;
		if(opt_debug) printf("producing Head\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "head")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Head->Lex?1:0) + (!!Head->Preamble?1:0) + (!!Head->Comment?1:0) + (!!Head->Authors?1:0) + (!!Head->Lexon?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "head", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "head", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Head->Preamble || Head->Comment || Head->Authors || Head->Lexon);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_lex(production, Head->Lex, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "head"), opt_subvalues && !!strstr(opt_subvalues, "head"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Head->Comment || Head->Authors || Head->Lexon);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_preamble(production, Head->Preamble, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "head"), opt_subvalues && !!strstr(opt_subvalues, "head"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Head->Authors || Head->Lexon);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_comment(production, Head->Comment, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "head"), opt_subvalues && !!strstr(opt_subvalues, "head"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Head->Lexon);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_authors(production, Head->Authors, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "head"), opt_subvalues && !!strstr(opt_subvalues, "head"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_lexon(production, Head->Lexon, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "head"), opt_subvalues && !!strstr(opt_subvalues, "head"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_lex(char **production, Lex *Lex, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Lex) return false;
		if(opt_debug) printf("producing Lex %s\n", Lex->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "lex")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Lex->Name?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "lex", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "lex", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Lex->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "lex"), opt_subvalues && !!strstr(opt_subvalues, "lex"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_lexon(char **production, Lexon *Lexon, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Lexon) return false;
		if(opt_debug) printf("producing Lexon %s\n", Lexon->Description);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "lexon")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Lexon->Description?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "lexon", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "lexon", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_description(production, Lexon->Description, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "lexon"), opt_subvalues && !!strstr(opt_subvalues, "lexon"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_authors(char **production, Authors *Authors, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Authors) return false;
		if(opt_debug) printf("producing Authors %s\n", Authors->Description);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "authors")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Authors->Description?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "authors", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "authors", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_description(production, Authors->Description, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "authors"), opt_subvalues && !!strstr(opt_subvalues, "authors"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_comment(char **production, Comment *Comment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Comment) return false;
		if(opt_debug) printf("producing Comment %s\n", Comment->Description);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "comment")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Comment->Description?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "comment", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "comment", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_description(production, Comment->Description, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "comment"), opt_subvalues && !!strstr(opt_subvalues, "comment"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_preamble(char **production, Preamble *Preamble, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Preamble) return false;
		if(opt_debug) printf("producing Preamble %s\n", Preamble->Description);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "preamble")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Preamble->Description?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "preamble", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "preamble", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_description(production, Preamble->Description, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "preamble"), opt_subvalues && !!strstr(opt_subvalues, "preamble"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_terms(char **production, Terms *Terms, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Terms) return false;
		if(opt_debug) printf("producing Terms\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "terms")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Terms->Provisions?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "terms", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "terms", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_provisions(production, Terms->Provisions, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "terms"), opt_subvalues && !!strstr(opt_subvalues, "terms"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_covenants(char **production, Covenants *Covenants, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Covenants) return false;
		if(opt_debug) printf("producing Covenants\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "covenants")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = !!Covenants->Covenants;
		bool skipped = (!opt_produce_tree || opt_produce_flat) && !!Covenants->Covenants;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Covenants->Covenant?1:0) + (!!Covenants->Covenants?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "covenants", off, " ");
		} else {
			if(!has_more_recursion && !terse) {
				padcat(1, indent, production, opening_bracket, " ", color, "covenants", off, " ");
				sameline = false;
				bracket_just_closed = false;
				sameline = false;
			} else
				sameline = true;
		}
		bool sibbling_follows;
		if(!opt_produce_flat) grid <<= 1;
		int irx = !terse ? 1 : 0;
		sibbling_follows = !!(Covenants->Covenant);
		if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows; if(line) grid |= 1; }
		irx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_covenants(production, Covenants->Covenants, indent+irx, false, sibbling_follows && skipped|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "covenants"), opt_subvalues && !!strstr(opt_subvalues, "covenants"));
		subhighlight = false;
		if(opt_produce_flat) grid <<= !terse ? 1 : 0;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_covenant(production, Covenants->Covenant, indent+irx, true, sibbling_follows && skipped, subhighlight || opt_values && !!strstr(opt_values, "covenants"), opt_subvalues && !!strstr(opt_subvalues, "covenants"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		if(topcall) {
			padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
			bracket_just_closed=true;
		}

		return true;
	}

	bool core_covenant(char **production, Covenant *Covenant, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Covenant) return false;
		if(opt_debug) printf("producing Covenant %s\n", Covenant->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "covenant")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Covenant->Name?1:0) + (!!Covenant->Provisions?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "covenant", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "covenant", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Covenant->Provisions);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Covenant->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "covenant"), opt_subvalues && !!strstr(opt_subvalues, "covenant"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_provisions(production, Covenant->Provisions, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "covenant"), opt_subvalues && !!strstr(opt_subvalues, "covenant"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_provisions(char **production, Provisions *Provisions, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Provisions) return false;
		if(opt_debug) printf("producing Provisions\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "provisions")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Provisions->Definitions?1:0) + (!!Provisions->Clauses?1:0) + (!!Provisions->Statements?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "provisions", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "provisions", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Provisions->Clauses || Provisions->Statements);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_definitions(production, Provisions->Definitions, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "provisions"), opt_subvalues && !!strstr(opt_subvalues, "provisions"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Provisions->Statements);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_clauses(production, Provisions->Clauses, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "provisions"), opt_subvalues && !!strstr(opt_subvalues, "provisions"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_statements(production, Provisions->Statements, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "provisions"), opt_subvalues && !!strstr(opt_subvalues, "provisions"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_definitions(char **production, Definitions *Definitions, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Definitions) return false;
		if(opt_debug) printf("producing Definitions\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "definitions")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = !!Definitions->Definitions;
		bool skipped = (!opt_produce_tree || opt_produce_flat) && !!Definitions->Definitions;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Definitions->Definition?1:0) + (!!Definitions->Definitions?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "definitions", off, " ");
		} else {
			if(!has_more_recursion && !terse) {
				padcat(1, indent, production, opening_bracket, " ", color, "definitions", off, " ");
				sameline = false;
				bracket_just_closed = false;
				sameline = false;
			} else
				sameline = true;
		}
		bool sibbling_follows;
		if(!opt_produce_flat) grid <<= 1;
		int irx = !terse ? 1 : 0;
		sibbling_follows = !!(Definitions->Definition);
		if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows; if(line) grid |= 1; }
		irx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_definitions(production, Definitions->Definitions, indent+irx, false, sibbling_follows && skipped|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "definitions"), opt_subvalues && !!strstr(opt_subvalues, "definitions"));
		subhighlight = false;
		if(opt_produce_flat) grid <<= !terse ? 1 : 0;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_definition(production, Definitions->Definition, indent+irx, true, sibbling_follows && skipped, subhighlight || opt_values && !!strstr(opt_values, "definitions"), opt_subvalues && !!strstr(opt_subvalues, "definitions"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		if(topcall) {
			padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
			bracket_just_closed=true;
		}

		return true;
	}

	bool core_definition(char **production, Definition *Definition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Definition) return false;
		if(opt_debug) printf("producing Definition %s\n", Definition->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "definition")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Definition->Name?1:0) + (!!Definition->Type_Term?1:0) + (!!Definition->Article?1:0) + (!!Definition->This_Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "definition", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "definition", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Definition->Type_Term || Definition->Article || Definition->This_Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Definition->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "definition"), opt_subvalues && !!strstr(opt_subvalues, "definition"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Definition->Article || Definition->This_Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_type_term(production, Definition->Type_Term, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "definition"), opt_subvalues && !!strstr(opt_subvalues, "definition"));
		subhighlight = false;
		if(opt_produce_tree) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Definition->This_Contract);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_article(production, Definition->Article, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "definition"), opt_subvalues && !!strstr(opt_subvalues, "definition"));
			subhighlight = false;
		}
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_this_contract(production, Definition->This_Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "definition"), opt_subvalues && !!strstr(opt_subvalues, "definition"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_type_term(char **production, Type_Term *Type_Term, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Type_Term) return false;
		if(opt_debug) printf("producing Type_Term\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "type-term")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Type_Term->Type?1:0) + (!!Type_Term->Article?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "type-term", off, " ");
		} else {
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type_Term->Article);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_type(production, Type_Term->Type, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type_term"), opt_subvalues && !!strstr(opt_subvalues, "type_term"));
		subhighlight = false;
		if(opt_produce_tree) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_article(production, Type_Term->Article, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type_term"), opt_subvalues && !!strstr(opt_subvalues, "type_term"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_type(char **production, Type *Type, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Type) return false;
		if(opt_debug) printf("producing Type\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "type")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Type->Person?1:0) + (!!Type->Amount?1:0) + (!!Type->Time?1:0) + (!!Type->Binary?1:0) + (!!Type->Text?1:0) + (!!Type->Data?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "type", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, opening_bracket, " ", color, "type", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type->Amount || Type->Time || Type->Binary || Type->Text || Type->Data);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_person(production, Type->Person, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type->Time || Type->Binary || Type->Text || Type->Data);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_amount(production, Type->Amount, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type->Binary || Type->Text || Type->Data);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_time(production, Type->Time, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type->Text || Type->Data);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_binary(production, Type->Binary, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Type->Data);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_text(production, Type->Text, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_data(production, Type->Data, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "type"), opt_subvalues && !!strstr(opt_subvalues, "type"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_person(char **production, Person *Person, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Person) return false;
		if(opt_debug) printf("producing Person\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "person")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "person", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "person", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_amount(char **production, Amount *Amount, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Amount) return false;
		if(opt_debug) printf("producing Amount\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "amount")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "amount", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "amount", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_time(char **production, Time *Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Time) return false;
		if(opt_debug) printf("producing Time\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "time")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "time", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "time", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_binary(char **production, Binary *Binary, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Binary) return false;
		if(opt_debug) printf("producing Binary\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "binary")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "binary", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "binary", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_text(char **production, Text *Text, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Text) return false;
		if(opt_debug) printf("producing Text\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "text")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "text", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "text", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_data(char **production, Data *Data, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Data) return false;
		if(opt_debug) printf("producing Data\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "data")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "data", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "data", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_this_contract(char **production, This_Contract *This_Contract, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!This_Contract) return false;
		if(opt_debug) printf("producing This_Contract %s\n", This_Contract->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "this-contract")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!This_Contract->This?1:0) + (!!This_Contract->Name?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "this-contract", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "this-contract", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(opt_produce_tree) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(This_Contract->Name);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_this(production, This_Contract->This, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "this_contract"), opt_subvalues && !!strstr(opt_subvalues, "this_contract"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, This_Contract->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "this_contract"), opt_subvalues && !!strstr(opt_subvalues, "this_contract"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_all_contracts(char **production, All_Contracts *All_Contracts, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!All_Contracts) return false;
		if(opt_debug) printf("producing All_Contracts\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "all-contracts")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "all-contracts", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "all-contracts", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_this(char **production, This *This, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!This) return false;
		if(opt_debug) printf("producing This\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "this")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "this", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "this", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_clauses(char **production, Clauses *Clauses, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Clauses) return false;
		if(opt_debug) printf("producing Clauses\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "clauses")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = !!Clauses->Clauses;
		bool skipped = (!opt_produce_tree || opt_produce_flat) && !!Clauses->Clauses;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Clauses->Clause?1:0) + (!!Clauses->Clauses?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "clauses", off, " ");
		} else {
			if(!has_more_recursion && !terse) {
				padcat(1, indent, production, opening_bracket, " ", color, "clauses", off, " ");
				sameline = false;
				bracket_just_closed = false;
				sameline = false;
			} else
				sameline = true;
		}
		bool sibbling_follows;
		if(!opt_produce_flat) grid <<= 1;
		int irx = !terse ? 1 : 0;
		sibbling_follows = !!(Clauses->Clause);
		if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows; if(line) grid |= 1; }
		irx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_clauses(production, Clauses->Clauses, indent+irx, false, sibbling_follows && skipped|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "clauses"), opt_subvalues && !!strstr(opt_subvalues, "clauses"));
		subhighlight = false;
		if(opt_produce_flat) grid <<= !terse ? 1 : 0;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_clause(production, Clauses->Clause, indent+irx, true, sibbling_follows && skipped, subhighlight || opt_values && !!strstr(opt_values, "clauses"), opt_subvalues && !!strstr(opt_subvalues, "clauses"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		if(topcall) {
			padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
			bracket_just_closed=true;
		}

		return true;
	}

	bool core_clause(char **production, Clause *Clause, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Clause) return false;
		if(opt_debug) printf("producing Clause %s\n", Clause->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "clause")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Clause->Name?1:0) + (!!Clause->Body?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "clause", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "clause", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Clause->Body);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Clause->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "clause"), opt_subvalues && !!strstr(opt_subvalues, "clause"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_body(production, Clause->Body, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "clause"), opt_subvalues && !!strstr(opt_subvalues, "clause"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_body(char **production, Body *Body, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Body) return false;
		if(opt_debug) printf("producing Body\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "body")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Body->Statements?1:0) + (!!Body->Function?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "body", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "body", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Body->Function);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_statements(production, Body->Statements, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "body"), opt_subvalues && !!strstr(opt_subvalues, "body"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_function(production, Body->Function, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "body"), opt_subvalues && !!strstr(opt_subvalues, "body"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_function(char **production, Function *Function, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Function) return false;
		if(opt_debug) printf("producing Function %s\n", Function->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "function")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Function->Name?1:0) + (!!Function->Illocutor?1:0) + (!!Function->Expression?1:0) + (!!Function->Article?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "function", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "function", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Function->Illocutor || Function->Expression || Function->Article);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Function->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "function"), opt_subvalues && !!strstr(opt_subvalues, "function"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Function->Expression || Function->Article);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_illocutor(production, Function->Illocutor, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "function"), opt_subvalues && !!strstr(opt_subvalues, "function"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Function->Article);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Function->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "function"), opt_subvalues && !!strstr(opt_subvalues, "function"));
		subhighlight = false;
		if(opt_produce_tree) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_article(production, Function->Article, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "function"), opt_subvalues && !!strstr(opt_subvalues, "function"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_statements(char **production, Statements *Statements, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Statements) return false;
		if(opt_debug) printf("producing Statements\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "statements")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = !!Statements->Statements;
		bool skipped = (!opt_produce_tree || opt_produce_flat) && !!Statements->Statements;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Statements->Statement?1:0) + (!!Statements->Statements?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "statements", off, " ");
		} else {
			if(!has_more_recursion && !terse) {
				padcat(1, indent, production, opening_bracket, " ", color, "statements", off, " ");
				sameline = false;
				bracket_just_closed = false;
				sameline = false;
			} else
				sameline = true;
		}
		bool sibbling_follows;
		if(!opt_produce_flat) grid <<= 1;
		int irx = !terse ? 1 : 0;
		sibbling_follows = !!(Statements->Statement);
		if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows; if(line) grid |= 1; }
		irx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_statements(production, Statements->Statements, indent+irx, false, sibbling_follows && skipped|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "statements"), opt_subvalues && !!strstr(opt_subvalues, "statements"));
		subhighlight = false;
		if(opt_produce_flat) grid <<= !terse ? 1 : 0;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_statement(production, Statements->Statement, indent+irx, true, sibbling_follows && skipped, subhighlight || opt_values && !!strstr(opt_values, "statements"), opt_subvalues && !!strstr(opt_subvalues, "statements"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		if(topcall) {
			padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
			bracket_just_closed=true;
		}

		return true;
	}

	bool core_statement(char **production, Statement *Statement, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Statement) return false;
		if(opt_debug) printf("producing Statement\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "statement")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Statement->Action?1:0) + (!!Statement->Flagging?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "statement", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "statement", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Statement->Flagging);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_action(production, Statement->Action, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "statement"), opt_subvalues && !!strstr(opt_subvalues, "statement"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_flagging(production, Statement->Flagging, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "statement"), opt_subvalues && !!strstr(opt_subvalues, "statement"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_action(char **production, Action *Action, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Action) return false;
		if(opt_debug) printf("producing Action\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "action")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Action->Subject?1:0) + (!!Action->Predicates?1:0) + (!!Action->Permission?1:0) + (!!Action->Condition?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "action", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "action", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Action->Predicates || Action->Permission || Action->Condition);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_subject(production, Action->Subject, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "action"), opt_subvalues && !!strstr(opt_subvalues, "action"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Action->Permission || Action->Condition);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_predicates(production, Action->Predicates, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "action"), opt_subvalues && !!strstr(opt_subvalues, "action"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Action->Condition);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_permission(production, Action->Permission, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "action"), opt_subvalues && !!strstr(opt_subvalues, "action"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_condition(production, Action->Condition, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "action"), opt_subvalues && !!strstr(opt_subvalues, "action"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_subject(char **production, Subject *Subject, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Subject) return false;
		if(opt_debug) printf("producing Subject\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "subject")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Subject->Symbols?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "subject", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "subject", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbols(production, Subject->Symbols, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "subject"), opt_subvalues && !!strstr(opt_subvalues, "subject"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_symbols(char **production, Symbols *Symbols, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Symbols) return false;
		if(opt_debug) printf("producing Symbols\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "symbols")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Symbols->Symbol?1:0) + (!!Symbols->Symbols?1:0) + (!!Symbols->Catena?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "symbols", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "symbols", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Symbols->Symbol || Symbols->Catena);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbols(production, Symbols->Symbols, indent+irx, false, false|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "symbols"), opt_subvalues && !!strstr(opt_subvalues, "symbols"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Symbols->Catena);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Symbols->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "symbols"), opt_subvalues && !!strstr(opt_subvalues, "symbols"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_catena(production, Symbols->Catena, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "symbols"), opt_subvalues && !!strstr(opt_subvalues, "symbols"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_symbol(char **production, Symbol *Symbol, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Symbol) return false;
		if(opt_debug) printf("producing Symbol %s\n", Symbol->Name);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "symbol")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Symbol->Name?1:0) + (!!Symbol->Article?1:0) + (!!Symbol->Type?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "symbol", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, opening_bracket, " ", color, "symbol", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Symbol->Article || Symbol->Type);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_name(production, Symbol->Name, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "symbol"), opt_subvalues && !!strstr(opt_subvalues, "symbol"));
		subhighlight = false;
		if(opt_produce_tree) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Symbol->Type);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_article(production, Symbol->Article, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "symbol"), opt_subvalues && !!strstr(opt_subvalues, "symbol"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_type(production, Symbol->Type, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "symbol"), opt_subvalues && !!strstr(opt_subvalues, "symbol"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_catena(char **production, Catena *Catena, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Catena) return false;
		if(opt_debug) printf("producing Catena\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "catena")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "catena", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "catena", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_object(char **production, Object *Object, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Object) return false;
		if(opt_debug) printf("producing Object\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "object")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Object->Symbol?1:0) + (!!Object->Reflexive?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "object", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "object", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Object->Reflexive);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Object->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "object"), opt_subvalues && !!strstr(opt_subvalues, "object"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_reflexive(production, Object->Reflexive, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "object"), opt_subvalues && !!strstr(opt_subvalues, "object"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_reflexive(char **production, Reflexive *Reflexive, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Reflexive) return false;
		if(opt_debug) printf("producing Reflexive\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "reflexive")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "reflexive", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "reflexive", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_contract(char **production, Contract *Contract, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Contract) return false;
		if(opt_debug) printf("producing Contract\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "contract")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Contract->This_Contract?1:0) + (!!Contract->All_Contracts?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "contract", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "contract", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Contract->All_Contracts);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_this_contract(production, Contract->This_Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "contract"), opt_subvalues && !!strstr(opt_subvalues, "contract"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_all_contracts(production, Contract->All_Contracts, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "contract"), opt_subvalues && !!strstr(opt_subvalues, "contract"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_predicates(char **production, Predicates *Predicates, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Predicates) return false;
		if(opt_debug) printf("producing Predicates\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "predicates")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = !!Predicates->Predicates;
		bool skipped = (!opt_produce_tree || opt_produce_flat) && !!Predicates->Predicates;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Predicates->Predicates?1:0) + (!!Predicates->Predicate?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "predicates", off, " ");
		} else {
			if(!has_more_recursion && !terse) {
				padcat(1, indent, production, opening_bracket, " ", color, "predicates", off, " ");
				sameline = false;
				bracket_just_closed = false;
				sameline = false;
			} else
				sameline = true;
		}
		bool sibbling_follows;
		if(!opt_produce_flat) grid <<= 1;
		int irx = !terse ? 1 : 0;
		sibbling_follows = !!(Predicates->Predicate);
		if(opt_produce_tree) { bool line = !opt_produce_flat && sibbling_follows; if(line) grid |= 1; }
		irx = (opt_produce_tree && !opt_produce_flat) || (!has_more_recursion && !sameline) ? 1 : 0;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_predicates(production, Predicates->Predicates, indent+irx, false, sibbling_follows && skipped|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "predicates"), opt_subvalues && !!strstr(opt_subvalues, "predicates"));
		subhighlight = false;
		if(opt_produce_flat) grid <<= !terse ? 1 : 0;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_predicate(production, Predicates->Predicate, indent+irx, true, sibbling_follows && skipped, subhighlight || opt_values && !!strstr(opt_values, "predicates"), opt_subvalues && !!strstr(opt_subvalues, "predicates"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		if(topcall) {
			padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
			bracket_just_closed=true;
		}

		return true;
	}

	bool core_predicate(char **production, Predicate *Predicate, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Predicate) return false;
		if(opt_debug) printf("producing Predicate\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "predicate")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Predicate->Certification?1:0) + (!!Predicate->Declaration?1:0) + (!!Predicate->Filing?1:0) + (!!Predicate->Registration?1:0) + (!!Predicate->Grantment?1:0) + (!!Predicate->Appointment?1:0) + (!!Predicate->Fixture?1:0) + (!!Predicate->Setting?1:0) + (!!Predicate->Payment?1:0) + (!!Predicate->Sending?1:0) + (!!Predicate->Notification?1:0) + (!!Predicate->Termination?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "predicate", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "predicate", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Declaration || Predicate->Filing || Predicate->Registration || Predicate->Grantment || Predicate->Appointment || Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_certification(production, Predicate->Certification, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Filing || Predicate->Registration || Predicate->Grantment || Predicate->Appointment || Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_declaration(production, Predicate->Declaration, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Registration || Predicate->Grantment || Predicate->Appointment || Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_filing(production, Predicate->Filing, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Grantment || Predicate->Appointment || Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_registration(production, Predicate->Registration, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Appointment || Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_grantment(production, Predicate->Grantment, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Fixture || Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_appointment(production, Predicate->Appointment, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Setting || Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_fixture(production, Predicate->Fixture, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Payment || Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_setting(production, Predicate->Setting, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Sending || Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_payment(production, Predicate->Payment, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Notification || Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_sending(production, Predicate->Sending, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Predicate->Termination);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_notification(production, Predicate->Notification, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_termination(production, Predicate->Termination, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "predicate"), opt_subvalues && !!strstr(opt_subvalues, "predicate"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_permission(char **production, Permission *Permission, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Permission) return false;
		if(opt_debug) printf("producing Permission\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "permission")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "permission", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "permission", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_certification(char **production, Certification *Certification, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Certification) return false;
		if(opt_debug) printf("producing Certification\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "certification")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Certification->Certify?1:0) + (!!Certification->Symbol?1:0) + (!!Certification->Expression?1:0) + (!!Certification->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "certification", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "certification", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Certification->Symbol || Certification->Expression || Certification->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_certify(production, Certification->Certify, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "certification"), opt_subvalues && !!strstr(opt_subvalues, "certification"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Certification->Expression || Certification->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Certification->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "certification"), opt_subvalues && !!strstr(opt_subvalues, "certification"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Certification->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Certification->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "certification"), opt_subvalues && !!strstr(opt_subvalues, "certification"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Certification->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "certification"), opt_subvalues && !!strstr(opt_subvalues, "certification"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_certify(char **production, Certify *Certify, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Certify) return false;
		if(opt_debug) printf("producing Certify\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "certify")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "certify", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "certify", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_declaration(char **production, Declaration *Declaration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Declaration) return false;
		if(opt_debug) printf("producing Declaration\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "declaration")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Declaration->Declare?1:0) + (!!Declaration->Symbol?1:0) + (!!Declaration->Expression?1:0) + (!!Declaration->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "declaration", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "declaration", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Declaration->Symbol || Declaration->Expression || Declaration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_declare(production, Declaration->Declare, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "declaration"), opt_subvalues && !!strstr(opt_subvalues, "declaration"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Declaration->Expression || Declaration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Declaration->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "declaration"), opt_subvalues && !!strstr(opt_subvalues, "declaration"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Declaration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Declaration->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "declaration"), opt_subvalues && !!strstr(opt_subvalues, "declaration"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Declaration->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "declaration"), opt_subvalues && !!strstr(opt_subvalues, "declaration"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_declare(char **production, Declare *Declare, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Declare) return false;
		if(opt_debug) printf("producing Declare\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "declare")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "declare", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "declare", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_filing(char **production, Filing *Filing, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Filing) return false;
		if(opt_debug) printf("producing Filing\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "filing")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Filing->File?1:0) + (!!Filing->Symbol?1:0) + (!!Filing->Expression?1:0) + (!!Filing->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "filing", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "filing", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Filing->Symbol || Filing->Expression || Filing->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_file(production, Filing->File, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "filing"), opt_subvalues && !!strstr(opt_subvalues, "filing"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Filing->Expression || Filing->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Filing->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "filing"), opt_subvalues && !!strstr(opt_subvalues, "filing"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Filing->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Filing->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "filing"), opt_subvalues && !!strstr(opt_subvalues, "filing"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Filing->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "filing"), opt_subvalues && !!strstr(opt_subvalues, "filing"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_file(char **production, File *File, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!File) return false;
		if(opt_debug) printf("producing File\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "file")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "file", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "file", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_registration(char **production, Registration *Registration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Registration) return false;
		if(opt_debug) printf("producing Registration\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "registration")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Registration->Register?1:0) + (!!Registration->Symbol?1:0) + (!!Registration->Expression?1:0) + (!!Registration->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "registration", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "registration", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Registration->Symbol || Registration->Expression || Registration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_register(production, Registration->Register, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "registration"), opt_subvalues && !!strstr(opt_subvalues, "registration"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Registration->Expression || Registration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Registration->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "registration"), opt_subvalues && !!strstr(opt_subvalues, "registration"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Registration->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Registration->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "registration"), opt_subvalues && !!strstr(opt_subvalues, "registration"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Registration->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "registration"), opt_subvalues && !!strstr(opt_subvalues, "registration"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_register(char **production, Register *Register, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Register) return false;
		if(opt_debug) printf("producing Register\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "register")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "register", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "register", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_grantment(char **production, Grantment *Grantment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Grantment) return false;
		if(opt_debug) printf("producing Grantment\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "grantment")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Grantment->Grant?1:0) + (!!Grantment->Symbol?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "grantment", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "grantment", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Grantment->Symbol);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_grant(production, Grantment->Grant, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "grantment"), opt_subvalues && !!strstr(opt_subvalues, "grantment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Grantment->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "grantment"), opt_subvalues && !!strstr(opt_subvalues, "grantment"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_grant(char **production, Grant *Grant, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Grant) return false;
		if(opt_debug) printf("producing Grant\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "grant")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "grant", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "grant", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_appointment(char **production, Appointment *Appointment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Appointment) return false;
		if(opt_debug) printf("producing Appointment\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "appointment")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Appointment->Appoint?1:0) + (!!Appointment->Symbol?1:0) + (!!Appointment->Expression?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "appointment", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "appointment", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Appointment->Symbol || Appointment->Expression);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_appoint(production, Appointment->Appoint, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "appointment"), opt_subvalues && !!strstr(opt_subvalues, "appointment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Appointment->Expression);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Appointment->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "appointment"), opt_subvalues && !!strstr(opt_subvalues, "appointment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Appointment->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "appointment"), opt_subvalues && !!strstr(opt_subvalues, "appointment"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_appoint(char **production, Appoint *Appoint, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Appoint) return false;
		if(opt_debug) printf("producing Appoint\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "appoint")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "appoint", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "appoint", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_fixture(char **production, Fixture *Fixture, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Fixture) return false;
		if(opt_debug) printf("producing Fixture\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "fixture")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Fixture->Fix?1:0) + (!!Fixture->Symbol?1:0) + (!!Fixture->Expression?1:0) + (!!Fixture->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "fixture", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "fixture", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Fixture->Symbol || Fixture->Expression || Fixture->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_fix(production, Fixture->Fix, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "fixture"), opt_subvalues && !!strstr(opt_subvalues, "fixture"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Fixture->Expression || Fixture->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Fixture->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "fixture"), opt_subvalues && !!strstr(opt_subvalues, "fixture"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Fixture->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Fixture->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "fixture"), opt_subvalues && !!strstr(opt_subvalues, "fixture"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Fixture->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "fixture"), opt_subvalues && !!strstr(opt_subvalues, "fixture"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_fix(char **production, Fix *Fix, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Fix) return false;
		if(opt_debug) printf("producing Fix\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "fix")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "fix", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "fix", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_fixed(char **production, Fixed *Fixed, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Fixed) return false;
		if(opt_debug) printf("producing Fixed\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "fixed")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "fixed", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "fixed", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_setting(char **production, Setting *Setting, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Setting) return false;
		if(opt_debug) printf("producing Setting\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "setting")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Setting->Illocutor?1:0) + (!!Setting->Symbol?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "setting", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "setting", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Setting->Symbol);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_illocutor(production, Setting->Illocutor, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "setting"), opt_subvalues && !!strstr(opt_subvalues, "setting"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Setting->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "setting"), opt_subvalues && !!strstr(opt_subvalues, "setting"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_illocutor(char **production, Illocutor *Illocutor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Illocutor) return false;
		if(opt_debug) printf("producing Illocutor\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "illocutor")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Illocutor->Be?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "illocutor", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "illocutor", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_be(production, Illocutor->Be, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "illocutor"), opt_subvalues && !!strstr(opt_subvalues, "illocutor"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_be(char **production, Be *Be, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Be) return false;
		if(opt_debug) printf("producing Be\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "be")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "be", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "be", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_payment(char **production, Payment *Payment, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Payment) return false;
		if(opt_debug) printf("producing Payment\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "payment")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Payment->Pay?1:0) + (!!Payment->Expression?1:0) + (!!Payment->Preposition?1:0) + (!!Payment->Object?1:0) + (!!Payment->From_Escrow?1:0) + (!!Payment->Escrow?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "payment", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "payment", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Payment->Expression || Payment->Preposition || Payment->Object || Payment->From_Escrow || Payment->Escrow);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_pay(production, Payment->Pay, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Payment->Preposition || Payment->Object || Payment->From_Escrow || Payment->Escrow);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Payment->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Payment->Object || Payment->From_Escrow || Payment->Escrow);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_preposition(production, Payment->Preposition, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Payment->From_Escrow || Payment->Escrow);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_object(production, Payment->Object, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Payment->Escrow);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_from_escrow(production, Payment->From_Escrow, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_escrow(production, Payment->Escrow, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "payment"), opt_subvalues && !!strstr(opt_subvalues, "payment"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_pay(char **production, Pay *Pay, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Pay) return false;
		if(opt_debug) printf("producing Pay\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "pay")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "pay", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "pay", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_preposition(char **production, Preposition *Preposition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Preposition) return false;
		if(opt_debug) printf("producing Preposition\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "preposition")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "preposition", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "preposition", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_escrow(char **production, Escrow *Escrow, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Escrow) return false;
		if(opt_debug) printf("producing Escrow\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "escrow")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "escrow", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "escrow", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_from_escrow(char **production, From_Escrow *From_Escrow, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!From_Escrow) return false;
		if(opt_debug) printf("producing From_Escrow\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "from-escrow")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "from-escrow", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "from-escrow", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_sending(char **production, Sending *Sending, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Sending) return false;
		if(opt_debug) printf("producing Sending\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "sending")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Sending->Send?1:0) + (!!Sending->Expression?1:0) + (!!Sending->Preposition?1:0) + (!!Sending->Object?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "sending", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "sending", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Sending->Expression || Sending->Preposition || Sending->Object);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_send(production, Sending->Send, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "sending"), opt_subvalues && !!strstr(opt_subvalues, "sending"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Sending->Preposition || Sending->Object);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Sending->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "sending"), opt_subvalues && !!strstr(opt_subvalues, "sending"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Sending->Object);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_preposition(production, Sending->Preposition, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "sending"), opt_subvalues && !!strstr(opt_subvalues, "sending"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_object(production, Sending->Object, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "sending"), opt_subvalues && !!strstr(opt_subvalues, "sending"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_send(char **production, Send *Send, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Send) return false;
		if(opt_debug) printf("producing Send\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "send")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "send", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "send", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_notification(char **production, Notification *Notification, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Notification) return false;
		if(opt_debug) printf("producing Notification\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "notification")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Notification->Notify?1:0) + (!!Notification->Object?1:0) + (!!Notification->Preposition?1:0) + (!!Notification->Expression?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "notification", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "notification", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Notification->Object || Notification->Preposition || Notification->Expression);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_notify(production, Notification->Notify, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "notification"), opt_subvalues && !!strstr(opt_subvalues, "notification"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Notification->Preposition || Notification->Expression);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_object(production, Notification->Object, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "notification"), opt_subvalues && !!strstr(opt_subvalues, "notification"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Notification->Expression);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_preposition(production, Notification->Preposition, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "notification"), opt_subvalues && !!strstr(opt_subvalues, "notification"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Notification->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "notification"), opt_subvalues && !!strstr(opt_subvalues, "notification"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_notify(char **production, Notify *Notify, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Notify) return false;
		if(opt_debug) printf("producing Notify\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "notify")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "notify", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "notify", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_termination(char **production, Termination *Termination, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Termination) return false;
		if(opt_debug) printf("producing Termination\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "termination")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Termination->Terminate?1:0) + (!!Termination->This_Contract?1:0) + (!!Termination->All_Contracts?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "termination", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "termination", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Termination->This_Contract || Termination->All_Contracts);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_terminate(production, Termination->Terminate, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "termination"), opt_subvalues && !!strstr(opt_subvalues, "termination"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Termination->All_Contracts);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_this_contract(production, Termination->This_Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "termination"), opt_subvalues && !!strstr(opt_subvalues, "termination"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_all_contracts(production, Termination->All_Contracts, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "termination"), opt_subvalues && !!strstr(opt_subvalues, "termination"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_terminate(char **production, Terminate *Terminate, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Terminate) return false;
		if(opt_debug) printf("producing Terminate\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "terminate")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "terminate", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "terminate", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_flagging(char **production, Flagging *Flagging, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Flagging) return false;
		if(opt_debug) printf("producing Flagging\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "flagging")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Flagging->Illocutor?1:0) + (!!Flagging->Symbol?1:0) + (!!Flagging->This_Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "flagging", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "flagging", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Flagging->Symbol || Flagging->This_Contract);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_illocutor(production, Flagging->Illocutor, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "flagging"), opt_subvalues && !!strstr(opt_subvalues, "flagging"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Flagging->This_Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Flagging->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "flagging"), opt_subvalues && !!strstr(opt_subvalues, "flagging"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_this_contract(production, Flagging->This_Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "flagging"), opt_subvalues && !!strstr(opt_subvalues, "flagging"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_condition(char **production, Condition *Condition, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Condition) return false;
		if(opt_debug) printf("producing Condition\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "condition")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Condition->If?1:0) + (!!Condition->Expression?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "condition", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "condition", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Condition->Expression);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_if(production, Condition->If, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "condition"), opt_subvalues && !!strstr(opt_subvalues, "condition"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expression(production, Condition->Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "condition"), opt_subvalues && !!strstr(opt_subvalues, "condition"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_if(char **production, If *If, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!If) return false;
		if(opt_debug) printf("producing If\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "if")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "if", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "if", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_expression(char **production, Expression *Expression, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Expression) return false;
		if(opt_debug) printf("producing Expression\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "expression")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Expression->Combination?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "expression", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "expression", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combination(production, Expression->Combination, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "expression"), opt_subvalues && !!strstr(opt_subvalues, "expression"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_scalar_comparison(char **production, Scalar_Comparison *Scalar_Comparison, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Scalar_Comparison) return false;
		if(opt_debug) printf("producing Scalar_Comparison\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "scalar-comparison")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Scalar_Comparison->Scalar_Expression?1:0) + (!!Scalar_Comparison->Comparison_Operator?1:0) + (!!Scalar_Comparison->Scalar_Expression2?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "scalar-comparison", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "scalar-comparison", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Scalar_Comparison->Comparison_Operator || Scalar_Comparison->Scalar_Expression2);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_scalar_expression(production, Scalar_Comparison->Scalar_Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_comparison"), opt_subvalues && !!strstr(opt_subvalues, "scalar_comparison"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Scalar_Comparison->Scalar_Expression2);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_comparison_operator(production, Scalar_Comparison->Comparison_Operator, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_comparison"), opt_subvalues && !!strstr(opt_subvalues, "scalar_comparison"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_scalar_expression(production, Scalar_Comparison->Scalar_Expression2, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_comparison"), opt_subvalues && !!strstr(opt_subvalues, "scalar_comparison"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_comparison_operator(char **production, Comparison_Operator *Comparison_Operator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Comparison_Operator) return false;
		if(opt_debug) printf("producing Comparison_Operator\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "comparison-operator")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Comparison_Operator->Equal?1:0) + (!!Comparison_Operator->Later?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "comparison-operator", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "comparison-operator", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Comparison_Operator->Later);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_equal(production, Comparison_Operator->Equal, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "comparison_operator"), opt_subvalues && !!strstr(opt_subvalues, "comparison_operator"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_later(production, Comparison_Operator->Later, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "comparison_operator"), opt_subvalues && !!strstr(opt_subvalues, "comparison_operator"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_equal(char **production, Equal *Equal, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Equal) return false;
		if(opt_debug) printf("producing Equal\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "equal")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "equal", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "equal", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_later(char **production, Later *Later, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Later) return false;
		if(opt_debug) printf("producing Later\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "later")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "later", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "later", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_scalar_expression(char **production, Scalar_Expression *Scalar_Expression, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Scalar_Expression) return false;
		if(opt_debug) printf("producing Scalar_Expression %s\n", Scalar_Expression->Scalar);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "scalar-expression")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Scalar_Expression->Symbol?1:0) + (!!Scalar_Expression->Scalar?1:0) + (!!Scalar_Expression->Point_In_Time?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "scalar-expression", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "scalar-expression", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Scalar_Expression->Scalar || Scalar_Expression->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Scalar_Expression->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_expression"), opt_subvalues && !!strstr(opt_subvalues, "scalar_expression"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Scalar_Expression->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_scalar(production, Scalar_Expression->Scalar, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_expression"), opt_subvalues && !!strstr(opt_subvalues, "scalar_expression"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_point_in_time(production, Scalar_Expression->Point_In_Time, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "scalar_expression"), opt_subvalues && !!strstr(opt_subvalues, "scalar_expression"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_combination(char **production, Combination *Combination, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Combination) return false;
		if(opt_debug) printf("producing Combination\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "combination")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Combination->Combinor?1:0) + (!!Combination->Combination?1:0) + (!!Combination->Combinator?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "combination", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, opening_bracket, " ", color, "combination", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combination->Combinor || Combination->Combinator);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combination(production, Combination->Combination, indent+irx, false, false|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "combination"), opt_subvalues && !!strstr(opt_subvalues, "combination"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combination->Combinator);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combinor(production, Combination->Combinor, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combination"), opt_subvalues && !!strstr(opt_subvalues, "combination"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combinator(production, Combination->Combinator, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combination"), opt_subvalues && !!strstr(opt_subvalues, "combination"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_combinor(char **production, Combinor *Combinor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Combinor) return false;
		if(opt_debug) printf("producing Combinor\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "combinor")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Combinor->Combinand?1:0) + (!!Combinor->Combinator?1:0) + (!!Combinor->Combinor?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "combinor", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, opening_bracket, " ", color, "combinor", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinor->Combinand || Combinor->Combinator);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combinor(production, Combinor->Combinor, indent+irx, false, false|| sibbling, subhighlight || opt_values && !!strstr(opt_values, "combinor"), opt_subvalues && !!strstr(opt_subvalues, "combinor"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinor->Combinator);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combinand(production, Combinor->Combinand, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinor"), opt_subvalues && !!strstr(opt_subvalues, "combinor"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_combinator(production, Combinor->Combinator, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinor"), opt_subvalues && !!strstr(opt_subvalues, "combinor"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_combinand(char **production, Combinand *Combinand, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Combinand) return false;
		if(opt_debug) printf("producing Combinand %s\n", Combinand->Description);
		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "combinand")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Combinand->Symbol?1:0) + (!!Combinand->Expiration?1:0) + (!!Combinand->Reflexive?1:0) + (!!Combinand->Description?1:0) + (!!Combinand->Scalar_Comparison?1:0) + (!!Combinand->Negation?1:0) + (!!Combinand->Existence?1:0) + (!!Combinand->Point_In_Time?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "combinand", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, opening_bracket, " ", color, "combinand", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Expiration || Combinand->Reflexive || Combinand->Description || Combinand->Scalar_Comparison || Combinand->Negation || Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Combinand->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Reflexive || Combinand->Description || Combinand->Scalar_Comparison || Combinand->Negation || Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_expiration(production, Combinand->Expiration, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Description || Combinand->Scalar_Comparison || Combinand->Negation || Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_reflexive(production, Combinand->Reflexive, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Scalar_Comparison || Combinand->Negation || Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_description(production, Combinand->Description, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Negation || Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_scalar_comparison(production, Combinand->Scalar_Comparison, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Existence || Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_negation(production, Combinand->Negation, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinand->Point_In_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_existence(production, Combinand->Existence, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_point_in_time(production, Combinand->Point_In_Time, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinand"), opt_subvalues && !!strstr(opt_subvalues, "combinand"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_combinator(char **production, Combinator *Combinator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Combinator) return false;
		if(opt_debug) printf("producing Combinator\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "combinator")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Combinator->Or_?1:0) + (!!Combinator->And?1:0) + (!!Combinator->Neither?1:0) + (!!Combinator->Nor?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "combinator", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "combinator", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinator->And || Combinator->Neither || Combinator->Nor);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_or_(production, Combinator->Or_, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinator"), opt_subvalues && !!strstr(opt_subvalues, "combinator"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinator->Neither || Combinator->Nor);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_and(production, Combinator->And, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinator"), opt_subvalues && !!strstr(opt_subvalues, "combinator"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Combinator->Nor);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_neither(production, Combinator->Neither, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinator"), opt_subvalues && !!strstr(opt_subvalues, "combinator"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_nor(production, Combinator->Nor, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "combinator"), opt_subvalues && !!strstr(opt_subvalues, "combinator"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_or_(char **production, Or_ *Or_, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Or_) return false;
		if(opt_debug) printf("producing Or_\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "or-")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "or-", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "or-", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_and(char **production, And *And, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!And) return false;
		if(opt_debug) printf("producing And\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "and")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "and", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "and", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_neither(char **production, Neither *Neither, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Neither) return false;
		if(opt_debug) printf("producing Neither\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "neither")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "neither", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "neither", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_nor(char **production, Nor *Nor, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Nor) return false;
		if(opt_debug) printf("producing Nor\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "nor")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "nor", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "nor", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_existence(char **production, Existence *Existence, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Existence) return false;
		if(opt_debug) printf("producing Existence\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "existence")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Existence->Symbol?1:0) + (!!Existence->Equal?1:0) + (!!Existence->Fixed?1:0) + (!!Existence->Be?1:0) + (!!Existence->Contract?1:0) + (!!Existence->Being?1:0) + (!!Existence->True?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "existence", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "existence", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Existence->Equal || Existence->Fixed || Existence->Be || Existence->Contract || Existence->Being || Existence->True);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Existence->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Existence->Fixed || Existence->Be || Existence->Contract || Existence->Being || Existence->True);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_equal(production, Existence->Equal, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Existence->Be || Existence->Contract || Existence->Being || Existence->True);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_fixed(production, Existence->Fixed, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Existence->Contract || Existence->Being || Existence->True);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_be(production, Existence->Be, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
			subhighlight = false;
		}
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = !!(Existence->Being || Existence->True);
			if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Existence->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
			subhighlight = false;
		}
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Existence->True);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_being(production, Existence->Being, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_true(production, Existence->True, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "existence"), opt_subvalues && !!strstr(opt_subvalues, "existence"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_negation(char **production, Negation *Negation, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Negation) return false;
		if(opt_debug) printf("producing Negation\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "negation")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Negation->Negator?1:0) + (!!Negation->Symbol?1:0) + (!!Negation->Fixed?1:0) + (!!Negation->Contract?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "negation", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "negation", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Negation->Symbol || Negation->Fixed || Negation->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_negator(production, Negation->Negator, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "negation"), opt_subvalues && !!strstr(opt_subvalues, "negation"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Negation->Fixed || Negation->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Negation->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "negation"), opt_subvalues && !!strstr(opt_subvalues, "negation"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Negation->Contract);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_fixed(production, Negation->Fixed, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "negation"), opt_subvalues && !!strstr(opt_subvalues, "negation"));
		subhighlight = false;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_contract(production, Negation->Contract, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "negation"), opt_subvalues && !!strstr(opt_subvalues, "negation"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_negator(char **production, Negator *Negator, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Negator) return false;
		if(opt_debug) printf("producing Negator\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "negator")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Negator->Be?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "negator", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "negator", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(true) {
			if(!terse) grid &= 4294967294;
			sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
			if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
			core_be(production, Negator->Be, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "negator"), opt_subvalues && !!strstr(opt_subvalues, "negator"));
			subhighlight = false;
		}
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_being(char **production, Being *Being, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Being) return false;
		if(opt_debug) printf("producing Being\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "being")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "being", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "being", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_true(char **production, True *True, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!True) return false;
		if(opt_debug) printf("producing True\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "true")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "true", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "true", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_article(char **production, Article *Article, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Article) return false;
		if(opt_debug) printf("producing Article\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "article")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "article", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "article", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_point_in_time(char **production, Point_In_Time *Point_In_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Point_In_Time) return false;
		if(opt_debug) printf("producing Point_In_Time\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "point-in-time")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Point_In_Time->Current_Time?1:0) + (!!Point_In_Time->Relative_Time?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "point-in-time", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "point-in-time", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Point_In_Time->Relative_Time);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_current_time(production, Point_In_Time->Current_Time, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "point_in_time"), opt_subvalues && !!strstr(opt_subvalues, "point_in_time"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_relative_time(production, Point_In_Time->Relative_Time, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "point_in_time"), opt_subvalues && !!strstr(opt_subvalues, "point_in_time"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_current_time(char **production, Current_Time *Current_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Current_Time) return false;
		if(opt_debug) printf("producing Current_Time\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "current-time")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "current-time", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "current-time", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_relative_time(char **production, Relative_Time *Relative_Time, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Relative_Time) return false;
		if(opt_debug) printf("producing Relative_Time\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "relative-time")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Relative_Time->Duration?1:0) + (!!Relative_Time->Symbol?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "relative-time", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "relative-time", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Relative_Time->Symbol);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_duration(production, Relative_Time->Duration, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "relative_time"), opt_subvalues && !!strstr(opt_subvalues, "relative_time"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_symbol(production, Relative_Time->Symbol, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "relative_time"), opt_subvalues && !!strstr(opt_subvalues, "relative_time"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_duration(char **production, Duration *Duration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Duration) return false;
		if(opt_debug) printf("producing Duration\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "duration")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Duration->Scalar_Expression?1:0) + (!!Duration->Time_Unit?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "duration", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "duration", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Duration->Time_Unit);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_scalar_expression(production, Duration->Scalar_Expression, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "duration"), opt_subvalues && !!strstr(opt_subvalues, "duration"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_time_unit(production, Duration->Time_Unit, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "duration"), opt_subvalues && !!strstr(opt_subvalues, "duration"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_time_unit(char **production, Time_Unit *Time_Unit, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Time_Unit) return false;
		if(opt_debug) printf("producing Time_Unit\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "time-unit")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0 + (!!Time_Unit->Years?1:0) + (!!Time_Unit->Months?1:0) + (!!Time_Unit->Weeks?1:0) + (!!Time_Unit->Days?1:0) + (!!Time_Unit->Hours?1:0) + (!!Time_Unit->Minutes?1:0) + (!!Time_Unit->Seconds?1:0) + (!!Time_Unit->Milliseconds?1:0)));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "time-unit", off, " ");
		} else {
			padcat(1, indent, production, opening_bracket, " ", color, "time-unit", off, " ");
			sameline = false;
			bracket_just_closed = false;
			sameline = false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Months || Time_Unit->Weeks || Time_Unit->Days || Time_Unit->Hours || Time_Unit->Minutes || Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_years(production, Time_Unit->Years, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Weeks || Time_Unit->Days || Time_Unit->Hours || Time_Unit->Minutes || Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_months(production, Time_Unit->Months, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Days || Time_Unit->Hours || Time_Unit->Minutes || Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_weeks(production, Time_Unit->Weeks, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Hours || Time_Unit->Minutes || Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_days(production, Time_Unit->Days, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Minutes || Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_hours(production, Time_Unit->Hours, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Seconds || Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_minutes(production, Time_Unit->Minutes, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = !!(Time_Unit->Milliseconds);
		if(opt_produce_tree) { bool line = opt_produce_flat && sibbling || sibbling_follows; if(line) grid |=1; }
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_seconds(production, Time_Unit->Seconds, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		if(!terse) grid &= 4294967294;
		sibbling_follows = false;
		irx = !terse ? 1 : 0;
		if(opt_produce_tree && opt_produce_flat) grid |= sibbling;
		if(!opt_produce_flat && !sibbling_follows) grid &= 0xFFFFFFFE;
		core_milliseconds(production, Time_Unit->Milliseconds, indent+irx, true, false, subhighlight || opt_values && !!strstr(opt_values, "time_unit"), opt_subvalues && !!strstr(opt_subvalues, "time_unit"));
		subhighlight = false;
		grid >>= !terse ? 1 : 0;
		padcat(0, 0, production, opt_produce_tree?"":closing_bracket, " ");
		bracket_just_closed=true;

		return true;
	}

	bool core_years(char **production, Years *Years, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Years) return false;
		if(opt_debug) printf("producing Years\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "years")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "years", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "years", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_months(char **production, Months *Months, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Months) return false;
		if(opt_debug) printf("producing Months\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "months")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "months", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "months", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_weeks(char **production, Weeks *Weeks, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Weeks) return false;
		if(opt_debug) printf("producing Weeks\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "weeks")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "weeks", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "weeks", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_days(char **production, Days *Days, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Days) return false;
		if(opt_debug) printf("producing Days\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "days")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "days", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "days", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_hours(char **production, Hours *Hours, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Hours) return false;
		if(opt_debug) printf("producing Hours\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "hours")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "hours", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "hours", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_minutes(char **production, Minutes *Minutes, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Minutes) return false;
		if(opt_debug) printf("producing Minutes\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "minutes")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "minutes", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "minutes", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_seconds(char **production, Seconds *Seconds, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Seconds) return false;
		if(opt_debug) printf("producing Seconds\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "seconds")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "seconds", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "seconds", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_milliseconds(char **production, Milliseconds *Milliseconds, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Milliseconds) return false;
		if(opt_debug) printf("producing Milliseconds\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "milliseconds")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "milliseconds", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "milliseconds", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}

	bool core_expiration(char **production, Expiration *Expiration, int indent, bool topcall, bool sibbling, bool highlight, bool subhighlight) {
		if(!Expiration) return false;
		if(opt_debug) printf("producing Expiration\n");

		char *color = !!opt_color && (highlight || opt_highlight && strstr(opt_highlight, "expiration")) ? opt_color : "";
		char *off = *color ? "\033[0m" : "";
		bool sameline;
		bool has_more_recursion = false;
		bool skipped = false;
		bool terse = opt_produce_terse && (skipped || (1 == 0));
		if(opt_produce_tree) {
			if(!(opt_produce_flat && has_more_recursion) && !terse)
				padcat(1, indent, production, "↳  ", color, "expiration", off, " ");
		} else {
			padcat(bracket_just_closed?1:0, bracket_just_closed?indent:0, production, color, "expiration", off, " ");
			sameline = !bracket_just_closed;
			bracket_just_closed=false;
		}
		bool sibbling_follows;
		grid <<= !terse ? 1 : 0;
		int irx = !terse ? 1 : 0;
		grid >>= !terse ? 1 : 0;

		return true;
	}
