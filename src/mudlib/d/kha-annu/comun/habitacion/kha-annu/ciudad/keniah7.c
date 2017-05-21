#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"En esta esquina de la calle percibes un olor peculiar, y puedes ver que "
"una de las farolas esta medio estropeada.\n");
   AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar. Una de ellas esta medio estropeada.\n"
"Tal vez podrias intentar arreglarla.\n");
   SetIntSmell(
   "Puag!! apesta a meados. Te dan ganas de vomitar.\n");
  SetIntBright(70);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"keniah6");
  AddExit("oeste",CIUDAD+"keniah8");

  SetLocate("Kha-annu");
}

init() {
  ::init();
add_action("fix","arreglar");
}

int fix (string str) {
  if ( (str != "farola") && (str != "la farola") ) {
    write("El que intentas arreglar?\n");
    return 1;
  } else {
    write("Has roto la farola! manazas!!!\n");
    say(TP->QueryShort()+" ha roto la farola, fuerte manazas!\n");
    SetIntLong(
"En esta esquina de la calle, percibes un olor peculiar y hay una farola rota.\n");
    AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar. Una de ellas esta totalmente rota.\n"
"Seguramente alguien muy manazas metio la mano.\n");
    return 1;
  }
}
