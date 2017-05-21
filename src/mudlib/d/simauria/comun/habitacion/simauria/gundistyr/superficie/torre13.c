/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre13.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás en una sala bastante espaciosa, aunque lo que te rodea no "
"dista mucho del resto de salas de estas ruinas, aunque mirando detenidamente "
"los detalles imaginas que se trataría de un salón o algo similar, el amplio "
"espacio que tienes, algún tapiz deshilachado, y hasta una vieja armadura "
"desmontada y dispersa por el suelo.\n"));

AddDetail(({"tapiz","tapiz deshilachado"}),W("Te acercas a ver el tapiz con "
"más detalle, y te parece distinguir un escudo de armas del cual solo "
"aprecias a ver la empuñadira de una espada.\n"));
AddDetail(({"armadura"}),W("Por el suelo ves una oxidada y vieja armadura "
"totalmente desmontada. Examinas algunas de las partes y ves que son muy "
"pesadas y que no ofrecen protección alguna. Es claramente una armadura de "
"decoración.\n"));
SetIntNoise("Únicamente escuchas una suave brisa.\n");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre12");
AddExit("norte","torre18");
AddExit("este","torre14");
AddExit("nordeste","torre19");
AddExit("noroeste","torre17");

}
