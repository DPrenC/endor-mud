/*****************************************************************************************
 ARCHIVO:       bosque68.c
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

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque72.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque65.c"));
    AddExit("este", HAB_BOSQUE_DRIADAS("bosque69.c"));

    AddItem(PNJ_VALMAR("driada.c"), REFRESH_DESTRUCT, 1);
}
