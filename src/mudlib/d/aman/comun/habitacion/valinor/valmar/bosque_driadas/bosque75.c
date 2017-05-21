/*****************************************************************************************
 ARCHIVO:       bosque75.c
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

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque79.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque72.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque76.c"));
    AddExit("noroeste", HAB_BOSQUE_DRIADAS("bosque78.c"));

    AddItem(PNJ_VALMAR("driada.c"), REFRESH_DESTRUCT, 2);
}
