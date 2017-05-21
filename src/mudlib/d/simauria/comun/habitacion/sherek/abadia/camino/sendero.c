/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/sendero.c
Autor: Yalin
Fecha: 29/07/2009 11:47
Descripci�n: plataforma de acceso a la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/ext");

create ()
{
    ::create();
    SetIntShort("un corto sendero");
    SetIntLong("Te hallas en medio de un peque�o sendero de graba que discurre entre setos de "
        "cipr�s, uniendo la meseta del sur con la explanada que da acceso a la abad�a.\n");
    AddExit("norte", SHERAB("frente/varios/expl_c"));
    AddExit("sur", SHERAB("camino/meseta"));
}
