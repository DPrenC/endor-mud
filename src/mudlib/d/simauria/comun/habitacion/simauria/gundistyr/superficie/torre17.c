/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre17.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("A tus pies observas viejas baldosas destrozadas por el paso de "
"los años entremezclada con la hierba que surge entre las fisuras. Hacia el "
"norte hay un viejo ventanal en el muro.\n"));

AddDetail(({"baldosa","baldosas"}),W("Las baldosas que ves en el suelo "
"están totalmente resquebrajadas por el paso del tiempo y las condiciones "
"atmosféricas. Entre las grietas asoma la hierba.\n"));

AddDetail(({"muro","ventanal"}),W("Al norte hay un muro con un pequeño "
"ventanal. Te asomas y eres capaz de ver el borde del acantilado más "
"lejos, hacia el norte.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("suroeste","torre15");
AddExit("este","torre18");
AddExit("oeste","torre16");
AddExit("sudeste","torre13");
}