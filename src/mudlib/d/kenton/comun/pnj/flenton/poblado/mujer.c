/***************************************************************************************
 ARCHIVO:	mujer.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Una mujer kender
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("una kender","kender",2+random(8),GENERO_FEMENINO);
  SetIds(({"mujer","kender"}));
  SetGoChance(5);

  SetShort("una kender");
  SetLong(W("Ves una bonita kender. Parece bastante joven, pero quizás "
   	"su vitalidad te engañe. Sus ojos brillan con la curiosidad de una "
   	"niña.\n"));
  InitChats(5,({
  	"La kender te mira con curiosidad.\n",
	"La kender dice: ¿Puedo hacer algo por ti?\n",
	"La kender tararea una melodia y sonrie.\n"}));
  InitAChats(10,({
  	"La kender grita con histerismo: ¡¡AYUDA!! ¡¡AYUDA!! ¡¡me atacan!!!"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
