/*
Fichero: encrucijadanorte.c
Autor: Aule
Fecha: 20/10/2012
Descripción: parte norte de la encrucijada
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();
    	SetLocate("el País de Bree");

    SetIntShort("norte de la encrucijada");
    SetIntLong("En este punto el Camino Verde que recorre las tierras de Bree se abre \n"
    "hacia el sur desembocando en un espacio más o menos circular donde desembocan \n"
    "otras tres vías desde el sur, este y oeste respectivamente.\n");
    AddExit("sur", "./encrucijada");
    AddExit("norte", "./camino_n1");
    AddExit("suroeste", "./encrucijadaoeste");
    AddExit("sureste", "./encrucijadaeste");
  }