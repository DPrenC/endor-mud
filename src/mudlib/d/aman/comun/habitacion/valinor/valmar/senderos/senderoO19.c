/*****************************************************************************************
 ARCHIVO:       senderoO19.c
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

    AddExit("noroeste", HAB_BOSQUE_SENDERO("senderoO18.c"));
    AddExit("noreste", HAB_BOSQUE_SENDERO("senderoE22.c"));
}
