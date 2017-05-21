/**************************************************************************
fichero: casco_minero.c
Autor: Riberales
Creación: 28/10/05
Descripción: Un casco de minero.
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
            "para evitar las contusiones en la cabeza por algún "
            "desprendimiento o golpe en la mina.\n");

    SetIds(({"casco","armadura","casco minero"}));
}
