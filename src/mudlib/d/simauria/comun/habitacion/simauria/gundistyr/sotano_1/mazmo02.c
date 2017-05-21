/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: mazmo02.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 27/9/01 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"
inherit SIM_ROOM;

create(){
::create();

SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Esta es una de las prisiones de la antigua torre de Gundistyr, "
"ya en ruinas desde hace mucho tiempo. Al lugar, ya t�trico de por si, hay "
"que a�adirle el paso de los a�os. La estancia no tiene m�s que un mont�n de "
"escombros, un viejo mont�n de paja que hace las veces de cama y una peque�a "
"mesilla. Las paredes est�n semiderruidas por el paso de los a�os.\n"));

SetSmell("Por el nauseabundo olor se nota que este lugar lleva tiempo cerrado.\n");
SetNoise("No escuchas m�s que el sonido de tu respiraci�n.\n");

AddDetail(({"pared","paredes"}),W("Las viejas paredes est�n requebrajadas por "
"los a�os, y los ladrillos est�n muy sueltos. Examinando mas detenidamente la "
"pared que tienes al norte encuentras un agujero por que el que podrias pasar "
"y dirigirte al norte.\n"));
AddDetail(({"escombro","escombros"}),W("No son m�s que un mont�n de "
"escombros formados por el techo semiderrumbado y las paredes derruidas.\n"));
AddDetail(({"paja","monton de paja","monton paja","mont�n de paja","mont�n "
"paja"}),W("Es un mont�n de paja amontonado en una esquina. El hecho de que "
"este cubierto por una ra�da y amarillenta s�bana te hace pensar que se hac�a "
"servir como nicho para los presos.\n"));

AddDetail(({"mesilla","mesa"}),W("Es una peque�a mesa de noche sin "
"absolutamente nada en particular.\n"));

SetIndoors(1);
SetIntBright(0);

AddExit("sur","pasi02");
AddExit("norte","cueva03");
HideExit("norte",1);
AddItem(PNJGD("rata"),REFRESH_ALWAYS,2+random(2));
}
