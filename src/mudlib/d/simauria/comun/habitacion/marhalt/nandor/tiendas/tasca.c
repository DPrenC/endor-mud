/****************************************************************************
Fichero: tasca.c
Autor: Ratwor
Fecha: 03/11/2006
Descripción: la tasca de Nandor.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <nightday.h>

inherit PUB;
create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("La tasca de Nandor");
    SetIntLong("Esta es la tasca de Nandor, un lugar medianamente pequeño, pero acojedor "
        "y familiar. Siempre hay buenos amigos conversando, tomándose unas copas o, "
        "simplemente, pasando el rato.\n Al dueño del local le gusta servir bebidas un "
        "tanto distintas. Al lado de unos cuadros se encuentra colgado el menú.\n ");
    SetIntBright(30);
    SetIntNoise("Escuchas el gentío de la tasca.\n");
    SetIntSmell("Se mezclan los olores de los distintos licores y comidas que aquí se "
        "sirven.\n");
    AddDetail(({"cuadro","cuadros"}), "Son unos cuadros de paisajes, parecen de la parte "
        "del bosque de Marhalt, del río Kandal, e incluso, de una parte del castillo.\n");
    AddExit("sur",MARH("nandor/calle12"));
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta de salida a la calle, de madera y sin adornos.\n",
    ({"puerta", "puerta de madera", "puerta de salida", "puerta de la calle"}),
    ([P_DOOR_CLOSE_TIME : ({ND_NIGHT, ND_PREDAWN, ND_DAWN})]));
    SetKeeper(PNJ("marhalt/tasquero_nandor"));
    SetNotifyExits("sur");
    SetLastDest("../calle12");
    SetCloseTime(({ND_NIGHT, ND_PREDAWN, ND_DAWN}));

    AddDrink("vino tinto", "un vaso de", 4, 8, 5, 0);
    AddDrink("vino blanco", "un vaso de", 4, 8, 5, 0);
    AddDrink( "cerveza rosa", "una jarra de", 5, 5, 10, 0, "Te bebes una jarra de cerveza"
        " rosa. ¡Esta cerveza sabe a fresas!.\n");
    AddDrink( "cerveza especial", "una jarra de", 9, 10, 13, 0, "Te bebes la cerveza "
        "especial que entra como un rayo, parece que le hallan puesto ginebra.\n");
    AddDrink("zumo de mora", "un vaso de", 5, 0,9, 0);
    AddDrink("sidra con tekila", "un chupito de", 7, 15, 5,0);
    AddDrink("zumo de frutas silvestres", "un vaso de", 8, 0,11, 0);
    AddDrink("zumo de naranja con ron", "un vaso de", 5, 6, 7, 0);
    AddSpecial("litru", "un cuenco de", 12, 7, 7, 11, 0, "Te tomas el cuenco del "
        "mejunje este raro... puedes apreciar que lleva chufas trituradas, zumo de limón y algo de ron.\n");
    AddFood("jamón", "unos taquitos de", 8, 11, 0);
    AddFood("queso", "unos taquitos de", 7, 10, 0);
    AddFood("olivas partidas", "unas", 3, 5, 0, "Te metes un puñado de olivas de golpe "
    "en la boca y escupes los huesos a diestro y siniestro.\n");
    AddFood("anchoas", "unas", 5, 7, 0);

    AddItem(PNJ("marhalt/ciego"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,1);
}
