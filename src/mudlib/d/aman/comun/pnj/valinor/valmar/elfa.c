/*****************************************************************************************
 ARCHIVO:       elfo.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCIÓN:   Elfa silvana de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("una elfa", "elfo", ([GC_GUARDABOSQUE: 50 + d10()]), GENERO_FEMENINO);
    SetShort("una elfa silvana");    
    SetLong("Ante tus ojos tienes a una de las perlas de la creación. Se trata de una "
        "elfa de ojos grises como la niebla. Posee una larga cabellera de color cobrizo "
        "que contrasta de forma llamativa con la palidez de su piel. Viste con discreta "
        "elegancia una oscura capa de color verde terroso y camina descalza.\n");
    AddId(({"elfa silvana", "elfa"}));
    SetGoChance(4);
    AddWalkZones(({HAB_VALMAR("senderos/"), HAB_VALMAR("bosque_central/"),
    	             HAB_VALMAR("bosque_driadas/")}));

    AddItem(ARMOUR, REFRESH_REMOVE, SF(wearme),
        ([
            P_SHORT: "una capa élfica",
            P_LONG:  "Es una capa con sombras oscuras, de tonos verdes y terrosos.\n",
            P_ARMOUR_TYPE: AT_TUNICA,
            P_IDS: ({"capa", "capa élfica", "capa oscura", "capa verde"}),
            P_AC: 3,
            P_SIZE: P_SIZE_MEDIUM,
            P_RESET_QUALITY: 100,
            P_WEIGHT: 500,
            P_VALUE: 300
         ]));

    //Arco largo d20
    AddItem("/obj/arco.c", REFRESH_REMOVE,
        ([
             P_SHORT: "un arco de tejo",
             P_LONG: "Este arco está fabricado con la madera de un tejo de los bosques "
             	       "de Orome.\n",
             P_WC: 8,
         ]), SF(wieldme));
    AddItem("/obj/carcaj", REFRESH_REMOVE, 1);
}
