/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina03.c
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
     "La altura a la que estas en este punto del camino te permite observar casi todo "
     "el valle de Zarkam. El camino sigue marcado por las huellas de los carromatos de "
     "minerales y te preguntas como pueden pasar por estos pasos tan estrechos. Desde "
     "aqui ya se oye el ruido del río Kuneii que ves al norte. A esta altura el viento "
     "es bastante frio.\n");

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
     "El río Kuneii serpentea a traves del valle de Zarkam. Sus aguas son frias y algo "
     "turbias. En esta zona, es mas bien un arroyo que corre entre penyas que un río "
     "propiamente dicho.\n");

SetIntNoise("Oyes el ruido del agua del río cada vez mas fuerte.\n");
SetIntSmell("No hueles nada que te llame la atencion.\n");
SetLocate("valle de Zarkam");
SetIndoors(0);
AddExit("oeste",Z_CAMINO("c_mina04"));
AddExit("sudeste",Z_CAMINO("c_mina02"));
AddItem(HERBS("hierba_saciante"), REFRESH_REMOVE);
}
