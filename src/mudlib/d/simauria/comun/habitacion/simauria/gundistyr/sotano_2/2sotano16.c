/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano16.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 2/10/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");

create(){
::create();
SetIntLong(W(TO->QueryIntLong() + "Hacia el sur ves una abrupta "
"pendiente. Si vas hacia all� dudas que puedas volver atr�s.\n"));
AddExit("oeste","2sotano15");
AddExit("sur","2sotano22");
}
