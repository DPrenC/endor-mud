/*
Fichero: camino_e1.c
Autor: aulë
Fecha: 06/03/2013
Descripción: camino al este de la encrucijada, hacia Bree.
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();
    SetIntShort("Camino hacia Bree");
    SetIntLong(
    "Desde aquí, un corto camino conduce al pie de la colina  donde se alza la puerta "
    "oeste de Bree. A los lados se extienden algunos campos cultivados y hacia el "
    "oeste el camino desemboca en una encrucijada.\n");
    AddExit("oeste", "./encrucijadaeste");
    AddExit("este", "./camino_e2");
    }