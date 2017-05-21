/*

DESCRIPCION  :

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS:

MODIFICACION :

*/



#include "./path.h"


#include <properties.h>

#include <rooms.h>



inherit ROOM;



create() {

  ::create();

SetIntShort("el camino del cementerio");

SetIntLong("  Solo queda una basta extension de terreno llena de tumbas y lapidas hacinadas\n"+

	   "el camino se desvanecio al pasar el arco de piedra. Pero las lapidas parece\n"+

           "que solo permiten dos caminos posibles al norte o al sur desde aqui.\n");

AddDetail(({"lapidas","sepulturas","tumbas"}),"  Las lapidas son de construccion simple, pero en estas estan mal\n"+

                                              "colocadas da la sensacion de que alguien ha estado cavando, sobre\n"+

                                              "cada una de las tumbas.\n");



AddDetail (({"niebla"}),"  En este punto del camino la niebla ya casi ha desaparecido excepto\n"+

                        "cerca del suelo donde aun permanece impidiendo ver con claridad el suelo.n");

SetIntNoise("  Se oye un ruido familiar, parece ser el de un fuego encendido.\n");



SetIntSmell("  Definitivamente huele a carne podrida.\n ");

SetLocate("Cementerio2");

SetIndoors (0); /* 0 exterior; 1 interior */

SetIntBright(20);


AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");
AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");


AddExit("norte","camino12");

AddExit("sur","camino11");


}
