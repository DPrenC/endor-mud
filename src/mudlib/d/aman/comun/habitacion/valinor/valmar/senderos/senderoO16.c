/*****************************************************************************************
 ARCHIVO:       senderoO16.c
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

    AddExit("este", HAB_BOSQUE_SENDERO("senderoO17.c"));
    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoO15.c"));
}
