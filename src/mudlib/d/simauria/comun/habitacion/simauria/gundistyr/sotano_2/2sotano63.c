/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano63.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_ALWAYS,4+random(4));

AddExit("este","2sotano64");
AddExit("noroeste","2sotano55");
}



