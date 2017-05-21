/*****************************************************************************************
 ARCHIVO:       bosque71.c
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

    AddExit("noroeste", HAB_BOSQUE_DRIADAS("bosque74.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque70.c"));

    AddItem(PNJ_VALMAR("driada.c"), REFRESH_DESTRUCT, 1);
}
