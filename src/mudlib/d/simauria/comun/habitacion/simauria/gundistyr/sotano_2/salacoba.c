/* ********************************************************** */
/* *                                                        * */
/* *        ARCHIVO:salacoba.c                              * */
/* *        AUTOR: [a] Articman                             * */
/* *        MODIFICACION: 26/02/02[a] Creaci�n              * */
/* *                                                        * */
/* ********************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("un escondrijo entre las grutas");
SetIntLong(W("Est�s en una peque�a habitaci�n rodeada de piedra. En la "
"pared del este ves una sospechosa mata de helechos. A tu alrededor ves "
"leves aspectos de decoraci�n en la sala en la que te encuentras. Junto "
"a un mont�n de paja observas una peque�a mesilla. Cerca de ella un viejo "
"cuadro y una peque�a pila de objetos.\n"));
AddDetail(({"pared del este","este","pared este"}),W("Parte de la pared al "
"este est� cubierta por una espesa mata de helechos.\n"));
AddDetail(({"mata","helechos","mata de helechos"}),W("Observas detenidamente "
"los helechos al este de tu posici�n y te llama mucho la atenci�n el hecho de "
"que este tipo de vegetaci�n se encuentre en unas cuevas de este tipo. Al "
"observar detenidamente los helechos te das cuenta de que no han crecido de "
"forma natural y de que esconden una salida al este.\n"));
AddDetail(({"paja","mont�n de paja","mont�n paja","monton de paja",
"monton paja"}),W("En una de las esquinas de la estancia, un mont�n de paja "
"yace en el suelo.\n"));
AddDetail(({"mesilla","mesa"}),W("Una vieja mesilla est� medio ca�da en el "
"suelo ya que le falta una de las patas.\n"));
AddDetail(({"cuadro","lienzo"}),W("En el suelo y apoyado en una de las paredes "
"observas un lienzo totalmente negro. No consigues distinguir ning�n tipo de "
"dibujo sobre �l.\n"));
AddDetail(({"pila","pila de objetos","pila objetos","objetos"}),W("Una peque�a "
"pila de viejos e inservibles objetos est� en una esquina.\n"));

AddItem(PNJGD("kobcobar"));
AddExit("este","2sotano05");
HideExit("este",1);
}
