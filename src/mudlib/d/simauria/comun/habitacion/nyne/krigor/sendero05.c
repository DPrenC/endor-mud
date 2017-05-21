/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero05.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("nordeste",KRIGOR("sendero06"));
	AddExit("suroeste",KRIGOR("sendero04"));
	
}
