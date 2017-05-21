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
"que pone 2-I y en la del oeste pone 2-J, el pasillo sigue al "
"sur y al norte.\n");

SetIndoors(1);
SetIntBright(50);
AddExit("sur","pasillo26");
AddExit("norte","pasillo24");
AddExit("este","d2i");
AddExit("oeste","d2j");
}
