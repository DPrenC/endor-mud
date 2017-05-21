/*****************************************************************************************
 ARCHIVO:       senderoE02.c
 AUTOR:         Ztico
 FECHA:         19-03-2005
 DESCRIPCI�N:   Sendero Este del bosque de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_SENDERO_ESTE;

create()
{
    if(::create()) return 1;

    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoE01.c"));
    AddExit("este", HAB_BOSQUE_SENDERO("senderoE03.c"));
}