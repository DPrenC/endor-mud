/*
Fichero: manzano.c
Autor: aulë
Fecha: 02/10/2014
Descripción: en lo alto del manzano del huerto.
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <skills.h>
#include <moving.h>
#include <sounds.h>

inherit BREE_ROOM;
public int bajar_manzano();
public string mirar_abajo(){
    object abajo = load_object(BREE("c1_huerto2"));
    if (!abajo)
    return "Se ve el huerto.\n";
    write("Desde aquí ves como el huerto sembrado se extiende hacia el norte, al oeste la "
    "colina baja hasta la empalizada con un estrecho sendero que la jalona y al este se "
    "extiende un patio entre la casa, el establo y un bajo cobertizo.\n"
    + abajo->Content());
    return "";
}

create(){
    ::create();
    SetLocate("sobre las ramas de un manzano");
    SetIntShort("las ramas de un manzano");
    SetIntLong(
    "Te encuentras en lo alto de un manzano, donde varias de sus gruesas ramas nacen del "
    "tronco bifurcado, formando un pequeño espacio donde se puede estar sentado.\n"
    "A tu alrededor el ramaje se entrecruza cubierto de hojas y algunas telarañas.\n"
    "Pueden verse algunas manzanas que aún no han sido recogidas.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el susurro de las hojas y, de vez en cuando, algún mugido o "
    "cacareo procedente de los establos.\n");
    SetIntSmell("Huele a hojas verdes y, levemente, a manzanas.\n");
    AddDetail(({"arbol", "árbol", "manzano"}),
    "Este gran manzano nace al sur del huerto de la casa y su sombra llega al límite del "
    "sembrado. Por su tamaño debe de llevar plantado aquí muchos años.\n");
    AddDetail(({"manzana", "manzanas", "frutos", "fruto", "fruta", "frutas"}),
"Algunas manzanas de distintos tamaños y en diversos estados de maduración cuelgan "
"separadas o por grupos de las ramas del árbol.\n");
    AddDetail(({"abajo", "huerto"}), SF(mirar_abajo));

    SetMaxIntWeight(450000);
    AddExit("abajo", SF(bajar_manzano));
    HideExit("abajo",1);
    AddRoomCmd("coger", "cmd_coger");
AddRoomCmd(({"bajar","descender"}), "bajar_manzano");
}

public int cmd_coger(string str){
    if (!str) return 0;
    if (str=="manzanas" || str=="manzana" || str=="fruta" || str=="frutas"
        || str=="fruto" || str=="frutos"){
        write("No encuentras ninguna manzana a tu alcance.\n");
        return 1;
    }
}

public int bajar_manzano(){
    object abajo = find_object(BREE("c1_huerto2"));
    int intento=TP->UseSkill(HAB_TREPAR, 10);
    if (query_once_interactive(TP)){
        if (TP->QueryTP()<3)
            return notify_fail("Necesitas descansar un rato.\n");
        if (intento> 0){
            TP->move(abajo, M_SPECIAL,
            ({" se agarra a las ramas y desciende del manzano",
              " desciende del manzano junto a ti...",
              "Te agarras a una de las ramas y desciendes a suelo firme.\n"}));
            TP->AddTP(-d3());
            return 1;
        } else {
            TP->move(abajo, M_SPECIAL,
            ({" intenta descender con cuidado del manzano, pero resbala y cae de bruces al suelo",
              " intenta bajar del manzano hasta tu posición pero resbala y cae torpemente de bruces contra el suelo",
              "Intentas descender con cuidado del manzano pero tus pies resbalan sobre la corteza y caes al suelo.\n"}));
                                              TP->Defend(d20(),TD_APLASTAMIENTO,DEFEND_NOMSG);
            TP->AddTP(-d3());
            play_sound(TO, SOUND_EVENTOS("caida_fuerte"), 0, 50);
            play_sound(abajo, SOUND_EVENTOS("caida_fuerte"));
            return 1;
        }
    }
}

