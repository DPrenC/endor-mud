/***************************************************************************************
 ARCHIVO:	gallina.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Una gallina
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("una gallina","gallina",2+random(5),GENERO_FEMENINO);
  SetIds(({"gallina"}));
  SetLong(W("Observas una bonita gallina de color pardo que tiene un plumaje "
  	"muy cuidado. No parece salvaje, sino de corral.\n"));
  SetSize(1);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetHands(({({"un ala",1,5}),({"un ala",1,5}),({"el pico",1,7})}));
}
