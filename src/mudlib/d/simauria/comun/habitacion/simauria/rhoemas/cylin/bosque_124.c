/***************************************************************************************
 ARCHIVO:	bosque_124.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_104"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_105"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_145"));
 fanimales();
}