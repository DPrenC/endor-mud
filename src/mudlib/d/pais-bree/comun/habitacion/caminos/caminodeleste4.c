/*
Fichero: caminodeleste4.c
Autor: aul�
Fecha: 14/03/2013
Descripci�n: Gran camino del este entre Bree y Rivendel y que comunica Bree con las 
otras tres aldeas de la regi�n.
*/
#include "./path.h"
inherit HABITACION+"caminos/bcaminodeleste";
create()
{
    ::create();

    AddExit("sureste", "./caminodeleste5");
     AddExit("noroeste", "./caminodeleste3"); 
    }