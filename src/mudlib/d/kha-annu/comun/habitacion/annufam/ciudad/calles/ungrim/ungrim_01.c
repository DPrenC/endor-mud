/****************************************************************************
Fichero: ungrim_01.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 27/09/2005
Descripci�n: Un tramo de la calle Ungrim, junto al cruce.
[T] 09/03/2009: A�ado puerta
[T] 05/01/2012: Alg�n typo
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit BASE_CIUDAD_ANNUFAM;

int ir_sur();

public void create()
{
	::create();

	SetIntShort("la calle Ungrim");
	SetIntLong("Est�s en la calle de los comercios de Annufam. Al norte se "
				"encuentra la tienda de alimentaci�n, donde podr�s comprar "
				"alg�n regalo para tu est�mago. La calle sigue al este "
				"mientras que al oeste llegas a la Avenida Real. Al sur de "
				"aqu�, observas una casa.\n");
	AddSuelo();
	AddLuzAntorchas();

	AddDetail(({"casa","sur","pared sur"}),
				"Es una casa bastante humilde. Por la cercan�a, piensas que "
				"pertenece al comerciante de la tienda que hay al norte.\n");


	AddDetail(({"norte","tienda"}),
				"Es una tienda que abastece a la ciudad con todo tipo de "
				"alimentos. Pertenece a un viejo enano que vino a Annufam "
				"nada m�s ser fundada.\n");

	AddExit("norte",HAB_TIENDAS_ANNUFAM("tienda_alimentacion"));
	AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_02"));
	AddExit("oeste",HAB_AVENIDA_ANNUFAM("avenida_03"));
	AddExit("sur",SF(ir_sur));
	AddDoor("norte", "la puerta de la tienda de alimentaci�n",
		"Es la puerta que da entrada a la tienda de alimentaci�n.\n",
		({"puerta", "puerta de la tienda de alimentaci�n", "puerta de la tienda de alimentacion"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}

int ir_sur()
{
	string nombre = CAP(TNAME);
	return notify_fail("Intentas abrir la puerta de la casa y de repente "
						"sale un enano de su interior.\n\nEl enano dice: "
						"Buenas "+ nombre+" , el se�or no est� en casa, podr�"
						" hablar con �l en la tienda que hay al norte.\n",
						NOTIFY_NOT_VALID);
}
