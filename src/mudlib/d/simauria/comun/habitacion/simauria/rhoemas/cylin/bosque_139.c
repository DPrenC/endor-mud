/***************************************************************************************
 ARCHIVO:	bosque_139.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Bosque Cylin, en Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("bosque");

create () {
 ::create();

 SetLocate("Bosque de Cylin - Gorgona");
 SetIntShort("el bosque de Cylin");
 AddRoomCmd("reiniciar","freiniciar");
 AddExit("sur",RHOEHAB("cylin/bosque_158"));
 AddExit("oeste",RHOEHAB("cylin/bosque_138"));
}

init(){
  ::init();
  
  add_action("fcoraje","coraje");
  TP->SetWhimpy(-1);
  tell_object(TP,W("Te sientes muy segur"+AO+" de ti mism"+AO+", esta vez no huirás automáticamente.\n"));
}

int fcoraje(int num)
{
	tell_object(TP,"Eres demasiado valiente para estar aquí, no puedes cambiar ahora.\n");
	return 1;
}

int freiniciar(string str)
{
	write("No, no... eso no se hace.\n");
	return 1;
}