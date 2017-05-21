/***************************************************************************************
 ARCHIVO:	patrullero.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Patrullero de Koek
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <moving.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("un patrullero","humano",15+random(11),GENERO_MASCULINO,GC_LUCHADOR);
  SetWhimpy(0);
  SetAlign(200);
  SetGoChance(10);
  SetAggressive(0);
  SetAds(({"un","el"}));
  SetIds(({"patrullero","humano"}));
  SetShort("un patrullero");
  SetLong(W("Es uno de los patrulleros que recorren Koek dia y noche para "
  	"custodiar a sus habitantes. Parece bastante capaz y no deberías "
  	"hacer nada malo en su presencia. Lleva un bonito uniforme azul "
  	"parecido al de los guardias de gala, pero no tan impecable.\n"));

  InitChats(4,({"El patrullero dice: Este es un pueblo tranquilo y queremos que siga siéndolo.\n",
  		 "El patrullero dice: Cuidado con lo que haces.\n",
		 "El patrullero dice: Si quieres confesar o entregarte adelante.\n",
		 "El patrullero dice: Si quieres confesar o entregarte adelante.\n",
		 "El patrullero dice: Aquí el crimen se castiga con la muerte o la cárcel.\n"}));

  InitAChats(5,"[52m¡Hombre mira!, ¡Un voluntario para probar nuestra cárcel!.[0m\n");

  AddItem(RHOEWEA("koek/patrullero/espada"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/patrullero/botas"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/patrullero/casco"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/patrullero/casaca"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/patrullero/escudo"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/patrullero/pantalones"),REFRESH_REMOVE,SF(wearme));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryEntrarPatrullero())
		return ::move(dest,method,stuff);
	else if(method!=M_GO)
		return ::move(dest,method,stuff);
	return ME_NO_ENTER;

}