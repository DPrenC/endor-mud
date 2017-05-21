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
SetIntShort("el p�rtico de la taberna del Tuerto");
 SetIntLong(
   "Te encuentras bajo el p�rtico de la taberna del Tuerto. A trav�s de "
   "la ventana de la taberna apenas si puedes ver algo dado que los "
   "cristales que la forman son translucidos adem�s de no estar muy "
   "limpios. Dicen que la bebida en esta taberna es buena y las "
   "broncas, como no pod�a ser de otra forma, frecuentes.\n");

#include "puerto_detail.h"

 AddDetail(({"ventana","cristales"}),
  "A trav�s de los sucios cristales de la ventana de la taberna "
  "apenas si puedes ver algo del interior.\n");

 AddDetail(({"taberna","edificio"}),
  "La taberna del Tuerto se halla en los bajos de este edificio. "
  "Apenas si puedes ver algo de su interior a trav�s de la ventana "
  "que tienes enfrente. Esta taberna es de las m�s conocidas de la "
  "ciudad, tanto por su bebida como por las peleas que continuamente "
  "se producen.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle03"));
   AddExit("sur",AZ_CIUDAD("calle00"));
   AddExit("norte",AZ_PUERTO("portico02"));
}
