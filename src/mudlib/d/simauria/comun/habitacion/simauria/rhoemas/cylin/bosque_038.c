/***************************************************************************************
 ARCHIVO:	bosque_038.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_023"));
 AddExit("este",RHOEHAB("cylin/bosque_039"));
 AddExit("oeste",RHOEHAB("cylin/bosque_037"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_056"));
 fanimales();
}
