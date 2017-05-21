/*
DESCRIPCION  : Cruce del Camino del Este y el camino a los campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_10.c
MODIFICACION : 28-05-97 [Grake] Creacion.
               13-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un cruce en el camino del Este");
  SetIntLong(
     "Has llegado a un cruce en el camino del Este. Aqui se separa del camino un "
     "sendero que desciende hacia el fondo del valle al norte donde se encuentran los "
     "campos de cultivo. A partir de aqui, el camino del Este comienza ascender hacia "
     "el paso de Akkbar que se halla en las montanyas al este de aqui.\n");

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
  SetIntSmell("Hmm.. el aire huele a tierra humeda.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("este",Z_CAMINO("ce_11"));
  AddExit("nordeste",Z_CAMINO("c_camp00"));
  AddExit("oeste",Z_CAMINO("ce_09"));
 }
