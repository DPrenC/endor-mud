/*
Fichero: bodega.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  bodega del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("una pequeña bodega");
    	SetIntLong("Estás en una pequeña estancia de techo bajo excavada en la misma "
    	"colina de Bree. Aquí se guardan las reservas de vino de la posada, en un "
    	"ambiente más fresco y a buen recaudo, pues dicha bebida no se produce en estas "
    	"tierras y hay que importarla de lugares lejanos. Decenas de botellas se alinean "
    	"colocadas en forma horizontal en el interior de botelleros de arcilla instalados "
    	"junto a las paredes.\n");
    	AddDetail("botelleros",
    	"Son piezas de áspera arcilla cocida colocadas unas encima de otras formando una "
    	"pila y en cuyos orificios se colocan las botellas para su conservación.\n");
    	AddDetail("botellas",
    	"Hay muchas y de origen variado aunque en la mayoría se ven las señas que las "
    	"identifican como procedentes de los viñedos de la Comarca.\n");
    	AddDetail(({"muros", "paredes", "techo", "suelo"}),
    	"Todo es sólida piedra con marcas visibles del pico que labró esta estancia en el "
    	"corazón de la colina.\n");
    	SetIntSmell("Entre los leves efluvios de la cercana despensa,distingues el agrio "
    	"olor del vino añejo.\n");
    	    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("noroeste", "./despensa");
     AddDoor("noroeste", "la puerta",
     "Es una puerta baja y ancha constituida por un grueso tablón de madera que aisla "
     "esta bodega del calor que pueda colarse desde la despensa.\n"
     "Por este lado no aprecias ninguna manilla ni picaporte.\n",
     ({"no", "noroeste", "pequeña", "baja", "despensa", "puerta"}));
     
     }