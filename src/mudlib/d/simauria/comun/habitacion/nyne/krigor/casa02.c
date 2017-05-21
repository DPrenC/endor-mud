/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : casa02.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("casa");

create()
{
	::create();
	
	AddExit("salir",KRIGOR("prado02"));
	
}	
