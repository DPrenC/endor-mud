/*
Fichero: paseo20.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: V�a que recorre la parte m�s alta de la aldea, sobre la que se abren los agujeros hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("sur", "./sendero15");
     AddExit("sureste", "./paseo19");
     AddExit("oeste", "./camino11"); 
    }