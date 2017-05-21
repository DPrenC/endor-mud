/*
Fichero: camino_e2.c
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
    "El camino continúa recto de este a oeste entre los campos cultivados de las "
    "afueras de la aldea. Continuando hacia el este se encuentra la entrada a Bree y "
    "hacia el este el camino desemboca en un cruce.\n");

    AddExit("oeste", "./camino_e1");
    AddExit("este", "./camino_e3");
    }