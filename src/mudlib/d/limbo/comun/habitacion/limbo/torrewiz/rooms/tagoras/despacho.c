/* vi: set tabstop=4 */
/** @file despacho.c
	@brief el despacho de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el despacho en el que Tagoras estudia la mejor manera de crear nuevas �reas e implementar nuevos objetos tales como armas, armaduras y toda clase de artilugios. Hay una mesa de caoba, un sill�n de cuero y un par de sillas. Tambi�n ves una librer�a cargada de libros y tratados m�gicos. Hacia al sur ves una salida hacia la terraza.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	Set(P_TPORT,TPORT_NO);
	SetLocate("Workroom de Tagoras");
	SetIntShort("el despacho de Tagoras");
	SetIntLong("Este es el despacho en el que Tagoras estudia la mejor manera de crear nuevas �reas e implementar nuevos objetos tales como armas, armaduras y toda clase de artilugios. Hay una mesa de caoba, un sill�n de cuero y un par de sillas. Tambi�n ves una librer�a cargada de libros y tratados m�gicos. Hacia al sur ves una salida hacia la terraza.\n");
	SetIntBright(35);
	AddDetail(({"libreria", "librer�a"}), "Es una librer�a de nogal abarrotada de tratados m�gicos.\n");
	AddDetail(({"sillon", "sill�n"}), "Es un sill�n de caoba, cubierto de cuero repujada, parece muy c�modo.\n");
	AddDetail(({"silla", "sillas"}), "Son una sillas de madera donde la gente que ha venido a ver a Tagoras puede sentarse mientras conversa con �l.\n");
	SetIntNoise("No oyes nada.\n");
	SetIntSmell("Huele a maderas nobles y cuero repujado.\n");
	AddExit("norte", "workroom");
	AddExit("este", "laboratorio");
	AddExit("sur", "terraza");
}
