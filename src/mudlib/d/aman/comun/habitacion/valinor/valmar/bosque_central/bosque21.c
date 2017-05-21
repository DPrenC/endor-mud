/*****************************************************************************************
 ARCHIVO:       bosque21.c
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

    AddExit("este", HAB_BOSQUE_CENTRAL("bosque22.c"));
    AddExit("sureste", HAB_BOSQUE_CENTRAL("bosque16.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque15.c"));
}
