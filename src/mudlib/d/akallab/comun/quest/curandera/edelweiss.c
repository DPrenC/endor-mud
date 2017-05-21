/*
DESCRIPCION    : flor de Edelweiss para el quest de la curandera
FICHERO        : /d/akallab/comun/quest/curandera/edelweiss.c
MODIFICACION   : 01-03-99 [Angor@Simauria].
*/

#include "path.h"
#include AK_MACRO

#include <herbs.h>

inherit HERB;

create() {
  ::create();
  SetShort("una flor de Edelweiss");
  SetLong(
  "Es una flor de Edelweiss, una pequenya planta con hojas abiertas en "
    "estrella y cubierta de una abundante pilosidad blanca que vive en "
    "las altas montanyas.\n");

  AddId(({"flor de edelweis","edelweiss","Edelweiss","flor","cur_quest_11"}));
  SetSmell("La flor de Edelweiss desprende un suave y dulzon aroma.\n");
  SetWeight(100);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(25+random(10)); //poco
  SetValue(25);
}
