/***************************************************************************************
 ARCHIVO:	atizador.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Un atizador
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESGRIMA,3,P_SIZE_MEDIUM,M_HIERRO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"atizador"}));
  SetShort("un atizador");
  SetLong(W("Es un atizador, un palo de hierro acabado en punta para remover las "
  	"brasas.\n"));
}
