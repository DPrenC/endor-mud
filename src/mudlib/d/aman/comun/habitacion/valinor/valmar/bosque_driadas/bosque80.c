/*****************************************************************************************
 ARCHIVO:       bosque80.c
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

    AddExit("este", HAB_BOSQUE_DRIADAS("bosque81.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque77.c"));
    AddExit("suroeste", HAB_BOSQUE_DRIADAS("bosque76.c"));
}
