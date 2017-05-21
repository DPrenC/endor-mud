/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/caminocem.c
Autor: Lug y Yalin
Fecha: 16/08/2006
Descripción: pequeño caminito al cementerio de la aldea.
****************************************************************************/
#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el camino del cementerio");
    SetIntLong("Este caminito une la aldea con el cementerio, que, "
    "lógicamente está algo en las afueras.\nLa verdad es que nadie lo cuida "
    "demasiado, así que hay algunas hierbecillas que intentan sobrevivir "
    "aquí como pueden.\n");
    SetIntSmell("huele a tierra, ganado y vegetación podrida.\n");
    SetIntNoise("Oyes el piar lejano de algún pájaro.\n");
    AddDetail(({"hierba","hierbas","hierbecillas"}), "son míseras hierbas "
        "que nacen aquí, como en cualquier camino poco transitado.\n");
    AddExit("sur", SHERALD("calles/calle00"));
    AddExit("norte", SHERALD("cementerio/cementerio00"));
}
