/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano75.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");

create(){
::create();

AddItem(PNJGD("kob"),REFRESH_ALWAYS,5+random(4));

AddExit("este","2sotano76");
AddExit("suroeste","2sotano79");
}



