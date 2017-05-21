/*
DESCRIPCION  : Sendero de los Cráneos al norte de Zarkam.
FICHERO      : /d/akallab/comun/rooms/akallab/zarkam/camino/cc_12.c
MODIFICACION : 03-12-97 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al norte de Zarkam");
  SetIntLong(
     "El Sendero de los Cráneos continua avanzando a traves de este valle hacia la "
     "ciudad de Zarkam que se halla sobre una loma al sur. Cerca de aqui hay dos "
     "cruces en el Sendero, uno al norte y que lleva al este, y otro al sur de aqui "
     "que lleva al oeste del valle. Desde aqui puedes ver al norte el río Kuneii. El "
     "viento frio sopla con fuerza desde el noroeste.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

 AddDetail(({"río","Kuneii","río Kuneii","kuneii"}),
     "El río Kuneii nace en las montanyas que se encuentran al oeste del valle de "
     "de Zarkam y avanza hacia el este atravesando el valle. Sus aguas son frias y "
     "algo turbias.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("nordeste",Z_CAMINO("cc_13"));
 AddExit("sur",Z_CAMINO("cc_11"));
}
