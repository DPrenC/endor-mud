 /*
DESCRIPCION : bajo el portico del gremio de aventureros
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico07.c
MODIFICACION: 09-09-07 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el p�rtico del gremio de aventureros");
 SetIntLong(
   "Este es el p�rtico del estrecho edificio donde se halla una sede del "
   "gremio de aventureros. La madera de la fachada est� bastante da�ada "
   "por el salitre y ciertamente las ventanas, reparadas innumerables "
   "veces, vieron d�as mejores... Est� claro que los miembros del gremio "
   "pasan m�s tiempo viajando que aqu�.\n");

#include "puerto_detail.h"

 AddDetail(({"puerta"}),
   "Est� al oeste de aqu�, siempre abierta a los miembros del gremio que recorren "
   "el mundo.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle07"));
   AddExit("norte",AZ_PUERTO("portico06"));
   AddExit("oeste","/guilds/aventurero/sede/azzor/aventurero");
}
