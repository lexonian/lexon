/* A Bison parser, made by GNU Bison 3.8.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "parser.y"


/* Prologue */

/* - */

#line 65 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Separator = 3,                  /* Separator  */
  YYSYMBOL_Comma = 4,                      /* Comma  */
  YYSYMBOL_Colon = 5,                      /* Colon  */
  YYSYMBOL_Semicolon = 6,                  /* Semicolon  */
  YYSYMBOL_Dash = 7,                       /* Dash  */
  YYSYMBOL_Percent = 8,                    /* Percent  */
  YYSYMBOL_Quote = 9,                      /* Quote  */
  YYSYMBOL_NAME = 10,                      /* NAME  */
  YYSYMBOL_DESCRIPTION = 11,               /* DESCRIPTION  */
  YYSYMBOL_SCALAR = 12,                    /* SCALAR  */
  YYSYMBOL_AUTHOR = 13,                    /* AUTHOR  */
  YYSYMBOL_AUTHORS = 14,                   /* AUTHORS  */
  YYSYMBOL_CLAUSE = 15,                    /* CLAUSE  */
  YYSYMBOL_COMMENT = 16,                   /* COMMENT  */
  YYSYMBOL_COMMENTS = 17,                  /* COMMENTS  */
  YYSYMBOL_GENERAL = 18,                   /* GENERAL  */
  YYSYMBOL_LEX = 19,                       /* LEX  */
  YYSYMBOL_LEXON = 20,                     /* LEXON  */
  YYSYMBOL_PER = 21,                       /* PER  */
  YYSYMBOL_PREAMBLE = 22,                  /* PREAMBLE  */
  YYSYMBOL_TERMS = 23,                     /* TERMS  */
  YYSYMBOL_A = 24,                         /* A  */
  YYSYMBOL_ACCEPT = 25,                    /* ACCEPT  */
  YYSYMBOL_ACCEPTS = 26,                   /* ACCEPTS  */
  YYSYMBOL_AFTER = 27,                     /* AFTER  */
  YYSYMBOL_AFTERWARDS = 28,                /* AFTERWARDS  */
  YYSYMBOL_ALL = 29,                       /* ALL  */
  YYSYMBOL_ALSO = 30,                      /* ALSO  */
  YYSYMBOL_AMOUNT = 31,                    /* AMOUNT  */
  YYSYMBOL_AN = 32,                        /* AN  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_ANNOUNCED = 34,                 /* ANNOUNCED  */
  YYSYMBOL_APPOINT = 35,                   /* APPOINT  */
  YYSYMBOL_APPOINTS = 36,                  /* APPOINTS  */
  YYSYMBOL_AS = 37,                        /* AS  */
  YYSYMBOL_AT = 38,                        /* AT  */
  YYSYMBOL_BE = 39,                        /* BE  */
  YYSYMBOL_BEEN = 40,                      /* BEEN  */
  YYSYMBOL_BEING = 41,                     /* BEING  */
  YYSYMBOL_BINARY = 42,                    /* BINARY  */
  YYSYMBOL_CERTIFIED = 43,                 /* CERTIFIED  */
  YYSYMBOL_CERTIFIES = 44,                 /* CERTIFIES  */
  YYSYMBOL_CERTIFY = 45,                   /* CERTIFY  */
  YYSYMBOL_COMING = 46,                    /* COMING  */
  YYSYMBOL_CONTRACT = 47,                  /* CONTRACT  */
  YYSYMBOL_CONTRACTS = 48,                 /* CONTRACTS  */
  YYSYMBOL_CURRENT = 49,                   /* CURRENT  */
  YYSYMBOL_DATA = 50,                      /* DATA  */
  YYSYMBOL_DAY = 51,                       /* DAY  */
  YYSYMBOL_DAYS = 52,                      /* DAYS  */
  YYSYMBOL_DECLARE = 53,                   /* DECLARE  */
  YYSYMBOL_DECLARED = 54,                  /* DECLARED  */
  YYSYMBOL_DECLARES = 55,                  /* DECLARES  */
  YYSYMBOL_DEFINED = 56,                   /* DEFINED  */
  YYSYMBOL_EQUAL = 57,                     /* EQUAL  */
  YYSYMBOL_EQUALING = 58,                  /* EQUALING  */
  YYSYMBOL_ESCROW = 59,                    /* ESCROW  */
  YYSYMBOL_FILE_ = 60,                     /* FILE_  */
  YYSYMBOL_FILED = 61,                     /* FILED  */
  YYSYMBOL_FILES = 62,                     /* FILES  */
  YYSYMBOL_FIX = 63,                       /* FIX  */
  YYSYMBOL_FIXED = 64,                     /* FIXED  */
  YYSYMBOL_FIXES = 65,                     /* FIXES  */
  YYSYMBOL_FOR = 66,                       /* FOR  */
  YYSYMBOL_FROM = 67,                      /* FROM  */
  YYSYMBOL_GIVEN = 68,                     /* GIVEN  */
  YYSYMBOL_GRANT = 69,                     /* GRANT  */
  YYSYMBOL_GRANTS = 70,                    /* GRANTS  */
  YYSYMBOL_GREATER = 71,                   /* GREATER  */
  YYSYMBOL_HAS = 72,                       /* HAS  */
  YYSYMBOL_HERSELF = 73,                   /* HERSELF  */
  YYSYMBOL_HIMSELF = 74,                   /* HIMSELF  */
  YYSYMBOL_HOUR = 75,                      /* HOUR  */
  YYSYMBOL_HOURS = 76,                     /* HOURS  */
  YYSYMBOL_IF = 77,                        /* IF  */
  YYSYMBOL_IN = 78,                        /* IN  */
  YYSYMBOL_INCOMING = 79,                  /* INCOMING  */
  YYSYMBOL_INTO = 80,                      /* INTO  */
  YYSYMBOL_IS = 81,                        /* IS  */
  YYSYMBOL_ITSELF = 82,                    /* ITSELF  */
  YYSYMBOL_LEAST = 83,                     /* LEAST  */
  YYSYMBOL_LESS = 84,                      /* LESS  */
  YYSYMBOL_LIES = 85,                      /* LIES  */
  YYSYMBOL_MAY = 86,                       /* MAY  */
  YYSYMBOL_MILLISECOND = 87,               /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 88,              /* MILLISECONDS  */
  YYSYMBOL_MINUTE = 89,                    /* MINUTE  */
  YYSYMBOL_MINUTES = 90,                   /* MINUTES  */
  YYSYMBOL_MONTH = 91,                     /* MONTH  */
  YYSYMBOL_MONTHS = 92,                    /* MONTHS  */
  YYSYMBOL_MYSELF = 93,                    /* MYSELF  */
  YYSYMBOL_NEITHER = 94,                   /* NEITHER  */
  YYSYMBOL_NEW = 95,                       /* NEW  */
  YYSYMBOL_NEXT = 96,                      /* NEXT  */
  YYSYMBOL_NO = 97,                        /* NO  */
  YYSYMBOL_NOR = 98,                       /* NOR  */
  YYSYMBOL_NOT = 99,                       /* NOT  */
  YYSYMBOL_NOTIFIES = 100,                 /* NOTIFIES  */
  YYSYMBOL_NOTIFY = 101,                   /* NOTIFY  */
  YYSYMBOL_NOW = 102,                      /* NOW  */
  YYSYMBOL_OF = 103,                       /* OF  */
  YYSYMBOL_OFF = 104,                      /* OFF  */
  YYSYMBOL_ON = 105,                       /* ON  */
  YYSYMBOL_ONESELF = 106,                  /* ONESELF  */
  YYSYMBOL_OR = 107,                       /* OR  */
  YYSYMBOL_OURSELVES = 108,                /* OURSELVES  */
  YYSYMBOL_PASSED = 109,                   /* PASSED  */
  YYSYMBOL_PAST = 110,                     /* PAST  */
  YYSYMBOL_PAY = 111,                      /* PAY  */
  YYSYMBOL_PAYS = 112,                     /* PAYS  */
  YYSYMBOL_PERSON = 113,                   /* PERSON  */
  YYSYMBOL_PROVIDED = 114,                 /* PROVIDED  */
  YYSYMBOL_REGISTER = 115,                 /* REGISTER  */
  YYSYMBOL_REGISTERS = 116,                /* REGISTERS  */
  YYSYMBOL_REMAINDER = 117,                /* REMAINDER  */
  YYSYMBOL_REPAY = 118,                    /* REPAY  */
  YYSYMBOL_REPAYS = 119,                   /* REPAYS  */
  YYSYMBOL_RESPECTIVE = 120,               /* RESPECTIVE  */
  YYSYMBOL_RETURN = 121,                   /* RETURN  */
  YYSYMBOL_RETURNS = 122,                  /* RETURNS  */
  YYSYMBOL_SECOND = 123,                   /* SECOND  */
  YYSYMBOL_SECONDS = 124,                  /* SECONDS  */
  YYSYMBOL_SEND = 125,                     /* SEND  */
  YYSYMBOL_SENDS = 126,                    /* SENDS  */
  YYSYMBOL_SIGNED = 127,                   /* SIGNED  */
  YYSYMBOL_SMALLER = 128,                  /* SMALLER  */
  YYSYMBOL_SO = 129,                       /* SO  */
  YYSYMBOL_TERMINATE = 130,                /* TERMINATE  */
  YYSYMBOL_TERMINATES = 131,               /* TERMINATES  */
  YYSYMBOL_TEXT = 132,                     /* TEXT  */
  YYSYMBOL_THAN = 133,                     /* THAN  */
  YYSYMBOL_THAT = 134,                     /* THAT  */
  YYSYMBOL_THE = 135,                      /* THE  */
  YYSYMBOL_THEMSELF = 136,                 /* THEMSELF  */
  YYSYMBOL_THEMSELVES = 137,               /* THEMSELVES  */
  YYSYMBOL_THEN = 138,                     /* THEN  */
  YYSYMBOL_THERE = 139,                    /* THERE  */
  YYSYMBOL_THEREFOR = 140,                 /* THEREFOR  */
  YYSYMBOL_THEREFORE = 141,                /* THEREFORE  */
  YYSYMBOL_THESE = 142,                    /* THESE  */
  YYSYMBOL_THIS = 143,                     /* THIS  */
  YYSYMBOL_TIME = 144,                     /* TIME  */
  YYSYMBOL_TO = 145,                       /* TO  */
  YYSYMBOL_TRUE = 146,                     /* TRUE  */
  YYSYMBOL_WAS = 147,                      /* WAS  */
  YYSYMBOL_WEEK = 148,                     /* WEEK  */
  YYSYMBOL_WEEKS = 149,                    /* WEEKS  */
  YYSYMBOL_WITH = 150,                     /* WITH  */
  YYSYMBOL_YEAR = 151,                     /* YEAR  */
  YYSYMBOL_YEARS = 152,                    /* YEARS  */
  YYSYMBOL_YES = 153,                      /* YES  */
  YYSYMBOL_YET = 154,                      /* YET  */
  YYSYMBOL_YOURSELF = 155,                 /* YOURSELF  */
  YYSYMBOL_YOURSELVES = 156,               /* YOURSELVES  */
  YYSYMBOL_YYACCEPT = 157,                 /* $accept  */
  YYSYMBOL_Document = 158,                 /* Document  */
  YYSYMBOL_Head = 159,                     /* Head  */
  YYSYMBOL_Lex = 160,                      /* Lex  */
  YYSYMBOL_Lexon = 161,                    /* Lexon  */
  YYSYMBOL_Authors = 162,                  /* Authors  */
  YYSYMBOL_Comment = 163,                  /* Comment  */
  YYSYMBOL_Preamble = 164,                 /* Preamble  */
  YYSYMBOL_Terms = 165,                    /* Terms  */
  YYSYMBOL_Covenants = 166,                /* Covenants  */
  YYSYMBOL_Covenant = 167,                 /* Covenant  */
  YYSYMBOL_Provisions = 168,               /* Provisions  */
  YYSYMBOL_Definitions = 169,              /* Definitions  */
  YYSYMBOL_Definition = 170,               /* Definition  */
  YYSYMBOL_Type_Term = 171,                /* Type_Term  */
  YYSYMBOL_Type = 172,                     /* Type  */
  YYSYMBOL_Person = 173,                   /* Person  */
  YYSYMBOL_Amount = 174,                   /* Amount  */
  YYSYMBOL_Time = 175,                     /* Time  */
  YYSYMBOL_Binary = 176,                   /* Binary  */
  YYSYMBOL_Text = 177,                     /* Text  */
  YYSYMBOL_Data = 178,                     /* Data  */
  YYSYMBOL_This_Contract = 179,            /* This_Contract  */
  YYSYMBOL_All_Contracts = 180,            /* All_Contracts  */
  YYSYMBOL_This = 181,                     /* This  */
  YYSYMBOL_Clauses = 182,                  /* Clauses  */
  YYSYMBOL_Clause = 183,                   /* Clause  */
  YYSYMBOL_Body = 184,                     /* Body  */
  YYSYMBOL_Function = 185,                 /* Function  */
  YYSYMBOL_Statements = 186,               /* Statements  */
  YYSYMBOL_Statement = 187,                /* Statement  */
  YYSYMBOL_Action = 188,                   /* Action  */
  YYSYMBOL_Subject = 189,                  /* Subject  */
  YYSYMBOL_Symbols = 190,                  /* Symbols  */
  YYSYMBOL_Symbol = 191,                   /* Symbol  */
  YYSYMBOL_Catena = 192,                   /* Catena  */
  YYSYMBOL_Object = 193,                   /* Object  */
  YYSYMBOL_Reflexive = 194,                /* Reflexive  */
  YYSYMBOL_Contract = 195,                 /* Contract  */
  YYSYMBOL_Predicates = 196,               /* Predicates  */
  YYSYMBOL_Predicate = 197,                /* Predicate  */
  YYSYMBOL_Permission = 198,               /* Permission  */
  YYSYMBOL_Certification = 199,            /* Certification  */
  YYSYMBOL_Certify = 200,                  /* Certify  */
  YYSYMBOL_Declaration = 201,              /* Declaration  */
  YYSYMBOL_Declare = 202,                  /* Declare  */
  YYSYMBOL_Filing = 203,                   /* Filing  */
  YYSYMBOL_File = 204,                     /* File  */
  YYSYMBOL_Registration = 205,             /* Registration  */
  YYSYMBOL_Register = 206,                 /* Register  */
  YYSYMBOL_Grantment = 207,                /* Grantment  */
  YYSYMBOL_Grant = 208,                    /* Grant  */
  YYSYMBOL_Appointment = 209,              /* Appointment  */
  YYSYMBOL_Appoint = 210,                  /* Appoint  */
  YYSYMBOL_Acceptance = 211,               /* Acceptance  */
  YYSYMBOL_Accept = 212,                   /* Accept  */
  YYSYMBOL_Fixture = 213,                  /* Fixture  */
  YYSYMBOL_Fix = 214,                      /* Fix  */
  YYSYMBOL_Fixed = 215,                    /* Fixed  */
  YYSYMBOL_Setting = 216,                  /* Setting  */
  YYSYMBOL_Illocutor = 217,                /* Illocutor  */
  YYSYMBOL_Be = 218,                       /* Be  */
  YYSYMBOL_Payment = 219,                  /* Payment  */
  YYSYMBOL_Pay = 220,                      /* Pay  */
  YYSYMBOL_Preposition = 221,              /* Preposition  */
  YYSYMBOL_Escrow = 222,                   /* Escrow  */
  YYSYMBOL_From_Escrow = 223,              /* From_Escrow  */
  YYSYMBOL_Sending = 224,                  /* Sending  */
  YYSYMBOL_Send = 225,                     /* Send  */
  YYSYMBOL_Notification = 226,             /* Notification  */
  YYSYMBOL_Notify = 227,                   /* Notify  */
  YYSYMBOL_Termination = 228,              /* Termination  */
  YYSYMBOL_Terminate = 229,                /* Terminate  */
  YYSYMBOL_Flagging = 230,                 /* Flagging  */
  YYSYMBOL_Condition = 231,                /* Condition  */
  YYSYMBOL_If = 232,                       /* If  */
  YYSYMBOL_Expression = 233,               /* Expression  */
  YYSYMBOL_Scalar_Comparison = 234,        /* Scalar_Comparison  */
  YYSYMBOL_Comparison_Operator = 235,      /* Comparison_Operator  */
  YYSYMBOL_Equal = 236,                    /* Equal  */
  YYSYMBOL_Greater = 237,                  /* Greater  */
  YYSYMBOL_Less = 238,                     /* Less  */
  YYSYMBOL_Later = 239,                    /* Later  */
  YYSYMBOL_Scalar_Expression = 240,        /* Scalar_Expression  */
  YYSYMBOL_Combination = 241,              /* Combination  */
  YYSYMBOL_Combinor = 242,                 /* Combinor  */
  YYSYMBOL_Combinand = 243,                /* Combinand  */
  YYSYMBOL_Combinator = 244,               /* Combinator  */
  YYSYMBOL_Or_ = 245,                      /* Or_  */
  YYSYMBOL_And = 246,                      /* And  */
  YYSYMBOL_Neither = 247,                  /* Neither  */
  YYSYMBOL_Nor = 248,                      /* Nor  */
  YYSYMBOL_Existence = 249,                /* Existence  */
  YYSYMBOL_Negation = 250,                 /* Negation  */
  YYSYMBOL_Negator = 251,                  /* Negator  */
  YYSYMBOL_Being = 252,                    /* Being  */
  YYSYMBOL_True = 253,                     /* True  */
  YYSYMBOL_Article = 254,                  /* Article  */
  YYSYMBOL_New = 255,                      /* New  */
  YYSYMBOL_Point_In_Time = 256,            /* Point_In_Time  */
  YYSYMBOL_Current_Time = 257,             /* Current_Time  */
  YYSYMBOL_Relative_Time = 258,            /* Relative_Time  */
  YYSYMBOL_Duration = 259,                 /* Duration  */
  YYSYMBOL_Time_Unit = 260,                /* Time_Unit  */
  YYSYMBOL_Years = 261,                    /* Years  */
  YYSYMBOL_Months = 262,                   /* Months  */
  YYSYMBOL_Weeks = 263,                    /* Weeks  */
  YYSYMBOL_Days = 264,                     /* Days  */
  YYSYMBOL_Hours = 265,                    /* Hours  */
  YYSYMBOL_Minutes = 266,                  /* Minutes  */
  YYSYMBOL_Seconds = 267,                  /* Seconds  */
  YYSYMBOL_Milliseconds = 268,             /* Milliseconds  */
  YYSYMBOL_Expiration = 269,               /* Expiration  */
  YYSYMBOL_Timeliness = 270,               /* Timeliness  */
  YYSYMBOL_Name = 271,                     /* Name  */
  YYSYMBOL_Description = 272,              /* Description  */
  YYSYMBOL_Scalar = 273                    /* Scalar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  466
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  819
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 12
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   411

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1123,  1123,  1124,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1151,  1157,  1163,  1164,  1170,  1171,  1177,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1196,  1197,  1203,  1204,  1205,
    1206,  1212,  1213,  1214,  1215,  1221,  1222,  1228,  1229,  1230,
    1231,  1237,  1238,  1244,  1245,  1246,  1247,  1248,  1249,  1255,
    1261,  1267,  1273,  1279,  1285,  1291,  1292,  1298,  1304,  1305,
    1311,  1312,  1318,  1324,  1325,  1331,  1332,  1333,  1334,  1340,
    1341,  1347,  1348,  1354,  1355,  1356,  1357,  1358,  1359,  1360,
    1361,  1362,  1363,  1364,  1370,  1376,  1377,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1396,  1397,  1403,  1404,  1405,
    1406,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1427,  1428,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1453,  1454,  1455,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,
    1471,  1477,  1478,  1479,  1480,  1481,  1487,  1488,  1494,  1495,
    1496,  1497,  1498,  1504,  1505,  1511,  1512,  1513,  1514,  1515,
    1516,  1517,  1518,  1519,  1520,  1526,  1527,  1533,  1534,  1535,
    1536,  1537,  1543,  1544,  1550,  1556,  1557,  1563,  1564,  1565,
    1571,  1572,  1578,  1579,  1580,  1586,  1587,  1593,  1594,  1595,
    1601,  1602,  1608,  1614,  1615,  1616,  1617,  1618,  1619,  1625,
    1626,  1627,  1628,  1634,  1635,  1641,  1642,  1643,  1644,  1650,
    1651,  1652,  1653,  1654,  1655,  1661,  1662,  1663,  1669,  1670,
    1671,  1672,  1678,  1679,  1680,  1681,  1687,  1693,  1694,  1700,
    1701,  1707,  1708,  1714,  1715,  1721,  1722,  1728,  1729,  1730,
    1731,  1732,  1733,  1734,  1735,  1741,  1742,  1743,  1749,  1750,
    1751,  1757,  1763,  1769,  1770,  1771,  1772,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1792,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,
    1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,  1874,  1875,
    1876,  1877,  1883,  1884,  1885,  1886,  1887,  1893,  1894,  1895,
    1901,  1902,  1908,  1909,  1910,  1911,  1912,  1913,  1914,  1915,
    1916,  1917,  1918,  1924,  1925,  1926,  1927,  1933,  1939,  1945,
    1951,  1957,  1958,  1959,  1960,  1966,  1967,  1968,  1969,  1975,
    1976,  1977,  1978,  1984,  1985,  1986,  1992,  1993,  1994,  1995,
    1996,  1997,  1998,  1999,  2000,  2006,  2007,  2008,  2014,  2015,
    2016,  2017,  2023,  2024,  2030,  2031,  2032,  2033,  2034,  2040,
    2041,  2042,  2043,  2044,  2050,  2056,  2057,  2058,  2059,  2060,
    2061,  2062,  2063,  2069,  2070,  2076,  2077,  2083,  2084,  2090,
    2091,  2097,  2098,  2104,  2105,  2111,  2112,  2118,  2119,  2125,
    2126,  2127,  2133,  2134,  2135,  2136,  2137,  2138,  2139,  2140,
    2141,  2142,  2143,  2144,  2148,  2151,  2154
};
#endif

#define YYPACT_NINF (-427)
#define YYTABLE_NINF (-355)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    23,    42,    57,   542,    35,  -427,    32,    35,   264,
      83,  -427,  -427,  -427,   253,  -427,  2301,  -427,   127,   103,
     139,   147,   163,   220,   235,   479,   413,   177,  -427,  -427,
     158,  -427,   291,    32,   263,  -427,   110,    35,   284,   253,
    -427,   281,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,    44,   117,   296,  -427,  2380,  -427,
    -427,  3732,     3,  -427,  1642,   -19,  -427,   565,     9,  -427,
      35,   306,   306,   306,   306,   306,   306,   413,   177,  -427,
     177,  -427,  -427,  -427,   267,  -427,   156,    32,  -427,   356,
      35,  -427,    35,  1777,  -427,  -427,  -427,   296,  -427,  1416,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,    98,
    -427,  2746,  -427,  2458,  -427,  2458,  -427,  2400,  -427,  2458,
    -427,  1629,  -427,  1629,  -427,  1629,  -427,  2458,  -427,  1235,
    -427,  1062,  -427,  2145,  -427,  2233,  -427,   -13,  -427,  -427,
    1629,  2545,  1629,   361,  -427,   337,  -427,     9,  -427,  -427,
    -427,   373,  -427,   389,   399,   408,   415,   431,   440,   177,
    -427,  -427,  -427,   486,    32,  -427,  -427,   194,   411,   444,
    2588,  1629,   467,  -427,  3449,  3537,   340,  -427,  -427,   277,
    2844,  2145,   436,  -427,  -427,  1197,  2611,  1332,  2663,  2458,
    1468,   448,  1604,  2707,  -427,  1739,  1874,   449,   463,  1912,
    1629,  1629,  -427,  -427,   212,   204,   380,  -427,  -427,   392,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   402,   -20,
    -427,  -427,   259,  -427,  -427,  3267,  -427,   259,   289,   230,
    2145,   149,  -427,  3321,  -427,   503,   -16,  -427,  -427,  1629,
     767,  3376,  -427,  -427,   215,  -427,  -427,  -427,  -427,   184,
     230,  -427,   450,  -427,   230,  -427,  -427,  -427,  -427,  1629,
     505,   508,  -427,  -427,  -427,  -427,   432,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,   511,  -427,   512,    61,  -427,    32,
    -427,   238,  2321,  1629,   513,   516,  -427,  4141,  3215,   391,
    -427,   286,  2932,  -427,  -427,  3020,  4141,   367,    10,  -427,
    2145,  -427,  1629,  -427,   482,  -427,  1629,  -427,  2009,   952,
     484,  -427,   485,  -427,  2145,  -427,  1629,  -427,  2145,  -427,
    2145,  -427,  2145,  1629,  1629,  1629,  -427,  -427,  -427,  -427,
     422,   168,  -427,  -427,   394,   382,   234,   434,   -18,   489,
    1222,  1629,   474,   396,  -427,   229,   339,   271,  -427,   475,
     475,   241,  -427,  -427,  1222,  1629,  -427,  -427,  -427,  -427,
    -427,  2233,   230,  2233,   230,  -427,  -427,     6,  -427,  -427,
     428,    13,   504,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  2515,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   927,
    -427,  -427,  -427,  -427,  2145,  -427,  -427,  -427,  -427,  -427,
    -427,  1629,   410,  1629,  -427,  2233,  -427,  2145,   545,  -427,
    -427,   486,  -427,  -427,  -427,  -427,    32,  -427,    35,  -427,
    -427,  2438,   624,   546,  -427,  -427,  -427,  4141,  3644,   424,
     414,  -427,  3839,  -427,  3108,  4141,   386,  4141,   438,   452,
    -427,   430,  -427,  -427,  -427,  2145,  -427,   521,  -427,   527,
    -427,  2145,  1629,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,   416,  -427,   468,   514,  -427,   435,   433,   523,   437,
    -427,  -427,   439,  -427,  -427,   250,   442,   -49,  -427,   425,
     342,  -427,  -427,  -427,  -427,  -427,  -427,   510,   478,  -427,
    -427,  -427,  -427,  -427,  -427,  2233,  -427,  2233,   520,   544,
     188,    14,    17,   518,   553,   189,  -427,   966,  -427,  -427,
    2145,  -427,  -427,   487,  -427,  -427,  -427,  -427,   592,   595,
    -427,   591,    35,  -427,  -427,  4141,   476,  -427,  3946,  4141,
    4141,  -427,  4141,   457,   460,  -427,   464,  -427,  -427,  -427,
    -427,  2145,  1629,  -427,  -427,   549,   469,  -427,   550,  -427,
     459,  -427,  -427,  -427,   501,  -427,   462,   507,  -427,  -427,
     465,  -427,   509,  -427,  -427,   490,   551,  -427,   537,   554,
     585,   543,   594,   198,   548,  -427,   555,  -427,  1629,  -427,
    -427,    44,   628,  -427,  4053,  4141,  -427,  -427,  -427,   473,
    -427,  -427,  -427,  -427,  -427,  -427,   580,  -427,  -427,  -427,
    -427,   488,  -427,  -427,  -427,   517,  -427,   519,   569,   239,
     557,   525,    21,   -38,   265,  -427,  -427,   652,    44,  4141,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,   526,   528,    22,
      15,   279,    24,   530,   604,   539,    38,   540,    65,    34,
    2145,   643,   792,  -427,  -427,    71,   541,   606,   547,    73,
     552,    99,    68,   558,   610,   532,   560,   104,   561,   630,
     122,   562,   631,   564,   145,   670,  -427,  2145,   679,   567,
     644,   563,   571,   170,   572,   660,   174,   577,   665,   579,
     179,   575,   582,  -427,   581,   584,   672,   583,   587,   589,
     677,   588,   599,   180,   600,   681,  -427,   720,  -427,   596,
     602,  -427,   603,   607,   691,   605,   611,   612,   700,   609,
     615,   183,   616,   705,  -427,   617,  -427,   620,   627,  -427,
     626,   633,   629,  -427,   634,   635,   723,   636,   642,  -427,
    -427,   638,  -427,   639,   645,  -427,   641,   646,   647,  -427,
     648,   654,   735,   653,   657,  -427,  -427,   659,  -427,  -427,
     666,  -427,   667,   662,  -427,   668,  -427,  -427,   673,  -427,
    -427,   678,  -427,   682,   684,  -427,   685,  -427,  -427,  -427,
     686,  -427,  -427,  -427,  -427,   687,  -427,  -427,  -427
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     0,
       0,   405,   406,   407,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   464,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,     0,    60,   213,    62,   410,    64,   411,   214,   408,
     409,    59,    63,    69,    68,    61,    46,   101,    53,    54,
      55,    56,    57,    58,     0,     0,    42,    70,    43,    79,
      81,     0,    94,    95,     0,   209,    82,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    16,    14,    13,
      10,     9,     7,    20,     0,    32,     0,     0,    29,     0,
       0,    36,     0,     0,    65,    66,    71,    44,    80,     0,
     195,   196,   190,   191,   157,   156,   163,   164,   175,   176,
     200,   201,   185,   186,   150,   242,   241,   219,   220,   182,
     183,   223,   224,   221,   222,   237,   238,   245,   246,     0,
     136,     0,   137,     0,   138,     0,   139,     0,   140,     0,
     141,     0,   142,     0,   143,     0,   144,     0,   145,     0,
     146,     0,   147,     0,   148,     0,   149,     0,   106,   105,
       0,     0,     0,     0,   210,   211,   103,     0,    99,   102,
      98,     0,   465,     0,     0,     0,     0,     0,     0,    18,
      17,    15,    11,     0,     0,    33,    30,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,   258,   260,     0,
       0,     0,     0,   121,   122,   151,     0,   158,     0,     0,
     165,     0,   177,     0,   184,   187,   192,   197,     0,     0,
       0,     0,   203,   466,   355,     0,     0,   113,   114,   214,
     116,   111,   391,   389,   418,   115,   118,   450,     0,   407,
     117,   120,     0,   112,   119,   362,   365,     0,     0,     0,
       0,     0,   368,     0,   261,   357,   360,   370,   369,     0,
       0,   371,   412,   413,     0,   372,   366,   353,   355,   407,
       0,   109,   407,   107,   239,   108,   243,   244,    96,     0,
       0,     0,   247,   212,   104,   100,     0,    22,    23,    24,
      25,    21,    26,    19,     0,    51,     0,     0,    34,     0,
      37,     0,     0,     0,     0,     0,   251,     0,     0,     0,
     123,     0,     0,   259,    84,     0,     0,     0,   255,    67,
       0,   152,     0,   154,     0,   159,     0,   161,   168,     0,
       0,   166,     0,   171,     0,   178,     0,   180,     0,   188,
       0,   193,     0,     0,     0,     0,   206,   204,   205,   232,
       0,     0,   449,   451,     0,     0,   356,     0,     0,     0,
       0,     0,   273,   267,   269,     0,   393,   389,   395,     0,
       0,     0,   363,   364,     0,     0,   392,   390,   226,   227,
     225,     0,     0,     0,     0,   439,   440,     0,   441,   442,
     270,     0,     0,   447,   448,   443,   444,   435,   436,   445,
     446,   437,   438,   433,   434,     0,   263,   264,   265,   266,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
     378,   379,   380,   377,     0,   373,   374,   375,   376,   385,
     367,     0,     0,   419,   356,     0,   110,     0,     0,   249,
     248,     0,    47,    49,    52,    38,     0,    39,     0,    72,
      74,    73,     0,     0,   253,   252,   124,     0,     0,     0,
       0,   127,     0,    89,     0,     0,     0,     0,     0,     0,
      85,     0,   256,   153,   155,     0,   162,     0,   169,     0,
     173,     0,     0,   179,   181,   189,   194,   198,   199,   207,
     208,     0,   234,     0,     0,   414,     0,     0,     0,     0,
     382,   387,   274,   268,   394,     0,   271,     0,   452,   456,
       0,   202,   381,   386,   400,   398,   399,   401,     0,   396,
     397,   384,   383,   388,   218,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   262,   354,   358,
       0,   361,   423,     0,   420,   236,   240,   250,     0,     0,
      40,     0,     0,   254,   128,     0,     0,   131,     0,     0,
       0,   125,     0,     0,     0,    90,     0,    87,    86,   257,
     160,     0,     0,   167,   172,     0,     0,   229,     0,   416,
       0,   415,   275,   454,     0,   272,   460,     0,   457,   453,
     458,   402,   403,   216,   217,   276,     0,   348,     0,     0,
       0,     0,     0,     0,     0,   350,     0,   359,   421,    48,
      50,     0,     0,   132,     0,     0,   129,   135,   126,     0,
      92,    91,    88,   170,   174,   233,     0,   231,   417,   455,
     461,   462,   459,   404,   277,   278,   349,   280,     0,     0,
       0,     0,     0,     0,     0,   351,   422,     0,     0,     0,
     133,   130,    93,   235,   463,   279,   281,   282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,   316,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,   285,   286,     0,     0,   292,     0,     0,
       0,   300,     0,     0,     0,     0,    76,     0,    77,   320,
       0,   317,   318,     0,     0,   324,     0,     0,     0,   332,
       0,     0,     0,     0,   289,   290,   287,   296,     0,   293,
     294,   304,     0,   301,   302,     0,     0,   308,     0,    78,
     321,   322,   319,   328,     0,   325,   326,   336,     0,   333,
     334,     0,     0,   340,     0,   291,   297,   298,   295,   305,
     306,   303,   312,     0,   309,   310,   323,   329,   330,   327,
     337,   338,   335,   344,     0,   341,   342,   299,   307,   313,
     314,   311,   331,   339,   345,   346,   343,   315,   347
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -427,  -427,  -427,  -427,  -427,   736,   352,   -17,  -427,  -427,
     741,    41,  -427,   777,   354,   -42,  -427,  -427,  -427,  -427,
    -427,  -427,   -11,   655,  -427,   742,   -39,  -427,  -427,   502,
     -66,  -427,  -427,  -427,    30,  -427,  -359,  -127,   187,    29,
     -35,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   445,  -427,
     -15,   202,  -427,  -427,  -185,  -427,   566,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,   621,  -427,   -94,  -427,  -427,   570,
    -427,  -427,  -427,   417,  -426,   395,  -427,   401,  -427,  -427,
    -427,  -427,  -427,  -427,   226,  -427,  -427,    -3,   -57,   420,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,   573,  -427,     7,   -60,  -427
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   304,    57,    58,    59,    60,    61,
      62,    63,   213,   214,    65,    66,    67,   459,   460,    68,
      69,    70,    71,    72,   255,   170,   284,   256,   257,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   522,   158,
     159,    75,   160,   161,   391,   259,   260,   162,   163,   164,
     165,   166,   167,    76,   210,   211,   261,   262,   415,   379,
     417,   418,   419,   263,   264,   265,   266,   434,   435,   436,
     437,   438,   267,   268,   269,   381,   531,   109,    78,   271,
     272,   273,   274,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   275,   383,    79,   276,   277
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    74,   108,   549,    18,    64,    18,   168,    89,    91,
      92,     1,    30,    77,   481,    32,   212,   430,   174,    29,
     177,   183,   184,   185,   186,   187,   188,   106,     5,   365,
      18,   507,   534,    18,   536,   176,   179,   175,   285,   366,
      42,     8,     6,   675,    99,    29,    73,   538,    31,   103,
      35,    44,   177,    74,   543,   609,    11,    64,   611,    46,
       7,   596,   673,   686,    12,   693,     8,   176,   106,   280,
     190,   191,   105,   192,    95,     9,   393,    98,   431,   698,
      10,    11,   432,    43,   178,   180,   555,   181,    36,    12,
     676,   433,    42,    18,    18,   445,   688,   367,    73,   447,
     368,   203,   204,    44,   173,   597,   701,   198,    81,   199,
     169,    46,   709,    97,   714,   703,   178,   328,   369,     8,
     508,   331,    51,   335,   617,    48,   341,    29,   345,    53,
      54,   349,   351,   202,    11,   294,    80,   195,   196,   539,
     717,    52,    12,   689,    82,   725,   544,   610,   482,   719,
     612,   305,    83,    55,   674,   687,   286,   694,   270,   194,
     270,    93,   704,   729,   104,     8,   392,    13,    84,   320,
     209,   699,   303,   215,    51,   217,   603,   220,   604,   222,
      11,   224,   306,   225,   295,   226,   734,   227,    12,   232,
     307,    18,    13,    52,    18,   283,   720,   309,   702,    24,
     288,   290,   291,     8,   710,    55,   715,   535,   270,   537,
     440,   743,   270,   177,   270,   747,   235,   270,    11,   270,
     752,   765,   270,   270,   781,    85,    12,   502,   176,   388,
     314,   315,   718,   365,   321,   308,   483,   726,   310,   327,
      86,   456,   441,   444,   488,    13,   333,     8,   337,   338,
     493,   343,   389,   347,   495,   730,   496,   270,   497,   356,
     357,   358,    11,   359,   285,   454,   285,    33,    96,   514,
      12,   607,   615,     8,    37,   524,    38,   178,   735,   651,
     324,   204,   466,   471,   525,   503,   102,    34,    11,   473,
     204,    13,  -228,   442,   390,   526,    12,    74,    43,   439,
      94,    64,   527,   744,   368,   100,    18,   748,    18,   462,
     388,    41,   753,   766,  -230,  -228,   782,   182,   285,   448,
     668,   360,   369,   608,   616,   443,   652,   270,   515,    13,
     216,   653,   218,   389,   221,   270,   223,  -230,   362,   361,
      48,   270,    73,   463,   228,   270,   677,   270,   193,   270,
     455,   476,   457,   556,   478,   479,   242,  -228,   243,   593,
     690,   197,   484,   258,   292,   258,   486,   669,   528,   490,
     480,   204,   670,    13,   293,   390,   494,    88,    90,  -230,
     518,   519,   296,   498,   499,   500,   386,   529,   387,   575,
     204,   580,   297,   678,   530,   108,   516,   583,   679,    13,
     510,   511,   298,  -270,   594,   177,   339,   691,   285,   305,
     285,   299,   692,   258,   532,   533,   311,   258,   300,   258,
     176,   283,   258,   283,   258,   520,   270,   258,   258,    21,
      22,   270,   564,   567,   301,    24,  -214,   571,   517,   189,
     559,   577,   204,   302,   270,   546,    74,   312,   307,   363,
      64,   599,   600,    18,   370,   578,   204,   258,    29,   384,
     630,   204,   258,   631,   204,   561,   540,   632,   204,   178,
     316,   552,    11,   554,   323,   283,   662,   204,   371,    42,
      12,   380,   270,   385,   329,   516,   352,   633,   270,   362,
      44,    73,    19,    20,    45,    21,    22,   560,    46,   541,
     353,    24,   363,   573,   574,   364,   576,   429,   449,   446,
      11,   450,   542,   451,   452,   453,   464,    42,    12,   465,
     472,   485,   584,   491,   492,   501,   505,    47,    44,   504,
     623,   512,   258,   626,   627,   628,    46,   506,   509,   521,
     258,   513,   545,    49,    50,   553,   258,   270,   557,   563,
     258,   585,   258,   568,   258,    19,    20,   569,    21,    22,
     581,    51,    23,   681,    24,   283,   582,   283,   579,   622,
     588,   586,   590,   587,    80,    29,   601,   589,   270,   598,
      52,   591,   602,    13,   592,   606,   705,   595,   708,   660,
     661,   605,    55,   342,   614,   619,    42,   618,   620,    51,
     621,   629,   613,   638,   636,   624,   657,    44,   635,   637,
     639,    45,   634,   737,   643,    46,   640,   641,    52,   642,
     646,    13,   645,   644,   683,   647,   648,   649,    53,    54,
      55,   258,   654,   562,    29,   650,   258,   658,   655,   663,
     667,   671,   664,   682,    47,   696,   706,   712,   656,   258,
     665,   722,   666,   672,   270,    42,   685,   680,   695,   684,
      49,    50,    29,   182,   233,   723,    44,   697,   700,   711,
      45,   728,   732,   736,    46,   713,    11,   270,    51,   270,
     716,   212,   738,    42,    12,   740,   721,   258,   724,   727,
     731,    43,   733,   258,    44,   739,   741,    52,    45,   742,
     745,   746,    46,    47,   270,   749,   750,   751,   754,    55,
     755,   278,   757,   758,   756,   760,   759,   761,   762,    49,
      50,   763,   768,   769,   236,   237,   238,   764,   767,   770,
     771,    47,   774,   239,   240,   773,   772,    51,   775,   776,
     777,   778,   779,   780,   783,   241,   784,    49,    50,   242,
     785,   243,   258,   786,   244,   787,    52,   790,   245,   788,
     246,    87,   247,   792,   793,    51,   789,   791,    55,   794,
     795,   796,   797,   798,   799,   801,   804,    29,   182,   800,
     101,   802,   803,   258,    52,   806,   805,   279,   250,   251,
     810,   252,   807,    56,    53,    54,    55,   707,    42,   808,
     809,   811,    29,   182,   233,   558,   812,   253,   254,    44,
     107,   813,   815,    45,   461,   814,    11,    46,   816,   817,
     818,   212,   287,    42,    12,   523,   322,   394,   382,   551,
     550,    43,   547,   416,    44,   548,     0,     0,    45,     0,
       0,     0,    46,     0,     0,     0,    47,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,   258,
       0,     0,    49,    50,   236,   237,   238,     0,     0,     0,
       0,    47,     0,   239,   240,     0,     0,     0,     0,     0,
      51,     0,   258,     0,   258,   241,     0,    49,    50,   242,
       0,   243,     0,     0,   244,     0,     0,     0,   245,    52,
     246,     0,   247,     0,     0,    51,     0,     0,     0,   258,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,   279,   250,   251,
       0,   252,     0,     0,    53,    54,    55,    29,   182,   233,
       0,     0,     0,     0,     0,     0,     0,   253,   254,     0,
       0,    11,     0,     0,     0,     0,   212,     0,    42,    12,
     430,     0,    29,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,     0,    11,    46,     0,     0,
       0,     0,     0,    42,    12,     0,   278,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,    45,   236,
     237,   238,    46,     0,     0,     0,    47,     0,   239,   240,
       0,     0,     0,     0,     0,     0,     0,   395,   396,     0,
     241,   431,    49,    50,   242,   432,   243,     0,     0,   244,
       0,    47,     0,   245,   433,   246,     0,   247,     0,     0,
      51,   398,   399,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,   403,   404,   405,   406,   407,   408,    52,
       0,     0,   279,   250,   251,    51,   252,     0,     0,    53,
      54,    55,    29,   182,   233,     0,     0,     0,     0,     0,
       0,     0,   253,   254,    52,     0,    11,    13,     0,   409,
     410,   212,     0,    42,    12,     0,    55,   489,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
       0,     0,    46,     0,   411,   412,     0,   413,   414,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,   236,   237,   238,     0,     0,     0,
       0,    47,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,    49,    50,   242,
       0,   243,     0,     0,   244,     0,     0,     0,   245,     0,
     246,     0,   247,     0,     0,    51,     0,     0,     0,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,   249,   250,   251,
       0,   252,     0,     0,    53,    54,    55,    29,   182,   233,
       0,     0,     0,     0,     0,     0,     0,   253,   254,     0,
       0,    11,     0,     0,     0,     0,   212,     0,    42,    12,
       0,     0,    29,     0,   330,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,    29,    11,    46,     0,     0,
       0,     0,     0,    42,    12,     0,   278,     0,     0,    11,
       0,     0,     0,     0,    44,     0,    42,    12,    45,   236,
     237,   238,    46,     0,     0,     0,    47,    44,   239,   240,
       0,    45,     0,     0,     0,    46,     0,     0,     0,     0,
     241,     0,    49,    50,   242,     0,   243,     0,     0,   244,
       0,    47,     0,   245,     0,   246,     0,   247,     0,     0,
      51,     0,     0,     0,    47,     0,     0,    49,    50,   386,
       0,   387,     0,     0,     0,     0,     0,     0,     0,    52,
      49,    50,   279,   250,   251,    51,   252,     0,     0,    53,
      54,    55,    29,   182,   233,     0,     0,     0,    51,     0,
       0,     0,   253,   254,    52,     0,    11,    13,     0,     0,
       0,   212,     0,    42,    12,     0,    55,    52,     0,     0,
      13,    43,     0,   229,    44,   230,   231,     0,    45,    55,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,   238,     0,     0,     0,
       0,    47,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,    29,    49,    50,   242,
       0,   243,     0,     0,   244,     0,     0,     0,   245,     0,
     246,     0,   247,     0,     0,    51,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,    45,     0,    52,     0,    46,   279,   250,   251,
       0,   252,     0,     0,    53,    54,    55,   334,    29,   182,
     233,     0,     0,     0,     0,     0,     0,   253,   254,     0,
       0,     0,    11,     0,     0,    47,     0,   212,     0,    42,
      12,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,    49,    50,     0,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,   238,     0,     0,     0,     0,    47,    52,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,   241,     0,    49,    50,   242,     0,   243,     0,     0,
     244,     0,     0,     0,   245,     0,   246,     0,   247,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,   279,   250,   251,     0,   252,     0,     0,
      53,    54,    55,   340,    29,   182,   233,     0,     0,     0,
       0,     0,     0,   253,   254,     0,     0,     0,    11,     0,
       0,     0,     0,   212,     0,    42,    12,     0,     0,    29,
       0,   344,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     0,    29,    11,    46,     0,     0,     0,     0,     0,
      42,    12,     0,   278,     0,     0,    11,     0,     0,     0,
       0,    44,     0,    42,    12,    45,   236,   237,   238,    46,
       0,     0,     0,    47,    44,   239,   240,     0,    45,     0,
       0,     0,    46,     0,     0,     0,     0,   241,     0,    49,
      50,   242,     0,   243,     0,     0,   244,     0,    47,     0,
     245,     0,   246,     0,   247,     0,     0,    51,     0,     0,
       0,    47,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    49,    50,   279,
     250,   251,    51,   252,     0,     0,    53,    54,    55,    29,
     182,   233,     0,     0,     0,    51,     0,     0,     0,   253,
     254,    52,     0,    11,    13,     0,     0,     0,   212,     0,
      42,    12,     0,    55,    52,     0,   348,    13,    43,     0,
     171,    44,     0,   172,     0,    45,    55,    29,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,   278,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    42,    12,
       0,   236,   237,   238,     0,     0,     0,     0,    47,    44,
     239,   240,     0,    45,     0,     0,     0,    46,     0,     0,
       0,     0,   241,     0,    49,    50,   242,     0,   243,     0,
       0,   244,     0,     0,     0,   245,     0,   246,     0,   247,
       0,     0,    51,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    49,    50,   279,   250,   251,     0,   252,     0,
       0,    53,    54,    55,    29,   182,   233,     0,     0,     0,
      51,     0,     0,     0,   253,   254,     0,     0,    11,     0,
       0,     0,     0,   212,     0,    42,    12,     0,     0,    52,
       0,   350,    13,    43,     0,   200,    44,     0,   201,     0,
      45,    55,    29,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    42,    12,     0,   236,   237,   238,     0,
       0,     0,     0,    47,    44,   239,   240,     0,    45,     0,
       0,     0,    46,     0,     0,     0,     0,   241,     0,    49,
      50,   242,     0,   243,     0,     0,   244,     0,     0,     0,
     245,     0,   246,     0,   247,     0,     0,    51,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    49,    50,   279,
     250,   251,     0,   252,     0,     0,    53,    54,    55,    29,
     182,   233,     0,     0,     0,    51,     0,     0,     0,   253,
     254,     0,     0,    11,     0,     0,     0,     0,   212,     0,
      42,    12,     0,     0,    52,     0,     0,    13,    43,     0,
       0,    44,   354,   355,     0,    45,    55,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,   238,     0,     0,     0,     0,    47,     0,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,     0,    49,    50,   242,     0,   243,     0,
       0,   244,     0,     0,     0,   245,     0,   246,     0,   247,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,   279,   250,   251,     0,   252,     0,
       0,    53,    54,    55,   487,    29,   182,   233,     0,     0,
       0,     0,     0,     0,   253,   254,     0,     0,     0,    11,
       0,     0,     0,     0,   212,     0,    42,    12,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,   238,
       0,     0,     0,     0,    47,     0,   239,   240,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,     0,
      49,    50,   242,    29,   243,     0,     0,   244,     0,     0,
       0,   245,     0,   246,     0,   247,     0,    11,    51,     0,
       0,     0,     0,     0,    42,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    52,     0,    45,
     279,   250,   251,    46,   252,     0,     0,    53,    54,    55,
       0,     0,   281,     0,     0,     0,     0,     0,     0,     0,
     253,   254,     0,     0,     0,     0,   237,   238,     0,     0,
       8,    29,    47,     0,     0,   240,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    11,   241,     0,    49,    50,
     458,    29,    42,    12,     0,     0,     0,     0,     0,   245,
      43,   246,     0,    44,     0,    11,    51,    45,     0,     0,
       0,    46,    42,    12,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    44,     0,    52,     0,    45,   282,   250,
     251,    46,     0,     0,     0,     0,     0,    55,     0,     0,
      47,     0,    48,     0,     0,     0,     0,     0,   253,   254,
      29,     0,     0,     0,     0,    41,    49,    50,     0,     0,
      47,     0,    48,     0,    11,     0,     0,     0,     0,     0,
      29,    42,    12,     0,    51,     0,    49,    50,     0,    43,
       0,     0,    44,     0,    11,     0,    45,     0,     0,   212,
      46,    42,    12,    52,    51,     0,    13,     0,     0,     0,
       0,     0,    44,    53,    54,    55,    45,     0,    29,     0,
      46,     0,     0,    52,     0,     0,    13,     0,     0,    47,
       0,    48,    11,    53,    54,    55,   219,     0,    29,    42,
      12,     0,     0,     0,     0,    49,    50,    43,     0,    47,
      44,     0,    11,     0,    45,     0,     0,   212,    46,    42,
      12,     0,     0,    51,     0,    49,    50,     0,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,    46,     0,
       0,     0,    52,    51,     0,    13,     0,    47,     0,    48,
       0,     0,    53,    54,    55,    29,     0,   233,     0,     0,
       0,     0,    52,    49,    50,    13,     0,    47,     0,    11,
       0,     0,    53,    54,    55,     0,    42,    12,     0,     0,
       0,    51,     0,    49,    50,    29,     0,    44,     0,     0,
       0,    45,     0,     0,     0,    46,     0,     0,     0,    11,
      52,    51,     0,    13,   278,     0,    42,    12,     0,     0,
      53,    54,    55,     0,     0,     0,     0,    44,     0,     0,
      52,    45,     0,    13,    47,    46,     0,     0,    29,     0,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
      49,    50,    11,     0,     0,     0,     0,   244,     0,    42,
      12,    29,     0,     0,    47,     0,     0,     0,    51,     0,
      44,     0,     0,     0,    45,    11,     0,     0,    46,     0,
      49,    50,    42,    12,     0,     0,     0,    52,   332,     0,
     279,     0,     0,    44,     0,     0,     0,    45,    51,    55,
       0,    46,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    52,     0,     0,
      13,     0,     0,    49,    50,     0,   289,    11,     0,    55,
      47,     0,     0,     0,    42,    12,     0,     0,     0,     0,
     336,    51,     0,     0,     0,    44,    49,    50,     0,    45,
       0,     0,     0,    46,     0,     0,     0,    29,     0,     0,
      52,     0,     0,    13,    51,     0,     0,     0,     0,   313,
       0,    11,    55,     0,     0,     0,     0,     0,    42,    12,
       0,     0,    47,    52,   346,     0,    13,     0,     0,    44,
     205,     0,     0,    45,     0,    55,     0,    46,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,    51,     0,     0,     0,
       0,   112,   113,     0,     0,    43,    47,     0,     0,     0,
     114,   115,     0,     0,     0,    52,     0,     0,    13,   116,
       0,   117,    49,    50,     0,     0,   118,    55,   119,   120,
       0,   121,     0,     0,   206,   122,   123,     0,     0,     0,
      51,     0,     0,   207,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    13,     0,     0,     0,   125,   126,   325,   326,
       0,    55,     0,     0,     0,     0,     0,   127,   128,     0,
     208,   129,   130,     0,   131,   132,     0,   133,   134,   110,
     111,   135,   136,     0,     0,     0,   137,   138,     0,   112,
     113,     0,     0,    43,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
       0,     0,     0,     0,   118,     0,   119,   120,     0,   121,
       0,     0,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,     0,     0,
       0,     0,     0,     0,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   110,   111,   129,
     130,     0,   131,   132,     0,   133,   134,   112,   113,   135,
     136,    43,     0,     0,   137,   138,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,     0,     0,
       0,     0,   118,     0,   119,   120,     0,   121,     0,     0,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,   110,   111,   129,   130,     0,
     131,   132,     0,   133,   134,   112,   113,   135,   136,    43,
       0,     0,   137,   138,   114,   115,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   117,     0,     0,     0,     0,
     118,     0,   119,   120,     0,   121,     0,     0,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,     0,     0,     0,     0,     0,     0,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,   110,   111,   129,   130,     0,   131,   132,
       0,   133,   134,   112,   113,   135,   136,    43,     0,     0,
     137,   138,   114,   115,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,     0,   118,     0,
     119,   120,     0,   121,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,   129,   130,     0,   131,   132,     0,   133,
     134,     0,     0,   135,   136,     0,     0,     0,   137,   138,
     110,   111,     0,   467,     0,   468,     0,     0,     0,     0,
     112,   113,     0,     0,    43,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,   118,     0,   119,   120,     0,
     121,     0,     0,     0,   122,   123,     0,     0,     0,     0,
       0,     0,   469,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,   372,     0,
       0,     0,     0,     0,     0,   125,   126,     0,  -352,  -352,
       0,     0,     0,     0,   373,   374,   127,   128,     0,     0,
     129,   130,     0,   131,   132,     0,   133,   134,  -352,   375,
     135,   136,  -352,  -352,     0,   137,   138,     0,   376,     0,
       0,  -352,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,
       0,     0,   372,     0,   242,   470,   377,     0,     0,     0,
       0,     0,   395,   396,     0,     0,     0,   247,   373,   374,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,  -352,   397,     0,     0,     0,   398,   399,     0,     0,
       0,     0,   400,     0,     0,   401,   402,     0,   403,   404,
     405,   406,   407,   408,   378,  -352,  -352,  -354,  -352,  -352,
       0,     0,     0,     0,     0,     0,     0,  -354,  -354,     0,
       0,     0,     0,  -354,  -354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   410,     0,  -354,     0,     0,
       0,  -354,  -354,     0,     0,     0,     0,  -354,     0,     0,
    -354,  -354,     0,  -354,  -354,  -354,  -354,  -354,  -354,   411,
     412,     0,   413,   414,   110,   111,     0,   317,     0,     0,
       0,     0,   318,     0,   112,   113,     0,     0,    43,     0,
       0,     0,     0,   114,   115,     0,     0,     0,     0,  -354,
    -354,     0,   116,     0,   117,     0,     0,     0,     0,   118,
       0,   119,   120,     0,   121,     0,     0,     0,   122,   123,
       0,     0,     0,     0,  -354,  -354,   319,  -354,  -354,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,   110,   111,   129,   130,     0,   131,   132,     0,
     133,   134,   112,   113,   135,   136,    43,     0,     0,   137,
     138,   114,   115,     0,     0,     0,     0,     0,     0,     0,
     116,     0,   117,     0,     0,     0,     0,   118,     0,   119,
     120,     0,   121,     0,     0,   206,   122,   123,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   208,   129,   130,     0,   131,   132,     0,   133,   134,
       0,     0,   135,   136,     0,     0,     0,   137,   138,   110,
     111,     0,   565,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,    43,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
       0,     0,     0,     0,   118,     0,   119,   120,     0,   121,
       0,     0,     0,   122,   123,     0,     0,     0,     0,     0,
       0,   566,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   110,   111,   129,
     130,     0,   131,   132,     0,   133,   134,   112,   113,   135,
     136,    43,     0,     0,   137,   138,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,     0,     0,
       0,     0,   118,     0,   119,   120,     0,   121,     0,     0,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,   129,   130,     0,
     131,   132,     0,   133,   134,     0,     0,   135,   136,     0,
       0,     0,   137,   138,   110,   111,     0,   570,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,    43,     0,
       0,     0,     0,   114,   115,     0,     0,     0,     0,     0,
       0,     0,   116,     0,   117,     0,     0,     0,     0,   118,
       0,   119,   120,     0,   121,     0,     0,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,   129,   130,     0,   131,   132,     0,
     133,   134,     0,     0,   135,   136,     0,     0,     0,   137,
     138,   110,   111,     0,   625,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,    43,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   117,     0,     0,     0,     0,   118,     0,   119,   120,
       0,   121,     0,     0,     0,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,   129,   130,     0,   131,   132,     0,   133,   134,     0,
       0,   135,   136,     0,     0,     0,   137,   138,   110,   111,
       0,   659,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,    43,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,     0,     0,   118,     0,   119,   120,     0,   121,     0,
       0,     0,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   110,   111,   129,   130,
       0,   131,   132,     0,   133,   134,   112,   113,   135,   136,
      43,     0,     0,   137,   138,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   117,     0,     0,     0,
       0,   118,     0,   119,   120,     0,   121,     0,     0,     0,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,   129,   130,     0,   131,
     132,     0,   133,   134,     0,     0,   135,   136,     0,     0,
       0,   137,   138
};

static const yytype_int16 yycheck[] =
{
       3,    16,    68,   429,     7,    16,     9,     4,    25,    26,
      27,    19,     5,    16,     4,     8,    29,    33,    37,    10,
      77,    81,    82,    83,    84,    85,    86,    66,     5,    49,
      33,    49,   391,    36,   393,    77,    78,    56,   165,    59,
      31,     9,     0,    81,    37,    10,    16,    41,     7,    64,
       9,    42,   109,    68,    41,    41,    24,    68,    41,    50,
       3,   110,    41,    41,    32,    41,     9,   109,   107,   163,
      87,    88,    65,    90,    33,    18,   261,    36,    94,    41,
      23,    24,    98,    39,    77,    78,   445,    80,     5,    32,
     128,   107,    31,    96,    97,   280,    81,   117,    68,   284,
     120,     3,     4,    42,    74,   154,    41,   100,     5,   102,
     107,    50,    41,     3,    41,    81,   109,   211,   138,     9,
     138,   215,   113,   217,   550,    81,   220,    10,   222,   142,
     143,   225,   226,   103,    24,   177,     9,    96,    97,   133,
      41,   132,    32,   128,     5,    41,   133,   133,   138,    81,
     133,   193,     5,   144,   133,   133,   167,   133,   161,     3,
     163,     3,   128,    41,    47,     9,   260,   135,     5,   204,
     141,   133,   189,   143,   113,   145,   535,   147,   537,   149,
      24,   151,   193,   153,   177,   155,    41,   157,    32,   159,
     193,   194,   135,   132,   197,   165,   128,     3,   133,    22,
     170,   171,   172,     9,   133,   144,   133,   392,   211,   394,
     270,    41,   215,   270,   217,    41,    67,   220,    24,   222,
      41,    41,   225,   226,    41,     5,    32,    59,   270,    80,
     200,   201,   133,    49,   205,   194,   330,   133,   197,   210,
       5,     3,    27,    59,   338,   135,   216,     9,   218,   219,
     344,   221,   103,   223,   348,   133,   350,   260,   352,   229,
     230,   231,    24,    59,   391,   307,   393,     3,     5,    40,
      32,    83,    83,     9,    21,    34,    23,   270,   133,    81,
       3,     4,   317,   318,    43,   117,     5,    23,    24,     3,
       4,   135,    80,    78,   145,    54,    32,   312,    39,   269,
       9,   312,    61,   133,   120,    21,   309,   133,   311,   312,
      80,    15,   133,   133,    80,   103,   133,    11,   445,   289,
      81,   117,   138,   135,   135,   110,   128,   330,    99,   135,
     143,   133,   145,   103,   147,   338,   149,   103,   109,   135,
      81,   344,   312,   313,   157,   348,    81,   350,    81,   352,
     309,   322,   311,   447,   325,   326,    97,   145,    99,   109,
      81,     5,   332,   161,     3,   163,   336,   128,   127,   339,
       3,     4,   133,   135,    37,   145,   346,    25,    26,   145,
     109,   110,     9,   353,   354,   355,    97,   146,    99,     3,
       4,   485,     3,   128,   153,   461,    57,   491,   133,   135,
     370,   371,     3,    64,   154,   462,   219,   128,   535,   451,
     537,     3,   133,   211,   384,   385,     5,   215,     3,   217,
     462,   391,   220,   393,   222,   154,   429,   225,   226,    16,
      17,   434,   467,   468,     3,    22,    97,   472,    99,    87,
     451,     3,     4,     3,   447,   415,   461,     3,   451,   110,
     461,   109,   110,   456,   252,     3,     4,   255,    10,   257,
       3,     4,   260,     3,     4,   458,    38,     3,     4,   462,
       3,   441,    24,   443,   134,   445,     3,     4,   252,    31,
      32,   255,   485,   257,    48,    57,    37,   581,   491,   109,
      42,   461,    13,    14,    46,    16,    17,   456,    50,    71,
      37,    22,   110,   474,   475,   103,   477,     4,     3,    59,
      24,     3,    84,    81,     3,     3,     3,    31,    32,     3,
     129,    39,   492,    39,    39,   103,   144,    79,    42,   135,
     565,    57,   330,   568,   569,   570,    50,   103,    49,    64,
     338,   145,    38,    95,    96,   135,   344,   550,     3,     3,
     348,   135,   350,   129,   352,    13,    14,   143,    16,    17,
      39,   113,    20,   657,    22,   535,    39,   537,   138,   562,
     135,   103,    49,    59,     9,    10,    66,   144,   581,   154,
     132,   144,   104,   135,   145,    41,   680,   145,   682,   624,
     625,    71,   144,   145,    41,     3,    31,   110,     3,   113,
       9,   572,    84,   144,   135,   129,   621,    42,    59,    59,
     109,    46,   582,   707,   105,    50,   154,   110,   132,   154,
      83,   135,    71,   133,   659,    71,    41,    84,   142,   143,
     144,   429,    84,     9,    10,    41,   434,     9,    83,    59,
      71,    84,   154,   658,    79,    41,     3,    41,   618,   447,
     133,    41,   133,   128,   657,    31,   128,     5,   128,   133,
      95,    96,    10,    11,    12,   133,    42,   128,   128,   128,
      46,    41,    41,     3,    50,   128,    24,   680,   113,   682,
     128,    29,     3,    31,    32,    41,   128,   485,   128,   128,
     128,    39,   128,   491,    42,   128,   133,   132,    46,   128,
     128,    41,    50,    79,   707,   128,    41,   128,   133,   144,
     128,    59,   128,    41,   133,   128,   133,   128,    41,    95,
      96,   133,    41,     3,    72,    73,    74,   128,   128,   133,
     128,    79,    41,    81,    82,   128,   133,   113,   133,   128,
     128,    41,   133,   128,   128,    93,    41,    95,    96,    97,
     133,    99,   550,   133,   102,   128,   132,   128,   106,   133,
     108,    25,   110,   128,    41,   113,   133,   133,   144,   133,
     128,   133,   133,   128,   133,   128,    41,    10,    11,   133,
      39,   133,   128,   581,   132,   128,   133,   135,   136,   137,
     128,   139,   133,    16,   142,   143,   144,     5,    31,   133,
     133,   133,    10,    11,    12,   451,   133,   155,   156,    42,
      68,   133,   128,    46,   312,   133,    24,    50,   133,   133,
     133,    29,   167,    31,    32,   380,   205,   261,   255,   434,
     429,    39,   415,   263,    42,   415,    -1,    -1,    46,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,
      -1,    -1,    95,    96,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
     113,    -1,   680,    -1,   682,    93,    -1,    95,    96,    97,
      -1,    99,    -1,    -1,   102,    -1,    -1,    -1,   106,   132,
     108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,   707,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,
      -1,   139,    -1,    -1,   142,   143,   144,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      33,    -1,    10,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    24,    50,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    72,
      73,    74,    50,    -1,    -1,    -1,    79,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
      -1,    79,    -1,   106,   107,   108,    -1,   110,    -1,    -1,
     113,    75,    76,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,   132,
      -1,    -1,   135,   136,   137,   113,   139,    -1,    -1,   142,
     143,   144,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,   132,    -1,    24,   135,    -1,   123,
     124,    29,    -1,    31,    32,    -1,   144,   145,    -1,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    -1,   148,   149,    -1,   151,   152,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,
      -1,    99,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
     108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,
      -1,   139,    -1,    -1,   142,   143,   144,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    10,    -1,    37,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    10,    24,    50,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    59,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    42,    -1,    31,    32,    46,    72,
      73,    74,    50,    -1,    -1,    -1,    79,    42,    81,    82,
      -1,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      93,    -1,    95,    96,    97,    -1,    99,    -1,    -1,   102,
      -1,    79,    -1,   106,    -1,   108,    -1,   110,    -1,    -1,
     113,    -1,    -1,    -1,    79,    -1,    -1,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      95,    96,   135,   136,   137,   113,   139,    -1,    -1,   142,
     143,   144,    10,    11,    12,    -1,    -1,    -1,   113,    -1,
      -1,    -1,   155,   156,   132,    -1,    24,   135,    -1,    -1,
      -1,    29,    -1,    31,    32,    -1,   144,   132,    -1,    -1,
     135,    39,    -1,   138,    42,   140,   141,    -1,    46,   144,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    10,    95,    96,    97,
      -1,    99,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
     108,    -1,   110,    -1,    -1,   113,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,   132,    -1,    50,   135,   136,   137,
      -1,   139,    -1,    -1,   142,   143,   144,   145,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,
      -1,    -1,    24,    -1,    -1,    79,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    95,    96,    -1,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    79,   132,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    93,    -1,    95,    96,    97,    -1,    99,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,    -1,    -1,   135,   136,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,    10,
      -1,    37,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    10,    24,    50,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    59,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    42,    -1,    31,    32,    46,    72,    73,    74,    50,
      -1,    -1,    -1,    79,    42,    81,    82,    -1,    46,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    -1,    99,    -1,    -1,   102,    -1,    79,    -1,
     106,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,
      -1,    79,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    95,    96,   135,
     136,   137,   113,   139,    -1,    -1,   142,   143,   144,    10,
      11,    12,    -1,    -1,    -1,   113,    -1,    -1,    -1,   155,
     156,   132,    -1,    24,   135,    -1,    -1,    -1,    29,    -1,
      31,    32,    -1,   144,   132,    -1,    37,   135,    39,    -1,
     138,    42,    -1,   141,    -1,    46,   144,    10,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    42,
      81,    82,    -1,    46,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    -1,    99,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,
      -1,    -1,   113,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    95,    96,   135,   136,   137,    -1,   139,    -1,
      -1,   142,   143,   144,    10,    11,    12,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   155,   156,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,   132,
      -1,    37,   135,    39,    -1,   138,    42,    -1,   141,    -1,
      46,   144,    10,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    79,    42,    81,    82,    -1,    46,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    -1,    99,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    95,    96,   135,
     136,   137,    -1,   139,    -1,    -1,   142,   143,   144,    10,
      11,    12,    -1,    -1,    -1,   113,    -1,    -1,    -1,   155,
     156,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,   132,    -1,    -1,   135,    39,    -1,
      -1,    42,   140,   141,    -1,    46,   144,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    -1,    99,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    -1,   135,   136,   137,    -1,   139,    -1,
      -1,   142,   143,   144,   145,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,    96,    97,    10,    99,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,   108,    -1,   110,    -1,    24,   113,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,   132,    -1,    46,
     135,   136,   137,    50,   139,    -1,    -1,   142,   143,   144,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
       9,    10,    79,    -1,    -1,    82,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    93,    -1,    95,    96,
       9,    10,    31,    32,    -1,    -1,    -1,    -1,    -1,   106,
      39,   108,    -1,    42,    -1,    24,   113,    46,    -1,    -1,
      -1,    50,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,   132,    -1,    46,   135,   136,
     137,    50,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,   155,   156,
      10,    -1,    -1,    -1,    -1,    15,    95,    96,    -1,    -1,
      79,    -1,    81,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      10,    31,    32,    -1,   113,    -1,    95,    96,    -1,    39,
      -1,    -1,    42,    -1,    24,    -1,    46,    -1,    -1,    29,
      50,    31,    32,   132,   113,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    42,   142,   143,   144,    46,    -1,    10,    -1,
      50,    -1,    -1,   132,    -1,    -1,   135,    -1,    -1,    79,
      -1,    81,    24,   142,   143,   144,    66,    -1,    10,    31,
      32,    -1,    -1,    -1,    -1,    95,    96,    39,    -1,    79,
      42,    -1,    24,    -1,    46,    -1,    -1,    29,    50,    31,
      32,    -1,    -1,   113,    -1,    95,    96,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,   132,   113,    -1,   135,    -1,    79,    -1,    81,
      -1,    -1,   142,   143,   144,    10,    -1,    12,    -1,    -1,
      -1,    -1,   132,    95,    96,   135,    -1,    79,    -1,    24,
      -1,    -1,   142,   143,   144,    -1,    31,    32,    -1,    -1,
      -1,   113,    -1,    95,    96,    10,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    24,
     132,   113,    -1,   135,    59,    -1,    31,    32,    -1,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    42,    -1,    -1,
     132,    46,    -1,   135,    79,    50,    -1,    -1,    10,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    24,    -1,    -1,    -1,    -1,   102,    -1,    31,
      32,    10,    -1,    -1,    79,    -1,    -1,    -1,   113,    -1,
      42,    -1,    -1,    -1,    46,    24,    -1,    -1,    50,    -1,
      95,    96,    31,    32,    -1,    -1,    -1,   132,    37,    -1,
     135,    -1,    -1,    42,    -1,    -1,    -1,    46,   113,   144,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   132,    -1,    -1,
     135,    -1,    -1,    95,    96,    -1,   141,    24,    -1,   144,
      79,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      37,   113,    -1,    -1,    -1,    42,    95,    96,    -1,    46,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    10,    -1,    -1,
     132,    -1,    -1,   135,   113,    -1,    -1,    -1,    -1,   141,
      -1,    24,   144,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    79,   132,    37,    -1,   135,    -1,    -1,    42,
       4,    -1,    -1,    46,    -1,   144,    -1,    50,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    39,    79,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,   132,    -1,    -1,   135,    53,
      -1,    55,    95,    96,    -1,    -1,    60,   144,    62,    63,
      -1,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
     113,    -1,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,   100,   101,     4,     5,
      -1,   144,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,   121,   122,    25,
      26,   125,   126,    -1,    -1,    -1,   130,   131,    -1,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    25,    26,   115,
     116,    -1,   118,   119,    -1,   121,   122,    35,    36,   125,
     126,    39,    -1,    -1,   130,   131,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    25,    26,   115,   116,    -1,
     118,   119,    -1,   121,   122,    35,    36,   125,   126,    39,
      -1,    -1,   130,   131,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,    25,    26,   115,   116,    -1,   118,   119,
      -1,   121,   122,    35,    36,   125,   126,    39,    -1,    -1,
     130,   131,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    -1,   115,   116,    -1,   118,   119,    -1,   121,
     122,    -1,    -1,   125,   126,    -1,    -1,    -1,   130,   131,
      25,    26,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,    -1,
      65,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,   111,   112,    -1,    -1,
     115,   116,    -1,   118,   119,    -1,   121,   122,    71,    72,
     125,   126,    75,    76,    -1,   130,   131,    -1,    81,    -1,
      -1,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      -1,    -1,    41,    -1,    97,   150,    99,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,   110,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    71,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,   147,   148,   149,    41,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    71,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,   148,
     149,    -1,   151,   152,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,   123,
     124,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,   148,   149,    77,   151,   152,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,    25,    26,   115,   116,    -1,   118,   119,    -1,
     121,   122,    35,    36,   125,   126,    39,    -1,    -1,   130,
     131,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,
      63,    -1,    65,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,    -1,   121,   122,
      -1,    -1,   125,   126,    -1,    -1,    -1,   130,   131,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    25,    26,   115,
     116,    -1,   118,   119,    -1,   121,   122,    35,    36,   125,
     126,    39,    -1,    -1,   130,   131,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
     118,   119,    -1,   121,   122,    -1,    -1,   125,   126,    -1,
      -1,    -1,   130,   131,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,   118,   119,    -1,
     121,   122,    -1,    -1,   125,   126,    -1,    -1,    -1,   130,
     131,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,
      -1,   115,   116,    -1,   118,   119,    -1,   121,   122,    -1,
      -1,   125,   126,    -1,    -1,    -1,   130,   131,    25,    26,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      -1,    -1,    -1,    60,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    25,    26,   115,   116,
      -1,   118,   119,    -1,   121,   122,    35,    36,   125,   126,
      39,    -1,    -1,   130,   131,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,    -1,   121,   122,    -1,    -1,   125,   126,    -1,    -1,
      -1,   130,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    19,   158,   159,   160,     5,     0,     3,     9,    18,
      23,    24,    32,   135,   165,   168,   169,   170,   254,    13,
      14,    16,    17,    20,    22,   161,   162,   163,   164,    10,
     271,   168,   271,     3,    23,   168,     5,    21,    23,   166,
     167,    15,    31,    39,    42,    46,    50,    79,    81,    95,
      96,   113,   132,   142,   143,   144,   170,   172,   173,   174,
     175,   176,   177,   178,   179,   181,   182,   183,   186,   187,
     188,   189,   190,   191,   217,   218,   230,   254,   255,   271,
       9,     5,     5,     5,     5,     5,     5,   162,   163,   164,
     163,   164,   164,     3,     9,   168,     5,     3,   168,   271,
      21,   167,     5,   217,    47,   271,   183,   182,   187,   254,
      25,    26,    35,    36,    44,    45,    53,    55,    60,    62,
      63,    65,    69,    70,    86,   100,   101,   111,   112,   115,
     116,   118,   119,   121,   122,   125,   126,   130,   131,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   216,   217,
     219,   220,   224,   225,   226,   227,   228,   229,     4,   107,
     192,   138,   141,   191,    37,    56,   172,   255,   271,   172,
     271,   271,    11,   272,   272,   272,   272,   272,   272,   163,
     164,   164,   164,    81,     3,   168,   168,     5,   271,   271,
     138,   141,   191,     3,     4,     4,    68,    77,   114,   196,
     231,   232,    29,   179,   180,   191,   195,   191,   195,    66,
     191,   195,   191,   195,   191,   191,   191,   191,   195,   138,
     140,   141,   191,    12,    59,    67,    72,    73,    74,    81,
      82,    93,    97,    99,   102,   106,   108,   110,   117,   135,
     136,   137,   139,   155,   156,   191,   194,   195,   218,   222,
     223,   233,   234,   240,   241,   242,   243,   249,   250,   251,
     254,   256,   257,   258,   259,   269,   272,   273,    59,   135,
     233,    59,   135,   191,   193,   194,   179,   180,   191,   141,
     191,   191,     3,    37,   172,   271,     9,     3,     3,     3,
       3,     3,     3,   164,   171,   172,   179,   254,   168,     3,
     168,     5,     3,   141,   191,   191,     3,    28,    33,    77,
     197,   196,   231,   134,     3,     4,     5,   196,   233,    48,
      37,   233,    37,   191,   145,   233,    37,   191,   191,   195,
     145,   233,   145,   191,    37,   233,    37,   191,    37,   233,
      37,   233,    37,    37,   140,   141,   191,   191,   191,    59,
     117,   135,   109,   110,   103,    49,    59,   117,   120,   138,
     218,   251,    41,    57,    58,    72,    81,    99,   147,   236,
     251,   252,   269,   270,   218,   251,    97,    99,    80,   103,
     145,   221,   233,   221,   223,    51,    52,    71,    75,    76,
      81,    84,    85,    87,    88,    89,    90,    91,    92,   123,
     124,   148,   149,   151,   152,   235,   236,   237,   238,   239,
     260,   261,   262,   263,   264,   265,   266,   267,   268,     4,
      33,    94,    98,   107,   244,   245,   246,   247,   248,   191,
     272,    27,    78,   110,    59,   221,    59,   221,   191,     3,
       3,    81,     3,     3,   172,   168,     3,   168,     9,   184,
     185,   186,   254,   191,     3,     3,   197,    28,    30,    77,
     150,   197,   129,     3,     4,     5,   196,     5,   196,   196,
       3,     4,   138,   233,   191,    39,   191,   145,   233,   145,
     191,    39,    39,   233,   191,   233,   233,   233,   191,   191,
     191,   103,    59,   117,   135,   144,   103,    49,   138,    49,
     191,   191,    57,   145,    40,    99,    57,    99,   109,   110,
     154,    64,   215,   215,    34,    43,    54,    61,   127,   146,
     153,   253,   191,   191,   193,   221,   193,   221,    41,   133,
      38,    71,    84,    41,   133,    38,   191,   240,   256,   241,
     244,   242,   191,   135,   191,   193,   233,     3,   171,   179,
     168,   271,     9,     3,   197,    28,    77,   197,   129,   143,
      28,   197,     5,   196,   196,     3,   196,     3,     3,   138,
     233,    39,    39,   233,   191,   135,   103,    59,   135,   144,
      49,   144,   145,   109,   154,   145,   110,   154,   154,   109,
     110,    66,   104,   193,   193,    71,    41,    83,   135,    41,
     133,    41,   133,    84,    41,    83,   135,   241,   110,     3,
       3,     9,   271,   197,   129,    28,   197,   197,   197,   196,
       3,     3,     3,   233,   191,    59,   135,    59,   144,   109,
     154,   110,   154,   105,   133,    71,    83,    71,    41,    84,
      41,    81,   128,   133,    84,    83,   191,   217,     9,    28,
     197,   197,     3,    59,   154,   133,   133,    71,    81,   128,
     133,    84,   128,    41,   133,    81,   128,    81,   128,   133,
       5,   233,   217,   197,   133,   128,    41,   133,    81,   128,
      81,   128,   133,    41,   133,   128,    41,   128,    41,   133,
     128,    41,   133,    81,   128,   233,     3,     5,   233,    41,
     133,   128,    41,   128,    41,   133,   128,    41,   133,    81,
     128,   128,    41,   133,   128,    41,   133,   128,    41,    41,
     133,   128,    41,   128,    41,   133,     3,   233,     3,   128,
      41,   133,   128,    41,   133,   128,    41,    41,   133,   128,
      41,   128,    41,   133,   133,   128,   133,   128,    41,   133,
     128,   128,    41,   133,   128,    41,   133,   128,    41,     3,
     133,   128,   133,   128,    41,   133,   128,   128,    41,   133,
     128,    41,   133,   128,    41,   133,   133,   128,   133,   133,
     128,   133,   128,    41,   133,   128,   133,   133,   128,   133,
     133,   128,   133,   128,    41,   133,   128,   133,   133,   133,
     128,   133,   133,   133,   133,   128,   133,   133,   133
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     160,   161,   162,   162,   163,   163,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   167,   167,   167,
     167,   168,   168,   168,   168,   169,   169,   170,   170,   170,
     170,   171,   171,   172,   172,   172,   172,   172,   172,   173,
     174,   175,   176,   177,   178,   179,   179,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   185,   185,   185,   186,
     186,   187,   187,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   190,   190,   191,   191,   191,
     191,   191,   191,   191,   191,   192,   192,   193,   193,   193,
     193,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     198,   199,   199,   199,   199,   199,   200,   200,   201,   201,
     201,   201,   201,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   204,   204,   205,   205,   205,
     205,   205,   206,   206,   207,   208,   208,   209,   209,   209,
     210,   210,   211,   211,   211,   212,   212,   213,   213,   213,
     214,   214,   215,   216,   216,   216,   216,   216,   216,   217,
     217,   217,   217,   218,   218,   219,   219,   219,   219,   220,
     220,   220,   220,   220,   220,   221,   221,   221,   222,   222,
     222,   222,   223,   223,   223,   223,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   230,
     230,   230,   230,   230,   230,   231,   231,   231,   232,   232,
     232,   233,   234,   235,   235,   235,   235,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     239,   239,   240,   240,   240,   240,   240,   241,   241,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   244,   245,   246,   247,
     248,   249,   249,   249,   249,   250,   250,   250,   250,   251,
     251,   251,   251,   252,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   254,   254,   254,   255,   255,
     255,   255,   256,   256,   257,   257,   257,   257,   257,   258,
     258,   258,   258,   258,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   262,   262,   263,   263,   264,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   269,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   271,   272,   273
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     1,     2,     2,     3,     2,     3,
       3,     4,     2,     3,     3,     4,     3,     4,     4,     5,
       4,     4,     4,     4,     4,     4,     4,     1,     2,     3,
       4,     2,     3,     4,     5,     1,     2,     4,     5,     5,
       6,     1,     2,     2,     3,     1,     2,     6,     7,     6,
       7,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     2,     5,     1,     1,     6,     7,     7,     8,     1,
       2,     1,     1,     3,     4,     5,     6,     6,     7,     5,
       6,     7,     7,     8,     1,     1,     3,     1,     2,     2,
       3,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     5,     6,     4,     5,     6,
       7,     5,     6,     7,     8,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     3,     4,     1,     1,     2,     3,
       5,     3,     4,     1,     1,     2,     3,     5,     3,     4,
       6,     3,     5,     4,     6,     1,     1,     2,     3,     4,
       3,     4,     1,     1,     2,     1,     1,     2,     3,     4,
       1,     1,     2,     3,     4,     1,     1,     2,     4,     4,
       1,     1,     1,     2,     3,     3,     3,     4,     4,     1,
       2,     2,     3,     1,     1,     4,     5,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     5,     2,     5,     3,     6,     4,     1,     1,     2,
       4,     1,     1,     2,     2,     1,     1,     3,     4,     4,
       5,     4,     5,     5,     6,     2,     3,     4,     1,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     2,     3,     1,     2,     3,     3,     4,     4,     5,
       4,     5,     5,     6,     6,     7,     7,     8,     7,     8,
       8,     9,     7,     8,     8,     9,     8,     9,     9,    10,
       7,     8,     8,     9,     8,     9,     9,    10,     8,     9,
       9,    10,     9,    10,    10,    11,     7,     8,     8,     9,
       8,     9,     9,    10,     8,     9,     9,    10,     9,    10,
      10,    11,     8,     9,     9,    10,     9,    10,    10,    11,
       9,    10,    10,    11,    10,    11,    11,    12,     3,     4,
       3,     4,     1,     1,     1,     1,     2,     1,     3,     4,
       1,     3,     1,     2,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     5,     1,     2,
       3,     4,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     3,     3,     4,     2,     3,     3,     4,
       3,     4,     4,     5,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   362,     0,   352,     0,   352,     0,   352,     0,   352,
     362,     0,   357,     0,   371,     0,   255,     0,   214,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "Separator", "Comma", "Colon",
  "Semicolon", "Dash", "Percent", "Quote", "NAME", "DESCRIPTION", "SCALAR",
  "AUTHOR", "AUTHORS", "CLAUSE", "COMMENT", "COMMENTS", "GENERAL", "LEX",
  "LEXON", "PER", "PREAMBLE", "TERMS", "A", "ACCEPT", "ACCEPTS", "AFTER",
  "AFTERWARDS", "ALL", "ALSO", "AMOUNT", "AN", "AND", "ANNOUNCED",
  "APPOINT", "APPOINTS", "AS", "AT", "BE", "BEEN", "BEING", "BINARY",
  "CERTIFIED", "CERTIFIES", "CERTIFY", "COMING", "CONTRACT", "CONTRACTS",
  "CURRENT", "DATA", "DAY", "DAYS", "DECLARE", "DECLARED", "DECLARES",
  "DEFINED", "EQUAL", "EQUALING", "ESCROW", "FILE_", "FILED", "FILES",
  "FIX", "FIXED", "FIXES", "FOR", "FROM", "GIVEN", "GRANT", "GRANTS",
  "GREATER", "HAS", "HERSELF", "HIMSELF", "HOUR", "HOURS", "IF", "IN",
  "INCOMING", "INTO", "IS", "ITSELF", "LEAST", "LESS", "LIES", "MAY",
  "MILLISECOND", "MILLISECONDS", "MINUTE", "MINUTES", "MONTH", "MONTHS",
  "MYSELF", "NEITHER", "NEW", "NEXT", "NO", "NOR", "NOT", "NOTIFIES",
  "NOTIFY", "NOW", "OF", "OFF", "ON", "ONESELF", "OR", "OURSELVES",
  "PASSED", "PAST", "PAY", "PAYS", "PERSON", "PROVIDED", "REGISTER",
  "REGISTERS", "REMAINDER", "REPAY", "REPAYS", "RESPECTIVE", "RETURN",
  "RETURNS", "SECOND", "SECONDS", "SEND", "SENDS", "SIGNED", "SMALLER",
  "SO", "TERMINATE", "TERMINATES", "TEXT", "THAN", "THAT", "THE",
  "THEMSELF", "THEMSELVES", "THEN", "THERE", "THEREFOR", "THEREFORE",
  "THESE", "THIS", "TIME", "TO", "TRUE", "WAS", "WEEK", "WEEKS", "WITH",
  "YEAR", "YEARS", "YES", "YET", "YOURSELF", "YOURSELVES", "$accept",
  "Document", "Head", "Lex", "Lexon", "Authors", "Comment", "Preamble",
  "Terms", "Covenants", "Covenant", "Provisions", "Definitions",
  "Definition", "Type_Term", "Type", "Person", "Amount", "Time", "Binary",
  "Text", "Data", "This_Contract", "All_Contracts", "This", "Clauses",
  "Clause", "Body", "Function", "Statements", "Statement", "Action",
  "Subject", "Symbols", "Symbol", "Catena", "Object", "Reflexive",
  "Contract", "Predicates", "Predicate", "Permission", "Certification",
  "Certify", "Declaration", "Declare", "Filing", "File", "Registration",
  "Register", "Grantment", "Grant", "Appointment", "Appoint", "Acceptance",
  "Accept", "Fixture", "Fix", "Fixed", "Setting", "Illocutor", "Be",
  "Payment", "Pay", "Preposition", "Escrow", "From_Escrow", "Sending",
  "Send", "Notification", "Notify", "Termination", "Terminate", "Flagging",
  "Condition", "If", "Expression", "Scalar_Comparison",
  "Comparison_Operator", "Equal", "Greater", "Less", "Later",
  "Scalar_Expression", "Combination", "Combinor", "Combinand",
  "Combinator", "Or_", "And", "Neither", "Nor", "Existence", "Negation",
  "Negator", "Being", "True", "Article", "New", "Point_In_Time",
  "Current_Time", "Relative_Time", "Duration", "Time_Unit", "Years",
  "Months", "Weeks", "Days", "Hours", "Minutes", "Seconds", "Milliseconds",
  "Expiration", "Timeliness", "Name", "Description", "Scalar", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* Document: Head Terms  */
#line 1123 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 3107 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1124 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 3113 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1130 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 3119 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1131 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3125 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1132 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3131 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1133 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3137 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1134 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3143 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1135 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3149 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1136 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3155 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1137 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3161 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1138 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 3167 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1139 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3173 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1140 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3179 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1141 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3185 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1142 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3191 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1143 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3197 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1144 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3203 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1145 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3209 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1151 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 3215 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1157 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 3221 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1163 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3227 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1164 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3233 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1170 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3239 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1171 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3245 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1177 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 3251 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1183 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3257 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1184 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3263 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1185 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3269 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1186 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3275 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1187 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3281 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1188 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3287 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1189 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3293 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1190 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3299 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1196 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3305 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1197 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3311 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1203 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3317 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1204 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3323 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1205 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3329 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1206 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3335 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1212 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3341 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1213 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3347 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1214 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3353 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1215 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3359 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1221 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3365 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1222 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3371 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1228 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3377 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1229 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3383 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1230 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3389 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1231 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3395 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1237 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3401 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1238 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3407 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1244 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 3413 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1245 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 3419 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1246 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 3425 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1247 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 3431 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1248 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 3437 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1249 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 3443 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1255 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 3449 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1261 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 3455 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1267 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 3461 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1273 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 3467 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1279 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 3473 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1285 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 3479 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1291 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3485 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1292 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3491 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1298 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 3497 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1304 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3503 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1305 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3509 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1311 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3515 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1312 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3521 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1318 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 3527 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1324 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 3533 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1325 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 3539 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1331 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3545 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1332 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3551 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1333 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3557 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1334 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3563 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1340 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3569 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1341 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3575 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1347 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3581 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1348 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3587 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1354 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3593 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1355 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3599 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Predicates Separator  */
#line 1356 "parser.y"
                                                                    { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3605 "parser.c"
    break;

  case 86: /* Action: Subject Permission Condition Colon Predicates Separator  */
#line 1357 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3611 "parser.c"
    break;

  case 87: /* Action: Subject Permission Condition Comma Predicates Separator  */
#line 1358 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3617 "parser.c"
    break;

  case 88: /* Action: Subject Permission Condition Comma Colon Predicates Separator  */
#line 1359 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3623 "parser.c"
    break;

  case 89: /* Action: Subject Permission Comma Predicates Separator  */
#line 1360 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3629 "parser.c"
    break;

  case 90: /* Action: Subject Permission Comma Condition Predicates Separator  */
#line 1361 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3635 "parser.c"
    break;

  case 91: /* Action: Subject Permission Comma Condition Colon Predicates Separator  */
#line 1362 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3641 "parser.c"
    break;

  case 92: /* Action: Subject Permission Comma Condition Comma Predicates Separator  */
#line 1363 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3647 "parser.c"
    break;

  case 93: /* Action: Subject Permission Comma Condition Comma Colon Predicates Separator  */
#line 1364 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3653 "parser.c"
    break;

  case 94: /* Subject: Symbols  */
#line 1370 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3659 "parser.c"
    break;

  case 95: /* Symbols: Symbol  */
#line 1376 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3665 "parser.c"
    break;

  case 96: /* Symbols: Symbols Catena Symbol  */
#line 1377 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3671 "parser.c"
    break;

  case 97: /* Symbol: Name  */
#line 1383 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3677 "parser.c"
    break;

  case 98: /* Symbol: New Name  */
#line 1384 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3683 "parser.c"
    break;

  case 99: /* Symbol: Article Name  */
#line 1385 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3689 "parser.c"
    break;

  case 100: /* Symbol: Article New Name  */
#line 1386 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3695 "parser.c"
    break;

  case 101: /* Symbol: Type  */
#line 1387 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3701 "parser.c"
    break;

  case 102: /* Symbol: New Type  */
#line 1388 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3707 "parser.c"
    break;

  case 103: /* Symbol: Article Type  */
#line 1389 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3713 "parser.c"
    break;

  case 104: /* Symbol: Article New Type  */
#line 1390 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3719 "parser.c"
    break;

  case 105: /* Catena: OR  */
#line 1396 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3725 "parser.c"
    break;

  case 106: /* Catena: Comma  */
#line 1397 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3731 "parser.c"
    break;

  case 107: /* Object: Symbol  */
#line 1403 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3737 "parser.c"
    break;

  case 108: /* Object: Reflexive  */
#line 1404 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3743 "parser.c"
    break;

  case 109: /* Object: ESCROW  */
#line 1405 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3749 "parser.c"
    break;

  case 110: /* Object: THE ESCROW  */
#line 1406 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3755 "parser.c"
    break;

  case 111: /* Reflexive: MYSELF  */
#line 1412 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3761 "parser.c"
    break;

  case 112: /* Reflexive: YOURSELF  */
#line 1413 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3767 "parser.c"
    break;

  case 113: /* Reflexive: HERSELF  */
#line 1414 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3773 "parser.c"
    break;

  case 114: /* Reflexive: HIMSELF  */
#line 1415 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3779 "parser.c"
    break;

  case 115: /* Reflexive: ONESELF  */
#line 1416 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3785 "parser.c"
    break;

  case 116: /* Reflexive: ITSELF  */
#line 1417 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3791 "parser.c"
    break;

  case 117: /* Reflexive: THEMSELF  */
#line 1418 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3797 "parser.c"
    break;

  case 118: /* Reflexive: OURSELVES  */
#line 1419 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3803 "parser.c"
    break;

  case 119: /* Reflexive: YOURSELVES  */
#line 1420 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3809 "parser.c"
    break;

  case 120: /* Reflexive: THEMSELVES  */
#line 1421 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3815 "parser.c"
    break;

  case 121: /* Contract: This_Contract  */
#line 1427 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3821 "parser.c"
    break;

  case 122: /* Contract: All_Contracts  */
#line 1428 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3827 "parser.c"
    break;

  case 123: /* Predicates: Predicates Comma Predicate  */
#line 1434 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3833 "parser.c"
    break;

  case 124: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1435 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3839 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1436 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3845 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1437 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3851 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma AND Predicate  */
#line 1438 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3857 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1439 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3863 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1440 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3869 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1441 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3875 "parser.c"
    break;

  case 131: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1442 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3881 "parser.c"
    break;

  case 132: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1443 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3887 "parser.c"
    break;

  case 133: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1444 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3893 "parser.c"
    break;

  case 134: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1445 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3899 "parser.c"
    break;

  case 135: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1446 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3905 "parser.c"
    break;

  case 136: /* Predicates: Predicate  */
#line 1447 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3911 "parser.c"
    break;

  case 137: /* Predicate: Certification  */
#line 1453 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3917 "parser.c"
    break;

  case 138: /* Predicate: Declaration  */
#line 1454 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3923 "parser.c"
    break;

  case 139: /* Predicate: Filing  */
#line 1455 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3929 "parser.c"
    break;

  case 140: /* Predicate: Registration  */
#line 1456 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3935 "parser.c"
    break;

  case 141: /* Predicate: Grantment  */
#line 1457 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3941 "parser.c"
    break;

  case 142: /* Predicate: Appointment  */
#line 1458 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3947 "parser.c"
    break;

  case 143: /* Predicate: Acceptance  */
#line 1459 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Acceptance=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Acceptance); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3953 "parser.c"
    break;

  case 144: /* Predicate: Fixture  */
#line 1460 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3959 "parser.c"
    break;

  case 145: /* Predicate: Setting  */
#line 1461 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3965 "parser.c"
    break;

  case 146: /* Predicate: Payment  */
#line 1462 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3971 "parser.c"
    break;

  case 147: /* Predicate: Sending  */
#line 1463 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3977 "parser.c"
    break;

  case 148: /* Predicate: Notification  */
#line 1464 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3983 "parser.c"
    break;

  case 149: /* Predicate: Termination  */
#line 1465 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3989 "parser.c"
    break;

  case 150: /* Permission: MAY  */
#line 1471 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 3995 "parser.c"
    break;

  case 151: /* Certification: Certify Symbol  */
#line 1477 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4001 "parser.c"
    break;

  case 152: /* Certification: Certify Symbol Expression  */
#line 1478 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4007 "parser.c"
    break;

  case 153: /* Certification: Certify Symbol AS Expression  */
#line 1479 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4013 "parser.c"
    break;

  case 154: /* Certification: Certify Contract Symbol  */
#line 1480 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4019 "parser.c"
    break;

  case 155: /* Certification: Certify Contract AS Symbol  */
#line 1481 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4025 "parser.c"
    break;

  case 156: /* Certify: CERTIFY  */
#line 1487 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4031 "parser.c"
    break;

  case 157: /* Certify: CERTIFIES  */
#line 1488 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4037 "parser.c"
    break;

  case 158: /* Declaration: Declare Symbol  */
#line 1494 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4043 "parser.c"
    break;

  case 159: /* Declaration: Declare Symbol Expression  */
#line 1495 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4049 "parser.c"
    break;

  case 160: /* Declaration: Declare Symbol TO BE Expression  */
#line 1496 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4055 "parser.c"
    break;

  case 161: /* Declaration: Declare Contract Symbol  */
#line 1497 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4061 "parser.c"
    break;

  case 162: /* Declaration: Declare Contract AS Symbol  */
#line 1498 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4067 "parser.c"
    break;

  case 163: /* Declare: DECLARE  */
#line 1504 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4073 "parser.c"
    break;

  case 164: /* Declare: DECLARES  */
#line 1505 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4079 "parser.c"
    break;

  case 165: /* Filing: File Symbol  */
#line 1511 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4085 "parser.c"
    break;

  case 166: /* Filing: File Symbol Expression  */
#line 1512 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4091 "parser.c"
    break;

  case 167: /* Filing: File Symbol TO BE Expression  */
#line 1513 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4097 "parser.c"
    break;

  case 168: /* Filing: File FOR Symbol  */
#line 1514 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4103 "parser.c"
    break;

  case 169: /* Filing: File FOR Symbol Expression  */
#line 1515 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4109 "parser.c"
    break;

  case 170: /* Filing: File FOR Symbol TO BE Expression  */
#line 1516 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4115 "parser.c"
    break;

  case 171: /* Filing: File Contract Symbol  */
#line 1517 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4121 "parser.c"
    break;

  case 172: /* Filing: File Contract TO BE Symbol  */
#line 1518 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4127 "parser.c"
    break;

  case 173: /* Filing: File FOR Contract Symbol  */
#line 1519 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4133 "parser.c"
    break;

  case 174: /* Filing: File FOR Contract TO BE Symbol  */
#line 1520 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4139 "parser.c"
    break;

  case 175: /* File: FILE_  */
#line 1526 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4145 "parser.c"
    break;

  case 176: /* File: FILES  */
#line 1527 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4151 "parser.c"
    break;

  case 177: /* Registration: Register Symbol  */
#line 1533 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4157 "parser.c"
    break;

  case 178: /* Registration: Register Symbol Expression  */
#line 1534 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4163 "parser.c"
    break;

  case 179: /* Registration: Register Symbol AS Expression  */
#line 1535 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4169 "parser.c"
    break;

  case 180: /* Registration: Register Contract Symbol  */
#line 1536 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4175 "parser.c"
    break;

  case 181: /* Registration: Register Contract AS Symbol  */
#line 1537 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4181 "parser.c"
    break;

  case 182: /* Register: REGISTER  */
#line 1543 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4187 "parser.c"
    break;

  case 183: /* Register: REGISTERS  */
#line 1544 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4193 "parser.c"
    break;

  case 184: /* Grantment: Grant Symbol  */
#line 1550 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 4199 "parser.c"
    break;

  case 185: /* Grant: GRANT  */
#line 1556 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4205 "parser.c"
    break;

  case 186: /* Grant: GRANTS  */
#line 1557 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4211 "parser.c"
    break;

  case 187: /* Appointment: Appoint Symbol  */
#line 1563 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4217 "parser.c"
    break;

  case 188: /* Appointment: Appoint Symbol Expression  */
#line 1564 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4223 "parser.c"
    break;

  case 189: /* Appointment: Appoint Symbol AS Expression  */
#line 1565 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4229 "parser.c"
    break;

  case 190: /* Appoint: APPOINT  */
#line 1571 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4235 "parser.c"
    break;

  case 191: /* Appoint: APPOINTS  */
#line 1572 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4241 "parser.c"
    break;

  case 192: /* Acceptance: Accept Symbol  */
#line 1578 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4247 "parser.c"
    break;

  case 193: /* Acceptance: Accept Symbol Expression  */
#line 1579 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4253 "parser.c"
    break;

  case 194: /* Acceptance: Accept Symbol AS Expression  */
#line 1580 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4259 "parser.c"
    break;

  case 195: /* Accept: ACCEPT  */
#line 1586 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4265 "parser.c"
    break;

  case 196: /* Accept: ACCEPTS  */
#line 1587 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4271 "parser.c"
    break;

  case 197: /* Fixture: Fix Symbol  */
#line 1593 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4277 "parser.c"
    break;

  case 198: /* Fixture: Fix Symbol AS Expression  */
#line 1594 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4283 "parser.c"
    break;

  case 199: /* Fixture: Fix Contract AS Symbol  */
#line 1595 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4289 "parser.c"
    break;

  case 200: /* Fix: FIX  */
#line 1601 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4295 "parser.c"
    break;

  case 201: /* Fix: FIXES  */
#line 1602 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4301 "parser.c"
    break;

  case 202: /* Fixed: FIXED  */
#line 1608 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 4307 "parser.c"
    break;

  case 203: /* Setting: Illocutor Symbol  */
#line 1614 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4313 "parser.c"
    break;

  case 204: /* Setting: Illocutor THEREFOR Symbol  */
#line 1615 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4319 "parser.c"
    break;

  case 205: /* Setting: Illocutor THEREFORE Symbol  */
#line 1616 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4325 "parser.c"
    break;

  case 206: /* Setting: Illocutor THEN Symbol  */
#line 1617 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4331 "parser.c"
    break;

  case 207: /* Setting: Illocutor THEN THEREFOR Symbol  */
#line 1618 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4337 "parser.c"
    break;

  case 208: /* Setting: Illocutor THEN THEREFORE Symbol  */
#line 1619 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4343 "parser.c"
    break;

  case 209: /* Illocutor: Be  */
#line 1625 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4349 "parser.c"
    break;

  case 210: /* Illocutor: Be AS  */
#line 1626 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4355 "parser.c"
    break;

  case 211: /* Illocutor: Be DEFINED  */
#line 1627 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4361 "parser.c"
    break;

  case 212: /* Illocutor: Be DEFINED AS  */
#line 1628 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4367 "parser.c"
    break;

  case 213: /* Be: BE  */
#line 1634 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4373 "parser.c"
    break;

  case 214: /* Be: IS  */
#line 1635 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4379 "parser.c"
    break;

  case 215: /* Payment: Pay Expression Preposition Object  */
#line 1641 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4385 "parser.c"
    break;

  case 216: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1642 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4391 "parser.c"
    break;

  case 217: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1643 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4397 "parser.c"
    break;

  case 218: /* Payment: Pay Escrow Preposition Object  */
#line 1644 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4403 "parser.c"
    break;

  case 219: /* Pay: PAY  */
#line 1650 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4409 "parser.c"
    break;

  case 220: /* Pay: PAYS  */
#line 1651 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4415 "parser.c"
    break;

  case 221: /* Pay: RETURN  */
#line 1652 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4421 "parser.c"
    break;

  case 222: /* Pay: RETURNS  */
#line 1653 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4427 "parser.c"
    break;

  case 223: /* Pay: REPAY  */
#line 1654 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4433 "parser.c"
    break;

  case 224: /* Pay: REPAYS  */
#line 1655 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4439 "parser.c"
    break;

  case 225: /* Preposition: TO  */
#line 1661 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4445 "parser.c"
    break;

  case 226: /* Preposition: INTO  */
#line 1662 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4451 "parser.c"
    break;

  case 227: /* Preposition: OF  */
#line 1663 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4457 "parser.c"
    break;

  case 228: /* Escrow: ESCROW  */
#line 1669 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4463 "parser.c"
    break;

  case 229: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1670 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4469 "parser.c"
    break;

  case 230: /* Escrow: THE ESCROW  */
#line 1671 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4475 "parser.c"
    break;

  case 231: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1672 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4481 "parser.c"
    break;

  case 232: /* From_Escrow: FROM ESCROW  */
#line 1678 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4487 "parser.c"
    break;

  case 233: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1679 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4493 "parser.c"
    break;

  case 234: /* From_Escrow: FROM THE ESCROW  */
#line 1680 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4499 "parser.c"
    break;

  case 235: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1681 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4505 "parser.c"
    break;

  case 236: /* Sending: Send Expression Preposition Object  */
#line 1687 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 4511 "parser.c"
    break;

  case 237: /* Send: SEND  */
#line 1693 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4517 "parser.c"
    break;

  case 238: /* Send: SENDS  */
#line 1694 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4523 "parser.c"
    break;

  case 239: /* Notification: Notify Object  */
#line 1700 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4529 "parser.c"
    break;

  case 240: /* Notification: Notify Object Preposition Expression  */
#line 1701 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4535 "parser.c"
    break;

  case 241: /* Notify: NOTIFY  */
#line 1707 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4541 "parser.c"
    break;

  case 242: /* Notify: NOTIFIES  */
#line 1708 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4547 "parser.c"
    break;

  case 243: /* Termination: Terminate This_Contract  */
#line 1714 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4553 "parser.c"
    break;

  case 244: /* Termination: Terminate All_Contracts  */
#line 1715 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4559 "parser.c"
    break;

  case 245: /* Terminate: TERMINATE  */
#line 1721 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4565 "parser.c"
    break;

  case 246: /* Terminate: TERMINATES  */
#line 1722 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4571 "parser.c"
    break;

  case 247: /* Flagging: Illocutor Symbol Separator  */
#line 1728 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4577 "parser.c"
    break;

  case 248: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1729 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4583 "parser.c"
    break;

  case 249: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1730 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4589 "parser.c"
    break;

  case 250: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1731 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4595 "parser.c"
    break;

  case 251: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1732 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4601 "parser.c"
    break;

  case 252: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1733 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4607 "parser.c"
    break;

  case 253: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1734 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4613 "parser.c"
    break;

  case 254: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1735 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4619 "parser.c"
    break;

  case 255: /* Condition: If Expression  */
#line 1741 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4625 "parser.c"
    break;

  case 256: /* Condition: If Expression THEN  */
#line 1742 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4631 "parser.c"
    break;

  case 257: /* Condition: If Expression Comma THEN  */
#line 1743 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4637 "parser.c"
    break;

  case 258: /* If: IF  */
#line 1749 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4643 "parser.c"
    break;

  case 259: /* If: GIVEN THAT  */
#line 1750 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4649 "parser.c"
    break;

  case 260: /* If: PROVIDED  */
#line 1751 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4655 "parser.c"
    break;

  case 261: /* Expression: Combination  */
#line 1757 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 4661 "parser.c"
    break;

  case 262: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1763 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 4667 "parser.c"
    break;

  case 263: /* Comparison_Operator: Equal  */
#line 1769 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4673 "parser.c"
    break;

  case 264: /* Comparison_Operator: Greater  */
#line 1770 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Greater=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Greater); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4679 "parser.c"
    break;

  case 265: /* Comparison_Operator: Less  */
#line 1771 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Less=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Less); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4685 "parser.c"
    break;

  case 266: /* Comparison_Operator: Later  */
#line 1772 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4691 "parser.c"
    break;

  case 267: /* Equal: EQUAL  */
#line 1778 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4697 "parser.c"
    break;

  case 268: /* Equal: EQUAL TO  */
#line 1779 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4703 "parser.c"
    break;

  case 269: /* Equal: EQUALING  */
#line 1780 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4709 "parser.c"
    break;

  case 270: /* Equal: IS  */
#line 1781 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4715 "parser.c"
    break;

  case 271: /* Equal: IS EQUAL  */
#line 1782 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4721 "parser.c"
    break;

  case 272: /* Equal: IS EQUAL TO  */
#line 1783 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4727 "parser.c"
    break;

  case 273: /* Equal: BEING  */
#line 1784 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4733 "parser.c"
    break;

  case 274: /* Equal: BEING EQUAL  */
#line 1785 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4739 "parser.c"
    break;

  case 275: /* Equal: BEING EQUAL TO  */
#line 1786 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4745 "parser.c"
    break;

  case 276: /* Greater: GREATER BEING GREATER  */
#line 1792 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4751 "parser.c"
    break;

  case 277: /* Greater: GREATER BEING GREATER THAN  */
#line 1793 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4757 "parser.c"
    break;

  case 278: /* Greater: GREATER THAN BEING GREATER  */
#line 1794 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4763 "parser.c"
    break;

  case 279: /* Greater: GREATER THAN BEING GREATER THAN  */
#line 1795 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4769 "parser.c"
    break;

  case 280: /* Greater: IS GREATER BEING GREATER  */
#line 1796 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4775 "parser.c"
    break;

  case 281: /* Greater: IS GREATER BEING GREATER THAN  */
#line 1797 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4781 "parser.c"
    break;

  case 282: /* Greater: IS GREATER THAN BEING GREATER  */
#line 1798 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4787 "parser.c"
    break;

  case 283: /* Greater: IS GREATER THAN BEING GREATER THAN  */
#line 1799 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4793 "parser.c"
    break;

  case 284: /* Less: LESS BEING LESS SMALLER BEING SMALLER  */
#line 1805 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4799 "parser.c"
    break;

  case 285: /* Less: LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1806 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4805 "parser.c"
    break;

  case 286: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1807 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4811 "parser.c"
    break;

  case 287: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1808 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4817 "parser.c"
    break;

  case 288: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1809 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4823 "parser.c"
    break;

  case 289: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1810 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4829 "parser.c"
    break;

  case 290: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1811 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4835 "parser.c"
    break;

  case 291: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1812 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4841 "parser.c"
    break;

  case 292: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1813 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4847 "parser.c"
    break;

  case 293: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1814 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4853 "parser.c"
    break;

  case 294: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1815 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4859 "parser.c"
    break;

  case 295: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1816 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4865 "parser.c"
    break;

  case 296: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1817 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4871 "parser.c"
    break;

  case 297: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1818 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4877 "parser.c"
    break;

  case 298: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1819 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4883 "parser.c"
    break;

  case 299: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1820 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4889 "parser.c"
    break;

  case 300: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1821 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4895 "parser.c"
    break;

  case 301: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1822 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4901 "parser.c"
    break;

  case 302: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1823 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4907 "parser.c"
    break;

  case 303: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1824 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4913 "parser.c"
    break;

  case 304: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1825 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4919 "parser.c"
    break;

  case 305: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1826 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4925 "parser.c"
    break;

  case 306: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1827 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4931 "parser.c"
    break;

  case 307: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1828 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4937 "parser.c"
    break;

  case 308: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1829 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4943 "parser.c"
    break;

  case 309: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1830 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4949 "parser.c"
    break;

  case 310: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1831 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4955 "parser.c"
    break;

  case 311: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1832 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4961 "parser.c"
    break;

  case 312: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1833 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4967 "parser.c"
    break;

  case 313: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1834 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4973 "parser.c"
    break;

  case 314: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1835 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4979 "parser.c"
    break;

  case 315: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1836 "parser.y"
                                                                                { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4985 "parser.c"
    break;

  case 316: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER  */
#line 1837 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4991 "parser.c"
    break;

  case 317: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1838 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4997 "parser.c"
    break;

  case 318: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1839 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5003 "parser.c"
    break;

  case 319: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1840 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5009 "parser.c"
    break;

  case 320: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1841 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5015 "parser.c"
    break;

  case 321: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1842 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5021 "parser.c"
    break;

  case 322: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1843 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5027 "parser.c"
    break;

  case 323: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1844 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5033 "parser.c"
    break;

  case 324: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1845 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5039 "parser.c"
    break;

  case 325: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1846 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5045 "parser.c"
    break;

  case 326: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1847 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5051 "parser.c"
    break;

  case 327: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1848 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5057 "parser.c"
    break;

  case 328: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1849 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5063 "parser.c"
    break;

  case 329: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1850 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5069 "parser.c"
    break;

  case 330: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1851 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5075 "parser.c"
    break;

  case 331: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1852 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5081 "parser.c"
    break;

  case 332: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1853 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5087 "parser.c"
    break;

  case 333: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1854 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5093 "parser.c"
    break;

  case 334: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1855 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5099 "parser.c"
    break;

  case 335: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1856 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5105 "parser.c"
    break;

  case 336: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1857 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5111 "parser.c"
    break;

  case 337: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1858 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5117 "parser.c"
    break;

  case 338: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1859 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5123 "parser.c"
    break;

  case 339: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1860 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5129 "parser.c"
    break;

  case 340: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1861 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5135 "parser.c"
    break;

  case 341: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1862 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5141 "parser.c"
    break;

  case 342: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1863 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5147 "parser.c"
    break;

  case 343: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1864 "parser.y"
                                                                               { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5153 "parser.c"
    break;

  case 344: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1865 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5159 "parser.c"
    break;

  case 345: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1866 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5165 "parser.c"
    break;

  case 346: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1867 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5171 "parser.c"
    break;

  case 347: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1868 "parser.y"
                                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5177 "parser.c"
    break;

  case 348: /* Later: IS AT LEAST  */
#line 1874 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5183 "parser.c"
    break;

  case 349: /* Later: IS AT THE LEAST  */
#line 1875 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5189 "parser.c"
    break;

  case 350: /* Later: LIES AT LEAST  */
#line 1876 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5195 "parser.c"
    break;

  case 351: /* Later: LIES AT THE LEAST  */
#line 1877 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5201 "parser.c"
    break;

  case 352: /* Scalar_Expression: Symbol  */
#line 1883 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5207 "parser.c"
    break;

  case 353: /* Scalar_Expression: Scalar  */
#line 1884 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5213 "parser.c"
    break;

  case 354: /* Scalar_Expression: Point_In_Time  */
#line 1885 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5219 "parser.c"
    break;

  case 355: /* Scalar_Expression: ESCROW  */
#line 1886 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5225 "parser.c"
    break;

  case 356: /* Scalar_Expression: THE ESCROW  */
#line 1887 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5231 "parser.c"
    break;

  case 357: /* Combination: Combinor  */
#line 1893 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5237 "parser.c"
    break;

  case 358: /* Combination: Combinor Comma Combination  */
#line 1894 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5243 "parser.c"
    break;

  case 359: /* Combination: Combinor Comma Combinator Combination  */
#line 1895 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5249 "parser.c"
    break;

  case 360: /* Combinor: Combinand  */
#line 1901 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5255 "parser.c"
    break;

  case 361: /* Combinor: Combinand Combinator Combinor  */
#line 1902 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5261 "parser.c"
    break;

  case 362: /* Combinand: Symbol  */
#line 1908 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5267 "parser.c"
    break;

  case 363: /* Combinand: Symbol Expiration  */
#line 1909 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5273 "parser.c"
    break;

  case 364: /* Combinand: Symbol Timeliness  */
#line 1910 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Timeliness=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Timeliness); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5279 "parser.c"
    break;

  case 365: /* Combinand: Reflexive  */
#line 1911 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5285 "parser.c"
    break;

  case 366: /* Combinand: Description  */
#line 1912 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5291 "parser.c"
    break;

  case 367: /* Combinand: Article Description  */
#line 1913 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5297 "parser.c"
    break;

  case 368: /* Combinand: Scalar_Comparison  */
#line 1914 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5303 "parser.c"
    break;

  case 369: /* Combinand: Negation  */
#line 1915 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5309 "parser.c"
    break;

  case 370: /* Combinand: Existence  */
#line 1916 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5315 "parser.c"
    break;

  case 371: /* Combinand: Point_In_Time  */
#line 1917 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5321 "parser.c"
    break;

  case 372: /* Combinand: Expiration  */
#line 1918 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5327 "parser.c"
    break;

  case 373: /* Combinator: Or_  */
#line 1924 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5333 "parser.c"
    break;

  case 374: /* Combinator: And  */
#line 1925 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5339 "parser.c"
    break;

  case 375: /* Combinator: Neither  */
#line 1926 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5345 "parser.c"
    break;

  case 376: /* Combinator: Nor  */
#line 1927 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5351 "parser.c"
    break;

  case 377: /* Or_: OR  */
#line 1933 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 5357 "parser.c"
    break;

  case 378: /* And: AND  */
#line 1939 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 5363 "parser.c"
    break;

  case 379: /* Neither: NEITHER  */
#line 1945 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 5369 "parser.c"
    break;

  case 380: /* Nor: NOR  */
#line 1951 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 5375 "parser.c"
    break;

  case 381: /* Existence: Symbol Equal Fixed  */
#line 1957 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5381 "parser.c"
    break;

  case 382: /* Existence: THERE Be Symbol  */
#line 1958 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5387 "parser.c"
    break;

  case 383: /* Existence: Contract Be Symbol  */
#line 1959 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5393 "parser.c"
    break;

  case 384: /* Existence: Symbol Being True  */
#line 1960 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5399 "parser.c"
    break;

  case 385: /* Negation: Negator Symbol  */
#line 1966 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5405 "parser.c"
    break;

  case 386: /* Negation: Symbol Negator Fixed  */
#line 1967 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5411 "parser.c"
    break;

  case 387: /* Negation: THERE Negator Symbol  */
#line 1968 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5417 "parser.c"
    break;

  case 388: /* Negation: Contract Negator Symbol  */
#line 1969 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5423 "parser.c"
    break;

  case 389: /* Negator: NOT  */
#line 1975 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5429 "parser.c"
    break;

  case 390: /* Negator: Be NOT  */
#line 1976 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5435 "parser.c"
    break;

  case 391: /* Negator: NO  */
#line 1977 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5441 "parser.c"
    break;

  case 392: /* Negator: Be NO  */
#line 1978 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5447 "parser.c"
    break;

  case 393: /* Being: IS  */
#line 1984 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5453 "parser.c"
    break;

  case 394: /* Being: HAS BEEN  */
#line 1985 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5459 "parser.c"
    break;

  case 395: /* Being: WAS  */
#line 1986 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5465 "parser.c"
    break;

  case 396: /* True: TRUE  */
#line 1992 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5471 "parser.c"
    break;

  case 397: /* True: YES  */
#line 1993 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5477 "parser.c"
    break;

  case 398: /* True: CERTIFIED  */
#line 1994 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5483 "parser.c"
    break;

  case 399: /* True: DECLARED  */
#line 1995 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5489 "parser.c"
    break;

  case 400: /* True: ANNOUNCED  */
#line 1996 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5495 "parser.c"
    break;

  case 401: /* True: FILED  */
#line 1997 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5501 "parser.c"
    break;

  case 402: /* True: FILED FOR  */
#line 1998 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5507 "parser.c"
    break;

  case 403: /* True: SIGNED OFF  */
#line 1999 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5513 "parser.c"
    break;

  case 404: /* True: SIGNED OFF ON  */
#line 2000 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5519 "parser.c"
    break;

  case 405: /* Article: A  */
#line 2006 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5525 "parser.c"
    break;

  case 406: /* Article: AN  */
#line 2007 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5531 "parser.c"
    break;

  case 407: /* Article: THE  */
#line 2008 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5537 "parser.c"
    break;

  case 408: /* New: NEW  */
#line 2014 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5543 "parser.c"
    break;

  case 409: /* New: NEXT  */
#line 2015 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5549 "parser.c"
    break;

  case 410: /* New: COMING  */
#line 2016 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5555 "parser.c"
    break;

  case 411: /* New: INCOMING  */
#line 2017 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5561 "parser.c"
    break;

  case 412: /* Point_In_Time: Current_Time  */
#line 2023 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5567 "parser.c"
    break;

  case 413: /* Point_In_Time: Relative_Time  */
#line 2024 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5573 "parser.c"
    break;

  case 414: /* Current_Time: THE CURRENT TIME  */
#line 2030 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5579 "parser.c"
    break;

  case 415: /* Current_Time: THE THEN CURRENT TIME  */
#line 2031 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5585 "parser.c"
    break;

  case 416: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 2032 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5591 "parser.c"
    break;

  case 417: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 2033 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5597 "parser.c"
    break;

  case 418: /* Current_Time: NOW  */
#line 2034 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5603 "parser.c"
    break;

  case 419: /* Relative_Time: Duration PAST  */
#line 2040 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5609 "parser.c"
    break;

  case 420: /* Relative_Time: Duration PAST Symbol  */
#line 2041 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5615 "parser.c"
    break;

  case 421: /* Relative_Time: Duration IN THE PAST  */
#line 2042 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5621 "parser.c"
    break;

  case 422: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 2043 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5627 "parser.c"
    break;

  case 423: /* Relative_Time: Duration AFTER Symbol  */
#line 2044 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5633 "parser.c"
    break;

  case 424: /* Duration: Scalar_Expression Time_Unit  */
#line 2050 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 5639 "parser.c"
    break;

  case 425: /* Time_Unit: Years  */
#line 2056 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5645 "parser.c"
    break;

  case 426: /* Time_Unit: Months  */
#line 2057 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5651 "parser.c"
    break;

  case 427: /* Time_Unit: Weeks  */
#line 2058 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5657 "parser.c"
    break;

  case 428: /* Time_Unit: Days  */
#line 2059 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5663 "parser.c"
    break;

  case 429: /* Time_Unit: Hours  */
#line 2060 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5669 "parser.c"
    break;

  case 430: /* Time_Unit: Minutes  */
#line 2061 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5675 "parser.c"
    break;

  case 431: /* Time_Unit: Seconds  */
#line 2062 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5681 "parser.c"
    break;

  case 432: /* Time_Unit: Milliseconds  */
#line 2063 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5687 "parser.c"
    break;

  case 433: /* Years: YEAR  */
#line 2069 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5693 "parser.c"
    break;

  case 434: /* Years: YEARS  */
#line 2070 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5699 "parser.c"
    break;

  case 435: /* Months: MONTH  */
#line 2076 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5705 "parser.c"
    break;

  case 436: /* Months: MONTHS  */
#line 2077 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5711 "parser.c"
    break;

  case 437: /* Weeks: WEEK  */
#line 2083 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5717 "parser.c"
    break;

  case 438: /* Weeks: WEEKS  */
#line 2084 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5723 "parser.c"
    break;

  case 439: /* Days: DAY  */
#line 2090 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5729 "parser.c"
    break;

  case 440: /* Days: DAYS  */
#line 2091 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5735 "parser.c"
    break;

  case 441: /* Hours: HOUR  */
#line 2097 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5741 "parser.c"
    break;

  case 442: /* Hours: HOURS  */
#line 2098 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5747 "parser.c"
    break;

  case 443: /* Minutes: MINUTE  */
#line 2104 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5753 "parser.c"
    break;

  case 444: /* Minutes: MINUTES  */
#line 2105 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5759 "parser.c"
    break;

  case 445: /* Seconds: SECOND  */
#line 2111 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5765 "parser.c"
    break;

  case 446: /* Seconds: SECONDS  */
#line 2112 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5771 "parser.c"
    break;

  case 447: /* Milliseconds: MILLISECOND  */
#line 2118 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5777 "parser.c"
    break;

  case 448: /* Milliseconds: MILLISECONDS  */
#line 2119 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5783 "parser.c"
    break;

  case 449: /* Expiration: HAS PASSED  */
#line 2125 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5789 "parser.c"
    break;

  case 450: /* Expiration: PAST  */
#line 2126 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5795 "parser.c"
    break;

  case 451: /* Expiration: IS PAST  */
#line 2127 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5801 "parser.c"
    break;

  case 452: /* Timeliness: NOT PASSED  */
#line 2133 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5807 "parser.c"
    break;

  case 453: /* Timeliness: NOT YET PASSED  */
#line 2134 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5813 "parser.c"
    break;

  case 454: /* Timeliness: HAS NOT PASSED  */
#line 2135 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5819 "parser.c"
    break;

  case 455: /* Timeliness: HAS NOT YET PASSED  */
#line 2136 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5825 "parser.c"
    break;

  case 456: /* Timeliness: NOT PAST  */
#line 2137 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5831 "parser.c"
    break;

  case 457: /* Timeliness: NOT PAST YET  */
#line 2138 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5837 "parser.c"
    break;

  case 458: /* Timeliness: NOT YET PAST  */
#line 2139 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5843 "parser.c"
    break;

  case 459: /* Timeliness: NOT YET PAST YET  */
#line 2140 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5849 "parser.c"
    break;

  case 460: /* Timeliness: IS NOT PAST  */
#line 2141 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5855 "parser.c"
    break;

  case 461: /* Timeliness: IS NOT PAST YET  */
#line 2142 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5861 "parser.c"
    break;

  case 462: /* Timeliness: IS NOT YET PAST  */
#line 2143 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5867 "parser.c"
    break;

  case 463: /* Timeliness: IS NOT YET PAST YET  */
#line 2144 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5873 "parser.c"
    break;

  case 464: /* Name: NAME  */
#line 2148 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 5879 "parser.c"
    break;

  case 465: /* Description: DESCRIPTION  */
#line 2151 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 5885 "parser.c"
    break;

  case 466: /* Scalar: SCALAR  */
#line 2154 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 5891 "parser.c"
    break;


#line 5895 "parser.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yystrlen (yysymbol_name (yyarg[yyi]));
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 2159 "parser.y"


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
	// Symbol->New
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
	// Predicate->Acceptance
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
	// Appointment->Expression
	return Appointment;
}

Appoint *process_appoint(Appoint *Appoint) {
	if(opt_debug_actions) printf("actions: parsing Appoint '%s'\n", Appoint->Literal);
	return Appoint;
}

Acceptance *process_acceptance(Acceptance *Acceptance) {
	if(opt_debug_actions) printf("actions: parsing Acceptance '%s'\n", Acceptance->Literal);
	// Acceptance->Accept
	// Acceptance->Symbol
	// Acceptance->Expression
	return Acceptance;
}

Accept *process_accept(Accept *Accept) {
	if(opt_debug_actions) printf("actions: parsing Accept '%s'\n", Accept->Literal);
	return Accept;
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
	// Comparison_Operator->Greater
	// Comparison_Operator->Less
	// Comparison_Operator->Later
	return Comparison_Operator;
}

Equal *process_equal(Equal *Equal) {
	if(opt_debug_actions) printf("actions: parsing Equal '%s'\n", Equal->Literal);
	return Equal;
}

Greater *process_greater(Greater *Greater) {
	if(opt_debug_actions) printf("actions: parsing Greater '%s'\n", Greater->Literal);
	return Greater;
}

Less *process_less(Less *Less) {
	if(opt_debug_actions) printf("actions: parsing Less '%s'\n", Less->Literal);
	return Less;
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
	if(opt_debug_actions) printf("actions: parsing Combinand %s\n", Combinand->Description);
	// Combinand->Symbol
	// Combinand->Expiration
	// Combinand->Timeliness
	// Combinand->Reflexive
	// Combinand->Description
	// Combinand->Article
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

New *process_new(New *New) {
	if(opt_debug_actions) printf("actions: parsing New '%s'\n", New->Literal);
	return New;
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

Timeliness *process_timeliness(Timeliness *Timeliness) {
	if(opt_debug_actions) printf("actions: parsing Timeliness '%s'\n", Timeliness->Literal);
	return Timeliness;
}

