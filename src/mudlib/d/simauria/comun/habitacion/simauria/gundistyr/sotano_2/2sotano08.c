/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano08.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();

AddExit("suroeste","2sotano13");
AddExit("este","2sotano09");
AddExit("norte","2sotano05");
}



