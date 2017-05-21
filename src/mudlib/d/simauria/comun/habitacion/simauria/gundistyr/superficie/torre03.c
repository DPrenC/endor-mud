/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre03.c                                    * */
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
"destrozado casi por completo. Por el suelo ves maderas que debieron ser "
"muebles y piedras que seguramente fueron paredes...\n"));

AddDetail(({"alfombra"}),W("A tus pies hay una antiquísima alfombra de "
"color muy oscuro. Supones que ese no era su color original, pero el paso "
"de los años y las inclemencias del tiempo la han dejado en el estado "
"actual.\n"));
AddDetail(({"madera","maderas","muebles"}),W("Tiradas por el suelo hay "
"diversas maderas entre las que te parece identificar alguna pata de una "
"mesa o silla.\n"));
AddDetail(({"pata","pata mesa","pata silla"}),W("Te fijas más en la pata "
"y confirmas que es de alguna vieja cómoda.\n"));
AddDetail(({"piedras","piedra"}),W("Son los restos de las paredes y de los "
"pisos superiores de la torre. No tienen nada de particular.\n"));
AddDetail(({"rocas"}),"Hay un montón de rocas provenientes de una antigua pared.\n");

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre01");
AddExit("norte","torre05");
AddExit("oeste","torre02");
AddExit("este","torre04");
}
