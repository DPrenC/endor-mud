/*          cemen2o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis] Modificadas las descripciones y AddDetails
	    [Jessy]   Castellanizando el fichero y cambiando la ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("en medio de");
SetIntShort("las tumbas");
SetIntLong(
	   "Sólo hay tumbas y más tumbas.... tendrías que volver al camino del este o del "
	   "norte porque te podría dar algo si continúas mirando tanta tumba...\n");
SetIndoors(0);
AddDetail(({"tumbas","tumba"}), "Si ves otra tumba, te va a dar algo.\n");
AddExit("norte","cemen3o");
AddExit("este","cemen2");
AddExit("sur","cemen1o");
}
