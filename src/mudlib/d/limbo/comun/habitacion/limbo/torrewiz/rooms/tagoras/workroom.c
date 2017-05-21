/* vi: set tabstop=4 */
/** @file workroom.c
	@brief las estancias de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aqu�. Unas luces m�gicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de alg�n tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias est�n pintadas con s�mbolos m�gicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una mesita, una silla de cortes�a y un espejo. Por la disposici�n de las estancias deduces que al oeste est� el dormitorio, al este alg�n tipo de almac�n, al sudeste el laboratorio y hacia el sur el despacho de Tagoras. Incluso, si te fijas, ves que m�s al sur parece que hay alg�n tipo de balc�n o terraza.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit TORRE("rooms/tagoras/tago_room");
//inherit "/d/l_tagoras/comun/habitacion/rooms/tagoras/tago_room";

public string QueryMXPIntLong()
{
	return "Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aqu�. Unas "+MXPSend("mirar", "luces")+" m�gicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de alg�n tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias est�n pintadas con s�mbolos m�gicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una "+MXPSend("mirar", "mesita")+", una "+MXPSend("mirar", "silla")+" de cortes�a y un "+MXPSend("mirar", "espejo")+". Por la disposici�n de las estancias deduces que al "+MXPSend("oeste", "oeste")+" est� el dormitorio, al "+MXPSend("este", "este")+" alg�n tipo de almac�n, al "+MXPSend("sudeste", "sudeste")+" el laboratorio y hacia el "+MXPSend("sur", "sur")+" el despacho de Tagoras. Incluso, si te fijas, ves que m�s al sur parece que hay alg�n tipo de balc�n o terraza.\n";
}

create() {
	::create();
	SetLocate("Workroom de Tagoras");
	SetIntShort("las estancias de Tagoras");
	SetIntLong("Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aqu�. Unas luces m�gicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de alg�n tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias est�n pintadas con s�mbolos m�gicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una mesita, una silla de cortes�a y un espejo. Por la disposici�n de las estancias deduces que al oeste est� el dormitorio, al este alg�n tipo de almac�n, al sudeste el laboratorio y hacia el sur el despacho de Tagoras. Incluso, si te fijas, ves que m�s al sur parece que hay alg�n tipo de balc�n o terraza.\n");
	SetIntBright(35);
	AddDetail(({"luz", "luces"}), "Son alg�n tipo de sortilegio que ha realizado Tagoras y que asegura que la habitaci�n est� suficientemente iluminada y no darse con los muebles.\n");
	SetIntNoise("No oyes nada.\n");
	SetIntSmell("Huele a incienso.\n");
	SetSafe(1);
	ForbidAllMagic("Los hechizos de Tagoras impiden que otros invoquen a los arcanos.\n");
	AddExit("este", "trastero");
	AddExit("sudeste", "laboratorio");
	AddExit("sur", "despacho");
	AddExit("oeste", "dormitorio");
	AddExit("torre", TORRE("piso2/center"));
	AddItem(TAGORAS_OTRO("mesita"), REFRESH_REMOVE);
	AddItem(TAGORAS_OTRO("silla"), REFRESH_REMOVE);
	AddItem(TAGORAS_OTRO("espejo"), REFRESH_REMOVE);
}
