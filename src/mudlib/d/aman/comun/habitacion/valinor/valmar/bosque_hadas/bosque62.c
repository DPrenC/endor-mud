/*****************************************************************************************
 ARCHIVO:       bosque62.c
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

    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque59.c"));
    AddExit("sureste", HAB_BOSQUE_HADAS("bosque61.c"));
}
