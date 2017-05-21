/*
DESCRIPCION  : escalera rota para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/escalera_rota.c
MODIFICACION : 26-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("escalera");
  AddId("restos");
  AddId("escalera de madera");
  AddId("amu_quest_04");
  AddAdjective("vieja");
  AddAdjective("rota");
  AddAdjective("de madera");
  SetShort("los restos de una escalera de madera");
  SetLong("Son los restos de una vieja y alargada escalera de madera que "
            "sin duda conocio mejores tiempos. Esta bastante rota y no sirve "
            "mas que de lenya para algun fuego.\n");
  SetWeight(5000);
  SetValue(0);
}
