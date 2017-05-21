/****************************************************************************
Fichero: calle12.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  La calle Narwhald.
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <colours.h>
#include <combat.h>
#include <door.h>
#include <properties.h>
#include <nightday.h>
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwald");
    SetIntLong("Los guijarros del suelo, junto con los maceteros y sus correspondientes "
    "plantas, adornan la calle Narwhald en toda su extensión.\n En el sur te encuentras con "
        "el pasaje que se dirije hacia la plaza de la villa, mientras que la "
        "calle continúa de este a oeste.\n Lo que se aprecia al norte es una tasca, "
        "como así lo indica el letrero que cuelga sobre la puerta.\n En el centro "
        "de la calle resalta un poste con una placa de oro en lo alto.\n");
    SetIntSmell("Huele a las plantas de los maceteros que adornan la calle.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "La calle está acompañada a lo largo y ancho por distintas plantas y maceteros.\n"
        " Por esta zona de la calle lo que más abundan son margaritas y algunos cactus "
        "de distintas variedades.\n");
    AddDetail(({"margaritas","margarita"}), "Son las típicas margaritas, si no te ven quizá "
        "puedas coger alguna para deshojarla.\n");
    AddDetail("cactus", "Los hay de distintas variedades, no los toques por si acaso "
        "te pinchas.\n");
    AddDetail(({"letrero","cartel"}), "El letrero con el nombre de la tasca.\n");
    AddReadMsg(({"letrero","cartel"}), "Tasca ¡Yo nooo!.\n");
    AddDetail(({"poste", "placa", "placa de oro"}), "Un poste de madera levanta "
    "una placa de oro hacia lo alto permitiendo su lectura a buena distancia.\n");
    AddReadMsg(({"placa", "placa de oro"}),
    TC_BLUE"^Siente las manos del amigo Donny para que te protejan.^\n"TC_NORMAL);

    AddRoomCmd("coger","cmd_coger");
    AddRoomCmd("tocar","cmd_tocar");
    AddExit("oeste","./calle13");
    AddExit("este","./calle11");
    AddExit("sur","./calle16");
    AddExit("norte","./tiendas/tasca");
    AddDoor("norte", "la puerta de la tasca",
    "Es una puerta de madera que da entrada a la tasca de Nandor.\n",
    ({"puerta", "puerta de madera", "puerta de la tasca", "puerta del norte"}),
    ([P_DOOR_CLOSE_TIME : ({ND_NIGHT, ND_PREDAWN, ND_DAWN})]));
}

public int cmd_coger(string str){
    string *quecojo = ({"margarita", "margarita de maceta", "margarita de la maceta",
                        "margarita de macetero", "margarita del macetero", "flor",
                        "flor de maceta", "flor de la maceta",
                        "flor de macetero", "flor del macetero"});
    object margarita;

    if (!str) return 0;
    if (member(quecojo, str) >= 0) {
        if (present("margarita",TP) || present("margarita",TO))
            return notify_fail("¡Deja las flores en paz que no te han hecho nada!.\n",
            NOTIFY_NOT_VALID);

        margarita = clone_object(OTRO("marhalt/nandor/margarita"));
        write("Disimuladamente arrancas una margarita del macetero de la calle.\n");
        if (margarita->move(TP,M_SILENT)!=ME_OK ){
            write("Llevas muchas cosas encima como para coger algo tan delicado "
            "y sin poder evitarlo se te cae al suelo.\n");
            say("A "+CAP(TNAME)+" se le cae una margarita al suelo.\n");
            margarita->move(environment(TP));
        }
        return 1;
    }
    return 0;
}

public int cmd_tocar(string str){
    if(!str) return 0;
    if(str=="cactus" || str=="Cactus"){
        write("Tocas un cactus y te pinchas dolorosamente.\n");
        say(CAP(TNAME)+" ingenuamente toca un cactus y se pincha, tiene pinta de "
        "haberle dolido.\n");
        TP->Defend(1,DT_PIERCE,DEFEND_NOMSG);
        return 1;
    }else{
        return notify_fail("Piénsatelo mejor antes de tocar cualquier cosa.\n",
        NOTIFY_NOT_VALID);
    }
}
