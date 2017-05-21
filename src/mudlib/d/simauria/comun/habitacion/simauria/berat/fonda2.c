/*
DESCRIPCION  : posada de grenel
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/fonda2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Maler]
07/05/2007, [Y] (Yalin): suprimo funciones de puerta, y añado puertas reales.
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
"aquí puedes ver una habitación a cada lado del "
"pasillo, y una alfombra marrón que continúa hacia "
"las escaleras.\nUnas antorchas en la pared de delante "
"iluminan este piso.\n"));
   SetIntBright(70);
   SetIndoors(1);
  AddDetail(({"habitaciones"}),
"Ves las dos habitacions que hay en este piso.\n");

   AddDetail(({"alfombra","alfombra marron"}),
"Es una polvorienta alfombra marrón.\n");
   AddDetail(({"escaleras"}),
"Están justo al final del pasillo, cubiertas por una alfombra marrón.\n");
  AddExit("oeste","./room2");
  AddExit("este","./room1");
  AddExit("escaleras","./fonda");
    AddDoor("este","la puerta de la habitación humilde",
        "Es una puerta de madera lisa, muy corriente.\n",
        ({"puerta","puerta este","puerta humilde","puerta de habitación humilde",
        "puerta de habitacion humilde"}), GENDER_FEMALE,"llave1hum",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    
    AddDoor("oeste","la puerta de la habitación noble",
        "Es una puerta de madera lisa, aunque muy bien pintada y barnizada.\n",
        ({"puerta","puerta oeste","puerta noble","puerta de habitación noble",
        "puerta de habitacion noble",}), GENDER_FEMALE,"llave2nob",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}

