/*          templo4u.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Jessy]   Castellanizaci�n del fichero, y cambio de las descripciones
	              del tmeplo que antes era ermita.
*/

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el almac�n del templo");
SetIntLong(W(
             "Est�s en el lugar donde se guardan todas las cosas necesarias para que se "
             "pueda celebrar una ceremonia. Puedes ver varias t�nicas, varios barriles "
             "de vino, una gran cesta y diversas cosas m�s que ni siquiera sabes como se "
	         "llaman. "
             "S�lo puedes bajar por las escaleras por las que has subido.\n"));
SetIndoors(1);
SetIntBright(20);

SetIntSmell("Notas un fuerte olor a vino rancio.\n");

AddDetail(({"cosas necesarias","cosas"}),
            "Especifica m�s...\n");
AddDetail(({"t�nicas","t�nica","tunica","tunicas"}),
            "Todas est�n hechas jirones y cubiertas de polvo.\n");
AddDetail(({"cesta"}),
            "Est� vac�a.\n");
AddDetail(({"barriles","vino"}),
            "La mayor�a de los barriles son ahora nidos de ratas. Todos est�n agujereados "
            "y el vino que conten�an se derram� hace mucho tiempo.\n");

AddItem(PNJ("marhalt/rata"),REFRESH_DESTRUCT,4);
AddExit("abajo","templo4");
}
