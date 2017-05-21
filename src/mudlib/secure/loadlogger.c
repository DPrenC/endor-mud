/* /secure/loadlogger
**
** Just makes every five minutes a one line log into a file.
** The line contains:
**   ctime() #total_users #players #wizards cmds/s lines/s #objects
** The numbers may be evaluated later with GNUplot or similar.
**
** Idea by Freaky (Unitopia).
**
**   11-Jan-94 [Mateese]
**   01-Aug-96 [Mateese] Added #objects count.
*/

#include "/secure/config.h"

#define LOGFILE ("/log/LOADLOG."+__HOST_NAME__)
#define DELAY 600

/*------------------------------------------------------------------------*/

create()
{
  seteuid(getuid(TO));

  if (   getuid(TO) != ROOTID
      || -1 != member(object_name(TO), '#')) {
    write(
 ctime(time())+": Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
         );
    destruct (TO);
    return;
  }
  do_log();
}

/*------------------------------------------------------------------------*/

static do_log() {
  string *s, rc;
  object *wiz, *pl, o;
  int nru, nro;
  while (remove_call_out("do_log") != -1);
  pl = users();
  nru = sizeof(pl);
  wiz = filter(pl, SF(query_wiz_level));
  pl = pl - wiz;
  s = explode(query_load_average(), " ");
  for (nro = 0, o = 0; o = debug_info(2, o); nro++);
  rc = ctime()+"\t"
       +nru+"\t"
       +sizeof(pl)+"\t"
       +sizeof(wiz)+"\t"
       +s[0]+"\t"
       +s[2]+"\t"
       + nro+"\n";
  write_file(LOGFILE, rc);
  call_out("do_log", DELAY);
}

/*========================================================================*/
