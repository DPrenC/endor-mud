/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano17.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_ALWAYS,4+random(4));

AddExit("este","2sotano18");
AddExit("sur","2sotano23");
AddExit("noroeste","2sotano10");
}



