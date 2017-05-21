/*
Fichero: paseo20.c
Autor: aulë
Fecha: 04/08/2013
Descripción: Vía que recorre la parte más alta de la aldea, sobre la que se abren los agujeros hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("sur", "./sendero15");
     AddExit("sureste", "./paseo19");
     AddExit("oeste", "./camino11"); 
    }