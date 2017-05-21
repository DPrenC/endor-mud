/*****************************************************************************************
 ARCHIVO:       bosque06.c
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
        "Una enorme raíz emerge del suelo formando una especie de banco natural que "
        "parece dispuesto para que te sientes a descansar.\n");
    AddDetail(({"raiz","raíz","banco"}), "Se trata de una raíz de tacto áspero y de un "
        "color marrón oscuro.\n");

    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque05.c"));
}
