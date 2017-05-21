/*
DESCRIPCION  : Camino a los Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp02.c
MODIFICACION : 24-11-97 [Grake] Creacion.
               14-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino a los campos de cultivo");
  SetIntLong(
     "El descenso del camino se modera a medida que te acercas a los campos de cultivo "
     "del valle de Zarkam que ahora ya tienes practicamente ante ti. Los campos estan "
     "regados por el río Kusaii, pero no parecen demasiado productivos. Observas que "
     "al norte de los mismos se halla una especie de gran cabanya o establo. A medida "
     "que vas llegando a la parte mas profunda y por tanto protegida del valle, el "
     "frio viento del se va moderando.\n");

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail(({"río","río Kusaii","río kusaii","Kusaii","kusaii"}),
    "El río Kusaii nace en las montanyas de Sharg, al sur del valle de Zarkam. Desde "
    "alli baja encajonado entre desfiladeros hasta el centro del valle donde se une "
    "con su afluente el Kuneii que viene del oeste, para despues dirigirse hacia el "
    "este hacia la costa. Este río no es navegable, pues al atravesar las montanyas "
    "Negras, que quedan al este de aqui, las cataratas de Nurr lo impiden.\n");

  AddDetail(({"tierras de cultivo","cultivos","campos de cultivo"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

  AddDetail(({"ciudad","ciudad fortificada","zarkam","Zarkam","murallas","torre"}),
    "La ciudad fortificada de Zarkam se halla situada sobre una loma en la parte alta "
    "del valle desde donde controla todo este territorio. La ciudad esta lejos, por "
    "lo que solo distingues sus murallas y sobre ellas, una alta torre.\n");

  SetIntNoise("Oyes al ruido del viento aullar a tu alrededor.\n");
  SetIntSmell("Notas un olor a tierra humeda removida.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("sur",Z_CAMINO("c_camp01"));
  AddExit("nordeste",Z_CAMINO("c_camp03"));
  AddItem(HERBS("hierba_intoxicante"), REFRESH_REMOVE);
}
