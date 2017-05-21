/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_07.c
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
    "El camino del Este asciende hasta llegar hasta el borde superior del barranco "
    "por cuyo fondo avanza vertiginoso el río Kuneii. Al norte de aqui en el fondo "
    "del valle, observas los campos de cultivo atravesados por el río. El frio "
    "viento sopla impasible.\n");

  AddDetail(({"barranco","pequenyo barranco"}),
    "Es una hendidura en la ladera de la montanya por cuyo fondo corre el río Kuneii. "
    "Para atravesarlo, el camino del Este debe bajar por sus laderas hasta llegar a "
    "la altura del río donde existe un puente.\n");

  AddDetail(({"río","río Kuneii","río kuneii","kuneii","Kuneii"}),
    "Nace en las montanyas del Sharg al sur y desciende hacia las tierras de cultivo "
    "alla en en el nordeste del valle. Aqui todavia es un arroyo, pero su agua ya "
    "baja con fuerza entre las rocas.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  AddDetail(({"tierras de cultivo","cultivos"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("ce_06"));
 AddExit("este",Z_CAMINO("ce_08"));
}
