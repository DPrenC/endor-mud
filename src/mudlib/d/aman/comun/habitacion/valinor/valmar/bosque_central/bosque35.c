/*****************************************************************************************
 ARCHIVO:       bosque35.c
 AUTOR:         Ztico
 FECHA:         18-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;

create()
{
    if(::create()) return 1;

    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque31.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque34.c"));
}
