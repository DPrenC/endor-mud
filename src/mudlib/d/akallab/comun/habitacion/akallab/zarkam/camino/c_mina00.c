/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina00.c
MODIFICACION: 03-12-97 [kuno]
              05-03-98 [Angor@Simauria] Rehecha
              06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("empezando");
  SetIntShort("el camino de la mina");
  SetIntLong(
    "Empiezas a andar por el camino de la mina y aunque de momento el sendero es "
    "apenas un falso llano supones que tendra que comenzar a ascender rapidamente ya "
    "que te diriges hacia las altas montanyas de Shojuna que se encuentran al oeste "
    "del valle. Al este de aqui, el camino acaba en el Sendero de los Cráneos.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"montanya","montanyas","Shojuna","shojuna"}),
     "Al oeste del valle se hallan las montanyas de Shujuna. Estas altas montanyas "
     "aislan al valle de Zarkam de los territorios costeros del oeste de la peninsula "
     "de Aguliuk ya que no existe un paso en condiciones para poder cruzarlas. Los "
     "orcos han excavado algunas minas en ellas.\n");

SetIntNoise("Oyes el fuerte viento a traves de las montanyas.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("valle de Zarkam");
SetIndoors(0);
AddExit("este",Z_CAMINO("cc_11"));
AddExit("noroeste",Z_CAMINO("c_mina01"));
}
