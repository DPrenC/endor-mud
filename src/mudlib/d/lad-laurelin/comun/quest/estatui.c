/*
DESCRIPCION    : estatuilla del dios Dehim que se usa para el Quest
FICHERO        : ......../tiindhil/comun/objeto/otro/estatui.c
CREACION       : Abril 99[Alura].
U.MODIFICACION :
*/


#include "path.h"

inherit THING;

create() {
	::create();

	SetShort("una pequeña estatuilla");
	SetLong(
"Es una delicada figura de un hombre cubierto por enredaderas. Con una\n"
"beatifica expresion, levanta sus brazos al cielo.\n");
	SetIds(({"estatuilla","figurilla"}));
	SetWeight(500);     //peso en gramos
	SetValue(10000);      // valor en monedas de cobre
	SetMaterial("porcelana");
}
