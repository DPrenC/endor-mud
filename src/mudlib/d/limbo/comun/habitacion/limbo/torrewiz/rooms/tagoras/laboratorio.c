/* vi: set tabstop=4 */
/** @file laboratorio.c
	@brief el laboratorio de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el laboratorio donde Tagoras crea nuevos objetos, desde pitilleras a perfumes, pasando por un sinfín de armas y armaduras. Siempre suele haber alguna a medio hacer o en pruebas por aquí. El suelo es de gres y las paredes están alicatadas hasta el techo, el cual y siguiendo el patrón de resto de estancias es de madera. Hay estanterías y material de laboratorio por todas partes.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	SetLocate("Workroom de Tagoras");
	SetIntShort("el laboratorio de Tagoras");
	SetIntLong("Este es el laboratorio donde Tagoras crea nuevos objetos, desde pitilleras a perfumes, pasando por un sinfín de armas y armaduras. Siempre suele haber alguna a medio hacer o en pruebas por aquí. El suelo es de gres y las paredes están alicatadas hasta el techo, el cual y siguiendo el patrón de resto de estancias es de madera. Hay estanterías y material de laboratorio por todas partes.\n");
	SetIntBright(35);
	AddDetail(({"suelo", "gres"}), "El suelo es de gres blanco, muy propio para un laboratorio.\n");
	AddDetail(({"pared", "paredes"}), "Las paredes están alicatadas de blanco hasta el techo.\n");
	AddDetail("techo", "El techo son unas vigas de roble con tablones de madera entre ellas.\n");
	AddDetail("estanterías", "Son unas estanterías metálicas repletas de frascos, matraces, cápsulas de Petri, botes, pipetas, ...\n");
	SetIntNoise("Oyes el borboteo de alguna poción que está realizándose a fuego lento.\n");
	SetIntSmell("Huele a diferentes productos alquímicos.\n");
	Set(P_TPORT,TPORT_NO);
	AddExit("norte", "trastero");
	AddExit("oeste", "despacho");
	AddExit("noroeste", "workroom");
}
