/***************************************************************************************
 ARCHIVO:	hombre.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Un hombre kender
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un kender","kender",2+random(11),GENERO_MASCULINO);
  SetIds(({"hombre","kender"}));
  SetGoChance(5);

  SetShort("un kender");
  SetLong(W("Ves un kender. Por su sangre corre la inquietud en persona. "
  	"Sus ojos se mueven de un lado a otro como si nada pudiera escapar "
  	"a su percepción.\n"));

  InitChats(5,({
  	"El kender te mira de arriba abajo.\n",
	"El kender sonrie.\n",
	"El kender dice: ¡Hola! ¿quien eres?\n"}));
  InitAChats(10,({
  	"El kender dice: ¡¡Eh!! ¿¿qué haces?? ¿¿por qué me atacas??\n",
	"El kender grita: ¡Kendarg! ¡Kendarg! ¡¡ayúdame!!\n"}));

  AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":5,"cobre":10])]));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
