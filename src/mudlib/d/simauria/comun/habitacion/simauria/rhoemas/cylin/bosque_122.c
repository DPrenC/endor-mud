/***************************************************************************************
 ARCHIVO:	bosque_122.c
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
 AddExit("este",RHOEHAB("cylin/bosque_123"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_143"));
 fanimales();
}