/*
Fichero: h13.c
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
    	    	    	    	"puerta de trancas que bloquea el camino.\n");
    	AddExit("norte", "./pasillo12");
 }