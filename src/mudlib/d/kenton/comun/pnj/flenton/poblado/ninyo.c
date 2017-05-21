/***************************************************************************************
 ARCHIVO:	ninyo.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Un ni�o kender
 MODIFICACION:  27-04-2003 A�ado botones para un quest.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

string frana()
{
	object rana;
	if (environment(TO) && present("rana",environment(TO)))
	{
		rana=present("rana",environment(TO));
		if (random(10)==7)
		{
			rana->move(TO);
			return "El ni�o coge una rana.\n";
		}
	}
	return "El ni�o te mira y sonrie de oreja a oreja.\n";
}

create(){
  ::create();
  SetStandard("un ni�o kender","kender",2+random(11),GENERO_MASCULINO);
  SetIds(({"ni�o","ninyo","kender"}));
  SetGoChance(6);

  SetShort("un ni�o kender");
  SetLong(W("Es un ni�o kender. Parece muy inquieto, y bastante despierto. "
  	"Te mira con mucha curiosidad. Tiene la cara y las manos sucias de "
  	"jugar con tierra.\n"));

  InitChats(5,({
  	"El ni�o dice: ��Hola!! ��C�mo te llamas??\n",
	"El ni�o dice: Me encanta eso que llevas ah�... �me lo das?\n",
	"El ni�o se sienta y se pone a jugar con la tierra...\n",
	"El ni�o comienza a hurgarse la nariz.\n",
	W("El ni�o dice: �Sabes que soy amigo de Kendarg, el h�roe local?\nEl ni�o "
		"asiente repetidamente muy orgulloso.\n"),
	SF(frana)}));
  InitAChats(10,({W("El ni�o te mira con una carita de pena y con l�grimas "
  	"en los ojos.\n")}));
  if (!random(3)) AddItem("/d/simauria/comun/objeto/otro/rhoemas/koek/varios/botones",REFRESH_REMOVE);
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
