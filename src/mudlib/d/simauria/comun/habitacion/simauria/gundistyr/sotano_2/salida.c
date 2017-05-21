/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: salida.c                                              * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */
#include "path.h"

inherit GD("cuevastd");

create(){
::create();

SetIntShort("las cuevas de Gundistyr");
SetIntLong(
"Una peque�a escalera de piedra te indica que estos profundos t�neles "
"se introducen m�s aun en las entra�as de las cuevas que se encuentran "
"bajo la derruida torre de Gundistyr. Al sur tienes un camino que te "
"lleva por este laberinto de piedra.\n");

SetIndoors(1);
SetIntBright(0);

AddDetail(({"pared","paredes"}),("A tu lado tienes unas altas paredes de caliza.\n"));
AddExit("sur","2sotano02");
AddExit("abajo",GSOT3("entrada"));
}



