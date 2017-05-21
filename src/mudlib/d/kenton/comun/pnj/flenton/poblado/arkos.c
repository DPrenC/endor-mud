/***************************************************************************************
 ARCHIVO:	arkos.c
 AUTOR:		[k] Korsario
 FECHA:		05/04/1998
 COMENTARIOS:	Arkos el artesano
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
inherit NPC;

create()
{
    ::create();
   SetStandard("arkos","humano",40,GENERO_MASCULINO);
    SetIds(({"arkos","humano","artesano"}));
    SetName("Arkos");
    SetShort("Arkos, el artesano");
    SetLong("Arkos es un humano bastante viejo. No habla demasiado pero parece muy buena "
        "persona.\nEs un artesano de los mejores que podrás encontrar.\n");
    SetShrugMsg("Arkos hace una mueca de aburrimiento y dice: Y yo qué sé. No me molestes.\n");
    InitChats(5,({
      	"Arkos te mira de arriba abajo sin mucho interés.\n",
	      "Arkos dice: ¿Deseas algo en particular?\n"}));
    InitAChats(10,({
  	    "Arkos grita: ¡¿Pero qué haces?! ¡Pagarás por esto!\n",
  	    "Arkos dice: Creo que estás cometiendo un error.\n"}));
}

