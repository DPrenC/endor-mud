/*
DESCRIPCION  : el amuleto perdido del quest del mismo nombre
FICHERO      : /d/akallab/comun/quest/amuleto/amuleto.c
MODIFICACION : 27-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("amuleto");
  AddId("colgante");
  AddId("amu_quest_05");
  AddAdjective("amuleto");
  AddAdjective("colgante");
  SetShort("un colgante con amuleto");
  SetLong("Es un colgante formado por un cordel y un pequenyo un amuleto "
    "en el. El amuleto consiste en algunos anillos brillantes de laton y "
	"una pequenya bolsa de cuero. No crees que valga gran cosa.\n");
  SetWeight(100);
  SetValue(5);
}
