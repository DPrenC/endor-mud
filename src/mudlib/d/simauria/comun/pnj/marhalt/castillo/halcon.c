/****************************************************************************
Fichero: halcon.c
Autor: Ratwor
Fecha: 20/04/2008
Descripción: unas aves para las pajareras del castillo
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;
create()
{
    ::create();
	SetStandard("un halcón", "animal", 11+d2(), GENDER_MALE);
	SetShort("Un halcón");
	SetLong("El halcón es un ave de presa  estilizada y de gran elegancia, cuyas alas, "
	"incluso plegadas superan la longitud de la cola. Bajo los atentos ojillos, las "
	"plumas son negras, mientras que las del vientre son amarillentas con rayas "
	"negras horizontales, y de color gris las de las alas.\n"
	"Es un ave muy usada en la cetrería cuando esta se practica en zonas abiertas por su "
	"gran velocidad de vuelo.\n");
	AddId(({"halcón", "halcon", "ave", "pájaro", "pajaro"}));
	InitChats(3, ({"El halcón lanza un agudo chillido.\n",
	     "El halcón se limpia el plumaje con el afilado pico.\n",
	    "El halcón te mira con sus ojillos negros.\n"}));
	InitAChats(20, ({"El halcón se lanza al ataque con las garras por delante.\n",
	     "El halcón asesta feroces picotazos.\n",
	     "El halcón aletea mientras lanza chillidos de furia.\n"}));
	SetAggressive(random(2));
	SetWeight(2000);
	SetHands(({({"el pico", TD_CORTE,0})}));
	SetCitizenship("nandor");
}
