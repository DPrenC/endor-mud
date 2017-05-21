/****************************************************************************
Fichero: hacha_romli.c
Autor: Riberales
Fecha: 24/02/2006
Descripción: El hacha de Romli
****************************************************************************/


#include "path.h"
#include <combat.h>
#include <properties.h>
#define MIN_LEVEL 50

inherit WEAPON;

public varargs mixed ChkEquip(object liv, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
    if (!liv || !query_once_interactive(liv) || liv->QueryGuildLevel() >= MIN_LEVEL)
    // se da el control a la función del propio weapon
    {
        return ::ChkEquip(liv, weapon, flags);
    }
    // no se puede empuñar
    return "Este hacha es demasiado peligrosa para que puedas empuñarla. Deberás "
           "ser al menos de nivel " + to_string(MIN_LEVEL) + " para poder usarla.\n";
}

create()
{
    if (!clonep(TO)) return;
    ::create();

    SetStandard(WT_HACHA,15,P_SIZE_MEDIUM,M_MITHRIL);
    SetShort("un hacha de mithril");
    SetLong("Es una típica hacha enana, a dos manos, y parece que bastante "
            "mortífera, por el filo y el tamaño de su hoja. Está fabricada "
            "con el mithril que los mismos enanos han extraído de sus minas, "
            "y decorada con runas de oro.\n");


    SetNumberHands(2);
    SetWeight(7999);
    SetIds(({"hacha","hacha de mithril","hacha enana","hacha mithril"}));
}

