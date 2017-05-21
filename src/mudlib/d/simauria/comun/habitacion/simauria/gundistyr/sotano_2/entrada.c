/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: entrada.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");

create() {
::create();
SetIntLong(W("Estás al inicio de unas profundas cuevas que no parecen "
"tener fin. Por mucho que tratas de afinar tu vista no puedes ver "
"absolutamente nada a tan sólo unos pasos de tí. Hay una salida "
"hacia el nordeste que te interna en estos profundos túneles, "
"mientras que si vas hacia arriba llegarás a las mazmorras.\n"));

AddExit("nordeste","2sotano31");
AddExit("arriba",GSOT1("salida"));
}
