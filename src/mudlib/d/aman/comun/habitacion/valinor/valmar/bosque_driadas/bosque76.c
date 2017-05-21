/*****************************************************************************************
 ARCHIVO:       bosque76.c
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

    AddExit("noreste", HAB_BOSQUE_DRIADAS("bosque80.c"));
    AddExit("noroeste", HAB_BOSQUE_DRIADAS("bosque79.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque73.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque77.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque75.c"));
}
