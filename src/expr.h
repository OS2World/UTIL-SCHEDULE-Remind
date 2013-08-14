/***************************************************************/
/*                                                             */
/*  EXPR.H                                                     */
/*                                                             */
/*  Contains a few definitions used by expression evaluator.   */
/*                                                             */
/*  This file is part of REMIND.                               */
/*  Copyright (C) 1992, 1993 by David F. Skoll.                */
/*                                                             */
/***************************************************************/

/* Define the types of values */
#define ERR_TYPE 0
#define INT_TYPE 1
#define TIM_TYPE 2
#define DATE_TYPE 3
#define STR_TYPE 4

/* Define stuff for parsing expressions */
#define BEG_OF_EXPR '['
#define END_OF_EXPR ']'
#define COMMA ','

#define UN_OP 0  /* Unary operator */
#define BIN_OP 1 /* Binary Operator */
#define FUNC 2   /* Function */
