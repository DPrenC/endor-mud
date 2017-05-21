/*
DESCRIPCION  : una gran caja de madera
FICHERO      : /d/akallab/comun/objeto/mueble/caja_vacia.c
MODIFICACION : 09-02-00 [Angor@Simauria] Creacion
*/

#include <properties.h>
inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

create () {
  ::create();
  SetShort("una gran caja de madera");
  SetLong("Es una gran caja de madera para almacenar cosas.\n");
  SetPreIntShort("dentro de");
  SetIntShort("una caja de madera");
  SetIntLong("Estas en el interior de una gran caja de madera.\n");
  SetPreContent("Contiene:\n");
  SetValue(150);
  SetWeight(5000);
  AddId("caja");
  // Las siguientes ajustadas para que quepan 6-7 viales
  SetMaxIntWeight(5000);
}