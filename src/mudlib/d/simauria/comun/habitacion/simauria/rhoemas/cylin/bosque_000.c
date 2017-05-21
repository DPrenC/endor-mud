/***************************************************************************************
 ARCHIVO:	bosque_000.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Bosque Cylin, en Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("bosque");

create () {
 ::create();

 SetLocate("Bosque de Cylin");
 SetIntShort("el bosque de Cylin");
 AddExit("sur",RHOEHAB("cylin/bosque_011"));
 AddExit("este",RHOEHAB("cylin/bosque_001"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_010"));
 fanimales();
}
