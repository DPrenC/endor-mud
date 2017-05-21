/*****************************************************************************************
 ARCHIVO:       bosque22.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque27.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque16.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque23.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque21.c"));
    AddExit("suroeste", HAB_BOSQUE_CENTRAL("bosque15.c"));

    AddItem(PNJ_VALMAR("elfo.c"), REFRESH_DESTRUCT, 1);
}
