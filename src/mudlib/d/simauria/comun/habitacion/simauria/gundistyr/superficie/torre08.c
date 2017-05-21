/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre08.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en un pasillo de la antigua torre que une el hall con "
"las dependencias al norte. El paisaje no es muy distinto del resto de salas."
"�nicamente restos de piedra gris, muros a medio derruir, y desechos por "
"todas partes.\n"));

AddDetail(({"piedra","piedras","piedra gris","restos de piedra gris"}),
"Son restos de piedra gris�cea con la que fue construida la torre.\n");

AddDetail(({"muro","muros"}),W("Los muros que tienes hacia el este y oeste no "
"tendr�n una altura superior al medio metro. Tras ellos no ves m�s que rocas "
"m�s rocas.\n"));
AddDetail(({"desechos"}),"Son �nicamente restos de la antigua torre.\n");

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("norte","torre11");
AddExit("sur","torre05");
AddExit("sudeste","torre06");
}
