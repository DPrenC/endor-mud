/**************************************************************************
fichero: cocodrilo.c
Autor: kastwey
		[T] Tagoras
Creación: 20/07/2005
Descripción: El cocodrilo del foso
[T] 21/03/2009: Añado la posibilidad de que al morir el cocodrilo vomite un destornillador.
**************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public void create()
{
	::create();
	SetStandard("un feroz cocodrilo", "cocodrilo", 12, GENDER_MALE);
	SetLong("Es un cocodrilo de casi tres metros de largo y con una boca "
			"en la que cabrían siete enanos de este dominio. Las escamas "
			"parecen dagas y un golpe de su cola podría atontar a "
			"cualquiera. Te está mirando amenazadoramente.\n");
	SetAggressive(1);
}

public varargs void Die(int silent)
{
	if (0 == random(4))
	{
		object destornillador;
		destornillador = clone_object(OTRO_ANNUFAM("destornillador"));
		destornillador->move(environment());
		tell_room(environment(), "Con los últimos estertores el cocodrilo vomita un destornillador que debieron olvidar los artesanos enanos que instalaron las rejillas de evacuación.\n");
	}
	return ::Die(silent);
}
