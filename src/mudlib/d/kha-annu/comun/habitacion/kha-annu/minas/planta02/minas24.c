/**************************************************************************
fichero: minas24.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
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

    SetIntShort("una galería de las minas enanas");
    SetIntLong("Te encuentras en el corazón de las minas enanas. La roca de "
               "esta parte de la galería está bastante machacada, mucho más "
               "de lo que has visto hasta ahora. El túnel prosigue hacia el "
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
        return "Observas que están destrozadas, aunque la pared este "
               "presenta una morfología un tanto extraña.\n";
    }
    return "Observas que están destrozadas, y que en la pared este hay un "
           "hueco.\n";
}

string m_pared_este()
{
    if (!p_pared)
    {
        return "Observas que es como si hubiera habido un derrumbe o algo. Tal "
               "vez fuera buena idea picar en ella.\n";
    }
    return "Observas una disposición algo heterodoxa, y un hueco por el que "
           "pasar a la otra parte de la roca.\n";
}

//Vamos a sobreescribir el picar de esta room.
int cmd_picar(string str)
{
    object pico = present("pico",TP);
    object room_este;
    if (!pico) return notify_fail("Para picar ssería bueno tener un pico.\n",
                      NOTIFY_NOT_VALID);

    if (!sizeof(filter(TP->QueryWeapons(),(:$1->id("pico_minas"):))))
    {
        return notify_fail("Mejor que empuñes primero el pico si quieres "
                           "picar algo.\n",
               NOTIFY_NOT_VALID);
    }

    if (!str || member(({"paredes","pared","pared este","roca","en pared "
        "este","en pared"}),str) <= -1)
    {
        return notify_fail("¿Picar qué?\n",NOTIFY_NOT_VALID);
    }

    if (!p_pared)
    {
        write("Comienzas a picar en la pared este y tras un rato, descubres "
              "que está hueca. Finalmente, consigues hacer un agujero por "
              "donde pasar.\n");
        say(CAP(TNAME) + "comienza a picar en la pared este y tras un rato, descubre "
              "que está hueca. Finalmente, consigue hacer un agujero por "
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
        return notify_fail("¿"+ CAP(query_verb()) + " por dónde?\n",
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
