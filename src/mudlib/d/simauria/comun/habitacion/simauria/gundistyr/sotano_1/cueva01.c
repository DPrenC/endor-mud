/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: cueva01.c                                             * */
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
"camino avanza hacia el suroeste sumergiendose más aun en estas cuevas, "
"mientras que al este se encuentra el camino que te puede llevar de vuelta  "
"a la salida.\n"));

SetSmell("Por el nauseabundo olor se nota que este lugar lleva tiempo cerrado.\n");
SetNoise("No escuchas más que el sonido de tu respiración.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("este","cueva02");
AddExit("suroeste","salida");
}