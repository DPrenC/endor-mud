/*          cemen4e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 30-10-97
            Ultima modificacion : 9-11-01
            Modificado por :
	    [Nemesis]  Cambios en las descripciones y AddDetails
	    [Jessy]    Castellanización de los ficheros y cambio de la ermita a templo...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el cementerio de Nandor");
SetIntLong(
           "Ves tumbas por todas partes. La mayoría han sido profanadas, pero hay una "
           "que, aunque reciente, parece intacta. "
           "Hacia el norte ves unos panteones, hacia el sur y el oeste el camino que "
           "lleva al templo.\n");
SetIndoors(0);

AddDetail("tumbas","Hay muchas... pero hay una que destaca sobre las demás.\n");
AddDetail("tumba", "\tTumba dedicada al wiz -BlackRider-\nTus amigos y "
          "compañeros de fatigas no te olvidan\n\tMay 97-Sep 97\n");
AddDetail("templo","Está cerca, al noroeste.\n");

AddExit("sur","cemen3e");
AddExit("norte","cemen4ne");
AddExit("oeste","cemen4");
}
