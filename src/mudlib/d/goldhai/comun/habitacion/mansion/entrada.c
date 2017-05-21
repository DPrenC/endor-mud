#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
 ::create();
 SetIntShort("la entrada de la mansi�n");
SetIntLong(
"Te encuentras en la entrada de esta mansi�n, un lugar bastante espacioso "
"sobre el que cuelga una impresionante l�mpara de ara�a con miles de "
"piezas de cristal. La estancia se prolonga hasta el sal�n que queda al sur. "
"Una escalinata de madera finamente tallada asciende junto a la pared hasta "
"el piso superior. Al este, la puerta principal permite salir al exterior.\n");

AddDetail(({"escalera","escalinata"}),
"La barandilla de la escalinata esta finamente tallada con motivos vegetales "
"como si fuese una enredadera con frutos. La escalinata permite subir a la "
"planta superior de la mansi�n.\n");

AddDetail(({"lampara","l�mpara"}),
"Tiene forma de ara�a con 10 brazos de los que cuelgan cristales tallados de "
"distintos tama�os. Juzgas que debe pesar bastante.\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(50);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 SetTPort(TPORT_NO);
 AddItem(PNJ("crowy/kguardia_elfo"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/kguardia_humano"),REFRESH_DESTRUCT);

 AddExit("arriba",MANSION("dormitorio"));
 AddExit("oeste",MANSION("cocina"));
 AddExit("sur",MANSION("comedor"));
 AddExit("este",BOSCURO("frente_mansion"));

 SetLocate("mansi�n de Hardester Rankomme");
}
