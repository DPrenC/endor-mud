/****************************************************************************
Fichero: galeria3.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripción: galería subterránea en el bosque de Morak.
****************************************************************************/

#include "path.h"
inherit ROOM;

public int fencontrar(string str)
{
    if (str != "rocas") return 0;
    if (!TP->QueryAttribute("encontrado_reducir"))
    {
        object ob;
        ob = clone_object("/guilds/conjuradores/pergamino/pergamino_reducir");
        ob->move(TO);
        TP->SetAttribute("encontrado_reducir",time());
        write("Al remover las rocas, algo cae a tus pies.\n");
        return 1;
    }
    return notify_fail("Apartas unas cuantas rocas, pero sólo ves..., más "
        "rocas.\n",NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetLocate("el valle de Azzor");
    SetIntShort("una galería subterránea");
    SetIntLong("Has llegado  al final de una galería subterránea. La galería "
        "no es más que un estrecho pasadizo excavado en la roca viva de la "
        "montaña, sin que aciertes a comprender muy bien por quién y para "
        "qué.\nUn derrumbamiento ha bloqueado el paso, aunque te da la "
        "impresión de que en otro tiempo, esto llevaba a algún sitio.\nLa "
        "agobiante estrechez del pasaje, unido al enrarecimiento del aire, "
        "hacen que éste sea un ambiente opresivo. No te sientes muy a gusto "
        "aquí.\nAlgunos fragmentos de roca han caído al suelo formando un "
        "pequeño montón.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "más que la roca que constituye esta montaña.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada más que "
        "eso.\n");
    AddDetail(({"rocas","monton","montón","monton de rocas","montón de rocas"}),
        "Son restos de rocas machacadas por un posible derrumbamiento. Tal "
            "vez ocultan algo, o tal vez no.\n");
    SetIndoors(1);
    SetIntBright(0);
    ForbidAllMagic("Inexplicablemente, tu magia ha desaparecido.\n");
    AddRoomCmd("remover","fencontrar");
    AddRoomCmd("apartar","fencontrar");
    AddRoomCmd("mover","fencontrar");
    AddExit("arriba",BOSQUE_MORAK("galeria2"));
}
