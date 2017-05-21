/* vi: set tabstop=4 */
/** @file trastero.c
	@brief el trastero de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-21

Este es el sitio donde Tagoras va dejando los objetos que va creando a la espera de poder utilizarlos. El suelo es de gres, aunque cuesta distinguirlo con tanto cachivache suelto, el techo de madera, pero sin grabados, ni nada y las paredes no tienes ni idea, porque están ocultas por multitud de estantes, estanterías y cajas apiladas.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>

inherit ROOM;

create() {
	::create();
	Set(P_TPORT,TPORT_NO);
	SetLocate("Workroom de Tagoras");
	SetIntShort("el trastero de Tagoras");
	SetIntLong("Este es el sitio donde Tagoras va dejando los objetos que va creando a la espera de poder utilizarlos. El suelo es de gres, aunque cuesta distinguirlo con tanto cachivache suelto, el techo de madera, pero sin grabados, ni nada y las paredes no tienes ni idea, porque están ocultas por multitud de estantes, estanterías y cajas apiladas.\n");
	SetIntBright(35);
	AddDetail(({"suelo", "gres"}), "El suelo está formado por losas de gres cuadradas, formando un damero con piezas de color azul y rojo.\n");
	AddDetail("techo", "El techo esta formado por una vigas de roble con tablones de madera entre ellas.\n");
	AddDetail("estantes", "Los estantes son una baldas de madera cargadas de objetos de dudosa valía.\n");
	AddDetail("estanterías", "Las estanterías están a rebosar de frascos, botes, legajos y otros artilugios mecánicos.\n");
	AddDetail(({"caja", "cajas"}), "Son una cajas de madera claveteadas y cerradas con cerrojos. Tagoras se ha asegurado que nadie más que él pueda abrirlas.\n");
	SetIntNoise("No se oye nada.\n");
	SetIntSmell("Dirías que hay un ligero olor a moho. Sería bueno que Tagoras le echase un vistazo antes que algo de lo que tiene aquí se echase a perder.\n");
	ForbidAllMagic();
	AddExit("sur", "laboratorio");
	AddExit("oeste", "workroom");
}
