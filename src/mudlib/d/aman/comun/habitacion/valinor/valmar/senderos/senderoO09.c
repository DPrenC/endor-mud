/*****************************************************************************************
 ARCHIVO:       senderoO09.c
 AUTOR:         Ztico
 FECHA:         19-03-2005
 DESCRIPCIÓN:   Sendero Oeste del bosque de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_SENDERO_OESTE;

create()
{
    if(::create()) return 1;

    AddExit("norte", HAB_BOSQUE_SENDERO("senderoO10.c"));
    AddExit("sur", HAB_BOSQUE_SENDERO("senderoO08.c"));

    AddItem(PNJ_VALMAR("elfa.c"), REFRESH_DESTRUCT, 1);
}
