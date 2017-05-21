/****************************************************************************
fichero: tasca.c
Autor: Kastwey
Descripción: Tasca
****************************************************************************/

#include <moving.h>
#include "path.h"

inherit "/std/pub";
#define nombre capitalize(TP->QueryName())
#define Sexo     (TP->QueryGenderEndString())
#define SexoSaludo     (TP->QueryGender()==2?"a":"e")
int ir_sur();

void init() {
    ::init();
    write("hola "+nombre+". Bienvenid"+Sexo+" a mi tasca.\n");
    say(nombre+" entra a la tasca de kastwey. Kastwey l"+SexoSaludo+" saluda.\n",TP);
}

create() {
    ::create();

    SetIntShort("la tasca de Kastwey");
    SetLocate("Dominios de Kastwey");
    SetIntLong("Estás en la tasca de Kastwey.\n"
"Es un local más bien pequeño, con algunas mesas desperdigadas sin ton ni son,\n"
"aunque con un que se yo, que le da cierto toque artístico.\n"
"Hacia el norte puedes ver la habitación de pruebas de Kastwey.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise("El sonido de risas y voces es muy fuerte.\n");
    SetIntSmell("Un olor a comida sale de la cocina.\n");

    AddExit("norte",SF(ir_sur));

    AddDetail(({"mesas","mesa","mesillas"}),"Son unas mesas  de madera muy rallada.\n"
    "En alguna de ellas puedes ver inscripciones grabadas a cuchillo.\n");

//    AddItem("/players/kastwey/pnj/rezthen.c",REFRESH_DESTRUCT,1);
//    AddItem("/players/kastwey/pnj/mosca.c",REFRESH_DESTRUCT,1);

    AddFood("serpiente al jugo","un plato de",10,13,0);
    AddFood("Chuleta de cerdo con patatas","un plato",9,12,0);
    AddFood("solomillo a la pimienta con patatas","un plato de",10,15,0);
    AddFood("sopa de verduras","un plato de",7,8,0);

    AddDrink("cerveza","una jarra de",3,4,8,0);
    AddDrink("flameado de Kastwey","una copita de",3,4,8,0);
}

int ir_sur() {
    if (!present("invitacion",TP) && TP->QueryName() != "kastwey") {
        write("La puerta de la habitacion de pruebas esta cerrada con llave.\n"
              "Necesitarás una invitación para pasar.\n");
    }
    else {
    write("\nAbres la puerta de la habitacion de pruebas... y entras.\n\n");
        TP->move(TORRE("/rooms/kastwey/workroom"), M_GO);
    }
    return 1;
}



