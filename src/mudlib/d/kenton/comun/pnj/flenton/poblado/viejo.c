/***************************************************************************************
 ARCHIVO:	viejo.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Un viejo kender
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un viejo kender","kender",2,GENERO_MASCULINO);
  SetIds(({"viejo","kender"}));
  SetGoChance(0);

  SetShort("un viejo kender");
  SetLong(W("Ves un viejo kender. Tiene una larga y blanca barba, señal de "
  	"su avanzada edad, mas si no fuera por eso no podrías asegurar que no "
  	"se trata de un joven. Sus ojos tienen la vivacidad de un niño, aunque "
  	"algunas pequeñas arrugas surcan su cara cuando sonríe, que es la "
  	"mayor parte del tiempo.\n"));
  InitChats(5,({
  	"El kender te mira de arriba a abajo.\n",
  	"El kender sonríe.\n",
  	"El kender dice: ¡Hola! ¿quién eres?\n"}) );
  InitAChats(10,({
  	"El kender dice: ¡¡Eh!! ¿qué haces? ¿por qué me atacas?\n",
	"El kender grita: ¡Kendarg! ¡Kendarg! ¡¡ayúdame!!\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
