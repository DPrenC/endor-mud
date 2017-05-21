/****************************************************************************
Fichero: armario_maestro.c
Autor: Tagoras
Fecha: 06/03/2009
Descripci�n: un armario para las habitaciones de los maestros
[T] 20/03/2009: A�adioo sonido al hacer unlock
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <lock.h>
#include <sounds.h>

inherit "/obj/chest";

public create()
{
	::create();

	SetShort("un arc�n");
	SetIntShort("un arc�n");
	SetIntLong("en un arc�n");
	AddId(({"arcon", "arc�n"}));
	SetAds(({"un"}));
	SetSize(P_SIZE_LARGE);
	Set(P_NOGET, 1);
	Set(P_GENDER, GENDER_MALE);

	SetLockState(LOCK_OPEN);
	if (random(2))
		AddItem(ARMA_CENTRO_ANNUFAM("hacha_oficial"), REFRESH_REMOVE);
	SetLockState(LOCK_LOCKED);
	SetPickChance(25);
}

public string QueryLong()
{
	if (LOCK_LOCKED == QueryLockState())
		return "Se trata de un arc�n grande en el que los oficiales enanos guardan sus cosas. Tiene una cerradura bastante fr�gil por lo que piensas que quiz� puedas abrirlo.\n";
	else
		return "Se trata de un arc�n grande en el que los oficiales enanos guardan sus cosas. Tiene una cerradura bastante fr�gil.\n";
}

// Esto es una chapucilla porque no he visto en ning�n lugar la forma de hacer el 'pick' del lock.
public varargs int flock (string str, int where)
{
    if (("unlock" == query_verb()) && str && (("arcon" == trim(LOWER(str))) || ("arc�n" == trim(LOWER(str)))) && (LOCK_LOCKED == QueryLockState())) 
    {
		if (random(100) < QueryPickChance())
		{
        	write("Despu�s de forcejear un rato con el cerrojo, oyes un *click*. Parece que se ha soltado el cierre, ya puedes abrir el arc�n.\n");
        	say("Se oye un ligero *click*.\n", TP);
			SetLockState(LOCK_CLOSED);
			play_sound(environment(),SND_SUCESOS("cerradura"));
        	return 1;
		}
		else
		{
			write("Intentas forzar el cerrojo, pero fallas estrepit�samente y lanzas una maldici�n al inventor de semejante artilugio.\n");
			say(CAP(TNAME)+" forcejea un rato con el cerrojo y al rato lanza una maldici�n que te pone los pelos de punta.\n");
			return 1;
		}
    }
    else
        return ::flock(str, where);
}
