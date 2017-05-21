/****************************************************************************
Fichero: tucan.c
Autor: Riberales
Fecha: 28/02/2006
Descripción: Un tucán.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un tucán","tucán",3+random(3),GENDER_MALE);
    SetShort("un tucán");
    SetLong("Se trata de una ave de poco más de medio metro, con un plumaje "
            "negro y algo paticorta. Su pico es largo y estrecho, por lo que "
            "no dudas en absoluto de que sea un arma punzante bastante "
            "efectiva.\n");

    SetIds(({"tucan","tucán","ave","pajaro","pájaro"}));

    SetHands(({({"el pico",DT_PIERCE,3})}));


    InitChats(3,({"El tucán alza el vuelo y vuelve a posarse.\n"}));
}
