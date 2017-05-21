/*
Borrado para la pizarra
*/

#include "path.h"
#include <combat.h>
#include <properties.h>

inherit THING;

#define CLEANER_USES	10

protected int nUses;

int QueryUses() { return nUses; }
int SetUses(int uses) { return nUses = uses; }
int AddUses(string str)
{
	object pizarra = present("pizarra", environment(TP));

	if (!str || ("" == trim(str)))
		return notify_fail("¿Borrar qué?\n", NOTIFY_ILL_ARG);
	if (str != "pizarra")
		return notify_fail("Eso no se puede borrar.\n", NOTIFY_ILL_ARG);
	if (!pizarra)
		return notify_fail("No ves ninguna pizarra por los alrededores.\n", NOTIFY_NOT_OBJ);
	if (!pizarra->QueryBBWritten() || !sizeof(pizarra->QueryBBWritten()))
		return notify_fail("Pero si ya está borrada.\n", NOTIFY_NOT_VALID);
	if (nUses >= CLEANER_USES)
		return notify_fail("El borrador está demasiado sucio para borrar nada más. Primero habrás de limpiarlo.\n", NOTIFY_NOT_VALID);

	write ("Borras la pizarra y la dejas totalmente limpia.\n");
	say(CAP(TNAME)+" usa el borrador y deja la pizarra totalmente limpia.\n", TP);
	pizarra->ClearBBWritten();
	nUses++;

	return 1;
}
int ClearUses(string str)
{
	if (!str)
		return notify_fail("¿Limpiar qué?\n", NOTIFY_ILL_ARG);
	if (str != "borrador")
		return notify_fail("Eso no lo puedes limpiar.\n", NOTIFY_ILL_ARG);
	if (nUses < CLEANER_USES)
		return notify_fail("Aún se puede usar, ya lo limpiarás más tarde.\n", NOTIFY_NOT_VALID);
	nUses=0;
	if (TP)
	{
		write("Golpeas el borrador contra las paredes hasta que lo dejas limpio.\nEste suelta una cantidad de polvo de tiza que te hace toser.\n");
		say(CAP(TNAME)+" golpea el borrador contra las paredes y genera una pequeña nube de tiza alrededor.\nVes que comienza a toser.\n", TP);
		TP->Defend(10, TD_VENENO, DEFEND_NOLIV | DEFEND_NOMSG);
		say("Coogh, coogh...\n");
	}

	return 1;
}

public string QueryExaLong()
{
	switch(nUses)
	{
		case 0: return "Está totalmente limpio.\n";
		case 1..3: return "Está algo sucio.\n";
		case 4..6: return "Está bastante sucio.\n";
		case 7..9: return "Está muy sucio.\n";
		default: return "Está tan sucio que no puedes usarse. Deberías limpiarlo primero.\n";
	}
}

public void create()
{
	::create();
	SetShort("un borrador");
	SetLong("Es un borrador para pizarras.\n");
	AddId("borrador");
	SetSize(P_SIZE_SMALL);
}

public void init()
{
	::init();

	add_action("AddUses", "borrar");
	add_action("ClearUses", "limpiar");
}
