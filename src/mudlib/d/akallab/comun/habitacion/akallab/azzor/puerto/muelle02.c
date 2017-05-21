 /*
DESCRIPCION : frente a la taberna del Tuerto en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle02.c
MODIFICACION: 07-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
//inherit ROOM;
inherit PORT;

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
   "Al oeste de aquí se halla la taberna del Tuerto, una de las más "
   "conocidas del puerto. La taberna es un edificio bajo con pórtico "
   "como la mayoría de los del puerto. La dársena continua hacia el "
   "Norte en dirección a la fortaleza.\n");

#include "puerto_detail.h"

 AddDetail(({"taberna","edificio"}),
 "La taberna del Tuerto se halla en el edificio que queda justo al "
 "oeste de aquí. Es un edificio bajo y de no muy buen aspecto. La "
 "taberna es una de las más conocidas de la ciudad, tanto por su bebida "
 "como por las peleas que continuamente se producen.\n");

 AddShip(BAR_TORMENTA("barco"));
 
 AddItem(PNJ_AZZOR("sitj"),REFRESH_DESTRUCT);
 AddExit("norte",AZ_PUERTO("muelle01"));
 AddExit("oeste",AZ_PUERTO("portico02"));
 AddExit("sur",AZ_PUERTO("muelle03"));
}
