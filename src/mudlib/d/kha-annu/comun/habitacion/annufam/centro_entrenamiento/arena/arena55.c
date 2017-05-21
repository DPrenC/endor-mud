/* vi: set tabstop=4 */
/** @file arena55.c
	@brief el extremo norte de la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Este es el punto de la Arena más alejado del centro, y quizá sea por eso por lo que el ambiente está más calmado. Resguardados del sol por las murallas que rodean la ciudad, los enanos descansan de sus entrenamientos y aprovechan esos momentos para refrescarse con el agua del barril que tienes ante ti.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("el extremo norte de la Arena");
	SetIntLong("Este es el punto de la Arena más alejado del centro, y quizá sea por eso por lo que el ambiente está más calmado. Resguardados del sol por las murallas que rodean la ciudad, los enanos descansan de sus entrenamientos y aprovechan esos momentos para refrescarse con el agua del barril que tienes ante ti.\n");
	AddExit("sudeste", "arena64");
	AddExit("sur", "arena54");
	AddExit("suroeste", "arena44");
	AddItem(OTRO_ANNUFAM("barril"), REFRESH_MOVE_HOME);
	AddLoma();
	AddParedLejos();
}
