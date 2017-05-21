/*****************************************************************************************
 ARCHIVO:       tdhab16.c
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
    SetIntLong("Te encuentras en una de las esquinas del salón en la que reposan "
          "trozos de bellas estatuas dedicadas a alguna hija del dios del lugar. Al "
          "oeste continúa el salón. Al sur divisas un círculo concéntrico en el "
          "suelo.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddDetail("estatuas", "Tenian que haber sido hermosas. Pero algún tipejo con mal "
          "gusto las ha retocado bastante, y ahora parecen ... otra cosa.\n");

    AddExit("oeste", ALULAGO("templo/tdhab17.c"));
    AddExit("norte", ALULAGO("templo/tdhab20.c"));
    AddExit("sur", ALULAGO("templo/tdhab8.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab19.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab7.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab9.c"));
    AddExit("este", ALULAGO("templo/tdhab15.c"));
    HideExit("este", 1);

    AddItem(ALUPNJ("rata"), REFRESH_DESTRUCT, 2);
    AddItem(ALUPNJ("aranya"), REFRESH_DESTRUCT, 1);
}
