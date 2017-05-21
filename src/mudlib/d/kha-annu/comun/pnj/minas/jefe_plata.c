/****************************************************************************
Fichero: jefe_plata.c
Autor: Riberales
Fecha: 05/02/2006
Descripci�n: El mayor de los guardias de plata de las minas.
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
    SetStandard("el guardi�n de la plata","enano",([GC_GUERRERO:103]),GENDER_MALE);

    SetShort("el guardi�n de la plata");

    SetLong("Se trata del guardi�n responsable de coordinar la segunda planta "
            "de la mina enana. Es un enano bastante joven, y algo alto para "
            "su raza. Su hacha y todo el equipo que lleva hace de �l un rudo "
            "contrincante.\n");
    Set(P_CANT_LURE,1);
    SetGoChance(0);

    AddId(({"guardian de plata","guardi�n de plata","guardian de la plata",
            "guardi�n de la plata","jefe_planta"}));

    InitChats(2,({"El enano te mira con desd�n.\n"}));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es un hacha de dos manos, de mithril y con la hoja "
                    "ba�ada en plata. Podr�a servir para destrozar "
                    "lic�ntropos, pero supones que m�s bien es un detalle "
                    "decorativo.\n",
            P_NUMBER_HANDS: 2,
            P_WC: 12]),SF(wieldme));
}

