/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/entrada.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: entrada a la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>
#include <messages.h>
#include <living.h>
inherit SIM_ROOM;

private int IrNorte();

create()
{
    ::create();
    SetLocate("la cantera de Sloch");
    SetIntShort("la entrada a la cantera de Sloch");
    SetIntLong("Éste es el puesto de guardias que custodian la cantera.\nTen "
        "cuidado con lo que haces, puesto que..., es fácil entrar, pero "
        "pocos logran salir vivos.\nTal vez fuese mejor volver por donde "
        "viniste.\n");
    SetIndoors(0);
    SetSafe(1);
    ForbidAllMagic();
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_REMOVE,4);
    AddExit("sur",SHERCAN("camino06"));
    AddExit("norte",SF(IrNorte));
}

private int IrNorte()
{
    object ob;
    ob=clone_object(QUEST+"sherek/pico");
    ob->move(TP);
    write("El guardia te sonríe y dice: Bien, ¿así que quieres echar una "
        "manita con las piedras, eh? Pues vale, ¡adentro!\nActo seguido, te "
        "pone un pico en las manos, y te empuja hacia las rocas.\n");
    say(W("El guardia mira sonriendo a "+CAP(TP->QueryName())+", y "
        "poniéndole un pico entre las manos, le arroja hacia el interior de "
        "la cantera.\n"),TP);
    TP->SetFollowers(0);
    int celda, road, col;
    road = d6();
    col = d6();
    celda = (road*10)+col;
    TP->move(SHERCAN("alto/cantera"+celda), M_GO);
    return 1;
}
