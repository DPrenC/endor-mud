/*
Fichero: gavenida5.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
	
		SetIntLong(QueryIntLong()+ "Al norte de aqu� se ierguen los salones de banquetes de "
		"Tulkas, el Campe�n de los Valar, famosos en toda Valinor.\n");
		AddDetail(({"banquetes", "salones", "salones de banquetes", "salones de tulkas", "tulkas"}),
		"Se trata de un edificio de una sola planta, amplio y cuadrado, pero no exento de la "
		"gracia que caracteriza a todas las construcciones de Valmar.\n"
"Edificado en m�rmol blanco y techado con lascas talladas del mismo material que bajan en "
"cuatro suaves aguas, cuenta con una galer�a porticada que lo rodea, y dos gruesas "
"columnas flanqueando la gran arcada de entrada, a la cual se asciende por una ancha "
"escalinata de m�rmol.\n"
"Grandes puertas de bronce rojo grabado con escenas de batallas de anta�o, siempre "
"abiertas a los costados, parecen dar la bienvenida a cualquiera que desee entrar.\n");    	    AddExit("oeste", "./gavenida4");
    	    AddExit("este", "./gavenida6");
    	    AddExit("norte", "./hab_tulkas");
    	    }