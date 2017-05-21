/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
  
  SetStandard("Rilkus","humano",4+random(3),GENERO_MASCULINO);
  SetShort("Rilkus el ayudante del tendero");
  SetLong(W("Es un joven humano de aspecto enclenque y despierto. Parece algo "
  "nervioso e impaciente.\n"));
  SetIds(({"Rilkus","rilkus","humano","tendero","ayudante","ayudante del tendero","joven"}));
  Set(P_CANT_LURE,1);
  SetAlign(200);
  InitChats(5,({
	"Rilkus mira a todas partes nervioso.\n",
	"Rilkus murmura intranquilo: ¿Donde estará?\n",
	"Rilkus te mira nervioso.\n",
	"Rilkus se frota las manos nerviosamente.\n"}));
}
