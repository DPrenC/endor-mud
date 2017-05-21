/*          cemen1e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis] Cambios en los AddDetails y descripciones.
	    [Jessy]   Castellanizaci�n del archivo y cambios de
	             la _E_rmita a templo ^_^
*/
#include <properties.h>
#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("en medio de");
SetIntShort("las l�pidas");
SetIntLong(W(
           "Est�s en el lugar donde se entierra a los muertos ... y ellos "
	   "est�n a tu alrededor. Lo �nico que ves son l�pidas y restos de "
	   "cad�veres. Si quieres salir ve al oeste o contin�a pisando tierra "
	   "muerta al norte.\n"));
SetIndoors(0);
AddDetail(({"lapidas","lapida","l�pidas","l�pida"}),
            "Hay un mont�n de ellas y no te vas a poner a leerlas todas.\n");
AddDetail(({"cadaveres","restos","cad�veres"}),
            "Est�n esparcidos por todas partes...\n");
AddExit("norte","cemen2e");
AddExit("oeste","cemen1");
}
