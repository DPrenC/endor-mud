/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre14.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás en una pequeña explanada cubierta casi en su totalidad "
"por verde hierba. Tus movimientos solo están limitados hacia el oeste y el "
"sudeste por dos pequeños muros, por lo demas, puedes moverte con total "
"libertad.\n"));

AddDetail(({"muro","muros"}),W("Son unos altos muros de piedra sin nada en "
"particular.\n"));
AddDetail(({"hierba","yerba"}),W("Bajo tus pies no hay más que fresca hierba "
"de las montañas.\n"));
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("norte","torre19");
AddExit("noroeste","torre18");
AddExit("oeste","torre13");

}
