/********************
Fichero: /d/akallab/comun/pnj/akallab/azzor/nytjar.c
Autor: Yalin
Fecha: 31/10/2007 15:18:24
Descripción: Tabernera para la taberna de Sally.
********************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

public string _druj()
{
    string msg;
    object druj=present("druj",environment());
    if (druj)
    {
        if (living(druj)) msg="Nytjar golpea el mostrador con una botella y grita: Oye, "
            "Druj, un día de estos te patearé el trasero.\n";
        else msg="Nytjar sonríe maliciosamente diciendo: Vaya, Druj, al fin has encontrado la "
            "orma de tu zapato...\n";
    }
    else msg="Nytjar mueve la cabeza y dice: ¡Qué raro! ¿Dónde andará hoy ese pesado de Druj?\n";
    return msg;
}

create()
{
    ::create();
    SetStandard("Nytjar","orco",25,GENERO_FEMENINO);
    SetName("Nytjar");
    SetShort("Nytjar, la fea");
    SetLong("Nitjar es una orca robusta y maciza, de mala hechura y peores modales.\nCuentan "
        "las malas lenguas que llegó de la ciudad, de donde se fué por no encontrar novio...; "
        "su cara de pocos amigos resulta fea hasta para los orcos... Aunque peores lenguas "
        "insinúan que tampoco buscaba novio, y hacen insidiosas suposiciones sobre sus "
        "preferencias...\n");
    AddId(({"nytjar","Nytjar","orca","orco","tabernera","camarera","fea"}));
    InitChats(5,({SF(_druj),
        "Nytjar te apunta con su garra y te grita: Eh, tú, ¿vas a beber algo?\n",
        "Nytjar mira hacia el oeste con ojos de cordero degollado.\n",
        "Nytjar te dice: Eh, tú, gentuza, pide algo o lárgate.\n",
        "Nytjar gruñe: Al próximo que me llame fea, le rompo la crisma.\n"}));
}
    
init()
{
    ::init();
    add_action("cmd_golpe","fea");
}

int cmd_golpe()
{
    TP->AddHP(-25);
    tell_room(environment(),CAP(TNAME)+" mira a Nytjar y le grita: ¡Eh, so fea!\nNytjar da un "
        "brinquito, mira a "+CAP(TNAME)+", y sin pestañear, le arrea un botellazo en la "
        "sesera.\n",({TP}));
    write("Nytjar salta como si le hubiera picado un bicho, se gira hacia ti, y te "
        "estampa una botella en la cabeza.\nEstás "+TP->QueryHealthMsg()+".\n");
    return 1;
}
            