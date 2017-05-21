/*****************************************************************************************
 ARCHIVO:       rosa_b.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCI�N:   Una rosa blanca
******************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit "/obj/hierba";

public int cmd_comer(string str);

create()
{
    if(::create()) return 1;

    SetShort("una preciosa rosa blanca");
    SetLong("Es una maravillosa rosa del blanco m�s puro y brillante que jam�s hayas "
        "visto, con sus p�talos completamente desplegados ante ti, como invit�ndote a "
        "acariciarlos.\n");
    AddId(({"rosa", "rosa blanca", "preciosa rosa", "preciosa rosa blanca"}));
    SetSmell("Acercas tu nariz y aspiras su delicado aroma, fresco y limpio. Una "
        "sensaci�n de paz te invade por completo.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetClass("magico");
    SetType("flor");
    SetWeight(60);
    Set(P_MAGIC, QueryHerb());
}

public int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(), str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n");

    write("El aura de pureza y serenidad que emana de esta flor es tan irresistible, "
        "que decides probar el sabor de sus p�talos, con la esperanza de que te "
        "contagie algo de su paz. As� pues, arrancas un p�talo y te lo comes. Al "
        "momento empiezas a experimentar una sensaci�n indefinida pero no "
        "desagradable, que va aumentando gradualmente y se transforma en la m�s "
        "intensa sensaci�n de calma que hayas experimentado nunca. En estos momentos, "
        "te sientes en plena conexi�n con el universo, tu mente es pura, clara y "
        "serena como el agua de un estanque, y afilada y certera como una daga.\n");
    say(CAP(NNAME(pl)) + " admira la belleza de su rosa blanca, y acto seguido se come "
        "uno de los p�talos. De inmediato notas que su postura parece m�s erguida y su "
        "mirada m�s clara, serena y brillante de lo habitual.\n");

    pl->HealSP(70);
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
