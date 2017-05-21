/***************************************************************************************
 ARCHIVO:	ninyo.c
 AUTOR:		[k] Korsario
 FECHA:		05-04-1998
 COMENTARIOS:	Un niño kender
 MODIFICACION:  27-04-2003 Añado botones para un quest.
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
			return "El niño coge una rana.\n";
		}
	}
	return "El niño te mira y sonrie de oreja a oreja.\n";
}

create(){
  ::create();
  SetStandard("un niño kender","kender",2+random(11),GENERO_MASCULINO);
  SetIds(({"niño","ninyo","kender"}));
  SetGoChance(6);

  SetShort("un niño kender");
  SetLong(W("Es un niño kender. Parece muy inquieto, y bastante despierto. "
  	"Te mira con mucha curiosidad. Tiene la cara y las manos sucias de "
  	"jugar con tierra.\n"));

  InitChats(5,({
  	"El niño dice: ¡¡Hola!! ¿¿Cómo te llamas??\n",
	"El niño dice: Me encanta eso que llevas ahí... ¿me lo das?\n",
	"El niño se sienta y se pone a jugar con la tierra...\n",
	"El niño comienza a hurgarse la nariz.\n",
	W("El niño dice: ¿Sabes que soy amigo de Kendarg, el héroe local?\nEl niño "
		"asiente repetidamente muy orgulloso.\n"),
	SF(frana)}));
  InitAChats(10,({W("El niño te mira con una carita de pena y con lágrimas "
  	"en los ojos.\n")}));
  if (!random(3)) AddItem("/d/simauria/comun/objeto/otro/rhoemas/koek/varios/botones",REFRESH_REMOVE);
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
