/****************************************************************************
Fichero: galeria.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripci�n: galer�a subterr�nea en el bosque de Morak.
****************************************************************************/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <moving.h>
inherit ROOM;

int irsur()
{
    if (TP->QuerySize()==P_SIZE_SMALL)
    {
        write("Entras por el agujero.\n");
        say(capitalize(TP->QueryName())+" entra por el agujero.\n",TP);
        TP->SetFollowers(0);
        return TP->move(BOSQUE_MORAK("bosque27"),M_GO);
    }
    else
    {
        say(capitalize(TP->QueryName())+" intenta entrar en el agujero pero "
            "no cabe.\n",TP);
        return notify_fail("Eres demasiado grande para pasar por el "
            "agujero.\n",NOTIFY_NOT_VALID);
    }
}

create()
{
    ::create();
    SetLocate("el valle de Azzor");
    SetIntShort("una galer�a subterr�nea");
    SetIntLong("Te hallas al principio de una galer�a subterr�nea. La "
        "galer�a no es m�s que un estrecho pasadizo excavado en la roca viva "
        "de la monta�a, sin que aciertes a comprender muy bien por qui�n y "
        "para qu�.\nLa agobiante estrechez del pasaje, unido al "
        "enrarecimiento del aire, hacen que �ste sea un ambiente opresivo. "
        "No te sientes muy a gusto aqu�.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "m�s que la roca que constituye esta monta�a.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada "
        "m�s que eso.\n");
    SetIndoors(1);
    SetIntBright(0);
    ForbidAllMagic("Inexplicablemente, tu magia ha desaparecido.\n");
    AddExit("norte",BOSQUE_MORAK("galeria2"));
    AddExit("salir", SF(irsur));
}
