/***************************************************************************************
 ARCHIVO:	discipulo_base.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Un discípulo del templo
 MODIFICACION:	11-05-2003 Bajo nivel de pnj
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <skills.h>
#include <moving.h>
#include <colours.h>

inherit NPC;
inherit GUARD;

create(){
  "*"::create();

  SetStandard("un discípulo","humano",([GC_CB_MR: 18+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(0);
  SetAggressive(random(2));
  SetCitizenship("seri");
  SetGuardDefendMsg("Un discipulo grita uniéndose al combate:\n ¡No permitiré que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetAds(({"un","el"}));
  SetIds(({"discipulo","discípulo","humano"}));
  AddSkill(HAB_DAGA,100);
  AddSkill(HAB_EXPERTISE,100);
  AddSkill(HAB_XARMAS,100);
  SetGoChance(25);
  SetShort("un discípulo");
  SetLong(W("Miras a uno de los discípulos del templo. Es un humano no muy "
    "corpulento, pero sin duda fuerte, que puede darte más de un disgusto. "
    "Tal y como mueve las manos dirías que es muy hábil con las dagas.\n"));
  InitChats(4,({"Un discípulo dice: Siempre me corto en los entrenamientos...\n",
      "Un discípulo dice: No te muevas, ¿tienes permiso para estar aquí?\n",
    "Un discípulo murmura: ¿Dónde estará mi maestro?\n",
    "Un discípulo murmura: Um... ¿qué querrá este?.\n",
    "Un discípulo murmura: Dentro de nada me toca el entrenamiento... pero estoy cansado...\n"}));
  InitAChats(8,({"  "TC_WHITE"Un discípulo grita: ¡Acabas de cometer el error de tu vida!"TC_NORMAL"\n",
       "  "TC_WHITE"Un discípulo grita: ¡No saldrás vivo de aquí!"TC_NORMAL"\n"}));

  if (!random(4)) AddItem(RHOEVAR("seri/llave_cylin"),REFRESH_REMOVE);
  AddItem(RHOEWEA("seri/discipulo/daga"),REFRESH_REMOVE,	SF(wieldme));
  AddItem(RHOEWEA("seri/discipulo/daga"),REFRESH_REMOVE,	SF(wieldme));
  AddItem(RHOEARM("seri/discipulo/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/discipulo/tunica"),REFRESH_REMOVE,	SF(wearme));
}

public varargs int DoDamage (int dam, int type, int gentle, mixed xtras) {
  InitChats(0,({}));
  return ::DoDamage(dam, type, gentle, &xtras);
}

public varargs int move(mixed dest, int method, mixed stuff) {
  if (environment(TO) && method==M_GO && dest->QueryLocate()!=environment(TO)->QueryLocate())
    return ME_NO_ENTER;
  return ::move(dest,method,stuff);
}
