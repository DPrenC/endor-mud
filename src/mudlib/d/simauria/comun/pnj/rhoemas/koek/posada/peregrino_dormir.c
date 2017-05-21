/***************************************************************************************
 ARCHIVO:	peregrino_dormir.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Peregrino durmiendo
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

  InitChats(4,({"Un peregrino ronca como un condenado: GROooooooooooooooaaaaAAAAAJJJJJJ.\n",
  		"Un peregrino se mueve como si estuviera luchando en sueños.\n",
		"Un peregrino se acuesta y se pone a dormir.\n",
		"Un peregrino se despierta.\n"}));

  AddItem(RHOEWEA("koek/peregrino/daga"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/peregrino/botas"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/peregrino/tunica"),REFRESH_REMOVE,SF(wearme));
}
