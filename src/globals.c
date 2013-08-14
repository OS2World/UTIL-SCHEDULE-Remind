/***************************************************************/
/*                                                             */
/*  GLOBALS.C                                                  */
/*                                                             */
/*  This file simply instantiates all of the global variables. */
/*                                                             */
/*  It does this by #defining MK_GLOBALS and #including        */
/*  globals.h and err.h                                        */
/*                                                             */
/*  This file is part of REMIND.                               */
/*  Copyright (C) 1992, 1993 by David F. Skoll.                */
/*                                                             */
/***************************************************************/
#include "config.h"
#include <stdio.h>   /* For defintion of FILE - sigh! */
#include "types.h"
#define MK_GLOBALS
#include "globals.h"
#include "err.h"
