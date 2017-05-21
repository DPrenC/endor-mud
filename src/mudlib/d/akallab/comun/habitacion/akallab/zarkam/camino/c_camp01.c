/*
DESCRIPCION  : Camino a los Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp01.c
MODIFICACION : 01-12-97 [Grake] Creacion.
               13-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino a los campos de cultivo");
  SetIntLong(
     "El camino que conduce hacia los campos de cultivo continua descendiendo hacia el "
     "norte. Desde aqui observas ya mas claramente los campos y el río Kusaii que los "
     "atraviesa. El aire es frio y sientes como se te vigila desde la lejana ciudad de "
     "Zarkam.\n");

  AddDetail(({"ciudad","ciudad fortificada","zarkam","Zarkam","murallas","torre"}),
    "La ciudad fortificada de Zarkam se halla situada sobre una loma en la parte alta "
    "del valle desde donde controla todo este territorio. La ciudad esta lejos, por "
    "lo que solo distingues sus murallas y sobre ellas, una alta torre.\n");

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

  SetIntNoise("Oyes al ruido del viento aullar a tu alrededor.\n");
  SetIntSmell("Hmm.. el aire huele a tierra humeda.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("sur",Z_CAMINO("c_camp00"));
  AddExit("norte",Z_CAMINO("c_camp02"));
}
