/*****************************************************************************************
 ARCHIVO:       senderoO11.c
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

    AddExit("noroeste", HAB_BOSQUE_SENDERO("senderoO12.c"));
    AddExit("sur", HAB_BOSQUE_SENDERO("senderoO10.c"));
}
