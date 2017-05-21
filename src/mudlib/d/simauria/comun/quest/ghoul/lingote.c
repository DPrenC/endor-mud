/***
Fichero: lingote_plata.c
autor: kastwey@simauria
Descripción: un lingote para el quest del ghoul.
***/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit THING;
int pLibre;
public int SetLibre(int valor);
public int QueryLibre();

create()
{
  ::create();
  SetShort("un lingote de plata");
  SetLong(W("Es un pequeño lingote de plata. "
  "Está tan pulido que puedes ver tu reflejo sobre su superficie.\n"));
  AddId(({"lingote","lingote de plata","lingote_quest_ghoul"}));
  Set(P_NOSELL, 1);
  Set(P_CANT_STEAL,1);
  SetNoDrop(1);
  SetValue(40000);
  SetWeight(150);
}
public varargs int move(mixed dest, int method, mixed extra)
{
 	if (pLibre) return ::move(dest, method, extra);
 	if (method == M_GET && QUESTMASTER->QueryQuestSolved("kill_ghoul",TP))
 	{
        Set(P_NODROP, 0);
        Set(P_NOSELL, 0);
 		RemoveId("lingote_quest_ghoul");
 		SetValue(10000);
 		SetLibre(1);
 		return ::move(dest, method, extra);
 	}
 	else if (method == M_GIVE && !dest->QueryHerreroTamaraQuest()) return ME_NO_GIVE;
 	else return ::move(dest, method, extra);
}

public int SetLibre(int valor) { return pLibre = valor; }
public int QueryLibre() { return pLibre; }
