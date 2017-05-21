/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: pasi06.c                                              * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();

SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Este es el pasillo a través del cual se puede acceder a "
"las antiguas mazmorras de Gundistyr. Hacia el este se encuentra la "
"salida de este antiguo lugar, mientras que si vas hacia el oeste podrás "
"acceder a las viejas celdas de esta torre.\n"));

SetSmell("Por el nauseabundo olor se nota que este lugar lleva tiempo cerrado.\n");
SetNoise("No escuchas más que el sonido de tu respiración.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("este","pasi07");
AddExit("oeste","pasi05");
AddItem(PNJGD("aranya"),REFRESH_ALWAYS);
}