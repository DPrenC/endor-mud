/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero12.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("sur",KRIGOR("sendero11"));
	AddExit("nordeste",KRIGOR("sendero13"));
	
}