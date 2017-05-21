/***************************************************************************************
 ARCHIVO:	peregrino_comedor.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Peregrino comiendo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
#define RHOEGREMIO ({GC_GUARDABOSQUE,GC_AVENTURERO,GC_GUERRERO,GC_CONJURADOR,GC_HECHICERO,GC_ASESINO,GC_CLERIGO})

create(){
  ::create();
  SetStandard("un peregrino","humano",10+random(11),GENERO_MASCULINO,RHOEGREMIO[random(sizeof(RHOEGREMIO))]);
  SetWhimpy(0);
  SetAlign(200);
  SetAggressive(0);
  SetAds(({"un","el"}));
  SetIds(({"peregrino"}));
  SetShort("un peregrino");
  SetLong("Es un peregrino que ha venido de lejos para ver el templo de Seri-Solderteg.\n");

  InitChats(4,({"Un peregrino pide más comida a gritos.\n",
  		"Un peregrino se tambalea después de beber tanta cerveza.\n",
		"Un peregrino te mira con desconfianza.\n"}));

  AddItem(RHOEWEA("koek/peregrino/daga"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/peregrino/botas"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/peregrino/tunica"),REFRESH_REMOVE,SF(wearme));
}
