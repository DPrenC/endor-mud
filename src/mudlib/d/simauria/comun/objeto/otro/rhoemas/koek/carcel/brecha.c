/***************************************************************************************
 ARCHIVO:	brecha.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Una brecha en la cabeza... suena raro... pero el SetDieMsg no salia
 		bien si no es con esto.. en las rooms no me rula
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort();
  SetLong();
  SetIds(({""}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(0);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetDieMsg("#jug# ha muerto debido a una gran brecha en la cabeza.");
}

init(){
  ::init();
  TP->Die();
  if (!living(environment(TO)))
  {
  	TO->remove();
  }
}