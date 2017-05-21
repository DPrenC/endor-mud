/*****************************************************************************************
 ARCHIVO:       senderoE15.c
 AUTOR:         Ztico
 FECHA:         19-03-2005
 DESCRIPCIÓN:   Sendero Este del bosque de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_SENDERO_ESTE;

create()
{
    if(::create()) return 1;

    AddExit("noroeste", HAB_BOSQUE_SENDERO("senderoE16.c"));
    AddExit("noreste", HAB_BOSQUE_SENDERO("senderoE14.c"));
}
