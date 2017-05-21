 /*
DESCRIPCION : bajo el portico de la taberna del Tuerto en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico01.c
MODIFICACION: 16-09-07 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el pórtico de la posada del Lobo de Mar");
 SetIntLong(
   "El pórtico de los edificios del puerto continua avanzando bajo los mismos."
   "En los días de la estación de lluvia, donde el agua cae sin parar aquí en "
   "costa, se agradece el cobijo de las arcadas de los edificios del puerto. "
   "Una vieja puerta de madera permite entrar a la posada del 'Lobo de Mar' al "
   "oeste de aquí. Has oido que está regentada por un viejo marino y que es un lugar "
   "aceptable para alojarse.\n");

#include "puerto_detail.h"

 AddDetail(({"puerta"}),
    "La puerta de la posada queda justo al este de aquí.\n");

AddDetail(({"posada","edificio"}),
   "Es un gran edificio de tres plantas de altura. Su fachada esta llena "
   "de ventanas y sobre la puerta principal cuelga un cartel de madera con "
   "el dibujo de una gran jarra de cerveza y el texto 'Posada el Lobo de "
   "Mar' pintado en él.\n");

   SetIndoors(1);
   SetIntBright(50);


   //AddExit("oeste",AZ_TABERNA("tuerto/barra"));
   
   //AddExit("norte",AZ_PUERTO("portico00"));
   AddExit("este",AZ_PUERTO("muelle01"));
   AddExit("sur",AZ_PUERTO("portico02"));
   AddExit("oeste",AZ_POSADA("lobomar/entrada"));
   
}
