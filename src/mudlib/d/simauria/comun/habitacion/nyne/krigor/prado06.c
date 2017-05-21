/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado06.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("noroeste",KRIGOR("sendero06"));
	AddExit("puerta",KRIGOR("casa06"));
	
}