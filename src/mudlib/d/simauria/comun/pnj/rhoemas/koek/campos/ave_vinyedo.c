/***************************************************************************************
 ARCHIVO:	ave.c
 AUTOR:		[z] Zomax
 FECHA:		31-10-2001
 COMENTARIOS:	Pequeña ave que se alimenta en los campos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un pájaro","pajaro",1+random(2),GENERO_MASCULINO);
  SetShort("un pájaro");
  SetLong(W("Es un pequeño pájaro que se deleita picoteando todo lo que encuentra "
  	"a su paso. Parece que no teme a nada ni a nadie, y campa por el lugar a "
  	"sus anchas.\n"));
  SetIds(({"pajaro","pájaro"}));
  SetAds(({"pequeño"}));
  SetNoise("De vez en cuando suelta un pequeño trino de alegría.\n");
  SetAggressive(0);
  SetGoChance(0);
  SetWeight(750);
  SetHands(({({"ala derecha",1,3}),({"ala izquierda",1,3}),({"el pico",1,4})}));
}
