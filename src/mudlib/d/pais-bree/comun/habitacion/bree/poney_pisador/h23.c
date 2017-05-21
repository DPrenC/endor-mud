/*
Fichero: h23.c
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
    	    	"proporciona una privilegiada vista de la ladera que desciende, salpicada de "
    	    	"casas de piedra de uno, dos e incluso tres pisos, habitadas por los "
    	    	"hombres de Bree. M�s all�, la l�nea oscura de la empalizada delimita la "
    	    	"aldea y al otro lado quedan los campos de cultivo que proporcionan grano a "
    	    	"la poblaci�n. Al estar en el tercer piso de la posada y contar con la "
    	    	"altura que proporciona la ladera de la colina, tu vista alcanza a "
    	    	"distinguir la l�nea del Camino Verde que corre de norte a sur, cruz�ndose "
    	    	"en el espacio circular de la encrucijada que hay ante la puerta oeste de "
    	    	"Bree, se une con el Gran Camino del Este que se aleja hacia el oeste, subiendo y bajando por suaves lomas en direcci�n a la Comarca. Al suroeste distingues la penumbrosa masa de las Quebradas de los T�mulos.\n");

    	AddExit("este", "./pasillo19");
     AddDoor("este", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "este", "e", "puerta este"})); 
    }