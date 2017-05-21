/***
Fichero: caballo.c
Autor: Riberales
		[T] Tagoras
Descripción: caballo para el establo de Siempreunidos.
Sacado de los establos de Zarkam.
[T] 20/03/2009: Añado el relincho al caballo
***/

#include "path.h"
#include <properties.h>
#include <sounds.h>

inherit NPC;

string herrero();
private string relinchar();
private string bufar();

public void create()
{
  	::create();
	SetName("caballo");
	SetIds(({"caballo", "animal"}));
	SetAds(({"marrón", "un"}));
	SetShort("un caballo");
	SetLong("Es un precioso caballo de color marrón y largas crines. No sabes de quien será.\n");
	SetWeight(415000);
	SetValue(23000);
	SetLevel(15);
	SetGender(GENDER_MALE);
	Set(P_HANDS, ({
		({"la pata trasera derecha", 0, 4}),
		({"la pata trasera izquierda", 0, 4}),
		({"un mordisco", 0, 7})}));

	InitChats(10, ({
		SF(herrero),
		SF(relinchar),
		SF(bufar),
//		"Hiiiiiii......brrr......hiiiiii.....\n",
		"El caballo come un poco de heno.\n",
//	  "Brrrr.....brrrrr...hiiiiiiii.\n",
//	  "Hiiii...hiiiiii....brrrr...\n",
		"El caballo no parece prestarte especial atención.\n"
	}));
}


init()
{
	(::init());
	add_action("montar", "montar");
	add_action("montar", "coger");
}


montar(string str)
{
	int hp;
	if(!str || !id(str)) return 0;
	write("El caballo se revuelve y te pega una coz. Te ha dolido bastante.\n");
	hp=this_player()->QueryHP();
	hp=(hp-10>0?hp-10:0);
	this_player()->SetHP(hp);
	return 1;
}


string herrero()
{
	if (environment()->QueryCuadraAnnufam())
	{
		return "El herrero entra a la cuadra por la puerta del oeste y cambia las herraduras a un caballo.\n";
	}
	return "El caballo mira hacia todos lados desorientado.\n";
}

private string relinchar()
{
	string * relinchos = ({
		"Hiiiiiii......brrr......hiiiiii.....\n",
		"Brrrr.....brrrrr...hiiiiiiii.\n",
		"Hiiii...hiiiiii....brrrr...\n"
	});

	play_sound(environment(),SND_PNJS("relincho"));
	return relinchos[random(sizeof(relinchos))];
}

private string bufar()
{
	play_sound(environment(),SND_PNJS("bufido_caballo"));
	return "Brrrr.....brrrrr...brrrrrr....\n";
}
