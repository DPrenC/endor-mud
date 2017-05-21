/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
  
  SetStandard("Bertur","humano",10+random(3),GENERO_MASCULINO);
  SetShort("Bertur el feliz tendero");
  SetLong(W("Es un rechoncho humano de aspecto feliz y risueño que siempre "
  "tiene una sonrisa en su cara.\n"));
  SetIds(({"Bertur","bertur","humano","tendero","feliz tendero","feliz bertur"}));
  Set(P_CANT_LURE,1);
  SetAlign(400);
  InitChats(2,({
  	"Bertur sonríe.\n",
	"Bertur te sonríe y te pregunta amablemente: '¿Desea algo?'\n",
	"Bertur coge un pedazo de pan duro y lo tira a la basura.\n",
	"Bertur coge un dulce y se lo come plácidamente.\n"}));
}
