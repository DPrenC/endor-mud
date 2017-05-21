/*****************************************************************************************
 ARCHIVO:       bosque79.c
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

    AddExit("norte", HAB_BOSQUE_SENDERO("senderoO15.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque75.c"));
    AddExit("oeste", HAB_BOSQUE_DRIADAS("bosque78.c"));
    AddExit("sureste", HAB_BOSQUE_DRIADAS("bosque76.c"));

    AddItem(PNJ_VALMAR("driada.c"), REFRESH_DESTRUCT, 1);
}
