/*****************************************************************************************
 ARCHIVO:       tdpas13.c
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

    SetIntShort("un pasillo");
    SetIntLong("Este pasillo conduce, al este, hacia una habitación, y al norte y "
          "oeste hacia otras dos alcobas.\nAl suroeste continúa el pasillo.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", ALULAGO("templo/tdhab33.c"));
    AddExit("noroeste", ALULAGO("templo/tdpas14.c"));
    AddExit("suroeste", ALULAGO("templo/tdpas5.c"));
    AddExit("este", ALULAGO("templo/tdhab11.c"));
    AddExit("oeste", ALULAGO("templo/tdhab12.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}
