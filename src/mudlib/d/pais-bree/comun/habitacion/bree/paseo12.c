/*
Fichero: paseo12.c
Autor: aulë
Fecha: 04/08/2013
Descripción: Vía que recorre la parte más alta de la aldea, sobre la que se abren los agujeros hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("norte", "./paseo13");
     AddExit("sur", "./paseo11"); 
    }