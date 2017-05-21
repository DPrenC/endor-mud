/*****************************************************************************************
 ARCHIVO:       senderoO15.c
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

    AddExit("este", HAB_BOSQUE_SENDERO("senderoO16.c"));
    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoO14.c"));
    AddExit("sur", HAB_BOSQUE_DRIADAS("bosque79.c"));

    AddItem(PNJ_VALMAR("elfo.c"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ_VALMAR("elfa.c"), REFRESH_DESTRUCT, random(2));
}
