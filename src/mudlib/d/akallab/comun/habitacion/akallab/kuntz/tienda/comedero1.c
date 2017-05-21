/*
DESCRIPCION : comedero troll de la Gran Caverna
FICHERO     : /d/akallab/comun/habitacion/akallab/kuntz/tienda/comedero1.c
MODIFICACION: 19-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit PUB;
#include <properties.h>

create() {
  ::create();
  SetIntShort("el comedero troll en la Gran Caverna");
  SetIntLong(
    "Te encuentras en el interior de una amplia cueva que constituye uno "
	  "de los comederos troll. Es aqui donde se reune y cocina "
	  "comunitariamente la caza de la tribu en la fogata que hay en medio de "
	  "la cueva. El aire esta algo viciado y huele carne asada.\n");

AddDetail(({"fogata","brasas"}),
  "En medio de la cueva se encuentra una pequenya fogata. Es alli donde, "
    "generalmete algunas viejas troll, cocinan la carne de la caza diaria "
	"de la tribu. El fuego arde lentamente sobre las brasas.\n");

AddExit("este",K_CUEVA("caverna12"));

SetIntNoise("Oyes el crepitar de las brasas de l fogata.\n");
SetIntSmell("¡Hmmmm! huele a carne asada.\n");
SetLocate("cavernas Troll en Kuntz");
SetIndoors(1);
SetIntBright(30);

AddFood("jabali asado","un trozo de",8,9,0);
AddFood("pollo asado","un plato de",6,6,0);
AddFood("orco asado","un trozo",8,7,0);
AddDrink("vino","un cuenco de",5,6,5,0);
AddDrink("cerveza","un cuenco de",4,5,4,0);

AddItem(PNJ("k_cueva/cocinera"),REFRESH_DESTRUCT,1);
AddItem(PNJ("std/troll2"),REFRESH_DESTRUCT,random(2)+1);
//AddItem(PNJ("k_cueva/borracho"),REFRESH_DESTRUCT,1);
}
