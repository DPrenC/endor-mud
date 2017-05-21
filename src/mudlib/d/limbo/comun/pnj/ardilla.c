/*
DESCRIPCION  : ardilla para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/ardilla.c
MODIFICACION : 10-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
 ::create();
 SetStandard("una ardilla","ardilla",([ GC_TORPE: 2]),GENDER_FEMALE);
 SetShort("una ardilla");
 SetLong(
 "Es una simpática y temerosa ardilla. Su pelaje es de un color ocre claro con\n"
 "estrías pardas. Es un animalillo nervioso que no para de mirar continuamente a\n"
 "lados como presintiendo algún peligro.\n");
 SetIds(({"ardilla","bicho"}));
 AddId("ardilla");
 AddAdjective("simpatica");
 AddAdjective("temerosa");
 SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
 SetInt(1);
 SetStr(QueryStr()-1);
 SetDex(QueryDex()+1);
 SetHands( ({ ({"mordisco",TD_PENETRACION,2}) }) );
 SetWeight(500);
 SetGoChance(50);
 SetNoGet("La ardilla pega un brinco y se aleja de ti.\n");
 InitChats(3,({"La ardilla mira nerviosa a todos lados.\n",
                "La ardilla coge una bellota y la guarda en sus carrillos.\n",
                "La ardilla va de aquí para alla.\n",
                "La ardilla te mira curiosa.\n"}));
 SetDesmembrableEn(({CABEZA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA}));
}
