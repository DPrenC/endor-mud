/**************************************************************************
fichero: perneras.c
Autor: Riberales
Creaci�n: 12/1/06
Descripci�n: Unas perneras de mt.
**************************************************************************/




#include "path.h"
#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create()
{
    ::create();

    SetStandard(AT_GREBAS,5,P_SIZE_MEDIUM,M_MITHRIL);

    SetShort("unas perneras");
    SetLong("Son unas perneras hechas de mithril extra�do de las minas "
            "enanas. En ambas piezas observas el s�mbolo del reino de "
            "Kha-annu.\n");

    AddSubDetail(({"simbolo","s�mbolo","signo"}),
                   "Se trata del s�mbolo del pueblo enanil de Kha-annu.\n");

    SetIds(({"armadura","perneras","perneras de mithril"}));
    Set(P_GENDER,GENDER_FEMALE);
    Set(P_NUMBER,NUMBER_PLURAL);
}
