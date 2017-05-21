/****************************************************************************
Fichero: azor.c
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
	SetStandard("un azor", "animal", 10+d2(), GENDER_MALE);
	SetShort("Un azor");
	SetLong("Es un ave rapaz con el plumaje de color gris por el dorso, la cola y las "
	  "alas, y blanco y castaño oscuro por el pecho. Sus alas relativamente cortas y "
	  "con el extremo redondeado le facilitan el vuelo y la maniobrabilidad en ámbitos "
	  "como los bosques. Las patas son cortas y fuertes, con afiladas garras. El pico es "
	  "ligeramente curvado, temible a corta distancia.\n"
	  "Éstas aves suelen ser entrenadas para la cetrería en zonas de bosques espesos.\n");
	AddId(({"azor", "ave", "pájaro", "pajaro"}));
	InitChats(3, ({"El azor lanza un agudo chillido.\n",
	   "El azor se limpia el plumaje con el afilado pico.\n",
	    "El azor te mira con sus ojillos negros.\n"}));
	InitAChats(20, ({"El azor se lanza al ataque con las garras por delante.\n",
	     "El azor asesta feroces picotazos.\n",
	     "El azor aletea mientras lanza chillidos de furia.\n"}));
	  SetAggressive(random(2));
	SetWeight(2200);
    SetHands(({({"el pico", TD_CORTE,0})}));
	SetCitizenship("nandor");
}
