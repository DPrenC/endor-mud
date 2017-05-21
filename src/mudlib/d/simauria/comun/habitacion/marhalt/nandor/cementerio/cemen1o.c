/*          cemen1o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis] Cambios en las descripciones y AddDetails para hacerlo
                      todo algo mas tetrico.
	    [Jessy]   Castellanizando el fichero y cambiando la ermita a templo
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("entre");
SetIntShort("las l�pidas orientales");
SetIntLong(
	   "Est�s donde se entierra a los muertos, pisando la tierra en la que ellos "
	   "est�n. No parece que sea el mejor sitio para estar, rodeado de l�pidas y "
	   "de muertos a medio desenterrar. Puedes ir al camino hacia el este o seguir "
	   "en esta nada agradable zona yendo al norte.\n");
SetIndoors(0);
AddDetail(({"lapidas","lapida","l�pidas","l�pida"}),
	    "Hay un mont�n. No te vas a poner a leerlas todas.\n");
AddDetail(({"muertos","restos"}),
          "Est�n muertos, no creo que puedan hacerte nada.\n");
AddExit("norte","cemen2o");
AddExit("este","cemen1");
}
