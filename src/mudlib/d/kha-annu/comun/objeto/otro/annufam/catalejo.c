/****************************************************************************
Fichero: catalejo.c
Autor: Riberales
       [T] Tagoras
Creación: 9/10/2005
Descripción: Catalejo del vigía, sucedáneo del arco.
[T] 09-03-2009: Añado la función cmd_observar
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
		return notify_fail("Estás bajo cubierto, ¿cómo quieres observar algo?\n", NOTIFY_NOT_VALID);	
	if (-1 != member(({ND_NIGHT, ND_PREDAWN, ND_FALL, ND_PRENIGHT}), NIGHTDAY->QueryState()))
		return notify_fail("¿Cómo quieres ver algo de noche?\n", NOTIFY_NOT_VALID);
	if (-1 == strstr(room->QueryIntShort(), "murallas"))
		return notify_fail("Deberías ir a un lugar elevado para poder observar algo interesante.\n", NOTIFY_NOT_VALID);
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
            "distancias. Éste es cilíndrico y de madera, con una lente en "
            "cada extremo. Si observas por el ves lo que hay más allá de tu "
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
