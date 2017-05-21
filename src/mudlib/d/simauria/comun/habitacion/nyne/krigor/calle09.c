/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : calle09.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("calle");

create()
{
	::create();
	
	
	AddExit("sur",KRIGOR("calle10"));
	AddExit("oeste",KRIGOR("sendero08"));
	AddExit("puerta",KRIGOR("casa19"));
	
}	
