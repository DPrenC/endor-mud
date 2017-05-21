/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:torre22.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en un peque�o recodo de la antigua torre de Gundistyr. "
"En una de los muros ves un viejo candelabro. Exceptuando eso, nada a tu "
"alrededor te llama especialmente la atenci�n.\n"));

AddDetail(({"muros","muro","roca","rocas"}),W("Son s�lo un mont�n de "
"piedras recuerdos de un antiguo muro derruido.\n"));
AddDetail(({"suelo","hierba","yerba"}),W("El suelo esta cubierto por una leve "
"capa de verde hierba. Sin duda, la humedad de la zona ha contribuido a su "
"crecimiento.\n"));
AddDetail(({"candelabro","viejo candelabro"}),W("Sobre la pared hay un viejo "
"candelabro torcido y ya oxidado y negro.\n"));
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));

AddExit("sur","torre20");
AddExit("este","escabajo");
}
