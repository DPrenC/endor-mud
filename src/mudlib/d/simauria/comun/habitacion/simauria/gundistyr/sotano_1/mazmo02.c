/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: mazmo02.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 27/9/01 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"
inherit SIM_ROOM;

create(){
::create();

SetIntShort("las mazmorras de Gundistyr");
SetIntLong(W("Esta es una de las prisiones de la antigua torre de Gundistyr, "
"ya en ruinas desde hace mucho tiempo. Al lugar, ya tétrico de por si, hay "
"que añadirle el paso de los años. La estancia no tiene más que un montón de "
"escombros, un viejo montón de paja que hace las veces de cama y una pequeña "
"mesilla. Las paredes están semiderruidas por el paso de los años.\n"));

SetSmell("Por el nauseabundo olor se nota que este lugar lleva tiempo cerrado.\n");
SetNoise("No escuchas más que el sonido de tu respiración.\n");

AddDetail(({"pared","paredes"}),W("Las viejas paredes están requebrajadas por "
"los años, y los ladrillos están muy sueltos. Examinando mas detenidamente la "
"pared que tienes al norte encuentras un agujero por que el que podrias pasar "
"y dirigirte al norte.\n"));
AddDetail(({"escombro","escombros"}),W("No son más que un montón de "
"escombros formados por el techo semiderrumbado y las paredes derruidas.\n"));
AddDetail(({"paja","monton de paja","monton paja","montón de paja","montón "
"paja"}),W("Es un montón de paja amontonado en una esquina. El hecho de que "
"este cubierto por una raída y amarillenta sábana te hace pensar que se hacía "
"servir como nicho para los presos.\n"));

AddDetail(({"mesilla","mesa"}),W("Es una pequeña mesa de noche sin "
"absolutamente nada en particular.\n"));

SetIndoors(1);
SetIntBright(0);

AddExit("sur","pasi02");
AddExit("norte","cueva03");
HideExit("norte",1);
AddItem(PNJGD("rata"),REFRESH_ALWAYS,2+random(2));
}
