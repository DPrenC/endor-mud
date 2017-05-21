/**************************************************************************
fichero: Foifur.c
Autor: Riberales
		[T] Tagoras
Creación: 30/08/2005
Descripción: El herrero de Annufam
[T] 20/03/2009: Añado sonidos al herrero.
**************************************************************************/
#include "path.h"
#include <combat.h>
#include <properties.h>
#include <sounds.h>

inherit NPC;

private string golpear();
private string golpe_escudo();
string raza();

public void create()
{
    ::create();
    SetStandard("Foifur","enano",85,GENDER_MALE);
    SetShort("Foifur, el maestro herrero.\n");
    SetLong(W("Foifur es el enano responsable de la herrería. Es el creador y "
              "destructor de todas las armas del Centro. Su mirada severa y "
              "sus brazos llenos de músculo y cicatrices te dicen que "
              "posiblemente fuera un gran guerrero en sus años de juventud, "
              "mas ahora, por causas desconocidas, sirve a su pueblo desde la "
              "fragua y el yunque.\n"));
        SetIds(({"maestro_herrero","foifur","herrero","maestro","maestro herrero"}));

    InitChats(3,({"El herrero introduce una espada usada en el fuego.\n",
                 "Foifur dice: Buf, no voy a dar abasto para el último pedido del Centro.\n",
				SF(golpear),
				SF(golpe_escudo)
                }));

    InitAChats(20,({"Foifur grita: Por Kha-annu, te voy a abrir la cabeza.\n",
                 W("Maldito "+ raza()+ "!\n")}));
}

string raza()
{
    if (TP->QueryRace() != "enano") return TP->QuerRace();
    return QueryRace()+ ", atacar a tu propio pueblo... ¡Traidor";
}

private string golpear()
{
	switch(random(100))
	{
		case 0..89: play_sound(environment(),SND_SUCESOS("herreria_bien")); break;
		case 90..98: play_sound(environment(),SND_SUCESOS("herreria_mal")); break;
		case 99: play_sound(environment(),SND_SUCESOS("herreria_romper")); break;
	}
    return "Foifur usa el martillo.\n";
}

private string golpe_escudo()
{
	play_sound(environment(),SND_SUCESOS("golpe_metalico"));
	return "Foifur golpea un escudo contra el yunque.\n";
}
