/* vi: set tabstop=4 */
/** @file c218.c
	@brief 
	@author SimBuilder
	@version 1.00
	@date 2009-03-07


*/

#include "./path.h"

inherit HAB_TERCERA_ANNUFAM("base_room.c");

create() {
	::create();
	SetLocate("Annufam");
	AddExit("norte", "c217");
	AddDoor("norte");
	AddArcon();
	AddSWindow();
}
