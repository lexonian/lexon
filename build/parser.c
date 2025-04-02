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
  YYSYMBOL_A = 13,                         /* A  */
  YYSYMBOL_ACCEPT = 14,                    /* ACCEPT  */
  YYSYMBOL_ACCEPTS = 15,                   /* ACCEPTS  */
  YYSYMBOL_AFTER = 16,                     /* AFTER  */
  YYSYMBOL_AFTERWARDS = 17,                /* AFTERWARDS  */
  YYSYMBOL_ALL = 18,                       /* ALL  */
  YYSYMBOL_ALSO = 19,                      /* ALSO  */
  YYSYMBOL_AMOUNT = 20,                    /* AMOUNT  */
  YYSYMBOL_AN = 21,                        /* AN  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_ANNOUNCED = 23,                 /* ANNOUNCED  */
  YYSYMBOL_APPOINT = 24,                   /* APPOINT  */
  YYSYMBOL_APPOINTS = 25,                  /* APPOINTS  */
  YYSYMBOL_AS = 26,                        /* AS  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_ASSIGNS = 28,                   /* ASSIGNS  */
  YYSYMBOL_AT = 29,                        /* AT  */
  YYSYMBOL_AUTHOR = 30,                    /* AUTHOR  */
  YYSYMBOL_AUTHORS = 31,                   /* AUTHORS  */
  YYSYMBOL_BE = 32,                        /* BE  */
  YYSYMBOL_BEEN = 33,                      /* BEEN  */
  YYSYMBOL_BEING = 34,                     /* BEING  */
  YYSYMBOL_BINARY = 35,                    /* BINARY  */
  YYSYMBOL_CERTIFIED = 36,                 /* CERTIFIED  */
  YYSYMBOL_CERTIFIES = 37,                 /* CERTIFIES  */
  YYSYMBOL_CERTIFY = 38,                   /* CERTIFY  */
  YYSYMBOL_CLAUSE = 39,                    /* CLAUSE  */
  YYSYMBOL_COMING = 40,                    /* COMING  */
  YYSYMBOL_COMMENT = 41,                   /* COMMENT  */
  YYSYMBOL_COMMENTS = 42,                  /* COMMENTS  */
  YYSYMBOL_CONTRACT = 43,                  /* CONTRACT  */
  YYSYMBOL_CONTRACTS = 44,                 /* CONTRACTS  */
  YYSYMBOL_CURRENT = 45,                   /* CURRENT  */
  YYSYMBOL_DATA = 46,                      /* DATA  */
  YYSYMBOL_DAY = 47,                       /* DAY  */
  YYSYMBOL_DAYS = 48,                      /* DAYS  */
  YYSYMBOL_DECLARE = 49,                   /* DECLARE  */
  YYSYMBOL_DECLARED = 50,                  /* DECLARED  */
  YYSYMBOL_DECLARES = 51,                  /* DECLARES  */
  YYSYMBOL_DEFINED = 52,                   /* DEFINED  */
  YYSYMBOL_EQUAL = 53,                     /* EQUAL  */
  YYSYMBOL_EQUALING = 54,                  /* EQUALING  */
  YYSYMBOL_ESCROW = 55,                    /* ESCROW  */
  YYSYMBOL_FILE_ = 56,                     /* FILE_  */
  YYSYMBOL_FILED = 57,                     /* FILED  */
  YYSYMBOL_FILES = 58,                     /* FILES  */
  YYSYMBOL_FIX = 59,                       /* FIX  */
  YYSYMBOL_FIXED = 60,                     /* FIXED  */
  YYSYMBOL_FIXES = 61,                     /* FIXES  */
  YYSYMBOL_FOR = 62,                       /* FOR  */
  YYSYMBOL_FROM = 63,                      /* FROM  */
  YYSYMBOL_GENERAL = 64,                   /* GENERAL  */
  YYSYMBOL_GIVEN = 65,                     /* GIVEN  */
  YYSYMBOL_GRANT = 66,                     /* GRANT  */
  YYSYMBOL_GRANTS = 67,                    /* GRANTS  */
  YYSYMBOL_GREATER = 68,                   /* GREATER  */
  YYSYMBOL_HAS = 69,                       /* HAS  */
  YYSYMBOL_HERSELF = 70,                   /* HERSELF  */
  YYSYMBOL_HIMSELF = 71,                   /* HIMSELF  */
  YYSYMBOL_HOUR = 72,                      /* HOUR  */
  YYSYMBOL_HOURS = 73,                     /* HOURS  */
  YYSYMBOL_IF = 74,                        /* IF  */
  YYSYMBOL_IN = 75,                        /* IN  */
  YYSYMBOL_INCOMING = 76,                  /* INCOMING  */
  YYSYMBOL_INTO = 77,                      /* INTO  */
  YYSYMBOL_IS = 78,                        /* IS  */
  YYSYMBOL_ITSELF = 79,                    /* ITSELF  */
  YYSYMBOL_LEAST = 80,                     /* LEAST  */
  YYSYMBOL_LESS = 81,                      /* LESS  */
  YYSYMBOL_LEX = 82,                       /* LEX  */
  YYSYMBOL_LEXON = 83,                     /* LEXON  */
  YYSYMBOL_LIES = 84,                      /* LIES  */
  YYSYMBOL_MAY = 85,                       /* MAY  */
  YYSYMBOL_MILLISECOND = 86,               /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 87,              /* MILLISECONDS  */
  YYSYMBOL_MINUTE = 88,                    /* MINUTE  */
  YYSYMBOL_MINUTES = 89,                   /* MINUTES  */
  YYSYMBOL_MONTH = 90,                     /* MONTH  */
  YYSYMBOL_MONTHS = 91,                    /* MONTHS  */
  YYSYMBOL_MYSELF = 92,                    /* MYSELF  */
  YYSYMBOL_NEITHER = 93,                   /* NEITHER  */
  YYSYMBOL_NEW = 94,                       /* NEW  */
  YYSYMBOL_NEXT = 95,                      /* NEXT  */
  YYSYMBOL_NO = 96,                        /* NO  */
  YYSYMBOL_NOR = 97,                       /* NOR  */
  YYSYMBOL_NOT = 98,                       /* NOT  */
  YYSYMBOL_NOTIFIES = 99,                  /* NOTIFIES  */
  YYSYMBOL_NOTIFY = 100,                   /* NOTIFY  */
  YYSYMBOL_NOW = 101,                      /* NOW  */
  YYSYMBOL_OF = 102,                       /* OF  */
  YYSYMBOL_OFF = 103,                      /* OFF  */
  YYSYMBOL_ON = 104,                       /* ON  */
  YYSYMBOL_ONESELF = 105,                  /* ONESELF  */
  YYSYMBOL_OR = 106,                       /* OR  */
  YYSYMBOL_OURSELVES = 107,                /* OURSELVES  */
  YYSYMBOL_PASSED = 108,                   /* PASSED  */
  YYSYMBOL_PAST = 109,                     /* PAST  */
  YYSYMBOL_PAY = 110,                      /* PAY  */
  YYSYMBOL_PAYS = 111,                     /* PAYS  */
  YYSYMBOL_PER = 112,                      /* PER  */
  YYSYMBOL_PERSON = 113,                   /* PERSON  */
  YYSYMBOL_PREAMBLE = 114,                 /* PREAMBLE  */
  YYSYMBOL_PROVIDED = 115,                 /* PROVIDED  */
  YYSYMBOL_REGISTER = 116,                 /* REGISTER  */
  YYSYMBOL_REGISTERS = 117,                /* REGISTERS  */
  YYSYMBOL_REMAINDER = 118,                /* REMAINDER  */
  YYSYMBOL_REPAY = 119,                    /* REPAY  */
  YYSYMBOL_REPAYS = 120,                   /* REPAYS  */
  YYSYMBOL_RESPECTIVE = 121,               /* RESPECTIVE  */
  YYSYMBOL_RETURN = 122,                   /* RETURN  */
  YYSYMBOL_RETURNS = 123,                  /* RETURNS  */
  YYSYMBOL_SECOND = 124,                   /* SECOND  */
  YYSYMBOL_SECONDS = 125,                  /* SECONDS  */
  YYSYMBOL_SEND = 126,                     /* SEND  */
  YYSYMBOL_SENDS = 127,                    /* SENDS  */
  YYSYMBOL_SIGNED = 128,                   /* SIGNED  */
  YYSYMBOL_SMALLER = 129,                  /* SMALLER  */
  YYSYMBOL_SO = 130,                       /* SO  */
  YYSYMBOL_TERMINATE = 131,                /* TERMINATE  */
  YYSYMBOL_TERMINATES = 132,               /* TERMINATES  */
  YYSYMBOL_TERMS = 133,                    /* TERMS  */
  YYSYMBOL_TEXT = 134,                     /* TEXT  */
  YYSYMBOL_THAN = 135,                     /* THAN  */
  YYSYMBOL_THAT = 136,                     /* THAT  */
  YYSYMBOL_THE = 137,                      /* THE  */
  YYSYMBOL_THEMSELF = 138,                 /* THEMSELF  */
  YYSYMBOL_THEMSELVES = 139,               /* THEMSELVES  */
  YYSYMBOL_THEN = 140,                     /* THEN  */
  YYSYMBOL_THERE = 141,                    /* THERE  */
  YYSYMBOL_THEREFOR = 142,                 /* THEREFOR  */
  YYSYMBOL_THEREFORE = 143,                /* THEREFORE  */
  YYSYMBOL_THESE = 144,                    /* THESE  */
  YYSYMBOL_THIS = 145,                     /* THIS  */
  YYSYMBOL_TIME = 146,                     /* TIME  */
  YYSYMBOL_TO = 147,                       /* TO  */
  YYSYMBOL_TRANSFER = 148,                 /* TRANSFER  */
  YYSYMBOL_TRANSFERS = 149,                /* TRANSFERS  */
  YYSYMBOL_TRUE = 150,                     /* TRUE  */
  YYSYMBOL_WAS = 151,                      /* WAS  */
  YYSYMBOL_WEEK = 152,                     /* WEEK  */
  YYSYMBOL_WEEKS = 153,                    /* WEEKS  */
  YYSYMBOL_WITH = 154,                     /* WITH  */
  YYSYMBOL_YEAR = 155,                     /* YEAR  */
  YYSYMBOL_YEARS = 156,                    /* YEARS  */
  YYSYMBOL_YES = 157,                      /* YES  */
  YYSYMBOL_YET = 158,                      /* YET  */
  YYSYMBOL_YOURSELF = 159,                 /* YOURSELF  */
  YYSYMBOL_YOURSELVES = 160,               /* YOURSELVES  */
  YYSYMBOL_YYACCEPT = 161,                 /* $accept  */
  YYSYMBOL_Document = 162,                 /* Document  */
  YYSYMBOL_Head = 163,                     /* Head  */
  YYSYMBOL_Lex = 164,                      /* Lex  */
  YYSYMBOL_Lexon = 165,                    /* Lexon  */
  YYSYMBOL_Authors = 166,                  /* Authors  */
  YYSYMBOL_Comment = 167,                  /* Comment  */
  YYSYMBOL_Preamble = 168,                 /* Preamble  */
  YYSYMBOL_Terms = 169,                    /* Terms  */
  YYSYMBOL_Covenants = 170,                /* Covenants  */
  YYSYMBOL_Covenant = 171,                 /* Covenant  */
  YYSYMBOL_Provisions = 172,               /* Provisions  */
  YYSYMBOL_Definitions = 173,              /* Definitions  */
  YYSYMBOL_Definition = 174,               /* Definition  */
  YYSYMBOL_Type_Term = 175,                /* Type_Term  */
  YYSYMBOL_Type = 176,                     /* Type  */
  YYSYMBOL_Person = 177,                   /* Person  */
  YYSYMBOL_Amount = 178,                   /* Amount  */
  YYSYMBOL_Time = 179,                     /* Time  */
  YYSYMBOL_Binary = 180,                   /* Binary  */
  YYSYMBOL_Text = 181,                     /* Text  */
  YYSYMBOL_Data = 182,                     /* Data  */
  YYSYMBOL_This_Contract = 183,            /* This_Contract  */
  YYSYMBOL_All_Contracts = 184,            /* All_Contracts  */
  YYSYMBOL_This = 185,                     /* This  */
  YYSYMBOL_Clauses = 186,                  /* Clauses  */
  YYSYMBOL_Clause = 187,                   /* Clause  */
  YYSYMBOL_Body = 188,                     /* Body  */
  YYSYMBOL_Function = 189,                 /* Function  */
  YYSYMBOL_Statements = 190,               /* Statements  */
  YYSYMBOL_Statement = 191,                /* Statement  */
  YYSYMBOL_Action = 192,                   /* Action  */
  YYSYMBOL_Punctuation = 193,              /* Punctuation  */
  YYSYMBOL_Subject = 194,                  /* Subject  */
  YYSYMBOL_Symbols = 195,                  /* Symbols  */
  YYSYMBOL_Symbol = 196,                   /* Symbol  */
  YYSYMBOL_Catena = 197,                   /* Catena  */
  YYSYMBOL_Object = 198,                   /* Object  */
  YYSYMBOL_Reflexive = 199,                /* Reflexive  */
  YYSYMBOL_Contract = 200,                 /* Contract  */
  YYSYMBOL_Predicates = 201,               /* Predicates  */
  YYSYMBOL_Predicate = 202,                /* Predicate  */
  YYSYMBOL_Permission = 203,               /* Permission  */
  YYSYMBOL_Certification = 204,            /* Certification  */
  YYSYMBOL_Certify = 205,                  /* Certify  */
  YYSYMBOL_Declaration = 206,              /* Declaration  */
  YYSYMBOL_Declare = 207,                  /* Declare  */
  YYSYMBOL_Filing = 208,                   /* Filing  */
  YYSYMBOL_File = 209,                     /* File  */
  YYSYMBOL_Registration = 210,             /* Registration  */
  YYSYMBOL_Register = 211,                 /* Register  */
  YYSYMBOL_Grantment = 212,                /* Grantment  */
  YYSYMBOL_Grant = 213,                    /* Grant  */
  YYSYMBOL_Appointment = 214,              /* Appointment  */
  YYSYMBOL_Appoint = 215,                  /* Appoint  */
  YYSYMBOL_Assignment = 216,               /* Assignment  */
  YYSYMBOL_Assign = 217,                   /* Assign  */
  YYSYMBOL_Acceptance = 218,               /* Acceptance  */
  YYSYMBOL_Accept = 219,                   /* Accept  */
  YYSYMBOL_Fixture = 220,                  /* Fixture  */
  YYSYMBOL_Fix = 221,                      /* Fix  */
  YYSYMBOL_Fixed = 222,                    /* Fixed  */
  YYSYMBOL_Setting = 223,                  /* Setting  */
  YYSYMBOL_Illocutor = 224,                /* Illocutor  */
  YYSYMBOL_Be = 225,                       /* Be  */
  YYSYMBOL_Payment = 226,                  /* Payment  */
  YYSYMBOL_Pay = 227,                      /* Pay  */
  YYSYMBOL_Preposition = 228,              /* Preposition  */
  YYSYMBOL_Escrow = 229,                   /* Escrow  */
  YYSYMBOL_From_Escrow = 230,              /* From_Escrow  */
  YYSYMBOL_Sending = 231,                  /* Sending  */
  YYSYMBOL_Send = 232,                     /* Send  */
  YYSYMBOL_Notification = 233,             /* Notification  */
  YYSYMBOL_Notify = 234,                   /* Notify  */
  YYSYMBOL_Termination = 235,              /* Termination  */
  YYSYMBOL_Terminate = 236,                /* Terminate  */
  YYSYMBOL_Flagging = 237,                 /* Flagging  */
  YYSYMBOL_Condition = 238,                /* Condition  */
  YYSYMBOL_If = 239,                       /* If  */
  YYSYMBOL_Expression = 240,               /* Expression  */
  YYSYMBOL_Scalar_Comparison = 241,        /* Scalar_Comparison  */
  YYSYMBOL_Comparison_Operator = 242,      /* Comparison_Operator  */
  YYSYMBOL_Equal = 243,                    /* Equal  */
  YYSYMBOL_Greater = 244,                  /* Greater  */
  YYSYMBOL_Less = 245,                     /* Less  */
  YYSYMBOL_Later = 246,                    /* Later  */
  YYSYMBOL_Scalar_Expression = 247,        /* Scalar_Expression  */
  YYSYMBOL_Combination = 248,              /* Combination  */
  YYSYMBOL_Combinor = 249,                 /* Combinor  */
  YYSYMBOL_Combinand = 250,                /* Combinand  */
  YYSYMBOL_Combinator = 251,               /* Combinator  */
  YYSYMBOL_Or_ = 252,                      /* Or_  */
  YYSYMBOL_And = 253,                      /* And  */
  YYSYMBOL_Neither = 254,                  /* Neither  */
  YYSYMBOL_Nor = 255,                      /* Nor  */
  YYSYMBOL_Existence = 256,                /* Existence  */
  YYSYMBOL_Negation = 257,                 /* Negation  */
  YYSYMBOL_Negator = 258,                  /* Negator  */
  YYSYMBOL_Being = 259,                    /* Being  */
  YYSYMBOL_True = 260,                     /* True  */
  YYSYMBOL_Article = 261,                  /* Article  */
  YYSYMBOL_New = 262,                      /* New  */
  YYSYMBOL_Point_In_Time = 263,            /* Point_In_Time  */
  YYSYMBOL_Current_Time = 264,             /* Current_Time  */
  YYSYMBOL_Relative_Time = 265,            /* Relative_Time  */
  YYSYMBOL_Duration = 266,                 /* Duration  */
  YYSYMBOL_Time_Unit = 267,                /* Time_Unit  */
  YYSYMBOL_Years = 268,                    /* Years  */
  YYSYMBOL_Months = 269,                   /* Months  */
  YYSYMBOL_Weeks = 270,                    /* Weeks  */
  YYSYMBOL_Days = 271,                     /* Days  */
  YYSYMBOL_Hours = 272,                    /* Hours  */
  YYSYMBOL_Minutes = 273,                  /* Minutes  */
  YYSYMBOL_Seconds = 274,                  /* Seconds  */
  YYSYMBOL_Milliseconds = 275,             /* Milliseconds  */
  YYSYMBOL_Expiration = 276,               /* Expiration  */
  YYSYMBOL_Timeliness = 277,               /* Timeliness  */
  YYSYMBOL_Name = 278,                     /* Name  */
  YYSYMBOL_Description = 279,              /* Description  */
  YYSYMBOL_Scalar = 280                    /* Scalar  */
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
#define YYLAST   3909

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  472
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  818
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 12
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   415

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
     155,   156,   157,   158,   159,   160
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1152,  1152,  1153,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1180,  1186,  1192,  1193,  1199,  1200,  1206,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1225,  1226,  1232,  1233,  1234,
    1235,  1241,  1242,  1243,  1244,  1250,  1251,  1257,  1258,  1259,
    1260,  1266,  1267,  1273,  1274,  1275,  1276,  1277,  1278,  1284,
    1290,  1296,  1302,  1308,  1314,  1320,  1321,  1327,  1333,  1334,
    1340,  1341,  1347,  1353,  1354,  1360,  1361,  1362,  1363,  1369,
    1370,  1376,  1377,  1383,  1384,  1385,  1386,  1387,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1406,  1412,  1413,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1432,  1433,  1439,
    1440,  1441,  1442,  1448,  1449,  1450,  1451,  1452,  1453,  1454,
    1455,  1456,  1457,  1463,  1464,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1508,  1514,  1515,  1516,  1517,  1518,  1524,
    1525,  1531,  1532,  1533,  1534,  1535,  1541,  1542,  1548,  1549,
    1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,  1563,  1564,
    1570,  1571,  1572,  1573,  1574,  1580,  1581,  1587,  1593,  1594,
    1600,  1601,  1607,  1608,  1614,  1615,  1621,  1622,  1628,  1629,
    1630,  1636,  1637,  1643,  1644,  1645,  1651,  1652,  1658,  1664,
    1665,  1666,  1667,  1668,  1669,  1675,  1676,  1677,  1678,  1684,
    1685,  1691,  1692,  1693,  1694,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1713,  1714,  1715,  1721,  1722,  1723,  1724,
    1730,  1731,  1732,  1733,  1739,  1745,  1746,  1752,  1753,  1759,
    1760,  1766,  1767,  1773,  1774,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1793,  1799,  1800,  1801,  1807,  1813,  1819,
    1820,  1821,  1822,  1828,  1829,  1830,  1831,  1832,  1833,  1834,
    1835,  1836,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,
    1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,
    1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,
    1885,  1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,
    1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,
    1905,  1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1924,  1925,  1926,  1927,  1933,  1934,
    1935,  1936,  1937,  1943,  1944,  1945,  1951,  1952,  1958,  1959,
    1960,  1961,  1962,  1963,  1964,  1965,  1966,  1967,  1968,  1974,
    1975,  1976,  1977,  1983,  1989,  1995,  2001,  2007,  2008,  2009,
    2010,  2016,  2017,  2018,  2019,  2025,  2026,  2027,  2028,  2034,
    2035,  2036,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,
    2050,  2056,  2057,  2058,  2064,  2065,  2066,  2067,  2073,  2074,
    2080,  2081,  2082,  2083,  2084,  2090,  2091,  2092,  2093,  2094,
    2100,  2106,  2107,  2108,  2109,  2110,  2111,  2112,  2113,  2119,
    2120,  2126,  2127,  2133,  2134,  2140,  2141,  2147,  2148,  2154,
    2155,  2161,  2162,  2168,  2169,  2175,  2176,  2177,  2183,  2184,
    2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,
    2198,  2201,  2204
};
#endif

#define YYPACT_NINF (-413)
#define YYTABLE_NINF (-378)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,   126,    69,   241,   294,    68,  -413,    46,    68,  -413,
    -413,   226,   141,  -413,   263,  -413,  2150,  -413,   189,   212,
     223,   227,   232,   235,   265,   338,   280,   154,  -413,  -413,
     270,  -413,   299,    46,   308,  -413,    74,    68,   211,   263,
    -413,  -413,  -413,  -413,   342,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,    93,   200,   304,  -413,  2237,  -413,
    -413,  3289,     3,  -413,  2547,   371,  -413,   821,   166,  -413,
      68,   345,   345,   345,   345,   345,   345,   280,   154,  -413,
     154,  -413,  -413,  -413,   284,  -413,    97,    46,  -413,   379,
      68,  -413,    68,  2578,  -413,  -413,  -413,   304,  -413,  1778,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,   409,  -413,  1969,  -413,  2402,  -413,  2402,
    -413,  2290,  -413,  2402,  -413,  2860,  -413,  1809,  -413,  1809,
    -413,  2860,  -413,  2402,  -413,  2419,  -413,   960,  -413,  1809,
    -413,  1916,  -413,    24,  -413,  -413,  2860,  2654,  2860,   390,
    -413,   369,  -413,   166,  -413,  -413,  -413,   394,  -413,   406,
     412,   417,   421,   425,   431,   154,  -413,  -413,  -413,  1134,
      46,  -413,  -413,   149,   440,   446,  2685,  2860,   448,  -413,
    2942,  3056,   326,  -413,  -413,   433,    21,  1809,   423,  -413,
    -413,  1097,  2731,  1205,  2795,  2402,  1313,   598,  1456,  2826,
    -413,  -413,  -413,   366,  -413,  -413,   372,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,   289,  -413,  -413,   262,  -413,
    -413,    36,  -413,   262,    45,   466,  -413,  2862,  -413,   495,
     152,  -413,  -413,  2860,  1670,   413,  -413,  -413,    75,  -413,
    -413,  -413,   494,   475,  1593,   479,   488,  2616,  2860,  2860,
    -413,    47,   -36,   416,   221,  1490,   264,  1809,   225,   264,
    -413,   467,  -413,   264,  -413,  -413,  -413,  -413,  2860,   521,
     526,  -413,  -413,  -413,  -413,   456,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,   535,  -413,   540,   258,  -413,    46,  -413,
     239,  2203,  2860,   541,   542,  -413,  3760,  2088,   419,  -413,
     462,    21,  -413,  -413,   410,  -413,   480,  3760,  -413,  -413,
    1809,  -413,  2860,  -413,   514,  -413,  2860,  -413,  1701,  1050,
     520,  -413,   522,  -413,  1809,  -413,  2860,  -413,  -413,  -413,
     418,  -413,   -27,   511,  1443,  2860,   509,   420,  -413,   256,
     498,   -77,  -413,   506,   506,   159,  -413,  -413,  1443,  2860,
    -413,  -413,  2860,  -413,  -413,   -13,  -413,  -413,   449,   -12,
     544,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  2509,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,   852,  -413,  -413,
    -413,  -413,  1809,  -413,  -413,  -413,  -413,  -413,  -413,  2860,
     434,  2860,  2860,  1809,  -413,  1809,  2860,  2860,  2860,  -413,
    -413,  -413,  -413,   472,   -26,   439,   296,   476,  -413,  -413,
    -413,  1916,   264,  1916,   264,  1916,  -413,  1809,   574,  -413,
    -413,  1134,  -413,  -413,  -413,  -413,    46,  -413,    68,  -413,
    -413,  2355,  1282,   576,  -413,  -413,  -413,  3760,  3175,   450,
     438,  -413,  3408,  -413,  3760,   499,  -413,  -413,   505,  -413,
    -413,  1809,  -413,   552,  -413,   553,  -413,  1809,  2860,  -413,
    -413,  -413,   443,   548,   451,  -413,  -413,   454,  -413,  -413,
     -43,   457,   -56,  -413,   428,   404,  -413,  -413,  -413,  -413,
    -413,  -413,   536,   502,  -413,  -413,  -413,  -413,  -413,  -413,
     538,   575,   -29,     0,     1,   529,   578,    23,  -413,  3742,
    -413,  -413,  1809,  -413,  -413,   504,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,   477,  -413,   513,   561,   485,  -413,  1916,
    -413,  1916,  -413,  -413,  -413,   620,   621,  -413,   616,    68,
    -413,  -413,  3760,   496,  -413,  3527,  3760,  3760,  -413,   528,
    -413,  -413,  -413,  -413,  1809,  2860,  -413,  -413,  -413,   481,
    -413,  -413,  -413,   523,  -413,   470,   527,  -413,  -413,   471,
    -413,   531,   497,   562,  -413,   557,   580,   609,   565,   619,
     292,   577,  -413,   579,  -413,  2860,   601,   525,  -413,   602,
    -413,  -413,  -413,  -413,    93,   651,  -413,  3646,  3760,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,   508,  -413,
    -413,  -413,   532,  -413,   533,   603,   309,   589,   543,     2,
     -50,   313,  -413,  -413,  -413,   618,  -413,   629,    93,  3760,
    -413,  -413,  -413,  -413,  -413,   545,   554,     9,   -18,   344,
      16,   556,   647,   558,    18,   559,    40,   228,  -413,  1809,
     679,   744,  -413,  -413,    42,   566,   652,   567,    54,   568,
      64,   271,   572,   656,   571,   573,    70,   581,   657,    73,
     583,   660,   584,    78,   706,  -413,  1809,   711,   586,   682,
     582,   591,   121,   593,   684,   129,   597,   694,   600,   139,
     596,   604,  -413,   605,   608,   705,   606,   614,   617,   713,
     613,   622,   157,   623,   716,  -413,   750,  -413,   624,   631,
    -413,   626,   640,   724,   636,   643,   648,   746,   646,   649,
     197,   653,   749,  -413,   650,  -413,   658,   662,  -413,   659,
     661,   663,  -413,   665,   666,   752,   667,   668,  -413,  -413,
     669,  -413,   670,   672,  -413,   671,   673,   674,  -413,   675,
     678,   753,   676,   680,  -413,  -413,   677,  -413,  -413,   681,
    -413,   683,   688,  -413,   686,  -413,  -413,   689,  -413,  -413,
     690,  -413,   691,   698,  -413,   693,  -413,  -413,  -413,   697,
    -413,  -413,  -413,  -413,   699,  -413,  -413,  -413
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,   411,
     412,     0,     0,   413,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   470,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,    60,   219,    62,     0,   416,    64,   417,   220,   414,
     415,    59,    63,    69,    68,    61,    46,   103,    53,    54,
      55,    56,    57,    58,     0,     0,    42,    70,    43,    79,
      81,     0,    96,    97,     0,   215,    82,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,    16,    14,    13,
      10,     9,     7,    20,     0,    32,     0,     0,    29,     0,
       0,    36,     0,     0,    65,    66,    71,    44,    80,     0,
     201,   202,   192,   193,   196,   197,   160,   159,   166,   167,
     178,   179,   206,   207,   188,   189,   153,   250,   249,   225,
     226,   185,   186,   229,   230,   227,   228,   245,   246,   253,
     254,   231,   232,     0,   138,     0,   139,     0,   140,     0,
     141,     0,   142,     0,   143,     0,   144,     0,   145,     0,
     146,     0,   147,     0,   148,     0,   149,     0,   150,     0,
     151,     0,   152,     0,   108,   107,     0,     0,     0,     0,
     216,   217,   105,     0,   101,   104,   100,     0,   471,     0,
       0,     0,     0,     0,     0,    18,    17,    15,    11,     0,
       0,    33,    30,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   264,   266,     0,     0,     0,     0,   123,
     124,   154,     0,   161,     0,     0,   168,     0,   180,     0,
     187,   472,   361,     0,   115,   116,   220,   118,   113,   397,
     395,   424,   117,   120,   456,   413,   119,   122,     0,   114,
     121,   358,   371,     0,     0,     0,   374,     0,   267,   363,
     366,   376,   375,     0,     0,   360,   418,   419,     0,   378,
     372,   359,   358,     0,   198,   203,     0,     0,     0,     0,
     209,   361,     0,     0,   413,   358,     0,     0,     0,     0,
     111,   413,   109,   247,   110,   251,   252,    98,     0,     0,
       0,   255,   218,   106,   102,     0,    22,    23,    24,    25,
      21,    26,    19,     0,    51,     0,     0,    34,     0,    37,
       0,     0,     0,     0,     0,   259,     0,     0,     0,   125,
       0,     0,   265,    84,    88,    89,    90,     0,   263,    67,
       0,   155,     0,   157,     0,   162,     0,   164,   171,     0,
       0,   169,     0,   174,     0,   181,     0,   183,   455,   457,
       0,   362,     0,     0,     0,     0,   279,   273,   275,     0,
     399,   395,   401,     0,     0,     0,   369,   370,     0,     0,
     398,   396,     0,   445,   446,     0,   447,   448,   276,     0,
       0,   453,   454,   449,   450,   441,   442,   451,   452,   443,
     444,   439,   440,     0,   269,   270,   271,   272,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,   384,   385,
     386,   383,     0,   379,   380,   381,   382,   391,   373,     0,
       0,   425,     0,     0,   199,     0,     0,     0,     0,   212,
     210,   211,   240,     0,     0,     0,   362,     0,   234,   235,
     233,     0,     0,     0,     0,     0,   112,     0,     0,   257,
     256,     0,    47,    49,    52,    38,     0,    39,     0,    72,
      74,    73,     0,     0,   261,   260,   126,     0,     0,     0,
       0,   129,     0,    86,     0,    92,    94,    91,     0,   156,
     158,     0,   165,     0,   172,     0,   176,     0,     0,   182,
     184,   420,     0,     0,     0,   388,   393,   280,   274,   400,
       0,   277,     0,   458,   462,     0,   208,   387,   392,   406,
     404,   405,   407,     0,   402,   403,   390,   389,   394,   191,
       0,     0,     0,     0,     0,     0,     0,     0,   358,   268,
     360,   364,     0,   367,   429,     0,   426,   195,   200,   204,
     205,   213,   214,     0,   242,     0,     0,     0,   224,     0,
     221,     0,   244,   248,   258,     0,     0,    40,     0,     0,
     262,   130,     0,     0,   133,     0,     0,     0,   127,     0,
      95,    93,    85,   163,     0,     0,   170,   175,   422,     0,
     421,   281,   460,     0,   278,   466,     0,   463,   459,   464,
     408,   409,   282,     0,   354,     0,     0,     0,     0,     0,
       0,     0,   356,     0,   365,   427,     0,     0,   237,     0,
     222,   223,    48,    50,     0,     0,   134,     0,     0,   131,
     137,   128,    87,   173,   177,   423,   461,   467,   468,   465,
     410,   283,   284,   355,   286,     0,     0,     0,     0,     0,
       0,     0,   357,   428,   241,     0,   239,     0,     0,     0,
     135,   132,   469,   285,   287,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,   136,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,   291,   292,     0,     0,   298,     0,     0,     0,
     306,     0,     0,     0,     0,    76,     0,    77,   326,     0,
     323,   324,     0,     0,   330,     0,     0,     0,   338,     0,
       0,     0,     0,   295,   296,   293,   302,     0,   299,   300,
     310,     0,   307,   308,     0,     0,   314,     0,    78,   327,
     328,   325,   334,     0,   331,   332,   342,     0,   339,   340,
       0,     0,   346,     0,   297,   303,   304,   301,   311,   312,
     309,   318,     0,   315,   316,   329,   335,   336,   333,   343,
     344,   341,   350,     0,   347,   348,   305,   313,   319,   320,
     317,   337,   345,   351,   352,   349,   321,   353
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -413,  -413,  -413,  -413,  -413,   773,    60,   -15,  -413,  -413,
     780,    30,  -413,   813,   376,    39,  -413,  -413,  -413,  -413,
    -413,  -413,   -14,   685,  -413,   765,   170,  -413,  -413,   534,
     -65,  -413,   512,  -413,  -413,   104,  -413,  -263,  -154,   374,
    -131,  -187,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,   461,  -413,   -63,    -7,  -413,  -413,  -273,  -413,   560,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,   633,  -413,    -2,
    -413,  -413,   590,  -413,  -413,  -413,   447,  -412,   424,  -413,
     435,  -413,  -413,  -413,  -413,  -413,  -413,   208,  -413,  -413,
      -3,   -71,   463,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,   114,  -413,    19,   -37,  -413
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   313,    57,    58,    59,    60,    61,
      62,    63,   219,   220,    65,    66,    67,   469,   470,    68,
      69,    70,   337,    71,    72,   285,   176,   293,   252,   253,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   517,   164,    74,   254,   166,   167,   451,   286,   287,
     168,   169,   170,   171,   172,   173,    76,   216,   217,   255,
     256,   403,   373,   405,   406,   407,   257,   258,   259,   260,
     422,   423,   424,   425,   426,   261,   262,   263,   375,   526,
     109,    78,   265,   266,   267,   268,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   269,   377,    79,   270,   271
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   103,    64,   108,    18,   541,   183,   174,    18,    75,
      89,    91,    92,    77,   215,   453,   455,   294,   502,   442,
     457,   530,   535,   329,    30,   334,   335,    32,   673,   554,
      18,   513,   514,    18,   606,   608,   671,    31,   183,  -190,
    -190,    35,   218,   685,   189,   190,   191,   192,   193,   194,
     692,   604,   697,   595,    64,     8,    99,    75,  -368,     9,
     687,    75,  -368,    95,   165,   592,    98,    10,    42,     6,
     366,     1,   196,   197,   700,   198,   708,    97,    29,   674,
     330,   515,   443,     8,   105,    88,    90,     9,   713,   367,
     368,   429,   555,    18,    18,    10,   184,   186,   716,   187,
     200,   444,   596,   612,   724,   369,     8,   728,   605,   175,
       9,   688,   733,   503,   370,   593,   182,   185,    10,   204,
      73,   205,   531,   536,  -236,    42,   201,   202,   184,  -368,
     614,     5,   239,  -368,   371,   607,   609,   672,   165,   476,
     481,   380,  -368,   381,   686,   244,    36,   195,   182,  -236,
     430,   693,   318,   698,   264,   742,   264,   273,     8,   295,
     613,   336,     9,   746,   264,   288,   264,   289,    53,    54,
      10,    48,    73,   751,   418,   701,    29,   709,   179,   559,
     312,   561,   519,    13,   431,   315,    41,   372,   558,   714,
     560,   764,   562,   183,  -236,   520,   316,    18,    80,   717,
      18,    43,   304,   165,   165,   725,   488,   208,   729,   521,
      29,    13,    46,   734,   264,   338,   522,    81,   264,   341,
     264,   345,   303,   264,   351,   264,   355,   428,    82,    33,
     317,   780,    83,   319,    13,     8,   106,    84,   314,     9,
      85,   364,   466,   104,     7,   419,   378,    10,     8,   420,
       8,   221,     9,   223,     9,   226,   743,   228,   421,   230,
      10,   251,    10,   272,   747,   274,   360,   275,    24,   280,
      86,   264,   434,    93,   752,   292,   446,   106,    41,    51,
     297,   299,   300,   184,   264,   452,    13,   523,   282,   509,
     571,   574,   765,    43,    42,   578,   620,   294,   621,   294,
      52,   294,   448,   182,    46,    11,   702,    64,    94,   524,
     323,   324,    55,    96,    75,    18,   525,    18,   472,   165,
     165,    21,    22,   100,    19,    20,   343,   449,   347,   348,
     165,   353,   781,   357,   360,    21,    22,   264,   489,   447,
      48,   448,   362,    44,   361,   264,   494,   102,   465,   718,
     467,   264,   499,   579,   510,   464,   188,   703,   239,    34,
     240,   363,   199,    13,   358,   376,   449,   427,    19,    20,
     648,    51,   450,  -238,    12,    37,    13,    23,    13,    21,
      22,   439,   440,   441,   203,   626,   376,   666,   629,   630,
     631,   675,    52,   301,    24,   302,    38,   180,  -238,   376,
     719,   183,   458,   305,    55,   294,   108,   294,    24,   306,
     362,   450,   209,   210,   264,   307,  -377,  -377,  -377,   264,
     308,   649,   689,   181,   309,    73,   473,   650,   310,   363,
     264,   548,   264,   549,   311,  -377,   333,   210,   667,  -377,
     660,   661,   676,  -238,   668,   320,   490,   566,   677,   321,
     492,   325,    24,   496,   264,   563,   365,    64,   316,   374,
     500,   379,   332,    18,    75,   483,   210,   339,   505,   506,
     165,   165,   682,   690,   358,   165,  -377,   165,   532,   691,
     374,   359,   527,   528,   486,   487,   529,   568,   264,   583,
    -377,   184,   382,   374,   264,   586,   567,  -194,  -194,   417,
     314,   432,   511,   580,   581,   435,  -377,   538,   582,   210,
    -377,   182,   598,   599,   436,  -377,  -368,   533,   445,  -377,
    -368,   222,   456,   224,   459,   227,    42,   229,   366,   460,
     534,   632,   210,   544,   461,   546,   547,   276,   462,   264,
     550,   551,   552,   463,   474,   475,   491,   367,   368,   482,
     485,   511,   497,  -377,   498,   292,   504,   292,  -276,   292,
    -377,   657,   507,   369,   501,   165,   516,   508,   165,   165,
     165,   545,   370,   537,   553,    73,   556,   564,   557,   570,
     575,   264,   633,   576,   584,   585,   597,  -368,   625,   588,
     239,  -368,   371,   589,  -220,   681,   512,   590,   600,   349,
    -368,   591,   587,   244,   594,   601,   602,   359,    29,   603,
     610,     9,   611,   615,   616,   617,   618,    75,    41,    10,
     165,   165,   619,   622,   623,   624,   627,   635,   637,   639,
     642,   636,   641,    43,   679,   640,   638,   643,    45,    29,
     188,   231,     9,   645,    46,   372,   646,   218,   644,    41,
      10,    75,   165,   647,   264,   680,   654,   656,   651,   652,
     658,    42,   655,   292,    43,   292,   662,   663,   664,    45,
     669,   665,   670,   678,    47,    46,   264,   704,   264,   707,
     683,   695,   705,   684,   232,   694,   711,   696,   699,   634,
     721,   727,    49,    50,   731,   710,   712,   715,   233,   234,
     235,   720,   723,   264,   736,    47,   722,   236,   237,   735,
     726,    51,   730,   732,   737,   738,   739,   740,   745,   653,
     741,   238,   744,    49,    50,   239,   748,   240,   749,   750,
     241,   753,    52,   754,   242,    13,   243,   756,   244,   757,
     755,   758,    51,   759,    55,   352,   760,   761,   762,   706,
     767,   763,   766,   768,    29,   188,   231,     9,   773,   769,
     770,   771,   218,    52,    41,    10,   245,   246,   247,   772,
     248,   774,   775,    53,    54,    55,    42,   776,   779,    43,
     777,   778,   782,   783,    45,   784,   792,   803,   249,   250,
      46,   786,   789,   785,   787,   791,   788,   794,    87,   232,
     790,   797,   793,   800,   795,   796,   798,   802,   799,   805,
     801,   804,   806,   233,   234,   235,   807,   809,   808,   101,
      47,   810,   236,   237,   811,   812,   813,   814,   815,    56,
      80,    29,   816,   107,   817,   518,   238,   565,    49,    50,
     239,    41,   240,   484,   331,   241,   543,   404,   454,   242,
     539,   243,   542,   244,     0,   471,    43,    51,   296,     0,
       0,    45,    29,   188,   231,     9,   540,    46,     0,     0,
     218,     0,    41,    10,   418,     0,     0,     0,    52,     0,
       0,   245,   246,   247,    42,   248,     0,    43,    53,    54,
      55,     0,    45,     0,     0,     0,     0,    47,    46,     0,
       0,     0,     0,   249,   250,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,   233,   234,   235,     0,     0,     0,     0,    47,     0,
     236,   237,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   419,    49,    50,   239,   420,
     240,     0,     0,   241,     0,    52,     0,   242,   421,   243,
       0,   244,     0,     0,     0,    51,     0,    55,     0,     0,
      29,   188,   231,     9,     0,     0,     0,     0,   218,     0,
      41,    10,     0,     0,     0,     0,    52,     0,     0,   245,
     246,   247,    42,   248,     0,    43,    53,    54,    55,     0,
      45,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,   249,   250,     0,     0,   281,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,     0,     0,   233,
     234,   235,     0,     0,     0,     0,    47,     0,   236,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,    49,    50,   239,     0,   240,     0,
      29,   241,     0,     9,     0,   242,     0,   243,     0,   244,
      41,    10,     0,    51,     0,     0,     0,     0,   283,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
      45,     0,     0,     0,    52,     0,    46,   284,   246,   247,
       0,   248,     0,     0,    53,    54,    55,    29,   188,   231,
       9,     0,     0,     0,     0,   218,     0,    41,    10,   249,
     250,     0,     0,   340,     0,     0,    47,     0,     0,    42,
       0,     0,    43,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    46,    49,    50,     0,     9,     0,     0,
       0,     0,   232,     0,    41,    10,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,   233,   234,   235,    43,
       0,     0,     0,    47,     0,   236,   237,     0,     0,     0,
      46,     0,     0,     0,    52,     0,     0,    13,     0,   238,
       0,    49,    50,   239,     0,   240,    55,   495,   241,     0,
       0,     0,   242,     0,   243,     0,   244,     0,     0,     0,
      51,     0,     0,     0,     0,    29,   188,   231,     9,     0,
       0,     0,     0,   218,     0,    41,    10,     0,     0,     0,
       0,    52,     0,     0,   245,   246,   247,    42,   248,     0,
      43,    53,    54,    55,     0,    45,     0,    51,     0,     0,
       0,    46,     0,     0,     0,     0,   249,   250,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    13,     0,     0,   233,   234,   235,     0,    53,    54,
      55,    47,     0,   236,   237,     0,     0,     0,     0,     0,
       0,   569,    29,     0,     0,     0,     0,   238,     0,    49,
      50,   239,    41,   240,     0,     0,   241,     0,     0,     0,
     242,     0,   243,     0,   244,     0,     0,    43,    51,     0,
       0,     0,    45,    29,   188,   231,     9,     0,    46,     0,
       0,   218,     0,    41,    10,     0,     0,     0,     0,    52,
       0,     0,   245,   246,   247,    42,   248,     0,    43,    53,
      54,    55,   344,    45,     0,     0,     0,     0,    47,    46,
       0,     0,     0,     0,   249,   250,     0,     0,   232,     0,
       0,     0,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,   233,   234,   235,     0,     0,     0,     0,    47,
       0,   236,   237,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,    49,    50,   239,
       0,   240,     0,     0,   241,     0,    52,     0,   242,     0,
     243,     0,   244,     0,     0,     0,    51,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     245,   246,   247,    29,   248,     0,     9,    53,    54,    55,
     350,     0,     0,    41,    10,     0,    29,   188,   231,     9,
       0,     0,   249,   250,   218,     0,    41,    10,    43,     0,
       0,     0,   354,    45,     0,     0,     0,     0,    42,    46,
       0,    43,     0,  -368,  -368,  -368,    45,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,   232,  -368,     0,     0,     0,  -368,     0,     0,    47,
       0,     0,    42,     0,   366,   233,   234,   235,     0,     0,
       0,     0,    47,     0,   236,   237,     0,    49,    50,   380,
       0,   381,     0,   367,   368,     0,     0,     0,   238,     0,
      49,    50,   239,  -368,   240,     0,    51,   241,     0,   369,
       0,   242,     0,   243,     0,   244,     0,  -368,   370,    51,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
      13,     0,     0,  -368,     0,     0,   239,  -368,   371,    55,
      52,     0,  -368,   245,   246,   247,  -368,   248,     0,   244,
      53,    54,    55,    29,   188,   231,     9,     0,     0,     0,
       0,   218,     0,    41,    10,   249,   250,     0,     0,   433,
       0,     0,     0,     0,     0,    42,     0,     0,    43,     0,
    -368,     0,     0,    45,     0,     0,     0,  -368,     0,    46,
       0,   372,     0,     0,     0,     0,     0,     0,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,     0,     0,     0,     0,    47,
       0,   236,   237,     0,     0,     0,     0,     0,     0,     0,
      29,   188,     0,     0,     0,   238,     0,    49,    50,   239,
      41,   240,     0,     0,   241,     0,     0,     0,   242,     0,
     243,     0,   244,     0,     0,    43,    51,     0,     0,     0,
      45,    29,   188,   231,     9,     0,    46,     0,     0,   218,
       0,    41,    10,     0,     0,     0,     0,    52,     0,     0,
     245,   246,   247,    42,   248,     0,    43,    53,    54,    55,
       0,    45,     0,     0,     0,     0,    47,    46,     0,     0,
       0,     0,   249,   250,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
     233,   234,   235,     0,     0,     0,     0,    47,     0,   236,
     237,     0,     0,    51,     0,     0,     0,     0,    29,     0,
       0,     0,     0,   238,     0,    49,    50,   239,    41,   240,
       0,     0,   241,     0,    52,     0,   242,     0,   243,     0,
     244,     0,     0,    43,    51,     0,    55,     0,    45,    29,
     188,   231,     9,     0,    46,     0,     0,   218,     0,    41,
      10,     0,     0,     0,     0,    52,     0,     0,   245,   246,
     247,    42,   248,     0,    43,    53,    54,    55,   493,    45,
       0,     0,     0,     0,    47,    46,     0,     0,     0,     0,
     249,   250,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,   233,   234,
     235,     0,     0,     0,     0,    47,     0,   236,   237,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,    49,    50,   239,     0,   240,     0,     0,
     241,     0,    52,     0,   242,     0,   243,     0,   244,     0,
       0,     0,    51,     0,    55,     0,    29,     0,     0,     9,
       0,     0,     0,     0,     0,     0,    41,    10,     0,     0,
       0,     0,     0,    52,     0,     0,   245,   246,   247,     0,
     248,    43,     0,    53,    54,    55,    45,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,   249,   250,
       0,   290,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,     0,   234,   235,     0,     0,
       0,     0,    47,   112,   113,   237,   114,   115,     0,     0,
       0,    42,     0,     0,     0,     0,   116,   117,   238,     0,
      49,    50,     0,     0,     0,     0,     0,     0,   118,     0,
     119,   242,     0,   243,     0,   120,     0,   121,   122,    51,
     123,     0,     0,     0,   212,   124,   125,     0,     0,     0,
       0,     0,     0,   213,     0,     0,     0,    48,     0,     0,
      52,     0,     0,   291,   246,   247,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,   249,   250,     0,     0,   129,
     130,     0,     0,     0,   214,   131,   132,     0,   133,   134,
       0,   135,   136,     0,     0,   137,   138,     0,     0,     0,
     139,   140,   110,   111,     0,   477,     0,   478,     0,     0,
       0,     0,   112,   113,     0,   114,   115,   141,   142,     0,
      42,     0,     0,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,   119,
       0,     0,     0,     0,   120,     0,   121,   122,     0,   123,
       0,     0,     0,     0,   124,   125,     0,     0,     0,     8,
      29,     0,   479,     9,     0,     0,    48,     0,     0,     0,
      41,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,     0,   127,   128,    44,
      45,     0,     0,     0,     0,     0,    46,     0,   129,   130,
       0,     0,     0,     0,   131,   132,     0,   133,   134,     0,
     135,   136,   468,    29,   137,   138,     9,     0,     0,   139,
     140,     0,     0,    41,    10,     0,    47,     0,    48,     0,
       0,     0,     0,     0,     0,    42,   141,   142,    43,     0,
       0,     0,   480,    45,    49,    50,     0,    29,     0,    46,
       9,     0,     0,     0,     0,     0,     0,    41,    10,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,     0,    47,
       0,    48,     0,    46,    52,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    49,    50,     0,
      29,     0,     0,     9,     0,     0,     0,     0,   218,     0,
      41,    10,     0,    47,     0,    48,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
      45,    49,    50,     0,     0,     0,    46,    52,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      51,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    47,     0,     9,     0,
       0,    52,     0,     0,    13,    41,    10,     0,     0,     0,
       0,    53,    54,    55,    49,    50,     0,    42,     0,     0,
      43,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,    46,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     9,     0,     0,     0,     0,
     218,     0,    41,    10,    52,     0,     0,    13,     0,    29,
       0,    47,     9,    48,    53,    54,    55,    43,     0,    41,
      10,     0,    45,     0,     0,     0,     0,     0,    46,    49,
      50,     0,     0,     0,    43,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,    46,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    13,     0,     0,    47,    49,    50,     0,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    50,    51,     0,     0,     0,    29,
       0,   231,     9,     0,     0,     0,     0,     0,     0,    41,
      10,     0,    51,     0,     0,     0,    52,     0,     0,    13,
       0,     0,     0,     0,    43,     0,    53,    54,    55,    45,
       0,     0,     0,    52,     0,    46,    13,    29,     0,   277,
       9,   278,   279,     0,   232,    55,     0,    41,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,    47,     0,    45,    29,     0,
       0,     9,     0,    46,     0,     0,     0,     0,    41,    10,
       0,     0,     0,    49,    50,     0,     0,     0,     0,     0,
     241,     0,     0,    43,     0,     0,     0,     0,    45,     0,
       0,     0,    51,    47,    46,     0,    29,     0,     0,     9,
       0,     0,     0,     0,     0,     0,    41,    10,     0,     0,
       0,    49,    50,    52,     0,     0,   245,     0,     0,     0,
       0,    43,     0,     0,    47,    55,    45,     0,     0,     0,
      51,     0,    46,     0,    29,     0,     0,     9,     0,     0,
       0,     0,    49,    50,    41,    10,     0,     0,     0,     0,
       0,    52,     0,     0,    13,     0,     0,   177,     0,    43,
     178,    51,    47,    55,    45,    29,     0,     0,     9,     0,
      46,     0,     0,     0,     0,    41,    10,     0,     0,     0,
      49,    50,    52,     0,     0,    13,     0,     0,   206,     0,
      43,   207,     0,     0,    55,    45,     0,     0,     0,    51,
      47,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     9,     0,     0,     0,    49,    50,
      52,    41,    10,    13,     0,     0,     0,   342,   437,   438,
       0,    47,    55,     0,     0,     0,    43,    51,     0,     0,
       0,    45,     0,     0,     0,     0,     0,    46,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    13,     0,     0,     0,     0,     0,   298,    51,     0,
      55,     0,     0,     0,     0,    29,     0,    47,     9,     0,
       0,     0,     0,     0,     0,    41,    10,     0,     0,    52,
       0,   346,    13,     0,     0,    49,    50,     0,   322,     0,
      43,    55,     0,     0,     0,    45,    29,     0,     0,     9,
       0,    46,     0,     0,    51,     0,    41,    10,     0,     0,
       0,     0,   356,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,    52,    45,     0,    13,     0,
      29,    47,    46,     9,     0,     0,     0,    55,     0,     0,
      41,    10,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,    43,   366,     0,     0,     0,
      45,     0,    47,     0,     0,     0,    46,     0,    51,   383,
     384,     0,     0,     0,     0,   367,   368,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    52,
     385,     0,    13,     0,   386,   387,    47,     0,     0,    51,
     388,    55,     0,   389,     0,     0,   390,     0,   391,   392,
     393,   394,   395,   396,    49,    50,   110,   111,     0,   326,
      52,     0,     0,    13,   327,     0,   112,   113,     0,   114,
     115,     0,    55,    51,    42,     0,     0,     0,     0,   116,
     117,     0,     0,     0,     0,     0,   397,   398,     0,     0,
       0,   118,     0,   119,    52,     0,     0,    13,   120,     0,
     121,   122,     0,   123,     0,     0,    55,     0,   124,   125,
       0,     0,     0,     0,   399,   400,   328,   401,   402,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,     0,     0,     0,     0,   131,   132,
       0,   133,   134,     0,   135,   136,     0,     0,   137,   138,
     110,   111,     0,   139,   140,     0,     0,     0,     0,     0,
     112,   113,     0,   114,   115,     0,     0,     0,    42,     0,
     141,   142,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,     0,   121,   122,     0,   123,     0,     0,
       0,   212,   124,   125,     0,     0,     0,     0,     0,     0,
     213,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,   214,   131,   132,     0,   133,   134,     0,   135,   136,
       0,     0,   137,   138,     0,     0,     0,   139,   140,   110,
     111,     0,   572,     0,     0,     0,     0,     0,     0,   112,
     113,     0,   114,   115,   141,   142,     0,    42,     0,     0,
       0,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,     0,     0,     0,
       0,   120,     0,   121,   122,     0,   123,     0,     0,     0,
       0,   124,   125,     0,     0,     0,     0,     0,     0,   573,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,     0,     0,     0,
       0,   131,   132,     0,   133,   134,     0,   135,   136,     0,
       0,   137,   138,   110,   111,     0,   139,   140,     0,     0,
       0,     0,     0,   112,   113,     0,   114,   115,     0,     0,
       0,    42,     0,   141,   142,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     119,     0,     0,     0,     0,   120,     0,   121,   122,     0,
     123,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,   131,   132,     0,   133,   134,
       0,   135,   136,     0,     0,   137,   138,     0,     0,     0,
     139,   140,   110,   111,     0,   577,     0,     0,     0,     0,
       0,     0,   112,   113,     0,   114,   115,   141,   142,     0,
      42,     0,     0,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,   119,
       0,     0,     0,     0,   120,     0,   121,   122,     0,   123,
       0,     0,     0,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,     0,     0,     0,   131,   132,     0,   133,   134,     0,
     135,   136,     0,     0,   137,   138,     0,     0,     0,   139,
     140,   110,   111,     0,   628,     0,     0,     0,     0,     0,
       0,   112,   113,     0,   114,   115,   141,   142,     0,    42,
       0,     0,     0,     0,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   119,     0,
       0,     0,     0,   120,     0,   121,   122,     0,   123,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,     0,
       0,     0,     0,   131,   132,     0,   133,   134,     0,   135,
     136,     0,     0,   137,   138,     0,     0,     0,   139,   140,
     110,   111,     0,   659,     0,     0,     0,     0,     0,     0,
     112,   113,     0,   114,   115,   141,   142,     0,    42,     0,
       0,     0,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,     0,   121,   122,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,   131,   132,     0,   133,   134,     0,   135,   136,
       0,     0,   137,   138,   110,   111,     0,   139,   140,     0,
       0,     0,     0,     0,   112,   113,     0,   114,   115,   383,
     384,     0,    42,     0,   141,   142,     0,   116,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,   119,     0,     0,   386,   387,   120,     0,   121,   122,
       0,   123,     0,     0,     0,     0,   124,   125,   391,   392,
     393,   394,   395,   396,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,     0,     0,     0,   397,   398,     0,     0,
     129,   130,     0,     0,     0,     0,   131,   132,     0,   133,
     134,     0,   135,   136,     0,     0,   137,   138,     0,     0,
       0,   139,   140,     0,   399,   400,     0,   401,   402,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142
};

static const yytype_int16 yycheck[] =
{
       3,    64,    16,    68,     7,   417,    77,     4,    11,    16,
      25,    26,    27,    16,   145,   288,   289,   171,    45,    55,
     293,    34,    34,   210,     5,     4,     5,     8,    78,    55,
      33,   108,   109,    36,    34,    34,    34,     7,   109,     3,
       4,    11,    18,    34,    81,    82,    83,    84,    85,    86,
      34,    80,    34,   109,    68,     9,    37,    64,    22,    13,
      78,    68,    26,    33,    71,   108,    36,    21,    32,     0,
      34,    82,    87,    88,    34,    90,    34,     3,    10,   129,
     211,   158,   118,     9,    65,    25,    26,    13,    34,    53,
      54,    16,   118,    96,    97,    21,    77,    78,    34,    80,
       3,   137,   158,    80,    34,    69,     9,    34,   137,   106,
      13,   129,    34,   140,    78,   158,    77,    78,    21,   100,
      16,   102,   135,   135,    77,    32,    96,    97,   109,    93,
     542,     5,    96,    97,    98,   135,   135,   135,   145,   326,
     327,    96,   106,    98,   135,   109,     5,    87,   109,   102,
      75,   135,     3,   135,   157,    34,   159,   159,     9,   173,
     137,   140,    13,    34,   167,   167,   169,   169,   144,   145,
      21,    78,    68,    34,    22,   135,    10,   135,    74,   452,
     195,   454,    23,   137,   109,   199,    20,   151,   451,   135,
     453,    34,   455,   264,   147,    36,   199,   200,     9,   135,
     203,    35,   183,   210,   211,   135,   337,   103,   135,    50,
      10,   137,    46,   135,   217,   217,    57,     5,   221,   221,
     223,   223,   183,   226,   226,   228,   228,   264,     5,     3,
     200,    34,     5,   203,   137,     9,    66,     5,   199,    13,
       5,   248,     3,    43,     3,    93,   253,    21,     9,    97,
       9,   147,    13,   149,    13,   151,   135,   153,   106,   155,
      21,   157,    21,   159,   135,   161,    45,   163,   114,   165,
       5,   274,   274,     3,   135,   171,    55,   107,    20,   113,
     176,   177,   178,   264,   287,   287,   137,   128,    63,    33,
     477,   478,   135,    35,    32,   482,   559,   451,   561,   453,
     134,   455,    77,   264,    46,    64,    78,   321,     9,   150,
     206,   207,   146,     5,   321,   318,   157,   320,   321,   326,
     327,    41,    42,   112,    30,    31,   222,   102,   224,   225,
     337,   227,   135,   229,    45,    41,    42,   340,   340,   118,
      78,    77,   121,    39,    55,   348,   348,     5,   318,    78,
     320,   354,   354,   484,    98,   316,    11,   129,    96,   133,
      98,   140,    78,   137,   108,   251,   102,   263,    30,    31,
      78,   113,   147,    77,   133,   112,   137,    83,   137,    41,
      42,   277,   278,   279,     5,   572,   272,    78,   575,   576,
     577,    78,   134,     3,   114,    26,   133,    26,   102,   285,
     129,   472,   298,     9,   146,   559,   471,   561,   114,     3,
     121,   147,     3,     4,   417,     3,     3,     4,     5,   422,
       3,   129,    78,    52,     3,   321,   322,   135,     3,   140,
     433,   433,   435,   435,     3,    22,     3,     4,   129,    26,
     627,   628,   129,   147,   135,     5,   342,   461,   135,     3,
     346,     3,   114,   349,   457,   457,   248,   471,   461,   251,
     356,   253,   136,   466,   471,     3,     4,    44,   364,   365,
     477,   478,   659,   129,   108,   482,    63,   484,    29,   135,
     272,   109,   378,   379,     4,     5,   382,   468,   491,   491,
      77,   472,    26,   285,   497,   497,   466,     3,     4,     4,
     461,    26,    53,     4,     5,    26,    93,   403,     3,     4,
      97,   472,   108,   109,    26,   102,    22,    68,   102,   106,
      26,   147,    55,   149,     3,   151,    32,   153,    34,     3,
      81,     3,     4,   429,    78,   431,   432,   163,     3,   542,
     436,   437,   438,     3,     3,     3,    32,    53,    54,   130,
     140,    53,    32,   140,    32,   451,    45,   453,    60,   455,
     147,   624,    53,    69,   146,   572,    60,   147,   575,   576,
     577,   137,    78,    29,   102,   471,   137,     3,   102,     3,
     130,   584,   584,   145,    32,    32,   158,    93,   569,   146,
      96,    97,    98,    45,    96,   658,    98,   146,    62,   225,
     106,   147,   498,   109,   147,   103,    68,   109,    10,    34,
      81,    13,    34,   109,   137,   102,    55,   624,    20,    21,
     627,   628,   137,     3,     3,     9,   130,   146,   158,   158,
      68,   108,   135,    35,     5,   104,   109,    80,    40,    10,
      11,    12,    13,    34,    46,   151,    81,    18,    68,    20,
      21,   658,   659,    34,   657,   657,    55,    55,    81,    80,
       9,    32,   137,   559,    35,   561,   158,   135,   135,    40,
      81,    68,   129,    55,    76,    46,   679,   679,   681,   681,
     135,    34,     3,   129,    55,   129,    34,   129,   129,   585,
      34,    34,    94,    95,    34,   129,   129,   129,    69,    70,
      71,   129,   129,   706,   706,    76,   135,    78,    79,     3,
     129,   113,   129,   129,     3,   129,    34,   135,    34,   615,
     129,    92,   129,    94,    95,    96,   129,    98,    34,   129,
     101,   135,   134,   129,   105,   137,   107,   129,   109,    34,
     135,   135,   113,   129,   146,   147,   129,    34,   135,     5,
      34,   129,   129,     3,    10,    11,    12,    13,    34,   135,
     129,   135,    18,   134,    20,    21,   137,   138,   139,   129,
     141,   135,   129,   144,   145,   146,    32,   129,   129,    35,
      34,   135,   129,    34,    40,   135,    34,    34,   159,   160,
      46,   129,   129,   135,   135,   129,   135,   129,    25,    55,
     135,   129,   135,   129,   135,   135,   135,   129,   135,   129,
     135,   135,   135,    69,    70,    71,   135,   129,   135,    39,
      76,   135,    78,    79,   135,   135,   135,   129,   135,    16,
       9,    10,   135,    68,   135,   374,    92,   461,    94,    95,
      96,    20,    98,   331,   211,   101,   422,   257,   288,   105,
     403,   107,   417,   109,    -1,   321,    35,   113,   173,    -1,
      -1,    40,    10,    11,    12,    13,   403,    46,    -1,    -1,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,   134,    -1,
      -1,   137,   138,   139,    32,   141,    -1,    35,   144,   145,
     146,    -1,    40,    -1,    -1,    -1,    -1,    76,    46,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,
      78,    79,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,    -1,   134,    -1,   105,   106,   107,
      -1,   109,    -1,    -1,    -1,   113,    -1,   146,    -1,    -1,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,   134,    -1,    -1,   137,
     138,   139,    32,   141,    -1,    35,   144,   145,   146,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    94,    95,    96,    -1,    98,    -1,
      10,   101,    -1,    13,    -1,   105,    -1,   107,    -1,   109,
      20,    21,    -1,   113,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,   134,    -1,    46,   137,   138,   139,
      -1,   141,    -1,    -1,   144,   145,   146,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,   159,
     160,    -1,    -1,    26,    -1,    -1,    76,    -1,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    94,    95,    -1,    13,    -1,    -1,
      -1,    -1,    55,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    69,    70,    71,    35,
      -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,    -1,
      46,    -1,    -1,    -1,   134,    -1,    -1,   137,    -1,    92,
      -1,    94,    95,    96,    -1,    98,   146,   147,   101,    -1,
      -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,   134,    -1,    -1,   137,   138,   139,    32,   141,    -1,
      35,   144,   145,   146,    -1,    40,    -1,   113,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      -1,   137,    -1,    -1,    69,    70,    71,    -1,   144,   145,
     146,    76,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    -1,    -1,    -1,    -1,    92,    -1,    94,
      95,    96,    20,    98,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,   107,    -1,   109,    -1,    -1,    35,   113,    -1,
      -1,    -1,    40,    10,    11,    12,    13,    -1,    46,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,   134,
      -1,    -1,   137,   138,   139,    32,   141,    -1,    35,   144,
     145,   146,   147,    40,    -1,    -1,    -1,    -1,    76,    46,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,
      -1,    98,    -1,    -1,   101,    -1,   134,    -1,   105,    -1,
     107,    -1,   109,    -1,    -1,    -1,   113,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
     137,   138,   139,    10,   141,    -1,    13,   144,   145,   146,
     147,    -1,    -1,    20,    21,    -1,    10,    11,    12,    13,
      -1,    -1,   159,   160,    18,    -1,    20,    21,    35,    -1,
      -1,    -1,    26,    40,    -1,    -1,    -1,    -1,    32,    46,
      -1,    35,    -1,     3,     4,     5,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    22,    -1,    -1,    -1,    26,    -1,    -1,    76,
      -1,    -1,    32,    -1,    34,    69,    70,    71,    -1,    -1,
      -1,    -1,    76,    -1,    78,    79,    -1,    94,    95,    96,
      -1,    98,    -1,    53,    54,    -1,    -1,    -1,    92,    -1,
      94,    95,    96,    63,    98,    -1,   113,   101,    -1,    69,
      -1,   105,    -1,   107,    -1,   109,    -1,    77,    78,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
     137,    -1,    -1,    93,    -1,    -1,    96,    97,    98,   146,
     134,    -1,   102,   137,   138,   139,   106,   141,    -1,   109,
     144,   145,   146,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,   159,   160,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,
     140,    -1,    -1,    40,    -1,    -1,    -1,   147,    -1,    46,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    -1,    -1,    -1,    92,    -1,    94,    95,    96,
      20,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
     107,    -1,   109,    -1,    -1,    35,   113,    -1,    -1,    -1,
      40,    10,    11,    12,    13,    -1,    46,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,   134,    -1,    -1,
     137,   138,   139,    32,   141,    -1,    35,   144,   145,   146,
      -1,    40,    -1,    -1,    -1,    -1,    76,    46,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    -1,    -1,   113,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    92,    -1,    94,    95,    96,    20,    98,
      -1,    -1,   101,    -1,   134,    -1,   105,    -1,   107,    -1,
     109,    -1,    -1,    35,   113,    -1,   146,    -1,    40,    10,
      11,    12,    13,    -1,    46,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,   134,    -1,    -1,   137,   138,
     139,    32,   141,    -1,    35,   144,   145,   146,   147,    40,
      -1,    -1,    -1,    -1,    76,    46,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    94,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   134,    -1,   105,    -1,   107,    -1,   109,    -1,
      -1,    -1,   113,    -1,   146,    -1,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,   134,    -1,    -1,   137,   138,   139,    -1,
     141,    35,    -1,   144,   145,   146,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    55,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    -1,    70,    71,    -1,    -1,
      -1,    -1,    76,    24,    25,    79,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    92,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,   105,    -1,   107,    -1,    56,    -1,    58,    59,   113,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
     134,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,   110,
     111,    -1,    -1,    -1,   115,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,    -1,
     131,   132,    14,    15,    -1,    17,    -1,    19,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,   148,   149,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,     9,
      10,    -1,    74,    13,    -1,    -1,    78,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    99,   100,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,   110,   111,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,     9,    10,   126,   127,    13,    -1,    -1,   131,
     132,    -1,    -1,    20,    21,    -1,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    32,   148,   149,    35,    -1,
      -1,    -1,   154,    40,    94,    95,    -1,    10,    -1,    46,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,    39,    40,    -1,    76,
      -1,    78,    -1,    46,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    94,    95,    -1,
      10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    76,    -1,    78,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    94,    95,    -1,    -1,    -1,    46,   134,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     113,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    76,    -1,    13,    -1,
      -1,   134,    -1,    -1,   137,    20,    21,    -1,    -1,    -1,
      -1,   144,   145,   146,    94,    95,    -1,    32,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,   134,    -1,    -1,   137,    -1,    10,
      -1,    76,    13,    78,   144,   145,   146,    35,    -1,    20,
      21,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    94,
      95,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,    -1,   137,    -1,    -1,    76,    94,    95,    -1,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,   113,    -1,    -1,    -1,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,   113,    -1,    -1,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    35,    -1,   144,   145,   146,    40,
      -1,    -1,    -1,   134,    -1,    46,   137,    10,    -1,   140,
      13,   142,   143,    -1,    55,   146,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    76,    -1,    40,    10,    -1,
      -1,    13,    -1,    46,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,   113,    76,    46,    -1,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    94,    95,   134,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    76,   146,    40,    -1,    -1,    -1,
     113,    -1,    46,    -1,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    94,    95,    20,    21,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,   137,    -1,    -1,   140,    -1,    35,
     143,   113,    76,   146,    40,    10,    -1,    -1,    13,    -1,
      46,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      94,    95,   134,    -1,    -1,   137,    -1,    -1,   140,    -1,
      35,   143,    -1,    -1,   146,    40,    -1,    -1,    -1,   113,
      76,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    13,    -1,    -1,    -1,    94,    95,
     134,    20,    21,   137,    -1,    -1,    -1,    26,   142,   143,
      -1,    76,   146,    -1,    -1,    -1,    35,   113,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   113,    -1,
     146,    -1,    -1,    -1,    -1,    10,    -1,    76,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,   134,
      -1,    26,   137,    -1,    -1,    94,    95,    -1,   143,    -1,
      35,   146,    -1,    -1,    -1,    40,    10,    -1,    -1,    13,
      -1,    46,    -1,    -1,   113,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,   134,    40,    -1,   137,    -1,
      10,    76,    46,    13,    -1,    -1,    -1,   146,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    35,    34,    -1,    -1,    -1,
      40,    -1,    76,    -1,    -1,    -1,    46,    -1,   113,    47,
      48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      68,    -1,   137,    -1,    72,    73,    76,    -1,    -1,   113,
      78,   146,    -1,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    90,    91,    94,    95,    14,    15,    -1,    17,
     134,    -1,    -1,   137,    22,    -1,    24,    25,    -1,    27,
      28,    -1,   146,   113,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    49,    -1,    51,   134,    -1,    -1,   137,    56,    -1,
      58,    59,    -1,    61,    -1,    -1,   146,    -1,    66,    67,
      -1,    -1,    -1,    -1,   152,   153,    74,   155,   156,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,    -1,   126,   127,
      14,    15,    -1,   131,   132,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
     148,   149,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,   115,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,    -1,   126,   127,    -1,    -1,    -1,   131,   132,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,   148,   149,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,   120,    -1,   122,   123,    -1,
      -1,   126,   127,    14,    15,    -1,   131,   132,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    -1,    -1,
      -1,    32,    -1,   148,   149,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,    -1,
     131,   132,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,   148,   149,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,    -1,   126,   127,    -1,    -1,    -1,   131,
     132,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,   148,   149,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,    -1,   126,   127,    -1,    -1,    -1,   131,   132,
      14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,   148,   149,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,    -1,   126,   127,    14,    15,    -1,   131,   132,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    47,
      48,    -1,    32,    -1,   148,   149,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    72,    73,    56,    -1,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    86,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,
     110,   111,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
     120,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
      -1,   131,   132,    -1,   152,   153,    -1,   155,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    82,   162,   163,   164,     5,     0,     3,     9,    13,
      21,    64,   133,   137,   169,   172,   173,   174,   261,    30,
      31,    41,    42,    83,   114,   165,   166,   167,   168,    10,
     278,   172,   278,     3,   133,   172,     5,   112,   133,   170,
     171,    20,    32,    35,    39,    40,    46,    76,    78,    94,
      95,   113,   134,   144,   145,   146,   174,   176,   177,   178,
     179,   180,   181,   182,   183,   185,   186,   187,   190,   191,
     192,   194,   195,   196,   224,   225,   237,   261,   262,   278,
       9,     5,     5,     5,     5,     5,     5,   166,   167,   168,
     167,   168,   168,     3,     9,   172,     5,     3,   172,   278,
     112,   171,     5,   224,    43,   278,   187,   186,   191,   261,
      14,    15,    24,    25,    27,    28,    37,    38,    49,    51,
      56,    58,    59,    61,    66,    67,    85,    99,   100,   110,
     111,   116,   117,   119,   120,   122,   123,   126,   127,   131,
     132,   148,   149,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   223,   225,   226,   227,   231,   232,
     233,   234,   235,   236,     4,   106,   197,   140,   143,   196,
      26,    52,   176,   262,   278,   176,   278,   278,    11,   279,
     279,   279,   279,   279,   279,   167,   168,   168,   168,    78,
       3,   172,   172,     5,   278,   278,   140,   143,   196,     3,
       4,     4,    65,    74,   115,   201,   238,   239,    18,   183,
     184,   196,   200,   196,   200,    62,   196,   200,   196,   200,
     196,    12,    55,    69,    70,    71,    78,    79,    92,    96,
      98,   101,   105,   107,   109,   137,   138,   139,   141,   159,
     160,   196,   199,   200,   225,   240,   241,   247,   248,   249,
     250,   256,   257,   258,   261,   263,   264,   265,   266,   276,
     279,   280,   196,   240,   196,   196,   200,   140,   142,   143,
     196,    55,    63,   118,   137,   196,   229,   230,   240,   240,
      55,   137,   196,   198,   199,   183,   184,   196,   143,   196,
     196,     3,    26,   176,   278,     9,     3,     3,     3,     3,
       3,     3,   168,   175,   176,   183,   261,   172,     3,   172,
       5,     3,   143,   196,   196,     3,    17,    22,    74,   202,
     201,   238,   136,     3,     4,     5,   140,   193,   240,    44,
      26,   240,    26,   196,   147,   240,    26,   196,   196,   200,
     147,   240,   147,   196,    26,   240,    26,   196,   108,   109,
      45,    55,   121,   140,   225,   258,    34,    53,    54,    69,
      78,    98,   151,   243,   258,   259,   276,   277,   225,   258,
      96,    98,    26,    47,    48,    68,    72,    73,    78,    81,
      84,    86,    87,    88,    89,    90,    91,   124,   125,   152,
     153,   155,   156,   242,   243,   244,   245,   246,   267,   268,
     269,   270,   271,   272,   273,   274,   275,     4,    22,    93,
      97,   106,   251,   252,   253,   254,   255,   196,   279,    16,
      75,   109,    26,    26,   240,    26,    26,   142,   143,   196,
     196,   196,    55,   118,   137,   102,    55,   118,    77,   102,
     147,   228,   240,   228,   230,   228,    55,   228,   196,     3,
       3,    78,     3,     3,   176,   172,     3,   172,     9,   188,
     189,   190,   261,   196,     3,     3,   202,    17,    19,    74,
     154,   202,   130,     3,   193,   140,     4,     5,   201,   240,
     196,    32,   196,   147,   240,   147,   196,    32,    32,   240,
     196,   146,    45,   140,    45,   196,   196,    53,   147,    33,
      98,    53,    98,   108,   109,   158,    60,   222,   222,    23,
      36,    50,    57,   128,   150,   157,   260,   196,   196,   196,
      34,   135,    29,    68,    81,    34,   135,    29,   196,   247,
     263,   248,   251,   249,   196,   137,   196,   196,   240,   240,
     196,   196,   196,   102,    55,   118,   137,   102,   198,   228,
     198,   228,   198,   240,     3,   175,   183,   172,   278,     9,
       3,   202,    17,    74,   202,   130,   145,    17,   202,   201,
       4,     5,     3,   240,    32,    32,   240,   196,   146,    45,
     146,   147,   108,   158,   147,   109,   158,   158,   108,   109,
      62,   103,    68,    34,    80,   137,    34,   135,    34,   135,
      81,    34,    80,   137,   248,   109,   137,   102,    55,   137,
     198,   198,     3,     3,     9,   278,   202,   130,    17,   202,
     202,   202,     3,   240,   196,   146,   108,   158,   109,   158,
     104,   135,    68,    80,    68,    34,    81,    34,    78,   129,
     135,    81,    80,   196,    55,   137,    55,   224,     9,    17,
     202,   202,   158,   135,   135,    68,    78,   129,   135,    81,
     129,    34,   135,    78,   129,    78,   129,   135,    55,     5,
     240,   224,   202,   135,   129,    34,   135,    78,   129,    78,
     129,   135,    34,   135,   129,    34,   129,    34,   135,   129,
      34,   135,    78,   129,   240,     3,     5,   240,    34,   135,
     129,    34,   129,    34,   135,   129,    34,   135,    78,   129,
     129,    34,   135,   129,    34,   135,   129,    34,    34,   135,
     129,    34,   129,    34,   135,     3,   240,     3,   129,    34,
     135,   129,    34,   135,   129,    34,    34,   135,   129,    34,
     129,    34,   135,   135,   129,   135,   129,    34,   135,   129,
     129,    34,   135,   129,    34,   135,   129,    34,     3,   135,
     129,   135,   129,    34,   135,   129,   129,    34,   135,   129,
      34,   135,   129,    34,   135,   135,   129,   135,   135,   129,
     135,   129,    34,   135,   129,   135,   135,   129,   135,   135,
     129,   135,   129,    34,   135,   129,   135,   135,   135,   129,
     135,   135,   135,   135,   129,   135,   135,   135
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   161,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   165,   166,   166,   167,   167,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   171,   171,   171,
     171,   172,   172,   172,   172,   173,   173,   174,   174,   174,
     174,   175,   175,   176,   176,   176,   176,   176,   176,   177,
     178,   179,   180,   181,   182,   183,   183,   184,   185,   185,
     186,   186,   187,   188,   188,   189,   189,   189,   189,   190,
     190,   191,   191,   192,   192,   192,   192,   192,   193,   193,
     193,   193,   193,   193,   193,   193,   194,   195,   195,   196,
     196,   196,   196,   196,   196,   196,   196,   197,   197,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   203,   204,   204,   204,   204,   204,   205,
     205,   206,   206,   206,   206,   206,   207,   207,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     210,   210,   210,   210,   210,   211,   211,   212,   213,   213,
     214,   214,   215,   215,   216,   216,   217,   217,   218,   218,
     218,   219,   219,   220,   220,   220,   221,   221,   222,   223,
     223,   223,   223,   223,   223,   224,   224,   224,   224,   225,
     225,   226,   226,   226,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   228,   228,   228,   229,   229,   229,   229,
     230,   230,   230,   230,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   237,   237,
     237,   237,   237,   238,   239,   239,   239,   240,   241,   242,
     242,   242,   242,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   246,   246,   247,   247,
     247,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   251,
     251,   251,   251,   252,   253,   254,   255,   256,   256,   256,
     256,   257,   257,   257,   257,   258,   258,   258,   258,   259,
     259,   259,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   261,   261,   261,   262,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   264,   265,   265,   265,   265,   265,
     266,   267,   267,   267,   267,   267,   267,   267,   267,   268,
     268,   269,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   275,   275,   276,   276,   276,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     278,   279,   280
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
       2,     1,     1,     3,     4,     6,     5,     7,     1,     1,
       1,     2,     2,     3,     2,     3,     1,     1,     3,     1,
       2,     2,     3,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     5,     6,     4,
       5,     6,     7,     5,     6,     7,     8,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     3,     4,     1,
       1,     2,     3,     5,     3,     4,     1,     1,     2,     3,
       5,     3,     4,     6,     3,     5,     4,     6,     1,     1,
       2,     3,     4,     3,     4,     1,     1,     2,     1,     1,
       2,     4,     1,     1,     2,     4,     1,     1,     2,     3,
       4,     1,     1,     2,     4,     4,     1,     1,     1,     2,
       3,     3,     3,     4,     4,     1,     2,     2,     3,     1,
       1,     4,     5,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     5,
       2,     5,     3,     6,     4,     1,     1,     2,     4,     1,
       1,     2,     2,     1,     1,     3,     4,     4,     5,     4,
       5,     5,     6,     2,     1,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     3,     1,
       2,     3,     3,     4,     4,     5,     4,     5,     5,     6,
       6,     7,     7,     8,     7,     8,     8,     9,     7,     8,
       8,     9,     8,     9,     9,    10,     7,     8,     8,     9,
       8,     9,     9,    10,     8,     9,     9,    10,     9,    10,
      10,    11,     7,     8,     8,     9,     8,     9,     9,    10,
       8,     9,     9,    10,     9,    10,    10,    11,     8,     9,
       9,    10,     9,    10,    10,    11,     9,    10,    10,    11,
      10,    11,    11,    12,     3,     4,     3,     4,     1,     1,
       1,     1,     2,     1,     3,     4,     1,     3,     1,     2,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     5,     1,     2,     3,     4,     5,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     3,
       3,     4,     2,     3,     3,     4,     3,     4,     4,     5,
       1,     1,     1
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   368,     0,   358,     0,   358,     0,   358,     0,   358,
       0,   363,     0,   368,     0,   358,     0,   358,     0,   358,
       0,   358,     0,   358,     0,   358,     0,   358,     0,   358,
       0,   220,     0
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
  "A", "ACCEPT", "ACCEPTS", "AFTER", "AFTERWARDS", "ALL", "ALSO", "AMOUNT",
  "AN", "AND", "ANNOUNCED", "APPOINT", "APPOINTS", "AS", "ASSIGN",
  "ASSIGNS", "AT", "AUTHOR", "AUTHORS", "BE", "BEEN", "BEING", "BINARY",
  "CERTIFIED", "CERTIFIES", "CERTIFY", "CLAUSE", "COMING", "COMMENT",
  "COMMENTS", "CONTRACT", "CONTRACTS", "CURRENT", "DATA", "DAY", "DAYS",
  "DECLARE", "DECLARED", "DECLARES", "DEFINED", "EQUAL", "EQUALING",
  "ESCROW", "FILE_", "FILED", "FILES", "FIX", "FIXED", "FIXES", "FOR",
  "FROM", "GENERAL", "GIVEN", "GRANT", "GRANTS", "GREATER", "HAS",
  "HERSELF", "HIMSELF", "HOUR", "HOURS", "IF", "IN", "INCOMING", "INTO",
  "IS", "ITSELF", "LEAST", "LESS", "LEX", "LEXON", "LIES", "MAY",
  "MILLISECOND", "MILLISECONDS", "MINUTE", "MINUTES", "MONTH", "MONTHS",
  "MYSELF", "NEITHER", "NEW", "NEXT", "NO", "NOR", "NOT", "NOTIFIES",
  "NOTIFY", "NOW", "OF", "OFF", "ON", "ONESELF", "OR", "OURSELVES",
  "PASSED", "PAST", "PAY", "PAYS", "PER", "PERSON", "PREAMBLE", "PROVIDED",
  "REGISTER", "REGISTERS", "REMAINDER", "REPAY", "REPAYS", "RESPECTIVE",
  "RETURN", "RETURNS", "SECOND", "SECONDS", "SEND", "SENDS", "SIGNED",
  "SMALLER", "SO", "TERMINATE", "TERMINATES", "TERMS", "TEXT", "THAN",
  "THAT", "THE", "THEMSELF", "THEMSELVES", "THEN", "THERE", "THEREFOR",
  "THEREFORE", "THESE", "THIS", "TIME", "TO", "TRANSFER", "TRANSFERS",
  "TRUE", "WAS", "WEEK", "WEEKS", "WITH", "YEAR", "YEARS", "YES", "YET",
  "YOURSELF", "YOURSELVES", "$accept", "Document", "Head", "Lex", "Lexon",
  "Authors", "Comment", "Preamble", "Terms", "Covenants", "Covenant",
  "Provisions", "Definitions", "Definition", "Type_Term", "Type", "Person",
  "Amount", "Time", "Binary", "Text", "Data", "This_Contract",
  "All_Contracts", "This", "Clauses", "Clause", "Body", "Function",
  "Statements", "Statement", "Action", "Punctuation", "Subject", "Symbols",
  "Symbol", "Catena", "Object", "Reflexive", "Contract", "Predicates",
  "Predicate", "Permission", "Certification", "Certify", "Declaration",
  "Declare", "Filing", "File", "Registration", "Register", "Grantment",
  "Grant", "Appointment", "Appoint", "Assignment", "Assign", "Acceptance",
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
#line 1152 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 3012 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1153 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 3018 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1159 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 3024 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1160 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3030 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1161 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3036 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1162 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3042 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1163 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3048 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1164 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3054 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1165 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3060 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1166 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3066 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1167 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 3072 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1168 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3078 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1169 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3084 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1170 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3090 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1171 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3096 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1172 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3102 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1173 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3108 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1174 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3114 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1180 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 3120 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1186 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 3126 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1192 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3132 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1193 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3138 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1199 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3144 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1200 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3150 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1206 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 3156 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1212 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3162 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1213 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3168 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1214 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3174 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1215 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3180 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1216 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3186 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1217 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3192 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1218 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3198 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1219 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3204 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1225 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3210 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1226 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3216 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1232 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3222 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1233 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3228 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1234 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3234 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1235 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3240 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1241 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3246 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1242 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3252 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1243 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3258 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1244 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3264 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1250 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3270 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1251 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3276 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1257 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3282 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1258 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3288 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1259 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3294 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1260 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3300 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1266 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3306 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1267 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3312 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1273 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 3318 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1274 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 3324 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1275 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 3330 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1276 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 3336 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1277 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 3342 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1278 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 3348 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1284 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 3354 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1290 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 3360 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1296 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 3366 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1302 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 3372 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1308 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 3378 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1314 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 3384 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1320 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3390 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1321 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3396 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1327 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 3402 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1333 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3408 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1334 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3414 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1340 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3420 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1341 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3426 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1347 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 3432 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1353 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 3438 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1354 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 3444 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1360 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3450 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1361 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3456 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1362 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3462 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1363 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3468 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1369 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3474 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1370 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3480 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1376 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3486 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1377 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3492 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1383 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3498 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1384 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3504 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Punctuation Predicates Separator  */
#line 1385 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Punctuation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Punctuation); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3510 "parser.c"
    break;

  case 86: /* Action: Subject Permission Comma Predicates Separator  */
#line 1386 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3516 "parser.c"
    break;

  case 87: /* Action: Subject Permission Comma Condition Punctuation Predicates Separator  */
#line 1387 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Punctuation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Punctuation); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3522 "parser.c"
    break;

  case 88: /* Punctuation: Comma  */
#line 1393 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3528 "parser.c"
    break;

  case 89: /* Punctuation: Colon  */
#line 1394 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3534 "parser.c"
    break;

  case 90: /* Punctuation: THEN  */
#line 1395 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3540 "parser.c"
    break;

  case 91: /* Punctuation: THEN Colon  */
#line 1396 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3546 "parser.c"
    break;

  case 92: /* Punctuation: Comma THEN  */
#line 1397 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3552 "parser.c"
    break;

  case 93: /* Punctuation: Comma THEN Colon  */
#line 1398 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3558 "parser.c"
    break;

  case 94: /* Punctuation: THEN Comma  */
#line 1399 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3564 "parser.c"
    break;

  case 95: /* Punctuation: Comma THEN Comma  */
#line 1400 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3570 "parser.c"
    break;

  case 96: /* Subject: Symbols  */
#line 1406 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3576 "parser.c"
    break;

  case 97: /* Symbols: Symbol  */
#line 1412 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3582 "parser.c"
    break;

  case 98: /* Symbols: Symbols Catena Symbol  */
#line 1413 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3588 "parser.c"
    break;

  case 99: /* Symbol: Name  */
#line 1419 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3594 "parser.c"
    break;

  case 100: /* Symbol: New Name  */
#line 1420 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3600 "parser.c"
    break;

  case 101: /* Symbol: Article Name  */
#line 1421 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3606 "parser.c"
    break;

  case 102: /* Symbol: Article New Name  */
#line 1422 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3612 "parser.c"
    break;

  case 103: /* Symbol: Type  */
#line 1423 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3618 "parser.c"
    break;

  case 104: /* Symbol: New Type  */
#line 1424 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3624 "parser.c"
    break;

  case 105: /* Symbol: Article Type  */
#line 1425 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3630 "parser.c"
    break;

  case 106: /* Symbol: Article New Type  */
#line 1426 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3636 "parser.c"
    break;

  case 107: /* Catena: OR  */
#line 1432 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3642 "parser.c"
    break;

  case 108: /* Catena: Comma  */
#line 1433 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3648 "parser.c"
    break;

  case 109: /* Object: Symbol  */
#line 1439 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3654 "parser.c"
    break;

  case 110: /* Object: Reflexive  */
#line 1440 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3660 "parser.c"
    break;

  case 111: /* Object: ESCROW  */
#line 1441 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3666 "parser.c"
    break;

  case 112: /* Object: THE ESCROW  */
#line 1442 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3672 "parser.c"
    break;

  case 113: /* Reflexive: MYSELF  */
#line 1448 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3678 "parser.c"
    break;

  case 114: /* Reflexive: YOURSELF  */
#line 1449 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3684 "parser.c"
    break;

  case 115: /* Reflexive: HERSELF  */
#line 1450 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3690 "parser.c"
    break;

  case 116: /* Reflexive: HIMSELF  */
#line 1451 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3696 "parser.c"
    break;

  case 117: /* Reflexive: ONESELF  */
#line 1452 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3702 "parser.c"
    break;

  case 118: /* Reflexive: ITSELF  */
#line 1453 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3708 "parser.c"
    break;

  case 119: /* Reflexive: THEMSELF  */
#line 1454 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3714 "parser.c"
    break;

  case 120: /* Reflexive: OURSELVES  */
#line 1455 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3720 "parser.c"
    break;

  case 121: /* Reflexive: YOURSELVES  */
#line 1456 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3726 "parser.c"
    break;

  case 122: /* Reflexive: THEMSELVES  */
#line 1457 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3732 "parser.c"
    break;

  case 123: /* Contract: This_Contract  */
#line 1463 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3738 "parser.c"
    break;

  case 124: /* Contract: All_Contracts  */
#line 1464 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3744 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma Predicate  */
#line 1470 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3750 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1471 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3756 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1472 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3762 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1473 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3768 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND Predicate  */
#line 1474 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3774 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1475 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3780 "parser.c"
    break;

  case 131: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1476 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3786 "parser.c"
    break;

  case 132: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1477 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3792 "parser.c"
    break;

  case 133: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1478 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3798 "parser.c"
    break;

  case 134: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1479 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3804 "parser.c"
    break;

  case 135: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1480 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3810 "parser.c"
    break;

  case 136: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1481 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3816 "parser.c"
    break;

  case 137: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1482 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3822 "parser.c"
    break;

  case 138: /* Predicates: Predicate  */
#line 1483 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3828 "parser.c"
    break;

  case 139: /* Predicate: Certification  */
#line 1489 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3834 "parser.c"
    break;

  case 140: /* Predicate: Declaration  */
#line 1490 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3840 "parser.c"
    break;

  case 141: /* Predicate: Filing  */
#line 1491 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3846 "parser.c"
    break;

  case 142: /* Predicate: Registration  */
#line 1492 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3852 "parser.c"
    break;

  case 143: /* Predicate: Grantment  */
#line 1493 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3858 "parser.c"
    break;

  case 144: /* Predicate: Appointment  */
#line 1494 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3864 "parser.c"
    break;

  case 145: /* Predicate: Assignment  */
#line 1495 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Assignment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Assignment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3870 "parser.c"
    break;

  case 146: /* Predicate: Acceptance  */
#line 1496 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Acceptance=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Acceptance); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3876 "parser.c"
    break;

  case 147: /* Predicate: Fixture  */
#line 1497 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3882 "parser.c"
    break;

  case 148: /* Predicate: Setting  */
#line 1498 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3888 "parser.c"
    break;

  case 149: /* Predicate: Payment  */
#line 1499 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3894 "parser.c"
    break;

  case 150: /* Predicate: Sending  */
#line 1500 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3900 "parser.c"
    break;

  case 151: /* Predicate: Notification  */
#line 1501 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3906 "parser.c"
    break;

  case 152: /* Predicate: Termination  */
#line 1502 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 3912 "parser.c"
    break;

  case 153: /* Permission: MAY  */
#line 1508 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 3918 "parser.c"
    break;

  case 154: /* Certification: Certify Symbol  */
#line 1514 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3924 "parser.c"
    break;

  case 155: /* Certification: Certify Symbol Expression  */
#line 1515 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3930 "parser.c"
    break;

  case 156: /* Certification: Certify Symbol AS Expression  */
#line 1516 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3936 "parser.c"
    break;

  case 157: /* Certification: Certify Contract Symbol  */
#line 1517 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3942 "parser.c"
    break;

  case 158: /* Certification: Certify Contract AS Symbol  */
#line 1518 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 3948 "parser.c"
    break;

  case 159: /* Certify: CERTIFY  */
#line 1524 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3954 "parser.c"
    break;

  case 160: /* Certify: CERTIFIES  */
#line 1525 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 3960 "parser.c"
    break;

  case 161: /* Declaration: Declare Symbol  */
#line 1531 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3966 "parser.c"
    break;

  case 162: /* Declaration: Declare Symbol Expression  */
#line 1532 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3972 "parser.c"
    break;

  case 163: /* Declaration: Declare Symbol TO BE Expression  */
#line 1533 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3978 "parser.c"
    break;

  case 164: /* Declaration: Declare Contract Symbol  */
#line 1534 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3984 "parser.c"
    break;

  case 165: /* Declaration: Declare Contract AS Symbol  */
#line 1535 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 3990 "parser.c"
    break;

  case 166: /* Declare: DECLARE  */
#line 1541 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 3996 "parser.c"
    break;

  case 167: /* Declare: DECLARES  */
#line 1542 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4002 "parser.c"
    break;

  case 168: /* Filing: File Symbol  */
#line 1548 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4008 "parser.c"
    break;

  case 169: /* Filing: File Symbol Expression  */
#line 1549 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4014 "parser.c"
    break;

  case 170: /* Filing: File Symbol TO BE Expression  */
#line 1550 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4020 "parser.c"
    break;

  case 171: /* Filing: File FOR Symbol  */
#line 1551 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4026 "parser.c"
    break;

  case 172: /* Filing: File FOR Symbol Expression  */
#line 1552 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4032 "parser.c"
    break;

  case 173: /* Filing: File FOR Symbol TO BE Expression  */
#line 1553 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4038 "parser.c"
    break;

  case 174: /* Filing: File Contract Symbol  */
#line 1554 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4044 "parser.c"
    break;

  case 175: /* Filing: File Contract TO BE Symbol  */
#line 1555 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4050 "parser.c"
    break;

  case 176: /* Filing: File FOR Contract Symbol  */
#line 1556 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4056 "parser.c"
    break;

  case 177: /* Filing: File FOR Contract TO BE Symbol  */
#line 1557 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4062 "parser.c"
    break;

  case 178: /* File: FILE_  */
#line 1563 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4068 "parser.c"
    break;

  case 179: /* File: FILES  */
#line 1564 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4074 "parser.c"
    break;

  case 180: /* Registration: Register Symbol  */
#line 1570 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4080 "parser.c"
    break;

  case 181: /* Registration: Register Symbol Expression  */
#line 1571 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4086 "parser.c"
    break;

  case 182: /* Registration: Register Symbol AS Expression  */
#line 1572 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4092 "parser.c"
    break;

  case 183: /* Registration: Register Contract Symbol  */
#line 1573 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4098 "parser.c"
    break;

  case 184: /* Registration: Register Contract AS Symbol  */
#line 1574 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4104 "parser.c"
    break;

  case 185: /* Register: REGISTER  */
#line 1580 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4110 "parser.c"
    break;

  case 186: /* Register: REGISTERS  */
#line 1581 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4116 "parser.c"
    break;

  case 187: /* Grantment: Grant Symbol  */
#line 1587 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 4122 "parser.c"
    break;

  case 188: /* Grant: GRANT  */
#line 1593 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4128 "parser.c"
    break;

  case 189: /* Grant: GRANTS  */
#line 1594 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4134 "parser.c"
    break;

  case 190: /* Appointment: Appoint Symbol  */
#line 1600 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4140 "parser.c"
    break;

  case 191: /* Appointment: Appoint Expression AS Symbol  */
#line 1601 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Appoint); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4146 "parser.c"
    break;

  case 192: /* Appoint: APPOINT  */
#line 1607 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4152 "parser.c"
    break;

  case 193: /* Appoint: APPOINTS  */
#line 1608 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4158 "parser.c"
    break;

  case 194: /* Assignment: Assign Symbol  */
#line 1614 "parser.y"
                                                                  { NEW(Assignment, *((Literal **)&yylval)); Assignment->Assign=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Assign); Assignment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Assignment)=process_assignment(Assignment); }
#line 4164 "parser.c"
    break;

  case 195: /* Assignment: Assign Expression AS Symbol  */
#line 1615 "parser.y"
                                                                  { NEW(Assignment, *((Literal **)&yylval)); Assignment->Assign=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Assign); Assignment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Assignment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Assignment)=process_assignment(Assignment); }
#line 4170 "parser.c"
    break;

  case 196: /* Assign: ASSIGN  */
#line 1621 "parser.y"
                                                                  { NEW(Assign, *((Literal **)&yylval)); ((*yyvalp).Assign)=process_assign(Assign); }
#line 4176 "parser.c"
    break;

  case 197: /* Assign: ASSIGNS  */
#line 1622 "parser.y"
                                                                  { NEW(Assign, *((Literal **)&yylval)); ((*yyvalp).Assign)=process_assign(Assign); }
#line 4182 "parser.c"
    break;

  case 198: /* Acceptance: Accept Symbol  */
#line 1628 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4188 "parser.c"
    break;

  case 199: /* Acceptance: Accept Symbol Expression  */
#line 1629 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4194 "parser.c"
    break;

  case 200: /* Acceptance: Accept Symbol AS Expression  */
#line 1630 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4200 "parser.c"
    break;

  case 201: /* Accept: ACCEPT  */
#line 1636 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4206 "parser.c"
    break;

  case 202: /* Accept: ACCEPTS  */
#line 1637 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4212 "parser.c"
    break;

  case 203: /* Fixture: Fix Symbol  */
#line 1643 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4218 "parser.c"
    break;

  case 204: /* Fixture: Fix Symbol AS Expression  */
#line 1644 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4224 "parser.c"
    break;

  case 205: /* Fixture: Fix Contract AS Symbol  */
#line 1645 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4230 "parser.c"
    break;

  case 206: /* Fix: FIX  */
#line 1651 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4236 "parser.c"
    break;

  case 207: /* Fix: FIXES  */
#line 1652 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4242 "parser.c"
    break;

  case 208: /* Fixed: FIXED  */
#line 1658 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 4248 "parser.c"
    break;

  case 209: /* Setting: Be Symbol  */
#line 1664 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4254 "parser.c"
    break;

  case 210: /* Setting: Be THEREFOR Symbol  */
#line 1665 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4260 "parser.c"
    break;

  case 211: /* Setting: Be THEREFORE Symbol  */
#line 1666 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4266 "parser.c"
    break;

  case 212: /* Setting: Be THEN Symbol  */
#line 1667 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4272 "parser.c"
    break;

  case 213: /* Setting: Be THEN THEREFOR Symbol  */
#line 1668 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4278 "parser.c"
    break;

  case 214: /* Setting: Be THEN THEREFORE Symbol  */
#line 1669 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4284 "parser.c"
    break;

  case 215: /* Illocutor: Be  */
#line 1675 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4290 "parser.c"
    break;

  case 216: /* Illocutor: Be AS  */
#line 1676 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4296 "parser.c"
    break;

  case 217: /* Illocutor: Be DEFINED  */
#line 1677 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4302 "parser.c"
    break;

  case 218: /* Illocutor: Be DEFINED AS  */
#line 1678 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4308 "parser.c"
    break;

  case 219: /* Be: BE  */
#line 1684 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4314 "parser.c"
    break;

  case 220: /* Be: IS  */
#line 1685 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4320 "parser.c"
    break;

  case 221: /* Payment: Pay Expression Preposition Object  */
#line 1691 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4326 "parser.c"
    break;

  case 222: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1692 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4332 "parser.c"
    break;

  case 223: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1693 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4338 "parser.c"
    break;

  case 224: /* Payment: Pay Escrow Preposition Object  */
#line 1694 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4344 "parser.c"
    break;

  case 225: /* Pay: PAY  */
#line 1700 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4350 "parser.c"
    break;

  case 226: /* Pay: PAYS  */
#line 1701 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4356 "parser.c"
    break;

  case 227: /* Pay: RETURN  */
#line 1702 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4362 "parser.c"
    break;

  case 228: /* Pay: RETURNS  */
#line 1703 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4368 "parser.c"
    break;

  case 229: /* Pay: REPAY  */
#line 1704 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4374 "parser.c"
    break;

  case 230: /* Pay: REPAYS  */
#line 1705 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4380 "parser.c"
    break;

  case 231: /* Pay: TRANSFER  */
#line 1706 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4386 "parser.c"
    break;

  case 232: /* Pay: TRANSFERS  */
#line 1707 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4392 "parser.c"
    break;

  case 233: /* Preposition: TO  */
#line 1713 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4398 "parser.c"
    break;

  case 234: /* Preposition: INTO  */
#line 1714 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4404 "parser.c"
    break;

  case 235: /* Preposition: OF  */
#line 1715 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4410 "parser.c"
    break;

  case 236: /* Escrow: ESCROW  */
#line 1721 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4416 "parser.c"
    break;

  case 237: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1722 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4422 "parser.c"
    break;

  case 238: /* Escrow: THE ESCROW  */
#line 1723 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4428 "parser.c"
    break;

  case 239: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1724 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4434 "parser.c"
    break;

  case 240: /* From_Escrow: FROM ESCROW  */
#line 1730 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4440 "parser.c"
    break;

  case 241: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1731 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4446 "parser.c"
    break;

  case 242: /* From_Escrow: FROM THE ESCROW  */
#line 1732 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4452 "parser.c"
    break;

  case 243: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1733 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4458 "parser.c"
    break;

  case 244: /* Sending: Send Expression Preposition Object  */
#line 1739 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 4464 "parser.c"
    break;

  case 245: /* Send: SEND  */
#line 1745 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4470 "parser.c"
    break;

  case 246: /* Send: SENDS  */
#line 1746 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4476 "parser.c"
    break;

  case 247: /* Notification: Notify Object  */
#line 1752 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4482 "parser.c"
    break;

  case 248: /* Notification: Notify Object Preposition Expression  */
#line 1753 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4488 "parser.c"
    break;

  case 249: /* Notify: NOTIFY  */
#line 1759 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4494 "parser.c"
    break;

  case 250: /* Notify: NOTIFIES  */
#line 1760 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4500 "parser.c"
    break;

  case 251: /* Termination: Terminate This_Contract  */
#line 1766 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4506 "parser.c"
    break;

  case 252: /* Termination: Terminate All_Contracts  */
#line 1767 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4512 "parser.c"
    break;

  case 253: /* Terminate: TERMINATE  */
#line 1773 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4518 "parser.c"
    break;

  case 254: /* Terminate: TERMINATES  */
#line 1774 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4524 "parser.c"
    break;

  case 255: /* Flagging: Illocutor Symbol Separator  */
#line 1780 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4530 "parser.c"
    break;

  case 256: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1781 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4536 "parser.c"
    break;

  case 257: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1782 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4542 "parser.c"
    break;

  case 258: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1783 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4548 "parser.c"
    break;

  case 259: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1784 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4554 "parser.c"
    break;

  case 260: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1785 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4560 "parser.c"
    break;

  case 261: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1786 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4566 "parser.c"
    break;

  case 262: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1787 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4572 "parser.c"
    break;

  case 263: /* Condition: If Expression  */
#line 1793 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4578 "parser.c"
    break;

  case 264: /* If: IF  */
#line 1799 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4584 "parser.c"
    break;

  case 265: /* If: GIVEN THAT  */
#line 1800 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4590 "parser.c"
    break;

  case 266: /* If: PROVIDED  */
#line 1801 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4596 "parser.c"
    break;

  case 267: /* Expression: Combination  */
#line 1807 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 4602 "parser.c"
    break;

  case 268: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1813 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 4608 "parser.c"
    break;

  case 269: /* Comparison_Operator: Equal  */
#line 1819 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4614 "parser.c"
    break;

  case 270: /* Comparison_Operator: Greater  */
#line 1820 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Greater=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Greater); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4620 "parser.c"
    break;

  case 271: /* Comparison_Operator: Less  */
#line 1821 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Less=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Less); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4626 "parser.c"
    break;

  case 272: /* Comparison_Operator: Later  */
#line 1822 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4632 "parser.c"
    break;

  case 273: /* Equal: EQUAL  */
#line 1828 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4638 "parser.c"
    break;

  case 274: /* Equal: EQUAL TO  */
#line 1829 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4644 "parser.c"
    break;

  case 275: /* Equal: EQUALING  */
#line 1830 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4650 "parser.c"
    break;

  case 276: /* Equal: IS  */
#line 1831 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4656 "parser.c"
    break;

  case 277: /* Equal: IS EQUAL  */
#line 1832 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4662 "parser.c"
    break;

  case 278: /* Equal: IS EQUAL TO  */
#line 1833 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4668 "parser.c"
    break;

  case 279: /* Equal: BEING  */
#line 1834 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4674 "parser.c"
    break;

  case 280: /* Equal: BEING EQUAL  */
#line 1835 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4680 "parser.c"
    break;

  case 281: /* Equal: BEING EQUAL TO  */
#line 1836 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4686 "parser.c"
    break;

  case 282: /* Greater: GREATER BEING GREATER  */
#line 1842 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4692 "parser.c"
    break;

  case 283: /* Greater: GREATER BEING GREATER THAN  */
#line 1843 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4698 "parser.c"
    break;

  case 284: /* Greater: GREATER THAN BEING GREATER  */
#line 1844 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4704 "parser.c"
    break;

  case 285: /* Greater: GREATER THAN BEING GREATER THAN  */
#line 1845 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4710 "parser.c"
    break;

  case 286: /* Greater: IS GREATER BEING GREATER  */
#line 1846 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4716 "parser.c"
    break;

  case 287: /* Greater: IS GREATER BEING GREATER THAN  */
#line 1847 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4722 "parser.c"
    break;

  case 288: /* Greater: IS GREATER THAN BEING GREATER  */
#line 1848 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4728 "parser.c"
    break;

  case 289: /* Greater: IS GREATER THAN BEING GREATER THAN  */
#line 1849 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4734 "parser.c"
    break;

  case 290: /* Less: LESS BEING LESS SMALLER BEING SMALLER  */
#line 1855 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4740 "parser.c"
    break;

  case 291: /* Less: LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1856 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4746 "parser.c"
    break;

  case 292: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1857 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4752 "parser.c"
    break;

  case 293: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1858 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4758 "parser.c"
    break;

  case 294: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1859 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4764 "parser.c"
    break;

  case 295: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1860 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4770 "parser.c"
    break;

  case 296: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1861 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4776 "parser.c"
    break;

  case 297: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1862 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4782 "parser.c"
    break;

  case 298: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1863 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4788 "parser.c"
    break;

  case 299: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1864 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4794 "parser.c"
    break;

  case 300: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1865 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4800 "parser.c"
    break;

  case 301: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1866 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4806 "parser.c"
    break;

  case 302: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1867 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4812 "parser.c"
    break;

  case 303: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1868 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4818 "parser.c"
    break;

  case 304: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1869 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4824 "parser.c"
    break;

  case 305: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1870 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4830 "parser.c"
    break;

  case 306: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1871 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4836 "parser.c"
    break;

  case 307: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1872 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4842 "parser.c"
    break;

  case 308: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1873 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4848 "parser.c"
    break;

  case 309: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1874 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4854 "parser.c"
    break;

  case 310: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1875 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4860 "parser.c"
    break;

  case 311: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1876 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4866 "parser.c"
    break;

  case 312: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1877 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4872 "parser.c"
    break;

  case 313: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1878 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4878 "parser.c"
    break;

  case 314: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1879 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4884 "parser.c"
    break;

  case 315: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1880 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4890 "parser.c"
    break;

  case 316: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1881 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4896 "parser.c"
    break;

  case 317: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1882 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4902 "parser.c"
    break;

  case 318: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1883 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4908 "parser.c"
    break;

  case 319: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1884 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4914 "parser.c"
    break;

  case 320: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1885 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4920 "parser.c"
    break;

  case 321: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1886 "parser.y"
                                                                                { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4926 "parser.c"
    break;

  case 322: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER  */
#line 1887 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4932 "parser.c"
    break;

  case 323: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1888 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4938 "parser.c"
    break;

  case 324: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1889 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4944 "parser.c"
    break;

  case 325: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1890 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4950 "parser.c"
    break;

  case 326: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1891 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4956 "parser.c"
    break;

  case 327: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1892 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4962 "parser.c"
    break;

  case 328: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1893 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4968 "parser.c"
    break;

  case 329: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1894 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4974 "parser.c"
    break;

  case 330: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1895 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4980 "parser.c"
    break;

  case 331: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1896 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4986 "parser.c"
    break;

  case 332: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1897 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4992 "parser.c"
    break;

  case 333: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1898 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 4998 "parser.c"
    break;

  case 334: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1899 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5004 "parser.c"
    break;

  case 335: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1900 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5010 "parser.c"
    break;

  case 336: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1901 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5016 "parser.c"
    break;

  case 337: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1902 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5022 "parser.c"
    break;

  case 338: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1903 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5028 "parser.c"
    break;

  case 339: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1904 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5034 "parser.c"
    break;

  case 340: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1905 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5040 "parser.c"
    break;

  case 341: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1906 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5046 "parser.c"
    break;

  case 342: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1907 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5052 "parser.c"
    break;

  case 343: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1908 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5058 "parser.c"
    break;

  case 344: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1909 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5064 "parser.c"
    break;

  case 345: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1910 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5070 "parser.c"
    break;

  case 346: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1911 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5076 "parser.c"
    break;

  case 347: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1912 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5082 "parser.c"
    break;

  case 348: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1913 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5088 "parser.c"
    break;

  case 349: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1914 "parser.y"
                                                                               { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5094 "parser.c"
    break;

  case 350: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1915 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5100 "parser.c"
    break;

  case 351: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1916 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5106 "parser.c"
    break;

  case 352: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1917 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5112 "parser.c"
    break;

  case 353: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1918 "parser.y"
                                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5118 "parser.c"
    break;

  case 354: /* Later: IS AT LEAST  */
#line 1924 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5124 "parser.c"
    break;

  case 355: /* Later: IS AT THE LEAST  */
#line 1925 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5130 "parser.c"
    break;

  case 356: /* Later: LIES AT LEAST  */
#line 1926 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5136 "parser.c"
    break;

  case 357: /* Later: LIES AT THE LEAST  */
#line 1927 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5142 "parser.c"
    break;

  case 358: /* Scalar_Expression: Symbol  */
#line 1933 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5148 "parser.c"
    break;

  case 359: /* Scalar_Expression: Scalar  */
#line 1934 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5154 "parser.c"
    break;

  case 360: /* Scalar_Expression: Point_In_Time  */
#line 1935 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5160 "parser.c"
    break;

  case 361: /* Scalar_Expression: ESCROW  */
#line 1936 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5166 "parser.c"
    break;

  case 362: /* Scalar_Expression: THE ESCROW  */
#line 1937 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5172 "parser.c"
    break;

  case 363: /* Combination: Combinor  */
#line 1943 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5178 "parser.c"
    break;

  case 364: /* Combination: Combinor Comma Combination  */
#line 1944 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5184 "parser.c"
    break;

  case 365: /* Combination: Combinor Comma Combinator Combination  */
#line 1945 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5190 "parser.c"
    break;

  case 366: /* Combinor: Combinand  */
#line 1951 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5196 "parser.c"
    break;

  case 367: /* Combinor: Combinand Combinator Combinor  */
#line 1952 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5202 "parser.c"
    break;

  case 368: /* Combinand: Symbol  */
#line 1958 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5208 "parser.c"
    break;

  case 369: /* Combinand: Symbol Expiration  */
#line 1959 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5214 "parser.c"
    break;

  case 370: /* Combinand: Symbol Timeliness  */
#line 1960 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Timeliness=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Timeliness); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5220 "parser.c"
    break;

  case 371: /* Combinand: Reflexive  */
#line 1961 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5226 "parser.c"
    break;

  case 372: /* Combinand: Description  */
#line 1962 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5232 "parser.c"
    break;

  case 373: /* Combinand: Article Description  */
#line 1963 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5238 "parser.c"
    break;

  case 374: /* Combinand: Scalar_Comparison  */
#line 1964 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5244 "parser.c"
    break;

  case 375: /* Combinand: Negation  */
#line 1965 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5250 "parser.c"
    break;

  case 376: /* Combinand: Existence  */
#line 1966 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5256 "parser.c"
    break;

  case 377: /* Combinand: Point_In_Time  */
#line 1967 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5262 "parser.c"
    break;

  case 378: /* Combinand: Expiration  */
#line 1968 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5268 "parser.c"
    break;

  case 379: /* Combinator: Or_  */
#line 1974 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5274 "parser.c"
    break;

  case 380: /* Combinator: And  */
#line 1975 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5280 "parser.c"
    break;

  case 381: /* Combinator: Neither  */
#line 1976 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5286 "parser.c"
    break;

  case 382: /* Combinator: Nor  */
#line 1977 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5292 "parser.c"
    break;

  case 383: /* Or_: OR  */
#line 1983 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 5298 "parser.c"
    break;

  case 384: /* And: AND  */
#line 1989 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 5304 "parser.c"
    break;

  case 385: /* Neither: NEITHER  */
#line 1995 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 5310 "parser.c"
    break;

  case 386: /* Nor: NOR  */
#line 2001 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 5316 "parser.c"
    break;

  case 387: /* Existence: Symbol Equal Fixed  */
#line 2007 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5322 "parser.c"
    break;

  case 388: /* Existence: THERE Be Symbol  */
#line 2008 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5328 "parser.c"
    break;

  case 389: /* Existence: Contract Be Symbol  */
#line 2009 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5334 "parser.c"
    break;

  case 390: /* Existence: Symbol Being True  */
#line 2010 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5340 "parser.c"
    break;

  case 391: /* Negation: Negator Symbol  */
#line 2016 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5346 "parser.c"
    break;

  case 392: /* Negation: Symbol Negator Fixed  */
#line 2017 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5352 "parser.c"
    break;

  case 393: /* Negation: THERE Negator Symbol  */
#line 2018 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5358 "parser.c"
    break;

  case 394: /* Negation: Contract Negator Symbol  */
#line 2019 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5364 "parser.c"
    break;

  case 395: /* Negator: NOT  */
#line 2025 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5370 "parser.c"
    break;

  case 396: /* Negator: Be NOT  */
#line 2026 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5376 "parser.c"
    break;

  case 397: /* Negator: NO  */
#line 2027 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5382 "parser.c"
    break;

  case 398: /* Negator: Be NO  */
#line 2028 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5388 "parser.c"
    break;

  case 399: /* Being: IS  */
#line 2034 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5394 "parser.c"
    break;

  case 400: /* Being: HAS BEEN  */
#line 2035 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5400 "parser.c"
    break;

  case 401: /* Being: WAS  */
#line 2036 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5406 "parser.c"
    break;

  case 402: /* True: TRUE  */
#line 2042 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5412 "parser.c"
    break;

  case 403: /* True: YES  */
#line 2043 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5418 "parser.c"
    break;

  case 404: /* True: CERTIFIED  */
#line 2044 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5424 "parser.c"
    break;

  case 405: /* True: DECLARED  */
#line 2045 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5430 "parser.c"
    break;

  case 406: /* True: ANNOUNCED  */
#line 2046 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5436 "parser.c"
    break;

  case 407: /* True: FILED  */
#line 2047 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5442 "parser.c"
    break;

  case 408: /* True: FILED FOR  */
#line 2048 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5448 "parser.c"
    break;

  case 409: /* True: SIGNED OFF  */
#line 2049 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5454 "parser.c"
    break;

  case 410: /* True: SIGNED OFF ON  */
#line 2050 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5460 "parser.c"
    break;

  case 411: /* Article: A  */
#line 2056 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5466 "parser.c"
    break;

  case 412: /* Article: AN  */
#line 2057 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5472 "parser.c"
    break;

  case 413: /* Article: THE  */
#line 2058 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5478 "parser.c"
    break;

  case 414: /* New: NEW  */
#line 2064 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5484 "parser.c"
    break;

  case 415: /* New: NEXT  */
#line 2065 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5490 "parser.c"
    break;

  case 416: /* New: COMING  */
#line 2066 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5496 "parser.c"
    break;

  case 417: /* New: INCOMING  */
#line 2067 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5502 "parser.c"
    break;

  case 418: /* Point_In_Time: Current_Time  */
#line 2073 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5508 "parser.c"
    break;

  case 419: /* Point_In_Time: Relative_Time  */
#line 2074 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5514 "parser.c"
    break;

  case 420: /* Current_Time: THE CURRENT TIME  */
#line 2080 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5520 "parser.c"
    break;

  case 421: /* Current_Time: THE THEN CURRENT TIME  */
#line 2081 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5526 "parser.c"
    break;

  case 422: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 2082 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5532 "parser.c"
    break;

  case 423: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 2083 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5538 "parser.c"
    break;

  case 424: /* Current_Time: NOW  */
#line 2084 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5544 "parser.c"
    break;

  case 425: /* Relative_Time: Duration PAST  */
#line 2090 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5550 "parser.c"
    break;

  case 426: /* Relative_Time: Duration PAST Symbol  */
#line 2091 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5556 "parser.c"
    break;

  case 427: /* Relative_Time: Duration IN THE PAST  */
#line 2092 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5562 "parser.c"
    break;

  case 428: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 2093 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5568 "parser.c"
    break;

  case 429: /* Relative_Time: Duration AFTER Symbol  */
#line 2094 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5574 "parser.c"
    break;

  case 430: /* Duration: Scalar_Expression Time_Unit  */
#line 2100 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 5580 "parser.c"
    break;

  case 431: /* Time_Unit: Years  */
#line 2106 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5586 "parser.c"
    break;

  case 432: /* Time_Unit: Months  */
#line 2107 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5592 "parser.c"
    break;

  case 433: /* Time_Unit: Weeks  */
#line 2108 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5598 "parser.c"
    break;

  case 434: /* Time_Unit: Days  */
#line 2109 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5604 "parser.c"
    break;

  case 435: /* Time_Unit: Hours  */
#line 2110 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5610 "parser.c"
    break;

  case 436: /* Time_Unit: Minutes  */
#line 2111 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5616 "parser.c"
    break;

  case 437: /* Time_Unit: Seconds  */
#line 2112 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5622 "parser.c"
    break;

  case 438: /* Time_Unit: Milliseconds  */
#line 2113 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5628 "parser.c"
    break;

  case 439: /* Years: YEAR  */
#line 2119 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5634 "parser.c"
    break;

  case 440: /* Years: YEARS  */
#line 2120 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5640 "parser.c"
    break;

  case 441: /* Months: MONTH  */
#line 2126 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5646 "parser.c"
    break;

  case 442: /* Months: MONTHS  */
#line 2127 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5652 "parser.c"
    break;

  case 443: /* Weeks: WEEK  */
#line 2133 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5658 "parser.c"
    break;

  case 444: /* Weeks: WEEKS  */
#line 2134 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5664 "parser.c"
    break;

  case 445: /* Days: DAY  */
#line 2140 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5670 "parser.c"
    break;

  case 446: /* Days: DAYS  */
#line 2141 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5676 "parser.c"
    break;

  case 447: /* Hours: HOUR  */
#line 2147 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5682 "parser.c"
    break;

  case 448: /* Hours: HOURS  */
#line 2148 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5688 "parser.c"
    break;

  case 449: /* Minutes: MINUTE  */
#line 2154 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5694 "parser.c"
    break;

  case 450: /* Minutes: MINUTES  */
#line 2155 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5700 "parser.c"
    break;

  case 451: /* Seconds: SECOND  */
#line 2161 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5706 "parser.c"
    break;

  case 452: /* Seconds: SECONDS  */
#line 2162 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5712 "parser.c"
    break;

  case 453: /* Milliseconds: MILLISECOND  */
#line 2168 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5718 "parser.c"
    break;

  case 454: /* Milliseconds: MILLISECONDS  */
#line 2169 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 5724 "parser.c"
    break;

  case 455: /* Expiration: HAS PASSED  */
#line 2175 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5730 "parser.c"
    break;

  case 456: /* Expiration: PAST  */
#line 2176 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5736 "parser.c"
    break;

  case 457: /* Expiration: IS PAST  */
#line 2177 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 5742 "parser.c"
    break;

  case 458: /* Timeliness: NOT PASSED  */
#line 2183 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5748 "parser.c"
    break;

  case 459: /* Timeliness: NOT YET PASSED  */
#line 2184 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5754 "parser.c"
    break;

  case 460: /* Timeliness: HAS NOT PASSED  */
#line 2185 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5760 "parser.c"
    break;

  case 461: /* Timeliness: HAS NOT YET PASSED  */
#line 2186 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5766 "parser.c"
    break;

  case 462: /* Timeliness: NOT PAST  */
#line 2187 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5772 "parser.c"
    break;

  case 463: /* Timeliness: NOT PAST YET  */
#line 2188 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5778 "parser.c"
    break;

  case 464: /* Timeliness: NOT YET PAST  */
#line 2189 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5784 "parser.c"
    break;

  case 465: /* Timeliness: NOT YET PAST YET  */
#line 2190 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5790 "parser.c"
    break;

  case 466: /* Timeliness: IS NOT PAST  */
#line 2191 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5796 "parser.c"
    break;

  case 467: /* Timeliness: IS NOT PAST YET  */
#line 2192 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5802 "parser.c"
    break;

  case 468: /* Timeliness: IS NOT YET PAST  */
#line 2193 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5808 "parser.c"
    break;

  case 469: /* Timeliness: IS NOT YET PAST YET  */
#line 2194 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 5814 "parser.c"
    break;

  case 470: /* Name: NAME  */
#line 2198 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 5820 "parser.c"
    break;

  case 471: /* Description: DESCRIPTION  */
#line 2201 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 5826 "parser.c"
    break;

  case 472: /* Scalar: SCALAR  */
#line 2204 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 5832 "parser.c"
    break;


#line 5836 "parser.c"

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




#line 2209 "parser.y"


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
	// Action->Punctuation
	return Action;
}

Punctuation *process_punctuation(Punctuation *Punctuation) {
	if(opt_debug_actions) printf("actions: parsing Punctuation '%s'\n", Punctuation->Literal);
	return Punctuation;
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
	// Predicate->Assignment
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

Assignment *process_assignment(Assignment *Assignment) {
	if(opt_debug_actions) printf("actions: parsing Assignment '%s'\n", Assignment->Literal);
	// Assignment->Assign
	// Assignment->Symbol
	// Assignment->Expression
	return Assignment;
}

Assign *process_assign(Assign *Assign) {
	if(opt_debug_actions) printf("actions: parsing Assign '%s'\n", Assign->Literal);
	return Assign;
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
	// Setting->Be
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

