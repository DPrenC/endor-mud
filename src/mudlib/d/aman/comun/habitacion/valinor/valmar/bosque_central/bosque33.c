/*****************************************************************************************
 ARCHIVO:       bosque33.c
 AUTOR:         Ztico
 FECHA:         18-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_CENTRAL;

create()
{
    if(::create()) return 1;
    AddItem(PNJ_VALMAR("centauro.c"), REFRESH_REMOVE, 2 + random(3));
    AddExit("sureste", HAB_BOSQUE_CENTRAL("bosque29.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque32.c"));


}
