/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:2torre03.c                                   * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás en un pequeño sendero rodeado por altos pinos. El suelo "
"que pisas está cubierto por una fina capa de hojas de pino caídas. El camino "
"en el que estás forma aquí una pequeña curva con salidas hacia el nordeste y "
"sudeste.\n"));
AddDetail(({"arboles","árboles","pinos"}),W("Ves unos enormes pinos a tu "
"alrededor. Apenas hay espacio entre ellos, tan sólo te parece ver un pequeño "
"sendero que va hacia el nordeste.\n"));
AddDetail(({"hojas","hojas pino","hojas pinos","hojas de pino","suelo"}),
"Hay hojas de pino por todo el suelo creando un pequeño manto.\n");

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("nordeste","ptoexp");
AddExit("suroeste","2torre02");
}
