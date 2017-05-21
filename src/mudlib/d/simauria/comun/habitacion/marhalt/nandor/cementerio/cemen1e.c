/*          cemen1e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis] Cambios en los AddDetails y descripciones.
	    [Jessy]   Castellanización del archivo y cambios de
	             la _E_rmita a templo ^_^
*/
#include <properties.h>
#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("en medio de");
SetIntShort("las lápidas");
SetIntLong(W(
           "Estás en el lugar donde se entierra a los muertos ... y ellos "
	   "están a tu alrededor. Lo único que ves son lápidas y restos de "
	   "cadáveres. Si quieres salir ve al oeste o continúa pisando tierra "
	   "muerta al norte.\n"));
SetIndoors(0);
AddDetail(({"lapidas","lapida","lápidas","lápida"}),
            "Hay un montón de ellas y no te vas a poner a leerlas todas.\n");
AddDetail(({"cadaveres","restos","cadáveres"}),
            "Están esparcidos por todas partes...\n");
AddExit("norte","cemen2e");
AddExit("oeste","cemen1");
}
