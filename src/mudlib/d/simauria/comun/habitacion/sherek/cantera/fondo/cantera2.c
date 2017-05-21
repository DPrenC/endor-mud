/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera2.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: Fichero base para la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <magia.h>
inherit SIM_ROOM;

public void pongo()
{
    switch (d3())
    {
        case 1:
            AddItem(PNJ("sherek/cantera/demonio"),REFRESH_DESTRUCT,(d3()));
        break;
        default: break;
    }
    return 0;
}

public int fpicar()
{
    object ob = present("PicoQuest",TP);
    if (!ob) write("No tienes el pico apropiado para picar aqu�.\n");
    else
    {
        if (ob->QueryEquipped() == TP)
        {
            if (TP->QueryTP() <=5)
            {
                write("Est�s exhausto. Tendr�s que descansar para seguir trabajando.\n");
                return 1;
            }
            write("Picas la roca. No sabes muy bien lo que buscas.\nApenas "
                "ahondas unos mil�metros en la piedra. �Es agotador!\n");
            say(W(CAP(TP->QueryName())+" se pone a picar con entusiasmo, pero "
                "apenas se notan su trabajo.\n"),TP);
            TP->AddTP(-5);
        }
        else write("Tendr�s que empu�ar el pico para poder picar.\n");
    }
    return 1;
}

private string adorno()
{
    string msg;
    switch (d4())
    {
        case 1:
            msg="Empiezas a maldecir a quien te meti� en este l�o.\n";
        break;
        case 2:
            msg="Te preguntas qui�n demonios te mandar�a venir aqu�.\n";
        break;
        case 3:
            msg="Piensas que meterte aqu� no fu� una buena idea.\n";
        break;
        case 4:
            msg="Deber�as empezar a preocuparte por tu salud mental.\n";
        break;
    }
    return msg;
}

private void describe()
{
    switch (d4())
    {
        case 1:
            SetIntLong("Un t�trico laberinto excavado en la roca viva. "
                "Es deprimente.\n"+adorno());
        break;
        case 2:
            SetIntLong("Paredes de roca desnuda te rodean por todas partes, "
                "produci�ndote una sensaci�n de claustrofobia.\n"+adorno());
        break;
        case 3:
            SetIntLong("A todo tu alrededor se extienden las galer�as "
                "excavadas en la fr�a roca.\n"+adorno());
        break;
        case 4:
            SetIntLong("Esto es una red de oscuros t�neles abiertos en la "
                "roca, por los que no ha pasado nadie en much�simos a�os.\n"+adorno());
        break;
    }
}

create()
{
    ::create();
    SetLocate("las minas de Sherek");
    SetIntShort("el coraz�n de la monta�a");
    describe();
    SetIndoors(1);
    SetIntBright(0);
    SetIntSmell("Huele  a humedad y aire viciado. \n");
    SetIntNoise("Silencio, un escalofriante silencio.\n");
    Set(P_TPORT,TPORT_NO);
    AddDetail(({"roca","rocas","piedra","piedras","granito","bloques"}),"Son "
        "monstruosas rocas de granito, donde en otro tiempo hubo vetas de "
        "piedras preciosas que extra�an los enanos.\n");
    ForbidAllMagic("Antiguos hechizos impiden hacer magia aqu�.\n");
    AddRoomCmd("picar","fpicar");
}

init()
{
    ::init();
    switch (d4())
    {
        case 1:
            write("No sabes c�mo vas a salir de aqu�.\n");
        break;
        case 2:
            write("�D�nde estar� la salida?\n");
        break;
        case 3:
            write("Este laberinto no parece tener fin.\n");
        break;
        case 4:
            write("Ya no sabes d�nde est�s .\n");
        break;
    }
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
        