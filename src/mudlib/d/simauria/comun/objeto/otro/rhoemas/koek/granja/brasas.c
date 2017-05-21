/***************************************************************************************
 ARCHIVO:	brasas.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Una brasas. Sólo codeadas para que salga el SetDieMsg como toca.
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
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(0);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetDieMsg("#jug# ha muerto quemado al meter la mano en una chimenea encendida.");
}

init(){
  ::init();
  TP->Die();
  if (!living(environment(TO)))
  {
  	TO->remove();
  }
}