/*
Fichero: desvio2.c
Autor: aulë
Fecha: 04/08/2013
Descripción: un estrecho atajo escondido que une el paseo superior con la puerta sur, entre la empalizada y las casas.*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();

    AddExit("oeste", "./desvio3");
     AddExit("este", "./desvio1"); 
    }