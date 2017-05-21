/***************************************************************************************
 ARCHIVO:	plato.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Plato normal y corriente
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"plato"}));
  SetAds(({"de madera"}));
  SetValue(5);
  SetWeight(100);
  SetShort("un plato");
  SetLong("Es un plato de madera. No tiene ningun adorno especial, es "
  	"totalmente liso. Tiene forma ovalada.\n");
}
