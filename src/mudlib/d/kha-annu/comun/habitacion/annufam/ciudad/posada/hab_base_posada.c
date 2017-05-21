/****************************************************************************
Fichero:hab_base_posada.c
Autor: Kastwey
		[T] Tagoras
Creación: 19/08/2005
Descripción: habitación base de la posada de Annufam
[T] 22/03/2009: Pongo puertas estandar
****************************************************************************/

#include "./path.h"

#define PASILLO  (HAB_POSADA_ANNUFAM("pasillo_piso1"))

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
	::create();
	SetIntShort("una habitación en la posada de Annufam");
	SetIntLong("Te encuentras en una habitación de la posada de Annufam.\n");
	SetIndoors(1);
	SetIntBright(75);

	AddDetail(({"cama","camastro"}),
			  W("Es un camastro de lo más sencillo: Un montoncito de paja "
				"metida en unas rudimentarias sábanas y una manta de lana a "
				"los pies para las noches de frío.\n"));

	AddDetail("armario",W("Se trata de un gran y antiguo armario donde los "
						  "huéspedes colocan sus ropas de viaje. Está "
						  "totalmente vacío.\n"));

	AddDetail(({"mesa","mesita","mesilla"}),
			  W("Es una pequeña mesita que descansa al lado de la cama. "
				"Tiene un cajón y poco más.\n"));

	AddDetail(({"cajon de mesita","cajon de mesilla","cajon de mesa",
				"cajón de mesita","cajón de mesilla","cajón de mesa"}),
			  W("Abres el cajón, y sin demasiada sorpresa compruebas que esta "
				"vacío.\n"));
}
