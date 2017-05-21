/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_11.c
MODIFICACION : 27-05-97 [Grake] Creacion.
               13-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Este");
  SetIntLong(
     "El camino del Este comienza asciende a medida que se acerca hacia las montanyas "
     "del este del valle. Al oeste de aqui hay un cruce en el camino, del que parte "
     "un sendero que desciende hacia los campos de cultivo que observas al fondo del "
     "valle. El paisaje es austero y el frio viento aulla con fuerza.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  AddDetail(({"tierras de cultivo","cultivos"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

  SetIntNoise("Oyes al ruido del viento aullar a tu alrededor.\n");
  SetIntSmell("Hmm.. el aire es seco y frio.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("oeste",Z_CAMINO("ce_10"));
  AddExit("este",Z_CAMINO("ce_12"));
 }
