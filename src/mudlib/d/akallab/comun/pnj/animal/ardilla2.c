/*
DESCRIPCION  : una ardilla agresiva
FICHERO      : /d/akallab/comun/pnj/animal/ardilla2.c
MODIFICACION :  29-10-98 [Angor@Simauria]Creacion
		16-11-01 [Theuzifan] Arreglado un typo -> raViosa
--------------------------------------------------------------------------------
*/

inherit NPC;

#include <properties.h>  //por el PSIZE
#include <living.h>      //por el GENDER

create() {
  ::create();
  SetName("ardilla");
  SetShort("una ardilla");
  SetLong(
    "Ves una simpatica ardilla jugando con un pequenyo objeto. Aunque cuando te "
    "fijas en ella adviertes que es un ojo y que la simpatica ardilla tiene una "
    "densa espuma en la boca\n");
  SetRace("animal");
  SetGender(GENDER_FEMALE);
  SetWeight(500);
  SetIds(({"ardilla"}));
  SetAds(({"rabiosa","simpatica"}));
  SetLevel(3);
  SetMaxHP(30);
  SetHP(27);
  SetDex(3);
  SetStr(2);
  SetInt(1);
  SetCon(1);
  SetAlign(-200);
  SetAC(2);
  SetHands(({({"un mordisco",0,2})}));
  InitChats(3,({
    "La ardilla admira tus ojos mientras devora el que tenia en las manos.\n",
    "La ardilla mordisquea tus pies. "
    "La ardilla realiza unos extranyos movimientos e intenta atacar a... un arbol!!!\n"  }));
  InitAChats(10,({
    "La ardilla te llena de espuma durante el combate.\n",
    "La ardilla hace un intento frustrado de sacarte los ojos.\n",
    "La ardilla engancha sus dientes en tu oreja.\n"  }));
}

init() {
  ::init();
  Kill(TP);
}
