/***************************************************************************************
 ARCHIVO:	bosque_032.c
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
 AddExit("este",RHOEHAB("cylin/bosque_033"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_018"));
 fanimales();
}
