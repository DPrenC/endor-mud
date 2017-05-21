/****************************************************************************
Fichero: troll_noche.c
Autor: Ratwor
Fecha: 16/08/2007
Descripción: un nuevo troll para la cueva de marhalt.
este sólo se ve por la noche por el desfiladero
****************************************************************************/

#include <properties.h>
#include "./path.h"
#include <gremios.h>
#include <nightday.h>
inherit NPC;

create() {
    ::create();
    SetStandard("un troll", "troll",([ GC_LUCHADOR: 45+d6()]),GENDER_MALE);
    SetShort("un troll de las cavernas");
    SetLong("Es una criatura enorme y verrugosa de piel verde. Sus ojos profundos "
    "miran con desprecio y maldad. Sus enormes garras le bastan para defenderse, "
    "pues su simple presencia es suficiente para intimidar.\n");
    SetGoChance(60);
    AddWalkZones(({MARH("cueva"), CAMINOS "/gremio/"}));
    SetAggressive(1);
    SetSmell("Huele horriblemente mal.\n");
}


init(){
    ::init();
    if (NIGHTDAY->QueryState() != ND_NIGHT)
    {
        /* 2008-06 Khelben
           Ponemos el sethidden(1) para que el bicho no sea visible en caso de que vayamos a cargarnoslo
           Ponemos el setaggressive(0) para que no moleste
        */
    	  SetAggressive(0);
    	  SetInvis(1);
        SetHidden(1000);
        foreach(object inv:all_inventory())
        {
            if (inv) {
               inv->remove();
               destruct(inv);
            }
        }
        /* 2008-06 Khelben
           Metemos el remove en un call_out
           Si ponemos el remove directamente, el init no termina, y eso no le
           mola al master.c
        */
        call_out("remove",0);
    }

}