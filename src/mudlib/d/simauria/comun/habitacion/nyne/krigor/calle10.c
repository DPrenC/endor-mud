/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle10.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("norte",KRIGOR("calle09"));
	AddExit("oeste",KRIGOR("sendero07"));
	AddExit("puerta",KRIGOR("casa20"));
	
}	
