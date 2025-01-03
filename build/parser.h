/* A Bison parser, made by GNU Bison 3.8.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 10 "parser.y"


#define CYCLE_2 true

#include <stdio.h>
#include <string.h>

int yylex(void);
void yyerror(const char *);

void mtrac_gross(void *);

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

#line 826 "parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Separator = 258,               /* Separator  */
    Comma = 259,                   /* Comma  */
    Colon = 260,                   /* Colon  */
    Semicolon = 261,               /* Semicolon  */
    Dash = 262,                    /* Dash  */
    Percent = 263,                 /* Percent  */
    Quote = 264,                   /* Quote  */
    NAME = 265,                    /* NAME  */
    DESCRIPTION = 266,             /* DESCRIPTION  */
    SCALAR = 267,                  /* SCALAR  */
    AUTHOR = 268,                  /* AUTHOR  */
    AUTHORS = 269,                 /* AUTHORS  */
    CLAUSE = 270,                  /* CLAUSE  */
    COMMENT = 271,                 /* COMMENT  */
    COMMENTS = 272,                /* COMMENTS  */
    GENERAL = 273,                 /* GENERAL  */
    LEX = 274,                     /* LEX  */
    LEXON = 275,                   /* LEXON  */
    PER = 276,                     /* PER  */
    PREAMBLE = 277,                /* PREAMBLE  */
    TERMS = 278,                   /* TERMS  */
    A = 279,                       /* A  */
    AFTER = 280,                   /* AFTER  */
    AFTERWARDS = 281,              /* AFTERWARDS  */
    ALL = 282,                     /* ALL  */
    ALSO = 283,                    /* ALSO  */
    AMOUNT = 284,                  /* AMOUNT  */
    AN = 285,                      /* AN  */
    AND = 286,                     /* AND  */
    ANNOUNCED = 287,               /* ANNOUNCED  */
    APPOINT = 288,                 /* APPOINT  */
    APPOINTS = 289,                /* APPOINTS  */
    AS = 290,                      /* AS  */
    AT = 291,                      /* AT  */
    BE = 292,                      /* BE  */
    BEEN = 293,                    /* BEEN  */
    BEING = 294,                   /* BEING  */
    BINARY = 295,                  /* BINARY  */
    CERTIFIED = 296,               /* CERTIFIED  */
    CERTIFIES = 297,               /* CERTIFIES  */
    CERTIFY = 298,                 /* CERTIFY  */
    CONTRACT = 299,                /* CONTRACT  */
    CONTRACTS = 300,               /* CONTRACTS  */
    CURRENT = 301,                 /* CURRENT  */
    DATA = 302,                    /* DATA  */
    DAY = 303,                     /* DAY  */
    DAYS = 304,                    /* DAYS  */
    DECLARE = 305,                 /* DECLARE  */
    DECLARED = 306,                /* DECLARED  */
    DECLARES = 307,                /* DECLARES  */
    DEFINED = 308,                 /* DEFINED  */
    EQUAL = 309,                   /* EQUAL  */
    EQUALING = 310,                /* EQUALING  */
    ESCROW = 311,                  /* ESCROW  */
    FILE_ = 312,                   /* FILE_  */
    FILED = 313,                   /* FILED  */
    FILES = 314,                   /* FILES  */
    FIX = 315,                     /* FIX  */
    FIXED = 316,                   /* FIXED  */
    FIXES = 317,                   /* FIXES  */
    FOR = 318,                     /* FOR  */
    FROM = 319,                    /* FROM  */
    GIVEN = 320,                   /* GIVEN  */
    GRANT = 321,                   /* GRANT  */
    GRANTS = 322,                  /* GRANTS  */
    HAS = 323,                     /* HAS  */
    HERSELF = 324,                 /* HERSELF  */
    HIMSELF = 325,                 /* HIMSELF  */
    HOUR = 326,                    /* HOUR  */
    HOURS = 327,                   /* HOURS  */
    IF = 328,                      /* IF  */
    IN = 329,                      /* IN  */
    INTO = 330,                    /* INTO  */
    IS = 331,                      /* IS  */
    ITSELF = 332,                  /* ITSELF  */
    LEAST = 333,                   /* LEAST  */
    LIES = 334,                    /* LIES  */
    MAY = 335,                     /* MAY  */
    MILLISECOND = 336,             /* MILLISECOND  */
    MILLISECONDS = 337,            /* MILLISECONDS  */
    MINUTE = 338,                  /* MINUTE  */
    MINUTES = 339,                 /* MINUTES  */
    MONTH = 340,                   /* MONTH  */
    MONTHS = 341,                  /* MONTHS  */
    MYSELF = 342,                  /* MYSELF  */
    NEITHER = 343,                 /* NEITHER  */
    NO = 344,                      /* NO  */
    NOR = 345,                     /* NOR  */
    NOT = 346,                     /* NOT  */
    NOTIFIES = 347,                /* NOTIFIES  */
    NOTIFY = 348,                  /* NOTIFY  */
    NOW = 349,                     /* NOW  */
    OF = 350,                      /* OF  */
    OFF = 351,                     /* OFF  */
    ON = 352,                      /* ON  */
    ONESELF = 353,                 /* ONESELF  */
    OR = 354,                      /* OR  */
    OURSELVES = 355,               /* OURSELVES  */
    PASSED = 356,                  /* PASSED  */
    PAST = 357,                    /* PAST  */
    PAY = 358,                     /* PAY  */
    PAYS = 359,                    /* PAYS  */
    PERSON = 360,                  /* PERSON  */
    PROVIDED = 361,                /* PROVIDED  */
    REGISTER = 362,                /* REGISTER  */
    REGISTERS = 363,               /* REGISTERS  */
    REMAINDER = 364,               /* REMAINDER  */
    RESPECTIVE = 365,              /* RESPECTIVE  */
    RETURN = 366,                  /* RETURN  */
    RETURNS = 367,                 /* RETURNS  */
    SECOND = 368,                  /* SECOND  */
    SECONDS = 369,                 /* SECONDS  */
    SEND = 370,                    /* SEND  */
    SENDS = 371,                   /* SENDS  */
    SIGNED = 372,                  /* SIGNED  */
    SO = 373,                      /* SO  */
    TERMINATE = 374,               /* TERMINATE  */
    TERMINATES = 375,              /* TERMINATES  */
    TEXT = 376,                    /* TEXT  */
    THAT = 377,                    /* THAT  */
    THE = 378,                     /* THE  */
    THEMSELF = 379,                /* THEMSELF  */
    THEMSELVES = 380,              /* THEMSELVES  */
    THEN = 381,                    /* THEN  */
    THERE = 382,                   /* THERE  */
    THEREFOR = 383,                /* THEREFOR  */
    THEREFORE = 384,               /* THEREFORE  */
    THESE = 385,                   /* THESE  */
    THIS = 386,                    /* THIS  */
    TIME = 387,                    /* TIME  */
    TO = 388,                      /* TO  */
    TRUE = 389,                    /* TRUE  */
    WAS = 390,                     /* WAS  */
    WEEK = 391,                    /* WEEK  */
    WEEKS = 392,                   /* WEEKS  */
    WITH = 393,                    /* WITH  */
    YEAR = 394,                    /* YEAR  */
    YEARS = 395,                   /* YEARS  */
    YES = 396,                     /* YES  */
    YOURSELF = 397,                /* YOURSELF  */
    YOURSELVES = 398               /* YOURSELVES  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
  Action * Action;                         /* Action  */
  All_Contracts * All_Contracts;           /* All_Contracts  */
  Amount * Amount;                         /* Amount  */
  And * And;                               /* And  */
  Appoint * Appoint;                       /* Appoint  */
  Appointment * Appointment;               /* Appointment  */
  Article * Article;                       /* Article  */
  Authors * Authors;                       /* Authors  */
  Be * Be;                                 /* Be  */
  Being * Being;                           /* Being  */
  Binary * Binary;                         /* Binary  */
  Body * Body;                             /* Body  */
  Catena * Catena;                         /* Catena  */
  Certification * Certification;           /* Certification  */
  Certify * Certify;                       /* Certify  */
  Clause * Clause;                         /* Clause  */
  Clauses * Clauses;                       /* Clauses  */
  Combinand * Combinand;                   /* Combinand  */
  Combination * Combination;               /* Combination  */
  Combinator * Combinator;                 /* Combinator  */
  Combinor * Combinor;                     /* Combinor  */
  Comment * Comment;                       /* Comment  */
  Comparison_Operator * Comparison_Operator; /* Comparison_Operator  */
  Condition * Condition;                   /* Condition  */
  Contract * Contract;                     /* Contract  */
  Covenant * Covenant;                     /* Covenant  */
  Covenants * Covenants;                   /* Covenants  */
  Current_Time * Current_Time;             /* Current_Time  */
  Data * Data;                             /* Data  */
  Days * Days;                             /* Days  */
  Declaration * Declaration;               /* Declaration  */
  Declare * Declare;                       /* Declare  */
  Definition * Definition;                 /* Definition  */
  Definitions * Definitions;               /* Definitions  */
  Description * DESCRIPTION;               /* DESCRIPTION  */
  Description * Description;               /* Description  */
  Document * Document;                     /* Document  */
  Duration * Duration;                     /* Duration  */
  Equal * Equal;                           /* Equal  */
  Escrow * Escrow;                         /* Escrow  */
  Existence * Existence;                   /* Existence  */
  Expiration * Expiration;                 /* Expiration  */
  Expression * Expression;                 /* Expression  */
  File * File;                             /* File  */
  Filing * Filing;                         /* Filing  */
  Fix * Fix;                               /* Fix  */
  Fixed * Fixed;                           /* Fixed  */
  Fixture * Fixture;                       /* Fixture  */
  Flagging * Flagging;                     /* Flagging  */
  From_Escrow * From_Escrow;               /* From_Escrow  */
  Function * Function;                     /* Function  */
  Grant * Grant;                           /* Grant  */
  Grantment * Grantment;                   /* Grantment  */
  Head * Head;                             /* Head  */
  Hours * Hours;                           /* Hours  */
  If * If;                                 /* If  */
  Illocutor * Illocutor;                   /* Illocutor  */
  Later * Later;                           /* Later  */
  Lex * Lex;                               /* Lex  */
  Lexon * Lexon;                           /* Lexon  */
  Milliseconds * Milliseconds;             /* Milliseconds  */
  Minutes * Minutes;                       /* Minutes  */
  Months * Months;                         /* Months  */
  Name * NAME;                             /* NAME  */
  Name * Name;                             /* Name  */
  Negation * Negation;                     /* Negation  */
  Negator * Negator;                       /* Negator  */
  Neither * Neither;                       /* Neither  */
  Nor * Nor;                               /* Nor  */
  Notification * Notification;             /* Notification  */
  Notify * Notify;                         /* Notify  */
  Object * Object;                         /* Object  */
  Or_ * Or_;                               /* Or_  */
  Pay * Pay;                               /* Pay  */
  Payment * Payment;                       /* Payment  */
  Permission * Permission;                 /* Permission  */
  Person * Person;                         /* Person  */
  Point_In_Time * Point_In_Time;           /* Point_In_Time  */
  Preamble * Preamble;                     /* Preamble  */
  Predicate * Predicate;                   /* Predicate  */
  Predicates * Predicates;                 /* Predicates  */
  Preposition * Preposition;               /* Preposition  */
  Provisions * Provisions;                 /* Provisions  */
  Reflexive * Reflexive;                   /* Reflexive  */
  Register * Register;                     /* Register  */
  Registration * Registration;             /* Registration  */
  Relative_Time * Relative_Time;           /* Relative_Time  */
  Scalar * SCALAR;                         /* SCALAR  */
  Scalar * Scalar;                         /* Scalar  */
  Scalar_Comparison * Scalar_Comparison;   /* Scalar_Comparison  */
  Scalar_Expression * Scalar_Expression;   /* Scalar_Expression  */
  Seconds * Seconds;                       /* Seconds  */
  Send * Send;                             /* Send  */
  Sending * Sending;                       /* Sending  */
  Setting * Setting;                       /* Setting  */
  Statement * Statement;                   /* Statement  */
  Statements * Statements;                 /* Statements  */
  Subject * Subject;                       /* Subject  */
  Symbol * Symbol;                         /* Symbol  */
  Symbols * Symbols;                       /* Symbols  */
  Terminate * Terminate;                   /* Terminate  */
  Termination * Termination;               /* Termination  */
  Terms * Terms;                           /* Terms  */
  Text * Text;                             /* Text  */
  This * This;                             /* This  */
  This_Contract * This_Contract;           /* This_Contract  */
  Time * Time;                             /* Time  */
  Time_Unit * Time_Unit;                   /* Time_Unit  */
  True * True;                             /* True  */
  Type * Type;                             /* Type  */
  Type_Term * Type_Term;                   /* Type_Term  */
  Weeks * Weeks;                           /* Weeks  */
  Years * Years;                           /* Years  */

#line 1100 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
