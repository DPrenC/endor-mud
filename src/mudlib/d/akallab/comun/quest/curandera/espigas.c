/*
DESCRIPCION  : un manojo de espigas de trigo
FICHERO      : /d/akallab/comun/quest/curandera/espigas.c
MODIFICACION : 20-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit THING;

create() {
   ::create();
   SetShort("unas espigas de trigo");
   SetLong("Son solo un manojo de doradas espigas de trigo.\n");
   AddId(({"espigas","espigas de trigo","trigo","manojo"}));
   SetWeight(50);
   SetValue(0);
}
