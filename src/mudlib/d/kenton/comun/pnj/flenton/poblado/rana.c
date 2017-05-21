/***************************************************************************************
 ARCHIVO:	rana.c
 AUTOR:		[z] Zomax
 FECHA:		27-01-2002
 COMENTARIOS:	Un rana para el poblado de Flenton.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("una rana verde","rana",1,GENERO_FEMENINO);
  SetHands(({({"anca derecha",1,1}),({"anca izquierda",1,1})}));
  SetIds(({"rana","rana verde"}));
  SetAlign(50);
  SetWhimpy(5);
  SetGoChance(10);
  SetWeight(5000);

  SetShort("una rana verde");
  SetLong("Es una rana muy verde y algo fea, la verdad. Tiene unos grandes ojos saltones.\n");

  AddSubDetail(({"ojo","ojos","ojos saltones"}),W("Los ojos de la rana son casi más grandes "
  	"que su cabeza.\n"));

  InitChats(5,({"La rana te mira con cara de tonta.\n",
   		"La rana salta de un lado para otro.\n",
   		"La rana te mira como si quisiera decirte algo.\n",
   		"La rana dice: ¿¡Croak!?\n",
   		"La rana sigue con la mirada atenta a un insecto.\n"}));
}

DoDamage(int dmg)
{
	InitChats(0,"");
	return ::DoDamage(dmg);
}

move(dest,method,stuff)
{
	if(method==M_GO && environment() && environment()->QueryLocate()!=dest->QueryLocate())
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
