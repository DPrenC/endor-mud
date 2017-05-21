/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado04.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("sudeste",KRIGOR("sendero04"));
	AddExit("puerta",KRIGOR("casa04"));
	
}