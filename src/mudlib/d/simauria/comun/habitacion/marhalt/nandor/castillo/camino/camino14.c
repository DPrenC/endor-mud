/****************************************************************************
Fichero: camino14.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/sendero_base");
create(){
    ::create();
    SetIntLong(QueryIntLong()+ " Al oeste, el serpenteo de este angosto sendero "
    "acaba en un terreno m�s llano, bajo el torre�n de la esquina nordeste de la "
    "fortaleza, junto al foso.\n");
    AddExit("oeste", "./camino15");
    AddExit("este", "./camino13");
}

