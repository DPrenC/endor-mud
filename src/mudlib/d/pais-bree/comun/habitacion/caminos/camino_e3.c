/*
Fichero: camino_e2.c
Autor: aul�
Fecha: 06/03/2013
Descripci�n: camino al este de la encrucijada, hacia Bree.
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();
    SetIntShort("Camino hacia Bree");
    SetIntLong(
    "El camino por el que avanzas conecta la aldea de Bree al este con el Cruce de "
    "Caminos al oeste, atravesando los campos cultivados de las afueras de la poblaci�n.\n"
    "Las puertas se encuentra ya muy cerca y pueden alcanzarse r�pidamente si se "
    "contin�a avanzando hacia el este.\n");

    AddExit("oeste", "./camino_e2");
     AddExit("este", "./antepuertao"); 
    }