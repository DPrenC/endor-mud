/**************************************************************************
Fichero: Tripanain.c
Autor: Tagoras
Creaci�n: 05-03-09
Descripci�n: La guardiana del almacen del centro
***************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public void create()
{
    ::create();
    SetStandard("Tripanain", "enano", 80, GENDER_FEMALE);
    AddId(({"Tripanain", "guardiana"}));
    SetShort("Tripanain la guardiana");
    SetLong("Ves a la que supones responsable del almac�n de armas del centro de adiestramiento de guerreros enanos de Annufam. Con todo el tiempo que llevas correteando por Simauria es la primera vez que ves a una enana tan fea y musculosa. De hecho no te queda demasiado claro que sea una enana y no un enano porque por encima de la t�nica le asoman unos pelos oscuros. Desde luego los enanos de Annufam tienen pocas cosas con las que desconcentrarse.\n");

    InitChats(3,({"Tripanain da un repaso general para ver que todo est� en su sitio.\n",
				"Tripanain refunfu�a al ver un hacha tirada en el suelo.\n",
				"Tripanain te mira de soslayo como si no se fiara de t�.\n"}));

	AddItem(OTRO_ANNUFAM("llave_almacen"), REFRESH_REMOVE);
}
