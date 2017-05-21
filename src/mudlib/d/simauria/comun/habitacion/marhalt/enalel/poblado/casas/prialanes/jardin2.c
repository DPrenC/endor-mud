/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("Casa Prialanes");
  SetIntShort("el jardín experimental");
  SetIntLong(W("Estás en medio del  jardín de la familia Prialane. Los manzanos "
  "aquí plantados parecen que han sufrido algún experimento fallido ya que su "
  "color es enfermizo. El jardín continúa hacia el sur y al norte.\n"));
  SetIntNoise("Los sonidos de la naturaleza llegan amortiguados por los cristales.\n");
  SetIntSmell("El aroma de extrañas manzanas flota en el lugar.\n");
  AddDetail(({"cristal","critstales"}),W("Son unas enormes paredes de cristal "
  "que protegen a los manzanos de las inclemencias del exterior.\n"));
  AddDetail(({"manzano","manzanos","árbol","arbol","árboles","arboles"}),W("Son "
  "unos altos y delgados manzanos de tronco claro y hojas claras. Parece que en "
  "estos momentos no hay manzanas en sus copas.\n"));
  
  AddExit("norte",ENALHAB"poblado/casas/prialanes/jardin1");
  AddExit("sur",ENALHAB"poblado/casas/prialanes/jardin3");
}
