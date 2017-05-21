/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano44.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_REMOVE,5+random(4));

AddExit("norte","2sotano35");
AddExit("este","2sotano45");
AddExit("suroeste","2sotano54");
}



