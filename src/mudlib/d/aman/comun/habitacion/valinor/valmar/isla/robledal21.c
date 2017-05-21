/*****************************************************************************************
 ARCHIVO:       robledal21.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

#define ARBUSTOS ({"maleza", "arbustos", "arbustos espinosos", "helechos", "matas",\
                   "matas de helechos"})

inherit BASE_ISLA;

public int cmd_cruzar(string str);

create()
{
    if(::create()) return 1;

    SetIntShort("el acantilado del este");
    SetIntLong("Te encuentras a apenas dos metros de un gran acantilado que nace del "
        "lago Glinnael. La niebla te impide ver el horizonte con nitidez, y la tupida "
        "maleza te hace más difícil el paso...\n");
    AddDetail("horizonte", "Atisbas fuliginosas siluetas de lo que deben ser los blancos "
        "picos de las Montañas Cylerid.\n");
    AddDetail("maleza", "Observas arbustos espinosos y altas matas de helechos. "
        "Fijándote mejor, parece que están ocultando la entrada a un pasadizo o algo "
        "similar.\n");
    AddDetail("pasadizo", "Te acercas y te das cuenta de que es realmente la boca de un "
        "túnel que da acceso a una especie de gran bóveda. Quizás, si cruzas la maleza, "
        "puedas alcanzar el interior.\n");

    SetIntSmell("Huele a hojas frescas y a humedad.\n");
    SetIntNoise("Escuchas el leve choque de las aguas contra las rocas.\n");

    AddRoomCmd(({"atravesar", "cruzar"}), "cmd_cruzar");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal25.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal16.c"));
}

public int cmd_cruzar(string str)
{
    if(!str || member(ARBUSTOS, str) < 0)
        return notify_fail("¿Qué quieres cruzar?\n");
    TP->move(HAB_BOSQUE_ISLA("robledal27"), M_SPECIAL,
        ({"desaparece a través de la maleza",
          "llega de entre la maleza",
          "Atraviesas la maleza como puedes y consigues llegar al túnel"}));
    return 1;
}
