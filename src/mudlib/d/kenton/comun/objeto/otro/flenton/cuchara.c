/***************************************************************************************
 ARCHIVO:	cuchara.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Cuchara normal y corriente
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"cuchara"}));
  SetAds(({"de madera"}));
  SetValue(5);
  SetWeight(50);
  SetShort("una cuchara");
  SetLong("Es una cuchara de madera. Es algo pequeña y no tiene ningun "
  	"adorno especial.\n");
}
