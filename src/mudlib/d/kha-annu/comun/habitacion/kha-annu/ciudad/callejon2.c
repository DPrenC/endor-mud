#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callej�n");
   SetIntLong(
"Te encuentras en la salida trasera de la taberna del 'peque�o dragon azul'.\n"
"Es un callejon oscuro y vacio. No hay nada interesante aqui.\n");

   SetIntBright(20);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"grimly2");
   AddExit("sur",CIUDAD+"baldur2");
   AddExit("oeste",TIENDAS+"taberna");
}
