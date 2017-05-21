/***************************************************************************************
 ARCHIVO:	armero.c
 AUTOR:		[z] Zomax
 FECHA:		10-01-2002
 COMENTARIOS:	Un aprendiz armero
 MODIFICACION:	11-05-2003 Bajo nivel
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <colours.h>

inherit NPC;
inherit GUARD;

create(){
  "*"::create();

  SetStandard("un aprendiz armero","humano",([GC_NINGUNO: 13+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(10);
  SetAggressive(0);
  SetIds(({"aprendiz","humano","armero","aprendiz armero"}));
  SetShort("un aprendiz armero");
  SetLong("Este es uno de los aprendices del templo de Seri-Solderteg. Los "
    "aprendices se dedican a mantener el templo y las tareas más aburridas "
    "a cambio de la instrucción y el alojamiento. Parece algo más fuerte que "
    "un humano normal, pero aún le falta mucho por aprender.\n");
  InitAChats(8,({"  "TC_WHITE"Un aprendiz grita: ¡Voy a demostrarte lo que enseñan en Seri-Solderteg, infiel!"TC_NORMAL"\n",
       "  "TC_WHITE"Un aprendiz grita: ¡No saldrás vivo de aquí!"TC_NORMAL"\n"}));

  SetCitizenship("seri");
  SetGuardDefendMsg("El armero grita uniéndose al combate:\n ¡No permitiré que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  /*AddItem(RHOEWEA("seri/aprendiz/vara"),REFRESH_REMOVE,	SF(wieldme));*/
  AddItem(RHOEARM("seri/aprendiz/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/aprendiz/tunica"),REFRESH_REMOVE,	SF(wearme));
}
