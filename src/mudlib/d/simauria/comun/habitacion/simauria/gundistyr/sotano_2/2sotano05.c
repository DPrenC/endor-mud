/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 2sotano05.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 29/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit GD("cuevastd");


create(){
::create();
SetIntLong(TO->QueryIntLong() + "En la pared del oeste ves una "
"sospechosa mata de helechos.\n");

AddDetail(({"pared del oeste","oeste","pared oeste"}),W("Parte de la pared al "
"oeste est� cubierta por una espesa mata de helechos.\n"));
AddDetail(({"mata","helechos","mata de helechos"}),W("Observas detenidamente "
"los helechos al oeste de tu posici�n y te llama mucho la atenci�n el hecho de "
"que este tipo de vegetaci�n se encuentre en unas cuevas de este tipo. Al "
"observar detenidamente los helechos te das cuenta de que no han crecido de "
"forma natural y de que esconden una salida al oeste.\n"));

AddExit("norte","2sotano03");
AddExit("sur","2sotano08");
AddExit("nordeste","2sotano04");
AddExit("oeste","salacoba");
HideExit("oeste",1);
}



