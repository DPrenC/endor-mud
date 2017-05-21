/***************************************************************************************
 ARCHIVO:	vaca.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Una vaca
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("una vaca","vaca",8+random(5),GENERO_FEMENINO);
  SetIds(({"vaca"}));
  SetLong(W("Es una bonita vaca de color blanca con motas negras. Parece muy "
  	"feliz y bien cuidada.\n"));
  SetSize(3);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetHands(({({"pata delantera derecha",1,10}),({"pata delantera izquierda",1,10})}));
}
