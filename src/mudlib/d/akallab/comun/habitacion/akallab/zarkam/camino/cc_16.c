/*
DESCRIPCION  : Sendero de los Cráneos al norte de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/cc_16.c
MODIFICACION : 05-03-98 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>



inherit ROOM;

//los PNJ no pasan
int ir_no()
{
if (TP->QueryIsPlayer()) return TP->move(K_CAMINO("kuntz_00"),M_GO);
  return 1;
}

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al norte de Zarkam");
  SetIntLong(
     "En este punto el Sendero de los Cráneos abandona el valle de Zarkam, que queda "
     "al sur, y se adentra en la cordillera montanyosa de Kova que se halla al norte "
     "de aqui. El Sendero de los Cráneos atraviesa estas montanyas por el desfiladero "
     "de Kuntz, un lugar peligroso especialmente por la noche. Un viento helado aulla "
     "al atravesar los angostos desfiladeros al norte.\n");

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

  SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("noroeste",SF(ir_no));
  AddExit("sudeste",Z_CAMINO("cc_15"));
}
