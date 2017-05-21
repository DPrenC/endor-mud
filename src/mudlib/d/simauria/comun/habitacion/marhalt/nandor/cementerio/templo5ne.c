/*          templo5ne.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-99
	    Modificaciones:
	    [Jessy]   Castellanización del fichero y cambio de las descripciones
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
           "Estás en el dormitorio donde duerme el clérigo que dirige las "
	   "plegarias para Sharanna. En el centro hay una cama y a su lado "
	   "hay una mesita y un escritorio con unos libros "
	   "encima. También hay un armario y una silla delante de él. Unas "
	   "escaleras conducen hacia el piso inferior vas a la cocina y al "
	   "suroeste hay otra habitación.\n"));
SetIndoors(1);
SetIntBright(20);

AddDetail(({"clérigo","clerigo"}), "No le ves por aquí...\n");
AddDetail(({"cama","mesita","escritorio","armario","silla"}),
            "Es humilde, pero funcional.\n");
AddDetail(({"libros"}),
            "Están cubiertos de polvo. Parece que nadie los ha tocado en mucho tiempo.\n");

AddExit("suroeste","templo5");
AddExit("abajo","templo1ne");
}
