	/*
Fichero: caminodeleste31.c
Autor: aul�
Fecha: 19/03/2013
Descripci�n: Gran camino del este entre Bree y Rivendel y que comunica Bree con las 
otras tres aldeas de la regi�n.
*/
#include "./path.h"
inherit HABITACION+"caminos/bcaminodeleste";
create()
{
    ::create();

    AddExit("este", "./caminodeleste32");
          AddExit("noroeste", "./caminodeleste30"); 
    }