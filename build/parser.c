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
  YYSYMBOL_TRANSFER = 146,                 /* TRANSFER  */
  YYSYMBOL_TRANSFERS = 147,                /* TRANSFERS  */
  YYSYMBOL_TRUE = 148,                     /* TRUE  */
  YYSYMBOL_WAS = 149,                      /* WAS  */
  YYSYMBOL_WEEK = 150,                     /* WEEK  */
  YYSYMBOL_WEEKS = 151,                    /* WEEKS  */
  YYSYMBOL_WITH = 152,                     /* WITH  */
  YYSYMBOL_YEAR = 153,                     /* YEAR  */
  YYSYMBOL_YEARS = 154,                    /* YEARS  */
  YYSYMBOL_YES = 155,                      /* YES  */
  YYSYMBOL_YET = 156,                      /* YET  */
  YYSYMBOL_YOURSELF = 157,                 /* YOURSELF  */
  YYSYMBOL_YOURSELVES = 158,               /* YOURSELVES  */
  YYSYMBOL_YYACCEPT = 159,                 /* $accept  */
  YYSYMBOL_Document = 160,                 /* Document  */
  YYSYMBOL_Head = 161,                     /* Head  */
  YYSYMBOL_Lex = 162,                      /* Lex  */
  YYSYMBOL_Lexon = 163,                    /* Lexon  */
  YYSYMBOL_Authors = 164,                  /* Authors  */
  YYSYMBOL_Comment = 165,                  /* Comment  */
  YYSYMBOL_Preamble = 166,                 /* Preamble  */
  YYSYMBOL_Terms = 167,                    /* Terms  */
  YYSYMBOL_Covenants = 168,                /* Covenants  */
  YYSYMBOL_Covenant = 169,                 /* Covenant  */
  YYSYMBOL_Provisions = 170,               /* Provisions  */
  YYSYMBOL_Definitions = 171,              /* Definitions  */
  YYSYMBOL_Definition = 172,               /* Definition  */
  YYSYMBOL_Type_Term = 173,                /* Type_Term  */
  YYSYMBOL_Type = 174,                     /* Type  */
  YYSYMBOL_Person = 175,                   /* Person  */
  YYSYMBOL_Amount = 176,                   /* Amount  */
  YYSYMBOL_Time = 177,                     /* Time  */
  YYSYMBOL_Binary = 178,                   /* Binary  */
  YYSYMBOL_Text = 179,                     /* Text  */
  YYSYMBOL_Data = 180,                     /* Data  */
  YYSYMBOL_This_Contract = 181,            /* This_Contract  */
  YYSYMBOL_All_Contracts = 182,            /* All_Contracts  */
  YYSYMBOL_This = 183,                     /* This  */
  YYSYMBOL_Clauses = 184,                  /* Clauses  */
  YYSYMBOL_Clause = 185,                   /* Clause  */
  YYSYMBOL_Body = 186,                     /* Body  */
  YYSYMBOL_Function = 187,                 /* Function  */
  YYSYMBOL_Statements = 188,               /* Statements  */
  YYSYMBOL_Statement = 189,                /* Statement  */
  YYSYMBOL_Action = 190,                   /* Action  */
  YYSYMBOL_Subject = 191,                  /* Subject  */
  YYSYMBOL_Symbols = 192,                  /* Symbols  */
  YYSYMBOL_Symbol = 193,                   /* Symbol  */
  YYSYMBOL_Catena = 194,                   /* Catena  */
  YYSYMBOL_Object = 195,                   /* Object  */
  YYSYMBOL_Reflexive = 196,                /* Reflexive  */
  YYSYMBOL_Contract = 197,                 /* Contract  */
  YYSYMBOL_Predicates = 198,               /* Predicates  */
  YYSYMBOL_Predicate = 199,                /* Predicate  */
  YYSYMBOL_Permission = 200,               /* Permission  */
  YYSYMBOL_Certification = 201,            /* Certification  */
  YYSYMBOL_Certify = 202,                  /* Certify  */
  YYSYMBOL_Declaration = 203,              /* Declaration  */
  YYSYMBOL_Declare = 204,                  /* Declare  */
  YYSYMBOL_Filing = 205,                   /* Filing  */
  YYSYMBOL_File = 206,                     /* File  */
  YYSYMBOL_Registration = 207,             /* Registration  */
  YYSYMBOL_Register = 208,                 /* Register  */
  YYSYMBOL_Grantment = 209,                /* Grantment  */
  YYSYMBOL_Grant = 210,                    /* Grant  */
  YYSYMBOL_Appointment = 211,              /* Appointment  */
  YYSYMBOL_Appoint = 212,                  /* Appoint  */
  YYSYMBOL_Acceptance = 213,               /* Acceptance  */
  YYSYMBOL_Accept = 214,                   /* Accept  */
  YYSYMBOL_Fixture = 215,                  /* Fixture  */
  YYSYMBOL_Fix = 216,                      /* Fix  */
  YYSYMBOL_Fixed = 217,                    /* Fixed  */
  YYSYMBOL_Setting = 218,                  /* Setting  */
  YYSYMBOL_Illocutor = 219,                /* Illocutor  */
  YYSYMBOL_Be = 220,                       /* Be  */
  YYSYMBOL_Payment = 221,                  /* Payment  */
  YYSYMBOL_Pay = 222,                      /* Pay  */
  YYSYMBOL_Preposition = 223,              /* Preposition  */
  YYSYMBOL_Escrow = 224,                   /* Escrow  */
  YYSYMBOL_From_Escrow = 225,              /* From_Escrow  */
  YYSYMBOL_Sending = 226,                  /* Sending  */
  YYSYMBOL_Send = 227,                     /* Send  */
  YYSYMBOL_Notification = 228,             /* Notification  */
  YYSYMBOL_Notify = 229,                   /* Notify  */
  YYSYMBOL_Termination = 230,              /* Termination  */
  YYSYMBOL_Terminate = 231,                /* Terminate  */
  YYSYMBOL_Flagging = 232,                 /* Flagging  */
  YYSYMBOL_Condition = 233,                /* Condition  */
  YYSYMBOL_If = 234,                       /* If  */
  YYSYMBOL_Expression = 235,               /* Expression  */
  YYSYMBOL_Scalar_Comparison = 236,        /* Scalar_Comparison  */
  YYSYMBOL_Comparison_Operator = 237,      /* Comparison_Operator  */
  YYSYMBOL_Equal = 238,                    /* Equal  */
  YYSYMBOL_Greater = 239,                  /* Greater  */
  YYSYMBOL_Less = 240,                     /* Less  */
  YYSYMBOL_Later = 241,                    /* Later  */
  YYSYMBOL_Scalar_Expression = 242,        /* Scalar_Expression  */
  YYSYMBOL_Combination = 243,              /* Combination  */
  YYSYMBOL_Combinor = 244,                 /* Combinor  */
  YYSYMBOL_Combinand = 245,                /* Combinand  */
  YYSYMBOL_Combinator = 246,               /* Combinator  */
  YYSYMBOL_Or_ = 247,                      /* Or_  */
  YYSYMBOL_And = 248,                      /* And  */
  YYSYMBOL_Neither = 249,                  /* Neither  */
  YYSYMBOL_Nor = 250,                      /* Nor  */
  YYSYMBOL_Existence = 251,                /* Existence  */
  YYSYMBOL_Negation = 252,                 /* Negation  */
  YYSYMBOL_Negator = 253,                  /* Negator  */
  YYSYMBOL_Being = 254,                    /* Being  */
  YYSYMBOL_True = 255,                     /* True  */
  YYSYMBOL_Article = 256,                  /* Article  */
  YYSYMBOL_New = 257,                      /* New  */
  YYSYMBOL_Point_In_Time = 258,            /* Point_In_Time  */
  YYSYMBOL_Current_Time = 259,             /* Current_Time  */
  YYSYMBOL_Relative_Time = 260,            /* Relative_Time  */
  YYSYMBOL_Duration = 261,                 /* Duration  */
  YYSYMBOL_Time_Unit = 262,                /* Time_Unit  */
  YYSYMBOL_Years = 263,                    /* Years  */
  YYSYMBOL_Months = 264,                   /* Months  */
  YYSYMBOL_Weeks = 265,                    /* Weeks  */
  YYSYMBOL_Days = 266,                     /* Days  */
  YYSYMBOL_Hours = 267,                    /* Hours  */
  YYSYMBOL_Minutes = 268,                  /* Minutes  */
  YYSYMBOL_Seconds = 269,                  /* Seconds  */
  YYSYMBOL_Milliseconds = 270,             /* Milliseconds  */
  YYSYMBOL_Expiration = 271,               /* Expiration  */
  YYSYMBOL_Timeliness = 272,               /* Timeliness  */
  YYSYMBOL_Name = 273,                     /* Name  */
  YYSYMBOL_Description = 274,              /* Description  */
  YYSYMBOL_Scalar = 275                    /* Scalar  */
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
#define YYLAST   4295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  468
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  821
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 12
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   413

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
     155,   156,   157,   158
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1125,  1125,  1126,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1153,  1159,  1165,  1166,  1172,  1173,  1179,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1198,  1199,  1205,  1206,  1207,
    1208,  1214,  1215,  1216,  1217,  1223,  1224,  1230,  1231,  1232,
    1233,  1239,  1240,  1246,  1247,  1248,  1249,  1250,  1251,  1257,
    1263,  1269,  1275,  1281,  1287,  1293,  1294,  1300,  1306,  1307,
    1313,  1314,  1320,  1326,  1327,  1333,  1334,  1335,  1336,  1342,
    1343,  1349,  1350,  1356,  1357,  1358,  1359,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1372,  1378,  1379,  1385,  1386,  1387,
    1388,  1389,  1390,  1391,  1392,  1398,  1399,  1405,  1406,  1407,
    1408,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1429,  1430,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1455,  1456,  1457,
    1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,
    1473,  1479,  1480,  1481,  1482,  1483,  1489,  1490,  1496,  1497,
    1498,  1499,  1500,  1506,  1507,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1528,  1529,  1535,  1536,  1537,
    1538,  1539,  1545,  1546,  1552,  1558,  1559,  1565,  1566,  1567,
    1573,  1574,  1580,  1581,  1582,  1588,  1589,  1595,  1596,  1597,
    1603,  1604,  1610,  1616,  1617,  1618,  1619,  1620,  1621,  1627,
    1628,  1629,  1630,  1636,  1637,  1643,  1644,  1645,  1646,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,  1659,  1665,  1666,  1667,
    1673,  1674,  1675,  1676,  1682,  1683,  1684,  1685,  1691,  1697,
    1698,  1704,  1705,  1711,  1712,  1718,  1719,  1725,  1726,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1745,  1746,  1747,
    1753,  1754,  1755,  1761,  1767,  1773,  1774,  1775,  1776,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1796,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,
    1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,
    1863,  1864,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,
    1878,  1879,  1880,  1881,  1887,  1888,  1889,  1890,  1891,  1897,
    1898,  1899,  1905,  1906,  1912,  1913,  1914,  1915,  1916,  1917,
    1918,  1919,  1920,  1921,  1922,  1928,  1929,  1930,  1931,  1937,
    1943,  1949,  1955,  1961,  1962,  1963,  1964,  1970,  1971,  1972,
    1973,  1979,  1980,  1981,  1982,  1988,  1989,  1990,  1996,  1997,
    1998,  1999,  2000,  2001,  2002,  2003,  2004,  2010,  2011,  2012,
    2018,  2019,  2020,  2021,  2027,  2028,  2034,  2035,  2036,  2037,
    2038,  2044,  2045,  2046,  2047,  2048,  2054,  2060,  2061,  2062,
    2063,  2064,  2065,  2066,  2067,  2073,  2074,  2080,  2081,  2087,
    2088,  2094,  2095,  2101,  2102,  2108,  2109,  2115,  2116,  2122,
    2123,  2129,  2130,  2131,  2137,  2138,  2139,  2140,  2141,  2142,
    2143,  2144,  2145,  2146,  2147,  2148,  2152,  2155,  2158
};
#endif

#define YYPACT_NINF (-403)
#define YYTABLE_NINF (-357)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    54,    26,   111,   546,    25,  -403,    99,    25,   309,
      94,  -403,  -403,  -403,    46,  -403,   835,  -403,    29,   161,
     165,   183,   240,   247,   262,   475,   418,   141,  -403,  -403,
     278,  -403,   284,    99,   290,  -403,    49,    25,   277,    46,
    -403,   295,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,   137,   180,   311,  -403,  2519,  -403,
    -403,  3563,     6,  -403,  2744,   220,  -403,    69,    14,  -403,
      25,   313,   313,   313,   313,   313,   313,   418,   141,  -403,
     141,  -403,  -403,  -403,   257,  -403,   123,    99,  -403,   376,
      25,  -403,    25,  2802,  -403,  -403,  -403,   311,  -403,   575,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   136,  -403,  2010,  -403,  2657,  -403,  2657,  -403,  2570,
    -403,  2657,  -403,  3077,  -403,  3077,  -403,  3077,  -403,  2657,
    -403,  2684,  -403,  1023,  -403,  1895,  -403,   491,  -403,     2,
    -403,  -403,  3077,  2917,  3077,   398,  -403,   369,  -403,    14,
    -403,  -403,  -403,   402,  -403,   417,   429,   436,   438,   440,
     442,   141,  -403,  -403,  -403,   668,    99,  -403,  -403,   196,
     444,   454,  2937,  3077,   459,  -403,  3278,  3366,   342,  -403,
    -403,   380,  2108,  1895,   420,  -403,  -403,  1132,  2978,  1241,
    3052,  2657,  1350,   634,  1459,  3075,  -403,  1568,  1677,   441,
     443,  2859,  3077,  3077,  -403,  -403,   -48,    -5,   357,  -403,
    -403,   384,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
     383,   276,  -403,  -403,   355,  -403,  -403,  4030,  -403,   355,
     167,   254,  1895,   237,  -403,  4085,  -403,   492,   208,  -403,
    -403,  3077,  1104,  4141,  -403,  -403,    12,  -403,  -403,  -403,
    -403,   158,   254,  -403,   439,  -403,   254,  -403,  -403,  -403,
    -403,  3077,   503,   507,  -403,  -403,  -403,  -403,   432,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   529,  -403,   533,   338,
    -403,    99,  -403,   265,  2435,  3077,   540,   541,  -403,  3978,
    3169,   424,  -403,   499,  2196,  -403,  -403,  2284,  3978,   501,
       4,  -403,  1895,  -403,  3077,  -403,   508,  -403,  3077,  -403,
    1786,  2496,   516,  -403,   519,  -403,  1895,  -403,  3077,  -403,
    1895,  -403,  1895,  -403,  1895,  3077,  3077,  3077,  -403,  -403,
    -403,  -403,   458,   -25,  -403,  -403,   411,   428,   286,   471,
      33,   526,  2879,  3077,   520,   431,  -403,   140,   415,   160,
    -403,   514,   514,    67,  -403,  -403,  2879,  3077,  -403,  -403,
    -403,  -403,  -403,   491,   254,   491,   254,  -403,  -403,   -27,
    -403,  -403,   334,   -16,   543,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  2719,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   914,  -403,  -403,  -403,  -403,  1895,  -403,  -403,  -403,
    -403,  -403,  -403,  3077,   447,  3077,  -403,   491,  -403,  1895,
     576,  -403,  -403,   668,  -403,  -403,  -403,  -403,    99,  -403,
      25,  -403,  -403,  2614,   263,   580,  -403,  -403,  -403,  3978,
    3475,   460,   445,  -403,  3672,  -403,  2372,  3978,   505,  3978,
     513,   515,  -403,   452,  -403,  -403,  -403,  1895,  -403,   552,
    -403,   553,  -403,  1895,  3077,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,   461,  -403,   490,   539,  -403,   465,   457,
     554,   463,  -403,  -403,   464,  -403,  -403,   151,   466,   -93,
    -403,   446,   -39,  -403,  -403,  -403,  -403,  -403,  -403,   544,
     509,  -403,  -403,  -403,  -403,  -403,  -403,   491,  -403,   491,
     534,   571,   -40,    16,    19,   531,   577,   -17,  -403,   701,
    -403,  -403,  1895,  -403,  -403,   506,  -403,  -403,  -403,  -403,
     616,   617,  -403,   613,    25,  -403,  -403,  3978,   495,  -403,
    3781,  3978,  3978,  -403,  3978,   517,   523,  -403,   525,  -403,
    -403,  -403,  -403,  1895,  3077,  -403,  -403,   572,   497,  -403,
     578,  -403,   486,  -403,  -403,  -403,   530,  -403,   478,   532,
    -403,  -403,   480,  -403,   535,  -403,  -403,   510,   581,  -403,
     563,   582,   606,   573,   614,   -45,   579,  -403,   585,  -403,
    3077,  -403,  -403,   137,   650,  -403,  3890,  3978,  -403,  -403,
    -403,   527,  -403,  -403,  -403,  -403,  -403,  -403,   601,  -403,
    -403,  -403,  -403,   521,  -403,  -403,  -403,   528,  -403,   536,
     591,     8,   594,   547,    21,   242,   222,  -403,  -403,   662,
     137,  3978,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   549,
     555,    24,   281,   332,    34,   557,   623,   559,    35,   562,
      39,   341,  1895,   693,   797,  -403,  -403,    45,   569,   657,
     574,   132,   583,   157,   346,   586,   664,   570,   587,   189,
     588,   679,   194,   595,   681,   596,   195,   706,  -403,  1895,
     722,   598,   686,   599,   600,   197,   603,   692,   203,   609,
     697,   611,   206,   612,   618,  -403,   615,   621,   709,   627,
     628,   635,   710,   629,   637,   213,   643,   732,  -403,   771,
    -403,   647,   654,  -403,   651,   655,   745,   663,   659,   667,
     772,   682,   688,   215,   689,   773,  -403,   685,  -403,   690,
     694,  -403,   698,   699,   702,  -403,   700,   707,   786,   704,
     712,  -403,  -403,   705,  -403,   708,   714,  -403,   713,   715,
     721,  -403,   720,   729,   793,   725,   734,  -403,  -403,   727,
    -403,  -403,   730,  -403,   731,   737,  -403,   735,  -403,  -403,
     739,  -403,  -403,   740,  -403,   742,   752,  -403,   749,  -403,
    -403,  -403,   750,  -403,  -403,  -403,  -403,   754,  -403,  -403,
    -403
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     0,
       0,   407,   408,   409,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   466,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,     0,    60,   213,    62,   412,    64,   413,   214,   410,
     411,    59,    63,    69,    68,    61,    46,   101,    53,    54,
      55,    56,    57,    58,     0,     0,    42,    70,    43,    79,
      81,     0,    94,    95,     0,   209,    82,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    16,    14,    13,
      10,     9,     7,    20,     0,    32,     0,     0,    29,     0,
       0,    36,     0,     0,    65,    66,    71,    44,    80,     0,
     195,   196,   190,   191,   157,   156,   163,   164,   175,   176,
     200,   201,   185,   186,   150,   244,   243,   219,   220,   182,
     183,   223,   224,   221,   222,   239,   240,   247,   248,   225,
     226,     0,   136,     0,   137,     0,   138,     0,   139,     0,
     140,     0,   141,     0,   142,     0,   143,     0,   144,     0,
     145,     0,   146,     0,   147,     0,   148,     0,   149,     0,
     106,   105,     0,     0,     0,     0,   210,   211,   103,     0,
      99,   102,    98,     0,   467,     0,     0,     0,     0,     0,
       0,    18,    17,    15,    11,     0,     0,    33,    30,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,   260,
     262,     0,     0,     0,     0,   121,   122,   151,     0,   158,
       0,     0,   165,     0,   177,     0,   184,   187,   192,   197,
       0,     0,     0,     0,   203,   468,   357,     0,     0,   113,
     114,   214,   116,   111,   393,   391,   420,   115,   118,   452,
       0,   409,   117,   120,     0,   112,   119,   364,   367,     0,
       0,     0,     0,     0,   370,     0,   263,   359,   362,   372,
     371,     0,     0,   373,   414,   415,     0,   374,   368,   355,
     357,   409,     0,   109,   409,   107,   241,   108,   245,   246,
      96,     0,     0,     0,   249,   212,   104,   100,     0,    22,
      23,    24,    25,    21,    26,    19,     0,    51,     0,     0,
      34,     0,    37,     0,     0,     0,     0,     0,   253,     0,
       0,     0,   123,     0,     0,   261,    84,     0,     0,     0,
     257,    67,     0,   152,     0,   154,     0,   159,     0,   161,
     168,     0,     0,   166,     0,   171,     0,   178,     0,   180,
       0,   188,     0,   193,     0,     0,     0,     0,   206,   204,
     205,   234,     0,     0,   451,   453,     0,     0,   358,     0,
       0,     0,     0,     0,   275,   269,   271,     0,   395,   391,
     397,     0,     0,     0,   365,   366,     0,     0,   394,   392,
     228,   229,   227,     0,     0,     0,     0,   441,   442,     0,
     443,   444,   272,     0,     0,   449,   450,   445,   446,   437,
     438,   447,   448,   439,   440,   435,   436,     0,   265,   266,
     267,   268,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,   380,   381,   382,   379,     0,   375,   376,   377,
     378,   387,   369,     0,     0,   421,   358,     0,   110,     0,
       0,   251,   250,     0,    47,    49,    52,    38,     0,    39,
       0,    72,    74,    73,     0,     0,   255,   254,   124,     0,
       0,     0,     0,   127,     0,    89,     0,     0,     0,     0,
       0,     0,    85,     0,   258,   153,   155,     0,   162,     0,
     169,     0,   173,     0,     0,   179,   181,   189,   194,   198,
     199,   207,   208,     0,   236,     0,     0,   416,     0,     0,
       0,     0,   384,   389,   276,   270,   396,     0,   273,     0,
     454,   458,     0,   202,   383,   388,   402,   400,   401,   403,
       0,   398,   399,   386,   385,   390,   218,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   354,   264,
     356,   360,     0,   363,   425,     0,   422,   238,   242,   252,
       0,     0,    40,     0,     0,   256,   128,     0,     0,   131,
       0,     0,     0,   125,     0,     0,     0,    90,     0,    87,
      86,   259,   160,     0,     0,   167,   172,     0,     0,   231,
       0,   418,     0,   417,   277,   456,     0,   274,   462,     0,
     459,   455,   460,   404,   405,   216,   217,   278,     0,   350,
       0,     0,     0,     0,     0,     0,     0,   352,     0,   361,
     423,    48,    50,     0,     0,   132,     0,     0,   129,   135,
     126,     0,    92,    91,    88,   170,   174,   235,     0,   233,
     419,   457,   463,   464,   461,   406,   279,   280,   351,   282,
       0,     0,     0,     0,     0,     0,     0,   353,   424,     0,
       0,     0,   133,   130,    93,   237,   465,   281,   283,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,   287,   288,     0,     0,   294,
       0,     0,     0,   302,     0,     0,     0,     0,    76,     0,
      77,   322,     0,   319,   320,     0,     0,   326,     0,     0,
       0,   334,     0,     0,     0,     0,   291,   292,   289,   298,
       0,   295,   296,   306,     0,   303,   304,     0,     0,   310,
       0,    78,   323,   324,   321,   330,     0,   327,   328,   338,
       0,   335,   336,     0,     0,   342,     0,   293,   299,   300,
     297,   307,   308,   305,   314,     0,   311,   312,   325,   331,
     332,   329,   339,   340,   337,   346,     0,   343,   344,   301,
     309,   315,   316,   313,   333,   341,   347,   348,   345,   317,
     349
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -403,  -403,  -403,  -403,  -403,   863,   266,    15,  -403,  -403,
     850,    41,  -403,   875,   448,    47,  -403,  -403,  -403,  -403,
    -403,  -403,     0,   726,  -403,   829,   177,  -403,  -403,   584,
     -66,  -403,  -403,  -403,    30,  -403,  -386,  -164,   336,  -116,
     -32,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   518,  -403,
     -15,   202,  -403,  -403,  -235,  -403,   639,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,   711,  -403,    58,  -403,  -403,   641,
    -403,  -403,  -403,   487,  -402,   472,  -403,   481,  -403,  -403,
    -403,  -403,  -403,  -403,   120,  -403,  -403,    -3,   -72,   496,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,   652,  -403,     7,   -63,  -403
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   306,    57,    58,    59,    60,    61,
      62,    63,   215,   216,    65,    66,    67,   461,   462,    68,
      69,    70,    71,    72,   257,   172,   286,   258,   259,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   524,   160,
     161,    75,   162,   163,   393,   261,   262,   164,   165,   166,
     167,   168,   169,    76,   212,   213,   263,   264,   417,   381,
     419,   420,   421,   265,   266,   267,   268,   436,   437,   438,
     439,   440,   269,   270,   271,   383,   533,   109,    78,   273,
     274,   275,   276,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   277,   385,    79,   278,   279
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    74,   108,   287,    18,   179,    18,   536,   483,   538,
     170,     1,    30,    77,   540,    32,    64,   598,   185,   186,
     187,   188,   189,   190,    29,   545,     6,   211,   395,   551,
      18,   214,  -230,    18,   504,    29,   653,   179,    80,   443,
      89,    91,    92,   609,    99,    42,    73,   447,    31,   103,
      35,   449,    97,    74,   361,  -230,    44,   611,     8,     5,
     613,   557,   675,   599,    46,   688,   617,    37,    64,    38,
     601,   602,   105,    11,    95,   695,   700,    98,    80,    29,
     703,    12,   509,   654,   180,   182,   711,   183,   655,   670,
     444,   323,   505,    18,    18,   610,   329,  -230,    73,    36,
      42,   526,   192,   193,   175,   194,   541,   200,     8,   201,
     527,    44,   362,   171,     7,    45,   180,   546,   618,    46,
       8,   528,   445,    11,   178,   181,   196,    51,   529,     9,
     363,    12,     8,   204,    10,    11,   671,   197,   198,   205,
     206,   672,   484,    12,    53,    54,    52,    11,    47,   612,
     619,   605,   614,   606,   676,    12,   178,   689,    55,   537,
     272,   539,   272,    24,    49,    50,    81,   696,   701,   288,
      82,   510,   704,   716,   322,   217,    43,   219,   712,   222,
     516,   224,    51,   226,    13,   227,   297,   228,    83,   229,
      29,   234,   309,    18,   530,   308,    18,   285,   719,   311,
     179,    52,   290,   292,   293,     8,   305,   367,   478,   442,
     272,   480,   481,    55,   272,   531,   272,   446,    48,   272,
      11,   272,   532,   282,   272,   272,   296,   104,    12,   287,
     727,   287,   316,   317,    13,   731,   736,   310,   745,   517,
     312,   432,   307,   106,   749,    84,    13,   754,   335,   364,
     339,   340,    85,   345,   767,   349,   783,   176,    13,   272,
     595,   358,   359,   360,   388,   717,   389,    86,   458,   520,
     521,   330,   564,    29,     8,   333,   177,   337,   370,   180,
     343,    93,   347,   287,   106,   351,   353,   468,   473,    11,
     720,    88,    90,    94,    42,    96,   371,    12,   100,    74,
     102,   441,   433,   679,   237,    44,   434,   596,    18,    45,
      18,   464,    33,    46,    64,   435,   522,   390,     8,   178,
     394,   450,   728,   677,   184,   367,    41,   732,   737,   272,
     746,    13,    34,    11,   390,   368,   750,   272,   195,   755,
     391,    12,    47,   272,    73,   465,   768,   272,   784,   272,
     680,   272,   457,   191,   459,   681,   456,   391,    49,    50,
     575,   576,   690,   578,   486,   260,  -232,   260,   488,    42,
     678,   492,   542,   287,   373,   287,    51,   382,   496,   387,
      44,   199,   392,   326,   206,   500,   501,   502,    46,  -232,
     485,   518,   179,   369,    43,    52,   370,   108,   490,   392,
      13,   294,   512,   513,   495,   543,   295,    55,   497,   691,
     498,   298,   499,   692,   371,   260,   534,   535,   544,   260,
     299,   260,   705,   285,   260,   285,   260,   721,   272,   260,
     260,  -232,   300,   272,    21,    22,    48,   566,   569,   301,
      24,   302,   573,   303,    13,   304,   272,   548,    74,   313,
     309,    51,   244,   561,   245,    18,   372,   314,   631,   260,
     693,   386,   318,    64,   260,   694,   364,   563,   331,   706,
      52,   180,   518,   554,   722,   556,   325,   285,   354,  -272,
     355,   218,    55,   220,   272,   223,   366,   225,    19,    20,
     272,    21,    22,    73,   365,   230,   431,    24,   448,   562,
     307,    29,   475,   206,   482,   206,   451,   558,   577,   206,
     452,   178,  -214,   453,   519,    11,   579,   206,   580,   206,
     632,   206,    42,    12,   586,   365,   633,   206,   634,   206,
     664,   206,   454,    44,   260,   625,   455,    45,   628,   629,
     630,    46,   260,   466,   467,   582,   506,   487,   260,   272,
     283,   585,   260,   474,   260,   493,   260,   341,   494,    19,
      20,   503,    21,    22,   239,   240,    23,   285,    24,   285,
      47,   624,   507,   242,   508,   511,   515,   514,   523,   559,
     272,   547,   555,   565,   243,    29,    49,    50,   571,   570,
     581,   583,   584,   588,   662,   663,   587,   247,   589,   248,
     590,   591,   600,   592,    51,   607,    42,   593,   659,   594,
     603,   597,   608,   604,   636,   615,   620,    44,   616,   621,
     622,    45,   623,    52,   626,    46,   284,   252,   253,   685,
     640,   637,   638,   260,   642,    55,   644,   639,   260,   641,
     645,   635,   643,   646,    29,   684,   648,   650,   255,   256,
     658,   260,   647,   649,    47,   652,   272,   651,    11,   660,
     665,   667,   669,   656,   698,    42,    12,   682,   657,   668,
      49,    50,    29,   184,   235,   674,    44,   666,   673,   272,
      45,   272,   686,   687,    46,   697,    11,   699,    51,   260,
     702,   214,    11,    42,    12,   260,   708,   713,   714,    42,
      12,    43,   715,   725,    44,   724,   272,    52,    45,   738,
      44,   718,    46,    47,   723,   726,   729,   683,    46,    55,
     730,   280,   734,   733,   735,   740,   741,   742,   744,    49,
      50,   747,   743,   748,   238,   239,   240,   751,   752,   753,
     707,    47,   710,   241,   242,   756,   757,    51,   758,   759,
     760,   764,   397,   398,   260,   243,   762,    49,    50,   244,
     761,   245,   765,   763,   246,   766,    52,   739,   247,    13,
     248,   769,   249,   770,   771,    51,   400,   401,    55,   344,
     772,    51,   773,   775,   774,   260,   776,   778,   405,   406,
     407,   408,   409,   410,    52,   779,   777,   281,   252,   253,
      52,   254,   709,    13,    53,    54,    55,    29,   184,   235,
      53,    54,    55,   780,   786,   781,   782,   785,   787,   255,
     256,    11,   789,   788,   411,   412,   214,   795,    42,    12,
     792,   790,   791,   793,   806,   794,    43,   796,   798,    44,
     797,   799,   800,    45,     8,    29,   801,    46,   802,   803,
      41,   413,   414,   804,   415,   416,   280,   805,   807,    11,
     809,   260,   808,   810,   811,   812,    42,    12,   813,   238,
     239,   240,   814,   815,    43,   816,    47,    44,   241,   242,
     817,    45,   818,   819,   260,    46,   260,   820,    87,   101,
     243,    56,    49,    50,   244,   289,   245,   107,   463,   246,
     525,   560,   396,   247,   549,   248,   418,   249,   553,   384,
      51,   260,   552,   550,    47,     0,    48,     0,   324,     0,
       0,     0,     0,     0,    29,   184,   235,     0,     0,    52,
      49,    50,   281,   252,   253,     0,   254,     0,    11,    53,
      54,    55,     0,   214,     0,    42,    12,   432,    51,     0,
       0,     0,     0,    43,   255,   256,    44,     0,     0,     0,
      45,     0,     0,     0,    46,     0,     0,    52,     0,     0,
      13,     0,     0,   280,     0,     0,     0,    53,    54,    55,
       0,     0,     0,     0,     0,     0,   238,   239,   240,     0,
       0,     0,     0,    47,     0,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   433,    49,
      50,   244,   434,   245,     0,     0,   246,     0,     0,     0,
     247,   435,   248,     0,   249,     0,     0,    51,     0,     0,
       0,     0,     0,    29,   184,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    11,     0,   281,
     252,   253,   214,   254,    42,    12,    53,    54,    55,     0,
       0,     0,    43,     0,     0,    44,     0,     0,     0,    45,
       0,   255,   256,    46,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,     0,   238,   239,   240,     0,     0,
       0,     0,    47,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,     0,    29,   184,   243,     0,    49,    50,
     244,     0,   245,     0,     0,   246,     0,     0,     0,   247,
       0,   248,     0,   249,     0,    42,    51,     0,     0,     0,
     250,     0,    29,   184,   235,     0,    44,     0,     0,     0,
      45,     0,     0,     0,    46,    52,    11,     0,   251,   252,
     253,   214,   254,    42,    12,    53,    54,    55,     0,   332,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
     255,   256,    46,    47,     0,     0,     0,     0,     0,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     0,     0,     0,   238,   239,   240,     0,     0,     0,
       0,    47,     0,   241,   242,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,   243,     0,    49,    50,   244,
       0,   245,     0,     0,   246,     0,    52,     0,   247,     0,
     248,     0,   249,     0,     0,    51,     0,     0,    55,     0,
       0,    29,   184,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    11,     0,   281,   252,   253,
     214,   254,    42,    12,    53,    54,    55,     0,     0,     0,
      43,     0,     0,    44,     0,     0,     0,    45,     0,   255,
     256,    46,     0,     0,     0,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,     0,     0,     0,     0,
      47,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,    49,    50,   244,     0,
     245,     0,     0,   246,     0,     0,     0,   247,     0,   248,
       0,   249,     0,     0,    51,     0,     0,     0,     0,     0,
      29,   184,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    11,     0,   281,   252,   253,   214,
     254,    42,    12,    53,    54,    55,   336,     0,     0,    43,
       0,     0,    44,     0,     0,     0,    45,     0,   255,   256,
      46,     0,     0,     0,     0,     0,     0,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,   239,   240,     0,     0,     0,     0,    47,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,    49,    50,   244,     0,   245,
       0,     0,   246,     0,     0,     0,   247,     0,   248,     0,
     249,     0,     0,    51,     0,     0,     0,     0,     0,    29,
     184,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    11,     0,   281,   252,   253,   214,   254,
      42,    12,    53,    54,    55,   342,   346,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,   255,   256,    46,
       0,     0,     0,     0,     0,     0,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   239,   240,     0,     0,     0,     0,    47,     0,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    49,    50,   244,     0,   245,     0,
       0,   246,     0,     0,     0,   247,     0,   248,     0,   249,
       0,     0,    51,     0,     0,     0,     0,     0,    29,   184,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    11,     0,   281,   252,   253,   214,   254,    42,
      12,    53,    54,    55,     0,   350,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,   255,   256,    46,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,   239,   240,     0,     0,     0,     0,    47,     0,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,    49,    50,   244,     0,   245,     0,     0,
     246,     0,     0,     0,   247,     0,   248,     0,   249,     0,
       0,    51,     0,     0,     0,     0,     0,    29,   184,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    11,     0,   281,   252,   253,   214,   254,    42,    12,
      53,    54,    55,     0,   352,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,   255,   256,    46,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     239,   240,     0,     0,     0,     0,    47,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,    49,    50,   244,     0,   245,     0,     0,   246,
       0,     0,     0,   247,     0,   248,     0,   249,     0,     0,
      51,     0,     0,     0,     0,     0,    29,   184,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      11,     0,   281,   252,   253,   214,   254,    42,    12,    53,
      54,    55,     0,     0,     0,    43,     0,     0,    44,     0,
       0,     0,    45,     0,   255,   256,    46,     0,     0,     0,
       0,     0,     0,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,   239,
     240,     0,     0,     0,     0,    47,     0,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,    49,    50,   244,     0,   245,     0,     0,   246,     0,
       0,     0,   247,     0,   248,     0,   249,     0,     0,    51,
       0,     0,     0,     0,     0,    29,   184,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    11,
       0,   281,   252,   253,   214,   254,    42,    12,    53,    54,
      55,   489,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,   255,   256,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,   239,   240,
       0,     0,     0,     0,    47,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
      49,    50,   244,     0,   245,     0,     0,   246,     0,     0,
       0,   247,     0,   248,     0,   249,     0,     0,    51,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     281,   252,   253,     0,   254,   110,   111,    53,    54,    55,
       0,     0,     0,     0,     0,   112,   113,     0,     0,    43,
       0,     0,   255,   256,   114,   115,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   117,     0,     0,     0,     0,
     118,     0,   119,   120,     0,   121,     0,     0,   208,   122,
     123,     0,     0,     0,     0,     0,     0,   209,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   126,   327,   328,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,   210,   129,   130,     0,   131,   132,
       0,   133,   134,   110,   111,   135,   136,     0,     0,     0,
     137,   138,     0,   112,   113,     0,     0,    43,     0,     0,
       0,     0,   114,   115,     0,     0,   139,   140,     0,     0,
       0,   116,     0,   117,     0,     0,     0,     0,   118,     0,
     119,   120,     0,   121,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,   477,     0,     0,     0,     0,     0,     0,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   110,   111,   129,   130,     0,   131,   132,     0,   133,
     134,   112,   113,   135,   136,    43,     0,     0,   137,   138,
     114,   115,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   117,     0,     0,   139,   140,   118,     0,   119,   120,
       0,   121,     0,     0,     0,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   110,
     111,   129,   130,     0,   131,   132,     0,   133,   134,   112,
     113,   135,   136,    43,     0,     0,   137,   138,   114,   115,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
       0,     0,   139,   140,   118,     0,   119,   120,     0,   121,
       0,     0,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,     0,     0,
       0,     0,     0,     0,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   110,   111,   129,
     130,     0,   131,   132,     0,   133,   134,   112,   113,   135,
     136,    43,     0,     0,   137,   138,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,     0,     0,
     139,   140,   118,     0,   119,   120,     0,   121,     0,     0,
       0,   122,   123,     0,   460,    29,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,    42,    12,     0,     0,
       0,     0,   125,   126,    43,     0,     0,    44,     0,     0,
       0,    45,     0,   127,   128,    46,     0,   129,   130,     0,
     131,   132,     0,   133,   134,     0,     0,   135,   136,     0,
       0,     0,   137,   138,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    48,     0,   139,   140,
      11,     0,     0,     0,     0,     0,     0,    42,    12,    29,
      49,    50,     0,     0,    41,     0,     0,     0,    44,     0,
       0,     0,    45,    11,     0,     0,    46,     0,    51,     0,
      42,    12,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,    52,     0,    46,
      13,     0,     0,     0,     0,    47,     0,    53,    54,    55,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,     0,    11,     0,     0,     0,    47,   214,
      48,    42,    12,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    44,     0,    49,    50,    45,     0,     0,     0,
      46,     0,     0,     0,    29,     0,     0,     0,    52,     0,
       0,    13,    51,     0,     0,     0,   221,     0,    11,     0,
      55,   491,     0,     0,     0,    42,    12,     0,     0,    47,
       0,    52,     0,    43,    13,     0,    44,     0,     0,     0,
      45,    53,    54,    55,    46,    49,    50,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,    51,     0,     0,   214,     0,    42,    12,
       0,     0,     0,    47,    29,    48,     0,     0,     0,    44,
       0,     0,    52,    45,     0,    13,     0,    46,    11,    49,
      50,     0,    53,    54,    55,    42,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    51,     0,    29,
      45,   235,     0,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    52,     0,     0,    13,
      42,    12,    49,    50,    29,     0,    53,    54,    55,     0,
       0,    44,     0,    47,     0,    45,     0,     0,    11,    46,
      51,     0,     0,     0,     0,    42,    12,     0,   280,    49,
      50,     0,     0,     0,     0,     0,    44,     0,     0,    52,
      45,     0,    13,     0,    46,     0,     0,    51,    47,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    49,    50,    52,     0,     0,    13,
       0,   246,   231,    47,   232,   233,    11,     0,    55,     0,
       0,     0,    51,    42,    12,     0,     0,     0,     0,    49,
      50,     0,     0,     0,    44,     0,     0,     0,    45,     0,
       0,    52,    46,     0,   281,     0,     0,    51,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    52,     0,     0,    13,
       0,    47,   173,    11,     0,   174,     0,     0,    55,    29,
      42,    12,     0,     0,     0,     0,     0,    49,    50,     0,
       0,    44,     0,    11,     0,    45,     0,     0,     0,    46,
      42,    12,     0,     0,     0,    51,     0,     0,     0,     0,
       0,    44,     0,     0,     0,    45,     0,    29,     0,    46,
       0,     0,     0,     0,    52,     0,     0,    13,    47,     0,
     202,    11,     0,   203,     0,     0,    55,    29,    42,    12,
       0,     0,     0,     0,    49,    50,     0,     0,    47,    44,
       0,    11,     0,    45,     0,     0,     0,    46,    42,    12,
       0,     0,    51,     0,    49,    50,   388,     0,   389,    44,
       0,     0,     0,    45,     0,     0,     0,    46,    29,     0,
       0,    52,    51,     0,    13,     0,    47,     0,     0,   356,
     357,     0,    11,    55,     0,     0,     0,     0,     0,    42,
      12,    52,    49,    50,    13,   334,    47,     0,     0,     0,
      44,     0,     0,    55,    45,     0,     0,     0,    46,     0,
      51,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      51,     0,    13,     0,     0,     0,     0,    47,   291,     0,
       0,    55,    29,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    13,    49,    50,     0,    11,     0,   315,     0,
       0,    55,     0,    42,    12,    29,     0,    29,     0,   338,
       0,    51,     0,     0,    44,     0,     0,     0,    45,    11,
       0,    11,    46,     0,     0,     0,    42,    12,    42,    12,
      52,     0,   348,    13,     0,     0,     0,    44,     0,    44,
       0,    45,    55,    45,     0,    46,     0,    46,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,    47,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
      49,    50,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,    13,    51,     0,
      51,     0,     0,     0,   110,   111,    55,   469,     0,   470,
       0,     0,     0,     0,   112,   113,     0,    52,    43,    52,
      13,     0,    13,   114,   115,     0,     0,     0,     0,    55,
       0,    55,   116,     0,   117,     0,     0,     0,     0,   118,
       0,   119,   120,     0,   121,     0,     0,     0,   122,   123,
       0,     0,     0,     0,     0,     0,   471,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,   129,   130,     0,   131,   132,     0,
     133,   134,     0,     0,   135,   136,     0,     0,     0,   137,
     138,     0,     0,   110,   111,     0,   319,     0,     0,     0,
       0,   320,     0,   112,   113,   139,   140,    43,     0,     0,
       0,   472,   114,   115,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,     0,   118,     0,
     119,   120,     0,   121,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,   321,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   110,   111,   129,   130,     0,   131,   132,     0,   133,
     134,   112,   113,   135,   136,    43,     0,     0,   137,   138,
     114,   115,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   117,     0,     0,   139,   140,   118,     0,   119,   120,
       0,   121,     0,     0,   208,   122,   123,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
     210,   129,   130,     0,   131,   132,     0,   133,   134,     0,
       0,   135,   136,     0,     0,     0,   137,   138,     0,     0,
     110,   111,     0,   567,     0,     0,     0,     0,     0,     0,
     112,   113,   139,   140,    43,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,   118,     0,   119,   120,     0,
     121,     0,     0,     0,   122,   123,     0,     0,     0,     0,
       0,     0,   568,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,   110,   111,
     129,   130,     0,   131,   132,     0,   133,   134,   112,   113,
     135,   136,    43,     0,     0,   137,   138,   114,   115,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,   139,   140,   118,     0,   119,   120,     0,   121,     0,
       0,     0,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,   129,   130,
       0,   131,   132,     0,   133,   134,     0,     0,   135,   136,
       0,     0,     0,   137,   138,     0,     0,   110,   111,     0,
     572,     0,     0,     0,     0,     0,     0,   112,   113,   139,
     140,    43,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,     0,     0,
       0,     0,   118,     0,   119,   120,     0,   121,     0,     0,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,   129,   130,     0,
     131,   132,     0,   133,   134,     0,     0,   135,   136,     0,
       0,     0,   137,   138,     0,     0,   110,   111,     0,   627,
       0,     0,     0,     0,     0,     0,   112,   113,   139,   140,
      43,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   117,     0,     0,     0,
       0,   118,     0,   119,   120,     0,   121,     0,     0,     0,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,   129,   130,     0,   131,
     132,     0,   133,   134,     0,     0,   135,   136,     0,     0,
       0,   137,   138,     0,     0,   110,   111,     0,   661,     0,
       0,     0,     0,     0,     0,   112,   113,   139,   140,    43,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   117,     0,     0,     0,     0,
     118,     0,   119,   120,     0,   121,     0,     0,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,   110,   111,   129,   130,     0,   131,   132,
       0,   133,   134,   112,   113,   135,   136,    43,     0,     0,
     137,   138,   114,   115,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,     0,     0,   139,   140,   118,     0,
     119,   120,     0,   121,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,   374,     0,     0,     0,     0,     0,     0,   125,   126,
       0,  -354,  -354,     0,     0,     0,     0,   375,   376,   127,
     128,     0,     0,   129,   130,     0,   131,   132,     0,   133,
     134,  -354,   377,   135,   136,  -354,  -354,     0,   137,   138,
       0,   378,     0,     0,  -354,  -354,     0,  -354,  -354,  -354,
    -354,  -354,  -354,     0,   139,   140,   374,   244,     0,   379,
       0,     0,     0,     0,     0,     0,   397,   398,     0,     0,
     249,     0,   375,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -354,  -354,     0,   399,     0,     0,     0,
     400,   401,     0,     0,     0,     0,   402,     0,     0,   403,
     404,     0,   405,   406,   407,   408,   409,   410,     0,   380,
    -354,  -354,  -356,  -354,  -354,     0,     0,     0,     0,     0,
       0,     0,  -356,  -356,     0,     0,     0,     0,  -356,  -356,
       0,     0,     0,     0,     0,     0,     0,     0,   411,   412,
       0,     0,  -356,     0,     0,     0,  -356,  -356,     0,     0,
       0,     0,  -356,     0,     0,  -356,  -356,     0,  -356,  -356,
    -356,  -356,  -356,  -356,     0,   413,   414,     0,   415,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -356,  -356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -356,  -356,     0,  -356,  -356
};

static const yytype_int16 yycheck[] =
{
       3,    16,    68,   167,     7,    77,     9,   393,     4,   395,
       4,    19,     5,    16,    41,     8,    16,   110,    81,    82,
      83,    84,    85,    86,    10,    41,     0,   143,   263,   431,
      33,    29,    80,    36,    59,    10,    81,   109,     9,    27,
      25,    26,    27,    83,    37,    31,    16,   282,     7,    64,
       9,   286,     3,    68,    59,   103,    42,    41,     9,     5,
      41,   447,    41,   156,    50,    41,    83,    21,    68,    23,
     109,   110,    65,    24,    33,    41,    41,    36,     9,    10,
      41,    32,    49,   128,    77,    78,    41,    80,   133,    81,
      78,   207,   117,    96,    97,   135,   212,   145,    68,     5,
      31,    34,    87,    88,    74,    90,   133,   100,     9,   102,
      43,    42,   117,   107,     3,    46,   109,   133,   135,    50,
       9,    54,   110,    24,    77,    78,     3,   113,    61,    18,
     135,    32,     9,   103,    23,    24,   128,    96,    97,     3,
       4,   133,   138,    32,   142,   143,   132,    24,    79,   133,
     552,   537,   133,   539,   133,    32,   109,   133,   144,   394,
     163,   396,   165,    22,    95,    96,     5,   133,   133,   169,
       5,   138,   133,    41,   206,   145,    39,   147,   133,   149,
      40,   151,   113,   153,   135,   155,   179,   157,     5,   159,
      10,   161,   195,   196,   127,   195,   199,   167,    41,     3,
     272,   132,   172,   173,   174,     9,   191,    49,   324,   272,
     213,   327,   328,   144,   217,   148,   219,    59,    81,   222,
      24,   224,   155,   165,   227,   228,   179,    47,    32,   393,
      41,   395,   202,   203,   135,    41,    41,   196,    41,    99,
     199,    33,   195,    66,    41,     5,   135,    41,   218,   109,
     220,   221,     5,   223,    41,   225,    41,    37,   135,   262,
     109,   231,   232,   233,    97,   133,    99,     5,     3,   109,
     110,   213,     9,    10,     9,   217,    56,   219,   120,   272,
     222,     3,   224,   447,   107,   227,   228,   319,   320,    24,
     133,    25,    26,     9,    31,     5,   138,    32,    21,   314,
       5,   271,    94,    81,    67,    42,    98,   156,   311,    46,
     313,   314,     3,    50,   314,   107,   156,    80,     9,   272,
     262,   291,   133,    81,    11,    49,    15,   133,   133,   332,
     133,   135,    23,    24,    80,    59,   133,   340,    81,   133,
     103,    32,    79,   346,   314,   315,   133,   350,   133,   352,
     128,   354,   311,    87,   313,   133,   309,   103,    95,    96,
     476,   477,    81,   479,   334,   163,    80,   165,   338,    31,
     128,   341,    38,   537,   254,   539,   113,   257,   348,   259,
      42,     5,   145,     3,     4,   355,   356,   357,    50,   103,
     332,    57,   464,   117,    39,   132,   120,   463,   340,   145,
     135,     3,   372,   373,   346,    71,    37,   144,   350,   128,
     352,     9,   354,    81,   138,   213,   386,   387,    84,   217,
       3,   219,    81,   393,   222,   395,   224,    81,   431,   227,
     228,   145,     3,   436,    16,    17,    81,   469,   470,     3,
      22,     3,   474,     3,   135,     3,   449,   417,   463,     5,
     453,   113,    97,   453,    99,   458,   254,     3,   574,   257,
     128,   259,     3,   463,   262,   133,   109,   460,    48,   128,
     132,   464,    57,   443,   128,   445,   134,   447,    37,    64,
      37,   145,   144,   147,   487,   149,   103,   151,    13,    14,
     493,    16,    17,   463,   110,   159,     4,    22,    59,   458,
     453,    10,     3,     4,     3,     4,     3,   449,     3,     4,
       3,   464,    97,    81,    99,    24,     3,     4,     3,     4,
       3,     4,    31,    32,   494,   110,     3,     4,     3,     4,
       3,     4,     3,    42,   332,   567,     3,    46,   570,   571,
     572,    50,   340,     3,     3,   487,   135,    39,   346,   552,
      59,   493,   350,   129,   352,    39,   354,   221,    39,    13,
      14,   103,    16,    17,    73,    74,    20,   537,    22,   539,
      79,   564,   144,    82,   103,    49,   145,    57,    64,     3,
     583,    38,   135,     3,    93,    10,    95,    96,   143,   129,
     138,    39,    39,   103,   626,   627,   135,   106,    59,   108,
     135,   144,   156,    49,   113,    71,    31,   144,   623,   145,
      66,   145,    41,   104,   584,    84,   110,    42,    41,     3,
       3,    46,     9,   132,   129,    50,   135,   136,   137,   661,
     144,    59,   135,   431,   156,   144,   156,    59,   436,   109,
     105,   583,   110,   133,    10,   660,    83,    41,   157,   158,
     620,   449,    71,    71,    79,    41,   659,    84,    24,     9,
      59,   133,    71,    84,    41,    31,    32,     5,    83,   133,
      95,    96,    10,    11,    12,   128,    42,   156,    84,   682,
      46,   684,   133,   128,    50,   128,    24,   128,   113,   487,
     128,    29,    24,    31,    32,   493,     3,   128,    41,    31,
      32,    39,   128,   133,    42,    41,   709,   132,    46,     3,
      42,   128,    50,    79,   128,   128,   128,   659,    50,   144,
      41,    59,    41,   128,   128,     3,   128,    41,   128,    95,
      96,   128,   133,    41,    72,    73,    74,   128,    41,   128,
     682,    79,   684,    81,    82,   133,   128,   113,   133,   128,
      41,    41,    51,    52,   552,    93,   128,    95,    96,    97,
     133,    99,   133,   128,   102,   128,   132,   709,   106,   135,
     108,   128,   110,    41,     3,   113,    75,    76,   144,   145,
     133,   113,   128,   128,   133,   583,    41,   128,    87,    88,
      89,    90,    91,    92,   132,   128,   133,   135,   136,   137,
     132,   139,     5,   135,   142,   143,   144,    10,    11,    12,
     142,   143,   144,    41,    41,   133,   128,   128,   133,   157,
     158,    24,   128,   133,   123,   124,    29,    41,    31,    32,
     128,   133,   133,   133,    41,   128,    39,   133,   133,    42,
     128,   133,   128,    46,     9,    10,   133,    50,   133,   128,
      15,   150,   151,   133,   153,   154,    59,   128,   133,    24,
     133,   659,   128,   133,   133,   128,    31,    32,   133,    72,
      73,    74,   133,   133,    39,   133,    79,    42,    81,    82,
     128,    46,   133,   133,   682,    50,   684,   133,    25,    39,
      93,    16,    95,    96,    97,   169,    99,    68,   314,   102,
     382,   453,   263,   106,   417,   108,   265,   110,   436,   257,
     113,   709,   431,   417,    79,    -1,    81,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,   132,
      95,    96,   135,   136,   137,    -1,   139,    -1,    24,   142,
     143,   144,    -1,    29,    -1,    31,    32,    33,   113,    -1,
      -1,    -1,    -1,    39,   157,   158,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,    -1,    -1,   132,    -1,    -1,
     135,    -1,    -1,    59,    -1,    -1,    -1,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    24,    -1,   135,
     136,   137,    29,   139,    31,    32,   142,   143,   144,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,   157,   158,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    93,    -1,    95,    96,
      97,    -1,    99,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,   108,    -1,   110,    -1,    31,   113,    -1,    -1,    -1,
     117,    -1,    10,    11,    12,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,   132,    24,    -1,   135,   136,
     137,    29,   139,    31,    32,   142,   143,   144,    -1,    37,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
     157,   158,    50,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,
      -1,    99,    -1,    -1,   102,    -1,   132,    -1,   106,    -1,
     108,    -1,   110,    -1,    -1,   113,    -1,    -1,   144,    -1,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    24,    -1,   135,   136,   137,
      29,   139,    31,    32,   142,   143,   144,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,   157,
     158,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      99,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,   108,
      -1,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    24,    -1,   135,   136,   137,    29,
     139,    31,    32,   142,   143,   144,   145,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,   157,   158,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,    99,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,   108,    -1,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    24,    -1,   135,   136,   137,    29,   139,
      31,    32,   142,   143,   144,   145,    37,    -1,    39,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,   157,   158,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    -1,    99,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    24,    -1,   135,   136,   137,    29,   139,    31,
      32,   142,   143,   144,    -1,    37,    -1,    39,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,   157,   158,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    -1,    99,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,    24,    -1,   135,   136,   137,    29,   139,    31,    32,
     142,   143,   144,    -1,    37,    -1,    39,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,   157,   158,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    95,    96,    97,    -1,    99,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,   108,    -1,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      24,    -1,   135,   136,   137,    29,   139,    31,    32,   142,
     143,   144,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,   157,   158,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    96,    97,    -1,    99,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,   108,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    24,
      -1,   135,   136,   137,    29,   139,    31,    32,   142,   143,
     144,   145,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,   157,   158,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,    96,    97,    -1,    99,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,
     135,   136,   137,    -1,   139,    25,    26,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,
      -1,    -1,   157,   158,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    62,    63,    -1,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,    -1,   114,   115,   116,    -1,   118,   119,
      -1,   121,   122,    25,    26,   125,   126,    -1,    -1,    -1,
     130,   131,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,   146,   147,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    25,    26,   115,   116,    -1,   118,   119,    -1,   121,
     122,    35,    36,   125,   126,    39,    -1,    -1,   130,   131,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    -1,    -1,   146,   147,    60,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    25,
      26,   115,   116,    -1,   118,   119,    -1,   121,   122,    35,
      36,   125,   126,    39,    -1,    -1,   130,   131,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,   146,   147,    60,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    25,    26,   115,
     116,    -1,   118,   119,    -1,   121,   122,    35,    36,   125,
     126,    39,    -1,    -1,   130,   131,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
     146,   147,    60,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,   100,   101,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,   111,   112,    50,    -1,   115,   116,    -1,
     118,   119,    -1,   121,   122,    -1,    -1,   125,   126,    -1,
      -1,    -1,   130,   131,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    -1,   146,   147,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    10,
      95,    96,    -1,    -1,    15,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    24,    -1,    -1,    50,    -1,   113,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,   132,    -1,    50,
     135,    -1,    -1,    -1,    -1,    79,    -1,   142,   143,   144,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    24,    -1,    -1,    -1,    79,    29,
      81,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    42,    -1,    95,    96,    46,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    10,    -1,    -1,    -1,   132,    -1,
      -1,   135,   113,    -1,    -1,    -1,    66,    -1,    24,    -1,
     144,   145,    -1,    -1,    -1,    31,    32,    -1,    -1,    79,
      -1,   132,    -1,    39,   135,    -1,    42,    -1,    -1,    -1,
      46,   142,   143,   144,    50,    95,    96,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,   113,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    79,    10,    81,    -1,    -1,    -1,    42,
      -1,    -1,   132,    46,    -1,   135,    -1,    50,    24,    95,
      96,    -1,   142,   143,   144,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,   113,    -1,    10,
      46,    12,    -1,    -1,    50,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,   132,    -1,    -1,   135,
      31,    32,    95,    96,    10,    -1,   142,   143,   144,    -1,
      -1,    42,    -1,    79,    -1,    46,    -1,    -1,    24,    50,
     113,    -1,    -1,    -1,    -1,    31,    32,    -1,    59,    95,
      96,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,   132,
      46,    -1,   135,    -1,    50,    -1,    -1,   113,    79,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    95,    96,   132,    -1,    -1,   135,
      -1,   102,   138,    79,   140,   141,    24,    -1,   144,    -1,
      -1,    -1,   113,    31,    32,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,   132,    50,    -1,   135,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,   135,
      -1,    79,   138,    24,    -1,   141,    -1,    -1,   144,    10,
      31,    32,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    42,    -1,    24,    -1,    46,    -1,    -1,    -1,    50,
      31,    32,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    10,    -1,    50,
      -1,    -1,    -1,    -1,   132,    -1,    -1,   135,    79,    -1,
     138,    24,    -1,   141,    -1,    -1,   144,    10,    31,    32,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    79,    42,
      -1,    24,    -1,    46,    -1,    -1,    -1,    50,    31,    32,
      -1,    -1,   113,    -1,    95,    96,    97,    -1,    99,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    10,    -1,
      -1,   132,   113,    -1,   135,    -1,    79,    -1,    -1,   140,
     141,    -1,    24,   144,    -1,    -1,    -1,    -1,    -1,    31,
      32,   132,    95,    96,   135,    37,    79,    -1,    -1,    -1,
      42,    -1,    -1,   144,    46,    -1,    -1,    -1,    50,    -1,
     113,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     113,    -1,   135,    -1,    -1,    -1,    -1,    79,   141,    -1,
      -1,   144,    10,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,   135,    95,    96,    -1,    24,    -1,   141,    -1,
      -1,   144,    -1,    31,    32,    10,    -1,    10,    -1,    37,
      -1,   113,    -1,    -1,    42,    -1,    -1,    -1,    46,    24,
      -1,    24,    50,    -1,    -1,    -1,    31,    32,    31,    32,
     132,    -1,    37,   135,    -1,    -1,    -1,    42,    -1,    42,
      -1,    46,   144,    46,    -1,    50,    -1,    50,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      95,    96,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,   135,   113,    -1,
     113,    -1,    -1,    -1,    25,    26,   144,    28,    -1,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,   132,    39,   132,
     135,    -1,   135,    44,    45,    -1,    -1,    -1,    -1,   144,
      -1,   144,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,   118,   119,    -1,
     121,   122,    -1,    -1,   125,   126,    -1,    -1,    -1,   130,
     131,    -1,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    -1,    35,    36,   146,   147,    39,    -1,    -1,
      -1,   152,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    25,    26,   115,   116,    -1,   118,   119,    -1,   121,
     122,    35,    36,   125,   126,    39,    -1,    -1,   130,   131,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    -1,    -1,   146,   147,    60,    -1,    62,    63,
      -1,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,   121,   122,    -1,
      -1,   125,   126,    -1,    -1,    -1,   130,   131,    -1,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,   146,   147,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,    -1,
      65,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    25,    26,
     115,   116,    -1,   118,   119,    -1,   121,   122,    35,    36,
     125,   126,    39,    -1,    -1,   130,   131,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      -1,   146,   147,    60,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,   115,   116,
      -1,   118,   119,    -1,   121,   122,    -1,    -1,   125,   126,
      -1,    -1,    -1,   130,   131,    -1,    -1,    25,    26,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   146,
     147,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
     118,   119,    -1,   121,   122,    -1,    -1,   125,   126,    -1,
      -1,    -1,   130,   131,    -1,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   146,   147,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,    -1,   121,   122,    -1,    -1,   125,   126,    -1,    -1,
      -1,   130,   131,    -1,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,   146,   147,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,    25,    26,   115,   116,    -1,   118,   119,
      -1,   121,   122,    35,    36,   125,   126,    39,    -1,    -1,
     130,   131,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,   146,   147,    60,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    51,    52,    -1,    -1,    -1,    -1,    57,    58,   111,
     112,    -1,    -1,   115,   116,    -1,   118,   119,    -1,   121,
     122,    71,    72,   125,   126,    75,    76,    -1,   130,   131,
      -1,    81,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    -1,   146,   147,    41,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
     110,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    -1,   149,
     150,   151,    41,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    -1,   150,   151,    -1,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,   153,   154
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    19,   160,   161,   162,     5,     0,     3,     9,    18,
      23,    24,    32,   135,   167,   170,   171,   172,   256,    13,
      14,    16,    17,    20,    22,   163,   164,   165,   166,    10,
     273,   170,   273,     3,    23,   170,     5,    21,    23,   168,
     169,    15,    31,    39,    42,    46,    50,    79,    81,    95,
      96,   113,   132,   142,   143,   144,   172,   174,   175,   176,
     177,   178,   179,   180,   181,   183,   184,   185,   188,   189,
     190,   191,   192,   193,   219,   220,   232,   256,   257,   273,
       9,     5,     5,     5,     5,     5,     5,   164,   165,   166,
     165,   166,   166,     3,     9,   170,     5,     3,   170,   273,
      21,   169,     5,   219,    47,   273,   185,   184,   189,   256,
      25,    26,    35,    36,    44,    45,    53,    55,    60,    62,
      63,    65,    69,    70,    86,   100,   101,   111,   112,   115,
     116,   118,   119,   121,   122,   125,   126,   130,   131,   146,
     147,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     218,   219,   221,   222,   226,   227,   228,   229,   230,   231,
       4,   107,   194,   138,   141,   193,    37,    56,   174,   257,
     273,   174,   273,   273,    11,   274,   274,   274,   274,   274,
     274,   165,   166,   166,   166,    81,     3,   170,   170,     5,
     273,   273,   138,   141,   193,     3,     4,     4,    68,    77,
     114,   198,   233,   234,    29,   181,   182,   193,   197,   193,
     197,    66,   193,   197,   193,   197,   193,   193,   193,   193,
     197,   138,   140,   141,   193,    12,    59,    67,    72,    73,
      74,    81,    82,    93,    97,    99,   102,   106,   108,   110,
     117,   135,   136,   137,   139,   157,   158,   193,   196,   197,
     220,   224,   225,   235,   236,   242,   243,   244,   245,   251,
     252,   253,   256,   258,   259,   260,   261,   271,   274,   275,
      59,   135,   235,    59,   135,   193,   195,   196,   181,   182,
     193,   141,   193,   193,     3,    37,   174,   273,     9,     3,
       3,     3,     3,     3,     3,   166,   173,   174,   181,   256,
     170,     3,   170,     5,     3,   141,   193,   193,     3,    28,
      33,    77,   199,   198,   233,   134,     3,     4,     5,   198,
     235,    48,    37,   235,    37,   193,   145,   235,    37,   193,
     193,   197,   145,   235,   145,   193,    37,   235,    37,   193,
      37,   235,    37,   235,    37,    37,   140,   141,   193,   193,
     193,    59,   117,   135,   109,   110,   103,    49,    59,   117,
     120,   138,   220,   253,    41,    57,    58,    72,    81,    99,
     149,   238,   253,   254,   271,   272,   220,   253,    97,    99,
      80,   103,   145,   223,   235,   223,   225,    51,    52,    71,
      75,    76,    81,    84,    85,    87,    88,    89,    90,    91,
      92,   123,   124,   150,   151,   153,   154,   237,   238,   239,
     240,   241,   262,   263,   264,   265,   266,   267,   268,   269,
     270,     4,    33,    94,    98,   107,   246,   247,   248,   249,
     250,   193,   274,    27,    78,   110,    59,   223,    59,   223,
     193,     3,     3,    81,     3,     3,   174,   170,     3,   170,
       9,   186,   187,   188,   256,   193,     3,     3,   199,    28,
      30,    77,   152,   199,   129,     3,     4,     5,   198,     5,
     198,   198,     3,     4,   138,   235,   193,    39,   193,   145,
     235,   145,   193,    39,    39,   235,   193,   235,   235,   235,
     193,   193,   193,   103,    59,   117,   135,   144,   103,    49,
     138,    49,   193,   193,    57,   145,    40,    99,    57,    99,
     109,   110,   156,    64,   217,   217,    34,    43,    54,    61,
     127,   148,   155,   255,   193,   193,   195,   223,   195,   223,
      41,   133,    38,    71,    84,    41,   133,    38,   193,   242,
     258,   243,   246,   244,   193,   135,   193,   195,   235,     3,
     173,   181,   170,   273,     9,     3,   199,    28,    77,   199,
     129,   143,    28,   199,     5,   198,   198,     3,   198,     3,
       3,   138,   235,    39,    39,   235,   193,   135,   103,    59,
     135,   144,    49,   144,   145,   109,   156,   145,   110,   156,
     156,   109,   110,    66,   104,   195,   195,    71,    41,    83,
     135,    41,   133,    41,   133,    84,    41,    83,   135,   243,
     110,     3,     3,     9,   273,   199,   129,    28,   199,   199,
     199,   198,     3,     3,     3,   235,   193,    59,   135,    59,
     144,   109,   156,   110,   156,   105,   133,    71,    83,    71,
      41,    84,    41,    81,   128,   133,    84,    83,   193,   219,
       9,    28,   199,   199,     3,    59,   156,   133,   133,    71,
      81,   128,   133,    84,   128,    41,   133,    81,   128,    81,
     128,   133,     5,   235,   219,   199,   133,   128,    41,   133,
      81,   128,    81,   128,   133,    41,   133,   128,    41,   128,
      41,   133,   128,    41,   133,    81,   128,   235,     3,     5,
     235,    41,   133,   128,    41,   128,    41,   133,   128,    41,
     133,    81,   128,   128,    41,   133,   128,    41,   133,   128,
      41,    41,   133,   128,    41,   128,    41,   133,     3,   235,
       3,   128,    41,   133,   128,    41,   133,   128,    41,    41,
     133,   128,    41,   128,    41,   133,   133,   128,   133,   128,
      41,   133,   128,   128,    41,   133,   128,    41,   133,   128,
      41,     3,   133,   128,   133,   128,    41,   133,   128,   128,
      41,   133,   128,    41,   133,   128,    41,   133,   133,   128,
     133,   133,   128,   133,   128,    41,   133,   128,   133,   133,
     128,   133,   133,   128,   133,   128,    41,   133,   128,   133,
     133,   133,   128,   133,   133,   133,   133,   128,   133,   133,
     133
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   159,   160,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     162,   163,   164,   164,   165,   165,   166,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   168,   169,   169,   169,
     169,   170,   170,   170,   170,   171,   171,   172,   172,   172,
     172,   173,   173,   174,   174,   174,   174,   174,   174,   175,
     176,   177,   178,   179,   180,   181,   181,   182,   183,   183,
     184,   184,   185,   186,   186,   187,   187,   187,   187,   188,
     188,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   192,   192,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   194,   195,   195,   195,
     195,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   197,   197,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     200,   201,   201,   201,   201,   201,   202,   202,   203,   203,
     203,   203,   203,   204,   204,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   206,   206,   207,   207,   207,
     207,   207,   208,   208,   209,   210,   210,   211,   211,   211,
     212,   212,   213,   213,   213,   214,   214,   215,   215,   215,
     216,   216,   217,   218,   218,   218,   218,   218,   218,   219,
     219,   219,   219,   220,   220,   221,   221,   221,   221,   222,
     222,   222,   222,   222,   222,   222,   222,   223,   223,   223,
     224,   224,   224,   224,   225,   225,   225,   225,   226,   227,
     227,   228,   228,   229,   229,   230,   230,   231,   231,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   233,
     234,   234,   234,   235,   236,   237,   237,   237,   237,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     239,   239,   239,   239,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     241,   241,   241,   241,   242,   242,   242,   242,   242,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   246,   246,   246,   247,
     248,   249,   250,   251,   251,   251,   251,   252,   252,   252,
     252,   253,   253,   253,   253,   254,   254,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     257,   257,   257,   257,   258,   258,   259,   259,   259,   259,
     259,   260,   260,   260,   260,   260,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   271,   271,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   273,   274,   275
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     5,     2,     5,     3,     6,     4,     1,
       1,     2,     4,     1,     1,     2,     2,     1,     1,     3,
       4,     4,     5,     4,     5,     5,     6,     2,     3,     4,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     3,     1,     2,     3,     3,     4,
       4,     5,     4,     5,     5,     6,     6,     7,     7,     8,
       7,     8,     8,     9,     7,     8,     8,     9,     8,     9,
       9,    10,     7,     8,     8,     9,     8,     9,     9,    10,
       8,     9,     9,    10,     9,    10,    10,    11,     7,     8,
       8,     9,     8,     9,     9,    10,     8,     9,     9,    10,
       9,    10,    10,    11,     8,     9,     9,    10,     9,    10,
      10,    11,     9,    10,    10,    11,    10,    11,    11,    12,
       3,     4,     3,     4,     1,     1,     1,     1,     2,     1,
       3,     4,     1,     3,     1,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     5,
       1,     2,     3,     4,     5,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     3,     3,     4,     2,     3,
       3,     4,     3,     4,     4,     5,     1,     1,     1
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   364,     0,   354,     0,   354,     0,   354,     0,   354,
     364,     0,   359,     0,   373,     0,   257,     0,   214,     0
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
  "THESE", "THIS", "TIME", "TO", "TRANSFER", "TRANSFERS", "TRUE", "WAS",
  "WEEK", "WEEKS", "WITH", "YEAR", "YEARS", "YES", "YET", "YOURSELF",
  "YOURSELVES", "$accept", "Document", "Head", "Lex", "Lexon", "Authors",
  "Comment", "Preamble", "Terms", "Covenants", "Covenant", "Provisions",
  "Definitions", "Definition", "Type_Term", "Type", "Person", "Amount",
  "Time", "Binary", "Text", "Data", "This_Contract", "All_Contracts",
  "This", "Clauses", "Clause", "Body", "Function", "Statements",
  "Statement", "Action", "Subject", "Symbols", "Symbol", "Catena",
  "Object", "Reflexive", "Contract", "Predicates", "Predicate",
  "Permission", "Certification", "Certify", "Declaration", "Declare",
  "Filing", "File", "Registration", "Register", "Grantment", "Grant",
  "Appointment", "Appoint", "Acceptance", "Accept", "Fixture", "Fix",
  "Fixed", "Setting", "Illocutor", "Be", "Payment", "Pay", "Preposition",
  "Escrow", "From_Escrow", "Sending", "Send", "Notification", "Notify",
  "Termination", "Terminate", "Flagging", "Condition", "If", "Expression",
  "Scalar_Comparison", "Comparison_Operator", "Equal", "Greater", "Less",
  "Later", "Scalar_Expression", "Combination", "Combinor", "Combinand",
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
#line 1125 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 3118 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1126 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 3124 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1132 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 3130 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1133 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3136 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1134 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3142 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1135 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3148 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1136 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3154 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1137 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3160 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1138 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3166 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1139 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3172 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1140 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 3178 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1141 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3184 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1142 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3190 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1143 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3196 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1144 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3202 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1145 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3208 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1146 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3214 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1147 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3220 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1153 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 3226 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1159 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 3232 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1165 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3238 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1166 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3244 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1172 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3250 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1173 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3256 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1179 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 3262 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1185 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3268 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1186 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3274 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1187 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3280 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1188 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3286 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1189 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3292 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1190 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3298 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1191 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3304 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1192 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3310 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1198 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3316 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1199 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3322 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1205 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3328 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1206 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3334 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1207 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3340 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1208 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3346 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1214 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3352 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1215 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3358 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1216 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3364 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1217 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3370 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1223 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3376 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1224 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3382 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1230 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3388 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1231 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3394 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1232 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3400 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1233 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3406 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1239 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3412 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1240 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3418 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1246 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 3424 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1247 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 3430 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1248 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 3436 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1249 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 3442 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1250 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 3448 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1251 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 3454 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1257 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 3460 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1263 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 3466 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1269 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 3472 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1275 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 3478 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1281 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 3484 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1287 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 3490 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1293 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3496 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1294 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3502 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1300 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 3508 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1306 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3514 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1307 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3520 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1313 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3526 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1314 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3532 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1320 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 3538 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1326 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 3544 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1327 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 3550 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1333 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3556 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1334 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3562 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1335 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3568 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1336 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3574 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1342 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3580 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1343 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3586 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1349 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3592 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1350 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3598 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1356 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3604 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1357 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3610 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Predicates Separator  */
#line 1358 "parser.y"
                                                                    { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3616 "parser.c"
    break;

  case 86: /* Action: Subject Permission Condition Colon Predicates Separator  */
#line 1359 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3622 "parser.c"
    break;

  case 87: /* Action: Subject Permission Condition Comma Predicates Separator  */
#line 1360 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3628 "parser.c"
    break;

  case 88: /* Action: Subject Permission Condition Comma Colon Predicates Separator  */
#line 1361 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3634 "parser.c"
    break;

  case 89: /* Action: Subject Permission Comma Predicates Separator  */
#line 1362 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3640 "parser.c"
    break;

  case 90: /* Action: Subject Permission Comma Condition Predicates Separator  */
#line 1363 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3646 "parser.c"
    break;

  case 91: /* Action: Subject Permission Comma Condition Colon Predicates Separator  */
#line 1364 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3652 "parser.c"
    break;

  case 92: /* Action: Subject Permission Comma Condition Comma Predicates Separator  */
#line 1365 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3658 "parser.c"
    break;

  case 93: /* Action: Subject Permission Comma Condition Comma Colon Predicates Separator  */
#line 1366 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3664 "parser.c"
    break;

  case 94: /* Subject: Symbols  */
#line 1372 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3670 "parser.c"
    break;

  case 95: /* Symbols: Symbol  */
#line 1378 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3676 "parser.c"
    break;

  case 96: /* Symbols: Symbols Catena Symbol  */
#line 1379 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3682 "parser.c"
    break;

  case 97: /* Symbol: Name  */
#line 1385 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3688 "parser.c"
    break;

  case 98: /* Symbol: New Name  */
#line 1386 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3694 "parser.c"
    break;

  case 99: /* Symbol: Article Name  */
#line 1387 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3700 "parser.c"
    break;

  case 100: /* Symbol: Article New Name  */
#line 1388 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3706 "parser.c"
    break;

  case 101: /* Symbol: Type  */
#line 1389 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3712 "parser.c"
    break;

  case 102: /* Symbol: New Type  */
#line 1390 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3718 "parser.c"
    break;

  case 103: /* Symbol: Article Type  */
#line 1391 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3724 "parser.c"
    break;

  case 104: /* Symbol: Article New Type  */
#line 1392 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3730 "parser.c"
    break;

  case 105: /* Catena: OR  */
#line 1398 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3736 "parser.c"
    break;

  case 106: /* Catena: Comma  */
#line 1399 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3742 "parser.c"
    break;

  case 107: /* Object: Symbol  */
#line 1405 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3748 "parser.c"
    break;

  case 108: /* Object: Reflexive  */
#line 1406 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3754 "parser.c"
    break;

  case 109: /* Object: ESCROW  */
#line 1407 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3760 "parser.c"
    break;

  case 110: /* Object: THE ESCROW  */
#line 1408 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3766 "parser.c"
    break;

  case 111: /* Reflexive: MYSELF  */
#line 1414 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3772 "parser.c"
    break;

  case 112: /* Reflexive: YOURSELF  */
#line 1415 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3778 "parser.c"
    break;

  case 113: /* Reflexive: HERSELF  */
#line 1416 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3784 "parser.c"
    break;

  case 114: /* Reflexive: HIMSELF  */
#line 1417 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3790 "parser.c"
    break;

  case 115: /* Reflexive: ONESELF  */
#line 1418 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3796 "parser.c"
    break;

  case 116: /* Reflexive: ITSELF  */
#line 1419 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3802 "parser.c"
    break;

  case 117: /* Reflexive: THEMSELF  */
#line 1420 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3808 "parser.c"
    break;

  case 118: /* Reflexive: OURSELVES  */
#line 1421 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3814 "parser.c"
    break;

  case 119: /* Reflexive: YOURSELVES  */
#line 1422 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3820 "parser.c"
    break;

  case 120: /* Reflexive: THEMSELVES  */
#line 1423 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3826 "parser.c"
    break;

  case 121: /* Contract: This_Contract  */
#line 1429 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3832 "parser.c"
    break;

  case 122: /* Contract: All_Contracts  */
#line 1430 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3838 "parser.c"
    break;

  case 123: /* Predicates: Predicates Comma Predicate  */
#line 1436 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3844 "parser.c"
    break;

  case 124: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1437 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3850 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1438 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3856 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1439 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3862 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma AND Predicate  */
#line 1440 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3868 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1441 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3874 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1442 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3880 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1443 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3886 "parser.c"
    break;

  case 131: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1444 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3892 "parser.c"
    break;

  case 132: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1445 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3898 "parser.c"
    break;

  case 133: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1446 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3904 "parser.c"
    break;

  case 134: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1447 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3910 "parser.c"
    break;

  case 135: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1448 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3916 "parser.c"
    break;

  case 136: /* Predicates: Predicate  */
#line 1449 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3922 "parser.c"
    break;

  case 137: /* Predicate: Certification  */
#line 1455 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3928 "parser.c"
    break;

  case 138: /* Predicate: Declaration  */
#line 1456 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3934 "parser.c"
    break;

  case 139: /* Predicate: Filing  */
#line 1457 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3940 "parser.c"
    break;

  case 140: /* Predicate: Registration  */
#line 1458 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3946 "parser.c"
    break;

  case 141: /* Predicate: Grantment  */
#line 1459 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3952 "parser.c"
    break;

  case 142: /* Predicate: Appointment  */
#line 1460 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3958 "parser.c"
    break;

  case 143: /* Predicate: Acceptance  */
#line 1461 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Acceptance=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Acceptance); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3964 "parser.c"
    break;

  case 144: /* Predicate: Fixture  */
#line 1462 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3970 "parser.c"
    break;

  case 145: /* Predicate: Setting  */
#line 1463 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3976 "parser.c"
    break;

  case 146: /* Predicate: Payment  */
#line 1464 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3982 "parser.c"
    break;

  case 147: /* Predicate: Sending  */
#line 1465 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3988 "parser.c"
    break;

  case 148: /* Predicate: Notification  */
#line 1466 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3994 "parser.c"
    break;

  case 149: /* Predicate: Termination  */
#line 1467 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4000 "parser.c"
    break;

  case 150: /* Permission: MAY  */
#line 1473 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 4006 "parser.c"
    break;

  case 151: /* Certification: Certify Symbol  */
#line 1479 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4012 "parser.c"
    break;

  case 152: /* Certification: Certify Symbol Expression  */
#line 1480 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4018 "parser.c"
    break;

  case 153: /* Certification: Certify Symbol AS Expression  */
#line 1481 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4024 "parser.c"
    break;

  case 154: /* Certification: Certify Contract Symbol  */
#line 1482 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4030 "parser.c"
    break;

  case 155: /* Certification: Certify Contract AS Symbol  */
#line 1483 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4036 "parser.c"
    break;

  case 156: /* Certify: CERTIFY  */
#line 1489 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4042 "parser.c"
    break;

  case 157: /* Certify: CERTIFIES  */
#line 1490 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4048 "parser.c"
    break;

  case 158: /* Declaration: Declare Symbol  */
#line 1496 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4054 "parser.c"
    break;

  case 159: /* Declaration: Declare Symbol Expression  */
#line 1497 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4060 "parser.c"
    break;

  case 160: /* Declaration: Declare Symbol TO BE Expression  */
#line 1498 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4066 "parser.c"
    break;

  case 161: /* Declaration: Declare Contract Symbol  */
#line 1499 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4072 "parser.c"
    break;

  case 162: /* Declaration: Declare Contract AS Symbol  */
#line 1500 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4078 "parser.c"
    break;

  case 163: /* Declare: DECLARE  */
#line 1506 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4084 "parser.c"
    break;

  case 164: /* Declare: DECLARES  */
#line 1507 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4090 "parser.c"
    break;

  case 165: /* Filing: File Symbol  */
#line 1513 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4096 "parser.c"
    break;

  case 166: /* Filing: File Symbol Expression  */
#line 1514 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4102 "parser.c"
    break;

  case 167: /* Filing: File Symbol TO BE Expression  */
#line 1515 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4108 "parser.c"
    break;

  case 168: /* Filing: File FOR Symbol  */
#line 1516 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4114 "parser.c"
    break;

  case 169: /* Filing: File FOR Symbol Expression  */
#line 1517 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4120 "parser.c"
    break;

  case 170: /* Filing: File FOR Symbol TO BE Expression  */
#line 1518 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4126 "parser.c"
    break;

  case 171: /* Filing: File Contract Symbol  */
#line 1519 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4132 "parser.c"
    break;

  case 172: /* Filing: File Contract TO BE Symbol  */
#line 1520 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4138 "parser.c"
    break;

  case 173: /* Filing: File FOR Contract Symbol  */
#line 1521 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4144 "parser.c"
    break;

  case 174: /* Filing: File FOR Contract TO BE Symbol  */
#line 1522 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4150 "parser.c"
    break;

  case 175: /* File: FILE_  */
#line 1528 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4156 "parser.c"
    break;

  case 176: /* File: FILES  */
#line 1529 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4162 "parser.c"
    break;

  case 177: /* Registration: Register Symbol  */
#line 1535 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4168 "parser.c"
    break;

  case 178: /* Registration: Register Symbol Expression  */
#line 1536 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4174 "parser.c"
    break;

  case 179: /* Registration: Register Symbol AS Expression  */
#line 1537 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4180 "parser.c"
    break;

  case 180: /* Registration: Register Contract Symbol  */
#line 1538 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4186 "parser.c"
    break;

  case 181: /* Registration: Register Contract AS Symbol  */
#line 1539 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4192 "parser.c"
    break;

  case 182: /* Register: REGISTER  */
#line 1545 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4198 "parser.c"
    break;

  case 183: /* Register: REGISTERS  */
#line 1546 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4204 "parser.c"
    break;

  case 184: /* Grantment: Grant Symbol  */
#line 1552 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 4210 "parser.c"
    break;

  case 185: /* Grant: GRANT  */
#line 1558 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4216 "parser.c"
    break;

  case 186: /* Grant: GRANTS  */
#line 1559 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4222 "parser.c"
    break;

  case 187: /* Appointment: Appoint Symbol  */
#line 1565 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4228 "parser.c"
    break;

  case 188: /* Appointment: Appoint Symbol Expression  */
#line 1566 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4234 "parser.c"
    break;

  case 189: /* Appointment: Appoint Symbol AS Expression  */
#line 1567 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4240 "parser.c"
    break;

  case 190: /* Appoint: APPOINT  */
#line 1573 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4246 "parser.c"
    break;

  case 191: /* Appoint: APPOINTS  */
#line 1574 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4252 "parser.c"
    break;

  case 192: /* Acceptance: Accept Symbol  */
#line 1580 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4258 "parser.c"
    break;

  case 193: /* Acceptance: Accept Symbol Expression  */
#line 1581 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4264 "parser.c"
    break;

  case 194: /* Acceptance: Accept Symbol AS Expression  */
#line 1582 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4270 "parser.c"
    break;

  case 195: /* Accept: ACCEPT  */
#line 1588 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4276 "parser.c"
    break;

  case 196: /* Accept: ACCEPTS  */
#line 1589 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4282 "parser.c"
    break;

  case 197: /* Fixture: Fix Symbol  */
#line 1595 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4288 "parser.c"
    break;

  case 198: /* Fixture: Fix Symbol AS Expression  */
#line 1596 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4294 "parser.c"
    break;

  case 199: /* Fixture: Fix Contract AS Symbol  */
#line 1597 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4300 "parser.c"
    break;

  case 200: /* Fix: FIX  */
#line 1603 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4306 "parser.c"
    break;

  case 201: /* Fix: FIXES  */
#line 1604 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4312 "parser.c"
    break;

  case 202: /* Fixed: FIXED  */
#line 1610 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 4318 "parser.c"
    break;

  case 203: /* Setting: Illocutor Symbol  */
#line 1616 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4324 "parser.c"
    break;

  case 204: /* Setting: Illocutor THEREFOR Symbol  */
#line 1617 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4330 "parser.c"
    break;

  case 205: /* Setting: Illocutor THEREFORE Symbol  */
#line 1618 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4336 "parser.c"
    break;

  case 206: /* Setting: Illocutor THEN Symbol  */
#line 1619 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4342 "parser.c"
    break;

  case 207: /* Setting: Illocutor THEN THEREFOR Symbol  */
#line 1620 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4348 "parser.c"
    break;

  case 208: /* Setting: Illocutor THEN THEREFORE Symbol  */
#line 1621 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4354 "parser.c"
    break;

  case 209: /* Illocutor: Be  */
#line 1627 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4360 "parser.c"
    break;

  case 210: /* Illocutor: Be AS  */
#line 1628 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4366 "parser.c"
    break;

  case 211: /* Illocutor: Be DEFINED  */
#line 1629 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4372 "parser.c"
    break;

  case 212: /* Illocutor: Be DEFINED AS  */
#line 1630 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4378 "parser.c"
    break;

  case 213: /* Be: BE  */
#line 1636 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4384 "parser.c"
    break;

  case 214: /* Be: IS  */
#line 1637 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4390 "parser.c"
    break;

  case 215: /* Payment: Pay Expression Preposition Object  */
#line 1643 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4396 "parser.c"
    break;

  case 216: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1644 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4402 "parser.c"
    break;

  case 217: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1645 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4408 "parser.c"
    break;

  case 218: /* Payment: Pay Escrow Preposition Object  */
#line 1646 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4414 "parser.c"
    break;

  case 219: /* Pay: PAY  */
#line 1652 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4420 "parser.c"
    break;

  case 220: /* Pay: PAYS  */
#line 1653 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4426 "parser.c"
    break;

  case 221: /* Pay: RETURN  */
#line 1654 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4432 "parser.c"
    break;

  case 222: /* Pay: RETURNS  */
#line 1655 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4438 "parser.c"
    break;

  case 223: /* Pay: REPAY  */
#line 1656 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4444 "parser.c"
    break;

  case 224: /* Pay: REPAYS  */
#line 1657 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4450 "parser.c"
    break;

  case 225: /* Pay: TRANSFER  */
#line 1658 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4456 "parser.c"
    break;

  case 226: /* Pay: TRANSFERS  */
#line 1659 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4462 "parser.c"
    break;

  case 227: /* Preposition: TO  */
#line 1665 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4468 "parser.c"
    break;

  case 228: /* Preposition: INTO  */
#line 1666 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4474 "parser.c"
    break;

  case 229: /* Preposition: OF  */
#line 1667 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4480 "parser.c"
    break;

  case 230: /* Escrow: ESCROW  */
#line 1673 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4486 "parser.c"
    break;

  case 231: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1674 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4492 "parser.c"
    break;

  case 232: /* Escrow: THE ESCROW  */
#line 1675 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4498 "parser.c"
    break;

  case 233: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1676 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4504 "parser.c"
    break;

  case 234: /* From_Escrow: FROM ESCROW  */
#line 1682 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4510 "parser.c"
    break;

  case 235: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1683 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4516 "parser.c"
    break;

  case 236: /* From_Escrow: FROM THE ESCROW  */
#line 1684 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4522 "parser.c"
    break;

  case 237: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1685 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4528 "parser.c"
    break;

  case 238: /* Sending: Send Expression Preposition Object  */
#line 1691 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 4534 "parser.c"
    break;

  case 239: /* Send: SEND  */
#line 1697 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4540 "parser.c"
    break;

  case 240: /* Send: SENDS  */
#line 1698 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4546 "parser.c"
    break;

  case 241: /* Notification: Notify Object  */
#line 1704 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4552 "parser.c"
    break;

  case 242: /* Notification: Notify Object Preposition Expression  */
#line 1705 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4558 "parser.c"
    break;

  case 243: /* Notify: NOTIFY  */
#line 1711 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4564 "parser.c"
    break;

  case 244: /* Notify: NOTIFIES  */
#line 1712 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4570 "parser.c"
    break;

  case 245: /* Termination: Terminate This_Contract  */
#line 1718 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4576 "parser.c"
    break;

  case 246: /* Termination: Terminate All_Contracts  */
#line 1719 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4582 "parser.c"
    break;

  case 247: /* Terminate: TERMINATE  */
#line 1725 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4588 "parser.c"
    break;

  case 248: /* Terminate: TERMINATES  */
#line 1726 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4594 "parser.c"
    break;

  case 249: /* Flagging: Illocutor Symbol Separator  */
#line 1732 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4600 "parser.c"
    break;

  case 250: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1733 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4606 "parser.c"
    break;

  case 251: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1734 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4612 "parser.c"
    break;

  case 252: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1735 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4618 "parser.c"
    break;

  case 253: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1736 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4624 "parser.c"
    break;

  case 254: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1737 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4630 "parser.c"
    break;

  case 255: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1738 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4636 "parser.c"
    break;

  case 256: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1739 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4642 "parser.c"
    break;

  case 257: /* Condition: If Expression  */
#line 1745 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4648 "parser.c"
    break;

  case 258: /* Condition: If Expression THEN  */
#line 1746 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4654 "parser.c"
    break;

  case 259: /* Condition: If Expression Comma THEN  */
#line 1747 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4660 "parser.c"
    break;

  case 260: /* If: IF  */
#line 1753 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4666 "parser.c"
    break;

  case 261: /* If: GIVEN THAT  */
#line 1754 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4672 "parser.c"
    break;

  case 262: /* If: PROVIDED  */
#line 1755 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4678 "parser.c"
    break;

  case 263: /* Expression: Combination  */
#line 1761 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 4684 "parser.c"
    break;

  case 264: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1767 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 4690 "parser.c"
    break;

  case 265: /* Comparison_Operator: Equal  */
#line 1773 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4696 "parser.c"
    break;

  case 266: /* Comparison_Operator: Greater  */
#line 1774 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Greater=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Greater); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4702 "parser.c"
    break;

  case 267: /* Comparison_Operator: Less  */
#line 1775 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Less=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Less); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4708 "parser.c"
    break;

  case 268: /* Comparison_Operator: Later  */
#line 1776 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4714 "parser.c"
    break;

  case 269: /* Equal: EQUAL  */
#line 1782 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4720 "parser.c"
    break;

  case 270: /* Equal: EQUAL TO  */
#line 1783 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4726 "parser.c"
    break;

  case 271: /* Equal: EQUALING  */
#line 1784 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4732 "parser.c"
    break;

  case 272: /* Equal: IS  */
#line 1785 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4738 "parser.c"
    break;

  case 273: /* Equal: IS EQUAL  */
#line 1786 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4744 "parser.c"
    break;

  case 274: /* Equal: IS EQUAL TO  */
#line 1787 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4750 "parser.c"
    break;

  case 275: /* Equal: BEING  */
#line 1788 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4756 "parser.c"
    break;

  case 276: /* Equal: BEING EQUAL  */
#line 1789 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4762 "parser.c"
    break;

  case 277: /* Equal: BEING EQUAL TO  */
#line 1790 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4768 "parser.c"
    break;

  case 278: /* Greater: GREATER BEING GREATER  */
#line 1796 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4774 "parser.c"
    break;

  case 279: /* Greater: GREATER BEING GREATER THAN  */
#line 1797 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4780 "parser.c"
    break;

  case 280: /* Greater: GREATER THAN BEING GREATER  */
#line 1798 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4786 "parser.c"
    break;

  case 281: /* Greater: GREATER THAN BEING GREATER THAN  */
#line 1799 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4792 "parser.c"
    break;

  case 282: /* Greater: IS GREATER BEING GREATER  */
#line 1800 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4798 "parser.c"
    break;

  case 283: /* Greater: IS GREATER BEING GREATER THAN  */
#line 1801 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4804 "parser.c"
    break;

  case 284: /* Greater: IS GREATER THAN BEING GREATER  */
#line 1802 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4810 "parser.c"
    break;

  case 285: /* Greater: IS GREATER THAN BEING GREATER THAN  */
#line 1803 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4816 "parser.c"
    break;

  case 286: /* Less: LESS BEING LESS SMALLER BEING SMALLER  */
#line 1809 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4822 "parser.c"
    break;

  case 287: /* Less: LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1810 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4828 "parser.c"
    break;

  case 288: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1811 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4834 "parser.c"
    break;

  case 289: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1812 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4840 "parser.c"
    break;

  case 290: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1813 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4846 "parser.c"
    break;

  case 291: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1814 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4852 "parser.c"
    break;

  case 292: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1815 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4858 "parser.c"
    break;

  case 293: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1816 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4864 "parser.c"
    break;

  case 294: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1817 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4870 "parser.c"
    break;

  case 295: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1818 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4876 "parser.c"
    break;

  case 296: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1819 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4882 "parser.c"
    break;

  case 297: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1820 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4888 "parser.c"
    break;

  case 298: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1821 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4894 "parser.c"
    break;

  case 299: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1822 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4900 "parser.c"
    break;

  case 300: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1823 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4906 "parser.c"
    break;

  case 301: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1824 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4912 "parser.c"
    break;

  case 302: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1825 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4918 "parser.c"
    break;

  case 303: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1826 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4924 "parser.c"
    break;

  case 304: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1827 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4930 "parser.c"
    break;

  case 305: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1828 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4936 "parser.c"
    break;

  case 306: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1829 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4942 "parser.c"
    break;

  case 307: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1830 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4948 "parser.c"
    break;

  case 308: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1831 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4954 "parser.c"
    break;

  case 309: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1832 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4960 "parser.c"
    break;

  case 310: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1833 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4966 "parser.c"
    break;

  case 311: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1834 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4972 "parser.c"
    break;

  case 312: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1835 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4978 "parser.c"
    break;

  case 313: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1836 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4984 "parser.c"
    break;

  case 314: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1837 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4990 "parser.c"
    break;

  case 315: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1838 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4996 "parser.c"
    break;

  case 316: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1839 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5002 "parser.c"
    break;

  case 317: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1840 "parser.y"
                                                                                { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5008 "parser.c"
    break;

  case 318: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER  */
#line 1841 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5014 "parser.c"
    break;

  case 319: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1842 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5020 "parser.c"
    break;

  case 320: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1843 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5026 "parser.c"
    break;

  case 321: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1844 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5032 "parser.c"
    break;

  case 322: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1845 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5038 "parser.c"
    break;

  case 323: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1846 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5044 "parser.c"
    break;

  case 324: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1847 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5050 "parser.c"
    break;

  case 325: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1848 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5056 "parser.c"
    break;

  case 326: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1849 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5062 "parser.c"
    break;

  case 327: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1850 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5068 "parser.c"
    break;

  case 328: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1851 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5074 "parser.c"
    break;

  case 329: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1852 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5080 "parser.c"
    break;

  case 330: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1853 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5086 "parser.c"
    break;

  case 331: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1854 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5092 "parser.c"
    break;

  case 332: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1855 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5098 "parser.c"
    break;

  case 333: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1856 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5104 "parser.c"
    break;

  case 334: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1857 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5110 "parser.c"
    break;

  case 335: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1858 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5116 "parser.c"
    break;

  case 336: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1859 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5122 "parser.c"
    break;

  case 337: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1860 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5128 "parser.c"
    break;

  case 338: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1861 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5134 "parser.c"
    break;

  case 339: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1862 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5140 "parser.c"
    break;

  case 340: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1863 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5146 "parser.c"
    break;

  case 341: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1864 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5152 "parser.c"
    break;

  case 342: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1865 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5158 "parser.c"
    break;

  case 343: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1866 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5164 "parser.c"
    break;

  case 344: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1867 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5170 "parser.c"
    break;

  case 345: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1868 "parser.y"
                                                                               { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5176 "parser.c"
    break;

  case 346: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1869 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5182 "parser.c"
    break;

  case 347: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1870 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5188 "parser.c"
    break;

  case 348: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1871 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5194 "parser.c"
    break;

  case 349: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1872 "parser.y"
                                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5200 "parser.c"
    break;

  case 350: /* Later: IS AT LEAST  */
#line 1878 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5206 "parser.c"
    break;

  case 351: /* Later: IS AT THE LEAST  */
#line 1879 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5212 "parser.c"
    break;

  case 352: /* Later: LIES AT LEAST  */
#line 1880 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5218 "parser.c"
    break;

  case 353: /* Later: LIES AT THE LEAST  */
#line 1881 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5224 "parser.c"
    break;

  case 354: /* Scalar_Expression: Symbol  */
#line 1887 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5230 "parser.c"
    break;

  case 355: /* Scalar_Expression: Scalar  */
#line 1888 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5236 "parser.c"
    break;

  case 356: /* Scalar_Expression: Point_In_Time  */
#line 1889 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5242 "parser.c"
    break;

  case 357: /* Scalar_Expression: ESCROW  */
#line 1890 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5248 "parser.c"
    break;

  case 358: /* Scalar_Expression: THE ESCROW  */
#line 1891 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5254 "parser.c"
    break;

  case 359: /* Combination: Combinor  */
#line 1897 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5260 "parser.c"
    break;

  case 360: /* Combination: Combinor Comma Combination  */
#line 1898 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5266 "parser.c"
    break;

  case 361: /* Combination: Combinor Comma Combinator Combination  */
#line 1899 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5272 "parser.c"
    break;

  case 362: /* Combinor: Combinand  */
#line 1905 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5278 "parser.c"
    break;

  case 363: /* Combinor: Combinand Combinator Combinor  */
#line 1906 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5284 "parser.c"
    break;

  case 364: /* Combinand: Symbol  */
#line 1912 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5290 "parser.c"
    break;

  case 365: /* Combinand: Symbol Expiration  */
#line 1913 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5296 "parser.c"
    break;

  case 366: /* Combinand: Symbol Timeliness  */
#line 1914 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Timeliness=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Timeliness); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5302 "parser.c"
    break;

  case 367: /* Combinand: Reflexive  */
#line 1915 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5308 "parser.c"
    break;

  case 368: /* Combinand: Description  */
#line 1916 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5314 "parser.c"
    break;

  case 369: /* Combinand: Article Description  */
#line 1917 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5320 "parser.c"
    break;

  case 370: /* Combinand: Scalar_Comparison  */
#line 1918 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5326 "parser.c"
    break;

  case 371: /* Combinand: Negation  */
#line 1919 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5332 "parser.c"
    break;

  case 372: /* Combinand: Existence  */
#line 1920 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5338 "parser.c"
    break;

  case 373: /* Combinand: Point_In_Time  */
#line 1921 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5344 "parser.c"
    break;

  case 374: /* Combinand: Expiration  */
#line 1922 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5350 "parser.c"
    break;

  case 375: /* Combinator: Or_  */
#line 1928 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5356 "parser.c"
    break;

  case 376: /* Combinator: And  */
#line 1929 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5362 "parser.c"
    break;

  case 377: /* Combinator: Neither  */
#line 1930 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5368 "parser.c"
    break;

  case 378: /* Combinator: Nor  */
#line 1931 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5374 "parser.c"
    break;

  case 379: /* Or_: OR  */
#line 1937 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 5380 "parser.c"
    break;

  case 380: /* And: AND  */
#line 1943 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 5386 "parser.c"
    break;

  case 381: /* Neither: NEITHER  */
#line 1949 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 5392 "parser.c"
    break;

  case 382: /* Nor: NOR  */
#line 1955 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 5398 "parser.c"
    break;

  case 383: /* Existence: Symbol Equal Fixed  */
#line 1961 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5404 "parser.c"
    break;

  case 384: /* Existence: THERE Be Symbol  */
#line 1962 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5410 "parser.c"
    break;

  case 385: /* Existence: Contract Be Symbol  */
#line 1963 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5416 "parser.c"
    break;

  case 386: /* Existence: Symbol Being True  */
#line 1964 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5422 "parser.c"
    break;

  case 387: /* Negation: Negator Symbol  */
#line 1970 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5428 "parser.c"
    break;

  case 388: /* Negation: Symbol Negator Fixed  */
#line 1971 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5434 "parser.c"
    break;

  case 389: /* Negation: THERE Negator Symbol  */
#line 1972 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5440 "parser.c"
    break;

  case 390: /* Negation: Contract Negator Symbol  */
#line 1973 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5446 "parser.c"
    break;

  case 391: /* Negator: NOT  */
#line 1979 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5452 "parser.c"
    break;

  case 392: /* Negator: Be NOT  */
#line 1980 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5458 "parser.c"
    break;

  case 393: /* Negator: NO  */
#line 1981 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5464 "parser.c"
    break;

  case 394: /* Negator: Be NO  */
#line 1982 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5470 "parser.c"
    break;

  case 395: /* Being: IS  */
#line 1988 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5476 "parser.c"
    break;

  case 396: /* Being: HAS BEEN  */
#line 1989 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5482 "parser.c"
    break;

  case 397: /* Being: WAS  */
#line 1990 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5488 "parser.c"
    break;

  case 398: /* True: TRUE  */
#line 1996 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5494 "parser.c"
    break;

  case 399: /* True: YES  */
#line 1997 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5500 "parser.c"
    break;

  case 400: /* True: CERTIFIED  */
#line 1998 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5506 "parser.c"
    break;

  case 401: /* True: DECLARED  */
#line 1999 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5512 "parser.c"
    break;

  case 402: /* True: ANNOUNCED  */
#line 2000 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5518 "parser.c"
    break;

  case 403: /* True: FILED  */
#line 2001 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5524 "parser.c"
    break;

  case 404: /* True: FILED FOR  */
#line 2002 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5530 "parser.c"
    break;

  case 405: /* True: SIGNED OFF  */
#line 2003 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5536 "parser.c"
    break;

  case 406: /* True: SIGNED OFF ON  */
#line 2004 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5542 "parser.c"
    break;

  case 407: /* Article: A  */
#line 2010 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5548 "parser.c"
    break;

  case 408: /* Article: AN  */
#line 2011 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5554 "parser.c"
    break;

  case 409: /* Article: THE  */
#line 2012 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5560 "parser.c"
    break;

  case 410: /* New: NEW  */
#line 2018 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5566 "parser.c"
    break;

  case 411: /* New: NEXT  */
#line 2019 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5572 "parser.c"
    break;

  case 412: /* New: COMING  */
#line 2020 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5578 "parser.c"
    break;

  case 413: /* New: INCOMING  */
#line 2021 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5584 "parser.c"
    break;

  case 414: /* Point_In_Time: Current_Time  */
#line 2027 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5590 "parser.c"
    break;

  case 415: /* Point_In_Time: Relative_Time  */
#line 2028 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5596 "parser.c"
    break;

  case 416: /* Current_Time: THE CURRENT TIME  */
#line 2034 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5602 "parser.c"
    break;

  case 417: /* Current_Time: THE THEN CURRENT TIME  */
#line 2035 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5608 "parser.c"
    break;

  case 418: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 2036 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5614 "parser.c"
    break;

  case 419: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 2037 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5620 "parser.c"
    break;

  case 420: /* Current_Time: NOW  */
#line 2038 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5626 "parser.c"
    break;

  case 421: /* Relative_Time: Duration PAST  */
#line 2044 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5632 "parser.c"
    break;

  case 422: /* Relative_Time: Duration PAST Symbol  */
#line 2045 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5638 "parser.c"
    break;

  case 423: /* Relative_Time: Duration IN THE PAST  */
#line 2046 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5644 "parser.c"
    break;

  case 424: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 2047 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5650 "parser.c"
    break;

  case 425: /* Relative_Time: Duration AFTER Symbol  */
#line 2048 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5656 "parser.c"
    break;

  case 426: /* Duration: Scalar_Expression Time_Unit  */
#line 2054 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 5662 "parser.c"
    break;

  case 427: /* Time_Unit: Years  */
#line 2060 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5668 "parser.c"
    break;

  case 428: /* Time_Unit: Months  */
#line 2061 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5674 "parser.c"
    break;

  case 429: /* Time_Unit: Weeks  */
#line 2062 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5680 "parser.c"
    break;

  case 430: /* Time_Unit: Days  */
#line 2063 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5686 "parser.c"
    break;

  case 431: /* Time_Unit: Hours  */
#line 2064 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5692 "parser.c"
    break;

  case 432: /* Time_Unit: Minutes  */
#line 2065 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5698 "parser.c"
    break;

  case 433: /* Time_Unit: Seconds  */
#line 2066 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5704 "parser.c"
    break;

  case 434: /* Time_Unit: Milliseconds  */
#line 2067 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5710 "parser.c"
    break;

  case 435: /* Years: YEAR  */
#line 2073 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5716 "parser.c"
    break;

  case 436: /* Years: YEARS  */
#line 2074 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5722 "parser.c"
    break;

  case 437: /* Months: MONTH  */
#line 2080 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5728 "parser.c"
    break;

  case 438: /* Months: MONTHS  */
#line 2081 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5734 "parser.c"
    break;

  case 439: /* Weeks: WEEK  */
#line 2087 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5740 "parser.c"
    break;

  case 440: /* Weeks: WEEKS  */
#line 2088 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5746 "parser.c"
    break;

  case 441: /* Days: DAY  */
#line 2094 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5752 "parser.c"
    break;

  case 442: /* Days: DAYS  */
#line 2095 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5758 "parser.c"
    break;

  case 443: /* Hours: HOUR  */
#line 2101 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5764 "parser.c"
    break;

  case 444: /* Hours: HOURS  */
#line 2102 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5770 "parser.c"
    break;

  case 445: /* Minutes: MINUTE  */
#line 2108 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5776 "parser.c"
    break;

  case 446: /* Minutes: MINUTES  */
#line 2109 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5782 "parser.c"
    break;

  case 447: /* Seconds: SECOND  */
#line 2115 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5788 "parser.c"
    break;

  case 448: /* Seconds: SECONDS  */
#line 2116 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5794 "parser.c"
    break;

  case 449: /* Milliseconds: MILLISECOND  */
#line 2122 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5800 "parser.c"
    break;

  case 450: /* Milliseconds: MILLISECONDS  */
#line 2123 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5806 "parser.c"
    break;

  case 451: /* Expiration: HAS PASSED  */
#line 2129 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5812 "parser.c"
    break;

  case 452: /* Expiration: PAST  */
#line 2130 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5818 "parser.c"
    break;

  case 453: /* Expiration: IS PAST  */
#line 2131 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5824 "parser.c"
    break;

  case 454: /* Timeliness: NOT PASSED  */
#line 2137 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5830 "parser.c"
    break;

  case 455: /* Timeliness: NOT YET PASSED  */
#line 2138 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5836 "parser.c"
    break;

  case 456: /* Timeliness: HAS NOT PASSED  */
#line 2139 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5842 "parser.c"
    break;

  case 457: /* Timeliness: HAS NOT YET PASSED  */
#line 2140 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5848 "parser.c"
    break;

  case 458: /* Timeliness: NOT PAST  */
#line 2141 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5854 "parser.c"
    break;

  case 459: /* Timeliness: NOT PAST YET  */
#line 2142 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5860 "parser.c"
    break;

  case 460: /* Timeliness: NOT YET PAST  */
#line 2143 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5866 "parser.c"
    break;

  case 461: /* Timeliness: NOT YET PAST YET  */
#line 2144 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5872 "parser.c"
    break;

  case 462: /* Timeliness: IS NOT PAST  */
#line 2145 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5878 "parser.c"
    break;

  case 463: /* Timeliness: IS NOT PAST YET  */
#line 2146 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5884 "parser.c"
    break;

  case 464: /* Timeliness: IS NOT YET PAST  */
#line 2147 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5890 "parser.c"
    break;

  case 465: /* Timeliness: IS NOT YET PAST YET  */
#line 2148 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5896 "parser.c"
    break;

  case 466: /* Name: NAME  */
#line 2152 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 5902 "parser.c"
    break;

  case 467: /* Description: DESCRIPTION  */
#line 2155 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 5908 "parser.c"
    break;

  case 468: /* Scalar: SCALAR  */
#line 2158 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 5914 "parser.c"
    break;


#line 5918 "parser.c"

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




#line 2163 "parser.y"


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

