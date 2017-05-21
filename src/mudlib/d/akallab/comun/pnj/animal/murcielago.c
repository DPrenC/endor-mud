/*
DESCRIPCION  : murcielago
FICHERO      : /d/akallab/comun/pnj/animal/murcielago.c
MODIFICACION : 10-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include <properties.h> //por el PSIZE
#include <living.h>     //por el GENDER
inherit NPC;

create() {
  ::create();

  SetStandard("murciélago","murcielago",5,GENDER_MALE);
  SetShort("un murcielago");
  SetLong(
    "Es un murciélago. Te recuerda a una pequeña rata, solo que con alas y unas "
    "grandes orejas. Es de color oscuro, casi negro, y parece bastante inquieto.\n");
  SetIds(({"murcielago","vampiro"}));
  SetAds(({"pequenyo"}));
  SetAlign(0);
  SetSize(P_SIZE_SMALL);
  SetDex(10);
  SetAggressive(random(2));
  SetHands(({ ({"un mordisco",0,4}) }));
  SetNoGet(0);
  SetWeight(500);

  InitChats(8,({
   "El murcielago revolotea a tu alrededor.\n",
   "El murcielago produce un agudo chillido.\n",
   "El murcielago esquiva los obstaculos de forma acrobatica.\n"   }));
}
