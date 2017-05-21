/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre01.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("La entrada a la torre de Gundistyr es bastante pobre. Estás "
"sobre lo que supones que en su día era el portón de entrada a la torre, "
"aunque ahora es simplemente... nada. Si vas hacia el norte, entrarás a las "
"ruinas, mientras que si vas al sur te alejaras de ellas.\n"));
AddDetail(({"ruinas","ruina","torre"}),W("Hacia el norte ves los restos de la "
"torre.\n"));
AddDetail(({"porton","portón"}),W("Sobre tu cabeza observas un gran portón "
"que hacía las veces de entrada a la torre, aunque ahora no hay puerta alguna "
"que lo proteja.\n"));
SetIntNoise("Únicamente escuchas una suave brisa.\n");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"hierba.\n"));
AddExit("norte","torre03");
AddExit("sur","enttorre");
}