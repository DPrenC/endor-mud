/***************************************************************************************
 ARCHIVO:	jabali.c
 AUTOR:		[k] Korsario
 FECHA:		28-10-1998
 COMENTARIOS:	Un jabal�
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un jabal�","jabali",6+random(6),GENERO_MASCULINO);
  SetHands(({({"sus colmillos",1,15})}));
  SetIds(({"jabali","jabal�"}));
  SetAC(10);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(6);
  SetWeight(20000);
  SetHP(QueryMaxHP());

  SetShort("un jabal�");
  SetLong("Ves un jabal� de los bosques. Est� buscando comida, rastreando "
  	"por su m�s preciado manjar, unas setas que s�lo se dan en esta parte "
  	"del bosque.\n");

  InitChats(5,"El jabal� gru�e y escarba en la tierra.\n",
	      "El jabal� te mira desconfiado.\n");
  InitAChats(5,"El jabal� lanza un agudo y molesto chillido.\n");
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="empalizada de flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
