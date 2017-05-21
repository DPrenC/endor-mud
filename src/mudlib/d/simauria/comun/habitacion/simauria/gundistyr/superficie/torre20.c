/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre20.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en una habitaci�n que tiene un par de peque�os arcos, "
"uno al oeste que parece llevar a una zona m�s principal de la torre, y otro "
"medio destruido al sur que te lleva hasta otra sala. Esta sala no tiene nada "
"en particular, por lo que piensas que era nada m�s que un pasillo, pese a "
"que el suelo esta cubierto por una alfombra verde a causa de la hierba y el "
"�nico techo que hay es el aire libre. El muro que hab�a al este est� "
"totalmente derruido, por lo que puedes ir hacia all�.\n"));

AddDetail(({"arcos"}),"Hay un arco al sur y al oeste.\n");
AddDetail(({"arco sur","arco del sur"}),W("Este arco podr�a decirse "
"que vivi� tiempos mejores. Da la impresi�n de que podr�a desmoronarse en "
"cualquier instante.\n"));
AddDetail(({"arco"}),"�Qu� arco quieres mirar?\n");
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
