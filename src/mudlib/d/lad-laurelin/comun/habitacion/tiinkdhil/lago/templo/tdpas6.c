/*****************************************************************************************
 ARCHIVO:       tdpas6.c
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
    SetIntLong("Este pequeño corredor es bastante oscuro, pero puedes distinguir algo "
          "de luz al norte. Al oeste divisas muchos destrozos.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", ALULAGO("templo/tdhab13.c"));
    AddExit("oeste", ALULAGO("templo/tdhab6.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT, 1);
}