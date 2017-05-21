/*****************************************************************************************
 ARCHIVO:       bosque03.c
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
        "Al sudeste puedes contemplar la majestuosidad de un gran árbol y al este se "
        "abre un pequeño claro y lo que pordría ser un sendero.\n");

    AddExit("suroeste", HAB_BOSQUE_CENTRAL("bosque00.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque04.c"));

    AddItem(PNJ_VALMAR("elfo"), REFRESH_DESTRUCT);
}
