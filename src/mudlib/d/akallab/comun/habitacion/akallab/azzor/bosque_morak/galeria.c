/****************************************************************************
Fichero: galeria.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripción: galería subterránea en el bosque de Morak.
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
    SetIntShort("una galería subterránea");
    SetIntLong("Te hallas al principio de una galería subterránea. La "
        "galería no es más que un estrecho pasadizo excavado en la roca viva "
        "de la montaña, sin que aciertes a comprender muy bien por quién y "
        "para qué.\nLa agobiante estrechez del pasaje, unido al "
        "enrarecimiento del aire, hacen que éste sea un ambiente opresivo. "
        "No te sientes muy a gusto aquí.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "más que la roca que constituye esta montaña.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada "
        "más que eso.\n");
    SetIndoors(1);
    SetIntBright(0);
    ForbidAllMagic("Inexplicablemente, tu magia ha desaparecido.\n");
    AddExit("norte",BOSQUE_MORAK("galeria2"));
    AddExit("salir", SF(irsur));
}
