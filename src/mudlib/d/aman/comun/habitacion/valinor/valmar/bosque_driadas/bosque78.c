/*****************************************************************************************
 ARCHIVO:       bosque78.c
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

    AddExit("este", HAB_BOSQUE_DRIADAS("bosque79.c"));
    AddExit("sureste", HAB_BOSQUE_DRIADAS("bosque75.c"));
}
