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
  YYSYMBOL_AFTER = 25,                     /* AFTER  */
  YYSYMBOL_AFTERWARDS = 26,                /* AFTERWARDS  */
  YYSYMBOL_ALL = 27,                       /* ALL  */
  YYSYMBOL_ALSO = 28,                      /* ALSO  */
  YYSYMBOL_AMOUNT = 29,                    /* AMOUNT  */
  YYSYMBOL_AN = 30,                        /* AN  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_ANNOUNCED = 32,                 /* ANNOUNCED  */
  YYSYMBOL_APPOINT = 33,                   /* APPOINT  */
  YYSYMBOL_APPOINTS = 34,                  /* APPOINTS  */
  YYSYMBOL_AS = 35,                        /* AS  */
  YYSYMBOL_AT = 36,                        /* AT  */
  YYSYMBOL_BE = 37,                        /* BE  */
  YYSYMBOL_BEEN = 38,                      /* BEEN  */
  YYSYMBOL_BEING = 39,                     /* BEING  */
  YYSYMBOL_BINARY = 40,                    /* BINARY  */
  YYSYMBOL_CERTIFIED = 41,                 /* CERTIFIED  */
  YYSYMBOL_CERTIFIES = 42,                 /* CERTIFIES  */
  YYSYMBOL_CERTIFY = 43,                   /* CERTIFY  */
  YYSYMBOL_CONTRACT = 44,                  /* CONTRACT  */
  YYSYMBOL_CONTRACTS = 45,                 /* CONTRACTS  */
  YYSYMBOL_CURRENT = 46,                   /* CURRENT  */
  YYSYMBOL_DATA = 47,                      /* DATA  */
  YYSYMBOL_DAY = 48,                       /* DAY  */
  YYSYMBOL_DAYS = 49,                      /* DAYS  */
  YYSYMBOL_DECLARE = 50,                   /* DECLARE  */
  YYSYMBOL_DECLARED = 51,                  /* DECLARED  */
  YYSYMBOL_DECLARES = 52,                  /* DECLARES  */
  YYSYMBOL_DEFINED = 53,                   /* DEFINED  */
  YYSYMBOL_EQUAL = 54,                     /* EQUAL  */
  YYSYMBOL_EQUALING = 55,                  /* EQUALING  */
  YYSYMBOL_ESCROW = 56,                    /* ESCROW  */
  YYSYMBOL_FILE_ = 57,                     /* FILE_  */
  YYSYMBOL_FILED = 58,                     /* FILED  */
  YYSYMBOL_FILES = 59,                     /* FILES  */
  YYSYMBOL_FIX = 60,                       /* FIX  */
  YYSYMBOL_FIXED = 61,                     /* FIXED  */
  YYSYMBOL_FIXES = 62,                     /* FIXES  */
  YYSYMBOL_FOR = 63,                       /* FOR  */
  YYSYMBOL_FROM = 64,                      /* FROM  */
  YYSYMBOL_GIVEN = 65,                     /* GIVEN  */
  YYSYMBOL_GRANT = 66,                     /* GRANT  */
  YYSYMBOL_GRANTS = 67,                    /* GRANTS  */
  YYSYMBOL_HAS = 68,                       /* HAS  */
  YYSYMBOL_HERSELF = 69,                   /* HERSELF  */
  YYSYMBOL_HIMSELF = 70,                   /* HIMSELF  */
  YYSYMBOL_HOUR = 71,                      /* HOUR  */
  YYSYMBOL_HOURS = 72,                     /* HOURS  */
  YYSYMBOL_IF = 73,                        /* IF  */
  YYSYMBOL_IN = 74,                        /* IN  */
  YYSYMBOL_INTO = 75,                      /* INTO  */
  YYSYMBOL_IS = 76,                        /* IS  */
  YYSYMBOL_ITSELF = 77,                    /* ITSELF  */
  YYSYMBOL_LEAST = 78,                     /* LEAST  */
  YYSYMBOL_LIES = 79,                      /* LIES  */
  YYSYMBOL_MAY = 80,                       /* MAY  */
  YYSYMBOL_MILLISECOND = 81,               /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 82,              /* MILLISECONDS  */
  YYSYMBOL_MINUTE = 83,                    /* MINUTE  */
  YYSYMBOL_MINUTES = 84,                   /* MINUTES  */
  YYSYMBOL_MONTH = 85,                     /* MONTH  */
  YYSYMBOL_MONTHS = 86,                    /* MONTHS  */
  YYSYMBOL_MYSELF = 87,                    /* MYSELF  */
  YYSYMBOL_NEITHER = 88,                   /* NEITHER  */
  YYSYMBOL_NO = 89,                        /* NO  */
  YYSYMBOL_NOR = 90,                       /* NOR  */
  YYSYMBOL_NOT = 91,                       /* NOT  */
  YYSYMBOL_NOTIFIES = 92,                  /* NOTIFIES  */
  YYSYMBOL_NOTIFY = 93,                    /* NOTIFY  */
  YYSYMBOL_NOW = 94,                       /* NOW  */
  YYSYMBOL_OF = 95,                        /* OF  */
  YYSYMBOL_OFF = 96,                       /* OFF  */
  YYSYMBOL_ON = 97,                        /* ON  */
  YYSYMBOL_ONESELF = 98,                   /* ONESELF  */
  YYSYMBOL_OR = 99,                        /* OR  */
  YYSYMBOL_OURSELVES = 100,                /* OURSELVES  */
  YYSYMBOL_PASSED = 101,                   /* PASSED  */
  YYSYMBOL_PAST = 102,                     /* PAST  */
  YYSYMBOL_PAY = 103,                      /* PAY  */
  YYSYMBOL_PAYS = 104,                     /* PAYS  */
  YYSYMBOL_PERSON = 105,                   /* PERSON  */
  YYSYMBOL_PROVIDED = 106,                 /* PROVIDED  */
  YYSYMBOL_REGISTER = 107,                 /* REGISTER  */
  YYSYMBOL_REGISTERS = 108,                /* REGISTERS  */
  YYSYMBOL_REMAINDER = 109,                /* REMAINDER  */
  YYSYMBOL_RESPECTIVE = 110,               /* RESPECTIVE  */
  YYSYMBOL_RETURN = 111,                   /* RETURN  */
  YYSYMBOL_RETURNS = 112,                  /* RETURNS  */
  YYSYMBOL_SECOND = 113,                   /* SECOND  */
  YYSYMBOL_SECONDS = 114,                  /* SECONDS  */
  YYSYMBOL_SEND = 115,                     /* SEND  */
  YYSYMBOL_SENDS = 116,                    /* SENDS  */
  YYSYMBOL_SIGNED = 117,                   /* SIGNED  */
  YYSYMBOL_SO = 118,                       /* SO  */
  YYSYMBOL_TERMINATE = 119,                /* TERMINATE  */
  YYSYMBOL_TERMINATES = 120,               /* TERMINATES  */
  YYSYMBOL_TEXT = 121,                     /* TEXT  */
  YYSYMBOL_THAT = 122,                     /* THAT  */
  YYSYMBOL_THE = 123,                      /* THE  */
  YYSYMBOL_THEMSELF = 124,                 /* THEMSELF  */
  YYSYMBOL_THEMSELVES = 125,               /* THEMSELVES  */
  YYSYMBOL_THEN = 126,                     /* THEN  */
  YYSYMBOL_THERE = 127,                    /* THERE  */
  YYSYMBOL_THEREFOR = 128,                 /* THEREFOR  */
  YYSYMBOL_THEREFORE = 129,                /* THEREFORE  */
  YYSYMBOL_THESE = 130,                    /* THESE  */
  YYSYMBOL_THIS = 131,                     /* THIS  */
  YYSYMBOL_TIME = 132,                     /* TIME  */
  YYSYMBOL_TO = 133,                       /* TO  */
  YYSYMBOL_TRUE = 134,                     /* TRUE  */
  YYSYMBOL_WAS = 135,                      /* WAS  */
  YYSYMBOL_WEEK = 136,                     /* WEEK  */
  YYSYMBOL_WEEKS = 137,                    /* WEEKS  */
  YYSYMBOL_WITH = 138,                     /* WITH  */
  YYSYMBOL_YEAR = 139,                     /* YEAR  */
  YYSYMBOL_YEARS = 140,                    /* YEARS  */
  YYSYMBOL_YES = 141,                      /* YES  */
  YYSYMBOL_YOURSELF = 142,                 /* YOURSELF  */
  YYSYMBOL_YOURSELVES = 143,               /* YOURSELVES  */
  YYSYMBOL_YYACCEPT = 144,                 /* $accept  */
  YYSYMBOL_Document = 145,                 /* Document  */
  YYSYMBOL_Head = 146,                     /* Head  */
  YYSYMBOL_Lex = 147,                      /* Lex  */
  YYSYMBOL_Lexon = 148,                    /* Lexon  */
  YYSYMBOL_Authors = 149,                  /* Authors  */
  YYSYMBOL_Comment = 150,                  /* Comment  */
  YYSYMBOL_Preamble = 151,                 /* Preamble  */
  YYSYMBOL_Terms = 152,                    /* Terms  */
  YYSYMBOL_Covenants = 153,                /* Covenants  */
  YYSYMBOL_Covenant = 154,                 /* Covenant  */
  YYSYMBOL_Provisions = 155,               /* Provisions  */
  YYSYMBOL_Definitions = 156,              /* Definitions  */
  YYSYMBOL_Definition = 157,               /* Definition  */
  YYSYMBOL_Type_Term = 158,                /* Type_Term  */
  YYSYMBOL_Type = 159,                     /* Type  */
  YYSYMBOL_Person = 160,                   /* Person  */
  YYSYMBOL_Amount = 161,                   /* Amount  */
  YYSYMBOL_Time = 162,                     /* Time  */
  YYSYMBOL_Binary = 163,                   /* Binary  */
  YYSYMBOL_Text = 164,                     /* Text  */
  YYSYMBOL_Data = 165,                     /* Data  */
  YYSYMBOL_This_Contract = 166,            /* This_Contract  */
  YYSYMBOL_All_Contracts = 167,            /* All_Contracts  */
  YYSYMBOL_This = 168,                     /* This  */
  YYSYMBOL_Clauses = 169,                  /* Clauses  */
  YYSYMBOL_Clause = 170,                   /* Clause  */
  YYSYMBOL_Body = 171,                     /* Body  */
  YYSYMBOL_Function = 172,                 /* Function  */
  YYSYMBOL_Statements = 173,               /* Statements  */
  YYSYMBOL_Statement = 174,                /* Statement  */
  YYSYMBOL_Action = 175,                   /* Action  */
  YYSYMBOL_Subject = 176,                  /* Subject  */
  YYSYMBOL_Symbols = 177,                  /* Symbols  */
  YYSYMBOL_Symbol = 178,                   /* Symbol  */
  YYSYMBOL_Catena = 179,                   /* Catena  */
  YYSYMBOL_Object = 180,                   /* Object  */
  YYSYMBOL_Reflexive = 181,                /* Reflexive  */
  YYSYMBOL_Contract = 182,                 /* Contract  */
  YYSYMBOL_Predicates = 183,               /* Predicates  */
  YYSYMBOL_Predicate = 184,                /* Predicate  */
  YYSYMBOL_Permission = 185,               /* Permission  */
  YYSYMBOL_Certification = 186,            /* Certification  */
  YYSYMBOL_Certify = 187,                  /* Certify  */
  YYSYMBOL_Declaration = 188,              /* Declaration  */
  YYSYMBOL_Declare = 189,                  /* Declare  */
  YYSYMBOL_Filing = 190,                   /* Filing  */
  YYSYMBOL_File = 191,                     /* File  */
  YYSYMBOL_Registration = 192,             /* Registration  */
  YYSYMBOL_Register = 193,                 /* Register  */
  YYSYMBOL_Grantment = 194,                /* Grantment  */
  YYSYMBOL_Grant = 195,                    /* Grant  */
  YYSYMBOL_Appointment = 196,              /* Appointment  */
  YYSYMBOL_Appoint = 197,                  /* Appoint  */
  YYSYMBOL_Fixture = 198,                  /* Fixture  */
  YYSYMBOL_Fix = 199,                      /* Fix  */
  YYSYMBOL_Fixed = 200,                    /* Fixed  */
  YYSYMBOL_Setting = 201,                  /* Setting  */
  YYSYMBOL_Illocutor = 202,                /* Illocutor  */
  YYSYMBOL_Be = 203,                       /* Be  */
  YYSYMBOL_Payment = 204,                  /* Payment  */
  YYSYMBOL_Pay = 205,                      /* Pay  */
  YYSYMBOL_Preposition = 206,              /* Preposition  */
  YYSYMBOL_Escrow = 207,                   /* Escrow  */
  YYSYMBOL_From_Escrow = 208,              /* From_Escrow  */
  YYSYMBOL_Sending = 209,                  /* Sending  */
  YYSYMBOL_Send = 210,                     /* Send  */
  YYSYMBOL_Notification = 211,             /* Notification  */
  YYSYMBOL_Notify = 212,                   /* Notify  */
  YYSYMBOL_Termination = 213,              /* Termination  */
  YYSYMBOL_Terminate = 214,                /* Terminate  */
  YYSYMBOL_Flagging = 215,                 /* Flagging  */
  YYSYMBOL_Condition = 216,                /* Condition  */
  YYSYMBOL_If = 217,                       /* If  */
  YYSYMBOL_Expression = 218,               /* Expression  */
  YYSYMBOL_Scalar_Comparison = 219,        /* Scalar_Comparison  */
  YYSYMBOL_Comparison_Operator = 220,      /* Comparison_Operator  */
  YYSYMBOL_Equal = 221,                    /* Equal  */
  YYSYMBOL_Later = 222,                    /* Later  */
  YYSYMBOL_Scalar_Expression = 223,        /* Scalar_Expression  */
  YYSYMBOL_Combination = 224,              /* Combination  */
  YYSYMBOL_Combinor = 225,                 /* Combinor  */
  YYSYMBOL_Combinand = 226,                /* Combinand  */
  YYSYMBOL_Combinator = 227,               /* Combinator  */
  YYSYMBOL_Or_ = 228,                      /* Or_  */
  YYSYMBOL_And = 229,                      /* And  */
  YYSYMBOL_Neither = 230,                  /* Neither  */
  YYSYMBOL_Nor = 231,                      /* Nor  */
  YYSYMBOL_Existence = 232,                /* Existence  */
  YYSYMBOL_Negation = 233,                 /* Negation  */
  YYSYMBOL_Negator = 234,                  /* Negator  */
  YYSYMBOL_Being = 235,                    /* Being  */
  YYSYMBOL_True = 236,                     /* True  */
  YYSYMBOL_Article = 237,                  /* Article  */
  YYSYMBOL_Point_In_Time = 238,            /* Point_In_Time  */
  YYSYMBOL_Current_Time = 239,             /* Current_Time  */
  YYSYMBOL_Relative_Time = 240,            /* Relative_Time  */
  YYSYMBOL_Duration = 241,                 /* Duration  */
  YYSYMBOL_Time_Unit = 242,                /* Time_Unit  */
  YYSYMBOL_Years = 243,                    /* Years  */
  YYSYMBOL_Months = 244,                   /* Months  */
  YYSYMBOL_Weeks = 245,                    /* Weeks  */
  YYSYMBOL_Days = 246,                     /* Days  */
  YYSYMBOL_Hours = 247,                    /* Hours  */
  YYSYMBOL_Minutes = 248,                  /* Minutes  */
  YYSYMBOL_Seconds = 249,                  /* Seconds  */
  YYSYMBOL_Milliseconds = 250,             /* Milliseconds  */
  YYSYMBOL_Expiration = 251,               /* Expiration  */
  YYSYMBOL_Name = 252,                     /* Name  */
  YYSYMBOL_Description = 253,              /* Description  */
  YYSYMBOL_Scalar = 254                    /* Scalar  */
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
#define YYLAST   2657

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  353
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  598
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   398

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
     135,   136,   137,   138,   139,   140,   141,   142,   143
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1062,  1062,  1063,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1090,  1096,  1102,  1103,  1109,  1110,  1116,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1135,  1136,  1142,  1143,  1144,
    1145,  1151,  1152,  1153,  1154,  1160,  1161,  1167,  1168,  1169,
    1170,  1176,  1177,  1183,  1184,  1185,  1186,  1187,  1188,  1194,
    1200,  1206,  1212,  1218,  1224,  1230,  1231,  1237,  1243,  1244,
    1250,  1251,  1257,  1263,  1264,  1270,  1271,  1272,  1273,  1279,
    1280,  1286,  1287,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1309,  1315,  1316,  1322,  1323,  1324,
    1325,  1331,  1332,  1338,  1339,  1340,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1361,  1362,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,
    1380,  1381,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1404,  1410,  1411,  1412,  1413,  1414,
    1420,  1421,  1427,  1428,  1429,  1430,  1431,  1437,  1438,  1444,
    1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,  1459,
    1460,  1466,  1467,  1468,  1469,  1470,  1476,  1477,  1483,  1489,
    1490,  1496,  1502,  1503,  1509,  1510,  1511,  1517,  1518,  1524,
    1530,  1531,  1532,  1533,  1534,  1535,  1541,  1542,  1543,  1544,
    1550,  1551,  1557,  1558,  1559,  1560,  1566,  1567,  1568,  1569,
    1575,  1576,  1582,  1583,  1584,  1585,  1591,  1592,  1593,  1594,
    1600,  1606,  1607,  1613,  1619,  1620,  1626,  1627,  1633,  1634,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1653,  1654,
    1655,  1661,  1662,  1663,  1669,  1675,  1681,  1682,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1696,  1702,  1703,  1704,
    1705,  1711,  1712,  1713,  1719,  1720,  1721,  1727,  1728,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1746,  1747,  1748,  1749,
    1755,  1761,  1767,  1773,  1779,  1780,  1781,  1782,  1788,  1789,
    1790,  1791,  1797,  1798,  1799,  1800,  1806,  1807,  1808,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1828,  1829,
    1830,  1836,  1837,  1843,  1844,  1845,  1846,  1847,  1853,  1854,
    1855,  1856,  1857,  1863,  1869,  1870,  1871,  1872,  1873,  1874,
    1875,  1876,  1882,  1883,  1889,  1890,  1896,  1897,  1903,  1904,
    1910,  1911,  1917,  1918,  1924,  1925,  1931,  1932,  1938,  1939,
    1940,  1944,  1947,  1950
};
#endif

#define YYPACT_NINF (-386)
#define YYTABLE_NINF (-264)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    57,    64,   161,   432,    75,  -386,     5,    75,    37,
      95,  -386,  -386,  -386,    15,  -386,   249,  -386,   123,   158,
     160,   162,   169,   172,   175,   445,   186,   166,  -386,  -386,
     202,  -386,   198,     5,   205,  -386,    96,    75,   192,    15,
    -386,   212,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
      80,   149,   207,  -386,  1161,  -386,  -386,  2457,     3,  -386,
    1266,    10,  -386,   253,  -386,    75,   219,   219,   219,   219,
     219,   219,   186,   166,  -386,   166,  -386,  -386,  -386,   159,
    -386,   145,     5,  -386,   232,    75,  -386,    75,  1291,  -386,
    -386,  -386,   207,  -386,   403,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
      18,  -386,  1559,  -386,  1270,  -386,  1270,  -386,  1204,  -386,
    1270,  -386,  1515,  -386,  1515,  -386,  1270,  -386,  1094,  -386,
     942,  -386,  1127,  -386,   404,  -386,    20,  -386,  -386,  1515,
    1375,  1515,   248,  -386,   222,  -386,  -386,   262,  -386,   278,
     282,   291,   295,   307,   308,   166,  -386,  -386,  -386,   609,
       5,  -386,  -386,   215,   310,   318,  1428,  1515,   323,  -386,
    2095,  2377,   206,  -386,  -386,    49,  1639,  1127,   286,  -386,
    -386,   990,  1454,   631,  1476,  1270,   655,   805,  1079,  1507,
    -386,  -386,   292,   299,  1319,  1515,  1515,  -386,  -386,  -386,
      74,   239,   241,  -386,  -386,  -386,  -386,   256,   -29,   120,
    1926,   120,   -58,   -51,  1127,   -49,  -386,  1965,  -386,   340,
     234,  -386,  -386,  1515,  2004,  -386,  -386,    84,  -386,  -386,
       8,   -51,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,   -51,  -386,  -386,  -386,  -386,  1515,
     350,   352,  -386,  -386,   287,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,   363,  -386,   365,   243,  -386,     5,  -386,   343,
     784,  1515,   368,   375,  -386,  2537,  1841,   264,  -386,   238,
    1719,  -386,  -386,  1740,  2537,   240,     9,  -386,  1127,  -386,
    1515,  -386,   347,  -386,  1515,  -386,   679,   808,   349,  -386,
     351,  -386,  1127,  -386,  1515,  -386,  1127,  1515,  1515,  1515,
    -386,  -386,  -386,  -386,   294,   -19,  -386,  -386,   268,   255,
    -386,   298,   -37,   353,  1350,  1515,   342,   265,  -386,    -6,
     329,  -386,   339,   339,   163,  -386,  1350,  1515,  -386,  -386,
    -386,  -386,   404,   -51,   404,   -51,  -386,  -386,  -386,  -386,
      14,   379,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  1397,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,   854,  -386,  -386,  -386,
    -386,  1127,  -386,  -386,  -386,  -386,  -386,  1515,   293,  1515,
     404,  1127,   408,  -386,  -386,   609,  -386,  -386,  -386,  -386,
       5,  -386,    75,  -386,  -386,  1232,   454,   414,  -386,  -386,
    -386,  2537,  2175,   306,   290,  -386,  2255,  -386,  1820,  2537,
     252,  2537,   257,   263,  -386,   300,  -386,  -386,  -386,  1127,
    -386,   388,  -386,   393,  -386,  1127,  1515,  -386,  -386,  -386,
    -386,  -386,  -386,   312,  -386,   341,   381,  -386,   315,   321,
     394,   324,  -386,  -386,   309,  -386,  -386,   314,  -386,  -386,
    -386,  -386,  -386,  -386,   392,   361,  -386,  -386,  -386,  -386,
    -386,  -386,   404,  -386,   404,   -35,    29,  -386,  1574,  -386,
    -386,  1127,  -386,  -386,   366,  -386,  -386,  -386,  -386,   462,
     467,  -386,   463,    75,  -386,  -386,  2537,   357,  -386,  2276,
    2537,  2537,  -386,  2537,   266,   284,  -386,   288,  -386,  -386,
    -386,  -386,  1127,  1515,  -386,  -386,   415,   364,  -386,   424,
    -386,   356,  -386,  -386,  -386,  -386,   387,  -386,  -386,  -386,
     411,  -386,   418,  -386,  1515,  -386,  -386,    80,   483,  -386,
    2356,  2537,  -386,  -386,  -386,   303,  -386,  -386,  -386,  -386,
    -386,  -386,   441,  -386,  -386,  -386,  -386,  -386,  -386,   493,
      80,  2537,  -386,  -386,  -386,  -386,  1127,   497,   543,  -386,
     503,  -386,  1127,   504,  -386,   508,  -386,  -386
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     0,
       0,   308,   309,   310,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   351,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,     0,    60,   200,    62,    64,   201,    59,    63,    69,
      68,    61,    46,    99,    53,    54,    55,    56,    57,    58,
       0,     0,    42,    70,    43,    79,    81,     0,    94,    95,
       0,   196,    82,     0,    97,     0,     0,     0,     0,     0,
       0,     0,    16,    14,    13,    10,     9,     7,    20,     0,
      32,     0,     0,    29,     0,     0,    36,     0,     0,    65,
      66,    71,    44,    80,     0,   182,   183,   151,   150,   157,
     158,   169,   170,   187,   188,   179,   180,   144,   225,   224,
     206,   207,   176,   177,   208,   209,   221,   222,   228,   229,
       0,   131,     0,   132,     0,   133,     0,   134,     0,   135,
       0,   136,     0,   137,     0,   138,     0,   139,     0,   140,
       0,   141,     0,   142,     0,   143,     0,   102,   101,     0,
       0,     0,     0,   197,   198,   100,    98,     0,   352,     0,
       0,     0,     0,     0,     0,    18,    17,    15,    11,     0,
       0,    33,    30,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   241,   243,     0,     0,     0,     0,   116,
     117,   145,     0,   152,     0,     0,   159,     0,   171,     0,
     178,   181,   184,     0,     0,     0,     0,   190,   353,   212,
       0,     0,   201,   294,   292,   317,   349,     0,   310,     0,
     269,     0,     0,     0,     0,     0,   271,     0,   244,   264,
     267,   273,   272,     0,   274,   311,   312,     0,   275,   262,
     310,     0,   105,   108,   109,   111,   106,   110,   113,   112,
     115,   107,   114,   103,     0,   104,   226,   227,    96,     0,
       0,     0,   230,   199,     0,    22,    23,    24,    25,    21,
      26,    19,     0,    51,     0,     0,    34,     0,    37,     0,
       0,     0,     0,     0,   234,     0,     0,     0,   118,     0,
       0,   242,    84,     0,     0,     0,   238,    67,     0,   146,
       0,   148,     0,   153,     0,   155,   162,     0,     0,   160,
       0,   165,     0,   172,     0,   174,     0,     0,     0,     0,
     193,   191,   192,   216,     0,     0,   348,   350,     0,     0,
     214,     0,     0,     0,     0,     0,   254,   248,   250,     0,
     296,   298,     0,     0,     0,   270,     0,     0,   295,   293,
     211,   210,     0,     0,     0,     0,   338,   339,   340,   341,
     251,     0,   346,   347,   342,   343,   334,   335,   344,   345,
     336,   337,   332,   333,     0,   246,   247,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,   281,   282,   283,
     280,     0,   276,   277,   278,   279,   288,     0,     0,   318,
       0,     0,     0,   232,   231,     0,    47,    49,    52,    38,
       0,    39,     0,    72,    74,    73,     0,     0,   236,   235,
     119,     0,     0,     0,     0,   122,     0,    89,     0,     0,
       0,     0,     0,     0,    85,     0,   239,   147,   149,     0,
     156,     0,   163,     0,   167,     0,     0,   173,   175,   185,
     186,   194,   195,     0,   218,     0,     0,   313,     0,     0,
       0,     0,   285,   290,   255,   249,   297,   252,   189,   284,
     289,   303,   301,   302,   304,     0,   299,   300,   287,   286,
     291,   205,     0,   202,     0,     0,     0,   261,   245,   263,
     265,     0,   268,   322,     0,   319,   220,   223,   233,     0,
       0,    40,     0,     0,   237,   123,     0,     0,   126,     0,
       0,     0,   120,     0,     0,     0,    90,     0,    87,    86,
     240,   154,     0,     0,   161,   166,     0,     0,   213,     0,
     315,     0,   314,   256,   253,   305,   306,   203,   204,   257,
       0,   259,     0,   266,   320,    48,    50,     0,     0,   127,
       0,     0,   124,   130,   121,     0,    92,    91,    88,   164,
     168,   217,     0,   215,   316,   307,   258,   260,   321,     0,
       0,     0,   128,   125,    93,   219,     0,     0,     0,   129,
       0,    75,     0,     0,    76,     0,    77,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -386,  -386,  -386,  -386,  -386,   487,    40,    -7,  -386,  -386,
     474,   140,  -386,   498,   101,   -65,  -386,  -386,  -386,  -386,
    -386,  -386,   -13,   359,  -386,   455,   -46,  -386,  -386,   231,
     -60,  -386,  -386,  -386,   -15,  -386,  -339,  -386,   100,  -122,
    -184,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,   173,  -386,   -16,   -93,
    -386,  -386,  -223,  -386,   296,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,   346,  -386,  -110,  -386,  -386,   297,  -386,   148,
    -385,   137,  -386,   146,  -386,  -386,  -386,  -386,  -386,  -386,
      -4,  -386,  -386,    70,   165,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,   313,    -3,   326,
    -386
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   282,    53,    54,    55,    56,    57,
      58,    59,   199,   200,    61,    62,    63,   423,   424,    64,
      65,    66,    67,    68,   230,   159,   264,   265,   231,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   479,   147,   148,    71,
     149,   150,   362,   233,   234,   151,   152,   153,   154,   155,
     156,    72,   196,   197,   235,   236,   384,   352,   386,   237,
     238,   239,   240,   401,   402,   403,   404,   405,   241,   242,
     243,   354,   488,   104,   244,   245,   246,   247,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   248,    74,   169,
     249
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    69,    30,    60,   103,    32,   298,   157,   165,   469,
     195,   500,   364,   445,     8,   220,   101,   339,    84,    86,
      87,   189,   190,   491,   360,   493,   360,   340,   410,    11,
       1,   358,   476,   359,    94,    12,    37,   464,    38,   165,
      33,   411,   251,   549,    98,   163,     8,   198,    70,    69,
     495,    60,   302,   190,   339,   162,   101,   232,   100,   232,
      34,    11,     5,   164,     6,    83,    85,    12,   477,   299,
     166,   506,   167,    18,   305,   176,   177,    18,   178,    18,
     341,   342,   361,   188,   361,    29,    73,   306,   550,   470,
     465,   309,   184,   313,   185,   336,   319,   343,   323,    92,
      36,   166,   158,    18,   232,     8,    18,   551,   232,   407,
     232,   430,   435,   232,   283,   232,   553,    43,   342,   201,
      11,   203,   175,   206,   363,   208,    12,   210,    13,   211,
     333,   212,    75,   217,   343,   446,   344,   232,   356,   263,
     492,   232,   494,   266,   268,   270,   271,    31,   180,    35,
      49,    50,   552,   547,     8,   548,    46,    43,   408,    29,
      13,    18,    18,    76,     7,    77,   284,    78,   281,    11,
       8,   292,   293,    90,    79,    12,    93,    80,   440,     9,
      81,   442,   443,   334,    10,    11,   409,   311,    24,   315,
     316,    12,   321,    99,   325,   481,    46,   335,   447,   330,
     331,   332,    21,    22,   482,    88,   452,    89,    24,   223,
      91,   224,   457,    95,   483,   232,   459,    97,   287,    13,
     418,   484,    41,   232,     8,   345,   353,   357,   406,   232,
     168,   181,   182,   232,   202,   179,   204,   183,   207,    11,
     209,   437,   190,   444,   190,    12,   213,   515,   518,   285,
      18,   272,   522,    18,   412,   526,   190,   273,     8,    29,
     528,   190,    75,    29,    41,   397,   529,   190,    13,   566,
     190,   274,    42,    11,    70,    69,   427,    60,    42,    12,
     485,   275,    42,    44,    13,   276,    43,   567,   190,    44,
      45,   568,   190,    44,   277,   448,    45,   486,   278,   450,
      45,   507,   454,   232,   487,   317,   584,   190,   232,   458,
     279,   280,   460,   461,   462,   289,   524,   525,   232,   527,
     286,   290,   398,   288,   399,    46,   294,   326,   301,   472,
     473,   307,   559,   400,   327,   562,   563,   564,    13,   531,
     336,   489,   490,   337,   396,   534,   420,   263,    47,   263,
     283,   338,     8,   413,    47,   414,   232,    18,    47,    18,
     426,   165,   232,   415,    48,   103,   416,    11,   417,   497,
      48,   428,    13,    12,    48,    51,   582,   583,   429,    49,
      50,    51,   436,   477,   449,    51,   455,   467,   456,   463,
    -251,   466,   503,   468,   505,   263,   474,   589,   475,   471,
     478,   565,   510,   170,   171,   172,   173,   174,   232,    70,
      69,   508,    60,    29,    29,   496,   504,   514,  -201,   512,
    -201,   520,   569,   166,   519,   532,   530,   419,    11,   421,
     533,   337,    42,    42,    12,   536,   537,   538,   539,   232,
     541,   535,   543,    44,    44,    19,    20,   544,    21,    22,
      45,    45,    23,   540,    24,   545,   542,   546,    19,    20,
     252,    21,    22,   513,    29,   555,    13,    24,   554,   587,
     556,   571,   557,   253,   254,   560,   590,   263,   593,   263,
     573,   255,   595,    42,   575,   285,   232,   572,   574,   576,
      18,   256,   580,   232,    44,   232,   577,   585,   586,   232,
     591,    45,   257,    29,   258,   218,   594,   596,    47,    47,
     558,   597,    82,    96,    52,   267,   509,    11,   570,   102,
     198,   425,    42,    12,    48,    48,   480,    13,   259,   260,
      43,   365,   498,    44,   385,    51,    51,   300,   502,   578,
      45,   579,   501,   355,     0,     0,   261,   262,   592,   499,
       0,     0,     0,    29,     0,   218,     0,     0,     0,    47,
     511,   221,     0,     0,   588,     0,     0,    11,     0,   222,
     198,     0,    42,    12,     0,    48,     0,     0,     0,     0,
      43,     0,   223,    44,   224,     0,    51,   225,     0,     0,
      45,     0,     0,     0,     0,   226,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,    48,     0,   250,     0,     0,   222,
     229,     0,     0,    49,    50,    51,     0,     0,     0,     0,
       0,     0,   223,    11,   224,     0,     0,   225,    42,    12,
       0,    29,     0,   218,     0,   226,     0,     0,    47,    44,
       0,     0,     0,     0,     0,    11,    45,     0,   198,     0,
      42,    12,     0,     0,    48,    29,   250,   218,    43,     0,
     229,    44,     0,    49,    50,    51,     0,     0,    45,    11,
       0,     0,   198,     0,    42,    12,     0,     0,     0,    29,
       0,   218,    43,     0,     0,    44,     0,     0,     0,   221,
       0,     0,    45,    11,     0,     0,   198,   222,    42,    12,
       0,     0,     0,     0,    47,     0,    43,     0,     0,    44,
     223,     0,   224,   221,     0,   225,    45,     0,     0,     0,
      48,   222,    13,   226,     0,     0,    47,     0,     0,    49,
      50,    51,     0,     0,   223,     0,   224,   221,     0,   225,
       0,     0,    48,     0,   250,   222,     0,   226,   229,     0,
      47,    49,    50,    51,   312,     0,     0,     0,   223,     0,
     224,     0,     0,   225,     0,     0,    48,     0,   250,     0,
       0,   226,   229,     0,    47,    49,    50,    51,   318,     0,
       0,     0,     0,   422,    29,     0,     0,     0,     0,     0,
      48,     0,   250,     0,     0,     0,   229,     0,    11,    49,
      50,    51,   451,    42,    12,    29,     0,     0,    29,     0,
       0,    43,     0,     0,    44,     0,     0,     0,     0,    11,
       0,    45,    11,     0,    42,    12,     0,    42,    12,     0,
       0,     0,     0,     0,     0,    44,     0,     0,    44,     0,
       0,     0,    45,     0,     0,    45,     0,     0,     0,     0,
      46,     0,     0,     0,    29,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,   198,     0,    42,    12,   397,     0,     0,     0,    47,
       0,    43,     0,     0,    44,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,    48,     0,    13,     0,     0,
      47,     0,     0,    47,    49,    50,    51,     0,     0,     0,
       0,     0,   221,     0,     0,     0,    48,     0,    13,    48,
     222,    13,     0,     0,     0,     0,     0,    51,   320,     0,
      51,   453,   398,   223,   399,   224,     0,     0,   225,     0,
       0,     0,    29,   400,   218,     0,   226,     0,     0,    47,
       0,     0,     0,     0,     0,     0,    11,     0,     0,   198,
       0,    42,    12,     0,     0,    48,     0,   250,     0,    43,
       0,   229,    44,     0,    49,    50,    51,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
      29,     0,   218,     0,     0,     0,   220,     0,     0,     0,
     221,     0,     0,     0,    11,     0,     0,   198,   222,    42,
      12,     0,     0,     0,     0,   308,     0,    43,     0,     0,
      44,   223,     0,   224,     0,     0,   225,    45,     0,     0,
       0,     0,     0,     0,   226,     0,     0,    47,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,    48,     0,   228,   222,     0,     0,   229,
       0,     0,    49,    50,    51,     0,     0,     0,     0,   223,
       0,   224,     0,     0,   225,     0,     0,     0,     0,    29,
       0,   218,   226,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    11,    29,     0,   198,     0,    42,    12,
       0,    48,     0,   250,   322,     0,    43,   229,    11,    44,
      49,    50,    51,    42,    12,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,    29,     0,   218,
       0,    45,     0,     0,     0,     0,     0,   221,     0,     0,
       0,    11,     0,     0,   198,   222,    42,    12,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    44,   223,     0,
     224,    29,     0,   225,    45,     0,    41,     0,     0,     0,
       0,   226,     0,     0,    47,    11,     0,     0,     0,     0,
      42,    12,     0,     0,     0,   221,     0,     0,    43,    47,
      48,    44,   250,   222,     0,     0,   229,     0,    45,    49,
      50,    51,     0,     0,    29,    48,   223,    13,   224,     0,
     214,   225,   215,   216,     0,     0,    51,     0,    11,   226,
       0,   198,    47,    42,    12,     0,     0,    46,     0,     0,
       0,     0,    29,     0,    44,     0,     0,     0,    48,     0,
     250,    45,     0,     0,   229,     0,    11,    49,    50,    51,
       0,    42,    12,     0,     0,     0,    47,   205,     0,    43,
       0,     0,    44,     0,     0,     0,    29,     0,     0,    45,
      29,     0,    48,     0,    13,     0,     0,     0,     0,     0,
      11,    49,    50,    51,    11,    42,    12,   198,     0,    42,
      12,    29,     0,     0,     0,     0,    44,     0,    46,    47,
      44,     0,     0,    45,     0,    11,     0,    45,     0,     0,
      42,    12,     0,     0,     0,    48,     0,    13,     0,    29,
       0,    44,     0,     0,    49,    50,    51,    47,    45,     0,
       0,     0,     0,    11,     0,     0,     0,     0,    42,    12,
       0,     0,     0,    48,     0,    13,     0,     0,     0,    44,
      29,     0,    49,    50,    51,     0,    45,     0,     0,     0,
       0,    47,     0,     0,    11,    47,     0,     0,     0,    42,
      12,     0,     0,     0,     0,    29,     0,    48,     0,    13,
      44,    48,   160,    13,     0,   161,    47,    45,    51,    11,
      49,    50,    51,     0,    42,    12,     0,    29,     0,   218,
       0,     0,    48,     0,    13,    44,     0,   186,     0,     0,
     187,    11,    45,    51,    47,     0,    42,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    29,   358,
      48,   359,    13,     0,    45,     0,     0,   328,   329,     0,
       0,    51,    11,     0,     0,    47,     0,    42,    12,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    44,     0,
       0,    48,     0,    13,     0,    45,     0,     0,    11,     0,
      47,     0,    51,    42,    12,     0,    29,     0,     0,   310,
       0,   225,     0,     0,    44,     0,    48,     0,    13,     0,
      11,    45,    47,     0,   269,    42,    12,    51,     0,     0,
       0,   314,     0,     0,     0,     0,    44,    29,    48,     0,
     250,     0,     0,    45,     0,    29,     0,     0,     0,    51,
       0,    11,     0,    47,     0,     0,    42,    12,     0,    11,
       0,     0,   324,     0,    42,    12,     0,    44,     0,    48,
       0,    13,     0,     0,    45,    44,     0,   291,     0,    47,
      51,     0,    45,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    13,     0,     0,
       0,    47,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,   105,   106,     0,     0,    43,    48,     0,    13,
       0,   107,   108,     0,     0,     0,     0,     0,    51,   109,
       0,   110,    47,     0,     0,     0,   111,     0,   112,   113,
      47,   114,   366,   367,   192,   115,   116,     0,    48,     0,
      13,     0,   193,     0,     0,    46,    48,     0,    13,    51,
       0,     0,     0,   303,   304,   368,   369,    51,     0,     0,
       0,   118,   119,     0,     0,   372,   373,   374,   375,   376,
     377,     0,   120,   121,     0,   194,   122,   123,     0,     0,
     124,   125,   105,   106,   126,   127,    43,     0,   128,   129,
       0,   107,   108,     0,     0,     0,     0,   378,   379,   109,
       0,   110,     0,     0,     0,     0,   111,     0,   112,   113,
       0,   114,     0,     0,     0,   115,   116,     0,     0,     0,
     380,   381,     0,   382,   383,    46,     0,     0,     0,     0,
       0,     0,     0,   438,   439,     0,     0,     0,     0,     0,
       0,   118,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,     0,   441,   122,   123,     0,     0,
     124,   125,   105,   106,   126,   127,    43,     0,   128,   129,
       0,   107,   108,     0,     0,     0,     0,     0,     0,   109,
       0,   110,     0,   105,   106,     0,   111,    43,   112,   113,
       0,   114,   107,   108,     0,   115,   116,     0,     0,     0,
     109,     0,   110,     0,     0,    46,     0,   111,     0,   112,
     113,     0,   114,     0,     0,     0,   115,   116,     0,     0,
       0,   118,   119,     0,     0,     0,    46,     0,     0,     0,
       0,     0,   120,   121,     0,   523,   122,   123,     0,     0,
     124,   125,   118,   119,   126,   127,     0,     0,   128,   129,
       0,     0,     0,   120,   121,     0,     0,   122,   123,     0,
       0,   124,   125,   105,   106,   126,   127,    43,     0,   128,
     129,     0,   107,   108,     0,     0,     0,   431,     0,   432,
     109,     0,   110,     0,   105,   106,     0,   111,    43,   112,
     113,     0,   114,   107,   108,     0,   115,   116,     0,     0,
       0,   109,     0,   110,     0,     0,    46,     0,   111,     0,
     112,   113,     0,   114,     0,     0,     0,   115,   116,     0,
       0,     0,   118,   119,   433,     0,     0,    46,     0,     0,
       0,     0,     0,   120,   121,     0,     0,   122,   123,     0,
       0,   124,   125,   118,   119,   126,   127,     0,     0,   128,
     129,     0,     0,     0,   120,   121,     0,     0,   122,   123,
       0,     0,   124,   125,     0,     0,   126,   127,     0,     0,
     128,   129,     0,    43,     0,   346,     0,     0,     0,     0,
       0,     0,     0,     0,  -261,  -261,     0,     0,     0,   434,
     347,   348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,  -261,  -261,     0,
       0,     0,   350,     0,   346,  -261,     0,  -261,  -261,  -261,
    -261,  -261,  -261,   366,   367,   223,     0,   224,     0,   347,
     348,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   368,   369,     0,  -261,
    -261,   370,     0,  -263,   371,     0,   372,   373,   374,   375,
     376,   377,  -263,  -263,     0,     0,     0,     0,  -263,  -263,
       0,   351,  -261,  -261,     0,  -261,  -261,     0,     0,     0,
       0,     0,     0,     0,     0,  -263,  -263,     0,   378,   379,
    -263,     0,     0,  -263,     0,  -263,  -263,  -263,  -263,  -263,
    -263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,     0,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -263,  -263,     0,
       0,   295,     0,     0,     0,     0,   296,     0,   105,   106,
       0,     0,    43,     0,     0,     0,     0,   107,   108,     0,
    -263,  -263,     0,  -263,  -263,   109,     0,   110,     0,     0,
       0,     0,   111,     0,   112,   113,     0,   114,     0,     0,
       0,   115,   116,     0,     0,     0,     0,     0,   297,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
       0,   516,   122,   123,     0,     0,   124,   125,   105,   106,
     126,   127,    43,     0,   128,   129,     0,   107,   108,     0,
       0,     0,     0,     0,     0,   109,     0,   110,     0,     0,
       0,     0,   111,     0,   112,   113,     0,   114,     0,     0,
       0,   115,   116,     0,     0,     0,     0,     0,   517,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
       0,   521,   122,   123,     0,     0,   124,   125,   105,   106,
     126,   127,    43,     0,   128,   129,     0,   107,   108,     0,
       0,     0,   561,     0,     0,   109,     0,   110,     0,   105,
     106,     0,   111,    43,   112,   113,     0,   114,   107,   108,
       0,   115,   116,     0,     0,     0,   109,     0,   110,     0,
       0,    46,     0,   111,     0,   112,   113,     0,   114,     0,
       0,     0,   115,   116,     0,     0,     0,   118,   119,     0,
       0,     0,    46,     0,     0,     0,     0,     0,   120,   121,
       0,     0,   122,   123,     0,     0,   124,   125,   118,   119,
     126,   127,     0,     0,   128,   129,     0,     0,     0,   120,
     121,     0,   581,   122,   123,     0,     0,   124,   125,   105,
     106,   126,   127,    43,     0,   128,   129,     0,   107,   108,
       0,     0,     0,     0,     0,     0,   109,     0,   110,     0,
     105,   106,     0,   111,    43,   112,   113,     0,   114,   107,
     108,     0,   115,   116,     0,     0,     0,   109,     0,   110,
       0,     0,    46,     0,   111,     0,   112,   113,     0,   114,
       0,     0,   192,   115,   116,     0,     0,     0,   118,   119,
     193,     0,     0,    46,     0,     0,     0,     0,     0,   120,
     121,     0,     0,   122,   123,     0,     0,   124,   125,   118,
     119,   126,   127,     0,     0,   128,   129,     0,     0,     0,
     120,   121,     0,   194,   122,   123,     0,     0,   124,   125,
     105,   106,   126,   127,    43,     0,   128,   129,     0,   107,
     108,     0,     0,     0,     0,     0,     0,   109,     0,   110,
       0,     0,     0,     0,   111,     0,   112,   113,     0,   114,
       0,     0,     0,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,   122,   123,     0,     0,   124,   125,
     105,   106,   126,   127,    43,     0,   128,   129,     0,   107,
     108,     0,     0,     0,     0,     0,     0,   109,     0,   110,
       0,     0,     0,     0,   111,     0,   112,   113,     0,   114,
       0,     0,     0,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,   122,   123,     0,     0,   124,   125,
       0,     0,   126,   127,     0,     0,   128,   129
};

static const yytype_int16 yycheck[] =
{
      16,    16,     5,    16,    64,     8,   190,     4,    73,    46,
     132,   396,   235,     4,     9,    64,    62,    46,    25,    26,
      27,     3,     4,   362,    75,   364,    75,    56,   251,    24,
      19,    89,    38,    91,    37,    30,    21,    56,    23,   104,
       3,   264,   152,    78,    60,    35,     9,    27,    64,    64,
      36,    64,     3,     4,    46,    70,   102,   150,    61,   152,
      23,    24,     5,    53,     0,    25,    26,    30,    54,   191,
      73,   410,    75,     3,   196,    82,    83,     7,    85,     9,
     109,   110,   133,    98,   133,    10,    16,   197,   123,   126,
     109,   201,    95,   203,    97,   101,   206,   126,   208,     3,
       5,   104,    99,    33,   197,     9,    36,    78,   201,    25,
     203,   295,   296,   206,   179,   208,   501,    37,   110,   134,
      24,   136,    82,   138,   234,   140,    30,   142,   123,   144,
      56,   146,     9,   148,   126,   126,   229,   230,   231,   154,
     363,   234,   365,   156,   159,   160,   161,     7,     3,     9,
     130,   131,   123,   492,     9,   494,    76,    37,    74,    10,
     123,    91,    92,     5,     3,     5,   179,     5,   175,    24,
       9,   186,   187,    33,     5,    30,    36,     5,   300,    18,
       5,   303,   304,   109,    23,    24,   102,   202,    22,   204,
     205,    30,   207,    44,   209,    32,    76,   123,   308,   214,
     215,   216,    16,    17,    41,     3,   316,     9,    22,    89,
       5,    91,   322,    21,    51,   308,   326,     5,     3,   123,
     285,    58,    15,   316,     9,   229,   230,   231,   243,   322,
      11,    91,    92,   326,   134,    76,   136,     5,   138,    24,
     140,     3,     4,     3,     4,    30,   146,   431,   432,   179,
     180,     3,   436,   183,   269,     3,     4,    35,     9,    10,
       3,     4,     9,    10,    15,    31,     3,     4,   123,     3,
       4,     9,    29,    24,   290,   290,   291,   290,    29,    30,
     117,     3,    29,    40,   123,     3,    37,     3,     4,    40,
      47,     3,     4,    40,     3,   310,    47,   134,     3,   314,
      47,   411,   317,   396,   141,   205,     3,     4,   401,   324,
       3,     3,   327,   328,   329,     5,   438,   439,   411,   441,
     180,     3,    88,   183,    90,    76,     3,    35,   122,   344,
     345,    45,   516,    99,    35,   519,   520,   521,   123,   449,
     101,   356,   357,   102,     4,   455,     3,   362,   105,   364,
     415,    95,     9,     3,   105,     3,   449,   287,   105,   289,
     290,   426,   455,    76,   121,   425,     3,    24,     3,   384,
     121,     3,   123,    30,   121,   132,   560,   561,     3,   130,
     131,   132,   118,    54,    37,   132,    37,   132,    37,    95,
      61,   123,   407,    95,   409,   410,    54,   581,   133,    46,
      61,   523,   415,    77,    78,    79,    80,    81,   501,   425,
     425,     3,   425,    10,    10,    36,   123,     3,    89,   422,
      91,   131,   532,   426,   118,    37,   126,   287,    24,   289,
      37,   102,    29,    29,    30,   123,    95,    56,   123,   532,
      46,   456,   133,    40,    40,    13,    14,   133,    16,    17,
      47,    47,    20,   132,    22,    63,   132,    96,    13,    14,
      56,    16,    17,     9,    10,     3,   123,    22,   102,   579,
       3,    56,     9,    69,    70,   118,   586,   492,   588,   494,
      56,    77,   592,    29,    97,   415,   579,   123,   132,    78,
     420,    87,     9,   586,    40,   588,    78,    56,     5,   592,
       3,    47,    98,    10,   100,    12,     3,     3,   105,   105,
     513,     3,    25,    39,    16,   156,   415,    24,   533,    64,
      27,   290,    29,    30,   121,   121,   353,   123,   124,   125,
      37,   235,   384,    40,   237,   132,   132,   191,   401,   554,
      47,   557,   396,   230,    -1,    -1,   142,   143,     5,   384,
      -1,    -1,    -1,    10,    -1,    12,    -1,    -1,    -1,   105,
     420,    68,    -1,    -1,   580,    -1,    -1,    24,    -1,    76,
      27,    -1,    29,    30,    -1,   121,    -1,    -1,    -1,    -1,
      37,    -1,    89,    40,    91,    -1,   132,    94,    -1,    -1,
      47,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,   121,    -1,   123,    -1,    -1,    76,
     127,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    24,    91,    -1,    -1,    94,    29,    30,
      -1,    10,    -1,    12,    -1,   102,    -1,    -1,   105,    40,
      -1,    -1,    -1,    -1,    -1,    24,    47,    -1,    27,    -1,
      29,    30,    -1,    -1,   121,    10,   123,    12,    37,    -1,
     127,    40,    -1,   130,   131,   132,    -1,    -1,    47,    24,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    10,
      -1,    12,    37,    -1,    -1,    40,    -1,    -1,    -1,    68,
      -1,    -1,    47,    24,    -1,    -1,    27,    76,    29,    30,
      -1,    -1,    -1,    -1,   105,    -1,    37,    -1,    -1,    40,
      89,    -1,    91,    68,    -1,    94,    47,    -1,    -1,    -1,
     121,    76,   123,   102,    -1,    -1,   105,    -1,    -1,   130,
     131,   132,    -1,    -1,    89,    -1,    91,    68,    -1,    94,
      -1,    -1,   121,    -1,   123,    76,    -1,   102,   127,    -1,
     105,   130,   131,   132,   133,    -1,    -1,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,   121,    -1,   123,    -1,
      -1,   102,   127,    -1,   105,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,   127,    -1,    24,   130,
     131,   132,   133,    29,    30,    10,    -1,    -1,    10,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    24,
      -1,    47,    24,    -1,    29,    30,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    40,    -1,
      -1,    -1,    47,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,   105,
      -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,   121,    -1,   123,    -1,    -1,
     105,    -1,    -1,   105,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,   121,    -1,   123,   121,
      76,   123,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
     132,   133,    88,    89,    90,    91,    -1,    -1,    94,    -1,
      -1,    -1,    10,    99,    12,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,   121,    -1,   123,    -1,    37,
      -1,   127,    40,    -1,   130,   131,   132,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      10,    -1,    12,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    24,    -1,    -1,    27,    76,    29,
      30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,
      40,    89,    -1,    91,    -1,    -1,    94,    47,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,   121,    -1,   123,    76,    -1,    -1,   127,
      -1,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,    89,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    -1,    10,
      -1,    12,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    10,    -1,    27,    -1,    29,    30,
      -1,   121,    -1,   123,    35,    -1,    37,   127,    24,    40,
     130,   131,   132,    29,    30,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    10,    -1,    12,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    24,    -1,    -1,    27,    76,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    89,    -1,
      91,    10,    -1,    94,    47,    -1,    15,    -1,    -1,    -1,
      -1,   102,    -1,    -1,   105,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    68,    -1,    -1,    37,   105,
     121,    40,   123,    76,    -1,    -1,   127,    -1,    47,   130,
     131,   132,    -1,    -1,    10,   121,    89,   123,    91,    -1,
     126,    94,   128,   129,    -1,    -1,   132,    -1,    24,   102,
      -1,    27,   105,    29,    30,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    10,    -1,    40,    -1,    -1,    -1,   121,    -1,
     123,    47,    -1,    -1,   127,    -1,    24,   130,   131,   132,
      -1,    29,    30,    -1,    -1,    -1,   105,    63,    -1,    37,
      -1,    -1,    40,    -1,    -1,    -1,    10,    -1,    -1,    47,
      10,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      24,   130,   131,   132,    24,    29,    30,    27,    -1,    29,
      30,    10,    -1,    -1,    -1,    -1,    40,    -1,    76,   105,
      40,    -1,    -1,    47,    -1,    24,    -1,    47,    -1,    -1,
      29,    30,    -1,    -1,    -1,   121,    -1,   123,    -1,    10,
      -1,    40,    -1,    -1,   130,   131,   132,   105,    47,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    40,
      10,    -1,   130,   131,   132,    -1,    47,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    24,   105,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    10,    -1,   121,    -1,   123,
      40,   121,   126,   123,    -1,   129,   105,    47,   132,    24,
     130,   131,   132,    -1,    29,    30,    -1,    10,    -1,    12,
      -1,    -1,   121,    -1,   123,    40,    -1,   126,    -1,    -1,
     129,    24,    47,   132,   105,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    10,    89,
     121,    91,   123,    -1,    47,    -1,    -1,   128,   129,    -1,
      -1,   132,    24,    -1,    -1,   105,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    40,    -1,
      -1,   121,    -1,   123,    -1,    47,    -1,    -1,    24,    -1,
     105,    -1,   132,    29,    30,    -1,    10,    -1,    -1,    35,
      -1,    94,    -1,    -1,    40,    -1,   121,    -1,   123,    -1,
      24,    47,   105,    -1,   129,    29,    30,   132,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    40,    10,   121,    -1,
     123,    -1,    -1,    47,    -1,    10,    -1,    -1,    -1,   132,
      -1,    24,    -1,   105,    -1,    -1,    29,    30,    -1,    24,
      -1,    -1,    35,    -1,    29,    30,    -1,    40,    -1,   121,
      -1,   123,    -1,    -1,    47,    40,    -1,   129,    -1,   105,
     132,    -1,    47,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    37,   121,    -1,   123,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,   132,    50,
      -1,    52,   105,    -1,    -1,    -1,    57,    -1,    59,    60,
     105,    62,    48,    49,    65,    66,    67,    -1,   121,    -1,
     123,    -1,    73,    -1,    -1,    76,   121,    -1,   123,   132,
      -1,    -1,    -1,     4,     5,    71,    72,   132,    -1,    -1,
      -1,    92,    93,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,   103,   104,    -1,   106,   107,   108,    -1,    -1,
     111,   112,    33,    34,   115,   116,    37,    -1,   119,   120,
      -1,    42,    43,    -1,    -1,    -1,    -1,   113,   114,    50,
      -1,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
     136,   137,    -1,   139,   140,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,    -1,     5,   107,   108,    -1,    -1,
     111,   112,    33,    34,   115,   116,    37,    -1,   119,   120,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    -1,    33,    34,    -1,    57,    37,    59,    60,
      -1,    62,    42,    43,    -1,    66,    67,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    76,    -1,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,   103,   104,    -1,     5,   107,   108,    -1,    -1,
     111,   112,    92,    93,   115,   116,    -1,    -1,   119,   120,
      -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,   111,   112,    33,    34,   115,   116,    37,    -1,   119,
     120,    -1,    42,    43,    -1,    -1,    -1,    26,    -1,    28,
      50,    -1,    52,    -1,    33,    34,    -1,    57,    37,    59,
      60,    -1,    62,    42,    43,    -1,    66,    67,    -1,    -1,
      -1,    50,    -1,    52,    -1,    -1,    76,    -1,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    92,    93,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,   111,   112,    92,    93,   115,   116,    -1,    -1,   119,
     120,    -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
     119,   120,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,   138,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    39,    79,    -1,    81,    82,    83,
      84,    85,    86,    48,    49,    89,    -1,    91,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,   113,
     114,    76,    -1,    39,    79,    -1,    81,    82,    83,    84,
      85,    86,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,   113,   114,
      76,    -1,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,    -1,
     136,   137,    -1,   139,   140,    50,    -1,    52,    -1,    -1,
      -1,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    26,   107,   108,    -1,    -1,   111,   112,    33,    34,
     115,   116,    37,    -1,   119,   120,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,
      -1,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    26,   107,   108,    -1,    -1,   111,   112,    33,    34,
     115,   116,    37,    -1,   119,   120,    -1,    42,    43,    -1,
      -1,    -1,    26,    -1,    -1,    50,    -1,    52,    -1,    33,
      34,    -1,    57,    37,    59,    60,    -1,    62,    42,    43,
      -1,    66,    67,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    76,    -1,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,   111,   112,    92,    93,
     115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,   103,
     104,    -1,    26,   107,   108,    -1,    -1,   111,   112,    33,
      34,   115,   116,    37,    -1,   119,   120,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      33,    34,    -1,    57,    37,    59,    60,    -1,    62,    42,
      43,    -1,    66,    67,    -1,    -1,    -1,    50,    -1,    52,
      -1,    -1,    76,    -1,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    92,    93,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,   111,   112,    92,
      93,   115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,
     103,   104,    -1,   106,   107,   108,    -1,    -1,   111,   112,
      33,    34,   115,   116,    37,    -1,   119,   120,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,   111,   112,
      33,    34,   115,   116,    37,    -1,   119,   120,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,   111,   112,
      -1,    -1,   115,   116,    -1,    -1,   119,   120
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,   145,   146,   147,     5,     0,     3,     9,    18,
      23,    24,    30,   123,   152,   155,   156,   157,   237,    13,
      14,    16,    17,    20,    22,   148,   149,   150,   151,    10,
     252,   155,   252,     3,    23,   155,     5,    21,    23,   153,
     154,    15,    29,    37,    40,    47,    76,   105,   121,   130,
     131,   132,   157,   159,   160,   161,   162,   163,   164,   165,
     166,   168,   169,   170,   173,   174,   175,   176,   177,   178,
     202,   203,   215,   237,   252,     9,     5,     5,     5,     5,
       5,     5,   149,   150,   151,   150,   151,   151,     3,     9,
     155,     5,     3,   155,   252,    21,   154,     5,   202,    44,
     252,   170,   169,   174,   237,    33,    34,    42,    43,    50,
      52,    57,    59,    60,    62,    66,    67,    80,    92,    93,
     103,   104,   107,   108,   111,   112,   115,   116,   119,   120,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   201,   202,   204,
     205,   209,   210,   211,   212,   213,   214,     4,    99,   179,
     126,   129,   178,    35,    53,   159,   252,   252,    11,   253,
     253,   253,   253,   253,   253,   150,   151,   151,   151,    76,
       3,   155,   155,     5,   252,   252,   126,   129,   178,     3,
       4,     4,    65,    73,   106,   183,   216,   217,    27,   166,
     167,   178,   182,   178,   182,    63,   178,   182,   178,   182,
     178,   178,   178,   182,   126,   128,   129,   178,    12,    56,
      64,    68,    76,    89,    91,    94,   102,   109,   123,   127,
     178,   182,   203,   207,   208,   218,   219,   223,   224,   225,
     226,   232,   233,   234,   238,   239,   240,   241,   251,   254,
     123,   218,    56,    69,    70,    77,    87,    98,   100,   124,
     125,   142,   143,   178,   180,   181,   166,   167,   178,   129,
     178,   178,     3,    35,     9,     3,     3,     3,     3,     3,
       3,   151,   158,   159,   166,   237,   155,     3,   155,     5,
       3,   129,   178,   178,     3,    26,    31,    73,   184,   183,
     216,   122,     3,     4,     5,   183,   218,    45,    35,   218,
      35,   178,   133,   218,    35,   178,   178,   182,   133,   218,
     133,   178,    35,   218,    35,   178,    35,    35,   128,   129,
     178,   178,   178,    56,   109,   123,   101,   102,    95,    46,
      56,   109,   110,   126,   203,   234,    39,    54,    55,    68,
      76,   135,   221,   234,   235,   251,   203,   234,    89,    91,
      75,   133,   206,   218,   206,   208,    48,    49,    71,    72,
      76,    79,    81,    82,    83,    84,    85,    86,   113,   114,
     136,   137,   139,   140,   220,   221,   222,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     4,    31,    88,    90,
      99,   227,   228,   229,   230,   231,   178,    25,    74,   102,
     206,   206,   178,     3,     3,    76,     3,     3,   159,   155,
       3,   155,     9,   171,   172,   173,   237,   178,     3,     3,
     184,    26,    28,    73,   138,   184,   118,     3,     4,     5,
     183,     5,   183,   183,     3,     4,   126,   218,   178,    37,
     178,   133,   218,   133,   178,    37,    37,   218,   178,   218,
     178,   178,   178,    95,    56,   109,   123,   132,    95,    46,
     126,    46,   178,   178,    54,   133,    38,    54,    61,   200,
     200,    32,    41,    51,    58,   117,   134,   141,   236,   178,
     178,   180,   206,   180,   206,    36,    36,   178,   223,   238,
     224,   227,   225,   178,   123,   178,   180,   218,     3,   158,
     166,   155,   252,     9,     3,   184,    26,    73,   184,   118,
     131,    26,   184,     5,   183,   183,     3,   183,     3,     3,
     126,   218,    37,    37,   218,   178,   123,    95,    56,   123,
     132,    46,   132,   133,   133,    63,    96,   180,   180,    78,
     123,    78,   123,   224,   102,     3,     3,     9,   252,   184,
     118,    26,   184,   184,   184,   183,     3,     3,     3,   218,
     178,    56,   123,    56,   132,    97,    78,    78,   178,   202,
       9,    26,   184,   184,     3,    56,     5,   218,   202,   184,
     218,     3,     5,   218,     3,   218,     3,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   148,   149,   149,   150,   150,   151,   152,   152,   152,
     152,   152,   152,   152,   152,   153,   153,   154,   154,   154,
     154,   155,   155,   155,   155,   156,   156,   157,   157,   157,
     157,   158,   158,   159,   159,   159,   159,   159,   159,   160,
     161,   162,   163,   164,   165,   166,   166,   167,   168,   168,
     169,   169,   170,   171,   171,   172,   172,   172,   172,   173,
     173,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   177,   177,   178,   178,   178,
     178,   179,   179,   180,   180,   180,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   182,   182,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   185,   186,   186,   186,   186,   186,
     187,   187,   188,   188,   188,   188,   188,   189,   189,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   191,
     191,   192,   192,   192,   192,   192,   193,   193,   194,   195,
     195,   196,   197,   197,   198,   198,   198,   199,   199,   200,
     201,   201,   201,   201,   201,   201,   202,   202,   202,   202,
     203,   203,   204,   204,   204,   204,   205,   205,   205,   205,
     206,   206,   207,   207,   207,   207,   208,   208,   208,   208,
     209,   210,   210,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   215,   215,   215,   215,   215,   215,   216,   216,
     216,   217,   217,   217,   218,   219,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   222,   222,   222,
     222,   223,   223,   223,   224,   224,   224,   225,   225,   226,
     226,   226,   226,   226,   226,   226,   227,   227,   227,   227,
     228,   229,   230,   231,   232,   232,   232,   232,   233,   233,
     233,   233,   234,   234,   234,   234,   235,   235,   235,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   237,   237,
     237,   238,   238,   239,   239,   239,   239,   239,   240,   240,
     240,   240,   240,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     247,   247,   248,   248,   249,   249,   250,   250,   251,   251,
     251,   252,   253,   254
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
       6,     7,     7,     8,     1,     1,     3,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       5,     6,     4,     5,     6,     7,     5,     6,     7,     8,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     4,
       1,     1,     2,     3,     5,     3,     4,     1,     1,     2,
       3,     5,     3,     4,     6,     3,     5,     4,     6,     1,
       1,     2,     3,     4,     3,     4,     1,     1,     2,     1,
       1,     2,     1,     1,     2,     4,     4,     1,     1,     1,
       2,     3,     3,     3,     4,     4,     1,     2,     2,     3,
       1,     1,     4,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     5,     2,     5,     3,     6,
       4,     1,     1,     4,     1,     1,     2,     2,     1,     1,
       3,     4,     4,     5,     4,     5,     5,     6,     2,     3,
       4,     1,     2,     1,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     3,     1,     2,     3,     3,     4,     3,
       4,     1,     1,     1,     1,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     3,
       3,     3,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     1,
       1,     1,     1,     3,     4,     4,     5,     1,     2,     3,
       4,     5,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1
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
       0,     0,     0,     0
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
       0,     0,     0,     0
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
       0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   269,     0,   261,     0,   261,     0,   261,     0,   261,
     269,     0,   264,     0,   274,     0,   238,     0
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
  "LEXON", "PER", "PREAMBLE", "TERMS", "A", "AFTER", "AFTERWARDS", "ALL",
  "ALSO", "AMOUNT", "AN", "AND", "ANNOUNCED", "APPOINT", "APPOINTS", "AS",
  "AT", "BE", "BEEN", "BEING", "BINARY", "CERTIFIED", "CERTIFIES",
  "CERTIFY", "CONTRACT", "CONTRACTS", "CURRENT", "DATA", "DAY", "DAYS",
  "DECLARE", "DECLARED", "DECLARES", "DEFINED", "EQUAL", "EQUALING",
  "ESCROW", "FILE_", "FILED", "FILES", "FIX", "FIXED", "FIXES", "FOR",
  "FROM", "GIVEN", "GRANT", "GRANTS", "HAS", "HERSELF", "HIMSELF", "HOUR",
  "HOURS", "IF", "IN", "INTO", "IS", "ITSELF", "LEAST", "LIES", "MAY",
  "MILLISECOND", "MILLISECONDS", "MINUTE", "MINUTES", "MONTH", "MONTHS",
  "MYSELF", "NEITHER", "NO", "NOR", "NOT", "NOTIFIES", "NOTIFY", "NOW",
  "OF", "OFF", "ON", "ONESELF", "OR", "OURSELVES", "PASSED", "PAST", "PAY",
  "PAYS", "PERSON", "PROVIDED", "REGISTER", "REGISTERS", "REMAINDER",
  "RESPECTIVE", "RETURN", "RETURNS", "SECOND", "SECONDS", "SEND", "SENDS",
  "SIGNED", "SO", "TERMINATE", "TERMINATES", "TEXT", "THAT", "THE",
  "THEMSELF", "THEMSELVES", "THEN", "THERE", "THEREFOR", "THEREFORE",
  "THESE", "THIS", "TIME", "TO", "TRUE", "WAS", "WEEK", "WEEKS", "WITH",
  "YEAR", "YEARS", "YES", "YOURSELF", "YOURSELVES", "$accept", "Document",
  "Head", "Lex", "Lexon", "Authors", "Comment", "Preamble", "Terms",
  "Covenants", "Covenant", "Provisions", "Definitions", "Definition",
  "Type_Term", "Type", "Person", "Amount", "Time", "Binary", "Text",
  "Data", "This_Contract", "All_Contracts", "This", "Clauses", "Clause",
  "Body", "Function", "Statements", "Statement", "Action", "Subject",
  "Symbols", "Symbol", "Catena", "Object", "Reflexive", "Contract",
  "Predicates", "Predicate", "Permission", "Certification", "Certify",
  "Declaration", "Declare", "Filing", "File", "Registration", "Register",
  "Grantment", "Grant", "Appointment", "Appoint", "Fixture", "Fix",
  "Fixed", "Setting", "Illocutor", "Be", "Payment", "Pay", "Preposition",
  "Escrow", "From_Escrow", "Sending", "Send", "Notification", "Notify",
  "Termination", "Terminate", "Flagging", "Condition", "If", "Expression",
  "Scalar_Comparison", "Comparison_Operator", "Equal", "Later",
  "Scalar_Expression", "Combination", "Combinor", "Combinand",
  "Combinator", "Or_", "And", "Neither", "Nor", "Existence", "Negation",
  "Negator", "Being", "True", "Article", "Point_In_Time", "Current_Time",
  "Relative_Time", "Duration", "Time_Unit", "Years", "Months", "Weeks",
  "Days", "Hours", "Minutes", "Seconds", "Milliseconds", "Expiration",
  "Name", "Description", "Scalar", YY_NULLPTR
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
#line 1062 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 2465 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1063 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 2471 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1069 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 2477 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1070 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2483 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1071 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2489 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1072 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2495 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1073 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 2501 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1074 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2507 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1075 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2513 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1076 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2519 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1077 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 2525 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1078 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2531 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1079 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2537 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1080 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2543 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1081 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 2549 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1082 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2555 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1083 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2561 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1084 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2567 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1090 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 2573 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1096 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 2579 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1102 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 2585 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1103 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 2591 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1109 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 2597 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1110 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 2603 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1116 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 2609 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1122 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2615 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1123 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2621 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1124 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2627 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1125 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2633 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1126 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2639 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1127 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2645 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1128 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2651 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1129 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2657 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1135 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 2663 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1136 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 2669 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1142 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2675 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1143 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2681 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1144 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2687 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1145 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2693 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1151 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2699 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1152 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2705 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1153 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2711 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1154 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2717 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1160 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 2723 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1161 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 2729 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1167 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2735 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1168 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2741 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1169 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2747 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1170 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2753 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1176 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 2759 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1177 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 2765 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1183 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 2771 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1184 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 2777 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1185 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 2783 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1186 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 2789 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1187 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 2795 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1188 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 2801 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1194 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 2807 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1200 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 2813 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1206 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 2819 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1212 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 2825 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1218 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 2831 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1224 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 2837 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1230 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 2843 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1231 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 2849 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1237 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 2855 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1243 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 2861 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1244 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 2867 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1250 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 2873 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1251 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 2879 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1257 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 2885 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1263 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 2891 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1264 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 2897 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1270 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 2903 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1271 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 2909 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1272 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 2915 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1273 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 2921 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1279 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 2927 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1280 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 2933 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1286 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 2939 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1287 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 2945 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1293 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2951 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1294 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2957 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Predicates Separator  */
#line 1295 "parser.y"
                                                                    { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2963 "parser.c"
    break;

  case 86: /* Action: Subject Permission Condition Colon Predicates Separator  */
#line 1296 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2969 "parser.c"
    break;

  case 87: /* Action: Subject Permission Condition Comma Predicates Separator  */
#line 1297 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2975 "parser.c"
    break;

  case 88: /* Action: Subject Permission Condition Comma Colon Predicates Separator  */
#line 1298 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2981 "parser.c"
    break;

  case 89: /* Action: Subject Permission Comma Predicates Separator  */
#line 1299 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2987 "parser.c"
    break;

  case 90: /* Action: Subject Permission Comma Condition Predicates Separator  */
#line 1300 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2993 "parser.c"
    break;

  case 91: /* Action: Subject Permission Comma Condition Colon Predicates Separator  */
#line 1301 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 2999 "parser.c"
    break;

  case 92: /* Action: Subject Permission Comma Condition Comma Predicates Separator  */
#line 1302 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3005 "parser.c"
    break;

  case 93: /* Action: Subject Permission Comma Condition Comma Colon Predicates Separator  */
#line 1303 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3011 "parser.c"
    break;

  case 94: /* Subject: Symbols  */
#line 1309 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3017 "parser.c"
    break;

  case 95: /* Symbols: Symbol  */
#line 1315 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3023 "parser.c"
    break;

  case 96: /* Symbols: Symbols Catena Symbol  */
#line 1316 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3029 "parser.c"
    break;

  case 97: /* Symbol: Name  */
#line 1322 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3035 "parser.c"
    break;

  case 98: /* Symbol: Article Name  */
#line 1323 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3041 "parser.c"
    break;

  case 99: /* Symbol: Type  */
#line 1324 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3047 "parser.c"
    break;

  case 100: /* Symbol: Article Type  */
#line 1325 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3053 "parser.c"
    break;

  case 101: /* Catena: OR  */
#line 1331 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3059 "parser.c"
    break;

  case 102: /* Catena: Comma  */
#line 1332 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3065 "parser.c"
    break;

  case 103: /* Object: Symbol  */
#line 1338 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3071 "parser.c"
    break;

  case 104: /* Object: Reflexive  */
#line 1339 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3077 "parser.c"
    break;

  case 105: /* Object: ESCROW  */
#line 1340 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3083 "parser.c"
    break;

  case 106: /* Reflexive: MYSELF  */
#line 1346 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3089 "parser.c"
    break;

  case 107: /* Reflexive: YOURSELF  */
#line 1347 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3095 "parser.c"
    break;

  case 108: /* Reflexive: HERSELF  */
#line 1348 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3101 "parser.c"
    break;

  case 109: /* Reflexive: HIMSELF  */
#line 1349 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3107 "parser.c"
    break;

  case 110: /* Reflexive: ONESELF  */
#line 1350 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3113 "parser.c"
    break;

  case 111: /* Reflexive: ITSELF  */
#line 1351 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3119 "parser.c"
    break;

  case 112: /* Reflexive: THEMSELF  */
#line 1352 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3125 "parser.c"
    break;

  case 113: /* Reflexive: OURSELVES  */
#line 1353 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3131 "parser.c"
    break;

  case 114: /* Reflexive: YOURSELVES  */
#line 1354 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3137 "parser.c"
    break;

  case 115: /* Reflexive: THEMSELVES  */
#line 1355 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3143 "parser.c"
    break;

  case 116: /* Contract: This_Contract  */
#line 1361 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3149 "parser.c"
    break;

  case 117: /* Contract: All_Contracts  */
#line 1362 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3155 "parser.c"
    break;

  case 118: /* Predicates: Predicates Comma Predicate  */
#line 1368 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3161 "parser.c"
    break;

  case 119: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1369 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3167 "parser.c"
    break;

  case 120: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1370 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3173 "parser.c"
    break;

  case 121: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1371 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3179 "parser.c"
    break;

  case 122: /* Predicates: Predicates Comma AND Predicate  */
#line 1372 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3185 "parser.c"
    break;

  case 123: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1373 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3191 "parser.c"
    break;

  case 124: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1374 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3197 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1375 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3203 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1376 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3209 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1377 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3215 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1378 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3221 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1379 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3227 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1380 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3233 "parser.c"
    break;

  case 131: /* Predicates: Predicate  */
#line 1381 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3239 "parser.c"
    break;

  case 132: /* Predicate: Certification  */
#line 1387 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3245 "parser.c"
    break;

  case 133: /* Predicate: Declaration  */
#line 1388 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3251 "parser.c"
    break;

  case 134: /* Predicate: Filing  */
#line 1389 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3257 "parser.c"
    break;

  case 135: /* Predicate: Registration  */
#line 1390 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3263 "parser.c"
    break;

  case 136: /* Predicate: Grantment  */
#line 1391 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3269 "parser.c"
    break;

  case 137: /* Predicate: Appointment  */
#line 1392 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3275 "parser.c"
    break;

  case 138: /* Predicate: Fixture  */
#line 1393 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3281 "parser.c"
    break;

  case 139: /* Predicate: Setting  */
#line 1394 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3287 "parser.c"
    break;

  case 140: /* Predicate: Payment  */
#line 1395 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3293 "parser.c"
    break;

  case 141: /* Predicate: Sending  */
#line 1396 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3299 "parser.c"
    break;

  case 142: /* Predicate: Notification  */
#line 1397 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3305 "parser.c"
    break;

  case 143: /* Predicate: Termination  */
#line 1398 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3311 "parser.c"
    break;

  case 144: /* Permission: MAY  */
#line 1404 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 3317 "parser.c"
    break;

  case 145: /* Certification: Certify Symbol  */
#line 1410 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3323 "parser.c"
    break;

  case 146: /* Certification: Certify Symbol Expression  */
#line 1411 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3329 "parser.c"
    break;

  case 147: /* Certification: Certify Symbol AS Expression  */
#line 1412 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3335 "parser.c"
    break;

  case 148: /* Certification: Certify Contract Symbol  */
#line 1413 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3341 "parser.c"
    break;

  case 149: /* Certification: Certify Contract AS Symbol  */
#line 1414 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3347 "parser.c"
    break;

  case 150: /* Certify: CERTIFY  */
#line 1420 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3353 "parser.c"
    break;

  case 151: /* Certify: CERTIFIES  */
#line 1421 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3359 "parser.c"
    break;

  case 152: /* Declaration: Declare Symbol  */
#line 1427 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3365 "parser.c"
    break;

  case 153: /* Declaration: Declare Symbol Expression  */
#line 1428 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3371 "parser.c"
    break;

  case 154: /* Declaration: Declare Symbol TO BE Expression  */
#line 1429 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3377 "parser.c"
    break;

  case 155: /* Declaration: Declare Contract Symbol  */
#line 1430 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3383 "parser.c"
    break;

  case 156: /* Declaration: Declare Contract AS Symbol  */
#line 1431 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3389 "parser.c"
    break;

  case 157: /* Declare: DECLARE  */
#line 1437 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 3395 "parser.c"
    break;

  case 158: /* Declare: DECLARES  */
#line 1438 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 3401 "parser.c"
    break;

  case 159: /* Filing: File Symbol  */
#line 1444 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3407 "parser.c"
    break;

  case 160: /* Filing: File Symbol Expression  */
#line 1445 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3413 "parser.c"
    break;

  case 161: /* Filing: File Symbol TO BE Expression  */
#line 1446 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3419 "parser.c"
    break;

  case 162: /* Filing: File FOR Symbol  */
#line 1447 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3425 "parser.c"
    break;

  case 163: /* Filing: File FOR Symbol Expression  */
#line 1448 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3431 "parser.c"
    break;

  case 164: /* Filing: File FOR Symbol TO BE Expression  */
#line 1449 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3437 "parser.c"
    break;

  case 165: /* Filing: File Contract Symbol  */
#line 1450 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3443 "parser.c"
    break;

  case 166: /* Filing: File Contract TO BE Symbol  */
#line 1451 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3449 "parser.c"
    break;

  case 167: /* Filing: File FOR Contract Symbol  */
#line 1452 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3455 "parser.c"
    break;

  case 168: /* Filing: File FOR Contract TO BE Symbol  */
#line 1453 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3461 "parser.c"
    break;

  case 169: /* File: FILE_  */
#line 1459 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 3467 "parser.c"
    break;

  case 170: /* File: FILES  */
#line 1460 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 3473 "parser.c"
    break;

  case 171: /* Registration: Register Symbol  */
#line 1466 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3479 "parser.c"
    break;

  case 172: /* Registration: Register Symbol Expression  */
#line 1467 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3485 "parser.c"
    break;

  case 173: /* Registration: Register Symbol AS Expression  */
#line 1468 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3491 "parser.c"
    break;

  case 174: /* Registration: Register Contract Symbol  */
#line 1469 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3497 "parser.c"
    break;

  case 175: /* Registration: Register Contract AS Symbol  */
#line 1470 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3503 "parser.c"
    break;

  case 176: /* Register: REGISTER  */
#line 1476 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 3509 "parser.c"
    break;

  case 177: /* Register: REGISTERS  */
#line 1477 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 3515 "parser.c"
    break;

  case 178: /* Grantment: Grant Symbol  */
#line 1483 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 3521 "parser.c"
    break;

  case 179: /* Grant: GRANT  */
#line 1489 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 3527 "parser.c"
    break;

  case 180: /* Grant: GRANTS  */
#line 1490 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 3533 "parser.c"
    break;

  case 181: /* Appointment: Appoint Symbol  */
#line 1496 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 3539 "parser.c"
    break;

  case 182: /* Appoint: APPOINT  */
#line 1502 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 3545 "parser.c"
    break;

  case 183: /* Appoint: APPOINTS  */
#line 1503 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 3551 "parser.c"
    break;

  case 184: /* Fixture: Fix Symbol  */
#line 1509 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3557 "parser.c"
    break;

  case 185: /* Fixture: Fix Symbol AS Expression  */
#line 1510 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3563 "parser.c"
    break;

  case 186: /* Fixture: Fix Contract AS Symbol  */
#line 1511 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3569 "parser.c"
    break;

  case 187: /* Fix: FIX  */
#line 1517 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 3575 "parser.c"
    break;

  case 188: /* Fix: FIXES  */
#line 1518 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 3581 "parser.c"
    break;

  case 189: /* Fixed: FIXED  */
#line 1524 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 3587 "parser.c"
    break;

  case 190: /* Setting: Illocutor Symbol  */
#line 1530 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3593 "parser.c"
    break;

  case 191: /* Setting: Illocutor THEREFOR Symbol  */
#line 1531 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3599 "parser.c"
    break;

  case 192: /* Setting: Illocutor THEREFORE Symbol  */
#line 1532 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3605 "parser.c"
    break;

  case 193: /* Setting: Illocutor THEN Symbol  */
#line 1533 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3611 "parser.c"
    break;

  case 194: /* Setting: Illocutor THEN THEREFOR Symbol  */
#line 1534 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3617 "parser.c"
    break;

  case 195: /* Setting: Illocutor THEN THEREFORE Symbol  */
#line 1535 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3623 "parser.c"
    break;

  case 196: /* Illocutor: Be  */
#line 1541 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3629 "parser.c"
    break;

  case 197: /* Illocutor: Be AS  */
#line 1542 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3635 "parser.c"
    break;

  case 198: /* Illocutor: Be DEFINED  */
#line 1543 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3641 "parser.c"
    break;

  case 199: /* Illocutor: Be DEFINED AS  */
#line 1544 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3647 "parser.c"
    break;

  case 200: /* Be: BE  */
#line 1550 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 3653 "parser.c"
    break;

  case 201: /* Be: IS  */
#line 1551 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 3659 "parser.c"
    break;

  case 202: /* Payment: Pay Expression Preposition Object  */
#line 1557 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3665 "parser.c"
    break;

  case 203: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1558 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3671 "parser.c"
    break;

  case 204: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1559 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3677 "parser.c"
    break;

  case 205: /* Payment: Pay Escrow Preposition Object  */
#line 1560 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3683 "parser.c"
    break;

  case 206: /* Pay: PAY  */
#line 1566 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3689 "parser.c"
    break;

  case 207: /* Pay: PAYS  */
#line 1567 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3695 "parser.c"
    break;

  case 208: /* Pay: RETURN  */
#line 1568 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3701 "parser.c"
    break;

  case 209: /* Pay: RETURNS  */
#line 1569 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3707 "parser.c"
    break;

  case 210: /* Preposition: TO  */
#line 1575 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 3713 "parser.c"
    break;

  case 211: /* Preposition: INTO  */
#line 1576 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 3719 "parser.c"
    break;

  case 212: /* Escrow: ESCROW  */
#line 1582 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3725 "parser.c"
    break;

  case 213: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1583 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3731 "parser.c"
    break;

  case 214: /* Escrow: THE ESCROW  */
#line 1584 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3737 "parser.c"
    break;

  case 215: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1585 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3743 "parser.c"
    break;

  case 216: /* From_Escrow: FROM ESCROW  */
#line 1591 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3749 "parser.c"
    break;

  case 217: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1592 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3755 "parser.c"
    break;

  case 218: /* From_Escrow: FROM THE ESCROW  */
#line 1593 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3761 "parser.c"
    break;

  case 219: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1594 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3767 "parser.c"
    break;

  case 220: /* Sending: Send Expression Preposition Object  */
#line 1600 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 3773 "parser.c"
    break;

  case 221: /* Send: SEND  */
#line 1606 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 3779 "parser.c"
    break;

  case 222: /* Send: SENDS  */
#line 1607 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 3785 "parser.c"
    break;

  case 223: /* Notification: Notify Object Preposition Expression  */
#line 1613 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 3791 "parser.c"
    break;

  case 224: /* Notify: NOTIFY  */
#line 1619 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 3797 "parser.c"
    break;

  case 225: /* Notify: NOTIFIES  */
#line 1620 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 3803 "parser.c"
    break;

  case 226: /* Termination: Terminate This_Contract  */
#line 1626 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 3809 "parser.c"
    break;

  case 227: /* Termination: Terminate All_Contracts  */
#line 1627 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 3815 "parser.c"
    break;

  case 228: /* Terminate: TERMINATE  */
#line 1633 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 3821 "parser.c"
    break;

  case 229: /* Terminate: TERMINATES  */
#line 1634 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 3827 "parser.c"
    break;

  case 230: /* Flagging: Illocutor Symbol Separator  */
#line 1640 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3833 "parser.c"
    break;

  case 231: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1641 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3839 "parser.c"
    break;

  case 232: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1642 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3845 "parser.c"
    break;

  case 233: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1643 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3851 "parser.c"
    break;

  case 234: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1644 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3857 "parser.c"
    break;

  case 235: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1645 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3863 "parser.c"
    break;

  case 236: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1646 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3869 "parser.c"
    break;

  case 237: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1647 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3875 "parser.c"
    break;

  case 238: /* Condition: If Expression  */
#line 1653 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 3881 "parser.c"
    break;

  case 239: /* Condition: If Expression THEN  */
#line 1654 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 3887 "parser.c"
    break;

  case 240: /* Condition: If Expression Comma THEN  */
#line 1655 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 3893 "parser.c"
    break;

  case 241: /* If: IF  */
#line 1661 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 3899 "parser.c"
    break;

  case 242: /* If: GIVEN THAT  */
#line 1662 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 3905 "parser.c"
    break;

  case 243: /* If: PROVIDED  */
#line 1663 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 3911 "parser.c"
    break;

  case 244: /* Expression: Combination  */
#line 1669 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 3917 "parser.c"
    break;

  case 245: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1675 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 3923 "parser.c"
    break;

  case 246: /* Comparison_Operator: Equal  */
#line 1681 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 3929 "parser.c"
    break;

  case 247: /* Comparison_Operator: Later  */
#line 1682 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 3935 "parser.c"
    break;

  case 248: /* Equal: EQUAL  */
#line 1688 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3941 "parser.c"
    break;

  case 249: /* Equal: EQUAL TO  */
#line 1689 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3947 "parser.c"
    break;

  case 250: /* Equal: EQUALING  */
#line 1690 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3953 "parser.c"
    break;

  case 251: /* Equal: IS  */
#line 1691 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3959 "parser.c"
    break;

  case 252: /* Equal: IS EQUAL  */
#line 1692 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3965 "parser.c"
    break;

  case 253: /* Equal: IS EQUAL TO  */
#line 1693 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3971 "parser.c"
    break;

  case 254: /* Equal: BEING  */
#line 1694 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3977 "parser.c"
    break;

  case 255: /* Equal: BEING EQUAL  */
#line 1695 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3983 "parser.c"
    break;

  case 256: /* Equal: BEING EQUAL TO  */
#line 1696 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 3989 "parser.c"
    break;

  case 257: /* Later: IS AT LEAST  */
#line 1702 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 3995 "parser.c"
    break;

  case 258: /* Later: IS AT THE LEAST  */
#line 1703 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4001 "parser.c"
    break;

  case 259: /* Later: LIES AT LEAST  */
#line 1704 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4007 "parser.c"
    break;

  case 260: /* Later: LIES AT THE LEAST  */
#line 1705 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4013 "parser.c"
    break;

  case 261: /* Scalar_Expression: Symbol  */
#line 1711 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4019 "parser.c"
    break;

  case 262: /* Scalar_Expression: Scalar  */
#line 1712 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4025 "parser.c"
    break;

  case 263: /* Scalar_Expression: Point_In_Time  */
#line 1713 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4031 "parser.c"
    break;

  case 264: /* Combination: Combinor  */
#line 1719 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4037 "parser.c"
    break;

  case 265: /* Combination: Combinor Comma Combination  */
#line 1720 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4043 "parser.c"
    break;

  case 266: /* Combination: Combinor Comma Combinator Combination  */
#line 1721 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4049 "parser.c"
    break;

  case 267: /* Combinor: Combinand  */
#line 1727 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 4055 "parser.c"
    break;

  case 268: /* Combinor: Combinand Combinator Combinor  */
#line 1728 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 4061 "parser.c"
    break;

  case 269: /* Combinand: Symbol  */
#line 1734 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4067 "parser.c"
    break;

  case 270: /* Combinand: Symbol Expiration  */
#line 1735 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4073 "parser.c"
    break;

  case 271: /* Combinand: Scalar_Comparison  */
#line 1736 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4079 "parser.c"
    break;

  case 272: /* Combinand: Negation  */
#line 1737 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4085 "parser.c"
    break;

  case 273: /* Combinand: Existence  */
#line 1738 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4091 "parser.c"
    break;

  case 274: /* Combinand: Point_In_Time  */
#line 1739 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4097 "parser.c"
    break;

  case 275: /* Combinand: Expiration  */
#line 1740 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4103 "parser.c"
    break;

  case 276: /* Combinator: Or_  */
#line 1746 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4109 "parser.c"
    break;

  case 277: /* Combinator: And  */
#line 1747 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4115 "parser.c"
    break;

  case 278: /* Combinator: Neither  */
#line 1748 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4121 "parser.c"
    break;

  case 279: /* Combinator: Nor  */
#line 1749 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4127 "parser.c"
    break;

  case 280: /* Or_: OR  */
#line 1755 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 4133 "parser.c"
    break;

  case 281: /* And: AND  */
#line 1761 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 4139 "parser.c"
    break;

  case 282: /* Neither: NEITHER  */
#line 1767 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 4145 "parser.c"
    break;

  case 283: /* Nor: NOR  */
#line 1773 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 4151 "parser.c"
    break;

  case 284: /* Existence: Symbol Equal Fixed  */
#line 1779 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4157 "parser.c"
    break;

  case 285: /* Existence: THERE Be Symbol  */
#line 1780 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4163 "parser.c"
    break;

  case 286: /* Existence: Contract Be Symbol  */
#line 1781 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4169 "parser.c"
    break;

  case 287: /* Existence: Symbol Being True  */
#line 1782 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4175 "parser.c"
    break;

  case 288: /* Negation: Negator Symbol  */
#line 1788 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4181 "parser.c"
    break;

  case 289: /* Negation: Symbol Negator Fixed  */
#line 1789 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4187 "parser.c"
    break;

  case 290: /* Negation: THERE Negator Symbol  */
#line 1790 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4193 "parser.c"
    break;

  case 291: /* Negation: Contract Negator Symbol  */
#line 1791 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4199 "parser.c"
    break;

  case 292: /* Negator: NOT  */
#line 1797 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4205 "parser.c"
    break;

  case 293: /* Negator: Be NOT  */
#line 1798 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4211 "parser.c"
    break;

  case 294: /* Negator: NO  */
#line 1799 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4217 "parser.c"
    break;

  case 295: /* Negator: Be NO  */
#line 1800 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4223 "parser.c"
    break;

  case 296: /* Being: IS  */
#line 1806 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4229 "parser.c"
    break;

  case 297: /* Being: HAS BEEN  */
#line 1807 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4235 "parser.c"
    break;

  case 298: /* Being: WAS  */
#line 1808 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4241 "parser.c"
    break;

  case 299: /* True: TRUE  */
#line 1814 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4247 "parser.c"
    break;

  case 300: /* True: YES  */
#line 1815 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4253 "parser.c"
    break;

  case 301: /* True: CERTIFIED  */
#line 1816 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4259 "parser.c"
    break;

  case 302: /* True: DECLARED  */
#line 1817 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4265 "parser.c"
    break;

  case 303: /* True: ANNOUNCED  */
#line 1818 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4271 "parser.c"
    break;

  case 304: /* True: FILED  */
#line 1819 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4277 "parser.c"
    break;

  case 305: /* True: FILED FOR  */
#line 1820 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4283 "parser.c"
    break;

  case 306: /* True: SIGNED OFF  */
#line 1821 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4289 "parser.c"
    break;

  case 307: /* True: SIGNED OFF ON  */
#line 1822 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4295 "parser.c"
    break;

  case 308: /* Article: A  */
#line 1828 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4301 "parser.c"
    break;

  case 309: /* Article: AN  */
#line 1829 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4307 "parser.c"
    break;

  case 310: /* Article: THE  */
#line 1830 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4313 "parser.c"
    break;

  case 311: /* Point_In_Time: Current_Time  */
#line 1836 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 4319 "parser.c"
    break;

  case 312: /* Point_In_Time: Relative_Time  */
#line 1837 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 4325 "parser.c"
    break;

  case 313: /* Current_Time: THE CURRENT TIME  */
#line 1843 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4331 "parser.c"
    break;

  case 314: /* Current_Time: THE THEN CURRENT TIME  */
#line 1844 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4337 "parser.c"
    break;

  case 315: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 1845 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4343 "parser.c"
    break;

  case 316: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 1846 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4349 "parser.c"
    break;

  case 317: /* Current_Time: NOW  */
#line 1847 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4355 "parser.c"
    break;

  case 318: /* Relative_Time: Duration PAST  */
#line 1853 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4361 "parser.c"
    break;

  case 319: /* Relative_Time: Duration PAST Symbol  */
#line 1854 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4367 "parser.c"
    break;

  case 320: /* Relative_Time: Duration IN THE PAST  */
#line 1855 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4373 "parser.c"
    break;

  case 321: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 1856 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4379 "parser.c"
    break;

  case 322: /* Relative_Time: Duration AFTER Symbol  */
#line 1857 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4385 "parser.c"
    break;

  case 323: /* Duration: Scalar_Expression Time_Unit  */
#line 1863 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 4391 "parser.c"
    break;

  case 324: /* Time_Unit: Years  */
#line 1869 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4397 "parser.c"
    break;

  case 325: /* Time_Unit: Months  */
#line 1870 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4403 "parser.c"
    break;

  case 326: /* Time_Unit: Weeks  */
#line 1871 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4409 "parser.c"
    break;

  case 327: /* Time_Unit: Days  */
#line 1872 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4415 "parser.c"
    break;

  case 328: /* Time_Unit: Hours  */
#line 1873 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4421 "parser.c"
    break;

  case 329: /* Time_Unit: Minutes  */
#line 1874 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4427 "parser.c"
    break;

  case 330: /* Time_Unit: Seconds  */
#line 1875 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4433 "parser.c"
    break;

  case 331: /* Time_Unit: Milliseconds  */
#line 1876 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4439 "parser.c"
    break;

  case 332: /* Years: YEAR  */
#line 1882 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 4445 "parser.c"
    break;

  case 333: /* Years: YEARS  */
#line 1883 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 4451 "parser.c"
    break;

  case 334: /* Months: MONTH  */
#line 1889 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 4457 "parser.c"
    break;

  case 335: /* Months: MONTHS  */
#line 1890 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 4463 "parser.c"
    break;

  case 336: /* Weeks: WEEK  */
#line 1896 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 4469 "parser.c"
    break;

  case 337: /* Weeks: WEEKS  */
#line 1897 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 4475 "parser.c"
    break;

  case 338: /* Days: DAY  */
#line 1903 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 4481 "parser.c"
    break;

  case 339: /* Days: DAYS  */
#line 1904 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 4487 "parser.c"
    break;

  case 340: /* Hours: HOUR  */
#line 1910 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 4493 "parser.c"
    break;

  case 341: /* Hours: HOURS  */
#line 1911 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 4499 "parser.c"
    break;

  case 342: /* Minutes: MINUTE  */
#line 1917 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 4505 "parser.c"
    break;

  case 343: /* Minutes: MINUTES  */
#line 1918 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 4511 "parser.c"
    break;

  case 344: /* Seconds: SECOND  */
#line 1924 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 4517 "parser.c"
    break;

  case 345: /* Seconds: SECONDS  */
#line 1925 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 4523 "parser.c"
    break;

  case 346: /* Milliseconds: MILLISECOND  */
#line 1931 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 4529 "parser.c"
    break;

  case 347: /* Milliseconds: MILLISECONDS  */
#line 1932 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 4535 "parser.c"
    break;

  case 348: /* Expiration: HAS PASSED  */
#line 1938 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4541 "parser.c"
    break;

  case 349: /* Expiration: PAST  */
#line 1939 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4547 "parser.c"
    break;

  case 350: /* Expiration: IS PAST  */
#line 1940 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4553 "parser.c"
    break;

  case 351: /* Name: NAME  */
#line 1944 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 4559 "parser.c"
    break;

  case 352: /* Description: DESCRIPTION  */
#line 1947 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 4565 "parser.c"
    break;

  case 353: /* Scalar: SCALAR  */
#line 1950 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 4571 "parser.c"
    break;


#line 4575 "parser.c"

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




#line 1955 "parser.y"


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

