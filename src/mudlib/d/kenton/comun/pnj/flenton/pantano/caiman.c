/***************************************************************************************
 ARCHIVO:	caiman.c
 AUTOR:		[k] Korsario
 FECHA:		13-11-1998
 COMENTARIOS:	Un caim�n
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un caim�n","caiman",8,GENERO_MASCULINO);
  SetHands(({({"los colmillos",1,2}),({"la cola",1,1})}));
  SetIds(({"caiman","caim�n","cocodrilo"}));
  SetStr(30);
  SetCon(25);
  SetDex(10);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(0);
  SetWeight(50000);
  SetHP(QueryMaxHP());

  SetShort("un caim�n");
  SetLong("Un gran caim�n de los pantanos. Una de las temibles amenazas "
  	"del pantano de la muerte. Es de grandes dimensiones y sus terribles "
  	"fauces partirian el tronco de un �rbol en dos facilmente.\n");

  InitChats(5,({"Ves unas burbujas que salen de las aguas estancadas.\n"}) );
  InitAChats(5,({"El caim�n trata de derribarte con su cola.\n",
   		  "El caim�n trata de morderte con sus afiladas y temibles fauces.\n"}));

}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
