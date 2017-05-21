 /*
DESCRIPCION : frente al meson del Negro en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle06.c
MODIFICACION: 28-09-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
   "Te encuentras en el muelle del puerto de Azzor que se extiende de Sur a Norte "
   "rodeando la d�rsena donde puedes ver fondeados multitud de barcos. "
   "Al oeste de aqu� se halla el mes�n del Negro, el lugar donde se dice que se "
   "come el mejor pescado del puerto.\n");

#include "puerto_detail.h"

 AddDetail(({"meson","mes�n","edificio"}),
  "El mes�n del Negro queda al oeste de aqu�. Sus platos de pescado son bien conocidos en "
    "esta zona.\n");

 AddExit("norte",AZ_PUERTO("muelle05"));
 AddExit("oeste",AZ_PUERTO("portico06"));
 AddExit("sur",AZ_PUERTO("muelle07"));
 AddItem(PNJ_AZZOR("cork"), REFRESH_DESTRUCT, 1);
}