/*
DESCRIPCION  : Almacen en la caverna de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/almacen1.c
MODIFICACION : 04-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("el almacén de las minas");
  SetIntLong(
  "Has alcanzado el extremo de esta galeria que reformada por los orcos "
    "como almacen de material para los mineros. Ves todo tipo de cajones "
	"apilados en las estanterias de madera que recorren las paredes de este "
	"almacen. La unica luz que ilumina el lugar proviene de la vieja "
	"lampara de aceite colgada del techo.\n");

  AddDetail(({"galeria","almacen"}),QueryIntLong());

  AddDetail(({"casetas","caseta","casetas de madera"}),
  "Son unas construcciones toscas de madera situadas junto a algunas de las "
    "paredes de la caverna. Seguramente seran usadas por los mineros.\n");

  AddDetail(({"estanterias","estanteria"}),
  "Las paredes de esta galeria almacen estan llenas de ellas.\n");

  AddDetail(({"cajones","cajon"}),
  "Las estanterias estan llenas de grandes cajones de madera con todo "
    "tipo de trastos y utensilios usados por los mineros para su trabajo. "
	"Tras rebuscar un rato en el que tienes ante ti no encuentras nada que "
	"te sea util.\n");

  AddDetail(({"lampara"}),
  "Esta firmemente sujeta al techo iluminando pobrememte este almacen.\n");

  SetIntNoise("No se oye gran cosa.\n");
  SetIntSmell("Huele a polvo y tierra.\n");
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("sur",Z_MINAS("/nivel0/almacen0"));
  AddItem(QUEST+"minas/nota_0", REFRESH_REMOVE);
}
