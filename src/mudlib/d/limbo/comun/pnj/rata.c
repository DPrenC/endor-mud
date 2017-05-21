/*
DESCRIPCION  : rata para la mina de novatos
FICHERO      : /d/limbo/comun/pnj/rata.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();

  SetStandard("una rata","rata",([ GC_TORPE: 2]),GENDER_FEMALE);
  SetShort("una rata enorme");
  SetLong(
  "Es una enorme rata de pelaje negro y con una larga cola. Sus dientes son muy\n"
  "afilados y sus ojos brillan con un gesto amenazador.\n");
  SetIds(({"rata","bicho"}));
  SetAds(({"una","enorme","asquerosa","peluda"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetHands(({ ({"mordisco",TD_PENETRACION,3})}));
  InitChats(8,({
   "La rata da vueltas a tu alrededor.\n",
   "La rata se te intenta subir a los tobillos.\n",
   "La rata te mira con gesto amenazador.\n",
   "La rata parece MUUUUY hambrienta.\n",
   "La rata te enseña sus dientes amarillos.\n",
  }));
}
