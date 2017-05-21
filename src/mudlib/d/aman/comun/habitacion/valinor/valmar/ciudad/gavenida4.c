/*
Fichero: gavenida4.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
		SetIntLong(QueryIntLong()+ "Al norte de aquí se levantan los salones de Ulmo, que el "
	"Señor de las Aguas utiliza como morada en las escasas ocasiones que abandona sus "
	"acuosos dominios para acudir a los concilios de los Valar.\n");
	AddDetail(({"salones", "salones de Ulmo"}),
		"El gran edificio está cincelado en piedra de tal forma que simula una gran ola "
		"en movimiento, rematada por torres de espuma levantadas en piedra blanca.\n");
    	    AddExit("oeste", "./gavenida3");
    	    AddExit("este", "./gavenida5");
    	    AddExit("norte", "./hab_ulmo");
    	    }