/*
Fichero: caminodeleste4.c
Autor: aulë
Fecha: 14/03/2013
Descripción: Gran camino del este entre Bree y Rivendel y que comunica Bree con las 
otras tres aldeas de la región.
*/
#include "./path.h"
inherit HABITACION+"caminos/bcaminodeleste";
create()
{
    ::create();

    AddExit("sureste", "./caminodeleste5");
     AddExit("noroeste", "./caminodeleste3"); 
    }