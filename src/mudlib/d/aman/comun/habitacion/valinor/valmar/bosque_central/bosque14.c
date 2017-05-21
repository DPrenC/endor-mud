/*****************************************************************************************
 ARCHIVO:       bosque14.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque20.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque09.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque13.c"));
}
