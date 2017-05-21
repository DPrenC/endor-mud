/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/nagor.c
Autor: Yalin.
Fecha: 27/10/2007 18:08:27
Descripción: Herrero de Zarkam.
********************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <guild.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Nagor","orco",([ GC_LUCHADOR:20 ]),GENERO_MASCULINO);
    SetName("Nagor");
    SetShort("Nagor, el herrero");
    SetLong("Nagor es un orco más bruto de lo habitual. Tal vez porque esto le da cierta "
        "facilidad para deformar metales a martillazos, cuando tuvo que retirarse de los "
        "campos de batalla por perder un pie, se dedicó a trabajar como herrero.\n");
    AddId(({"nagor","Nagor","herrero","orco"}));
    AddItem("/std/weapon",REFRESH_REMOVE,([
        P_WEAPON_TYPE:WT_MAZA,
        P_WC:12,
        P_SIZE:P_SIZE_MEDIUM,
        P_MATERIAL:M_HIERRO,
        P_IDS:({"martillo","martillo pesado"}),
        P_SHORT:"un martillo pesado",
        P_LONG:"Es un enorme martillo de herrero.\n",
        P_GENDER:GENERO_MASCULINO,
        P_NOSELL:1,
        P_NUMBER_HANDS:2
    ]),SF(wieldme));
    Set(P_CANT_LURE,1);
}
