/*
DESCRIPCION  : rata para el tutorial
MODIFICACION : 2008-03-23 [Angor]
*/

#include "./path.h"
inherit NPC;

private int comprueba_espada(object atacante)
{
    object espada = present("espada", atacante);
    if (!espada || !espada->QueryEquipped())
    {
        return notify_fail("¿No crees que antes de matar a la rata deberías empuñar algún arma?\n", NOTIFY_NOT_VALID);
    }
    return 1;
}


create() {
  ::create();

  SetStandard("una rata","rata",([ GC_TORPE: 1]),GENDER_FEMALE);
  SetShort("una rata enorme");
  SetLong(
  "Es una enorme rata de pelaje negro y con una larga cola. Sus dientes son muy\n"
  "afilados y sus ojos brillan con un gesto amenazador.\n");
  SetIds(({"rata","bicho"}));
  SetAds(({"una","enorme","asquerosa","peluda"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(2);
  SetHP(1);
  SetInt(1);
  SetHands(({ ({"mordisco",TD_PENETRACION,1})}));
  InitChats(6,({
   "La rata da vueltas a tu alrededor.\n",
   "La rata se te intenta subir a los tobillos.\n",
   "La rata te mira con gesto amenazador.\n",
   "La rata te enseña sus dientes amarillos.\n",
  }));
  SetChkFightFunction(SF(comprueba_espada));

}

init(){
  object ob = environment(TO);
  AddInformObj(ob);
	::init();
}