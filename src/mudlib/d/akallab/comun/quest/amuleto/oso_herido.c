/*
DESCRIPCION  : oso gris del quest del amuleto
FICHERO      : /d/akallab/comun/quest/amuleto/oso_herido.c
MODIFICACION : 27-10-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  SetStandard("oso","oso",20,GENERO_MASCULINO);
  SetName("oso");
  SetShort("un gran oso gris malherido");
  SetLong(
  "Ves a un enorme oso gris que protege su territorio y que no parece "
    "muy contento de verte por aqui. Esta herido y resulta muy violento, "
    "Podria destrozarte de un solo zarpazo.\n");
  SetHP(2*QueryMaxHP()/3);
/*  SetRace("animal");
  SetGender(GENDER_MALE);
  SetWeight(100000);
  SetIds(({"oso","oso gris"}));
  SetAds(({"gran","gris","enorme","herido"}));
  SetLevel(20);
  SetMaxHP(150);

  SetDex(6);
  SetStr(20);
  SetInt(1);
 */
  SetWhimpy(0);
  SetAlign(100);
  SetAC(2);
  SetGoChance(0);
  SetAggressive(1);
  SetHands(({({"boca",0,10}),({"zarpa izquierda",0,10}),({"zarpa derecha",0,10})}));
  InitChats(3,({
   "El oso grunye y lame sus heridas.\n",
   "El oso abre sus fauces amenazadoramente.\n",
   "El oso se yergue ante ti y da zarpazos desafiantes al aire.\n"
  }));
}
