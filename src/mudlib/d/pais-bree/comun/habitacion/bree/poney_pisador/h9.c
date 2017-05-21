/*
Fichero: h9.c
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
"Por los sonidos y olores, dir�as que esta habitaci�n se encuentra sobre los "
"establos.\n");    	    	SetIntNoise("Escuchas algunos golpes rudos, de vez en cuando "
"un largo resoplido equino y alguna blasfemia o silbido procedente del piso de abajo.\n");
SetIntSmell("Entre el olor a madera antigua y ropa de cama limpia se cuela un "
"persistente y perfectamente perceptible olor a bestias equinas.\n");
    	AddExit("este", "./pasillo10");
     AddDoor("este", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "este", "e", "puerta este"})); 
    }