/*          cemen4no.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Modificaciones:
            14-11-97 [Nemesis] Nemesis tells you: Tio, mete el path.h!!!
                               Nemesis tells you: Es SUDESTE!!!!

            23-11-98 [Nemesis] Cambio en descripciones y AddDetails.
	     9-11-01 [Jessy]   Castellanización delos ficheros y cambio de ermita a templo

*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("en medio de");
SetIntShort("los panteones familiares");
SetIntLong(
           "A tu alrededor están los panteones familiares más lujosos de todo este lugar. "
           "Nunca hubieras pensado que en este sitio también habría ratas pero las hay. "
           "Al este puedes ver las paredes del pequeño templo y al sur ves tumbas.\n");
SetIndoors(0);

AddDetail(({"panteones","panteones familiares"}),
            "Todos han sido abiertos y sus ataúdes saqueados. Aún puedes ver algún resto.\n");
AddDetail(({"resto","restos"}),
            "Sólo quedan huesos medio roídos. Es como si hubieran sido saqueados hace "
            "mucho, mucho tiempo...\n");
AddDetail(({"pared","paredes"}),
            "Parecen fuertes, aunque no parecen haber sido encaladas en años.\n");
AddDetail("tumbas", "No se ven bien desde aquí.\n");

AddItem(PNJ("marhalt/rata"),REFRESH_DESTRUCT,2);
AddExit("sur","cemen4o");
AddExit("sudeste","cemen4");
}
