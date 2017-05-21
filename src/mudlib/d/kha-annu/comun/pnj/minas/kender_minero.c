/****************************************************************************
Fichero: kender_minero.c
Autor: Riberales
Creación: 28/10/05
Descripción: Un kender bambando por las minas.
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

    SetLong("Observas al kender con precaución ya que es conocida su "
            "afición por 'lo ajeno'. No para de mirar de un lugar a otro, "
            "pues su estancia seguramente no será muy aprobada por el "
            "pueblo enanil.\n");


    SetIds(({"kender","ladron","ladronzuelo","ladrón"}));
    SetGoChance(55);
    AddWalkZones(HAB_MINAS(""));
    SetWhimpy(25);
    AddItem(ARMA_MINAS("pico"),REFRESH_REMOVE,SF(wieldme));


    InitChats(4,({"El kender se ríe.\n","El kender te mira y sonríe.\n"}));
}




