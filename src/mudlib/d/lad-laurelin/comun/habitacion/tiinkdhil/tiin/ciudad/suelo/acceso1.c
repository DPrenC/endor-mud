/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.

               [Ch] Se deberia poner una funcion para los elevadores.
MODIFICACION : [l] lonerwolf
               19/10/00 [l] puse una funcion de prueba para subir al nivel
	                    superior
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el camino El Viajero");
SetIntLong(
"Junto a unos arboles ves una especie de elevadores que permiten llegar hasta\n"
"lo alto de las ramas más gruesas. En las alturas ves como penden pasarelas y\n"
"un sinfin de lianas, por los que se pueden transitar entre ramas adyacentes.\n"
"El camino sigue entre los arboles y se dirige hacia el mayor arbol que hayas\n"
"visto jamas. El tronco es tan grande que ocupa casi todo tu campo visual.\n");

AddDetail (({"elevador","elevadores"}),
"Estas estructuras estan hechas de fuerte cañamo. Permiten el ascenso a las\n"
"partes más altas de los árboles. Gracias a un ingenioso mecanismo de poleas\n"
"se puede ascender sin ningun problema. Hay todo tipo de arneses para subir\n"
"casi cualquier tipo de cosas.\n");

SetIntNoise("Puedes escuchar claramente el mecanismo de Poleas de los elevadores");
SetIntSmell("El olor a savia de árbol se hace más fuerte");
SetLocate("Ciudad Tiinkdel");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("viajero2"));
AddExit("sur",TCSUELO("cruce2"));
AddExit("elevador",TCSUELO("acceso1"));

}

void init(){
   ::init();
   add_action("subir","elevador");
}

int subir()
{
  say(TP->QueryName()+" sube por el elevador\n",TP);
  write("Te montas en el elevador y este sube llevandote al segundo piso\n");
  TP->Move(TCPISO1("2"),M_GO);
  return 1;
}


