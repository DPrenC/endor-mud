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
    SetStandard("el guardi�n del mithril","enano",([GC_GUERRERO:112]),GENDER_MALE);

    SetShort("el guardi�n del mithril");

    SetLong("Se trata de un guardia de la ciudad enana de Kha-annu, "
            "trasladado a las minas enanas, para coordinar la tercera y "
            "�ltima planta. Es un enano muy recio y con cara de pocos amigos. "
            "Parece ser que no le ha hecho mucha gracia que lo enviasen tan "
            "lejos de su casa, pero es conocida la lealtad del enano a su "
            "pueblo.\n");

    Set(P_CANT_LURE,1);
    SetGoChance(0);

    AddId(({"guardian de mithril","guardi�n de mithril","guardian del mithril",
            "guardi�n del mithril","jefe_planta"}));

    InitChats(2,({"Un enano gru�e.\n"}));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es un hacha de dos manos, de mithril y con la hoja "
                    "ba�ada en oro. TE parece una de las armas m�s bonitas "
                    "que nunca has visto, mas las armas no se fabrican para "
                    "que se aprecien por su est�tica.\n",
            P_NUMBER_HANDS: 2,
            P_WC: 13]),SF(wieldme));
}

