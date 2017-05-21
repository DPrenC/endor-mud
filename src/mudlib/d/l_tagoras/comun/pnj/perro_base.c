/*
* Objeto base para la definición de perros
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
// Pequeñas
#define DR_BEAGLE				8
// Toy
#define DR_CHIHUAHUA			9
// Numero de razas
#define DR_NUMERO				10

/* El tamaño del perro determina diferentes cosas:
* El nivel: 5*el tamaño+aleatorio(5). Pequeño de 5 a 9, Mediano de 10 a 14, Grande de 15 a 19 y Enorme de 20 a 24
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
	"mastín",
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
	"Es un perro bastante grande, que destaca por su capa lisa y negra con partes bien definidas de color fuego. Sus dientes son muy grandes y fácilmente podrían matarte.",
	"Lo primero en que te fijas es en su largo pelo. Además su cabeza es larga y su cola termina en anillo. Te parece que ha de ser tremendamente ágil y veloz.",
	"Es un perro de pelo largo con una apariencia de gran belleza, que se yergue con serena dignidad y en el que cada parte está en proporción al conjunto.",
	"Es un perro de contextura fuerte, región renal corta y muy activo, tiene un cráneo amplio, pecho y costillas amplias y profundas; la región renal y los miembros posteriores son anchos y fuertes.",
	"Eso no es un perro corriente, con semejante cabezón no entiendes como puede sobrevivir un bicho así en los tiempos que corren.",
	"Es un perro de tamaño mediano y de aspecto elegante. Da la impresión de fortaleza, resistencia, flexibilidad, gracia, dignidad y confianza en sí mismo. Su expresión, comúnmente llamada \"sonrisa de Samoyedo\" resulta de la combinación de la forma y posición de los ojos con la boca ligeramente curvada hacia arriba.",
	"Este perro tiene un aspecto musculoso en las patas y un pelaje suave y corto. Tiene las orejas bastante largas.",
	"El perro más pequeño que has visto jamás. No te extrañaría que una rata de buen tamaño se lo pudiera comer."
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
			write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y él se deja acariciar afectuosamente.\n");
			say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y éste se deja acariciar afectuosamente.\n", TP);
			return 1;
		}
		if (TP->QueryAlign()<(TO->QueryAlign()-100))
		{
			write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y él te muerde.\n");
			say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y éste le muerde.\n", TP);
			TP->Defend(1+random(TO->QueryLevel()), TD_PENETRACION, DEFEND_NOMSG);
			return 1;
		}
		// Alignment +- 100
		write("Acercas la mano para acariciar al "+dog_names[dog_race]+" y él se aparta de tí gruñendo y ladrándote.\n");
		say(CAP(TP->QueryName())+" le acerca la mano al "+dog_names[dog_race]+" para acariciarle y éste se aparta gruñendo y ladrando.\n", TP);
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
	InitChats(3, ({"El "+dog_names[dog_race]+" te gruñe amenazadoramente.\n",
			"El "+dog_names[dog_race]+" te mira con ojos feroces.\n",
			"El "+dog_names[dog_race]+" enseña los dientes.\n",
			SF(snd_ladrido)}));
	InitAChats(20, ({"El "+dog_names[dog_race]+" lanza feroces dentelladas.\n",
			"El "+dog_names[dog_race]+" ladra furiosamente.\n",
			"El "+dog_names[dog_race]+" se lanza hacia adelante y cierra sus fuertes mandíbulas.\n",
			"El "+dog_names[dog_race]+" asesta una veloz dentellada.\n",
			SF(snd_grunyido)}));
	SetSmell("Claramente huele a "+dog_names[dog_race]+". ¿Qué te esperabas? ¿Qué oliera a rosas?\n");
	SetNoise("Oyes al "+dog_names[dog_race]+" jadear y lanzar algún ladrido de vez en cuando.\n");
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
	InitChats(3, ({"El "+dog_names[dog_race]+" te gruñe amenazadoramente.\n",
			"El "+dog_names[dog_race]+" te mira con ojos feroces.\n",
			"El "+dog_names[dog_race]+" enseña los dientes.\n",
			SF(snd_ladrido)}));
	InitAChats(20, ({"El "+dog_names[dog_race]+" lanza feroces dentelladas.\n",
			"El "+dog_names[dog_race]+" ladra furiosamente.\n",
			"El "+dog_names[dog_race]+" se lanza hacia adelante y cierra sus fuertes mandíbulas.\n",
			"El "+dog_names[dog_race]+" asesta una veloz dentellada.\n",
			SF(snd_grunyido)}));
	SetSmell("Claramente huele a "+dog_names[dog_race]+". ¿Qué te esperabas? ¿Qué oliera a rosas?\n");
	SetNoise("Oyes al "+dog_names[dog_race]+" jadear y lanzar algún ladrido de vez en cuando.\n");
	SetShrugMsg("El "+dog_names[dog_race]+" te observa atentamente y te responde con un ladrido.\n");
	SetWhimpy(QueryLevel()/2);
}

public void snd_ladrido()
{
	tell_room(environment(), "El "+dog_names[dog_race]+" ladra: '¡¡Guau, guau!!'\n");
	if (P_SIZE_SMALL != dog_sizes[dog_race])
		play_sound(environment(), SND_PNJS("ladrido"));
	else
		play_sound(environment(), SND_PNJS("perro_pequeno"),0, 100, 2);
}

public void snd_grunyido()
{
	tell_room(environment(), "El "+dog_names[dog_race]+" gruñe: 'Grrrr...'\n");
	if (P_SIZE_SMALL != dog_sizes[dog_race])
		play_sound(environment(), SND_PNJS("grunido"));
	else
		play_sound(environment(), SND_PNJS("grunido_pequeno"));
}
