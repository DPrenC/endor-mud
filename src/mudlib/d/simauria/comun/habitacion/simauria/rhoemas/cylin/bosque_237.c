/***************************************************************************************
 ARCHIVO:	bosque_237.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_218"));
 AddExit("oeste",RHOEHAB("cylin/bosque_236"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_219"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_253"));
 fanimales();
}