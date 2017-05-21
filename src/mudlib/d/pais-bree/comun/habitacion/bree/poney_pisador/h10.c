/*
Fichero: h10.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	    	    	    	SetIntLong(QueryIntLong()+"La ventana del cuarto da sobre un "
    	    	    	    	"callej�n que rodea la posada por el sur. En esta direcci�n "
    	    	    	    	"puedes ver algunas casas diseminadas que llegan hasta la "
    	    	    	    	"empalizada y el seto que rodea la aldea, cerrada por una "
    	    	    	    	"puerta de trancas que bloquea el camino.\n");

    	AddExit("norte", "./pasillo10");
     AddDoor("norte", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"})); 
    }