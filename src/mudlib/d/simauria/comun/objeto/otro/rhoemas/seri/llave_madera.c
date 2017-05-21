/***************************************************************************************
 ARCHIVO:	llave_madera.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Una llave de madera
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();
  SetShort("una llave de madera");
  SetLong("Es una llave de madera muy extraña. Parece tallada de un tronco.\n");
  SetIds(({"llave","llave de madera","llave de seri-solderteg","llave de cylin"}));
  SetMaterial(M_MADERA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  Set(P_CANT_STEAL,1);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetWeight(50);
  SetValue(0);
}

