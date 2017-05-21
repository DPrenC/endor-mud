/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero03.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("norte",KRIGOR("sendero04"));
	AddExit("sudeste",KRIGOR("sendero02"));
	AddExit("suroeste",KRIGOR("prado03"));
	


}