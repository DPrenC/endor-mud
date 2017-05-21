/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina01.c
MODIFICACION: 03-12-97 [kuno]
              05-03-98 [Angor@Simauria] Rehecha
              06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("el camino de la mina");
 SetIntLong(
    "A medida que el camino se acerca a las montañas del oeste, su ascensión es cada "
    "vez mas pronunciada. En el camino de tierra se observan claramente las profundas "
    "huellas dejadas por los carromatos que, cargados de mineral de la mina, suelen "
    "circular por él. En la rama de un viejo arbol junto al camino esta posado un "
    "cuervo negro que salta continuamente de una rama a otra.\n");

  AddDetail(({"montanya","montañas","montaña","montanyas","Shojuna","shojuna"}),
     "Al oeste del valle se hallan las montañas de Shujuna. Estas altas montanyas "
     "aislan al valle de Zarkam de los territorios costeros del oeste de la península "
     "de Aguliuk ya que no existe un paso en condiciones para poder cruzarlas. Los "
     "orcos han excavado algunas minas en ellas.\n");

  AddDetail(({"mineral","huellas","carromatos","huellas de carromatos"}),
     "Por este camino se baja en carromatos el mineral extraido de la mina hacia la "
     "forja que hay en la herreria de Zarkam. El mineral es pesado y las carromatos "
     "cargados dejan por ello claras huellas de su paso en el camino.\n");

  SetIntNoise("Tan solo eres capaz de oir los graznidos del cuevo.\n");
  SetIntSmell("No hueles nada especial.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("oeste",Z_CAMINO("c_mina02"));
  AddExit("sudeste",Z_CAMINO("c_mina00"));
  AddItem(PNJ("animal/cuervo"),REFRESH_REMOVE,1);
}
