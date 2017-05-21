/***************************************************************************************
 ARCHIVO:	bosque_070.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_051"));
 AddExit("oeste",RHOEHAB("cylin/bosque_069"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_090"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_088"));
 fanimales();
}
