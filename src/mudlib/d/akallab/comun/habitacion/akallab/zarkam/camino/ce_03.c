/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_03.c
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
     "En este punto el camino del Este alcanza un pequenyo barranco por el que baja el "
     "río Kuneii de las montanyas. El camino desciende siguiendo el curso del río "
     "hasta un puente que se encuentra mas al norte. Puedes observar como las aguas "
     "bajan formando rapidos mientras serpentean entre las rocas del cauce. El frio "
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

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("ce_02"));
 AddExit("nordeste",Z_CAMINO("ce_04"));
}
