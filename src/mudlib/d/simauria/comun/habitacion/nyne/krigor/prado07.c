/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado07.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("oeste",KRIGOR("sendero06"));
	AddExit("puerta",KRIGOR("casa07"));
	
}