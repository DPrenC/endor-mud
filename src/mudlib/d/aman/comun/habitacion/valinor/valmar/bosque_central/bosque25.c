/*****************************************************************************************
 ARCHIVO:       bosque25.c
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

    AddExit("este", HAB_BOSQUE_CENTRAL("bosque26.c"));
    AddExit("suroeste", HAB_BOSQUE_CENTRAL("bosque18.c"));

    AddItem(PNJ_VALMAR("elfa.c"), REFRESH_DESTRUCT, 1);
}
