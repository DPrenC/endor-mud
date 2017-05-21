/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano02.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("norte","salida");
AddExit("oeste","2sotano01");
}



