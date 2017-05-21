/*****************************************************************************************
 ARCHIVO:       bosque10.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque16.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque05.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque11.c"));
}
