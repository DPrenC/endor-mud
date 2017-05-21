/****************************************************************************
Fichero: jefe_plata.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: El mayor de los guardias de plata de las minas.
****************************************************************************/


#include "path.h"
#include <combat.h>
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("guardia_base");


public int QueryJefePlanta() { return 1; }

create()
{
    ::create();
    SetJefePlanta(1);
    SetStandard("el guardián de la plata","enano",([GC_GUERRERO:103]),GENDER_MALE);

    SetShort("el guardián de la plata");

    SetLong("Se trata del guardián responsable de coordinar la segunda planta "
            "de la mina enana. Es un enano bastante joven, y algo alto para "
            "su raza. Su hacha y todo el equipo que lleva hace de él un rudo "
            "contrincante.\n");
    Set(P_CANT_LURE,1);
    SetGoChance(0);

    AddId(({"guardian de plata","guardián de plata","guardian de la plata",
            "guardián de la plata","jefe_planta"}));

    InitChats(2,({"El enano te mira con desdén.\n"}));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es un hacha de dos manos, de mithril y con la hoja "
                    "bañada en plata. Podría servir para destrozar "
                    "licántropos, pero supones que más bien es un detalle "
                    "decorativo.\n",
            P_NUMBER_HANDS: 2,
            P_WC: 12]),SF(wieldme));
}

