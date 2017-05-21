/***************************************************************************************
 ARCHIVO:	manodehierro.c
 AUTOR:		[z] Zomax
 FECHA:		05-04-1998
 COMENTARIOS:	Mano de Hierro, el herrero. Nombre y descripciones de [k] Korsario, lo
 		traslado a un pnj con archivo propio.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("El herrero, ManodeHierro","humano",30,GENERO_MASCULINO);
  SetIds(({"manodehierro", "herrero","ManodeHierro"}));
  SetName("ManodeHierro");

  SetShort("El herrero, ManodeHierro");
  SetLong(W("El viejo herrero, ManodeHierro. Es un humano bastante corpulento y "
  	"alto. Te parece bastante fuerte para su edad. Tiene una gran barba que "
  	"acaricia con orgullo. A pesar de su rudo aspecto parece bastante agradable.\n"));

  InitChats(5,({"ManodeHierro golpea fuertemente una pieza de metal.\n",
	        "ManodeHierro te mira y pone cara de malas pulgas.\n"}));
  InitAChats(10,({"ManodeHierro dice: ¡Ahora probarás las espadas que forjo!\n",
                 "ManodeHierro grita: ¡Verás cuando te coja!\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
