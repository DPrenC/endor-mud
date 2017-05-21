/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/habs/abad.c
Autor: Yalin
Fecha: 15/05/2009 20:17
Descripción: habitación del abad.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/hab");

create()
{
    ::create();
    SetIntShort("la habitación del abad");
    SetIntLong(QueryIntLong()+"Ésta es la de melbius.\n");
    AddExit("sur",SHERAB("novic/habs/despacho"));
}
