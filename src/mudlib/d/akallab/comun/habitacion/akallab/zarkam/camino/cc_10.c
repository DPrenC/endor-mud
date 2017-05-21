/*
DESCRIPCION  : Sendero de los Cráneos al norte de Zarkam.
FICHERO      : /d/akallab/comun/rooms/akallab/zarkam/camino/cc_10.c
MODIFICACION : 29-11-97 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al norte de Zarkam");
  SetIntLong(
     "El Sendero de los Cráneos continua avanzando a traves del valle ascendiendo "
     "hacia la loma que hay al sur y sobre la que se asienta la ciudad fortificada de "
     "Zarkam. Junto al camino hay un alto poste en el que ondea una bandera negra. Al "
     "norte de aqui, hay un cruce en el camino. Un viento helado sopla con fuerza.\n");

  AddDetail(({"bandera","bandera negra","poste"}),
     "Como es habitual entre los orcos, se ha colocado el estandarte del imperio junto "
     "al camino. Este consiste en una larga banderola negra sin ningun otro simbolo, y "
     "su sola presencia ya atemoriza a muchos. La bandera se agita vigorosamente bajo "
     "el fuerte viento que baja desde las montanyas del norte.\n");

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

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("norte",Z_CAMINO("cc_11"));
 AddExit("sur",Z_CAMINO("cc_09"));
}
