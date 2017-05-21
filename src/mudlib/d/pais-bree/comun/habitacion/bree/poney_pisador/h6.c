/*
Fichero: h6.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	SetIntLong(QueryIntLong()+"Este cuarto mira al oeste y su amplia ventana "
    	    	"proporciona una hermosa vista de la ladera que desciende, salpicada de "
    	    	"casas de piedra de uno, dos e incluso tres pisos, habitadas por los "
    	    	"hombres de Bree. M�s all�, la l�nea oscura de la empalizada delimita la "
    	    	"aldea y al otro lado quedan los campos de cultivo que proporcionan grano a "
    	    	"la poblaci�n.\n"
    	    	"Esta habitaci�n est� m�s caldeada que el resto, por encontrarse sobre la "
    	    	"sala com�n, aunque el barullo del piso de abajo bien podr�a arruinarle el "
    	    	"sue�o a un troll borracho.\n");
    	    	SetIntNoise("Escuchas voces, cantos, entrechocar de jarras y cubiertos, "
    	    	"risas y discusiones procedentes del piso de abajo.\n");
    	AddExit("este", "./pasillo6");
     AddDoor("este", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "este", "e", "puerta este"})); 
    }