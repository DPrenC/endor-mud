/***************************************************************************************
 ARCHIVO:		peregrino.c
 AUTOR:		[z] Zomax
 FECHA:		10-01-2002
 COMENTARIOS:	Un peregrino que va al templo a rezar
 MODIFICACION:	11-05-2003 Bajo nivel.
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un peregrino","humano",([GC_NINGUNO: 13+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(10);
  SetAggressive(0);
    SetCitizenship("seri");
  SetAds(({"un","el"}));
  SetIds(({"peregrino","humano"}));
  SetGoChance(0);
  SetShort("un peregrino");
  SetLong(W("Es un peregrino que ha venido de lejos para poder rezar a la diosa "
    "Xaenetia en su templo. Está muy concentrado rezando y no quiere que le "
    "molesten.\n"));
  InitAChats(8,({"  [36mUn peregrino grita: ¡Has perturbado mis rezos, lo pagarás caro, infiel![0m\n"}));

  AddItem(RHOEWEA("koek/peregrino/daga"),REFRESH_REMOVE,	SF(wieldme));
  AddItem(RHOEARM("koek/peregrino/botas"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("koek/peregrino/tunica"),REFRESH_REMOVE,	SF(wearme));
}


