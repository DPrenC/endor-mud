/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: Fichero base para la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <magia.h>
inherit SIM_ROOM;

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
            write("Te pones a picar la roca");
            object guar=present("guardian");
            if(guar && living(guar)) write(" bajo la sonrisa burlona del guardia");
            write(".\nApenas ahondas unos milímetros en la piedra. ¡Es agotador!\n");
            say(W(CAP(TP->QueryName())+" se pone a picar con entusiasmo, pero "
                "apenas se nota su trabajo.\n"),TP);
            TP->AddTP(-5);
        }
        else write("Tendrás que empuñar el pico para poder picar.\n");
    }
    return 1;
}

public int pongo()
{
    switch (d4())
    {
        case 1:
            AddItem(PNJ("sherek/cantera/guardian"),REFRESH_DESTRUCT,(d2()));
            return 1;
        break;
        case 2:
            AddItem(PNJ("sherek/cantera/esclavo"),REFRESH_DESTRUCT,(d2()));
            return 1;
        break;
        default: break;
    }
    return 1;
}

private string avisa()
{
    string msg;
    switch (d4())
    {
        case 1:
            msg="Anteriores excavaciones hacen que algunas pendientes que "
                "bajes no puedan volver a ser escaladas.\n";
        break;
        case 2:
            msg="Los cortes de las rocas podrían no permitirte volver "
                "de algunas direcciones.\n";
        break;
        case 3:
            msg="Los bloques arrancados hacen que esto sea un laberinto de "
                "piedra basta.\n";
        break;
        case 4:
            msg="Cuidado hacia dónde te mueves, porque podrías no poder "
                "retroceder.\n";
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
            SetIntLong("El terreno no es más que una masa de roca viva, que "
                "espera ser arrancada.\n"+avisa());
        break;
    }
}

create()
{
    ::create();
    SetLocate("la cantera de Sherek");
    SetIntShort("la cantera de Sherek");
    describe();
    SetIndoors(0);
    SetIntSmell("Hueles el seco polvo de granito... ¡Achís!\n");
    SetIntNoise("Sólo escuchas los duros golpes de pico.\n");
    Set(P_TPORT,TPORT_NO);
    AddDetail(({"roca","rocas","piedra","piedras","granito"}),"Son monstruosas "
        "rocas de granito, de donde se extraen, a golpe de pico, los bloques con "
        "que los monjes construyen sus edificios, o venden a otros pueblos.\n");
    ForbidAllMagic("Antiguos hechizos impiden hacer magia en esta montaña.\n");
}

init()
{
    ::init();
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
        