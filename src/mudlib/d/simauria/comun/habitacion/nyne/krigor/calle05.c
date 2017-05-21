/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle05.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("este",KRIGOR("plaza"));
	AddExit("noroeste",KRIGOR("calle06"));
	AddExit("puerta",KRIGOR("casa15"));
	
}	
