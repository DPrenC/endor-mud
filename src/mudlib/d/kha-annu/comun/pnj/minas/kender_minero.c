/****************************************************************************
Fichero: kender_minero.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Un kender bambando por las minas.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

create()
{
    ::create();
    seteuid(getuid());

    SetStandard("un kender","kender",([GC_NINGUNO:35+random(10)]),GENDER_MALE);

    SetLong("Observas al kender con precauci�n ya que es conocida su "
            "afici�n por 'lo ajeno'. No para de mirar de un lugar a otro, "
            "pues su estancia seguramente no ser� muy aprobada por el "
            "pueblo enanil.\n");


    SetIds(({"kender","ladron","ladronzuelo","ladr�n"}));
    SetGoChance(55);
    AddWalkZones(HAB_MINAS(""));
    SetWhimpy(25);
    AddItem(ARMA_MINAS("pico"),REFRESH_REMOVE,SF(wieldme));


    InitChats(4,({"El kender se r�e.\n","El kender te mira y sonr�e.\n"}));
}




