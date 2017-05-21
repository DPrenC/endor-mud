/***************************************************************************************
 ARCHIVO:	pluma.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Una pluma de pavo real
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetAds(({"multicolor"}));
  SetValue(3);
  SetWeight(5);

  SetShort("una pluma");
  SetLong("Es una multicolor pluma de la cola de un pavo real.\n");
}
