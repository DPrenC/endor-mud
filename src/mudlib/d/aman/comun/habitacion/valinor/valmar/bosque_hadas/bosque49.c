/*****************************************************************************************
 ARCHIVO:       bosque49.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntLong(::QueryIntLong() +
        "La entrada a una pequeña gruta se abre hacia el oeste.\n");

    AddExit("este", HAB_BOSQUE_HADAS("bosque50.c"));
    AddExit("oeste", HAB_BOSQUE_HADAS("bosque48.c"));
}
