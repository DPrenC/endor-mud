/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle07.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("sudeste",KRIGOR("calle08"));
	AddExit("suroeste",KRIGOR("calle06"));
	AddExit("puerta",KRIGOR("casa17"));
	
}	
