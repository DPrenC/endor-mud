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
  SetLong(W("Ves un viejo kender. Tiene una larga y blanca barba, se�al de "
  	"su avanzada edad, mas si no fuera por eso no podr�as asegurar que no "
  	"se trata de un joven. Sus ojos tienen la vivacidad de un ni�o, aunque "
  	"algunas peque�as arrugas surcan su cara cuando sonr�e, que es la "
  	"mayor parte del tiempo.\n"));
  InitChats(5,({
  	"El kender te mira de arriba a abajo.\n",
  	"El kender sonr�e.\n",
  	"El kender dice: �Hola! �qui�n eres?\n"}) );
  InitAChats(10,({
  	"El kender dice: ��Eh!! �qu� haces? �por qu� me atacas?\n",
	"El kender grita: �Kendarg! �Kendarg! ��ay�dame!!\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
