/* vi: set tabstop=4 */
/** @file arena43.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Est�s rodeando la loma que los enanos guerreros de Annufam emplean en sus entrenamientos. Les ves subir corriendo y echando unos gritos terribles con sus hachas levantadas y te imaginas que es lo que suceder�a si ese ataque a la loma se produjese sobre una guarnici�n orca. Si quieres subir a la loma tendr�s que ir en direcci�n este, pero si por el contrario quieres ir hacia la puerta del edificio, tendr�s que hacerlo en direcci�n sur.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("flanqueando");
	SetIntShort("una loma");
	SetIntLong("Est�s rodeando la loma que los enanos guerreros de Annufam emplean en sus entrenamientos. Les ves subir corriendo y echando unos gritos terribles con sus hachas levantadas y te imaginas que es lo que suceder�a si ese ataque a la loma se produjese sobre una guarnici�n orca. Si quieres subir a la loma tendr�s que ir en direcci�n este, pero si por el contrario quieres ir hacia la puerta del edificio, tendr�s que hacerlo en direcci�n sur.\n");
	AddExit("norte", "arena44");
	AddExit("nordeste", "arena54");
	AddExit("este", "arena53");
	AddExit("sudeste", "arena52");
	AddExit("sur", "arena42");
	AddExit("suroeste", "arena32");
	AddExit("oeste", "arena33");
	AddLoma();
	AddParedLejos();
}
