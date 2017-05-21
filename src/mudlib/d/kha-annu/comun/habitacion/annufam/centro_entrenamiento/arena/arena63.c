/* vi: set tabstop=4 */
/** @file arena63.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estás rodeando la loma que los enanos guerreros de Annufam emplean en sus entrenamientos. Les ves subir corriendo y echando unos gritos terribles con sus hachas levantadas y te imaginas que es lo que sucedería si ese ataque a la loma se produjese sobre una guarnición orca. Si quieres subir a la loma tendrás que ir en dirección oeste, pero si por el contrario quieres ir hacia la puerta del edificio, tendrás que hacerlo en dirección sur.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("Flanqueando");
	SetIntShort("una loma");
	SetIntLong("Estás rodeando la loma que los enanos guerreros de Annufam emplean en sus entrenamientos. Les ves subir corriendo y echando unos gritos terribles con sus hachas levantadas y te imaginas que es lo que sucedería si ese ataque a la loma se produjese sobre una guarnición orca. Si quieres subir a la loma tendrás que ir en dirección oeste, pero si por el contrario quieres ir hacia la puerta del edificio, tendrás que hacerlo en dirección sur.\n");
	AddExit("norte", "arena64");
	AddExit("este", "arena73");
	AddExit("sudeste", "arena72");
	AddExit("sur", "arena62");
	AddExit("suroeste", "arena52");
	AddExit("oeste", "arena53");
	AddExit("noroeste", "arena54");
	AddLoma();
	AddParedLejos();
}
