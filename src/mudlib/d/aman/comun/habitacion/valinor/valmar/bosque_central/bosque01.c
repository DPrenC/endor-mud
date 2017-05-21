/*****************************************************************************************
 ARCHIVO:       bosque01.c
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

    SetIntLong(::QueryIntLong() +
        "Al sudeste puedes divisar un enorme árbol.\n");

    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque05.c"));
    AddExit("sureste",HAB_BOSQUE_CENTRAL("bosque00.c"));
}
