/*
Fichero: caminodeleste22.c
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

    AddExit("este", "./caminodeleste23");
          AddExit("suroeste", "./caminodeleste21"); 
    }