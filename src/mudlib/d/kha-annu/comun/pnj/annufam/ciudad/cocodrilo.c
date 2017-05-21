/**************************************************************************
fichero: cocodrilo.c
Autor: kastwey
		[T] Tagoras
Creaci�n: 20/07/2005
Descripci�n: El cocodrilo del foso
[T] 21/03/2009: A�ado la posibilidad de que al morir el cocodrilo vomite un destornillador.
**************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public void create()
{
	::create();
	SetStandard("un feroz cocodrilo", "cocodrilo", 12, GENDER_MALE);
	SetLong("Es un cocodrilo de casi tres metros de largo y con una boca "
			"en la que cabr�an siete enanos de este dominio. Las escamas "
			"parecen dagas y un golpe de su cola podr�a atontar a "
			"cualquiera. Te est� mirando amenazadoramente.\n");
	SetAggressive(1);
}

public varargs void Die(int silent)
{
	if (0 == random(4))
	{
		object destornillador;
		destornillador = clone_object(OTRO_ANNUFAM("destornillador"));
		destornillador->move(environment());
		tell_room(environment(), "Con los �ltimos estertores el cocodrilo vomita un destornillador que debieron olvidar los artesanos enanos que instalaron las rejillas de evacuaci�n.\n");
	}
	return ::Die(silent);
}
