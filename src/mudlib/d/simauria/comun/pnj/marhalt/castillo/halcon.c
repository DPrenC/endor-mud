/****************************************************************************
Fichero: halcon.c
Autor: Ratwor
Fecha: 20/04/2008
Descripci�n: unas aves para las pajareras del castillo
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;
create()
{
    ::create();
	SetStandard("un halc�n", "animal", 11+d2(), GENDER_MALE);
	SetShort("Un halc�n");
	SetLong("El halc�n es un ave de presa  estilizada y de gran elegancia, cuyas alas, "
	"incluso plegadas superan la longitud de la cola. Bajo los atentos ojillos, las "
	"plumas son negras, mientras que las del vientre son amarillentas con rayas "
	"negras horizontales, y de color gris las de las alas.\n"
	"Es un ave muy usada en la cetrer�a cuando esta se practica en zonas abiertas por su "
	"gran velocidad de vuelo.\n");
	AddId(({"halc�n", "halcon", "ave", "p�jaro", "pajaro"}));
	InitChats(3, ({"El halc�n lanza un agudo chillido.\n",
	     "El halc�n se limpia el plumaje con el afilado pico.\n",
	    "El halc�n te mira con sus ojillos negros.\n"}));
	InitAChats(20, ({"El halc�n se lanza al ataque con las garras por delante.\n",
	     "El halc�n asesta feroces picotazos.\n",
	     "El halc�n aletea mientras lanza chillidos de furia.\n"}));
	SetAggressive(random(2));
	SetWeight(2000);
	SetHands(({({"el pico", TD_CORTE,0})}));
	SetCitizenship("nandor");
}
