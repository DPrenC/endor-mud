/*****************************************************************************************
 ARCHIVO:       bosque50.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit HAB_BOSQUE_HADAS("bosq_hadas_base.c");

create()
{
    if(::create()) return 1;

    AddExit("noreste", HAB_BOSQUE_HADAS("bosque56.c"));
    AddExit("oeste", HAB_BOSQUE_HADAS("bosque49.c"));
}
