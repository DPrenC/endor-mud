/*          cemen2e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 2-11-01
            Modificado por :
	    [Nemesis] Cambios en las descripciones y AddDetails
	    [Jessy]   CAstellanizar el fichero y cambiar la ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("entre");
SetIntShort("las lápidas");
SetIntLong(
	   "Sólo ves tumbas removidas. Por respeto tendrías que volver al camino hacia el oeste "
	   "o al norte no sea que se vayan a enfadar estos muertos.\n");
SetIndoors(0);
SetIntSmell("Hay un extraño olor en el ambiente. No es agradable.\n");
AddDetail(({"tumbas","tumbas removidas"}),
	    "Hay un montón de ellas. Todas han sido profanadas y algunos de sus ocupantes "
	    "yacen esparcidos por aquí y por allí...\n");
AddDetail(({"muertos","ocupantes","ocupantes de las tumbas","cadaveres","cadáveres"}),
	    "No tienen buen aspecto. Casi todos están medio devorados.\n");
AddExit("norte","cemen3e");
AddExit("oeste","cemen2");
AddExit("sur","cemen1e");
}
