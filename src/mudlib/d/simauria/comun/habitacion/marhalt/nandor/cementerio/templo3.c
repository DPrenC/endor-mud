/*          templo3.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
            Modificado por :
	    [Nemesis]  Retoques en la descripcion y AddDetails
	    [Jessy]    Castellanización del fichero y cambio de las
	               descripciones de ermita a templo.
            16-05-02 [n] Retocadas las descripciones.
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetPreIntShort("frente a");
SetIntShort("el altar");
SetIntLong(
           "Hay un gran número de bancos para que la gente se siente mientras se celebra "
           "el acto religioso. Hacia el este ves una imagen y al oeste puedes ver un "
           "confesionario. Al sur ves la entrada del templo.\n");
SetIndoors(1);
SetIntBright(20);

AddDetail(({"estatua"}),
            "Es una estatua de Sharanna. Tiene un montón de flores a sus pies.\n");
AddDetail(({"flores"}),
            "No parecen muy frescas. Tienen a la diosa muy desatendida. Como esto siga así "
	    "puede que incurran en su ira...\n");
AddDetail(({"confesionario"}),
            "Parece vacío.\n");
AddDetail(({"entrada"}),
            "Es el lugar por donde se entra y sale del templo.\n");

AddExit("norte","./templo4");
AddExit("sur","templo2");
AddExit("este","templo3e");
AddExit("oeste","templo3o");

}
