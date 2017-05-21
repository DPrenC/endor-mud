 /*
DESCRIPCION : frente a la taberna de Sally en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle04.c
MODIFICACION: 07-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
   "Al oeste de aqu� se halla la taberna de Sally "
   "la gorda, una orca con fama de descarada, pendenciera, jueguista, "
   "ladrona y muchas otras cosas m�s. Dicen las malas lenguas que "
   "cuando hace tiempo le gan� en el juego la taberna a su due�o "
   "hubo m�s trampa que suerte. Es una taberna bastante conocida "
   "y la bebida no esta muy aguada.\n");

#include "puerto_detail.h"

 AddDetail(({"taberna","edificio"}),
  "La taberna de Sally la gorda se halla en el edificio que queda justo al "
  "oeste de aqu�. Es un edificio bajo y de no muy buen aspecto. La "
  "taberna es una de las m�s conocidas de la ciudad, tanto por su bebida "
  "como por las peleas que continuamente se producen.\n");

 AddExit("norte",AZ_PUERTO("muelle00"));
 AddExit("oeste",AZ_PUERTO("portico04"));
 AddExit("sur",AZ_PUERTO("muelle05"));
}
