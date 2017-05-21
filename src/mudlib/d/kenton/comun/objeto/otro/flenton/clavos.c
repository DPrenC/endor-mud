/***************************************************************************************
 ARCHIVO:	clavos.c
 AUTOR:		[z] Zomax
 FECHA:		21-01-2002
 COMENTARIOS:	Unos clavos para clavar.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetValue(100);
  SetWeight(500);
  SetIds(({"clavo","clavos"}));

  SetShort("unos clavos");
  SetLong("Son unos clavos de hierro de 5 cm de largo.\n");
}
