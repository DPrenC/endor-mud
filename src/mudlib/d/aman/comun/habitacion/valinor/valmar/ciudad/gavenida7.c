/*
Fichero: gavenida7.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
    	    AddExit("oeste", "./gavenida6");
    	    //AddExit("este", "./gavenida8");
    	    }