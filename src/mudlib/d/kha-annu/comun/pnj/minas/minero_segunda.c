/****************************************************************************
Fichero: minero_segunda.c
Autor: Riberales
Creación: 7/11/05
Descripción: El enano que pasea por el segundo piso.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("minero_base");

create()
{
    ::create();




    SetStandard("un enano minero","enano",([GC_LUCHADOR:22+random(7)]),GENDER_MALE);
    SetLong(SF(descripcion_larga));
    SetGoChance(85);
    AddWalkZones(HAB_SEGUNDA_MINAS(""));


    AddItem(ARMA_MINAS("pico"),REFRESH_REMOVE,SF(wieldme));
    AddItem(PROT_MINAS("casco_minero"),REFRESH_REMOVE,SF(wearme));

}

