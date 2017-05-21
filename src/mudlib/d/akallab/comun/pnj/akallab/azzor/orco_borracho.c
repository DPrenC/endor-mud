/****************************************************************************
Fichero: orco_borracho.c
Autor: Kastwey
Fecha: 06/12/2005
Descripción: Un orco borracho, en la taberna de Sally la gorda.
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;

public create()
{
    ::create();
    SetStandard("un orco","orco",20 + random(15),GENDER_MALE);
    AddId(({"agricultor","orco_borracho"}));
    SetLong("Es un orco de porte rudo, tal vez un campesino de la vega que "
            "pasa aquí sus horas de descanso bebiendo y enredando. No va "
            "especialmente limpio, de su cuerpo emana un olor acre y su ropa "
            "está sucia y deteriorada.\n");

    SetSmell("El orco desprende un olor a sudor rancio. Muy desagradable, por "
             "decirlo suavemente.\n");

    SetAlcohol(150);
}






