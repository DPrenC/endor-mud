/*          cemen2.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis]
	    [Jessy]   Castellanizaci�n del fichero y cambio de ermita a templo
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el camino del Templo");
SetIntLong(
	   "Est�s caminando por el interior del cementerio siguiendo la senda que lleva "
	   "al antiguo templo. Puedes ver un esqueleto tirado en medio del camino. "
	   "Hacia el norte ves un templo "
	   "Hacia el sur est� la entrada y al este y oeste contin�as viendo cruces...\n");
SetIndoors(0);
AddDetail(({"esqueleto"}), "�Se ha movido?\n");
AddDetail(({"templo"}), "No se ve bien desde aqu�.\n");
AddExit("sur","cemen1");
AddExit("norte","cemen3");
AddExit("este","cemen2e");
AddExit("oeste","cemen2o");
}
