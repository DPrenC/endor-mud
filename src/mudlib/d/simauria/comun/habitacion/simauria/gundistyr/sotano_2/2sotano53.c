/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano53.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_REMOVE,4+random(4));

AddExit("sur","2sotano60");
AddExit("nordeste","2sotano43");
}



