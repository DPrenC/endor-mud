/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado05.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("oeste",KRIGOR("sendero04"));
	AddExit("puerta",KRIGOR("casa05"));
	
}