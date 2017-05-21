/****************************************************************************
Fichero: /d/simauria/comun/transporte/diligencia/masher/intmasher.c
Autor: Lug y Yalin
Fecha: 01/08/2006
Descripción: Diligencia Nandor-Sherek
****************************************************************************/
#include "path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("La diligencia Masher");
    SetIntLong("Estás dentro de la maltrecha diligencia que hace el trayecto "
        "entre la ciudad de Nandor y los dominios de Sherek.\nEs apenas una "
        "cabaña rectangular hecha de tablones toscamente ensamblados, sobre "
        "2 ejes fijos con argollas directamente a la caja, sin amortiguación "
        "de ningún tipo.\n");
    SetIndoors(1);
    SetIntBright(50);
    SetIntSmell("Huele a hierba y verduras, que a menudo se transportan en esta diligencia.");
}

