	/*
Fichero: caminodeleste44.c
Autor: aulë
Fecha: 19/03/2013
Descripción: Gran camino del este entre Bree y Rivendel y que comunica Bree con las 
otras tres aldeas de la región.
*/
#include "./path.h"
inherit HABITACION+"caminos/bcaminodeleste";
create()
{
    ::create();

    AddExit("sureste", "./caminodeleste4 5");
          AddExit("oeste", "./caminodeleste43"); 
    }