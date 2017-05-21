/***************************************************************************************
 ARCHIVO:	bosque_080.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_061"));
 AddExit("sur",RHOEHAB("cylin/bosque_099"));
 AddExit("este",RHOEHAB("cylin/bosque_081"));
 AddExit("oeste",RHOEHAB("cylin/bosque_079"));
 fanimales();
}
