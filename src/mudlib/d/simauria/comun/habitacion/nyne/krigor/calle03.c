/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle03.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("norte",KRIGOR("calle04"));
	AddExit("sur",KRIGOR("calle02"));
	AddExit("puerta",KRIGOR("casa13"));
	
}	
