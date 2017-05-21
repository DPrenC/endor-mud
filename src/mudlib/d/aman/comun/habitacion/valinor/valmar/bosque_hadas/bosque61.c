/*****************************************************************************************
 ARCHIVO:       bosque61.c
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

    AddExit("noroeste", HAB_BOSQUE_HADAS("bosque62.c"));
    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque55.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque56.c"));
}
