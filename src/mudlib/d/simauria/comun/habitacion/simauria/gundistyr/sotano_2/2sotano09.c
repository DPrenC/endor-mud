/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano09.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("oeste","2sotano08");
AddExit("nordeste","2sotano06");
}



