/****************************************************************************
Fichero: patio11.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"En esta zona los arqueros de la guarnición afinan la "
    "puntería usando las dianas colgadas en el muro de la torre del homenaje, justo al "
    "sur de aquí.\n");
    AddDetail(({"diana", "dianas"}), "Unas secciones  de madera blanda con círculos "
    "concéntricos pintados, distribuidas en hilera.\n");
    AddExit("este", "./patio12");
    AddExit("oeste",  "./patio10");
    AddExit("norte", "./patio05");
    AddExit("nordeste", "./patio06");
    AddExit("noroeste", "./patio04");
}


