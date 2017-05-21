/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero10.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("noroeste",KRIGOR("sendero11"));
	AddExit("sur",KRIGOR("sendero09"));
	AddExit("sudeste",KRIGOR("prado10"));
	
}