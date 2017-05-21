/***************************************************************************************
 ARCHIVO:	yegua.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un yegua
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  switch(random(4))
  {
  	case 0:	SetStandard("una yegua negra","yegua",10+random(4),GENERO_FEMENINO);
  		SetIds(({"yegua","yegua negra"}));
  		SetLong(W("Es una preciosa yegua negra de pelo corto y brillante "
  			"con unas impresionantes pezuñas que imponen respeto. Parece "
  			"un noble animal.\n"));
  		break;
  	case 1:	SetStandard("una yegua moteada","yegua",10+random(4),GENERO_FEMENINO);
  		SetIds(({"yegua","yegua moteada"}));
  		SetLong(W("Es una yegua gris moteada. Tiene un precioso y brillante "
  			"pelo largo grisáceo con motas negras y blancas. Sus patas y "
  			"pezuñas son de muy buenas medidas. Parece una yegua perfecta.\n"));
  		break;
  	case 2:	SetStandard("una yegua parda","yegua",10+random(4),GENERO_FEMENINO);
  		SetIds(({"yegua","yegua parda"}));
  		SetLong(W("Estás contemplando la magnífica figura de una yegua parda. "
  			"Tiene unas patas tan largas y bien formadas que hacen de ella "
  			"la perfecta yegua de mensajería, veloz y resistente. Tiene "
  			"el pelo perfectamente cepillado y liso.\n"));
  		break;
  	case 3:	SetStandard("una yegua blanca","yegua",10+random(4),GENERO_FEMENINO);
  		SetIds(({"yegua","yegua blanca"}));
  		SetLong(W("Observas una preciosa yegua blanca, con las crines trenzadas "
                        "que le caen hasta la base del cuello. Tiene las patas finas, "
                        "pero muy resistentes. El pelo es medianamente largo y completamente "
                        "blanco. Brilla casi tanto como la luna llena de noche en un cielo "
                        "raso.\n"));
  		break;
  	default:break;
  }
  SetSize(3);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  InitAChats(10,({"  [33mLa yegua relincha nerviosa.[0m\n"}));
  SetHands(({({"pata delantera derecha",1,12}),({"pata delantera izquierda",1,12})}));
  AddSubDetail(({"pezuñas","pezunyas"}),W("Con esas pezuñas se nota que es un excelente "
  	"animal.\n"));
}
