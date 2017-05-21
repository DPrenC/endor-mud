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
SetIntShort("las lápidas orientales");
SetIntLong(
	   "Estás donde se entierra a los muertos, pisando la tierra en la que ellos "
	   "están. No parece que sea el mejor sitio para estar, rodeado de lápidas y "
	   "de muertos a medio desenterrar. Puedes ir al camino hacia el este o seguir "
	   "en esta nada agradable zona yendo al norte.\n");
SetIndoors(0);
AddDetail(({"lapidas","lapida","lápidas","lápida"}),
	    "Hay un montón. No te vas a poner a leerlas todas.\n");
AddDetail(({"muertos","restos"}),
          "Están muertos, no creo que puedan hacerte nada.\n");
AddExit("norte","cemen2o");
AddExit("este","cemen1");
}
