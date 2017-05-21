/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre21.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Muros y rocas te rodean, haciendo que la �nica salida "
"existente se encuentre al oeste.  A tu alrededor tan s�lo observas "
"rocas y el aire libre...\n"));

AddDetail(({"muros","muro","roca","rocas"}),W("Son s�lo un mont�n de "
"piedras recuerdos de un antiguo muro derruido.\n"));
AddDetail(({"suelo","hierba","yerba"}),W("El suelo esta cubierto por una leve "
"capa de verde hierba. Sin duda, la humedad de la zona ha contribuido a su "
"crecimiento.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("oeste","torre20");					
}
