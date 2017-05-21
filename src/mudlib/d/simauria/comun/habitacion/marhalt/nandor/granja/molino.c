#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create () {
  ::create();
Set(P_INT_SHORT,"un molino");
SetIntLong(
"Te encuentras en el interior de un molino de agua. Unos engranajes\n"
"hacen mover la piedra que muele el trigo te rodean. Puedes ver\n"
"unos sacos de harina tirados en un rincon.\n");

SetIndoors(1);
SetIntBright(30);

SetIntNoise("El ruido de los engranajes es lo unico que escuchas.\n");
SetIntSmell("Huele a trigo molido.\n");
SetLocate("nandor");

AddDetail(({"saco","sacos"}),
"Son sacos de tela resistente llenos de harina de trigo.\n");
AddDetail(({"harina"}),
"Es un polvo blanco en que se convierte el trigo cuando se muele\n");
AddDetail(({"engranaje","engranajes","piedra"}),
"Forma parte de un sistema que transforma la simiente en harina.\n");
AddExit("este","../sendero3");
}
