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
    SetStandard("el guardián del mithril","enano",([GC_GUERRERO:112]),GENDER_MALE);

    SetShort("el guardián del mithril");

    SetLong("Se trata de un guardia de la ciudad enana de Kha-annu, "
            "trasladado a las minas enanas, para coordinar la tercera y "
            "última planta. Es un enano muy recio y con cara de pocos amigos. "
            "Parece ser que no le ha hecho mucha gracia que lo enviasen tan "
            "lejos de su casa, pero es conocida la lealtad del enano a su "
            "pueblo.\n");

    Set(P_CANT_LURE,1);
    SetGoChance(0);

    AddId(({"guardian de mithril","guardián de mithril","guardian del mithril",
            "guardián del mithril","jefe_planta"}));

    InitChats(2,({"Un enano gruñe.\n"}));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es un hacha de dos manos, de mithril y con la hoja "
                    "bañada en oro. TE parece una de las armas más bonitas "
                    "que nunca has visto, mas las armas no se fabrican para "
                    "que se aprecien por su estética.\n",
            P_NUMBER_HANDS: 2,
            P_WC: 13]),SF(wieldme));
}

