/***************************************************************************************
 ARCHIVO:	pikarus.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Pikarus el tabernero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Pikarus, el tabernero","kender",10,GENERO_MASCULINO);
  SetName("pikarus");
  SetIds(({"tabernero","pikarus"}));

  SetShort("Pikarus, el tabernero");
  SetLong(W("Ves a pikarus, el tabernero. Es un kender bajo y regordete. "
  	"Esta siempre contento y risueño y es un gran compañero de charla "
  	"para las largas noches de invierno.\n"));

  InitChats(5,({W("Pikarus dice: Bueno, bueno, bueno... veo caras sedientas por aquí, "
			"Una nueva ronda??\n"),
	        "Pikarus dice: ¡No encontrarás un asado mejor que el de esta casa!\n"}));
  InitAChats(10,({"Pikarus grita: ¡Creo que tienes un serio problema de agresividad!\n",
                 "Pikarus dice: ¡¿Pero qué haces?!.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
