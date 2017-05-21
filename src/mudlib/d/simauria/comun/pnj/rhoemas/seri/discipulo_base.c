/***************************************************************************************
 ARCHIVO:	discipulo_base.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Un disc�pulo del templo
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

  SetStandard("un disc�pulo","humano",([GC_CB_MR: 18+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(0);
  SetAggressive(random(2));
  SetCitizenship("seri");
  SetGuardDefendMsg("Un discipulo grita uni�ndose al combate:\n �No permitir� que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetAds(({"un","el"}));
  SetIds(({"discipulo","disc�pulo","humano"}));
  AddSkill(HAB_DAGA,100);
  AddSkill(HAB_EXPERTISE,100);
  AddSkill(HAB_XARMAS,100);
  SetGoChance(25);
  SetShort("un disc�pulo");
  SetLong(W("Miras a uno de los disc�pulos del templo. Es un humano no muy "
    "corpulento, pero sin duda fuerte, que puede darte m�s de un disgusto. "
    "Tal y como mueve las manos dir�as que es muy h�bil con las dagas.\n"));
  InitChats(4,({"Un disc�pulo dice: Siempre me corto en los entrenamientos...\n",
      "Un disc�pulo dice: No te muevas, �tienes permiso para estar aqu�?\n",
    "Un disc�pulo murmura: �D�nde estar� mi maestro?\n",
    "Un disc�pulo murmura: Um... �qu� querr� este?.\n",
    "Un disc�pulo murmura: Dentro de nada me toca el entrenamiento... pero estoy cansado...\n"}));
  InitAChats(8,({"  "TC_WHITE"Un disc�pulo grita: �Acabas de cometer el error de tu vida!"TC_NORMAL"\n",
       "  "TC_WHITE"Un disc�pulo grita: �No saldr�s vivo de aqu�!"TC_NORMAL"\n"}));

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
