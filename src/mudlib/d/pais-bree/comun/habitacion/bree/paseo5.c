/*
Fichero: paseo5.c
Autor: aulë
Fecha: 04/08/2013
Descripción: VVía que recorre la parte más alta de la aldea, sobre la que se abren los agujeros hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("oeste", "./sendero1");
     AddExit("este", "./jardin1");
     AddExit("sur", "./paseo4");
     AddExit("norte", "./paseo6"); 
   
    }