/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:escarriba.c                                  * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */
#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás en una sala muy pequeña, tanto que  tienes una "
"leve sensación claustrofóbica. Estás rodeado por paredes excepto al "
"norte, hacia donde te adentrarias mas en las ruinas. Unas escaleras "
"de caracol llevan hacia arriba, a lo que en su dia fue un piso superior "
"de la torre.También observas aquí una columna.\n"));

AddDetail(({"pared","paredes"}),W("Unas altas paredes bloquean el camino "
"hacia el este, oeste y sur.\n"));
AddDetail(({"escalera","escaleras"}),W("Unas escaleras de caracol suben "
"hacia arriba. Estás construidas de ya agrietada piedra.\n"));
AddDetail(({"columna"}),W("Hay una columna no excesivamente alta que sirve "
"de soporte al piso superior.\n"));
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("arriba","2torre01");
AddExit("norte","torre07");
}