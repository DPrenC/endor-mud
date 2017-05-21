/***************************************************************************************
 ARCHIVO:	zendak.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Zendak, el héroe local perdido
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Zendak el guerrero","humano",100,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(500);
  SetGoChance(0);
  SetAggressive(0);
  SetName("Zendak");
  SetIds(({"zendak","Zendak","guerrero","humano"}));
  SetShort("Zendak el guerrero");
  SetLong(W("Zendak es un poderoso guerrero que luchó contra las criaturas del "
  	"bosque Cylin y conquistó todo el valle de Rhoemas estableciendo las bases "
  	"de Koek. Tiene unos músculos como dos balas de cañón y una expresión que "
  	"demuestra seguridad al tiempo que aterroriza a sus enemigos.\n"));
  AddSubDetail(({"musculos","músculos"}),"Son todo un homenaje a la anatomía humana.\n");
}
