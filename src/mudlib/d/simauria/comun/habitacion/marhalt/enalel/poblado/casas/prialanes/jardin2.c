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
  SetIntShort("el jard�n experimental");
  SetIntLong(W("Est�s en medio del  jard�n de la familia Prialane. Los manzanos "
  "aqu� plantados parecen que han sufrido alg�n experimento fallido ya que su "
  "color es enfermizo. El jard�n contin�a hacia el sur y al norte.\n"));
  SetIntNoise("Los sonidos de la naturaleza llegan amortiguados por los cristales.\n");
  SetIntSmell("El aroma de extra�as manzanas flota en el lugar.\n");
  AddDetail(({"cristal","critstales"}),W("Son unas enormes paredes de cristal "
  "que protegen a los manzanos de las inclemencias del exterior.\n"));
  AddDetail(({"manzano","manzanos","�rbol","arbol","�rboles","arboles"}),W("Son "
  "unos altos y delgados manzanos de tronco claro y hojas claras. Parece que en "
  "estos momentos no hay manzanas en sus copas.\n"));
  
  AddExit("norte",ENALHAB"poblado/casas/prialanes/jardin1");
  AddExit("sur",ENALHAB"poblado/casas/prialanes/jardin3");
}
