/***************************************************************************************
 ARCHIVO:	piedra.c
 AUTOR:		[o] Okkita
 FECHA:		07-11-1997
 COMENTARIOS:	Una piedra peque�a, munici�n para las hondas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"piedra","guijarro"}));
  SetAds(({"peque�a","redondeada"}));
  SetValue(1);
  SetWeight(50);

  SetShort("una piedra");
  SetLong("Es una peque�a piedra redondeada.\n");
}
