/****************************************************************************
Fichero: catalejo.c
Autor: Riberales
       [T] Tagoras
Creaci�n: 9/10/2005
Descripci�n: Catalejo del vig�a, suced�neo del arco.
[T] 09-03-2009: A�ado la funci�n cmd_observar
****************************************************************************/

#include "./path.h"
#include <ansi.h>
#include <nightday.h>

inherit THING;

public int cmd_observar(string str)
{
	object room;

	room = environment(TP);
	if (room->QueryIndoors())
		return notify_fail("Est�s bajo cubierto, �c�mo quieres observar algo?\n", NOTIFY_NOT_VALID);	
	if (-1 != member(({ND_NIGHT, ND_PREDAWN, ND_FALL, ND_PRENIGHT}), NIGHTDAY->QueryState()))
		return notify_fail("�C�mo quieres ver algo de noche?\n", NOTIFY_NOT_VALID);
	if (-1 == strstr(room->QueryIntShort(), "murallas"))
		return notify_fail("Deber�as ir a un lugar elevado para poder observar algo interesante.\n", NOTIFY_NOT_VALID);
	if (-1 != strstr(room->QueryIntShort(), "Annufam"))
		write ( "Ves los alrededores de la ciudad de Annufam.\n" );
	else
		write ( "Ves los alrededores.\n" );
	
	return 1;
}

public void create()
{
    ::create();
    SetShort("un catalejo");
    SetLong("Se trata de un utensilio que sirve para observar largas "
            "distancias. �ste es cil�ndrico y de madera, con una lente en "
            "cada extremo. Si observas por el ves lo que hay m�s all� de tu "
            "alrededor.\n");

    SetIds(({"catalejo"}));
    SetWeight(500);
    SetValue(700);
}

public void init()
{
    ::init();
    add_action("cmd_observar", "observar");
}
