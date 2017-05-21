/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_08.c
MODIFICACION : 13-02-98 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("el camino del Este");
 SetIntLong(
    "En este punto, el camino del Este gira hacia el nordeste siguiendo el relieve "
    "del valle de Zarkam. La ladera de la montanya es bastante empinada en el lado "
    "sudeste del camino, de forma que esta zona se encuentra practicamente siempre "
    "a la sombra. Gracias a la humedad de la zona, es un buen lugar para que crezcan "
    "todo tipo de setas. Esta zona esta resguardada del viento.\n");

  AddDetail(({"montanya","ladera"}),QueryIntLong());

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  AddDetail(({"tierras de cultivo","cultivos"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

 SetIntNoise("Oyes el viento aullando a lo lejos.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("ce_07"));
 AddExit("nordeste",Z_CAMINO("ce_09"));
 AddItem(HERBS("seta"), REFRESH_REMOVE);
 AddItem(HERBS("seta_narcotica"), REFRESH_REMOVE);
 AddItem(HERBS("seta_curativa"), REFRESH_REMOVE);
}
