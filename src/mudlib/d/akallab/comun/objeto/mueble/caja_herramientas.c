/*
DESCRIPCION  : una caja de madera de herramientas
FICHERO      : /d/akallab/comun/objeto/mueble/caja_herramientas.c
MODIFICACION : 10-02-00 [Angor@Simauria] Creacion
*/

#include <properties.h>

inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

create () {
  object ob;

  ::create();
  SetShort("una caja herramientas");
  SetLong("Es una caja de madera para guardar herramentas.\n");
  SetPreIntShort("dentro de");
  SetIntShort("una caja de herramientas");
  SetIntLong("Estás en el interior de una caja de herramientas.\n");
  SetPreContent("Contiene:\n");
  SetValue(100);
  SetWeight(1000);
  AddId("caja");
  SetMaxIntWeight(10000);
  Set(P_NOGET,1);

  //objetos que contiene:
  ob=clone_object("/obj/torch");
  ob->move(TO);
}