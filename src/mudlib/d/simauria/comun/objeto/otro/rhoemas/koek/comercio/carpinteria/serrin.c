/***************************************************************************************
 ARCHIVO:	serrin.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Un poco de serr�n
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un poco de serr�n");
  SetLong("Es un mont�n de serr�n de lo m�s normal. Esto en su d�a fue un �rbol.\n");
  SetIds(({"serrin","serr�n"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(50);
  SetMaterial(M_MADERA);
}
