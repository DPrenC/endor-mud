/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre05.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Te da la impresión de que estas en lo que parece hace mucho "
"tiempo fue el hall. Ves un montón de rocas sobre una raída y antiquísima "
"alfombra que el paso del tiempo ha teñido de un color negruzco y ha "
"destrozado casi por completo. Hay restos de la antigua torre por todas "
"partes.\n"));

AddDetail(({"alfombra"}),W("A tus pies hay una antiquísima alfombra de "
"color muy oscuro. Supones que ese no era su color original, pero el paso "
"de los años y las inclemencias del tiempo la han dejado en el estado "
"actual.\n"));
AddDetail(({"restos"}),"Ves restos de muros por todas partes.\n");
AddDetail(({"rocas"}),W("Hay un montón de rocas provenientes de una antigua "
"pared.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre03");
AddExit("norte","torre08");
AddExit("este","torre06");
}
