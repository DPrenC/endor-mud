/*****************************************************************************************
 ARCHIVO:       bosque70.c
 AUTOR:         Ztico
 FECHA:         06-04-2005
 DESCRIPCI�N:   Bosque de las Dr�adas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_DRIADAS;

create()
{
    if(::create()) return 1;

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque74.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque67.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque71.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque69.c"));
}
