/*****************************************************************************************
 ARCHIVO:       bosque57.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    AddExit("este", HAB_BOSQUE_SENDERO("senderoE09.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque52.c"));
}
