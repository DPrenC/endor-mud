/***************************************************************************************
 ARCHIVO:	caballito_mar.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Un caballito de mar
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"caballito"}));
  SetAds(({"disecado"}));
  SetValue(100);
  SetWeight(5);

  SetShort("un caballito de mar");
  SetLong("Es un caballito de mar disecado.\n");
}
