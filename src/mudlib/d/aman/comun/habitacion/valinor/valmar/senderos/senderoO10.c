/*****************************************************************************************
 ARCHIVO:       senderoO10.c
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

    AddExit("norte", HAB_BOSQUE_SENDERO("senderoO11.c"));
    AddExit("sur", HAB_BOSQUE_SENDERO("senderoO09.c"));
}
