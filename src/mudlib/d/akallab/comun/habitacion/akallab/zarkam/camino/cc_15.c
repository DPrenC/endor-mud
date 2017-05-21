/*
DESCRIPCION  : Sendero de los Cráneos al norte de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/cc_15.c
MODIFICACION : 05-03-98 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al norte de Zarkam");
  SetIntLong(
     "La ascension del Sendero de los Cráneos se hace mas abrupta a medida que se "
     "acerca al paso de Kuntz en la cordillera de Kova al norte del valle. Desde aqui "
     "se observa al sur el río Kuneii que cruza el valle de oeste a este. El viento "
     "sopla cada vez con mas fuerza a medad que te acercas a las montanyas.\n");

  AddDetail(({"desfiladero","kuntz","Kuntz","cordillera","Kova","kova"}),
     "La cordillera montanyosa de Kova se halla al norte del valle. Esta formada por "
     "altas montanyas cubiertas de nieves perpetuas. La unica forma razonable para "
     "atravesarlas es a traves del desfiladero de Kunz. Este desfiladero avanza a "
     "traves de profundas grietas y peligrosas simas siendo ademas una zona donde se "
     "suelen esconder grupos de troll.\n");

  AddDetail(({"río","río Kuneii","Kuneii"}),
    "El río Kuneii serpentea a traves del valle de Zarkam. Sus aguas son frias y "
    "algo turbias.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("noroeste",Z_CAMINO("cc_16"));
 AddExit("sur",Z_CAMINO("cc_14"));
 AddItem(HERBS("hierba_magica"), REFRESH_REMOVE);
}
