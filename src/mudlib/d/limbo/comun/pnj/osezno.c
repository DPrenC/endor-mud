/*
DESCRIPCION  : un oso joven para la mina
FICHERO      : /d/limbo/comun/pnj/osezno.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("un osezno","oso",([ GC_TORPE: 5]),GENDER_MALE);
  SetShort("un joven oso gris");
  SetLong(
  "Es un joven oso gris. Su pelaje es tupido y sus garras afiladas. Pese a su\n"
  "edad parece bastante fuerte y fiero.\n");
  SetIds(({"oso","osezno","animal"}));
  SetAds(({"gris","joven","fiero","fuerte"}));
  SetAggressive(1);
  SetSize(P_SIZE_MEDIUM);
  SetStr(QueryStr()+2);
  SetDex(QueryDex()-2);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetHands(({ ({"mordisco",TD_PENETRACION,4}),({"zarpazo",TD_CORTE,2}),({"zarpazo",TD_CORTE,2}) }) );
  InitAChats(10,({"El oso gruñe.\n",
                  "El oso abre la boca en un gesto amenazador mostrnado sus temibles colmillos.\n"}));
}

