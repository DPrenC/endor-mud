/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:2torre03.c                                   * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en un peque�o sendero rodeado por altos pinos. El suelo "
"que pisas est� cubierto por una fina capa de hojas de pino ca�das. El camino "
"en el que est�s forma aqu� una peque�a curva con salidas hacia el nordeste y "
"sudeste.\n"));
AddDetail(({"arboles","�rboles","pinos"}),W("Ves unos enormes pinos a tu "
"alrededor. Apenas hay espacio entre ellos, tan s�lo te parece ver un peque�o "
"sendero que va hacia el nordeste.\n"));
AddDetail(({"hojas","hojas pino","hojas pinos","hojas de pino","suelo"}),
"Hay hojas de pino por todo el suelo creando un peque�o manto.\n");

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("nordeste","ptoexp");
AddExit("suroeste","2torre02");
}
