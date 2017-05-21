/****************************************************************************
Fichero:hab_base_posada.c
Autor: Kastwey
		[T] Tagoras
Creaci�n: 19/08/2005
Descripci�n: habitaci�n base de la posada de Annufam
[T] 22/03/2009: Pongo puertas estandar
****************************************************************************/

#include "./path.h"

#define PASILLO  (HAB_POSADA_ANNUFAM("pasillo_piso1"))

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
	::create();
	SetIntShort("una habitaci�n en la posada de Annufam");
	SetIntLong("Te encuentras en una habitaci�n de la posada de Annufam.\n");
	SetIndoors(1);
	SetIntBright(75);

	AddDetail(({"cama","camastro"}),
			  W("Es un camastro de lo m�s sencillo: Un montoncito de paja "
				"metida en unas rudimentarias s�banas y una manta de lana a "
				"los pies para las noches de fr�o.\n"));

	AddDetail("armario",W("Se trata de un gran y antiguo armario donde los "
						  "hu�spedes colocan sus ropas de viaje. Est� "
						  "totalmente vac�o.\n"));

	AddDetail(({"mesa","mesita","mesilla"}),
			  W("Es una peque�a mesita que descansa al lado de la cama. "
				"Tiene un caj�n y poco m�s.\n"));

	AddDetail(({"cajon de mesita","cajon de mesilla","cajon de mesa",
				"caj�n de mesita","caj�n de mesilla","caj�n de mesa"}),
			  W("Abres el caj�n, y sin demasiada sorpresa compruebas que esta "
				"vac�o.\n"));
}
