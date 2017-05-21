/*          cemen4ne.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 9-11-01
            Modificado por :
	    [Nemesis] Cambio en descripciones y AddDetails
	    [Jessy]   Castellanización de los ficheros y cambio de ermita a templo...
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
           "Estás en el sitio más interesante del cementerio. Puedes ver los panteones de "
           "las familias más ricas de la aldea junto con alguna que otra estatua de esas "
           "personas. Al oeste puedes ver las paredes del templo, que se encuentran cubiertas. "
	   "de hiedra y demás plantas trepadoras.\n");
SetIndoors(0);

AddDetail(({"panteones","panteones famliares"}),
            "El hecho de ser los más ricos no les ha salvado de ser abiertos y saqueados.\n");
AddDetail(({"estatuas", "estatua"}),
            "No queda ninguna intacta. Todas han sido derribadas.\n");
AddDetail(({"pared","paredes"}),
            "Están cubiertas de espesas hiedras.\n");
AddDetail(({"hiedra","hiedras"}),
            "Están medio secas. Parece que nadie las ha cuidado en mucho tiempo.\n");

AddExit("sur","cemen4e");
AddExit("suroeste","cemen4");
}
