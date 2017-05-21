/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : sendero07.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("sendero");

create()
{
	::create();
	
	AddExit("noroeste",KRIGOR("plaza"));
	AddExit("sur",KRIGOR("sendero06"));
	AddExit("puerta",KRIGOR("casa06"));
	AddExit("este",KRIGOR("calle10"));
}