/***************************************************************************************
 ARCHIVO:	serpiente.c
 AUTOR:		[k] Korsario
 FECHA:		18-09-1998
 COMENTARIOS:	Una serpiente
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("una serpiente","serpiente",5,GENERO_FEMENINO);
  SetHands(({({"los colmillos",1,2}),({"la cola",1,1})}));
  SetIds(({"serpiente"}));
  SetStr(15);
  SetCon(20);
  SetDex(10);
  SetAlign(-100);
  SetWhimpy(0);
  SetGoChance(5);
  SetWeight(1500);
  SetHP(QueryMaxHP());

  SetShort("una serpiente");
  SetLong(W("Una serpiente común de los pantanos. Es bastante grande y de color "
  	"verdoso, con manchas amarillas y negras.\n"));

  InitAChats(5,({"Shhhssshh, Shhhssshh.\n"}));
  InitAChats(5,({"Shhhhsshh, Shhhsshhh.\n",
  	         "La serpiente trata de morderte con sus afilados colmillos.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
