/*
DESCRIPCION  : cubo de madera
FICHERO      : /d/akallab/comun/objeto/otro/cubo.c
MODIFICACION : 10-20-00 [Angor@Simauria] Creacion.
*/

inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

create () {
  ::create();
  SetShort("un pequenyo cubo de madera");
  SetLong("Es un pequenyo cubo de madera. No esta en muy "
    "buen estado, pero aun puede utilizarse.\n");
  SetPreIntShort("dentro de");
  SetIntShort("un pequeño cubo de madera");
  SetIntLong("Estas en el interior de una pequenyo cubo de madera.\n");
  SetPreContent("Contiene:\n");
  SetValue(10);
  SetWeight(500);
  SetMaxIntWeight(3000);
  AddId("cubo");
  AddId("cubo de madera");
  //AddAdjective("pequenyo");
  //AddAdjective("de madera");
}