/*****************************************************************************************
 ARCHIVO:       bosque04.c
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
        "Observas que al este, de entre los árboles, se abre un sendero por el que te "
        "puedes adentrar.\n");

    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque03.c"));
    AddExit("sureste", HAB_BOSQUE_SENDERO("senderoE01.c"));
    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque09.c"));
}
