/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano70.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();
AddItem(PNJGD("kob"),REFRESH_ALWAYS,3+random(4));
AddItem(PNJGD("gkob"),REFRESH_ALWAYS,random(4));
AddExit("suroeste","2sotano77");
AddExit("norte","2sotano62");
}



