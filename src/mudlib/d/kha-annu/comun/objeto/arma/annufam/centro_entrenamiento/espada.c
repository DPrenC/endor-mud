/**************************************************************************
fichero: espada_murallas.c
Autor: Tagoras
Creación: 28/02/2009
Descripción: Una espada para los enanos del centro
**************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>

inherit WEAPON;

public void create()
{
    ::create();
    SetStandard(WT_ESPADA, 12, P_SIZE_GENERIC, M_HIERRO);
    SetShort("una espada");
    SetLong("Es una espada de hoja larga y muy afilada. La empuñadura está forjada delicadamente y aparenta la cabeza de un león.\n");
}
