/*
* Un cuervo
*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>
#include <sounds.h>

inherit NPC;

public void snd_graznido();

create ()
{
	::create();

	seteuid(getuid());
	SetStandard("un cuervo", "cuervo", ([GC_LUCHADOR: 5+random(2)]), GENERO_MASCULINO);
	SetShort("un cuervo");
	SetLong("Es un pájaro negro como el carbón. El pico es fuerte, negro y ligeramente curvado. La cola es relativamente larga, el cuello es bastante grueso, y el iris es marrón oscuro. Su plumaje posee reflejos iridiscentes azulados y púrpuras.\n");
	AddId("cuervo");
	switch (random(10))
	{
		case 0..5: SetAggressive(0); break;
		case 6..8: SetAggressive(1); break;
		case 9: SetAggressive(2); break;
	}
	SetAlign(-400+random(800));
	SetSize(P_SIZE_MEDIUM);
	SetWeight(700+random(1000));
	InitChats(3, ({"El cuervo te observa mientras ladea la cabeza.\n",
			"Crees escuchar que el cuervo ha graznado tu nombre. Es un mal augurio.\n",
			SF(snd_graznido)
			}));
	InitAChats(20, ({"El cuervo extiende sus alas para parecer más grande.\n",
			"El cuervo se lanza en picado.\n",
			"El cuervo intenta sacarte los ojos.\n"
			}));
	SetSmell("El olor del cuervo es tan sutil que no llegas a percibirlo.\n");
	SetNoise("Oyes al cuervo graznar.\n");
	SetShrugMsg("El cuervo te observa atentamente y te responde con un graznido.\n");
	SetWhimpy(QueryLevel()/2);
	SetMsgIn("viene volando");
	SetMsgOut("se va volando");
	SetHands(({
		({"el pico", TD_PENETRACION, 0}),
		({"la garra delantera derecha", TD_APLASTAMIENTO, 0}),
		({"la garra delantera izquierda", TD_APLASTAMIENTO, 0})
	}));
}

public void snd_graznido()
{
	tell_room(environment(), "El cuervo grazna: 'rrok...rrok...kraa'\n");
	if (random(2))
	 	play_sound(environment(), SND_PNJS("cuervo1"));
	else
	 	play_sound(environment(), SND_PNJS("cuervo2"));
}
