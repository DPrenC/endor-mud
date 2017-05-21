/*
DESCRIPCION  : cangrejo para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/cangrejo.c
MODIFICACION : 30-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;

create() {
 ::create();
 SetStandard("un cangrejo","cangrejo",([ GC_TORPE: 2]),GENDER_MALE);
 SetShort("un cangrejo");
 SetLong(
 "Es un cangrejo de mar. Es de un color rojizo y se esconde facilmente entre las\n"
 "rocas. No debe ser agradable si te engancha con alguna de sus pinzas...\n");
 AddId("cangrejo");
 AddAdjective("de mar");
 SetAlign(0);
 SetSize(P_SIZE_SMALL);
 SetAC(0);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
 SetHands(({({"pinza izquierda",0,1}),({"pinza derecha",0,1})}));
 SetWeight(500);
 SetGoChance(0);
 SetNoGet("El cangrejo se escabulle entre las rocas.\n");
 InitChats(3,({"El cangrejo va de un lado para otro.\n",
                "El cangrejo mordisquea alguna cosa.\n"}));
 SetDesmembrableEn(({PINZA,PINZA}));
}
