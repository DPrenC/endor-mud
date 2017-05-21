/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero08.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("nordeste",KRIGOR("sendero09"));
	AddExit("suroeste",KRIGOR("plaza"));
	AddExit("este",KRIGOR("calle09"));
	AddExit("oeste",KRIGOR("calle08"));
}