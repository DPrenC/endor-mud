/*****************************************************************************************
 ARCHIVO:       bosque28.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCI�N:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;

create()
{
    if(::create()) return 1;

    SetIntLong(::QueryIntLong() +
        "Los matorrales te impiden el paso hacia cualquier direcci�n. S�lo te queda "
        "volver por donde has venido.\n");

    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque27.c"));
}
