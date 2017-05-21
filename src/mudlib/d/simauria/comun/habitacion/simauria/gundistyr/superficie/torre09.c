/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre09.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Pequeños matojos de hierba que surgen entre las grietas de las "
"baldosas, fragmentos de roca por doquier, paredes desmoronadas... "
"Definitivamente en esta sala no hay nada de interés. Ni siquiera puedes "
"imaginar cual era su uso original.\n"));

AddDetail(({"hierba","yerba","matojos","baldosas","matojos de hierba"}),
W("Algunos matojos de hierba verde sobresalen entre las grietas de las "
"baldosas ya muy desgastadas.\n"));
AddDetail(({"fragmentos","roca","rocas","fragmentos de roca"}),W("Ves "
"rocas y piedras por todos lados.\n"));
AddDetail(({"pared","paredes"}),W("Son sólo un misero de recuerdo de unas "
"paredes...\n"));
AddDetail(({"baldosa","baldosas"}),W("Son unas viejas y agrietadas baldosas."
"\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("este","torre10");
}
