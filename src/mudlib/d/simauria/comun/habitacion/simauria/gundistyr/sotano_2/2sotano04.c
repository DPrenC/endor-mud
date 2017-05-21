/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano04.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddItem(PNJGD("kob"),REFRESH_REMOVE,4+random(4));

AddExit("norte","2sotano01");
AddExit("suroeste","2sotano05");
}
