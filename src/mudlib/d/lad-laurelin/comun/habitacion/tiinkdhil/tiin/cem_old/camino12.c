/*

DESCRIPCION  :

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS:

MODIFICACION :

*/



#include "./path.h"


#include <properties.h>

#include <rooms.h>


inherit ROOM;


create() {

  ::create();

SetIntShort("una bifurcación en el cementerio");

SetIntLong("  Hay una bifurcación, una que sigue hacia el norte, otra hacia el sur, y\n"+

	   "otra que parece llevar hacia el este . Aqui el número de lápidas es menor\n"+
            "que en el resto. Al este distingues entre la niebla un mausoleo.\n");
AddDetail(({"lapidas","lápidas","sepulturas","tumbas"}),"  Las lapidas son de construccion simple, "+
 " con un nombre tallado en marmol clavado en el suelo.\n");

AddDetail (({"niebla"}),"  Cerca del suelo es espesa y apenas te deja ver la hierba que\n" +

 "recubre todo el cementerio,el resto se trata de una niebla mucho\n"+

                 "menos densa pero que aun así te impide ver el final del camino.\n");

SetIntNoise("  Se puede oir la suave brisa del viento,que mueve la hierba.Se oye algo más\n"+

             "al fondo, cerca del camino,pero desde esta distancia no puedes saber bien de\n"+

	    "que se trata.\n");

 SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");

 SetLocate("Cementerio2");


SetIndoors (0); /* 0 exterior; 1 interior */

SetIntBright(20);


AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");

AddExit("este","mausoleo7");

AddExit("norte","camino13");

AddExit("sur","camino14");

}
