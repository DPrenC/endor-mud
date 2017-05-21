/*
Fichero: bviao.c
Autor: aulë
Fecha: 04/08/2013
Descripción: Base del camino que une el Poney con la puerta oeste. 
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("un camino en pendiente");
    	    	    switch(d3()){
        case 1:
       SetIntLong(
       "El camino que sigues asciende por la falda de la colina en una leve pendiente "
       "hacia el este, desde la puerta occidental de la aldea. A tu alrededor se "
       "levantan algunas casas dispersas de hombres, rodeadas de pequeñas parcelas de "
      "tierra, huertos, establos y diversas dependencias que muestran a las claras que "
      "Bree, pese a ser relativamente grande para hallarse en medio de ninguna parte, "
      "subsiste más de la agricultura y la ganadería que de su posición en un antiguo "
      "cruce de caminos.\n");
       break;
       case 2:
       	SetIntLong(
       	"-Circulas por un camino de grava, piedrecillas y tierra batida con algunos "
       	"baches que asciende desde la puerta occidental de la empalizada, internándose en "
       	"la aldea. A tu alrededor se ierguen, algo distantes unas de otras, las casas "
       	"de piedra de los hombres de Bree. Pese a que todo parece más o menos cuidado y "
       	"habitado, los días en que Bree era un crisol de viajeros y comerciantes que "
       	"recorrían los caminos de Eriador han quedado muy atrás, dependiendo ahora del "
       	"campo para la subsistencia.\n");
       	break;
       	case 3:
       		SetIntLong(
       		"El camino que sigues y que comienza allá abajo en la puerta de la empalizada "
       		"es la continuación del Gran Camino del Este que atraviesa la aldea de Bree "
       		"para luego girar al sur y al este en dirección a las partes orientales del "
       		"antiguo reino dúnadan de Arnor y el mítico valle de Rivendel.\n"
       		"La senda asciende en leve pendiente hacia las partes más altas de la colina "
       		"donde se asienta la famosa posada del Poney Pisador. A la vera del camino se "
       		"levantan, desperdigadas las casas en las que moran los aldeanos humanos de la "
       		"población.\n");  
break;
}
}