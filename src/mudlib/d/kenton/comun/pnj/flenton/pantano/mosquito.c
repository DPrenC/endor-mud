/***************************************************************************************
 ARCHIVO:	mosquito.c
 AUTOR:		[k] Korsario
 FECHA:		18-09-1998
 COMENTARIOS:	Un mosquito
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un mosquito","mosquito",10,GENERO_MASCULINO);
  SetHands(({({"su afiliado estilete",1,1})}));
  SetIds(({"mosquito"}));
  SetAC(0);
  SetAlign(-25);
  SetWhimpy(0);
  SetGoChance(6);
  SetWeight(20);
  SetHP(QueryMaxHP());

  SetShort("un gran mosquito");
  SetLong(W("Un mosquito de grandes dimensiones. Su cuerpo es de color rojo, "
   	"lo cual quizás desvele sus tendencias alimenticias. Produce un molesto "
   	"zumbido con sus alas.\n"));

  InitAChats(5,({"Un mosquito produce un molesto zumbido.\n"}));
  InitAChats(5,({"El mosquito te intenta picar con su afilado estilete.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
