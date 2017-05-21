/***************************************************************************************
 ARCHIVO:	cueva.c
 AUTOR:		[z] Zomax
 FECHA:		27-11-2001
 COMENTARIOS:	Guarida de la Gorgona.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int fcoger(string str)
{
	if (str=="cama" || str=="hoja" || str=="hojas" || str=="rama" || str=="ramas" || str=="hoja seca" || str=="hojas secas")
	{
		write("Mejor que no toques nada de eso, no sea que venga el dueño.\n");
		return 1;
	}
}

int fhuir(string str)
{
	if (TP->QueryCombatDelay())
	{
		write(W("No puedes huir. Estás inmovilizad"+AO+".\n"));
		say(W(CATP+" mira a su alrededor con pánico en los ojos. Parece que "
		"quiere huir, pero está inmovilizad"+AO+".\n"),TP);
		return 1;
	}
}

create () {
  ::create();
  SetIndoors(1);
  SetIntBright(20);
  SetLocate("Bosque de Cylin - Gorgona");
  SetIntShort("el bosque de Cylin");
  SetIntLong(W("Estás en un lugar muy oscuro, mezcla de cueva y madriguera. Hay una "
  		"especie de cama en un rincón hecha a base de ramas y hojas secas que "
  		"debe ser el lugar de reposo de alguien... o algo... no te sientes nada "
  		"cómodo, como si alguien te observara. Deberías salir de aqui enseguida.\n"));
  AddDetail(({"cama","hoja","hojas","rama","ramas","hoja seca","hojas secas"}),W(
		"Hay una cama hecha de hojas secas y ramas en una esquina, mejor no tocar "
		"nada...\n"));
  AddExit("arriba",RHOEHAB("cylin/gorgona"));
  AddItem(RHOEPNJ("cylin/gorgona"),1);
  AddRoomCmd("huir","fhuir");
  AddRoomCmd("reiniciar","freiniciar");
}

init(){
  ::init();
  
  add_action("fcoraje","coraje");
  add_action("fcoger","coger");
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
