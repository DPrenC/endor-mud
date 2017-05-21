
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create() {   ::create();
SetIntShort("el cementerio");
 SetIntLong(
"Te encuentras en una pequeña estancia en medio de la cual ves lo que queda\n"
     "de una tumba rodeada por telarañas, mugre y porqueria que se ha acumulado con\n"
     "el tiempo. Aquí no hay rastro de niebla.\n"
     );
   SetIndoors(1);
   SetIntBright(30);
   SetIntSmell(
     "El olor a cerrado y a humedad flota en el ambiente.\n"
     );
   SetIntNoise(
     "Ruidos como de arañazos se escuchan a lo lejos.\n"
     );
   AddDetail(({"niebla"}),
     "Una fina capa de niebla se filtra por la entrada del mausoleo haciendo que esta estancia parezca un pequeño lago.\n"
     );
   AddDetail(({"tumba"}),
     "Al examinarla con más detenimiento, observas que tiene símbolos élficos y está muy bien trabajada.\n"
     );
   AddDetail(({"porqueria","telarañas","mugre"}),
     "Una capa de porqueria se acumula en todas partes. Nadie a limpiado aqui en mucho tiempo.\n"
     );


    AddExit("este",ALUTIIN("cementerio/camino7"));
   AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
   SetLocate("cementerio2"); } 