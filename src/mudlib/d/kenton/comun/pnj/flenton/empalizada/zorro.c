/***************************************************************************************
 ARCHIVO:	zorro.c
 AUTOR:		[k] Korsario
 FECHA:		28-10-1998
 COMENTARIOS:	Un zorro
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;


create(){
  ::create();
  SetStandard("un zorro","zorro",2+random(4),GENERO_MASCULINO);
  SetHands(({({"su garra izquierda",1,5}),({"su garra derecha",1,5}),({"sus afilados dientes",1,10})}));
  SetIds(({"zorro"}));
  SetAlign(0);
  SetWhimpy(20);
  SetGoChance(10);
  SetWeight(10000);
  SetHP(QueryMaxHP());

  SetShort("un zorro");
  SetLong("Ves un zorro. Es un animal de pelaje abundante. Su orejas "
  	"estan siempre alertas, acechando una posible presa o cualquier "
  	"peligro.\n");

  InitChats(5,"El zorro te mira con desconfianza.\n",
  	      "El zorro uele el ambiente, buscando un rastro.\n");
  InitAChats(5,"El zorro ensenya sus dientes.\n");
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="empalizada de flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
