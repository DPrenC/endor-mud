/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre01.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("La entrada a la torre de Gundistyr es bastante pobre. Est�s "
"sobre lo que supones que en su d�a era el port�n de entrada a la torre, "
"aunque ahora es simplemente... nada. Si vas hacia el norte, entrar�s a las "
"ruinas, mientras que si vas al sur te alejaras de ellas.\n"));
AddDetail(({"ruinas","ruina","torre"}),W("Hacia el norte ves los restos de la "
"torre.\n"));
AddDetail(({"porton","port�n"}),W("Sobre tu cabeza observas un gran port�n "
"que hac�a las veces de entrada a la torre, aunque ahora no hay puerta alguna "
"que lo proteja.\n"));
SetIntNoise("�nicamente escuchas una suave brisa.\n");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"hierba.\n"));
AddExit("norte","torre03");
AddExit("sur","enttorre");
}