/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle08.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("este",KRIGOR("sendero08"));
	AddExit("noroeste",KRIGOR("calle07"));
	AddExit("puerta",KRIGOR("casa18"));
	
}	
