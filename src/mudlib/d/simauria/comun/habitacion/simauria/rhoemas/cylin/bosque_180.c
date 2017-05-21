/***************************************************************************************
 ARCHIVO:	bosque_180.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_160"));
 AddExit("este",RHOEHAB("cylin/bosque_181"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_201"));
 fanimales();
}