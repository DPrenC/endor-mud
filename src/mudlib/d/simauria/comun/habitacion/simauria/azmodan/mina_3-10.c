/***********************************************************/
//  "mina_3-10"
//  Mina abandonada
//  15-12-01 : Creación -> Kodex
//  15-12-01 : Modificación -> Kodex
//
//
#include "path.h"
#include <moving.h>

inherit STD_AZMODAN("mina");

int piedra = 1;

string mirar_manta()
{
    if (!piedra)
    {
        return "Es una manta vieja y descolorida.\n";
    }
    return W("Levantas la manta de tela y ves una piedra preciosa coronando "
             "el montón de rocas.\n");
}

int coger_cmd(string str)
{
    object ob;
    int val;

    if (str != "piedra" && str != "piedra preciosa")
    {
        return 0;
    }
    if (!piedra) return 0;
    ob = clone_object(OBJETO_AZMODAN("piedra"));
    if ((val = ob->move(TP)) != ME_OK)
    {
        switch(val)
        {
            case ME_TOO_HEAVY:
                notify_fail(W("Una piedra preciosa pesa demasiado para "
                              "que la puedas coger.\n"),NOTIFY_NOT_VALID);
                break;
            case ME_TOO_MANY:
                notify_fail(W("Llevas demasiadas cosas en tu inventario "
                              "para poder coger una piedra.\n"),
                            NOTIFY_NOT_VALID);
                break;
            case ME_TOO_BIG:
                notify_fail("No tienes espacio suficiente para coger una "
                            "piedra.\n", NOTIFY_NOT_VALID);
                break;
            default:
                notify_fail("No puedes coger una piedra preciosa.\n",
                            NOTIFY_NOT_VALID);
                break;
        }
        ob->remove();
        if (ob) destruct(ob);
        return 0;
    }

    write("Coges una brillante piedra preciosa.\n");
    say(W(capitalize(TNAME) + " coge una brillante piedra preciosa "
          "del suelo.\n"));
    piedra = 0;
    return 1;
}

public create()
{
    ::create();
    SetIntShort("la tercera planta de la mina");
    SetIntLong(W("Te encuentras en un gran corredor de la mina hay "
                 "rocas por el suelo y una manta de tela encima de otro "
                 "montón de rocas. Hacia el sur continúa el largo pasillo y "
                 "hacia el norte puedes ver unas luces rojas que salen de "
                 "una gran sala.\n"));
    AddDetail(({"manta","manta de tela"}),SF(mirar_manta));
    AddExit("sur",MINA_AZMODAN("mina_3-06"));
    AddExit("oeste",MINA_AZMODAN("mina_3-09"));
    AddExit("norte",MINA_AZMODAN("mina_3-14"));
    if (random(100) < 50)
    {
        switch(random(2))
        {
            case 0:
                AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1);
                break;
            case 1:
                AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1);
                break;
            default: break;
        }
    }

}

void aviso()
{
    if (environment(TP) != TO) return;
    tell_object(TP,"Ves algo brillante.... parece una piedra "
                              "preciosa en el suelo.\n");
}


init()
{
    ::init();
    if (TP->QueryRace() == "enano" && piedra)
    {
        call_out("aviso",1);
    }
add_action("coger_cmd","coger");
}

public void reset()
{
    ::reset();
    piedra = 1;
}