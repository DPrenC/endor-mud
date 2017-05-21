/* SIMAURIA /obj/gameclock.c'
   ==========================
   [w] Woo@simauria
   [n] Nemesis@simauria
   [t] Theuzifan@simauria

   16-06-97 [w] Traducidas algunas cosas, aun queda.
   07-01-98 [w] Traducidos los distintos momentos del dia.
   13-03-98 [n,t] Arreglado un pequenyo fallo de que no salia el momento del dia
 		 algunas veces.
   Mar'99 [n] Castellanizado.
*/

#include <config.h>
#include <nightday.h>

void create () {
  if (member(object_name(TO), '#') != -1) {
    destruct(TO);
    return;
  }
}

int clean_up(int ref) {
  if (ref <= 1)
    destruct(TO);
  return TO && 1;
}

int QueryBoottime() { return query_boot_time(); }

string QueryDaytime() {
  if (!find_object(NIGHTDAY)&&!load_object(NIGHTDAY))
    return "nightday.c no cargado";
  switch ((int)NIGHTDAY->QueryState()) {
    case ND_NIGHT   : return "noche";
    case ND_PREDAWN : return "cerca del alba";
    case ND_DAWN    : return "alba";
    case ND_SUNRISE : return "amanecer";
    case ND_PRENOON : return "mañana";
    case ND_DAY     : return "día";
    case ND_POSTNOON: return "tarde";
    case ND_PREFALL : return "tarde avanzada";
    case ND_FALL    : return "anochecer";
    case ND_PRENIGHT: return "casi de noche";
    default: return "indeterminado";
  }
  return 0;
}

mixed * QueryUptime () {
  mixed rc;
  int uptime, j;
  int firstset, boottime;

  boottime = query_boot_time();
  if (boottime < 1 || boottime > time())
    return 0;
  uptime = time() - boottime;

  rc = allocate(8);
  firstset = -1;

  j = uptime / 60 / 60 / 24;
  rc[0] = j;
  rc[1] = j == 1 ? "día" : "días";
  uptime -= j * 60 * 60 * 24;
  if (firstset < 0 && j != 0)
    firstset = 0;

  j = uptime / 60 / 60;
  rc[2] = j;
  rc[3] = j == 1 ? "hora" : "horas";
  uptime -= j * 60 * 60;
  if (firstset < 0 && j != 0)
    firstset = 2;

  j = uptime / 60;
  rc[4] = j;
  rc[5] = j == 1 ? "minuto" : "minutos";
  uptime -= j * 60;
  if (firstset < 0 && j != 0)
    firstset = 4;

  rc[6] = uptime;
  rc[7] = uptime == 1 ? "segundo" : "segundos";
  if (firstset < 0)
    firstset = 6;

  return rc[firstset..];
}
