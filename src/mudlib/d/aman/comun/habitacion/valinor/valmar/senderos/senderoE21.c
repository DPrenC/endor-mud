/*****************************************************************************************
 ARCHIVO:       senderoE21.c
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

    AddExit("este", HAB_BOSQUE_SENDERO("senderoE20.c"));
    AddExit("noroeste", HAB_BOSQUE_SENDERO("senderoE22.c"));
}
