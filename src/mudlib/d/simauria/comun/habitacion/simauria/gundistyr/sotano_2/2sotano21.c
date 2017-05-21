/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano21.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_ALWAYS,4+random(4));

AddExit("norte","2sotano14");
AddExit("sudeste","2sotano28");
}



