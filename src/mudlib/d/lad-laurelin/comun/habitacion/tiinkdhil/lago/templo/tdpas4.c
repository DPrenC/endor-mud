/*****************************************************************************************
 ARCHIVO:       tdpas4.c
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

    SetIntShort("el pasillo");
    SetIntLong("Aquí si que hay habitantes. Enormes ratas se mueven a tu alrededor. "
          "Sigue el pasillo hacia el norte.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", ALULAGO("templo/tdpas5.c"));
    AddExit("este", ALULAGO("templo/tdpas3.c"));

    AddItem(ALUPNJ("rata"), REFRESH_DESTRUCT, 2);
}