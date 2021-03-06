/*
DESCRIPCION  : Camino a los Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp00.c
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
    "El camino desciende hacia los campos de cultivo que se encuentran al fondo del "
    "valle de Zarkam. Al sur de aqui, este camino se cruza con el camino del Este que "
    "cruza el valle. Observas que los campos estan cuidadados, pero que a pesar de "
    "estar regados por el r�o Kusaii, su fertilidad es escasa. Lejos sobre una loma "
    "al oeste se alza la ciudad fortificada de Zarkam.\n");

  AddDetail(({"ciudad","ciudad fortificada","zarkam","Zarkam","murallas","torre"}),
    "La ciudad fortificada de Zarkam se halla situada sobre una loma en la parte alta "
    "del valle desde donde controla todo este territorio. La ciudad esta lejos, por "
    "lo que solo distingues sus murallas y sobre ellas, una alta torre.\n");

  AddDetail(({"r�o","r�o Kusaii","r�o kusaii","Kusaii","kusaii"}),
    "El r�o Kusaii nace en las montanyas de Sharg, al sur del valle de Zarkam. Desde "
    "alli baja encajonado entre desfiladeros hasta el centro del valle donde se une "
    "con su afluente el Kuneii que viene del oeste, para despues dirigirse hacia el "
    "este hacia la costa. Este r�o no es navegable, pues al atravesar las montanyas "
    "Negras, que quedan al este de aqui, las cataratas de Nurr lo impiden.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Es un camino que cruza el valle de Zarkam de este a oeste.\n");

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
  AddExit("suroeste",Z_CAMINO("ce_10"));
  AddExit("norte",Z_CAMINO("c_camp01"));
}
