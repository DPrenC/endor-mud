/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre19.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en una sala bastante espaciosa, aunque lo que te rodea no "
"dista mucho del resto de salas de estas ruinas, aunque mirando detenidamente "
"los detalles imaginas que se tratar�a de un sal�n o algo similar, el amplio "
"espacio que tienes y alg�n tapiz deshilachado.\n"));

AddDetail(({"tapiz","tapiz deshilachado"}),W("Te acercas a ver el tapiz con "
"m�s detalle, y te parece distinguir un escudo de armas del cual s�lo "
"aprecias a ver la empu�adura de una espada.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre14");
AddExit("suroeste","torre13");
AddExit("oeste","torre18");
AddExit("este","torre20");

}
