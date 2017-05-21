/**************************************************************************
fichero: perneras.c
Autor: Riberales
Creación: 12/1/06
Descripción: Unas perneras de mt.
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
    SetLong("Son unas perneras hechas de mithril extraído de las minas "
            "enanas. En ambas piezas observas el símbolo del reino de "
            "Kha-annu.\n");

    AddSubDetail(({"simbolo","símbolo","signo"}),
                   "Se trata del símbolo del pueblo enanil de Kha-annu.\n");

    SetIds(({"armadura","perneras","perneras de mithril"}));
    Set(P_GENDER,GENDER_FEMALE);
    Set(P_NUMBER,NUMBER_PLURAL);
}
