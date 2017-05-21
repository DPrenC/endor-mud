/**************************************************************************
fichero: minas_oculta.c
Autor: Riberales
Creación: 12/11/05
Descripción: Room en segunda planta de las minas, secreta, de la 24.
**************************************************************************/


#include "path.h"
#include <properties.h>
#include <moving.h>
#include <magia.h>
inherit ROOM;

string m_agujero();
string m_paredes();
string m_pared_oeste();
int p_pared;
int cmd_entrar();

public int SetPared(int i)
{

    return p_pared = i;
}



create()
{
    ::create();

    SetLocate("las minas de Kha-annu");
    SetIntShort("una estancia oculta");
    SetIntLong("Has aparecido en lo que parece una cámara que sufrió un "
               "derrumbe. A duras penas puedes moverte, y las rocas ocupan "
               "casi toda la estancia. En el suelo observas un pequeño bulto "
               "recubierto de polvo.\n");



    Set(P_TPORT,TPORT_NO);
        SetExplorable(1); // pongo una lorobola por aquí.

    AddDetail(({"agujero","hueco"}),SF(m_agujero));
    AddDetail(({"pared","paredes"}),SF(m_paredes));
    AddDetail("pared oeste",SF(m_pared_oeste));

    AddItem(OTRO_MINAS("cadaver_minero"));

    SetIntSmell("Percibes un fuerte olor a putrefaccción.\n");
    SetIntNoise("No consigues escuchar nada, parece que estás en el más "
                "absoluto silencio.\n");
    AddRoomCmd(({"entrar","pasar"}),"cmd_entrar");
    AddRoomCmd("picar", "cmd_picar");

}

int cmd_picar(string str)
{
    object pico = present("pico",TP);
    object room_oeste;

    if (!pico) return notify_fail("Para picar ssería bueno tener un pico.\n",
                      NOTIFY_NOT_VALID);

    if (!sizeof(filter(TP->QueryWeapons(),(:$1->id("pico_minas"):))))
    {
        return notify_fail("Mejor que empuñes primero el pico si quieres "
                           "picar algo.\n",
               NOTIFY_NOT_VALID);
    }

    if (!str || member(({"paredes","pared","pared oeste","roca","en pared "
        "oeste","en pared"}),str) <= -1)
    {
        return notify_fail("¿Picar qué?\n",NOTIFY_NOT_VALID);
    }

    if (TP->QueryTP() < 6)
    {
        return notify_fail("Estás demasiado cansad"+SEXO+" para picar.\n",
               NOTIFY_NOT_VALID);
    }
    if (!p_pared)
    {
        write("Comienzas a picar en la pared oeste y tras un rato, abres un "
              "agujero por donde pasar.\n");

        room_oeste = load_object(HAB_SEGUNDA_MINAS("minas24"));
        room_oeste->SetPared(1);
        tell_room(room_oeste,"Escuchas unos golpes al este, y de repente "
                        "observas como se abre un hueco en la roca.\n");
        SetPared(1);
        TP->AddTP(-6);
        return 1;
    }
    return notify_fail("No hay nada que picar.\n",NOTIFY_NOT_VALID);
}



int cmd_entrar(string str)
{
   if (!p_pared) return 0;
   if (!str || member(({"por agujero","por el agujero","por pared oeste","por "
                        "la pared oeste","por hueco","por el hueco"}),str) <0)
    {
        return notify_fail("¿"+ CAP(query_verb()) + " por dónde?\n",
               NOTIFY_NOT_VALID);
    }
    TP->move(HAB_SEGUNDA_MINAS("minas24"),M_SPECIAL,({
             "se mete por el agujero que hay en la roca de la pared este",
             "llega por el hueco que hay al oeste",
            "te metes por el agujero"}));
    return 1;
}

string m_paredes()
{
    string generico = "Están llenas de salientes y agujeros. Mejor será que "
                      "vayas con cuidado para no darte con algún trozo de roca.";

    if (!p_pared) return generico + "\n";

    return generico + " En la parte oeste observas un hueco.\n";
}

string m_pared_oeste()
{
    if (p_pared)
    {
        return "Observas un agujero por el cual puedes intentar pasar al otro "
               "lado.\n";
    }
    return "no ves nada de eso.\n";
}


string m_agujero()
{
    if (p_pared)
    {
        return "Es un agujero por el que puedes pasar a la otra parte de la "
               "roca.\n";
    }
}
