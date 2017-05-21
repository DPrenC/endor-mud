/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre03.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Te da la impresi�n de que estas en lo que parece hace mucho "
"tiempo fue el hall. Ves un mont�n de rocas sobre una ra�da y antiqu�sima "
"alfombra que el paso del tiempo ha te�ido de un color negruzco y ha "
"destrozado casi por completo. Por el suelo ves maderas que debieron ser "
"muebles y piedras que seguramente fueron paredes...\n"));

AddDetail(({"alfombra"}),W("A tus pies hay una antiqu�sima alfombra de "
"color muy oscuro. Supones que ese no era su color original, pero el paso "
"de los a�os y las inclemencias del tiempo la han dejado en el estado "
"actual.\n"));
AddDetail(({"madera","maderas","muebles"}),W("Tiradas por el suelo hay "
"diversas maderas entre las que te parece identificar alguna pata de una "
"mesa o silla.\n"));
AddDetail(({"pata","pata mesa","pata silla"}),W("Te fijas m�s en la pata "
"y confirmas que es de alguna vieja c�moda.\n"));
AddDetail(({"piedras","piedra"}),W("Son los restos de las paredes y de los "
"pisos superiores de la torre. No tienen nada de particular.\n"));
AddDetail(({"rocas"}),"Hay un mont�n de rocas provenientes de una antigua pared.\n");

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre01");
AddExit("norte","torre05");
AddExit("oeste","torre02");
AddExit("este","torre04");
}
