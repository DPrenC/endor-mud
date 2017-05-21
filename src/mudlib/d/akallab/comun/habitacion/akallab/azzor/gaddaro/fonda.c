/*
DESCRIPCION : fonda de Gaddaro
FICHERO     : /d/akallab/comun/habitacion/azzor/gaddaro/fonda.c
MODIFICACION:
24-02-99 [Angor] Creacion
??-??-?? [Woo] Modificado para que siga el estandar
16-09-07 [Angor] Typos y modificaciones
*/
#include "path.h"
#include AK_MACRO
inherit PUB;
create() {
 ::create();
SetIntShort("la fonda 'El Tejón rabioso'");
 SetIntLong(
"La fonda del 'Tejón rabioso' es un pequeño y austero local cuyo piso esta "
"elevado del nivel de la calle, probablemente para evitar el agua de las "
"lluvias. De las paredes cuelgan algunas cabezas disecadas de caza local. "
"Las mesas y sillas se encuentran distribuidas de cualquier forma cerca "
"de la chimenea.\n");

 SetIntBright(45);
 
 AddDetail(({"cabezas"}),
 "De las paredes cuelgan cabezas de zorros, osos y un par de lobos.\n");

 AddDetail(({"mesas","sillas"}),
 "La fonda esta llena de ellas. Son todas bastante viejas y no parece haber dos iguales.\n");

 AddDetail(({"chimenea"}),
 "Al fondo hay una pequeña chimenea de piedra junto a la esquina. En ella siempre hay "
 "un agradable fuego que mantiene la fonda a una confortable temperatura.\n");

 SetLocate("valle de Azzor");

 AddExit("oeste",GADDARO("calle02"));
 AddFood("jabali asado","un",20,25,0);
 AddFood("cordero al horno","un",22,24,0);
 AddFood("guiso de cerdo","un plato de",8,9,0);
 AddFood("pollo asado","un",12,14,0);
 AddFood("trucha al horno","una",10,12,0);
 AddFood("sopa de verduras","un plato de",5,6,0);
 AddDrink("vino","un vaso de",5,4,4,0);
 AddDrink("cerveza","una jarra de",6,6,6,0);
}
