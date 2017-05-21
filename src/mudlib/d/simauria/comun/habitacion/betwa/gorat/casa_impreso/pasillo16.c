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
"que pone  1-K y en la del oeste pone 1-L, el pasillo sigue al "
"norte y al sur.\n");

SetIntBright(50);
SetIndoors(1);
AddExit("sur","pasillo15");
AddExit("norte","pasillo17");
AddExit("este","d1k");
AddExit("oeste","d1l");
}
