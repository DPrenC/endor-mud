/*****************************************************************************************
 ARCHIVO:       bosque05.c
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
        "Observas como las enredederas serpentean por las ramas encorvadas de los "
        "árboles, formando un arco por el que se accede al sendero del oeste.\n");

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque10.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque06.c"));
    AddExit("sureste", HAB_BOSQUE_CENTRAL("bosque01.c"));
    AddExit("oeste", HAB_BOSQUE_SENDERO("senderoO01.c"));
}
