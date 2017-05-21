/***************************************************************************************
 ARCHIVO:	jabali.c
 AUTOR:		[k] Korsario
 FECHA:		28-10-1998
 COMENTARIOS:	Un jabalí
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un jabalí","jabali",6+random(6),GENERO_MASCULINO);
  SetHands(({({"sus colmillos",1,15})}));
  SetIds(({"jabali","jabalí"}));
  SetAC(10);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(6);
  SetWeight(20000);
  SetHP(QueryMaxHP());

  SetShort("un jabalí");
  SetLong("Ves un jabalí de los bosques. Está buscando comida, rastreando "
  	"por su más preciado manjar, unas setas que sólo se dan en esta parte "
  	"del bosque.\n");

  InitChats(5,"El jabalí gruñe y escarba en la tierra.\n",
	      "El jabalí te mira desconfiado.\n");
  InitAChats(5,"El jabalí lanza un agudo y molesto chillido.\n");
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="empalizada de flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
