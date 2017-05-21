/*
DESCRIPCION  : entrada oeste al 'arbol de la vida'

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS: falta el archivo que conduce a una ciudad, no
se cual es

SUGERENCIAS: que haya algunas voces que cuando te adentres
en el arbol, te canten o algo asi.

MODIFICADO POR AVENGELYNE, LA MUJER FATAL.

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada oeste al 'árbol de la vida' ");
  SetIntLong(
"Estás ante la entrada oeste del 'árbol de la vida', lugar mágico y sagra-\n"
"do para los elfos. Si continuas hacia el este te adentrarás en él, si vas\n"
"hacia el oeste te dirigirás hacia un camino. Al sur ves una habitación.\n"
"Lo mas cautivador de este lugar es que a pesar de que el suelo sea de\n"
"tierra, tanto las paredes como el techo estan hechos con la corteza del\n"
"árbol.\n"
);



AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise(
"Oyes unos extranyos canticos que te invitan a aden-\n"
"trarte en el arbol\n"
);


SetIntSmell(
"Aspiras el inconfundible aroma a tierra humeda mezclado\n"
"con el olor a madera y savia.\n"
);


SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("este",TABASE("interior4"));
AddExit("oeste","");
AddExit("sur",TABASE("puesto3"));

}