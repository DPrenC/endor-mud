/*    Fichero: pub1.c
      Autor: [I] Izet@Simauria
      Creacion : 3 Feb 1998
      Ultima modificacion : 3 Feb 1998
*/

#include "./path.h"
#include <properties.h>
#include <door.h>

inherit PUB;

create()
{
    ::create();
    SetIntShort("la taberna del Dragón Rojo");
    SetLocate("ciudad de Kha-Annu");
    SetIntLong("Te encuentras en la taberna del 'pequeño dragon azul'. Muchos aventureros se reúnen en "
        "esta taberna a cantar y narrar sus grandes viajes en busca de grandes riquezas. Éste "
        "es el lugar perfecto donde encontrar información acerca de la situación actual sobre "
        "el mundo exterior. Hay un 'menú' sobre la barra.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise("Un ligero murmullo de cantos, voces y risas da calor al ambiente.\n");
    SetIntSmell("Hueles a comida.\n");
    SetKeeper(MONS+"gulfar");
    SetNotifyExits(({"oeste"}));
    AddExit("norte",CIUDAD+"grimly1");
    AddExit("este",CIUDAD+"callejon2");
    AddExit("oeste",CIUDAD+"rurik");
    AddDoor("oeste","la puerta de la calle",
        "Es una enorme puerta de madera tallada.\n",
    ({"puerta","puerta de calle","puerta de la calle"}), GENDER_FEMALE,
    ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddFood("especial de la casa","un plato del",15,18,0);
    AddFood("jabali asado","un plato de",13,15,0);
    AddFood("pollo en salsa de ciruelas","un plato de",11,12,0);
    AddDrink("cerveza negra","una jarra de",6,7,10,0);
}
