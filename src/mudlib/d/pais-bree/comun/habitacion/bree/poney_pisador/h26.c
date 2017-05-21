/*
Fichero: h26.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	    	SetIntLong(QueryIntLong()+"Por la ventana puedes ver, all� abajo, el patio "
    	    	"situado entre las dos alas de la posada con un gran mont�n de le�a al fondo.\n");
    	AddExit("norte", "./pasillo20");
     AddDoor("norte", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"})); 
    }