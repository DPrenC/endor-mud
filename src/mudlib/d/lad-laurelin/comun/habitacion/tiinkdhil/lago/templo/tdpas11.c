/*****************************************************************************************
 ARCHIVO:       tdpas11.c
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
    SetIntLong("Todo está derruido, destrozado por el paso del tiempo, las cortinas, y "
          "practicamente la puerta que tienes enfrente.\n");
    SetIndoors(1);
    SetIntBright(40);


    AddExit("sudeste", ALULAGO("templo/tdpas10.c"));
    AddExit("oeste", ALULAGO("templo/tdhab21"));
    AddDoor("oeste", "una puerta",
        "Está en muy malas condiciones.\n");
}
