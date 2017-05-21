/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: cueva02.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 27/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Parece que te encuentras en una pequeña cueva natural que se "
"encontraba tras los desgastados muros de las mazmorras de Gundistyr. El "
"camino avanza hacia el oeste sumergiendose más aun en estas cuevas, "
"mientras que al sureste se encuentra el camino que te puede llevar "
"de vuelta a la salida.\n"));

SetSmell(W("Por el nauseabundo olor se nota que este lugar lleva "
"iempo cerrado.\n"));
SetNoise("No escuchas más que el sonido de tu respiración.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("sudeste","cueva03");
AddExit("oeste","cueva01");
}