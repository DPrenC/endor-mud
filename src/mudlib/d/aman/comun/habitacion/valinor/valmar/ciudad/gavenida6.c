/*
Fichero: gavenida6.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
    	    AddExit("oeste", "./gavenida5");
    	    AddExit("este", "./gavenida7");
    	    }