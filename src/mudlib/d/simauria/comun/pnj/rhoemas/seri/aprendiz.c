/***************************************************************************************
 ARCHIVO:	aprendiz.c
 AUTOR:		[z] Zomax
 FECHA:		29-12-2001
 COMENTARIOS:	Un aprendiz del templo
 MODIFICACION:	11-05-2003 Bajo nivel.
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <gremios.h>
#include <skills.h>
#include <moving.h>
#include <colours.h>

inherit NPC;
inherit GUARD;

create(){
  "*"::create();

  SetStandard("un aprendiz","humano",([GC_CR_MM: 13+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(10);
  SetAggressive(0);
  SetCitizenship("seri");
  SetGuardDefendMsg("Un aprendiz grita uniéndose al combate:\n ¡No permitiré que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetAds(({"un","el"}));
  SetIds(({"aprendiz","humano"}));
  AddSkill(HAB_VARA,100);
  SetGoChance(10);
  SetShort("un aprendiz");
  SetLong(W("Este es uno de los aprendices del templo de Seri-Solderteg. Los "
    "aprendices se dedican a mantener el templo y las tareas más aburridas "
    "a cambio de la instrucción y el alojamiento. Parece algo más fuerte que "
    "un humano normal, pero aún le falta mucho por aprender.\n"));
  InitChats(2,({"Un aprendiz dice: ¿Qué demonios haces tú aquí?\n",
      "Un aprendiz dice: Siempre me toca barrer el suelo...\n",
    "Un aprendiz dice: Dentro de nada seré discípulo...\n",
    "Un aprendiz murmura: Um... no se si todo esto vale la pena...\n",
    "Un aprendiz murmura: ¡Rayos, acabo de fregar el suelo y ya lo están "
    "pisando!.\n"}));
  InitAChats(8,({"  "TC_WHITE"Un aprendiz grita: ¡Voy a demostrarte lo que enseñan en Seri-Solderteg, infiel!"TC_NORMAL"\n",
       "  "TC_WHITE"Un aprendiz grita: ¡No saldrás vivo de aquí!"TC_NORMAL"\n"}));
  if (!random(5)) AddItem(RHOEVAR("seri/llave_cylin"),REFRESH_REMOVE);
  AddItem(RHOEWEA("seri/aprendiz/vara"),REFRESH_REMOVE,	SF(wieldme));
  AddItem(RHOEARM("seri/aprendiz/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/aprendiz/tunica"),REFRESH_REMOVE,	SF(wearme));
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

