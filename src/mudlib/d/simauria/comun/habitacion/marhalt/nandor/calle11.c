/****************************************************************************
Fichero: calle11.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  La calle Narwhald
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwhald");
    SetIntLong(" Continúas en la calle Narwhald, paralela a la calle principal de"
        " la villa, con sus brillantes guijarros en el suelo y sus maceteros adornando el"
        " ambiente.\n Hacia el norte puedes acceder al porche de una casa, mientras que al"
        " sur tienes una pared, posiblemente perteneciente a otra casa o tienda, aunque "
        "el cartel que cuelga quizá te lo indique.\n La calle continúa al este y oeste.\n");
    AddDetail(({"porche","norte"}), "da entrada a una vivienda.\n ");
    AddDetail(({"cartel","letrero"}), "Está a casi 3 metros de altura pegado en la pared "
        "del sur.\n");
    AddReadMsg(({"cartel","letrero"}), "La armería del buen guerrero.\n  Se entra por la "
        "otra calle.\n");
    SetIntNoise("Te ha parecido escuchar unos cantos un tanto extraños provenientes del "
        "norte, aunque ahora han  cesado.\n");
    SetIntSmell("Huele a las plantas de la calle.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "A lo largo de toda la calle se pueden ver distintas plantas en sus maceteros.\n"
        " Por esta parte de la calle puedes ver pequeñas palmeritas, cikus, galateas y "
        "unas pocas amapolas.\n");
    AddDetail(({"galateas", "cikus", "amapolas", "palmeritas", "palmeras"}),
        "Son las plantas que adornan esta parte de la calle en sus maceteros.\n");
    AddDetail(({"pared","pared sur","sur"}), "Será el lateral de una tienda, Hay un cartel"
        " pegado.\n");
    AddExit("oeste","./calle12");
    AddExit("este","./calle10");
    AddExit("norte","./casas/porche");
}

init(){
    ::init();
    call_out("paseante",1);
}

public void paseante(){
    tell_room(MARH("nandor/casas/porche"), "Ves como " +CAP(TNAME)+ " pasea por la "
        "calle Narwhald.");
}
