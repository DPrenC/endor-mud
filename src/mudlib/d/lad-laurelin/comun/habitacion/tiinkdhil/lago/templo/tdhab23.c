/*****************************************************************************************
 ARCHIVO:       tdhab23.c
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
    SetIntLong("Esquina nordeste del salón. Tienes delante un trono espectacular que "
          "estuvo ocupado por uno de los dos grandes oradores del lugar.\n");
    SetIndoors(1);
    SetIntBright(38);
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("oeste", ALULAGO("templo/tdhab24.c"));
    AddExit("sur", ALULAGO("templo/tdhab18.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab19.c"));

    AddItem(ALUPNJ("esquel"), REFRESH_DESTRUCT, 1);
}
