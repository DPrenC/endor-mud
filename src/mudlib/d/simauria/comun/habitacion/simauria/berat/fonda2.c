/*
DESCRIPCION  : posada de grenel
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/fonda2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Maler]
07/05/2007, [Y] (Yalin): suprimo funciones de puerta, y a�ado puertas reales.
*/
#include "path.h"
#include <properties.h>
#include <door.h>
inherit SIM_ROOM;


create() {
   ::create();
  SetIntShort("la posada de Grenel");
  SetIntLong(W(
"Te encuentras en el piso superior de la posada, "
"aqu� puedes ver una habitaci�n a cada lado del "
"pasillo, y una alfombra marr�n que contin�a hacia "
"las escaleras.\nUnas antorchas en la pared de delante "
"iluminan este piso.\n"));
   SetIntBright(70);
   SetIndoors(1);
  AddDetail(({"habitaciones"}),
"Ves las dos habitacions que hay en este piso.\n");

   AddDetail(({"alfombra","alfombra marron"}),
"Es una polvorienta alfombra marr�n.\n");
   AddDetail(({"escaleras"}),
"Est�n justo al final del pasillo, cubiertas por una alfombra marr�n.\n");
  AddExit("oeste","./room2");
  AddExit("este","./room1");
  AddExit("escaleras","./fonda");
    AddDoor("este","la puerta de la habitaci�n humilde",
        "Es una puerta de madera lisa, muy corriente.\n",
        ({"puerta","puerta este","puerta humilde","puerta de habitaci�n humilde",
        "puerta de habitacion humilde"}), GENDER_FEMALE,"llave1hum",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    
    AddDoor("oeste","la puerta de la habitaci�n noble",
        "Es una puerta de madera lisa, aunque muy bien pintada y barnizada.\n",
        ({"puerta","puerta oeste","puerta noble","puerta de habitaci�n noble",
        "puerta de habitacion noble",}), GENDER_FEMALE,"llave2nob",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}

