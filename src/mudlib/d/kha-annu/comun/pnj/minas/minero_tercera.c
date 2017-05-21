/****************************************************************************
Fichero: minero_tercera.c
Autor: Riberales
Creación: 21/12/05
Descripción: El enano que pasea por el tercer piso.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("minero_base");

create()
{
    ::create();




    SetStandard("un enano minero","enano",([GC_LUCHADOR:30+random(6)]),GENDER_MALE);
    SetLong(SF(descripcion_larga));
    SetGoChance(85);
    AddWalkZones(HAB_TERCERA_MINAS(""));


    AddItem(ARMA_MINAS("pico"),REFRESH_REMOVE,SF(wieldme));
    AddItem(PROT_MINAS("casco_minero"),REFRESH_REMOVE,SF(wearme));

}

