/****************************************************************************
Fichero: armario_maestro.c
Autor: Tagoras
Fecha: 06/03/2009
Descripción: un armario para las habitaciones de los maestros
[T] 20/03/2009: Añadido sonido al hacer unlock.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <lock.h>
#include <sounds.h>

inherit "/obj/chest";

public create()
{
	::create();

	SetShort("un armario");
	SetIntShort("un armario");
	SetIntLong("en un armario");
	AddId("armario");
	SetAds(({"un"}));
	SetSize(P_SIZE_LARGE);
	Set(P_NOGET, 1);
	Set(P_GENDER, GENDER_MALE);

	SetLockState(LOCK_OPEN);
	if (random(2))
		AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":2])]));
	SetLockState(LOCK_LOCKED);
	SetPickChance(25);
}

public string QueryLong()
{
	if (LOCK_LOCKED == QueryLockState())
		return "Se trata de un armario de hoja doble y con una cerradura muy frágil. Quizá con un poco de maña pudieras abrirlo.\n";
	else
		return "Se trata de un armario de hoja doble y con una cerradura muy frágil.\n";
}

// Esto es una chapucilla porque no he visto en ningún lugar la forma de hacer el 'pick' del lock.
public varargs int flock (string str, int where)
{
    if (("unlock" == query_verb()) && str && ("armario" == trim(LOWER(str))) && (LOCK_LOCKED == QueryLockState()))
    {
		if (random(100) < QueryPickChance())
		{
        	write("Después de forcejear un rato con el cerrojo, oyes un *click*. Parece que se ha soltado el cierre, ya puedes abrir el armario.\n");
        	say("Se oye un ligero *click*.\n", TP);
			SetLockState(LOCK_CLOSED);
			play_sound(environment(),SND_SUCESOS("cerradura"));
        	return 1;
		}
		else
		{
			write("Intentas forzar el cerrojo, pero fallas estrepitósamente y lanzas una maldición al inventor de semejante artilugio.\n");
			say(CAP(TNAME)+" forcejea un rato con el cerrojo y al rato lanza una maldición que te pone los pelos de punta.\n");
			return 1;
		}
    }
    else
        return ::flock(str, where);
}
