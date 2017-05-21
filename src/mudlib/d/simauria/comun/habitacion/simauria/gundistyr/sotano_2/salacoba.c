/* ********************************************************** */
/* *                                                        * */
/* *        ARCHIVO:salacoba.c                              * */
/* *        AUTOR: [a] Articman                             * */
/* *        MODIFICACION: 26/02/02[a] Creación              * */
/* *                                                        * */
/* ********************************************************** */

#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetIntShort("un escondrijo entre las grutas");
SetIntLong(W("Estás en una pequeña habitación rodeada de piedra. En la "
"pared del este ves una sospechosa mata de helechos. A tu alrededor ves "
"leves aspectos de decoración en la sala en la que te encuentras. Junto "
"a un montón de paja observas una pequeña mesilla. Cerca de ella un viejo "
"cuadro y una pequeña pila de objetos.\n"));
AddDetail(({"pared del este","este","pared este"}),W("Parte de la pared al "
"este está cubierta por una espesa mata de helechos.\n"));
AddDetail(({"mata","helechos","mata de helechos"}),W("Observas detenidamente "
"los helechos al este de tu posición y te llama mucho la atención el hecho de "
"que este tipo de vegetación se encuentre en unas cuevas de este tipo. Al "
"observar detenidamente los helechos te das cuenta de que no han crecido de "
"forma natural y de que esconden una salida al este.\n"));
AddDetail(({"paja","montón de paja","montón paja","monton de paja",
"monton paja"}),W("En una de las esquinas de la estancia, un montón de paja "
"yace en el suelo.\n"));
AddDetail(({"mesilla","mesa"}),W("Una vieja mesilla está medio caída en el "
"suelo ya que le falta una de las patas.\n"));
AddDetail(({"cuadro","lienzo"}),W("En el suelo y apoyado en una de las paredes "
"observas un lienzo totalmente negro. No consigues distinguir ningún tipo de "
"dibujo sobre él.\n"));
AddDetail(({"pila","pila de objetos","pila objetos","objetos"}),W("Una pequeña "
"pila de viejos e inservibles objetos está en una esquina.\n"));

AddItem(PNJGD("kobcobar"));
AddExit("este","2sotano05");
HideExit("este",1);
}
