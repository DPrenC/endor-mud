/*****************************************************************************************
 ARCHIVO:       bosque63.c
 AUTOR:         Ztico
 FECHA:         06-04-2005
 DESCRIPCIÓN:   Bosque de las Dríadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_DRIADAS;

create()
{
    if(::create()) return 1;

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque66.c"));
    AddExit("sur", HAB_BOSQUE_SENDERO("senderoO06.c"));
}
