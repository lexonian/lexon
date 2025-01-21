%{

/* Prologue */

/* - */
%}

/* Requires */

%code requires {

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


Document *root;
/* action handler (stub) functions */
Document *process_document(Document *Document);
Head *process_head(Head *Head);
Lex *process_lex(Lex *Lex);
Lexon *process_lexon(Lexon *Lexon);
Authors *process_authors(Authors *Authors);
Comment *process_comment(Comment *Comment);
Preamble *process_preamble(Preamble *Preamble);
Terms *process_terms(Terms *Terms);
Covenants *process_covenants(Covenants *Covenants);
Covenant *process_covenant(Covenant *Covenant);
Provisions *process_provisions(Provisions *Provisions);
Definitions *process_definitions(Definitions *Definitions);
Definition *process_definition(Definition *Definition);
Type_Term *process_type_term(Type_Term *Type_Term);
Type *process_type(Type *Type);
Person *process_person(Person *Person);
Amount *process_amount(Amount *Amount);
Time *process_time(Time *Time);
Binary *process_binary(Binary *Binary);
Text *process_text(Text *Text);
Data *process_data(Data *Data);
This_Contract *process_this_contract(This_Contract *This_Contract);
All_Contracts *process_all_contracts(All_Contracts *All_Contracts);
This *process_this(This *This);
Clauses *process_clauses(Clauses *Clauses);
Clause *process_clause(Clause *Clause);
Body *process_body(Body *Body);
Function *process_function(Function *Function);
Statements *process_statements(Statements *Statements);
Statement *process_statement(Statement *Statement);
Action *process_action(Action *Action);
Subject *process_subject(Subject *Subject);
Symbols *process_symbols(Symbols *Symbols);
Symbol *process_symbol(Symbol *Symbol);
Catena *process_catena(Catena *Catena);
Object *process_object(Object *Object);
Reflexive *process_reflexive(Reflexive *Reflexive);
Contract *process_contract(Contract *Contract);
Predicates *process_predicates(Predicates *Predicates);
Predicate *process_predicate(Predicate *Predicate);
Permission *process_permission(Permission *Permission);
Certification *process_certification(Certification *Certification);
Certify *process_certify(Certify *Certify);
Declaration *process_declaration(Declaration *Declaration);
Declare *process_declare(Declare *Declare);
Filing *process_filing(Filing *Filing);
File *process_file(File *File);
Registration *process_registration(Registration *Registration);
Register *process_register(Register *Register);
Grantment *process_grantment(Grantment *Grantment);
Grant *process_grant(Grant *Grant);
Appointment *process_appointment(Appointment *Appointment);
Appoint *process_appoint(Appoint *Appoint);
Fixture *process_fixture(Fixture *Fixture);
Fix *process_fix(Fix *Fix);
Fixed *process_fixed(Fixed *Fixed);
Setting *process_setting(Setting *Setting);
Illocutor *process_illocutor(Illocutor *Illocutor);
Be *process_be(Be *Be);
Payment *process_payment(Payment *Payment);
Pay *process_pay(Pay *Pay);
Preposition *process_preposition(Preposition *Preposition);
Escrow *process_escrow(Escrow *Escrow);
From_Escrow *process_from_escrow(From_Escrow *From_Escrow);
Sending *process_sending(Sending *Sending);
Send *process_send(Send *Send);
Notification *process_notification(Notification *Notification);
Notify *process_notify(Notify *Notify);
Termination *process_termination(Termination *Termination);
Terminate *process_terminate(Terminate *Terminate);
Flagging *process_flagging(Flagging *Flagging);
Condition *process_condition(Condition *Condition);
If *process_if(If *If);
Expression *process_expression(Expression *Expression);
Scalar_Comparison *process_scalar_comparison(Scalar_Comparison *Scalar_Comparison);
Comparison_Operator *process_comparison_operator(Comparison_Operator *Comparison_Operator);
Equal *process_equal(Equal *Equal);
Later *process_later(Later *Later);
Scalar_Expression *process_scalar_expression(Scalar_Expression *Scalar_Expression);
Combination *process_combination(Combination *Combination);
Combinor *process_combinor(Combinor *Combinor);
Combinand *process_combinand(Combinand *Combinand);
Combinator *process_combinator(Combinator *Combinator);
Or_ *process_or_(Or_ *Or_);
And *process_and(And *And);
Neither *process_neither(Neither *Neither);
Nor *process_nor(Nor *Nor);
Existence *process_existence(Existence *Existence);
Negation *process_negation(Negation *Negation);
Negator *process_negator(Negator *Negator);
Being *process_being(Being *Being);
True *process_true(True *True);
Article *process_article(Article *Article);
Point_In_Time *process_point_in_time(Point_In_Time *Point_In_Time);
Current_Time *process_current_time(Current_Time *Current_Time);
Relative_Time *process_relative_time(Relative_Time *Relative_Time);
Duration *process_duration(Duration *Duration);
Time_Unit *process_time_unit(Time_Unit *Time_Unit);
Years *process_years(Years *Years);
Months *process_months(Months *Months);
Weeks *process_weeks(Weeks *Weeks);
Days *process_days(Days *Days);
Hours *process_hours(Hours *Hours);
Minutes *process_minutes(Minutes *Minutes);
Seconds *process_seconds(Seconds *Seconds);
Milliseconds *process_milliseconds(Milliseconds *Milliseconds);
Expiration *process_expiration(Expiration *Expiration);
}

/* Declarations */

/* Mapping C types to tokens */

%define api.value.type union

%define parse.error detailed
%define lr.type ielr
%glr-parser
%define parse.trace

	%token Separator
	%token Comma
	%token Colon
	%token Semicolon
	%token Dash
	%token Percent
	%token Quote
	%token <Name *> NAME
	%nterm <Name *> Name
	%token <Description *> DESCRIPTION
	%nterm <Description *> Description
	%token <Scalar *> SCALAR
	%nterm <Scalar *> Scalar
	%token AUTHOR
	%token AUTHORS
	%token CLAUSE
	%token COMMENT
	%token COMMENTS
	%token GENERAL
	%token LEX
	%token LEXON
	%token PER
	%token PREAMBLE
	%token TERMS
	%token A
	%token AFTER
	%token AFTERWARDS
	%token ALL
	%token ALSO
	%token AMOUNT
	%token AN
	%token AND
	%token ANNOUNCED
	%token APPOINT
	%token APPOINTS
	%token AS
	%token AT
	%token BE
	%token BEEN
	%token BEING
	%token BINARY
	%token CERTIFIED
	%token CERTIFIES
	%token CERTIFY
	%token CONTRACT
	%token CONTRACTS
	%token CURRENT
	%token DATA
	%token DAY
	%token DAYS
	%token DECLARE
	%token DECLARED
	%token DECLARES
	%token DEFINED
	%token EQUAL
	%token EQUALING
	%token ESCROW
	%token FILE_
	%token FILED
	%token FILES
	%token FIX
	%token FIXED
	%token FIXES
	%token FOR
	%token FROM
	%token GIVEN
	%token GRANT
	%token GRANTS
	%token HAS
	%token HERSELF
	%token HIMSELF
	%token HOUR
	%token HOURS
	%token IF
	%token IN
	%token INTO
	%token IS
	%token ITSELF
	%token LEAST
	%token LIES
	%token MAY
	%token MILLISECOND
	%token MILLISECONDS
	%token MINUTE
	%token MINUTES
	%token MONTH
	%token MONTHS
	%token MYSELF
	%token NEITHER
	%token NO
	%token NOR
	%token NOT
	%token NOTIFIES
	%token NOTIFY
	%token NOW
	%token OF
	%token OFF
	%token ON
	%token ONESELF
	%token OR
	%token OURSELVES
	%token PASSED
	%token PAST
	%token PAY
	%token PAYS
	%token PERSON
	%token PROVIDED
	%token REGISTER
	%token REGISTERS
	%token REMAINDER
	%token RESPECTIVE
	%token RETURN
	%token RETURNS
	%token SECOND
	%token SECONDS
	%token SEND
	%token SENDS
	%token SIGNED
	%token SO
	%token TERMINATE
	%token TERMINATES
	%token TEXT
	%token THAT
	%token THE
	%token THEMSELF
	%token THEMSELVES
	%token THEN
	%token THERE
	%token THEREFOR
	%token THEREFORE
	%token THESE
	%token THIS
	%token TIME
	%token TO
	%token TRUE
	%token WAS
	%token WEEK
	%token WEEKS
	%token WITH
	%token YEAR
	%token YEARS
	%token YES
	%token YOURSELF
	%token YOURSELVES
	%nterm <Action *> Action
	%nterm <All_Contracts *> All_Contracts
	%nterm <Amount *> Amount
	%nterm <And *> And
	%nterm <Appoint *> Appoint
	%nterm <Appointment *> Appointment
	%nterm <Article *> Article
	%nterm <Authors *> Authors
	%nterm <Be *> Be
	%nterm <Being *> Being
	%nterm <Binary *> Binary
	%nterm <Body *> Body
	%nterm <Catena *> Catena
	%nterm <Certification *> Certification
	%nterm <Certify *> Certify
	%nterm <Clause *> Clause
	%nterm <Clauses *> Clauses
	%nterm <Combinand *> Combinand
	%nterm <Combination *> Combination
	%nterm <Combinator *> Combinator
	%nterm <Combinor *> Combinor
	%nterm <Comment *> Comment
	%nterm <Comparison_Operator *> Comparison_Operator
	%nterm <Condition *> Condition
	%nterm <Contract *> Contract
	%nterm <Covenant *> Covenant
	%nterm <Covenants *> Covenants
	%nterm <Current_Time *> Current_Time
	%nterm <Data *> Data
	%nterm <Days *> Days
	%nterm <Declaration *> Declaration
	%nterm <Declare *> Declare
	%nterm <Definition *> Definition
	%nterm <Definitions *> Definitions
	%nterm <Document *> Document
	%nterm <Duration *> Duration
	%nterm <Equal *> Equal
	%nterm <Escrow *> Escrow
	%nterm <Existence *> Existence
	%nterm <Expiration *> Expiration
	%nterm <Expression *> Expression
	%nterm <File *> File
	%nterm <Filing *> Filing
	%nterm <Fix *> Fix
	%nterm <Fixed *> Fixed
	%nterm <Fixture *> Fixture
	%nterm <Flagging *> Flagging
	%nterm <From_Escrow *> From_Escrow
	%nterm <Function *> Function
	%nterm <Grant *> Grant
	%nterm <Grantment *> Grantment
	%nterm <Head *> Head
	%nterm <Hours *> Hours
	%nterm <If *> If
	%nterm <Illocutor *> Illocutor
	%nterm <Later *> Later
	%nterm <Lex *> Lex
	%nterm <Lexon *> Lexon
	%nterm <Milliseconds *> Milliseconds
	%nterm <Minutes *> Minutes
	%nterm <Months *> Months
	%nterm <Negation *> Negation
	%nterm <Negator *> Negator
	%nterm <Neither *> Neither
	%nterm <Nor *> Nor
	%nterm <Notification *> Notification
	%nterm <Notify *> Notify
	%nterm <Object *> Object
	%nterm <Or_ *> Or_
	%nterm <Pay *> Pay
	%nterm <Payment *> Payment
	%nterm <Permission *> Permission
	%nterm <Person *> Person
	%nterm <Point_In_Time *> Point_In_Time
	%nterm <Preamble *> Preamble
	%nterm <Predicate *> Predicate
	%nterm <Predicates *> Predicates
	%nterm <Preposition *> Preposition
	%nterm <Provisions *> Provisions
	%nterm <Reflexive *> Reflexive
	%nterm <Register *> Register
	%nterm <Registration *> Registration
	%nterm <Relative_Time *> Relative_Time
	%nterm <Scalar_Comparison *> Scalar_Comparison
	%nterm <Scalar_Expression *> Scalar_Expression
	%nterm <Seconds *> Seconds
	%nterm <Send *> Send
	%nterm <Sending *> Sending
	%nterm <Setting *> Setting
	%nterm <Statement *> Statement
	%nterm <Statements *> Statements
	%nterm <Subject *> Subject
	%nterm <Symbol *> Symbol
	%nterm <Symbols *> Symbols
	%nterm <Terminate *> Terminate
	%nterm <Termination *> Termination
	%nterm <Terms *> Terms
	%nterm <Text *> Text
	%nterm <This *> This
	%nterm <This_Contract *> This_Contract
	%nterm <Time *> Time
	%nterm <Time_Unit *> Time_Unit
	%nterm <True *> True
	%nterm <Type *> Type
	%nterm <Type_Term *> Type_Term
	%nterm <Weeks *> Weeks
	%nterm <Years *> Years


%%

/* Grammar */

	
	Document:	
		  Head Terms                                      { NEW(Document, *((Literal **)&yylval)); Document->Head=$Head; Document->Terms=$Terms; root=process_document(Document); }
		| Head Terms Covenants                            { NEW(Document, *((Literal **)&yylval)); Document->Head=$Head; Document->Terms=$Terms; Document->Covenants=$Covenants; root=process_document(Document); }
		;


	
	Head:	
		  Lex                                             { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; $$=process_head(Head); }
		| Lex Preamble                                    { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Comment                                     { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Comment=$Comment; $$=process_head(Head); }
		| Lex Comment Preamble                            { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Comment=$Comment; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Authors                                     { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Authors=$Authors; $$=process_head(Head); }
		| Lex Authors Preamble                            { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Authors=$Authors; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Authors Comment                             { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Authors=$Authors; Head->Comment=$Comment; $$=process_head(Head); }
		| Lex Authors Comment Preamble                    { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Authors=$Authors; Head->Comment=$Comment; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Lexon                                       { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; $$=process_head(Head); }
		| Lex Lexon Preamble                              { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Lexon Comment                               { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Comment=$Comment; $$=process_head(Head); }
		| Lex Lexon Comment Preamble                      { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Comment=$Comment; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Lexon Authors                               { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Authors=$Authors; $$=process_head(Head); }
		| Lex Lexon Authors Preamble                      { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Authors=$Authors; Head->Preamble=$Preamble; $$=process_head(Head); }
		| Lex Lexon Authors Comment                       { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Authors=$Authors; Head->Comment=$Comment; $$=process_head(Head); }
		| Lex Lexon Authors Comment Preamble              { NEW(Head, *((Literal **)&yylval)); Head->Lex=$Lex; Head->Lexon=$Lexon; Head->Authors=$Authors; Head->Comment=$Comment; Head->Preamble=$Preamble; $$=process_head(Head); }
		;


	
	Lex:	
		  LEX Colon Name Separator                        { NEW(Lex, *((Literal **)&yylval)); Lex->Name=$Name; $$=process_lex(Lex); }
		;


	
	Lexon:	
		  LEXON Colon Description Separator               { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=$Description; $$=process_lexon(Lexon); }
		;


	
	Authors:	
		  AUTHOR Colon Description Separator              { NEW(Authors, *((Literal **)&yylval)); Authors->Description=$Description; $$=process_authors(Authors); }
		| AUTHORS Colon Description Separator             { NEW(Authors, *((Literal **)&yylval)); Authors->Description=$Description; $$=process_authors(Authors); }
		;


	
	Comment:	
		  COMMENT Colon Description Separator             { NEW(Comment, *((Literal **)&yylval)); Comment->Description=$Description; $$=process_comment(Comment); }
		| COMMENTS Colon Description Separator            { NEW(Comment, *((Literal **)&yylval)); Comment->Description=$Description; $$=process_comment(Comment); }
		;


	
	Preamble:	
		  PREAMBLE Colon Description Separator            { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=$Description; $$=process_preamble(Preamble); }
		;


	
	Terms:	
		   Provisions                                     { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		|  Separator Provisions                           { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		|  TERMS Colon Provisions                         { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		|  TERMS Colon Separator Provisions               { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		| GENERAL Provisions                              { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		| GENERAL Separator Provisions                    { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		| GENERAL TERMS Colon Provisions                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		| GENERAL TERMS Colon Separator Provisions        { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=$Provisions; $$=process_terms(Terms); }
		;


	
	Covenants:	
		   Covenant                                       { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=$Covenant; $$=process_covenants(Covenants); }
		| Covenants Covenant                              { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=$1; Covenants->Covenant=$Covenant; $$=process_covenants(Covenants); }
		;


	
	Covenant:	
		   PER Name Colon Provisions                      { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=$Name; Covenant->Provisions=$Provisions; $$=process_covenant(Covenant); }
		|  PER Name Colon Separator Provisions            { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=$Name; Covenant->Provisions=$Provisions; $$=process_covenant(Covenant); }
		| TERMS PER Name Colon Provisions                 { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=$Name; Covenant->Provisions=$Provisions; $$=process_covenant(Covenant); }
		| TERMS PER Name Colon Separator Provisions       { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=$Name; Covenant->Provisions=$Provisions; $$=process_covenant(Covenant); }
		;


	
	Provisions:	
		  Definitions                                     { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=$Definitions; $$=process_provisions(Provisions); }
		| Definitions Clauses                             { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=$Definitions; Provisions->Clauses=$Clauses; $$=process_provisions(Provisions); }
		| Definitions Statements                          { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=$Definitions; Provisions->Statements=$Statements; $$=process_provisions(Provisions); }
		| Definitions Statements Clauses                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=$Definitions; Provisions->Statements=$Statements; Provisions->Clauses=$Clauses; $$=process_provisions(Provisions); }
		;


	
	Definitions:	
		   Definition                                     { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=$Definition; $$=process_definitions(Definitions); }
		| Definitions Definition                          { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=$1; Definitions->Definition=$Definition; $$=process_definitions(Definitions); }
		;


	
	Definition:	
		   Quote Name Quote IS Type_Term Separator        { NEW(Definition, *((Literal **)&yylval)); Definition->Name=$Name; Definition->Type_Term=$Type_Term; $$=process_definition(Definition); }
		| Article Quote Name Quote IS Type_Term Separator { NEW(Definition, *((Literal **)&yylval)); Definition->Article=$Article; Definition->Name=$Name; Definition->Type_Term=$Type_Term; $$=process_definition(Definition); }
		|  Quote Name Quote IS This_Contract Separator    { NEW(Definition, *((Literal **)&yylval)); Definition->Name=$Name; Definition->This_Contract=$This_Contract; $$=process_definition(Definition); }
		| Article Quote Name Quote IS This_Contract Separator { NEW(Definition, *((Literal **)&yylval)); Definition->Article=$Article; Definition->Name=$Name; Definition->This_Contract=$This_Contract; $$=process_definition(Definition); }
		;


	
	Type_Term:	
		   Type                                           { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=$Type; $$=process_type_term(Type_Term); }
		| Article Type                                    { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=$Article; Type_Term->Type=$Type; $$=process_type_term(Type_Term); }
		;


	
	Type:	
		  Person                                          { NEW(Type, *((Literal **)&yylval)); Type->Person=$Person; $$=process_type(Type); }
		| Amount                                          { NEW(Type, *((Literal **)&yylval)); Type->Amount=$Amount; $$=process_type(Type); }
		| Time                                            { NEW(Type, *((Literal **)&yylval)); Type->Time=$Time; $$=process_type(Type); }
		| Binary                                          { NEW(Type, *((Literal **)&yylval)); Type->Binary=$Binary; $$=process_type(Type); }
		| Text                                            { NEW(Type, *((Literal **)&yylval)); Type->Text=$Text; $$=process_type(Type); }
		| Data                                            { NEW(Type, *((Literal **)&yylval)); Type->Data=$Data; $$=process_type(Type); }
		;


	
	Person:	
		  PERSON                                          { NEW(Person, *((Literal **)&yylval)); $$=process_person(Person); }
		;


	
	Amount:	
		  AMOUNT                                          { NEW(Amount, *((Literal **)&yylval)); $$=process_amount(Amount); }
		;


	
	Time:	
		  TIME                                            { NEW(Time, *((Literal **)&yylval)); $$=process_time(Time); }
		;


	
	Binary:	
		  BINARY                                          { NEW(Binary, *((Literal **)&yylval)); $$=process_binary(Binary); }
		;


	
	Text:	
		  TEXT                                            { NEW(Text, *((Literal **)&yylval)); $$=process_text(Text); }
		;


	
	Data:	
		  DATA                                            { NEW(Data, *((Literal **)&yylval)); $$=process_data(Data); }
		;


	
	This_Contract:	
		  This CONTRACT                                   { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=$This; $$=process_this_contract(This_Contract); }
		| This Name                                       { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=$This; This_Contract->Name=$Name; $$=process_this_contract(This_Contract); }
		;


	
	All_Contracts:	
		  ALL CONTRACTS                                   { NEW(All_Contracts, *((Literal **)&yylval)); $$=process_all_contracts(All_Contracts); }
		;


	
	This:	
		  THIS                                            { NEW(This, *((Literal **)&yylval)); $$=process_this(This); }
		| THESE                                           { NEW(This, *((Literal **)&yylval)); $$=process_this(This); }
		;


	
	Clauses:	
		   Clause                                         { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=$Clause; $$=process_clauses(Clauses); }
		| Clauses Clause                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=$1; Clauses->Clause=$Clause; $$=process_clauses(Clauses); }
		;


	
	Clause:	
		  CLAUSE Colon Name Separator Body                { NEW(Clause, *((Literal **)&yylval)); Clause->Name=$Name; Clause->Body=$Body; $$=process_clause(Clause); }
		;


	
	Body:	
		  Statements                                      { NEW(Body, *((Literal **)&yylval)); Body->Statements=$Statements; $$=process_body(Body); }
		| Function                                        { NEW(Body, *((Literal **)&yylval)); Body->Function=$Function; $$=process_body(Body); }
		;


	
	Function:	
		   Quote Name Quote Illocutor Expression Separator { NEW(Function, *((Literal **)&yylval)); Function->Name=$Name; Function->Illocutor=$Illocutor; Function->Expression=$Expression; $$=process_function(Function); }
		|  Quote Name Quote Illocutor Colon Expression Separator { NEW(Function, *((Literal **)&yylval)); Function->Name=$Name; Function->Illocutor=$Illocutor; Function->Expression=$Expression; $$=process_function(Function); }
		| Article Quote Name Quote Illocutor Expression Separator { NEW(Function, *((Literal **)&yylval)); Function->Article=$Article; Function->Name=$Name; Function->Illocutor=$Illocutor; Function->Expression=$Expression; $$=process_function(Function); }
		| Article Quote Name Quote Illocutor Colon Expression Separator { NEW(Function, *((Literal **)&yylval)); Function->Article=$Article; Function->Name=$Name; Function->Illocutor=$Illocutor; Function->Expression=$Expression; $$=process_function(Function); }
		;


	
	Statements:	
		   Statement                                      { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=$Statement; $$=process_statements(Statements); }
		| Statements Statement                            { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=$1; Statements->Statement=$Statement; $$=process_statements(Statements); }
		;


	
	Statement:	
		  Action                                          { NEW(Statement, *((Literal **)&yylval)); Statement->Action=$Action; $$=process_statement(Statement); }
		| Flagging                                        { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=$Flagging; $$=process_statement(Statement); }
		;


	
	Action:	
		  Subject Predicates Separator                    { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Predicates Separator         { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Condition Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Condition Colon Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Condition Comma Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Condition Comma Colon Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Comma Predicates Separator   { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Comma Condition Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Comma Condition Colon Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Comma Condition Comma Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		| Subject Permission Comma Condition Comma Colon Predicates Separator { NEW(Action, *((Literal **)&yylval)); Action->Subject=$Subject; Action->Permission=$Permission; Action->Condition=$Condition; Action->Predicates=$Predicates; $$=process_action(Action); }
		;


	
	Subject:	
		  Symbols                                         { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=$Symbols; $$=process_subject(Subject); }
		;


	
	Symbols:	
		   Symbol                                         { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=$Symbol; $$=process_symbols(Symbols); }
		| Symbols Catena Symbol                           { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=$1; Symbols->Catena=$Catena; Symbols->Symbol=$Symbol; $$=process_symbols(Symbols); }
		;


	
	Symbol:	
		   Name                                           { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=$Name; $$=process_symbol(Symbol); }
		| Article Name                                    { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=$Article; Symbol->Name=$Name; $$=process_symbol(Symbol); }
		|  Type                                           { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=$Type; $$=process_symbol(Symbol); }
		| Article Type                                    { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=$Article; Symbol->Type=$Type; $$=process_symbol(Symbol); }
		;


	
	Catena:	
		  OR                                              { NEW(Catena, *((Literal **)&yylval)); $$=process_catena(Catena); }
		| Comma                                           { NEW(Catena, *((Literal **)&yylval)); $$=process_catena(Catena); }
		;


	
	Object:	
		  Symbol                                          { NEW(Object, *((Literal **)&yylval)); Object->Symbol=$Symbol; $$=process_object(Object); }
		| Reflexive                                       { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=$Reflexive; $$=process_object(Object); }
		| ESCROW                                          { NEW(Object, *((Literal **)&yylval)); $$=process_object(Object); }
		;


	
	Reflexive:	
		  MYSELF                                          { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| YOURSELF                                        { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| HERSELF                                         { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| HIMSELF                                         { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| ONESELF                                         { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| ITSELF                                          { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| THEMSELF                                        { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| OURSELVES                                       { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| YOURSELVES                                      { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		| THEMSELVES                                      { NEW(Reflexive, *((Literal **)&yylval)); $$=process_reflexive(Reflexive); }
		;


	
	Contract:	
		  This_Contract                                   { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=$This_Contract; $$=process_contract(Contract); }
		| All_Contracts                                   { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=$All_Contracts; $$=process_contract(Contract); }
		;


	
	Predicates:	
		  Predicates Comma Predicate                      { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AFTERWARDS Predicate           { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma IF SO Predicate                { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma IF SO AFTERWARDS Predicate     { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND Predicate                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND AFTERWARDS Predicate       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND IF SO Predicate            { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND IF SO AFTERWARDS Predicate { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND ALSO Predicate             { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND ALSO AFTERWARDS Predicate  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND ALSO IF SO Predicate       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND ALSO IF SO AFTERWARDS Predicate { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicates Comma AND WITH THIS Predicate        { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=$1; Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		| Predicate                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=$Predicate; $$=process_predicates(Predicates); }
		;


	
	Predicate:	
		  Certification                                   { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=$Certification; $$=process_predicate(Predicate); }
		| Declaration                                     { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=$Declaration; $$=process_predicate(Predicate); }
		| Filing                                          { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=$Filing; $$=process_predicate(Predicate); }
		| Registration                                    { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=$Registration; $$=process_predicate(Predicate); }
		| Grantment                                       { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=$Grantment; $$=process_predicate(Predicate); }
		| Appointment                                     { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=$Appointment; $$=process_predicate(Predicate); }
		| Fixture                                         { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=$Fixture; $$=process_predicate(Predicate); }
		| Setting                                         { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=$Setting; $$=process_predicate(Predicate); }
		| Payment                                         { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=$Payment; $$=process_predicate(Predicate); }
		| Sending                                         { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=$Sending; $$=process_predicate(Predicate); }
		| Notification                                    { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=$Notification; $$=process_predicate(Predicate); }
		| Termination                                     { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=$Termination; $$=process_predicate(Predicate); }
		;


	
	Permission:	
		  MAY                                             { NEW(Permission, *((Literal **)&yylval)); $$=process_permission(Permission); }
		;


	
	Certification:	
		  Certify Symbol                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=$Certify; Certification->Symbol=$Symbol; $$=process_certification(Certification); }
		| Certify Symbol Expression                       { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=$Certify; Certification->Symbol=$Symbol; Certification->Expression=$Expression; $$=process_certification(Certification); }
		| Certify Symbol AS Expression                    { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=$Certify; Certification->Symbol=$Symbol; Certification->Expression=$Expression; $$=process_certification(Certification); }
		| Certify Contract Symbol                         { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=$Certify; Certification->Contract=$Contract; Certification->Symbol=$Symbol; $$=process_certification(Certification); }
		| Certify Contract AS Symbol                      { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=$Certify; Certification->Contract=$Contract; Certification->Symbol=$Symbol; $$=process_certification(Certification); }
		;


	
	Certify:	
		  CERTIFY                                         { NEW(Certify, *((Literal **)&yylval)); $$=process_certify(Certify); }
		| CERTIFIES                                       { NEW(Certify, *((Literal **)&yylval)); $$=process_certify(Certify); }
		;


	
	Declaration:	
		  Declare Symbol                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=$Declare; Declaration->Symbol=$Symbol; $$=process_declaration(Declaration); }
		| Declare Symbol Expression                       { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=$Declare; Declaration->Symbol=$Symbol; Declaration->Expression=$Expression; $$=process_declaration(Declaration); }
		| Declare Symbol TO BE Expression                 { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=$Declare; Declaration->Symbol=$Symbol; Declaration->Expression=$Expression; $$=process_declaration(Declaration); }
		| Declare Contract Symbol                         { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=$Declare; Declaration->Contract=$Contract; Declaration->Symbol=$Symbol; $$=process_declaration(Declaration); }
		| Declare Contract AS Symbol                      { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=$Declare; Declaration->Contract=$Contract; Declaration->Symbol=$Symbol; $$=process_declaration(Declaration); }
		;


	
	Declare:	
		  DECLARE                                         { NEW(Declare, *((Literal **)&yylval)); $$=process_declare(Declare); }
		| DECLARES                                        { NEW(Declare, *((Literal **)&yylval)); $$=process_declare(Declare); }
		;


	
	Filing:	
		  File Symbol                                     { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		| File Symbol Expression                          { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; Filing->Expression=$Expression; $$=process_filing(Filing); }
		| File Symbol TO BE Expression                    { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; Filing->Expression=$Expression; $$=process_filing(Filing); }
		| File FOR Symbol                                 { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		| File FOR Symbol Expression                      { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; Filing->Expression=$Expression; $$=process_filing(Filing); }
		| File FOR Symbol TO BE Expression                { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Symbol=$Symbol; Filing->Expression=$Expression; $$=process_filing(Filing); }
		| File Contract Symbol                            { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Contract=$Contract; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		| File Contract TO BE Symbol                      { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Contract=$Contract; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		| File FOR Contract Symbol                        { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Contract=$Contract; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		| File FOR Contract TO BE Symbol                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=$File; Filing->Contract=$Contract; Filing->Symbol=$Symbol; $$=process_filing(Filing); }
		;


	
	File:	
		  FILE_                                           { NEW(File, *((Literal **)&yylval)); $$=process_file(File); }
		| FILES                                           { NEW(File, *((Literal **)&yylval)); $$=process_file(File); }
		;


	
	Registration:	
		  Register Symbol                                 { NEW(Registration, *((Literal **)&yylval)); Registration->Register=$Register; Registration->Symbol=$Symbol; $$=process_registration(Registration); }
		| Register Symbol Expression                      { NEW(Registration, *((Literal **)&yylval)); Registration->Register=$Register; Registration->Symbol=$Symbol; Registration->Expression=$Expression; $$=process_registration(Registration); }
		| Register Symbol AS Expression                   { NEW(Registration, *((Literal **)&yylval)); Registration->Register=$Register; Registration->Symbol=$Symbol; Registration->Expression=$Expression; $$=process_registration(Registration); }
		| Register Contract Symbol                        { NEW(Registration, *((Literal **)&yylval)); Registration->Register=$Register; Registration->Contract=$Contract; Registration->Symbol=$Symbol; $$=process_registration(Registration); }
		| Register Contract AS Symbol                     { NEW(Registration, *((Literal **)&yylval)); Registration->Register=$Register; Registration->Contract=$Contract; Registration->Symbol=$Symbol; $$=process_registration(Registration); }
		;


	
	Register:	
		  REGISTER                                        { NEW(Register, *((Literal **)&yylval)); $$=process_register(Register); }
		| REGISTERS                                       { NEW(Register, *((Literal **)&yylval)); $$=process_register(Register); }
		;


	
	Grantment:	
		  Grant Symbol                                    { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=$Grant; Grantment->Symbol=$Symbol; $$=process_grantment(Grantment); }
		;


	
	Grant:	
		  GRANT                                           { NEW(Grant, *((Literal **)&yylval)); $$=process_grant(Grant); }
		| GRANTS                                          { NEW(Grant, *((Literal **)&yylval)); $$=process_grant(Grant); }
		;


	
	Appointment:	
		  Appoint Symbol                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=$Appoint; Appointment->Symbol=$Symbol; $$=process_appointment(Appointment); }
		;


	
	Appoint:	
		  APPOINT                                         { NEW(Appoint, *((Literal **)&yylval)); $$=process_appoint(Appoint); }
		| APPOINTS                                        { NEW(Appoint, *((Literal **)&yylval)); $$=process_appoint(Appoint); }
		;


	
	Fixture:	
		  Fix Symbol                                      { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=$Fix; Fixture->Symbol=$Symbol; $$=process_fixture(Fixture); }
		| Fix Symbol AS Expression                        { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=$Fix; Fixture->Symbol=$Symbol; Fixture->Expression=$Expression; $$=process_fixture(Fixture); }
		| Fix Contract AS Symbol                          { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=$Fix; Fixture->Contract=$Contract; Fixture->Symbol=$Symbol; $$=process_fixture(Fixture); }
		;


	
	Fix:	
		  FIX                                             { NEW(Fix, *((Literal **)&yylval)); $$=process_fix(Fix); }
		| FIXES                                           { NEW(Fix, *((Literal **)&yylval)); $$=process_fix(Fix); }
		;


	
	Fixed:	
		  FIXED                                           { NEW(Fixed, *((Literal **)&yylval)); $$=process_fixed(Fixed); }
		;


	
	Setting:	
		  Illocutor Symbol                                { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		| Illocutor THEREFOR Symbol                       { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		| Illocutor THEREFORE Symbol                      { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		| Illocutor THEN Symbol                           { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		| Illocutor THEN THEREFOR Symbol                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		| Illocutor THEN THEREFORE Symbol                 { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=$Illocutor; Setting->Symbol=$Symbol; $$=process_setting(Setting); }
		;


	
	Illocutor:	
		  Be                                              { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=$Be; $$=process_illocutor(Illocutor); }
		| Be AS                                           { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=$Be; $$=process_illocutor(Illocutor); }
		| Be DEFINED                                      { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=$Be; $$=process_illocutor(Illocutor); }
		| Be DEFINED AS                                   { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=$Be; $$=process_illocutor(Illocutor); }
		;


	
	Be:	
		  BE                                              { NEW(Be, *((Literal **)&yylval)); $$=process_be(Be); }
		| IS                                              { NEW(Be, *((Literal **)&yylval)); $$=process_be(Be); }
		;


	
	Payment:	
		  Pay Expression Preposition Object               { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=$Pay; Payment->Expression=$Expression; Payment->Preposition=$Preposition; Payment->Object=$Object; $$=process_payment(Payment); }
		| Pay From_Escrow Expression Preposition Object   { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=$Pay; Payment->From_Escrow=$From_Escrow; Payment->Expression=$Expression; Payment->Preposition=$Preposition; Payment->Object=$Object; $$=process_payment(Payment); }
		| Pay Expression From_Escrow Preposition Object   { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=$Pay; Payment->Expression=$Expression; Payment->From_Escrow=$From_Escrow; Payment->Preposition=$Preposition; Payment->Object=$Object; $$=process_payment(Payment); }
		| Pay Escrow Preposition Object                   { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=$Pay; Payment->Escrow=$Escrow; Payment->Preposition=$Preposition; Payment->Object=$Object; $$=process_payment(Payment); }
		;


	
	Pay:	
		  PAY                                             { NEW(Pay, *((Literal **)&yylval)); $$=process_pay(Pay); }
		| PAYS                                            { NEW(Pay, *((Literal **)&yylval)); $$=process_pay(Pay); }
		| RETURN                                          { NEW(Pay, *((Literal **)&yylval)); $$=process_pay(Pay); }
		| RETURNS                                         { NEW(Pay, *((Literal **)&yylval)); $$=process_pay(Pay); }
		;


	
	Preposition:	
		  TO                                              { NEW(Preposition, *((Literal **)&yylval)); $$=process_preposition(Preposition); }
		| INTO                                            { NEW(Preposition, *((Literal **)&yylval)); $$=process_preposition(Preposition); }
		;


	
	Escrow:	
		   ESCROW                                         { NEW(Escrow, *((Literal **)&yylval)); $$=process_escrow(Escrow); }
		|  REMAINDER OF THE ESCROW                        { NEW(Escrow, *((Literal **)&yylval)); $$=process_escrow(Escrow); }
		| THE ESCROW                                      { NEW(Escrow, *((Literal **)&yylval)); $$=process_escrow(Escrow); }
		| THE REMAINDER OF THE ESCROW                     { NEW(Escrow, *((Literal **)&yylval)); $$=process_escrow(Escrow); }
		;


	
	From_Escrow:	
		  FROM ESCROW                                     { NEW(From_Escrow, *((Literal **)&yylval)); $$=process_from_escrow(From_Escrow); }
		| FROM REMAINDER OF THE ESCROW                    { NEW(From_Escrow, *((Literal **)&yylval)); $$=process_from_escrow(From_Escrow); }
		| FROM THE ESCROW                                 { NEW(From_Escrow, *((Literal **)&yylval)); $$=process_from_escrow(From_Escrow); }
		| FROM THE REMAINDER OF THE ESCROW                { NEW(From_Escrow, *((Literal **)&yylval)); $$=process_from_escrow(From_Escrow); }
		;


	
	Sending:	
		  Send Expression Preposition Object              { NEW(Sending, *((Literal **)&yylval)); Sending->Send=$Send; Sending->Expression=$Expression; Sending->Preposition=$Preposition; Sending->Object=$Object; $$=process_sending(Sending); }
		;


	
	Send:	
		  SEND                                            { NEW(Send, *((Literal **)&yylval)); $$=process_send(Send); }
		| SENDS                                           { NEW(Send, *((Literal **)&yylval)); $$=process_send(Send); }
		;


	
	Notification:	
		  Notify Object Preposition Expression            { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=$Notify; Notification->Object=$Object; Notification->Preposition=$Preposition; Notification->Expression=$Expression; $$=process_notification(Notification); }
		;


	
	Notify:	
		  NOTIFY                                          { NEW(Notify, *((Literal **)&yylval)); $$=process_notify(Notify); }
		| NOTIFIES                                        { NEW(Notify, *((Literal **)&yylval)); $$=process_notify(Notify); }
		;


	
	Termination:	
		  Terminate This_Contract                         { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=$Terminate; Termination->This_Contract=$This_Contract; $$=process_termination(Termination); }
		| Terminate All_Contracts                         { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=$Terminate; Termination->All_Contracts=$All_Contracts; $$=process_termination(Termination); }
		;


	
	Terminate:	
		  TERMINATE                                       { NEW(Terminate, *((Literal **)&yylval)); $$=process_terminate(Terminate); }
		| TERMINATES                                      { NEW(Terminate, *((Literal **)&yylval)); $$=process_terminate(Terminate); }
		;


	
	Flagging:	
		   Illocutor Symbol Separator                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		|  Illocutor THEREFORE Symbol Separator           { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		|  Illocutor THEN Symbol Separator                { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		|  Illocutor THEN THEREFORE Symbol Separator      { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		| This_Contract Illocutor Symbol Separator        { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=$This_Contract; Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		| This_Contract Illocutor THEREFORE Symbol Separator { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=$This_Contract; Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		| This_Contract Illocutor THEN Symbol Separator   { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=$This_Contract; Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		| This_Contract Illocutor THEN THEREFORE Symbol Separator { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=$This_Contract; Flagging->Illocutor=$Illocutor; Flagging->Symbol=$Symbol; $$=process_flagging(Flagging); }
		;


	
	Condition:	
		  If Expression                                   { NEW(Condition, *((Literal **)&yylval)); Condition->If=$If; Condition->Expression=$Expression; $$=process_condition(Condition); }
		| If Expression THEN                              { NEW(Condition, *((Literal **)&yylval)); Condition->If=$If; Condition->Expression=$Expression; $$=process_condition(Condition); }
		| If Expression Comma THEN                        { NEW(Condition, *((Literal **)&yylval)); Condition->If=$If; Condition->Expression=$Expression; $$=process_condition(Condition); }
		;


	
	If:	
		  IF                                              { NEW(If, *((Literal **)&yylval)); $$=process_if(If); }
		| GIVEN THAT                                      { NEW(If, *((Literal **)&yylval)); $$=process_if(If); }
		| PROVIDED                                        { NEW(If, *((Literal **)&yylval)); $$=process_if(If); }
		;


	
	Expression:	
		  Combination                                     { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=$Combination; $$=process_expression(Expression); }
		;


	
	Scalar_Comparison:	
		  Scalar_Expression Comparison_Operator Scalar_Expression { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=$1; Scalar_Comparison->Comparison_Operator=$Comparison_Operator; Scalar_Comparison->Scalar_Expression2=$3; $$=process_scalar_comparison(Scalar_Comparison); }
		;


	
	Comparison_Operator:	
		  Equal                                           { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=$Equal; $$=process_comparison_operator(Comparison_Operator); }
		| Later                                           { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=$Later; $$=process_comparison_operator(Comparison_Operator); }
		;


	
	Equal:	
		  EQUAL                                           { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| EQUAL TO                                        { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| EQUALING                                        { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| IS                                              { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| IS EQUAL                                        { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| IS EQUAL TO                                     { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| BEING                                           { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| BEING EQUAL                                     { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		| BEING EQUAL TO                                  { NEW(Equal, *((Literal **)&yylval)); $$=process_equal(Equal); }
		;


	
	Later:	
		  IS AT LEAST                                     { NEW(Later, *((Literal **)&yylval)); $$=process_later(Later); }
		| IS AT THE LEAST                                 { NEW(Later, *((Literal **)&yylval)); $$=process_later(Later); }
		| LIES AT LEAST                                   { NEW(Later, *((Literal **)&yylval)); $$=process_later(Later); }
		| LIES AT THE LEAST                               { NEW(Later, *((Literal **)&yylval)); $$=process_later(Later); }
		;


	
	Scalar_Expression:	
		  Symbol                                          { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=$Symbol; $$=process_scalar_expression(Scalar_Expression); }
		| Scalar                                          { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=$Scalar; $$=process_scalar_expression(Scalar_Expression); }
		| Point_In_Time                                   { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=$Point_In_Time; $$=process_scalar_expression(Scalar_Expression); }
		;


	
	Combination:	
		  Combinor                                        { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=$Combinor; $$=process_combination(Combination); }
		| Combinor Comma Combination                      { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=$Combinor; Combination->Combination=$3; $$=process_combination(Combination); }
		| Combinor Comma Combinator Combination           { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=$Combinor; Combination->Combinator=$Combinator; Combination->Combination=$4; $$=process_combination(Combination); }
		;


	
	Combinor:	
		  Combinand                                       { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=$Combinand; $$=process_combinor(Combinor); }
		| Combinand Combinator Combinor                   { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=$Combinand; Combinor->Combinator=$Combinator; Combinor->Combinor=$3; $$=process_combinor(Combinor); }
		;


	
	Combinand:	
		  Symbol                                          { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=$Symbol; $$=process_combinand(Combinand); }
		| Symbol Expiration                               { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=$Symbol; Combinand->Expiration=$Expiration; $$=process_combinand(Combinand); }
		| Scalar_Comparison                               { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=$Scalar_Comparison; $$=process_combinand(Combinand); }
		| Negation                                        { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=$Negation; $$=process_combinand(Combinand); }
		| Existence                                       { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=$Existence; $$=process_combinand(Combinand); }
		| Point_In_Time                                   { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=$Point_In_Time; $$=process_combinand(Combinand); }
		| Expiration                                      { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=$Expiration; $$=process_combinand(Combinand); }
		;


	
	Combinator:	
		  Or_                                             { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=$Or_; $$=process_combinator(Combinator); }
		| And                                             { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=$And; $$=process_combinator(Combinator); }
		| Neither                                         { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=$Neither; $$=process_combinator(Combinator); }
		| Nor                                             { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=$Nor; $$=process_combinator(Combinator); }
		;


	
	Or_:	
		  OR                                              { NEW(Or_, *((Literal **)&yylval)); $$=process_or_(Or_); }
		;


	
	And:	
		  AND                                             { NEW(And, *((Literal **)&yylval)); $$=process_and(And); }
		;


	
	Neither:	
		  NEITHER                                         { NEW(Neither, *((Literal **)&yylval)); $$=process_neither(Neither); }
		;


	
	Nor:	
		  NOR                                             { NEW(Nor, *((Literal **)&yylval)); $$=process_nor(Nor); }
		;


	
	Existence:	
		  Symbol Equal Fixed                              { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=$Symbol; Existence->Equal=$Equal; Existence->Fixed=$Fixed; $$=process_existence(Existence); }
		| THERE Be Symbol                                 { NEW(Existence, *((Literal **)&yylval)); Existence->Be=$Be; Existence->Symbol=$Symbol; $$=process_existence(Existence); }
		| Contract Be Symbol                              { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=$Contract; Existence->Be=$Be; Existence->Symbol=$Symbol; $$=process_existence(Existence); }
		| Symbol Being True                               { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=$Symbol; Existence->Being=$Being; Existence->True=$True; $$=process_existence(Existence); }
		;


	
	Negation:	
		  Negator Symbol                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=$Negator; Negation->Symbol=$Symbol; $$=process_negation(Negation); }
		| Symbol Negator Fixed                            { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=$Symbol; Negation->Negator=$Negator; Negation->Fixed=$Fixed; $$=process_negation(Negation); }
		| THERE Negator Symbol                            { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=$Negator; Negation->Symbol=$Symbol; $$=process_negation(Negation); }
		| Contract Negator Symbol                         { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=$Contract; Negation->Negator=$Negator; Negation->Symbol=$Symbol; $$=process_negation(Negation); }
		;


	
	Negator:	
		   NOT                                            { NEW(Negator, *((Literal **)&yylval)); $$=process_negator(Negator); }
		| Be NOT                                          { NEW(Negator, *((Literal **)&yylval)); Negator->Be=$Be; $$=process_negator(Negator); }
		|  NO                                             { NEW(Negator, *((Literal **)&yylval)); $$=process_negator(Negator); }
		| Be NO                                           { NEW(Negator, *((Literal **)&yylval)); Negator->Be=$Be; $$=process_negator(Negator); }
		;


	
	Being:	
		  IS                                              { NEW(Being, *((Literal **)&yylval)); $$=process_being(Being); }
		| HAS BEEN                                        { NEW(Being, *((Literal **)&yylval)); $$=process_being(Being); }
		| WAS                                             { NEW(Being, *((Literal **)&yylval)); $$=process_being(Being); }
		;


	
	True:	
		  TRUE                                            { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| YES                                             { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| CERTIFIED                                       { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| DECLARED                                        { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| ANNOUNCED                                       { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| FILED                                           { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| FILED FOR                                       { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| SIGNED OFF                                      { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		| SIGNED OFF ON                                   { NEW(True, *((Literal **)&yylval)); $$=process_true(True); }
		;


	
	Article:	
		  A                                               { NEW(Article, *((Literal **)&yylval)); $$=process_article(Article); }
		| AN                                              { NEW(Article, *((Literal **)&yylval)); $$=process_article(Article); }
		| THE                                             { NEW(Article, *((Literal **)&yylval)); $$=process_article(Article); }
		;


	
	Point_In_Time:	
		  Current_Time                                    { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=$Current_Time; $$=process_point_in_time(Point_In_Time); }
		| Relative_Time                                   { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=$Relative_Time; $$=process_point_in_time(Point_In_Time); }
		;


	
	Current_Time:	
		  THE CURRENT TIME                                { NEW(Current_Time, *((Literal **)&yylval)); $$=process_current_time(Current_Time); }
		| THE THEN CURRENT TIME                           { NEW(Current_Time, *((Literal **)&yylval)); $$=process_current_time(Current_Time); }
		| THE RESPECTIVE CURRENT TIME                     { NEW(Current_Time, *((Literal **)&yylval)); $$=process_current_time(Current_Time); }
		| THE RESPECTIVE THEN CURRENT TIME                { NEW(Current_Time, *((Literal **)&yylval)); $$=process_current_time(Current_Time); }
		| NOW                                             { NEW(Current_Time, *((Literal **)&yylval)); $$=process_current_time(Current_Time); }
		;


	
	Relative_Time:	
		  Duration PAST                                   { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=$Duration; $$=process_relative_time(Relative_Time); }
		| Duration PAST Symbol                            { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=$Duration; Relative_Time->Symbol=$Symbol; $$=process_relative_time(Relative_Time); }
		| Duration IN THE PAST                            { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=$Duration; $$=process_relative_time(Relative_Time); }
		| Duration IN THE PAST Symbol                     { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=$Duration; Relative_Time->Symbol=$Symbol; $$=process_relative_time(Relative_Time); }
		| Duration AFTER Symbol                           { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=$Duration; Relative_Time->Symbol=$Symbol; $$=process_relative_time(Relative_Time); }
		;


	
	Duration:	
		  Scalar_Expression Time_Unit                     { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=$Scalar_Expression; Duration->Time_Unit=$Time_Unit; $$=process_duration(Duration); }
		;


	
	Time_Unit:	
		  Years                                           { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=$Years; $$=process_time_unit(Time_Unit); }
		| Months                                          { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=$Months; $$=process_time_unit(Time_Unit); }
		| Weeks                                           { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=$Weeks; $$=process_time_unit(Time_Unit); }
		| Days                                            { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=$Days; $$=process_time_unit(Time_Unit); }
		| Hours                                           { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=$Hours; $$=process_time_unit(Time_Unit); }
		| Minutes                                         { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=$Minutes; $$=process_time_unit(Time_Unit); }
		| Seconds                                         { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=$Seconds; $$=process_time_unit(Time_Unit); }
		| Milliseconds                                    { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=$Milliseconds; $$=process_time_unit(Time_Unit); }
		;


	
	Years:	
		  YEAR                                            { NEW(Years, *((Literal **)&yylval)); $$=process_years(Years); }
		| YEARS                                           { NEW(Years, *((Literal **)&yylval)); $$=process_years(Years); }
		;


	
	Months:	
		  MONTH                                           { NEW(Months, *((Literal **)&yylval)); $$=process_months(Months); }
		| MONTHS                                          { NEW(Months, *((Literal **)&yylval)); $$=process_months(Months); }
		;


	
	Weeks:	
		  WEEK                                            { NEW(Weeks, *((Literal **)&yylval)); $$=process_weeks(Weeks); }
		| WEEKS                                           { NEW(Weeks, *((Literal **)&yylval)); $$=process_weeks(Weeks); }
		;


	
	Days:	
		  DAY                                             { NEW(Days, *((Literal **)&yylval)); $$=process_days(Days); }
		| DAYS                                            { NEW(Days, *((Literal **)&yylval)); $$=process_days(Days); }
		;


	
	Hours:	
		  HOUR                                            { NEW(Hours, *((Literal **)&yylval)); $$=process_hours(Hours); }
		| HOURS                                           { NEW(Hours, *((Literal **)&yylval)); $$=process_hours(Hours); }
		;


	
	Minutes:	
		  MINUTE                                          { NEW(Minutes, *((Literal **)&yylval)); $$=process_minutes(Minutes); }
		| MINUTES                                         { NEW(Minutes, *((Literal **)&yylval)); $$=process_minutes(Minutes); }
		;


	
	Seconds:	
		  SECOND                                          { NEW(Seconds, *((Literal **)&yylval)); $$=process_seconds(Seconds); }
		| SECONDS                                         { NEW(Seconds, *((Literal **)&yylval)); $$=process_seconds(Seconds); }
		;


	
	Milliseconds:	
		  MILLISECOND                                     { NEW(Milliseconds, *((Literal **)&yylval)); $$=process_milliseconds(Milliseconds); }
		| MILLISECONDS                                    { NEW(Milliseconds, *((Literal **)&yylval)); $$=process_milliseconds(Milliseconds); }
		;


	
	Expiration:	
		  HAS PASSED                                      { NEW(Expiration, *((Literal **)&yylval)); $$=process_expiration(Expiration); }
		|  PAST                                           { NEW(Expiration, *((Literal **)&yylval)); $$=process_expiration(Expiration); }
		| IS PAST                                         { NEW(Expiration, *((Literal **)&yylval)); $$=process_expiration(Expiration); }
		;


	Name: NAME						{ $$=$NAME; }
	    ;

	Description: DESCRIPTION						{ $$=$DESCRIPTION; }
	    ;

	Scalar: SCALAR						{ $$=$SCALAR; }
	    ;



%%

/* Epilogue */

bool core_document(char **production, Document *root, int indent, bool topcall, bool sibbling,
	bool highlight, bool subhighlight); // #core #tree
bool js_document(char **production, Document *root, int indent); // #javascript
bool sol_document(char **production, Document *root, int indent); // #solidity
bool sophia_document(char **production, Document *root, int indent); // #sophia
extern bool opt_produce_tree;
extern bool opt_produce_core;
extern bool opt_produce_javascript;
extern bool opt_produce_solidity;
extern bool opt_produce_sophia;
char *walk() {
	char *production = mtrac_strdup("");
	if(opt_verbose || opt_debug) fprintf(stderr, "• starting walk\n");
	if(opt_produce_javascript) {
		if(opt_verbose || opt_debug) fprintf(stderr, "• produce javascript\n");
		js_document(&production, root, 0); // #javascript
	} else if(opt_produce_solidity) {
		if(opt_verbose || opt_debug) fprintf(stderr, "• produce solidity\n");
		sol_document(&production, root, 0); // #solidity
	} else if(opt_produce_sophia) {
		if(opt_verbose || opt_debug) fprintf(stderr, "• produce sophia\n");
		sophia_document(&production, root, 0); // #sophia
	} else if(opt_produce_tree) {
		if(opt_verbose || opt_debug) fprintf(stderr, "• produce abstract syntax tree\n");
		core_document(&production, root, 0, true, false, false, false); // #tree #core
	} else { /* default */
		if(opt_verbose || opt_debug) fprintf(stderr, "• produce core listing\n");
		core_document(&production, root, 0, true, false, false, false); // #core
	}
	padcat(0,0,&production, "\
");
	return production;

}

extern int prec_line;
extern char *context;
extern char *prec_file;
extern char *yytext;
void yyerror(const char *s) {
	fprintf(stderr, "Lexon: %s -- check %s, line %d: %s\n>> %s\n", s, prec_file, prec_line, yytext, context);
	exit(1);
}

/* action handler (stub) functions */

Document *process_document(Document *Document) {
	if(opt_debug_actions) printf("actions: parsing Document '%s'\n", Document->Literal);
	// Document->Head
	// Document->Terms
	// Document->Covenants
	return Document;
}

Head *process_head(Head *Head) {
	if(opt_debug_actions) printf("actions: parsing Head '%s'\n", Head->Literal);
	// Head->Lex
	// Head->Preamble
	// Head->Comment
	// Head->Authors
	// Head->Lexon
	return Head;
}

Lex *process_lex(Lex *Lex) {
	if(opt_debug_actions) printf("actions: parsing Lex %s\n", Lex->Name);
	// Lex->Name
	return Lex;
}

Lexon *process_lexon(Lexon *Lexon) {
	if(opt_debug_actions) printf("actions: parsing Lexon %s\n", Lexon->Description);
	// Lexon->Description
	return Lexon;
}

Authors *process_authors(Authors *Authors) {
	if(opt_debug_actions) printf("actions: parsing Authors %s\n", Authors->Description);
	// Authors->Description
	return Authors;
}

Comment *process_comment(Comment *Comment) {
	if(opt_debug_actions) printf("actions: parsing Comment %s\n", Comment->Description);
	// Comment->Description
	return Comment;
}

Preamble *process_preamble(Preamble *Preamble) {
	if(opt_debug_actions) printf("actions: parsing Preamble %s\n", Preamble->Description);
	// Preamble->Description
	return Preamble;
}

Terms *process_terms(Terms *Terms) {
	if(opt_debug_actions) printf("actions: parsing Terms '%s'\n", Terms->Literal);
	// Terms->Provisions
	return Terms;
}

Covenants *process_covenants(Covenants *Covenants) {
	if(opt_debug_actions) printf("actions: parsing Covenants '%s'\n", Covenants->Literal);
	// Covenants->Covenant
	// Covenants->Covenants
	return Covenants;
}

Covenant *process_covenant(Covenant *Covenant) {
	if(opt_debug_actions) printf("actions: parsing Covenant %s\n", Covenant->Name);
	// Covenant->Name
	// Covenant->Provisions
	return Covenant;
}

Provisions *process_provisions(Provisions *Provisions) {
	if(opt_debug_actions) printf("actions: parsing Provisions '%s'\n", Provisions->Literal);
	// Provisions->Definitions
	// Provisions->Clauses
	// Provisions->Statements
	return Provisions;
}

Definitions *process_definitions(Definitions *Definitions) {
	if(opt_debug_actions) printf("actions: parsing Definitions '%s'\n", Definitions->Literal);
	// Definitions->Definition
	// Definitions->Definitions
	return Definitions;
}

Definition *process_definition(Definition *Definition) {
	if(opt_debug_actions) printf("actions: parsing Definition %s\n", Definition->Name);
	// Definition->Name
	// Definition->Type_Term
	// Definition->Article
	// Definition->This_Contract
	return Definition;
}

Type_Term *process_type_term(Type_Term *Type_Term) {
	if(opt_debug_actions) printf("actions: parsing Type_Term '%s'\n", Type_Term->Literal);
	// Type_Term->Type
	// Type_Term->Article
	return Type_Term;
}

Type *process_type(Type *Type) {
	if(opt_debug_actions) printf("actions: parsing Type '%s'\n", Type->Literal);
	// Type->Person
	// Type->Amount
	// Type->Time
	// Type->Binary
	// Type->Text
	// Type->Data
	return Type;
}

Person *process_person(Person *Person) {
	if(opt_debug_actions) printf("actions: parsing Person '%s'\n", Person->Literal);
	return Person;
}

Amount *process_amount(Amount *Amount) {
	if(opt_debug_actions) printf("actions: parsing Amount '%s'\n", Amount->Literal);
	return Amount;
}

Time *process_time(Time *Time) {
	if(opt_debug_actions) printf("actions: parsing Time '%s'\n", Time->Literal);
	return Time;
}

Binary *process_binary(Binary *Binary) {
	if(opt_debug_actions) printf("actions: parsing Binary '%s'\n", Binary->Literal);
	return Binary;
}

Text *process_text(Text *Text) {
	if(opt_debug_actions) printf("actions: parsing Text '%s'\n", Text->Literal);
	return Text;
}

Data *process_data(Data *Data) {
	if(opt_debug_actions) printf("actions: parsing Data '%s'\n", Data->Literal);
	return Data;
}

This_Contract *process_this_contract(This_Contract *This_Contract) {
	if(opt_debug_actions) printf("actions: parsing This_Contract %s\n", This_Contract->Name);
	// This_Contract->This
	// This_Contract->Name
	return This_Contract;
}

All_Contracts *process_all_contracts(All_Contracts *All_Contracts) {
	if(opt_debug_actions) printf("actions: parsing All_Contracts '%s'\n", All_Contracts->Literal);
	return All_Contracts;
}

This *process_this(This *This) {
	if(opt_debug_actions) printf("actions: parsing This '%s'\n", This->Literal);
	return This;
}

Clauses *process_clauses(Clauses *Clauses) {
	if(opt_debug_actions) printf("actions: parsing Clauses '%s'\n", Clauses->Literal);
	// Clauses->Clause
	// Clauses->Clauses
	return Clauses;
}

Clause *process_clause(Clause *Clause) {
	if(opt_debug_actions) printf("actions: parsing Clause %s\n", Clause->Name);
	// Clause->Name
	// Clause->Body
	return Clause;
}

Body *process_body(Body *Body) {
	if(opt_debug_actions) printf("actions: parsing Body '%s'\n", Body->Literal);
	// Body->Statements
	// Body->Function
	return Body;
}

Function *process_function(Function *Function) {
	if(opt_debug_actions) printf("actions: parsing Function %s\n", Function->Name);
	// Function->Name
	// Function->Illocutor
	// Function->Expression
	// Function->Article
	return Function;
}

Statements *process_statements(Statements *Statements) {
	if(opt_debug_actions) printf("actions: parsing Statements '%s'\n", Statements->Literal);
	// Statements->Statement
	// Statements->Statements
	return Statements;
}

Statement *process_statement(Statement *Statement) {
	if(opt_debug_actions) printf("actions: parsing Statement '%s'\n", Statement->Literal);
	// Statement->Action
	// Statement->Flagging
	return Statement;
}

Action *process_action(Action *Action) {
	if(opt_debug_actions) printf("actions: parsing Action '%s'\n", Action->Literal);
	// Action->Subject
	// Action->Predicates
	// Action->Permission
	// Action->Condition
	return Action;
}

Subject *process_subject(Subject *Subject) {
	if(opt_debug_actions) printf("actions: parsing Subject '%s'\n", Subject->Literal);
	// Subject->Symbols
	return Subject;
}

Symbols *process_symbols(Symbols *Symbols) {
	if(opt_debug_actions) printf("actions: parsing Symbols '%s'\n", Symbols->Literal);
	// Symbols->Symbol
	// Symbols->Symbols
	// Symbols->Catena
	return Symbols;
}

Symbol *process_symbol(Symbol *Symbol) {
	if(opt_debug_actions) printf("actions: parsing Symbol %s\n", Symbol->Name);
	// Symbol->Name
	// Symbol->Article
	// Symbol->Type
	return Symbol;
}

Catena *process_catena(Catena *Catena) {
	if(opt_debug_actions) printf("actions: parsing Catena '%s'\n", Catena->Literal);
	return Catena;
}

Object *process_object(Object *Object) {
	if(opt_debug_actions) printf("actions: parsing Object '%s'\n", Object->Literal);
	// Object->Symbol
	// Object->Reflexive
	return Object;
}

Reflexive *process_reflexive(Reflexive *Reflexive) {
	if(opt_debug_actions) printf("actions: parsing Reflexive '%s'\n", Reflexive->Literal);
	return Reflexive;
}

Contract *process_contract(Contract *Contract) {
	if(opt_debug_actions) printf("actions: parsing Contract '%s'\n", Contract->Literal);
	// Contract->This_Contract
	// Contract->All_Contracts
	return Contract;
}

Predicates *process_predicates(Predicates *Predicates) {
	if(opt_debug_actions) printf("actions: parsing Predicates '%s'\n", Predicates->Literal);
	// Predicates->Predicates
	// Predicates->Predicate
	return Predicates;
}

Predicate *process_predicate(Predicate *Predicate) {
	if(opt_debug_actions) printf("actions: parsing Predicate '%s'\n", Predicate->Literal);
	// Predicate->Certification
	// Predicate->Declaration
	// Predicate->Filing
	// Predicate->Registration
	// Predicate->Grantment
	// Predicate->Appointment
	// Predicate->Fixture
	// Predicate->Setting
	// Predicate->Payment
	// Predicate->Sending
	// Predicate->Notification
	// Predicate->Termination
	return Predicate;
}

Permission *process_permission(Permission *Permission) {
	if(opt_debug_actions) printf("actions: parsing Permission '%s'\n", Permission->Literal);
	return Permission;
}

Certification *process_certification(Certification *Certification) {
	if(opt_debug_actions) printf("actions: parsing Certification '%s'\n", Certification->Literal);
	// Certification->Certify
	// Certification->Symbol
	// Certification->Expression
	// Certification->Contract
	return Certification;
}

Certify *process_certify(Certify *Certify) {
	if(opt_debug_actions) printf("actions: parsing Certify '%s'\n", Certify->Literal);
	return Certify;
}

Declaration *process_declaration(Declaration *Declaration) {
	if(opt_debug_actions) printf("actions: parsing Declaration '%s'\n", Declaration->Literal);
	// Declaration->Declare
	// Declaration->Symbol
	// Declaration->Expression
	// Declaration->Contract
	return Declaration;
}

Declare *process_declare(Declare *Declare) {
	if(opt_debug_actions) printf("actions: parsing Declare '%s'\n", Declare->Literal);
	return Declare;
}

Filing *process_filing(Filing *Filing) {
	if(opt_debug_actions) printf("actions: parsing Filing '%s'\n", Filing->Literal);
	// Filing->File
	// Filing->Symbol
	// Filing->Expression
	// Filing->Contract
	return Filing;
}

File *process_file(File *File) {
	if(opt_debug_actions) printf("actions: parsing File '%s'\n", File->Literal);
	return File;
}

Registration *process_registration(Registration *Registration) {
	if(opt_debug_actions) printf("actions: parsing Registration '%s'\n", Registration->Literal);
	// Registration->Register
	// Registration->Symbol
	// Registration->Expression
	// Registration->Contract
	return Registration;
}

Register *process_register(Register *Register) {
	if(opt_debug_actions) printf("actions: parsing Register '%s'\n", Register->Literal);
	return Register;
}

Grantment *process_grantment(Grantment *Grantment) {
	if(opt_debug_actions) printf("actions: parsing Grantment '%s'\n", Grantment->Literal);
	// Grantment->Grant
	// Grantment->Symbol
	return Grantment;
}

Grant *process_grant(Grant *Grant) {
	if(opt_debug_actions) printf("actions: parsing Grant '%s'\n", Grant->Literal);
	return Grant;
}

Appointment *process_appointment(Appointment *Appointment) {
	if(opt_debug_actions) printf("actions: parsing Appointment '%s'\n", Appointment->Literal);
	// Appointment->Appoint
	// Appointment->Symbol
	return Appointment;
}

Appoint *process_appoint(Appoint *Appoint) {
	if(opt_debug_actions) printf("actions: parsing Appoint '%s'\n", Appoint->Literal);
	return Appoint;
}

Fixture *process_fixture(Fixture *Fixture) {
	if(opt_debug_actions) printf("actions: parsing Fixture '%s'\n", Fixture->Literal);
	// Fixture->Fix
	// Fixture->Symbol
	// Fixture->Expression
	// Fixture->Contract
	return Fixture;
}

Fix *process_fix(Fix *Fix) {
	if(opt_debug_actions) printf("actions: parsing Fix '%s'\n", Fix->Literal);
	return Fix;
}

Fixed *process_fixed(Fixed *Fixed) {
	if(opt_debug_actions) printf("actions: parsing Fixed '%s'\n", Fixed->Literal);
	return Fixed;
}

Setting *process_setting(Setting *Setting) {
	if(opt_debug_actions) printf("actions: parsing Setting '%s'\n", Setting->Literal);
	// Setting->Illocutor
	// Setting->Symbol
	return Setting;
}

Illocutor *process_illocutor(Illocutor *Illocutor) {
	if(opt_debug_actions) printf("actions: parsing Illocutor '%s'\n", Illocutor->Literal);
	// Illocutor->Be
	return Illocutor;
}

Be *process_be(Be *Be) {
	if(opt_debug_actions) printf("actions: parsing Be '%s'\n", Be->Literal);
	return Be;
}

Payment *process_payment(Payment *Payment) {
	if(opt_debug_actions) printf("actions: parsing Payment '%s'\n", Payment->Literal);
	// Payment->Pay
	// Payment->Expression
	// Payment->Preposition
	// Payment->Object
	// Payment->From_Escrow
	// Payment->Escrow
	return Payment;
}

Pay *process_pay(Pay *Pay) {
	if(opt_debug_actions) printf("actions: parsing Pay '%s'\n", Pay->Literal);
	return Pay;
}

Preposition *process_preposition(Preposition *Preposition) {
	if(opt_debug_actions) printf("actions: parsing Preposition '%s'\n", Preposition->Literal);
	return Preposition;
}

Escrow *process_escrow(Escrow *Escrow) {
	if(opt_debug_actions) printf("actions: parsing Escrow '%s'\n", Escrow->Literal);
	return Escrow;
}

From_Escrow *process_from_escrow(From_Escrow *From_Escrow) {
	if(opt_debug_actions) printf("actions: parsing From_Escrow '%s'\n", From_Escrow->Literal);
	return From_Escrow;
}

Sending *process_sending(Sending *Sending) {
	if(opt_debug_actions) printf("actions: parsing Sending '%s'\n", Sending->Literal);
	// Sending->Send
	// Sending->Expression
	// Sending->Preposition
	// Sending->Object
	return Sending;
}

Send *process_send(Send *Send) {
	if(opt_debug_actions) printf("actions: parsing Send '%s'\n", Send->Literal);
	return Send;
}

Notification *process_notification(Notification *Notification) {
	if(opt_debug_actions) printf("actions: parsing Notification '%s'\n", Notification->Literal);
	// Notification->Notify
	// Notification->Object
	// Notification->Preposition
	// Notification->Expression
	return Notification;
}

Notify *process_notify(Notify *Notify) {
	if(opt_debug_actions) printf("actions: parsing Notify '%s'\n", Notify->Literal);
	return Notify;
}

Termination *process_termination(Termination *Termination) {
	if(opt_debug_actions) printf("actions: parsing Termination '%s'\n", Termination->Literal);
	// Termination->Terminate
	// Termination->This_Contract
	// Termination->All_Contracts
	return Termination;
}

Terminate *process_terminate(Terminate *Terminate) {
	if(opt_debug_actions) printf("actions: parsing Terminate '%s'\n", Terminate->Literal);
	return Terminate;
}

Flagging *process_flagging(Flagging *Flagging) {
	if(opt_debug_actions) printf("actions: parsing Flagging '%s'\n", Flagging->Literal);
	// Flagging->Illocutor
	// Flagging->Symbol
	// Flagging->This_Contract
	return Flagging;
}

Condition *process_condition(Condition *Condition) {
	if(opt_debug_actions) printf("actions: parsing Condition '%s'\n", Condition->Literal);
	// Condition->If
	// Condition->Expression
	return Condition;
}

If *process_if(If *If) {
	if(opt_debug_actions) printf("actions: parsing If '%s'\n", If->Literal);
	return If;
}

Expression *process_expression(Expression *Expression) {
	if(opt_debug_actions) printf("actions: parsing Expression '%s'\n", Expression->Literal);
	// Expression->Combination
	return Expression;
}

Scalar_Comparison *process_scalar_comparison(Scalar_Comparison *Scalar_Comparison) {
	if(opt_debug_actions) printf("actions: parsing Scalar_Comparison '%s'\n", Scalar_Comparison->Literal);
	// Scalar_Comparison->Scalar_Expression
	// Scalar_Comparison->Comparison_Operator
	// Scalar_Comparison->Scalar_Expression2
	return Scalar_Comparison;
}

Comparison_Operator *process_comparison_operator(Comparison_Operator *Comparison_Operator) {
	if(opt_debug_actions) printf("actions: parsing Comparison_Operator '%s'\n", Comparison_Operator->Literal);
	// Comparison_Operator->Equal
	// Comparison_Operator->Later
	return Comparison_Operator;
}

Equal *process_equal(Equal *Equal) {
	if(opt_debug_actions) printf("actions: parsing Equal '%s'\n", Equal->Literal);
	return Equal;
}

Later *process_later(Later *Later) {
	if(opt_debug_actions) printf("actions: parsing Later '%s'\n", Later->Literal);
	return Later;
}

Scalar_Expression *process_scalar_expression(Scalar_Expression *Scalar_Expression) {
	if(opt_debug_actions) printf("actions: parsing Scalar_Expression %s\n", Scalar_Expression->Scalar);
	// Scalar_Expression->Symbol
	// Scalar_Expression->Scalar
	// Scalar_Expression->Point_In_Time
	return Scalar_Expression;
}

Combination *process_combination(Combination *Combination) {
	if(opt_debug_actions) printf("actions: parsing Combination '%s'\n", Combination->Literal);
	// Combination->Combinor
	// Combination->Combination
	// Combination->Combinator
	return Combination;
}

Combinor *process_combinor(Combinor *Combinor) {
	if(opt_debug_actions) printf("actions: parsing Combinor '%s'\n", Combinor->Literal);
	// Combinor->Combinand
	// Combinor->Combinator
	// Combinor->Combinor
	return Combinor;
}

Combinand *process_combinand(Combinand *Combinand) {
	if(opt_debug_actions) printf("actions: parsing Combinand '%s'\n", Combinand->Literal);
	// Combinand->Symbol
	// Combinand->Expiration
	// Combinand->Scalar_Comparison
	// Combinand->Negation
	// Combinand->Existence
	// Combinand->Point_In_Time
	return Combinand;
}

Combinator *process_combinator(Combinator *Combinator) {
	if(opt_debug_actions) printf("actions: parsing Combinator '%s'\n", Combinator->Literal);
	// Combinator->Or_
	// Combinator->And
	// Combinator->Neither
	// Combinator->Nor
	return Combinator;
}

Or_ *process_or_(Or_ *Or_) {
	if(opt_debug_actions) printf("actions: parsing Or_ '%s'\n", Or_->Literal);
	return Or_;
}

And *process_and(And *And) {
	if(opt_debug_actions) printf("actions: parsing And '%s'\n", And->Literal);
	return And;
}

Neither *process_neither(Neither *Neither) {
	if(opt_debug_actions) printf("actions: parsing Neither '%s'\n", Neither->Literal);
	return Neither;
}

Nor *process_nor(Nor *Nor) {
	if(opt_debug_actions) printf("actions: parsing Nor '%s'\n", Nor->Literal);
	return Nor;
}

Existence *process_existence(Existence *Existence) {
	if(opt_debug_actions) printf("actions: parsing Existence '%s'\n", Existence->Literal);
	// Existence->Symbol
	// Existence->Equal
	// Existence->Fixed
	// Existence->Be
	// Existence->Contract
	// Existence->Being
	// Existence->True
	return Existence;
}

Negation *process_negation(Negation *Negation) {
	if(opt_debug_actions) printf("actions: parsing Negation '%s'\n", Negation->Literal);
	// Negation->Negator
	// Negation->Symbol
	// Negation->Fixed
	// Negation->Contract
	return Negation;
}

Negator *process_negator(Negator *Negator) {
	if(opt_debug_actions) printf("actions: parsing Negator '%s'\n", Negator->Literal);
	// Negator->Be
	return Negator;
}

Being *process_being(Being *Being) {
	if(opt_debug_actions) printf("actions: parsing Being '%s'\n", Being->Literal);
	return Being;
}

True *process_true(True *True) {
	if(opt_debug_actions) printf("actions: parsing True '%s'\n", True->Literal);
	return True;
}

Article *process_article(Article *Article) {
	if(opt_debug_actions) printf("actions: parsing Article '%s'\n", Article->Literal);
	return Article;
}

Point_In_Time *process_point_in_time(Point_In_Time *Point_In_Time) {
	if(opt_debug_actions) printf("actions: parsing Point_In_Time '%s'\n", Point_In_Time->Literal);
	// Point_In_Time->Current_Time
	// Point_In_Time->Relative_Time
	return Point_In_Time;
}

Current_Time *process_current_time(Current_Time *Current_Time) {
	if(opt_debug_actions) printf("actions: parsing Current_Time '%s'\n", Current_Time->Literal);
	return Current_Time;
}

Relative_Time *process_relative_time(Relative_Time *Relative_Time) {
	if(opt_debug_actions) printf("actions: parsing Relative_Time '%s'\n", Relative_Time->Literal);
	// Relative_Time->Duration
	// Relative_Time->Symbol
	return Relative_Time;
}

Duration *process_duration(Duration *Duration) {
	if(opt_debug_actions) printf("actions: parsing Duration '%s'\n", Duration->Literal);
	// Duration->Scalar_Expression
	// Duration->Time_Unit
	return Duration;
}

Time_Unit *process_time_unit(Time_Unit *Time_Unit) {
	if(opt_debug_actions) printf("actions: parsing Time_Unit '%s'\n", Time_Unit->Literal);
	// Time_Unit->Years
	// Time_Unit->Months
	// Time_Unit->Weeks
	// Time_Unit->Days
	// Time_Unit->Hours
	// Time_Unit->Minutes
	// Time_Unit->Seconds
	// Time_Unit->Milliseconds
	return Time_Unit;
}

Years *process_years(Years *Years) {
	if(opt_debug_actions) printf("actions: parsing Years '%s'\n", Years->Literal);
	return Years;
}

Months *process_months(Months *Months) {
	if(opt_debug_actions) printf("actions: parsing Months '%s'\n", Months->Literal);
	return Months;
}

Weeks *process_weeks(Weeks *Weeks) {
	if(opt_debug_actions) printf("actions: parsing Weeks '%s'\n", Weeks->Literal);
	return Weeks;
}

Days *process_days(Days *Days) {
	if(opt_debug_actions) printf("actions: parsing Days '%s'\n", Days->Literal);
	return Days;
}

Hours *process_hours(Hours *Hours) {
	if(opt_debug_actions) printf("actions: parsing Hours '%s'\n", Hours->Literal);
	return Hours;
}

Minutes *process_minutes(Minutes *Minutes) {
	if(opt_debug_actions) printf("actions: parsing Minutes '%s'\n", Minutes->Literal);
	return Minutes;
}

Seconds *process_seconds(Seconds *Seconds) {
	if(opt_debug_actions) printf("actions: parsing Seconds '%s'\n", Seconds->Literal);
	return Seconds;
}

Milliseconds *process_milliseconds(Milliseconds *Milliseconds) {
	if(opt_debug_actions) printf("actions: parsing Milliseconds '%s'\n", Milliseconds->Literal);
	return Milliseconds;
}

Expiration *process_expiration(Expiration *Expiration) {
	if(opt_debug_actions) printf("actions: parsing Expiration '%s'\n", Expiration->Literal);
	return Expiration;
}

