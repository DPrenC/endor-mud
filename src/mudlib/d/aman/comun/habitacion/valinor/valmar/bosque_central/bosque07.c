/*****************************************************************************************
 ARCHIVO:       bosque07.c
 AUTOR:         Ztico
 FECHA:         15-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;

create()
{
    if(::create()) return 1;

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque12.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque02.c"));
    AddExit("noreste", HAB_BOSQUE_CENTRAL("bosque13.c"));
    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque11.c"));
}
