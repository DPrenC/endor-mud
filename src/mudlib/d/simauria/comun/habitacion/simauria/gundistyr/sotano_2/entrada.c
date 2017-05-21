/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: entrada.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");

create() {
::create();
SetIntLong(W("Est�s al inicio de unas profundas cuevas que no parecen "
"tener fin. Por mucho que tratas de afinar tu vista no puedes ver "
"absolutamente nada a tan s�lo unos pasos de t�. Hay una salida "
"hacia el nordeste que te interna en estos profundos t�neles, "
"mientras que si vas hacia arriba llegar�s a las mazmorras.\n"));

AddExit("nordeste","2sotano31");
AddExit("arriba",GSOT1("salida"));
}
