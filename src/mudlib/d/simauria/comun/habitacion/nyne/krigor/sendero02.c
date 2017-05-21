/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero02.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("noroeste",KRIGOR("sendero03"));
	AddExit("sur",KRIGOR("sendero01"));
	AddExit("oeste",KRIGOR("prado01"));
	AddExit("este",KRIGOR("prado02"));


}