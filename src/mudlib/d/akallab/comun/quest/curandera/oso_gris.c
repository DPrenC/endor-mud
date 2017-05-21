/*
DESCRIPCION  : oso gris del quest de la curandera
FICHERO      : /d/akallab/comun/quest/curandera/oso_gris.c
MODIFICACION : 23-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  SetName("oso");
  SetShort("un gran oso gris");
  SetLong(
  "Ves a un enorme oso gris que protege su territorio y que no parece "
    "muy contento de verte por aqui. Podria destrozarte de un solo "
    "zarpazo.\n");
  SetRace("animal");
  SetGender(GENDER_MALE);
  SetWeight(100000);
  SetIds(({"oso","oso gris"}));
  SetAds(({"gran","gris","enorme"}));
  SetLevel(10);
  SetMaxHP(150);
  SetHP(130);
  SetDex(8);
  SetStr(12);
  SetInt(8);
  SetWhimpy(0);
  SetAlign(100);
  SetAC(3);
  SetGoChance(0);
  SetAggressive(1);
  SetHands(({({"boca",0,10}),({"zarpa izquierda",0,10}),({"zarpa derecha",0,10})}));
  InitChats(3,({
   "El oso grunye y leme sus garras.\n",
   "El oso abre sus fauces amenazadoramente.\n",
   "El oso se yergue ante ti y da zarpazos desafiantes al aire.\n"
  }));
}

public varargs void Die(mixed silent)
{
object ob;
  ob=clone_object(QUEST+"curandera/garra_oso");
  ob->move(environment(TO));
  ::Die(silent);
}
