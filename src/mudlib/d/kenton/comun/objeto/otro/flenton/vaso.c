/***************************************************************************************
 ARCHIVO:	vaso.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Vaso normal y corriente
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"vaso"}));
  SetAds(({"de madera"}));
  SetValue(5);
  SetWeight(100);
  SetShort("un vaso");
  SetLong("Es un vaso de madera. No tiene ningun adorno especial, es "
  	"totalmente liso.\n");
}
