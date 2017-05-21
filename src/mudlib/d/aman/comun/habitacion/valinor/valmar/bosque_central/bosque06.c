/*****************************************************************************************
 ARCHIVO:       bosque06.c
 AUTOR:         Ztico
 FECHA:         15-03-2005
 DESCRIPCI�N:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;


create()
{
    if(::create()) return 1;

    SetIntLong(::QueryIntLong() +
        "Una enorme ra�z emerge del suelo formando una especie de banco natural que "
        "parece dispuesto para que te sientes a descansar.\n");
    AddDetail(({"raiz","ra�z","banco"}), "Se trata de una ra�z de tacto �spero y de un "
        "color marr�n oscuro.\n");

    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque05.c"));
}
