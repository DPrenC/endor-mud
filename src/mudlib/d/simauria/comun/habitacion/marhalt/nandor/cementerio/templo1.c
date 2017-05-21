/*          ermit1.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Modificaciones :
            7-11-97 [Nemesis] Tio! A ver si te aprendes los nombres de
            		      las funciones!
            23-09-98 [Nemesis] Pequenyos cambios en el codigo de las funciones
           		       y ligeros retoques a las descripciones y AddDetails.
	     9-11-01 [Jessy]   Castellanización de los ficheros y cambio de ermita a templo.
            16-05-02 [n] Retocadas las descripciones.
*/
#include <properties.h>
#include <moving.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("la entrada al templo.");
SetIntLong(
           "Estás en la entrada del templo dedicado a la diosa Sharanna, "
	   "la Señora de la Muerte. A pesar de la desolación que emana del "
           "lugar, sientes que aquí estarás protegido de todo mal. Sin embargo, sigues "
           "teniendo esa sensación extraña en la espalda. Hacia el norte ves el "
	   "altar. Hay mesas a los laterales cubiertas por un paño negro, y encima "
	   "de ellas puedes ver unos cuantos incensarios ardiendo, haciendo que el "
	   "ambiente de la estancia se encuentre cargado. En ellas también hay restos "
	   "de cera. Parece que hace tiempo la gente dejaba allí las velas para pedir "
	   "a la diosa que el descanso de sus familiares fuera lo más placentero "
	   "posible. A la entrada, ves en el suelo "
	   "una pequeña cesta. Hacia el sur puedes ir al cementerio. "
           "Al nordeste y al noroeste puedes ver dos puertas que están abiertas.\n");
SetIndoors(1);
SetIntBright(20);
SetIntSmell("Huele mucho a incienso.\n");

AddDetail(({"cesta"}),
            "Es una de esas cestas donde la gente deja donativos. Por desgracia está "
            "totalmente vacía.\n");
AddDetail(({"puertas"}), "Parecen llevar al interior del templo.\n");
AddDetail(({"puerta"}), "¿QUÉ puerta?");
AddDetail(({"puerta nordeste","puerta del nordeste"}),
            "Parece llevar al nordeste...\n");
AddDetail(({"puerta noroeste","puerta del noroeste"}),
            "Parece llevar al noroeste...\n");

AddExit("sur","cemen4");
AddExit("norte","templo2");
AddExit("nordeste","templo1ne");
AddExit("noroeste","templo1no");
}
