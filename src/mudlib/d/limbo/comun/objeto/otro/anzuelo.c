/*
DESCRIPCION  : Miembro desmembrado
FICHERO      : /obj/miembro.c
MODIFICACION : 17-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
//#include <properties.h>

create() {
  ::create();
  SetShort("un anzuelo");
  SetLong("Es un afilado anzuelo de pesca. Deberias tener ciudado si no quieres pincharte.\n");
  AddId("anzuelo");
  SetWeight(50);
}