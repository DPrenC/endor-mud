/*****************************************************************************************
 ARCHIVO:       bosque29.c
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

    AddExit("noreste", HAB_BOSQUE_CENTRAL("bosque34.c"));
    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque33.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque24.c"));

    AddItem(PNJ_VALMAR("gyrto-centauro.c"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ_VALMAR("centauro.c"), REFRESH_DESTRUCT, 2 + random(3));
}
