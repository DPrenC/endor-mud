/* vi: set tabstop=4 */
/** @file base_arena_trasera.c
	@brief Archivo base para arena trasera

Este es el código LPC del tipo de room base definido por el usuario arena trasera
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	AddDetail(({"pared", "trasera", "pared trasera"}),"Es la pared trasera del Centro de Adiestramiento para Guerreros Enanos. En ella puedes ver alguna ventana.\n");
	AddDetail(({"ventana"}),"A través de ella observas algunos enanos entrenando las habilidades de lucha en el interior del edificio.\n");
}
