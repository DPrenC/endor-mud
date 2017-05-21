/* vi: set tabstop=4 */
/** @file terraza.c
	@brief la terraza
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Estás en las terraza. Aquí suele salir Tagoras los días de buen tiempo para disfrutar del paisaje. El suelo es de piedra y ves que hay una tumbona y un parasol.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	Set(P_TPORT,TPORT_NO);
	SetLocate("Workroom de Tagoras");
	SetIntShort("la terraza");
	SetIntLong("Estás en las terraza. Aquí suele salir Tagoras los días de buen tiempo para disfrutar del paisaje. El suelo es de piedra y ves que hay una tumbona y un parasol.\n");
	SetIndoors(0);
	AddDetail("paisaje", "Divisas los bosques de alrededor y allá a lo lejos el limbo, el parque de novatos y un pocos más lejos Stonehenge.\n");
	SetIntNoise("Oyes el trino lejano de algún pajarillo.\n");
	SetIntSmell("Llega el olor penetrante de los bosques de alrededor.\n");
	AddExit("norte", "despacho");
}
