/***************************************************************************************
 ARCHIVO:	tinte_purpura.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Tínte púrpura para tintar seda especial.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("tinte púrpura");
  SetLong(W("Unos polvos de color púrpura espectacularmente intenso. No parecen muy "
 	"comunes y para conseguir tanta intensidad deben haber tardado mucho en "
 	"fabricarlos.\n"));
  SetIds(({"polvos","tinte","tinte purpura","tinte púrpura"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(50);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
