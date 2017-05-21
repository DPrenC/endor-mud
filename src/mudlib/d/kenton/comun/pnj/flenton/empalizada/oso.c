/***************************************************************************************
 ARCHIVO:	oso.c
 AUTOR:		[k] Korsario
 FECHA:		28-10-1998
 COMENTARIOS:	Un oso
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
   ::create();
  SetStandard("un oso","oso",10+random(14),GENERO_MASCULINO);
  SetHands(({({"su garra izquierda",1,15}),({"su garra derecha",1,15}),({"sus afilados dientes",1,10})}));
  SetIds(({"oso","gran oso"}));
  SetAC(10);
  SetAlign(0);
  SetWhimpy(10);
  SetGoChance(5);
  SetWeight(200000);
  SetHP(QueryMaxHP());

  SetShort("un gran oso");
  SetLong("Ves un gran oso. Es un animal de gran embergadura y fortaleza. "
  	"Tiene unos dos metros de altura. Y sus brazos son poderosos y acaban "
  	"en afiladas y mortales garras.\n");

  InitChats(4,"El oso le gruñe a una abeja.\n",
  	      "El oso se lame una pata.\n",
  	      "El oso se queda dormido.\n");
  InitAChats(5,"El oso se alza en pie en actitud feroz.\n",
  	       "El oso gruñe con furia.\n");
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="empalizada de flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
