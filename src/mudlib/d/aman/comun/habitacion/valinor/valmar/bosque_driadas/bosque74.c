/*****************************************************************************************
 ARCHIVO:       bosque74.c
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

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque77.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque70.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque73.c"));
    AddExit("sureste", HAB_BOSQUE_DRIADAS("bosque71.c"));
}
