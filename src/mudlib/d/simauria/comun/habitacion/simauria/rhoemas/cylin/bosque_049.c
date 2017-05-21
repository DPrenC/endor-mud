/***************************************************************************************
 ARCHIVO:	bosque_049.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_034"));
 AddExit("este",RHOEHAB("cylin/bosque_050"));
 AddExit("oeste",RHOEHAB("cylin/bosque_048"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_067"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_065"));
 fanimales();
}
