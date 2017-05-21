/****************************************************************************
Fichero: /d/kha-annu/comun/pnj/base.c
Autor: Yalin
Fecha: 28/03/2008 17:54
Descripción: base para todos los pnj enanos.
****************************************************************************/

#include "path.h"
inherit NPC;


create()
{
    ::create();
    AddId(({"enano"}));
    SetCitizenship("kha-annu");
}
    