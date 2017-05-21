/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano13.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();
AddItem(PNJGD("kob"),REFRESH_ALWAYS,4+random(4));
AddItem(PNJGD("gkob"),REFRESH_ALWAYS,1+random(2));

AddExit("este","2sotano14");
AddExit("nordeste","2sotano08");
}



