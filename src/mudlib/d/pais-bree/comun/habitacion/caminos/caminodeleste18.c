/*
Fichero: caminodeleste18.c
Autor: aul�
Fecha: 19/03/2013
Descripci�n: Gran camino del este entre Bree y Rivendel y que comunica Bree con las 
otras tres aldeas de la regi�n.
*/
#include "./path.h"
inherit HABITACION+"caminos/bcaminodeleste";
create()
{
    ::create();

    AddExit("sureste", "./caminodeleste19");
          AddExit("oeste", "./caminodeleste17"); 
    }