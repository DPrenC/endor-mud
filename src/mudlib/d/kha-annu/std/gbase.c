/****************************************************************************
Fichero: /d/kha-annu/comun/pnj/gbase.c
Autor: Yalin
Fecha: 28/03/2008 17:54
Descripción: base para todos los guardias.
****************************************************************************/

#include "path.h"
inherit NPC;
inherit GUARD;


create()
{
    "*"::create();
    AddId(({"guardia","guardian","guardián","vigilante"}));
}
    