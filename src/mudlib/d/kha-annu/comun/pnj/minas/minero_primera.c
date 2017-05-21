/****************************************************************************
Fichero: minero_primera.c
Autor: Riberales
Creación: 28/10/05
Descripción: El enano que pasea por la primera planta.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>


inherit PNJ_MINAS("minero_base");

create()
{
    ::create();



    SetStandard("un enano minero","enano",([GC_LUCHADOR:15+random(6)]),GENDER_MALE);
    SetLong(SF(descripcion_larga));
    AddWalkZones(HAB_PRIMERA_MINAS(""));
    SetGoChance(85);


    AddItem(ARMA_MINAS("pico"),REFRESH_REMOVE,SF(wieldme));
    AddItem(PROT_MINAS("casco_minero"),REFRESH_REMOVE,SF(wearme));
}

