/*
DESCRIPCION  : Sendero de los Cráneos al norte de Zarkam.
FICHERO      : /d/akallab/comun/rooms/akallab/zarkam/camino/cc_14.c
MODIFICACION : 04-12-97 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  object obj;
  ::create();
  SetIntShort("el sendero de los Cráneos al norte de Zarkam");
  SetIntLong(
     "El Sendero de los Cráneos comienza a ascender lentamente a medida que se acerca "
     "a la cordillera montanyosa de Kova que se halla al norte del valle. Al sur de "
     "aqui hay un cruce en el Sendero del que sale un camino que va hacia el este del "
     "valle. El río Kuneii, que cruza el valle de oeste a este, pasa cerca de aqui al "
     "sur. El viento sopla con fuerza.\n");

  AddDetail(({"desfiladero","kuntz","Kuntz","cordillera","Kova","kova"}),
     "La cordillera montanyosa de Kova se halla al norte del valle. Esta formada por "
     "altas montanyas cubiertas de nieves perpetuas. La unica forma razonable para "
     "atravesarlas es a traves del desfiladero de Kunz. Este desfiladero avanza a "
     "traves de profundas grietas y peligrosas simas siendo ademas una zona donde se "
     "suelen esconder grupos de troll.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

 AddDetail(({"río","Kuneii","río Kuneii","kuneii"}),
     "El río Kuneii nace en las montanyas que se encuentran al oeste del valle de "
     "de Zarkam y avanza hacia el este atravesando el valle. Sus aguas son frias y "
     "algo turbias.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("norte",Z_CAMINO("cc_15"));
 AddExit("sur",Z_CAMINO("cc_13"));

 AddItem(PNJ("animal/lobo"),REFRESH_DESTRUCT);
}
