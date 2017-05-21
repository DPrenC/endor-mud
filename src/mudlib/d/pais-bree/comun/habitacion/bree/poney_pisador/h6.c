/*
Fichero: h6.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  habitación para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	SetIntLong(QueryIntLong()+"Este cuarto mira al oeste y su amplia ventana "
    	    	"proporciona una hermosa vista de la ladera que desciende, salpicada de "
    	    	"casas de piedra de uno, dos e incluso tres pisos, habitadas por los "
    	    	"hombres de Bree. Más allá, la línea oscura de la empalizada delimita la "
    	    	"aldea y al otro lado quedan los campos de cultivo que proporcionan grano a "
    	    	"la población.\n"
    	    	"Esta habitación está más caldeada que el resto, por encontrarse sobre la "
    	    	"sala común, aunque el barullo del piso de abajo bien podría arruinarle el "
    	    	"sueño a un troll borracho.\n");
    	    	SetIntNoise("Escuchas voces, cantos, entrechocar de jarras y cubiertos, "
    	    	"risas y discusiones procedentes del piso de abajo.\n");
    	AddExit("este", "./pasillo6");
     AddDoor("este", "la puerta",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "este", "e", "puerta este"})); 
    }