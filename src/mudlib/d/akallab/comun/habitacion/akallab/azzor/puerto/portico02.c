 /*
DESCRIPCION : bajo el portico de la taberna del Tuerto en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico05.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el pórtico de la taberna del Tuerto");
 SetIntLong(
   "Estás bajo el pórtico de la taberna del Tuerto, una de las más conocidas "
   "de la ciudad. El Tuerto es un viejo guerrero que hace tiempo dejó la lucha "
   "para regentar esta taberna. Has oído que la semana pasada murieron aquí "
   "tres orcos medio borrachos en una de las muchas broncas que se producen...\n");

#include "puerto_detail.h"

 AddDetail(({"puerta"}),
  "La puerta de la taberna queda justo al oeste de aquí.\n");

AddDetail(({"taberna","edificio"}),
  "La taberna del Tuerto se halla en los bajos de este edificio. "
  "Su puerta queda justo al oeste de aquí. Esta taberna es de las más "
  "conocidas de la ciudad, tanto por su bebida como por las peleas "
  "que continuamente se producen.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle02"));
   AddExit("norte",AZ_PUERTO("portico01"));
   //AddExit("oeste",AZ_TABERNA("tuerto/barra"));
   AddExit("sur",AZ_PUERTO("portico03"));
}
