/*****************************************************************************************
 ARCHIVO:       bosque11.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;

create()
{
    if(::create()) return 1;

    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque10.c"));
    AddExit("sureste", HAB_BOSQUE_CENTRAL("bosque07.c"));
}
