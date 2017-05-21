/****************************************************************************
Fichero: tucan.c
Autor: Riberales
Fecha: 28/02/2006
Descripci�n: Un tuc�n.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un tuc�n","tuc�n",3+random(3),GENDER_MALE);
    SetShort("un tuc�n");
    SetLong("Se trata de una ave de poco m�s de medio metro, con un plumaje "
            "negro y algo paticorta. Su pico es largo y estrecho, por lo que "
            "no dudas en absoluto de que sea un arma punzante bastante "
            "efectiva.\n");

    SetIds(({"tucan","tuc�n","ave","pajaro","p�jaro"}));

    SetHands(({({"el pico",DT_PIERCE,3})}));


    InitChats(3,({"El tuc�n alza el vuelo y vuelve a posarse.\n"}));
}
