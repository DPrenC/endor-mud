/*****************************************************************************************
 ARCHIVO:       senderoE20.c
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

    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoE21.c"));
    AddExit("sureste", HAB_BOSQUE_SENDERO("senderoE19.c"));
}
