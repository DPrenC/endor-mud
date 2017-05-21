/*
* Objeto base para la definición de lobos
*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>
#include <sounds.h>

inherit NPC;

string * wolf_colors = ({ "gris", "blanco", "pardo", "rojo", "negro" });
string wolf_color = "";

public void snd_aullido();
public void snd_grunyido();

create ()
{
	::create();

	seteuid(getuid());
	wolf_color = wolf_colors[random(sizeof(wolf_colors))];
	SetStandard("un lobo "+wolf_color, "lobo", ([GC_LUCHADOR: 25+random(10)]), GENERO_MASCULINO);
	SetShort("un lobo "+wolf_color);
	SetLong("Un magnífico ejemplar de lobo "+wolf_color+". Su cabeza es puntiaguda, con hocico puntiagudo, orejas cortas triangulares y rígidas; ojos triangulares de color dorado o amarillo oscuro. Patas fuertes y robustas, con cinco dedos en la delantera y cuatro en las traseras.\n");
	AddId("lobo "+wolf_color);
	switch (random(10))
	{
		case 0..5: SetAggressive(0); break;
		case 6..8: SetAggressive(1); break;
		case 9: SetAggressive(2); break;
	}
	SetAlign(-400+random(800));
	SetSize(P_SIZE_LARGE);
	SetWeight(45000);
	InitChats(3, ({"El lobo "+wolf_color+" te gruñe amenazadoramente.\n",
			"El lobo "+wolf_color+" te mira con ojos feroces.\n",
			"El lobo "+wolf_color+" enseña los dientes.\n",
			SF(snd_aullido),
			SF(snd_grunyido),
			}));
	InitAChats(20, ({"El lobo "+wolf_color+" lanza feroces dentelladas.\n",
			"El lobo "+wolf_color+" gruñe furiosamente.\n",
			"El lobo "+wolf_color+" se lanza hacia adelante y cierra sus fuertes mandíbulas.\n",
			"El lobo "+wolf_color+" asesta una veloz dentellada.\n",
			}));
	SetSmell("Claramente huele a lobo "+wolf_color+". ¿Qué te esperabas? ¿Qué oliera a rosas?\n");
	SetNoise("Oyes al lobo "+wolf_color+" jadear y lanzar algún aullido de vez en cuando.\n");
	SetShrugMsg("El lobo "+wolf_color+" te observa atentamente y te responde con un gruñido.\n");
	SetWhimpy(QueryLevel()/2);
	SetMsgIn("viene corriendo");
	SetMsgOut("se va corriendo");
	SetHands(({
		({"los dientes", TD_PENETRACION, 0}),
		({"la pata delantera derecha", TD_APLASTAMIENTO, 0}),
		({"la pata delantera izquierda", TD_APLASTAMIENTO, 0})
	}));
}

public void snd_aullido()
{
	tell_room(environment(), "El lobo "+wolf_color+" aulla: AUUUUUUUUUUUUUUUUUUUUUUUU...\n");
	play_sound(environment(), SND_PNJS("lobo_aullido"));
}

public void snd_grunyido()
{
	tell_room(environment(), "El lobo "+wolf_color+" gruñe: GRRR....GRRR...\n");
	play_sound(environment(), SND_PNJS("lobo_grunyido"));
}
