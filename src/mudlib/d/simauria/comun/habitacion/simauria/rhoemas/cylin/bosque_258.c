/***************************************************************************************
 ARCHIVO:	bosque_258.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_241"));
 AddExit("sur",RHOEHAB("cylin/bosque_273"));
 AddExit("oeste",RHOEHAB("cylin/bosque_257"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_274"));
 fanimales();
}