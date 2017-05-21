/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Llave
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit "/std/thing"; 

create(){
  ::create();
  
  SetShort("Una peque�a llave");
  SetLong("Es una peque�a llave de metal con una letra D tallada en el centro.\n");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetWeight(20);
  SetIds(({"Llave_DormitorioAnciano","llave","llave peque�a","llave pequenya"}));
}
