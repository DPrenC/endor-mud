/***************************************************************************************
 ARCHIVO:	martillo.c
 AUTOR:		[z] Zomax
 FECHA:		21-01-2002
 COMENTARIOS:	Un martillo para vender en la herrería
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(250);
  SetWeight(2500);
  SetIds(({"martillo","martillo de hierro"}));

  SetShort("un martillo");
  SetLong("Es un contundente martillo de hierro muy pesado.\n");
}
