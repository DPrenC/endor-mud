/*
DESCRIPCION  : Ciudad de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : Creado por chantiel
MODIFICACION : [l] lonerwolf
               19/10/00 [l] coloque la descripciones pertinentes
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("la calle Hirak");
SetIntLong("Está en el Camino de Hirak. Al sur se encuentra la Taberna el\n"
	   "Vegetariano, al oeste continúa el camino de Hirak y al este está\n"
	   "el cruce con el camino del Anochecer\n"
	   );

AddDetail (({"posada","posada el vegetariano","posada el Vegetariano"}),
	   "Es una posada muy concurrida de la ciudad, tiene un cartel en\n"
	   "la puerta"
	   );

AddDetail (({"cartel"}),
	   "\n"
	   "        ################################\n"
	   "        ##                            ##\n"
	   "        ##   Posada El Vegetariano    ##\n"
	   "        ## su comida hecha de la mano ##\n"
	   "        ##                            ##\n"
	   "        ## Comida baja en grasas      ##\n"
	   "        ##                            ##\n"
	   "        ################################\n"
	   "\n"
	   );

SetIntNoise("Se escucha el conversar de la gente de la Taberna");
SetIntSmell("El olor de la comida de la taberna llega hasta este lugar\n"
	    "Y huele bien!");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("sur",TCSUELO("taberna1"));
AddExit("este",TCSUELO("hirak3"));
AddExit("oeste",TCSUELO("cruce1"));

}
