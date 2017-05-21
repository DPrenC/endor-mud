/***************************************************************************************
 ARCHIVO:	escama.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Una escama de dragón negro que genera oscuridad
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escama"}));
  SetAds(({"negra"}));
  SetValue(0);
  SetWeight(50);
  SetBright(-10);

  SetShort("una escama negra");
  SetLong("Una escama de un material negro muy duro. Es de un negro "
  	"tan intenso, que parece emanar oscuridad.\n");
}
