/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle01.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	AddExit("este",KRIGOR("sendero06"));
	AddExit("oeste",KRIGOR("calle02"));
	AddExit("puerta",KRIGOR("casa11"));
	
}	
