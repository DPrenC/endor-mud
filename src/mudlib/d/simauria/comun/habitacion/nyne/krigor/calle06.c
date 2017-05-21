/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle06.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("sudeste",KRIGOR("calle05"));
	AddExit("suroeste",KRIGOR("prado08"));
	AddExit("nordeste",KRIGOR("calle07"));
	AddExit("puerta",KRIGOR("casa16"));
	
}	
