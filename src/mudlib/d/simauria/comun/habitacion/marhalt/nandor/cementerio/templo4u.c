/*          templo4u.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Jessy]   Castellanización del fichero, y cambio de las descripciones
	              del tmeplo que antes era ermita.
*/

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el almacén del templo");
SetIntLong(W(
             "Estás en el lugar donde se guardan todas las cosas necesarias para que se "
             "pueda celebrar una ceremonia. Puedes ver varias túnicas, varios barriles "
             "de vino, una gran cesta y diversas cosas más que ni siquiera sabes como se "
	         "llaman. "
             "Sólo puedes bajar por las escaleras por las que has subido.\n"));
SetIndoors(1);
SetIntBright(20);

SetIntSmell("Notas un fuerte olor a vino rancio.\n");

AddDetail(({"cosas necesarias","cosas"}),
            "Especifica más...\n");
AddDetail(({"túnicas","túnica","tunica","tunicas"}),
            "Todas están hechas jirones y cubiertas de polvo.\n");
AddDetail(({"cesta"}),
            "Está vacía.\n");
AddDetail(({"barriles","vino"}),
            "La mayoría de los barriles son ahora nidos de ratas. Todos están agujereados "
            "y el vino que contenían se derramó hace mucho tiempo.\n");

AddItem(PNJ("marhalt/rata"),REFRESH_DESTRUCT,4);
AddExit("abajo","templo4");
}
