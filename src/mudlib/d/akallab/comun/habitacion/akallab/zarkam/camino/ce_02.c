/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_02.c
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
     "El camino del Este sigue avanzando a traves del valle de Zarkam. Desde aqui se "
     "observa ya el río Kuneii al este que nace en las montanyas del sur, y lejos en "
     "fondo del valle al nordeste observas las tierras de cultivo que proveen a la "
     "ciudad de Zarkam. El frio viento aulla entre las rocas.\n");

  AddDetail(({"río","río Kuneii","río kuneii","kuneii","Kuneii"}),
     "Nace en las montanyas del Sharg al sur y desciende hacia las tierras de cultivo "
     "alla en en el nordeste del valle. Aqui todavia es un arroyo, pero su agua ya "
     "baja con fuerza entre las rocas.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "Es una importante via de comunicacion que recorre el valle de norte a sur.\n");

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
 AddExit("oeste",Z_CAMINO("ce_01"));
 AddExit("este",Z_CAMINO("ce_03"));
}
