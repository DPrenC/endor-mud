/*****************************************************************************************
 ARCHIVO:       tdhab19.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Tienes enfrente el altar de Dehim. Es curioso, parece que nadie lo "
          "haya tocado en todos estos años. Ni siquiera tiene polvo. A ambos lados "
          "tienes los límites del salón, y detrás continúa el salón.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab18.c"));
    AddExit("norte", ALULAGO("templo/tdhab24.c"));
    AddExit("oeste", ALULAGO("templo/tdhab20.c"));
    AddExit("sur", ALULAGO("templo/tdhab15.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab25.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab16.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab23.c"));

    AddItem(ALUPNJ("esquel"), REFRESH_DESTRUCT, 1);
}
