/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano39.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("sudeste","2sotano49");
AddExit("norte","2sotano29");

AddItem(PNJGD("kob"),REFRESH_REMOVE,5+random(4));
}



