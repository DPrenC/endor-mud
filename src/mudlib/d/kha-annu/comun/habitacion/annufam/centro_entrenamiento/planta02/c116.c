/* vi: set tabstop=4 */
/** @file c116.c
	@brief 
	@author SimBuilder
	@version 1.00
	@date 2009-02-27


*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_room_recluta");

create() {
	::create();
	AddExit("sur", "c117");
	AddDoor("sur");
	AddNWindow();
}
