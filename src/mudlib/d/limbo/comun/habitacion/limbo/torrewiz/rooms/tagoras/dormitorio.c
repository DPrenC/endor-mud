/* vi: set tabstop=4 */
/** @file dormitorio.c
	@brief el dormitorio de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este el dormitorio donde Tagoras descansa las pocas horas que le quedan libre para hacerlo. Hay una cama, �con dosel?, una mesita de noche, una silla y un armario. El suelo es de gres, y el techo de bonita madera labrada, las paredes est�n pintadas con figuras aleg�ricas.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	Set(P_TPORT,TPORT_NO);
	SetLocate("Workroom de Tagoras");
	SetIntShort("el dormitorio de Tagoras");
	SetIntLong("Este el dormitorio donde Tagoras descansa las pocas horas que le quedan libre para hacerlo. Hay una cama, �con dosel?, una mesita de noche, una silla y un armario. El suelo es de gres, y el techo de bonita madera labrada, las paredes est�n pintadas con figuras aleg�ricas.\n");
	SetIntBright(35);
	AddDetail(({"suelo", "gres"}), "El gres del suelo forma un dibujo geom�trico en espiral jugando h�bilmente con el tama�o y disposici�n de las losetas.\n");
	AddDetail("techo", "El techo est� formado por unas vigas de roble sobre las que se ponen unos tablones en los que se han labrado diversos animales del bosque.\n");
	AddDetail(({"talla", "tallas", "animal", "animales"}), "Entre las tallas del techo puedes distinguir ardillas, topos, jabal�es, lobos y osos. Parecen algunos de los animales que pueden convocar los guardabosques.\n");
	AddDetail(({"figura", "figuras"}), "Son diversas figuras que recuerdan la mitolog�a �lfica.\n");
	SetIntNoise("No oyes nada\n");
	SetIntSmell("Huele a bosque, increible, pero cierto. Alg�n truco m�gico del druida, fijo.\n");
	AddExit("este", "workroom");
}
