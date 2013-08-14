This archive contains a port to OS/2 1.x--2.x and DOS of David Skoll's
Remind 3.0.10. David Skoll writes:

   Remind is a sophisticated calendar/alarm program, which runs under
   MS-DOS, UNIX and OS/2.  I have posted Patch 10 to comp.sources.misc.

The flexibility of the triggers (and some other nice features)
distinguish this program from other reminder-like programs. Norm Walsh
remarks that VREXX can add PM-popup capability to Remind (see below).

The OS/2 changes will be integrated into the next release of
Remind. This interim release is to replace an older version, and to
provide a version for the Nov-93 CD of ftp-os2.cdrom.com.

Russ Herman (rwh@gov.on.ca) is reponsible for the popup capability and
support for the bcc compiler. EMX/gcc and MSC support are from Norm
Walsh (norm@ora.com) and Darrel Hankerson (hankedr@mail.auburn.edu).

Files:
 ./ 
   remind.exe   OS/2 1.x--2.x and DOS executable
   rem2ps.exe   
   remind.man   documentation ("groff -man remind.1 > remind.man")
   rem2ps.man
   defs.rem     sample definitions
 src/           sources
   patches.os2  context-diffs from 3.0.10
   

Notes: Norm Walsh suggested using VREXX to add PM popups to Remind.
VREXX is by Richard B. Lam, and is available at ftp-os2.cdrom.com
in pub/os2/ews/vrexx2.zip. 

A very basic outline of a VREXX script to add the PM popup capability 
is given by the following popup.cmd file:

  /* popup.cmd: Popup ARG(1) message */
  call RxFuncAdd 'VInit', 'VREXX', 'VINIT'
  initcode = VInit()
  if initcode = 'ERROR' then signal CLEANUP

  signal on failure name CLEANUP
  signal on halt name CLEANUP
  signal on syntax name CLEANUP

  msg.0 = 1
  msg.1 = ARG(1)
  call VMsgBox 'Remind', msg, 1

  CLEANUP:
    call VExit

  exit

The '-k' option of Remind is used to specify the command for MSG-type
reminders. If your shell is cmd.exe, then 

    remind "-kpopup %s" mytest.rem

might be a typical example (use %%s for 4os2).


--
Darrel Hankerson hankedr@mail.auburn.edu
4 November 1993

