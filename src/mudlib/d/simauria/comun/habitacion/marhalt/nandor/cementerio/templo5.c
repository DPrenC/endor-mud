/*          templo5.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Nemesis]
	    [Jessy]    Castellanización del fichero y cambio de las descripciones
	               del templo que antes era una hermita.
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("las escaleras del campanario");
SetIntLong(W(
             "Estás en las escaleras que conducen hacia lo más alto del campanario. De un "
	     "agujero en el techo cuelga una gruesa cuerda que llega hasta el suelo. "
             "Hacia arriba subes al campanario, al noroeste vas a la biblioteca y hacia "
             "el nordeste parece haber un dormitorio.\n"));
SetIndoors(1);
SetIntBright(20);
AddDetail("cuerda",
          "No lo puedes asegurar, pero seguro que tiene algo que ver con la campana.\n");
AddExit("arriba","templo6");
AddExit("nordeste","templo5ne");
AddExit("noroeste","templo5no");
}