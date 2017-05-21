/***************************************************************************************
 ARCHIVO:	gato.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un gato (varios, en realidad)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <sounds.h>
inherit NPC;
public void snd_gato();
create(){
  ::create();
  switch(random(4))
  {
  	case 0:	SetStandard("un gato negro","gato",4+random(5),GENERO_MASCULINO);
  		SetIds(({"gato","gato negro"}));
  		SetShort("un gato negro");
  		SetLong("Es un precioso gato negro que vagabundea por esta zona. "
  			"Tiene los ojos verdes e hipnóticos.\n");
  		break;
  	case 1:	SetStandard("un gato gris","gato",4+random(5),GENERO_MASCULINO);
  		SetIds(({"gato","gato gris"}));
  		SetLong("Es un bonito gato de pelo gris largo con los bigotes "
  			"más grandes que has visto nunca.\n");
  		break;
  	case 2:	SetStandard("un gato pardo","gato",4+random(5),GENERO_MASCULINO);
  		SetIds(({"gato","gato pardo"}));
  		SetLong("Es un bonito gato pardo con uñas afiladas y ojos penetrantes.\n");
  		break;
  	case 3:	SetStandard("un gato blanco","gato",4+random(5),GENERO_MASCULINO);
  		SetIds(({"gato","gato blanco"}));
  		SetLong("Este es un gato blanco de pelo largo. Parece que busca algo "
  			"o símplemente se pasea. Quién sabe lo que pasa por su mente.\n");
  		break;
  	default:break;
  }
  SetSize(1);
  SetGoChance(20);
  SetWhimpy(0);
    InitChats(2, SF(snd_gato));
  InitAChats(10,({"  [50mEl gato te clava las uñas en la cara.[0m\n"}));
  SetHands(({({"pata delantera derecha",1,5}),({"pata delantera izquierda",1,5}),({"los dientes",1,8})}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryEntrarGato())
		return:: move(dest,method,stuff);
	else if(method!=M_GO)
		return ::move(dest,method,stuff);
	return ME_NO_ENTER;

}

public void snd_gato(){
    play_sound(environment(), SND_PNJS("gato"));
}
