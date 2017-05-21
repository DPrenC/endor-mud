/*          templo3e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
            Modificado por :
	    [Nemesis]  Descripcion y AddDetails
	    [Jessy]    Castellanizaci�n del fichero y cambio de las descripciones
	               del templo que antes era una ermita.
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("frente a");
SetPreIntShort("frente a");
SetIntShort("una imagen");
SetIntLong(
           "Ves la imagen de la diosa Sharanna la se�ora de la Muerte, con "
	   "un mont�n de flores a sus pies. Al oeste ves los bancos para sentarse "
	   "y al noroeste ves el altar.\n");
AddDetail("flores", "Estan secas.\n");
AddDetail(({"estatua","Sharanna","sharanna","imagen"}),
            "Est� muy deteriorada. Seguro que nadie se ha ocupado de ella en a�os.\n");
AddDetail(({"altar"}),
            "No lo ves bien desde aqu�.\n");
SetIndoors(1);
SetIntBright(20);
AddExit("oeste","templo3");
}