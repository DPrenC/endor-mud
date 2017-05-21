/***************************************************************************************
 ARCHIVO:	bosque_236.c
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
 AddExit("este",RHOEHAB("cylin/bosque_237"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_216"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_252"));
 fanimales();
}