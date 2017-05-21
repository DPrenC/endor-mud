/* vi: set tabstop=4 */
/** @file workroom.c
	@brief las estancias de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aquí. Unas luces mágicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de algún tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias están pintadas con símbolos mágicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una mesita, una silla de cortesía y un espejo. Por la disposición de las estancias deduces que al oeste está el dormitorio, al este algún tipo de almacén, al sudeste el laboratorio y hacia el sur el despacho de Tagoras. Incluso, si te fijas, ves que más al sur parece que hay algún tipo de balcón o terraza.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit TORRE("rooms/tagoras/tago_room");
//inherit "/d/l_tagoras/comun/habitacion/rooms/tagoras/tago_room";

public string QueryMXPIntLong()
{
	return "Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aquí. Unas "+MXPSend("mirar", "luces")+" mágicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de algún tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias están pintadas con símbolos mágicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una "+MXPSend("mirar", "mesita")+", una "+MXPSend("mirar", "silla")+" de cortesía y un "+MXPSend("mirar", "espejo")+". Por la disposición de las estancias deduces que al "+MXPSend("oeste", "oeste")+" está el dormitorio, al "+MXPSend("este", "este")+" algún tipo de almacén, al "+MXPSend("sudeste", "sudeste")+" el laboratorio y hacia el "+MXPSend("sur", "sur")+" el despacho de Tagoras. Incluso, si te fijas, ves que más al sur parece que hay algún tipo de balcón o terraza.\n";
}

create() {
	::create();
	SetLocate("Workroom de Tagoras");
	SetIntShort("las estancias de Tagoras");
	SetIntLong("Este es el distribuidor que desde la torre de los Wizards da paso a las diferentes estancias que usa Tagoras cuando se deja caer por aquí. Unas luces mágicas en las paredes iluminan el distribuidor. El suelo es de gres, el techo parece de algún tipo de madera labrada y las pocas paredes que hay, debido a las espaciosas aberturas al resto de estancias están pintadas con símbolos mágicos; seguramente para proteger el sancta sanctorum de Tagoras. Puedes ver que en esta estancia el mobiliario se reduce a una mesita, una silla de cortesía y un espejo. Por la disposición de las estancias deduces que al oeste está el dormitorio, al este algún tipo de almacén, al sudeste el laboratorio y hacia el sur el despacho de Tagoras. Incluso, si te fijas, ves que más al sur parece que hay algún tipo de balcón o terraza.\n");
	SetIntBright(35);
	AddDetail(({"luz", "luces"}), "Son algún tipo de sortilegio que ha realizado Tagoras y que asegura que la habitación está suficientemente iluminada y no darse con los muebles.\n");
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
