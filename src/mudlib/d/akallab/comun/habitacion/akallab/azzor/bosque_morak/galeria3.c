/****************************************************************************
Fichero: galeria3.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripci�n: galer�a subterr�nea en el bosque de Morak.
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
    return notify_fail("Apartas unas cuantas rocas, pero s�lo ves..., m�s "
        "rocas.\n",NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetLocate("el valle de Azzor");
    SetIntShort("una galer�a subterr�nea");
    SetIntLong("Has llegado  al final de una galer�a subterr�nea. La galer�a "
        "no es m�s que un estrecho pasadizo excavado en la roca viva de la "
        "monta�a, sin que aciertes a comprender muy bien por qui�n y para "
        "qu�.\nUn derrumbamiento ha bloqueado el paso, aunque te da la "
        "impresi�n de que en otro tiempo, esto llevaba a alg�n sitio.\nLa "
        "agobiante estrechez del pasaje, unido al enrarecimiento del aire, "
        "hacen que �ste sea un ambiente opresivo. No te sientes muy a gusto "
        "aqu�.\nAlgunos fragmentos de roca han ca�do al suelo formando un "
        "peque�o mont�n.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "m�s que la roca que constituye esta monta�a.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada m�s que "
        "eso.\n");
    AddDetail(({"rocas","monton","mont�n","monton de rocas","mont�n de rocas"}),
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
