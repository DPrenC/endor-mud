#include "path.h"
#include <properties.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "/std/room/items";
inherit "/obj/chest";
#define  ABIERTO    TO->QueryLockState()

public int abrir_(string str)
{
    if (member(({"cajon","cajón","cajoncito","cajon de mesita","cajón de mesita",
        "cajoncito de mesita","cajon de la mesita","cajón de la mesita","cajoncito de la mesita",
        "mesita","mesita de noche"}),str)>=0)
    {
        if (ABIERTO == LOCK_OPEN)
        {
            write("El cajón ya está abierto.\n");
            return 1;
        }
        if (TP == YALIN || TP->QueryRealName() == "ferny")
        {
            //aquí bloque de código para abrir
            say(TNAME+" murmura unas palabras que no entiendes antes de acercar su mano a la mesita.\n",TP);
            return 0;
        }
        write("Una fuerza mágica te impide acercar tu mano al cajón. Parece ser que sólo "
            "Yalin y el niño pueden abrirlo.\n");
        say(TNAME+" intenta abrir la mesita, pero parece ser que una fuerza mágica se lo impide.\n");
        return 1;
    }
    return 0;
}

public int cerrar_(string str)
{
    if (member(({"cajon","cajón","cajoncito","cajon de mesita","cajón de mesita",
        "cajoncito de mesita","cajon de la mesita","cajón de la mesita","cajoncito de la mesita",
        "mesita","mesita de noche"}),str)>=0)
    {
        if (ABIERTO == LOCK_CLOSED)
        {
            write("El cajón ya está cerrado.\n");
            return 1;
        }
        if (TP == YALIN || TP->QueryRealName() == "ferny")
        {
            //aquí bloque de código para cerrar
            say(TNAME+" murmura unas palabras que no entiendes antes de acercar su mano a la mesita.\n",TP);
            return 0;
        }
        write("Una fuerza mágica te impide acercar tu mano al cajón. Parece ser que sólo "
            "Yalin y el niño pueden tocarlo.\n");
        say(TNAME+" intenta cerrar la mesita, pero parece ser que una fuerza mágica se lo impide.\n");
        return 1;
    }
    return 0;
}

create()
{
    "*"::create();
    SetIds(({"mesita"}));
    SetAds(({"de"}));
    SetShort("la mesita de noche");
    SetLong("Es una mesa cuadrada, pequeña y baja, situada a la derecha de la cama.\nTiene un "
        "pequeño cajón, y se utiliza para posar o guardar objetos que son o pueden ser necesarios "
        "cuando se está en la cama.\n");
    AddId(({"mesita","mesilla"}));
    AddAdjective(({"noche"}));
    AddSubDetail(({"cajon","cajón","cajoncito"}),"Es una cajita sin tapa, embutida en la parte "
        "frontal de la mesita, y que, mediante unas guías sobre las que se desliza, puede sacarse "
        "y meterse, para abrirlo y cerrarlo, respectivamente.\n");
    SetPreContent("En el cajón hay:\n");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NOGET,"Ir por ahí con una mesita sería absurdo.\n");
    Set(P_LOCKSTATE,LOCK_OPEN);
    SetMaxIntWeight(1000);
    AddItem("llave",REFRESH_REMOVE);
    AddItem("anillo",REFRESH_REMOVE,2);
    Set(P_LOCKSTATE,LOCK_CLOSED);
}
  
init()
{
    ::init();
    add_action("cerrar_","cerrar");
    add_action("abrir_","abrir");
}
        