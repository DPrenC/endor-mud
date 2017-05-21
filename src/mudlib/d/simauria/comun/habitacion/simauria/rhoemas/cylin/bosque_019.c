/***************************************************************************************
 ARCHIVO:	bosque_019.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_008"));
 AddExit("este",RHOEHAB("cylin/bosque_020"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_007"));
 fanimales();
}
