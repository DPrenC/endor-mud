/****************************************************************************
Fichero: armario.c
Autor: Tagoras
Fecha: 04/0r/2009
Descripción: un armario para el almacen del centro
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <lock.h>

inherit "/obj/chest";

public create()
{
	::create();

	SetShort("un armario");
	SetLong("Es un armario en el que sospechas que se guardan las mejores armas del centro. Está fabricado con madera resistente así que no podrás forzarlo, pero sí abrirlo con la llave.\n");
	SetIntShort("un armario");
	SetIntLong("en un armario");
	AddId("armario");
	SetAds(({"un", "de", "del", "almacen", "almacén"}));
	SetSize(P_SIZE_LARGE);
	Set(P_NOGET, 1);
	Set(P_GENDER, GENDER_MALE);

	SetLockState(LOCK_OPEN);
	AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE);
	AddItem(ARMA_CENTRO_ANNUFAM("mangual"), REFRESH_REMOVE);

	SetKeyIds("llave_almacen_annufam");
	SetLockState(LOCK_LOCKED);
}


public varargs int fopen (string str, int where)
{
	object guardian;

	if (str && ("armario" == trim(LOWER(str))) && (guardian = present("tripanain", environment(TP))) && living(guardian))
	{
		write("Tripanain te grita: ¡Pero bueno! ¿Qué pretendes hacer abriendo ese armario?\n");
		say("Tripanain le grita a "+ CAP(TNAME)+ ".\n", TP);
		guardian->Kill(TP);
		return 1;
	}
	else
		return ::fopen(str, where);
}
