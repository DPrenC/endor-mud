/* SIMAURIA /std/guild/stats_new.c
   ===============================
   [h] Nyh

   XX-12-04 [h] Creación a partir del antiguo /std/guild/stats.c
*/

#include <guild.h>
#include <races.h>     // RD_STAT
#include <config.h>    // RACEMASTER, NOTIFY_
#include <stats.h>

#define T(x) "True"+x


// [Nyh] añado coisas
#ifndef STATS
#define STATS ({ P_STR, P_DEX, P_CON, P_INT, P_WIS, P_CHA })
#endif


/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/

/* [Nyh] Dejo esto para ver si me falla algo de por medio... loggeo
* Stats
* =====
*/

public mapping SetMinStats(mapping stats) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->SetMinStats(%O)\n",ctime(),PO,TO,stats));
  return G_MINSTATS;
}

public varargs mapping QueryMinStats(object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMinStats(%O)\n",ctime(),PO,TO,pl));
  return G_MINSTATS;
}

public varargs int QueryMinStat(string stat,object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMinStat(%O,%O)\n",ctime(),PO,TO,stat,pl));
  return QueryMinStats(pl)[stat];
}

public mapping AddMinStat(string stat,int value) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->AddMinStat(%O, %O)\n",ctime(),PO,TO,stat, value));
  return G_MINSTATS;
}

public mapping SetMaxStats(mapping stats) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->SetMMaxStats(%O)\n",ctime(),PO,TO,stats));
  return G_MAXSTATS;
}

public mapping SetModMaxStats(mapping stats) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->SetModMaxStats(%O)\n",ctime(),PO,TO,stats));
  return G_MAXSTATS;
}

public varargs mapping QueryMaxStats(object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMaxStats(%O)\n",ctime(),PO,TO,pl));
  return G_MAXSTATS;
}

public varargs int QueryMaxStat(string stat,object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMaxStat(%O, %O)\n",ctime(),PO,TO,stat, pl));
  return QueryMaxStats(pl)[stat];
}

public mapping AddMaxStat(string stat,int value) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->AddMaxStat(%O, %O)\n",ctime(),PO,TO,stat, value));
  return G_MAXSTATS;
}

public mapping SetMaxHLPStats(mapping stats) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->SetMaxHLPStats(%O)\n",ctime(),PO,TO,stats));
  return G_MAXSTATS;
}

public mapping SetModMaxHLPStats(mapping stats) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->SetModMaxHLPStats(%O)\n",ctime(),PO,TO,stats));
  return G_MAXSTATS;
}

public varargs mapping QueryMaxHLPStats(object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMaxHLPStats(%O)\n",ctime(),PO,TO,pl));
  return G_MAXSTATS;
}

public varargs int QueryMaxHLPStat(string stat,object pl) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->QueryMaxHLPStat(%O, %O)\n",ctime(),PO,TO,stat, pl));
  return QueryMaxHLPStats(pl)[stat];
}

public mapping AddMaxHLPStat(string stat,int value) {
  log_file("/NEW_STATS",sprintf("[%O] %O llamó a %O->AddMaxHLPStat(%O, %O)\n",ctime(),PO,TO,stat, value));
  return G_MAXSTATS;
}
