/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: pasi05.c                                              * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Este es el pasillo a trav�s del cual se puede acceder a "
"las antiguas mazmorras de Gundistyr. Hacia el este se encuentra la "
"salida de este antiguo lugar, mientras que si vas hacia el oeste podr�s "
"acceder a las viejas celdas de esta torre.\n"));
AddDetail(({"celda","celdas"}),W("Hacia el norte y hacia el sur observas lo "
"que en su tiempo eran las celdas de esta torre. Puedes entrar a ellas sin "
"problemas debido a que el paso de los a�os ha hecho que la puerta que las "
"protege sea inutil...\n"));

SetSmell("Por el nauseabundo olor se nota que este lugar lleva tiempo cerrado.\n");
SetNoise("No escuchas m�s que el sonido de tu respiraci�n.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("este","pasi06");
AddExit("oeste","pasi04");
AddExit("norte","mazmo05");
AddExit("sur","mazmo10");
}