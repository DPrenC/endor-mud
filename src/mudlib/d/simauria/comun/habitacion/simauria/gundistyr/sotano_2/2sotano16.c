/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano16.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");

create(){
::create();
SetIntLong(W(TO->QueryIntLong() + "Hacia el sur ves una abrupta "
"pendiente. Si vas hacia allí dudas que puedas volver atrás.\n"));
AddExit("oeste","2sotano15");
AddExit("sur","2sotano22");
}
