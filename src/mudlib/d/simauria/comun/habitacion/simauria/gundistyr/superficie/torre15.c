/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre15.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("A tus pies observas viejas baldosas destrozada por el paso de "
"los a�os. A tu alrededor no observas nada que pueda ser interesante. "
"�nicamente la soledad de una torre perdida en el olvido.\n"
"Si vas hacia el norte y noreste te internaras m�s en la vieja torre. Al "
"oeste de aqu� ves un agujero de forma rectangular que parece ser muy "
"hondo.\n"));
AddDetail(({"baldosa","baldosas"}),W("Las baldosas que ves en el suelo "
"est�n totalmente resquebrajadas por el paso del tiempo y las condiciones "
"atmosf�ricas.\n"));
AddDetail(({"agujero","agujero rectangular"}),W("Un enorme agujero desciende "
"m�s all� de donde tu vista te permite apreciar.\n"));
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("norte","torre16");
AddExit("nordeste","torre17");
}