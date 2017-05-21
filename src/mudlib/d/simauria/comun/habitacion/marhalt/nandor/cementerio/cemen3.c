/*          cemen3.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 23-11-98
            Ultima modificación : 2-11-01
	    Modificación:
	    [Jessy]   CAstellanización del fichero y cambio de ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Pequeña plaza");
SetIntShort("el cementerio de Nandor");
SetIntLong(
	   "Estás en una pequeña plaza en medio del cementerio. En el centro puedes ver "
	   "una capilla dedicada al protector de la aldea. A tu alrededor todavía puedes "
	   "ver lápidas, hacia el noreste y noroeste ves unas tumbas, hacia el este y el "
	   "oeste continúa un corto camino, al sur ves las puertas del cementerio y más "
	   "al norte ves el templo.\n");
SetIndoors(0);
AddDetail("capilla","Ahora esta vacía...\n");
AddDetail("tumbas",
	  "Están profanadas, como casi todas las que has visto hasta ahora.\n");
AddDetail("lapidas","lápidas",
	  "Están esparcidas por ahí...\n");
AddDetail("templo",
	  "Está muy deteriorado. Parece que no mucha gente viene por aquí.\n");
AddExit("sur","cemen2");
AddExit("norte","cemen4");
AddExit("este","cemen3e");
AddExit("oeste","cemen3o");

}
