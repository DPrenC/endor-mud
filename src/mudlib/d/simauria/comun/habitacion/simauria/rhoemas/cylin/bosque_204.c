/***************************************************************************************
 ARCHIVO:	bosque_204.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_184"));
 AddExit("este",RHOEHAB("cylin/bosque_205"));
 AddExit("oeste",RHOEHAB("cylin/bosque_203"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_185"));
 fanimales();
}