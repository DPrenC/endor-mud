/*          ermit2.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 12-11-01
	    Modificaciones:
	    [Jessy]    Castellanización del fichero y cambio de las descripciones
	               del templo que antes era una ermita.
            16-05-02 [n] Retocadas las descripciones.
NOTAS:
   [n] Vuelven a faltar AddDetails (altar, p. ej.)
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el interior del Templo");
SetIntLong(
           "Estás en el interior del templo. A tu alrededor puedes ver varias figuras "
           "que representan a la Diosa Sharanna en todo su esplendor, y muchas velas "
	   "que hacen que el aire tenga un olor extraño al mezclarse con el incienso "
	   "quemado que también hay por todas partes. Al norte puedes ver el altar y al "
	   "sur la entrada del templo.\n");
SetIntSmell("Hay un olor extraño que hace que te marees.\n");
SetIndoors(1);
SetIntBright(20);
AddExit("sur","templo1");
AddExit("norte","templo3");
}
