/***************************************************************************************
 ARCHIVO:	serrin.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Un poco de serrín
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un poco de serrín");
  SetLong("Es un montón de serrín de lo más normal. Esto en su día fue un árbol.\n");
  SetIds(({"serrin","serrín"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(50);
  SetMaterial(M_MADERA);
}
