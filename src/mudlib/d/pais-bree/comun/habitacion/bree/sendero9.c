/*
Fichero: sendero9.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: sendero que transcurre por el coraz�n de Bree, alrrededor de los huertos de "
"los hobbits de la parte alta de la aldea.*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();

    AddExit("norte", "./sendero10");
     AddExit("sur", "./sendero8"); 
    }