/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano31.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("suroeste","entrada");
AddExit("oeste","2sotano30");
}



