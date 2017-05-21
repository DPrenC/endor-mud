/* vi: set tabstop=4 */
/** @file laboratorio.c
	@brief el laboratorio de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el laboratorio donde Tagoras crea nuevos objetos, desde pitilleras a perfumes, pasando por un sinf�n de armas y armaduras. Siempre suele haber alguna a medio hacer o en pruebas por aqu�. El suelo es de gres y las paredes est�n alicatadas hasta el techo, el cual y siguiendo el patr�n de resto de estancias es de madera. Hay estanter�as y material de laboratorio por todas partes.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	SetLocate("Workroom de Tagoras");
	SetIntShort("el laboratorio de Tagoras");
	SetIntLong("Este es el laboratorio donde Tagoras crea nuevos objetos, desde pitilleras a perfumes, pasando por un sinf�n de armas y armaduras. Siempre suele haber alguna a medio hacer o en pruebas por aqu�. El suelo es de gres y las paredes est�n alicatadas hasta el techo, el cual y siguiendo el patr�n de resto de estancias es de madera. Hay estanter�as y material de laboratorio por todas partes.\n");
	SetIntBright(35);
	AddDetail(({"suelo", "gres"}), "El suelo es de gres blanco, muy propio para un laboratorio.\n");
	AddDetail(({"pared", "paredes"}), "Las paredes est�n alicatadas de blanco hasta el techo.\n");
	AddDetail("techo", "El techo son unas vigas de roble con tablones de madera entre ellas.\n");
	AddDetail("estanter�as", "Son unas estanter�as met�licas repletas de frascos, matraces, c�psulas de Petri, botes, pipetas, ...\n");
	SetIntNoise("Oyes el borboteo de alguna poci�n que est� realiz�ndose a fuego lento.\n");
	SetIntSmell("Huele a diferentes productos alqu�micos.\n");
	Set(P_TPORT,TPORT_NO);
	AddExit("norte", "trastero");
	AddExit("oeste", "despacho");
	AddExit("noroeste", "workroom");
}
