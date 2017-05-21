/***************************************************************************************
 ARCHIVO:	potro.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un potro
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  switch(random(4))
  {
  	case 0:	SetStandard("un potro negro","potro",6+random(5),GENERO_MASCULINO);
  		SetIds(({"potro","potro negro"}));
  		SetShort("un potro negro");
  		SetLong(W("Es un precioso potro negro de pelo corto y brillante. "
  			"Es muy joven, pero seguro que será un perfecto caballo de "
  			"mayor.\n"));
  		break;
  	case 1:	SetStandard("un potro gris","potro",6+random(5),GENERO_MASCULINO);
  		SetIds(({"potro","potro gris"}));
  		SetLong(W("Es un bonito potro de pelo gris largo, con las patas "
  			"anchas y llenas de pelo. Parece muy inteligente y juguetón. "
  			"Tiene la crin cortada para que no le tape los ojos y pueda "
  			"ver con claridad.\n"));
  		break;
  	case 2:	SetStandard("un potro pardo","potro",6+random(5),GENERO_MASCULINO);
  		SetIds(({"potro","potro pardo"}));
  		SetLong(W("Estás contemplando la magnífica figura de un potro pardo. "
  			"Tiene unas patas largas y bien formadas que hacen de él "
  			"un futuro caballo de pura sangre. Tiene el pelo perfectamente "
  			"cepillado y liso.\n"));
  		break;
  	case 3:	SetStandard("un potro blanco","potro",6+random(5),GENERO_MASCULINO);
  		SetIds(({"potro","potro blanco"}));
  		SetLong(W("Este es un potro blanco de pelo corto. Tiene las crines "
  			"trenzadas de una forma que le caen por el lomo y las patas "
  			"anchas y muy bien formadas. Parece un estupendo potro.\n"));
  		break;
  	default:break;
  }
  SetSize(2);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  InitAChats(10,({"  [33mEl potro relincha nervioso.[0m\n"}));
  SetHands(({({"pata delantera derecha",1,10}),({"pata delantera izquierda",1,10})}));
}
