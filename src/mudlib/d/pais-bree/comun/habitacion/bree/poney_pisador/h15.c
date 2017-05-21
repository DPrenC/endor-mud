/*
Fichero: h15.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  habitación para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	    	    	    	SetIntLong(QueryIntLong()+"La ventana del cuarto da sobre un "
    	    	    	    	"callejón que rodea la posada por el sur. En esta dirección "
    	    	    	    	"puedes ver algunas casas diseminadas que llegan hasta la "
    	    	    	    	"empalizada y el seto que rodea la aldea, cerrada por una "
    	    	    	    	"puerta de trancas que bloquea el camino.\n"
    	    	    	    	"Al otro lado, puedes ver que el camino desciende rápidamente y "
    	    	    	    	"desaparece doblando al sureste, hacia las otras aldeas del País "
    	    	    	    	"de Bree y cruzando la herbosa falda de la colina, que sirve "
    	    	    	    	"para apacentar al ganado de la aldea.\n");
    	AddExit("norte", "./pasillo13");
     AddDoor("norte", "la puerta",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"})); 
    }