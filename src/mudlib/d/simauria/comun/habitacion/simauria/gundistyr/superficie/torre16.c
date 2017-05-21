/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre16.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("A tus pies observas viejas baldosas destrozada por el paso de "
"los años. A tu alrededor no observas nada que pueda ser interesante. "
"Únicamente la soledad de una torre perdida en el olvido.\n"
"Si vas hacia el este te internaras más en la vieja torre, aunque también hay "
"una salida hacia el sur.\n"));

AddDetail(({"baldosa","baldosas"}),W("Las baldosas que ves en el suelo "
"están totalmente resquebrajadas por el paso del tiempo y las condiciones "
"atmosféricas.\n"));
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre15");
AddExit("este","torre17");
}