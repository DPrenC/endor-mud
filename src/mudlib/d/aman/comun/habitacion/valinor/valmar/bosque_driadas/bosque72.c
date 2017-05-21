/*****************************************************************************************
 ARCHIVO:       bosque72.c
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

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque75.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque73.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque68.c"));
}
