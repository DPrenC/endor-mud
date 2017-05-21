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
  SetIntLong(W("Estás al final del jardín de experimentación de la familia. "
  "Los oscuros manzanos parecen rozar los cristales que protegen este lugar. "
  "El jardín continúa hacia el norte.\n"));
  SetIntNoise("Los sonidos de la naturaleza llegan amortiguados por los cristales.\n");
  SetIntSmell("El aroma de extrañas manzanas flota en el lugar.\n");
  AddDetail(({"cristal","critstales"}),W("Son unas enormes paredes de cristal "
  "que protegen a los manzanos de las inclemencias del exterior.\n"));
  AddDetail(({"manzano","manzanos","árbol","arbol","árboles","arboles"}),W("Son "
  "unos altísimos y delgados manzanos de tronco oscuro y hojas rojizas. Parece "
  "que en estos momentos no hay manzanas en sus copas.\n"));
  
  AddExit("norte",ENALHAB"poblado/casas/prialanes/jardin2");
}
