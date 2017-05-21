/*****************************************************************************************
 ARCHIVO:       bosque02.c
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
        "Al sur contemplas un arbol gigante.\n");

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque07.c"));
    AddExit("sur",HAB_BOSQUE_CENTRAL("bosque00.c"));
}
