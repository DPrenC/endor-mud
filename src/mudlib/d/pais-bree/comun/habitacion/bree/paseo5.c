/*
Fichero: paseo5.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: VV�a que recorre la parte m�s alta de la aldea, sobre la que se abren los agujeros hobbits.*/
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