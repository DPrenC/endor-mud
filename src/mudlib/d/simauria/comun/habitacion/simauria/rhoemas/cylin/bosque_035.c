/***************************************************************************************
 ARCHIVO:	bosque_035.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_052"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_021"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_051"));
 fanimales();
}
