/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano01.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("sur","2sotano04");
AddExit("este","2sotano02");
}



