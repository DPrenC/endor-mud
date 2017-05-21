/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Llave
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit "/std/thing"; 

create(){
  ::create();
  
  SetShort("Una pequeña llave");
  SetLong("Es una pequeña llave de metal con una letra D tallada en el centro.\n");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetWeight(20);
  SetIds(({"Llave_DormitorioAnciano","llave","llave pequeña","llave pequenya"}));
}
