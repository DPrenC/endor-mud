/***************************************************************************************
 ARCHIVO:	lobo.c
 AUTOR:		[k] Korsario
 FECHA:		28-10-1998
 COMENTARIOS:	Un lobo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un lobo","lobo",6+random(6),GENERO_MASCULINO);
  SetHands(({({"su garra izquierda",1,10}),({"su garra derecha",1,10}),({"sus afilados dientes",1,15})}));
  SetIds(({"lobo"}));
  SetAC(10);
  SetAlign(-10);
  SetWhimpy(10);
  SetGoChance(6);
  SetWeight(10000);
  SetHP(QueryMaxHP());

  SetShort("un lobo");
  SetLong("Ves un lobo gris. Es un animal de aspecto fiero y gran "
  	"resistencia, un habitual morador de los bosques que suele cazar "
  	"en manada.\n");

  InitChats(5,"Un lobo se pone a aullar.\n",
  	      "Un lobo se pone a olisquear el ambiente.\n",
  	      "Un lobo te gruñe.\n");
  InitAChats(5,"El lobo aulla buscando la ayuda de su manada.\n",
	       "El lobo te gruñe y enseña su poderosa dentadura.\n");
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="empalizada de flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
