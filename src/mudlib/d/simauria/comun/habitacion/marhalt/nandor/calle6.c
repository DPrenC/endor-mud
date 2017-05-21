/*   calle6.c
     Articman 3/5/2002 Castellanización y retoques */
#include "./path.h"
#include <combat.h>
#include <skills.h>
#include <moving.h>
#include <sounds.h>
inherit SIM_ROOM;

public int subir_algarrobo(){
    object algarrobo = find_object(MARH("nandor/algarrobo"));
    int intento=TP->UseSkill(HAB_TREPAR, 10);
    if (query_once_interactive(TP)){
        if (TP->QueryTP()<1)
            return notify_fail("Has agotado tus fuerzas, descansa un rato.\n");
        if (intento> 0){
            TP->move(MARH("nandor/algarrobo"), M_SPECIAL,
            ({"sube al algarrobo con agilidad...",
              "llega ágilmente desde abajo...",
              "subes trepando hasta la copa del algarrobo..."}));
            TP->AddTP(-d3());
            return 1;
        } else {
            write ("Intentas trepar al algarrobo, pero el intento te hace estamparte "
            "contra el suelo.\n");
            say (CAP(TNAME)+" intenta trepar al algarrobo, pero el intento le sale "
            "fallido y se cae al suelo.\n");
            tell_room(MARH("nandor/algarrobo"), CAP(TNAME)+
            " intenta subir hasta aquí trepando torpemente, pero se cae pegándose un "
            "fuerte golpe contra el suelo.\n");
            TP->Defend(d20(),TD_APLASTAMIENTO,DEFEND_NOMSG);
            TP->AddTP(-d3());
            play_sound(algarrobo, SND_SUCESOS("caida_fuerte"), 0, 50);
            play_sound(TO, SND_SUCESOS("caida_fuerte"));
            return 1;
        }
    }
}


create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("una calle cualquiera");
    SetIntLong("Estás en una calle algo apartada del centro del pueblo, en la que "
        "se nota que el bullicio es menor.\n  La calle discurre hacia el sur, en "
        "dirección a un cruce de caminos, y hacia el norte se llega a la plaza del "
        "pueblo.\n  Al este observas una casa vieja y medio destartalada.\n  Ya no se "
        "ven en esta zona maceteros con flores, pero sí puedes ver que a un costado "
        "del camino se levanta un viejo algarrobo, del que caen algunas algarrobas "
        "de vez en cuando.\n");

    AddRoomCmd("coger", "cmd_coger");
    AddRoomCmd("gritar", "cmd_gritar");
    SetIndoors(0);
    AddDetail(({"arbol", "árbol", "algarrobo"}), "Es un viejo árbol de tronco rugoso "
        "y hojas de color verde. Aunque no parece que lo cuiden mucho, este árbol se "
        "las arregla para continuar dando algarrobas.\n");
    AddDetail("huellas", "Son huellas de ruedas de las diligencias que pasan por este "
        "camino.\n");
    AddDetail(({"algarroba", "algarrobas", "frutos", "fruto"}), "las algarrobas son "
        "vainas retorcidas de color verde amarronado con que muchas veces se alimentan "
        "los caballos que tiran de las diligencias que pasan por aquí.\n");
    AddDetail(({"casa", "casita"}), "Es una casita pequeña, pero no parece que quien "
        "viva en ella se ocupe mucho de cuidar de su aspecto.\n");

    AddExit("norte","./calle5");
    AddExit("sur","./calle7");
    AddExit(({"trepar","subir","arriba"}), SF(subir_algarrobo));
    HideExit(({"subir", "trepar","arriba"}),1);
    AddExit("este","./casas/casa6" );
    AddDoor("este");
}

public int cmd_coger(string str){
    string *quecoger = ({"algarroba", "algarrobas", "fruto", "frutos", "algarrobas de algarrobo",
                         "algarrobas del algarrobo", "algarroba de algarrobo",
                         "algarroba del algarrobo", "fruto de algarrobo", "fruto del algarrobo",
                         "frutos de algarrobo", "frutos del algarrobo"});
    if (!str) return 0;
    if (member(quecoger, str) >= 0) {
        write("Saltas intentando coger alguna algarroba del árbol, pero parece que "
        "no llegas.\n");
        say(CAP(TNAME)+ " salta para intentar coger algarrobas del árbol, pero están "
        "muy altas y no va a llegar.\n");
        return 1;
    }
    return 0;
}

public void init(){
    ::init();
    call_out("merodear",1);
}

public void merodear(){
    tell_room(MARH("nandor/algarrobo"), "Ves a "+CAP(TNAME)+ " que"
        " merodea debajo del algarrobo.\n");
}

public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    call_out("irse",1);
}

public void irse(){
    object algarrobo= find_object(MARH("nandor/algarrobo"));
    if(!present(TP,algarrobo))
    tell_room(MARH("nandor/algarrobo"), CAP(TNAME)+" se aleja del algarrobo.\n",({TP}));
}

public int cmd_gritar(string str){
    if (!str){
        tell_room(MARH("nandor/algarrobo"), "Escuchas que alguien grita muy fuerte "
        "desde abajo.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/algarrobo"), "Escuchas que alguien grita desde abajo: '"
        +str+"'.\n");
        return 0;
    }
}
