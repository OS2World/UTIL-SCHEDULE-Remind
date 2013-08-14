/***************************************************************/
/*                                                             */
/*  LANG.H                                                     */
/*                                                             */
/*  Header file for language support for various languages.    */
/*                                                             */
/*  This file is part of REMIND.                               */
/*  Copyright (C) 1992, 1993 by David F. Skoll.                */
/*                                                             */
/***************************************************************/

/* I'm chauvinistic and name each language with its English name... */

#define ENGLISH    0 /* original by David Skoll */
#define GERMAN     1 /* translated by Wolfgang Thronicke */
#define DUTCH      2 /* translated by Willem Kasdorp and Erik-Jan Vens */
#define FINNISH    3 /* translated by Mikko Silvonen */
#define FRENCH	   4 /* translated by Laurent Duperval */
#define NORWEGIAN  5 /* translated by Trygve Randen */

/* Add more languages here - but please e-mail dfs@doe.carleton.ca
   to have your favorite language assigned a number.  If you add a
   language, please send me the header file, and permission to include
   it in future releases of Remind.  Note that you'll get no remuneration
   for this service - just everlasting fame. :-)

   Use the file tstlang.rem to test your new language file. */

/************************************************************************
 *                                                                      *
 *       Define the language you want to use here                       *
 *                                                                      *
 ************************************************************************/
#ifndef LANG  /* Allow for definition on compiler command line */
#define LANG ENGLISH
#endif

/* If LANG is not defined, it defaults to English. */
#ifndef LANG
#define LANG ENGLISH
#endif


/* Pick up the appropriate header file */
#if LANG == ENGLISH
#include "english.h"
#elif LANG == GERMAN
#include "german.h"
#elif LANG == DUTCH
#include "dutch.h"
#elif LANG == FINNISH
#include "finnish.h"
#elif LANG == FRENCH
#include "french.h"
#elif LANG == NORWEGIAN
#include "norwgian.h"

/* If no sensible language, choose English.  I intended to use
   the #error directive here, but some C compilers barf. */
#else
#include "english.h"
#endif
