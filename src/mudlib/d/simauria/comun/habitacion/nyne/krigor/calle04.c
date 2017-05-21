/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle04.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("nordeste",KRIGOR("plaza"));
	AddExit("sur",KRIGOR("calle03"));
	AddExit("puerta",KRIGOR("casa14"));
	
}	
