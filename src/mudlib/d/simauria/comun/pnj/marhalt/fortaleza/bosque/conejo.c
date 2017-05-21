/*
DESCRIPCION  : un conejo
FICHERO      : /d/simauria/comun/pnj/marhalt/fortaleza/bosque/conejo.c
MODIFICACION : 29-10-98 [Maler]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
  ::create();

  SetStandard("un conejo", "conejo", 3, GENDER_MALE);
  SetShort("un conejo");
  SetLong("Un precioso conejo blanco se para ante tí, levanta la cabeza y te "
          "mira, mientras mueve sus orejas alante y atras y olisquea el aire "
          "con su nariz.\n");
  SetWeight(1500);
  SetIds(({"conejo"}));
  SetAds(({"blanco"}));
  SetGoChance(35);
  SetDex(5);
  SetStr(2);
  SetCon(2);
  SetInt(1);
  SetMaxHP(40);
  SetHP(QueryMaxHP());
  SetAC(1);
  SetHands(({({"un mordisco",0,2})}));
  InitChats(10,({
     "El conejo olisquea el aire en busca de algo.\n",
     "El conejo comienza a saltar de un lado para otro.\n"
     }));
  AddWalkZones(ROOMFB(""));
 }
