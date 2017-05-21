/****************************************************************************
Fichero: base_pasillo
Autor: Tagoras
Fecha: 27/02/2009
Descripción: Base del pasillo de la planta primera del centro.
****************************************************************************/

#include "path.h"

inherit HAB_TERCERA_ANNUFAM("base_planta");

create()
{
	::create();

	AddDetail(({"pared","paredes"}), "Las paredes de los pasillos de este centro son muy parecidas al suelo. Están hechas con piedra oscura y sin ningún tipo de decoración más que algunas antorchas y faroles.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT, 1);
}
