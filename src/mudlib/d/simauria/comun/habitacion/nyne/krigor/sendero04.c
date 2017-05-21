/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero04.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("nordeste",KRIGOR("sendero05"));
	AddExit("sur",KRIGOR("sendero03"));
	AddExit("noroeste",KRIGOR("prado04"));
	AddExit("este",KRIGOR("prado05"));

}