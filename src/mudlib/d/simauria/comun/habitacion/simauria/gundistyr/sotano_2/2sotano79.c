/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano79.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("nordeste","2sotano75");
AddExit("noroeste","2sotano73");
AddExit("norte","2sotano74");
AddExit("sur","rio");
}



