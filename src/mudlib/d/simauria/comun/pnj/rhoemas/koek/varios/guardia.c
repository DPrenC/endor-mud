/***************************************************************************************
 ARCHIVO:	guardia.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Guardia de gala de Koek
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("un guardia","humano",20+random(11),GENERO_MASCULINO,GC_LUCHADOR);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetAds(({"un","el"}));
  SetIds(({"guardia","humano"}));
  SetShort("un guardia");
  SetLong(W("Es uno de los guardias de gala que protegen los lugares "
  	"importantes de Koek y cuidan de que todo esté en orden. Tiene "
  	"un aspecto impecable con el uniforme y parece muy amable, por "
  	"lo menos hasta que alguien hace algo que no debe.\n"));

  InitChats(4,({"El guardia dice: Será mejor que ni lo pienses.\n",
  		 "El guardia dice: Si tienes algo que confesar, adelante.\n",
		 "El guardia te mira con desconfianza.\n",
		 "El guardia te hace saber que te vigila.\n"}));

  InitAChats(5,"[52m¡Hombre mira!, ¡Un voluntario para probar nuestra cárcel!.[0m\n");

  AddItem(RHOEWEA("koek/guardia/espada"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/guardia/botas"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/guardia/casco"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/guardia/casaca"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/guardia/escudo"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/guardia/guantes"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/guardia/pantalones"),REFRESH_REMOVE,SF(wearme));
}
