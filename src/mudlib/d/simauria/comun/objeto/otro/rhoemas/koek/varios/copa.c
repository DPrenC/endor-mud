/***************************************************************************************
 ARCHIVO:	copa.c
 AUTOR:		[z] Zomax
 FECHA:		09-04-2003
 COMENTARIOS:	Una copa ceremonial.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una copa ceremonial");
  SetLong(W("Es una preciosa copa de oro con algún tipo de piedras preciosas incrustadas "
  "que no sabes reconocer. Parece obra de algún forjador enano. En la base pone que es "
  "propiedad del templo de Seri-Solderteg, en Koek.\n"));
  SetIds(({"copa","copa ceremonial"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(500);
  SetValue(500000);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
