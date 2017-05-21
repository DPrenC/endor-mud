/**************************************************************************
fichero: minas24.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include <moving.h>
#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

int p_pared;
string m_agujero();
string m_paredes();
string m_pared_este();
int cmd_entrar();


public int SetPared(int i)
{
    return p_pared = i;
}


create()
{
    ::create();

    SetIntShort("una galer�a de las minas enanas");
    SetIntLong("Te encuentras en el coraz�n de las minas enanas. La roca de "
               "esta parte de la galer�a est� bastante machacada, mucho m�s "
               "de lo que has visto hasta ahora. El t�nel prosigue hacia el "
               "norte y hacia el sur.\n");

    AddDetail(({"agujero","hueco"}),SF(m_agujero));
    AddDetail(({"roca","pared","paredes"}),SF(m_paredes));

    AddDetail(({"pared este","este"}),SF(m_pared_este));

    AddExit("norte",HAB_SEGUNDA_MINAS("minas25"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas23"));
    AddRoomCmd(({"entrar","pasar"}),"cmd_entrar");
    AddGuardia();
}


    string m_paredes()
{
    if (!p_pared)
    {
        return "Observas que est�n destrozadas, aunque la pared este "
               "presenta una morfolog�a un tanto extra�a.\n";
    }
    return "Observas que est�n destrozadas, y que en la pared este hay un "
           "hueco.\n";
}

string m_pared_este()
{
    if (!p_pared)
    {
        return "Observas que es como si hubiera habido un derrumbe o algo. Tal "
               "vez fuera buena idea picar en ella.\n";
    }
    return "Observas una disposici�n algo heterodoxa, y un hueco por el que "
           "pasar a la otra parte de la roca.\n";
}

//Vamos a sobreescribir el picar de esta room.
int cmd_picar(string str)
{
    object pico = present("pico",TP);
    object room_este;
    if (!pico) return notify_fail("Para picar sser�a bueno tener un pico.\n",
                      NOTIFY_NOT_VALID);

    if (!sizeof(filter(TP->QueryWeapons(),(:$1->id("pico_minas"):))))
    {
        return notify_fail("Mejor que empu�es primero el pico si quieres "
                           "picar algo.\n",
               NOTIFY_NOT_VALID);
    }

    if (!str || member(({"paredes","pared","pared este","roca","en pared "
        "este","en pared"}),str) <= -1)
    {
        return notify_fail("�Picar qu�?\n",NOTIFY_NOT_VALID);
    }

    if (!p_pared)
    {
        write("Comienzas a picar en la pared este y tras un rato, descubres "
              "que est� hueca. Finalmente, consigues hacer un agujero por "
              "donde pasar.\n");
        say(CAP(TNAME) + "comienza a picar en la pared este y tras un rato, descubre "
              "que est� hueca. Finalmente, consigue hacer un agujero por "
              "donde pasar.\n", TP);

        room_este = load_object(HAB_SEGUNDA_MINAS("minas_oculta"));
        room_este->SetPared(1);
        tell_room(room_este,"Escuchas unos golpes al oeste, y de repente "
                        "observas como se abre un hueco en la roca.\n");

        SetPared(1);

        return 1;
    }
    return notify_fail("No hay nada que picar.\n",NOTIFY_NOT_VALID);
}



int cmd_entrar(string str)
{
    if (!p_pared) return 0;
    if (!str || member(({"por agujero","por hueco"}),str) <0)
    {
        return notify_fail("�"+ CAP(query_verb()) + " por d�nde?\n",
               NOTIFY_NOT_VALID);
    }
    TP->move(HAB_SEGUNDA_MINAS("minas_oculta"),M_SPECIAL,({
             "se mete por el agujero que hay en la roca de la pared este",
             "llega por el hueco que hay al oeste",
            "te metes por el agujero"}));
    return 1;
}

string m_agujero()
{
    if (p_pared)
    {
        return "Es un agujero por el que puedes pasar a la otra parte de la "
               "roca.\n";
    }
}
