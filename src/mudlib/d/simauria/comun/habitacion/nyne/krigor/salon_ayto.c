/*
DESCRIPCION  : Salon de reuniones en el ayuntamiento
FICHERO      : KRIGOR(salon_ayto.c)
MODIFICACION : 26-11-01 [Chaos@Simauria] Creacion.
               27-11-01 [Chaos@Simauria] modificacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SCHEDULER_ROOM;

create() {
    ::create();
    SetIntShort("el salón del ayuntamiento");
    SetIntLong(
     "Estás en una amplia sala de reuniones en el ayuntamiento. Aquí se reune la gente "
     "del pueblo cuando se debe discutir algún tema de interés común o por el mero "
     "hecho de charlar un rato. Al fondo hay una chimenea y varios cómodos butacones "
     "donde descansar y charlar al calor del fuego.\n");

    AddDetail(({"chimenea","brasas"}),
    "Es una chimenea baja y ancha de piedra en la que arden lentamente las brasas de "
     "un fuego, proporcionando una agradable temperatura al ambiente.\n");

    AddDetail(({"butacones","butacas"}),
    "Junto a la chimenea y formando un pequeño corro hay unos cuantos butacones que "
     "sin duda conocieron tiempos mejores. Son una especie de sofas individuales "
     "forrados con una descolorida tela de color rojizo.\n");

    AddDetail("trofeos",
    "A lo largo de las paredes del salón hay colgados varios trofeos obtenidos por "
     "algunos de los ciudadanos del pueblo. Puedes observar varias cabezas disecadas "
     "de animales salvajes.\n");

    AddDetail(({"cabezas","cabezas disecadas"}),
     "Seguro que sus dueños ya no las echan de menos.\n");

    SetIntNoise("Las brasas del fuego crepitan ocasionalmente.\n");
    SetIntSmell("Huele un poco a humo.\n");
    SetLocate("Krigor");
    SetIntBright(30);
    AddExit("sur",KRIGOR("ayuntamiento"));
    SetMainRoom("./ayuntamiento");
    SetNotifyExits(({}));
    SetLastDest("./plaza");
}