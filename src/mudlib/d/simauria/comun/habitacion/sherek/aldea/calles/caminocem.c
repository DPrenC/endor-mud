/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/caminocem.c
Autor: Lug y Yalin
Fecha: 16/08/2006
Descripci�n: peque�o caminito al cementerio de la aldea.
****************************************************************************/
#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el camino del cementerio");
    SetIntLong("Este caminito une la aldea con el cementerio, que, "
    "l�gicamente est� algo en las afueras.\nLa verdad es que nadie lo cuida "
    "demasiado, as� que hay algunas hierbecillas que intentan sobrevivir "
    "aqu� como pueden.\n");
    SetIntSmell("huele a tierra, ganado y vegetaci�n podrida.\n");
    SetIntNoise("Oyes el piar lejano de alg�n p�jaro.\n");
    AddDetail(({"hierba","hierbas","hierbecillas"}), "son m�seras hierbas "
        "que nacen aqu�, como en cualquier camino poco transitado.\n");
    AddExit("sur", SHERALD("calles/calle00"));
    AddExit("norte", SHERALD("cementerio/cementerio00"));
}
