/*****************************************************************************************
 ARCHIVO:       bosque66.c
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

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque69.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque63.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque67.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque65.c"));
}
