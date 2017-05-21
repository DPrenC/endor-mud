/***************************************************************************************
 ARCHIVO:	peregrino.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Peregrino
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <moving.h>

inherit NPC;
#include RHOEDANYO
#define RHOEGREMIO ({GC_GUARDABOSQUE,GC_AVENTURERO,GC_GUERRERO,GC_CONJURADOR,GC_HECHICERO,GC_ASESINO,GC_CLERIGO})

create(){
  ::create();
  SetStandard("un peregrino","humano",10+random(5),GENERO_MASCULINO,GC_CONJURADOR);
  SetWhimpy(0);
  SetAlign(200);
  SetGoChance(10);
  SetAggressive(0);
  SetAds(({"un","el"}));
  SetIds(({"peregrino"}));
  SetShort("un peregrino");
  SetLong("Es un peregrino que ha venido de lejos para ver el templo de Seri-Solderteg.\n");

  AddItem(RHOEWEA("koek/peregrino/daga"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/peregrino/botas"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/peregrino/tunica"),REFRESH_REMOVE,SF(wearme));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryEntrarPatrullero())
		return:: move(dest,method,stuff);
	else if(method!=M_GO)
		return ::move(dest,method,stuff);
	return ME_NO_ENTER;

}