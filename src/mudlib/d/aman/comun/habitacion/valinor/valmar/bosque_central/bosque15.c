/*****************************************************************************************
 ARCHIVO:       bosque15.c
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

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque21.c"));
    AddExit("noreste", HAB_BOSQUE_CENTRAL("bosque22.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque16.c"));

    AddItem(OBJ_COMIDA_VALINOR("gran_seta.c"), REFRESH_REMOVE, 1);
}
