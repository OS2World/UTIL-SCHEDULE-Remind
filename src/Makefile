# Makefile for REMIND

#-----------------------------------------------------------------------------
# THINGS FOR YOU TO EDIT START BELOW
#-----------------------------------------------------------------------------

# Uncomment the next line if you are running on a SYSV system
# SYSV= -DSYSV

# Uncomment the next line if you are running under UNIX (including SYSV!)
UNIX= -DUNIX

# Uncomment the next lines if you want to use gcc instead of default compiler
# NOTE:  Tempting as it may be, if you use 'cc' for the C compiler, do not
# use 'ld' for the linker.  It will probably work much better if you use
# LD= cc rather than LD= ld.
CC= gcc
LD= gcc

# Put any additional flags for the C compiler or linker here - if you
# are not using gcc, you probably want to remove '-ansi'.
CFLAGS= -O -ansi
CDEFS=
LDFLAGS=

#### INSTALLATION LOCATIONS ####
# Note that I use 'cp' rather than 'install' for improved portability.
#
# BINDIR:  Where should the Remind executable be installed?
BINDIR= /usr/local/bin

# SCRIPTDIR:  Where should the kall and rem shell scripts be installed?
SCRIPTDIR= /usr/share/bin

# MANDIR:  Where should the man pages be installed?
MANDIR= /usr/local/man

# MANSECT:  Which man section should the man pages go into?
MANSECT= 1

# EXEMODE:  What file protection mode should be used for the executables?
EXEMODE= 755

# MANMODE:  What file protection mode should be used for the man pages?
MANMODE= 644

# OWNER, GROUP:  What owner and group to use for executables,
# scripts and man pages?
OWNER=bin
GROUP=bin

#-----------------------------------------------------------------------------
# YOU SHOULDN'T EDIT ANYTHING BELOW HERE.  You may want to change some things
# in config.h; then, you should be able to type 'make'.
#-----------------------------------------------------------------------------
VERSION= 03.00.10
MATHLIB= -lm

HDRS= config.h err.h expr.h globals.h protos.h types.h version.h \
lang.h english.h german.h dutch.h finnish.h french.h norwgian.h

STDHDRS= config.h types.h protos.h globals.h err.h lang.h

LANGHDRS= english.h german.h dutch.h finnish.h french.h norwgian.h

SRCS= calendar.c dorem.c dosubst.c expr.c files.c funcs.c globals.c hbcal.c \
init.c main.c moon.c omit.c sort.c queue.c token.c trigger.c userfns.c \
utils.c var.c

MANIFEST= README.UNIX README.DOS COPYRIGHT $(HDRS) $(SRCS) Makefile rem rem.1 \
remind.1 remind-all.csh remind-all.sh test.rem test-rem test.cmp makefile.tc \
makefile.msc lnk.msc lnk.tc MANIFEST.UNX MANIFEST.DOS WHATSNEW.30 kall kall.1 \
defs.rem README.OS2 makefile.os2 rem2ps.c rem2ps.h remind.def rem2ps.1 \
tstlang.rem README.BCC lnk.bcc makefile.bcc os2func.c \
test-rem.bat test-rem.cmd test1.cmp test2.cmp


OBJS= $(SRCS:.c=.o)

all: remind rem2ps

.c.o:
	$(CC) $(UNIX) $(SYSV) -c $(CFLAGS) $(CDEFS) $*.c

rem2ps: rem2ps.o
	$(LD) $(LDFLAGS) -o rem2ps rem2ps.o

remind: $(OBJS)
	$(LD) $(LDFLAGS) -o remind $(OBJS) $(MATHLIB)

clean:
	rm -f *.o *~ core *.bak

clobber:
	rm -f *.o *~ remind rem2ps test.out core *.bak

test: remind
	sh test-rem

rem2ps.o: rem2ps.c rem2ps.h lang.h config.h
calendar.o: calendar.c $(STDHDRS) expr.h
dorem.o: dorem.c $(STDHDRS) expr.h
dosubst.o: dosubst.c $(STDHDRS) $(LANGHDRS)
expr.o: expr.c $(STDHDRS) expr.h
files.o: files.c $(STDHDRS)
funcs.o: funcs.c $(STDHDRS) expr.h version.h
globals.o: globals.c config.h types.h globals.h err.h lang.h $(LANGHDRS)
hbcal.o: hbcal.c $(STDHDRS)
init.o: init.c $(STDHDRS) expr.h version.h lang.h $(LANGHDRS)
main.o: main.c $(STDHDRS) expr.h
moon.o: moon.c $(STDHDRS)
omit.o: omit.c $(STDHDRS)
sort.o: sort.c $(STDHDRS)
queue.o: queue.c $(STDHDRS)
token.o: token.c $(STDHDRS)
trigger.o: trigger.c $(STDHDRS) expr.h
userfns.o: userfns.c $(STDHDRS) expr.h
utils.o: utils.c $(STDHDRS)
var.o: var.c $(STDHDRS) expr.h

tarZ:
	tar cvf remind-3.0.10.tar $(MANIFEST)
	compress -v remind-3.0.10.tar

shar:
	shar -x -n"Remind $(VERSION)" -l45 -o./Shar $(MANIFEST)

todos:
	mcopy -tn $(MANIFEST) a:

fromdos:
	mcopy -tn 'a:*' .
	-mv -f copyrigh COPYRIGHT
	-mv -f makefile Makefile
	-mv -f readme.os2 README.OS2
	-mv -f readme.dos README.DOS
	-mv -f readme.bcc README.BCC
	-mv -f readme.uni README.UNIX
	-mv -f remind-a.csh remind-all.csh
	-mv -f remind-a.sh remind-all.sh
	-mv -f manifest.dos MANIFEST.DOS
	-mv -f manifest.unx MANIFEST.UNX
	-mv -f whatsnew.30 WHATSNEW.30
	-chmod u+x test-rem

backup:
	cp $(MANIFEST) ../backup

transmit:
	sz -a -e $(MANIFEST)

install:  install-bin install-scripts install-man

install-bin: remind rem2ps
	cp remind $(BINDIR)/remind
	-chmod $(EXEMODE) $(BINDIR)/remind
	-chown $(OWNER) $(BINDIR)/remind
	-chgrp $(GROUP) $(BINDIR)/remind
	cp rem2ps $(BINDIR)/rem2ps
	-chmod $(EXEMODE) $(BINDIR)/rem2ps
	-chown $(OWNER) $(BINDIR)/rem2ps
	-chgrp $(GROUP) $(BINDIR)/rem2ps

install-scripts:
	cp kall $(SCRIPTDIR)/kall
	-chmod $(EXEMODE) $(SCRIPTDIR)/kall
	-chown $(OWNER) $(SCRIPTDIR)/kall
	-chgrp $(GROUP) $(SCRIPTDIR)/kall
	cp rem $(SCRIPTDIR)/rem
	-chmod $(EXEMODE) $(SCRIPTDIR)/rem
	-chown $(OWNER) $(SCRIPTDIR)/rem
	-chgrp $(GROUP) $(SCRIPTDIR)/rem

install-man:
	cp remind.1 $(MANDIR)/man$(MANSECT)/remind.$(MANSECT)
	-chmod $(MANMODE) $(MANDIR)/man$(MANSECT)/remind.$(MANSECT)
	-chown $(OWNER) $(MANDIR)/man$(MANSECT)/remind.$(MANSECT)
	-chgrp $(GROUP) $(MANDIR)/man$(MANSECT)/remind.$(MANSECT)
	cp rem.1 $(MANDIR)/man$(MANSECT)/rem.$(MANSECT)
	-chmod $(MANMODE) $(MANDIR)/man$(MANSECT)/rem.$(MANSECT)
	-chown $(OWNER) $(MANDIR)/man$(MANSECT)/rem.$(MANSECT)
	-chgrp $(GROUP) $(MANDIR)/man$(MANSECT)/rem.$(MANSECT)
	cp kall.1 $(MANDIR)/man$(MANSECT)/kall.$(MANSECT)
	-chmod $(MANMODE) $(MANDIR)/man$(MANSECT)/kall.$(MANSECT)
	-chown $(OWNER) $(MANDIR)/man$(MANSECT)/kall.$(MANSECT)
	-chgrp $(GROUP) $(MANDIR)/man$(MANSECT)/kall.$(MANSECT)
	cp rem2ps.1 $(MANDIR)/man$(MANSECT)/rem2ps.$(MANSECT)
	-chmod $(MANMODE) $(MANDIR)/man$(MANSECT)/rem2ps.$(MANSECT)
	-chown $(OWNER) $(MANDIR)/man$(MANSECT)/rem2ps.$(MANSECT)
	-chgrp $(GROUP) $(MANDIR)/man$(MANSECT)/rem2ps.$(MANSECT)

release:
	-mkdir RELEASE
	-rm -f RELEASE/*
	mkpatch ../prev . patch.10 Shar "Remind-3.0/Patch-10/part"
	mv Shar* RELEASE
	rm -f patch.10
	for i in *.1; do nroff -man $$i | sed -e 's/_//g' > `basename $$i .1`.man; done
	mv *.man RELEASE
	for i in *.1; do groff -man -Tps $$i > `basename $$i .1`.ps; done
	mv *.ps RELEASE

# Meant for debugging - don't invoke this target unless you know what
# you're doing!
majortest:
	for comp in "cc" "gcc -Wall -pedantic -ansi" ; do for lang in 1 2 3 4 5 0 ; do for def in ISOLATIN1 IBMEXTENDED FOOBARBAZ ; do echo $$def $$lang ; $(MAKE) clobber ; $(MAKE) "CDEFS=-DLANG=$$lang -D$$def=1" CFLAGS=-O "CC=$$comp" "LD=$$comp" ; done ; done ; done

