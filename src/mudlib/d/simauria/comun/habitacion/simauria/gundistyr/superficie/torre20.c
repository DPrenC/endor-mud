/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre20.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás en una habitación que tiene un par de pequeños arcos, "
"uno al oeste que parece llevar a una zona más principal de la torre, y otro "
"medio destruido al sur que te lleva hasta otra sala. Esta sala no tiene nada "
"en particular, por lo que piensas que era nada más que un pasillo, pese a "
"que el suelo esta cubierto por una alfombra verde a causa de la hierba y el "
"único techo que hay es el aire libre. El muro que había al este está "
"totalmente derruido, por lo que puedes ir hacia allí.\n"));

AddDetail(({"arcos"}),"Hay un arco al sur y al oeste.\n");
AddDetail(({"arco sur","arco del sur"}),W("Este arco podría decirse "
"que vivió tiempos mejores. Da la impresión de que podría desmoronarse en "
"cualquier instante.\n"));
AddDetail(({"arco"}),"¿Qué arco quieres mirar?\n");
AddDetail(({"arco oeste","arco del oeste"}),"Es un arco de piedra.\n");
AddDetail(({"suelo","hierba","yerba"}),W("El suelo esta cubierto por una leve "
"capa de verde hierba. Sin duda, la humedad de la zona ha contribuido a su "
"crecimiento.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("oeste","torre19");
AddExit("este","torre21");
AddExit("norte","torre22");
}
