/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero09.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("norte",KRIGOR("sendero10"));
	AddExit("suroeste",KRIGOR("sendero08"));
	AddExit("noroeste",KRIGOR("prado09"));
	
}