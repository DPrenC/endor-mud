/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:enttorre.c                                   * */
/* *         AUTOR: [a] Artic                                     * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */
#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Ante ti se extiende una enorme explanada donde en su dia se "
"erguia majestuosamente la torre de Gundistyr, aunque ahora no ves "
"m�s que un mont�n de ruinas. El ambiente es desolador, no ves m�s que "
"montones de piedra acumulados y tan s�lo quedan peque�as muestras que "
"demuestran que son restos de una antigua torre.\n"));
AddDetail(({"ruinas","ruina"}),W("Hacia el norte ves los restos de la "
"torre.\n"));
AddDetail(({"piedras","piedra"}),W("Hay montones de piedra hacia el norte. "
"A tu lado tienes una que te llama particularmente la atenci�n. Apartando "
"los helechos que la cubren en parte puedes leer:"TC_CYAN+" GUNDISTYR"
+TC_NORMAL+".\n"));
SetIntNoise("�nicamente escuchas una suave brisa.\n");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));
AddExit("sur","camino05");
AddExit("norte","torre01");
AddExit("oeste","entoeste");
AddExit("este","enteste");
}
