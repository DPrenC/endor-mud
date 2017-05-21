/***************************************************************************************
 ARCHIVO:	bosque_216.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_235"));
 AddExit("oeste",RHOEHAB("cylin/bosque_215"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_236"));
 fanimales();
}