/****************************************************************************
Fichero: jefe_hierro.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: El mayor de los guardias de hierro de las minas.
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
    SetStandard("el guardián del hierro","enano",([GC_GUERRERO: 95]),GENDER_MALE);

    SetShort("el guardián del hierro");

    SetLong("Se trata del enano máximo responsable de la primera planta, de "
            "su seguridad y de los guardias que la patrullan. No parece que "
            "tuviera muchas ganas de entrar en combate, pues se le nota ya "
            "que es un veterano del hacha, pero tienes la certeza de que "
            "lo hará si es necesario.\n");
    Set(P_CANT_LURE,1);
    SetGoChance(0);

    AddId(({"guardian del hierro","guardián del hierro","jefe_planta"}));

    InitChats(2,({"El enano te mira.\n"}));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es un hacha de dos manos, de mithril y sin ningún tipo "
                    "de aderezo. La utilizan los responsables de las minas "
                    "enanas, por lo que supones que ha de ser un buen "
                    "arma.\n",
            P_NUMBER_HANDS: 2,
            P_WC: 11]),SF(wieldme));
}

