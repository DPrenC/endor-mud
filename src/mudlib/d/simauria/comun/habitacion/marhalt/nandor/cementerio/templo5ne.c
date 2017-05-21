/*          templo5ne.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-99
	    Modificaciones:
	    [Jessy]   Castellanizaci�n del fichero y cambio de las descripciones
	              del templo que antes era una hermita
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el dormitorio del sacerdote de Sharanna");
SetIntLong(W(
           "Est�s en el dormitorio donde duerme el cl�rigo que dirige las "
	   "plegarias para Sharanna. En el centro hay una cama y a su lado "
	   "hay una mesita y un escritorio con unos libros "
	   "encima. Tambi�n hay un armario y una silla delante de �l. Unas "
	   "escaleras conducen hacia el piso inferior vas a la cocina y al "
	   "suroeste hay otra habitaci�n.\n"));
SetIndoors(1);
SetIntBright(20);

AddDetail(({"cl�rigo","clerigo"}), "No le ves por aqu�...\n");
AddDetail(({"cama","mesita","escritorio","armario","silla"}),
            "Es humilde, pero funcional.\n");
AddDetail(({"libros"}),
            "Est�n cubiertos de polvo. Parece que nadie los ha tocado en mucho tiempo.\n");

AddExit("suroeste","templo5");
AddExit("abajo","templo1ne");
}
