/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:escabajo.c                                   * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */
#include "path.h"
#include <colours.h>

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Ves unas t�tricas escaleras cubiertas de musgo que descienden "
"hacia la oscuridad. Desde tu posici�n no eres capaz de ver donde llevan.\n "
"Exceptuando al este esta sala est� cerrada por un muro de piedra, a "
"excepci�n, claro de las escaleras.\n"));

AddDetail(({"muros","muro","roca","rocas"}),W("Son s�lo un mont�n de "
"piedras recuerdos de un antiguo muro derruido.\n"));
AddDetail(({"suelo","hierba","yerba"}),W("El suelo esta cubierto por una leve "
"capa de verde hierba. Sin duda, la humedad de la zona ha contribuido a su "
"crecimiento.\n"));
AddDetail(({"candelabro","viejo candelabro"}),W("Sobre la pared hay un viejo "
"candelabro torcido y ya oxidado y negro.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("abajo",GSOT1("entrada"));
AddExit("oeste","torre22");
}