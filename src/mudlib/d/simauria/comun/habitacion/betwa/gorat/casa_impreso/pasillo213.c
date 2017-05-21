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
"que pone 2-Y y en la del oeste pone 2-Z, el pasillo sigue al "
"sur y arriba tienes unas escaleras que te llevan al piso superior\n");

SetIndoors(1);
SetIntBright(50);
AddExit("arriba","pasillo31");
AddExit("norte","pasillo212");
AddExit("este","d2y");
AddExit("oeste","d2z");
}
