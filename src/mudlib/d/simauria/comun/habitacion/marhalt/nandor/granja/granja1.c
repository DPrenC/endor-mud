/*
Fichero: granja_1.c
Modificado: 12/01/2005: [kastwey@simauria]: Traslado todas las funciones al granjero
para que no sea necesaria la granja en sí.
***/

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;


create () {
  ::create();
  Set(P_INT_SHORT,"el piso inferior de una granja");
  SetIntLong(
    "Te encuentras en el interior de una casa de campo. A un lado se encuentra la "
    "chimenea, donde estan todos los utensilios para la cocina. En medio de la "
    "habitacion hay una gran mesa de madera flanqueada por media docena de sillas. "
    "Al otro extremo una escalera sube al piso superior. Al fondo hay una puerta "
    "de salida.\n");

  SetIndoors(1);  // 1-> cubierto 0-> descubierto
  SetIntBright(30);

  SetIntNoise("No hay ningun sonido que te llame la atencion.\n");
  SetIntSmell("Hueles a pan recien hecho.\n");
  SetLocate("Villa de Nandor");

  AddItem(QUEST "granjero/granjero",REFRESH_DESTRUCT);
  AddDetail(({"utensilios"}),
  "Cacerolas, cucharas de madera, cubos para transportar agua, tinajas, jarras, un "
  "conjunto bastante completo de cacharros domesticos.\n");
  AddDetail(({"mesa"}),
  "Es una gran mesa de madera de roble. Aunque bastante rustica, parece solida.\n");
  AddDetail(({"sillas"}),
  "Son media docena de sillas del mismo estilo que la mesa.\n");
  AddExit("arriba","./granja2");
  AddExit("salir","../sendero1");
  AddExit("norte","./huerto");
}