/*****************************************************************************************
 ARCHIVO:       bosque45.c
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

    AddExit("sur", HAB_BOSQUE_HADAS("bosque41.c"));
    AddExit("oeste", HAB_BOSQUE_HADAS("bosque44.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque51.c"));
}
