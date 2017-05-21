/*          cemen4no.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Modificaciones:
            14-11-97 [Nemesis] Nemesis tells you: Tio, mete el path.h!!!
                               Nemesis tells you: Es SUDESTE!!!!

            23-11-98 [Nemesis] Cambio en descripciones y AddDetails.
	     9-11-01 [Jessy]   Castellanizaci�n delos ficheros y cambio de ermita a templo

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
           "A tu alrededor est�n los panteones familiares m�s lujosos de todo este lugar. "
           "Nunca hubieras pensado que en este sitio tambi�n habr�a ratas pero las hay. "
           "Al este puedes ver las paredes del peque�o templo y al sur ves tumbas.\n");
SetIndoors(0);

AddDetail(({"panteones","panteones familiares"}),
            "Todos han sido abiertos y sus ata�des saqueados. A�n puedes ver alg�n resto.\n");
AddDetail(({"resto","restos"}),
            "S�lo quedan huesos medio ro�dos. Es como si hubieran sido saqueados hace "
            "mucho, mucho tiempo...\n");
AddDetail(({"pared","paredes"}),
            "Parecen fuertes, aunque no parecen haber sido encaladas en a�os.\n");
AddDetail("tumbas", "No se ven bien desde aqu�.\n");

AddItem(PNJ("marhalt/rata"),REFRESH_DESTRUCT,2);
AddExit("sur","cemen4o");
AddExit("sudeste","cemen4");
}
