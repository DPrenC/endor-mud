/*****************************************************************************************
 ARCHIVO:       bosque56.c
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

    AddExit("norte", HAB_BOSQUE_HADAS("bosque61.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque51.c"));
    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque50.c"));
}
