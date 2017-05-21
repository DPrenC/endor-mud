/*
Fichero: encrucijadaoeste.c
Autor: Aule
Fecha: 20/10/2012
Descripción: parte oeste de la encrucijada
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();

    SetIntShort("oeste de la encrucijada");
    SetIntLong("En este punto el Camino del Oeste procedente de la Comarca se abre \n"
    "hacia el este desembocando en un espacio más o menos circular donde confluyen \n"
    "otras tres vías desde el norte, sur y este.\n"
    "Al este, más allá de la encrucijada se iergue la aldea de Bree, establecida en las \n"
    "faldas de la gran colina del mismo nombre.\n");
    AddExit("este", "./encrucijada");
    AddExit("oeste", "./camino_o1");
  AddExit("noreste", "./encrucijadanorte");
  AddExit("sureste", "./encrucijadasur");
}