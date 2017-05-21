/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION : sandalin
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la salida sur");
  SetIntLong(
"Te sientes observado. Notas como infinidad de pares de ojos te miran a cada\n"
"paso que das. Te sientes incomodo. Miras a tu alrededor. Solo ves arboles.\n""Uno te impresiona. Un gigantesco arbol de mas de cuarenta metros de alto\n"
"escoltado por dos enormes arboles con unas pequeñas entradas. Puesta en uno\n"
"de los ellos hay una gran placa que brilla misteriosamente. Entre las\n"
"gigantescas ramas de los arboles mas grandes, ves como penden lianas y puentes\n"
"colgantes que hacen posible el transito. El camino se prolonga hacia el norte.\n"
"Hacia el sur esta el bosque de Lomilmand. Al este y oeste distingues dos huecos\n"
"en los arboles.\n");

AddDetail (({"placa","gran placa"}),
"Se trata de una placa hecha de salvia de un color azulado y bastante dura.\n"
"En su superfice se puede leer un mensaje.\n ");

SetIntNoise("");
SetIntSmell(
"Notas como tus fosas nasales se dilatan. El aire puro del bosque corre ahora\n"
"por tus venas. Te sientes revitalizado. Inspiras una vez mas mientras te\n"
"preparas para iniciar la marcha.\n"
);
SetLocate("Tiink");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("acceso2"));
AddExit("sur",TBOSQUE("bosque218"));
AddExit("este",TCSUELO("puesto8"));
AddExit("oeste",TCSUELO("puesto7"));

}