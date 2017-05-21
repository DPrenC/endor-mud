/*****************************************************************************************
 ARCHIVO:       tdpas2.c
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

    SetIntShort("el corredor");
    SetPreIntShort("por");
    SetIntLong("Enormes bichos se mueven a tu alrededor. Sobre todo, abundan las "
          "arañas. Tejen enormes telas de araña a tu alrededor...\nEl corredor continúa "
          "hacia el nordeste.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("suroeste", ALULAGO("templo/tdpas1.c"));
    AddExit("nordeste", ALULAGO("templo/tdpas9.c"));

    AddItem(ALUPNJ("aranya"), REFRESH_DESTRUCT, 2);
}
