/*
Una tiza
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit THING;

#define CELDA		"/d/limbo/comun/habitacion/limbo/torrewiz/rooms/tagoras/celda"
#define MAX_USES	1000
#define BB_CAPACITY 10

protected int nUses;

public void DoWrite(string str);

public int QueryUses() { return nUses; }
public int SetUses(int uses) { return nUses=uses; }
public int AddUses(string str)
{
	object pizarra = present("pizarra", environment(TP));

	if (!str || ("" == trim(str)))
		return notify_fail("¿Escribir dónde?", NOTIFY_ILL_ARG);
	if ((str != "pizarra") && (str != "en pizarra") && (str != "en la pizarra"))
		return notify_fail("Ahí no puedes escribir.", NOTIFY_ILL_ARG);
	if (!pizarra)
		return notify_fail("No ves ninguna pizarra por los alrededores.", NOTIFY_NOT_OBJ);
	if (sizeof(pizarra->QueryBBWritten()) >= BB_CAPACITY)
		return notify_fail("La pizarra está totalmente llena de frases. Primero habrás de borrarla.\n", NOTIFY_NOT_VALID);

	write("¿Qué es lo que quieres escribir?\n");
	input_to("DoWrite");

	return 1;
}

public void DoWrite(string str)
{
	object pizarra = present("pizarra", environment(TP));

	if (!str || ("" == trim(str)))
	{
		write ("No has escrito nada\n");
		return;
	}
	nUses++;
	pizarra->AddBBWritten(trim(str));
	write ("Escribes en la pizarra '"+trim(str)+"'.\n");
	say (CAP(TNAME)+" escribe algo en la pizarra.\n", TP);
	CELDA->CheckPhrase(TP, trim(str));
	if (nUses >= MAX_USES)
	{
		write("La tiza se ha acabado.\n");
		call_out("remove", 1);
	}
}

public string QueryExaLong()
{
	switch (nUses)
	{
		case 0: return "Está perfecta.\n";
		case 1..200: return "Está casi perfecta.\n";
		case 201..400: return "Tiene algo de uso.\n";
		case 401..600: return "Tiene bastante uso.\n";
		case 601..800: return "Tiene mucho uso.\n";
		default: return "Está casi gastada.\n";
	}
}

public void create()
{
	::create();
	SetShort("una tiza");
	SetLong("Es un trozo de tiza "+TC_WHITE+"blanca"+TC_NORMAL+" de los que se usan para escribir en pizarras.\n");
	AddId("tiza");
	SetSize(P_SIZE_SMALL);
	SetGender(GENERO_FEMENINO);
}

public void init()
{
	::init();
	add_action("AddUses", "escribir");
}
