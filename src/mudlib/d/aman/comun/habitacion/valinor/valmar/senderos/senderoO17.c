/*****************************************************************************************
 ARCHIVO:       senderoO17.c
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

    AddExit("este", HAB_BOSQUE_SENDERO("senderoO18.c"));
    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoO16.c"));
}
