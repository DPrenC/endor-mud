 /*
DESCRIPCION : bajo el portico de la taberna del Tuerto en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico03.c
MODIFICACION: 09-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 ::create();
SetIntShort("el pórtico de la taberna del Tuerto");
 SetIntLong(
   "Te encuentras bajo el pórtico de la taberna del Tuerto. A través de "
   "la ventana de la taberna apenas si puedes ver algo dado que los "
   "cristales que la forman son translucidos además de no estar muy "
   "limpios. Dicen que la bebida en esta taberna es buena y las "
   "broncas, como no podía ser de otra forma, frecuentes.\n");

#include "puerto_detail.h"

 AddDetail(({"ventana","cristales"}),
  "A través de los sucios cristales de la ventana de la taberna "
  "apenas si puedes ver algo del interior.\n");

 AddDetail(({"taberna","edificio"}),
  "La taberna del Tuerto se halla en los bajos de este edificio. "
  "Apenas si puedes ver algo de su interior a través de la ventana "
  "que tienes enfrente. Esta taberna es de las más conocidas de la "
  "ciudad, tanto por su bebida como por las peleas que continuamente "
  "se producen.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle03"));
   AddExit("sur",AZ_CIUDAD("calle00"));
   AddExit("norte",AZ_PUERTO("portico02"));
}
