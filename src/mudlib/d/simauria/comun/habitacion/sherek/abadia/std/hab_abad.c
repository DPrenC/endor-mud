/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/habs/abad.c
Autor: Yalin
Fecha: 15/05/2009 20:17
Descripci�n: habitaci�n del abad.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/hab");

create()
{
    ::create();
    SetIntShort("la habitaci�n del abad");
    SetIntLong(QueryIntLong()+"�sta es la de melbius.\n");
    AddExit("sur",SHERAB("novic/habs/despacho"));
}
