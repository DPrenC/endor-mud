/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero06.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("norte",KRIGOR("sendero07"));
	AddExit("suroeste",KRIGOR("sendero05"));
	AddExit("sudeste",KRIGOR("prado06"));
	AddExit("oeste",KRIGOR("calle01"));
	AddExit("este",KRIGOR("prado07"));

}