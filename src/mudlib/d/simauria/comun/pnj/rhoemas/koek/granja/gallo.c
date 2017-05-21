/***************************************************************************************
 ARCHIVO:	gallo.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un gallo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un gallo","gallo",3+random(5),GENERO_MASCULINO);
  SetIds(({"gallo"}));
  SetLong(W("Es un gallo. Tiene una bonita y llamativa cresta roja en la cabeza, y "
  	"se comporta como si fuera el amo del corral.\n"));
  AddSubDetail(({"cresta"}),W("Sin duda es un gallo, y te atreverías a decir que es "
  	"el gallo del corral.\n"));
  SetSize(1);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetHands(({({"un ala",1,5}),({"un ala",1,5}),({"el pico",1,7})}));
}
