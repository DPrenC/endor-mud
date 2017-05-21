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
  SetIntShort("la entrada sur al'�rbol de la vida'");
  SetIntLong(
"Te encuentras en la entrada sur del '�rbol de la vida'. Hacia el sur hay\n"
"un camino que conducir� a alguna ciudad; si vas al norte te adentrar�s en\n"
"el �rbol; al este hay una habitaci�n. Esta estancia parece como si estu-\n"
"viera excavada en el �rbol, ya que tanto las paredes como el techo est�m\n"
"formadas con la corteza del mismo. La excepci�n es el suelo que est� hecho\n"
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