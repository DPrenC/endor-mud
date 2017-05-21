/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: salida.c                                              * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 27/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Llegas al final del pasillo. En este lugar no hay nada "
"exceptuando unas escaleras excavadas en la dura piedra. Es seguro que "
"eso no es obra de la naturaleza, es un trabajo realizado por alg�n tipo "
"de criatura.\n"));

SetSmell(W("Por el nauseabundo olor se nota que este lugar lleva tiempo "
"cerrado.\n"));
SetNoise("No escuchas m�s que el sonido de tu respiraci�n.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("nordeste","cueva01");
AddExit("abajo",GSOT2("entrada"));
}