/**************************************************************************
fichero: casco_minero.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Un casco de minero.
**************************************************************************/




#include "path.h"
#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create()
{
    ::create();

    SetStandard(AT_CASCO,2,P_SIZE_GENERIC,M_HIERRO);

    SetShort("un casco minero");
    SetLong("Se trata de un casco que suelen utilizar los mineros de Kha-annu "
            "para evitar las contusiones en la cabeza por alg�n "
            "desprendimiento o golpe en la mina.\n");

    SetIds(({"casco","armadura","casco minero"}));
}
