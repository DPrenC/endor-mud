/*
Fichero: h27.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n para la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/basehabi";
create()
{
    ::create();
    	    	SetIntLong(QueryIntLong()+"La ventana del cuarto da al norte y por ella puedes ver "
    	"la ladera de la colina que asciende hacia los agujeros de los hobbits que "
    	"habitan en Bree. Al encontrarte en la tercera parte del edificio aciertas a ver "
    	"los campos que se extienden m�s al norte,hasta convertirse en p�ramos desiertos.\n");
    	
    	AddExit("sur", "./pasillo21");
     AddDoor("sur", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "sur", "s", "puerta sur"})); 
    }