/***************************************************************************************
 ARCHIVO:	discipulo_rezando.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Un discípulo del templo
 MODIFICACION:	11-05-2003 Bajo nivel
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"

inherit RHOEPNJ("seri/discipulo_base");


create(){
  ::create();
 InitChats(4,({"Un discípulo reza piadosamente.\n",
		"Un discípulo se concentra en sus rezos.\n",
		"Un discípulo murmura algún tipo de oración.\n"}));
}
