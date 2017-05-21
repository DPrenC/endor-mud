/*          cemen3o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 23-11-97
            Modificado por :
	    [Nemesis] Cambios en las descripciones y AddDetails
	    [Jessy]   Castellanizaci�n de los ficheros y cambiar la ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el camino interior del cementerio de Nandor");
SetIntLong("Est�s en el camino interior del cementerio. Hay un banco que sin duda sirvi� "
           "en sus buenos tiempos para que la gente descansara. Al norte ves tumbas, al "
           "sur m�s tumbas y al este se divisa una capilla. Un poco m�s al norte se ve el "
           "templo.\n");
SetIndoors(0);
AddDetail("banco",
          "Est� roto en el suelo, no parece que sirva para descansar.\n");
AddDetail(({"tumbas","tumba"}),
          "��Qu� otra cosa esperabas encontrar en un cementerio??\n");
AddDetail("capilla",
          "Desde aqu� no la puedes ver muy bien. Est� en el centro de la plaza que hay "
          "al este.\n");
AddDetail("templo",
          "No lo ves muy bien, pero sin duda ha conocido d�as mejores...\n");
AddExit("sur","cemen2o");
AddExit("norte","cemen4o");
AddExit("este","cemen3");
}
