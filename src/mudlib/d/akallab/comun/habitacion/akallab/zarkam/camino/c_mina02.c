/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina02.c
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
    "Desde aqui ya comienzas a poder ver la mayor parte del valle de Zarkam, ya que a "
    "medida que te acercas a las montanyas de Shojuna te hallas a mayor altura. En el "
    "camino puedes observar las huellas dejadas por los carromatos que bajan mineral "
    "desde la mina. Al norte se encuentra el río Kuneii, aunque aqui es mas bien un "
    "arroyo. El frio de esas alturas se te cala en los huesos.\n");

  AddDetail(({"montanya","montanyas","Shojuna","shojuna"}),
     "Al oeste del valle se hallan las montanyas de Shujuna. Estas altas montanyas "
     "aislan al valle de Zarkam de los territorios costeros del oeste de la peninsula "
     "de Aguliuk ya que no existe un paso en condiciones para poder cruzarlas. Los "
     "orcos han excavado algunas minas en ellas.\n");

  AddDetail(({"mineral","huellas","carromatos","huellas de carromatos"}),
     "Por este camino se baja en carromatos el mineral extraido de la mina hacia la "
     "forja que hay en la herreria de Zarkam. El mineral es pesado y las carromatos "
     "cargados dejan por ello claras huellas de su paso en el camino.\n");

  AddDetail(({"arroyo","río","río Kuneii","Kuneii","kuneii"}),
     "El río Kuneii serpentea a medida que atraviesa el valle de Zarkam de oeste a "
     "este. Sus aguas son frias y algo turbias.\n");

  SetIntNoise("Oyes el graznido de un cuervo no lejos de aqui.\n");
  SetIntSmell("No hueles nada especial.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("este",Z_CAMINO("c_mina01"));
  AddExit("noroeste",Z_CAMINO("c_mina03"));
}
