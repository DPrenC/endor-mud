/*
Fichero: sendero15.c
Autor: aulë
Fecha: 04/08/2013
Descripción: sendero que transcurre por el corazón de Bree, alrrededor de los huertos de "
"los hobbits de la parte alta de la aldea.*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();

    AddExit("norte", "./paseo20");
     AddExit("sur", "./sendero13"); 
    }