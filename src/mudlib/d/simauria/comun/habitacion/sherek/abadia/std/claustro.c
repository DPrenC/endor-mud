/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/claustro/claustro.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripci�n: Claustro de la abad�a, fichero base.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERAB("std/ext");

create()
{
    ::create();
    SetIntShort("el interior del claustro, ");
    SetIntLong("En el coraz�n del monasterio, este espacio prohibido a extra�os ofrece a los "
        "monjes un refugio de paz y aislamiento.\nB�sicamente, es una galer�a formada por cuatro "
        "p�rticos en cuadro, que bordea la pared del edificio, circundando un jardincillo, del que "
        "la separan unos tupidos setos de cipr�s.\nJunto a las paredes, hay bancos colocados a "
        "intervalos.\nEl murmullo del agua de alg�n estanque interior infunde al alma una "
        "sensaci�n de tranquilidad.\n");
    AddDetail(({"seto","setos","cipres","cipr�s","cipreses"}),"Una pared verde formada por "
        "cipreses, muy juntos y recortados a una altura uniforme de 2 metros, a�sla el jard�n "
        "interior del p�rtico exterior del claustro, formando una galer�a con la pared del "
        "edificio, s�lo interrumpida por las 4 aberturas que llevan a los arcos de entrada.\n");
    AddDetail(({"estanque","jardin","jard�n"}),"Los altos setos de cipr�s te impiden ver el "
        "interior del jard�n.\n");
    AddDetail(({"pared","paredes"}),"Est�n hechas con inmensos bloques de piedra pulida, con toda "
        "seguridad extra�da por los esclavos de la cantera. Grabados a cincel, puedes ver en ellas "
        "dibujos hist�ricos sobre la abad�a y los monjes.\n");
    AddDetail(({"dibujo","dibujos","grabado","grabados"}),"Representan antiguas batallas libradas "
        "por los monjes y sus subordinados, puede que todas reales, puede que no todas, y puede "
        "que ninguna lo sea...\n");
    SetIntNoise("Escuchas el rumor del agua de alg�n estanque cercano.\n");
    SetIntSmell("El aroma de la hierba, del agua y los cipreses te llena de satisfacci�n.\n");
    AddItem(OTRO("sherek/abadia/banco"));
    SetSoundEnvironment(SND_AMBIENTES("arroyo2"),6);
}

public void notify_leave(mixed to, int method, mixed extra)
{
    object ob=TP || PO;
    int sentado=ob->QueryAttribute("sentado");
    if (sentado)
    {
        object banco=present("banco");
        if (banco) banco->flevantarse();
    }
    ::notify_leave(to, method, extra);
}
        