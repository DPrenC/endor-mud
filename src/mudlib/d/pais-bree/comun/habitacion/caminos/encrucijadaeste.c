/*
Fichero: encrucijadaeste.c
Autor: Aule
Fecha: 06/03/2013
Descripción: parte este de la encrucijada
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();

    SetIntShort("este de la encrucijada");
    AddExit("este", "./camino_e1");
    AddExit("oeste", "./encrucijada");
  AddExit("noroeste", "./encrucijadanorte");
  AddExit("suroeste", "./encrucijadasur");
}