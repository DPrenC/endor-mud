/*****************************************************************************************
 ARCHIVO:       tdhab20.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit ROOM;

int cmd_beber(string str);

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Es la esquina noroeste del gran salón. Esta delimitada por unos bancos "
          "en los que se solían sentar los monjes. Hay una gran palangana encima de una "
          "mesa.\n");
    SetIndoors(1);
    SetIntBright(30);

    //añadidos botellines de agua bendita
    Set(P_REFILL, "agua bendita");

    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");
    AddDetail("palangana", "Contienen un líquido incoloro que debe ser agua. Tal vez "
          "sea agua de lluvia que cayó a través de las goteras. Puedes intentar beber "
          "agua de la palangana.\n");

    AddRoomCmd("beber", "cmd_beber");

    AddExit("este", ALULAGO("templo/tdhab19.c"));
    AddExit("norte", ALULAGO("templo/tdhab25.c"));
    AddExit("sur", ALULAGO("templo/tdhab16.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab24.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab15.c"));

    AddItem(ALUOBJ("otro/bagua"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}

int cmd_beber(string str)
{
    int sed;
    int sedm;

    sed = TP->QueryDrink();
    sedm = TP->QueryMaxDrink();

    if(!str || str != "agua de la palangana")
    {
        write("¿Beber QUÉ?\n");
        return 1;
    }

    if(sedm - sed < 10)
    {
        TP->SetDrink(sedm);
        write("Ya no tienes sed.\n");
        return 1;
    }
    TP->SetDrink(sed + 10);
    write("Al beber, tu sed disminuye.\n");
    say(CAP(TNAME) + " bebe de la palangana.\n");
    return 1;
}
