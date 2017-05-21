/*
DESCRIPCION  : salvado de trigo
FICHERO      : /d/akallab/comun/quest/curandera/salvado.c
MODIFICACION : 20-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit THING;

create() {
   ::create();
   SetShort("salvado de trigo");
   SetLong("Es solo un poco de salvado de trigo, la fibra que envuelve "
             "a la semilla de este cereal.\n");
   AddId(({"salvado","salvado de trigo","cur_quest_07"}));
   SetWeight(50);
   SetValue(0);
}
