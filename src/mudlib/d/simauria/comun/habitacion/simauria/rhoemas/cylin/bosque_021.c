/***************************************************************************************
 ARCHIVO:	bosque_021.c
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
 AddExit("este",RHOEHAB("cylin/bosque_022"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_009"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_035"));
 fanimales();
}
