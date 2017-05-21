/*
DESCRIPCION  : murcielago la mina parque de novatos
FICHERO      : /d/limbo/comun/pnj/murcielago.c
MODIFICACION : 10-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();

  SetStandard("un murcielago","murcielago",([ GC_TORPE: 3]),GENDER_MALE);
  SetShort("un murcielago");
  SetLong(
  "Es un murcielago. Te recuerda a una pequeña rata, solo que con alas y unas\n"
  "grandes orejas. Es de color oscuro, casi negro, y parece bastante inquieto.\n");
  SetIds(({"murcielago","vampiro","murciélago"}));
  SetAds(({"pequenyo","pequeño"}));
  SetSize(P_SIZE_SMALL);
  SetAC(0);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetStr(QueryStr()-2);
  SetDex(QueryDex()+2);
  SetInt(1);
  SetHands( ({ ({"mordisco",TD_PENETRACION,4}) }) );
  SetNoGet(0);
  SetWeight(500);

  InitChats(8,({
   "El murcielago revolotea a tu alrededor.\n",
   "El murcielago produce un agudo chillido.\n",
   "El murcielago esquiva los obstaculos de forma acrobática al volar.\n",
   "El murcielago se cuelga en un saliente de la roca.\n",
   "El murcielago atrapa algun tipo de bicho que revoloteaba cerca.\n"}));
  SetDesmembrableEn(({CABEZA,ALA_MEMBRANA,ALA_MEMBRANA}));
}
