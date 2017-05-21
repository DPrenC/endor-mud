/*****************************************************************************************
 ARCHIVO:       senderoE05.c
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

    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoE04.c"));
    AddExit("norte", HAB_BOSQUE_SENDERO("senderoE06.c"));
}
