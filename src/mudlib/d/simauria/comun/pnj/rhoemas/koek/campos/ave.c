/***************************************************************************************
 ARCHIVO:	ave.c
 AUTOR:		[z] Zomax
 FECHA:		31-10-2001
 COMENTARIOS:	Peque�a ave que se alimenta en los campos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un p�jaro","pajaro",1+random(2),GENERO_MASCULINO);
  SetShort("un p�jaro");
  SetLong(W("Es un peque�o p�jaro que se deleita picoteando todo lo que encuentra "
  	"a su paso. Parece que no teme a nada ni a nadie, y campa por el lugar a "
  	"sus anchas.\n"));
  SetIds(({"pajaro","p�jaro"}));
  SetAds(({"peque�o"}));
  SetNoise("De vez en cuando suelta un peque�o trino de alegr�a.\n");
  SetAggressive(0);
  SetGoChance(0);
  SetWeight(750);
  SetHands(({({"ala derecha",1,3}),({"ala izquierda",1,3}),({"el pico",1,4})}));
}
