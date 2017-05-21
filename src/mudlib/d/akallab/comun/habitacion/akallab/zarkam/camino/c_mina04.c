/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina04.c
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
    "En este punto el camino de la mina comienza a encajonarse entre las altas "
    "montanyas de Shojuna perdiendo asi de vista el valle de Zarkam. El camino se "
    "acerca al caudaloso arroyo que es el río Kuneii, tanto que ambos se cruzan al "
    "oeste de aqui.\n");

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

SetIntNoise("El arroyo es bastante escandaloso.\n");
SetIntSmell("El aire es muy humedo debido, sin duda, al río.\n");
SetLocate("valle de Zarkam");
SetIndoors(0);
AddExit("oeste",Z_CAMINO("c_mina05"));
AddExit("este",Z_CAMINO("c_mina03"));
AddItem(PNJ("animal/lobo"),REFRESH_DESTRUCT);
}
