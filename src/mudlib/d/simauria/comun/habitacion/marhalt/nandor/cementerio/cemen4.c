/*          cemen4.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-11-98
            Ultima modificaci�n : 4-11-01
	    Modificaciones:
	    [Jessy]   Castellanizaci�n de los ficheros y cambio de ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Frente al templo");
SetIntShort("el cementerio de Nandor");
SetIntLong(
           "Est�s frente al templo. Si contin�as al norte entrar�s en su interior, ya "
           "que las puertas parecen haber desaparecido. Hacia el sur ves una plaza con "
	   "una peque�a capilla, al este y oeste ves tumbas y al nordeste y noroeste "
	   "varios panteones familiares.\n");
SetIndoors(0);

AddDetail("puertas", "No est�n abiertas ni cerradas... Simplemente no est�n.\n");
AddDetail("capilla", "Desde aqu� no la ves muy bien.\n");
AddDetail(({"panteones", "panteones familiares"}),
            "No los puedes ver bien desde aqu�.\n");
AddDetail("tumbas", "Pr�cticamente todas han sido profanadas...\n");

AddExit("sur","cemen3");
AddExit("norte","templo1");
AddExit("este","cemen4e");
AddExit("oeste","cemen4o");
AddExit("nordeste","cemen4ne");
AddExit("noroeste","cemen4no");

}
