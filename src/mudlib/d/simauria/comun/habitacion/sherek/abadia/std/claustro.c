/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/claustro/claustro.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripción: Claustro de la abadía, fichero base.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERAB("std/ext");

create()
{
    ::create();
    SetIntShort("el interior del claustro, ");
    SetIntLong("En el corazón del monasterio, este espacio prohibido a extraños ofrece a los "
        "monjes un refugio de paz y aislamiento.\nBásicamente, es una galería formada por cuatro "
        "pórticos en cuadro, que bordea la pared del edificio, circundando un jardincillo, del que "
        "la separan unos tupidos setos de ciprés.\nJunto a las paredes, hay bancos colocados a "
        "intervalos.\nEl murmullo del agua de algún estanque interior infunde al alma una "
        "sensación de tranquilidad.\n");
    AddDetail(({"seto","setos","cipres","ciprés","cipreses"}),"Una pared verde formada por "
        "cipreses, muy juntos y recortados a una altura uniforme de 2 metros, aísla el jardín "
        "interior del pórtico exterior del claustro, formando una galería con la pared del "
        "edificio, sólo interrumpida por las 4 aberturas que llevan a los arcos de entrada.\n");
    AddDetail(({"estanque","jardin","jardín"}),"Los altos setos de ciprés te impiden ver el "
        "interior del jardín.\n");
    AddDetail(({"pared","paredes"}),"Están hechas con inmensos bloques de piedra pulida, con toda "
        "seguridad extraída por los esclavos de la cantera. Grabados a cincel, puedes ver en ellas "
        "dibujos históricos sobre la abadía y los monjes.\n");
    AddDetail(({"dibujo","dibujos","grabado","grabados"}),"Representan antiguas batallas libradas "
        "por los monjes y sus subordinados, puede que todas reales, puede que no todas, y puede "
        "que ninguna lo sea...\n");
    SetIntNoise("Escuchas el rumor del agua de algún estanque cercano.\n");
    SetIntSmell("El aroma de la hierba, del agua y los cipreses te llena de satisfacción.\n");
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
        