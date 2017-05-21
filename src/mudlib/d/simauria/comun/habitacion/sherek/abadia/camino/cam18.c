/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam18.c
Autor: Yalin
Fecha: 04/07/2009 23:07
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Aqu� el camino presenta una mayor inclinaci�n, salvando el �ltimo "
        "tramo abrupto antes de al canzar la cima.\nDesde tu posici�n puedes ver ya el front�n del "
        "imponente edificio de la abad�a, al norte, mientras que hacia el sur, el camino se pierde en "
        "direcci�n al valle.\n");
    AddExit("norte", SHERAB("camino/meseta"));
    AddExit("sur", SHERAB("camino/cam17"));
}
