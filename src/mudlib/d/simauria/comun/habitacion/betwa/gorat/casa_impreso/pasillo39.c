/*
casa del quest de gorat
cheto 10-10-2001
*/

#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Gorat");
SetIntShort("la casa del registro de Gorat");
SetIntLong(
"Te encuentras en el pasillo de la casa del registro de gorat, en el "
"pasillo puedes ver puertas a ambos lados, en la del este ves un cartel "
"que pone 3-Q y en la del oeste pone 3-R, el pasillo sigue al "
"norte y al sur.\n");

SetIndoors(1);
  SetIntBright(50);
AddExit("sur","pasillo38");
AddExit("norte","pasillo310");
AddExit("este","d3q");
AddExit("oeste","d3r");
}
