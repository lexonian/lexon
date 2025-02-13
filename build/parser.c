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
#define YYLAST   3042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  359
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  604
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
       0,  1065,  1065,  1066,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1093,  1099,  1105,  1106,  1112,  1113,  1119,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1138,  1139,  1145,  1146,  1147,
    1148,  1154,  1155,  1156,  1157,  1163,  1164,  1170,  1171,  1172,
    1173,  1179,  1180,  1186,  1187,  1188,  1189,  1190,  1191,  1197,
    1203,  1209,  1215,  1221,  1227,  1233,  1234,  1240,  1246,  1247,
    1253,  1254,  1260,  1266,  1267,  1273,  1274,  1275,  1276,  1282,
    1283,  1289,  1290,  1296,  1297,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1312,  1318,  1319,  1325,  1326,  1327,
    1328,  1334,  1335,  1341,  1342,  1343,  1349,  1350,  1351,  1352,
    1353,  1354,  1355,  1356,  1357,  1358,  1364,  1365,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1384,  1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,
    1398,  1399,  1400,  1401,  1407,  1413,  1414,  1415,  1416,  1417,
    1423,  1424,  1430,  1431,  1432,  1433,  1434,  1440,  1441,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1462,
    1463,  1469,  1470,  1471,  1472,  1473,  1479,  1480,  1486,  1492,
    1493,  1499,  1500,  1501,  1507,  1508,  1514,  1515,  1516,  1522,
    1523,  1529,  1535,  1536,  1537,  1538,  1539,  1540,  1546,  1547,
    1548,  1549,  1555,  1556,  1562,  1563,  1564,  1565,  1571,  1572,
    1573,  1574,  1580,  1581,  1582,  1588,  1589,  1590,  1591,  1597,
    1598,  1599,  1600,  1606,  1612,  1613,  1619,  1620,  1626,  1627,
    1633,  1634,  1640,  1641,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1660,  1661,  1662,  1668,  1669,  1670,  1676,  1682,
    1688,  1689,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1709,  1710,  1711,  1712,  1718,  1719,  1720,  1726,  1727,
    1728,  1734,  1735,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1755,  1756,  1757,  1758,  1764,  1770,  1776,  1782,
    1788,  1789,  1790,  1791,  1797,  1798,  1799,  1800,  1806,  1807,
    1808,  1809,  1815,  1816,  1817,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1837,  1838,  1839,  1845,  1846,  1852,
    1853,  1854,  1855,  1856,  1862,  1863,  1864,  1865,  1866,  1872,
    1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,  1891,  1892,
    1898,  1899,  1905,  1906,  1912,  1913,  1919,  1920,  1926,  1927,
    1933,  1934,  1940,  1941,  1947,  1948,  1949,  1953,  1956,  1959
};
#endif

#define YYPACT_NINF (-382)
#define YYTABLE_NINF (-268)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    16,    25,   357,   418,    40,  -382,    86,    40,    37,
     103,  -382,  -382,  -382,   113,  -382,   682,  -382,    38,   117,
     123,   130,   137,   163,   171,   439,   153,   136,  -382,  -382,
      54,  -382,   170,    86,   178,  -382,   100,    40,   165,   113,
    -382,   206,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
      44,    35,   183,  -382,   805,  -382,  -382,  2842,    19,  -382,
    1073,    52,  -382,    59,  -382,    40,   201,   201,   201,   201,
     201,   201,   153,   136,  -382,   136,  -382,  -382,  -382,   144,
    -382,   389,    86,  -382,   224,    40,  -382,    40,  1174,  -382,
    -382,  -382,   183,  -382,    42,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
      50,  -382,  1944,  -382,  1051,  -382,  1051,  -382,   448,  -382,
    1051,  -382,  1814,  -382,  1814,  -382,  1051,  -382,   704,  -382,
     894,  -382,  1758,  -382,  1840,  -382,   -18,  -382,  -382,  1814,
    1444,  1814,   235,  -382,   210,  -382,  -382,   232,  -382,   244,
     254,   256,   272,   283,   288,   136,  -382,  -382,  -382,  1902,
      86,  -382,  -382,   409,   290,   299,  1554,  1814,   316,  -382,
    2480,  2762,   200,  -382,  -382,   158,  2024,  1758,   285,  -382,
    -382,  1017,  1658,  1140,  1790,  1051,  1264,   203,  1388,  1868,
    -382,  1511,   297,   307,  1298,  1814,  1814,  -382,  -382,  -382,
     -32,   237,  -382,  -382,   242,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,   252,   253,  -382,  -382,   193,  -382,  -382,
    2311,  -382,   193,    66,   102,  1758,   109,  -382,  2350,  -382,
     345,    12,  -382,  -382,  1814,  2389,  -382,  -382,     2,  -382,
    -382,  -382,    27,   102,  -382,  -382,   102,  -382,  -382,  -382,
    -382,  1814,   347,   348,  -382,  -382,   280,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,   361,  -382,   369,    46,  -382,    86,
    -382,   417,   263,  1814,   373,   374,  -382,  2922,  2226,   247,
    -382,   204,  2104,  -382,  -382,  2125,  2922,   249,     6,  -382,
    1758,  -382,  1814,  -382,   341,  -382,  1814,  -382,  1634,   452,
     351,  -382,   352,  -382,  1758,  -382,  1814,  -382,  1758,  -382,
    1758,  1814,  1814,  1814,  -382,  -382,  -382,  -382,   287,   -25,
    -382,  -382,   268,   271,  -382,   295,   -28,   359,   499,  1814,
     354,   289,  -382,   -23,   294,  -382,   355,   355,   164,  -382,
     499,  1814,  -382,  -382,  -382,  -382,  -382,  1840,   102,  1840,
     102,  -382,  -382,  -382,  -382,   105,   385,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  1422,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,   771,  -382,  -382,  -382,  -382,  1758,  -382,  -382,  -382,
    -382,  -382,  1814,   300,  1814,  1840,  1758,   422,  -382,  -382,
    1902,  -382,  -382,  -382,  -382,    86,  -382,    40,  -382,  -382,
     937,   208,   424,  -382,  -382,  -382,  2922,  2560,   318,   306,
    -382,  2640,  -382,  2205,  2922,   258,  2922,   262,   264,  -382,
     319,  -382,  -382,  -382,  1758,  -382,   405,  -382,   420,  -382,
    1758,  1814,  -382,  -382,  -382,  -382,  -382,  -382,  -382,   331,
    -382,   365,   407,  -382,   342,   332,   423,   334,  -382,  -382,
     335,  -382,  -382,   337,  -382,  -382,  -382,  -382,  -382,  -382,
     411,   383,  -382,  -382,  -382,  -382,  -382,  -382,  1840,  -382,
    1840,   -43,    29,  -382,  2495,  -382,  -382,  1758,  -382,  -382,
     382,  -382,  -382,  -382,  -382,   483,   486,  -382,   481,    40,
    -382,  -382,  2922,   375,  -382,  2661,  2922,  2922,  -382,  2922,
     267,   286,  -382,   303,  -382,  -382,  -382,  -382,  1758,  1814,
    -382,  -382,   435,   371,  -382,   445,  -382,   372,  -382,  -382,
    -382,  -382,   408,  -382,  -382,  -382,   428,  -382,   429,  -382,
    1814,  -382,  -382,    44,   501,  -382,  2741,  2922,  -382,  -382,
    -382,   324,  -382,  -382,  -382,  -382,  -382,  -382,   457,  -382,
    -382,  -382,  -382,  -382,  -382,   525,    44,  2922,  -382,  -382,
    -382,  -382,  1758,   511,   648,  -382,   512,  -382,  1758,   522,
    -382,   523,  -382,  -382
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     0,
       0,   314,   315,   316,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   357,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,     0,    60,   202,    62,    64,   203,    59,    63,    69,
      68,    61,    46,    99,    53,    54,    55,    56,    57,    58,
       0,     0,    42,    70,    43,    79,    81,     0,    94,    95,
       0,   198,    82,     0,    97,     0,     0,     0,     0,     0,
       0,     0,    16,    14,    13,    10,     9,     7,    20,     0,
      32,     0,     0,    29,     0,     0,    36,     0,     0,    65,
      66,    71,    44,    80,     0,   184,   185,   151,   150,   157,
     158,   169,   170,   189,   190,   179,   180,   144,   229,   228,
     208,   209,   176,   177,   210,   211,   224,   225,   232,   233,
       0,   131,     0,   132,     0,   133,     0,   134,     0,   135,
       0,   136,     0,   137,     0,   138,     0,   139,     0,   140,
       0,   141,     0,   142,     0,   143,     0,   102,   101,     0,
       0,     0,     0,   199,   200,   100,    98,     0,   358,     0,
       0,     0,     0,     0,     0,    18,    17,    15,    11,     0,
       0,    33,    30,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   245,   247,     0,     0,     0,     0,   116,
     117,   145,     0,   152,     0,     0,   159,     0,   171,     0,
     178,   181,   186,     0,     0,     0,     0,   192,   359,   215,
       0,     0,   108,   109,   203,   111,   106,   300,   298,   323,
     110,   113,   355,     0,   316,   112,   115,     0,   107,   114,
     273,   275,     0,     0,     0,     0,     0,   277,     0,   248,
     268,   271,   279,   278,     0,   280,   317,   318,     0,   281,
     276,   266,   316,     0,   105,   103,   226,   104,   230,   231,
      96,     0,     0,     0,   234,   201,     0,    22,    23,    24,
      25,    21,    26,    19,     0,    51,     0,     0,    34,     0,
      37,     0,     0,     0,     0,     0,   238,     0,     0,     0,
     118,     0,     0,   246,    84,     0,     0,     0,   242,    67,
       0,   146,     0,   148,     0,   153,     0,   155,   162,     0,
       0,   160,     0,   165,     0,   172,     0,   174,     0,   182,
       0,     0,     0,     0,   195,   193,   194,   219,     0,     0,
     354,   356,     0,     0,   217,     0,     0,     0,     0,     0,
     258,   252,   254,     0,   302,   304,     0,     0,     0,   274,
       0,     0,   301,   299,   213,   214,   212,     0,     0,     0,
       0,   344,   345,   346,   347,   255,     0,   352,   353,   348,
     349,   340,   341,   350,   351,   342,   343,   338,   339,     0,
     250,   251,   329,   330,   331,   332,   333,   334,   335,   336,
     337,     0,   287,   288,   289,   286,     0,   282,   283,   284,
     285,   294,     0,     0,   324,     0,     0,     0,   236,   235,
       0,    47,    49,    52,    38,     0,    39,     0,    72,    74,
      73,     0,     0,   240,   239,   119,     0,     0,     0,     0,
     122,     0,    89,     0,     0,     0,     0,     0,     0,    85,
       0,   243,   147,   149,     0,   156,     0,   163,     0,   167,
       0,     0,   173,   175,   183,   187,   188,   196,   197,     0,
     221,     0,     0,   319,     0,     0,     0,     0,   291,   296,
     259,   253,   303,   256,   191,   290,   295,   309,   307,   308,
     310,     0,   305,   306,   293,   292,   297,   207,     0,   204,
       0,     0,     0,   265,   249,   267,   269,     0,   272,   328,
       0,   325,   223,   227,   237,     0,     0,    40,     0,     0,
     241,   123,     0,     0,   126,     0,     0,     0,   120,     0,
       0,     0,    90,     0,    87,    86,   244,   154,     0,     0,
     161,   166,     0,     0,   216,     0,   321,     0,   320,   260,
     257,   311,   312,   205,   206,   261,     0,   263,     0,   270,
     326,    48,    50,     0,     0,   127,     0,     0,   124,   130,
     121,     0,    92,    91,    88,   164,   168,   220,     0,   218,
     322,   313,   262,   264,   327,     0,     0,     0,   128,   125,
      93,   222,     0,     0,     0,   129,     0,    75,     0,     0,
      76,     0,    77,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -382,  -382,  -382,  -382,  -382,   502,     3,   -19,  -382,  -382,
     492,     5,  -382,   517,   114,   -62,  -382,  -382,  -382,  -382,
    -382,  -382,   -13,   386,  -382,   474,   -40,  -382,  -382,   251,
     -60,  -382,  -382,  -382,   -15,  -382,  -350,  -141,   362,   -42,
    -116,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,   184,  -382,   -16,    43,
    -382,  -382,  -230,  -382,   298,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,   367,  -382,    13,  -382,  -382,   308,  -382,   159,
    -381,   154,  -382,   160,  -382,  -382,  -382,  -382,  -382,  -382,
      -6,  -382,  -382,    23,   174,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,   326,    -3,   441,
    -382
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   284,    53,    54,    55,    56,    57,
      58,    59,   199,   200,    61,    62,    63,   428,   429,    64,
      65,    66,    67,    68,   240,   159,   266,   241,   242,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   485,   147,   148,    71,
     149,   150,   367,   244,   245,   151,   152,   153,   154,   155,
     156,    72,   196,   197,   246,   247,   389,   356,   391,   248,
     249,   250,   251,   406,   407,   408,   409,   410,   252,   253,
     254,   358,   494,   104,   255,   256,   257,   258,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   259,    74,   260,
     261
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    69,    30,    60,   103,    32,    84,    86,    87,   198,
     450,   165,    31,   267,    35,   482,   369,   497,   475,   499,
     506,     5,   101,   157,   337,     6,    18,   412,    83,    85,
      18,   470,    18,   415,    94,   555,   416,     1,    90,    73,
      33,    93,   165,   402,    98,    29,     8,    75,    70,    69,
      29,    60,    29,   189,   190,   162,    18,    88,   100,    18,
      34,    11,   101,   176,   177,   512,   178,    12,    75,    29,
     166,    42,   167,   343,   300,    42,   413,   338,   340,    99,
     556,    43,    44,   188,   471,   175,    44,   163,    42,    45,
     195,   339,   184,    45,   185,     8,   181,   182,   476,    44,
     403,   166,   404,    92,   414,   164,    45,   557,    36,     8,
      11,   405,    49,    50,    18,    18,    12,   285,   158,   201,
      46,   203,    76,   206,    11,   208,   559,   210,    77,   211,
      12,   212,   451,   217,    37,    78,    38,   346,   498,   265,
     500,   501,    79,   268,   270,   272,   273,    47,   553,   301,
     554,    47,   558,   347,   307,   362,   283,   363,    24,   483,
      13,   304,   190,    48,    47,   263,   286,    48,    80,    21,
      22,   294,   295,   220,    51,    24,    81,   364,    51,    89,
      48,   435,   440,    91,   364,   288,    95,   313,   290,   317,
     318,    51,   323,   243,   327,   243,   487,   365,    41,   334,
     335,   336,   287,    18,   365,   488,    18,   442,   190,    13,
     308,    97,   168,    29,   311,   489,   315,   519,    29,   321,
     179,   325,   490,    13,   329,   423,   267,    11,   267,   183,
      43,   349,    42,    12,   357,   366,   361,    42,   274,   411,
     243,   276,   366,    44,   243,   275,   243,   277,    44,   243,
      45,   243,   449,   190,   243,    45,   417,   278,   368,   279,
     445,   532,   190,   447,   448,   534,   190,   535,   190,    46,
     572,   190,   427,    29,   267,   280,    70,    69,   432,    60,
     348,   491,   227,   243,   228,   360,   281,    11,   243,   573,
     190,   282,    42,    12,   424,   291,   426,   453,   492,   343,
      43,   455,   292,    44,   459,   493,   574,   190,    47,   344,
      45,   463,    18,    47,    18,   431,   466,   467,   468,   296,
     521,   524,   303,   452,    48,   528,    13,   590,   190,    48,
     309,   457,   330,   478,   479,    51,   322,   462,   340,    46,
      51,   464,   331,   465,   341,   495,   496,   342,   483,   401,
     418,   419,   265,   243,   265,  -255,   420,   267,   285,   267,
       7,   243,   345,   346,   421,   441,     8,   243,    47,   165,
     103,   243,   422,   243,   503,     9,   433,   434,   454,   347,
      10,    11,   469,  -203,    48,  -203,    13,    12,   460,   461,
     474,   472,   180,    49,    50,    51,   341,   509,     8,   511,
     265,   530,   531,   473,   533,   477,   565,   516,   480,   568,
     569,   570,   289,    11,    70,    69,   484,    60,     8,    12,
     425,   502,   481,   510,   518,   514,     8,   520,   166,   513,
     517,    19,    20,    11,    21,    22,   525,   526,    23,    12,
      24,    11,   538,   287,   243,   536,   541,    12,    18,   243,
     588,   589,    19,    20,   542,    21,    22,   539,    29,   243,
     543,    24,    29,   544,   546,   545,   548,   537,   549,   547,
     550,   595,    11,   540,   551,   198,    11,    42,    12,   552,
      13,    42,    12,   265,   560,   265,   561,   571,    44,   562,
     563,   577,    44,   566,   578,    45,   202,   243,   204,    45,
     207,   579,   209,   243,   580,   581,   582,   583,   213,    29,
     586,   205,    13,   591,   597,   600,   564,   169,   170,   171,
     172,   173,   174,    11,   576,   602,   603,    82,    42,    12,
     592,    96,    13,    52,   515,    29,   168,   218,   102,    44,
      13,   486,   269,   430,   370,   584,    45,   585,   504,    11,
     243,   575,   198,    47,    42,    12,   390,    47,   302,     0,
     508,   507,    43,   505,     0,    44,   359,   319,     0,    48,
     594,    13,    45,    48,     0,    13,     0,     0,    49,    50,
      51,   243,     0,     0,    51,   458,     0,     0,   362,     0,
     363,     0,     0,   221,   222,   223,     0,     0,   593,     0,
       0,   224,   225,     0,    47,   596,     0,   599,     0,     0,
       0,   601,   226,     0,   227,     0,   228,     0,     0,   229,
      48,     0,    13,   230,     0,   231,     0,   232,   243,     0,
      47,    51,     0,     0,     0,   243,     0,   243,     0,     0,
       0,   243,     0,     0,     0,     0,    48,     0,   262,   235,
     236,     0,   237,   598,     0,    49,    50,    51,    29,   168,
     218,     0,     0,     0,     0,     0,     0,   238,   239,     0,
       0,     0,    11,     0,     0,   198,     0,    42,    12,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       0,     8,    29,     0,     0,    45,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    42,    12,     0,    29,     0,   221,   222,   223,    43,
       0,     0,    44,     0,   224,   225,     0,     0,    11,    45,
       0,     0,     0,    42,    12,   226,     0,   227,     0,   228,
       0,     0,   229,     0,    44,     0,   230,     0,   231,     0,
     232,    45,     0,    47,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,   262,   235,   236,     0,   237,     0,     0,    49,    50,
      51,    29,   168,   218,     0,     0,     0,    47,     0,     0,
     238,   239,     0,     0,     0,    11,     0,     0,   198,     0,
      42,    12,   402,    48,     0,    13,     0,     0,    43,    47,
       0,    44,    49,    50,    51,    29,     0,     0,    45,     0,
      41,     0,     0,     0,     0,    48,     0,    13,     0,    11,
     214,     0,   215,   216,    42,    12,    51,     0,     0,   221,
     222,   223,    43,     0,     0,    44,     0,   224,   225,     0,
       0,     0,    45,     0,     0,     0,     0,     0,   226,   403,
     227,   404,   228,     0,     0,   229,     0,     0,     0,   230,
     405,   231,     0,   232,     0,     0,    47,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,   262,   235,   236,     0,   237,     0,
       0,    49,    50,    51,    29,   168,   218,     0,     0,     0,
      47,     0,     0,   238,   239,     0,     0,     0,    11,     0,
       0,   198,     0,    42,    12,     0,    48,     0,    13,     0,
       0,    43,     0,     0,    44,    49,    50,    51,     0,     0,
       0,    45,     0,     0,     0,     0,     0,    29,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,    11,   221,   222,   223,     0,    42,    12,     0,     0,
     224,   225,     0,     0,    43,     0,     0,    44,     0,     0,
       0,   226,     0,   227,    45,   228,     0,     0,   229,     0,
       0,     0,   230,     0,   231,     0,   232,     0,     0,    47,
       0,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    48,     0,   234,   235,   236,
       0,   237,     0,     0,    49,    50,    51,    29,   168,   218,
       0,     0,     0,     0,     0,     0,   238,   239,     0,     0,
       0,    11,    47,     0,   198,     0,    42,    12,     0,     0,
       0,     0,   310,     0,    43,     0,     0,    44,    48,     0,
      13,    29,     0,     0,    45,     0,     0,    49,    50,    51,
       0,     0,     0,     0,     0,    11,     0,     0,   198,     0,
      42,    12,     0,    29,     0,   221,   222,   223,     0,     0,
       0,    44,     0,   224,   225,     0,     0,    11,    45,     0,
       0,     0,    42,    12,   226,     0,   227,     0,   228,     0,
       0,   229,     0,    44,     0,   230,     0,   231,     0,   232,
      45,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
     262,   235,   236,     0,   237,     0,     0,    49,    50,    51,
      29,   168,   218,     0,     0,     0,    47,     0,     0,   238,
     239,     0,     0,     0,    11,     0,     0,   198,     0,    42,
      12,     0,    48,     0,    13,     0,     0,    43,    47,     0,
      44,    49,    50,    51,    29,     0,     0,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    13,     0,    11,   160,
       0,     0,   161,    42,    12,    51,     0,     0,   221,   222,
     223,     0,     0,     0,    44,     0,   224,   225,     0,     0,
       0,    45,     0,     0,     0,     0,     0,   226,     0,   227,
       0,   228,     0,     0,   229,     0,     0,     0,   230,     0,
     231,     0,   232,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,   262,   235,   236,     0,   237,     0,     0,
      49,    50,    51,   314,    29,   168,   218,     0,     0,    47,
       0,     0,   238,   239,     0,     0,     0,     0,    11,     0,
       0,   198,     0,    42,    12,    48,     0,    13,     0,     0,
     186,    43,     0,   187,    44,     0,    51,     0,    29,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    42,    12,     0,
       0,     0,   221,   222,   223,     0,     0,     0,    44,     0,
     224,   225,     0,     0,     0,    45,     0,     0,     0,     0,
       0,   226,     0,   227,     0,   228,     0,     0,   229,     0,
       0,     0,   230,     0,   231,     0,   232,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,   262,   235,   236,
       0,   237,     0,     0,    49,    50,    51,   320,    29,   168,
     218,     0,     0,    47,     0,     0,   238,   239,     0,     0,
       0,     0,    11,     0,     0,   198,     0,    42,    12,    48,
       0,    13,     0,   324,     0,    43,   332,   333,    44,     0,
      51,     0,    29,     0,   218,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    42,    12,     0,    29,     0,   221,   222,   223,     0,
       0,     0,    44,     0,   224,   225,     0,     0,    11,    45,
       0,     0,     0,    42,    12,   226,     0,   227,     0,   228,
       0,     0,   229,     0,    44,     0,   230,     0,   231,     0,
     232,    45,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,   262,   235,   236,     0,   237,   229,     0,    49,    50,
      51,    29,   168,   218,     0,     0,     0,    47,     0,     0,
     238,   239,     0,     0,     0,    11,     0,     0,   198,     0,
      42,    12,     0,    48,     0,   262,   328,     0,    43,    47,
       0,    44,     0,     0,    51,     0,     0,     0,    45,     0,
       0,     0,     0,     0,    29,    48,     0,    13,     0,     0,
       0,     0,     0,   271,     0,     0,    51,     0,    11,   221,
     222,   223,     0,    42,    12,     0,     0,   224,   225,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   226,     0,
     227,    45,   228,     0,     0,   229,     0,     0,     0,   230,
       0,   231,     0,   232,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,   262,   235,   236,     0,   237,     0,
       0,    49,    50,    51,    29,   168,   218,     0,     0,     0,
       0,     0,     0,   238,   239,     0,     0,     0,    11,    47,
       0,   198,     0,    42,    12,     0,     0,     0,    29,     0,
       0,    43,     0,     0,    44,    48,     0,    13,     0,     0,
       0,    45,    11,   293,     0,     0,    51,    42,    12,     0,
       0,     0,     0,   312,     0,     0,     0,     0,    44,     0,
       0,     0,   221,   222,   223,    45,     0,     0,     0,     0,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,   227,     0,   228,     0,     0,   229,     0,
       0,     0,   230,     0,   231,     0,   232,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,   262,   235,   236,
       0,   237,     0,    47,    49,    50,    51,   456,    29,   168,
     218,     0,     0,     0,     0,     0,   238,   239,     0,    48,
       0,    13,    11,     0,     0,   198,     0,    42,    12,     0,
      51,     0,     0,     0,     0,    43,     0,     0,    44,     0,
      29,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    42,
      12,     0,     0,     0,    29,   316,   221,   222,   223,     0,
      44,     0,     0,     0,   224,   225,     0,    45,    11,     0,
       0,     0,     0,    42,    12,   226,     0,   227,     0,   228,
      29,     0,   229,     0,    44,     0,   230,     0,   231,     0,
     232,    45,     0,    47,    11,     0,     0,     0,     0,    42,
      12,     0,     0,     0,     0,     0,     0,     0,    29,    48,
      44,   262,   235,   236,     0,   237,     0,    45,    49,    50,
      51,     0,    11,     0,     0,    47,   264,    42,    12,     0,
     238,   239,     0,   326,     0,     0,     0,     0,    44,   222,
     223,    48,     0,    13,     0,    45,     0,   225,     0,    47,
       0,     0,    51,     0,     0,     0,    11,   226,     0,     0,
       0,    42,    12,     0,     0,    48,     0,    13,   230,     0,
     231,     0,    44,     0,     0,    47,    51,     0,   191,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    13,   235,   236,     0,     0,     0,     0,
       0,     0,    51,    47,     0,     0,     0,   105,   106,     0,
       0,    43,   238,   239,     0,     0,   107,   108,     0,    48,
       0,    13,     0,     0,   109,     0,   110,     0,     0,     0,
      51,   111,     0,   112,   113,     0,   114,    47,     0,   192,
     115,   116,     0,     0,     0,     0,     0,   193,     0,     0,
      46,     0,     0,    48,     0,    13,     0,     0,   305,   306,
       0,     0,    49,    50,    51,     0,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,     0,
     194,   122,   123,     0,     0,   124,   125,   105,   106,   126,
     127,    43,     0,   128,   129,     0,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,     0,     0,     0,
       0,   111,     0,   112,   113,     0,   114,     0,     0,     0,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,   443,   444,
       0,     0,     0,     0,     0,     0,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,     0,
     446,   122,   123,     0,     0,   124,   125,   105,   106,   126,
     127,    43,     0,   128,   129,     0,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,     0,   105,   106,
       0,   111,    43,   112,   113,     0,   114,   107,   108,     0,
     115,   116,     0,     0,     0,   109,     0,   110,     0,     0,
      46,     0,   111,     0,   112,   113,     0,   114,     0,     0,
       0,   115,   116,     0,     0,     0,   118,   119,     0,     0,
       0,    46,     0,     0,     0,     0,     0,   120,   121,     0,
     529,   122,   123,     0,     0,   124,   125,   118,   119,   126,
     127,     0,     0,   128,   129,     0,     0,     0,   120,   121,
       0,     0,   122,   123,     0,     0,   124,   125,   105,   106,
     126,   127,    43,     0,   128,   129,     0,   107,   108,     0,
       0,     0,   436,     0,   437,   109,     0,   110,     0,   105,
     106,     0,   111,    43,   112,   113,     0,   114,   107,   108,
       0,   115,   116,     0,     0,     0,   109,     0,   110,     0,
       0,    46,     0,   111,     0,   112,   113,     0,   114,     0,
       0,     0,   115,   116,     0,     0,     0,   118,   119,   438,
       0,     0,    46,     0,     0,     0,     0,     0,   120,   121,
       0,     0,   122,   123,     0,     0,   124,   125,   118,   119,
     126,   127,     0,     0,   128,   129,     0,     0,     0,   120,
     121,     0,     0,   122,   123,     0,     0,   124,   125,     0,
       0,   126,   127,     0,     0,   128,   129,     0,    43,     0,
     350,     0,     0,     0,     0,     0,     0,     0,     0,  -265,
    -265,     0,     0,     0,   439,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
       0,     0,  -265,  -265,     0,     0,     0,   354,     0,   350,
    -265,     0,  -265,  -265,  -265,  -265,  -265,  -265,   371,   372,
     227,     0,   228,     0,   351,   352,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,   373,   374,     0,  -265,  -265,   375,     0,  -267,   376,
       0,   377,   378,   379,   380,   381,   382,  -267,  -267,     0,
       0,     0,     0,  -267,  -267,     0,   355,  -265,  -265,     0,
    -265,  -265,     0,     0,     0,     0,     0,     0,     0,     0,
    -267,  -267,     0,   383,   384,  -267,     0,     0,  -267,     0,
    -267,  -267,  -267,  -267,  -267,  -267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,     0,   387,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -267,  -267,     0,     0,   297,     0,     0,     0,
       0,   298,     0,   105,   106,     0,     0,    43,     0,     0,
       0,     0,   107,   108,     0,  -267,  -267,     0,  -267,  -267,
     109,     0,   110,     0,     0,     0,     0,   111,     0,   112,
     113,     0,   114,   371,   372,     0,   115,   116,     0,     0,
       0,     0,     0,   299,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,   374,     0,     0,
       0,     0,   118,   119,     0,     0,   377,   378,   379,   380,
     381,   382,     0,   120,   121,     0,   522,   122,   123,     0,
       0,   124,   125,   105,   106,   126,   127,    43,     0,   128,
     129,     0,   107,   108,     0,     0,     0,     0,   383,   384,
     109,     0,   110,     0,     0,     0,     0,   111,     0,   112,
     113,     0,   114,     0,     0,     0,   115,   116,     0,     0,
       0,   385,   386,   523,   387,   388,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   121,     0,   527,   122,   123,     0,
       0,   124,   125,   105,   106,   126,   127,    43,     0,   128,
     129,     0,   107,   108,     0,     0,     0,   567,     0,     0,
     109,     0,   110,     0,   105,   106,     0,   111,    43,   112,
     113,     0,   114,   107,   108,     0,   115,   116,     0,     0,
       0,   109,     0,   110,     0,     0,    46,     0,   111,     0,
     112,   113,     0,   114,     0,     0,     0,   115,   116,     0,
       0,     0,   118,   119,     0,     0,     0,    46,     0,     0,
       0,     0,     0,   120,   121,     0,     0,   122,   123,     0,
       0,   124,   125,   118,   119,   126,   127,     0,     0,   128,
     129,     0,     0,     0,   120,   121,     0,   587,   122,   123,
       0,     0,   124,   125,   105,   106,   126,   127,    43,     0,
     128,   129,     0,   107,   108,     0,     0,     0,     0,     0,
       0,   109,     0,   110,     0,   105,   106,     0,   111,    43,
     112,   113,     0,   114,   107,   108,     0,   115,   116,     0,
       0,     0,   109,     0,   110,     0,     0,    46,     0,   111,
       0,   112,   113,     0,   114,     0,     0,   192,   115,   116,
       0,     0,     0,   118,   119,   193,     0,     0,    46,     0,
       0,     0,     0,     0,   120,   121,     0,     0,   122,   123,
       0,     0,   124,   125,   118,   119,   126,   127,     0,     0,
     128,   129,     0,     0,     0,   120,   121,     0,   194,   122,
     123,     0,     0,   124,   125,   105,   106,   126,   127,    43,
       0,   128,   129,     0,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,     0,     0,     0,     0,   111,
       0,   112,   113,     0,   114,     0,     0,     0,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,     0,     0,   122,
     123,     0,     0,   124,   125,   105,   106,   126,   127,    43,
       0,   128,   129,     0,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,     0,     0,     0,     0,   111,
       0,   112,   113,     0,   114,     0,     0,     0,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,     0,     0,   122,
     123,     0,     0,   124,   125,     0,     0,   126,   127,     0,
       0,   128,   129
};

static const yytype_int16 yycheck[] =
{
      16,    16,     5,    16,    64,     8,    25,    26,    27,    27,
       4,    73,     7,   154,     9,    38,   246,   367,    46,   369,
     401,     5,    62,     4,    56,     0,     3,    25,    25,    26,
       7,    56,     9,   263,    37,    78,   266,    19,    33,    16,
       3,    36,   104,    31,    60,    10,     9,     9,    64,    64,
      10,    64,    10,     3,     4,    70,    33,     3,    61,    36,
      23,    24,   102,    82,    83,   415,    85,    30,     9,    10,
      73,    29,    75,    46,   190,    29,    74,   109,   101,    44,
     123,    37,    40,    98,   109,    82,    40,    35,    29,    47,
     132,   123,    95,    47,    97,     9,    91,    92,   126,    40,
      88,   104,    90,     3,   102,    53,    47,    78,     5,     9,
      24,    99,   130,   131,    91,    92,    30,   179,    99,   134,
      76,   136,     5,   138,    24,   140,   507,   142,     5,   144,
      30,   146,   126,   148,    21,     5,    23,   110,   368,   154,
     370,    36,     5,   156,   159,   160,   161,   105,   498,   191,
     500,   105,   123,   126,   196,    89,   175,    91,    22,    54,
     123,     3,     4,   121,   105,   152,   179,   121,     5,    16,
      17,   186,   187,    64,   132,    22,     5,    75,   132,     9,
     121,   297,   298,     5,    75,   180,    21,   202,   183,   204,
     205,   132,   207,   150,   209,   152,    32,    95,    15,   214,
     215,   216,   179,   180,    95,    41,   183,     3,     4,   123,
     197,     5,    11,    10,   201,    51,   203,     9,    10,   206,
      76,   208,    58,   123,   211,   287,   367,    24,   369,     5,
      37,   237,    29,    30,   240,   133,   242,    29,     3,   254,
     197,     9,   133,    40,   201,    35,   203,     3,    40,   206,
      47,   208,     3,     4,   211,    47,   271,     3,   245,     3,
     302,     3,     4,   305,   306,     3,     4,     3,     4,    76,
       3,     4,     9,    10,   415,     3,   292,   292,   293,   292,
     237,   117,    89,   240,    91,   242,     3,    24,   245,     3,
       4,     3,    29,    30,   289,     5,   291,   312,   134,    46,
      37,   316,     3,    40,   319,   141,     3,     4,   105,    56,
      47,   326,   289,   105,   291,   292,   331,   332,   333,     3,
     436,   437,   122,   310,   121,   441,   123,     3,     4,   121,
      45,   318,    35,   348,   349,   132,   133,   324,   101,    76,
     132,   328,    35,   330,   102,   360,   361,    95,    54,     4,
       3,     3,   367,   310,   369,    61,    76,   498,   420,   500,
       3,   318,   109,   110,     3,   118,     9,   324,   105,   431,
     430,   328,     3,   330,   389,    18,     3,     3,    37,   126,
      23,    24,    95,    89,   121,    91,   123,    30,    37,    37,
      95,   123,     3,   130,   131,   132,   102,   412,     9,   414,
     415,   443,   444,   132,   446,    46,   522,   420,    54,   525,
     526,   527,     3,    24,   430,   430,    61,   430,     9,    30,
       3,    36,   133,   123,   427,     3,     9,     3,   431,   416,
     425,    13,    14,    24,    16,    17,   118,   131,    20,    30,
      22,    24,    37,   420,   401,   126,   461,    30,   425,   406,
     566,   567,    13,    14,   123,    16,    17,    37,    10,   416,
      95,    22,    10,    56,   132,   123,   132,   454,   133,    46,
     133,   587,    24,   460,    63,    27,    24,    29,    30,    96,
     123,    29,    30,   498,   102,   500,     3,   529,    40,     3,
       9,    56,    40,   118,   123,    47,   134,   454,   136,    47,
     138,    56,   140,   460,   132,    97,    78,    78,   146,    10,
       9,    63,   123,    56,     3,     3,   519,    76,    77,    78,
      79,    80,    81,    24,   539,     3,     3,    25,    29,    30,
       5,    39,   123,    16,   420,    10,    11,    12,    64,    40,
     123,   357,   156,   292,   246,   560,    47,   563,   389,    24,
     507,   538,    27,   105,    29,    30,   248,   105,   191,    -1,
     406,   401,    37,   389,    -1,    40,   240,   205,    -1,   121,
     586,   123,    47,   121,    -1,   123,    -1,    -1,   130,   131,
     132,   538,    -1,    -1,   132,   133,    -1,    -1,    89,    -1,
      91,    -1,    -1,    68,    69,    70,    -1,    -1,   585,    -1,
      -1,    76,    77,    -1,   105,   592,    -1,   594,    -1,    -1,
      -1,   598,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
     121,    -1,   123,    98,    -1,   100,    -1,   102,   585,    -1,
     105,   132,    -1,    -1,    -1,   592,    -1,   594,    -1,    -1,
      -1,   598,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,    -1,   127,     5,    -1,   130,   131,   132,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,     9,    10,    -1,    -1,    47,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    10,    -1,    68,    69,    70,    37,
      -1,    -1,    40,    -1,    76,    77,    -1,    -1,    24,    47,
      -1,    -1,    -1,    29,    30,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    40,    -1,    98,    -1,   100,    -1,
     102,    47,    -1,   105,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,    -1,   127,    -1,    -1,   130,   131,
     132,    10,    11,    12,    -1,    -1,    -1,   105,    -1,    -1,
     142,   143,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    31,   121,    -1,   123,    -1,    -1,    37,   105,
      -1,    40,   130,   131,   132,    10,    -1,    -1,    47,    -1,
      15,    -1,    -1,    -1,    -1,   121,    -1,   123,    -1,    24,
     126,    -1,   128,   129,    29,    30,   132,    -1,    -1,    68,
      69,    70,    37,    -1,    -1,    40,    -1,    76,    77,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,    -1,   127,    -1,
      -1,   130,   131,   132,    10,    11,    12,    -1,    -1,    -1,
     105,    -1,    -1,   142,   143,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,    -1,   121,    -1,   123,    -1,
      -1,    37,    -1,    -1,    40,   130,   131,   132,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    24,    68,    69,    70,    -1,    29,    30,    -1,    -1,
      76,    77,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,
      -1,    87,    -1,    89,    47,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,   121,    -1,   123,   124,   125,
      -1,   127,    -1,    -1,   130,   131,   132,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,    24,   105,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    40,   121,    -1,
     123,    10,    -1,    -1,    47,    -1,    -1,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    10,    -1,    68,    69,    70,    -1,    -1,
      -1,    40,    -1,    76,    77,    -1,    -1,    24,    47,    -1,
      -1,    -1,    29,    30,    87,    -1,    89,    -1,    91,    -1,
      -1,    94,    -1,    40,    -1,    98,    -1,   100,    -1,   102,
      47,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,    -1,   127,    -1,    -1,   130,   131,   132,
      10,    11,    12,    -1,    -1,    -1,   105,    -1,    -1,   142,
     143,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,   121,    -1,   123,    -1,    -1,    37,   105,    -1,
      40,   130,   131,   132,    10,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,    -1,    24,   126,
      -1,    -1,   129,    29,    30,   132,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    40,    -1,    76,    77,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
     100,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,    -1,   127,    -1,    -1,
     130,   131,   132,   133,    10,    11,    12,    -1,    -1,   105,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,   121,    -1,   123,    -1,    -1,
     126,    37,    -1,   129,    40,    -1,   132,    -1,    10,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    40,    -1,
      76,    77,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
      -1,   127,    -1,    -1,   130,   131,   132,   133,    10,    11,
      12,    -1,    -1,   105,    -1,    -1,   142,   143,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,   121,
      -1,   123,    -1,    35,    -1,    37,   128,   129,    40,    -1,
     132,    -1,    10,    -1,    12,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    10,    -1,    68,    69,    70,    -1,
      -1,    -1,    40,    -1,    76,    77,    -1,    -1,    24,    47,
      -1,    -1,    -1,    29,    30,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    40,    -1,    98,    -1,   100,    -1,
     102,    47,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,    -1,   127,    94,    -1,   130,   131,
     132,    10,    11,    12,    -1,    -1,    -1,   105,    -1,    -1,
     142,   143,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,   121,    -1,   123,    35,    -1,    37,   105,
      -1,    40,    -1,    -1,   132,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    10,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,   132,    -1,    24,    68,
      69,    70,    -1,    29,    30,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    87,    -1,
      89,    47,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,   100,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,    -1,   127,    -1,
      -1,   130,   131,   132,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    24,   105,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    10,    -1,
      -1,    37,    -1,    -1,    40,   121,    -1,   123,    -1,    -1,
      -1,    47,    24,   129,    -1,    -1,   132,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    68,    69,    70,    47,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
      -1,   127,    -1,   105,   130,   131,   132,   133,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,   121,
      -1,   123,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
     132,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,
      10,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    10,    35,    68,    69,    70,    -1,
      40,    -1,    -1,    -1,    76,    77,    -1,    47,    24,    -1,
      -1,    -1,    -1,    29,    30,    87,    -1,    89,    -1,    91,
      10,    -1,    94,    -1,    40,    -1,    98,    -1,   100,    -1,
     102,    47,    -1,   105,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,   121,
      40,   123,   124,   125,    -1,   127,    -1,    47,   130,   131,
     132,    -1,    24,    -1,    -1,   105,    56,    29,    30,    -1,
     142,   143,    -1,    35,    -1,    -1,    -1,    -1,    40,    69,
      70,   121,    -1,   123,    -1,    47,    -1,    77,    -1,   105,
      -1,    -1,   132,    -1,    -1,    -1,    24,    87,    -1,    -1,
      -1,    29,    30,    -1,    -1,   121,    -1,   123,    98,    -1,
     100,    -1,    40,    -1,    -1,   105,   132,    -1,     4,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   105,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,   142,   143,    -1,    -1,    42,    43,    -1,   121,
      -1,   123,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,
     132,    57,    -1,    59,    60,    -1,    62,   105,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,   121,    -1,   123,    -1,    -1,     4,     5,
      -1,    -1,   130,   131,   132,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,    -1,
     106,   107,   108,    -1,    -1,   111,   112,    33,    34,   115,
     116,    37,    -1,   119,   120,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,    -1,
       5,   107,   108,    -1,    -1,   111,   112,    33,    34,   115,
     116,    37,    -1,   119,   120,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    33,    34,
      -1,    57,    37,    59,    60,    -1,    62,    42,    43,    -1,
      66,    67,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,
      76,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,   103,   104,    -1,
       5,   107,   108,    -1,    -1,   111,   112,    92,    93,   115,
     116,    -1,    -1,   119,   120,    -1,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,   111,   112,    33,    34,
     115,   116,    37,    -1,   119,   120,    -1,    42,    43,    -1,
      -1,    -1,    26,    -1,    28,    50,    -1,    52,    -1,    33,
      34,    -1,    57,    37,    59,    60,    -1,    62,    42,    43,
      -1,    66,    67,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    76,    -1,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    92,    93,    73,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,   111,   112,    92,    93,
     115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,   115,   116,    -1,    -1,   119,   120,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,   138,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,    39,
      79,    -1,    81,    82,    83,    84,    85,    86,    48,    49,
      89,    -1,    91,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,   113,   114,    76,    -1,    39,    79,
      -1,    81,    82,    83,    84,    85,    86,    48,    49,    -1,
      -1,    -1,    -1,    54,    55,    -1,   135,   136,   137,    -1,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,   113,   114,    76,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    42,    43,    -1,   136,   137,    -1,   139,   140,
      50,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    -1,    62,    48,    49,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,   103,   104,    -1,    26,   107,   108,    -1,
      -1,   111,   112,    33,    34,   115,   116,    37,    -1,   119,
     120,    -1,    42,    43,    -1,    -1,    -1,    -1,   113,   114,
      50,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,   136,   137,    73,   139,   140,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    26,   107,   108,    -1,
      -1,   111,   112,    33,    34,   115,   116,    37,    -1,   119,
     120,    -1,    42,    43,    -1,    -1,    -1,    26,    -1,    -1,
      50,    -1,    52,    -1,    33,    34,    -1,    57,    37,    59,
      60,    -1,    62,    42,    43,    -1,    66,    67,    -1,    -1,
      -1,    50,    -1,    52,    -1,    -1,    76,    -1,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,   111,   112,    92,    93,   115,   116,    -1,    -1,   119,
     120,    -1,    -1,    -1,   103,   104,    -1,    26,   107,   108,
      -1,    -1,   111,   112,    33,    34,   115,   116,    37,    -1,
     119,   120,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    -1,    33,    34,    -1,    57,    37,
      59,    60,    -1,    62,    42,    43,    -1,    66,    67,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    76,    -1,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    92,    93,    73,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,   111,   112,    92,    93,   115,   116,    -1,    -1,
     119,   120,    -1,    -1,    -1,   103,   104,    -1,   106,   107,
     108,    -1,    -1,   111,   112,    33,    34,   115,   116,    37,
      -1,   119,   120,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,   111,   112,    33,    34,   115,   116,    37,
      -1,   119,   120,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
      -1,   119,   120
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
      64,    68,    69,    70,    76,    77,    87,    89,    91,    94,
      98,   100,   102,   109,   123,   124,   125,   127,   142,   143,
     178,   181,   182,   203,   207,   208,   218,   219,   223,   224,
     225,   226,   232,   233,   234,   238,   239,   240,   241,   251,
     253,   254,   123,   218,    56,   178,   180,   181,   166,   167,
     178,   129,   178,   178,     3,    35,     9,     3,     3,     3,
       3,     3,     3,   151,   158,   159,   166,   237,   155,     3,
     155,     5,     3,   129,   178,   178,     3,    26,    31,    73,
     184,   183,   216,   122,     3,     4,     5,   183,   218,    45,
      35,   218,    35,   178,   133,   218,    35,   178,   178,   182,
     133,   218,   133,   178,    35,   218,    35,   178,    35,   218,
      35,    35,   128,   129,   178,   178,   178,    56,   109,   123,
     101,   102,    95,    46,    56,   109,   110,   126,   203,   234,
      39,    54,    55,    68,    76,   135,   221,   234,   235,   251,
     203,   234,    89,    91,    75,    95,   133,   206,   218,   206,
     208,    48,    49,    71,    72,    76,    79,    81,    82,    83,
      84,    85,    86,   113,   114,   136,   137,   139,   140,   220,
     221,   222,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     4,    31,    88,    90,    99,   227,   228,   229,   230,
     231,   178,    25,    74,   102,   206,   206,   178,     3,     3,
      76,     3,     3,   159,   155,     3,   155,     9,   171,   172,
     173,   237,   178,     3,     3,   184,    26,    28,    73,   138,
     184,   118,     3,     4,     5,   183,     5,   183,   183,     3,
       4,   126,   218,   178,    37,   178,   133,   218,   133,   178,
      37,    37,   218,   178,   218,   218,   178,   178,   178,    95,
      56,   109,   123,   132,    95,    46,   126,    46,   178,   178,
      54,   133,    38,    54,    61,   200,   200,    32,    41,    51,
      58,   117,   134,   141,   236,   178,   178,   180,   206,   180,
     206,    36,    36,   178,   223,   238,   224,   227,   225,   178,
     123,   178,   180,   218,     3,   158,   166,   155,   252,     9,
       3,   184,    26,    73,   184,   118,   131,    26,   184,     5,
     183,   183,     3,   183,     3,     3,   126,   218,    37,    37,
     218,   178,   123,    95,    56,   123,   132,    46,   132,   133,
     133,    63,    96,   180,   180,    78,   123,    78,   123,   224,
     102,     3,     3,     9,   252,   184,   118,    26,   184,   184,
     184,   183,     3,     3,     3,   218,   178,    56,   123,    56,
     132,    97,    78,    78,   178,   202,     9,    26,   184,   184,
       3,    56,     5,   218,   202,   184,   218,     3,     5,   218,
       3,   218,     3,     3
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
     195,   196,   196,   196,   197,   197,   198,   198,   198,   199,
     199,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   203,   203,   204,   204,   204,   204,   205,   205,
     205,   205,   206,   206,   206,   207,   207,   207,   207,   208,
     208,   208,   208,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   215,   215,   215,   215,
     215,   215,   216,   216,   216,   217,   217,   217,   218,   219,
     220,   220,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   222,   222,   222,   222,   223,   223,   223,   224,   224,
     224,   225,   225,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   228,   229,   230,   231,
     232,   232,   232,   232,   233,   233,   233,   233,   234,   234,
     234,   234,   235,   235,   235,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   237,   237,   237,   238,   238,   239,
     239,   239,   239,   239,   240,   240,   240,   240,   240,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   245,   245,   246,   246,   247,   247,   248,   248,
     249,   249,   250,   250,   251,   251,   251,   252,   253,   254
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
       1,     2,     3,     4,     1,     1,     2,     4,     4,     1,
       1,     1,     2,     3,     3,     3,     4,     4,     1,     2,
       2,     3,     1,     1,     4,     5,     5,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     5,     2,
       5,     3,     6,     4,     1,     1,     2,     4,     1,     1,
       2,     2,     1,     1,     3,     4,     4,     5,     4,     5,
       5,     6,     2,     3,     4,     1,     2,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     2,     3,     1,     2,
       3,     3,     4,     3,     4,     1,     1,     1,     1,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     3,
       4,     4,     5,     1,     2,     3,     4,     5,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   273,     0,   265,     0,   265,     0,   265,     0,   265,
     273,     0,   268,     0,   280,     0,   242,     0
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
#line 1065 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 2585 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1066 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 2591 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1072 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 2597 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1073 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2603 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1074 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2609 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1075 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2615 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1076 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 2621 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1077 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2627 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1078 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2633 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1079 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2639 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1080 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 2645 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1081 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2651 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1082 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2657 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1083 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2663 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1084 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 2669 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1085 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2675 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1086 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 2681 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1087 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 2687 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1093 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 2693 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1099 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 2699 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1105 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 2705 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1106 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 2711 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1112 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 2717 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1113 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 2723 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1119 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 2729 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1125 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2735 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1126 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2741 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1127 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2747 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1128 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2753 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1129 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2759 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1130 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2765 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1131 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2771 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1132 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 2777 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1138 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 2783 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1139 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 2789 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1145 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2795 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1146 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2801 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1147 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2807 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1148 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 2813 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1154 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2819 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1155 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2825 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1156 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2831 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1157 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 2837 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1163 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 2843 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1164 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 2849 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1170 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2855 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1171 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2861 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1172 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2867 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1173 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 2873 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1179 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 2879 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1180 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 2885 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1186 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 2891 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1187 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 2897 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1188 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 2903 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1189 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 2909 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1190 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 2915 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1191 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 2921 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1197 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 2927 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1203 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 2933 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1209 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 2939 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1215 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 2945 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1221 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 2951 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1227 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 2957 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1233 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 2963 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1234 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 2969 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1240 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 2975 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1246 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 2981 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1247 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 2987 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1253 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 2993 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1254 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 2999 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1260 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 3005 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1266 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 3011 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1267 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 3017 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1273 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3023 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1274 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3029 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1275 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3035 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1276 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3041 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1282 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3047 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1283 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3053 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1289 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3059 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1290 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3065 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1296 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3071 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1297 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3077 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Predicates Separator  */
#line 1298 "parser.y"
                                                                    { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3083 "parser.c"
    break;

  case 86: /* Action: Subject Permission Condition Colon Predicates Separator  */
#line 1299 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3089 "parser.c"
    break;

  case 87: /* Action: Subject Permission Condition Comma Predicates Separator  */
#line 1300 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3095 "parser.c"
    break;

  case 88: /* Action: Subject Permission Condition Comma Colon Predicates Separator  */
#line 1301 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3101 "parser.c"
    break;

  case 89: /* Action: Subject Permission Comma Predicates Separator  */
#line 1302 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3107 "parser.c"
    break;

  case 90: /* Action: Subject Permission Comma Condition Predicates Separator  */
#line 1303 "parser.y"
                                                                          { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3113 "parser.c"
    break;

  case 91: /* Action: Subject Permission Comma Condition Colon Predicates Separator  */
#line 1304 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3119 "parser.c"
    break;

  case 92: /* Action: Subject Permission Comma Condition Comma Predicates Separator  */
#line 1305 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3125 "parser.c"
    break;

  case 93: /* Action: Subject Permission Comma Condition Comma Colon Predicates Separator  */
#line 1306 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Condition); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3131 "parser.c"
    break;

  case 94: /* Subject: Symbols  */
#line 1312 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3137 "parser.c"
    break;

  case 95: /* Symbols: Symbol  */
#line 1318 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3143 "parser.c"
    break;

  case 96: /* Symbols: Symbols Catena Symbol  */
#line 1319 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3149 "parser.c"
    break;

  case 97: /* Symbol: Name  */
#line 1325 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3155 "parser.c"
    break;

  case 98: /* Symbol: Article Name  */
#line 1326 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3161 "parser.c"
    break;

  case 99: /* Symbol: Type  */
#line 1327 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3167 "parser.c"
    break;

  case 100: /* Symbol: Article Type  */
#line 1328 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3173 "parser.c"
    break;

  case 101: /* Catena: OR  */
#line 1334 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3179 "parser.c"
    break;

  case 102: /* Catena: Comma  */
#line 1335 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3185 "parser.c"
    break;

  case 103: /* Object: Symbol  */
#line 1341 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3191 "parser.c"
    break;

  case 104: /* Object: Reflexive  */
#line 1342 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3197 "parser.c"
    break;

  case 105: /* Object: ESCROW  */
#line 1343 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3203 "parser.c"
    break;

  case 106: /* Reflexive: MYSELF  */
#line 1349 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3209 "parser.c"
    break;

  case 107: /* Reflexive: YOURSELF  */
#line 1350 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3215 "parser.c"
    break;

  case 108: /* Reflexive: HERSELF  */
#line 1351 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3221 "parser.c"
    break;

  case 109: /* Reflexive: HIMSELF  */
#line 1352 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3227 "parser.c"
    break;

  case 110: /* Reflexive: ONESELF  */
#line 1353 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3233 "parser.c"
    break;

  case 111: /* Reflexive: ITSELF  */
#line 1354 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3239 "parser.c"
    break;

  case 112: /* Reflexive: THEMSELF  */
#line 1355 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3245 "parser.c"
    break;

  case 113: /* Reflexive: OURSELVES  */
#line 1356 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3251 "parser.c"
    break;

  case 114: /* Reflexive: YOURSELVES  */
#line 1357 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3257 "parser.c"
    break;

  case 115: /* Reflexive: THEMSELVES  */
#line 1358 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3263 "parser.c"
    break;

  case 116: /* Contract: This_Contract  */
#line 1364 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3269 "parser.c"
    break;

  case 117: /* Contract: All_Contracts  */
#line 1365 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3275 "parser.c"
    break;

  case 118: /* Predicates: Predicates Comma Predicate  */
#line 1371 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3281 "parser.c"
    break;

  case 119: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1372 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3287 "parser.c"
    break;

  case 120: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1373 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3293 "parser.c"
    break;

  case 121: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1374 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3299 "parser.c"
    break;

  case 122: /* Predicates: Predicates Comma AND Predicate  */
#line 1375 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3305 "parser.c"
    break;

  case 123: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1376 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3311 "parser.c"
    break;

  case 124: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1377 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3317 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1378 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3323 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1379 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3329 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1380 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3335 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1381 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3341 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1382 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3347 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1383 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3353 "parser.c"
    break;

  case 131: /* Predicates: Predicate  */
#line 1384 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3359 "parser.c"
    break;

  case 132: /* Predicate: Certification  */
#line 1390 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3365 "parser.c"
    break;

  case 133: /* Predicate: Declaration  */
#line 1391 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3371 "parser.c"
    break;

  case 134: /* Predicate: Filing  */
#line 1392 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3377 "parser.c"
    break;

  case 135: /* Predicate: Registration  */
#line 1393 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3383 "parser.c"
    break;

  case 136: /* Predicate: Grantment  */
#line 1394 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3389 "parser.c"
    break;

  case 137: /* Predicate: Appointment  */
#line 1395 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3395 "parser.c"
    break;

  case 138: /* Predicate: Fixture  */
#line 1396 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3401 "parser.c"
    break;

  case 139: /* Predicate: Setting  */
#line 1397 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3407 "parser.c"
    break;

  case 140: /* Predicate: Payment  */
#line 1398 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3413 "parser.c"
    break;

  case 141: /* Predicate: Sending  */
#line 1399 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3419 "parser.c"
    break;

  case 142: /* Predicate: Notification  */
#line 1400 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3425 "parser.c"
    break;

  case 143: /* Predicate: Termination  */
#line 1401 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3431 "parser.c"
    break;

  case 144: /* Permission: MAY  */
#line 1407 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 3437 "parser.c"
    break;

  case 145: /* Certification: Certify Symbol  */
#line 1413 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3443 "parser.c"
    break;

  case 146: /* Certification: Certify Symbol Expression  */
#line 1414 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3449 "parser.c"
    break;

  case 147: /* Certification: Certify Symbol AS Expression  */
#line 1415 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3455 "parser.c"
    break;

  case 148: /* Certification: Certify Contract Symbol  */
#line 1416 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3461 "parser.c"
    break;

  case 149: /* Certification: Certify Contract AS Symbol  */
#line 1417 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3467 "parser.c"
    break;

  case 150: /* Certify: CERTIFY  */
#line 1423 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3473 "parser.c"
    break;

  case 151: /* Certify: CERTIFIES  */
#line 1424 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3479 "parser.c"
    break;

  case 152: /* Declaration: Declare Symbol  */
#line 1430 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3485 "parser.c"
    break;

  case 153: /* Declaration: Declare Symbol Expression  */
#line 1431 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3491 "parser.c"
    break;

  case 154: /* Declaration: Declare Symbol TO BE Expression  */
#line 1432 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3497 "parser.c"
    break;

  case 155: /* Declaration: Declare Contract Symbol  */
#line 1433 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3503 "parser.c"
    break;

  case 156: /* Declaration: Declare Contract AS Symbol  */
#line 1434 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3509 "parser.c"
    break;

  case 157: /* Declare: DECLARE  */
#line 1440 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 3515 "parser.c"
    break;

  case 158: /* Declare: DECLARES  */
#line 1441 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 3521 "parser.c"
    break;

  case 159: /* Filing: File Symbol  */
#line 1447 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3527 "parser.c"
    break;

  case 160: /* Filing: File Symbol Expression  */
#line 1448 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3533 "parser.c"
    break;

  case 161: /* Filing: File Symbol TO BE Expression  */
#line 1449 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3539 "parser.c"
    break;

  case 162: /* Filing: File FOR Symbol  */
#line 1450 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3545 "parser.c"
    break;

  case 163: /* Filing: File FOR Symbol Expression  */
#line 1451 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3551 "parser.c"
    break;

  case 164: /* Filing: File FOR Symbol TO BE Expression  */
#line 1452 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3557 "parser.c"
    break;

  case 165: /* Filing: File Contract Symbol  */
#line 1453 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3563 "parser.c"
    break;

  case 166: /* Filing: File Contract TO BE Symbol  */
#line 1454 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3569 "parser.c"
    break;

  case 167: /* Filing: File FOR Contract Symbol  */
#line 1455 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3575 "parser.c"
    break;

  case 168: /* Filing: File FOR Contract TO BE Symbol  */
#line 1456 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 3581 "parser.c"
    break;

  case 169: /* File: FILE_  */
#line 1462 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 3587 "parser.c"
    break;

  case 170: /* File: FILES  */
#line 1463 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 3593 "parser.c"
    break;

  case 171: /* Registration: Register Symbol  */
#line 1469 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3599 "parser.c"
    break;

  case 172: /* Registration: Register Symbol Expression  */
#line 1470 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3605 "parser.c"
    break;

  case 173: /* Registration: Register Symbol AS Expression  */
#line 1471 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3611 "parser.c"
    break;

  case 174: /* Registration: Register Contract Symbol  */
#line 1472 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3617 "parser.c"
    break;

  case 175: /* Registration: Register Contract AS Symbol  */
#line 1473 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 3623 "parser.c"
    break;

  case 176: /* Register: REGISTER  */
#line 1479 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 3629 "parser.c"
    break;

  case 177: /* Register: REGISTERS  */
#line 1480 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 3635 "parser.c"
    break;

  case 178: /* Grantment: Grant Symbol  */
#line 1486 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 3641 "parser.c"
    break;

  case 179: /* Grant: GRANT  */
#line 1492 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 3647 "parser.c"
    break;

  case 180: /* Grant: GRANTS  */
#line 1493 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 3653 "parser.c"
    break;

  case 181: /* Appointment: Appoint Symbol  */
#line 1499 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 3659 "parser.c"
    break;

  case 182: /* Appointment: Appoint Symbol Expression  */
#line 1500 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 3665 "parser.c"
    break;

  case 183: /* Appointment: Appoint Symbol AS Expression  */
#line 1501 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 3671 "parser.c"
    break;

  case 184: /* Appoint: APPOINT  */
#line 1507 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 3677 "parser.c"
    break;

  case 185: /* Appoint: APPOINTS  */
#line 1508 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 3683 "parser.c"
    break;

  case 186: /* Fixture: Fix Symbol  */
#line 1514 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3689 "parser.c"
    break;

  case 187: /* Fixture: Fix Symbol AS Expression  */
#line 1515 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3695 "parser.c"
    break;

  case 188: /* Fixture: Fix Contract AS Symbol  */
#line 1516 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 3701 "parser.c"
    break;

  case 189: /* Fix: FIX  */
#line 1522 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 3707 "parser.c"
    break;

  case 190: /* Fix: FIXES  */
#line 1523 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 3713 "parser.c"
    break;

  case 191: /* Fixed: FIXED  */
#line 1529 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 3719 "parser.c"
    break;

  case 192: /* Setting: Illocutor Symbol  */
#line 1535 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3725 "parser.c"
    break;

  case 193: /* Setting: Illocutor THEREFOR Symbol  */
#line 1536 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3731 "parser.c"
    break;

  case 194: /* Setting: Illocutor THEREFORE Symbol  */
#line 1537 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3737 "parser.c"
    break;

  case 195: /* Setting: Illocutor THEN Symbol  */
#line 1538 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3743 "parser.c"
    break;

  case 196: /* Setting: Illocutor THEN THEREFOR Symbol  */
#line 1539 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3749 "parser.c"
    break;

  case 197: /* Setting: Illocutor THEN THEREFORE Symbol  */
#line 1540 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 3755 "parser.c"
    break;

  case 198: /* Illocutor: Be  */
#line 1546 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3761 "parser.c"
    break;

  case 199: /* Illocutor: Be AS  */
#line 1547 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3767 "parser.c"
    break;

  case 200: /* Illocutor: Be DEFINED  */
#line 1548 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3773 "parser.c"
    break;

  case 201: /* Illocutor: Be DEFINED AS  */
#line 1549 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 3779 "parser.c"
    break;

  case 202: /* Be: BE  */
#line 1555 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 3785 "parser.c"
    break;

  case 203: /* Be: IS  */
#line 1556 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 3791 "parser.c"
    break;

  case 204: /* Payment: Pay Expression Preposition Object  */
#line 1562 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3797 "parser.c"
    break;

  case 205: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1563 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3803 "parser.c"
    break;

  case 206: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1564 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3809 "parser.c"
    break;

  case 207: /* Payment: Pay Escrow Preposition Object  */
#line 1565 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 3815 "parser.c"
    break;

  case 208: /* Pay: PAY  */
#line 1571 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3821 "parser.c"
    break;

  case 209: /* Pay: PAYS  */
#line 1572 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3827 "parser.c"
    break;

  case 210: /* Pay: RETURN  */
#line 1573 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3833 "parser.c"
    break;

  case 211: /* Pay: RETURNS  */
#line 1574 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 3839 "parser.c"
    break;

  case 212: /* Preposition: TO  */
#line 1580 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 3845 "parser.c"
    break;

  case 213: /* Preposition: INTO  */
#line 1581 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 3851 "parser.c"
    break;

  case 214: /* Preposition: OF  */
#line 1582 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 3857 "parser.c"
    break;

  case 215: /* Escrow: ESCROW  */
#line 1588 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3863 "parser.c"
    break;

  case 216: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1589 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3869 "parser.c"
    break;

  case 217: /* Escrow: THE ESCROW  */
#line 1590 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3875 "parser.c"
    break;

  case 218: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1591 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 3881 "parser.c"
    break;

  case 219: /* From_Escrow: FROM ESCROW  */
#line 1597 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3887 "parser.c"
    break;

  case 220: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1598 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3893 "parser.c"
    break;

  case 221: /* From_Escrow: FROM THE ESCROW  */
#line 1599 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3899 "parser.c"
    break;

  case 222: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1600 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 3905 "parser.c"
    break;

  case 223: /* Sending: Send Expression Preposition Object  */
#line 1606 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 3911 "parser.c"
    break;

  case 224: /* Send: SEND  */
#line 1612 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 3917 "parser.c"
    break;

  case 225: /* Send: SENDS  */
#line 1613 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 3923 "parser.c"
    break;

  case 226: /* Notification: Notify Object  */
#line 1619 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Notification)=process_notification(Notification); }
#line 3929 "parser.c"
    break;

  case 227: /* Notification: Notify Object Preposition Expression  */
#line 1620 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 3935 "parser.c"
    break;

  case 228: /* Notify: NOTIFY  */
#line 1626 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 3941 "parser.c"
    break;

  case 229: /* Notify: NOTIFIES  */
#line 1627 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 3947 "parser.c"
    break;

  case 230: /* Termination: Terminate This_Contract  */
#line 1633 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 3953 "parser.c"
    break;

  case 231: /* Termination: Terminate All_Contracts  */
#line 1634 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 3959 "parser.c"
    break;

  case 232: /* Terminate: TERMINATE  */
#line 1640 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 3965 "parser.c"
    break;

  case 233: /* Terminate: TERMINATES  */
#line 1641 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 3971 "parser.c"
    break;

  case 234: /* Flagging: Illocutor Symbol Separator  */
#line 1647 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3977 "parser.c"
    break;

  case 235: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1648 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3983 "parser.c"
    break;

  case 236: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1649 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3989 "parser.c"
    break;

  case 237: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1650 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 3995 "parser.c"
    break;

  case 238: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1651 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4001 "parser.c"
    break;

  case 239: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1652 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4007 "parser.c"
    break;

  case 240: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1653 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4013 "parser.c"
    break;

  case 241: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1654 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4019 "parser.c"
    break;

  case 242: /* Condition: If Expression  */
#line 1660 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4025 "parser.c"
    break;

  case 243: /* Condition: If Expression THEN  */
#line 1661 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4031 "parser.c"
    break;

  case 244: /* Condition: If Expression Comma THEN  */
#line 1662 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4037 "parser.c"
    break;

  case 245: /* If: IF  */
#line 1668 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4043 "parser.c"
    break;

  case 246: /* If: GIVEN THAT  */
#line 1669 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4049 "parser.c"
    break;

  case 247: /* If: PROVIDED  */
#line 1670 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4055 "parser.c"
    break;

  case 248: /* Expression: Combination  */
#line 1676 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 4061 "parser.c"
    break;

  case 249: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1682 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 4067 "parser.c"
    break;

  case 250: /* Comparison_Operator: Equal  */
#line 1688 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4073 "parser.c"
    break;

  case 251: /* Comparison_Operator: Later  */
#line 1689 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4079 "parser.c"
    break;

  case 252: /* Equal: EQUAL  */
#line 1695 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4085 "parser.c"
    break;

  case 253: /* Equal: EQUAL TO  */
#line 1696 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4091 "parser.c"
    break;

  case 254: /* Equal: EQUALING  */
#line 1697 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4097 "parser.c"
    break;

  case 255: /* Equal: IS  */
#line 1698 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4103 "parser.c"
    break;

  case 256: /* Equal: IS EQUAL  */
#line 1699 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4109 "parser.c"
    break;

  case 257: /* Equal: IS EQUAL TO  */
#line 1700 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4115 "parser.c"
    break;

  case 258: /* Equal: BEING  */
#line 1701 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4121 "parser.c"
    break;

  case 259: /* Equal: BEING EQUAL  */
#line 1702 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4127 "parser.c"
    break;

  case 260: /* Equal: BEING EQUAL TO  */
#line 1703 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4133 "parser.c"
    break;

  case 261: /* Later: IS AT LEAST  */
#line 1709 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4139 "parser.c"
    break;

  case 262: /* Later: IS AT THE LEAST  */
#line 1710 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4145 "parser.c"
    break;

  case 263: /* Later: LIES AT LEAST  */
#line 1711 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4151 "parser.c"
    break;

  case 264: /* Later: LIES AT THE LEAST  */
#line 1712 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 4157 "parser.c"
    break;

  case 265: /* Scalar_Expression: Symbol  */
#line 1718 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4163 "parser.c"
    break;

  case 266: /* Scalar_Expression: Scalar  */
#line 1719 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4169 "parser.c"
    break;

  case 267: /* Scalar_Expression: Point_In_Time  */
#line 1720 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 4175 "parser.c"
    break;

  case 268: /* Combination: Combinor  */
#line 1726 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4181 "parser.c"
    break;

  case 269: /* Combination: Combinor Comma Combination  */
#line 1727 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4187 "parser.c"
    break;

  case 270: /* Combination: Combinor Comma Combinator Combination  */
#line 1728 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 4193 "parser.c"
    break;

  case 271: /* Combinor: Combinand  */
#line 1734 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 4199 "parser.c"
    break;

  case 272: /* Combinor: Combinand Combinator Combinor  */
#line 1735 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 4205 "parser.c"
    break;

  case 273: /* Combinand: Symbol  */
#line 1741 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4211 "parser.c"
    break;

  case 274: /* Combinand: Symbol Expiration  */
#line 1742 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4217 "parser.c"
    break;

  case 275: /* Combinand: Reflexive  */
#line 1743 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4223 "parser.c"
    break;

  case 276: /* Combinand: Description  */
#line 1744 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4229 "parser.c"
    break;

  case 277: /* Combinand: Scalar_Comparison  */
#line 1745 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4235 "parser.c"
    break;

  case 278: /* Combinand: Negation  */
#line 1746 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4241 "parser.c"
    break;

  case 279: /* Combinand: Existence  */
#line 1747 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4247 "parser.c"
    break;

  case 280: /* Combinand: Point_In_Time  */
#line 1748 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4253 "parser.c"
    break;

  case 281: /* Combinand: Expiration  */
#line 1749 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 4259 "parser.c"
    break;

  case 282: /* Combinator: Or_  */
#line 1755 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4265 "parser.c"
    break;

  case 283: /* Combinator: And  */
#line 1756 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4271 "parser.c"
    break;

  case 284: /* Combinator: Neither  */
#line 1757 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4277 "parser.c"
    break;

  case 285: /* Combinator: Nor  */
#line 1758 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 4283 "parser.c"
    break;

  case 286: /* Or_: OR  */
#line 1764 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 4289 "parser.c"
    break;

  case 287: /* And: AND  */
#line 1770 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 4295 "parser.c"
    break;

  case 288: /* Neither: NEITHER  */
#line 1776 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 4301 "parser.c"
    break;

  case 289: /* Nor: NOR  */
#line 1782 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 4307 "parser.c"
    break;

  case 290: /* Existence: Symbol Equal Fixed  */
#line 1788 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4313 "parser.c"
    break;

  case 291: /* Existence: THERE Be Symbol  */
#line 1789 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4319 "parser.c"
    break;

  case 292: /* Existence: Contract Be Symbol  */
#line 1790 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4325 "parser.c"
    break;

  case 293: /* Existence: Symbol Being True  */
#line 1791 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 4331 "parser.c"
    break;

  case 294: /* Negation: Negator Symbol  */
#line 1797 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4337 "parser.c"
    break;

  case 295: /* Negation: Symbol Negator Fixed  */
#line 1798 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4343 "parser.c"
    break;

  case 296: /* Negation: THERE Negator Symbol  */
#line 1799 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4349 "parser.c"
    break;

  case 297: /* Negation: Contract Negator Symbol  */
#line 1800 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 4355 "parser.c"
    break;

  case 298: /* Negator: NOT  */
#line 1806 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4361 "parser.c"
    break;

  case 299: /* Negator: Be NOT  */
#line 1807 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4367 "parser.c"
    break;

  case 300: /* Negator: NO  */
#line 1808 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4373 "parser.c"
    break;

  case 301: /* Negator: Be NO  */
#line 1809 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 4379 "parser.c"
    break;

  case 302: /* Being: IS  */
#line 1815 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4385 "parser.c"
    break;

  case 303: /* Being: HAS BEEN  */
#line 1816 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4391 "parser.c"
    break;

  case 304: /* Being: WAS  */
#line 1817 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 4397 "parser.c"
    break;

  case 305: /* True: TRUE  */
#line 1823 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4403 "parser.c"
    break;

  case 306: /* True: YES  */
#line 1824 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4409 "parser.c"
    break;

  case 307: /* True: CERTIFIED  */
#line 1825 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4415 "parser.c"
    break;

  case 308: /* True: DECLARED  */
#line 1826 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4421 "parser.c"
    break;

  case 309: /* True: ANNOUNCED  */
#line 1827 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4427 "parser.c"
    break;

  case 310: /* True: FILED  */
#line 1828 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4433 "parser.c"
    break;

  case 311: /* True: FILED FOR  */
#line 1829 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4439 "parser.c"
    break;

  case 312: /* True: SIGNED OFF  */
#line 1830 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4445 "parser.c"
    break;

  case 313: /* True: SIGNED OFF ON  */
#line 1831 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 4451 "parser.c"
    break;

  case 314: /* Article: A  */
#line 1837 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4457 "parser.c"
    break;

  case 315: /* Article: AN  */
#line 1838 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4463 "parser.c"
    break;

  case 316: /* Article: THE  */
#line 1839 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 4469 "parser.c"
    break;

  case 317: /* Point_In_Time: Current_Time  */
#line 1845 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 4475 "parser.c"
    break;

  case 318: /* Point_In_Time: Relative_Time  */
#line 1846 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 4481 "parser.c"
    break;

  case 319: /* Current_Time: THE CURRENT TIME  */
#line 1852 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4487 "parser.c"
    break;

  case 320: /* Current_Time: THE THEN CURRENT TIME  */
#line 1853 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4493 "parser.c"
    break;

  case 321: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 1854 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4499 "parser.c"
    break;

  case 322: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 1855 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4505 "parser.c"
    break;

  case 323: /* Current_Time: NOW  */
#line 1856 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 4511 "parser.c"
    break;

  case 324: /* Relative_Time: Duration PAST  */
#line 1862 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4517 "parser.c"
    break;

  case 325: /* Relative_Time: Duration PAST Symbol  */
#line 1863 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4523 "parser.c"
    break;

  case 326: /* Relative_Time: Duration IN THE PAST  */
#line 1864 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4529 "parser.c"
    break;

  case 327: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 1865 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4535 "parser.c"
    break;

  case 328: /* Relative_Time: Duration AFTER Symbol  */
#line 1866 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 4541 "parser.c"
    break;

  case 329: /* Duration: Scalar_Expression Time_Unit  */
#line 1872 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 4547 "parser.c"
    break;

  case 330: /* Time_Unit: Years  */
#line 1878 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4553 "parser.c"
    break;

  case 331: /* Time_Unit: Months  */
#line 1879 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4559 "parser.c"
    break;

  case 332: /* Time_Unit: Weeks  */
#line 1880 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4565 "parser.c"
    break;

  case 333: /* Time_Unit: Days  */
#line 1881 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4571 "parser.c"
    break;

  case 334: /* Time_Unit: Hours  */
#line 1882 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4577 "parser.c"
    break;

  case 335: /* Time_Unit: Minutes  */
#line 1883 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4583 "parser.c"
    break;

  case 336: /* Time_Unit: Seconds  */
#line 1884 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4589 "parser.c"
    break;

  case 337: /* Time_Unit: Milliseconds  */
#line 1885 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 4595 "parser.c"
    break;

  case 338: /* Years: YEAR  */
#line 1891 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 4601 "parser.c"
    break;

  case 339: /* Years: YEARS  */
#line 1892 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 4607 "parser.c"
    break;

  case 340: /* Months: MONTH  */
#line 1898 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 4613 "parser.c"
    break;

  case 341: /* Months: MONTHS  */
#line 1899 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 4619 "parser.c"
    break;

  case 342: /* Weeks: WEEK  */
#line 1905 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 4625 "parser.c"
    break;

  case 343: /* Weeks: WEEKS  */
#line 1906 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 4631 "parser.c"
    break;

  case 344: /* Days: DAY  */
#line 1912 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 4637 "parser.c"
    break;

  case 345: /* Days: DAYS  */
#line 1913 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 4643 "parser.c"
    break;

  case 346: /* Hours: HOUR  */
#line 1919 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 4649 "parser.c"
    break;

  case 347: /* Hours: HOURS  */
#line 1920 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 4655 "parser.c"
    break;

  case 348: /* Minutes: MINUTE  */
#line 1926 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 4661 "parser.c"
    break;

  case 349: /* Minutes: MINUTES  */
#line 1927 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 4667 "parser.c"
    break;

  case 350: /* Seconds: SECOND  */
#line 1933 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 4673 "parser.c"
    break;

  case 351: /* Seconds: SECONDS  */
#line 1934 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 4679 "parser.c"
    break;

  case 352: /* Milliseconds: MILLISECOND  */
#line 1940 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 4685 "parser.c"
    break;

  case 353: /* Milliseconds: MILLISECONDS  */
#line 1941 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 4691 "parser.c"
    break;

  case 354: /* Expiration: HAS PASSED  */
#line 1947 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4697 "parser.c"
    break;

  case 355: /* Expiration: PAST  */
#line 1948 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4703 "parser.c"
    break;

  case 356: /* Expiration: IS PAST  */
#line 1949 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 4709 "parser.c"
    break;

  case 357: /* Name: NAME  */
#line 1953 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 4715 "parser.c"
    break;

  case 358: /* Description: DESCRIPTION  */
#line 1956 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 4721 "parser.c"
    break;

  case 359: /* Scalar: SCALAR  */
#line 1959 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 4727 "parser.c"
    break;


#line 4731 "parser.c"

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




#line 1964 "parser.y"


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
	// Appointment->Expression
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
	if(opt_debug_actions) printf("actions: parsing Combinand %s\n", Combinand->Description);
	// Combinand->Symbol
	// Combinand->Expiration
	// Combinand->Reflexive
	// Combinand->Description
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

