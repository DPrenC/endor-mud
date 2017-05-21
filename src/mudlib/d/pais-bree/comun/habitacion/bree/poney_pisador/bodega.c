/*
Fichero: bodega.c
Autor: aul�
Fecha: 18/03/2013
Descripci�n:  bodega del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("una peque�a bodega");
    	SetIntLong("Est�s en una peque�a estancia de techo bajo excavada en la misma "
    	"colina de Bree. Aqu� se guardan las reservas de vino de la posada, en un "
    	"ambiente m�s fresco y a buen recaudo, pues dicha bebida no se produce en estas "
    	"tierras y hay que importarla de lugares lejanos. Decenas de botellas se alinean "
    	"colocadas en forma horizontal en el interior de botelleros de arcilla instalados "
    	"junto a las paredes.\n");
    	AddDetail("botelleros",
    	"Son piezas de �spera arcilla cocida colocadas unas encima de otras formando una "
    	"pila y en cuyos orificios se colocan las botellas para su conservaci�n.\n");
    	AddDetail("botellas",
    	"Hay muchas y de origen variado aunque en la mayor�a se ven las se�as que las "
    	"identifican como procedentes de los vi�edos de la Comarca.\n");
    	AddDetail(({"muros", "paredes", "techo", "suelo"}),
    	"Todo es s�lida piedra con marcas visibles del pico que labr� esta estancia en el "
    	"coraz�n de la colina.\n");
    	SetIntSmell("Entre los leves efluvios de la cercana despensa,distingues el agrio "
    	"olor del vino a�ejo.\n");
    	    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("noroeste", "./despensa");
     AddDoor("noroeste", "la puerta",
     "Es una puerta baja y ancha constituida por un grueso tabl�n de madera que aisla "
     "esta bodega del calor que pueda colarse desde la despensa.\n"
     "Por este lado no aprecias ninguna manilla ni picaporte.\n",
     ({"no", "noroeste", "peque�a", "baja", "despensa", "puerta"}));
     
     }