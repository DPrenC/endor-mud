/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/base.c
Autor: Lug y Yalin
Fecha: 08/01/2007
Descripción: npc base para todos los habitantes de la zona.
****************************************************************************/

#include "path.h"
inherit NPC;

create()
{
    ::create();
    AddId("humano");
    SetCitizenship("sherek");
}

