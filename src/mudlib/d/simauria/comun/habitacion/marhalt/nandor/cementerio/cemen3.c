/*          cemen3.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 23-11-98
            Ultima modificaci�n : 2-11-01
	    Modificaci�n:
	    [Jessy]   CAstellanizaci�n del fichero y cambio de ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Peque�a plaza");
SetIntShort("el cementerio de Nandor");
SetIntLong(
	   "Est�s en una peque�a plaza en medio del cementerio. En el centro puedes ver "
	   "una capilla dedicada al protector de la aldea. A tu alrededor todav�a puedes "
	   "ver l�pidas, hacia el noreste y noroeste ves unas tumbas, hacia el este y el "
	   "oeste contin�a un corto camino, al sur ves las puertas del cementerio y m�s "
	   "al norte ves el templo.\n");
SetIndoors(0);
AddDetail("capilla","Ahora esta vac�a...\n");
AddDetail("tumbas",
	  "Est�n profanadas, como casi todas las que has visto hasta ahora.\n");
AddDetail("lapidas","l�pidas",
	  "Est�n esparcidas por ah�...\n");
AddDetail("templo",
	  "Est� muy deteriorado. Parece que no mucha gente viene por aqu�.\n");
AddExit("sur","cemen2");
AddExit("norte","cemen4");
AddExit("este","cemen3e");
AddExit("oeste","cemen3o");

}
