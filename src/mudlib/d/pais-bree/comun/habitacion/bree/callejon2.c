/*
Fichero: callejon2.c
Autor: aulë
Fecha: 04/08/2013
Descripción: callejón que pasa al sur del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("un callejón");
    	SetIntLong("Estás en un callejón que jalona la posada del Poney Pisador por la "
    	"parte sur. Al norte se levanta dicho edificio mientras que al sur se encuentran "
    	"otras casas y huertos de los aldeanos de Bree. La calle discurre en pendiente hacia "
    	"la parte alta de la aldea, ocupada por los agujeros de los hobbits.\n");
    	AddDetail("casas",
    	"Algunas casas de piedra o ladrillo bien construidas se asientan en la falda de la "
    	"colina, sin apelotonarse unas sobre otras, separadas por pequeños huertos y terrenos.\n");
    	AddDetail("huertos",
    	"Pequeñas huertas, terrenos herbosos o jardines separan unas casas de las otras, "
    	"cerrados por setos o muros bajos de piedras irregulares.\n");
    AddDetail(({"posada", "poney pisador", "norte"}),
    "Delimitando por el norte el callejón se alzan los tres pisos del Poney Pisador, "
    "con las ventanas de las diversas habitaciones dando sobre tu cabeza.\n"
    "Parece un edificio antiguo pero sólido.\n");
    AddDetail(({"agujeros", "agujeros hobbits"}),
    "Desde aquí no aciertas a verlos.\n");
 
    AddExit("oeste", "./callejon1");
     AddExit("este", "./callejon3");
          AddExit("norte", HABITACION+"bree/poney_pisador/pajar");
              HideExit("norte",1);
              AddDoor("norte", "una baja puerta",
              "Es una puerta de madera gruesa, pesada, baja y ancha que da acceso al edificio del norte. Por el aspecto que ofrece parece que no es utilizada muy a menudo.\n",
              ({"puerta", "puerta n", "puerta del norte", "n", "norte"}));
 
    } 
   