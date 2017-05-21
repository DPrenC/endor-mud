/*
DESCRIPCION  : entrada sur al 'arbol de la vida'

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS:falta el archivo que va a las calles, y que tiene entrada sur

MODIFICADO POR AVENGELYNE, LA MUJER FATAL

SUGERENCIAS: hacer que cuando te introduzcas en el arbol, haya unas voces que te canten o algo asi

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada sur al'árbol de la vida'");
  SetIntLong(
"Te encuentras en la entrada sur del 'árbol de la vida'. Hacia el sur hay\n"
"un camino que conducirá a alguna ciudad; si vas al norte te adentrarás en\n"
"el árbol; al este hay una habitación. Esta estancia parece como si estu-\n"
"viera excavada en el árbol, ya que tanto las paredes como el techo estám\n"
"formadas con la corteza del mismo. La excepción es el suelo que está hecho\n"
"con tierra.\n"
);



AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise(
"Te parece escuchar unos extranyos canticos invitandote\n"
"a adentrarte em el arbol.\n"
);


SetIntSmell(
"Percibes un fuerte olor a madera y a savia, entremezclado\n"
"con el de la tierra humeda.\n"
);


SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("norte",TABASE("interior7"));
AddExit("este",TABASE("puesto4"));
}