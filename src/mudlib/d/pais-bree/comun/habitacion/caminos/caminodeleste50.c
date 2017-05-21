	/*
Fichero: caminodeleste50.c
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

    AddExit("este", CAMINO_ESTE_ERIADOR1("/camino1_01"));
          AddExit("oeste", "./caminodeleste49"); 
    }