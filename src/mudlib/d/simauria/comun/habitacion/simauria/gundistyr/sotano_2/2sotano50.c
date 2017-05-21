/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano50.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_ALWAYS,4+random(4));

AddExit("nordeste","2sotano40");
AddExit("oeste","2sotano49");
}



