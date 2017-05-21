/*
* Objeto base para la definici�n de perros
*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>
#include <sounds.h>

inherit NPC;

#define DR_CALLEJERO			0
// Gigantes
#define DR_MASTIN				1
#define DR_ROTTWEILER			2
// Grandes
#define DR_LEBREL_AFGANO		3
#define DR_COLLIE				4
#define DR_RETRIEVER_LABRADOR	5
// Medianas
#define DR_BULLDOG				6
#define DR_SAMOYEDO				7
// Peque�as
#define DR_BEAGLE				8
// Toy
#define DR_CHIHUAHUA			9
// Numero de razas
#define DR_NUMERO				10

/* El tama�o del perro determina diferentes cosas:
* El nivel: 5*el tama�o+aleatorio(5). Peque�o de 5 a 9, Mediano de 10 a 14, Grande de 15 a 19 y Enorme de 20 a 24
*/
int * dog_sizes = ({
	P_SIZE_MEDIUM,
	P_SIZE_HUGE,
	P_SIZE_HUGE,
	P_SIZE_LARGE,
	P_SIZE_LARGE,
	P_SIZE_LARGE,
	P_SIZE_MEDIUM,
	P_SIZE_MEDIUM,
	P_SIZE_SMALL,
	P_SIZE_SMALL
});

string * dog_names = ({
	"perro callejero",
	"mast�n",
	"rottweiler",
	"lebrel afgano",
	"collie",
	"retriever labrador",
	"bulldog",
	"samoyedo",
	"beagle",
	"chihuahua"
});

string * dog_longs = ({
	"Es un perro callejero, mezcla de diferentes razas y que no sobresale en ninguna de ellas. Siempre ha vivido en la calle y su aspecto es algo demacrado.",
	"Es un perro de gran corpulencia y alzado. Su pelaje es abundante y semilargo. Tiene una cabeza grande y maciza con unos labios colgantes y carnosos.",
	"Es un perro bastante grande, que destaca por su capa lisa y negra con partes bien definidas de color fuego. Sus dientes son muy grandes y f�cilmente podr�an matarte.",
	"Lo primero en que te fijas es en su largo pelo. Adem�s su cabeza es larga y su cola termina en anillo. Te parece que ha de ser tremendamente �gil y veloz.",
	"Es un perro de pelo largo con una apariencia de gran belleza, que se yergue con serena dignidad y en el que cada parte est� en proporci�n al conjunto.",
	"Es un perro de contextura fuerte, regi�n renal corta y muy activo, tiene un cr�neo amplio, pecho y costillas amplias y profundas; la regi�n renal y los miembros posteriores son anchos y fuertes.",
	"Eso no es un perro corriente, con semejante cabez�n no entiendes como puede sobrevivir un bicho as� en los tiempos que corren.",
	"Es un perro de tama�o mediano y de aspecto elegante. Da la impresi�n de fortaleza, resistencia, flexibilidad, gracia, dignidad y confianza en s� mismo. Su expresi�n, com�nmente llamada \"sonrisa de Samoyedo\" resulta de la combinaci�n de la forma y posici�n de los ojos con la boca ligeramente curvada hacia arriba.",
	"Este perro tiene un aspecto musculoso en las patas y un pelaje suave y corto. Tiene las orejas bastante largas.",
	"El perro m�s peque�o que has visto jam�s. No te extra�ar�a que una rata de buen tama�o se lo pudiera comer."
});

int * dog_weights = ({
	20000,
	83000,
	50000,
	25000,
	28500,
	29500,
	20500,
	25000,
	11000,
	2000
});

int dog_race;

public void snd_ladrido();
public void snd_grunyido();

public int cmd_acariciar(string str)
{
	if (!str) return 0;
	if (str=="perro" || str=="a perro" || str=="al perro" || str==dog_names[dog_race] || str=="a "+dog_names[dog_race]
		|| str=="al "+dog_names[dog_race])
	{
		if (TP->QueryAlign()>(TO->QueryAlign()+100))
		{
			write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y �l se deja acariciar afectuosamente.\n");
			say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y �ste se deja acariciar afectuosamente.\n", TP);
			return 1;
		}
		if (TP->QueryAlign()<(TO->QueryAlign()-100))
		{
			write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y �l te muerde.\n");
			say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y �ste le muerde.\n", TP);
			TP->Defend(1+random(TO->QueryLevel()), TD_PENETRACION, DEFEND_NOMSG);
			return 1;
		}
		// Alignment +- 100
		write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y �l se aparta de t� gru�endo y ladr�ndote.\n");
		say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y �ste se aparta gru�endo y ladrando.\n", TP);
		snd_grunyido();
		return 1;
	}
	return 0;
}

create ()
{
	::create();

	dog_race = random(DR_NUMERO);
	seteuid(getuid());
	SetStandard("un "+dog_names[dog_race], "perro", ([GC_LUCHADOR: 5*dog_sizes[dog_race]+random(5)]), GENERO_MASCULINO);
	SetShort("un "+dog_names[dog_race]);
	SetLong(dog_longs[dog_race]+"\n");
	AddId(dog_names[dog_race]);
	switch (random(10))
	{
		case 0..5: SetAggressive(0); break;
		case 6..8: SetAggressive(1); break;
		case 9: SetAggressive(2); break;
	}
	SetAlign(-100+random(200));
	SetSize(dog_sizes[dog_race]);
	SetWeight(dog_weights[dog_race]);
	InitChats(3, ({"El "+dog_names[dog_race]+" te gru�e amenazadoramente.\n",
			"El "+dog_names[dog_race]+" te mira con ojos feroces.\n",
			"El "+dog_names[dog_race]+" ense�a los dientes.\n",
			SF(snd_ladrido)}));
	InitAChats(20, ({"El "+dog_names[dog_race]+" lanza feroces dentelladas.\n",
			"El "+dog_names[dog_race]+" ladra furiosamente.\n",
			"El "+dog_names[dog_race]+" se lanza hacia adelante y cierra sus fuertes mand�bulas.\n",
			"El "+dog_names[dog_race]+" asesta una veloz dentellada.\n",
			SF(snd_grunyido)}));
	SetSmell("Claramente huele a "+dog_names[dog_race]+". �Qu� te esperabas? �Qu� oliera a rosas?\n");
	SetNoise("Oyes al "+dog_names[dog_race]+" jadear y lanzar alg�n ladrido de vez en cuando.\n");
	SetShrugMsg("El "+dog_names[dog_race]+" te observa atentamente y te responde con un ladrido.\n");
	SetWhimpy(QueryLevel()/2);
	SetMsgIn("viene corriendo");
	SetMsgOut("se va corriendo");
	SetHands(({
		({"los dientes", TD_PENETRACION, 0}),
		({"la pata delantera derecha", TD_APLASTAMIENTO, 0}),
		({"la pata delantera izquierda", TD_APLASTAMIENTO, 0})
	}));
}

init ()
{
	::init();
	add_action("cmd_acariciar", "acariciar");
	add_action("cmd_acariciar", "tocar");
}

public void SetDogRace(int race)
{
	if ((race < 0) || (race >= DR_NUMERO))
		return;
	dog_race = race;
	SetName("un "+dog_names[dog_race]);
	SetLevel(5*dog_sizes[dog_race]+random(5));
	SetShort("un "+dog_names[dog_race]);
	SetLong(dog_longs[dog_race]+"\n");
	SetIds(({"perro", dog_names[dog_race]}));
	SetSize(dog_sizes[dog_race]);
	SetWeight(dog_weights[dog_race]);
	InitChats(3, ({"El "+dog_names[dog_race]+" te gru�e amenazadoramente.\n",
			"El "+dog_names[dog_race]+" te mira con ojos feroces.\n",
			"El "+dog_names[dog_race]+" ense�a los dientes.\n",
			SF(snd_ladrido)}));
	InitAChats(20, ({"El "+dog_names[dog_race]+" lanza feroces dentelladas.\n",
			"El "+dog_names[dog_race]+" ladra furiosamente.\n",
			"El "+dog_names[dog_race]+" se lanza hacia adelante y cierra sus fuertes mand�bulas.\n",
			"El "+dog_names[dog_race]+" asesta una veloz dentellada.\n",
			SF(snd_grunyido)}));
	SetSmell("Claramente huele a "+dog_names[dog_race]+". �Qu� te esperabas? �Qu� oliera a rosas?\n");
	SetNoise("Oyes al "+dog_names[dog_race]+" jadear y lanzar alg�n ladrido de vez en cuando.\n");
	SetShrugMsg("El "+dog_names[dog_race]+" te observa atentamente y te responde con un ladrido.\n");
	SetWhimpy(QueryLevel()/2);
}

public void snd_ladrido()
{
	tell_room(environment(), "El "+dog_names[dog_race]+" ladra: '��Guau, guau!!'\n");
	if (P_SIZE_SMALL != dog_sizes[dog_race])
		play_sound(environment(), SND_PNJS("ladrido"));
	else
		play_sound(environment(), SND_PNJS("perro_pequeno"),0, 100, 2);
}

public void snd_grunyido()
{
	tell_room(environment(), "El "+dog_names[dog_race]+" gru�e: 'Grrrr...'\n");
	if (P_SIZE_SMALL != dog_sizes[dog_race])
		play_sound(environment(), SND_PNJS("grunido"));
	else
		play_sound(environment(), SND_PNJS("grunido_pequeno"));
}
