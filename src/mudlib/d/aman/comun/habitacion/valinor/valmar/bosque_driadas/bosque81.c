/*****************************************************************************************
 ARCHIVO:       bosque81.c
 AUTOR:         Ztico
 FECHA:         06-04-2005
 DESCRIPCIÓN:   Bosque de las Dríadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_DRIADAS;

create()
{
    if(::create()) return 1;

    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque80.c"));
    AddExit("suroeste", HAB_BOSQUE_DRIADAS("bosque77.c"));

    AddItem(PNJ_VALMAR("driada.c"), REFRESH_DESTRUCT, 3);
}
