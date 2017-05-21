/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera1.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: Fichero base para la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <magia.h>
inherit SIM_ROOM;

public int pongo()
{
    switch (d3())
    {
        case 1:
            AddItem(PNJ("sherek/cantera/murcielago"),REFRESH_DESTRUCT,(d3()));
        break;
        default: break;
    }
    return 1;
}

public int fpicar()
{
    object ob = present("PicoQuest",TP);
    if (!ob) write("No tienes el pico apropiado para picar aquí.\n");
    else
    {
        if (ob->QueryEquipped() == TP)
        {
            if (TP->QueryTP() <=5)
            {
                write("Estás exhausto. Tendrás que descansar para seguir trabajando.\n");
                return 1;
            }
            write("Picas la roca. No sabes muy bien lo que buscas.\nApenas "
                "ahondas unos milímetros en la piedra. ¡Es agotador!\n");
            say(W(CAP(TP->QueryName())+" se pone a picar con entusiasmo, pero "
                "apenas se nota su trabajo.\n"),TP);
            TP->AddTP(-5);
        }
        else write("Tendrás que empuñar el pico para poder picar.\n");
    }
    return 1;
}

private string avisa()
{
    string msg;
    switch (d4())
    {
        case 1:
            msg="Anteriores excavaciones hacen que algunas pendientes sean "
                "resbaladizas y peligrosas.\n";
        break;
        case 2:
            msg="Los cortes de las rocas las hacen abruptas y desiguales. "
                "Ve con cuidado, porque podrías darte algún golpe.\n";
        break;
        case 3:
            msg="Los bloques socavados hacen que esto sea un laberinto de "
                "piedra basta.\nCuidado, porque podrías cortarte.\n";
        break;
        case 4:
            msg="Cuidado al moverte, porque podrías resbalarte con el "
                "estiércol de murciélago.\n";
        break;
    }
    return msg;
}

private void describe()
{
    switch (d4())
    {
        case 1:
            SetIntLong("Rocas, rocas, y más rocas...\n"+avisa());
        break;
        case 2:
            SetIntLong("Sólo ves rocas resquebrajadas a todo tu alrededor.\n"+avisa());
        break;
        case 3:
            SetIntLong("Por todas partes se extiende el desolado paisaje de "
                "las rocas peladas.\n"+avisa());
        break;
        case 4:
            SetIntLong("El terreno no es más que una masa de roca irregular "
                "y agujereada por todas partes.\n"+avisa());
        break;
    }
}

create()
{
    ::create();
    SetLocate("las minas de Sherek");
    SetIntShort("el interior de la montaña");
    describe();
    SetIndoors(1);
    SetIntBright(0);
    SetIntSmell("Apesta a cerrado y estiércol de murciélago. \n");
    SetIntNoise("Escuchas chillidos y aleteos.\n");
    Set(P_TPORT,TPORT_NO);
    AddDetail(({"roca","rocas","piedra","piedras","granito","bloques"}),"Son "
        "monstruosas rocas de granito, donde en otro tiempo hubo vetas de "
        "piedras preciosas que extraían los enanos.\n");
    AddDetail(({"estiercol","estiércol"}),"Son cagarrutas de murciélago, ¿qué esperabas?\n");
    ForbidAllMagic("Antiguos hechizos impiden hacer magia aquí.\n");
}

init()
{
    ::init();
    switch (d3())
    {
        case 1:
            switch (d4())
            {
                case 1:
                    write("¡Ay! Te golpeas en la cabeza con un saliente.\n");
                break;
                case 2:
                    write("¡Uy! Te arañas al pasar entre dos rocas.\n");
                break;
                case 3:
                    write("¡Aúuuuuh! Te tuerces el tobillo en una grieta.\n");
                break;
                case 4:
                    write("¡Uáaaaah! Resbalas en el suelo y caes.\n");
                break;
            }
            TP->AddHP(-2);
        break;
        default: break;
    }
    add_action("fpicar","picar");
}

public varargs int prevent_leave(mixed dest, int method, mixed extra)
{
    object ob=TP || PO;
    if (ob->Query(P_IS_FOLLOWER)) call_out("notify_leave",5,dest,method,extra);
    return ME_NO_PREVENT;
}

public void notify_leave(mixed to, int method, mixed extra)
{
    object ob=TP || PO;
    if (ob->Query(P_IS_FOLLOWER)) ob->Set(P_IS_FOLLOWER, FOLLOW_NO);
    ob->SetFollowers(0);
    ::notify_leave(to, method, extra);
}
        