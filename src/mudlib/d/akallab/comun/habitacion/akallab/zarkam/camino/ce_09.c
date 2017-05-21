/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_09.c
MODIFICACION : 28-05-97 [Grake] Creacion.
               13-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  object obj;
  ::create();
  SetIntShort("el camino del Este");
  SetIntLong(
     "El camino del Este continua avanzando a traves del valle de Zarkam. Observas que "
     "al este de aqui se halla un cruce en el camino del que parte un sendero que "
     "desciende hacia los campos de cultivo que se hallan al norte. Estos estan "
     "cubiertos por una cierta niebla debida a la humedad.\n");

  AddDetail(({"niebla"}),QueryIntLong());

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
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("este",Z_CAMINO("ce_10"));
  AddExit("suroeste",Z_CAMINO("ce_08"));

  AddItem(PNJ("animal/lobo"),REFRESH_DESTRUCT);
}
