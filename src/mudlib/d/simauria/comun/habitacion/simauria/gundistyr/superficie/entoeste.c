/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:entoeste.c                                   * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */
#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Te encuentras frente a las ruinas de una vieja torre. Al "
"norte se alza uno de los pocos muros que se mantienen en pie de estas "
"antiguas ruinas. Hacia el oeste hay unas grandes piedras que te impiden "
"ir hacia alli, mientras que al este se encuentra la entrada a las ruinas.\n"));
AddDetail(({"muro"}),W("Miras hacia el norte y ves una pared que se alza "
"bastantes metros sobre tu cabeza. Sin duda es el muro más alto de los que "
"se mantienen en pie."));
AddDetail(({"piedra","piedras"}),W("Al oeste tienes grandes fragmentos de "
"la torre que te impiden que avances hacia alli."));
AddDetail(({"ruinas","ruina","torre"}),W("Hacia el norte ves los restos de la "
"torre.\n"));
SetIntNoise("Únicamente escuchas una suave brisa.");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));
AddExit("este","enttorre");
}
