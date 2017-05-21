/*****************************************************************************************
 ARCHIVO:       bosque31.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque35.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque26.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque30.c"));
}
