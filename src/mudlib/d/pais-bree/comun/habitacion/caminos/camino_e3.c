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
    "El camino por el que avanzas conecta la aldea de Bree al este con el Cruce de "
    "Caminos al oeste, atravesando los campos cultivados de las afueras de la población.\n"
    "Las puertas se encuentra ya muy cerca y pueden alcanzarse rápidamente si se "
    "continúa avanzando hacia el este.\n");

    AddExit("oeste", "./camino_e2");
     AddExit("este", "./antepuertao"); 
    }