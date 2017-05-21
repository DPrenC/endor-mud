/***
Fichero: lingote_plata.c
autor: kastwey@simauria
Descripci�n: un lingote para el quest del ghoul.
***/

#include "path.h"
#include <moving.h>
#include <properties.h>


inherit THING;

create()
{
  ::create();
  SetShort("un lingote de plata");
  SetLong(W("Es un peque�o lingote de plata. "
  "Est� tan pulido que puedes ver tu reflejo sobre su superficie.\n"));
  AddId(({"lingote","lingote de plata","lingote_quest_ghoul"}));
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  SetValue(40000);
  SetWeight(150);
}

public varargs int move(mixed dest, int method, mixed extra)
{
 	if (method == M_GET && QUESTMASTER->QueryQuestSolved("kill_ghoul",TP)) return write("Miras el lingote, y luego piensas que, si ya as hecho el quest... para qu� lo quieres?\n"),ME_NO_GET;
 	else if (method == M_GIVE && !dest->QueryHerreroTamaraQuest()) return ME_NO_GIVE;
 	else return ::move(dest, method, extra);
}
