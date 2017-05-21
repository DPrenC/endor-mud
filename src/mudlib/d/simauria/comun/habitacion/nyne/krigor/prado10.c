/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor 
   *  FICHERO      : prado10.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("este",KRIGOR("manantial2"));
	AddExit("noroeste",KRIGOR("sendero10"));
	AddExit("puerta",KRIGOR("casa10"));
	
}