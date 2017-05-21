/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION : [Ch] 11-10-97 Recalibracion de los caracteres a 80 :)
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("la entrada de la prisión");
SetIntLong(
"Estas ante unas escaleras de caracol hechas de piedra, pero al norte y al\n"
"este ves pasillos hechos de tierra, como si hubiesen excavado un tunel a\n"
"ambos lados, ademas hay varias puertas en las paredes del tunel, pero son\n"
"puertas con rejas como si fueran celdas. Parecen los calabozos del Arbol\n"
"de la Vida. Desde el nordeste llega un fuerte ronquido que hace estremecer\n"
"un poco el ambiente. Subiendo las escaleras llegas a la superficie.\n"
);

AddDetail (({"escalera","escalera de caracol","subida"}),"");

SetIntBright(10);
SetIntNoise(
"A lo lejos se olle el amortiguado eco de unas botas y desde la estancia que hay\n"
"al nordeste proceden unos ronquidos ensordecedores.\n");
SetIntSmell("Una suave corriente renueva el aire humedo de la estancia.\n");
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("pasillo4"));
AddExit("este",TASOTANO("pasillo6"));
AddExit("arriba",TABASE("bajada1"));
AddExit("nordeste",TASOTANO("carcelero"));

}