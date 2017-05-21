/**************************************************************************
fichero: espada_murallas.c
Autor: Tagoras
Creaci�n: 28/02/2009
Descripci�n: Una espada para los enanos del centro
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
    SetLong("Es una espada de hoja larga y muy afilada. La empu�adura est� forjada delicadamente y aparenta la cabeza de un le�n.\n");
}
