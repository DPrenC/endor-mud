/*
Fichero: camino7.c
Autor: aul�
Fecha: 04/08/2014
Descripci�n: peque�o camino que une la calle principal con el paseo por el norte del Poney.*/
#include "./path.h"
inherit HABITACION+"bree/bpaseo";

create()
{
    ::create();

    AddExit("noreste", "./camino8");
     AddExit("suroeste", "./camino6"); 
    }