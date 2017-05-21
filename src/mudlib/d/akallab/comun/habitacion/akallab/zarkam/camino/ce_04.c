/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_04.c
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
    "El camino desciende rapidamente a medida que se acerca al fondo del barranco, "
    "hasta llegar a un viejo puente de madera al este de aqui. El puente permite "
    "cruzar el río Kuneii cuyas aguas bajan rapidas desde las montanyas del sur. "
    "Hacia el nordeste ves como el barranco acaba frente a los campos de cultivo. "
    "El fondo del barranco esta mas a cubierto y apenas hace viento.\n");

  AddDetail(({"puente","viejo puente"}),
    "Un viejo puente de madera en el fondo del barranco permite cruzar el río Kuneii. "
    "A pesar de ser viejo, esta construido de forma sobria y robusta.\n");

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

 SetIntNoise("Apenas se oye el viento desde aqui.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("suroeste",Z_CAMINO("ce_03"));
 AddExit("este",Z_CAMINO("ce_05"));
}
