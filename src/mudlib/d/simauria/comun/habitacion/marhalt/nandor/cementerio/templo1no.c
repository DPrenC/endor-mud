/*          ermit1no.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 12-11-01
            Modificado por :
	    [Nemesis]   Modificados descripcion y AddDetails
	    [Jessy]     Castellanización de los ficheros y cambio interior del templo
	                que antes era una ermita.
            16-05-02 [n] Retocadas las descripciones.
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el trastero del templo");
SetIntLong(
           "En esta habitación hay de todo: velas, incienso, restos de madera,... "
           "Parece el cuarto trastero del templo de tan lleno de trastos que está. "
	   "Aquí puedes ver una escalera te permite subir a la planta superior. "
           "Al sudeste puedes volver a la sala principal del templo.\n");
SetIndoors(1);
SetIntBright(20);

AddDetail("trastos",
          "Tirados por el cuarto ves montón de cosas inútiles entre las que están: "
          "una pala, un viejo cartel, velas, incienso, unas sillas rotas y cosas por el estilo.\n");
AddDetail(({"pala","cartel","incienso"}),
            "En el estado en que se encuentra, no sirve para nada...\n");
AddDetail(({"velas","sillas"}),
            "Son totalmente inservibles.\n");

AddExit("arriba","templo5no");
AddExit("sudeste","templo1");
}
