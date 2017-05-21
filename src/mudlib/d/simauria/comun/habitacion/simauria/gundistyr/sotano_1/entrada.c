/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: entrada.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();

SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Estás bajo las ruinas de la torre de Gundistyr, en lo que "
"parece ser la entrada a unas antiguas mazmorras. Observas la escalera "
"medio derruida que sube de nuevo a la superficie. Hacia el oeste se "
"extiende un pasillo, mientras que en el resto de direcciones no ves más "
"que muros de ladrillos.\n"));

AddDetail(({"escalera","escaleras"}),W("Es una vieja escalera de piedra a "
"la que le faltan algunos peldaños y que te lleva de nuevo a la "
"superficie\n"));

AddDetail(({"muro","pared","muros","paredes"}),W("A tu alrededor tienes los "
"viejos muros de estas mazmorras.\n"));

SetSmell(W("Por el nauseabundo olor se nota que este lugar lleva tiempo "
"cerrado.\n"));
SetNoise("No escuchas más que el sonido de tu respiración.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("oeste","pasi07");
AddExit("arriba",GSUP("escabajo"));
}