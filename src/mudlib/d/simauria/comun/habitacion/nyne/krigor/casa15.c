/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : casa15.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("casa");

create()
{
	::create();
	
	AddExit("salir",KRIGOR("calle05"));
	
}	
