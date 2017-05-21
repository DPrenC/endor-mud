/*****************************************************************************************
 ARCHIVO:       bosque18.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque24.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque12.c"));
    AddExit("noreste", HAB_BOSQUE_CENTRAL("bosque25.c"));
    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque23.c"));
}
