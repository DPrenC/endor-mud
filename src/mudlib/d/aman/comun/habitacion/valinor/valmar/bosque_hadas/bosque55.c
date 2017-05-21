/*****************************************************************************************
 ARCHIVO:       bosque55.c
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

    AddExit("norte", HAB_BOSQUE_HADAS("bosque60.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque61.c"));
    AddExit("oeste", HAB_BOSQUE_HADAS("bosque54.c"));
}
