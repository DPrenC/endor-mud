/*
Fichero: paseo19.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: V�a que recorre la parte m�s alta de la aldea, sobre la que se abren los agujeros hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("noroeste", "./paseo20");
     AddExit("sureste", "./paseo18"); 
    }