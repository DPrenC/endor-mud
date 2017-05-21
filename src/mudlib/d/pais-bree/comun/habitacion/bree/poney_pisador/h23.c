/*
Fichero: h23.c
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
    	    	"proporciona una privilegiada vista de la ladera que desciende, salpicada de "
    	    	"casas de piedra de uno, dos e incluso tres pisos, habitadas por los "
    	    	"hombres de Bree. Más allá, la línea oscura de la empalizada delimita la "
    	    	"aldea y al otro lado quedan los campos de cultivo que proporcionan grano a "
    	    	"la población. Al estar en el tercer piso de la posada y contar con la "
    	    	"altura que proporciona la ladera de la colina, tu vista alcanza a "
    	    	"distinguir la línea del Camino Verde que corre de norte a sur, cruzándose "
    	    	"en el espacio circular de la encrucijada que hay ante la puerta oeste de "
    	    	"Bree, se une con el Gran Camino del Este que se aleja hacia el oeste, subiendo y bajando por suaves lomas en dirección a la Comarca. Al suroeste distingues la penumbrosa masa de las Quebradas de los Túmulos.\n");

    	AddExit("este", "./pasillo19");
     AddDoor("este", "la puerta",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "este", "e", "puerta este"})); 
    }