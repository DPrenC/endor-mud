/*
DESCRIPCION  : Entrada Norte de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/ciudad/suelo/salida1.c
NOTAS        : Creado por Chantiel
MODIFICACION : [l] Lonerwolf
               [l] 17/01/03Me he decidio a sacar la zona, asi que le he hecho unos
               retoques a los detalles de la habitacion
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("la salida norte");
SetIntLong(
"Ante ti se abre la espesa maleza protectora de la ciudad. Hay grandes árboles\n"
"que te rodean y forman un camino natural por el que se puede transitar. Pero\n"
"lo que realmente atrae la atencion es el gigantesco árbol de más de cuarenta\n"
"metros de altura que esta al sur del paseo. A ambos lados del camino hay dos\n"
"árboles con una entrada labrada en su tronco. Puesta en uno de los ellos hay\n"
"una gran placa que brilla misteriosamente. Entre las gigantescas ramas de los\n"
"árboles más grandes, ves como penden lianas y puentes colgantes que hacen\n"
"posible el tránsito. El camino se prolonga hacia el sur. Hacia el norte esta\n"
"el bosque de Lomilmand.\n");

AddDetail (({"placa","gran placa"}),
"Se trata de una placa hecha de savia de un color azulado y bastante dura.\n"
"En su superfice se puede leer un mensaje.\n ");

AddDetail (({"liana","Liana"}),
"Es una cuerda hecha con los filamentos que se desprenden de los arboles.\n");

AddDetail (({"arbol","árbol"}),
"Es un arbol realmente grande, es el mas grande que jamas hayas visto. Te\n"
"preguntas cuantos años tendra ese arbol.\n ");

AddDetail (({"puente","Puente"}),
"Es un puente hecho de madera y lianas.\n");

SetIntNoise("Escuchas el canto de los elfos. Pero tristemente no logras comprender lo que dice, supones que es el idioma elfico de la region");
SetIntSmell("Huele a savia de árbol por todo el lugar");
SetIndoors (0); /* 0 exterior; 1 interior */
SetLocate("Ciudad Tiinkdel");


AddExit("norte",TBOSQUE("bosque185"));
AddExit("sur",TCSUELO("viajero2"));
AddExit("este",TCSUELO("puesto2"));
AddExit("oeste",TCSUELO("puesto1"));

}
void init(){
   ::init();
   add_action("fleer","leer");
}

int fleer(string cadena){
   if(cadena != "placa"){
      write("Leer que?\n");
      return 1;
   }
   else{
     write("Escrito en la placa lees:\n"
	   "Bien venido a la ciudad de Tiink extranjero,\n"
	   "te encuentras en el sendero El Aventurero.\n");
     say(TP->QueryName()+" lee una placa.\n");
     return 1;
   }
}