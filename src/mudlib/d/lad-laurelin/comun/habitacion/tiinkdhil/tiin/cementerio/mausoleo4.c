
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create() {   ::create();
SetIntShort("el cementerio");
 SetIntLong(
"Te encuentras en una peque�a estancia en medio de la cual ves lo que queda\n"
     "de una tumba rodeada por telara�as, mugre y porqueria que se ha acumulado con\n"
     "el tiempo. Aqu� no hay rastro de niebla.\n"
     );
   SetIndoors(1);
   SetIntBright(30);
   SetIntSmell(
     "El olor a cerrado y a humedad flota en el ambiente.\n"
     );
   SetIntNoise(
     "Ruidos como de ara�azos se escuchan a lo lejos.\n"
     );
   AddDetail(({"niebla"}),
     "Una fina capa de niebla se filtra por la entrada del mausoleo haciendo que esta estancia parezca un peque�o lago.\n"
     );
   AddDetail(({"tumba"}),
     "Al examinarla con m�s detenimiento, observas que tiene s�mbolos �lficos y est� muy bien trabajada.\n"
     );
   AddDetail(({"porqueria","telara�as","mugre"}),
     "Una capa de porqueria se acumula en todas partes. Nadie a limpiado aqui en mucho tiempo.\n"
     );


    AddExit("este",ALUTIIN("cementerio/camino7"));
   AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
   SetLocate("cementerio2"); } 