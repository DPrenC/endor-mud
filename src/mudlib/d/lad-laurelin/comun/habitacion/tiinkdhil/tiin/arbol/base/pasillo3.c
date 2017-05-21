/*
DESCRIPCION  : entrada oeste al arbol de la vida

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS: falta un archivo , el que va a alguna ciudad, con salida este

MODIFICADO POR AVENGELYNE, LA MUJER FATAL
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada este al 'arbol de la vida' ");
  SetIntLong(
"Estás en la entrada este del 'árbol de la vida', sitio sagrado para los\n"
"elfos. Hacia el este ves un camino; al oeste te adentras en el árbol. Al\n"
"norte hay una habitación. Esta entrada parece como si estuviera 'excavada'\n"
"en el árbol, ya que tanto las paredes como el techo están formadas con la\n"
"corteza del mismo. Se respira algo mágico en el ambiente.\n"
);



AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise(
"Escuchas unos extranyos canticos que provienen del\n"
"interior del arbol, y que te invitan a que lo explores.\n"
);


SetIntSmell(
"Notas el inconfundible aroma a madera y savia.\n"
);


SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("oeste",TABASE("interior5"));
AddExit("norte",TABASE("puesto2"));


}