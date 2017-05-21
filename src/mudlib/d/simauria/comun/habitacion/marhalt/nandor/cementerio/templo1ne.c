/*          ermit1ne.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 9-11-01
            Modificado por :
	    [Nemesis] Cambios en la descripcion y AddDetails
	    [Jessy]   Castellanizaci�n de los ficheros, y creaci�n del templo
	              que antes era una ermita.
	    16-05-02 [n] Retocadas las descripciones.
    NOTAS:
         [n] A�adir TODOS los detalles que aparecen en la descripci�n, so vaga...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("la cocina del templo.");
SetIntLong(
          "Est�s en la cocina del templo. Hay una silla y una mesa con un poco de "
	  "comida encima de ella. Hacia el suroeste vas a la entrada del templo "
	  "y hay una escalera que sube hacia el segundo piso.\n");
SetIndoors(1);
SetIntBright(20);
AddDetail(({"comida"}),
            "Est� algo pasadilla. Puedes probarla, pero no te lo aconsejar�a..\n");
AddDetail(({"mesa","silla"}),
            "Parece llevar mucho tiempo sin ser usada...\n");
AddDetail(({"escalera"}),
            "Es muy antigua, pero parece solida.\n");
AddExit("arriba","templo5ne");
AddExit("suroeste","templo1");
}
