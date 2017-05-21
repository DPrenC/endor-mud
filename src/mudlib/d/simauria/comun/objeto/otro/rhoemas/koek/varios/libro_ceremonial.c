/***************************************************************************************
 ARCHIVO:	libro_ceremonial.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	El libro para recuperar en el quest.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("el libro ceremonial de Seri-Solderteg");
  SetLong(W("Es un precioso libro de rezos con cubierta de oro forjada con gran maestría. "
  	"A los lados tiene unos bonitos cierres parece que mágicos que solo pueden abrirse "
  	"en la ceremonia del templo de Seri-Solderteg. Parace que no podrás leerlo.\n"));
  SetIds(({"libro","libro ceremonial","libro ceremonial de Seri-Solderteg"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(500);
  SetValue(0);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
