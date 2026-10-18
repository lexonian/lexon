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
  YYSYMBOL_SET = 128,                      /* SET  */
  YYSYMBOL_SETS = 129,                     /* SETS  */
  YYSYMBOL_SIGNED = 130,                   /* SIGNED  */
  YYSYMBOL_SMALLER = 131,                  /* SMALLER  */
  YYSYMBOL_SO = 132,                       /* SO  */
  YYSYMBOL_TERMINATE = 133,                /* TERMINATE  */
  YYSYMBOL_TERMINATES = 134,               /* TERMINATES  */
  YYSYMBOL_TERMS = 135,                    /* TERMS  */
  YYSYMBOL_TEXT = 136,                     /* TEXT  */
  YYSYMBOL_THAN = 137,                     /* THAN  */
  YYSYMBOL_THAT = 138,                     /* THAT  */
  YYSYMBOL_THE = 139,                      /* THE  */
  YYSYMBOL_THEMSELF = 140,                 /* THEMSELF  */
  YYSYMBOL_THEMSELVES = 141,               /* THEMSELVES  */
  YYSYMBOL_THEN = 142,                     /* THEN  */
  YYSYMBOL_THERE = 143,                    /* THERE  */
  YYSYMBOL_THEREFOR = 144,                 /* THEREFOR  */
  YYSYMBOL_THEREFORE = 145,                /* THEREFORE  */
  YYSYMBOL_THESE = 146,                    /* THESE  */
  YYSYMBOL_THIS = 147,                     /* THIS  */
  YYSYMBOL_TIME = 148,                     /* TIME  */
  YYSYMBOL_TO = 149,                       /* TO  */
  YYSYMBOL_TRANSFER = 150,                 /* TRANSFER  */
  YYSYMBOL_TRANSFERS = 151,                /* TRANSFERS  */
  YYSYMBOL_TRUE = 152,                     /* TRUE  */
  YYSYMBOL_WAS = 153,                      /* WAS  */
  YYSYMBOL_WEEK = 154,                     /* WEEK  */
  YYSYMBOL_WEEKS = 155,                    /* WEEKS  */
  YYSYMBOL_WITH = 156,                     /* WITH  */
  YYSYMBOL_YEAR = 157,                     /* YEAR  */
  YYSYMBOL_YEARS = 158,                    /* YEARS  */
  YYSYMBOL_YES = 159,                      /* YES  */
  YYSYMBOL_YET = 160,                      /* YET  */
  YYSYMBOL_YOURSELF = 161,                 /* YOURSELF  */
  YYSYMBOL_YOURSELVES = 162,               /* YOURSELVES  */
  YYSYMBOL_YYACCEPT = 163,                 /* $accept  */
  YYSYMBOL_Document = 164,                 /* Document  */
  YYSYMBOL_Head = 165,                     /* Head  */
  YYSYMBOL_Lex = 166,                      /* Lex  */
  YYSYMBOL_Lexon = 167,                    /* Lexon  */
  YYSYMBOL_Authors = 168,                  /* Authors  */
  YYSYMBOL_Comment = 169,                  /* Comment  */
  YYSYMBOL_Preamble = 170,                 /* Preamble  */
  YYSYMBOL_Terms = 171,                    /* Terms  */
  YYSYMBOL_Covenants = 172,                /* Covenants  */
  YYSYMBOL_Covenant = 173,                 /* Covenant  */
  YYSYMBOL_Provisions = 174,               /* Provisions  */
  YYSYMBOL_Definitions = 175,              /* Definitions  */
  YYSYMBOL_Definition = 176,               /* Definition  */
  YYSYMBOL_Type_Term = 177,                /* Type_Term  */
  YYSYMBOL_Type = 178,                     /* Type  */
  YYSYMBOL_Person = 179,                   /* Person  */
  YYSYMBOL_Amount = 180,                   /* Amount  */
  YYSYMBOL_Time = 181,                     /* Time  */
  YYSYMBOL_Binary = 182,                   /* Binary  */
  YYSYMBOL_Text = 183,                     /* Text  */
  YYSYMBOL_Data = 184,                     /* Data  */
  YYSYMBOL_This_Contract = 185,            /* This_Contract  */
  YYSYMBOL_All_Contracts = 186,            /* All_Contracts  */
  YYSYMBOL_This = 187,                     /* This  */
  YYSYMBOL_Clauses = 188,                  /* Clauses  */
  YYSYMBOL_Clause = 189,                   /* Clause  */
  YYSYMBOL_Body = 190,                     /* Body  */
  YYSYMBOL_Function = 191,                 /* Function  */
  YYSYMBOL_Statements = 192,               /* Statements  */
  YYSYMBOL_Statement = 193,                /* Statement  */
  YYSYMBOL_Action = 194,                   /* Action  */
  YYSYMBOL_Punctuation = 195,              /* Punctuation  */
  YYSYMBOL_Subject = 196,                  /* Subject  */
  YYSYMBOL_Symbols = 197,                  /* Symbols  */
  YYSYMBOL_Symbol = 198,                   /* Symbol  */
  YYSYMBOL_Catena = 199,                   /* Catena  */
  YYSYMBOL_Object = 200,                   /* Object  */
  YYSYMBOL_Reflexive = 201,                /* Reflexive  */
  YYSYMBOL_Contract = 202,                 /* Contract  */
  YYSYMBOL_Predicates = 203,               /* Predicates  */
  YYSYMBOL_Predicate = 204,                /* Predicate  */
  YYSYMBOL_Permission = 205,               /* Permission  */
  YYSYMBOL_Certification = 206,            /* Certification  */
  YYSYMBOL_Certify = 207,                  /* Certify  */
  YYSYMBOL_Declaration = 208,              /* Declaration  */
  YYSYMBOL_Declare = 209,                  /* Declare  */
  YYSYMBOL_Filing = 210,                   /* Filing  */
  YYSYMBOL_File = 211,                     /* File  */
  YYSYMBOL_Registration = 212,             /* Registration  */
  YYSYMBOL_Register = 213,                 /* Register  */
  YYSYMBOL_Grantment = 214,                /* Grantment  */
  YYSYMBOL_Grant = 215,                    /* Grant  */
  YYSYMBOL_Appointment = 216,              /* Appointment  */
  YYSYMBOL_Appoint = 217,                  /* Appoint  */
  YYSYMBOL_Assignment = 218,               /* Assignment  */
  YYSYMBOL_Assign = 219,                   /* Assign  */
  YYSYMBOL_Acceptance = 220,               /* Acceptance  */
  YYSYMBOL_Accept = 221,                   /* Accept  */
  YYSYMBOL_Fixture = 222,                  /* Fixture  */
  YYSYMBOL_Fix = 223,                      /* Fix  */
  YYSYMBOL_Fixed = 224,                    /* Fixed  */
  YYSYMBOL_Setting = 225,                  /* Setting  */
  YYSYMBOL_Illocutor = 226,                /* Illocutor  */
  YYSYMBOL_Be = 227,                       /* Be  */
  YYSYMBOL_Payment = 228,                  /* Payment  */
  YYSYMBOL_Pay = 229,                      /* Pay  */
  YYSYMBOL_Preposition = 230,              /* Preposition  */
  YYSYMBOL_Escrow = 231,                   /* Escrow  */
  YYSYMBOL_From_Escrow = 232,              /* From_Escrow  */
  YYSYMBOL_Sending = 233,                  /* Sending  */
  YYSYMBOL_Send = 234,                     /* Send  */
  YYSYMBOL_Notification = 235,             /* Notification  */
  YYSYMBOL_Notify = 236,                   /* Notify  */
  YYSYMBOL_Termination = 237,              /* Termination  */
  YYSYMBOL_Terminate = 238,                /* Terminate  */
  YYSYMBOL_Flagging = 239,                 /* Flagging  */
  YYSYMBOL_Condition = 240,                /* Condition  */
  YYSYMBOL_If = 241,                       /* If  */
  YYSYMBOL_After = 242,                    /* After  */
  YYSYMBOL_Expression = 243,               /* Expression  */
  YYSYMBOL_Scalar_Comparison = 244,        /* Scalar_Comparison  */
  YYSYMBOL_Comparison_Operator = 245,      /* Comparison_Operator  */
  YYSYMBOL_Equal = 246,                    /* Equal  */
  YYSYMBOL_Greater = 247,                  /* Greater  */
  YYSYMBOL_Less = 248,                     /* Less  */
  YYSYMBOL_Later = 249,                    /* Later  */
  YYSYMBOL_Scalar_Expression = 250,        /* Scalar_Expression  */
  YYSYMBOL_Combination = 251,              /* Combination  */
  YYSYMBOL_Combinor = 252,                 /* Combinor  */
  YYSYMBOL_Combinand = 253,                /* Combinand  */
  YYSYMBOL_Combinator = 254,               /* Combinator  */
  YYSYMBOL_Or_ = 255,                      /* Or_  */
  YYSYMBOL_And = 256,                      /* And  */
  YYSYMBOL_Neither = 257,                  /* Neither  */
  YYSYMBOL_Nor = 258,                      /* Nor  */
  YYSYMBOL_Existence = 259,                /* Existence  */
  YYSYMBOL_Negation = 260,                 /* Negation  */
  YYSYMBOL_Negator = 261,                  /* Negator  */
  YYSYMBOL_Being = 262,                    /* Being  */
  YYSYMBOL_True = 263,                     /* True  */
  YYSYMBOL_Article = 264,                  /* Article  */
  YYSYMBOL_New = 265,                      /* New  */
  YYSYMBOL_Point_In_Time = 266,            /* Point_In_Time  */
  YYSYMBOL_Current_Time = 267,             /* Current_Time  */
  YYSYMBOL_Relative_Time = 268,            /* Relative_Time  */
  YYSYMBOL_Duration = 269,                 /* Duration  */
  YYSYMBOL_Time_Unit = 270,                /* Time_Unit  */
  YYSYMBOL_Years = 271,                    /* Years  */
  YYSYMBOL_Months = 272,                   /* Months  */
  YYSYMBOL_Weeks = 273,                    /* Weeks  */
  YYSYMBOL_Days = 274,                     /* Days  */
  YYSYMBOL_Hours = 275,                    /* Hours  */
  YYSYMBOL_Minutes = 276,                  /* Minutes  */
  YYSYMBOL_Seconds = 277,                  /* Seconds  */
  YYSYMBOL_Milliseconds = 278,             /* Milliseconds  */
  YYSYMBOL_Expiration = 279,               /* Expiration  */
  YYSYMBOL_Timeliness = 280,               /* Timeliness  */
  YYSYMBOL_Name = 281,                     /* Name  */
  YYSYMBOL_Description = 282,              /* Description  */
  YYSYMBOL_Scalar = 283                    /* Scalar  */
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
#define YYLAST   4538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  485
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  842
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 12
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   417

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
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1161,  1161,  1162,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1189,  1195,  1201,  1202,  1208,  1209,  1215,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1234,  1235,  1241,  1242,  1243,
    1244,  1250,  1251,  1252,  1253,  1259,  1260,  1266,  1267,  1268,
    1269,  1275,  1276,  1282,  1283,  1284,  1285,  1286,  1287,  1293,
    1299,  1305,  1311,  1317,  1323,  1329,  1330,  1336,  1342,  1343,
    1349,  1350,  1356,  1362,  1363,  1369,  1370,  1371,  1372,  1378,
    1379,  1385,  1386,  1392,  1393,  1394,  1395,  1396,  1402,  1403,
    1404,  1405,  1406,  1407,  1408,  1409,  1415,  1421,  1422,  1428,
    1429,  1430,  1431,  1432,  1433,  1434,  1435,  1441,  1442,  1448,
    1449,  1450,  1451,  1457,  1458,  1459,  1460,  1461,  1462,  1463,
    1464,  1465,  1466,  1472,  1473,  1479,  1480,  1481,  1482,  1483,
    1484,  1485,  1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,
    1494,  1495,  1496,  1497,  1498,  1499,  1500,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,
    1519,  1525,  1531,  1532,  1533,  1534,  1535,  1541,  1542,  1548,
    1549,  1550,  1551,  1552,  1558,  1559,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1580,  1581,  1587,  1588,
    1589,  1590,  1591,  1597,  1598,  1604,  1610,  1611,  1617,  1618,
    1624,  1625,  1631,  1632,  1638,  1639,  1645,  1646,  1647,  1653,
    1654,  1660,  1661,  1662,  1668,  1669,  1670,  1671,  1677,  1678,
    1684,  1685,  1686,  1687,  1688,  1689,  1695,  1696,  1697,  1698,
    1704,  1705,  1711,  1712,  1713,  1714,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1733,  1734,  1735,  1741,  1742,  1743,
    1744,  1750,  1751,  1752,  1753,  1759,  1765,  1766,  1772,  1773,
    1779,  1780,  1786,  1787,  1793,  1794,  1800,  1801,  1802,  1803,
    1804,  1805,  1806,  1807,  1813,  1814,  1820,  1821,  1822,  1828,
    1834,  1840,  1846,  1847,  1848,  1849,  1855,  1856,  1857,  1858,
    1859,  1860,  1861,  1862,  1863,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  1876,  1882,  1883,  1884,  1885,  1886,  1887,  1888,
    1889,  1890,  1891,  1892,  1893,  1894,  1895,  1896,  1897,  1898,
    1899,  1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,  1908,
    1909,  1910,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  1918,
    1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,  1928,
    1929,  1930,  1931,  1932,  1933,  1934,  1935,  1936,  1937,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1945,  1951,  1952,  1953,
    1954,  1960,  1961,  1962,  1963,  1964,  1970,  1971,  1972,  1978,
    1979,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,  1993,
    1994,  1995,  2001,  2002,  2003,  2004,  2010,  2016,  2022,  2028,
    2034,  2035,  2036,  2037,  2043,  2044,  2045,  2046,  2052,  2053,
    2054,  2055,  2061,  2062,  2063,  2069,  2070,  2071,  2072,  2073,
    2074,  2075,  2076,  2077,  2083,  2084,  2085,  2091,  2092,  2093,
    2094,  2100,  2101,  2107,  2108,  2109,  2110,  2111,  2117,  2118,
    2119,  2120,  2121,  2127,  2133,  2134,  2135,  2136,  2137,  2138,
    2139,  2140,  2146,  2147,  2153,  2154,  2160,  2161,  2167,  2168,
    2174,  2175,  2181,  2182,  2188,  2189,  2195,  2196,  2202,  2203,
    2204,  2210,  2211,  2212,  2213,  2214,  2215,  2216,  2217,  2218,
    2219,  2220,  2221,  2225,  2228,  2231
};
#endif

#define YYPACT_NINF (-406)
#define YYTABLE_NINF (-391)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    65,   127,   212,   487,   130,  -406,   101,   130,  -406,
    -406,   133,   148,  -406,   -74,  -406,   708,  -406,   195,   244,
     247,   255,   259,   279,   291,   346,   203,   178,  -406,  -406,
     306,  -406,   307,   101,   370,  -406,    33,   130,   246,   -74,
    -406,  -406,  -406,  -406,   373,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,   191,   281,   364,  -406,  2316,  -406,
    -406,  3575,    59,  -406,  2556,   344,  -406,    25,   106,  -406,
     130,   404,   404,   404,   404,   404,   404,   203,   178,  -406,
     178,  -406,  -406,  -406,   340,  -406,   100,   101,  -406,   417,
     130,  -406,   130,  2590,  -406,  -406,  -406,   364,  -406,  1158,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,   300,  -406,  2132,  -406,  2447,
    -406,  2447,  -406,  2378,  -406,  2447,  -406,  2875,  -406,  1981,
    -406,  1981,  -406,  2875,  -406,  2447,  -406,  2476,  -406,  1118,
    -406,  1981,  -406,  2079,  -406,     3,  -406,  -406,  2875,  2673,
    2875,   431,  -406,   410,  -406,   106,  -406,  -406,  -406,   435,
    -406,   442,   444,   451,   461,   469,   474,   178,  -406,  -406,
    -406,   528,   101,  -406,  -406,   154,   473,   489,  2735,  2875,
     501,  -406,  3096,  2975,  -406,   367,  -406,  -406,   308,    27,
    1981,  1981,   463,  -406,  -406,  1257,  2806,  1367,  2844,  2447,
    1477,  1782,  1622,  2846,  -406,  -406,  -406,   402,  -406,  -406,
     411,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,   304,
    -406,  -406,   441,  -406,  -406,   360,  -406,   441,   287,   485,
    -406,  4380,  -406,   508,   239,  -406,  -406,  2875,   515,   445,
    -406,  -406,   168,  -406,  -406,  -406,  1577,   495,  1761,   498,
     505,  2621,  2875,  2875,  -406,   129,   -27,   425,   263,   204,
     213,  1981,   267,   213,  -406,   477,  -406,   213,  -406,  -406,
    -406,  -406,  2875,   530,   531,  -406,  -406,  -406,  -406,   462,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,   540,  -406,   549,
      38,  -406,   101,  -406,   250,  1278,  2875,   554,   555,  -406,
    4296,  2253,   439,  -406,   368,    27,  -406,  -406,   447,  -406,
     386,  4296,  -406,  -406,  -406,  1981,  -406,  2875,  -406,   541,
    -406,  2875,  -406,  1871,  2295,   551,  -406,   552,  -406,  1981,
    -406,  2875,  -406,  -406,  -406,   448,  -406,    -8,   560,  2701,
    2875,   544,   450,  -406,    62,   470,   138,  -406,   -31,   -31,
      82,  -406,  -406,  2701,  2875,  -406,  -406,  2875,  -406,  -406,
     -22,  -406,  -406,   507,     6,   571,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  2552,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  1008,  -406,  -406,  -406,  -406,  1981,  -406,  -406,
    -406,  -406,  -406,  -406,  2875,   467,  2875,  2875,  1981,  -406,
    1981,  2875,  2875,  2875,  -406,  -406,  -406,  -406,   506,   -12,
     468,   271,   510,  -406,  -406,  -406,  2079,   213,  2079,   213,
    2079,  -406,  1981,   610,  -406,  -406,   528,  -406,  -406,  -406,
    -406,   101,  -406,   130,  -406,  -406,  2407,   285,   612,  -406,
    -406,  -406,  4296,  3338,   484,  3217,   475,  -406,  3696,  -406,
    4296,   403,  -406,  -406,   437,  -406,  -406,  1981,  -406,   588,
    -406,   589,  -406,  1981,  2875,  -406,  -406,  -406,   476,   578,
     478,  -406,  -406,   480,  -406,  -406,    77,   481,    28,  -406,
     465,   343,  -406,  -406,  -406,  -406,  -406,  -406,  -406,   569,
     532,  -406,  -406,  -406,  -406,  -406,  -406,   566,   605,   -61,
      22,    34,   561,   611,    16,  -406,  2982,  -406,  -406,  1981,
    -406,  -406,   535,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
     509,  -406,   545,   591,   513,  -406,  2079,  -406,  2079,  -406,
    -406,  -406,   646,   653,  -406,   648,   130,  -406,  -406,  4296,
     533,  -406,  3817,  4296,  3459,   534,  -406,  4296,  4296,  -406,
     458,  -406,  -406,  -406,  -406,  1981,  2875,  -406,  -406,  -406,
     512,  -406,  -406,  -406,   563,  -406,   519,   559,  -406,  -406,
     520,  -406,   565,   547,   613,  -406,   602,   617,   652,   607,
     655,   229,   614,  -406,   619,  -406,  2875,   636,   553,  -406,
     638,  -406,  -406,  -406,  -406,   191,   685,  -406,  3938,  4296,
    -406,  -406,  4296,   568,  -406,  4059,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,   542,  -406,  -406,  -406,   567,  -406,
     570,   635,   339,   627,   580,    41,   -72,   353,  -406,  -406,
    -406,   657,  -406,   788,   191,  4296,  -406,  -406,  -406,  4180,
    4296,  -406,  -406,  -406,  -406,   577,   584,    42,   196,   365,
      52,   593,   688,   594,    55,   596,    58,   262,  -406,  1981,
     727,   898,  -406,  4296,  -406,  -406,  -406,    64,   600,   698,
     603,    66,   604,    83,   296,   606,   699,   599,   608,    91,
     618,   704,    95,   621,   707,   622,   114,   739,  -406,  1981,
     742,  -406,   624,   722,   620,   628,   128,   629,   724,   142,
     630,   728,   632,   143,   631,   633,  -406,   634,   644,   731,
     639,   649,   650,   732,   645,   654,   149,   656,   733,  -406,
     766,  -406,   651,   658,  -406,   660,   659,   749,   667,   664,
     674,   757,   670,   679,   162,   680,   779,  -406,   677,  -406,
     678,   686,  -406,   681,   682,   691,  -406,   687,   694,   782,
     689,   696,  -406,  -406,   692,  -406,   693,   700,  -406,   695,
     701,   702,  -406,   705,   706,   801,   709,   710,  -406,  -406,
     711,  -406,  -406,   712,  -406,   713,   714,  -406,   715,  -406,
    -406,   716,  -406,  -406,   723,  -406,   725,   720,  -406,   726,
    -406,  -406,  -406,   734,  -406,  -406,  -406,  -406,   735,  -406,
    -406,  -406
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,   424,
     425,     0,     0,   426,     2,    27,    41,    45,     0,     0,
       0,     0,     0,     0,     0,    12,     8,     6,     5,   483,
       0,    28,     0,     0,     0,    31,     0,     0,     0,     3,
      35,    60,   230,    62,     0,   429,    64,   430,   231,   427,
     428,    59,    63,    69,    68,    61,    46,   103,    53,    54,
      55,    56,    57,    58,     0,     0,    42,    70,    43,    79,
      81,     0,    96,    97,     0,   226,    82,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,    16,    14,    13,
      10,     9,     7,    20,     0,    32,     0,     0,    29,     0,
       0,    36,     0,     0,    65,    66,    71,    44,    80,     0,
     209,   210,   200,   201,   204,   205,   168,   167,   174,   175,
     186,   187,   214,   215,   196,   197,   161,   261,   260,   236,
     237,   193,   194,   240,   241,   238,   239,   256,   257,   216,
     217,   264,   265,   242,   243,     0,   146,     0,   147,     0,
     148,     0,   149,     0,   150,     0,   151,     0,   152,     0,
     153,     0,   154,     0,   155,     0,   156,     0,   157,     0,
     158,     0,   159,     0,   160,     0,   108,   107,     0,     0,
       0,     0,   227,   228,   105,     0,   101,   104,   100,     0,
     484,     0,     0,     0,     0,     0,     0,    18,    17,    15,
      11,     0,     0,    33,    30,     0,     0,     0,     0,     0,
       0,    83,     0,     0,   279,     0,   276,   278,     0,     0,
       0,     0,     0,   123,   124,   162,     0,   169,     0,     0,
     176,     0,   188,     0,   195,   485,   374,     0,   115,   116,
     231,   118,   113,   410,   408,   437,   117,   120,   469,   426,
     119,   122,     0,   114,   121,   371,   384,     0,     0,     0,
     387,     0,   280,   376,   379,   389,   388,     0,     0,   373,
     431,   432,     0,   391,   385,   372,   371,     0,   206,   211,
       0,     0,     0,     0,   220,   374,     0,     0,   426,   371,
       0,     0,     0,     0,   111,   426,   109,   258,   110,   262,
     263,    98,     0,     0,     0,   266,   229,   106,   102,     0,
      22,    23,    24,    25,    21,    26,    19,     0,    51,     0,
       0,    34,     0,    37,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   125,     0,     0,   277,    84,    88,    89,
      90,     0,   274,   275,    67,     0,   163,     0,   165,     0,
     170,     0,   172,   179,     0,     0,   177,     0,   182,     0,
     189,     0,   191,   468,   470,     0,   375,     0,     0,     0,
       0,   292,   286,   288,     0,   412,   408,   414,     0,     0,
       0,   382,   383,     0,     0,   411,   409,     0,   458,   459,
       0,   460,   461,   289,     0,     0,   466,   467,   462,   463,
     454,   455,   464,   465,   456,   457,   452,   453,     0,   282,
     283,   284,   285,   443,   444,   445,   446,   447,   448,   449,
     450,   451,     0,   397,   398,   399,   396,     0,   392,   393,
     394,   395,   404,   386,     0,     0,   438,     0,     0,   207,
       0,     0,     0,     0,   223,   221,   222,   251,     0,     0,
       0,   375,     0,   245,   246,   244,     0,     0,     0,     0,
       0,   112,     0,     0,   268,   267,     0,    47,    49,    52,
      38,     0,    39,     0,    72,    74,    73,     0,     0,   272,
     271,   126,     0,     0,     0,     0,     0,   129,     0,    86,
       0,    92,    94,    91,     0,   164,   166,     0,   173,     0,
     180,     0,   184,     0,     0,   190,   192,   433,     0,     0,
       0,   401,   406,   293,   287,   413,     0,   290,     0,   471,
     475,     0,   218,   219,   400,   405,   419,   417,   418,   420,
       0,   415,   416,   403,   402,   407,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   371,   281,   373,   377,     0,
     380,   442,     0,   439,   203,   208,   212,   213,   224,   225,
       0,   253,     0,     0,     0,   235,     0,   232,     0,   255,
     259,   269,     0,     0,    40,     0,     0,   273,   130,     0,
       0,   133,     0,     0,     0,     0,   137,     0,     0,   127,
       0,    95,    93,    85,   171,     0,     0,   178,   183,   435,
       0,   434,   294,   473,     0,   291,   479,     0,   476,   472,
     477,   421,   422,   295,     0,   367,     0,     0,     0,     0,
       0,     0,     0,   369,     0,   378,   440,     0,     0,   248,
       0,   233,   234,    48,    50,     0,     0,   134,     0,     0,
     131,   138,     0,     0,   141,     0,   145,   128,    87,   181,
     185,   436,   474,   480,   481,   478,   423,   296,   297,   368,
     299,     0,     0,     0,     0,     0,     0,     0,   370,   441,
     252,     0,   250,     0,     0,     0,   135,   132,   142,     0,
       0,   139,   482,   298,   300,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,     0,
       0,     0,   136,     0,   143,   140,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,   144,     0,     0,   335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,     0,   304,   305,     0,     0,
     311,     0,     0,     0,   319,     0,     0,     0,     0,    76,
       0,    77,   339,     0,   336,   337,     0,     0,   343,     0,
       0,     0,   351,     0,     0,     0,     0,   308,   309,   306,
     315,     0,   312,   313,   323,     0,   320,   321,     0,     0,
     327,     0,    78,   340,   341,   338,   347,     0,   344,   345,
     355,     0,   352,   353,     0,     0,   359,     0,   310,   316,
     317,   314,   324,   325,   322,   331,     0,   328,   329,   342,
     348,   349,   346,   356,   357,   354,   363,     0,   360,   361,
     318,   326,   332,   333,   330,   350,   358,   364,   365,   362,
     334,   366
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -406,  -406,  -406,  -406,  -406,   811,   312,     0,  -406,  -406,
     800,    11,  -406,   845,   399,   -54,  -406,  -406,  -406,  -406,
    -406,  -406,   -11,   703,  -406,   802,   260,  -406,  -406,   543,
     -65,  -406,   538,  -406,  -406,   336,  -406,  -375,  -171,   277,
    -136,    71,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,   490,  -406,   -63,    -2,  -406,  -406,  -277,  -406,   582,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,   662,  -406,  -406,
     -97,  -406,  -406,   615,  -406,  -406,  -406,   471,  -405,   454,
    -406,   455,  -406,  -406,  -406,  -406,  -406,  -406,   338,  -406,
    -406,    -3,   -68,   479,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,    79,  -406,     2,   -33,
    -406
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    25,    26,    27,    28,    14,    39,
      40,    15,    16,    17,   317,    57,    58,    59,    60,    61,
      62,    63,   223,   224,    65,    66,    67,   474,   475,    68,
      69,    70,   341,    71,    72,   289,   178,   297,   256,   257,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   524,   166,    74,   258,   168,   169,   456,   290,   291,
     170,   171,   172,   173,   174,   175,    76,   219,   220,   221,
     259,   260,   408,   378,   410,   411,   412,   261,   262,   263,
     264,   427,   428,   429,   430,   431,   265,   266,   267,   380,
     533,   109,    78,   269,   270,   271,   272,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   273,   382,    79,   274,
     275
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   103,   298,   108,    18,    64,   693,    30,    18,   185,
      32,   218,   537,    77,    75,   458,   460,   548,    31,   615,
     462,   222,    35,   184,   187,    89,    91,    92,   447,   522,
      18,   338,   339,    18,    80,    29,    97,   508,    37,    99,
     542,   185,     8,   561,    95,    41,     9,    98,   191,   192,
     193,   194,   195,   196,    10,   184,   617,    64,    41,   694,
      43,    38,    75,   176,   277,    45,    75,   105,   619,   167,
       5,    46,   292,    43,   293,   691,   708,   334,   616,   186,
     188,   565,   189,   567,    46,   569,   715,   198,   199,   720,
     200,   448,   723,    18,    18,   515,   623,   523,   732,     1,
     737,    47,   206,   202,   207,   526,   562,   203,   204,     8,
       8,   186,   449,     9,     9,   538,    29,   740,   527,    49,
      50,    10,    10,   342,   343,   748,    41,     6,   346,   752,
     350,   307,   528,   356,   509,   360,    33,   606,    51,   529,
      29,    43,     8,   543,   625,   167,     9,   318,   757,    53,
      54,    51,    46,    36,    10,   624,   268,   322,   268,   618,
     516,    52,   766,     8,   299,   177,   268,     9,   268,   340,
     363,   620,    13,    55,    52,    10,   770,   775,   692,   709,
     566,   439,   568,   788,   434,   603,    55,   308,   607,   716,
     319,   631,   721,   632,   457,   724,   804,   316,   320,    18,
     185,   733,    18,   738,    80,   494,  -247,  -381,  -381,  -381,
     167,   167,   530,   321,   184,     7,   323,   268,   268,    51,
     741,     8,   268,    42,   268,     9,  -381,   268,   749,   268,
    -381,  -247,   753,    10,   531,   433,    42,   604,   371,    13,
      13,   532,    52,   435,    21,    22,   519,   520,   495,    81,
     369,   758,    82,   471,    55,   383,   500,   372,   373,     8,
      83,   423,   505,     9,    84,   767,   469,  -381,    34,    48,
     186,    10,    13,   374,   710,   268,    11,   436,  -247,   771,
     776,  -381,   375,   333,    85,   298,   789,   298,   268,   298,
     453,    29,    24,    13,   576,    29,    86,  -381,   521,   805,
     243,  -381,   376,   211,   212,    41,  -381,   664,   365,    93,
    -381,   337,   212,   248,    64,   454,    94,    24,   451,    18,
      43,    18,   477,    75,   104,    45,   106,   711,   167,   167,
     286,    46,   424,   470,   381,   472,   425,    88,    90,   167,
     725,   555,   268,   556,   453,   426,  -381,    12,  -249,   365,
     268,    13,    73,  -381,   590,   381,   268,   377,   100,   366,
     665,    47,   455,  -198,  -198,   570,   666,   106,   381,   454,
     182,   489,   212,  -249,   742,    96,    19,    20,   102,    49,
      50,   452,  -381,   385,   367,   386,  -381,    21,    22,    13,
     492,   493,    42,   726,   371,   298,   183,   298,    51,   197,
     594,   481,   487,    44,    73,   368,   597,   591,   592,   185,
     181,   108,   318,   372,   373,   190,   455,   686,   201,   268,
    -249,    52,   205,   184,   268,   367,   226,   743,   228,   374,
     231,   695,   233,    55,   305,   268,   306,   268,   375,   210,
     593,   212,   280,   712,   309,   310,   368,   311,  -390,  -390,
    -390,   609,   610,  -381,   312,   573,   243,  -381,   376,   268,
      24,   648,   212,   320,   313,    64,  -381,  -390,    18,   248,
     687,  -390,   314,    42,    75,   575,   688,   315,   324,   186,
     167,   167,   574,   167,   696,   225,   167,   227,   167,   230,
     697,   232,   325,   234,   268,   255,   713,   276,   649,   278,
     268,   279,   714,   284,   329,   336,   354,   344,  -390,   296,
     363,   387,   422,   377,   301,   303,   304,    19,    20,    48,
     364,   437,  -390,   517,   440,    29,   190,   450,    21,    22,
    -289,   441,   461,   464,   465,    41,   539,   243,  -390,   244,
     466,     9,  -390,   467,   327,   328,   268,  -390,    41,    10,
      43,  -390,   468,   578,   581,    45,   586,   479,   480,   589,
     517,    46,   348,    43,   352,   353,  -231,   358,   518,   362,
      23,   488,   673,   497,    46,   540,   700,   167,   636,   364,
     167,   167,   167,   503,   504,   167,   167,  -390,   541,   491,
     370,    47,   268,   379,  -390,   384,   507,   513,  -289,   514,
     544,    24,   727,   432,   730,   510,   552,   563,   560,    49,
      50,   701,   564,   571,   379,   577,   582,   444,   445,   446,
     595,   596,   587,   600,   599,   608,   601,   379,    51,   602,
     605,   611,   760,    75,   613,   612,   167,   167,   463,   614,
     167,    51,   621,   167,   626,   622,   629,   628,   627,   633,
     637,    52,   630,   640,   641,   644,   634,   635,   646,   647,
     651,    73,   478,    55,    52,   638,   645,    13,   654,   656,
     268,   652,    75,   167,    53,    54,    55,   167,   167,   653,
     655,   658,   659,   496,   657,   660,   661,   498,   662,   663,
     502,   670,   671,   672,   674,   667,   268,   506,   268,   668,
     679,   167,   682,   685,   683,   511,   512,   684,   689,   676,
     677,   690,   698,   678,   706,   707,   681,     8,    29,   534,
     535,     9,   718,   536,   717,   719,   268,   722,    41,    10,
     728,   734,   735,   745,   736,   739,   746,   744,   751,   747,
      42,   755,   759,    43,   545,   761,   702,    44,    45,   750,
     704,   705,   754,   756,    46,   762,   763,   764,   769,   765,
     768,   772,   773,   774,   778,   781,   785,   791,   777,   792,
     551,   779,   553,   554,   731,   780,   782,   557,   558,   559,
     783,   784,   786,   797,    47,   787,    48,   790,   793,   794,
     796,   801,   296,   699,   296,   799,   296,   795,    29,   190,
     235,     9,    49,    50,   798,   800,   222,   802,    41,    10,
     803,   806,    73,   807,   808,   809,   816,   810,   811,   812,
      42,    51,   813,    43,   814,   815,   817,   818,    45,   819,
     820,   821,   822,   824,    46,   827,    87,   826,   823,   101,
     598,   829,   825,   236,    52,   833,   828,    13,   830,   831,
     832,   838,   834,   835,    53,    54,    55,   237,   238,   239,
     836,    56,   837,   839,    47,   572,   240,   241,   476,   525,
     107,   840,   841,   490,   459,   335,   409,   549,   300,   546,
     242,   550,    49,    50,   243,     0,   244,   547,     0,   245,
       0,     0,     0,   246,     0,   247,     0,   248,     0,     0,
       0,    51,   296,   729,   296,     0,     0,     0,    29,   190,
     235,     9,     0,     0,     0,     0,   222,     0,    41,    10,
       0,     0,     0,     0,    52,     0,     0,   249,   250,   251,
      42,   252,   650,    43,    53,    54,    55,     0,    45,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,   253,
     254,     0,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,   669,     0,     0,     0,     0,   237,   238,   239,
       0,     0,     0,     0,    47,     0,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,     0,    49,    50,   243,     0,   244,     0,     0,   245,
       0,     0,     0,   246,     0,   247,     0,   248,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,    29,   190,
     235,     9,     0,     0,     0,     0,   222,     0,    41,    10,
     423,     0,     0,     0,    52,     0,     0,   249,   250,   251,
      42,   252,     0,    43,    53,    54,    55,     0,    45,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,   253,
     254,     0,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,   238,   239,
       0,     0,     0,     0,    47,     0,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   424,    49,    50,   243,   425,   244,     0,     0,   245,
       0,     0,     0,   246,   426,   247,     0,   248,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,    29,   190,
     235,     9,     0,     0,     0,     0,   222,     0,    41,    10,
       0,     0,     0,     0,    52,     0,     0,   249,   250,   251,
      42,   252,     0,    43,    53,    54,    55,     0,    45,     0,
       0,     0,     0,     0,    46,     0,     0,     0,    29,   253,
     254,     0,     0,   285,     0,     0,     0,     0,    41,     0,
       0,   286,     0,     0,     0,     0,     0,   237,   238,   239,
       0,     0,     0,    43,    47,     0,   240,   241,    45,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
     242,     0,    49,    50,   243,     0,   244,     0,     0,   245,
       0,     0,     0,   246,     0,   247,     0,   248,     0,     0,
       0,    51,     0,     0,    47,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    50,    52,     0,     0,   288,   250,   251,
       0,   252,     0,     0,    53,    54,    55,    29,   190,   235,
       9,    51,     0,     0,     0,   222,     0,    41,    10,   253,
     254,     0,     0,   345,     0,     0,     0,   473,    29,    42,
       0,     9,    43,     0,    52,     0,     0,    45,    41,    10,
       0,     0,     0,    46,     0,     0,    55,     0,     0,     0,
      42,     0,   236,    43,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,    46,     0,   237,   238,   239,     0,
       0,     0,     0,    47,     0,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,    49,    50,   243,    47,   244,    48,     0,   245,     0,
       0,     0,   246,     0,   247,     0,   248,     0,     0,     0,
      51,     0,    49,    50,     0,     0,     0,    29,   190,   235,
       9,     0,     0,     0,     0,   222,     0,    41,    10,     0,
       0,    51,     0,    52,     0,     0,   249,   250,   251,    42,
     252,     0,    43,    53,    54,    55,     0,    45,     0,     0,
       0,     0,     0,    46,    52,     0,     0,    13,   253,   254,
       0,     0,   236,     0,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,    47,     0,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,    49,    50,   243,     0,   244,     0,     0,   245,     0,
       0,     0,   246,     0,   247,     0,   248,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,    29,   190,   235,
       9,     0,     0,     0,     0,   222,     0,    41,    10,     0,
       0,     0,     0,    52,     0,     0,   249,   250,   251,    42,
     252,     0,    43,    53,    54,    55,   349,    45,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,   253,   254,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,    47,     0,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,    49,    50,   243,     0,   244,     0,     0,   245,     0,
    -202,  -202,   246,     0,   247,     0,   248,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,  -381,
       0,     0,     0,  -381,     0,     0,     0,     0,     0,    42,
       0,   371,     0,    52,     0,     0,   249,   250,   251,     0,
     252,     0,     0,    53,    54,    55,   355,     0,     0,     0,
     372,   373,    29,   190,   235,     9,     0,     0,   253,   254,
     222,     0,    41,    10,     0,     0,   374,     0,   359,     0,
       0,     0,     0,     0,    42,   375,     0,    43,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,    46,     0,
    -381,     0,     0,   243,  -381,   376,     0,   236,     0,     0,
       0,     0,     0,  -381,     0,     0,   248,     0,     0,     0,
       0,   237,   238,   239,     0,     0,     0,     0,    47,     0,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,     0,    49,    50,   243,     0,
     244,     0,     0,   245,     0,     0,     0,   246,     0,   247,
     377,   248,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,   249,   250,   251,     0,   252,     0,     0,    53,    54,
      55,    29,   190,   235,     9,     0,     0,     0,     0,   222,
       0,    41,    10,   253,   254,     0,     0,   438,     0,     0,
       0,     0,    29,    42,     0,     9,    43,     0,     0,     0,
       0,    45,    41,    10,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,   236,    43,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,    46,     0,
     237,   238,   239,     0,     0,     0,     0,    47,     0,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,    49,    50,   243,    47,   244,
       0,     0,   245,     0,     0,     0,   246,     0,   247,     0,
     248,     0,     0,     0,    51,     0,    49,    50,     0,     0,
       0,    29,   190,   235,     9,     0,     0,     0,     0,   222,
       0,    41,    10,     0,     0,    51,     0,    52,     0,     0,
     249,   250,   251,    42,   252,     0,    43,    53,    54,    55,
       0,    45,     0,     0,     0,     0,     0,    46,    52,     0,
       0,    13,   253,   254,     0,     0,   236,     0,     0,     0,
      55,   357,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,    47,     0,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,    49,    50,   243,     0,   244,
       0,     0,   245,     0,     0,     0,   246,     0,   247,     0,
     248,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,    29,   190,   235,     9,     0,     0,     0,     0,   222,
       0,    41,    10,     0,     0,     0,     0,    52,     0,     0,
     249,   250,   251,    42,   252,     0,    43,    53,    54,    55,
     499,    45,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,   253,   254,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,    47,     0,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,    49,    50,   243,     0,   244,
       0,     0,   245,     0,     0,     0,   246,     0,   247,    29,
     248,     0,     9,     0,    51,     0,     0,     0,     0,    41,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    52,     0,    45,
     249,   250,   251,     0,   252,    46,     0,    53,    54,    55,
       0,     0,     0,     0,   294,     0,   213,     0,     0,     0,
       0,     0,   253,   254,     0,     0,   110,   111,   214,   238,
     239,     0,     0,     0,     0,    47,   112,   113,   241,   114,
     115,     0,     0,     0,    42,     0,     0,     0,     0,   116,
     117,   242,     0,    49,    50,     0,     0,     0,     0,     0,
       0,   118,     0,   119,   246,     0,   247,     0,   120,     0,
     121,   122,    51,   123,     0,     0,     0,   215,   124,   125,
       0,     0,     0,     0,     0,     0,   216,     0,     0,     0,
      48,     0,     0,     0,     0,    52,     0,     0,   295,   250,
     251,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   129,   130,     0,     0,     0,   217,   131,   132,
       0,   133,   134,     0,   135,   136,     0,     0,   137,   138,
     139,   140,     0,     0,     0,   141,   142,   110,   111,     0,
     482,     0,   483,     0,     0,     0,     0,   112,   113,     0,
     114,   115,   143,   144,     0,    42,     0,     0,     0,     0,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,   119,    29,     0,     0,     9,   120,
       0,   121,   122,     0,   123,    41,    10,     0,     0,   124,
     125,     0,     0,     0,     0,     0,    29,   484,     0,     9,
      43,    48,     0,     0,     0,    45,    41,    10,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    43,   127,   128,     0,    44,    45,     0,     0,     0,
       0,     0,    46,   129,   130,     0,     0,     0,     0,   131,
     132,    47,   133,   134,     0,   135,   136,     0,     0,   137,
     138,   139,   140,     0,     0,     0,   141,   142,    29,    49,
      50,     9,    47,     0,    48,   485,   222,     0,    41,    10,
       0,     0,     0,   143,   144,     0,     0,     0,    51,   486,
      49,    50,     0,    43,     0,     0,     0,    29,    45,     0,
       9,     0,     0,     0,    46,     0,     0,    41,    10,    51,
       0,    52,     0,     0,    13,     0,     0,     0,     0,    42,
     229,     0,    43,    55,   501,     0,     0,    45,     0,     0,
       0,     0,    52,    46,    47,    13,     0,    29,     0,     0,
       9,     0,    53,    54,    55,   222,     0,    41,    10,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    47,     0,    48,    29,    45,     0,     9,
       0,    51,     0,    46,     0,     0,    41,    10,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    52,     0,    45,    13,     0,     0,
      51,     0,    46,    47,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    52,     0,     0,    13,     0,     0,     0,
       0,     0,    47,    53,    54,    55,     0,     0,     0,     0,
      51,     0,    29,     0,   235,     9,    29,     0,     0,     9,
      49,    50,    41,    10,     0,     0,    41,    10,     0,     0,
       0,     0,     0,    52,     0,     0,    13,    43,     0,    51,
       0,    43,    45,    53,    54,    55,    45,     0,    46,     0,
      29,     0,    46,     9,     0,     0,     0,   236,     0,     0,
      41,    10,    52,     0,     0,    13,     0,     0,   281,     0,
     282,   283,     0,     0,    55,    43,     0,     0,    47,     0,
      45,    29,    47,     0,     9,     0,    46,     0,     0,     0,
       0,    41,    10,     0,     0,     0,    49,    50,     0,     0,
      49,    50,     0,   245,     0,     0,    43,     0,     0,     0,
       0,    45,     0,     0,     0,    51,    47,    46,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    49,    50,     9,     0,    52,     0,
       0,   249,    52,    41,    10,    13,     0,    47,   179,     0,
      55,   180,     0,    51,    55,     0,     0,     0,    43,     0,
       0,    29,     0,    45,     9,    49,    50,     0,     0,    46,
       0,    41,    10,     0,     0,     0,    52,     0,     0,    13,
       0,     0,   208,     0,    51,   209,    43,     0,    55,     0,
       0,    45,     0,     0,     0,    29,     0,    46,     9,    47,
       0,     0,     0,     0,     0,    41,    10,    52,     0,     0,
      13,     0,     0,     0,     0,   442,   443,    49,    50,    55,
      43,     0,     0,     0,     0,    45,     0,    47,     0,     0,
       0,    46,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    50,   385,     0,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,    47,    13,     0,    51,     0,    29,     0,   302,     9,
       0,    55,     0,     0,     0,     0,    41,    10,     0,    49,
      50,     0,   347,     0,     0,     0,     0,    52,     0,     0,
      13,    43,     0,     0,     0,     0,    45,     0,    51,    55,
       0,     0,    46,     0,    29,     0,    29,     9,     0,     9,
       0,     0,     0,     0,    41,    10,    41,    10,     0,     0,
     351,    52,   361,     0,    13,     0,     0,     0,     0,    43,
     326,    43,    47,    55,    45,    29,    45,     0,     9,     0,
      46,     0,    46,     0,     0,    41,    10,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,    45,     0,     0,     0,    51,
      47,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      49,    50,    52,     0,     0,    13,     0,     0,     0,     0,
       0,    47,     0,     0,    55,     0,     0,    51,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    52,    13,     0,    13,     0,     0,    51,   110,
     111,   214,    55,     0,    55,     0,     0,     0,     0,   112,
     113,     0,   114,   115,     0,     0,     0,    42,     0,     0,
       0,    52,   116,   117,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    55,   118,     0,   119,     0,     0,   388,
     389,   120,     0,   121,   122,     0,   123,     0,     0,     0,
     215,   124,   125,     0,     0,     0,     0,     0,     0,   216,
       0,     0,     0,    48,   391,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,     0,     0,     0,
     217,   131,   132,     0,   133,   134,     0,   135,   136,     0,
       0,   137,   138,   139,   140,     0,   402,   403,   141,   142,
     110,   111,     0,   330,     0,     0,     0,     0,   331,     0,
     112,   113,     0,   114,   115,   143,   144,     0,    42,     0,
       0,     0,     0,   116,   117,     0,   404,   405,     0,   406,
     407,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,     0,   121,   122,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,     0,     0,     0,     0,
     332,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,   131,   132,     0,   133,   134,     0,   135,   136,
       0,     0,   137,   138,   139,   140,     0,     0,     0,   141,
     142,   110,   111,     0,   583,     0,   584,     0,     0,     0,
       0,   112,   113,     0,   114,   115,   143,   144,     0,    42,
       0,     0,     0,     0,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   119,     0,
       0,     0,     0,   120,     0,   121,   122,     0,   123,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,   585,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,     0,
       0,     0,     0,   131,   132,     0,   133,   134,     0,   135,
     136,     0,     0,   137,   138,   139,   140,     0,     0,     0,
     141,   142,   110,   111,     0,   579,     0,     0,     0,     0,
       0,     0,   112,   113,     0,   114,   115,   143,   144,     0,
      42,     0,     0,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,   119,
       0,     0,     0,     0,   120,     0,   121,   122,     0,   123,
       0,     0,     0,     0,   124,   125,     0,     0,     0,     0,
       0,     0,   580,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,     0,     0,     0,   131,   132,     0,   133,   134,     0,
     135,   136,     0,     0,   137,   138,   139,   140,     0,     0,
       0,   141,   142,   110,   111,     0,   642,     0,     0,     0,
       0,     0,     0,   112,   113,     0,   114,   115,   143,   144,
       0,    42,     0,     0,     0,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     119,     0,     0,     0,     0,   120,     0,   121,   122,     0,
     123,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,   643,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,   131,   132,     0,   133,   134,
       0,   135,   136,     0,     0,   137,   138,   139,   140,   110,
     111,     0,   141,   142,     0,     0,     0,     0,     0,   112,
     113,     0,   114,   115,     0,     0,     0,    42,     0,   143,
     144,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,     0,     0,     0,
       0,   120,     0,   121,   122,     0,   123,     0,     0,     0,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,     0,     0,     0,
       0,   131,   132,     0,   133,   134,     0,   135,   136,     0,
       0,   137,   138,   139,   140,     0,     0,     0,   141,   142,
     110,   111,     0,   588,     0,     0,     0,     0,     0,     0,
     112,   113,     0,   114,   115,   143,   144,     0,    42,     0,
       0,     0,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,     0,   121,   122,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,   131,   132,     0,   133,   134,     0,   135,   136,
       0,     0,   137,   138,   139,   140,     0,     0,     0,   141,
     142,   110,   111,     0,   639,     0,     0,     0,     0,     0,
       0,   112,   113,     0,   114,   115,   143,   144,     0,    42,
       0,     0,     0,     0,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   119,     0,
       0,     0,     0,   120,     0,   121,   122,     0,   123,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,     0,
       0,     0,     0,   131,   132,     0,   133,   134,     0,   135,
     136,     0,     0,   137,   138,   139,   140,     0,     0,     0,
     141,   142,   110,   111,     0,   675,     0,     0,     0,     0,
       0,     0,   112,   113,     0,   114,   115,   143,   144,     0,
      42,     0,     0,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,   119,
       0,     0,     0,     0,   120,     0,   121,   122,     0,   123,
       0,     0,     0,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,     0,     0,     0,   131,   132,     0,   133,   134,     0,
     135,   136,     0,     0,   137,   138,   139,   140,     0,     0,
       0,   141,   142,   110,   111,     0,   680,     0,     0,     0,
       0,     0,     0,   112,   113,     0,   114,   115,   143,   144,
       0,    42,     0,     0,     0,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     119,     0,     0,     0,     0,   120,     0,   121,   122,     0,
     123,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,   131,   132,     0,   133,   134,
       0,   135,   136,     0,     0,   137,   138,   139,   140,     0,
       0,     0,   141,   142,   110,   111,     0,   703,     0,     0,
       0,     0,     0,     0,   112,   113,     0,   114,   115,   143,
     144,     0,    42,     0,     0,     0,     0,   116,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,   119,     0,     0,     0,     0,   120,     0,   121,   122,
       0,   123,     0,     0,     0,     0,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,     0,     0,     0,   131,   132,     0,   133,
     134,     0,   135,   136,     0,     0,   137,   138,   139,   140,
     110,   111,     0,   141,   142,     0,     0,     0,     0,     0,
     112,   113,     0,   114,   115,     0,     0,     0,    42,     0,
     143,   144,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,     0,   121,   122,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,   131,   132,   371,   133,   134,     0,   135,   136,
       0,     0,   137,   138,   139,   140,     0,   388,   389,   141,
     142,     0,     0,   372,   373,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   390,     0,
       0,     0,   391,   392,     0,     0,     0,     0,   393,     0,
       0,   394,     0,     0,   395,     0,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,     0,   406,   407
};

static const yytype_int16 yycheck[] =
{
       3,    64,   173,    68,     7,    16,    78,     5,    11,    77,
       8,   147,    34,    16,    16,   292,   293,   422,     7,    80,
     297,    18,    11,    77,    78,    25,    26,    27,    55,    60,
      33,     4,     5,    36,     9,    10,     3,    45,   112,    37,
      34,   109,     9,    55,    33,    20,    13,    36,    81,    82,
      83,    84,    85,    86,    21,   109,    34,    68,    20,   131,
      35,   135,    64,     4,   161,    40,    68,    65,    34,    71,
       5,    46,   169,    35,   171,    34,    34,   213,   139,    77,
      78,   456,    80,   458,    46,   460,    34,    87,    88,    34,
      90,   118,    34,    96,    97,    33,    80,   128,    34,    82,
      34,    76,   100,     3,   102,    23,   118,    96,    97,     9,
       9,   109,   139,    13,    13,   137,    10,    34,    36,    94,
      95,    21,    21,   220,   221,    34,    20,     0,   225,    34,
     227,   185,    50,   230,   142,   232,     3,   109,   113,    57,
      10,    35,     9,   137,   549,   147,    13,   201,    34,   146,
     147,   113,    46,     5,    21,   139,   159,     3,   161,   137,
      98,   136,    34,     9,   175,   106,   169,    13,   171,   142,
     108,   137,   139,   148,   136,    21,    34,    34,   137,   137,
     457,   278,   459,    34,    16,   108,   148,   185,   160,   137,
     201,   566,   137,   568,   291,   137,    34,   197,   201,   202,
     268,   137,   205,   137,     9,   341,    77,     3,     4,     5,
     212,   213,   130,   202,   268,     3,   205,   220,   221,   113,
     137,     9,   225,    32,   227,    13,    22,   230,   137,   232,
      26,   102,   137,    21,   152,   268,    32,   160,    34,   139,
     139,   159,   136,    75,    41,    42,   108,   109,   345,     5,
     252,   137,     5,     3,   148,   257,   353,    53,    54,     9,
       5,    22,   359,    13,     5,   137,   320,    63,   135,    78,
     268,    21,   139,    69,    78,   278,    64,   109,   149,   137,
     137,    77,    78,   212,     5,   456,   137,   458,   291,   460,
      77,    10,   114,   139,     9,    10,     5,    93,   160,   137,
      96,    97,    98,     3,     4,    20,   102,    78,    45,     3,
     106,     3,     4,   109,   325,   102,     9,   114,    55,   322,
      35,   324,   325,   325,    43,    40,    66,   131,   330,   331,
      63,    46,    93,   322,   255,   324,    97,    25,    26,   341,
      78,   438,   345,   440,    77,   106,   142,   135,    77,    45,
     353,   139,    16,   149,   490,   276,   359,   153,   112,    55,
     131,    76,   149,     3,     4,   462,   137,   107,   289,   102,
      26,     3,     4,   102,    78,     5,    30,    31,     5,    94,
      95,   118,    22,    96,   121,    98,    26,    41,    42,   139,
       4,     5,    32,   131,    34,   566,    52,   568,   113,    87,
     497,   330,   331,    39,    68,   142,   503,     4,     5,   477,
      74,   476,   466,    53,    54,    11,   149,    78,    78,   422,
     149,   136,     5,   477,   427,   121,   149,   131,   151,    69,
     153,    78,   155,   148,     3,   438,    26,   440,    78,   103,
       3,     4,   165,    78,     9,     3,   142,     3,     3,     4,
       5,   108,   109,    93,     3,   466,    96,    97,    98,   462,
     114,     3,     4,   466,     3,   476,   106,    22,   471,   109,
     131,    26,     3,    32,   476,   473,   137,     3,     5,   477,
     482,   483,   471,   485,   131,   149,   488,   151,   490,   153,
     137,   155,     3,   157,   497,   159,   131,   161,   595,   163,
     503,   165,   137,   167,     3,   138,   229,    44,    63,   173,
     108,    26,     4,   153,   178,   179,   180,    30,    31,    78,
     109,    26,    77,    53,    26,    10,    11,   102,    41,    42,
      60,    26,    55,     3,     3,    20,    29,    96,    93,    98,
      78,    13,    97,     3,   208,   209,   549,   102,    20,    21,
      35,   106,     3,   482,   483,    40,   485,     3,     3,   488,
      53,    46,   226,    35,   228,   229,    96,   231,    98,   233,
      83,   132,   635,    32,    46,    68,   673,   579,   576,   109,
     582,   583,   584,    32,    32,   587,   588,   142,    81,   142,
     252,    76,   595,   255,   149,   257,   148,    53,   128,   149,
      29,   114,   699,   267,   701,    45,   139,   139,   102,    94,
      95,   674,   102,     3,   276,     3,   132,   281,   282,   283,
      32,    32,   147,    45,   148,   160,   148,   289,   113,   149,
     149,    62,   729,   635,    68,   103,   638,   639,   302,    34,
     642,   113,    81,   645,   109,    34,    55,   102,   139,     3,
     579,   136,   139,   582,   583,   584,     3,     9,   587,   588,
     148,   325,   326,   148,   136,   132,   132,   139,   109,   104,
     673,   108,   674,   675,   146,   147,   148,   679,   680,   160,
     160,    68,    80,   347,   137,    68,    34,   351,    81,    34,
     354,    55,   139,    55,     9,    81,   699,   361,   701,    80,
     132,   703,   160,    68,   137,   369,   370,   137,    81,   638,
     639,   131,    55,   642,   137,   131,   645,     9,    10,   383,
     384,    13,    34,   387,   131,   131,   729,   131,    20,    21,
       3,   131,    34,    34,   131,   131,   137,   131,    34,   131,
      32,    34,     3,    35,   408,     3,   675,    39,    40,   131,
     679,   680,   131,   131,    46,   131,    34,   137,    34,   131,
     131,   131,    34,   131,   131,    34,    34,    34,   137,     3,
     434,   137,   436,   437,   703,   131,   137,   441,   442,   443,
     131,   131,   137,    34,    76,   131,    78,   131,   137,   131,
     131,    34,   456,     5,   458,   131,   460,   137,    10,    11,
      12,    13,    94,    95,   137,   131,    18,   137,    20,    21,
     131,   131,   476,    34,   137,   137,    34,   131,   137,   137,
      32,   113,   131,    35,   137,   131,   137,   131,    40,   137,
     137,   131,   137,   131,    46,    34,    25,   131,   137,    39,
     504,   131,   137,    55,   136,   131,   137,   139,   137,   137,
     137,   131,   137,   137,   146,   147,   148,    69,    70,    71,
     137,    16,   137,   137,    76,   466,    78,    79,   325,   379,
      68,   137,   137,   335,   292,   213,   261,   422,   175,   408,
      92,   427,    94,    95,    96,    -1,    98,   408,    -1,   101,
      -1,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,   113,   566,     5,   568,    -1,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,   136,    -1,    -1,   139,   140,   141,
      32,   143,   596,    35,   146,   147,   148,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   626,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    94,    95,    96,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      22,    -1,    -1,    -1,   136,    -1,    -1,   139,   140,   141,
      32,   143,    -1,    35,   146,   147,   148,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,   106,   107,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,   136,    -1,    -1,   139,   140,   141,
      32,   143,    -1,    35,   146,   147,   148,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    10,   161,
     162,    -1,    -1,    55,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    35,    76,    -1,    78,    79,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    94,    95,    96,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    76,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,   136,    -1,    -1,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,    10,    11,    12,
      13,   113,    -1,    -1,    -1,    18,    -1,    20,    21,   161,
     162,    -1,    -1,    26,    -1,    -1,    -1,     9,    10,    32,
      -1,    13,    35,    -1,   136,    -1,    -1,    40,    20,    21,
      -1,    -1,    -1,    46,    -1,    -1,   148,    -1,    -1,    -1,
      32,    -1,    55,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    95,    96,    76,    98,    78,    -1,   101,    -1,
      -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,
     113,    -1,    94,    95,    -1,    -1,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,   113,    -1,   136,    -1,    -1,   139,   140,   141,    32,
     143,    -1,    35,   146,   147,   148,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,   136,    -1,    -1,   139,   161,   162,
      -1,    -1,    55,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    -1,    -1,   136,    -1,    -1,   139,   140,   141,    32,
     143,    -1,    35,   146,   147,   148,   149,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
       3,     4,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,   136,    -1,    -1,   139,   140,   141,    -1,
     143,    -1,    -1,   146,   147,   148,   149,    -1,    -1,    -1,
      53,    54,    10,    11,    12,    13,    -1,    -1,   161,   162,
      18,    -1,    20,    21,    -1,    -1,    69,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    32,    78,    -1,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      93,    -1,    -1,    96,    97,    98,    -1,    55,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,
     153,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,   161,   162,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    10,    32,    -1,    13,    35,    -1,    -1,    -1,
      -1,    40,    20,    21,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    94,    95,    96,    76,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,    -1,    -1,   113,    -1,    94,    95,    -1,    -1,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,   113,    -1,   136,    -1,    -1,
     139,   140,   141,    32,   143,    -1,    35,   146,   147,   148,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,   136,    -1,
      -1,   139,   161,   162,    -1,    -1,    55,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    94,    95,    96,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,   140,   141,    32,   143,    -1,    35,   146,   147,   148,
     149,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    94,    95,    96,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,    10,
     109,    -1,    13,    -1,   113,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,   136,    -1,    40,
     139,   140,   141,    -1,   143,    46,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    55,    -1,     4,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    14,    15,    16,    70,
      71,    -1,    -1,    -1,    -1,    76,    24,    25,    79,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      38,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,   105,    -1,   107,    -1,    56,    -1,
      58,    59,   113,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,   136,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   110,   111,    -1,    -1,    -1,   115,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,    -1,   126,   127,
     128,   129,    -1,    -1,    -1,   133,   134,    14,    15,    -1,
      17,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,
      27,    28,   150,   151,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    51,    10,    -1,    -1,    13,    56,
      -1,    58,    59,    -1,    61,    20,    21,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    10,    74,    -1,    13,
      35,    78,    -1,    -1,    -1,    40,    20,    21,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    99,   100,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,    76,   119,   120,    -1,   122,   123,    -1,    -1,   126,
     127,   128,   129,    -1,    -1,    -1,   133,   134,    10,    94,
      95,    13,    76,    -1,    78,   142,    18,    -1,    20,    21,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,   113,   156,
      94,    95,    -1,    35,    -1,    -1,    -1,    10,    40,    -1,
      13,    -1,    -1,    -1,    46,    -1,    -1,    20,    21,   113,
      -1,   136,    -1,    -1,   139,    -1,    -1,    -1,    -1,    32,
      62,    -1,    35,   148,   149,    -1,    -1,    40,    -1,    -1,
      -1,    -1,   136,    46,    76,   139,    -1,    10,    -1,    -1,
      13,    -1,   146,   147,   148,    18,    -1,    20,    21,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    76,    -1,    78,    10,    40,    -1,    13,
      -1,   113,    -1,    46,    -1,    -1,    20,    21,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,   136,    -1,    40,   139,    -1,    -1,
     113,    -1,    46,    76,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,   136,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    76,   146,   147,   148,    -1,    -1,    -1,    -1,
     113,    -1,    10,    -1,    12,    13,    10,    -1,    -1,    13,
      94,    95,    20,    21,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,   139,    35,    -1,   113,
      -1,    35,    40,   146,   147,   148,    40,    -1,    46,    -1,
      10,    -1,    46,    13,    -1,    -1,    -1,    55,    -1,    -1,
      20,    21,   136,    -1,    -1,   139,    -1,    -1,   142,    -1,
     144,   145,    -1,    -1,   148,    35,    -1,    -1,    76,    -1,
      40,    10,    76,    -1,    13,    -1,    46,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    94,    95,    -1,    -1,
      94,    95,    -1,   101,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,   113,    76,    46,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    94,    95,    13,    -1,   136,    -1,
      -1,   139,   136,    20,    21,   139,    -1,    76,   142,    -1,
     148,   145,    -1,   113,   148,    -1,    -1,    -1,    35,    -1,
      -1,    10,    -1,    40,    13,    94,    95,    -1,    -1,    46,
      -1,    20,    21,    -1,    -1,    -1,   136,    -1,    -1,   139,
      -1,    -1,   142,    -1,   113,   145,    35,    -1,   148,    -1,
      -1,    40,    -1,    -1,    -1,    10,    -1,    46,    13,    76,
      -1,    -1,    -1,    -1,    -1,    20,    21,   136,    -1,    -1,
     139,    -1,    -1,    -1,    -1,   144,   145,    94,    95,   148,
      35,    -1,    -1,    -1,    -1,    40,    -1,    76,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    76,   139,    -1,   113,    -1,    10,    -1,   145,    13,
      -1,   148,    -1,    -1,    -1,    -1,    20,    21,    -1,    94,
      95,    -1,    26,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,    35,    -1,    -1,    -1,    -1,    40,    -1,   113,   148,
      -1,    -1,    46,    -1,    10,    -1,    10,    13,    -1,    13,
      -1,    -1,    -1,    -1,    20,    21,    20,    21,    -1,    -1,
      26,   136,    26,    -1,   139,    -1,    -1,    -1,    -1,    35,
     145,    35,    76,   148,    40,    10,    40,    -1,    13,    -1,
      46,    -1,    46,    -1,    -1,    20,    21,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,   113,
      76,    46,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      94,    95,   136,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,   148,    -1,    -1,   113,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   136,   139,    -1,   139,    -1,    -1,   113,    14,
      15,    16,   148,    -1,   148,    -1,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      -1,   136,    37,    38,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    49,    -1,    51,    -1,    -1,    47,
      48,    56,    -1,    58,    59,    -1,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,
     115,   116,   117,    -1,   119,   120,    -1,   122,   123,    -1,
      -1,   126,   127,   128,   129,    -1,   124,   125,   133,   134,
      14,    15,    -1,    17,    -1,    -1,    -1,    -1,    22,    -1,
      24,    25,    -1,    27,    28,   150,   151,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,   154,   155,    -1,   157,
     158,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,    -1,   126,   127,   128,   129,    -1,    -1,    -1,   133,
     134,    14,    15,    -1,    17,    -1,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,   150,   151,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,    -1,   126,   127,   128,   129,    -1,    -1,    -1,
     133,   134,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,   150,   151,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,    -1,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,   150,   151,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,    -1,   126,   127,   128,   129,    14,
      15,    -1,   133,   134,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,   150,
     151,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,   120,    -1,   122,   123,    -1,
      -1,   126,   127,   128,   129,    -1,    -1,    -1,   133,   134,
      14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,   150,   151,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,    -1,   126,   127,   128,   129,    -1,    -1,    -1,   133,
     134,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,   150,   151,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,    -1,   126,   127,   128,   129,    -1,    -1,    -1,
     133,   134,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,   150,   151,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,    -1,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,   150,   151,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,    -1,   126,   127,   128,   129,    -1,
      -1,    -1,   133,   134,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,   150,
     151,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
     120,    -1,   122,   123,    -1,    -1,   126,   127,   128,   129,
      14,    15,    -1,   133,   134,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
     150,   151,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,    -1,   116,   117,    34,   119,   120,    -1,   122,   123,
      -1,    -1,   126,   127,   128,   129,    -1,    47,    48,   133,
     134,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    68,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,   157,   158
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    82,   164,   165,   166,     5,     0,     3,     9,    13,
      21,    64,   135,   139,   171,   174,   175,   176,   264,    30,
      31,    41,    42,    83,   114,   167,   168,   169,   170,    10,
     281,   174,   281,     3,   135,   174,     5,   112,   135,   172,
     173,    20,    32,    35,    39,    40,    46,    76,    78,    94,
      95,   113,   136,   146,   147,   148,   176,   178,   179,   180,
     181,   182,   183,   184,   185,   187,   188,   189,   192,   193,
     194,   196,   197,   198,   226,   227,   239,   264,   265,   281,
       9,     5,     5,     5,     5,     5,     5,   168,   169,   170,
     169,   170,   170,     3,     9,   174,     5,     3,   174,   281,
     112,   173,     5,   226,    43,   281,   189,   188,   193,   264,
      14,    15,    24,    25,    27,    28,    37,    38,    49,    51,
      56,    58,    59,    61,    66,    67,    85,    99,   100,   110,
     111,   116,   117,   119,   120,   122,   123,   126,   127,   128,
     129,   133,   134,   150,   151,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   225,   227,   228,   229,
     233,   234,   235,   236,   237,   238,     4,   106,   199,   142,
     145,   198,    26,    52,   178,   265,   281,   178,   281,   281,
      11,   282,   282,   282,   282,   282,   282,   169,   170,   170,
     170,    78,     3,   174,   174,     5,   281,   281,   142,   145,
     198,     3,     4,     4,    16,    65,    74,   115,   203,   240,
     241,   242,    18,   185,   186,   198,   202,   198,   202,    62,
     198,   202,   198,   202,   198,    12,    55,    69,    70,    71,
      78,    79,    92,    96,    98,   101,   105,   107,   109,   139,
     140,   141,   143,   161,   162,   198,   201,   202,   227,   243,
     244,   250,   251,   252,   253,   259,   260,   261,   264,   266,
     267,   268,   269,   279,   282,   283,   198,   243,   198,   198,
     202,   142,   144,   145,   198,    55,    63,   118,   139,   198,
     231,   232,   243,   243,    55,   139,   198,   200,   201,   185,
     186,   198,   145,   198,   198,     3,    26,   178,   281,     9,
       3,     3,     3,     3,     3,     3,   170,   177,   178,   185,
     264,   174,     3,   174,     5,     3,   145,   198,   198,     3,
      17,    22,    74,   204,   203,   240,   138,     3,     4,     5,
     142,   195,   243,   243,    44,    26,   243,    26,   198,   149,
     243,    26,   198,   198,   202,   149,   243,   149,   198,    26,
     243,    26,   198,   108,   109,    45,    55,   121,   142,   227,
     261,    34,    53,    54,    69,    78,    98,   153,   246,   261,
     262,   279,   280,   227,   261,    96,    98,    26,    47,    48,
      68,    72,    73,    78,    81,    84,    86,    87,    88,    89,
      90,    91,   124,   125,   154,   155,   157,   158,   245,   246,
     247,   248,   249,   270,   271,   272,   273,   274,   275,   276,
     277,   278,     4,    22,    93,    97,   106,   254,   255,   256,
     257,   258,   198,   282,    16,    75,   109,    26,    26,   243,
      26,    26,   144,   145,   198,   198,   198,    55,   118,   139,
     102,    55,   118,    77,   102,   149,   230,   243,   230,   232,
     230,    55,   230,   198,     3,     3,    78,     3,     3,   178,
     174,     3,   174,     9,   190,   191,   192,   264,   198,     3,
       3,   204,    17,    19,    74,   142,   156,   204,   132,     3,
     195,   142,     4,     5,   203,   243,   198,    32,   198,   149,
     243,   149,   198,    32,    32,   243,   198,   148,    45,   142,
      45,   198,   198,    53,   149,    33,    98,    53,    98,   108,
     109,   160,    60,   128,   224,   224,    23,    36,    50,    57,
     130,   152,   159,   263,   198,   198,   198,    34,   137,    29,
      68,    81,    34,   137,    29,   198,   250,   266,   251,   254,
     252,   198,   139,   198,   198,   243,   243,   198,   198,   198,
     102,    55,   118,   139,   102,   200,   230,   200,   230,   200,
     243,     3,   177,   185,   174,   281,     9,     3,   204,    17,
      74,   204,   132,    17,    19,    74,   204,   147,    17,   204,
     203,     4,     5,     3,   243,    32,    32,   243,   198,   148,
      45,   148,   149,   108,   160,   149,   109,   160,   160,   108,
     109,    62,   103,    68,    34,    80,   139,    34,   137,    34,
     137,    81,    34,    80,   139,   251,   109,   139,   102,    55,
     139,   200,   200,     3,     3,     9,   281,   204,   132,    17,
     204,   204,    17,    74,   204,   132,   204,   204,     3,   243,
     198,   148,   108,   160,   109,   160,   104,   137,    68,    80,
      68,    34,    81,    34,    78,   131,   137,    81,    80,   198,
      55,   139,    55,   226,     9,    17,   204,   204,   204,   132,
      17,   204,   160,   137,   137,    68,    78,   131,   137,    81,
     131,    34,   137,    78,   131,    78,   131,   137,    55,     5,
     243,   226,   204,    17,   204,   204,   137,   131,    34,   137,
      78,   131,    78,   131,   137,    34,   137,   131,    34,   131,
      34,   137,   131,    34,   137,    78,   131,   243,     3,     5,
     243,   204,    34,   137,   131,    34,   131,    34,   137,   131,
      34,   137,    78,   131,   131,    34,   137,   131,    34,   137,
     131,    34,    34,   137,   131,    34,   131,    34,   137,     3,
     243,     3,   131,    34,   137,   131,    34,   137,   131,    34,
      34,   137,   131,    34,   131,    34,   137,   137,   131,   137,
     131,    34,   137,   131,   131,    34,   137,   131,    34,   137,
     131,    34,     3,   137,   131,   137,   131,    34,   137,   131,
     131,    34,   137,   131,    34,   137,   131,    34,   137,   137,
     131,   137,   137,   131,   137,   131,    34,   137,   131,   137,
     137,   131,   137,   137,   131,   137,   131,    34,   137,   131,
     137,   137,   137,   131,   137,   137,   137,   137,   131,   137,
     137,   137
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   163,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   167,   168,   168,   169,   169,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   172,   173,   173,   173,
     173,   174,   174,   174,   174,   175,   175,   176,   176,   176,
     176,   177,   177,   178,   178,   178,   178,   178,   178,   179,
     180,   181,   182,   183,   184,   185,   185,   186,   187,   187,
     188,   188,   189,   190,   190,   191,   191,   191,   191,   192,
     192,   193,   193,   194,   194,   194,   194,   194,   195,   195,
     195,   195,   195,   195,   195,   195,   196,   197,   197,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   200,
     200,   200,   200,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   206,   206,   206,   206,   206,   207,   207,   208,
     208,   208,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   211,   211,   212,   212,
     212,   212,   212,   213,   213,   214,   215,   215,   216,   216,
     217,   217,   218,   218,   219,   219,   220,   220,   220,   221,
     221,   222,   222,   222,   223,   223,   223,   223,   224,   224,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   226,
     227,   227,   228,   228,   228,   228,   229,   229,   229,   229,
     229,   229,   229,   229,   230,   230,   230,   231,   231,   231,
     231,   232,   232,   232,   232,   233,   234,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   240,   240,   241,   241,   241,   242,
     243,   244,   245,   245,   245,   245,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   247,   247,   247,
     247,   247,   247,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   249,
     249,   250,   250,   250,   250,   250,   251,   251,   251,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   254,   254,   254,   255,   256,   257,   258,
     259,   259,   259,   259,   260,   260,   260,   260,   261,   261,
     261,   261,   262,   262,   262,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   265,   265,   265,
     265,   266,   266,   267,   267,   267,   267,   267,   268,   268,
     268,   268,   268,   269,   270,   270,   270,   270,   270,   270,
     270,   270,   271,   271,   272,   272,   273,   273,   274,   274,
     275,   275,   276,   276,   277,   277,   278,   278,   279,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   281,   282,   283
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
       5,     6,     7,     5,     6,     7,     8,     5,     6,     7,
       8,     6,     7,     8,     9,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     3,     4,     1,     1,     2,
       3,     5,     3,     4,     1,     1,     2,     3,     5,     3,
       4,     6,     3,     5,     4,     6,     1,     1,     2,     3,
       4,     3,     4,     1,     1,     2,     1,     1,     2,     4,
       1,     1,     2,     4,     1,     1,     2,     3,     4,     1,
       1,     2,     4,     4,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     4,     4,     1,     2,     2,     3,
       1,     1,     4,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       5,     2,     5,     3,     6,     4,     1,     1,     2,     4,
       1,     1,     2,     2,     1,     1,     3,     4,     4,     5,
       4,     5,     5,     6,     2,     2,     1,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     3,     1,     2,     3,     3,     4,     4,     5,     4,
       5,     5,     6,     6,     7,     7,     8,     7,     8,     8,
       9,     7,     8,     8,     9,     8,     9,     9,    10,     7,
       8,     8,     9,     8,     9,     9,    10,     8,     9,     9,
      10,     9,    10,    10,    11,     7,     8,     8,     9,     8,
       9,     9,    10,     8,     9,     9,    10,     9,    10,    10,
      11,     8,     9,     9,    10,     9,    10,    10,    11,     9,
      10,    10,    11,    10,    11,    11,    12,     3,     4,     3,
       4,     1,     1,     1,     1,     2,     1,     3,     4,     1,
       3,     1,     2,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     5,     1,     2,     3,
       4,     5,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     3,     3,     4,     2,     3,     3,     4,     3,
       4,     4,     5,     1,     1,     1
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   381,     0,   371,     0,   371,     0,   371,     0,   371,
       0,   376,     0,   381,     0,   371,     0,   371,     0,   371,
       0,   371,     0,   371,     0,   371,     0,   371,     0,   371,
       0,   231,     0
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
  "RETURN", "RETURNS", "SECOND", "SECONDS", "SEND", "SENDS", "SET", "SETS",
  "SIGNED", "SMALLER", "SO", "TERMINATE", "TERMINATES", "TERMS", "TEXT",
  "THAN", "THAT", "THE", "THEMSELF", "THEMSELVES", "THEN", "THERE",
  "THEREFOR", "THEREFORE", "THESE", "THIS", "TIME", "TO", "TRANSFER",
  "TRANSFERS", "TRUE", "WAS", "WEEK", "WEEKS", "WITH", "YEAR", "YEARS",
  "YES", "YET", "YOURSELF", "YOURSELVES", "$accept", "Document", "Head",
  "Lex", "Lexon", "Authors", "Comment", "Preamble", "Terms", "Covenants",
  "Covenant", "Provisions", "Definitions", "Definition", "Type_Term",
  "Type", "Person", "Amount", "Time", "Binary", "Text", "Data",
  "This_Contract", "All_Contracts", "This", "Clauses", "Clause", "Body",
  "Function", "Statements", "Statement", "Action", "Punctuation",
  "Subject", "Symbols", "Symbol", "Catena", "Object", "Reflexive",
  "Contract", "Predicates", "Predicate", "Permission", "Certification",
  "Certify", "Declaration", "Declare", "Filing", "File", "Registration",
  "Register", "Grantment", "Grant", "Appointment", "Appoint", "Assignment",
  "Assign", "Acceptance", "Accept", "Fixture", "Fix", "Fixed", "Setting",
  "Illocutor", "Be", "Payment", "Pay", "Preposition", "Escrow",
  "From_Escrow", "Sending", "Send", "Notification", "Notify",
  "Termination", "Terminate", "Flagging", "Condition", "If", "After",
  "Expression", "Scalar_Comparison", "Comparison_Operator", "Equal",
  "Greater", "Less", "Later", "Scalar_Expression", "Combination",
  "Combinor", "Combinand", "Combinator", "Or_", "And", "Neither", "Nor",
  "Existence", "Negation", "Negator", "Being", "True", "Article", "New",
  "Point_In_Time", "Current_Time", "Relative_Time", "Duration",
  "Time_Unit", "Years", "Months", "Weeks", "Days", "Hours", "Minutes",
  "Seconds", "Milliseconds", "Expiration", "Timeliness", "Name",
  "Description", "Scalar", YY_NULLPTR
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
#line 1161 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terms); root=process_document(Document); }
#line 3222 "parser.c"
    break;

  case 3: /* Document: Head Terms Covenants  */
#line 1162 "parser.y"
                                                                  { NEW(Document, *((Literal **)&yylval)); Document->Head=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Head); Document->Terms=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terms); Document->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenants); root=process_document(Document); }
#line 3228 "parser.c"
    break;

  case 4: /* Head: Lex  */
#line 1168 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lex); ((*yyvalp).Head)=process_head(Head); }
#line 3234 "parser.c"
    break;

  case 5: /* Head: Lex Preamble  */
#line 1169 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3240 "parser.c"
    break;

  case 6: /* Head: Lex Comment  */
#line 1170 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3246 "parser.c"
    break;

  case 7: /* Head: Lex Comment Preamble  */
#line 1171 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3252 "parser.c"
    break;

  case 8: /* Head: Lex Authors  */
#line 1172 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3258 "parser.c"
    break;

  case 9: /* Head: Lex Authors Preamble  */
#line 1173 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3264 "parser.c"
    break;

  case 10: /* Head: Lex Authors Comment  */
#line 1174 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3270 "parser.c"
    break;

  case 11: /* Head: Lex Authors Comment Preamble  */
#line 1175 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3276 "parser.c"
    break;

  case 12: /* Head: Lex Lexon  */
#line 1176 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Lexon); ((*yyvalp).Head)=process_head(Head); }
#line 3282 "parser.c"
    break;

  case 13: /* Head: Lex Lexon Preamble  */
#line 1177 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3288 "parser.c"
    break;

  case 14: /* Head: Lex Lexon Comment  */
#line 1178 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3294 "parser.c"
    break;

  case 15: /* Head: Lex Lexon Comment Preamble  */
#line 1179 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3300 "parser.c"
    break;

  case 16: /* Head: Lex Lexon Authors  */
#line 1180 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Authors); ((*yyvalp).Head)=process_head(Head); }
#line 3306 "parser.c"
    break;

  case 17: /* Head: Lex Lexon Authors Preamble  */
#line 1181 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3312 "parser.c"
    break;

  case 18: /* Head: Lex Lexon Authors Comment  */
#line 1182 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Comment); ((*yyvalp).Head)=process_head(Head); }
#line 3318 "parser.c"
    break;

  case 19: /* Head: Lex Lexon Authors Comment Preamble  */
#line 1183 "parser.y"
                                                                  { NEW(Head, *((Literal **)&yylval)); Head->Lex=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Lex); Head->Lexon=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Lexon); Head->Authors=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Authors); Head->Comment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comment); Head->Preamble=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Preamble); ((*yyvalp).Head)=process_head(Head); }
#line 3324 "parser.c"
    break;

  case 20: /* Lex: LEX Colon Name Separator  */
#line 1189 "parser.y"
                                                                  { NEW(Lex, *((Literal **)&yylval)); Lex->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Name); ((*yyvalp).Lex)=process_lex(Lex); }
#line 3330 "parser.c"
    break;

  case 21: /* Lexon: LEXON Colon Description Separator  */
#line 1195 "parser.y"
                                                                  { NEW(Lexon, *((Literal **)&yylval)); Lexon->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Lexon)=process_lexon(Lexon); }
#line 3336 "parser.c"
    break;

  case 22: /* Authors: AUTHOR Colon Description Separator  */
#line 1201 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3342 "parser.c"
    break;

  case 23: /* Authors: AUTHORS Colon Description Separator  */
#line 1202 "parser.y"
                                                                  { NEW(Authors, *((Literal **)&yylval)); Authors->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Authors)=process_authors(Authors); }
#line 3348 "parser.c"
    break;

  case 24: /* Comment: COMMENT Colon Description Separator  */
#line 1208 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3354 "parser.c"
    break;

  case 25: /* Comment: COMMENTS Colon Description Separator  */
#line 1209 "parser.y"
                                                                  { NEW(Comment, *((Literal **)&yylval)); Comment->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Comment)=process_comment(Comment); }
#line 3360 "parser.c"
    break;

  case 26: /* Preamble: PREAMBLE Colon Description Separator  */
#line 1215 "parser.y"
                                                                  { NEW(Preamble, *((Literal **)&yylval)); Preamble->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Description); ((*yyvalp).Preamble)=process_preamble(Preamble); }
#line 3366 "parser.c"
    break;

  case 27: /* Terms: Provisions  */
#line 1221 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3372 "parser.c"
    break;

  case 28: /* Terms: Separator Provisions  */
#line 1222 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3378 "parser.c"
    break;

  case 29: /* Terms: TERMS Colon Provisions  */
#line 1223 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3384 "parser.c"
    break;

  case 30: /* Terms: TERMS Colon Separator Provisions  */
#line 1224 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3390 "parser.c"
    break;

  case 31: /* Terms: GENERAL Provisions  */
#line 1225 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3396 "parser.c"
    break;

  case 32: /* Terms: GENERAL Separator Provisions  */
#line 1226 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3402 "parser.c"
    break;

  case 33: /* Terms: GENERAL TERMS Colon Provisions  */
#line 1227 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3408 "parser.c"
    break;

  case 34: /* Terms: GENERAL TERMS Colon Separator Provisions  */
#line 1228 "parser.y"
                                                                  { NEW(Terms, *((Literal **)&yylval)); Terms->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Terms)=process_terms(Terms); }
#line 3414 "parser.c"
    break;

  case 35: /* Covenants: Covenant  */
#line 1234 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3420 "parser.c"
    break;

  case 36: /* Covenants: Covenants Covenant  */
#line 1235 "parser.y"
                                                                  { NEW(Covenants, *((Literal **)&yylval)); Covenants->Covenants=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Covenants); Covenants->Covenant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Covenant); ((*yyvalp).Covenants)=process_covenants(Covenants); }
#line 3426 "parser.c"
    break;

  case 37: /* Covenant: PER Name Colon Provisions  */
#line 1241 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3432 "parser.c"
    break;

  case 38: /* Covenant: PER Name Colon Separator Provisions  */
#line 1242 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3438 "parser.c"
    break;

  case 39: /* Covenant: TERMS PER Name Colon Provisions  */
#line 1243 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3444 "parser.c"
    break;

  case 40: /* Covenant: TERMS PER Name Colon Separator Provisions  */
#line 1244 "parser.y"
                                                                  { NEW(Covenant, *((Literal **)&yylval)); Covenant->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Name); Covenant->Provisions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Provisions); ((*yyvalp).Covenant)=process_covenant(Covenant); }
#line 3450 "parser.c"
    break;

  case 41: /* Provisions: Definitions  */
#line 1250 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definitions); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3456 "parser.c"
    break;

  case 42: /* Provisions: Definitions Clauses  */
#line 1251 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3462 "parser.c"
    break;

  case 43: /* Provisions: Definitions Statements  */
#line 1252 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3468 "parser.c"
    break;

  case 44: /* Provisions: Definitions Statements Clauses  */
#line 1253 "parser.y"
                                                                  { NEW(Provisions, *((Literal **)&yylval)); Provisions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Definitions); Provisions->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Provisions->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clauses); ((*yyvalp).Provisions)=process_provisions(Provisions); }
#line 3474 "parser.c"
    break;

  case 45: /* Definitions: Definition  */
#line 1259 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3480 "parser.c"
    break;

  case 46: /* Definitions: Definitions Definition  */
#line 1260 "parser.y"
                                                                  { NEW(Definitions, *((Literal **)&yylval)); Definitions->Definitions=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Definitions); Definitions->Definition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Definition); ((*yyvalp).Definitions)=process_definitions(Definitions); }
#line 3486 "parser.c"
    break;

  case 47: /* Definition: Quote Name Quote IS Type_Term Separator  */
#line 1266 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3492 "parser.c"
    break;

  case 48: /* Definition: Article Quote Name Quote IS Type_Term Separator  */
#line 1267 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->Type_Term=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Type_Term); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3498 "parser.c"
    break;

  case 49: /* Definition: Quote Name Quote IS This_Contract Separator  */
#line 1268 "parser.y"
                                                                  { NEW(Definition, *((Literal **)&yylval)); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3504 "parser.c"
    break;

  case 50: /* Definition: Article Quote Name Quote IS This_Contract Separator  */
#line 1269 "parser.y"
                                                                      { NEW(Definition, *((Literal **)&yylval)); Definition->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Definition->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Definition->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Definition)=process_definition(Definition); }
#line 3510 "parser.c"
    break;

  case 51: /* Type_Term: Type  */
#line 1275 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3516 "parser.c"
    break;

  case 52: /* Type_Term: Article Type  */
#line 1276 "parser.y"
                                                                  { NEW(Type_Term, *((Literal **)&yylval)); Type_Term->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Type_Term->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Type_Term)=process_type_term(Type_Term); }
#line 3522 "parser.c"
    break;

  case 53: /* Type: Person  */
#line 1282 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Person=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Person); ((*yyvalp).Type)=process_type(Type); }
#line 3528 "parser.c"
    break;

  case 54: /* Type: Amount  */
#line 1283 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Amount=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Amount); ((*yyvalp).Type)=process_type(Type); }
#line 3534 "parser.c"
    break;

  case 55: /* Type: Time  */
#line 1284 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time); ((*yyvalp).Type)=process_type(Type); }
#line 3540 "parser.c"
    break;

  case 56: /* Type: Binary  */
#line 1285 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Binary=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Binary); ((*yyvalp).Type)=process_type(Type); }
#line 3546 "parser.c"
    break;

  case 57: /* Type: Text  */
#line 1286 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Text=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Text); ((*yyvalp).Type)=process_type(Type); }
#line 3552 "parser.c"
    break;

  case 58: /* Type: Data  */
#line 1287 "parser.y"
                                                                  { NEW(Type, *((Literal **)&yylval)); Type->Data=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Data); ((*yyvalp).Type)=process_type(Type); }
#line 3558 "parser.c"
    break;

  case 59: /* Person: PERSON  */
#line 1293 "parser.y"
                                                                  { NEW(Person, *((Literal **)&yylval)); ((*yyvalp).Person)=process_person(Person); }
#line 3564 "parser.c"
    break;

  case 60: /* Amount: AMOUNT  */
#line 1299 "parser.y"
                                                                  { NEW(Amount, *((Literal **)&yylval)); ((*yyvalp).Amount)=process_amount(Amount); }
#line 3570 "parser.c"
    break;

  case 61: /* Time: TIME  */
#line 1305 "parser.y"
                                                                  { NEW(Time, *((Literal **)&yylval)); ((*yyvalp).Time)=process_time(Time); }
#line 3576 "parser.c"
    break;

  case 62: /* Binary: BINARY  */
#line 1311 "parser.y"
                                                                  { NEW(Binary, *((Literal **)&yylval)); ((*yyvalp).Binary)=process_binary(Binary); }
#line 3582 "parser.c"
    break;

  case 63: /* Text: TEXT  */
#line 1317 "parser.y"
                                                                  { NEW(Text, *((Literal **)&yylval)); ((*yyvalp).Text)=process_text(Text); }
#line 3588 "parser.c"
    break;

  case 64: /* Data: DATA  */
#line 1323 "parser.y"
                                                                  { NEW(Data, *((Literal **)&yylval)); ((*yyvalp).Data)=process_data(Data); }
#line 3594 "parser.c"
    break;

  case 65: /* This_Contract: This CONTRACT  */
#line 1329 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3600 "parser.c"
    break;

  case 66: /* This_Contract: This Name  */
#line 1330 "parser.y"
                                                                  { NEW(This_Contract, *((Literal **)&yylval)); This_Contract->This=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.This); This_Contract->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).This_Contract)=process_this_contract(This_Contract); }
#line 3606 "parser.c"
    break;

  case 67: /* All_Contracts: ALL CONTRACTS  */
#line 1336 "parser.y"
                                                                  { NEW(All_Contracts, *((Literal **)&yylval)); ((*yyvalp).All_Contracts)=process_all_contracts(All_Contracts); }
#line 3612 "parser.c"
    break;

  case 68: /* This: THIS  */
#line 1342 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3618 "parser.c"
    break;

  case 69: /* This: THESE  */
#line 1343 "parser.y"
                                                                  { NEW(This, *((Literal **)&yylval)); ((*yyvalp).This)=process_this(This); }
#line 3624 "parser.c"
    break;

  case 70: /* Clauses: Clause  */
#line 1349 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3630 "parser.c"
    break;

  case 71: /* Clauses: Clauses Clause  */
#line 1350 "parser.y"
                                                                  { NEW(Clauses, *((Literal **)&yylval)); Clauses->Clauses=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Clauses); Clauses->Clause=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Clause); ((*yyvalp).Clauses)=process_clauses(Clauses); }
#line 3636 "parser.c"
    break;

  case 72: /* Clause: CLAUSE Colon Name Separator Body  */
#line 1356 "parser.y"
                                                                  { NEW(Clause, *((Literal **)&yylval)); Clause->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Name); Clause->Body=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Body); ((*yyvalp).Clause)=process_clause(Clause); }
#line 3642 "parser.c"
    break;

  case 73: /* Body: Statements  */
#line 1362 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statements); ((*yyvalp).Body)=process_body(Body); }
#line 3648 "parser.c"
    break;

  case 74: /* Body: Function  */
#line 1363 "parser.y"
                                                                  { NEW(Body, *((Literal **)&yylval)); Body->Function=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Function); ((*yyvalp).Body)=process_body(Body); }
#line 3654 "parser.c"
    break;

  case 75: /* Function: Quote Name Quote Illocutor Expression Separator  */
#line 1369 "parser.y"
                                                                   { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3660 "parser.c"
    break;

  case 76: /* Function: Quote Name Quote Illocutor Colon Expression Separator  */
#line 1370 "parser.y"
                                                                         { NEW(Function, *((Literal **)&yylval)); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3666 "parser.c"
    break;

  case 77: /* Function: Article Quote Name Quote Illocutor Expression Separator  */
#line 1371 "parser.y"
                                                                          { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3672 "parser.c"
    break;

  case 78: /* Function: Article Quote Name Quote Illocutor Colon Expression Separator  */
#line 1372 "parser.y"
                                                                                { NEW(Function, *((Literal **)&yylval)); Function->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Article); Function->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Name); Function->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Function->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Function)=process_function(Function); }
#line 3678 "parser.c"
    break;

  case 79: /* Statements: Statement  */
#line 1378 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3684 "parser.c"
    break;

  case 80: /* Statements: Statements Statement  */
#line 1379 "parser.y"
                                                                  { NEW(Statements, *((Literal **)&yylval)); Statements->Statements=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Statements); Statements->Statement=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Statement); ((*yyvalp).Statements)=process_statements(Statements); }
#line 3690 "parser.c"
    break;

  case 81: /* Statement: Action  */
#line 1385 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Action=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Action); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3696 "parser.c"
    break;

  case 82: /* Statement: Flagging  */
#line 1386 "parser.y"
                                                                  { NEW(Statement, *((Literal **)&yylval)); Statement->Flagging=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Flagging); ((*yyvalp).Statement)=process_statement(Statement); }
#line 3702 "parser.c"
    break;

  case 83: /* Action: Subject Predicates Separator  */
#line 1392 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Subject); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3708 "parser.c"
    break;

  case 84: /* Action: Subject Permission Predicates Separator  */
#line 1393 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3714 "parser.c"
    break;

  case 85: /* Action: Subject Permission Condition Punctuation Predicates Separator  */
#line 1394 "parser.y"
                                                                                { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Punctuation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Punctuation); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3720 "parser.c"
    break;

  case 86: /* Action: Subject Permission Comma Predicates Separator  */
#line 1395 "parser.y"
                                                                  { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Permission); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3726 "parser.c"
    break;

  case 87: /* Action: Subject Permission Comma Condition Punctuation Predicates Separator  */
#line 1396 "parser.y"
                                                                                      { NEW(Action, *((Literal **)&yylval)); Action->Subject=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Subject); Action->Permission=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Permission); Action->Condition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Condition); Action->Punctuation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Punctuation); Action->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Predicates); ((*yyvalp).Action)=process_action(Action); }
#line 3732 "parser.c"
    break;

  case 88: /* Punctuation: Comma  */
#line 1402 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3738 "parser.c"
    break;

  case 89: /* Punctuation: Colon  */
#line 1403 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3744 "parser.c"
    break;

  case 90: /* Punctuation: THEN  */
#line 1404 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3750 "parser.c"
    break;

  case 91: /* Punctuation: THEN Colon  */
#line 1405 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3756 "parser.c"
    break;

  case 92: /* Punctuation: Comma THEN  */
#line 1406 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3762 "parser.c"
    break;

  case 93: /* Punctuation: Comma THEN Colon  */
#line 1407 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3768 "parser.c"
    break;

  case 94: /* Punctuation: THEN Comma  */
#line 1408 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3774 "parser.c"
    break;

  case 95: /* Punctuation: Comma THEN Comma  */
#line 1409 "parser.y"
                                                                  { NEW(Punctuation, *((Literal **)&yylval)); ((*yyvalp).Punctuation)=process_punctuation(Punctuation); }
#line 3780 "parser.c"
    break;

  case 96: /* Subject: Symbols  */
#line 1415 "parser.y"
                                                                  { NEW(Subject, *((Literal **)&yylval)); Subject->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbols); ((*yyvalp).Subject)=process_subject(Subject); }
#line 3786 "parser.c"
    break;

  case 97: /* Symbols: Symbol  */
#line 1421 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3792 "parser.c"
    break;

  case 98: /* Symbols: Symbols Catena Symbol  */
#line 1422 "parser.y"
                                                                  { NEW(Symbols, *((Literal **)&yylval)); Symbols->Symbols=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbols); Symbols->Catena=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Catena); Symbols->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Symbols)=process_symbols(Symbols); }
#line 3798 "parser.c"
    break;

  case 99: /* Symbol: Name  */
#line 1428 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3804 "parser.c"
    break;

  case 100: /* Symbol: New Name  */
#line 1429 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3810 "parser.c"
    break;

  case 101: /* Symbol: Article Name  */
#line 1430 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3816 "parser.c"
    break;

  case 102: /* Symbol: Article New Name  */
#line 1431 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Name=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Name); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3822 "parser.c"
    break;

  case 103: /* Symbol: Type  */
#line 1432 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3828 "parser.c"
    break;

  case 104: /* Symbol: New Type  */
#line 1433 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3834 "parser.c"
    break;

  case 105: /* Symbol: Article Type  */
#line 1434 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3840 "parser.c"
    break;

  case 106: /* Symbol: Article New Type  */
#line 1435 "parser.y"
                                                                  { NEW(Symbol, *((Literal **)&yylval)); Symbol->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Article); Symbol->New=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.New); Symbol->Type=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Type); ((*yyvalp).Symbol)=process_symbol(Symbol); }
#line 3846 "parser.c"
    break;

  case 107: /* Catena: OR  */
#line 1441 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3852 "parser.c"
    break;

  case 108: /* Catena: Comma  */
#line 1442 "parser.y"
                                                                  { NEW(Catena, *((Literal **)&yylval)); ((*yyvalp).Catena)=process_catena(Catena); }
#line 3858 "parser.c"
    break;

  case 109: /* Object: Symbol  */
#line 1448 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Object)=process_object(Object); }
#line 3864 "parser.c"
    break;

  case 110: /* Object: Reflexive  */
#line 1449 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); Object->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Object)=process_object(Object); }
#line 3870 "parser.c"
    break;

  case 111: /* Object: ESCROW  */
#line 1450 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3876 "parser.c"
    break;

  case 112: /* Object: THE ESCROW  */
#line 1451 "parser.y"
                                                                  { NEW(Object, *((Literal **)&yylval)); ((*yyvalp).Object)=process_object(Object); }
#line 3882 "parser.c"
    break;

  case 113: /* Reflexive: MYSELF  */
#line 1457 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3888 "parser.c"
    break;

  case 114: /* Reflexive: YOURSELF  */
#line 1458 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3894 "parser.c"
    break;

  case 115: /* Reflexive: HERSELF  */
#line 1459 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3900 "parser.c"
    break;

  case 116: /* Reflexive: HIMSELF  */
#line 1460 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3906 "parser.c"
    break;

  case 117: /* Reflexive: ONESELF  */
#line 1461 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3912 "parser.c"
    break;

  case 118: /* Reflexive: ITSELF  */
#line 1462 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3918 "parser.c"
    break;

  case 119: /* Reflexive: THEMSELF  */
#line 1463 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3924 "parser.c"
    break;

  case 120: /* Reflexive: OURSELVES  */
#line 1464 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3930 "parser.c"
    break;

  case 121: /* Reflexive: YOURSELVES  */
#line 1465 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3936 "parser.c"
    break;

  case 122: /* Reflexive: THEMSELVES  */
#line 1466 "parser.y"
                                                                  { NEW(Reflexive, *((Literal **)&yylval)); ((*yyvalp).Reflexive)=process_reflexive(Reflexive); }
#line 3942 "parser.c"
    break;

  case 123: /* Contract: This_Contract  */
#line 1472 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3948 "parser.c"
    break;

  case 124: /* Contract: All_Contracts  */
#line 1473 "parser.y"
                                                                  { NEW(Contract, *((Literal **)&yylval)); Contract->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Contract)=process_contract(Contract); }
#line 3954 "parser.c"
    break;

  case 125: /* Predicates: Predicates Comma Predicate  */
#line 1479 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3960 "parser.c"
    break;

  case 126: /* Predicates: Predicates Comma AFTERWARDS Predicate  */
#line 1480 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3966 "parser.c"
    break;

  case 127: /* Predicates: Predicates Comma IF SO Predicate  */
#line 1481 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3972 "parser.c"
    break;

  case 128: /* Predicates: Predicates Comma IF SO AFTERWARDS Predicate  */
#line 1482 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3978 "parser.c"
    break;

  case 129: /* Predicates: Predicates Comma AND Predicate  */
#line 1483 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3984 "parser.c"
    break;

  case 130: /* Predicates: Predicates Comma AND AFTERWARDS Predicate  */
#line 1484 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3990 "parser.c"
    break;

  case 131: /* Predicates: Predicates Comma AND IF SO Predicate  */
#line 1485 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 3996 "parser.c"
    break;

  case 132: /* Predicates: Predicates Comma AND IF SO AFTERWARDS Predicate  */
#line 1486 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4002 "parser.c"
    break;

  case 133: /* Predicates: Predicates Comma AND ALSO Predicate  */
#line 1487 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4008 "parser.c"
    break;

  case 134: /* Predicates: Predicates Comma AND ALSO AFTERWARDS Predicate  */
#line 1488 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4014 "parser.c"
    break;

  case 135: /* Predicates: Predicates Comma AND ALSO IF SO Predicate  */
#line 1489 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4020 "parser.c"
    break;

  case 136: /* Predicates: Predicates Comma AND ALSO IF SO AFTERWARDS Predicate  */
#line 1490 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4026 "parser.c"
    break;

  case 137: /* Predicates: Predicates Comma AND THEN Predicate  */
#line 1491 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4032 "parser.c"
    break;

  case 138: /* Predicates: Predicates Comma AND THEN AFTERWARDS Predicate  */
#line 1492 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4038 "parser.c"
    break;

  case 139: /* Predicates: Predicates Comma AND THEN IF SO Predicate  */
#line 1493 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4044 "parser.c"
    break;

  case 140: /* Predicates: Predicates Comma AND THEN IF SO AFTERWARDS Predicate  */
#line 1494 "parser.y"
                                                                       { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4050 "parser.c"
    break;

  case 141: /* Predicates: Predicates Comma AND THEN ALSO Predicate  */
#line 1495 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4056 "parser.c"
    break;

  case 142: /* Predicates: Predicates Comma AND THEN ALSO AFTERWARDS Predicate  */
#line 1496 "parser.y"
                                                                      { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4062 "parser.c"
    break;

  case 143: /* Predicates: Predicates Comma AND THEN ALSO IF SO Predicate  */
#line 1497 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4068 "parser.c"
    break;

  case 144: /* Predicates: Predicates Comma AND THEN ALSO IF SO AFTERWARDS Predicate  */
#line 1498 "parser.y"
                                                                            { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4074 "parser.c"
    break;

  case 145: /* Predicates: Predicates Comma AND WITH THIS Predicate  */
#line 1499 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicates=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.Predicates); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4080 "parser.c"
    break;

  case 146: /* Predicates: Predicate  */
#line 1500 "parser.y"
                                                                  { NEW(Predicates, *((Literal **)&yylval)); Predicates->Predicate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Predicate); ((*yyvalp).Predicates)=process_predicates(Predicates); }
#line 4086 "parser.c"
    break;

  case 147: /* Predicate: Certification  */
#line 1506 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Certification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Certification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4092 "parser.c"
    break;

  case 148: /* Predicate: Declaration  */
#line 1507 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Declaration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Declaration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4098 "parser.c"
    break;

  case 149: /* Predicate: Filing  */
#line 1508 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Filing=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Filing); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4104 "parser.c"
    break;

  case 150: /* Predicate: Registration  */
#line 1509 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Registration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Registration); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4110 "parser.c"
    break;

  case 151: /* Predicate: Grantment  */
#line 1510 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Grantment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Grantment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4116 "parser.c"
    break;

  case 152: /* Predicate: Appointment  */
#line 1511 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Appointment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Appointment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4122 "parser.c"
    break;

  case 153: /* Predicate: Assignment  */
#line 1512 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Assignment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Assignment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4128 "parser.c"
    break;

  case 154: /* Predicate: Acceptance  */
#line 1513 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Acceptance=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Acceptance); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4134 "parser.c"
    break;

  case 155: /* Predicate: Fixture  */
#line 1514 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Fixture=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixture); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4140 "parser.c"
    break;

  case 156: /* Predicate: Setting  */
#line 1515 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Setting=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Setting); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4146 "parser.c"
    break;

  case 157: /* Predicate: Payment  */
#line 1516 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Payment=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Payment); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4152 "parser.c"
    break;

  case 158: /* Predicate: Sending  */
#line 1517 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Sending=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Sending); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4158 "parser.c"
    break;

  case 159: /* Predicate: Notification  */
#line 1518 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Notification=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Notification); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4164 "parser.c"
    break;

  case 160: /* Predicate: Termination  */
#line 1519 "parser.y"
                                                                  { NEW(Predicate, *((Literal **)&yylval)); Predicate->Termination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Termination); ((*yyvalp).Predicate)=process_predicate(Predicate); }
#line 4170 "parser.c"
    break;

  case 161: /* Permission: MAY  */
#line 1525 "parser.y"
                                                                  { NEW(Permission, *((Literal **)&yylval)); ((*yyvalp).Permission)=process_permission(Permission); }
#line 4176 "parser.c"
    break;

  case 162: /* Certification: Certify Symbol  */
#line 1531 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4182 "parser.c"
    break;

  case 163: /* Certification: Certify Symbol Expression  */
#line 1532 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4188 "parser.c"
    break;

  case 164: /* Certification: Certify Symbol AS Expression  */
#line 1533 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Certification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4194 "parser.c"
    break;

  case 165: /* Certification: Certify Contract Symbol  */
#line 1534 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4200 "parser.c"
    break;

  case 166: /* Certification: Certify Contract AS Symbol  */
#line 1535 "parser.y"
                                                                  { NEW(Certification, *((Literal **)&yylval)); Certification->Certify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Certify); Certification->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Certification->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Certification)=process_certification(Certification); }
#line 4206 "parser.c"
    break;

  case 167: /* Certify: CERTIFY  */
#line 1541 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4212 "parser.c"
    break;

  case 168: /* Certify: CERTIFIES  */
#line 1542 "parser.y"
                                                                  { NEW(Certify, *((Literal **)&yylval)); ((*yyvalp).Certify)=process_certify(Certify); }
#line 4218 "parser.c"
    break;

  case 169: /* Declaration: Declare Symbol  */
#line 1548 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4224 "parser.c"
    break;

  case 170: /* Declaration: Declare Symbol Expression  */
#line 1549 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4230 "parser.c"
    break;

  case 171: /* Declaration: Declare Symbol TO BE Expression  */
#line 1550 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Declare); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Declaration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4236 "parser.c"
    break;

  case 172: /* Declaration: Declare Contract Symbol  */
#line 1551 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4242 "parser.c"
    break;

  case 173: /* Declaration: Declare Contract AS Symbol  */
#line 1552 "parser.y"
                                                                  { NEW(Declaration, *((Literal **)&yylval)); Declaration->Declare=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Declare); Declaration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Declaration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Declaration)=process_declaration(Declaration); }
#line 4248 "parser.c"
    break;

  case 174: /* Declare: DECLARE  */
#line 1558 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4254 "parser.c"
    break;

  case 175: /* Declare: DECLARES  */
#line 1559 "parser.y"
                                                                  { NEW(Declare, *((Literal **)&yylval)); ((*yyvalp).Declare)=process_declare(Declare); }
#line 4260 "parser.c"
    break;

  case 176: /* Filing: File Symbol  */
#line 1565 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4266 "parser.c"
    break;

  case 177: /* Filing: File Symbol Expression  */
#line 1566 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4272 "parser.c"
    break;

  case 178: /* Filing: File Symbol TO BE Expression  */
#line 1567 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4278 "parser.c"
    break;

  case 179: /* Filing: File FOR Symbol  */
#line 1568 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4284 "parser.c"
    break;

  case 180: /* Filing: File FOR Symbol Expression  */
#line 1569 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4290 "parser.c"
    break;

  case 181: /* Filing: File FOR Symbol TO BE Expression  */
#line 1570 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Symbol); Filing->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4296 "parser.c"
    break;

  case 182: /* Filing: File Contract Symbol  */
#line 1571 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4302 "parser.c"
    break;

  case 183: /* Filing: File Contract TO BE Symbol  */
#line 1572 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4308 "parser.c"
    break;

  case 184: /* Filing: File FOR Contract Symbol  */
#line 1573 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4314 "parser.c"
    break;

  case 185: /* Filing: File FOR Contract TO BE Symbol  */
#line 1574 "parser.y"
                                                                  { NEW(Filing, *((Literal **)&yylval)); Filing->File=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.File); Filing->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Contract); Filing->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Filing)=process_filing(Filing); }
#line 4320 "parser.c"
    break;

  case 186: /* File: FILE_  */
#line 1580 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4326 "parser.c"
    break;

  case 187: /* File: FILES  */
#line 1581 "parser.y"
                                                                  { NEW(File, *((Literal **)&yylval)); ((*yyvalp).File)=process_file(File); }
#line 4332 "parser.c"
    break;

  case 188: /* Registration: Register Symbol  */
#line 1587 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4338 "parser.c"
    break;

  case 189: /* Registration: Register Symbol Expression  */
#line 1588 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4344 "parser.c"
    break;

  case 190: /* Registration: Register Symbol AS Expression  */
#line 1589 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Registration->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4350 "parser.c"
    break;

  case 191: /* Registration: Register Contract Symbol  */
#line 1590 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4356 "parser.c"
    break;

  case 192: /* Registration: Register Contract AS Symbol  */
#line 1591 "parser.y"
                                                                  { NEW(Registration, *((Literal **)&yylval)); Registration->Register=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Register); Registration->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Registration->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Registration)=process_registration(Registration); }
#line 4362 "parser.c"
    break;

  case 193: /* Register: REGISTER  */
#line 1597 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4368 "parser.c"
    break;

  case 194: /* Register: REGISTERS  */
#line 1598 "parser.y"
                                                                  { NEW(Register, *((Literal **)&yylval)); ((*yyvalp).Register)=process_register(Register); }
#line 4374 "parser.c"
    break;

  case 195: /* Grantment: Grant Symbol  */
#line 1604 "parser.y"
                                                                  { NEW(Grantment, *((Literal **)&yylval)); Grantment->Grant=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Grant); Grantment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Grantment)=process_grantment(Grantment); }
#line 4380 "parser.c"
    break;

  case 196: /* Grant: GRANT  */
#line 1610 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4386 "parser.c"
    break;

  case 197: /* Grant: GRANTS  */
#line 1611 "parser.y"
                                                                  { NEW(Grant, *((Literal **)&yylval)); ((*yyvalp).Grant)=process_grant(Grant); }
#line 4392 "parser.c"
    break;

  case 198: /* Appointment: Appoint Symbol  */
#line 1617 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Appoint); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4398 "parser.c"
    break;

  case 199: /* Appointment: Appoint Expression AS Symbol  */
#line 1618 "parser.y"
                                                                  { NEW(Appointment, *((Literal **)&yylval)); Appointment->Appoint=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Appoint); Appointment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Appointment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Appointment)=process_appointment(Appointment); }
#line 4404 "parser.c"
    break;

  case 200: /* Appoint: APPOINT  */
#line 1624 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4410 "parser.c"
    break;

  case 201: /* Appoint: APPOINTS  */
#line 1625 "parser.y"
                                                                  { NEW(Appoint, *((Literal **)&yylval)); ((*yyvalp).Appoint)=process_appoint(Appoint); }
#line 4416 "parser.c"
    break;

  case 202: /* Assignment: Assign Symbol  */
#line 1631 "parser.y"
                                                                  { NEW(Assignment, *((Literal **)&yylval)); Assignment->Assign=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Assign); Assignment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Assignment)=process_assignment(Assignment); }
#line 4422 "parser.c"
    break;

  case 203: /* Assignment: Assign Expression AS Symbol  */
#line 1632 "parser.y"
                                                                  { NEW(Assignment, *((Literal **)&yylval)); Assignment->Assign=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Assign); Assignment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Assignment->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Assignment)=process_assignment(Assignment); }
#line 4428 "parser.c"
    break;

  case 204: /* Assign: ASSIGN  */
#line 1638 "parser.y"
                                                                  { NEW(Assign, *((Literal **)&yylval)); ((*yyvalp).Assign)=process_assign(Assign); }
#line 4434 "parser.c"
    break;

  case 205: /* Assign: ASSIGNS  */
#line 1639 "parser.y"
                                                                  { NEW(Assign, *((Literal **)&yylval)); ((*yyvalp).Assign)=process_assign(Assign); }
#line 4440 "parser.c"
    break;

  case 206: /* Acceptance: Accept Symbol  */
#line 1645 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4446 "parser.c"
    break;

  case 207: /* Acceptance: Accept Symbol Expression  */
#line 1646 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4452 "parser.c"
    break;

  case 208: /* Acceptance: Accept Symbol AS Expression  */
#line 1647 "parser.y"
                                                                  { NEW(Acceptance, *((Literal **)&yylval)); Acceptance->Accept=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Accept); Acceptance->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Acceptance->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Acceptance)=process_acceptance(Acceptance); }
#line 4458 "parser.c"
    break;

  case 209: /* Accept: ACCEPT  */
#line 1653 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4464 "parser.c"
    break;

  case 210: /* Accept: ACCEPTS  */
#line 1654 "parser.y"
                                                                  { NEW(Accept, *((Literal **)&yylval)); ((*yyvalp).Accept)=process_accept(Accept); }
#line 4470 "parser.c"
    break;

  case 211: /* Fixture: Fix Symbol  */
#line 1660 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4476 "parser.c"
    break;

  case 212: /* Fixture: Fix Symbol AS Expression  */
#line 1661 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Fixture->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4482 "parser.c"
    break;

  case 213: /* Fixture: Fix Contract AS Symbol  */
#line 1662 "parser.y"
                                                                  { NEW(Fixture, *((Literal **)&yylval)); Fixture->Fix=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Fix); Fixture->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Fixture->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Fixture)=process_fixture(Fixture); }
#line 4488 "parser.c"
    break;

  case 214: /* Fix: FIX  */
#line 1668 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4494 "parser.c"
    break;

  case 215: /* Fix: FIXES  */
#line 1669 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4500 "parser.c"
    break;

  case 216: /* Fix: SET  */
#line 1670 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4506 "parser.c"
    break;

  case 217: /* Fix: SETS  */
#line 1671 "parser.y"
                                                                  { NEW(Fix, *((Literal **)&yylval)); ((*yyvalp).Fix)=process_fix(Fix); }
#line 4512 "parser.c"
    break;

  case 218: /* Fixed: FIXED  */
#line 1677 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 4518 "parser.c"
    break;

  case 219: /* Fixed: SET  */
#line 1678 "parser.y"
                                                                  { NEW(Fixed, *((Literal **)&yylval)); ((*yyvalp).Fixed)=process_fixed(Fixed); }
#line 4524 "parser.c"
    break;

  case 220: /* Setting: Be Symbol  */
#line 1684 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4530 "parser.c"
    break;

  case 221: /* Setting: Be THEREFOR Symbol  */
#line 1685 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4536 "parser.c"
    break;

  case 222: /* Setting: Be THEREFORE Symbol  */
#line 1686 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4542 "parser.c"
    break;

  case 223: /* Setting: Be THEN Symbol  */
#line 1687 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4548 "parser.c"
    break;

  case 224: /* Setting: Be THEN THEREFOR Symbol  */
#line 1688 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4554 "parser.c"
    break;

  case 225: /* Setting: Be THEN THEREFORE Symbol  */
#line 1689 "parser.y"
                                                                  { NEW(Setting, *((Literal **)&yylval)); Setting->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Be); Setting->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Setting)=process_setting(Setting); }
#line 4560 "parser.c"
    break;

  case 226: /* Illocutor: Be  */
#line 1695 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4566 "parser.c"
    break;

  case 227: /* Illocutor: Be AS  */
#line 1696 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4572 "parser.c"
    break;

  case 228: /* Illocutor: Be DEFINED  */
#line 1697 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4578 "parser.c"
    break;

  case 229: /* Illocutor: Be DEFINED AS  */
#line 1698 "parser.y"
                                                                  { NEW(Illocutor, *((Literal **)&yylval)); Illocutor->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Be); ((*yyvalp).Illocutor)=process_illocutor(Illocutor); }
#line 4584 "parser.c"
    break;

  case 230: /* Be: BE  */
#line 1704 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4590 "parser.c"
    break;

  case 231: /* Be: IS  */
#line 1705 "parser.y"
                                                                  { NEW(Be, *((Literal **)&yylval)); ((*yyvalp).Be)=process_be(Be); }
#line 4596 "parser.c"
    break;

  case 232: /* Payment: Pay Expression Preposition Object  */
#line 1711 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4602 "parser.c"
    break;

  case 233: /* Payment: Pay From_Escrow Expression Preposition Object  */
#line 1712 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.From_Escrow); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4608 "parser.c"
    break;

  case 234: /* Payment: Pay Expression From_Escrow Preposition Object  */
#line 1713 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Pay); Payment->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Expression); Payment->From_Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.From_Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4614 "parser.c"
    break;

  case 235: /* Payment: Pay Escrow Preposition Object  */
#line 1714 "parser.y"
                                                                  { NEW(Payment, *((Literal **)&yylval)); Payment->Pay=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Pay); Payment->Escrow=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Escrow); Payment->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Payment->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Payment)=process_payment(Payment); }
#line 4620 "parser.c"
    break;

  case 236: /* Pay: PAY  */
#line 1720 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4626 "parser.c"
    break;

  case 237: /* Pay: PAYS  */
#line 1721 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4632 "parser.c"
    break;

  case 238: /* Pay: RETURN  */
#line 1722 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4638 "parser.c"
    break;

  case 239: /* Pay: RETURNS  */
#line 1723 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4644 "parser.c"
    break;

  case 240: /* Pay: REPAY  */
#line 1724 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4650 "parser.c"
    break;

  case 241: /* Pay: REPAYS  */
#line 1725 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4656 "parser.c"
    break;

  case 242: /* Pay: TRANSFER  */
#line 1726 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4662 "parser.c"
    break;

  case 243: /* Pay: TRANSFERS  */
#line 1727 "parser.y"
                                                                  { NEW(Pay, *((Literal **)&yylval)); ((*yyvalp).Pay)=process_pay(Pay); }
#line 4668 "parser.c"
    break;

  case 244: /* Preposition: TO  */
#line 1733 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4674 "parser.c"
    break;

  case 245: /* Preposition: INTO  */
#line 1734 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4680 "parser.c"
    break;

  case 246: /* Preposition: OF  */
#line 1735 "parser.y"
                                                                  { NEW(Preposition, *((Literal **)&yylval)); ((*yyvalp).Preposition)=process_preposition(Preposition); }
#line 4686 "parser.c"
    break;

  case 247: /* Escrow: ESCROW  */
#line 1741 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4692 "parser.c"
    break;

  case 248: /* Escrow: REMAINDER OF THE ESCROW  */
#line 1742 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4698 "parser.c"
    break;

  case 249: /* Escrow: THE ESCROW  */
#line 1743 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4704 "parser.c"
    break;

  case 250: /* Escrow: THE REMAINDER OF THE ESCROW  */
#line 1744 "parser.y"
                                                                  { NEW(Escrow, *((Literal **)&yylval)); ((*yyvalp).Escrow)=process_escrow(Escrow); }
#line 4710 "parser.c"
    break;

  case 251: /* From_Escrow: FROM ESCROW  */
#line 1750 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4716 "parser.c"
    break;

  case 252: /* From_Escrow: FROM REMAINDER OF THE ESCROW  */
#line 1751 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4722 "parser.c"
    break;

  case 253: /* From_Escrow: FROM THE ESCROW  */
#line 1752 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4728 "parser.c"
    break;

  case 254: /* From_Escrow: FROM THE REMAINDER OF THE ESCROW  */
#line 1753 "parser.y"
                                                                  { NEW(From_Escrow, *((Literal **)&yylval)); ((*yyvalp).From_Escrow)=process_from_escrow(From_Escrow); }
#line 4734 "parser.c"
    break;

  case 255: /* Sending: Send Expression Preposition Object  */
#line 1759 "parser.y"
                                                                  { NEW(Sending, *((Literal **)&yylval)); Sending->Send=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Send); Sending->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Expression); Sending->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Sending->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Sending)=process_sending(Sending); }
#line 4740 "parser.c"
    break;

  case 256: /* Send: SEND  */
#line 1765 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4746 "parser.c"
    break;

  case 257: /* Send: SENDS  */
#line 1766 "parser.y"
                                                                  { NEW(Send, *((Literal **)&yylval)); ((*yyvalp).Send)=process_send(Send); }
#line 4752 "parser.c"
    break;

  case 258: /* Notification: Notify Object  */
#line 1772 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Object); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4758 "parser.c"
    break;

  case 259: /* Notification: Notify Object Preposition Expression  */
#line 1773 "parser.y"
                                                                  { NEW(Notification, *((Literal **)&yylval)); Notification->Notify=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Notify); Notification->Object=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Object); Notification->Preposition=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Preposition); Notification->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Notification)=process_notification(Notification); }
#line 4764 "parser.c"
    break;

  case 260: /* Notify: NOTIFY  */
#line 1779 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4770 "parser.c"
    break;

  case 261: /* Notify: NOTIFIES  */
#line 1780 "parser.y"
                                                                  { NEW(Notify, *((Literal **)&yylval)); ((*yyvalp).Notify)=process_notify(Notify); }
#line 4776 "parser.c"
    break;

  case 262: /* Termination: Terminate This_Contract  */
#line 1786 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.This_Contract); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4782 "parser.c"
    break;

  case 263: /* Termination: Terminate All_Contracts  */
#line 1787 "parser.y"
                                                                  { NEW(Termination, *((Literal **)&yylval)); Termination->Terminate=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminate); Termination->All_Contracts=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.All_Contracts); ((*yyvalp).Termination)=process_termination(Termination); }
#line 4788 "parser.c"
    break;

  case 264: /* Terminate: TERMINATE  */
#line 1793 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4794 "parser.c"
    break;

  case 265: /* Terminate: TERMINATES  */
#line 1794 "parser.y"
                                                                  { NEW(Terminate, *((Literal **)&yylval)); ((*yyvalp).Terminate)=process_terminate(Terminate); }
#line 4800 "parser.c"
    break;

  case 266: /* Flagging: Illocutor Symbol Separator  */
#line 1800 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4806 "parser.c"
    break;

  case 267: /* Flagging: Illocutor THEREFORE Symbol Separator  */
#line 1801 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4812 "parser.c"
    break;

  case 268: /* Flagging: Illocutor THEN Symbol Separator  */
#line 1802 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4818 "parser.c"
    break;

  case 269: /* Flagging: Illocutor THEN THEREFORE Symbol Separator  */
#line 1803 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4824 "parser.c"
    break;

  case 270: /* Flagging: This_Contract Illocutor Symbol Separator  */
#line 1804 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4830 "parser.c"
    break;

  case 271: /* Flagging: This_Contract Illocutor THEREFORE Symbol Separator  */
#line 1805 "parser.y"
                                                                     { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4836 "parser.c"
    break;

  case 272: /* Flagging: This_Contract Illocutor THEN Symbol Separator  */
#line 1806 "parser.y"
                                                                  { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4842 "parser.c"
    break;

  case 273: /* Flagging: This_Contract Illocutor THEN THEREFORE Symbol Separator  */
#line 1807 "parser.y"
                                                                          { NEW(Flagging, *((Literal **)&yylval)); Flagging->This_Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.This_Contract); Flagging->Illocutor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Illocutor); Flagging->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Flagging)=process_flagging(Flagging); }
#line 4848 "parser.c"
    break;

  case 274: /* Condition: If Expression  */
#line 1813 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->If=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.If); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4854 "parser.c"
    break;

  case 275: /* Condition: After Expression  */
#line 1814 "parser.y"
                                                                  { NEW(Condition, *((Literal **)&yylval)); Condition->After=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.After); Condition->Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expression); ((*yyvalp).Condition)=process_condition(Condition); }
#line 4860 "parser.c"
    break;

  case 276: /* If: IF  */
#line 1820 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4866 "parser.c"
    break;

  case 277: /* If: GIVEN THAT  */
#line 1821 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4872 "parser.c"
    break;

  case 278: /* If: PROVIDED  */
#line 1822 "parser.y"
                                                                  { NEW(If, *((Literal **)&yylval)); ((*yyvalp).If)=process_if(If); }
#line 4878 "parser.c"
    break;

  case 279: /* After: AFTER  */
#line 1828 "parser.y"
                                                                  { NEW(After, *((Literal **)&yylval)); ((*yyvalp).After)=process_after(After); }
#line 4884 "parser.c"
    break;

  case 280: /* Expression: Combination  */
#line 1834 "parser.y"
                                                                  { NEW(Expression, *((Literal **)&yylval)); Expression->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Expression)=process_expression(Expression); }
#line 4890 "parser.c"
    break;

  case 281: /* Scalar_Comparison: Scalar_Expression Comparison_Operator Scalar_Expression  */
#line 1840 "parser.y"
                                                                          { NEW(Scalar_Comparison, *((Literal **)&yylval)); Scalar_Comparison->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Scalar_Expression); Scalar_Comparison->Comparison_Operator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Comparison_Operator); Scalar_Comparison->Scalar_Expression2=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Expression); ((*yyvalp).Scalar_Comparison)=process_scalar_comparison(Scalar_Comparison); }
#line 4896 "parser.c"
    break;

  case 282: /* Comparison_Operator: Equal  */
#line 1846 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Equal); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4902 "parser.c"
    break;

  case 283: /* Comparison_Operator: Greater  */
#line 1847 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Greater=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Greater); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4908 "parser.c"
    break;

  case 284: /* Comparison_Operator: Less  */
#line 1848 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Less=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Less); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4914 "parser.c"
    break;

  case 285: /* Comparison_Operator: Later  */
#line 1849 "parser.y"
                                                                  { NEW(Comparison_Operator, *((Literal **)&yylval)); Comparison_Operator->Later=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Later); ((*yyvalp).Comparison_Operator)=process_comparison_operator(Comparison_Operator); }
#line 4920 "parser.c"
    break;

  case 286: /* Equal: EQUAL  */
#line 1855 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4926 "parser.c"
    break;

  case 287: /* Equal: EQUAL TO  */
#line 1856 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4932 "parser.c"
    break;

  case 288: /* Equal: EQUALING  */
#line 1857 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4938 "parser.c"
    break;

  case 289: /* Equal: IS  */
#line 1858 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4944 "parser.c"
    break;

  case 290: /* Equal: IS EQUAL  */
#line 1859 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4950 "parser.c"
    break;

  case 291: /* Equal: IS EQUAL TO  */
#line 1860 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4956 "parser.c"
    break;

  case 292: /* Equal: BEING  */
#line 1861 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4962 "parser.c"
    break;

  case 293: /* Equal: BEING EQUAL  */
#line 1862 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4968 "parser.c"
    break;

  case 294: /* Equal: BEING EQUAL TO  */
#line 1863 "parser.y"
                                                                  { NEW(Equal, *((Literal **)&yylval)); ((*yyvalp).Equal)=process_equal(Equal); }
#line 4974 "parser.c"
    break;

  case 295: /* Greater: GREATER BEING GREATER  */
#line 1869 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4980 "parser.c"
    break;

  case 296: /* Greater: GREATER BEING GREATER THAN  */
#line 1870 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4986 "parser.c"
    break;

  case 297: /* Greater: GREATER THAN BEING GREATER  */
#line 1871 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4992 "parser.c"
    break;

  case 298: /* Greater: GREATER THAN BEING GREATER THAN  */
#line 1872 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 4998 "parser.c"
    break;

  case 299: /* Greater: IS GREATER BEING GREATER  */
#line 1873 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 5004 "parser.c"
    break;

  case 300: /* Greater: IS GREATER BEING GREATER THAN  */
#line 1874 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 5010 "parser.c"
    break;

  case 301: /* Greater: IS GREATER THAN BEING GREATER  */
#line 1875 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 5016 "parser.c"
    break;

  case 302: /* Greater: IS GREATER THAN BEING GREATER THAN  */
#line 1876 "parser.y"
                                                                  { NEW(Greater, *((Literal **)&yylval)); ((*yyvalp).Greater)=process_greater(Greater); }
#line 5022 "parser.c"
    break;

  case 303: /* Less: LESS BEING LESS SMALLER BEING SMALLER  */
#line 1882 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5028 "parser.c"
    break;

  case 304: /* Less: LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1883 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5034 "parser.c"
    break;

  case 305: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1884 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5040 "parser.c"
    break;

  case 306: /* Less: LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1885 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5046 "parser.c"
    break;

  case 307: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1886 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5052 "parser.c"
    break;

  case 308: /* Less: LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1887 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5058 "parser.c"
    break;

  case 309: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1888 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5064 "parser.c"
    break;

  case 310: /* Less: LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1889 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5070 "parser.c"
    break;

  case 311: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1890 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5076 "parser.c"
    break;

  case 312: /* Less: LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1891 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5082 "parser.c"
    break;

  case 313: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1892 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5088 "parser.c"
    break;

  case 314: /* Less: LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1893 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5094 "parser.c"
    break;

  case 315: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1894 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5100 "parser.c"
    break;

  case 316: /* Less: LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1895 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5106 "parser.c"
    break;

  case 317: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1896 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5112 "parser.c"
    break;

  case 318: /* Less: LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1897 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5118 "parser.c"
    break;

  case 319: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1898 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5124 "parser.c"
    break;

  case 320: /* Less: LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1899 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5130 "parser.c"
    break;

  case 321: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1900 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5136 "parser.c"
    break;

  case 322: /* Less: LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1901 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5142 "parser.c"
    break;

  case 323: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1902 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5148 "parser.c"
    break;

  case 324: /* Less: LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1903 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5154 "parser.c"
    break;

  case 325: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1904 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5160 "parser.c"
    break;

  case 326: /* Less: LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1905 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5166 "parser.c"
    break;

  case 327: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1906 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5172 "parser.c"
    break;

  case 328: /* Less: LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1907 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5178 "parser.c"
    break;

  case 329: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1908 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5184 "parser.c"
    break;

  case 330: /* Less: LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1909 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5190 "parser.c"
    break;

  case 331: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1910 "parser.y"
                                                                      { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5196 "parser.c"
    break;

  case 332: /* Less: LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1911 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5202 "parser.c"
    break;

  case 333: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1912 "parser.y"
                                                                           { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5208 "parser.c"
    break;

  case 334: /* Less: LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1913 "parser.y"
                                                                                { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5214 "parser.c"
    break;

  case 335: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER  */
#line 1914 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5220 "parser.c"
    break;

  case 336: /* Less: IS LESS BEING LESS SMALLER BEING SMALLER THAN  */
#line 1915 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5226 "parser.c"
    break;

  case 337: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER  */
#line 1916 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5232 "parser.c"
    break;

  case 338: /* Less: IS LESS BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1917 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5238 "parser.c"
    break;

  case 339: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER  */
#line 1918 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5244 "parser.c"
    break;

  case 340: /* Less: IS LESS BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1919 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5250 "parser.c"
    break;

  case 341: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1920 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5256 "parser.c"
    break;

  case 342: /* Less: IS LESS BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1921 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5262 "parser.c"
    break;

  case 343: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER  */
#line 1922 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5268 "parser.c"
    break;

  case 344: /* Less: IS LESS BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1923 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5274 "parser.c"
    break;

  case 345: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1924 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5280 "parser.c"
    break;

  case 346: /* Less: IS LESS BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1925 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5286 "parser.c"
    break;

  case 347: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1926 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5292 "parser.c"
    break;

  case 348: /* Less: IS LESS BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1927 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5298 "parser.c"
    break;

  case 349: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1928 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5304 "parser.c"
    break;

  case 350: /* Less: IS LESS BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1929 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5310 "parser.c"
    break;

  case 351: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER  */
#line 1930 "parser.y"
                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5316 "parser.c"
    break;

  case 352: /* Less: IS LESS THAN BEING LESS SMALLER BEING SMALLER THAN  */
#line 1931 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5322 "parser.c"
    break;

  case 353: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER  */
#line 1932 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5328 "parser.c"
    break;

  case 354: /* Less: IS LESS THAN BEING LESS SMALLER THAN BEING SMALLER THAN  */
#line 1933 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5334 "parser.c"
    break;

  case 355: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER  */
#line 1934 "parser.y"
                                                                   { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5340 "parser.c"
    break;

  case 356: /* Less: IS LESS THAN BEING LESS IS SMALLER BEING SMALLER THAN  */
#line 1935 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5346 "parser.c"
    break;

  case 357: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER  */
#line 1936 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5352 "parser.c"
    break;

  case 358: /* Less: IS LESS THAN BEING LESS IS SMALLER THAN BEING SMALLER THAN  */
#line 1937 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5358 "parser.c"
    break;

  case 359: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER  */
#line 1938 "parser.y"
                                                                     { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5364 "parser.c"
    break;

  case 360: /* Less: IS LESS THAN BEING LESS THAN SMALLER BEING SMALLER THAN  */
#line 1939 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5370 "parser.c"
    break;

  case 361: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER  */
#line 1940 "parser.y"
                                                                          { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5376 "parser.c"
    break;

  case 362: /* Less: IS LESS THAN BEING LESS THAN SMALLER THAN BEING SMALLER THAN  */
#line 1941 "parser.y"
                                                                               { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5382 "parser.c"
    break;

  case 363: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER  */
#line 1942 "parser.y"
                                                                        { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5388 "parser.c"
    break;

  case 364: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER BEING SMALLER THAN  */
#line 1943 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5394 "parser.c"
    break;

  case 365: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER  */
#line 1944 "parser.y"
                                                                             { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5400 "parser.c"
    break;

  case 366: /* Less: IS LESS THAN BEING LESS THAN IS SMALLER THAN BEING SMALLER THAN  */
#line 1945 "parser.y"
                                                                                  { NEW(Less, *((Literal **)&yylval)); ((*yyvalp).Less)=process_less(Less); }
#line 5406 "parser.c"
    break;

  case 367: /* Later: IS AT LEAST  */
#line 1951 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5412 "parser.c"
    break;

  case 368: /* Later: IS AT THE LEAST  */
#line 1952 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5418 "parser.c"
    break;

  case 369: /* Later: LIES AT LEAST  */
#line 1953 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5424 "parser.c"
    break;

  case 370: /* Later: LIES AT THE LEAST  */
#line 1954 "parser.y"
                                                                  { NEW(Later, *((Literal **)&yylval)); ((*yyvalp).Later)=process_later(Later); }
#line 5430 "parser.c"
    break;

  case 371: /* Scalar_Expression: Symbol  */
#line 1960 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5436 "parser.c"
    break;

  case 372: /* Scalar_Expression: Scalar  */
#line 1961 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Scalar=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5442 "parser.c"
    break;

  case 373: /* Scalar_Expression: Point_In_Time  */
#line 1962 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); Scalar_Expression->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5448 "parser.c"
    break;

  case 374: /* Scalar_Expression: ESCROW  */
#line 1963 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5454 "parser.c"
    break;

  case 375: /* Scalar_Expression: THE ESCROW  */
#line 1964 "parser.y"
                                                                  { NEW(Scalar_Expression, *((Literal **)&yylval)); ((*yyvalp).Scalar_Expression)=process_scalar_expression(Scalar_Expression); }
#line 5460 "parser.c"
    break;

  case 376: /* Combination: Combinor  */
#line 1970 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5466 "parser.c"
    break;

  case 377: /* Combination: Combinor Comma Combination  */
#line 1971 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinor); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5472 "parser.c"
    break;

  case 378: /* Combination: Combinor Comma Combinator Combination  */
#line 1972 "parser.y"
                                                                  { NEW(Combination, *((Literal **)&yylval)); Combination->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Combinor); Combination->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combination->Combination=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combination); ((*yyvalp).Combination)=process_combination(Combination); }
#line 5478 "parser.c"
    break;

  case 379: /* Combinor: Combinand  */
#line 1978 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinand); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5484 "parser.c"
    break;

  case 380: /* Combinor: Combinand Combinator Combinor  */
#line 1979 "parser.y"
                                                                  { NEW(Combinor, *((Literal **)&yylval)); Combinor->Combinand=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Combinand); Combinor->Combinator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Combinator); Combinor->Combinor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Combinor); ((*yyvalp).Combinor)=process_combinor(Combinor); }
#line 5490 "parser.c"
    break;

  case 381: /* Combinand: Symbol  */
#line 1985 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5496 "parser.c"
    break;

  case 382: /* Combinand: Symbol Expiration  */
#line 1986 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5502 "parser.c"
    break;

  case 383: /* Combinand: Symbol Timeliness  */
#line 1987 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Symbol); Combinand->Timeliness=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Timeliness); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5508 "parser.c"
    break;

  case 384: /* Combinand: Reflexive  */
#line 1988 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Reflexive=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Reflexive); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5514 "parser.c"
    break;

  case 385: /* Combinand: Description  */
#line 1989 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5520 "parser.c"
    break;

  case 386: /* Combinand: Article Description  */
#line 1990 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Article=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Article); Combinand->Description=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Description); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5526 "parser.c"
    break;

  case 387: /* Combinand: Scalar_Comparison  */
#line 1991 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Scalar_Comparison=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Scalar_Comparison); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5532 "parser.c"
    break;

  case 388: /* Combinand: Negation  */
#line 1992 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Negation=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Negation); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5538 "parser.c"
    break;

  case 389: /* Combinand: Existence  */
#line 1993 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Existence=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Existence); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5544 "parser.c"
    break;

  case 390: /* Combinand: Point_In_Time  */
#line 1994 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Point_In_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Point_In_Time); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5550 "parser.c"
    break;

  case 391: /* Combinand: Expiration  */
#line 1995 "parser.y"
                                                                  { NEW(Combinand, *((Literal **)&yylval)); Combinand->Expiration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Expiration); ((*yyvalp).Combinand)=process_combinand(Combinand); }
#line 5556 "parser.c"
    break;

  case 392: /* Combinator: Or_  */
#line 2001 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Or_=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Or_); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5562 "parser.c"
    break;

  case 393: /* Combinator: And  */
#line 2002 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->And=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.And); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5568 "parser.c"
    break;

  case 394: /* Combinator: Neither  */
#line 2003 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Neither=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Neither); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5574 "parser.c"
    break;

  case 395: /* Combinator: Nor  */
#line 2004 "parser.y"
                                                                  { NEW(Combinator, *((Literal **)&yylval)); Combinator->Nor=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Nor); ((*yyvalp).Combinator)=process_combinator(Combinator); }
#line 5580 "parser.c"
    break;

  case 396: /* Or_: OR  */
#line 2010 "parser.y"
                                                                  { NEW(Or_, *((Literal **)&yylval)); ((*yyvalp).Or_)=process_or_(Or_); }
#line 5586 "parser.c"
    break;

  case 397: /* And: AND  */
#line 2016 "parser.y"
                                                                  { NEW(And, *((Literal **)&yylval)); ((*yyvalp).And)=process_and(And); }
#line 5592 "parser.c"
    break;

  case 398: /* Neither: NEITHER  */
#line 2022 "parser.y"
                                                                  { NEW(Neither, *((Literal **)&yylval)); ((*yyvalp).Neither)=process_neither(Neither); }
#line 5598 "parser.c"
    break;

  case 399: /* Nor: NOR  */
#line 2028 "parser.y"
                                                                  { NEW(Nor, *((Literal **)&yylval)); ((*yyvalp).Nor)=process_nor(Nor); }
#line 5604 "parser.c"
    break;

  case 400: /* Existence: Symbol Equal Fixed  */
#line 2034 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Equal=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Equal); Existence->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5610 "parser.c"
    break;

  case 401: /* Existence: THERE Be Symbol  */
#line 2035 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5616 "parser.c"
    break;

  case 402: /* Existence: Contract Be Symbol  */
#line 2036 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Existence->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5622 "parser.c"
    break;

  case 403: /* Existence: Symbol Being True  */
#line 2037 "parser.y"
                                                                  { NEW(Existence, *((Literal **)&yylval)); Existence->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Existence->Being=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Being); Existence->True=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.True); ((*yyvalp).Existence)=process_existence(Existence); }
#line 5628 "parser.c"
    break;

  case 404: /* Negation: Negator Symbol  */
#line 2043 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5634 "parser.c"
    break;

  case 405: /* Negation: Symbol Negator Fixed  */
#line 2044 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Symbol); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Fixed=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Fixed); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5640 "parser.c"
    break;

  case 406: /* Negation: THERE Negator Symbol  */
#line 2045 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5646 "parser.c"
    break;

  case 407: /* Negation: Contract Negator Symbol  */
#line 2046 "parser.y"
                                                                  { NEW(Negation, *((Literal **)&yylval)); Negation->Contract=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Contract); Negation->Negator=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Negator); Negation->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Negation)=process_negation(Negation); }
#line 5652 "parser.c"
    break;

  case 408: /* Negator: NOT  */
#line 2052 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5658 "parser.c"
    break;

  case 409: /* Negator: Be NOT  */
#line 2053 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5664 "parser.c"
    break;

  case 410: /* Negator: NO  */
#line 2054 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5670 "parser.c"
    break;

  case 411: /* Negator: Be NO  */
#line 2055 "parser.y"
                                                                  { NEW(Negator, *((Literal **)&yylval)); Negator->Be=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Be); ((*yyvalp).Negator)=process_negator(Negator); }
#line 5676 "parser.c"
    break;

  case 412: /* Being: IS  */
#line 2061 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5682 "parser.c"
    break;

  case 413: /* Being: HAS BEEN  */
#line 2062 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5688 "parser.c"
    break;

  case 414: /* Being: WAS  */
#line 2063 "parser.y"
                                                                  { NEW(Being, *((Literal **)&yylval)); ((*yyvalp).Being)=process_being(Being); }
#line 5694 "parser.c"
    break;

  case 415: /* True: TRUE  */
#line 2069 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5700 "parser.c"
    break;

  case 416: /* True: YES  */
#line 2070 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5706 "parser.c"
    break;

  case 417: /* True: CERTIFIED  */
#line 2071 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5712 "parser.c"
    break;

  case 418: /* True: DECLARED  */
#line 2072 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5718 "parser.c"
    break;

  case 419: /* True: ANNOUNCED  */
#line 2073 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5724 "parser.c"
    break;

  case 420: /* True: FILED  */
#line 2074 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5730 "parser.c"
    break;

  case 421: /* True: FILED FOR  */
#line 2075 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5736 "parser.c"
    break;

  case 422: /* True: SIGNED OFF  */
#line 2076 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5742 "parser.c"
    break;

  case 423: /* True: SIGNED OFF ON  */
#line 2077 "parser.y"
                                                                  { NEW(True, *((Literal **)&yylval)); ((*yyvalp).True)=process_true(True); }
#line 5748 "parser.c"
    break;

  case 424: /* Article: A  */
#line 2083 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5754 "parser.c"
    break;

  case 425: /* Article: AN  */
#line 2084 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5760 "parser.c"
    break;

  case 426: /* Article: THE  */
#line 2085 "parser.y"
                                                                  { NEW(Article, *((Literal **)&yylval)); ((*yyvalp).Article)=process_article(Article); }
#line 5766 "parser.c"
    break;

  case 427: /* New: NEW  */
#line 2091 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5772 "parser.c"
    break;

  case 428: /* New: NEXT  */
#line 2092 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5778 "parser.c"
    break;

  case 429: /* New: COMING  */
#line 2093 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5784 "parser.c"
    break;

  case 430: /* New: INCOMING  */
#line 2094 "parser.y"
                                                                  { NEW(New, *((Literal **)&yylval)); ((*yyvalp).New)=process_new(New); }
#line 5790 "parser.c"
    break;

  case 431: /* Point_In_Time: Current_Time  */
#line 2100 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Current_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Current_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5796 "parser.c"
    break;

  case 432: /* Point_In_Time: Relative_Time  */
#line 2101 "parser.y"
                                                                  { NEW(Point_In_Time, *((Literal **)&yylval)); Point_In_Time->Relative_Time=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Relative_Time); ((*yyvalp).Point_In_Time)=process_point_in_time(Point_In_Time); }
#line 5802 "parser.c"
    break;

  case 433: /* Current_Time: THE CURRENT TIME  */
#line 2107 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5808 "parser.c"
    break;

  case 434: /* Current_Time: THE THEN CURRENT TIME  */
#line 2108 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5814 "parser.c"
    break;

  case 435: /* Current_Time: THE RESPECTIVE CURRENT TIME  */
#line 2109 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5820 "parser.c"
    break;

  case 436: /* Current_Time: THE RESPECTIVE THEN CURRENT TIME  */
#line 2110 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5826 "parser.c"
    break;

  case 437: /* Current_Time: NOW  */
#line 2111 "parser.y"
                                                                  { NEW(Current_Time, *((Literal **)&yylval)); ((*yyvalp).Current_Time)=process_current_time(Current_Time); }
#line 5832 "parser.c"
    break;

  case 438: /* Relative_Time: Duration PAST  */
#line 2117 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5838 "parser.c"
    break;

  case 439: /* Relative_Time: Duration PAST Symbol  */
#line 2118 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5844 "parser.c"
    break;

  case 440: /* Relative_Time: Duration IN THE PAST  */
#line 2119 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Duration); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5850 "parser.c"
    break;

  case 441: /* Relative_Time: Duration IN THE PAST Symbol  */
#line 2120 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5856 "parser.c"
    break;

  case 442: /* Relative_Time: Duration AFTER Symbol  */
#line 2121 "parser.y"
                                                                  { NEW(Relative_Time, *((Literal **)&yylval)); Relative_Time->Duration=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Duration); Relative_Time->Symbol=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Symbol); ((*yyvalp).Relative_Time)=process_relative_time(Relative_Time); }
#line 5862 "parser.c"
    break;

  case 443: /* Duration: Scalar_Expression Time_Unit  */
#line 2127 "parser.y"
                                                                  { NEW(Duration, *((Literal **)&yylval)); Duration->Scalar_Expression=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Scalar_Expression); Duration->Time_Unit=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Time_Unit); ((*yyvalp).Duration)=process_duration(Duration); }
#line 5868 "parser.c"
    break;

  case 444: /* Time_Unit: Years  */
#line 2133 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Years=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Years); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5874 "parser.c"
    break;

  case 445: /* Time_Unit: Months  */
#line 2134 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Months=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Months); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5880 "parser.c"
    break;

  case 446: /* Time_Unit: Weeks  */
#line 2135 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Weeks=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Weeks); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5886 "parser.c"
    break;

  case 447: /* Time_Unit: Days  */
#line 2136 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Days=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Days); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5892 "parser.c"
    break;

  case 448: /* Time_Unit: Hours  */
#line 2137 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Hours=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Hours); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5898 "parser.c"
    break;

  case 449: /* Time_Unit: Minutes  */
#line 2138 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Minutes=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Minutes); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5904 "parser.c"
    break;

  case 450: /* Time_Unit: Seconds  */
#line 2139 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Seconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Seconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5910 "parser.c"
    break;

  case 451: /* Time_Unit: Milliseconds  */
#line 2140 "parser.y"
                                                                  { NEW(Time_Unit, *((Literal **)&yylval)); Time_Unit->Milliseconds=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Milliseconds); ((*yyvalp).Time_Unit)=process_time_unit(Time_Unit); }
#line 5916 "parser.c"
    break;

  case 452: /* Years: YEAR  */
#line 2146 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5922 "parser.c"
    break;

  case 453: /* Years: YEARS  */
#line 2147 "parser.y"
                                                                  { NEW(Years, *((Literal **)&yylval)); ((*yyvalp).Years)=process_years(Years); }
#line 5928 "parser.c"
    break;

  case 454: /* Months: MONTH  */
#line 2153 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5934 "parser.c"
    break;

  case 455: /* Months: MONTHS  */
#line 2154 "parser.y"
                                                                  { NEW(Months, *((Literal **)&yylval)); ((*yyvalp).Months)=process_months(Months); }
#line 5940 "parser.c"
    break;

  case 456: /* Weeks: WEEK  */
#line 2160 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5946 "parser.c"
    break;

  case 457: /* Weeks: WEEKS  */
#line 2161 "parser.y"
                                                                  { NEW(Weeks, *((Literal **)&yylval)); ((*yyvalp).Weeks)=process_weeks(Weeks); }
#line 5952 "parser.c"
    break;

  case 458: /* Days: DAY  */
#line 2167 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5958 "parser.c"
    break;

  case 459: /* Days: DAYS  */
#line 2168 "parser.y"
                                                                  { NEW(Days, *((Literal **)&yylval)); ((*yyvalp).Days)=process_days(Days); }
#line 5964 "parser.c"
    break;

  case 460: /* Hours: HOUR  */
#line 2174 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5970 "parser.c"
    break;

  case 461: /* Hours: HOURS  */
#line 2175 "parser.y"
                                                                  { NEW(Hours, *((Literal **)&yylval)); ((*yyvalp).Hours)=process_hours(Hours); }
#line 5976 "parser.c"
    break;

  case 462: /* Minutes: MINUTE  */
#line 2181 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5982 "parser.c"
    break;

  case 463: /* Minutes: MINUTES  */
#line 2182 "parser.y"
                                                                  { NEW(Minutes, *((Literal **)&yylval)); ((*yyvalp).Minutes)=process_minutes(Minutes); }
#line 5988 "parser.c"
    break;

  case 464: /* Seconds: SECOND  */
#line 2188 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 5994 "parser.c"
    break;

  case 465: /* Seconds: SECONDS  */
#line 2189 "parser.y"
                                                                  { NEW(Seconds, *((Literal **)&yylval)); ((*yyvalp).Seconds)=process_seconds(Seconds); }
#line 6000 "parser.c"
    break;

  case 466: /* Milliseconds: MILLISECOND  */
#line 2195 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 6006 "parser.c"
    break;

  case 467: /* Milliseconds: MILLISECONDS  */
#line 2196 "parser.y"
                                                                  { NEW(Milliseconds, *((Literal **)&yylval)); ((*yyvalp).Milliseconds)=process_milliseconds(Milliseconds); }
#line 6012 "parser.c"
    break;

  case 468: /* Expiration: HAS PASSED  */
#line 2202 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 6018 "parser.c"
    break;

  case 469: /* Expiration: PAST  */
#line 2203 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 6024 "parser.c"
    break;

  case 470: /* Expiration: IS PAST  */
#line 2204 "parser.y"
                                                                  { NEW(Expiration, *((Literal **)&yylval)); ((*yyvalp).Expiration)=process_expiration(Expiration); }
#line 6030 "parser.c"
    break;

  case 471: /* Timeliness: NOT PASSED  */
#line 2210 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6036 "parser.c"
    break;

  case 472: /* Timeliness: NOT YET PASSED  */
#line 2211 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6042 "parser.c"
    break;

  case 473: /* Timeliness: HAS NOT PASSED  */
#line 2212 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6048 "parser.c"
    break;

  case 474: /* Timeliness: HAS NOT YET PASSED  */
#line 2213 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6054 "parser.c"
    break;

  case 475: /* Timeliness: NOT PAST  */
#line 2214 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6060 "parser.c"
    break;

  case 476: /* Timeliness: NOT PAST YET  */
#line 2215 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6066 "parser.c"
    break;

  case 477: /* Timeliness: NOT YET PAST  */
#line 2216 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6072 "parser.c"
    break;

  case 478: /* Timeliness: NOT YET PAST YET  */
#line 2217 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6078 "parser.c"
    break;

  case 479: /* Timeliness: IS NOT PAST  */
#line 2218 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6084 "parser.c"
    break;

  case 480: /* Timeliness: IS NOT PAST YET  */
#line 2219 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6090 "parser.c"
    break;

  case 481: /* Timeliness: IS NOT YET PAST  */
#line 2220 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6096 "parser.c"
    break;

  case 482: /* Timeliness: IS NOT YET PAST YET  */
#line 2221 "parser.y"
                                                                  { NEW(Timeliness, *((Literal **)&yylval)); ((*yyvalp).Timeliness)=process_timeliness(Timeliness); }
#line 6102 "parser.c"
    break;

  case 483: /* Name: NAME  */
#line 2225 "parser.y"
                                                                { ((*yyvalp).Name)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.NAME); }
#line 6108 "parser.c"
    break;

  case 484: /* Description: DESCRIPTION  */
#line 2228 "parser.y"
                                                                                { ((*yyvalp).Description)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.DESCRIPTION); }
#line 6114 "parser.c"
    break;

  case 485: /* Scalar: SCALAR  */
#line 2231 "parser.y"
                                                                { ((*yyvalp).Scalar)=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.SCALAR); }
#line 6120 "parser.c"
    break;


#line 6124 "parser.c"

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




#line 2236 "parser.y"


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
	// Condition->After
	return Condition;
}

If *process_if(If *If) {
	if(opt_debug_actions) printf("actions: parsing If '%s'\n", If->Literal);
	return If;
}

After *process_after(After *After) {
	if(opt_debug_actions) printf("actions: parsing After '%s'\n", After->Literal);
	return After;
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

