 /*
DESCRIPCION : bajo el portico de la taberna de Sally en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico04.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el pórtico de la taberna de Sally");
 SetIntLong(
  "Estás bajo el pórtico de la taberna de Sally la gorda, que es el "
  "local que queda al oeste de aquí y que puedes ver a través de una ventana. "
  "Dicen que en esta taberna los precios son razonables, el ambiente "
  "agradable, la bebida no muy aguada y no que falta una buena bronca "
  "de vez en cuando.\n");

#include "puerto_detail.h"

 AddDetail(({"ventana"}),
  "A través de la ventana puedes ver el interior de la taberna. Parece un "
  "lugar agradable para pasar el rato.\n");

 AddDetail(({"taberna","edificio"}),
  "Es un edificio bajo y de no muy buen aspecto. La taberna es una de "
  "las más conocidas de la ciudad, tanto por su bebida como por las peleas "
  "que continuamente se producen.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle04"));
   AddExit("norte",AZ_CIUDAD("calle00"));
   AddExit("sur",AZ_PUERTO("portico05"));
}
