/*
Fichero: gavenida2.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
	SetIntLong(QueryIntLong()+ "Ante ti, al norte, se alzan las mansiones que Aulë, el "
	"Vala Herrero, posee en  Valmar y en los  que habita y trabaja cuando se encuentra en "
	"la ciudad.\n");
	AddDetail(({"aule", "mansiones de aule", "palacios de aule", "palacio de aule"}),
	"Es un formidable edificio fortificado de piedra pulida cuyas torrecillas y cúpulas "
	"están coronadas por los más extraños metales.\n");
    	    AddExit("oeste", "./gavenida1");
    	    AddExit("este", "./gavenida3");
    	    AddExit("norte", "./hab_aule");
    	    }