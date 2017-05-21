/*          templo5no.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Nemesis]
	    [Jessy]    Castellanizaci�n del fichero y cambio de las descripciones
	               del templo que antes era una hermita.
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
    SetLocate("Cementerio de Nandor");
    SetIntShort("la biblioteca del templo");
    SetIntLong(
           "Est�s en la biblioteca del templo. Aqu� hay varios estantes con un gran"
           "n�mero de libros encima."
           "Hacia abajo vas al trastero del templo y al sudeste hay otra habitaci�n.\n");
    SetIntBright(20);

    AddDetail("libros","Parecen todos muy antiguos.\n");

    AddExit("sudeste","templo5");
    AddExit("abajo","templo1no");
//AddItem(OBJETO+"otro/biblia",REFRESH_REMOVE,1);
}
