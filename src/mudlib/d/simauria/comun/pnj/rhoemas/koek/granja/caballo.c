/***************************************************************************************
 ARCHIVO:	caballo.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un caballo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
 switch(random(4))
  {
  	case 0:	SetStandard("un caballo negro","caballo",10+random(5),GENERO_MASCULINO);
  		SetIds(({"caballo","caballo negro"}));
  		SetLong(W("Es un precioso caballo negro de pelo corto y brillante "
  			"con unas impresionantes pezuñas que imponen respeto. Parece "
  			"un noble animal.\n"));
  		break;
  	case 1:	SetStandard("un caballo gris","caballo",10+random(5),GENERO_MASCULINO);
  		SetIds(({"caballo","caballo gris"}));
  		SetLong(W("Es un bonito caballo de pelo gris largo, con las patas "
  			"anchas y llenas de pelo. Parece muy inteligente y fornido. "
  			"Tiene la crin cortada para que no le tape los ojos y pueda "
  			"ver con claridad.\n"));
  		break;
  	case 2:	SetStandard("un caballo pardo","caballo",10+random(5),GENERO_MASCULINO);
  		SetIds(({"caballo","caballo pardo"}));
  		SetLong(W("Estás contemplando la magnífica figura de un caballo pardo. "
  			"Tiene unas patas tan largas y bien formadas que hacen de él "
  			"el perfecto caballo de mensajería, veloz y resistente. Tiene "
  			"el pelo perfectamente cepillado y liso.\n"));
  		break;
  	case 3:	SetStandard("un caballo blanco","caballo",10+random(5),GENERO_MASCULINO);
  		SetIds(({"caballo","caballo blanco"}));
  		SetLong(W("Este es un caballo blanco de pelo corto. Tiene las crines "
  			"trenzadas de una forma que le caen por el lomo y las patas "
  			"anchas y muy bien formadas. Parece un estupendo caballo.\n"));
  		break;
  	default:break;
  }
  SetSize(3);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  InitAChats(10,({"  [33mEl caballo relincha nervioso.[0m\n"}));
  SetHands(({({"pata delantera derecha",1,13}),({"pata delantera izquierda",1,13})}));
}
