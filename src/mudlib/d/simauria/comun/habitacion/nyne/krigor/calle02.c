/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle02.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	AddExit("este",KRIGOR("calle01"));
	AddExit("norte",KRIGOR("calle03"));
	AddExit("puerta",KRIGOR("casa12"));
	
}	
