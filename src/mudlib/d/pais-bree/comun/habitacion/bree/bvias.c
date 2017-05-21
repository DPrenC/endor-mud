/*
Fichero: bvias.c
Autor: aulë
Fecha: 04/08/2013
Descripción: Base del camino que une el Poney con la puerta sur. 
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
SetIntShort("Camino bordeando la ladera.\n");
    	    	    switch(d3()){
        case 1:
     SetIntLong(
     "Este camino recorre a media altura la ladera de la colina desde la puerta sur de "
     "la empalizada hasta la posada del Poney Pisador. A ambos lados se alzan las casas "
     "de piedra de los habitantes humanos de la aldea y los pocos comercios que aún "
     "subsisten, ahora que el tráfico no es tan fluido en los caminos como lo era antaño.\n"
     "La senda es llana y donde las casas dejan un hueco distingues la empinada "
     "ladera que asciende hacia el este y los agujeros hobbits que han sido excavados en "
     "su interior.\n");
     break;
     case 2:
     	SetIntLong(
     	"Discurres por un ancho camino llano de gravilla y tierra batida que bordea la "
     	"falda de la colina y atraviesa la parte central de la aldea de Bree desde la "
     	"puerta sur, antes de girar al oeste y descender a la puerta occidental de la "
     	"empalizada. En la curva situada al este de aquí se alza la famosa posada del "
     	"Poney Pisador, centro de noticias, solaz y cotilleos de las cuatro aldeas del País de Bree.\n");
break;
case 3:
	SetIntLong(
	"Después de trasponer la puerta sur de la aldea, el Camino del Este costea la "
	"ladera de la colina entre las casas dispersas de los aldeanos, rodeadas de pequeños "
	"huertos y jardines cercados por espesos setos. La vía, cubierta de una mezcla de "
	"gravilla y tierra batida con algunos baches aquí y allá, se extiende hacia el norte "
	"hasta una pequeña plazoleta junto a la que se alza un gran edificio de dos alas "
	"que se apoya contra la colina. Más allá, el camino da un brusco giro al oeste y se "
	"pierde de vista.\n");     break;
	}
}