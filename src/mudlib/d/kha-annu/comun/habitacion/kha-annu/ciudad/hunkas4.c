#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Hunkas");
   SetIntLong(
"Justo aqui puedes cruzar un callejón hacia el oeste, para llegar a la calle "
"Rurik, donde estan las escuelas de Metalurgia e Ingenieria.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"hunkas5");
  AddExit("sur",CIUDAD+"hunkas3");
  AddExit("oeste",CIUDAD+"callejon1");

  SetLocate("Kha-annu");
}
