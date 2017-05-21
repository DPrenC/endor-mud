/***
fichero: folleto.c
Autor: kastwey
Descripción: Un folleto explicativo sobre el uso de las taquillas.
***/

#include <securebox.h>

inherit THING;

private string leer_folleto();

create()
{
    ::create();
    SetShort("Un folleto de la hermandad de consignas");
    SetLong(W("Esto es un folleto de la hermandad de consignas.\nEn él se muestra información referente a las taquillas.\nPara leerlo, escribe leer folleto.\n"));
    AddId(({"folleto","folleto de consignas","folleto de taquillas",
            "folleto de las taquillas"}));
    Set(P_NOSELL, 1);
    SetValue(0);
    SetWeight(30);
    SetReadMsg(SF(leer_folleto));
}

private string leer_folleto()
{
    return read_file(SBOXPATH "folleto.txt");
}

