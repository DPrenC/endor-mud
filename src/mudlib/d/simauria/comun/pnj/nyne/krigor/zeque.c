/*
 DESCRIPCION : Este es zeque, el guia de los contrabandistas.
 FICHERO     : zeque.c
 CREACION    : 28-07-2002 [Bomber]

*/

#include "path.h"
#include <properties.h>
#include <gremios.h>
#include <moving.h>

inherit NPC;
inherit "/lib/money";

create()
{
    ::create();
   SetStandard("Zeque","humano",([GC_LUCHADOR: 90+d6()]),GENDER_MALE);
    SetShort("Zeque, el guía");
    SetLong( "Este es Zeque, el guía de los contrabandistas.\n Su constitución es "
    "notablemente grande, sus brazos robustos y su cabeza ridículamente cuadrada"
    ", aunque no poco respetable.\n" );
    AddId(({"Zeque","zeque","guia","guía"}));
    InitChats(3,({
    "Zeque dice: Psss... yo se donde está el gremio de los contrabandistas.\n",
    "Zeque dice: Por 10 monedas de mithril podría guiarte.\n"}));

    AddQuestion(({"gremio","Gremio","contrabandistas","Contrabandistas","contrabandista",
        "Contrabandista", "gremio de contrabandistas"}),
        "El guía te dice: si, podría guiarte hasta allí... por un módico precio.\n",1);
    AddQuestion(({"precio", "módico precio", "modico precio"}),
        "El guía te dice: tan sólo 10 monedas de mithril.\n",1);
}

int _pagar_()
{
    int dinero;

    if (!TP->QueryIsPlayer()) return 1;
    dinero=QuerySomeonesValue(TP);
    if (dinero<(50000))
    {
        tell_object(TP,"Zeque te dice: Lo siento, cobro 10 monedas de mithril.\n");
        return 1;
    }
    PayValue(TP,50000);
    write("\nZeque te dice: De acuerdo. Te llevaré al gremio.\n");
    write("Zeque te golpea en la cabeza y de notas como si cayeras por un agujero enorme!!!\n");
    TP->move("/d/simauria/comun/habitacion/nyne/bosque_nyne/gremio_contrabandistas", M_SILENT);
    return 1;
}

init(){
    ::init();
    add_action("_pagar_","pagar");
}
