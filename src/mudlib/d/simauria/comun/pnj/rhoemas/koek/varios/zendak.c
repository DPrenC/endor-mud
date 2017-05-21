/***************************************************************************************
 ARCHIVO:	zendak.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Zendak, el h�roe local perdido
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
  SetLong(W("Zendak es un poderoso guerrero que luch� contra las criaturas del "
  	"bosque Cylin y conquist� todo el valle de Rhoemas estableciendo las bases "
  	"de Koek. Tiene unos m�sculos como dos balas de ca��n y una expresi�n que "
  	"demuestra seguridad al tiempo que aterroriza a sus enemigos.\n"));
  AddSubDetail(({"musculos","m�sculos"}),"Son todo un homenaje a la anatom�a humana.\n");
}
