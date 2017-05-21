/*****************************************************************************************
 ARCHIVO:       tdhab18.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <money.h>

inherit ROOM;

int vist;

string hay_monedas();

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Estás en una de las esquinas del salón, la cual está bordeada por unos "
          "alargados bancos dispuestos en torno al altar, que está al noroeste de tus "
          "ojos. En las paredes hay unos cuencos colgados.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddDetail(({"cuenco", "cuencos"}), SF(hay_monedas));
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("norte", ALULAGO("templo/tdhab23.c"));
    AddExit("oeste", ALULAGO("templo/tdhab19.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab24.c"));

    AddItem(ALUPNJ("esquel"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}

string hay_monedas()
{
    if(vist == 1) return "Aunque ahora no hay nada, antes tenía dinero.\n";
    AddItem("/obj/money", REFRESH_REMOVE,
        (["Money":MONEY_DEMON->CreateMoney((random(10)+10), ({"silver"}))]));
    vist = 1;
    return "Este cuenco recogía las ofrendas al dios. Tal vez tenga algunas monedas.\n";
}

public varargs void reset()
{
    vist = 0;
    ::reset();
}
