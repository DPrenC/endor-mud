#include "path.h"
#include <properties.h>
#include <colours.h>

inherit THING;

#define AO (TP->QueryGender()==GENERO_FEMENINO?"a":"o")

public string QueryLong()
{
	int i;
	string msg;

	if (TP && !TP->QueryHidden() && !TP->QueryInvis())
	{
		i = (1000 + TP->QueryAlign()) * 17 / 2000;
		if (i > 16) i = 16; else if (i < 0) i = 0;
		msg = "Te ves a ti mism"+AO+" reflejad"+AO+" en el espejo. Te rodea un aura ";
		switch (i)
		{
			case 0..6: msg+=TC_RED+"roja"+TC_NORMAL; break;
			case 7..9: msg+=TC_BLUE+"azul"+TC_NORMAL; break;
			case 10..16: msg+=TC_WHITE+"blanca"+TC_NORMAL; break;
		}
		msg += ".\n";
		return msg;
	}
	else
		return ::QueryLong();
}

public void create()
{
	::create();
	SetShort("un espejo");
	SetLong("Es un espejo con marco de madera.\n");
	AddId("espejo");
}
