/***************************************************************************************
 ARCHIVO:	muerte_arenas.c
 AUTOR:		[z] Zomax
 FECHA:		27-01-2002
 COMENTARIOS:	Un objeto sin más para matar a un player que caiga en las arenas movedizas
 		y salga el SetDieMsg como toca.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("arenas movedizas");
  SetLong("Son unas temibles y peligrosas arenas movedizas.\n");
  SetIds(({"arena","arenas"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(0);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  SetDieMsg("#jug# ha muerto ahogado en las arenas movedizas del pantano de la muerte.");
}

init(){
  ::init();
  TP->Die();
  if (!living(environment(TO)))
  {
  	TO->remove();
  }
}
