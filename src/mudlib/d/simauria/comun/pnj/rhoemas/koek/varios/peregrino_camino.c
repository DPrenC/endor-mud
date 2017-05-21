/***************************************************************************************
 ARCHIVO:	peregrino_camino.c
 AUTOR:		Ratwor
 FECHA:		04-01-2002
 COMENTARIOS:	Peregrino que hace su peregrinación por el camino.
 ***************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create(){
    ::create();

    SetStandard("un peregrino","humano",([GC_MAGO:10+d6()]),GENERO_MASCULINO);
    SetWhimpy(10);
    SetGoChance(90);
    AddWalkZones(CAMINOS "/berat-rhoemas");
    AddId(({"hombre","peregrino"}));
    SetShort("un peregrino");
    SetLong("Es un peregrino que hace la peregrinación del largo camino de Rhoemas para "
    "poder ver el templo de Seri-Solderteg en la ciudad de Koek.\n");

    AddItem(RHOEWEA("koek/peregrino/daga"),REFRESH_REMOVE,SF(wieldme));
    AddItem(RHOEARM("koek/peregrino/botas"),REFRESH_REMOVE,SF(wearme));
    AddItem(RHOEARM("koek/peregrino/tunica"),REFRESH_REMOVE,SF(wearme));
    if (d4()==1)
        AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(7),"plata":d6()])]));
    if(d4()==1)
        AddItem(GOBJETO("comida/queso"), REFRESH_REMOVE);
    if(d4()==1)
        AddItem(GOBJETO("comida/mendrugo"), REFRESH_REMOVE);

}
