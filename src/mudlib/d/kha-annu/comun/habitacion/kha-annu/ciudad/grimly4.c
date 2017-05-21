#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"El ambiente parece algo mas cargado en esta parte de la Avenida. La puerta "
"trasera de uno de los gremios de la ciudad, se encuentra al sur; hacia el este "
"y al oeste continua la Avenida Grimly. Mas farolas iluminan la calle.\n");

    AddDetail(({"farola","farolas"}),
"Da la impresion de que nunca hayas visto una. Alumbran la Avenida.\n");
   SetIntBright(80);
   SetIndoors(1);

   AddExit("sur","/guilds/guerreros/sedes/kha-annu/sede_kha-annu");
   AddExit("este",CIUDAD+"grimly5");
   AddExit("oeste",CIUDAD+"grimly3");

   SetLocate("Kha-annu");
}
