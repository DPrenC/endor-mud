/***************************************************************************************
 ARCHIVO:	peregrino_banyo.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Peregrino bañandose
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
  SetLong(W("Es un peregrino que ha venido de lejos para ver el templo de Seri-Solderteg. "
  	"¡Vaya! ¡Está desnudo!... no mires mucho...\n"));

  InitChats(4,({"Un peregrino se baña en una de las balsas.\n",
  		"Un peregrino se queja de que el agua está fría para su gusto.\n",
		"Un peregrino se frota la espalda.\n"}));

}
