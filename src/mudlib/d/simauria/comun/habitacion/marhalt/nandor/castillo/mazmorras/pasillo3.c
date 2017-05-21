/****************************************************************************
Fichero: pasillo3.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En las mazmorras del castillo
****************************************************************************/

#include "./path.h"
#include <moving.h>

inherit CASTILLO("mazmorras/mazmorras_base");

haz_oeste(){
    if (!TP) return 0;
    if (present("car\ncelero",TO) && query_once_interactive(TP)) {
        write(
        "El carcelero sonríe y te dice: 'Así que tienes interes en visitar nuestras "
        "mazmorras, eh?\n  Bien te complaceré!!!' "
        "Acto seguido te pega una patada y te empuja hacia el oeste.\n");
        say("El carcelero agarra a "+CAP(TNAME)+" y le empuja hacia el oeste.\n");
        TP->heal(-5);
        TP->move(CASTILLO("mazmorras/pasillo4"),M_GO,"oeste");
        return 1;
    }
    TP->move(CASTILLO("mazmorras/pasillo4"),M_GO,"oeste");
    return 1;
}

haz_salir(){
    if (!TP) return 0;
    if (present("car\ncelero",TO) && query_once_interactive(TP)) {
        write(
        "El carcelero te detiene y te dice:\n ¿Adonde te crees que vas?, tanta curiosidad "
        "que tienes pues adentro se ha dicho.\n");
        say("El carcelero agarra a "+CAP(TNAME)+" y le empuja hacia el oeste.\n");
        TP->move(CASTILLO("mazmorras/pasillo4"),M_GO,"oeste");
        return 1;
    }
    TP->move(CASTILLO("mazmorras/pasillo2"),M_GO,"sudeste");
    return 1;
}

create () {
    ::create();
    SetIntShort("la antesala a las mazmorras");
    SetIntLong(
    "Parece que has llegado a un lobrego lugar debajo del castillo, iluminado por "
   "un par de antorchas. Ni siquiera se trata de una construccion propiamente dicha, "
    "parece más bien que este hueco se ganó a la roca a fuerza de pico y pala.\n "
    " El pasillo continúa al oeste y sudeste.\n");
    SetIntBright(21);
    AddDetail("antorchas",
    "Están clavadas en la pared y dan muy poca luz.\n");

    AddExit("sudeste",SF(haz_salir));
    AddExit("oeste",SF(haz_oeste));
    AddItem(PNJCASTILLO("carcelero"),REFRESH_DESTRUCT);
}
